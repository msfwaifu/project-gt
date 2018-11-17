
void Dynamic_Radar(int Client)
{
	if (Radar)
	{
		RadarAlapha();
		rectDef_s rect = { rect.y - 20 };
		rectDef_s prect;
		RadarCenter.x = (Center.x * 2) - RadarSize - 40;
		RadarCenter.y = RadarSize / 2 + 25;

		UI_DrawShader(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (RadarCenter.y - RadarSize / 2) + Heights, (RadarSize * 1.5) - 40, RadarSize, radarBackground, 0, "white");
		CG_CompassDrawPlayerMap(&prect, &rect);
		UI_DrawShader(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, RadarCenter.y + Heights, (((RadarSize * 1.5) - 55) / 2), 1, White, 0, "white"); // horz
		UI_DrawShader((((RadarCenter.x - RadarSize / 1.5) + 14 + ((RadarSize * 1.5) - 55) / 2) + 100) + Widths, RadarCenter.y + Heights, (((RadarSize * 1.5) - 55) / 2) + 2, 1, White, 0, "white"); // horz
		UI_DrawShader(((RadarCenter.x) + 100) + Widths, (RadarCenter.y - RadarSize / 2) + Heights, 1, (RadarSize / 2) - 10, White, 0, "white"); // vert
		UI_DrawShader(((RadarCenter.x) + 100) + Widths, ((RadarCenter.y - RadarSize / 2) + (RadarSize / 2) + 10) + Heights, 1, (RadarSize / 2) - 10, White, 0, "white");

		DrawOutlineMenus(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (RadarCenter.y - RadarSize / 2) + Heights, (RadarSize * 1.5) - 40, RadarSize, Selector, "white", 2, Gradient1);
		float healthHeight = cgArray_s->Health * 1.75;
		for (int i = 0; i < 2048; i++)
		{
			int Type = Centity_s[i].Type;
			int RadarX, RadarY;

			RadarX = GetPlayerOrigin(cgArray_s->ClientNumber).x - GetPlayerOrigin(i).x;
			RadarY = GetPlayerOrigin(cgArray_s->ClientNumber).y - GetPlayerOrigin(i).y;

			float Angle = cg->playerstate.viewAngles.y / 180 * 3.141;

			float RotateX = RadarY * cosf(Angle) - RadarX * sinf(Angle);
			float RotateY = RadarX * cosf(Angle) + RadarY * sinf(Angle);

			float FinalX = RadarCenter.x + RotateX / 8.1232;//9.0686;
			float FinalY = RadarCenter.y + RotateY / 10.4686; //12.5977;

			if (FinalX < RadarCenter.x - RadarSize / 1.5) FinalX = (RadarCenter.x - RadarSize / 1.5) + 2;
			if (FinalY < RadarCenter.y - RadarSize / 2) FinalY = (RadarCenter.y - RadarSize / 2) + 2;

			if (FinalX > RadarCenter.x + RadarSize / 1.5) FinalX = (RadarCenter.x + RadarSize / 1.5) - 2;
			if (FinalY > RadarCenter.y + RadarSize / 2) FinalY = (RadarCenter.y + RadarSize / 2) - 2;

			if (i != Client)
			{
				if ((!cg->clients[i].Dead) && Centity_s[i].Type == ET_Player && strcmp(cg->clients[i].PlayerModel, ""))
				{
					Color ESPColor;
					if (!isPlayerFriendly(&Centity[i]))
					{
						if (i == nearestClient)
						{
							ESPColor = ESPTargeted;
						}
						else if (PrioritisePlayer[i])
						{
							ESPColor = ESPPrioritise;
						}
						else if (IgnorePlayer[i])
						{
							ESPColor = ESPIgnore;
						}
						else if ((autowallEnabled && playerReady && PrioritisePlayer[i]) || (!autowallEnabled && isPlayerVisible(&Centity[i]) && PrioritisePlayer[i]))
						{
							ESPColor = ESPPrioritise;
						}
						else if ((autowallEnabled && playerReady) || (!autowallEnabled && isPlayerVisible(&Centity[i])))
						{
							ESPColor = ESPVisible;
						}
						else
						{
							ESPColor = ESPEnemy;
						}
					}
					else if (isPlayerFriendly(&Centity[i]))
					{
						ESPColor = ESPFriend;
					}

					UI_DrawShader(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 20, 20, ESPColor, (cg1->playerstate.viewAngles.y - cg1->clients[i].viewAngle.y), "compassping_player");
				}

			}
			else {
				UI_DrawShader(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 20, 20, Selector, 0, "compassping_player");
			}
			if (Centity[i].Type == ET_ITEM)
			{
				WeaponVariantDef * WeaponsShaderss = BG_VarientDef(Centity[i].pickupId);
				if ((Centity_s[i].State & (1 << 6)) != 0) {//bouncingbetty_mp
					if (!strcmp(WeaponsShaderss->name, "scavenger_item_mp")) {
						if(RadarScavenger)
							UI_DrawShaderPVOID(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 35, 25, White, (cgArray_s->ViewAngle.y), Material_RegisterHandle("hud_scavenger_pickup", 0), 9);
					}
					else if (WeaponsShaderss->weapDef->hudIcon)
					{
						if (RadarWeapons) {
							UI_DrawShaderPVOID(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 35, 25, White, (cgArray_s->ViewAngle.y), WeaponsShaderss->weapDef->hudIcon, 9);
						}
					}
				}
			}
			if (Centity[i].Type == ET_MISSILE)
			{
				WeaponVariantDef * Weapvardef = BG_VarientDef(Centity[i].pickupId);
				if ((Centity_s[i].State & (1 << 6)) != 0)
				{
					if(RadarItems)
					UI_DrawShaderPVOID(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 20, 12, White, (cg1->playerstate.viewAngles.y), Weapvardef->weapDef->hudIcon, 9);
				}
			}
			if (Centity[i].Type == ET_PLANE)
			{
				if ((Centity_s[i].State & (1 << 6)) != 0)
				{
					if(RadarPlane)
					UI_DrawShader(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 50, 50, White, (cg1->playerstate.viewAngles.y - compassVeh->lastYaw), "hud_ks_u2_spyplane");
				}
			}
			if (Centity[i].Type == ET_HELICOPTER)
			{
				if ((Centity_s[i].State & (1 << 6)) != 0)
				{
					if(RadarHeli)
					UI_DrawShader(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 50, 50, White, (cg1->playerstate.viewAngles.y - compassHeli->lastYaw), "compass_objpoint_helicopter");
				}
			}
			if (Centity[i].Type == ET_TURRET)
			{
				if ((Centity_s[i].State & (1 << 6)) != 0) {
					if(RadarTurrent)
					UI_DrawShader(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 30, 30, White, (cg1->playerstate.viewAngles.y - compassTurrent->lastYaw), "compass_turret_white");
				}
			}
			if (Centity[i].Type == ET_ACTOR)
			{
				if ((Centity_s[i].State & (1 << 6)) != 0) {
					if(RadarDogs)
					UI_DrawShader(((FinalX - 10) + 100) + Widths, (FinalY - 10) + Heights, 20, 20, White, (cgArray_s->ViewAngle.y), "hud_obit_dogs");
				}
			}
		}
	}
}

