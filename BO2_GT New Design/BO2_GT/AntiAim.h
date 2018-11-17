
char ClampChar_r(const int i)
{
	if (i < -128) {
		return -128;
	}
	if (i > 127) {
		return 127;
	}
	return i;
}

bool isClientAlive(int client) {
	if (!*(bool*)ClientInfo(client, 0x8F))
		if (*(int*)ClientInfo(client, 0x0C) > 0)
			return true;
		else
			return false;
	else
		return false;
}

float DEG2RAD(float DEG)
{
	return ((DEG * M_PI) / 180);
}

void FixMovementBO2(usercmd_s* pCmd, float CurAngle, float OldAngle, float fOldForward, float fOldSidemove)
{
	float deltaView = CurAngle - OldAngle, f1, f2;

	if (OldAngle < 0.f)
		f1 = 360.0f + OldAngle;
	else
		f1 = OldAngle;

	if (CurAngle < 0.0f)
		f2 = 360.0f + CurAngle;
	else
		f2 = CurAngle;

	if (f2 < f1)
		deltaView = abs(f2 - f1);
	else
		deltaView = 360.0f - abs(f1 - f2);
	deltaView = 360.0f - deltaView;

	pCmd->fDir = ClampChar_r((int)(cosf(DEG2RAD(deltaView))*  fOldForward + cosf(DEG2RAD(deltaView + 90.f))*  fOldSidemove));
	pCmd->rDir = ClampChar_r((int)(sinf(DEG2RAD(deltaView))*  fOldForward + sinf(DEG2RAD(deltaView + 90.f))*  fOldSidemove));
}

void doNoSway()
{
	WeaponDef * weapondef = BG_GetWeaponDef(cg->playerstate.weapon);
	if (noSway) {
		weapondef->adsGunKickReducedKickPercent = 0.0f;
		weapondef->adsIdleSpeed = 0.0f;
		weapondef->adsMoveSpeedScale = 0.0f;
		weapondef->adsSwayLerpSpeed = 0.0f;
		weapondef->adsSwayMaxAngle = 0.0f;
		weapondef->adsSwayPitchScale = 0.0f;
		weapondef->adsSwayYawScale = 0.0f;
		weapondef->cameraShakeScale = 0.0f;
		weapondef->fAdsBobFactor = 0.0f;
		weapondef->fAdsViewBobMult = 0.0f;
		weapondef->fAdsIdleAmount = 0.0f;
		weapondef->fHipIdleAmount = 0.0f;
		weapondef->adsIdleSpeed = 0.0f;
		weapondef->hipIdleSpeed = 0.0f;
		weapondef->fIdleCrouchFactor = 0.0f;
		weapondef->fIdleProneFactor = 0.0f;
		weapondef->fGunMaxPitch = 0.0f;
		weapondef->fGunMaxYaw = 0.0f;
		weapondef->swayMaxAngle = 0.0f;
		weapondef->swayLerpSpeed = 0.0f;
		weapondef->swayPitchScale = 0.0f;
		weapondef->swayYawScale = 0.0f;
		weapondef->swayHorizScale = 0.0f;
		weapondef->swayVertScale = 0.0f;
		weapondef->swayShellShockScale = 0.0f;
		weapondef->adsSwayMaxAngle = 0.0f;
		weapondef->adsSwayLerpSpeed = 0.0f;
		weapondef->adsSwayPitchScale = 0.0f;
		weapondef->adsSwayYawScale = 0.0f;
		weapondef->adsGunKickReducedKickBullets = 0;
		weapondef->adsGunKickReducedKickPercent = 0.0f;
		weapondef->fAdsGunKickPitchMin = 0.0f;
		weapondef->fAdsGunKickPitchMax = 0.0f;
		weapondef->fAdsGunKickYawMin = 0.0f;
		weapondef->fAdsGunKickYawMax = 0.0f;
		weapondef->fAdsGunKickAccel = 0.0f;
		weapondef->fAdsGunKickSpeedMax = 0.0f;
		weapondef->fAdsGunKickSpeedDecay = 0.0f;
		weapondef->fAdsGunKickStaticDecay = 0.0f;
		weapondef->fAdsViewKickPitchMin = 0.0f;
		weapondef->fAdsViewKickPitchMax = 0.0f;
		weapondef->fAdsViewKickMinMagnitude = 0.0f;
		weapondef->fAdsViewKickYawMin = 0.0f;
		weapondef->fAdsViewKickYawMax = 0.0f;
		weapondef->fAdsRecoilReductionRate = 0.0f;
		weapondef->fAdsRecoilReductionLimit = 0.0f;
		weapondef->fAdsRecoilReturnRate = 0.0f;
		weapondef->fAdsViewScatterMin = 0.0f;
		weapondef->fAdsViewScatterMax = 0.0f;
		weapondef->hipGunKickReducedKickBullets = 0;
		weapondef->hipGunKickReducedKickPercent = 0.0f;
		weapondef->fHipGunKickPitchMin = 0.0f;
		weapondef->fHipGunKickPitchMax = 0.0f;
		weapondef->fHipGunKickYawMin = 0.0f;
		weapondef->fHipGunKickYawMax = 0.0f;
		weapondef->fHipGunKickAccel = 0.0f;
		weapondef->fHipGunKickSpeedMax = 0.0f;
		weapondef->fHipGunKickSpeedDecay = 0.0f;
		weapondef->fHipGunKickStaticDecay = 0.0f;
		weapondef->fHipViewKickPitchMin = 0.0f;
		weapondef->fHipViewKickPitchMax = 0.0f;
		weapondef->fHipViewKickMinMagnitude = 0.0f;
		weapondef->fHipViewKickYawMin = 0.0f;
		weapondef->fHipViewKickYawMax = 0.0f;
		weapondef->fHipViewScatterMin = 0.0f;
		weapondef->fHipViewScatterMax = 0.0f;
		weapondef->fAdsViewKickCenterDuckedScale = 0.0f;
		weapondef->fAdsViewKickCenterProneScale = 0.0f;
		weapondef->fAntiQuickScopeTime = 0.0f;
		weapondef->fAntiQuickScopeScale = 0.0f;
		weapondef->fAntiQuickScopeSpreadMultiplier = 0.0f;
		weapondef->fAntiQuickScopeSpreadMax = 0.0f;
		weapondef->fAntiQuickScopeSwayFactor = 0.0f;
		weapondef->explosionCameraShakeScale = 0.0f;
	}
	else
	{
		weapondef->adsIdleSpeed = 2.0f;
		weapondef->hipIdleSpeed = 4.0f;
	}

	/*weapondef->swayHorizScale = 0;
	weapondef->swayLerpSpeed = 0;
	weapondef->swayMaxAngle = 0;
	weapondef->swayPitchScale = 0;
	weapondef->swayShellShockScale = 0;
	weapondef->swayVertScale = 0;
	weapondef->swayYawScale = 0;
	weapondef->fAdsBobFactor = 0;
	weapondef->fAdsGunKickAccel = 0;
	weapondef->fAdsGunKickPitchMax = 0;
	weapondef->fAdsGunKickPitchMin = 0;
	weapondef->fAdsGunKickSpeedDecay = 0;
	weapondef->fAdsGunKickSpeedMax = 0;
	weapondef->fAdsGunKickStaticDecay = 0;
	weapondef->fAdsGunKickYawMax = 0;
	weapondef->vertViewJitter = 0;
	weapondef->explosionCameraShakeDuration = 0;
	weapondef->explosionCameraSHakeRadius = 0;
	weapondef->explosionCameraShakeScale = 0;
	weapondef->fAdsViewBobMult = 0;*/

}



