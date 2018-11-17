bool gameEnded()
{
	if (*(int*)0xF99280 != 0)
		return true;
	else
		return false;
}

Vector2 RadarCenter, Center;
int RadarSize = 250;
int RadarSize2 = 150;

char* GetWeaponName(char wep)
{
	switch (wep)
	{
	case 0x01: return "WEAPON_DEFAULTWEAPON"; break;
	case 0x02: return "MP7"; break; // menu_mp_weapons_mp7
	case 0x04: return "PDW - 57"; break;//menu_mp_weapons_ar57
	case 0x06: return "Vector K10"; break; //menu_mp_weapons_kriss
	case 0x08: return "MSMC"; break; //menu_mp_weapons_insas
	case 0x0A: return "Chicom CQB"; break; //menu_mp_weapons_qcw
	case 0x0C: return "Skorpion EVO"; break; //menu_mp_weapons_evoskorpion
	case 0x0E: return "Peacekeeper"; break; //menu_mp_weapons_pm
	case 0x10: return "MTAR"; break; //menu_mp_weapons_tar21
	case 0x14: return "Type 25"; break; //menu_mp_weapons_type95
	case 0x18: return "SWAT - 556"; break; //menu_mp_weapons_sig556
	case 0x1C: return "FAL DSW"; break; //menu_mp_weapons_sa58
	case 0x20: return "M27"; break;//menu_mp_weapons_hk416
	case 0x24: return "SCAR - H"; break; //menu_mp_weapons_scar
	case 0x28: return "SMR"; break;//menu_mp_weapons_saritch
	case 0x2C: return "M8A1"; break;//menu_mp_weapons_xm8
	case 0x30: return "AN - 94"; break; //menu_mp_weapons_an94
	case 0x34: return "R870 MCS"; break; //menu_mp_weapons_870mcs
	case 0x35: return "S12"; break; //menu_mp_weapons_saiga12
	case 0x36: return "KSG"; break; //menu_mp_weapons_ksg
	case 0x37: return "M1216"; break;//menu_mp_weapons_srm
	case 0x38: return "Mk 48"; break; //menu_mp_weapons_mk48
	case 0x3A: return "QBB LSW"; break; //menu_mp_weapons_qbb95
	case 0x3C: return "LSAT"; break; //menu_mp_weapons_lsat
	case 0x3E: return "HAMR"; break; //menu_mp_weapons_hamr
	case 0x40: return "SVU - AS"; break; //menu_mp_weapons_svu
	case 0x41: return "DSR 50"; break; //menu_mp_weapons_dsr1
	case 0x42: return "Ballista"; break; //menu_mp_weapons_ballista
	case 0x43: return "XPR - 50"; break; //menu_mp_weapons_as50
	case 0x44: return "KAP - 40 Dual Wield"; break; //menu_mp_weapons_kard
	case 0x46: return "Tac - 45 Dual Wield"; break; //menu_mp_weapons_fnp45
	case 0x48: return "Five - seven Dual Wield"; break; //menu_mp_weapons_five_seven
	case 0x4A: return "Executioner Dual Wield"; break;//menu_mp_weapons_judge
	case 0x4C: return "B23R Dual Wield"; break;//menu_mp_weapons_baretta
	case 0x4E: return "Five - seven"; break; //menu_mp_weapons_five_seven
	case 0x4F: return "Tac - 45"; break; //menu_mp_weapons_fnp45
	case 0x50: return "B23R"; break;//menu_mp_weapons_baretta
	case 0x51: return "Executioner"; break;//menu_mp_weapons_judge
	case 0x52: return "KAP - 40"; break; //menu_mp_weapons_kard
	case 0x54: return "SMAW"; break; //menu_mp_weapons_smaw
	case 0x55: return "FHJ - 18 AA"; break; //menu_mp_weapons_fhj
	case 0x56: return "RPG"; break; //menu_mp_weapons_rpg
	case 0x57: return "Combat Knife"; break; // N/A
	case 0x59: return "Assault Shield"; break; //menu_mp_weapons_riot_shield
	case 0x5A: return "Crossbow"; break; //menu_mp_weapons_crossbow
	case 0x5B: return "Ballistic Knife"; break; // menu_mp_weapons_ballistic_knife
	case 0x5C: return "Grenade"; break;
	case 0x5D: return "Concussion"; break;
	case 0x5E: return "Semtex"; break;
	case 0x5F: return "Smoke Grenade"; break;
	case 0x60: return "Combat Axe"; break;
	case 0x61: return "Sensor Grenade"; break;
	case 0x62: return "Bouncing Betty"; break;
	case 0x63: return "EMP Grenade"; break;
	case 0x64: return "C4"; break;
	case 0x65: return "Shock Charge"; break;
	case 0x66: return "Claymore"; break;
	case 0x67: return "Black Hat"; break;
	case 0x68: return "Flashbang"; break;
	case 0x69: return "Trophy System"; break;
	case 0x6A: return "Tactical Insertion"; break;
	case 0x6B: return "Throwable RC - XD"; break;
	case 0x6C: return "Throwable War Machine Explosive"; break;
	default:
		return "N/A"; break;
	}
}
#define GetPointer(X) *(int*)(X)
char getCurrentWeapon(int playerID)
{
	int goToInt = 0x379107C3 + (0x374 * playerID);
	return *(char*)goToInt;
}

