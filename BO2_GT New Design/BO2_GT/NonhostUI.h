int menuX = 300;
int menuXX = 300;
int menuW = 0;

void Animations()
{
	static int itick, iwait;
	bool istate = ((Sys_Milliseconds() - itick) > iwait);

	if (istate)
	{
		if (InGame)
		{//
			MenuOpen ? (mBackground.a < 0.8f) ? mBackground.a += 0.02f : mBackground.a = 0.8f : (mBackground.a > 0.0f) ? mBackground.a -= 0.1f : mBackground.a = 0.0f;
			MenuOpen ? (mOutline.a < 1.0f) ? mOutline.a += 0.02f : mOutline.a = 1.0f : (mOutline.a > 0.0f) ? mOutline.a -= 0.02f : mOutline.a = 0.0f;
			MenuOpen ? (mOutlinea.a < 0.18f) ? mOutlinea.a += 0.02f : mOutlinea.a = 0.18f : (mOutlinea.a > 0.0f) ? mOutlinea.a -= 0.1f : mOutlinea.a = 0.0f;
			MenuOpen ? (mBackgrounda.a < 0.18f) ? mBackgrounda.a += 0.02f : mBackgrounda.a = 0.18f : (mBackgrounda.a > 0.0f) ? mBackgrounda.a -= 0.1f : mBackgrounda.a = 0.0f;
			MenuOpen ? (mText.a < 1.0f) ? mText.a += 0.02f : mText.a = 1.0f : (mText.a > 0.0f) ? mText.a -= 0.1f : mText.a = 0.0f;
			MenuOpen ? (myText.a < 1.0f) ? myText.a += 0.02f : myText.a = 1.0f : (myText.a > 0.0f) ? myText.a -= 0.1f : myText.a = 0.0f;

			//MenuOpen ? (menuX < 600) ? menuX += 15 : menuX = 600 : (menuX > 300) ? menuX -= 15 : menuX = 300;
			MenuOpen ? (menuXX > 300) ? menuXX -= 15 : menuXX = 300 : (menuXX < 600) ? menuXX += 15 : menuXX = 600;
			MenuOpen ? (menuX < 600) ? menuX += 15 : menuX = 600 : (menuX > 300) ? menuX -= 15 : menuX = 300;
			MenuOpen ? (menuW < 300) ? menuW += 15 : menuW = 300 : (menuW > 0) ? menuW -= 15 : menuW = 0;
			MenuHasBeenSeled ? (subScrollSize < 150) ? subScrollSize += 15 : subScrollSize = 150 : (subScrollSize > 15) ? subScrollSize -= 20 : subScrollSize = 15;
		}

		if (!InGame)
		{
			MenuOpen ? (mBackground.a < 0.8f) ? mBackground.a += 0.02f : mBackground.a = 0.8f : (mBackground.a > 0.0f) ? mBackground.a -= 0.1f : mBackground.a = 0.0f;
			MenuOpen ? (mOutline.a < 1.0f) ? mOutline.a += 0.02f : mOutline.a = 1.0f : (mOutline.a > 0.0f) ? mOutline.a -= 0.02f : mOutline.a = 0.0f;
			MenuOpen ? (mOutlinea.a < 0.18f) ? mOutlinea.a += 0.02f : mOutlinea.a = 0.18f : (mOutlinea.a > 0.0f) ? mOutlinea.a -= 0.1f : mOutlinea.a = 0.0f;
			MenuOpen ? (mBackgrounda.a < 0.18f) ? mBackgrounda.a += 0.02f : mBackgrounda.a = 0.18f : (mBackgrounda.a > 0.0f) ? mBackgrounda.a -= 0.1f : mBackgrounda.a = 0.0f;
			MenuOpen ? (mText.a < 1.0f) ? mText.a += 0.02f : mText.a = 1.0f : (mText.a > 0.0f) ? mText.a -= 0.1f : mText.a = 0.0f;
			MenuOpen ? (myText.a < 1.0f) ? myText.a += 0.02f : myText.a = 1.0f : (myText.a > 0.0f) ? myText.a -= 0.1f : myText.a = 0.0f;

			//MenuOpen ? (menuX < 600) ? menuX += 15 : menuX = 600 : (menuX > 300) ? menuX -= 15 : menuX = 300;
			MenuOpen ? (menuXX > 300) ? menuXX -= 15 : menuXX = 300 : (menuXX < 600) ? menuXX += 15 : menuXX = 600;
			MenuOpen ? (menuX < 600) ? menuX += 15 : menuX = 600 : (menuX > 300) ? menuX -= 15 : menuX = 300;
			MenuOpen ? (menuW < 300) ? menuW += 15 : menuW = 300 : (menuW > 0) ? menuW -= 15 : menuW = 0;
			MenuHasBeenSeled ? (subScrollSize < 150) ? subScrollSize += 15 : subScrollSize = 150 : (subScrollSize > 15) ? subScrollSize -= 20 : subScrollSize = 15;
		}

		RGBEditorOpen ? (rBackground.a < 0.8f) ? rBackground.a += 0.02f : rBackground.a = 0.8f : (rBackground.a > 0.0f) ? rBackground.a -= 0.1f : rBackground.a = 0.0f;
		RGBEditorOpen ? (rOutline.a < 0.8f) ? rOutline.a += 0.02f : rOutline.a = 0.8f : (rOutline.a > 0.0f) ? rOutline.a -= 0.1f : rOutline.a = 0.0f;
		RGBEditorOpen ? (rText.a < 1.0f) ? rText.a += 0.02f : rText.a = 1.0f : (rText.a > 0.0f) ? rText.a -= 0.1f : rText.a = 0.0f;

		SubTest ? (sBackground.a < 0.8f) ? sBackground.a += 0.02f : sBackground.a = 0.8f : (sBackground.a > 0.0f) ? sBackground.a -= 0.1f : sBackground.a = 0.0f;
		SubTest ? (sOutline.a < 1.0f) ? sOutline.a += 0.02f : sOutline.a = 1.0f : (sOutline.a > 0.0f) ? sOutline.a -= 0.1f : sOutline.a = 0.0f;
		SubTest ? (sText.a < 1.0f) ? sText.a += 0.02f : sText.a = 1.0f : (sText.a > 0.0f) ? sText.a -= 0.1f : sText.a = 0.0f;

		itick = Sys_Milliseconds(), iwait = 1;
	}
}