void arrowCompass(int Client)
{
	if (bCompass) {

		for (int i = 0; i < 18; i++)
		{//getCurrentWeapon
			if (i != Client) {
				if (Centity[i].Type == ET_PLAYER)
				{
					if ((!cg->clients[i].Dead) && Centity[i].Type == ET_Player && strcmp(cg->clients[i].PlayerModel, ""))
					{

						int RadarX, RadarY;
						int Shader, dwWidth, dwHeight;
						dwWidth = 20; dwHeight = 10;
						int wWidth, wHeight;
						wWidth = 40; wHeight = 25;

						RadarX = GetPlayerOrigin(cgArray_s->ClientNumber).x - GetPlayerOrigin(i).x;
						RadarY = GetPlayerOrigin(cgArray_s->ClientNumber).y - GetPlayerOrigin(i).y;

						float Angle = cg1->playerstate.viewAngles.y / 180 * 3.141;

						float RotateX = RadarY * cosf(Angle) - RadarX * sinf(Angle);
						float RotateY = RadarX * cosf(Angle) + RadarY * sinf(Angle);

						float FinalX = cCenter.x + RotateX;
						float FinalY = cCenter.y + RotateY;

						float angle = myMath::atan2(RotateX, RotateY) * (360 / M_PI);
						float FinalA = (FinalY > cCenter.y ? -angle - 180.0f : -angle);

						if (FinalA < 0)
							FinalA += 360.0f;

						double radians = (M_PI / 180)*(FinalA - 90.0f);
						float CircleX = cCenter.x + (cosf(radians) * fCompassSize);
						float CircleY = cCenter.y + (sinf(radians) * fCompassSize);
						float CircleXX = cCenter.x + (cosf(radians) * (fCompassSize - 20));
						float CircleYX = cCenter.y + (sinf(radians) * (fCompassSize - 20));
						Color ESPColor;

						if (!isPlayerFriendly(&Centity[i]))
						{
							if (i == nearestClient)
							{
								ESPColor = ESPTargeted;
							}
							else if (PrioritisePlayer[i])
							{
								ESPColor = ESPPrioritise;
							}
							else if (IgnorePlayer[i])
							{
								ESPColor = ESPIgnore;
							}
							else if ((autowallEnabled && playerReady && PrioritisePlayer[i]) || (!autowallEnabled && isPlayerVisible(&Centity[i]) && PrioritisePlayer[i]))
							{
								ESPColor = ESPPrioritise;
							}
							else if ((autowallEnabled && playerReady) || (!autowallEnabled && isPlayerVisible(&Centity[i])))
							{
								ESPColor = ESPVisible;
							}
							else
							{
								ESPColor = ESPEnemy;
							}
						}

						if (EnemyESP)
						{
							if (!CG_IsEntityFriendlyNotEnemy(0, Centityy(i)))
							{

								if (AimTarget_isTargetVisible(0, Centityy(i)))
								{
									UI_DrawShader(CircleX - dwWidth, CircleY - dwHeight, dwWidth, dwHeight, ESPColor, FinalA, "hud_grenadepointer");
								}
								else if (PrioritisePlayer[i])
									UI_DrawShader(CircleX - dwWidth, CircleY - dwHeight, dwWidth, dwHeight, ESPColor, FinalA, "hud_grenadepointer");
								else if (IgnorePlayer[i])
									UI_DrawShader(CircleX - dwWidth, CircleY - dwHeight, dwWidth, dwHeight, ESPColor, FinalA, "hud_grenadepointer");
								else {
									UI_DrawShader(CircleX - dwWidth, CircleY - dwHeight, dwWidth, dwHeight, ESPColor, FinalA, "hud_grenadepointer");
								}
								if (DrawWeapon)
								{
									//WeaponDef * WeaponsShaders = BG_GetWeaponDef(Centity[i].primaryWeapon);
									UI_DrawShader(CircleXX - wWidth, CircleYX - wHeight, wWidth, wHeight, White, FinalA, GetWeaponShaderName(&Centity[i]));
								}

							}
						}
						if (FriendESP)
						{
							if (CG_IsEntityFriendlyNotEnemy(0, Centityy(i)))
							{
								UI_DrawShader(CircleX - dwWidth, CircleY - dwHeight, dwWidth, dwHeight, GreenC, FinalA, "hud_grenadepointer");
								if (DrawWeapon)
								{
									UI_DrawShader(CircleXX - wWidth, CircleYX - wHeight, wWidth, wHeight, White, FinalA, GetWeaponShaderName(&Centity[i]));
								}
							}
						}
					}
				}
			}
		}
	}
}