float BG_GetDamageRangeScale(int weapon)
{
	return Invoke<float>(0x60A890, weapon);
}


void _DoNoSpread(usercmd_s* cmd)
{

	Vector3 viewAngles, viewAxis[3], spreadDirection;
	WeaponDef * weapondef = BG_GetWeaponDef(cg->playerstate.weapon);
	int playerState = 0x03780EA28;
	if (!weapondef)
		return;

	float minSpread, maxSpread, spread, spreadEndVec[3];
	int WeaponNum = cg->playerstate.weapon, unkSpread = 0;
	Invoke<void>(0x5F09C8, playerState, WeaponNum, &minSpread, &maxSpread);
	spread = cg->spreadMultiplier * 0.0039215689f;

	if (*(float *)(playerState + 0x1E0) == 1.0f) //If player is aiming
		return;

	if (!(weapondef->weaponClass == WEAPCLASS_MG || weapondef->weaponClass == WEAPCLASS_PISTOL || weapondef->weaponClass == WEAPCLASS_SMG || weapondef->weaponClass == WEAPCLASS_RIFLE)) //If gun isn't gun
		return;

	minSpread = *(float *)(weapondef + 0x7E0);
	spread = minSpread + ((maxSpread - minSpread) * spread);
	float frange = (weapondef->weaponClass == WEAPCLASS_SPREAD) ? BG_GetDamageRangeScale(WeaponNum) * weapondef->damageRange[0] : 8192.0f;
	anglevectors(anglesOut, &viewAxis[0], &viewAxis[1], &viewAxis[2]);
	int seed = cg->playerstate.time;
	Invoke<void>(0x05D6C54, &seed);
	if (*(int *)(weapondef + 0x20) != 0x3 && *(int *)(weapondef + 0x20) != 0xD)
		unkSpread = 1;
	else
		unkSpread = *(int *)(weapondef + 0x3D0);

	Invoke<void>(0xEBB48, &seed, spread, &anglesOut, &spreadEndVec, &spreadDirection, &viewAxis[0], &viewAxis[1], &viewAxis[2], frange, WeaponNum, 0, unkSpread);
	VectoAngles(&spreadDirection, &viewAngles);
	cmd->viewAngles[0] += ANGLE2SHORT(anglesOut.x - viewAngles.x);
	cmd->viewAngles[1] += ANGLE2SHORT(anglesOut.y - viewAngles.y);
}

