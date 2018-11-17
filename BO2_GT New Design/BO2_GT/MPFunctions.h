void sMenuPaint_All(...)
{
	__asm("li %r3, 0x4;");
}

void sProxyFuncs(...)
{
	__asm("li %r3, 0x5;");
}

void sCL_SendCmd(...)
{
	__asm("li %r3, 0x6;");
}
void sr_endFrame(...)
{
	__asm("li %r3, 0x9;");
}

void AddOptions(int size, const char* optArray[], Color col)
{
	MaxScroll = size - 1;
	int forSize = size;
	for (int i = 0; i < forSize; i++)
	{
		Color tColor = col;
		int X = 0;
		if(i == 2 || i == 4 || i == 6 || i== 0 || i ==8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20 || i == 22 || i == 24 || i == 26)
			UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, EvenOptions, 0, "white");
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19 || i == 21 || i == 23 || i == 25 || i == 27)
			UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, OddOptions, 0, "white");
		if (i == scroll && MenuHasBeenSeled || i == PreScroll && PreGameMenuHasBeenSeled)
		{
			tColor = col;
			X = 0;
		//	UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, Selector, 0, "white");

			UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, Gradient1, 180, "gradient_fadein");
			UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, Selector, 0, "gradient_fadein");

		}
		DrawText(optArray[i], (ScrWidth / 2) - 120 + 2 + 5, (ScrHeight / 2) - 61 - 100 + 1.5 + (i * 23), 0, 0.7f, "normalFont", tColor, align_left);
	}
}

void AddSubOptions(int size, const char* optArray[], Color col)
{
	MaxScroll = size - 1;
	int forSize = size;
	for (int i = 0; i < forSize; i++)
	{
		Color tsColor = col;
		int X = 0;
		if (i == subScrolls && MenuHasBeenSeled)
		{
			tsColor = col;
			X = 0;
			UI_DrawShader((ScrWidth / 2) - 242, (ScrHeight / 2) - 80.5 + 3 + (i * 23), 280 - 17, 19, sOutline, 0, "white");
		}
		DrawText(optArray[i], (ScrWidth / 2) - 242 + 5, (ScrHeight / 2) - 61 + (i * 23), 0, 0.7f, "normalFont", tsColor, align_left);
	}
}

void DrawPreGamePlayersMenu()
{
	MaxScroll = 11;

	for (int i = 0; i < 12; i++)
	{
		Color tColor = mText;
		int X = 0;
		if (i == PreScroll && PreGameMenuHasBeenSeled)
		{
			tColor = mOutline;
			X = 8;
		}

		if (InParty == 0)
		{
			if (strcmp((char*)0xF9E698 + (i * 0x148), ""))
			{
				char playerName[255];
				if (cg->clientNum == i)
				{
					snprintf(playerName, 255, "%s^7", (char*)0xF9E698 + (i * 0x148));
					if (!(strcmp((char*)0xF9E698 + (i * 0x148), Dvar_GetString("party_hostname"))))
						snprintf(playerName, 255, "[^1HOST^7] ^7%s^7", (char*)0xF9E698 + (i * 0x148));
				}
				else
				{
					if (!(strcmp((char*)0xF9E698 + (i * 0x148), Dvar_GetString("party_hostname"))))
						snprintf(playerName, 255, "[^1HOST^7] ^7%s^7", (char*)0xF9E698 + (i * 0x148));
					else
						snprintf(playerName, 255, "^7%s^7", (char*)0xF9E698 + (i * 0x148));
				}
				DrawText(playerName, (ScrWidth / 2) - 242 + 5, (ScrHeight / 2) - 60 + (i * 23), 0, 0.7f, "normalFont", tColor, align_left);
			}
			else
				DrawText("Not Connected", (ScrWidth / 2) - 242 + 5, (ScrHeight / 2) - 60 + (i * 23), 0, 0.7f, "normalFont", tColor, align_left);
		}
		else
		{
			if (strcmp((char*)0xFA99A0 + (i * 0x148), ""))
			{
				char playerName[255];
				if (cg->clientNum == i)
				{
					snprintf(playerName, 255, "%s^7", (char*)0xFA99A0 + (i * 0x148));
					if (!(strcmp((char*)0xFA99A0 + (i * 0x148), Dvar_GetString("party_hostname"))))
						snprintf(playerName, 255, "[^1HOST^7] ^7%s^7", (char*)0xFA99A0 + (i * 0x148));
				}
				else
				{
					if (!(strcmp((char*)0xFA99A0 + (i * 0x148), Dvar_GetString("party_hostname"))))
						snprintf(playerName, 255, "[^1HOST^7] ^7%s^7", (char)0xFA99A0 + (i * 0x148));
					else
						snprintf(playerName, 255, "^7%s^7", (char*)0xFA99A0 + (i * 0x148));
				}
				DrawText(playerName, (ScrWidth / 2) - 90 + X, (ScrHeight / 2) - 60 + (i * 23), 0, 0.7f, "normalFont", tColor, align_left);
			}
			else
				DrawText("Not Connected", (ScrWidth / 2) - 90 + X, (ScrHeight / 2) - 60 + (i * 23), 0, 0.7f, "normalFont", tColor, align_left);
		}
	}
}