void _EntityESP()
{
	for (int i = 0; i < 1024; i++)
	{
		if (Centity_s[i].Type > 0)
		{
			Vector2 Location;
			if (WorldPosToScreenPos(Centity_s[i].Origin, &Location))
			{
				if (Centity[i].Type == ET_ITEM)
				{
					WeaponVariantDef * WeaponsShaderss = BG_VarientDef(Centity[i].pickupId);
					if ((Centity[i].State & (1 << 6)) != 0) {
						if (!strcmp(WeaponsShaderss->name, "scavenger_item_mp")) {
							UI_DrawShaderPVOID(Location.x, Location.y, 35, 25, White, 0, Material_RegisterHandle("hud_scavenger_pickup", 0), 9);
						}
						else if (WeaponsShaderss->weapDef->hudIcon)
						{
							UI_DrawShaderPVOID(Location.x, Location.y, 35, 25, White, 0, WeaponsShaderss->weapDef->hudIcon, 9);
						}

						if (ItemCheck)
							DrawLine(dc.width / 2, dc.height / 2, Location.x, Location.y, White);

					}
				}
				else if (Centity_s[i].Type == ET_MISSILE)
				{
					if ((Centity_s[i].State & (1 << 6)) != 0) {
						WeaponVariantDef * Weapvardef = BG_VarientDef(Centity[i].pickupId);
							UI_DrawShaderPVOID(Location.x, Location.y, 35, 25, White, 0, Weapvardef->weapDef->hudIcon, 9);
					
					}
					if (MissileCheck) 
						DrawLine(dc.width / 2, dc.height / 2, Location.x, Location.y, White);
				}
				if (Centity[i].Type == ET_PLANE) {
					if ((Centity[i].State & (1 << 6)) != 0)
					{
						if (PlaneCheck)
							DrawLine(dc.width / 2, dc.height / 2, Location.x, Location.y, White);
					}
				}
				if (Centity[i].Type == ET_ACTOR) {
					if ((Centity[i].State & (1 << 6)) != 0)
					{
						if (ActorCheck)
							DrawLine(dc.width / 2, dc.height / 2, Location.x, Location.y, White);
					}
				}
			}
		}
	}
}