WeaponDef * BG_GetWeaponDef(int Weapon)
{
	return Invoke<WeaponDef *>(0x606F08, Weapon);//BG_VarientDef
}

void anglevectors(Vector3 v, Vector3 * forward, Vector3 * right, Vector3 * up)
{
	float fv[] = { v.x, v.y, v.z };
	float vf[3], vr[3], vu[3];
	Invoke<void>(0x3CFD98, fv, vf, vr, vu);
	*forward = Vector3(vf[0], vf[1], vf[2]);
	*right = Vector3(vr[0], vr[1], vr[2]);
	*up = Vector3(vu[0], vu[1], vu[2]);
}

WeaponVariantDef * BG_VarientDef(int Weapon)
{
	return Invoke<WeaponVariantDef *>(0x606EE0, Weapon);//BG_VarientDef
}

bool WorldPosToScreenPos(Vector3 worldPos, Vector2 * screenPos)
{
	return Invoke<bool>(0x5A480, 0, &worldPos, screenPos);
}

int oCentity(int ClientIndex)
{
	return *(int*)(0xE22F20) + (ClientIndex * 0x374);
}

Vector3 _GetPlayerOrigin(int index)
{
	return *(Vector3*)(oCentity(index) + 0x168);
}

Vector3 GetPlayerOrigin(int index)
{
	return *(Vector3*)(oCentity(index) + 0x168);
}

bool isPlayerFriendly(Centity_t * cent)
{
	return Invoke<bool>(0x049720, 0, cent);
}

bool isPlayerVisible(Centity_t * cent)
{
	return Invoke<bool>(0x15988, 0, cent);
}

bool isPlayerShielding(int cent)
{
	if (*(int*)(oCentity(cent) + 0x2B4) == 0x59)
		return true;
	else
		return false;
}

Vector3 AimTarget_GetTagPos(Centity_t * cent, const char* tagname)
{
	Vector3 pos;
	*(int*)0x461FB4 = 0x4E800020;
	Invoke<bool>(0x015708, cent, Invoke<int>(0x48ED68, tagname, 0), &pos);
	*(int*)0x461FB4 = 0xF821FB71;
	return pos;
}

void DrawBone(int Entity, char* from, char* to, Color color)
{
	Vector2 fromco, toco;
	if (WorldPosToScreenPos(AimTarget_GetTagPos(&Centity[Entity], from), &fromco))
		if (WorldPosToScreenPos(AimTarget_GetTagPos(&Centity[Entity], to), &toco))
			DrawLine(fromco.x, fromco.y, toco.x, toco.y, color);
}