void pDrawBool(bool b, int p)
{
	Color boolColour = { 0, 0, 0, 0 };
	if (b)
		boolColour.a = 1;
	else
		boolColour.a = 0;

	UI_DrawShader((ScrWidth / 2) + 140 - 18 + 280 - 17, (ScrHeight / 2) - 80.5 - 100 + 5 - (5 * 23)+ (5 * 23) + (p * 23), 15, 15, White, 0 ,"white");

	DrawLine((ScrWidth / 2) + 140 - 18 + 280 - 17 + 2, (ScrHeight / 2) - 80.5 - 100 + 2 + 5 + (p * 23), (ScrWidth / 2) + 140 - 18 + 280 - 17 + 13, (ScrHeight / 2) - 80.5 - 100 + 13 + 5 + (p * 23), boolColour);

	DrawLine((ScrWidth / 2) + 140 - 18 + 280 - 17 + 2, (ScrHeight / 2) - 80.5 - 100 + 13 + 5 + (p * 23), (ScrWidth / 2) + 140 - 18 + 280 - 17 + 13, (ScrHeight / 2) - 80.5 - 100 + 2 + 5 + (p * 23), boolColour);
}

void AddOptionsp(int size, const char* optArray[], Color col)
{
	MaxScroll = size - 1;
	int forSize = size;
	for (int i = 0; i < forSize; i++)
	{
		Color pColor = col;
		int X = 0;
		if (i == playerscroll && PlayersMenuHasBeenSeled)
		{
			pColor = mOutline;
		}

		DrawText(optArray[i], (ScrWidth / 2) - 90 + X, (ScrHeight / 2) - 57 + 100 + (i * 23), 0, 0.7f, "normalFont", pColor, align_left);
		pDrawBool(IgnorePlayer[scroll], 1);
		pDrawBool(PrioritisePlayer[scroll], 2);

	}
}

void DrawPlayersOptions()
{
	const char* pOptions[] = { "Steal Name", "Ignore Player", "Prioritise Player", "View Profile" };
	DrawOutline((ScrWidth / 2) - 120 + 263 + 2, (ScrHeight / 2) - 80.5 - 100 + (0 * 23), 280 - 17, (4 * 23), Selector, "white", 2);
	for (int i = 0; i < 4; i++)
	{
		if (i == 2 || i == 4 || i == 6 || i == 0 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20 || i == 22 || i == 24 || i == 26)
			UI_DrawShader((ScrWidth / 2) - 120 + 263+2, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, EvenOptions, 0, "white");
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19 || i == 21 || i == 23 || i == 25 || i == 27)
			UI_DrawShader((ScrWidth / 2) - 120 + 263+2, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, OddOptions, 0, "white");
		Color pColor = mText;

		
		if (PlayersMenuHasBeenSeled && playerscroll == i)
			UI_DrawShader((ScrWidth / 2) - 120 + 263 + 2, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, Selector, 0, "white");

		DrawText(pOptions[i], (ScrWidth / 2) - 120 + 263+2 + 2+5, (ScrHeight / 2) - 80.5 - 100 - (4*23) + ((5 + i) * 23), 0, 0.7f, "normalFont", mText, align_left);
		pDrawBool(IgnorePlayer[scroll], 1);
		pDrawBool(PrioritisePlayer[scroll], 2);
	}
}