void HealthBarHook() {
	int CenterX = 1280 / 2;
	int CenterY = 720 / 2;
	RadarCenter.x = (Center.x * 2) - RadarSize - 40;
	RadarCenter.y = RadarSize / 2 + 25;
	if (HealthBARR) {
		float w = 200, health = ((float)cgArray_s->Health / 100.0f);
		float wh = 17.5;
		float x = CenterX - w / 2;
		float healthHeight = cgArray_s->Health * (1.75 * 2);
		Color healthColor = { (float)1 - (cgArray_s->Health / 100), (float)cgArray_s->Health / 100, 0, 1 };
		if (Radar)
		{
			DrawOutlineMenus(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (((RadarCenter.y - RadarSize / 2) + RadarSize + RadarSize / 4) - 24 + 4 - 2 - 15 - 17) + Heights, (RadarSize * 1.5) - 40, 10, Selector, "white", 2, Gradient1);
			UI_DrawShader(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (((RadarCenter.y - RadarSize / 2) + RadarSize + RadarSize / 4) - 24 + 4 - 2 - 15 - 17) + Heights, (RadarSize * 1.5) - 40, 10, Red, 0, "white");
			UI_DrawShader(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (((RadarCenter.y - RadarSize / 2) + RadarSize + RadarSize / 4) - 24 + 4 - 2 - 15 - 17) + Heights, (healthHeight)-15, 10, GreenC, 0, "white");
		}
		else
		{
			DrawOutlineMenus(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (ScrHeight - 15) + Heights, (RadarSize * 1.5) - 40, 10, Selector, "white", 2, Gradient1);
			UI_DrawShader(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (ScrHeight - 15) + Heights, (RadarSize * 1.5) - 40, 10, Red, 0, "white");
			UI_DrawShader(((RadarCenter.x - RadarSize / 1.5) + 100) + Widths, (ScrHeight - 15) + Heights, (healthHeight)-15, 10, GreenC, 0, "white");
		}
	}
}