void calculateNoSpread(usercmd_s* Command) {
	float spread, minSpread, maxSpread;
	Vector3 viewAngles, spreadEnd, viewAxis[3];
	Vector3 spreadDirection;

	int WeaponID = *(int*)(oCentity(cg->clientNum) + 0x2B4);

	float aimRatio = *(float*)0x03780EC08;
	float spreadRange = 8192.0f;

	if (aimRatio > 0.1f)
		return;

	spread = cg->spreadMultiplier * 0.0039215689;
	Invoke<void>(0x5F09C8, 0x03780EA28, WeaponID, &minSpread, &maxSpread);

	float finalSpread = minSpread + ((maxSpread - minSpread) * spread);
	int pHoldRand = *(int*)(0x03780EA28);
	int seed = cg->playerstate.time;

	viewAngles.x = *(float *)(0x03780EA28 + 0x1F8);
	viewAngles.y = *(float *)(0x03780EA28 + 0x1FC);
	viewAngles.z = 0;

	VectoAngles(&viewAngles, viewAxis);
	Invoke<void>(0xEBB48, &pHoldRand, finalSpread, &cg->refdef.ViewOrigin, &spreadEnd, &spreadDirection, &viewAxis[0], &viewAxis[1], &viewAxis[2], spreadRange);

	Vector3 tmp = Difference(spreadEnd, cg->refdef.ViewOrigin);
	VectoAngles(&tmp, &viewAngles);

	Command->viewAngles[0] += ANGLE2SHORT(*(float *)(0x03780EA28 + 0x1F8) - viewAngles.x);
	Command->viewAngles[1] += ANGLE2SHORT(*(float *)(0x03780EA28 + 0x1FC) - viewAngles.y);
}