void DrawPlayerIPs()
{
	if (!DvarGetBool("cl_ingame"))
	{
		char CurrPlayerInfo[255];
		int IPRes;
		if (InParty == 0)
			IPRes = *(int*)(0xF9E726 + scroll * 0x148);
		else
			IPRes = *(int*)(0xFA9A2E + scroll * 0x148);


		snprintf(CurrPlayerInfo, sizeof(CurrPlayerInfo), "^7IP: %i.%i.%i.%i^7", (IPRes & 0xff000000) >> 24, (IPRes & 0x00ff0000) >> 16, (IPRes & 0x0000ff00) >> 8, (IPRes & 0x000000ff) >> 0);
		DrawOutline((ScrWidth / 2) - 120 + 263 + 2, (ScrHeight / 2) - 23 - 80.5 - 100 + (10 * 23), 280 - 17, (3 * 23), Selector, "white", 2);
		DrawText(CurrPlayerInfo, (ScrWidth / 2) - 120 + 263 + 2 + 5, (ScrHeight / 2) - 80.5 - 100 + (10 * 23), 0, 0.7f, "normalFont", mText, align_left);
	}
	else
	{

		char exIP[255];
		char inIP[255];
		char port[255];
		int eIPRes = *(int*)(0xF9E726 + scroll * 0x148);
		int iIPRes = *(int*)(0xF9E708 + scroll * 0x148);//
		int cPort = *(int*)(0xF9E72A + scroll * 0x148);

		snprintf(exIP, sizeof(exIP), "^7External IP: %i.%i.%i.%i^7", (eIPRes & 0xff000000) >> 24, (eIPRes & 0x00ff0000) >> 16, (eIPRes & 0x0000ff00) >> 8, (eIPRes & 0x000000ff) >> 0);
		snprintf(inIP, sizeof(inIP), "^7Internal IP: %i.%i.%i.%i^7", (iIPRes & 0xff000000) >> 24, (iIPRes & 0x00ff0000) >> 16, (iIPRes & 0x0000ff00) >> 8, (iIPRes & 0x000000ff) >> 0);
		snprintf(port, sizeof(port), "^7Port Address: %i", cPort << 8);
		for (int i = 0; i < 3; i++) {
			if (i == 2 || i == 4 || i == 6 || i == 0 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20 || i == 22 || i == 24 || i == 26)
				UI_DrawShader((ScrWidth / 2) - 120 + 263 + 2, (ScrHeight / 2) - 23 - 80.5 - 100 + (i * 23) + (10 * 23), 280 - 17, 24, EvenOptions, 0, "white");
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19 || i == 21 || i == 23 || i == 25 || i == 27)
				UI_DrawShader((ScrWidth / 2) - 120 + 263 + 2, (ScrHeight / 2) - 23 - 80.5 - 100 + (i * 23) + (10 * 23), 280 - 17, 24, OddOptions, 0, "white");
		}

		DrawOutline((ScrWidth / 2) - 120 + 263 + 2, (ScrHeight / 2) - 23 - 80.5 - 100 + (10 * 23), 280 - 17, (3 * 23), Selector, "white", 2);
		DrawText(exIP, (ScrWidth / 2) - 120 + 263 + 2 + 5, (ScrHeight / 2) - 80.5 - 100 + (10 * 23), 0, 0.7f, "normalFont", mText, align_left);
		DrawText(inIP, (ScrWidth / 2) - 120 + 263 + 2 + 5, (ScrHeight / 2) - 80.5 - 100 + (11 * 23), 0, 0.7f, "normalFont", mText, align_left);
		DrawText(port, (ScrWidth / 2) - 120 + 263 + 2 + 5, (ScrHeight / 2) - 80.5 - 100 + (12 * 23), 0, 0.7f, "normalFont", mText, align_left);
	}
}

