

namespace autowall {


	enum TraceHitType
	{
		TRACE_HITTYPE_NONE = 0,
		TRACE_HITTYPE_ENTITY = 1,
		TRACE_HITTYPE_DYNENT_MODEL = 2,
		TRACE_HITTYPE_DYNENT_BRUSH = 3,
		TRACE_HITTYPE_DYNENT_UNKNOWN = 4
	};

#pragma pack(push, 1)

	typedef float vec_t;
	typedef vec_t vec2_t[2];
	typedef vec_t Vector3[3];
	typedef vec_t vec4_t[4];
	typedef vec_t vec5_t[5];
	typedef int DWORD;
	typedef short WORD;
	typedef char BYTE;
	typedef vec_t *pVector3;

	struct trace_t
	{
		Vector3 normal;
		char unk1[0x04];
		float fraction;
		char unk2[0x08];
		TraceHitType hitType;
		short hitId;
		short modelIndex;
		short partName;
		short partGroup;
		char unk4[0x10];
	}; // 0x38

#pragma pack(pop)

	struct BulletFireParams
	{
		int weaponEntIndex;
		int ignoreEntIndex;
		float damageMultiplier;
		int methodOfDeath;
		Vector3 origStart;
		Vector3 start;
		Vector3 end;
		Vector3 dir;
	}; // 0x40

	struct BulletTraceResults
	{
		trace_t trace;
		int* hitEnt; // gentity_s*
		Vector3 hitPos;
		int ignoreHitEnt;
		int hitSurfaceType;
	}; // 0x50
	
	float Get3DDistance(vec_t *v1, vec_t *v2) {
		float a = v1[0] - v2[0];
		float b = v1[1] - v2[1];
		float c = v1[2] - v2[2];
		return sqrt(a*a + b * b + c * c);
	}
	void VectorNormalize(vec_t *v) {
		float length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
		if (length != 0) {
			v[0] = v[0] / length;
			v[1] = v[1] / length;
			v[2] = v[2] / length;
		}
	}
#define DotProduct(a,b)			((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])
#define VectorSubtract(a,b,c)	((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)		((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])



#define	VectorScale(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define	VectorMA(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define CrossProduct(a,b,c)		((c)[0]=(a)[1]*(b)[2]-(a)[2]*(b)[1],(c)[1]=(a)[2]*(b)[0]-(a)[0]*(b)[2],(c)[2]=(a)[0]*(b)[1]-(a)[1]*(b)[0])

	float min(float x, float y) {
		return x > y ? y : x;
	}
	int Trace_GetEntityHitID(unsigned int trace) {
		int r4 = *(int*)(trace + 0x1C);
		bool cr0 = r4 == 2;
		int cr1 = r4 == 1;
		int cr6 = r4 == 4;
		int cr7 = r4 == 3;
		if (cr0 == true) {
			return 0x3FE;
		}
		if (cr7 == false) {
			if (cr6 == false) {
				if (cr1 == false) {
					return 0x3FF;
				}
				else {
					return *(short*)(trace + 0x20);
				}
			}
			else {
				return 0x3FE;
			}
		}
		else {
			return 0x3FE;
		}
	}

	int Trace_GetEntityHitIDs(trace_t *trace)
	{
		return Invoke<int>(0x306CC0, trace);
	}

	struct weaponWeirdData {
		int unknwn1;
		int unknown2;
		int weaponDefPtr;
	};
	weaponWeirdData wtfisthislolweaponshit;

	int GetWeaponDef(int weapon)
	{
		Invoke<int>(0x00606F08, weapon);
	}

	bool BulletTraceO(int localClientNum, BulletFireParams *bp, unsigned int weapDef, unsigned int centityattacker, BulletTraceResults *br, unsigned int lastSurfaceType, bool simulated)
	{
		Invoke<bool>(0xE9FBC, localClientNum, bp, weapDef, centityattacker, br, lastSurfaceType, simulated);
	}

