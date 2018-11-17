int TickerTimer, TickerTimerbg, TickerTimegb, iClan;

void MenuT(uint64_t)
{
	while (true)
	{
		if (DvarGetBool("cl_ingame"))
		{
			TickerTimer++;
			if (TickerTimer > 10)
			{
				if (!(cg_fov == 65))
				{
					char cbuf[255];
					snprintf(cbuf, 255, "cg_fov %i", cg_fov);
					Cbuf_AddText(cbuf);
				}

			
				WriteProcess(0x9E50D0, (float*)&Smoke, 16);
				if (ForceHost)
					Cbuf_AddText("set party_connectToOthers 0;party_minPlayers 1;party_minLobbyTime 1;party_pregameTimer 1");

				if (Wallhack)
				{
					char FixBlur[] = { 0x00 };
					WriteProcess(0x1CBF9F8, &FixBlur, sizeof(FixBlur));
				}
				TickerTimer = 0;
			}
			InGame = true;
			if (!MenuOpen && SaveEditorBool)
			{

				if (Key_IsDown(X))
				{
					SaveEditorBool = false;
					MenuOpen = true;
					sleep(250);
				}
				if (Key_IsDown(Square))
				{
					Heights = 0;
					Widths = 0;
					sleep(40);
				}
				if (Key_IsDown(Circle))
				{
					SaveEditorBool = false;
					MenuOpen = true;
					Heights = 0;
					Widths = 0;
					sleep(40);	
				}
				if (Key_IsDown(DpadUp))
				{
					Heights--;
					sleep(35);
				}
				if (Key_IsDown(DpadRight))
				{
					Widths--;
					sleep(35);
				}
				if (Key_IsDown(DpadDown))
				{
					Heights++;
					sleep(35);
				}
				if (Key_IsDown(DpadLeft))
				{
					Widths++;
					sleep(35);
				}
			}
			if (!MenuOpen && !RGBEditorOpen && !SubTest)
			{
				if (Key_IsDown(R3) && Key_IsDown(DpadUp))
				{
					MenuOpen = true;
					sleep(200);
				}
			}
			else if (!MenuOpen && SubTest)
			{
				if (Key_IsDown(Circle))
				{
					SubTest = false;
					MenuOpen = true;
					sleep(200);
				}
				if (Key_IsDown(DpadDown))
				{
					subScrolls--;
					if (subScrolls < 0) {
						subScrolls = MaxScroll;
					}
					subScrolls--;
					if (subScrolls < 0) {
						subScrolls = MaxScroll;
					}
					sleep(100);
				}
				if (Key_IsDown(DpadUp))
				{
					subScrolls++;
					if (subScrolls > MaxScroll) {
						subScrolls = 0;
					}
					subScrolls++;
					if (subScrolls > MaxScroll) {
						subScrolls = 0;
					}
					sleep(100);
				}

				if (Key_IsDown(X))
				{
					SelectOptionSub();
					sleep(150);
				}
				if (Key_IsDown(DpadLeft))
				{
					IntChanger(0);
					sleep(40);
				}
				if (Key_IsDown(DpadRight))
				{
					IntChanger(1);
					sleep(40);
				}
			}
			
			else if (MenuOpen)
			{
				if (!comboBoxOpen && !PlayersMenuHasBeenSeled)
				{

					if (Key_IsDown(Circle))
					{

						if (SubmenuScroll == 0)
							MenuOpen = false;
						else if (SubmenuScroll == 10)
							SubmenuScroll = 5;
						else if (SubmenuScroll > 0 && SubmenuScroll != 10) {
							SubmenuScroll = 0;
							scroll = 0;
							PreScroll = 0;
						}
						sleep(200);
					}
					if (Key_IsDown(DpadUp))
					{
						scroll--;
						if (scroll < 0) {
							scroll = MaxScroll;
						}
						PreScroll--;
						if (PreScroll < 0) {
							PreScroll = MaxScroll;
						}
						sleep(100);
					}
					if (Key_IsDown(DpadDown))
					{
						scroll++;
						if (scroll > MaxScroll) {
							scroll = 0;
						}
						PreScroll++;
						if (PreScroll > MaxScroll) {
							PreScroll = 0;
						}
						sleep(100);
					}

					if (Key_IsDown(X))
					{
						SelectOption();
						sleep(150);
					}
					if (Key_IsDown(DpadLeft))
					{
						IntChanger(0);
						sleep(40);
					}
					if (Key_IsDown(DpadRight))
					{
						IntChanger(1);
						sleep(40);
					}
				}
				else if (PlayersMenuHasBeenSeled)
				{
					if (Key_IsDown(Circle))
					{
						SubmenuScroll == 0;
						PlayersMenuHasBeenSeled = false;
						sleep(100);
					}
					if (Key_IsDown(X))
					{
						SelectOption();
						sleep(150);
					}
					if (Key_IsDown(DpadUp))
					{
						playerscroll--;
						if (playerscroll < 0)
							playerscroll = pMaxScroll;
						sleep(100);
					}
					if (Key_IsDown(DpadDown))
					{
						playerscroll++;
						if (playerscroll > pMaxScroll)
							playerscroll = 0;
						sleep(100);
					}
				}
				else if (comboBoxOpen)
				{
					if (Key_IsDown(DpadUp)) //Opt Up
					{
						comboScroll--;
						if (comboScroll < 0)
							comboScroll = maxComboScroll;
						sleep(150);
					}
					if (Key_IsDown(DpadDown)) //Opt Down
					{
						comboScroll++;
						if (comboScroll > maxComboScroll)
							comboScroll = 0;
						sleep(150);
					}
					if (Key_IsDown(X)) //Select Option
					{
						comboBoxCallback();
						sleep(150);
					}
				}
			}
			else if (!MenuOpen && RGBEditorOpen)
			{
				if (Key_IsDown(X))
				{
					SaveColour();
					RGBEditorOpen = false;
					sleep(50);
					MenuOpen = true;
					sleep(150);
				}
				if (Key_IsDown(Circle))
				{
					RGBEditorOpen = false;
					sleep(50);
					MenuOpen = true;
					sleep(150);
				}
				if (Key_IsDown(DpadRight))
				{
					ChangeColourValue(1);
					sleep(1);
				}
				if (Key_IsDown(DpadLeft))
				{
					ChangeColourValue(0);
					sleep(1);
				}
				if (Key_IsDown(DpadUp))
				{
					RGBscroll--;
					if (RGBscroll < 0)
						RGBscroll = 3;
					sleep(150);
				}
				if (Key_IsDown(DpadDown))
				{
					RGBscroll++;
					if (RGBscroll > 3)
						RGBscroll = 0;
					sleep(150);
				}
			}
		}
		else
		{
			InGame = false;
			FlashName = false;

			if (!MenuOpen && SaveEditorBool)
			{

				if (Key_IsDown(X))
				{
					SaveEditorBool = false;
					MenuOpen = true;
					sleep(250);
				}
				if (Key_IsDown(Square))
				{
					Heights = 0;
					Widths = 0;
					sleep(40);
				}
				if (Key_IsDown(Circle))
				{
					SaveEditorBool = false;
					MenuOpen = true;
					Heights = 0;
					Widths = 0;
					sleep(40);
				}
				if (Key_IsDown(DpadUp))
				{
					Heights--;
					sleep(35);
				}
				if (Key_IsDown(DpadRight))
				{
					Widths--;
					sleep(35);
				}
				if (Key_IsDown(DpadDown))
				{
					Heights++;
					sleep(35);
				}
				if (Key_IsDown(DpadLeft))
				{
					Widths++;
					sleep(35);
				}
			}
			if (!MenuOpen && !RGBEditorOpen && !SubTest)
			{
				if (Key_IsDown(R3))
				{
					MenuOpen = true;
					sleep(200);
				}
			}
			else if (!MenuOpen && SubTest)
			{
				if (Key_IsDown(Circle))
				{
					SubTest = false;
					MenuOpen = true;
					sleep(200);
				}
				if (Key_IsDown(DpadDown))
				{
					subScrolls--;
					if (subScrolls < 0) {
						subScrolls = MaxScroll;
					}
					subScrolls--;
					if (subScrolls < 0) {
						subScrolls = MaxScroll;
					}
					sleep(100);
				}
				if (Key_IsDown(DpadUp))
				{
					subScrolls++;
					if (subScrolls > MaxScroll) {
						subScrolls = 0;
					}
					subScrolls++;
					if (subScrolls > MaxScroll) {
						subScrolls = 0;
					}
					sleep(100);
				}

				if (Key_IsDown(X))
				{
					SelectOptionSub();
					sleep(150);
				}
				if (Key_IsDown(DpadLeft))
				{
					IntChanger(0);
					sleep(40);
				}
				if (Key_IsDown(DpadRight))
				{
					IntChanger(1);
					sleep(40);
				}
			}

			else if (MenuOpen)
			{
				if (!comboBoxOpen && !PlayersMenuHasBeenSeled)
				{

					if (Key_IsDown(Circle))
					{

						if (SubmenuScroll == 0)
							MenuOpen = false;
						else if (SubmenuScroll == 10)
							SubmenuScroll = 5;
						else if (SubmenuScroll > 0 && SubmenuScroll != 10) {
							SubmenuScroll = 0;
							scroll = 0;
							PreScroll = 0;
						}
						sleep(200);
					}
					if (Key_IsDown(DpadUp))
					{
						scroll--;
						if (scroll < 0) {
							scroll = MaxScroll;
						}
						PreScroll--;
						if (PreScroll < 0) {
							PreScroll = MaxScroll;
						}
						sleep(100);
					}
					if (Key_IsDown(DpadDown))
					{
						scroll++;
						if (scroll > MaxScroll) {
							scroll = 0;
						}
						PreScroll++;
						if (PreScroll > MaxScroll) {
							PreScroll = 0;
						}
						sleep(100);
					}

					if (Key_IsDown(Square))
					{
						SelectOption();
						sleep(150);
					}
					if (Key_IsDown(DpadLeft))
					{
						IntChanger(0);
						sleep(40);
					}
					if (Key_IsDown(DpadRight))
					{
						IntChanger(1);
						sleep(40);
					}
				}
				else if (PlayersMenuHasBeenSeled)
				{
					if (Key_IsDown(Circle))
					{
						SubmenuScroll == 0;
						PlayersMenuHasBeenSeled = false;
						sleep(100);
					}
					if (Key_IsDown(X))
					{
						SelectOption();
						sleep(150);
					}
					if (Key_IsDown(DpadUp))
					{
						playerscroll--;
						if (playerscroll < 0)
							playerscroll = pMaxScroll;
						sleep(100);
					}
					if (Key_IsDown(DpadDown))
					{
						playerscroll++;
						if (playerscroll > pMaxScroll)
							playerscroll = 0;
						sleep(100);
					}
				}
				else if (comboBoxOpen)
				{
					if (Key_IsDown(DpadUp)) //Opt Up
					{
						comboScroll--;
						if (comboScroll < 0)
							comboScroll = maxComboScroll;
						sleep(150);
					}
					if (Key_IsDown(DpadDown)) //Opt Down
					{
						comboScroll++;
						if (comboScroll > maxComboScroll)
							comboScroll = 0;
						sleep(150);
					}
					if (Key_IsDown(X)) //Select Option
					{
						comboBoxCallback();
						sleep(150);
					}
				}
			}
			else if (!MenuOpen && RGBEditorOpen)
			{
				if (Key_IsDown(X))
				{
					SaveColour();
					RGBEditorOpen = false;
					sleep(50);
					MenuOpen = true;
					sleep(150);
				}
				if (Key_IsDown(Circle))
				{
					RGBEditorOpen = false;
					sleep(50);
					MenuOpen = true;
					sleep(150);
				}
				if (Key_IsDown(DpadRight))
				{
					ChangeColourValue(1);
					sleep(1);
				}
				if (Key_IsDown(DpadLeft))
				{
					ChangeColourValue(0);
					sleep(1);
				}
				if (Key_IsDown(DpadUp))
				{
					RGBscroll--;
					if (RGBscroll < 0)
						RGBscroll = 3;
					sleep(150);
				}
				if (Key_IsDown(DpadDown))
				{
					RGBscroll++;
					if (RGBscroll > 3)
						RGBscroll = 0;
					sleep(150);
				}
			}
		}
		sleep(30);
	}
	sleep(50);
}