const char* GetWeaponShaderName(Centity_t * cent)
{
	int wepvar = Invoke<int>(0x606F08, cent->primaryWeapon);
	if (wepvar != NULL)
	{
		int Second = (int)(wepvar + 0x660);
		if (Second != NULL)
		{
			int third = *(int*)Second;
			if (third != NULL)
			{
				const char* Shadername = *(const char**)third;
				if (strstr(Shadername, "menu_"))
				{
					return Shadername;
				}
			}
		}
	}
	return "hint_mantle";
}

const char *getPrestigeIcon(int prestige)
{
	if (prestige < 10)
		return va("rank_prestige0%i", prestige);

	if (prestige >= 10)
		return va("rank_prestige%i", prestige);
}

void DoAllBones(int i, Color ESPColor)
{
	DrawBone(i, "j_knee_le", "pelvis", ESPColor);
	DrawBone(i, "j_elbow_ri", "j_wrist_ri", ESPColor);
	DrawBone(i, "j_neck", "j_elbow_ri", ESPColor);
	DrawBone(i, "j_ankle_ri", "j_knee_ri", ESPColor);
	DrawBone(i, "j_elbow_le", "j_wrist_le", ESPColor);
	DrawBone(i, "j_ankle_le", "j_knee_le", ESPColor);
	DrawBone(i, "j_knee_ri", "pelvis", ESPColor);
	DrawBone(i, "pelvis", "j_neck", ESPColor);
	DrawBone(i, "j_neck", "j_elbow_le", ESPColor);
	DrawBone(i, "j_neck", "j_head", ESPColor);
}

void MakeLines(Vector3 Origin, float X1, float Y1, float Z1, float X2, float Y2, float Z2, Color color)
{
	Vector2 Screen1, Screen2;
	Vector3 Origin1(Origin.x + X1, Origin.y + Y1, (Origin.z + Z1) - 50);
	Vector3 Origin2(Origin.x + X2, Origin.y + Y2, (Origin.z + Z2) - 50);

	if (WorldPosToScreenPos(Origin1, &Screen1) && WorldPosToScreenPos(Origin2, &Screen2))
	{
		DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, color);
	}
}

void _EntityBoxLines(Vector3 Origin, float X1, float Y1, float Z1, float X2, float Y2, float Z2, Color color)
{
	Vector2 Screen1, Screen2;
	Vector3 Origin1(Origin.x + X1, Origin.y + Y1, (Origin.z + Z1) + 20);
	Vector3 Origin2(Origin.x + X2, Origin.y + Y2, (Origin.z + Z2) + 20);

	if (WorldPosToScreenPos(Origin1, &Screen1) && WorldPosToScreenPos(Origin2, &Screen2))
	{
		DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, color);
	}
}