void DrawVAngles(Vector3 FromOrigin, int Entity, Color ESP)
{
	Vector2 Screen1, Screen2;
	float Scale = 150;
	Vector3 From(FromOrigin.x, FromOrigin.y, FromOrigin.z);
	Vector3 ToForward = AnglesToFoward(From, cg1->clients[Entity].viewAngle, Scale);
	if (WorldPosToScreenPos(From, &Screen1))
	{
		if (WorldPosToScreenPos(ToForward, &Screen2))
		{
			if (!CG_IsEntityFriendlyNotEnemy(0, Centityy(Entity)))
			{
				if (AimTarget_isTargetVisible(0, Centityy(Entity)))
				{
					DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, ESP);
				}
				else if (PrioritisePlayer[Entity])
					DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, ESP);
				else if (IgnorePlayer[Entity])
					DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, ESP);
				else {
					DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, ESP);
				}

			}
			else
			{
				DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, ESP);
			}
			DrawLine(Screen1.x, Screen1.y, Screen2.x, Screen2.y, ESP);
		}
	}
}

void renderESP(int localPlayer)
{
	cCenter.x = cg->refdef.Width / 2;
	cCenter.y = cg->refdef.Height / 2;

	Center.x = cg->refdef.Width / 2;
	Center.y = cg->refdef.Height / 2;

	if (bEntityShader)
		_EntityESP();

	for (int i = 0; i < 18; i++)
	{
		bool DrawNow = false;
		if (DvarGetBool("cl_ingame"))
		{
			if (i != localPlayer)
			{
				if ((!cg->clients[i].Dead) && Centity[i].Type == ET_Player && strcmp(cg->clients[i].PlayerModel, ""))
				{
					Vector3 HeadOrigin = AimTarget_GetTagPos(&Centity[i], "j_head");
					Vector2 HeadPos;
					Vector3 MainOrigin = AimTarget_GetTagPos(&Centity[i], "j_mainroot");
					Vector2 SpineOrigin;
					Vector3 FootOrigin = Centity[i].origin;
					Vector2 FootPos;
					Vector3 FeetOrigin = GetPlayerOrigin(i);
					Vector3 HeadOrigin1 = AimTarget_GetTagPos(&Centity[i], "j_head");
					Vector3 NeckOrigin = AimTarget_GetTagPos(&Centity[i], "j_neck");
					Vector2 FeetLocation, HeadLocation, NeckLocation;
					FeetOrigin.z -= 5;
					HeadOrigin1.z += 10;
					HeadOrigin.z += 10;
					MainOrigin.z += 4;
					FootOrigin.z -= 5;

					if (WorldPosToScreenPos(MainOrigin, &SpineOrigin) && WorldPosToScreenPos(FeetOrigin, &FeetLocation) &&
						WorldPosToScreenPos(HeadOrigin, &HeadLocation) && WorldPosToScreenPos(NeckOrigin, &NeckLocation))
					{
						if (WorldPosToScreenPos(FootOrigin, &FootPos))
						{
							if (WorldPosToScreenPos(HeadOrigin, &HeadPos))
							{
								int BoxHeight = abs(FootPos.y - HeadPos.y);
								float fHeight = FeetLocation.y - HeadLocation.y;
								float fWidth;
								fWidth = fHeight / 1.95;
								float correctY = HeadPos.y - 36000 / Distance3D(GetPlayerOrigin(LocalPlayer), GetPlayerOrigin(i));
								Color ESPColor;
								if (EnemyESP)
								{
									if (!isPlayerFriendly(&Centity[i]))
									{
										if (i == nearestClient)
										{
											ESPColor = ESPTargeted;
											DrawNow = true;
										}
										else if (PrioritisePlayer[i])
										{
											ESPColor = ESPPrioritise;
											DrawNow = true;
										}
										else if (IgnorePlayer[i])
										{
											ESPColor = ESPIgnore;
											DrawNow = true;
										}
										else if ((autowallEnabled && playerReady && PrioritisePlayer[i]) || (!autowallEnabled && isPlayerVisible(&Centity[i]) && PrioritisePlayer[i]))
										{
											ESPColor = ESPPrioritise;
											DrawNow = true;
										}
										else if ((autowallEnabled && playerReady) || (!autowallEnabled && isPlayerVisible(&Centity[i])))
										{
											ESPColor = ESPVisible;
											DrawNow = true;
										}
										else
										{
											ESPColor = ESPEnemy;
											DrawNow = true;
										}
									}
								}
								if (vAngles)
								{
									DrawVAngles(NeckOrigin, i, ESPColor);
								}
								if (FriendESP)
								{
									if (isPlayerFriendly(&Centity[i]))
									{
										ESPColor = ESPFriend;
										DrawNow = true;
									}
								}
								if (DrawNow)
								{
									if (DrawName)
									{
										int amount;
										if (DrawDistance)
											amount = 16;
										else
											amount = 8;
										DrawText(cg->clients[i].PlayerName, HeadPos.x, HeadPos.y - amount, 0, 0.5, "normalFont", White, align_center);
									}
									if (DrawWeapon)
									{
										UI_DrawShader(FeetLocation.x - 70 / 2, FootPos.y, 70, 40, White, 0, GetWeaponShaderName(&Centity[i]));
									}
									if (bRank)
										UI_DrawShader(FeetLocation.x - 35 / 2, (FootPos.y) + 35, 35, 35, White, 0, getPrestigeIcon(i));
									if (DrawDistance)
									{
										int DistanceF = Distance3D(_GetPlayerOrigin(cg->clientNum), _GetPlayerOrigin(i));
										char DistanceBuff[250];
										snprintf(DistanceBuff, sizeof(DistanceBuff), "%im", DistanceF / 100);
										DrawText(DistanceBuff, HeadPos.x, HeadPos.y - 6, 0, 0.5, "normalFont", White, align_center);
										//DrawESPText(1, i, HeadPos.x + 15, HeadPos.y + 7, ESPColor);
									}
									if (BoxType == 1)
									{
										espBackground.a = 0.6;
										ESPColor.a = 0.6;
										DrawOutline((SpineOrigin.x - BoxHeight / 4) + 1, (HeadPos.y) + 1, (BoxHeight / 2) - 2, BoxHeight - 2, espBackground, "white", 2);
										DrawOutlineMenus(SpineOrigin.x - BoxHeight / 4, HeadPos.y, BoxHeight / 2, BoxHeight, ESPColor, "white", 2, Gradient1);
										DrawOutline((SpineOrigin.x - BoxHeight / 4) - 1, (HeadPos.y) - 1, (BoxHeight / 2) + 2, BoxHeight + 2, espBackground, "white", 2);
										espBackground.a = 1;
										ESPColor.a = 1;
									}
									if (BoxType == 2)
									{
										ESPColor.a = 0.6;
										BoxAroundPlayer(AimTarget_GetTagPos(&Centity[i], "j_head"), 20, 60, ESPColor, 0, i, HeadPos.x, correctY, Distance3D(GetPlayerOrigin(i), GetPlayerOrigin(LocalPlayer)));
										ESPColor.a = 1;
									}
									if (BoxType == 3)
									{
										ESPColor.a = 0.6;
										BoxAroundPlayer(AimTarget_GetTagPos(&Centity[i], "j_head"), 20, 60, ESPColor, 3, i, HeadPos.x, correctY, Distance3D(GetPlayerOrigin(i), GetPlayerOrigin(LocalPlayer)));
										ESPColor.a = 1;
									}
									if (BoxType == 4)
									{
										UI_DrawShader((FeetLocation.x - (fWidth / 2)), (FeetLocation.y - fHeight), (fWidth / 4), 1, ESPColor, 0, "white");						// top left line
										UI_DrawShader((FeetLocation.x - (fWidth / 2)), FeetLocation.y, (fWidth / 4), 1, ESPColor, 0, "white");									// bottom left line
										UI_DrawShader((FeetLocation.x - (fWidth / 2)), (FeetLocation.y - fHeight), 1, (fWidth / 4), ESPColor, 0, "white");						// left top line
										UI_DrawShader((FeetLocation.x + (fWidth / 2)), (FeetLocation.y - fHeight), 1, (fWidth / 4), ESPColor, 0, "white");						// right top line

										UI_DrawShader((FeetLocation.x + ((fWidth / 2) - (fWidth / 4))), (FeetLocation.y - fHeight), (fWidth / 4), 1, ESPColor, 0, "white");		// top right line
										UI_DrawShader((FeetLocation.x + ((fWidth / 2) - (fWidth / 4))), FeetLocation.y, (fWidth / 4) + 1, 1, ESPColor, 0, "white");				// bottom right line
										UI_DrawShader((FeetLocation.x - (fWidth / 2)), (FeetLocation.y - (fWidth / 4)), 1, (fWidth / 4), ESPColor, 0, "white");					// left bottom line
										UI_DrawShader((FeetLocation.x + (fWidth / 2)), (FeetLocation.y - (fWidth / 4)), 1, (fWidth / 4), ESPColor, 0, "white");


									}
									if (SnapType > 0)
									{
										int X = (ScrWidth / 2);
										int Y;
										if (SnapType == 1)
											Y = (ScrHeight / 2) - (ScrHeight + 1);
										if (SnapType == 2)
											Y = (ScrHeight / 2);
										if (SnapType == 3)
											Y = (ScrHeight / 2) + (ScrHeight - 1);

										DrawLine(X, Y, FootPos.x, FootPos.y, ESPColor);
									}
									if (DrawBones)
									{
										DoAllBones(i, ESPColor);
									}
									ESPColor.a = 1;
								}
								DrawNow = false;
							}
						}
					}
				}
				Vector2 OriginF;
				Vector3 HeadPos43 = AimTarget_GetTagPos(&Centity[nearestClient], "j_mainroot");

				int X, Y;

				if (X > ((ScrWidth / 4) + (ScrWidth / 4)))
					X = 1000;
				else if (X < (ScrWidth / 4))
					X = -1000;

				if (Y >(ScrHeight / 4 + ((ScrHeight / 4) + ScrHeight / 4)))
					Y = 1000;
				else if (Y < ScrHeight / 4)
					Y = -1000;

			}
		}
	}
}