void MenuTZM(uint64_t)
{
	while (true)
	{
		if (DvarGetBool("cl_ingame"))
		{
			TickerTimer++;
			if (TickerTimer > 10)
			{
				if (!(cg_fov == 65))
				{
					char cbuf[255];
					snprintf(cbuf, 255, "cg_fov %i", cg_fov);
					Cbuf_AddText(cbuf);
				}
				WriteProcess(0x9E50D0, (float*)&Smoke, 16);
				if (ForceHost)
					Cbuf_AddText("set party_connectToOthers 0;party_minPlayers 1;party_minLobbyTime 1;party_pregameTimer 1");

				if (Wallhack)
				{
					char FixBlur[] = { 0x00 };
					WriteProcess(0x1CBF9F8, &FixBlur, sizeof(FixBlur));
				}
				TickerTimer = 0;
			}
			InGame = true;
			if (!MenuOpen && !RGBEditorOpen && !SubTest)
			{
				if (Key_IsDown(R3) && Key_IsDown(DpadUp))
				{
					MenuOpen = true;
					sleep(200);
				}
			}
			else if (!MenuOpen && SubTest)
			{
				if (Key_IsDown(Circle))
				{
					SubTest = false;
					MenuOpen = true;
					sleep(200);
				}
				if (Key_IsDown(DpadDown))
				{
					subScrolls--;
					if (subScrolls < 0) {
						subScrolls = MaxScroll;
					}
					subScrolls--;
					if (subScrolls < 0) {
						subScrolls = MaxScroll;
					}
					sleep(100);
				}
				if (Key_IsDown(DpadUp))
				{
					subScrolls++;
					if (subScrolls > MaxScroll) {
						subScrolls = 0;
					}
					subScrolls++;
					if (subScrolls > MaxScroll) {
						subScrolls = 0;
					}
					sleep(100);
				}

				if (Key_IsDown(X))
				{

					sleep(150);
				}
				if (Key_IsDown(DpadLeft))
				{
				//	IntChangerZM(0);
					sleep(40);
				}
				if (Key_IsDown(DpadRight))
				{
				//	IntChangerZM(1);
					sleep(40);
				}
			}
			else if (MenuOpen)
			{
				if (!comboBoxOpen)
				{

					if (Key_IsDown(Circle))
					{
						MenuOpen = false;
						sleep(200);
					}
					if (Key_IsDown(L2))
					{
						SubmenuScroll--;
						if (SubmenuScroll < 0)
							SubmenuScroll = 6;
						sleep(150);
					}
					if (Key_IsDown(R2))
					{
						SubmenuScroll++;
						if (SubmenuScroll > 6)
							SubmenuScroll = 0;
						sleep(150);
					}

					if (Key_IsDown(DpadUp))
					{
						scroll--;
						if (scroll < 0) {
							scroll = MaxScroll;
						}
						PreScroll--;
						if (PreScroll < 0) {
							PreScroll = MaxScroll;
						}
						sleep(100);
					}
					if (Key_IsDown(DpadDown))
					{
						scroll++;
						if (scroll > MaxScroll) {
							scroll = 0;
						}
						PreScroll++;
						if (PreScroll > MaxScroll) {
							PreScroll = 0;
						}
						sleep(100);
					}

					if (Key_IsDown(X))
					{
					//	SelectOptionZM();
						sleep(150);
					}
					if (Key_IsDown(DpadLeft))
					{
					//	IntChangerZM(0);
						sleep(40);
					}
					if (Key_IsDown(DpadRight))
					{
					//	IntChangerZM(1);
						sleep(40);
					}
				}
				else if (comboBoxOpen)
				{
					if (Key_IsDown(DpadUp)) //Opt Up
					{
						comboScroll--;
						if (comboScroll < 0)
							comboScroll = maxComboScroll;
						sleep(150);
					}
					if (Key_IsDown(DpadDown)) //Opt Down
					{
						comboScroll++;
						if (comboScroll > maxComboScroll)
							comboScroll = 0;
						sleep(150);
					}
					if (Key_IsDown(X)) //Select Option
					{
						comboBoxCallbackZM();
						sleep(150);
					}
				}
			}
			else if (!MenuOpen && RGBEditorOpen)
			{
				if (Key_IsDown(X))
				{
					SaveColour();
					RGBEditorOpen = false;
					sleep(50);
					MenuOpen = true;
					sleep(150);
				}
				if (Key_IsDown(Circle))
				{
					RGBEditorOpen = false;
					sleep(50);
					MenuOpen = true;
					sleep(150);
				}
				if (Key_IsDown(DpadRight))
				{
					ChangeColourValue(1);
					sleep(1);
				}
				if (Key_IsDown(DpadLeft))
				{
					ChangeColourValue(0);
					sleep(1);
				}
				if (Key_IsDown(DpadUp))
				{
					RGBscroll--;
					if (RGBscroll < 0)
						RGBscroll = 3;
					sleep(150);
				}
				if (Key_IsDown(DpadDown))
				{
					RGBscroll++;
					if (RGBscroll > 3)
						RGBscroll = 0;
					sleep(150);
				}
			}
		}
		else
		{
			InGame = false;
			FlashName = false;

			if (!PreGameMenuOpen)
			{
				if (Key_IsDown(R3))
				{
					PreGameMenuOpen = true;
					sleep(200);
				}
			}
			if (!comboBoxOpen)
			{
				if (!comboBoxOpen)
				{

					if (Key_IsDown(R3))
					{
						PreGameMenuOpen = false;
						sleep(200);
					}
					if (Key_IsDown(L2))
					{
						PreSubmenuScroll--;
						if (PreSubmenuScroll < 0)
							PreSubmenuScroll = 3;
						sleep(150);
					}
					if (Key_IsDown(R2))
					{
						PreSubmenuScroll++;
						if (PreSubmenuScroll > 3)
							PreSubmenuScroll = 0;
						sleep(150);
					}
					if (Key_IsDown(DpadUp))
					{
						scroll--;
						if (scroll < 0) {
							scroll = MaxScroll;
						}
						PreScroll--;
						if (PreScroll < 0) {
							PreScroll = MaxScroll;
						}
						sleep(100);
					}
					if (Key_IsDown(DpadDown))
					{
						scroll++;
						if (scroll > MaxScroll)
						{
							scroll = 0;
						}
						PreScroll++;
						if (PreScroll > MaxScroll) {
							PreScroll = 0;
						}
						sleep(100);
					}
					if (Key_IsDown(L3))
					{
					//	PreGameSelectOptionZM();
						sleep(150);
					}
				}
			}
			else if (comboBoxOpen)
			{
				if (Key_IsDown(DpadUp)) //Opt Up
				{
					comboScroll--;
					if (comboScroll < 0)
						comboScroll = maxComboScroll;
					sleep(150);
				}
				if (Key_IsDown(DpadDown)) //Opt Down
				{
					comboScroll++;
					if (comboScroll > maxComboScroll)
						comboScroll = 0;
					sleep(150);
				}
				if (Key_IsDown(L3)) //Select Option
				{
					comboBoxCallbackZM();
					sleep(150);
				}
			}
		}
		sleep(30);
	}
	sleep(50);
}