int Lag;
int ProxyFuncs(int r3)
{
	if (InGame && isClientAlive(cg->clientNum))
	{
		if (ClientActive_s != NULL)
		{
			WeaponDef * weapondef = BG_GetWeaponDef(cg->playerstate.weapon);
			if (noSway)
				doNoSway();
			if (weapondef->weaponClass == WEAPCLASS_MG || weapondef->weaponClass == WEAPCLASS_PISTOL || weapondef->weaponClass == WEAPCLASS_SMG || weapondef->weaponClass == WEAPCLASS_RIFLE)
			{
				usercmd_s* oldcmd = &ClientActive_s->UserCmd[(ClientActive_s->CurrentCmdNumber - 1) & 0x7F];
				usercmd_s* cmd = &ClientActive_s->UserCmd[ClientActive_s->CurrentCmdNumber & 0x7F];

				if (AimbotEnabled)
				{
					if (noSway)
					{
						if (!weapondef)
							return;

						weapondef->swayMaxAngle = 0.0f;
						weapondef->swayLerpSpeed = 0.0f;
						weapondef->swayPitchScale = 0.0f;
						weapondef->swayYawScale = 0.0f;
						weapondef->swayHorizScale = 0.0f;
						weapondef->swayVertScale = 0.0f;
						weapondef->swayShellShockScale = 0.0f;
						weapondef->adsSwayMaxAngle = 0.0f;
						weapondef->adsSwayLerpSpeed = 0.0f;
						weapondef->adsSwayPitchScale = 0.0f;
						weapondef->adsSwayYawScale = 0.0f;
						weapondef->adsGunKickReducedKickBullets = 0;
						weapondef->adsGunKickReducedKickPercent = 0.0f;
						weapondef->fAntiQuickScopeSwayFactor = 0.0f;
						weapondef->explosionCameraShakeScale = 0.0f;
					}
					float oldAngleY = SHORT2ANGLE(oldcmd->viewAngles[1]);
					if (sAimbot && shootNow)
					{
						oldcmd->viewAngles[0] = ANGLE2SHORT(AimAngles.x);
						oldcmd->viewAngles[1] = ANGLE2SHORT(AimAngles.y);
					}
					FixMovementBO2(oldcmd, SHORT2ANGLE(oldcmd->viewAngles[1]), oldAngleY, (float)oldcmd->fDir, (float)oldcmd->rDir);
					if (shootNow)
					{
						if (noSpread)
						{
							_DoNoSpread(oldcmd);
							if (Key_IsDown(R1))
								oldcmd->buttons &= ~(1 << 31);
						}

						if (autoShoot)
						{
							oldcmd->buttons &= ~(1 << 31);
							cmd->buttons |= (1 << 31);
						}
					}
					shootNow = false;
				}
			}
		}
		if (AntiAimEnabled && FakeLag)
		{
			if (InGame) {
				Lag++;
			}
		}
	}
	if (FakeLag)
	{
		if (InGame) {
			if ((Lag > LagAmount) || (shootNow && autoShoot) || Key_IsDown(R1))
			{
				sProxyFuncs(r3);
				Lag = 0;
			}
		}
	}
	else
	{
		sProxyFuncs(r3);
	}
}
int CL_SendCmd(int r3)
{
	if (InGame && isClientAlive(cg->clientNum))
	{
		usercmd_s* newcmd = &ClientActive_s->UserCmd[(ClientActive_s->CurrentCmdNumber + 1) & 0x7F];
		usercmd_s* currcmd = &ClientActive_s->UserCmd[ClientActive_s->CurrentCmdNumber & 0x7F];
		*newcmd = *currcmd;

		++ClientActive_s->CurrentCmdNumber;
		currcmd->time--;

		if (AntiAimEnabled && !isHostMigrating())
		{
			if (xAntiAimType == 1) //Emotion - Works
			{
				//if (jitAnglex > 180)
				//	jitAnglex = -180;

				//cmd->viewAngles.x = ANGLE2SHORT(jitAnglex);

				//jitAnglex += 90;
				//cmd->viewAngles.x = ANGLE2SHORT(oldAngleX);

				newcmd->viewAngles[0] = ANGLE2SHORT((!(newcmd->time % 3) ? 69.99999f : -69.99999f) - ClientActive_s->baseAngle.x);
			}
			else if (xAntiAimType == 2) //Up - Works
			{
				newcmd->viewAngles[0] = ANGLE2SHORT(69.99999f - ClientActive_s->baseAngle.x);
			}
			else if (xAntiAimType == 3) //Down - Works
			{
				newcmd->viewAngles[0] = ANGLE2SHORT(-69.99999f - ClientActive_s->baseAngle.x);
			}
			else if (xAntiAimType == 4 && (shootNow || Key_IsDown(R1))) //Inv on Shot - Works
			{
				newcmd->viewAngles[0] = ANGLE2SHORT((!(newcmd->time % 3) ? 69.99999f : -69.99999f) - ClientActive_s->baseAngle.x);
			}
			else if (xAntiAimType == 5) //Aim->Enemy - Works
			{
				newcmd->viewAngles[0] = ANGLE2SHORT(AimAngles.x);
			}

			//Left Right
			if (yAntiAimType == 1) //Jitter - Works
			{
				newcmd->viewAngles[1] -= ANGLE2SHORT(!(newcmd->time % 2) ? 180.0f : 0.0f);
			}
			else if (yAntiAimType == 2) //Spin Bot - Works
			{
				if (spinAngle < -360)
					spinAngle = 0;

				if (ReverseDir)
					spinAngle += spinSpeed;
				else
					spinAngle -= spinSpeed;

				newcmd->viewAngles[1] = ANGLE2SHORT(spinAngle);
			}
			else if (yAntiAimType == 3) //Shield - Works
			{
				newcmd->viewAngles[1] -= ANGLE2SHORT(180.0f);
			}
			else if (yAntiAimType == 4 && (shootNow || Key_IsDown(R1))) //Inv on Shot - Works
			{
				newcmd->viewAngles[1] = ANGLE2SHORT((!(newcmd->time % 3) ? 180.0f : -0.0f) - ClientActive_s->baseAngle.y);
			}
			else if (yAntiAimType == 5) //Body->Enemy - Limited
			{
				newcmd->viewAngles[1] = ANGLE2SHORT(AimAngles.y);
			}
			else if (yAntiAimType == 6) //Shield->Enemy - Limited
			{
				newcmd->viewAngles[1] = ANGLE2SHORT(AimAngles.y - 180.0f);
			}
			else if (yAntiAimType == 7) //Shield->Enemy - Limited
			{
				if (AimAngles.y == ClientActive_s->baseAngle.y)
					newcmd->viewAngles[1] -= ANGLE2SHORT(180.0f);
				else
					newcmd->viewAngles[1] = ANGLE2SHORT(AimAngles.y - 180.0f);
			}


			

		}
	}
	sCL_SendCmd(r3);
}