void DrawPlayersMenu()
{
	MaxScroll = 11;

	for (int i = 0; i < 12; i++)
	{
		Color tColor = mText;
		int X = 0;
		if (i == scroll && MenuHasBeenSeled)
		{
			tColor = mOutline;
			X = 8;
		}
		if (i == 2 || i == 4 || i == 6 || i == 0 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20 || i == 22 || i == 24 || i == 26)
			UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, EvenOptions, 0, "white");
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19 || i == 21 || i == 23 || i == 25 || i == 27)
			UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, OddOptions, 0, "white");
		if (i == scroll && MenuHasBeenSeled || i == PreScroll && PreGameMenuHasBeenSeled)
		{
			tColor = White;
			X = 0;
			UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 - 100 + (i * 23), 280 - 17, 24, Selector, 0, "white");
		}
		if (strcmp(cg->clients[i].PlayerName, ""))
		{
			
			char playerName[255];
			snprintf(playerName, 255, "%s^7", cg->clients[i].PlayerName);
			DrawText(playerName, (ScrWidth / 2) - 120 + 2 + 5, (ScrHeight / 2) - 61 - 100 + 1.5 + (i * 23), 0, 0.7f, "normalFont", tColor, align_left);
		}
		else
			DrawText("Not Connected", (ScrWidth / 2) - 120 + 2 + 5, (ScrHeight / 2) - 61 - 100 + 1.5 + (i * 23), 0, 0.7f, "normalFont", tColor, align_left);
	}
}

void SubTestOpts()
{
	const char* pOptions[] = { "Steal Name", "Ignore Player", "Prioritise Player", "View Profile" };
	switch (TestScroll)
	{
	case 0:
		AddSubOptions(4, pOptions, sText);
		break;
	}
}

void DrawPreGameSubmenuTitles()
{
	char* SubItems[] = { "Name Changing", "Account Recovery", "Modifications", "Clients List" };
	for (int i = 0; i < 4; i++)
	{

		Color mColor = mText;
		int X = 242;
		if (i == PreSubmenuScroll) {
			mColor = mOutline;
			X = 242;
		}
		DrawText(SubItems[i], ((ScrWidth / 2) - X) + 5 + (i * 130), (ScrHeight / 2) - 82, 0, 0.7f, "normalFont", mColor, align_left);
	}
}