void CrossHairs()
{
	float xHairSize = (8 + (cg->spreadMultiplier / 4));
	float CrosshairX1 = cg->refdef.Width / 2 - 8 - xHairSize;
	float CrosshairY1 = cg->refdef.Width / 2 - 1 + xHairSize;

	float CrosshairX2 = cg->refdef.Height / 2 - 8 - xHairSize;
	float CrosshairY2 = cg->refdef.Height / 2 - 1 + xHairSize;

		if (CrossType == 0)
		{}
		else if (CrossType == 1)
		{//+
			UI_DrawShader(CrosshairX1, cg->refdef.Height / 2 - 1, 8, 1, Selector, 0, "white");
			UI_DrawShader(CrosshairY1, cg->refdef.Height / 2 - 1, 8, 1, Gradient1, 180, "white");
			UI_DrawShader(cg->refdef.Width / 2 - 1, CrosshairX2, 1, 8, Selector, 0, "white");
			UI_DrawShader(cg->refdef.Width / 2 - 1, CrosshairY2, 1, 8, Gradient1, 180, "white");
		}
		else if (CrossType == 2)
		{//X
			DrawLine(CrosshairY1, (ScrHeight / 2) + 15, (ScrWidth / 2), (ScrHeight / 2), Selector);
			DrawLine(CrosshairY2, (ScrHeight / 2) - 15, (ScrWidth / 2), (ScrHeight / 2), Selector);


			DrawLine(CrosshairX1, (ScrHeight / 2) + 15, (ScrWidth / 2), (ScrHeight / 2), Selector);
			DrawLine(CrosshairX2, (ScrHeight / 2) - 15, (ScrWidth / 2), (ScrHeight / 2), Selector);

			/*DrawLine((ScrWidth / 2) + 15, (ScrHeight / 2) + 15, (ScrWidth / 2), (ScrHeight / 2), Selector);
			DrawLine((ScrWidth / 2) + 15, (ScrHeight / 2) - 15, (ScrWidth / 2), (ScrHeight / 2), Selector);


			DrawLine((ScrWidth / 2) - 15, (ScrHeight / 2) + 15, (ScrWidth / 2), (ScrHeight / 2), Selector);
			DrawLine((ScrWidth / 2) - 15, (ScrHeight / 2) - 15, (ScrWidth / 2), (ScrHeight / 2), Selector);*/
		}
}



