void* Material_RegisterHandle(const char* Material, int ImageTrac)
{
	return Invoke<void*>(0x763220, Material, ImageTrac, 0);
}

enum alignment
{
	align_left,
	align_right,
	align_center,
};

void UI_DrawShader(float X, float Y, float Width, float Height, Color color, float Angle, const char*MaterialName)
{
	Invoke<void>(0x456F8, 0xFB9DE0, X, Y, Width, Height, CColor color, Angle, Material_RegisterHandle(MaterialName, 9));
}

void UI_DrawShaderPVOID(float X, float Y, float Width, float Height, Color color, float Angle, void* MaterialName, int ImageTrac)
{
	Invoke<void>(0x456F8, 0xFB9DE0, X, Y, Width, Height, CColor color, Angle, MaterialName);
}

void DrawOutline(float x, float y, float width, float height, Color color, const char *material, int thickness)
{
	UI_DrawShader(x - thickness, y - thickness, width + (thickness * 2), thickness, color, 0, "white"); // Top
	UI_DrawShader(x - thickness, y + height, width + (thickness * 2), thickness, color, 0, "white"); // Bottom

	UI_DrawShader(x - thickness, y - thickness, thickness, height + thickness, color, 0, "white"); // Left
	UI_DrawShader(x + width, y - thickness, thickness, height + (thickness * 2), color, 0, "white"); // Right
}
void DrawOutlineMenus(float x, float y, float width, float height, Color color, const char *material, int thickness, Color left)
{
	UI_DrawShader(x - thickness, y - thickness, width + (thickness * 2), thickness, left, 180, "gradient_fadein"); // Top Left
	UI_DrawShader(x - thickness, y - thickness, width + (thickness * 2), thickness, color, 0, "gradient_fadein"); // Top Right

	UI_DrawShader(x - thickness, y + height, width + (thickness * 2), thickness, left, 180, "gradient_fadein"); // Bottom Left
	UI_DrawShader(x - thickness, y + height, width + (thickness * 2), thickness, color, 0, "gradient_fadein"); // Bottom Right

	UI_DrawShader(x - thickness, y - thickness, thickness, height + thickness, left, 0, "white"); // Left
	UI_DrawShader(x + width, y - thickness, thickness, height + (thickness * 2), color, 0, "white"); // Right
}

void DrawOutlineTOP(float x, float y, float width, float height, Color color, const char *material, int thickness)
{
	UI_DrawShader(x - thickness, y - thickness, width + (thickness * 2), thickness, color, 0, "white"); // Top
}

int CG_DrawRotatedPicPhysical(ScreenPlacement* screenPlacement, float X, float Y, float Width, float Height, float Angle, Color color, const char* Material)
{
	Invoke<int>(0x456F8, screenPlacement, X, Y, Width, Height, Angle, (float*)&color, Material_RegisterHandle(Material, 0));
}

int DrawLine(int x1, int y1, int x2, int y2, Color color) {
	ScreenPlacement* ptr = ScrPlace_GetView(0);
	float x, y, angle, l1, l2, h1;
	h1 = y2 - y1;
	l1 = x2 - x1;
	l2 = sqrt(l1 * l1 + h1 * h1);
	x = x1 + ((l1 - l2) / 2);
	y = y1 + (h1 / 2);
	angle = myMath::atan2(h1, l1)* (180 / 3.14159265358979323846);
	return CG_DrawRotatedPicPhysical(ptr, x, y, l2, 1.0, angle, color, "white");
}

#define R_GetFontPathFromName(name) ((const char*(*)(const char*))&opd_z(0x75C104, 0xD67E98))(name)
int R_RegisterFont(const char* font, int imageTrac) {
	return Invoke<int>(0x75A2C0, font, imageTrac);
}

int R_TextWidth(const char* text, const char * font, float scale)
{
	return Invoke<int>(0x75A338, 0, text, 0x7FFFFFFF, R_RegisterFont(font, 0)) * scale;
}

int R_TextHeight(const char* font, float scale)
{
	const char* psz_font = R_GetFontPathFromName(font);
	return Invoke<int>(0x75A5D0, R_RegisterFont(psz_font, 0)) * scale;
}

