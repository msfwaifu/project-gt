void IntChanger(int way) //0 = Left, 1 = Right
{
	switch (SubmenuScroll)
	{
	case 1:
		switch (scroll)
		{
		case 4:
			switch (way)
			{
			case 0:
				cg_fov--;
				if (cg_fov < 60)
					cg_fov = 120;
				break;
			case 1:
				cg_fov++;
				if (cg_fov > 120)
					cg_fov = 60;

				break;
			}
			char cbuf[255];
			snprintf(cbuf, 255, "cg_fov %i", cg_fov);
			Cbuf_AddText(cbuf);
			break;
		}
		break;
	case 4:
		switch (scroll)
		{
			case 3:
			switch (way)
			{
			case 0:
			spinSpeed--;
			if (spinSpeed < 10)
			spinSpeed = 45;
			break;
			case 1:
			spinSpeed++;
			if (spinSpeed > 45)
			spinSpeed = 10;
			break;
			}
			break;
			case 6:
			switch (way)
			{
			case 0:
			LagAmount--;
			if (LagAmount < 10)
			LagAmount = 30;
			break;
			case 1:
			LagAmount++;
			if (LagAmount > 30)
			LagAmount = 10;
			break;
			}
			break;
		}
		break;
	case 2:
		switch (scroll)
		{
		case 11:
			switch (way)
			{
			case 0:
				fRadarDist--;
				if (fRadarDist < 5)
					fRadarDist = 100;
				break;
			case 1:
				fRadarDist++;
				if (fRadarDist > 100)
					fRadarDist = 5;
				break;
			}
			break;
		case 13:
			switch (way)
			{
			case 0:
				fCompassSize--;
				if (fCompassSize < 30)
					fCompassSize = 160;
				fCompassSizeE--;
				if (fCompassSizeE < 30)
					fCompassSizeE = 160;

				break;
			case 1:
				fCompassSize++;
				if (fCompassSize > 160)
					fCompassSize = 30;
				fCompassSizeE++;
				if (fCompassSizeE > 160)
					fCompassSizeE = 30;
				break;
			}
			break;
		}
		break;
	case 5: //Customize
		switch (scroll)
		{
		case 2:
			switch (way)
			{
			case 0:
				LSD--;
				if (LSD < 0)
					LSD = 9;
				break;
			case 1:
				LSD++;
				if (LSD > 9)
					LSD = 0;
				break;
			}
		}
		break;
	}

}






void PreGameSelectOption()
{
	switch (PreSubmenuScroll)
	{
	case 0:
		switch (PreScroll)
		{
		case 0:
			ChangeNamePreGameKeyboard();
			break;
		case 1:
			FlashPreGame = false;
			sleep(5);
			ChangeClanTagPreGameKeyboard();
			break;
		case 2:
			FlashPreGame = !FlashPreGame;
			break;
		case 3:
			ChangeNamePregame("^H/menu_mp_weapons_scar");
			break;
		}
		break;
	case 2:
		switch (PreScroll)
		{
		case 0:
			ForceHost = !ForceHost;
			if (ForceHost)
				Cbuf_AddText("set party_connectToOthers 0;party_minPlayers 1;party_minLobbyTime 1;party_pregameTimer 1");
			else
				Cbuf_AddText("set party_connectToOthers 1;party_minPlayers 0;party_minLobbyTime 0;party_pregameTimer 0");
			break;
		case 1:
			Cbuf_AddText("xpartygo");
			break;
		case 2:
			JoinParties = !JoinParties;
			if (JoinParties)
			{
				char Off1[] = { 0x38 };
				char Off2[] = { 0x38 };

				WriteProcess(0x533900, Off1, sizeof(Off1));
				WriteProcess(0x521C38, Off2, sizeof(Off2));
			}
			else
			{
				char Off1[] = { 0x41 };
				char Off2[] = { 0x88 };

				WriteProcess(0x533900, Off1, sizeof(Off1));
				WriteProcess(0x521C38, Off2, sizeof(Off2));
			}
			break;
			break;
		case 3:
			comboBox(4);
			break;
		}
		break;
	}
}