char* TargetName;
void TargetFinder()
{
	if (TargetScan)
	{
		LocalPlayer = cg->clientNum;
		int nearestClient = GetNearestPlayer(LocalPlayer);
		DrawOutlineMenus((ScrWidth / 2) - 400, (ScrHeight / 2) - 300, 800, 600, Selector, "white", 2, Gradient1);
		Vector3 Pos = AimTarget_GetTagPos(&Centity[nearestClient], "j_neck");
		Vector2 Poss;

		if (WorldPosToScreenPos(Pos, &Poss)) {
			int X = Poss.x;
			int Y = Poss.y;

			Color Finder = Selector;

			if (X < (ScrWidth / 2) - 400)
			{
				X = (ScrWidth / 2) - 400; Finder = rTransparent;
			}
			if (Y < (ScrHeight / 2) - 300)
			{
				Y = (ScrHeight / 2) - 300; Finder = rTransparent;
			}
			if (X > ((ScrWidth / 2) - 400 + 800))
			{
				X = (((ScrWidth / 2) - 400) + 800); Finder = rTransparent;
			}
			if (Y > ((ScrHeight / 2) - 300) + 400)
			{
				Y = (((ScrHeight / 2) - 300) + 400); Finder = rTransparent;
			}

			if (autowall::isTargetHitable(getMyRefDef(), GetTagPosFloat(nearestClient, Tag), nearestClient))
			{
				UI_DrawShader(X, (ScrHeight / 2) - 300, 2, 600, Finder, 0, "White");
				UI_DrawShader((ScrWidth / 2) - 400, Y, 800, 2, Finder, 0, "White");

				TargetName = cg->clients[nearestClient].PlayerName;
			}
		}
	}
}

void ArrayConsole()
{
	int Array = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i < 4)
			i = 0;
		Array = i;
		char* Test[4];
		Test[i] = TargetName;
		char* Name[] = { Test[0], Test[1], Test[2], Test[3], Test[4] };

		DrawText(Name[i], (ScrWidth / 2) - 120 + 2 + 5, (ScrHeight / 2) - 61 - 100 + 1.5 + (i * 23), 0, 0.7f, "normalFont", White , align_left);
	}
	
}

void ESPHook() {
	if (DvarGetBool("cl_ingame")) {
			LocalPlayer = cg->clientNum;
			if (cg->health > 0) {
				if (EnemyESP || FriendESP || Radar || bCompass) {
					renderESP(LocalPlayer);
					Dynamic_Radar(LocalPlayer);
					arrowCompass(LocalPlayer);
				}
				HealthBarHook();
				CrossHairs();
				TargetFinder();
			}
			nearestClient = -1;
	}
}