void DrawPreGameMenuOpts()
{
	const char* Name[] = { "Custom 32 Character Name", "Custom Clan", "Flash Clan", "Scar-H Name" };
	const char* Account[] = { "Set Prestige", "Set Level", "Set Fake Level" };
	const char* Modifications[] = { "Force Host", "Force Start", "Join Private Parties", "Spoof IP" };
	switch (PreSubmenuScroll)
	{
	case 0:
		AddOptions(4, Name, mText);
		break;
	case 1:
		AddOptions(3, Account, mText);
		break;
	case 2:
		AddOptions(4, Modifications, mText);
		break;
	case 3:
		DrawPreGamePlayersMenu();
		break;
	}
}
char* MenuTitle = "Project GT";
void DrawMenuOpts()
{
	const char* SubItems[] = { "Main Menu", "ESP Menu", "Aimbot Menu", "Anti-Aim Menu", "Visual Menu", "Pre-Game Menu", "Player List", "Settings", "Entity Checks" };
	const char* Modifications[] = { "No Recoil", "Constant Radar", "No Sway", "Laser", "Change Field of View", "End Game", "Crash Server", "Quit Black Ops II", "Advertise Menu", "Change Name"};
	const char* ESP[] = { "Show Enemies", "Show Teammates", "Box Type", "vAngles", "Draw Name", "Draw Distance", "Draw Weapon", "Draw Snapline", "Draw Bones", "Draw Rank", "Entity ESP" };
	const char* Aiming[] = { "Enable", "Lock-on Key", "Type", "Targeting Type", "Autowall", "Autoshoot", "No Spread", "Lock-on Tag", "Shield Bypass", "Auto Bone" };
	const char* AntiAim[] = { "Enabled", "Pitch", "Yaw", "Spin Speed", "Reverse Direction", "Fake Lag", "Lag Amount" };
	const char* HUD[] = { "Dynamic Radar", "Compass", "Health Bar", "Server Information", "Target Information", "Target Scanner", "Crosshair", "Radar Settings" };
	const char* Customise[] = { "HUD Resizer", "WAll", "EntityHack" };
	const char* Pregame[] = { "Name", "Spoof IP" };
	const char* EntityCheck[] = { "ET_ITEM", "ET_MISSILE", "ET_PLANE", "ET_ACTOR" };
	const char* RadarSettings[] = { "Weapons", "Scavenger Bags", "Items", "Helicopters", "Dogs", "Turrents" };
	switch (SubmenuScroll)
	{
	case 0:
		MenuTitle = "Project GT";
		AddOptions(8, SubItems, TextOption);
		break;
	case 1:
		MenuTitle = "Main Menu";
		AddOptions(10, Modifications, TextOption);
		break;
	case 2:
		MenuTitle = "ESP Menu";
		AddOptions(11, ESP, TextOption);
		break;
	case 3:
		MenuTitle = "Aimbot Menu";
		AddOptions(10, Aiming, TextOption);
		break;
	case 4:
		MenuTitle = "Anti-Aim Menu";
		AddOptions(7, AntiAim, TextOption);
		break;
	case 5:
		MenuTitle = "Visual Menu";
		AddOptions(8, HUD, TextOption);
		break;
	case 6:
		MenuTitle = "Pre-Game Menu";
		AddOptions(2, Pregame, TextOption);
		break;
	case 7:
		MenuTitle = "Player List";
		DrawPlayersMenu();
		break;
	case 8:
		MenuTitle = "Settings";
		AddOptions(3, Customise, TextOption);
		break;
	case 9:
		MenuTitle = "Entity Check";
		AddOptions(4, EntityCheck, TextOption);
		break;
	case 10:
		MenuTitle = "Radar Settings";
		AddOptions(6, RadarSettings, TextOption);
		break;
	}
}


void DrawBool(bool b, int p)
{

	Color boolColour = { 0, 0, 0, 0 };
	if (b)
		boolColour.a = 1;
	else
		boolColour.a = 0;

	UI_DrawShader((ScrWidth / 2) + 140 - 18, (ScrHeight / 2) - 80.5 - 100 + 5 + (p * 23), 15, 15, White, 0, "white");
	DrawLine((ScrWidth / 2) + 140 - 18 + 2, (ScrHeight / 2) - 80.5 - 100 + 2 + 5 + (p * 23), (ScrWidth / 2) + 140 - 18 + 13, (ScrHeight / 2) - 80.5 - 100 + 13 + 5 + (p * 23), boolColour);

	DrawLine((ScrWidth / 2) + 140 - 18 + 2, (ScrHeight / 2) - 80.5 - 100 + 13 + 5 + (p * 23), (ScrWidth / 2) + 140 - 18 + 13, (ScrHeight / 2) - 80.5 - 100 + 2 + 5 + (p * 23), boolColour);
}

void DrawColour(Color col, int p)
{
	UI_DrawShader((ScrWidth / 2) + 140 - 200 + 2 + 75 + 40 + 5, (ScrHeight / 2) - 79 - 100 + 2 + (p * 23), 50, 15, col, 0, "white");
	if (scroll == p && MenuHasBeenSeled)
		DrawOutline((ScrWidth / 2) + 140 - 200 + 2 + 75 + 40 + 5, (ScrHeight / 2) - 79 - 100 + 2 + (p * 23), 50, 15, mOutline, "white", 1);
}