void BoxAroundPlayer(Vector3 Center, float W, float H, Color color, int toe, int target, float x, float y, float distance)
{
	Vector2 FeetLocation, HeadLocation;
	float fHeight = FeetLocation.y - HeadLocation.y;
	float fWidth;
	fWidth = fHeight / 1.95;
	if (toe == 66)
	{

	}
	if (toe == 67)
	{

	}
	if (toe == 1)
	{
	}
	else if (toe == 2)
	{



	}
	else if (toe == 4)
	{

	}
	else if (toe == 3)
	{
		MakeLines(Center, -W, -W, 0, W, -W, 0, color);
		MakeLines(Center, -W, -W, 0, -W, W, 0, color);
		MakeLines(Center, W, W, 0, W, -W, 0, color);
		MakeLines(Center, W, W, 0, -W, W, 0, color);
		MakeLines(Center, -W, -W, 0, 0, 0, H, color);
		MakeLines(Center, -W, W, 0, 0, 0, H, color);
		MakeLines(Center, W, -W, 0, 0, 0, H, color);
		MakeLines(Center, W, W, 0, 0, 0, H, color);
	}
	else if (toe == 5)
	{

	}
	else if (toe == 0)
	{
		MakeLines(Center, -W, -W, 0, W, -W, 0, color);
		MakeLines(Center, -W, -W, 0, -W, -W, H, color);
		MakeLines(Center, W, -W, 0, W, -W, H, color);

		MakeLines(Center, -W, -W, H, W, -W, H, color);
		MakeLines(Center, -W, -W, 0, -W, W, 0, color);
		MakeLines(Center, W, W, 0, W, -W, 0, color);
		MakeLines(Center, W, W, 0, -W, W, 0, color);
		MakeLines(Center, -W, W, 0, -W, W, H, color);
		MakeLines(Center, W, W, 0, W, W, H, color);
		MakeLines(Center, -W, -W, H, -W, W, H, color);
		MakeLines(Center, W, W, H, W, -W, H, color);
		MakeLines(Center, W, W, H, -W, W, H, color);


	}
}

int Centityy(int ClientIndex)
{
	return *(int*)(0xE22F20) + (ClientIndex * 0x374);
}

int cg_t(int Mod)
{
	return *(int*)(0xE22F18) + Mod;
}

int ClientInfo(int Index, int Mod)
{
	return (cg_t(0)) + 0x69DA0 + (Index * 0x808) + Mod;
}

int AimTarget_isTargetVisible_t[2] = { 0x15988, 0xD67E98 };
bool(*AimTarget_isTargetVisible)(int LocalClient, int Centityy) = (bool(*)(int, int))&AimTarget_isTargetVisible_t;
int CG_IsEntityFriendlyNotEnemy_t[2] = { 0x049720, 0xD67E98 };
bool(*CG_IsEntityFriendlyNotEnemy)(int LocalClient, int Centityy) = (bool(*)(int, int))&CG_IsEntityFriendlyNotEnemy_t;


#pragma region NO STREAM
void __cdecl CG_CompassCalcDimensions(int compassType, cg_s* cga, rectDef_s * parentRect, rectDef_s * rect, float* x, float* y, float* w, float *h)
{
	Invoke<void>(0x2F810, compassType, cga, parentRect, rect, x, y, w, h);
}

enum addr {
	compassMaxRange = 0x01cc9d78,
};



int CG_DrawRotatedPicPhysical1_s[] = { 0x10B060 ,0xD67E98 };
void(*CG_DrawRotatedPicPhysical1)(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float angle, const float *color, void *material) = (void(*)(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float angle, const float *color, void *material))&CG_DrawRotatedPicPhysical1_s;

Color Color_s(float R, float G, float B, float A)
{
	Color C = { R / 255.00f, G / 255.00f, B / 255.00f, A / 255.00f };
	return C;
}

GfxCmdStretchPic * mattt;

Vector2 Difference(Vector2 Target, Vector2 Entity)
{
	Vector2 Return = Target - Entity;
	return Return;
}

Vector2 Screen(Vector2 Target, Vector2 Entity)
{
	Vector2 Return = Target + Entity;
	return Return;
}