	bool BulletTrace(BulletFireParams* bulletFireParams, BulletTraceResults* bulletTraceResults, unsigned int localClientNum, unsigned int centity, unsigned int surfaceType)
	{
		int wepid = *(int*)(oCentity(cg->clientNum) + 0x2B4);
		int weaponDefPtr = GetWeaponDef(wepid);
		return BulletTraceO(localClientNum, bulletFireParams, weaponDefPtr, centity, bulletTraceResults, surfaceType, false);
	}

	float BG_GetSurfacePenetrationDepth(unsigned int weaponDefPtr, unsigned int surfaceType)
	{
		Invoke<float>(0x005EFFC0, weaponDefPtr, surfaceType);
	}

	double __cdecl BG_GetSurfacePenetrationDepthRebuilt(PenetrateType pt, int surfaceType)
	{
		double results;
		if ((unsigned int)surfaceType >= 0x20)
		{
			return;
		}
		return Invoke<float>(0x5EFFC0, pt, surfaceType);
	}

	bool BG_AdvanceTrace(BulletFireParams* bulletFireParams, BulletTraceResults* bulletTraceResults, float amount)
	{
		Invoke<bool>(0x005EFE18, bulletFireParams, bulletTraceResults, amount);
	}

	bool CG_SimulateBulletFire_Internal(int localClientNum, BulletFireParams* bulletFireParams, int weaponIndex, Centity_t* centityAttacker, unsigned int pointerToViewPoint, bool unknwon, bool unknwon2, BulletTraceResults* btr, PenetrateType a9)
	{
		Invoke<bool>(0x000EAC28, localClientNum, bulletFireParams, weaponIndex, centityAttacker, pointerToViewPoint, unknwon, unknwon, &btr, a9);
	}

	bool FireBulletPenetrate(int localClientNum, BulletFireParams* bulletFireParams, int weaponIndex, Centity_t* centityAttacker, unsigned int pointerToViewPoint, bool unknwon, bool unknwon2, BulletTraceResults btr)
	{
		Invoke<bool>(0x000EAC28, localClientNum, bulletFireParams, weaponIndex, centityAttacker, pointerToViewPoint, unknwon, unknwon, &btr);
	}

	char blr[4] = { 0x4E, 0x80, 0x00, 0x20 };
	char nop[4] = { 0x60, 0x00, 0x00, 0x00 };
	char patch0[4] = { 0xF8, 0x21, 0xFE, 0xC1 };
	char patch1[4] = { 0xF8, 0x21, 0xFE, 0xE1 };

	typedef bool(*BulletTrace1)(int localClient, void *bp, Centity_t* centity_s_ptr, void *results, int surfaceType);
	BulletTrace1 bulletTrace = (BulletTrace1)0xE9FBC;

	bool performBulletTrace(int myClientNum, int clients, void *bulletFireParams, void *bulletTraceResults, int surfaceType)
	{
		return bulletTrace(0, bulletFireParams, &Centity[clients], bulletTraceResults, surfaceType);
	}