void SelectOptionSub()
{
	switch (subScrolls)
	{
	case 0: //SubTest
		switch (scroll)
		{
		case 0:
			PrioritisePlayer[scroll] = false;
			IgnorePlayer[scroll] = !IgnorePlayer[scroll]; break;
		case 1:
			IgnorePlayer[scroll] = false;
			PrioritisePlayer[scroll] = !PrioritisePlayer[scroll]; break;
		} break;
	}
}

void SelectOption()
{
	if (!PlayersMenuHasBeenSeled)
	{
		switch (SubmenuScroll)
		{
		case 0: //Modifications
			switch (scroll)
			{
			case 0:
				SubmenuScroll = 1;
				scroll = 0;
				PreScroll = 0;
				break;
			case 1:
				SubmenuScroll = 2;
				scroll = 0;
				PreScroll = 0;
				break;
			case 2:
				SubmenuScroll = 3;
				scroll = 0;
				PreScroll = 0;
				break;
			case 3:
				SubmenuScroll = 4;
				scroll = 0;
				PreScroll = 0;
				break;
			case 4:
				SubmenuScroll = 5;
				scroll = 0;
				PreScroll = 0;
				break;
			case 5:
				SubmenuScroll = 6;
				scroll = 0;
				PreScroll = 0;
				break;
			case 6:
				SubmenuScroll = 7;
				scroll = 0;
				PreScroll = 0;
				break;
			case 7:
				SubmenuScroll = 8;
				scroll = 0;
				PreScroll = 0;
				break;
			case 8:
				SubmenuScroll = 9;
				scroll = 0;
				PreScroll = 0;
				break;
			case 9:
				SubmenuScroll = 10;
				scroll = 0;
				PreScroll = 0;
				break;
			case 10:
				break;
			}
			break;
		case 1:
			switch (scroll)
			{
			case 0:
				NoRecoil = !NoRecoil;
				if (!NoRecoil)
				{
					char nop[] = { 0x60, 0x00, 0x00, 0x00 };
					WriteProcess(0xF9E54, &nop, sizeof(nop));
				}
				else
				{
					char norec[] = { 0x48, 0x50, 0x6D, 0x65 };
					WriteProcess(0xF9E54, &norec, sizeof(norec));
				}
				break;
			case 1:
				constRadar = !constRadar;
				if (!constRadar)
				{
					char constRadar[] = { 0x60, 0x00, 0x00, 0x00 };
					WriteProcess(0x33C60, &constRadar, sizeof(constRadar));
				}
				else
				{
					char constRadarOff[] = { 0x40, 0x81, 0x00, 0x44 };
					WriteProcess(0x33C60, &constRadarOff, sizeof(constRadarOff));
				}
				break;
			case 2:
				noSway = !noSway;
				break;
			case 3:
				Laser = !Laser;
				if (!Laser)
				{
					char laser[] = { 0x2C, 0x03, 0x00, 0x01 };
					WriteProcess(0xEF68C, &laser, sizeof(laser));
				}
				else
				{
					char laserOff[] = { 0x2C, 0x03, 0x00, 0x00 };
					WriteProcess(0xEF68C, &laserOff, sizeof(laserOff));
				}
				break;
				//case 4: FOV

			case 5:
				char endgame[255];
				snprintf(endgame, 255, "cmd mr %i 3 endround", *(int*)0xF11D9C);
				Cbuf_AddText(endgame);
				break;
			case 6:
				char buffery[255];
				snprintf(buffery, sizeof(buffery), "cmd sl", *(int*)(0xF109E8 + 0x13B4), 3, "_ENDHOST");
				Cbuf_AddText(buffery);
				break;
			case 7:
				Cbuf_AddText("Quit");
				break;
			case 8:
				FlashName = !FlashName;
				break;
			case 9:
				ChangeNameIngameKeyboard();
				break;
			case 10:
				break;
			}
			break;
		case 2: //ESP
			switch (scroll)
			{
			case 0:
				EnemyESP = !EnemyESP;
				break;
			case 1:
				FriendESP = !FriendESP;
				break;
			case 2:
				comboBox(5);
				break;
			case 3:
				vAngles = !vAngles;
				break;
			case 4:
				DrawName = !DrawName;
				break;
			case 5:
				DrawDistance = !DrawDistance;
				break;
			case 6:
				DrawWeapon = !DrawWeapon;
				break;
			case 7:
				comboBox(4);
				break;
			case 8:
				DrawBones = !DrawBones;
				break;
			case 9:
				bRank = !bRank;
				break;
			case 10:
				bEntityShader = !bEntityShader;
				break;
			}
			break;
		case 3: //Aimbot
			switch (scroll)
			{
			case 0:
				AimbotEnabled = !AimbotEnabled;
				break;
			case 1:
				comboBox(5);
				break;
			case 2:
				comboBox(2);
				break;
			case 3:
				comboBox(3);
				break;
			case 4:
				autowallEnabled = !autowallEnabled;
				break;
			case 5:
				autoShoot = !autoShoot;
				break;
			case 6:
				noSpread = !noSpread;
				break;
			case 8:
				comboBox(8);
				break;
			case 9:
				AutoBone = !AutoBone;
				break;
			}
			break;
		case 4: //Anti-Aim
			switch (scroll)
			{
			case 0:
				AntiAimEnabled = !AntiAimEnabled;
				break;
			case 1:
				comboBox(6);
				break;
			case 2:
				comboBox(7);
				break;
			case 4:
				ReverseDir = !ReverseDir;
				break;
			case 5:
				FakeLag = !FakeLag;
				break;
			}
			break;
		case 5: //Heads Up Display
			switch (scroll)
			{
			case 0:
				Radar = !Radar;
				break;
			case 1:
				bCompass = !bCompass;
				break;
			case 2:
				HealthBARR = !HealthBARR;
				break;
			case 3:
				serverInfo = !serverInfo;
				break;
			case 4:
				targetInfo = !targetInfo;
				break;
			case 5:
				TargetScan = !TargetScan;
				break;
			case 6:
				comboBox(3);
				break;
			case 7:
				SubmenuScroll = 10;
				scroll = 0;
				PreScroll = 0;
				break;
			}
				break;
		case 6:
			switch (scroll)
			{
			case 1:
				comboBox(4);
				break;
			}
			break;
		case 7:
			PlayersMenuHasBeenSeled = true;
			playerscroll = 0;
			pMaxScroll = 3;
			break;
		case 8: //Customize
			switch (scroll)
			{
			case 0:
				MenuOpen = false;
				SaveEditorBool = true;
				break;
			case 1:
				WallHacks = !WallHacks;
				break;
			case 2:
				EntityWAll = !EntityWAll;
				break;
			}
			break;
		case 9:
			switch (scroll)
			{
			case 0:
				ItemCheck = !ItemCheck;
				break;
			case 1:
				MissileCheck = !MissileCheck;
				break;
			case 2:
				PlaneCheck = !PlaneCheck;
				break;
			case 3: 
				ActorCheck = !ActorCheck;
				break;
			}
			break;
		case 10:
			switch (scroll)
			{// "Weapons", "Scavenger Bags", "Items", "Helicopters", "Planes", "Dogs", "Turrents" }
			case 0:
				RadarWeapons = !RadarWeapons;
				break;
			case 1: 
				RadarScavenger = !RadarScavenger;
				break;
			case 2:
				RadarItems = !RadarItems;
				break;
			case 3:
				RadarHeli = !RadarHeli;
				break;
			case 4:
				RadarDogs = !RadarDogs;
				break;
			case 5:
				RadarTurrent = !RadarTurrent;
				break;
			}
			break;
		}
	}
	else
	{
		switch (playerscroll)
		{
		case 0:
			if (scroll == cg->clientNum)
				ChangeNameIngame((char*)0x1F504DC);
			else
				ChangeNameIngame(cg->clients[scroll].PlayerName);
			break;
		case 1:
			PrioritisePlayer[scroll] = false;
			IgnorePlayer[scroll] = !IgnorePlayer[scroll];
			break;
		case 2:
			IgnorePlayer[scroll] = false;
			PrioritisePlayer[scroll] = !PrioritisePlayer[scroll];
			break;
		case 3:
			showgamercard(scroll);
			break;
		}
	}
}