void _Rainbow(Color * rain)
{
	if (rain->a <= 0) rain->a = 1.0;
	if (rain->r <= 0 && rain->g <= 0 && rain->b <= 0)
		rain->r = 1.0;
	if (rain->r > 0 && rain->b <= 0.25 / 255.00f)
	{
		rain->r -= 2 / 255.00f;
		rain->g += 2 / 255.00f;
		rain->a = rain->a;
	}
	if (rain->g > 0 && rain->r <= 0.25 / 255.00f)
	{
		rain->g -= 2 / 255.00f;
		rain->b += 2 / 255.00f;
		rain->a = rain->a;
	}
	if (rain->b > 0 && rain->g <= 0.25 / 255.00f)
	{
		rain->r += 2 / 255.00f;
		rain->b -= 2 / 255.00f;
		rain->a = rain->a;
	}
}
void _Gradient(Color * rain)//b //r
{
	if (rain->a <= 0) rain->a = 1.0;
	if (rain->b <= 0 && rain->g <= 0 && rain->r <= 0)
		rain->g = 1.0;
	if (rain->g > 0 && rain->r <= 0.25 / 255.00f)
	{
		rain->g -= 2 / 255.00f;
		rain->b += 2 / 255.00f;
		rain->a = 1.0;
	}
	if (rain->b > 0 && rain->g <= 0.25 / 255.00f)
	{
		rain->b -= 2 / 255.00f;
		rain->r += 2 / 255.00f;
		rain->a = 1.0;
	}
	if (rain->r > 0 && rain->b <= 0.25 / 255.00f)
	{
		rain->g += 2 / 255.00f;
		rain->r -= 2 / 255.00f;
		rain->a = 1.0;
	}
}