void WorldToCompass(Vector3 *worldPos, Vector2 *Compass, rectDef_s Rect)
{
	float pixPerInch = Rect.w / compassMaxRange;
	float ViewAngle = cg->playerstate.viewAngles.y / 180 * M_PI;

	Vector2 Difference(pixPerInch * (cg->refdef.ViewOrigin.x - worldPos->x), pixPerInch * (cg->refdef.ViewOrigin.y - worldPos->y));

	Vector2 Screen(Rect.x + (Difference.y * cosf(ViewAngle) - Difference.x * sinf(ViewAngle)), Rect.y + (Difference.x * cosf(ViewAngle) + Difference.y * sinf(ViewAngle)));

	if (Screen.x < Rect.x - (Rect.w / 2)) Screen.x = Rect.x - (Rect.w / 2);
	if (Screen.x > Rect.x + (Rect.w / 2)) Screen.x = Rect.x + (Rect.w / 2);
	if (Screen.y < Rect.y - (Rect.h / 2)) Screen.y = Rect.y - (Rect.h / 2);
	if (Screen.y > Rect.y + (Rect.h / 2)) Screen.y = Rect.y + (Rect.h / 2);

	Compass->x = Screen.x + (Rect.w / 2);
	Compass->y = Screen.y + (Rect.h / 2);
}



#pragma region ANTI_SCREEN SHARE
void __cdecl R_AddCmdDrawStretchPicRotateSTInternal(float x, float y, float w, float h, float centerS, float centerT, float radiusST, float scaleFinalS, float scaleFinalT, float angle, const float * color, void * material)
{
	Invoke<void>(0x76A55C, x, y, w, h, centerS, centerT, radiusST, scaleFinalS, scaleFinalT, angle, color, material);
}

void __cdecl ScrPlace_ApplyRect(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign)
{
	Invoke<void>(0x15FFE0, 0xFB9DE0, x, y, w, h, horzAlign, vertAlign);
}

void __cdecl CL_DrawStretchPicRotatedSTInternal(float x, float y, float w, float h, int horzAlign, int vertAlign, float centerS, float centerT, float radiusST, float scaleFinalS, float scaleFinalT, float angle, Color c, void *Material)
{
	ScrPlace_ApplyRect(&x, &y, &w, &h, horzAlign, vertAlign);
	R_AddCmdDrawStretchPicRotateSTInternal(x, y, w, h, centerS, centerT, radiusST, scaleFinalS, scaleFinalT, angle, (float*)&c, Material);
}

#define compass_max_range (*(float*)(0x01cc9d78))
#define FLOAT_1_0 1.0f
#define __mask_neg_float -1.0f
#define color_white Color_s(255, 255, 255, 255)
#pragma endregion

#pragma region Map Color
float WHITEE[4] = { 1,1,1,1 };
Color QWERTY = { 1,1,1,1 };
#pragma endregion

#pragma region Compass Math

float _mm_xor_ps(float v15, float _mask__NegFloat_)
{
	return v15 * _mask__NegFloat_;
}

void __cdecl CG_CompassDrawPlayerMap(rectDef_s *parentRect, rectDef_s *rect)
{
	/// stack
	Vector2 east, south, mapCenter;
	float delta, delta_4, texCenter, texCenter_4, texRadius, scaleFinalS, scaleFinalT, rotation, x, y, w, h;
	/// radar_render #begin
	float width = 223, hight = 168;

	parentRect->w = width;
	parentRect->h = hight;

	rect->w = width;
	rect->h = hight;
	rect->x = 509;
	rect->y = 16;

	w = width;
	h = hight;

	mapCenter.x = cg->refdef.ViewOrigin.x;
	mapCenter.y = cg->refdef.ViewOrigin.y;

	east.x = compass_data->compassNorth.y;
	east.y = _mm_xor_ps(compass_data->compassNorth.x, __mask_neg_float);
	south.x = _mm_xor_ps(compass_data->compassNorth.x, __mask_neg_float);
	south.y = _mm_xor_ps(compass_data->compassNorth.y, __mask_neg_float);

	delta = mapCenter.x - compass_data->compassMapUpperLeft.x;
	delta_4 = mapCenter.y - compass_data->compassMapUpperLeft.y;
	texCenter = (float)((float)(delta * east.x) + (float)(delta_4 * east.y)) / compass_data->compassMapWorldSize.x;
	texCenter_4 = (float)((float)(delta * south.x) + (float)(delta_4 * south.y)) / compass_data->compassMapWorldSize.y;
	if (compass_data->compassMapWorldSize.x <= compass_data->compassMapWorldSize.y)
	{
		texRadius = (float)(0.5 * compass_max_range) / compass_data->compassMapWorldSize.y;
		scaleFinalS = compass_data->compassMapWorldSize.y / compass_data->compassMapWorldSize.x;
		scaleFinalT = FLOAT_1_0;
	}
	else
	{
		texRadius = (float)(0.5 * compass_max_range) / compass_data->compassMapWorldSize.x;
		scaleFinalS = FLOAT_1_0;
		scaleFinalT = compass_data->compassMapWorldSize.x / compass_data->compassMapWorldSize.y;
	}
	/// rotation 
	rotation = _mm_xor_ps((cg->playerstate.viewAngles.y - compass_data->compassNorthYaw), __mask_neg_float);
	/// calc dimmensions
	
	CG_CompassCalcDimensions(0, cg, parentRect, rect, &x, &y, &w, &h);
	CL_DrawStretchPicRotatedSTInternal((x)+(Widths/1.515), (y)+(Heights/1.515), w, h, rect->horzAlign, rect->vertAlign, texCenter, texCenter_4, texRadius, scaleFinalS, scaleFinalT, rotation, color_white, compass_data->compassMapMaterial);
}