void DrawIntSlider(int value, int min, int max, int p)
{

	int Increment = (max - min) / 75;
	int Zero = Increment;
	int Hundred = Increment * 75;

	int X = ((value - min) * 75) / (max - min);


	char Draw[255];
	snprintf(Draw, 255, "%i", value);
	DrawText(Draw, (ScrWidth / 2) + 135 - 200 + 2 + 75 + 40 + 5, (ScrHeight / 2) - 60.5 - 100 + 2 + (p * 23), 0, 0.7f, "normalFont", mText, align_right);

	UI_DrawShader((ScrWidth / 2) + 140 - 200 + 2 + 75 + 40 + 5, (ScrHeight / 2) - 79 - 100 + 2 + (p * 23), 75, 12, mText, 0, "white");
	UI_DrawShader((ScrWidth / 2) + 140 - 200 + 2 + 75 + 40 + 5+1, (ScrHeight / 2) - 79 - 100 + 2 + (p * 23)+1, X - 2, 10, Selector, 0, "white");
	
}

void DrawComboBoxBorder(int p)
{
	UI_DrawShader((ScrWidth / 2) + 35, (ScrHeight / 2) - 80 + (p * 23), 2, 18, mOutline, 0, "white"); //LEFT
	UI_DrawShader((ScrWidth / 2) + 125, (ScrHeight / 2) - 80 + (p * 23), 2, 19, mOutline, 0, "white"); //RIGHT

	UI_DrawShader((ScrWidth / 2) + 35, (ScrHeight / 2) - 80 + (p * 23), 10, 2, mOutline, 0, "white"); //TOP LEFT
	UI_DrawShader((ScrWidth / 2) + 125, (ScrHeight / 2) - 80 + (p * 23), 11, 2, mOutline, 0, "white"); //TOP RIGHT

	UI_DrawShader((ScrWidth / 2) + 35, (ScrHeight / 2) - 80 + (p * 23) + 18, 11, 2, mOutline, 0, "white"); //BOTTOM LEFT
	UI_DrawShader((ScrWidth / 2) + 125, (ScrHeight / 2) - 80 + (p * 23) + 18, 11, 2, mOutline, 0, "white"); //BOTTOM RIGHT
}

void DrawComboBoxDrop(char* toDraw, int p, const char* items[], int size)
{
	int CurrentP = currComboOpt;
	for (int i = 0; i < size; i++)
	{
		Color t = mText;//UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 + (i * 23), 280 - 17, 24, EvenOptions, 0, "white");
		if (comboScroll == i)
			t = mOutline;
		///
		if (i == 2 || i == 4 || i == 6 || i == 0 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20 || i == 22 || i == 24 || i == 26)
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p + i) * 23), 106, 23, OddOptions, 0, "white");
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19 || i == 21 || i == 23 || i == 25 || i == 27)
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p + i) * 23), 106, 23, EvenOptions, 0, "white");

		//DrawOutline((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p + i) * 23), 106, ((size) * 23), Selector, "white", 2);
		

		if (i == comboScroll)
		{
			//tColor = col;
			//X = 0;
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p + i) * 23), 106, 23, Selector, 0, "white");
		}
		//UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 78 + 2 + ((p + i) * 23), 100, 18, ComboBoxBG, 0, "white");
		DrawText(items[i], (ScrWidth / 2) + 42 + 50, (ScrHeight / 2) - 61 - 100 + 2 + ((p + i) * 23), 0, 0.6f, "normalFont", White, align_center);
	}
}
void DrawComboBoxDrop2(char* toDraw, int p, const char* items[], int size)
{
	int CurrentP = currComboOpt;
	for (int i = 0; i < size; i++)
	{
		Color t = mText;//UI_DrawShader((ScrWidth / 2) - 120, (ScrHeight / 2) - 80.5 + (i * 23), 280 - 17, 24, EvenOptions, 0, "white");
		if (comboScroll == i)
			t = mOutline;
		///
		if (i == 2 || i == 4 || i == 6 || i == 0 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20 || i == 22 || i == 24 || i == 26)
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p + i) * 23), 106, 23, EvenOptions, 0, "white");
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19 || i == 21 || i == 23 || i == 25 || i == 27)
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p + i) * 23), 106, 23, OddOptions, 0, "white");
		if (i == comboScroll)
		{
			//tColor = col;
			//X = 0;
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p + i) * 23), 106, 23, Selector, 0, "white");
		}
		//UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 78 + 2 + ((p + i) * 23), 100, 18, ComboBoxBG, 0, "white");
		
		DrawText(items[i], (ScrWidth / 2) + 42 + 50, (ScrHeight / 2) - 61 - 100 + 2 + ((p + i) * 23), 0, 0.6f, "normalFont", White, align_center);
	}
}