void R_AddCmdDrawText(const char* Text, int MaxChars, int Font, float X, float Y, float XScale, float YScale, float Rotation, float * Color, int Style) {
	Invoke<void>(0x76A910, Text, MaxChars, Font, X, Y, XScale, YScale, Rotation, Color, Style);
}

void DrawText(const char* text, float x, float y, float rotation, float scale, const char* font, Color col, alignment align) {
	const char* pszfont = R_GetFontPathFromName(font);
	if (text == NULL) return;
	int font_handle = R_RegisterFont(pszfont, 0);
	int width = R_TextWidth(text, pszfont, scale);
	if (align & align_left)
		x = x;
	if (align & align_right)
		x = x - width;
	if (align & align_center)
		x = x - (width / 2);
	R_AddCmdDrawText(text, 0x7FFFFFFF, font_handle, x, y, scale, scale, rotation, (float*)&col, 0);
}

void DrawTextOnBack(const char *xtext, float x, float y, const char *xfont, float xfontSize, float yfontSize, Color color) {
	R_AddCmdDrawText(xtext, 0x7FFFFFFF, R_RegisterFont(xfont, 0), x, y, xfontSize, yfontSize, 0, (float*)&color, 0);
}

void DrawTextOnBack2(const char *xtext, float x, float y, const char *xfont, float xfontSize, float yfontSize, float rotation, Color color) {
	R_AddCmdDrawText(xtext, 0x7FFFFFFF, R_RegisterFont(xfont, 0), x, y, xfontSize, yfontSize, rotation, (float*)&color, 0);
}

void DrawTextWidthShaderRight(char *text, float x, float y, char *font, float fontSize, Color color, Color bcolor, Color lcolor) {
	float textWid = R_TextWidth(text, "fonts/720/normalFont", fontSize);
	UI_DrawShader(x - textWid - 2, y - 17, textWid + 5, 22, bcolor, 0, "white");
	DrawOutlineMenus(x - textWid - 2, y - 17, textWid + 5, 22, lcolor, "white", 2, Gradient1);
	DrawTextOnBack(text, x - (R_TextWidth(text, "fonts/720/normalFont", fontSize)), y + 2, font, fontSize, fontSize, color);
}

void DrawTextWidthShaderLeft(char *text, float x, float y, char *font, float fontSize, Color color, Color bcolor, Color lcolor) {
	float textWid = R_TextWidth(text, "fonts/720/normalFont", fontSize);
	UI_DrawShader(x - 2, y - 17, textWid + 5, 22, bcolor, 0, "white");
	DrawOutlineMenus(x - 2, y - 17, textWid + 5, 22, lcolor, "white", 2, Gradient1);
	DrawTextOnBack(text, x, y + 2, font, fontSize, fontSize, color);
}

void DrawTextWidthShader(char *text, float x, float y, char *font, float fontSize, Color color, Color bcolor, Color lcolor) {
	float textWid = R_TextWidth(text, "fonts/720/normalFont", fontSize);
	UI_DrawShader(x - textWid - 2, y - 17, textWid + 5, 22, bcolor, 0, "white");
	DrawOutlineMenus(x - textWid - 2, y - 17, textWid + 5, 22, lcolor, "white", 2, Gradient1);
	DrawTextOnBack(text, x - (R_TextWidth(text, "fonts/720/normalFont", fontSize)), y + 2, font, fontSize, fontSize, color);
}
//DrawOutlineMenus
void DrawMenuName(char *text, float x, float y, char *font, float fontSize, float rotation, Color color, Color bcolor, Color lcolor) {
	float textWid = R_TextWidth(text, "fonts/720/normalFont", fontSize);
	UI_DrawShader(x - 2, y - 17, 29, textWid + 5, bcolor, 0, "white");
	DrawOutline(x - 2, y - 17,  29, textWid + 5, lcolor, "white", 2);
	DrawTextOnBack2(text, x + R_TextHeight("fonts/720/normalFont", fontSize) + 9, y + (R_TextWidth(text, "fonts/720/normalFont", fontSize)) - 15, font, fontSize, fontSize, rotation, color);
}