void RadarAlapha()
{
	///Overall
	*(float*)0x029ae54c = 0.0f;//Map

	///SND Map
	//1st Round
	*(float*)0x029afc74 = 0.0f;//Map
	*(float*)0x029afb3c = 0.0f;//Compass
	*(float*)0x029af8cc = 0.0f;//Misc
	*(float*)0x029af2b4 = 0.0f;//CompassBack
	//2nd Round
	*(float*)0x029b4e1c = 0.0f;//Map + Compass + CompassBack
	//3rd Round 0x029f6ffc
	*(float*)0x029f6ffc = 0.0f;//Map
	//4th Round 0x029e616c
	*(float*)0x029e616c = 0.0f;//Map
	*(float*)0x029e5dc8 = 0.0f;//Compass
	*(float*)0x029e553c = 0.0f;//CompassBack
	//5th Round 0x029faa7c
	*(float*)0x029faa7c = 0.0f;//Map + Compass + CompassBack
	//6th Round 0x029b862c
	*(float*)0x029b862c = 0.0f;//Map + Compass + CompassBack

	///ONE CTF
	*(float*)0x029af8cc = 0.0f;//Map
	*(float*)0x029af524 = 0.0f;//Compass
	*(float*)0x029aec9c = 0.0f;//CompassBack
}
#pragma endregion

#pragma endregion


Vector2 cCenter;

int fCompassSizeE = 80;

#define FLAG_CROUCHED 0x4
#define FLAG_PRONE 0x8

float GetBoxWidth(pCentity_t ent) {
	if (ent->eFlags & FLAG_PRONE)
		return 35;
	else return 17;
}

float GetBoxHeight(pCentity_t ent) {
	if (ent->eFlags & FLAG_PRONE)
		return -25;
	else if (ent->eFlags & FLAG_CROUCHED)
		return -25;
	else return -25;
}