void DrawComboxBoxRes(char* toDraw, int p, const char* items[], int size)
{
	if (!(comboBoxOpen && (scroll == p || PreScroll == p)))
	{
		if (p == 2 || p == 4 || p == 6 || p == 0 || p == 8 || p == 10 || p == 12 || p == 14 || p == 16 || p == 18 || p == 20 || p == 22 || p == 24 || p == 26)
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p) * 23), 106, 23, EvenOptions, 0, "white");
		if (p == 1 || p == 3 || p == 5 || p == 7 || p == 9 || p == 11 || p == 13 || p == 15 || p == 17 || p == 19 || p == 21 || p == 23 || p == 25 || p == 27)
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p) * 23), 106, 23, OddOptions, 0, "white");
		if (p == scroll)
		{
			UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 80.5 - 100 + ((p) * 23), 106, 23, Selector, 0, "white");
		}
		//UI_DrawShader((ScrWidth / 2) + 37, (ScrHeight / 2) - 78 + 2 + (p * 23), 100, 16, ComboBoxBGNoClick, 0, "white");

		char Draw[255];
		snprintf(Draw, 255, "%s", toDraw);
		DrawText(Draw, (ScrWidth / 2) + 42 + 50, (ScrHeight / 2) - 61 - 100 + 2 + (p * 23), 0, 0.6f, "normalFont", mText, align_center);
	}
	else if (comboBoxOpen && (scroll == p || PreScroll == p))
	{
		if (p == 2 || p == 4 || p == 6 || p == 0 || p == 8 || p == 10 || p == 12 || p == 14 || p == 16 || p == 18 || p == 20 || p == 22 || p == 24 || p == 26)
			DrawComboBoxDrop(toDraw, p, items, size);
		if (p == 1 || p == 3 || p == 5 || p == 7 || p == 9 || p == 11 || p == 13 || p == 15 || p == 17 || p == 19 || p == 21 || p == 23 || p == 25 || p == 27)
			DrawComboBoxDrop2(toDraw, p, items, size);
	}
}


