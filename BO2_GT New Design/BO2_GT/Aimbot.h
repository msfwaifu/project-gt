
bool isHostMigrating()
{
	if (!(ClientUIActive_s->migrationState == CMSTATE_INACTIVE))
		return false;
	else
		return true;
}

#define SHORT2ANGLE(x)  ((x)*(360.0/65536))
#define ANGLE2SHORT(x)   ((int)((x)*65536/360) & 65535)

bool isAnyVis(int mClient)
{
	int isVis = 0;
	for (int i = 0; i < 12; ++i)
	{
		if (i != mClient)
		{
			if (!isPlayerFriendly(&pCentity_s[i]))
			{
				if (*(int*)ClientInfo(i, 0x0C) > 0)
				{
					if (!isPlayerFriendly(&pCentity_s[i]))
					{
						if (isPlayerVisible(&pCentity_s[i]))
						{
							isVis++;
						}
					}
				}
			}
		}
	}
	if (isVis > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void VectoAngles(Vector3 * vec, Vector3 * angles)
{
	Invoke<void>(0x3CAB90, vec, angles);
}

float *getMyRefDef() {
	return (float*)&(cg->refdef.ViewOrigin);
}

int SL_GetString(const char* str, unsigned int user)
{
	Invoke<int>(0x48ED68, str, user);
}

bool ogAimTarget_GetTagPos(int targ_centity, unsigned tagIndex, float *pos)
{
	Invoke<bool>(0x015708, targ_centity, tagIndex, pos);
}

float outTMPTAGPOS[3];
float *GetTagPosFloat(int targEnt, const char *tagName)
{
	ogAimTarget_GetTagPos(oCentity(targEnt), SL_GetString(tagName, 0), outTMPTAGPOS);
	return outTMPTAGPOS;
}

Vector3 AimAngles;
Vector3 anglesOut;

char* CycleTags()
{
	for (int i = 0; i < 20; i++)
	{
		return tagList[i];
	}
}

int currTag;
char* WASSS;
char* VisibleBone()
{
	if (AutoBone)
	{
		for (int i = 0; i < 17; i++)
		{

			return tagList[i];
		}
	}
	else
	{
		return tagList[0];
	}
	//return _Tag;
}

enum TraceHitType
{
	TRACE_HITTYPE_NONE = 0x0,
	TRACE_HITTYPE_ENTITY = 0x1,
	TRACE_HITTYPE_DYNENT_MODEL = 0x2,
	TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
	TRACE_HITTYPE_GLASS = 0x4,
};

struct trace_t
{
	Vector3 normal;//0x0
	float fraction;//0xC
	short sflags;
	short cflags;
	TraceHitType hitType;
	short hitId;//0x20
	short modelIndex;
	short partName;
	short partGroup;
	char unk4[0x10];
};
/* 1554 */
struct cplane_s
{
	Vector3 normal;
	float dist;
	char type;
	char signbits;
	char pad[2];
};

/* 1555 */
struct cbrushside_t
{
	cplane_s *plane;
	int cflags;
	int sflags;
};

/* 2577 */
struct cbrush_t
{
	Vector3 mins;
	int contents;
	Vector3 maxs;
	unsigned int numsides;
	cbrushside_t *sides;
	int axial_cflags[2][3];
	int axial_sflags[2][3];
	unsigned int numverts;
	Vector3 *verts;
};
union CollisionAabbTreeIndex
{
	int firstChildIndex;
	int partitionIndex;
};
struct CollisionAabbTree
{
	Vector3 origin;
	unsigned __int16 materialIndex;
	unsigned __int16 childCount;
	Vector3 halfSize;
	CollisionAabbTreeIndex u;
};
union $FEAE568E79F30CC825B5B849C1ABE004
{
	CollisionAabbTree *tree;
	cbrush_t *brush;
};

/* 2578 */
struct col_prim_t
{
	int type;
	$FEAE568E79F30CC825B5B849C1ABE004 ___u1;
};

struct IgnoreEntParams
{
	int baseEntity;
	int parentEntity;
	bool ignoreSelf;
	bool ignoreParent;
	bool ignoreSiblings;
	bool ignoreChildren;
};

struct col_context_t
{
	int mask;
	col_prim_t *prims;
	int nprims;
	IgnoreEntParams *ignoreEntParams;
	int passEntityNum0;
	int passEntityNum1;
	int staticmodels;
	int locational;
	char *priorityMap;
	int(__cdecl *collide_entity_func)(int);
};

void CG_LocationalTrace(trace_t * ptrace, Vector3  start, Vector3  end, int passEntityNum, int contentMask, bool checkRopes, col_context_t * context)
{
	Invoke<void>(0x100018, ptrace, &start, &end, passEntityNum, contentMask, checkRopes, context);
}





bool swapAnkle;
int GetNearestPlayer(int Client)
{
	currTag++;
	Tag = WASSS;
	float nearestDistance = 99999999;
	for (int i = 0; i < 18; ++i)
	{
		if (i != Client)
		{
			if (!ignoreShields == 1 && isPlayerShielding(i) || !IgnorePlayer[i])
			{
				if (!isPlayerFriendly(&pCentity_s[i]) && TeamCheck)
				{
					if (!*(bool*)ClientInfo(i, 0x8F))
					{
						if (*(int*)ClientInfo(i, 0x0C) > 0)
						{
							{
								if (*(int*)ClientInfo(i, 0x0C) > 0 && *(int*)(Centityy(i) + 0x2B4) == 0x59/*assault shield*/)
								{
									Tag = "j_ankle_le";
									float Distance = Distance3D(GetPlayerOrigin(Client), GetPlayerOrigin(i));
									if (autowallEnabled && autowall::isTargetHitable(getMyRefDef(), GetTagPosFloat(i, Tag), i))
									{
										if (Distance < nearestDistance)
										{
											nearestDistance = Distance;
											nearestClient = i;
											playerReady = true;
											shootNow = true;
										}
									}
									else if (!autowallEnabled)
									{
										if (isPlayerVisible(&pCentity_s[i]) && Stealth && !Logical)
										{
											if (Distance < nearestDistance)
											{
												nearestDistance = Distance;
												nearestClient = i;
												playerReady = true;
												shootNow = true;
											}
										}
										else if (!Stealth && !Logical)
										{
											if (Distance < nearestDistance)
											{
												nearestDistance = Distance;
												nearestClient = i;
												playerReady = true;
												shootNow = true;
											}
										}
										else if (Logical && !Stealth)
										{
											if (isAnyVis(LocalPlayer) == true)
											{
												if (Distance < nearestDistance)
												{
													nearestDistance = Distance;
													nearestClient = i;
													playerReady = true;
													shootNow = true;
												}
											}
											else
											{
												if (Distance < nearestDistance)
												{
													nearestDistance = Distance;
													nearestClient = i;
													playerReady = true;
													shootNow = true;
												}
											}
										}
									}
								}
								else
								{


									float Distance = Distance3D(GetPlayerOrigin(Client), GetPlayerOrigin(i));
									if (autowallEnabled && autowall::isTargetHitable(getMyRefDef(), GetTagPosFloat(i, Tag), i))
									{
										if (Distance < nearestDistance)
										{
											nearestDistance = Distance;
											nearestClient = i;
											playerReady = true;
											shootNow = true;
										}
									}
									else if (!autowallEnabled)
									{
										if (isPlayerVisible(&pCentity_s[i]) && Stealth && !Logical)
										{
											if (Distance < nearestDistance)
											{
												nearestDistance = Distance;
												nearestClient = i;
												playerReady = true;
												shootNow = true;
											}
										}
										else if (!Stealth && !Logical)
										{
											if (Distance < nearestDistance)
											{
												nearestDistance = Distance;
												nearestClient = i;
												playerReady = true;
												shootNow = true;
											}
										}
										else if (Logical && !Stealth)
										{
											if (isAnyVis(LocalPlayer) == true)
											{
												if (Distance < nearestDistance)
												{
													nearestDistance = Distance;
													nearestClient = i;
													playerReady = true;
													shootNow = true;
												}
											}
											else
											{
												if (Distance < nearestDistance)
												{
													nearestDistance = Distance;
													nearestClient = i;
													playerReady = true;
													shootNow = true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
				else if (!TeamCheck)
				{
					if (!*(bool*)ClientInfo(i, 0x8F))
					{
						if (*(int*)ClientInfo(i, 0x0C) > 0)
						{
							if (isPlayerVisible(&pCentity_s[i]) && Stealth)
							{
								float Distance = Distance3D(GetPlayerOrigin(Client), GetPlayerOrigin(i));
								if (Distance < nearestDistance)
								{
									nearestDistance = Distance;
									nearestClient = i;
									playerReady = true;
								}
							}
							else if (!Stealth)
							{
								float Distance = Distance3D(GetPlayerOrigin(Client), GetPlayerOrigin(i));
								if (Distance < nearestDistance)
								{
									nearestDistance = Distance;
									nearestClient = i;
									playerReady = true;
								}
							}
						}
					}
				}
			}
		}
	}
	return nearestClient;
}

void getTargetType() {
	if (aimbotType == 0) //Closest
	{
		Stealth = false;
		Logical = false;
	}
	else if (aimbotType == 1) //Logical
	{
		Stealth = false;
		Logical = true;
	}
	else if (aimbotType == 2) //Visible Only
	{
		Stealth = true;
		Logical = false;
	}
}

void doAimbot()
{
	if (DvarGetBool("cl_ingame"))
	{
		if (InGame && !isHostMigrating())
		{
			if (AimbotEnabled && ((!AimingRequired) || AimingRequired && (AimingKey == 1 && Key_IsDown(L1) || AimingKey == 2 && Key_IsDown(L2) || AimingKey == 3 && Key_IsDown(R1) || AimingKey == 4 && Key_IsDown(R2))))
			{
				//getTargetType();
				LocalPlayer = cg->clientNum;
				int nearestClient = GetNearestPlayer(LocalPlayer);
				if (playerReady && nearestClient != -1) {
					if (ignoreShields == 2 && isPlayerShielding(nearestClient))
					{
						Tag = "j_ankle_le";
					}
					//printf("Targetting Client %i\n", nearestClient);
					Vector3 Difference = AimTarget_GetTagPos(&pCentity_s[nearestClient], Tag);
					Vector3 Angles = Difference - cg->refdef.ViewOrigin;
					VectoAngles(&Angles, &anglesOut);

					AimAngles.x = anglesOut.x - ClientActive_s->baseAngle.x;
					AimAngles.y = anglesOut.y - ClientActive_s->baseAngle.y;
					AimAngles.z = 0;

					if (!sAimbot)
						ClientActive_s->viewAngle = anglesOut - ClientActive_s->baseAngle;
				}
			}
		}
		playerReady = false;
	}
}