void Draw3DBox(int client, Color sColor)
{
	Vector3 Center = pCentity_s[client].origin;

	float W = GetBoxWidth(&pCentity_s[client]), H = GetBoxHeight(&pCentity_s[client]);

	//bottom
	_EntityBoxLines(Center, -W, -W, 0, -W + (W / 2), -W, 0, sColor);
	_EntityBoxLines(Center, W / 2, -W, 0, W, -W, 0, sColor);

	_EntityBoxLines(Center, -W, -W, 0, -W, -W + (W / 2), 0, sColor);
	_EntityBoxLines(Center, -W, W - (W / 2), 0, -W, W, 0, sColor);

	_EntityBoxLines(Center, W, -W + (W / 2), 0, W, -W, 0, sColor);
	_EntityBoxLines(Center, W, W - (W / 2), 0, W, W, 0, sColor);

	_EntityBoxLines(Center, -W + (W / 2), W, 0, -W, W, 0, sColor);
	_EntityBoxLines(Center, W, W, 0, W - (W / 2), W, 0, sColor);

	//middle
	_EntityBoxLines(Center, -W, -W, 0, -W, -W, H / 6, sColor);
	_EntityBoxLines(Center, -W, -W, H, -W, -W, H - (H / 6), sColor);

	_EntityBoxLines(Center, -W, W, 0, -W, W, H / 6, sColor);
	_EntityBoxLines(Center, -W, W, H, -W, W, H - (H / 6), sColor);

	_EntityBoxLines(Center, W, -W, 0, W, -W, H / 6, sColor);
	_EntityBoxLines(Center, W, -W, H, W, -W, H - (H / 6), sColor);

	_EntityBoxLines(Center, W, W, 0, W, W, H / 6, sColor);
	_EntityBoxLines(Center, W, W, H, W, W, H - (H / 6), sColor);

	//top
	_EntityBoxLines(Center, -W, -W, H, -W + (W / 2), -W, H, sColor);
	_EntityBoxLines(Center, W / 2, -W, H, W, -W, H, sColor);

	_EntityBoxLines(Center, -W, -W, H, -W, -W + (W / 2), H, sColor);
	_EntityBoxLines(Center, -W, W - (W / 2), H, -W, W, H, sColor);

	_EntityBoxLines(Center, W, -W + (W / 2), H, W, -W, H, sColor);
	_EntityBoxLines(Center, W, W - (W / 2), H, W, W, H, sColor);

	_EntityBoxLines(Center, -W + (W / 2), W, H, -W, W, H, sColor);
	_EntityBoxLines(Center, W, W, H, W - (W / 2), W, H, sColor);

}

void SinCos(float num, float *sin, float *cos) {
	*sin = myMath::sin(num);
	*cos = myMath::cos(num);
}
void AngleVectors(Vector3 *angles, Vector3 *forward, Vector3 *right, Vector3 *up)
{
	float sr, sp, sy, cr, cp, cy;
	SinCos(angles->y, &sy, &cy);
	SinCos(angles->x, &sp, &cp);
	SinCos(angles->z, &sr, &cr);
	forward->x = cp * cy;
	forward->y = cp * sy;
	forward->z = -sp;
	right->x = (-1 * sr*sp*cy + -1 * cr*-sy);
	right->y = (-1 * sr*sp*sy + -1 * cr*cy);
	right->z = -1 * sr*cp;
	up->x = (cr*sp*cy + -sr * -sy);
	up->y = (cr*sp*sy + -sr * cy);
	up->z = cr * cp;
}

Vector3 AnglesToFoward(Vector3 Origin, Vector3 Angles, float diff) {
	float angle, sr, sp, sy, cr, cp, cy, PiDiv;
	PiDiv = ((float)M_PI / 180);
	angle = Angles.y * PiDiv;
	sy = (float)sinf(angle);
	cy = (float)cosf(angle);
	angle = Angles.x * PiDiv;
	sp = sinf(angle);
	cp = (float)cosf(angle);
	angle = Angles.y * PiDiv;
	sr = (float)sinf(angle);
	cr = (float)cosf(angle);
	Vector3 Final((cp * cy * diff) + Origin.x, (cp * sy * diff) + Origin.y, (-sp * diff) + Origin.z);
	return Final;
}

int MyPow(int base, int exp)
{
	if (exp < 0)
		return -1;

	int result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

int distanceBetweenTwoPoints(int x, int y, Vector2 bone)
{
	const double p1 = MyPow(x - bone.x, 2);
	const double p2 = MyPow(y - bone.y, 2);
	return sqrt(p1 + p2);
}