void DrawOptBools()
{
	switch (SubmenuScroll)
	{
	case 1:
		DrawBool(NoRecoil, 0);
		DrawBool(constRadar, 1);
		DrawBool(noSway, 2);
		DrawBool(Laser, 3);
		DrawIntSlider(cg_fov, 60, 120, 4);

		DrawBool(FlashName, 8);
		break;
	case 2:
		DrawBool(EnemyESP, 0);
		DrawBool(FriendESP, 1);
		if (!(scroll == 2))
			DrawComboxBoxRes(ESPBoxT, 2, ESPBoxTs, 5);
		DrawBool(vAngles, 3);
		DrawBool(DrawName, 4);
		DrawBool(DrawDistance, 5);
		DrawBool(DrawWeapon, 6);
		if (!(scroll == 7))
			DrawComboxBoxRes(ESPSnapT, 7, ESPSnapTs, 4);
		DrawBool(DrawBones, 8);
		DrawBool(bRank, 9);
		DrawBool(bEntityShader, 10);

		if (scroll == 2)
			DrawComboxBoxRes(ESPBoxT, 2, ESPBoxTs, 5);
		if (scroll == 7)
			DrawComboxBoxRes(ESPSnapT, 7, ESPSnapTs, 4);
		break;
	case 3:
		DrawBool(AimbotEnabled, 0);
		if (!(scroll == 1))
			DrawComboxBoxRes(aimKey, 1, aimKeys, 5);
		if (!(scroll == 2))
			DrawComboxBoxRes(aimType, 2, aimTypes, 2);
		if (!(scroll == 3))
			DrawComboxBoxRes(targType, 3, targetTypes, 3);
		DrawBool(autowallEnabled, 4);
		DrawBool(autoShoot, 5);
		DrawBool(noSpread, 6);

		if (!(scroll == 8))
			DrawComboxBoxRes(riotCheck, 8, riotTypes, 2);
		DrawBool(AutoBone, 9);
		if (scroll == 1)
			DrawComboxBoxRes(aimKey, 1, aimKeys, 5);
		if (scroll == 2)
			DrawComboxBoxRes(aimType, 2, aimTypes, 2);
		if (scroll == 3)
			DrawComboxBoxRes(targType, 3, targetTypes, 3);
		if (scroll == 8)
			DrawComboxBoxRes(riotCheck, 8, riotTypes, 2);
		break;
	case 4:
		DrawBool(AntiAimEnabled, 0);
		if (!(scroll == 1))
			DrawComboxBoxRes(xAntiAim, 1, xAntiAims, 6);
		if (!(scroll == 2))
			DrawComboxBoxRes(yAntiAim, 2, yAntiAims, 7);
		DrawIntSlider(spinSpeed, 10, 45, 3);
		DrawBool(ReverseDir, 4);
		DrawBool(FakeLag, 5);
		DrawIntSlider(LagAmount, 10, 30, 6);

		if (scroll == 1)
			DrawComboxBoxRes(xAntiAim, 1, xAntiAims, 6);
		if (scroll == 2)
			DrawComboxBoxRes(yAntiAim, 2, yAntiAims, 7);
		break;
	case 5:
		DrawBool(Radar, 0);
		DrawBool(bCompass, 1);
		DrawBool(HealthBARR, 2);
		DrawBool(serverInfo, 3);
		DrawBool(targetInfo, 4);
		DrawBool(TargetScan, 5);
		//DrawBool(Cross, 5);
		if (!(scroll == 6))
			DrawComboxBoxRes(CrossHair, 6, Crosshairs, 3);
		if(scroll == 6)
			DrawComboxBoxRes(CrossHair, 6, Crosshairs, 3);
		break;
	case 6:
		if (!(scroll == 1))
			DrawComboxBoxRes(SpoofedIP, 1, IPs, 4);
		if(scroll == 1)
			DrawComboxBoxRes(SpoofedIP, 1, IPs, 4);
		break;
	case 8:
		
		break;
	case 9:
		DrawBool(ItemCheck, 0);
		DrawBool(MissileCheck, 1);
		DrawBool(PlaneCheck, 2);
		DrawBool(ActorCheck, 3);
		break;
	case 10:// "Weapons", "Scavenger Bags", "Items", "Helicopters", "Planes", "Dogs", "Turrents" }
		DrawBool(RadarWeapons, 0);
		DrawBool(RadarScavenger, 1);
		DrawBool(RadarItems, 2);
		DrawBool(RadarHeli, 3);
		DrawBool(RadarDogs, 4);
		DrawBool(RadarTurrent, 5);
		break;
	}
}

void DrawPreGameOptBools()
{
	switch (PreSubmenuScroll)
	{
	case 0:
		DrawBool(FlashPreGame, 2);
		break;
	case 2:
		DrawBool(ForceHost, 0);
		DrawBool(JoinParties, 2);
		DrawComboxBoxRes(SpoofedIP, 3, IPs, 4);
		break;
	}
}

void ChangeNameIngame(char* newName)
{
	if (strlen(newName) < 1)
		newName = (char*)0x1F504DC;
	char playerName[256];
	snprintf(playerName, sizeof(playerName), ";cmd userinfo \"\\name\\%s\\xuid\\%s", newName, 0x26C06E8);

	Cbuf_AddText(playerName);
}




void CG_SetThirdPerson(bool* rs)
{
	*rs = !*rs;
	Invoke<void>(0x61558, 0, *rs);
}

char showcard[255] = "xshowgamercardbyclientnumingame ";
void showgamercard(int client) {
	char buffer[2];
	sprintf(buffer, "%i", showcard, client);
	Cbuf_AddText(buffer);
	buffer[0] = *"";
	buffer[1] = *"";
	buffer[2] = *"";
	showcard[32] = *"";
	showcard[33] = *"";
	showcard[34] = *"";
}