int SX, SY;

void SaveEditor(int X, int Y)
{
	DrawOutline(0, 0, ScrWidth + X, ScrHeight + Y, GreenC, "white", 0);
}

void ExternalShaderPreGame()
{
	char sGMs = dc.fps;
	char FPSS[200];
	sprintf(FPSS, "FPS: %i", sGMs);
	int DebugInfoY = (RadarCenter.y - RadarSize / 2) + 20;
	DrawTextWidthShaderRight("Project GT v3.1 Private Beta", ((dc.width) - 26) + Widths, DebugInfoY + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
	DrawTextWidthShaderRight(FPSS, ((dc.width) - 26) + Widths, DebugInfoY + 24 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
	DrawTextWidthShaderRight(va("Screen Resolution: %ix%i", dc.width, dc.height), ((dc.width) - 26) + Widths, DebugInfoY + 48 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
}

void ExternalShaderInGame() {
	if (DvarGetBool("cl_ingame")) {
		Center.x = cg->refdef.Width / 2;
		Center.y = cg->refdef.Height / 2;
		RadarCenter.x = (Center.x * 2) - RadarSize - 40;
		RadarCenter.y = RadarSize / 2 + 25;
		char sGMs = dc.fps;
		char FPSS[200];
		sprintf(FPSS, "FPS: %i", sGMs);
		if (!Radar) {
			int DebugInfoY = (RadarCenter.y - RadarSize / 2) + 20;
			DrawTextWidthShaderLeft("Project GT v3.1 Private Beta", ((dc.width / dc.width) + 15) + - Widths, DebugInfoY + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			DrawTextWidthShaderLeft(FPSS, ((dc.width / dc.width) + 15) + - Widths, DebugInfoY + 48 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			DrawTextWidthShaderLeft(va("Screen Resolution: %ix%i", cgss->screenX, cgss->screenY), ((dc.width / dc.width) + 15) + - Widths, DebugInfoY+24 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
			DrawTextWidthShaderLeft(va("Ping: %i", PING->ping), (((dc.width / dc.width) + 15)) + - Widths, DebugInfoY + 72 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
			if (serverInfo)
			{
				DrawTextWidthShaderRight("Server Information", ((dc.width) - 26) + Widths, DebugInfoY + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
				DrawTextWidthShaderRight(va("Map: %s", Dvar_GetString("party_mapname")), ((dc.width) - 26) + Widths, DebugInfoY + 24 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
				DrawTextWidthShaderRight(va("Game Mode: %s", Dvar_GetString("party_gametype")), ((dc.width) - 26) + Widths, DebugInfoY + 48 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
				DrawTextWidthShaderRight(va("Host: %s", Dvar_GetString("party_hostname")), ((dc.width) - 26) + Widths, DebugInfoY + 72 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			}
		}
		else if (Radar && Health) {
			int DebugInfoY = ((RadarCenter.y - RadarSize / 2) + RadarSize + RadarSize / 4) - 24 + 10 + 5 + 4 - 10 - 3;

			DrawTextWidthShaderLeft("Project GT v3.1 Private Beta", ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			DrawTextWidthShaderLeft(FPSS, ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + 48 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			DrawTextWidthShaderLeft(va("Screen Resolution: %ix%i", cgss->screenX, cgss->screenY), ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + 24 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
			DrawTextWidthShaderLeft(va("Ping: %i", PING->ping), (((dc.width / dc.width) + 15)) + -Widths, DebugInfoY + 72 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
			if (serverInfo)
			{
				DrawTextWidthShaderRight("Server Information", ((dc.width) - 26) + Widths, DebugInfoY + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
				DrawTextWidthShaderRight(va("Map: %s", Dvar_GetString("party_mapname")), ((dc.width) - 26) + Widths, DebugInfoY + 24 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
				DrawTextWidthShaderRight(va("Game Mode: %s", Dvar_GetString("party_gametype")), ((dc.width) - 26) + Widths, DebugInfoY + 48 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
				DrawTextWidthShaderRight(va("Host: %s", Dvar_GetString("party_hostname")), ((dc.width) - 26) + Widths, DebugInfoY + 72 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			}
		}
		else if (Radar)
		{
			int DebugInfoY = (RadarCenter.y - RadarSize / 2) + 20 + Heights;
			DrawTextWidthShaderLeft("Project GT v3.1 Private Beta", ((dc.width / dc.width) + 15) + - Widths, DebugInfoY, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			DrawTextWidthShaderLeft(FPSS, ((dc.width / dc.width) + 15) + - Widths, DebugInfoY + 48, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			DrawTextWidthShaderLeft(va("Screen Resolution: %ix%i", cgss->screenX, cgss->screenY), ((dc.width / dc.width) + 15) + - Widths, DebugInfoY + 24, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
			DrawTextWidthShaderLeft(va("Ping: %i", PING->ping), ((dc.width / dc.width) + 15) + - Widths, DebugInfoY + 72, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
			if (serverInfo)
			{
				DrawTextWidthShaderRight("Server Information:", ((dc.width) - 26) + Widths, 300 + 18 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
				DrawTextWidthShaderRight(va("Map: %s", Dvar_GetString("party_mapname")), ((dc.width) - 26) + Widths, 300 + 24 + 18 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
				DrawTextWidthShaderRight(va("Game Mode: %s", Dvar_GetString("party_gametype")), ((dc.width) - 26) + Widths, 300 + 48 + 18 + Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
				DrawTextWidthShaderRight(va("Host: %s", Dvar_GetString("party_hostname")), ((dc.width) - 26) + Widths, 300 + 72 + 18 + Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
			}
		}
	}
}

void MenuPaint_All(int LocalClientNum, int dc_)
{
#pragma region MenuHandling
	SetRToc(0xD67E98);
	Animations();
	_Rainbow(&Rainbow);
	if(Flash)
	_Rainbow(&Selector);
	_Rainbow(&Smoke);
	_Gradient(&Gradient1);
	InParty = ReadInt(0xFB2D0F);
	RadarCenter.x = (Center.x * 2) - RadarSize - 40;
	RadarCenter.y = RadarSize / 2 + 25;
	cCenter.x = cg->refdef.Width - cg->refdef.Width + 5;
#pragma endregion

	#pragma region LSD Vision

	char LSD1[] = { 0x3F, 0x80 };
	char LSD2[] = { 0x3F, 0x81 };
	char LSD3[] = { 0x3F, 0x82 };
	char LSD4[] = { 0x3F, 0x83 };
	char LSD5[] = { 0x3F, 0x84 };
	char LSD6[] = { 0x3F, 0x85 };
	char LSD7[] = { 0x3F, 0x86 };
	char LSD8[] = { 0x3F, 0x87 };
	char LSD9[] = { 0x3F, 0x88 };
	char LSD10[] = { 0x3F, 0x89 };
	if (LSD == 0)
		WriteProcess(0x786480, LSD1, sizeof(LSD1));
	else if (LSD == 1)
		WriteProcess(0x786480, LSD2, sizeof(LSD2));
	else if (LSD == 2)
		WriteProcess(0x786480, LSD3, sizeof(LSD3));
	else if (LSD == 3)
		WriteProcess(0x786480, LSD4, sizeof(LSD4));
	else if (LSD == 4)
		WriteProcess(0x786480, LSD5, sizeof(LSD5));
	else if (LSD == 5)
		WriteProcess(0x786480, LSD6, sizeof(LSD6));
	else if (LSD == 6)
		WriteProcess(0x786480, LSD7, sizeof(LSD7));
	else if (LSD == 7)
		WriteProcess(0x786480, LSD8, sizeof(LSD8));
	else if (LSD == 8)
		WriteProcess(0x786480, LSD9, sizeof(LSD9));
	else if (LSD == 9)
		WriteProcess(0x786480, &LSD10, sizeof(LSD10));

#pragma endregion

	#pragma region Controls 
	if (mBackground.a > 0.0f)
		if (DvarGetBool("cl_ingame"))
			DrawTextWidthShaderRight("Scroll: ^BPS3ButtonDpadU^ ^BPS3ButtonDpadD^ || Slider: ^BPS3ButtonDpadL^ ^BPS3ButtonDpadR^ || Select: ^BPS3ButtonX^ || Back: ^BPS3ButtonCircle^", ((ScrWidth) - 26) + Widths, (ScrHeight - 4) - R_TextHeight("fonts/720/normalFont", 0.6) - Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
		else
			DrawTextWidthShaderRight("Scroll: ^BPS3ButtonDpadU^ ^BPS3ButtonDpadD^ || Slider: ^BPS3ButtonDpadL^ ^BPS3ButtonDpadR^ || Select: ^BPS3ButtonSquare^ || Back: ^BPS3ButtonCircle^", ((ScrWidth)-26) + Widths, (ScrHeight - 4) - R_TextHeight("fonts/720/normalFont", 0.6) - Heights, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
	else
		if(DvarGetBool("cl_ingame"))
			DrawTextWidthShaderRight("Open: ^BPS3ButtonDpadU^ ^BPS3ButtonStickAnimatedR^", ((ScrWidth)-26) + Widths, (ScrHeight - 4) - R_TextHeight("fonts/720/normalFont", 0.6) - Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
		else
			DrawTextWidthShaderRight("Open: ^BPS3ButtonStickAnimatedR^", ((ScrWidth)-26) + Widths, (ScrHeight - 4) - R_TextHeight("fonts/720/normalFont", 0.6) - Heights, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
#pragma endregion

	#pragma region GT

	//GT Background
	UI_DrawShader(cCenter.x - Widths, 660 - Heights, 100, 14, GTBack, 0, "white");//Top
	UI_DrawShader(cCenter.x - Widths, 660 + 14 - Heights, 14, 50 - 12, GTBack, 0, "white");//Left
	UI_DrawShader(cCenter.x + 100 - 25 - 12 + 2 + 2 - 2 - Widths, 660 + 12 + 2 - Heights, 14 - 4 - 2 - 2 + 4, 50 - 12 + 2 - 2 - 2, GTBack, 0, "white");//Left T Down
	UI_DrawShader(cCenter.x + 12 - 2 + 4 - Widths, 660 + 12 + 50 - 12 - 12 - Heights, 38 - 12 + 2 - 2 - 1, 12, GTBack, 0, "white");//G bottom Inside
	UI_DrawShader(cCenter.x + 100 - 25 - 12 - 12 - 12 - Widths, 660 + 12 + 12 - Heights, 14, 50 - 12 + 2 - 12 + 12 - 6 - 4 - 2, GTBack, 0, "white");//Left T Across
																														   //GT Outline
	UI_DrawShader(cCenter.x - Widths, 660 - Heights, 100, 2, Selector, 0, "gradient_fadein");//Top
	UI_DrawShader(cCenter.x - Widths, 660 - Heights, 100, 2, Gradient1, 180, "gradient_fadein");//Top
	UI_DrawShader(cCenter.x - Widths, 660 - Heights, 2, 50, Gradient1, 0, "white");//Left
	UI_DrawShader(cCenter.x + 100 - Widths, 660 - Heights, 2, 12, Selector, 0, "white");//Right
	UI_DrawShader(cCenter.x + 100 - 25 - Widths, 660 + 12 - Heights, 25 + 2, 2, Selector, 0, "white");//Right T
	UI_DrawShader(cCenter.x + 100 - 25 - Widths, 660 + 12 - Heights, 2, 50 - 12, Selector, 0, "white");//Right T down
	UI_DrawShader(cCenter.x + 100 - 25 - 12 + 2 - Widths, 660 + 12 + 38 - Heights, 12, 2, Selector, 0, "white");//Right T Bottom
	UI_DrawShader(cCenter.x + 100 - 25 - 12 - Widths, 660 + 12 - Heights, 2, 50 - 12 + 2, Selector, 0, "white");//Left T Down
	UI_DrawShader(cCenter.x + 12 - Widths, 660 + 12 - Heights, 50 + 2, 2, Selector, 0, "gradient_fadein");//G top
	UI_DrawShader(cCenter.x + 12 - Widths, 660 + 12 - Heights, 50 + 2, 2, Gradient1, 180, "gradient_fadein");//G top
	UI_DrawShader(cCenter.x + 12 - Widths, 660 + 12 - Heights, 2, 50 - 12 - 12, Gradient1, 0, "white");//G Down
	UI_DrawShader(cCenter.x - Widths, 660 + 12 + 50 - 12 - Heights, 38 - 12 + 12 + 12 + 2, 2, Gradient1, 180, "gradient_fadein");//G bottom Outside
	UI_DrawShader(cCenter.x + 12 - Widths, 660 + 12 + 50 - 12 - 12 - Heights, 38 - 12 + 2, 2, Gradient1, 180, "gradient_fadein");//G bottom Inside
	UI_DrawShader(cCenter.x - Widths, 660 + 12 + 50 - 12 - Heights, 38 - 12 + 12 + 12 + 2, 2, Selector, 0, "gradient_fadein");//G bottom Outside
	UI_DrawShader(cCenter.x + 12 - Widths, 660 + 12 + 50 - 12 - 12 - Heights, 38 - 12 + 2, 2, Selector, 0, "gradient_fadein");//G bottom Inside
	UI_DrawShader(cCenter.x + 100 - 25 - 12 - 12 - Widths, 660 + 12 + 12 - Heights, 2, 50 - 12 + 2 - 12, Selector, 0, "white");//Left T Down
	UI_DrawShader(cCenter.x + 100 - 25 - 12 - 12 - 12 - Widths, 660 + 12 + 12 - Heights, 2, 50 - 12 + 2 - 12 - 12, Selector, 0, "white");//Left T Down
	UI_DrawShader(cCenter.x + 100 - 25 - 12 - 12 - 12 - Widths, 660 + 12 + 12 - Heights, 14, 2, Selector, 0, "white");//Left T Across
#pragma endregion

	#pragma region MenuOpen

	if (menuX > 300) //Client is Open
	{

		DrawMenuName(MenuTitle, (ScrWidth / 2) - 120 + 2 - 29 - 2, (ScrHeight / 2) - 80.5 - 83, "fonts/720/normalFont", 1, -90, TextOption, EvenOptions, Gradient1);
		UI_DrawShader((ScrWidth / 2) - 120 + 2, (ScrHeight / 2) - 80.5 - 100, 280 - 17 - 4, ((MaxScroll + 1) * 23), mBackground, 0, "white");
		DrawOutlineMenus((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100, 280 - 17 - 4 + 4, ((MaxScroll + 1) * 23), Selector, "white", 2, Gradient1);
		//gradient_fadein

		DrawMenuOpts();
		DrawOptBools();

		if (SubmenuScroll == 7 && MenuHasBeenSeled)
		{
			DrawPlayerIPs();
			if (PlayersMenuHasBeenSeled)
				DrawPlayersOptions();
		}
	}
#pragma endregion



	if(cg->health > 0)
		ExternalShaderInGame();
	if (SaveEditorBool)
	{
		DrawTextWidthShaderLeft("Control:^BPS3ButtonDpadU^/^BPS3ButtonDpadD^/^BPS3ButtonDpadL^/^BPS3ButtonDpadR^ | Confirm: ^BPS3ButtonX^ | Reset: ^BPS3ButtonSquare^ | Cancel: ^BPS3ButtonCircle^", (ScrWidth / 2) - (R_TextWidth("Control:^BPS3ButtonDpadU^/^BPS3ButtonDpadD^/^BPS3ButtonDpadL^/^BPS3ButtonDpadR^ | Confirm: ^BPS3ButtonX^ | Reset: ^BPS3ButtonSquare^ | Cancel: ^BPS3ButtonCircle^", "fonts/720/normalFont", 0.6) / 2), ScrHeight / 2, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
	}
	if (DvarGetBool("cl_ingame"))
	{
		WASSS = Tag;
		doAimbot();
		doNoSway();

		#pragma region TargetInfo
		if (cg->health > 0) {
			if (nearestClient != LocalPlayer && Centity[nearestClient].Type == ET_PLAYER) {
				if (targetInfo)
				{
					char* visible;
					if (AimTarget_isTargetVisible(0, Centityy(nearestClient)))
						visible = "^2True"; else visible = "^1False";
					float Distance = Distance3D(GetPlayerOrigin(nearestClient), GetPlayerOrigin(LocalPlayer));
					int dist;
					if (Distance < 999999999)
						dist = Distance / 100;
					char FPSS[200];
					sprintf(FPSS, "Distance: %d m", dist);
					int DebugInfoY = (RadarCenter.y - RadarSize / 2) + 20 + Heights;
					DrawTextWidthShaderLeft("Target Information:", ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + 96, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
					DrawTextWidthShaderLeft(va("Name: %s", cg->clients[nearestClient].PlayerName), ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + 120, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
					DrawTextWidthShaderLeft(FPSS, ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + 144, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
					DrawTextWidthShaderLeft(va("Weapon: %s", GetWeaponName(getCurrentWeapon(nearestClient))), ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + 168, "fonts/720/normalFont", 0.6, White, OddOptions, Selector);
					DrawTextWidthShaderLeft(va("Visible: %s", visible), ((dc.width / dc.width) + 15) + -Widths, DebugInfoY + 192, "fonts/720/normalFont", 0.6, White, EvenOptions, Selector);
				}
			}
		}
#pragma endregion
	
		TickerTimerbg++;
		if (TickerTimerbg > 50)
		{
			if (FlashName)
			{
				iClan++;
				if (iClan == 3)
					iClan++;
				if (iClan > 6)
					iClan = 1;
				char newClan[10];
				char newName[11];
				snprintf(newClan, 10, "^%i", iClan);
				//I_ChangeClan(newClan);
				snprintf(newName, 11, "PROJECTGT");
				AdvMenu(newName, newClan);
			}
			TickerTimerbg = 0;
		}

#pragma region RBG Editor Open


		if (rBackground.a > 0.0f)
		{
			UI_DrawShader((ScrWidth / 2) - 49 - 15, ((ScrHeight / 2) + 39) - 50 + 3 - 40, 227, 160, rBackground, 0, "white");
			UI_DrawShader((ScrWidth / 2) - 49 - 15, ((ScrHeight / 2) + 39) - 50 + 3 - 40, 227, 25, RGBEditorCol, 0,"white");
			DrawOutline((ScrWidth / 2) - 49 - 15, ((ScrHeight / 2) + 39) - 50 + 3 - 40, 227, 160, rOutline, "white", 2);

			UI_DrawShader((ScrWidth / 2) - 50, ((ScrHeight / 2) + 41) - 50, 200, 19, White, 0,"white"); //Red
			UI_DrawShader((ScrWidth / 2) - 50, ((ScrHeight / 2) + 71) - 50, 200, 19, White, 0,"white"); //Green
			UI_DrawShader((ScrWidth / 2) - 50, ((ScrHeight / 2) + 101) - 50, 200, 19, White,0, "white"); //Blue
			UI_DrawShader((ScrWidth / 2) - 50, ((ScrHeight / 2) + 131) - 50, 200, 19, White, 0,"white"); //Alpha

																									//((value - min) * 100) / (max - min);
			rText.r = 1;
			UI_DrawShader((ScrWidth / 2) - 49, ((ScrHeight / 2) + 39) - 50 + 3, 0 + ((((RGBr - 0) * 200) / (255 - 0))) - 2, 17, Red, 0, "white"); //Red Select
			rText.r = 0;
			if (RGBscroll == 0)
				DrawOutline((ScrWidth / 2) - 49, ((ScrHeight / 2) + 39) - 50 + 3, 0 + ((((RGBr - 0) * 200) / (255 - 0))) - 2, 17, rOutline, "white", 2); //Red Selector

			rText.g = 1;
			UI_DrawShader((ScrWidth / 2) - 49, ((ScrHeight / 2) + 69) - 50 + 3, 0 + ((((RGBg - 0) * 200) / (255 - 0))) - 2, 17, GreenC, 0, "white"); //Green Select
			rText.g = 0;
			if (RGBscroll == 1)
				DrawOutline((ScrWidth / 2) - 49, ((ScrHeight / 2) + 69) - 50 + 3, 0 + ((((RGBg - 0) * 200) / (255 - 0))) - 2, 17, rOutline, "white", 2); //Green Selector

			rText.b = 1;
			UI_DrawShader((ScrWidth / 2) - 49, ((ScrHeight / 2) + 99) - 50 + 3, 0 + ((((RGBb - 0) * 200) / (255 - 0))) - 2, 17, BlueC, 0, "white"); //Blue Select
			rText.b = 0;
			if (RGBscroll == 2)
				DrawOutline((ScrWidth / 2) - 49, ((ScrHeight / 2) + 99) - 50 + 3, 0 + ((((RGBb - 0) * 200) / (255 - 0))) - 2, 17, rOutline, "white", 2); //Blue Selector
			rText.r = 1; rText.g = 1; rText.b = 1; rText.a = 1;
			UI_DrawShader((ScrWidth / 2) - 49, ((ScrHeight / 2) + 129) - 50 + 3, (0 + (((RGBa - (0.2 * 255)) * 200) / (255 - (0.2 * 255)))) - 2, 17, Black, 0, "white"); //Alpha Select
			if (RGBscroll == 3)
				DrawOutline((ScrWidth / 2) - 49, ((ScrHeight / 2) + 129) - 50 + 3, (0 + (((RGBa - (0.2 * 255)) * 200) / (255 - (0.2 * 255)))) - 2, 17, rOutline, "white", 2); //Alpha Selector
		}

#pragma endregion

#pragma region SubMenu
		if (sBackground.a > 0.0f) //Client is Open
		{
			//Draw Option Items
			UI_DrawShader((ScrWidth / 2) - 245, (ScrHeight / 2) - 80.5 - 25, 286 - 17, ((MaxScroll + 1) * 23) + 25, sBackground, 0, "white");
			DrawOutline((ScrWidth / 2) - 242, (ScrHeight / 2) - 80.5, 280 - 17, ((MaxScroll + 1) * 23), sOutline, "white", 3);
			DrawText("Test Menu", (ScrWidth / 2) - 116, (ScrHeight / 2) - 83.5, 0, .8, "normalFont", sText, align_center);
			DrawOutlineTOP((ScrWidth / 2) - 242, (ScrHeight / 2) - 80.5 - 25, 280 - 17, ((MaxScroll) * 23) + 25, sOutline, "white", 3);

			//DrawShader((ScrWidth / 2) - 242, (ScrHeight / 2) - 80.5 + ((MaxScroll + 1) * 23), 494, 20, mBackground, "white");
			//DrawOutline((ScrWidth / 2) - 242, (ScrHeight / 2) - 80.5 + ((MaxScroll + 1) * 23), 494, 20, mOutline, "white", 2);


			SubTestOpts();
			//DrawOptBools();
		}
#pragma endregion

		if (DrawCrosshair)
		{
			UI_DrawShader(ScrWidth / 2 - CrosshairSize, ScrHeight / 2 - 1, 3, CrosshairSize * 2 + 3, ESPCrosshairCol, 0, "white");
			UI_DrawShader(ScrWidth / 2 - 1, ScrHeight / 2 - CrosshairSize, CrosshairSize * 2 + 3, 3, ESPCrosshairCol, 0, "white");
		}
		
	}
	else
	{
		if (!DvarGetBool("cl_ingame"))
		{
			TickerTimegb++;
			if (TickerTimegb > 45)
			{
				if (FlashPreGame)
				{
					iClan++;
					if (iClan == 3)
						iClan++;
					if (iClan > 6)
						iClan = 1;

					char newClan[10];
					snprintf(newClan, 10, "^%i", iClan);
					ChangeClanTagPreGame(newClan);
				}
				TickerTimegb = 0;
			}
			ExternalShaderPreGame();
		}
		if (mBackground.a > 0.0f)
		{
			
		}
	}
	sMenuPaint_All(LocalClientNum, dc_);
}