	bool isTargetHitable(Vector3 start, Vector3 end, int targetClientNum) {
		WeaponDef * weapondef = BG_GetWeaponDef(cg->playerstate.weapon);
		BulletTraceResults bulletTraceResults;
		BulletFireParams bulletFireParams;

		if (!weapondef)
			return false;

		PenetrateType penType = PENETRATE_TYPE_LARGE;
		bulletFireParams.weaponEntIndex = cg->playerstate.weapon;
		bulletFireParams.ignoreEntIndex = cg->clientNum;
		bulletFireParams.damageMultiplier = 1.0f;
		bulletFireParams.methodOfDeath = weapondef->weaponType;
		VectorCopy(start, bulletFireParams.origStart);
		VectorCopy(start, bulletFireParams.start);
		VectorCopy(end, bulletFireParams.end);

		Vector3 dir;
		VectorSubtract(end, start, dir);
		VectorNormalize(dir);
		VectorCopy(dir, bulletFireParams.dir);
		write_process1((void*)0x000E9BE8, blr, 4);//CG_BulletHitEvent
		write_process1((void*)0x0045C038, blr, 4);//Tracer_Spawn
		CG_SimulateBulletFire_Internal(0, &bulletFireParams, cg->playerstate.weapon, &Centity[cg->clientNum], *(unsigned int*)&cg->refdef.ViewOrigin, 0, 0, &bulletTraceResults, penType);
		write_process1((void*)0x000E9BE8, patch0, 4);//CG_BulletHitEvent
		write_process1((void*)0x0045C038, patch1, 4);//Tracer_Spawn

		unsigned int traceResultTrace = (unsigned int)&bulletTraceResults;
		return (bulletFireParams.ignoreEntIndex == targetClientNum);
		if (bulletFireParams.ignoreEntIndex == targetClientNum)
			return true;
		return false;

	//	memset(&bulletFireParams, 0x00, sizeof(BulletFireParams));
	//	bulletFireParams.weaponEntIndex = 1022;
	//	bulletFireParams.ignoreEntIndex = cg->clientNum;
	//	bulletFireParams.damageMultiplier = 1.0f;
	//	bulletFireParams.methodOfDeath = weapondef->weaponType;
	//	VectorCopy(start, bulletFireParams.origStart);
	//	VectorCopy(start, bulletFireParams.start);
	//	VectorCopy(end, bulletFireParams.end);

	//	Vector3 dir;
	//	VectorSubtract(end, start, dir);
	//	VectorNormalize(dir);
	//	VectorCopy(dir, bulletFireParams.dir);

	//	bool hit = BulletTrace(&bulletFireParams, &bulletTraceResults, 0, cg->clientNum, bulletTraceResults.hitSurfaceType);

	//	if (!hit)
	//		return bulletFireParams.damageMultiplier;
	//	if (Trace_GetEntityHitIDs(&bulletTraceResults.trace) != 1022)
	//		return 0.0f;
	//	if (*(WORD*)((DWORD)&bulletTraceResults.trace + 40) == 2)
	//		return 0.0f;
	//	if (weapondef->penetrateType == PENETRATE_TYPE_NONE)
	//		return 0.0f;
	//	int penetrationCount = 0;
	//	float perk_bulletPenetrationMultiplier = 1.0f;
	//	float penetrationDepth;
	//	BulletFireParams bulletFireParams_2;
	//	BulletTraceResults bulletTraceResults_2;
	//	Vector3 hitPosBackup;
	//	bool hit_2;
	//	bool v26;
	//	while (true)
	//	{
	//		penetrationDepth = BG_GetSurfacePenetrationDepth(weapondef->penetrateType, bulletTraceResults.hitSurfaceType);

	//		if (penetrationDepth <= 0.0f)
	//			return 0.0f;

	//		VectorCopy(bulletTraceResults.hitPos, hitPosBackup);
	//		if (!BG_AdvanceTrace(&bulletFireParams, &bulletTraceResults, 0.13500000536441803f))
	//			return 0.0f;

	//		hit = BulletTrace(&bulletFireParams, &bulletTraceResults, 0, cg->clientNum, bulletTraceResults.hitSurfaceType);
	//		memcpy(&bulletFireParams_2, &bulletFireParams, sizeof(BulletFireParams));

	//		VectorScale(bulletFireParams.dir, -1.0f, bulletFireParams_2.dir);
	//		VectorCopy(bulletFireParams.end, bulletFireParams_2.start);
	//		VectorMA(hitPosBackup, 0.009999999776482582f, bulletFireParams_2.dir, bulletFireParams_2.end);

	//		memcpy(&bulletTraceResults_2, &bulletTraceResults, sizeof(BulletTraceResults));

	//		VectorScale(bulletTraceResults_2.trace.normal, -1.0f, bulletTraceResults_2.trace.normal);

	//		if (hit)
	//			BG_AdvanceTrace(&bulletFireParams_2, &bulletTraceResults_2, 0.009999999776482582f);

	//		hit_2 = BulletTrace(&bulletFireParams_2, &bulletTraceResults_2, 0, cg->clientNum, bulletTraceResults_2.hitSurfaceType);

	//		v26 = (hit_2 != 0) && *(BYTE*)((DWORD)&bulletTraceResults_2.trace + 42) || *(BYTE*)((DWORD)&bulletTraceResults.trace + 43) && *(BYTE*)((DWORD)&bulletTraceResults_2.trace + 43);

	//		if (hit_2 || v26)
	//			break;
	//		if (!hit)
	//		{
	//			return bulletFireParams.damageMultiplier;
	//		}
	//		goto continueLoop;
	//	continueLoop:
	//		if (hit)
	//		{
	//			penetrationCount++;
	//			if (penetrationCount < 5) // max number of surfaces penetrated is 5 (from penetrationCount dvar)
	//				continue;
	//		}

	//		return 0.0f;
	//	}
	//	float surfaceDepth = 0.0f;
	//	if (v26)
	//		surfaceDepth = Get3DDistance(bulletFireParams_2.start, bulletFireParams_2.end);
	//	else
	//		surfaceDepth = Get3DDistance(bulletTraceResults_2.hitPos, hitPosBackup);

	//	// minimum surface depth is 1.0f
	//	if (surfaceDepth < 1.0f)
	//		surfaceDepth = 1.0f;

	//	if (hit_2)
	//	{
	//		float penetrationDepth_2 = BG_GetSurfacePenetrationDepthRebuilt(PENETRATE_TYPE_LARGE, bulletTraceResults_2.hitSurfaceType);
	//		penetrationDepth = min(penetrationDepth, penetrationDepth_2);

	//		// we return if our penetration depth is zero or negative
	//		if (penetrationDepth <= 0.0f)
	//			return 0.0f;
	//	}
	//	bulletFireParams.damageMultiplier -= surfaceDepth / penetrationDepth;
	//	goto LABEL_84;

	//LABEL_84:
	//	if (bulletFireParams.damageMultiplier <= 0.0f)
	//		return 0.0f;

	//	goto continueLoop;
	//	// impossibru, this return can't be executed (who cares)
	//	return 0.0f;


		//if (!weapondef)
		//	return false;

		//PenetrateType penType = PENETRATE_TYPE_LARGE;
		//bulletFireParams.weaponEntIndex = cg->playerstate.weapon;
		//bulletFireParams.ignoreEntIndex = cg->clientNum;
		//bulletFireParams.damageMultiplier = 1.0f;
		//bulletFireParams.methodOfDeath = weapondef->weaponType;
		//VectorCopy(start, bulletFireParams.origStart);
		//VectorCopy(start, bulletFireParams.start);
		//VectorCopy(end, bulletFireParams.end);

		//Vector3 dir;
		//VectorSubtract(end, start, dir);
		//VectorNormalize(dir);
		//VectorCopy(dir, bulletFireParams.dir);
		//write_process1((void*)0x000E9BE8, blr, 4);//CG_BulletHitEvent
		//write_process1((void*)0x0045C038, blr, 4);//Tracer_Spawn
		//CG_SimulateBulletFire_Internal(0, &bulletFireParams, cg->playerstate.weapon, &Centity[cg->clientNum], *(unsigned int*)&cg->refdef.ViewOrigin, 0, 0, &bulletTraceResults, penType);
		////FireBulletPenetrate(0, &bulletFireParams, cg->playerstate.weapon, &Centity[cg->clientNum], (unsigned int)&(cg->refdef.ViewOrigin), 1, 1, bulletTraceResults);
		//write_process1((void*)0x000E9BE8, patch0, 4);//CG_BulletHitEvent
		//write_process1((void*)0x0045C038, patch1, 4);//Tracer_Spawn


		//unsigned int traceResultTrace = (unsigned int)&bulletTraceResults;
		//return (bulletFireParams.ignoreEntIndex == targetClientNum);
		//if (bulletFireParams.ignoreEntIndex == targetClientNum)
		//	return true;
		//return false;



			//BG_GetSurfacePenetrationDepthRebuilt(PENETRATE_TYPE_LARGE, bulletTraceResults.hitSurfaceType);
			/*	
			unsigned int traceResultTrace = (unsigned int)&bulletTraceResults;
			return (bulletFireParams.ignoreEntIndex == targetClientNum);
			if (bulletFireParams.ignoreEntIndex == targetClientNum)
		    return true;
			else
			return false;*/

			/*unsigned int traceResultTrace = (unsigned int)&bulletTraceResults;

			bool hit = performBulletTrace(cg->clientNum, cg->clientNum, &bulletFireParams, &bulletTraceResults, 0);

			if (!hit)
				return bulletFireParams.damageMultiplier;
			if (*(int*)((int)&bulletTraceResults.trace + 40) == 2)
				return 0.0f;
			if (!*(int*)(weapondef + 36) || *(char*)((int)&bulletTraceResults.trace + 43))
				return 0.0f;


			int penetrationCount = 0;
			float perk_bulletPenetrationMultiplier = 2.0f;
			float penetrationDepth;
			BulletFireParams bulletFireParams_2;
			BulletTraceResults bulletTraceResults_2;
			Vector3 hitPosBackup;
			bool hit_2;
			bool v26;

			while (true)
			{
				penetrationDepth = BG_GetSurfacePenetrationDepth(1, bulletTraceResults.hitSurfaceType);

				if (penetrationDepth <= 0.0f)
					return 0.0f;
				memcpy(hitPosBackup, bulletTraceResults.hitPos, 0xC);
				if (!BG_AdvanceTrace(&bulletFireParams, &bulletTraceResults, 0.13500000536441803f))
					return 0.0f;

				hit = performBulletTrace(cg->clientNum, cg->clientNum, &bulletFireParams, &bulletTraceResults, bulletTraceResults.hitSurfaceType);

					memcpy(&bulletFireParams_2, &bulletFireParams, sizeof(BulletFireParams));
					VectorScale(bulletFireParams.dir, -1.0f, bulletFireParams_2.dir);
					memcpy(bulletFireParams_2.start, bulletFireParams.end, 0xC);
					VectorMA(hitPosBackup, 0.009999999776482582f, bulletFireParams_2.dir, bulletFireParams_2.end);

					memcpy(&bulletTraceResults_2, &bulletTraceResults, sizeof(BulletTraceResults));
					VectorScale(&bulletTraceResults_2.trace.normal, -1.0f, &bulletTraceResults_2.trace.normal);

					if(hit)
						BG_AdvanceTrace(&bulletFireParams_2, &bulletTraceResults_2, 0.009999999776482582f);



					hit_2 = performBulletTrace(cg->clientNum, cg->clientNum, &bulletFireParams_2, &bulletTraceResults_2, bulletTraceResults_2.hitSurfaceType);
					v26 = (hit_2 != 0) && *(char*)((int)&bulletTraceResults_2.trace + 42) || *(char*)((int)&bulletTraceResults.trace + 43) && *(char*)((int)&bulletTraceResults_2.trace + 43);
					if (hit_2 || v26)
						break;
					if (!hit)
						return bulletFireParams.damageMultiplier;
					goto continueLoop;
				continueLoop:
					if (hit)
					{
						penetrationCount++;
						if (penetrationCount < 5)
							continue;
					}
					return 0.0f;
			}

			float surfaceDepth = 0.0f;
			if (v26)
				surfaceDepth = Get3DDistance(bulletFireParams_2.start, bulletFireParams_2.end);
			else
				surfaceDepth = Get3DDistance(bulletTraceResults_2.hitPos, hitPosBackup);

			if (surfaceDepth < 1.0f)
				surfaceDepth = 1.0f;
			if (hit_2)
			{
				float penetrationDepth_2 = BG_GetSurfacePenetrationDepth(1,bulletTraceResults_2.hitSurfaceType);
				penetrationDepth = min(penetrationDepth, penetrationDepth_2);
				if (penetrationDepth <= 0.0f)
					return 0.0f;
			}
			if (1 == 0)
			{
				if (1 == 0)
				{
				LABEL_84:
					if (bulletFireParams.damageMultiplier <= 0.0f)
						return 0.0f;
					goto continueLoop;
				}
			}

			bulletFireParams.damageMultiplier -= surfaceDepth / penetrationDepth;
			goto LABEL_84;
			return 0.0f*/

	}
	
}
