#define PI (3.1415926535897931)
#define FLAG_CROUCHED 0x04
#define FLAG_PRONE 0x08

typedef float Vector;
typedef struct Vector2
{
	float x, y;
	Vector2()
	{
		this->x = this->y = 0;
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(Vector2 & Vec)
	{
		return (this->x == Vec.x && this->y == Vec.y);
	}
	const Vector2& operator- (Vector2 const &Vector)
	{
		return Vector2(this->x - Vector.x, this->y - Vector.y);
	}
	const Vector2& operator+ (Vector2 const &Vector)
	{
		return Vector2(this->x + Vector.x, this->y + Vector.y);
	}
}Vector2, *PVector2;
namespace myMath {
#define PI (3.1415926535897931)
	float abs(float a) {
		if (a < 0)
			return a * -1;
		return a;
	}
	float DegreesToRadians(float Degrees)
	{
		return Degrees * PI / 180.0f;
	}

	float RadiansToDegrees(float Radians)
	{
		return Radians * 180.0f / PI;
	}

	float pow(float num, int power) {
		float ret = 1;
		for (int i = 0; i < power; i++)
			ret = ret * num;
		return ret;
	}

	float root(float num, int nroot) {
		int iterations = 15 * (nroot - 1);
		float x = iterations * 100;
		for (int i = 1; i < iterations; i++) {
			x = (float)(((float)1 / nroot)*(((nroot - 1)*x) + (num / pow(x, nroot - 1))));
		}
		return x;
	}

	float sin(float deg) {
		bool neg = false;
		while (deg >= 360) deg = deg - 360;
		while (deg < 0) deg = deg + 360;
		if (deg > 180) {
			deg = deg - 180;
			neg = true;
		}
		float ret = (float)(4 * deg*(180 - deg)) / (40500 - (deg*(180 - deg)));
		if (neg)return ret * -1;
		return ret;
	}

	float cos(float AnglesDeg)
	{
		float AnglesRad = DegreesToRadians(AnglesDeg);
		float Rad = (float)(PI / 2.0f) - AnglesRad;
		float ang = RadiansToDegrees(Rad);
		return sin(ang);
	}

	float tan(float AnglesDeg)
	{
		float sinus = sin(AnglesDeg);
		float cosinus = cos(AnglesDeg);
		return sinus / cosinus;
	}

	double atan(double x, int n)
	{
		double a = 0.0;// 1st term
		double sum = 0.0;

		// special cases
		if (x == 1.0) return PI / 4.0;
		if (x == -1.0) return -PI / 4.0;

		if (n > 0)
		{
			if ((x < -1.0) || (x > 1.0))
			{
				// constant term
				if (x > 1.0)
					sum = PI / 2.0;
				else
					sum = -PI / 2.0;
				// initial value of a
				a = -1.0 / x;
				for (int j = 1; j <= n; j++)
				{
					sum += a;
					a *= -1.0*(2.0*j - 1) / ((2.0*j + 1)*x*x);// next term from last
				}
			}
			else// -1 < x < 1
			{
				// constant term
				sum = 0.0;
				// initial value of a
				a = x;
				for (int j = 1; j <= n; j++)
				{
					sum += a;
					a *= -1.0*(2.0*j - 1)*x*x / (2.0*j + 1);// next term from last
				}
			}
			//r_err = a;// max. error = 1st term not taken for alternating series
		}

		return sum;
	}

	double atan2(double y, double x)
	{
		double u = atan(y / x, 24);
		if (x < 0.0)// 2nd, 3rd quadrant
		{
			if (u > 0.0)// will go to 3rd quadrant
				u -= PI;
			else
				u += PI;
		}
		return u;
	}


}

typedef struct Vector3
{
	float x, y, z;
	Vector3()
	{
		x = y = z = 0;
	}
	Vector3(float x, float y, float z)
	{
		this->x = x; this->y = y; this->z = z;
	}
	const bool operator== (Vector3 const &Vector)
	{
		return (this->x == Vector.x && this->y == Vector.y && this->z == Vector.z);
	}
	const Vector3& operator+ (Vector3 const &Vector)
	{
		return Vector3(this->x + Vector.x, this->y + Vector.y, this->z + Vector.z);
	}
	const Vector3& operator- (Vector3 const &Vector)
	{
		return Vector3(this->x - Vector.x, this->y - Vector.y, this->z - Vector.z);
	}
	Vector3 VectorNormalize() {
		Vector3 v;
		float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
		if (length != 0) {
			v.x = v.x / length;
			v.y = v.y / length;
			v.z = v.z / length;
		}
	}
	float Distance(Vector3 const &Vector)
	{
		return sqrtf(DistanceEx(Vector));
	}
	float DistanceEx(Vector3 const &Vector)
	{
		float _x = this->x - Vector.x, _y = this->y - Vector.y, _z = this->z - Vector.z;
		return ((_x * _x) + (_y * _y) + (_z * _z));
	}
	const Vector3 &RoundHalfUp()
	{
		return Vector3(floor(this->x + 0.5), floor(this->y + 0.5), floor(this->z + 0.5));
	}\
		const Vector3 &RoundHalfDown()
	{
		return Vector3(floor(this->x + 0.5), floor(this->y + 0.5), floor(this->z + 0.5));
	}
} Vector3, *PVector3;


float dx, dy, dz;
float Distance3D(Vector3 c1, Vector3 c2)
{
	float dx = c2.x - c1.x;
	float dy = c2.y - c1.y;
	float dz = c2.z - c1.z;

	return sqrt((float)((dx * dx) + (dy * dy) + (dz * dz)));
}

typedef struct Vector4
{
	float x, y, z, a;
	Vector4()
	{
		x = y = z = a = 0;
	}
	Vector4(float x, float y, float z, float a)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->a = a;
	}

} Vector4, *PVector4;

Vector3 vectoangles(Vector3 Angles)
{
	float forward;
	float yaw, pitch;
	//float PI = 3.1415926535897931;
	if (Angles.x == 0 && Angles.y == 0)
	{
		yaw = 0;
		if (Angles.z > 0) pitch = 90.00;
		else pitch = 270.00;
	}
	else
	{
		if (Angles.x != -1) yaw = (float)(atan2((double)Angles.y, (double)Angles.x) * 180.00 / PI);
		else if (Angles.y > 0) yaw = 90.00;
		else yaw = 270;
		if (yaw < 0) yaw += 360.00;

		forward = (float)sqrt((double)(Angles.x * Angles.x + Angles.y * Angles.y));
		pitch = (float)(atan2((double)Angles.z, (double)forward) * 180.00 / PI);
		if (pitch < 0) pitch += 360.00;
	}
	Vector3 AnglesVector(-pitch, yaw, 0);
	return AnglesVector;
}

Vector3 Difference(Vector3 Target, Vector3 Entity)
{
	Vector3 Return = Target - Entity;
	return Return;
}

typedef struct vec4_t
{
	float x, y, z, w;
	vec4_t()
	{
		x = y = z = w = 0;
	};
};


struct GfxCmdHeader {
	unsigned short byteCount;
	char id;
	char ui3d;
};

union GfxColor {
	unsigned int packed;
	char array[4];
};

struct GfxCmdDrawText2D {
	GfxCmdHeader header;
	int type;
	float x;
	float y;
	float w;
	float h;
	float rotation;
	void* font;
	float xScale;
	float yScale;
	GfxColor color;
	signed int maxChars;
	int renderFlags;
	int cursorPos;
	char cursorLetter;
	GfxColor glowForceColor;
	int fxBirthTime;
	int fxLetterTime;
	int fxDecayStartTime;
	int fxDecayDuration;
	int fxRedactDecayStartTime;
	int fxRedactDecayDuration;
	void* fxMaterial;
	void* fxMaterialGlow;
	float padding;
	char text[3];
};


struct GfxCmdStretchPic {
	GfxCmdHeader header;
	void* material;
	float x;
	float y;
	float w0;
	float w;
	float h;
	float s0;
	float t0;
	float s1;
	float t1;
	GfxColor color;
};

/* dvar->flags */
#define DVAR_ARCHIVE		(1 << 0)	// 0x0001
#define DVAR_USERINFO		(1 << 1)	// 0x0002
#define DVAR_SERVERINFO		(1 << 2)	// 0x0004
#define DVAR_SYSTEMINFO		(1 << 3)	// 0x0008
#define DVAR_INIT		(1 << 4)	// 0x0010
#define DVAR_LATCH		(1 << 5)	// 0x0020
#define DVAR_ROM		(1 << 6)	// 0x0040
#define DVAR_CHEAT		(1 << 7)	// 0x0080
#define DVAR_DEVELOPER		(1 << 8)	// 0x0100
#define DVAR_SAVED		(1 << 9)	// 0x0200
#define DVAR_NORESTART		(1 << 10)	// 0x0400
#define DVAR_CHANGEABLE_RESET	(1 << 12)	// 0x1000
#define DVAR_EXTERNAL		(1 << 14)	// 0x4000
#define DVAR_AUTOEXEC		(1 << 15)	// 0x8000

enum dvarType_t
{
	DVAR_TYPE_INVALID = 0x0,
	DVAR_TYPE_BOOL = 0x1,
	DVAR_TYPE_FLOAT = 0x2,
	DVAR_TYPE_FLOAT_2 = 0x3,
	DVAR_TYPE_FLOAT_3 = 0x4,
	DVAR_TYPE_FLOAT_4 = 0x5,
	DVAR_TYPE_INT = 0x6,
	DVAR_TYPE_ENUM = 0x7,
	DVAR_TYPE_STRING = 0x8,
	DVAR_TYPE_COLOR = 0x9,
	DVAR_TYPE_INT64 = 0xA,
	DVAR_TYPE_LINEAR_COLOR_RGB = 0xB,
	DVAR_TYPE_COLOR_XYZ = 0xC,
	DVAR_TYPE_COUNT = 0xD,
};

union DvarLimits
{
	struct {
		int stringCount;
		const char **strings;
	} enumeration;

	struct {
		int min;
		int max;
	} integer;

	struct {
		float min;
		float max;
	} value, vector;

	struct {
		int64_t min;
		int64_t max;
	} integer64;
};

enum eSessionModes_mode
{
	SESSIONMODE_OFFLINE = 0x0,
	SESSIONMODE_SYSTEMLINK = 0x1,
	SESSIONMODE_ONLINE = 0x2,
	SESSIONMODE_LOCAL = 0x3,
	SESSIONMODE_ZOMBIES = 0x4,
	SESSIONMODE_MAX = 0x5,
	SESSIONMODE_INVALID = 0x6,
};

#pragma region weapon def
#pragma region enums

enum guidedMissileType_t
{
	MISSILE_GUIDANCE_NONE = 0x0,
	MISSILE_GUIDANCE_SIDEWINDER = 0x1,
	MISSILE_GUIDANCE_HELLFIRE = 0x2,
	MISSILE_GUIDANCE_JAVELIN = 0x3,
	MISSILE_GUIDANCE_BALLISTIC = 0x4,
	MISSILE_GUIDANCE_WIREGUIDED = 0x5,
	MISSILE_GUIDANCE_TVGUIDED = 0x6,
	MISSILE_GUIDANCE_COUNT = 0x7,
};
enum AnimationType {

	none = 0,
	adefault = 1,
	other = 2,
	sniper = 3,
	m203 = 4,
	hold = 5,
	briefcase = 6,
	reviver = 7,
	radio = 8,
	dualwield = 9,
	remotecontrol = 10,
	crossbow = 11,
	minigun = 12,
	beltfed = 13,
	g11 = 14,
	rearclip = 15,
	handleclip = 16,
	rearclipsniper = 17,
	ballisticknife = 18,
	singleknife = 19,
	nopump = 20,
	hatchet = 21,
	grimreaper = 22,
	zipline = 23,
	riotshield = 24,
	tablet = 25,
	turned = 26,
	screecher = 27,
	PLAYER_ANIM_TYPE_MAX
};
enum weapType_t
{
	WEAPTYPE_BULLET = 0x0,
	WEAPTYPE_GRENADE = 0x1,
	WEAPTYPE_PROJECTILE = 0x2,
	WEAPTYPE_BINOCULARS = 0x3,
	WEAPTYPE_GAS = 0x4,
	WEAPTYPE_BOMB = 0x5,
	WEAPTYPE_MINE = 0x6,
	WEAPTYPE_MELEE = 0x7,
	WEAPTYPE_NUM = 0x8,
};
enum weapClass_t
{
	WEAPCLASS_RIFLE = 0x0,
	WEAPCLASS_MG = 0x1,
	WEAPCLASS_SMG = 0x2,
	WEAPCLASS_SPREAD = 0x3,
	WEAPCLASS_PISTOL = 0x4,
	WEAPCLASS_GRENADE = 0x5,
	WEAPCLASS_ROCKETLAUNCHER = 0x6,
	WEAPCLASS_TURRET = 0x7,
	WEAPCLASS_NON_PLAYER = 0x8,
	WEAPCLASS_GAS = 0x9,
	WEAPCLASS_ITEM = 0xA,
	WEAPCLASS_MELEE = 0xB,
	WEAPCLASS_KILLSTREAK_ALT_STORED_WEAPON = 0xC,
	WEAPCLASS_NUM = 0xD,
};
enum PenetrateType
{
	PENETRATE_TYPE_NONE = 0x0,
	PENETRATE_TYPE_SMALL = 0x1,
	PENETRATE_TYPE_MEDIUM = 0x2,
	PENETRATE_TYPE_LARGE = 0x3,
	PENETRATE_TYPE_COUNT = 0x4,
};
enum ImpactType
{
	IMPACT_TYPE_NONE = 0x0,
	IMPACT_TYPE_BULLET_SMALL = 0x1,
	IMPACT_TYPE_BULLET_LARGE = 0x2,
	IMPACT_TYPE_BULLET_AP = 0x3,
	IMPACT_TYPE_BULLET_XTREME = 0x4,
	IMPACT_TYPE_SHOTGUN = 0x5,
	IMPACT_TYPE_GRENADE_BOUNCE = 0x6,
	IMPACT_TYPE_GRENADE_EXPLODE = 0x7,
	IMPACT_TYPE_RIFLE_GRENADE = 0x8,
	IMPACT_TYPE_ROCKET_EXPLODE = 0x9,
	IMPACT_TYPE_ROCKET_EXPLODE_XTREME = 0xA,
	IMPACT_TYPE_PROJECTILE_DUD = 0xB,
	IMPACT_TYPE_MORTAR_SHELL = 0xC,
	IMPACT_TYPE_TANK_SHELL = 0xD,
	IMPACT_TYPE_BOLT = 0xE,
	IMPACT_TYPE_BLADE = 0xF,
	IMPACT_TYPE_COUNT = 0x10,
};
enum weapInventoryType_t
{
	WEAPINVENTORY_PRIMARY = 0x0,
	WEAPINVENTORY_OFFHAND = 0x1,
	WEAPINVENTORY_ITEM = 0x2,
	WEAPINVENTORY_ALTMODE = 0x3,
	WEAPINVENTORY_MELEE = 0x4,
	WEAPINVENTORYCOUNT = 0x5,
};
enum weapFireType_t
{
	WEAPON_FIRETYPE_FULLAUTO = 0x0,
	WEAPON_FIRETYPE_SINGLESHOT = 0x1,
	WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
	WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
	WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
	WEAPON_FIRETYPE_STACKED = 0x5,
	WEAPON_FIRETYPE_MINIGUN = 0x6,
	WEAPON_FIRETYPECOUNT = 0x7,
};
enum weapClipType_t
{
	WEAPON_CLIPTYPE_BOTTOM = 0x0,
	WEAPON_CLIPTYPE_TOP = 0x1,
	WEAPON_CLIPTYPE_LEFT = 0x2,
	WEAPON_CLIPTYPE_DP28 = 0x3,
	WEAPON_CLIPTYPE_PTRS = 0x4,
	WEAPON_CLIPTYPE_LMG = 0x5,
	WEAPON_CLIPTYPECOUNT = 0x6,
};
enum barrelType_t {

	BARREL_TYPE_SINGLE = 0x0,
	BARREL_TYPE_DUAL = 0x1,
	BARREL_TYPE_DUAL_ALTERNATE = 0x2,
	BARREL_TYPE_QUAD = 0x3,
	BARREL_TYPE_QUAD_ALTERNATE = 0x4,
	BARREL_TYPE_QUAD_DOUBLE_ALTERNATE = 0x5,
	BARREL_TYPE_COUNT = 0x6
};
enum OffhandClass {

	OFFHAND_CLASS_NONE = 0x0,
	OFFHAND_CLASS_FRAG_GRENADE = 0x1,
	OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
	OFFHAND_CLASS_FLASH_GRENADE = 0x3,
	OFFHAND_CLASS_GEAR = 0x4,
	OFFHAND_CLASS_SUPPLYDROP_MARKER = 0x5,
	OFFHAND_CLASS_COUNT = 0x6,
};
enum OffhandSlot {

	OFFHAND_SLOT_NONE = 0x0,
	OFFHAND_SLOT_LETHAL_GRENADE = 0x1,
	OFFHAND_SLOT_TACTICAL_GRENADE = 0x2,
	OFFHAND_SLOT_EQUIPMENT = 0x3,
	OFFHAND_SLOT_SPECIFIC_USE = 0x4,
	OFFHAND_SLOT_COUNT = 0x5,
};
enum weapStance_t
{
	WEAPSTANCE_STAND = 0x0,
	WEAPSTANCE_DUCK = 0x1,
	WEAPSTANCE_PRONE = 0x2,
	WEAPSTANCE_NUM = 0x3,
};
enum activeReticleType_t
{
	VEH_ACTIVE_RETICLE_NONE = 0x0,
	VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
	VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
	VEH_ACTIVE_RETICLE_COUNT = 0x3,
};
enum weaponIconRatioType_t
{
	WEAPON_ICON_RATIO_1TO1 = 0x0,
	WEAPON_ICON_RATIO_2TO1 = 0x1,
	WEAPON_ICON_RATIO_4TO1 = 0x2,
	WEAPON_ICON_RATIO_COUNT = 0x3,
};
enum ammoCounterClipType_t
{
	AMMO_COUNTER_CLIP_NONE = 0x0,
	AMMO_COUNTER_CLIP_MAGAZINE = 0x1,
	AMMO_COUNTER_CLIP_SHORTMAGAZINE = 0x2,
	AMMO_COUNTER_CLIP_SHOTGUN = 0x3,
	AMMO_COUNTER_CLIP_ROCKET = 0x4,
	AMMO_COUNTER_CLIP_BELTFED = 0x5,
	AMMO_COUNTER_CLIP_ALTWEAPON = 0x6,
	AMMO_COUNTER_CLIP_COUNT = 0x7,
};
enum weapOverlayReticle_t
{
	WEAPOVERLAYRETICLE_NONE = 0x0,
	WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
	WEAPOVERLAYRETICLE_NUM = 0x2,
};
enum weapOverlayInterface_t {

	WEAPOVERLAYINTERFACE_NONE = 0x0,
	WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
	WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
	WEAPOVERLAYINTERFACE_MAX
};
enum weapProjExposion_t
{
	WEAPPROJEXP_GRENADE = 0x0,
	WEAPPROJEXP_ROCKET = 0x1,
	WEAPPROJEXP_FLASHBANG = 0x2,
	WEAPPROJEXP_NONE = 0x3,
	WEAPPROJEXP_DUD = 0x4,
	WEAPPROJEXP_SMOKE = 0x5,
	WEAPPROJEXP_HEAVY = 0x6,
	WEAPPROJEXP_FIRE = 0x7,
	WEAPPROJEXP_NAPALMBLOB = 0x8,
	WEAPPROJEXP_BOLT = 0x9,
	WEAPPROJEXP_NUM = 0xA,
};
enum WeapStickinessType {

	WEAPSTICKINESS_NONE = 0x0,
	WEAPSTICKINESS_ALL = 0x1,
	WEAPSTICKINESS_ALL_NO_SENTIENTS = 0x2,
	WEAPSTICKINESS_GROUND = 0x3,
	WEAPSTICKINESS_GROUND_WITH_YAW = 0x4,
	WEAPSTICKINESS_FLESH = 0x5,
	WEAPSTICKINESS_COUNT = 0x6
};

enum WeapRotateType {

	WEAPROTATE_GRENADE_ROTATE = 0x0,
	WEAPROTATE_BLADE_ROTATE = 0x1,
	WEAPROTATE_CYLINDER_ROTATE = 0x2,
	WEAPROTATE_COUNT = 0x3
};
#pragma endregion

enum CG_DrawNameMode_t
{
	Abbreviated = 0,
	ClanTagOnly = 1,
	FullName = 2,
	RankIconOnly = 3,
};



typedef unsigned int ScriptString;

struct ProjectileExplosionEffect {

	int * projExplosionEffect;
	bool projExplosionEffectForceNormalUp;
};
struct WeaponDef {

	const char *szOverlayName;
	int **gunXModel;
	int *handXModel;
	const char *szModeName;
	ScriptString(*noteTrackSoundMapKeys)[0x14];
	ScriptString(*notetrackSoundMapValues)[0x14];
	AnimationType playerAnimType;
	weapType_t weaponType;
	weapClass_t weaponClass;
	PenetrateType penetrateType;
	ImpactType impactType;
	weapInventoryType_t inventoryType;
	weapFireType_t fireType;
	weapClipType_t clipType;
	barrelType_t barrelType;
	int itemIndex;
	const char * parentWeaponName;
	int iJamFireTime;
	int overheatWeapon;
	float overheatRate;
	float cooldownRate;
	float overheatEndVal;
	bool coolWhileFiring;
	bool fuelTankWeapon;
	int iTankLifeTime;
	OffhandClass offhandClass;
	OffhandSlot offhandSlot;
	weapStance_t stance;
	int * viewFlashEffect;
	int * worldFlashEffect;
	int * barrelCooldownEffect;
	int barrelCooldownMinCount;
	Vector3 vViewFlashOffset;
	Vector3 vWorldFlashOffset;
	char * pickupSound;
	char * pickupSoundPlayer;
	char * ammoPickupSound;
	char * ammoPickupSoundPlayer;
	char * projectileSound;
	char * pullbackSound;
	char * pullbackSoundPlayer;
	char * fireSound;
	char * fireSoundPlayer;
	char * loopFireSound;
	char * loopFireSoundPlayer;
	char * loopFireEndSound;
	char * loopFireEndSoundPlayer;
	char * startFireSound;
	char * stopFireSound;
	char * killcamStartFireSound;
	char * startFireSoundPlayer;
	char * stopFireSoundPlayer;
	char * killcamStartFireSoundPlayer;
	char * lastShotSound;
	char * lastShotSoundPlayer;
	char * emptyFireSound;
	char * emptyFireSoundPlayer;
	char * crackSound;
	char * whizbySound;
	char * meleeSwipeSound;
	char * meleeSwipeSoundPlayer;
	char * meleeHitSound;
	char * meleeMissSound;
	char * rechamberSound;
	char * rechamberSoundPlayer;
	char * reloadSound;
	char * reloadSoundPlayer;
	char * reloadEmptySound;
	char * reloadEmptySoundPlayer;
	char * reloadStartSound;
	char * reloadStartSoundPlayer;
	char * reloadEndSound;
	char * reloadEndSoundPlayer;
	char * rotateLoopSound;
	char * rotateLoopSoundPlayer;
	char * rotateStopSound;
	char * rotateStopSoundPlayer;
	char * deploySound;
	char * deploySoundPlayer;
	char * finishDeploySound;
	char * finishDeploySoundPlayer;
	char * breakdownSound;
	char * breakdownSoundPlayer;
	char * finishBreakdownSound;
	char * finishBreakdownSoundPlayer;
	char * detonateSound;
	char * detonateSoundPlayer;
	char * nightVisionWearSound;
	char * nightVisionWearSoundPlayer;
	char * nightVisionRemoveSound;
	char * nightVisionRemoveSoundPlayer;
	char * altSwitchSound;
	char * altSwitchSoundPlayer;
	char * raiseSound;
	char * raiseSoundPlayer;
	char * firstRaiseSound;
	char * firstRaiseSoundPlayer;
	char * adsRaiseSoundPlayer;
	char * adsLowerSoundPlayer;
	char * putawaySound;
	char * putawaySoundPlayer;
	char * overheatSound;
	char * overheatSoundPlayer;
	char * adsZoomSound;
	char * shellCasing;
	char * shellCasingPlayer;
	char * * bounceSounds;    //Refer to surfaceNames_t
	const char * standMountedWeapdef;
	const char * crouchMountedWeapdef;
	const char * proneMountedWeapdef;
	unsigned int standMountedWeapIndex;
	unsigned int crouchMountedWeapIndex;
	unsigned int proneMountedWeapIndex;
	int * viewShellEjectEffect;
	int * worldShellEjectEffect;
	int * viewLastShotEjectEffect;
	int * worldLastShotEjectEffect;
	Vector3 vViewShellEjectOffset;
	Vector3 vWorldShellEjectOffset;
	Vector3 vViewShellEjectRotation;
	Vector3 vWorldShellEjectRotation;
	int *reticleCenter;
	int *reticleSide;
	int iReticleCenterSize;
	int iReticleSideSize;
	int iReticleMinOfs;
	activeReticleType_t activeReticleType;
	Vector3 vStandMove;
	Vector3 vStandRot;
	Vector3 vDuckedOfs;
	Vector3 vDuckedMove;
	Vector3 vDuckedSprintOfs;
	Vector3 vDuckedSprintRot;
	Vector2 vDuckedSprintBob;
	float fDuckedSprintCycleScale;
	Vector3 vSprintOfs;
	Vector3 vSprintRot;
	Vector2 vSprintBob;
	float fSprintCycleScale;
	Vector3 vLowReadyOfs;
	Vector3 vLowReadyRot;
	Vector3 vRideOfs;
	Vector3 vRideRot;
	Vector3 vDtpOfs;
	Vector3 vDtpRot;
	Vector2 vDtpBob;
	float fDtpCycleScale;
	Vector3 vMantleOfs;
	Vector3 vMantleRot;
	Vector3 vSlideOfs;
	Vector3 vSlideRot;
	Vector3 vDuckedRot;
	Vector3 vProneOfs;
	Vector3 vProneMove;
	Vector3 vProneRot;
	Vector3 vStrafeMove;
	Vector3 vStrafeRot;
	float fPosMoveRate;
	float fPosProneMoveRate;
	float fStandMoveMinSpeed;
	float fDuckedMoveMinSpeed;
	float fProneMoveMinSpeed;
	float fPosRotRate;
	float fPosProneRotRate;
	float fStandRotMinSpeed;
	float fDuckedRotMinSpeed;
	float fProneRotMinSpeed;
	int * *worldModel;
	int *worldClipModel;
	int *rocketModel;
	int *mountedModel;
	int *additionalMeleeModel;
	int * fireTypeIcon;
	int * hudIcon;
	weaponIconRatioType_t hudIconRatio;
	int * indicatorIcon;
	weaponIconRatioType_t indicatorIconRatio;
	int * ammoCounterIcon;
	weaponIconRatioType_t ammoCounterIconRatio;
	ammoCounterClipType_t ammoCounterClip;
	int iStartAmmo;
	int iMaxAmmo;
	int shotCount;
	const char *szSharedAmmoCapName;
	int iSharedAmmoCapIndex;
	int iSharedAmmoCap;
	bool unlimitedAmmo;
	bool ammoCountClipRelative;
	int damage[6];
	float damageRange[6];
	int minPlayerDamage;
	float damageDuration;
	float damageInterval;
	int playerDamage;
	int iMeleeDamage;
	int iDamageType;
	ScriptString explosionTag;
	int iFireDelay;
	int iMeleeDelay;
	int meleeChargeDelay;
	int iDetonateDelay;
	int iSpinUpTime;
	int iSpinDownTime;
	float spinRate;
	const char *spinLoopSound;
	const char *spinLoopSoundPlayer;
	const char *startSpinSound;
	const char *startSpinSoundPlayer;
	const char *stopSpinSound;
	const char *stopSpinSoundPlayer;
	bool applySpinPitch;
	int iFireTime;
	int iLastFireTime;
	int iRechamberTime;
	int iRechamberBoltTime;
	int iHoldFireTime;
	int iDetonateTime;
	int iMeleeTime;
	int iBurstDelayTime;
	int meleeChargeTime;
	int iReloadTimeRight;
	int iReloadTimeLeft;
	int reloadShowRocketTime;
	int iReloadEmptyTimeLeft;
	int iReloadAddTime;
	int iReloadEmptyAddTime;
	int iReloadQuickAddTime;
	int iReloadQuickEmptyAddTime;
	int iReloadStartTime;
	int iReloadStartAddTime;
	int iReloadEndTime;
	int iDropTime;
	int iRaiseTime;
	int iAltDropTime;
	int quickDropTime;
	int quickRaiseTime;
	int iFirstRaiseTime;
	int iEmptyRaiseTime;
	int iEmptyDropTime;
	int sprintInTime;
	int sprintLoopTime;
	int sprintOutTime;
	int lowReadyInTime;
	int lowReadyLoopTime;
	int lowReadyOutTime;
	int contFireInTime;
	int contFireLoopTime;
	int contFireOutTime;
	int dtpInTime;
	int dtpLoopTime;
	int dtpOutTime;
	int crawlInTime;
	int crawlForwardTime;
	int crawlBackTime;
	int crawlRightTime;
	int crawlLeftTime;
	int crawlOutFireTime;
	int crawlOutTime;
	int slideInTime;
	int deployTime;
	int breakdownTime;
	int iFlourishTime;
	int nightVisionWearTime;
	int nightVisionWearTimeFadeOutEnd;
	int nightVisionWearTimePowerUp;
	int nightVisionRemoveTime;
	int nightVisionRemoveTimePowerDown;
	int nightVisionRemoveTimeFadeInStart;
	int fuseTime;
	int aiFuseTime;
	int lockOnRadius;
	int lockOnSpeed;
	bool requireLockonToFire;
	bool noAdsWhenMagEmpty;
	bool avoidDropCleanup;
	unsigned int stackFire;
	float stackFireSpread;
	float stackFireAccuracyDecay;
	const char *stackSound;
	float autoAimRange;
	float aimAssistRange;
	bool mountableWeapon;
	float aimPadding;
	float enemyCrosshairRange;
	bool crosshairColorChange;
	float moveSpeedScale;
	float adsMoveSpeedScale;
	float sprintDurationScale;
	weapOverlayReticle_t adsOverlayReticle;
	weapOverlayInterface_t adsOverlayInterface;
	float overlayWidth;
	float overlayHeight;
	float fAdsBobFactor;
	float fAdsViewBobMult;
	bool bHoldBreathToSteady;
	float fHipSpreadStandMin;
	float fHipSpreadDuckedMin;
	float fHipSpreadProneMin;
	float hipSpreadStandMax;
	float hipSpreadDuckedMax;
	float hipSpreadProneMax;
	float fHipSpreadDecayRate;
	float fHipSpreadFireAdd;
	float fHipSpreadTurnAdd;
	float fHipSpreadMoveAdd;
	float fHipSpreadDuckedDecay;
	float fHipSpreadProneDecay;
	float fHipReticleSidePos;
	float fAdsIdleAmount;
	float fHipIdleAmount;
	float adsIdleSpeed;
	float hipIdleSpeed;
	float fIdleCrouchFactor;
	float fIdleProneFactor;
	float fGunMaxPitch;
	float fGunMaxYaw;
	float swayMaxAngle;
	float swayLerpSpeed;
	float swayPitchScale;
	float swayYawScale;
	float swayHorizScale;
	float swayVertScale;
	float swayShellShockScale;
	float adsSwayMaxAngle;
	float adsSwayLerpSpeed;
	float adsSwayPitchScale;
	float adsSwayYawScale;
	bool sharedAmmo;
	bool bRifleBullet;
	bool armorPiercing;
	bool bAirburstWeapon;
	bool bBoltAction;
	bool bUseAltTagFlash;
	bool bUseAntiLagRewind;
	bool bIsCarriedKillstreakWeapon;
	bool aimDownSight;
	bool bRechamberWhileAds;
	bool bReloadWhileAds;
	float adsViewErrorMin;
	float adsViewErrorMax;
	bool bCookOffHold;
	bool bClipOnly;
	bool bCanUseInVehicle;
	bool bNoDropsOrRaises;
	bool adsFireOnly;
	bool cancelAutoHolsterWhenEmpty;
	bool suppressAmmoReserveDisplay;
	bool laserSight;
	bool laserSightDuringNightvision;
	bool bHideThirdPerson;
	bool bHasBayonet;
	bool bDualWield;
	bool bExplodeOnGround;
	bool bThrowBack;
	bool bRetrievable;
	bool bDieOnRespawn;
	bool bNoThirdPersonDropsOrRaises;
	bool bContinuousFire;
	bool bNoPing;
	bool bForceBounce;
	bool bUseDroppedModelAsStowed;
	bool bNoQuickDropWhenEmpty;
	bool bKeepCrosshairWhenADS;
	bool bUseOnlyAltWeaoponHideTagsInAltMode;
	bool bAltWeaponAdsOnly;
	bool bAltWeaponDisableSwitching;
	int *killIcon;
	weaponIconRatioType_t killIconRatio;
	bool flipKillIcon;
	bool bNoPartialReload;
	bool bSegmentedReload;
	bool bNoADSAutoReload;
	int iReloadAmmoAdd;
	int iReloadStartAdd;
	const char *szSpawnedGrenadeWeaponName;
	const char *szDualWieldWeaponName;
	unsigned int dualWieldWeaponIndex;
	int iDropAmmoMin;
	int iDropAmmoMax;
	int iDropClipAmmoMin;
	int iDropClipAmmoMax;
	int iShotsBeforeRechamber;
	bool blocksProne;
	bool bShowIndicator;
	int isRollingGrenade;
	int useBallisticPrediction;
	int isValuable;
	int isTacticalInsertion;
	bool isReviveWeapon;
	bool bUseRigidBodyOnVehicle;
	int iExplosionRadius;
	int iExplosionRadiusMin;
	int iIndicatorRadius;
	int iExplosionInnerDamage;
	int iExplosionOuterDamage;
	float damageConeAngle;
	int iProjectileSpeed;
	int iProjectileSpeedUp;
	int iProjectileSpeedRelativeUp;
	int iProjectileSpeedForward;
	float fProjectileTakeParentVelocity;
	int iProjectileActivateDist;
	float projLifetime;
	float timeToAccelerate;
	float projectileCurvature;
	int *projectileModel;
	weapProjExposion_t projExplosion;
	ProjectileExplosionEffect projExplosionEffect[5];
	int * projDudEffect;
	const char *projExplosionSound;
	const char *projDudSound;
	const char *mortarShellSound;
	const char *tankShellSound;
	bool bProjImpactExplode;
	bool bProjSentientImpactExplode;
	bool bProjExplodeWhenStationary;
	bool bBulletImpactExplode;
	WeapStickinessType stickiness;
	WeapRotateType rotateType;
	bool plantable;
	bool hasDetonator;
	bool timedDetonation;
	bool noCrumpleMissile;
	bool rotate;
	bool keepRolling;
	bool holdButtonToThrow;
	bool offhandHoldIsCancelable;
	bool freezeMovementWhenFiring;
	float lowAmmoWarningThreshold;
	bool bDisallowAtMatchStart;
	float meleeChargeRange;
	bool bUseAsMelee;
	bool isCameraSensor;
	bool isAcousticSensor;
	bool isLaserSensor;
	bool isHoldUseGrenade;
	float *parallelBounce;
	float *perpendicularBounce;
	int * projTrailEffect;
	Vector3 vProjectileColor;
	guidedMissileType_t guidedMissileType;
	float maxSteeringAccel;
	int projIgnitionDelay;
	int projIgnitionEffect;
	const char *projIgnitionSound;
	float fAdsAimPitch;
	float fAdsCrosshairInFrac;
	float fAdsCrosshairOutFrac;
	int adsGunKickReducedKickBullets;
	float adsGunKickReducedKickPercent;
	float fAdsGunKickPitchMin;
	float fAdsGunKickPitchMax;
	float fAdsGunKickYawMin;
	float fAdsGunKickYawMax;
	float fAdsGunKickAccel;
	float fAdsGunKickSpeedMax;
	float fAdsGunKickSpeedDecay;
	float fAdsGunKickStaticDecay;
	float fAdsViewKickPitchMin;
	float fAdsViewKickPitchMax;
	float fAdsViewKickMinMagnitude;
	float fAdsViewKickYawMin;
	float fAdsViewKickYawMax;
	float fAdsRecoilReductionRate;
	float fAdsRecoilReductionLimit;
	float fAdsRecoilReturnRate;
	float fAdsViewScatterMin;
	float fAdsViewScatterMax;
	float fAdsSpread;
	int hipGunKickReducedKickBullets;
	float hipGunKickReducedKickPercent;
	float fHipGunKickPitchMin;
	float fHipGunKickPitchMax;
	float fHipGunKickYawMin;
	float fHipGunKickYawMax;
	float fHipGunKickAccel;
	float fHipGunKickSpeedMax;
	float fHipGunKickSpeedDecay;
	float fHipGunKickStaticDecay;
	float fHipViewKickPitchMin;
	float fHipViewKickPitchMax;
	float fHipViewKickMinMagnitude;
	float fHipViewKickYawMin;
	float fHipViewKickYawMax;
	float fHipViewScatterMin;
	float fHipViewScatterMax;
	float fAdsViewKickCenterDuckedScale;
	float fAdsViewKickCenterProneScale;
	float fAntiQuickScopeTime;
	float fAntiQuickScopeScale;
	float fAntiQuickScopeSpreadMultiplier;
	float fAntiQuickScopeSpreadMax;
	float fAntiQuickScopeSwayFactor;
	float fightDist;
	float maxDist;
	const char * aiVsAiAccuracyGraphName;
	const char * aiVsPlayerAccuracyGraphName;
	Vector2 * aiVsAiAccuracyGraphKnots;
	Vector2 * aiVsPlayerAccuracyGraphKnots;
	Vector2 * aiVsAiOriginalAccuracyGraphKnots;
	Vector2 * aiVsPlayerOriginalAccuracyGraphKnots;
	int aiVsAiAccuracyGraphKnotCount;
	int aiVsPlayerAccuracyGraphKnotCount;
	int aiVsAiOriginalAccuracyGraphKnotCount;
	int aiVsPlayerOriginalAccuracyGraphKnotCount;
	int iPositionReloadTransTime;
	float leftArc;
	float rightArc;
	float topArc;
	float bottomArc;
	float accuracy;
	float aiSpread;
	float playerSpread;
	float minTurnSpeed[2];
	float maxTurnSpeed[2];
	float pitchConvergenceTime;
	float yawConvergenceTime;
	float suppressTime;
	float maxRange;
	float fAnimHorRotateInc;
	float fPlayerPositionDist;
	const char *szUseHintString;
	const char *dropHintString;
	int iUseHintStringIndex;
	int dropHintStringIndex;
	float horizViewJitter;
	float vertViewJitter;
	float cameraShakeScale;
	int cameraShakeDuration;
	int cameraShakeRadius;
	float explosionCameraShakeScale;
	int explosionCameraShakeDuration;
	int explosionCameraSHakeRadius;
	const char *szScript;
	float destabilizationRateTime;
	float destabilizationCurvatureMax;
	int destabilizeDistance;
	float * locationDamageMultipliers;      //Refer to hitLocation_t
	const char *fireRumble;
	const char *meleeImpactRumble;
	const char *reloadRumble;
	const char *explosionRumble;
	int tracerType;
	int enemyTracerType;
	float adsDofStart;
	float adsDofEnd;
	float hipDofStart;
	float hipDofEnd;
	float scanSpeed;
	float scanAccel;
	int scanPauseTime;
	const char * flameTableFirstPerson;
	const char * flameTableThirdPerson;
	int firstPersonFlameTable;
	int thirdPersonFlameTable;
	int tagFx_preparationEffect;
	int tagFlash_preparationEffect;
	bool doGibbing;
	float maxGibDistance;
	float altScopeADSTransInTime;
	float altScopeADSTransOutTime;
	int iIntroFireTime;
	int iIntroFireLength;
	int meleeSwipeEffect;						//FxEffectDef
	int meleeImpactEffect;						//FxEffectDef
	int meleeImpactNoBloodEffect;
	const char *throwBackType;
	int camo;
	float customFloat[3];
	__declspec(align(4)) bool customBool0;
	__declspec(align(4)) bool customBool1;
	__declspec(align(4)) bool customBool2;
};
#pragma endregion


union DvarValue
{
	bool enabled;
	int integer;
	unsigned int unsignedInt;
	int64_t integer64;
	int64_t unsignedInt64;
	float value;
	float vectorv[4];
	const char *string;
	char color[4];
};

#pragma pack(push, 4)
struct dvar_t
{
	const char *name;
	const char *description;
	int hash;
	unsigned int flags;
	dvarType_t type;
	bool modified;
	DvarValue current;
	DvarValue latched;
	DvarValue reset;
	DvarLimits domain;
	dvar_t *hashNext;
	int unknown3;
};
#pragma pack(pop)


struct ScreenPlacement
{
	int64_t scaleVirtualToReal;
	int64_t scaleVirtualToFull;
	int64_t scaleRealToVirtual;
	int64_t virtualViewableMin;
	int64_t virtualViewableMax;
	int64_t virtualTweakableMin;
	int64_t virtualTweakableMax;
	int64_t realViewportBase;
	int64_t realViewportSize;
	int64_t realViewportMid;
	int64_t realViewableMin;
	int32_t realViewableMaxX;
	int32_t realViewableMaxY;
	int64_t realTweakableMin;
	int64_t realTweakableMax;
	int64_t subScreen;
	int hudSplitscreenScale;
};

#define GLOBAL_CGAME_PTR_ADDR		0xE22F18
#define GLOBAL_CLIENT_PTR_ADDR	0xD689D8

typedef struct
{
	int time;  // 0x00-0x04
	int buttons;  // 0x04-0x08
	int Buf8;   // 0x08-0x0C
	int viewAngles[3];  // 0x0C-0x18
	int weapon;   // 0x18-0x1C
	int offHandIndex; // 0x1C-0x20
	int Buf20;   // 0x20-0x24
	char fDir; // 0x24-0x25
	char rDir;  // 0x25-0x26
	char Buf[0x16];  // 0x26-0x3C
}usercmd_s;

typedef struct
{
	char padding00[0x44];          // 0x00
	bool ADS;       // 0x44
	char padding01[0xC3];    // 0x45
	Vector3 baseAngle;     // 0x108
	char padding02[0x2B80];    // 0x114
	Vector3 viewAngle;     // 0x2C94
	char padding03[0x40010];   // 0x2C9C
	usercmd_s UserCmd[128];    // 0x42CB0
	int CurrentCmdNumber;    // 0x44AB0
}ClientActive_t;

typedef struct
{
	int ClientNumber;			 //0x0
	char padding00[0x1C];		 //0x4
	int Servertime;				 //0x20
	char padding03828[0x168];	 //0x24
	int Stance;					 //0x18C
	char padding01[0x138];		 //0x190
	int Health;					 //0x2C8
	char padding02[0x27D0];		 //0x2CC
	int MaxEntities;			 //0x2A9C
	char padding03[0x45608];	 //0x2AA0
	Vector3 ViewAngle;			//0x482A0
	char padding05[0x55D4];		 //0x482AC
	float SpreadMultiplier;        //0x80B80
}cgArray_t;


typedef struct
{
	int x;						// 0x0
	int y;						// 0x4
	int Width;					// 0x8
	int Height;					// 0xC
	char padding000[0x14];		// 0x10
	float fovx;					// 0x24
	float fovy;					// 0x28
	float fovz;					// 0x2C
	char padding001[0x4];		// 0x30
	float fov;					// 0x34
	Vector3 viewOrigin;			// 0x38
	char padding002[0x4];		// 0x44
	Vector3 axis[3];			// 0x48
								// 0x6C
} RefDef;

typedef struct
{
	char padding000[0x2B4];		// 0x0
	int identifierThing;		// 0x2B4
								// 0x2B8
} WeaponInfoThing;


enum CommandMask
{
	CMD_MASK_FIRE = (1 << 31),
	CMD_MASK_AIM = (1 << 20),
};

struct vec3i {
	int x, y, z;
};

typedef struct
{
	int time;					// 0x0
	int buttons;				// 0x4
	char padding000[0x4];		// 0x8
	vec3i viewAngles;		    // 0xC
	char padding002[0xC];       // 0x18
	char forwardmove;           // 0x24
	char sidemove;             // 0x25
	char upmove;                // 0x26
	char padding003[0x1];       // 0x27
	char padding001[0x14];		// 0x28
								// 0x3C
} CCommand;

typedef struct
{
	CCommand commands[128];		// 0x0
	int currentIdx;				// 0x1E00
} CInput;

typedef struct
{
	char padding000[0x98];		// 0x0
	Vector3 origin;				// 0x98
	char padding001[0x64];		// 0xA4
	float refViewAngle[2];		// 0x108
	char padding002[0x2B84];	// 0x110
	float viewAngle[2];			// 0x2C94
	char padding003[0x40014];	// 0x2C9C
	CInput input;				// 0x42CB0
} Client;

enum entityType_t
{
	ET_General = 0,
	ET_Player = 1,
	ET_Corpse = 2,
	ET_Item = 3,
	ET_Missile = 4,
	ET_Invisible_entity = 5,
	ET_Scriptmover = 6,
	ET_Sound_blend = 7,
	ET_Fx = 8,
	ET_Loop_FX = 9,
	ET_Primary_Light = 10,
	ET_Turret = 11,
	ET_Helicopter = 12,
	ET_Plane = 13,
	ET_Vehicle = 14,
	ET_Vehicle_corpse = 15,
	ET_Actor = 16,
	ET_Actor_spawner = 17,
	ET_Actor_corpse = 18,
	ET_Streamer_Hint = 19,
};

typedef enum {
	ET_GENERAL = 0x0,
	ET_PLAYER = 0x1,
	ET_PLAYER_CORPSE = 0x2,
	ET_ITEM = 0x3,
	ET_MISSILE = 0x4,
	ET_INVISIBLE = 0x5,
	ET_SCRIPTMOVER = 0x6,
	ET_SOUND_BLEND = 0x7,
	ET_FX = 0x8,
	ET_LOOP_FX = 0x9,
	ET_PRIMARY_LIGHT = 0xA,
	ET_TURRET = 0xB,
	ET_HELICOPTER = 0xC,
	ET_PLANE = 0xD,
	ET_VEHICLE = 0xE,
	ET_VEHICLE_CORPSE = 0xF,
	ET_ACTOR = 0x10,
	ET_ACTOR_SPAWNER = 0x11,
	ET_ACTOR_CORPSE = 0x12,
	ET_STREAMER_HINT = 0x13,
	ET_ZBARRIER = 0x14,
	ET_EVENTS = 0x15,
} entityType_tt;

typedef struct
{
	char padding01[0x2C];         //0x0
	Vector3 Origin;                 //0x2C
	char padding02[0x11C];         //0x38
	int Flags;                     //0x154
	char padding938[0x10];        //0x158
	Vector3 NewOrigin;            //0x168
	char _0x0174[0x38];
	int AltType;                   //0x1AC
	int WeaponID;
	int OldWeapon;
	char padding03[0x18];         //0x1B0
	int ClientNumber;             //0x1D0
	char padding04[0x14];       //0x1D4
	Vector3 OldOrigin;            //0x1E8
	char _0x1F4[0xB4];
	short Type;                    //0x2A8
	char _0x02AA[0xC2];
	char State;                     //0x36C    
	char padding05[0x7];         //0x36D
								 //size 0x374
}Centity_ts, *pCentity_ts;

#define INT16 int16_t
#define INT32 int32_t
#define INT64 int64_t
#define UINT16 uint16_t
#define UINT32 uint32_t
#define UINT64 uint64_t

typedef struct
{
	short lightingHandle; //0x0000 
	unsigned char eType; //0x0002 
	unsigned char localClientNum; //0x0003 
	char _0x0004[40];
	Vector3 origin; //0x002C 
	char _0x0038[284];
	int eFlags; //0x0154 
	int eFlags2; //0x0158 
	unsigned char trType; //0x015C 
	char _0x015D[3];
	int trTime; //0x0160 
	int trDuration; //0x0164 
	Vector3 trBase; //0x0168 
	Vector3 trDelta; //0x0174 
	char _0x0180[36];
	float leanf; //0x01A4 
	int movementDir; //0x01A8 
	int movementType; //0x01AC 
	int primaryWeapon; //0x01B0 
	int stowedWeapon; //0x01B4 
	int offHandWeaponModel; //0x01B8   like Grenades
	int meleeWeapon; //0x01BC 
	unsigned char offhandeWeaponModel; //0x01C0 
	unsigned char meleeWeaponModel; //0x01C1 
	unsigned char vehicleType; //0x01C2 
	unsigned char vehicleAnimBoneIndex; //0x01C3 
	unsigned char vehicleSeat; //0x01C4 
	unsigned char stowedweaponCamo; //0x01C5 
	char _0x01C6[10];
	int clientNum; //0x01D0 
	int nextLerpeFlags; //0x01D4 
	int nextLerpeFlags1; //0x01D8 
	unsigned char nextLerptrType; //0x01DC 
	char _0x01DD[3];
	int nextlerptrtime; //0x01E0 
	int nextlerptrduration;        //0x01E4 
	Vector3 nextLerptrbase;        //0x01E8 
	Vector3 nextLerptrdelta;        //0x01F4 
	char _0x0200[168];
	short Type;                    //0x02A8 
	char _0x02Adc[0xA];
	int pickupId;                // 0x2B4
	char _0x02AA[0xB4];
	char State;                    //0x36C    
	char padding05[0x7];        //0x36D

}Centity_t, *pCentity_t;//Size = 0x0374

typedef struct
{
	INT16 lightingHandle; //0x0000 
	unsigned char eType; //0x0002 
	unsigned char localClientNum; //0x0003 
	char _0x0004[40];
	Vector3 Origin; //0x002C 
	char _0x0038[284];
	INT32 Flags; //0x0154 
	INT32 eFlags2; //0x0158 
	unsigned char trType; //0x015C 
	char _0x015D[3];
	INT32 trTime; //0x0160 
	INT32 trDuration; //0x0164 
	Vector3 NewOrigin; //0x0168 
	Vector3 trDelta; //0x0174 
	char _0x0180[36];
	float leanf; //0x01A4 
	INT32 movementDir; //0x01A8 
	INT32 movementType; //0x01AC 
	INT32 WeaponID; //0x01B0 
	INT32 OldWeapon; //0x01B4 
	INT32 offHandWeaponModel; //0x01B8 
	INT32 meleeWeapon; //0x01BC 
	unsigned char offhandeWeaponModel; //0x01C0 
	unsigned char meleeWeaponModel; //0x01C1 
	unsigned char vehicleType; //0x01C2 
	unsigned char vehicleAnimBoneIndex; //0x01C3 
	unsigned char vehicleSeat; //0x01C4 
	unsigned char stowedweaponCamo; //0x01C5 
	char _0x01C6[10];
	INT32 ClientNumber; //0x01D0 
	INT32 nextLerpeFlags; //0x01D4 
	INT32 nextLerpeFlags1; //0x01D8 
	unsigned char nextLerptrType; //0x01DC 
	char _0x01DD[3];
	INT32 nextlerptrtime; //0x01E0 
	INT32 nextlerptrduration; //0x01E4 
	Vector3 OldOrigin; //0x01E8 
	Vector3 nextLerptrdelta; //0x01F4 
	char _0x0200[90];
	bool Alive; //0x25A
	char _0x025B[77];
	INT16 Type; //0x02A8
	char _0x02AA[202];

}Centity_tdfa, *pCentity_tdfa;//Size = 0x0374

typedef struct
{
	char padding__[0x2B3]; //0-7
	int PickUPID;
	char padding___[0xC1];
}WeaponID;


#pragma region cg
typedef struct
{
	char padding00[0x8];   //0x8
	int Width;      //0x8
	int Height;      //0xC
	char padding01[0x14];   //0x10
	Vector3 Fov_v;     //0x24
	char padding02[0x4];   //0x30
	float Fov;      //0x34
	Vector3 ViewOrigin;    //0x38
	char padding03[0x4];   //0x44
	Vector3 ViewAxis[3];   //0x48
} refdef_s;// 0x6C

typedef struct
{
	int somethinghax;			 //0x0
	int somethinghax1;			 //0x4
	int null;					 //0x8
	char Name[0x20];		 //0xC
	int Team;					 //0x2C
	char padding01[0x5F];		 //0x30
	bool Dead;					 //0x8F
	char padding04[0x24];		 //
	char CurrentWeaponName[32];  //0xB4
	char paddin05[0x3F0];		 //D4
	Vector3 viewAngle;			 //0x4C4
	char _0x4D0[0xF4];
	int Weapon;					 //0x5C4
	char padding03[0x240];		 //0x5C8
								 //Size: 0x808
} clientinfo_s;

typedef struct
{
	int somethinghax;    //0x0
	int somethinghax1;    //0x4
	int anull;      //0x8
	char PlayerName[0x20];   //0xC
	int Team;      //0x2C
	char padding01[0x5F];   //0x30
	bool Dead;      //0x8F
	char padding02[0x60];   //0x90
	char PlayerModel[0x20];      //0xF0
	char padding03[0x4B7];
	char Weapon;     //0x5C7
	char padding04[0x240];   //0x5C8
							 //Size: 0x808
} clientinfo_ss;

typedef struct
{
	int szName; //0x0000 
	char _0x0004[108];
}shader_t;//Size=0x0070


typedef struct
{
	char _0x0000[940];
	shader_t *pShader; //0x03AC 
	char _0x03B0[12];
	shader_t *pShader2; //0x03BC 
}weapon2_t;//Size=0x03C0

typedef struct
{
	char _0x0000[12];
	char szName[32]; //0x000C 
	int iTeam; //0x002C 
	int iTeam2; //0x0030 
	char _0x0034[44];
	int iRank; //0x0060 
	char _0x0064[48];
	int iScore; //0x0094 
	char _0x0098[72];
	char szModel[64]; //0x00E0 
	char _0x0120[932];
	Vector3 ViewAngleY; //0x04C4 
	char _0x04D0[192];
	int N2399ED54; //0x0590 
	char _0x0594[48];
	int iWeaponID; //0x05C4 
	char _0x05C8[448];
	weapon2_t *pCurrentWeapon; //0x0788 
	char _0x078C[12];
	weapon2_t *pPrimaryWeapon; //0x0798 
	char _0x079C[108];
}client_t;//Size=0x0808

struct playerstate_s
{
	int time;     /// 0x00000
	char _000000000[0x1B4];  /// 0x00004
	int weapon;     /// 0x001B8
	char _000000001[0x3C];  /// 0x001BC
	Vector3 viewAngles;   /// 0x001F8
	char _00000001[0x55E4];  /// 0x00204
};
enum stance_t
{
	STANCE_STANDING = 0x0,
	STANCE_CROUCH = 0x4,
	STANCE_PRONE = 0x8,
};
struct cg_s22
{
	int clientNum;    /// 0x00000
	char padding00[0x1C];  /// 0x00004
	int serverTime;    /// 0x00020
	char _00000001[0x94];  /// 0x00024
	Vector3 origin;    /// 0x000B8
	char _00000002[0xC8];  /// 0x000C4
	stance_t stance;   /// 0x0018C
	char _00000003[0x4C];  /// 0x00190
	int maxEntities;   /// 0x001DC
	char _00000004[0x90];  /// 0x001E0
	float zoomProgress;   /// 0x00270
	char _00000005[0x54];  /// 0x00274
	int health;     /// 0x002C8
	char _0x000006[0x4];  /// 0x002CC
	int maxHealth;    /// 0x002D0
	char _00000007[0x98];  /// 0x002D4
	float weaponKickProgress; /// 0x0036C
	char _00000008[0x48038]; /// 0x00370
	playerstate_s playerstate; /// 0x483A8
	refdef_s refdef;   /// 0x4DB90
	char _00000009[0x1C1A4]; /// 0x4DBFC
	clientinfo_s clients[18]; /// 0x69DA0
	char _0000000A[0xE060];  /// 0x72E30
	float spreadMultiplier;  /// 0x80E90
};

struct cg_s
{
	int clientNum;    /// 0x00000
	char padding00[0x1C];  /// 0x00004
	int serverTime;    /// 0x00020
	char _00000001[0x94];  /// 0x00024
	Vector3 origin;    /// 0x000B8
	char _00000002[0xC8];  /// 0x000C4
	stance_t stance;   /// 0x0018C
	char _00000003[0x4C];  /// 0x00190
	int maxEntities;   /// 0x001DC
	char _00000004[0x90];  /// 0x001E0
	float zoomProgress;   /// 0x00270
	char _00000005[0x54];  /// 0x00274
	int health;     /// 0x002C8
	char _0x000006[0x4];  /// 0x002CC
	int maxHealth;    /// 0x002D0
	char _00000007[0x98];  /// 0x002D4
	float weaponKickProgress; /// 0x0036C
	char _00000008[0x48038]; /// 0x00370
	playerstate_s playerstate; /// 0x483A8
	refdef_s refdef;   /// 0x4DB90
	char _00000009[0x1C1A4]; /// 0x4DBFC
	clientinfo_ss clients[18]; /// 0x69DA0
	char _0000000A[0xE060];  /// 0x72E30
	float spreadMultiplier;  /// 0x80E90
};
typedef struct
{
	int localIndex;				// 0x0
	char padding000[0x244];		// 0x4
	int weaponData;				// 0x248
	char padding001[0x24];		// 0x24C
	float zoomAmount;			// 0x270
	char padding002[0x4832C];	// 0x274
	float refdefViewAngles[3];	// 0x485A0
	char padding003[0x2810];	// 0x485AC
	WeaponInfoThing weaponThing;// 0x4ADBC
	char padding004[0x2B1C];	// 0x4B074
	RefDef refdef;				// 0x4DB90
	char padding005[0x1C1A4];	// 0x4DBFC
	client_t clientInfosZ[16];	// 0x69DA0
	char padding006[0xF070];	// 0x71E20
	float spreadMult;			// 0x80E90
} cssgs;
struct cg_Test
{
	int clientNum;    /// 0x00000
	char padding00[0x1C];  /// 0x00004
	int serverTime;    /// 0x00020
	char _00000001[0x94];  /// 0x00024
	Vector3 origin;    /// 0x000B8
	char _00000002[0xC8];  /// 0x000C4
	stance_t stance;   /// 0x0018C
	char _00000003[0x4C];  /// 0x00190
	int maxEntities;   /// 0x001DC
	char _00000004[0x90];  /// 0x001E0
	float zoomProgress;   /// 0x00270
	char _00000005[0x54];  /// 0x00274
	int health;     /// 0x002C8
	char _0x000006[0x4];  /// 0x002CC
	int maxHealth;    /// 0x002D0
	char _00000007[0x98];  /// 0x002D4
	float weaponKickProgress; /// 0x0036C
	char _00000008[0x48038]; /// 0x00370
	playerstate_s playerstate; /// 0x483A8
	refdef_s refdef;   /// 0x4DB90
	char _00000009[0x1C1A4]; /// 0x4DBFC
	client_t pCli[18]; /// 0x69DA0
	char _0000000A[0xE060];  /// 0x72E30
	float spreadMultiplier;  /// 0x80E90
};
#pragma endregion

struct UiContext
{
	int x;    // 0x0000
	int y;    // 0x0004
	int frameTime;  // 0x0008
	int realTime;  // 0x000C
	char padding[0xC]; // 0x0010
	int width;   // 0x001C
	int height;   // 0x0020
	float aspect;  // 0x0024
	float fps;   // 0x0028
};
struct color
{
	float r, g, b, a;

	color() { r = g = b = a = 0.0; }
	color(float r, float g, float b, float a) { this->r = r / 255.0f, this->g = g / 255.0f, this->b = b / 255.0f, this->a = a / 255.0f; }
};

enum clientMigState_t
{
	CMSTATE_INACTIVE = 0x0,
	CMSTATE_OLDHOSTLEAVING = 0x1,
	CMSTATE_LIMBO = 0x2,
	CMSTATE_NEWHOSTCONNECT = 0x3,
	CMSTATE_COUNT = 0x4,
};

typedef struct
{
	clientMigState_t migrationState;
	char padding[0x10];
}ClientUIActive_t;

typedef struct pcg_s//
{
	unsigned char _0x0000[24];
	unsigned long iIngame; //0x0018 
	unsigned char _0x001C[104];
	unsigned long Ping; //0x0084 
	unsigned long iNewTime; //0x0088 
	unsigned long iTime; //0x008C 
	unsigned long iOldTime; //0x0090 
	unsigned char _0x0094[36];
	Vector3 vOrigin; //0x00B8 
	unsigned char _0x00C4[152];
	unsigned long iMoveType; //0x015C 
	unsigned char _0x0160[44];
	unsigned long iMoveFlag; //0x018C 
	unsigned char _0x0190[163];
	unsigned char ClientNumber; //0x0233 
	unsigned char _0x0234[20];
	unsigned long iWeaponID; //0x0248 
	unsigned char _0x024C[36];
	float flZoomProgress; //0x0270 
	unsigned char _0x0274[84];
	unsigned long Health; //0x02C8 
	unsigned char _0x02CC[4];
	unsigned long MaxHealth; //0x02D0 
	unsigned char _0x02D4[116];
	unsigned long iSecondaryWeaponID; //0x0348 
	unsigned char _0x034C[24];
	unsigned long iPrimaryWeaponID; //0x0364 
	unsigned char _0x0368[292];
	unsigned long iSecondaryAmmo; //0x048C 
	unsigned long iPrimaryAmmo; //0x0490 
	unsigned char _0x0494[52];
	unsigned long iSecondaryClip; //0x04C8 
	unsigned long iPrimaryClip; //0x04CC 
	unsigned char _0x04D0[880];
};//Size=0x01D4

#define __int32 int
#define __int16 short
#define __int64 long long

struct cgs_s
{
	/*int viewX;
	int viewY;
	int viewWidth;
	int viewHeight;
	float viewAspect;
	char _0000000[16];
	int serverCommandSequence;
	int processedSnapshotNum;
	int localServer;
	char gametype[32];
	char szHostName[256];
	int maxclients;
	char mapname[64];
	int gameEndTime;
	int voteTime;
	int voteYes;
	int voteNo;*/

	char _0x0000[8];
	__int32 screenX; //0x0008 
	__int32 screenY; //0x000C 
	char _0x0010[32];
	char gametype[4]; //0x0030
	char _0x0034[0x1C];
	char hostName[0x14]; //0x50
	char _0x0064[0xEC];
	int MaxClients; // 0x150
	char _0x0154[0x44];
	char mapName[0x18]; //0x198

};

struct PINGG
{
	int clientNum;    /// 0x00000
	char padding00[0x1C];  /// 0x00004
	int serverTime;    /// 0x00020
	char _00000001[0x60];  /// 0x00024
	int ping;
	char _000000011[0x30];
	Vector3 origin;    /// 0x000B8
	char _00000002[0xC8];  /// 0x000C4
	stance_t stance;   /// 0x0018C
	char _00000003[0x4C];  /// 0x00190
	int maxEntities;   /// 0x001DC
	char _00000004[0x90];  /// 0x001E0
	float zoomProgress;   /// 0x00270
	char _00000005[0x54];  /// 0x00274
	int health;     /// 0x002C8
	char _0x000006[0x4];  /// 0x002CC
	int maxHealth;    /// 0x002D0
	char _00000007[0x98];  /// 0x002D4
	float weaponKickProgress; /// 0x0036C
	char _00000008[0x48038]; /// 0x00370
	playerstate_s playerstate; /// 0x483A8f=
	refdef_s refdef;   /// 0x4DB90
	char _00000009[0x1C1A4]; /// 0x4DBFC
	clientinfo_s clients[18]; /// 0x69DA0
	char _0000000A[0xE060];  /// 0x72E30
	float spreadMultiplier;  /// 0x80E90
};


#pragma endregion

ScreenPlacement *ScrPlace_GetView(int localClient)
{
	Invoke<ScreenPlacement*>(0x15F080, localClient);
}

struct rectDef_s
{
	float x;
	float y;
	float w;
	float h;
	int horzAlign;
	int vertAlign;
};

struct compass_shit
{
	float compassNorthYaw;
	Vector2 compassNorth;
	int *compassMapMaterial;
	int *compassMapScrambledMaterial;
	Vector2 compassMapUpperLeft;
	Vector2 compassMapWorldSize;
};

struct Material
{
	const char * name;
};

struct WeaponVariantDef {

	char * name;
	int iVariantCount;
	WeaponDef *weapDef;
	const char *szDisplayName;
	const char *szAltWeaponName;
	const char *szAttachmentUnique;
	int **attachments;				//Count = 0x3F
	int **attachmentUniques;			//Count = 0x5F
	const char **szXAnims;					//Count = 0x58
	ScriptString(*hideTags)[0x20];
	int **attachViewModel;					//Count = 8
	int **attachWorldModel;					//Count = 8
	const char **attachViewModelTag;				//Count = 8
	const char **attachWorldModelTag;				//Count = 8
	Vector3 attachViewModelOffset[8];
	Vector3 attachWorldModelOffset[8];
	Vector3 attachViewModelRotation[8];
	Vector3 attachWorldModelRotation[8];
	Vector3 stowedModelOffsets;
	Vector3 stowedModelRotations;
	unsigned int altWeaponIndex;
	int iAttachments;
	bool bIgnoreAttachments;
	int iClipSize;
	int iReloadTime;
	int iReloadEmptyTime;
	int iReloadQuickTime;
	int iReloadQuickEmptyTime;
	int iAdsTransInTime;
	int iAdsTransOutTime;
	int iAltRaiseTime;
	const char *szAmmoDisplayName;
	const char *szAmmoName;
	int iAmmoIndex;
	const char *szClipName;
	int iClipIndex;
	float fAimAssistRangeAds;
	float fAdsSwayHorizScale;
	float fAdsSwayVertScale;
	float fAdsViewKickCenterSpeed;
	float fHipViewKickCenterSpeed;
	float fAdsZoomFov[3];
	float fAdsZoomInFrac;
	float fAdsZoomOutFrac;
	float fOverlayAlphaScale;
	float fOOPosAnimLength[2];
	bool bSilenced;
	bool bDualMag;
	bool bInfraRed;
	bool bTVGuided;
	unsigned int perks[2];
	bool bAntiQuickScope;
	Material *overlayMaterial;
	Material *overlayMaterialLowRes;
	Material *dpadIcon;
	weaponIconRatioType_t dpadIconRatio;
	bool noAmmoOnDpadIcon;
	bool mmsWeapon;
	bool mmsInScope;
	float mmsFOV;
	float mmsAspect;
	float mmsMaxDist;
	Vector3 ikLeftHandIdlePos;
	Vector3 ikLeftHandOffset;
	Vector3 ikLeftHandRotation;
	bool bUsingLeftHandProneIK;
	Vector3 ikLeftHandProneOffset;
	Vector3 ikLeftHandProneRotation;
	Vector3 ikLeftHandUiViewerOffset;
	Vector3 ikLeftHandUiViewerRotation;
};

enum team_t
{
	TEAM_FREE = 0x0,
	TEAM_BAD = 0x0,
	TEAM_ALLIES = 0x1,
	TEAM_AXIS = 0x2,
	TEAM_THREE = 0x3,
	TEAM_FOUR = 0x4,
	TEAM_FIVE = 0x5,
	TEAM_SIX = 0x6,
	TEAM_SEVEN = 0x7,
	TEAM_EIGHT = 0x8,
	TEAM_NUM_PLAYING_TEAMS = 0x9,
	TEAM_SPECTATOR = 0x9,
	TEAM_NUM_TEAMS = 0xA,
	TEAM_LOCALPLAYERS = 0xB,
	TEAM_FIRST_PLAYING_TEAM = 0x1,
	TEAM_LAST_PLAYING_TEAM = 0x8,
};

struct CompassHelicopter
{
	int entityNum;
	int lastUpdate;
	Vector2 lastPos;
	float lastYaw;
	team_t team;
	int ownerIndex;
};//DEA600

struct CompassTurrets
{
	int entityNum;
	int lastUpdate;
	int beginFadeTime;
	Vector2 lastPos;
	float lastYaw;
	team_t team;
	int ownerIndex;
	bool enemy;
	bool firing;
};


struct cpose_t
{
	unsigned __int16 lightingHandle;
	char eType;
	char eTypeUnion;
	char localClientNum;
	char isRagdoll;
	int ragdollHandle;
	int physObjId;
	int physUserBody;
	int killcamRagdollHandle;
	int physUserBodyProneFeet;
	char destructiblePose;
	int startBurnTime;
	float wetness;
	int cullIn;
	Vector3 origin;
	float angles[2];
	Vector3 absmin;
	Vector3 absmax;
	int skinCacheEntry;
	int ___u19;
	int constantSet;
};

/* 2499 */
struct trajectory_t
{
	char trType;
	int trTime;
	int trDuration;
	Vector3 trBase;
	Vector3 trDelta;
};

/* 2500 */
union $9B35D18BE7DE1A49784D3DA3953D5C89
{
	char iHeadIconTeam;
	__int16 teamAndOwnerIndex;
};

struct LerpEntityStateTurret
{
	Vector3 gunAngles;
	int ownerNum;
	float heatVal;
	int overheating;
	float pivotOffset;
	int flags;
};
struct LerpEntityStateLoopFx
{
	float cullDist;
	int period;
};
union $41090544F01B971CEA6978417397BD1B
{
	int actorNum;
	int corpseNum;
};

/* 1839 */
struct $0E2ADDF4FFAE096DF2EC3B0B4A5C12BC
{
	__int16 fBodyPitch;
};
struct LerpEntityStateActor
{
	$41090544F01B971CEA6978417397BD1B index;
	int species;
	int team;
	int enemy;
	int freeCameraLockOnAllowed;
	$0E2ADDF4FFAE096DF2EC3B0B4A5C12BC proneInfo;
	unsigned __int16 aiType;
};
struct LerpEntityStatePrimaryLight
{
	char colorAndExp[4];
	float intensity;
	float radius;
	float cosHalfFovOuter;
	float cosHalfFovInner;
	unsigned int mixerIndex;
};

/* 1786 */
struct $190F2CF944EC18EE3AF27F473C4F9DBE
{
	unsigned __int32 weaponIdx : 8;
	unsigned __int32 attachment1 : 6;
	unsigned __int32 attachment2 : 6;
	unsigned __int32 attachment3 : 6;
	unsigned __int32 padding : 6;
};

/* 1787 */
union Weapon
{
	$190F2CF944EC18EE3AF27F473C4F9DBE __s0;
	unsigned int weaponData;
};
struct LerpEntityStatePlayer
{
	float leanf;
	int movementDir;
	int moveType;
	Weapon primaryWeapon;
	Weapon stowedWeapon;
	Weapon offhandWeapon;
	Weapon meleeWeapon;
	char meleeWeaponCamo;
	char meleeWeaponModel;
	char vehicleType;
	char vehicleAnimBoneIndex;
	char vehicleSeat;
	char stowedWeaponCamo;
	char weaponHeat;
	char proneLegsAngle;
};
struct LerpEntityStateVehicleGunnerAngles
{
	__int16 pitch;
	__int16 yaw;
};
struct LerpEntityStateVehicleRotorArm
{
	__int16 pitch;
	__int16 roll;
};
union $7CBD316E680DA7A717A2D40CF13F48A6
{
	LerpEntityStateVehicleGunnerAngles gunnerAngles[4];
	LerpEntityStateVehicleRotorArm rotors[4];
};

/* 1704 */
union $ABF14481B6CB3C635AAEF83DF0F35947
{
	__int16 throttle;
	__int16 bodyPitch;
};
struct __declspec(align(2)) LerpEntityStateVehicle
{
	float steerYaw;
	float bodyRoll;
	$7CBD316E680DA7A717A2D40CF13F48A6 ___u2;
	$ABF14481B6CB3C635AAEF83DF0F35947 ___u3;
	__int16 gunPitch;
	__int16 gunYaw;
	char targetRotorSpeed;
};
struct LerpEntityStateMissile
{
	int launchTime;
	int parentClientNum;
	int fuseTime;
	int forcedDud;
	float autoDetonateTime;
};
struct LerpEntityStateScriptMover
{
	char attachTagIndex[4];
	int attachedTagIndex;
	__int16 attachModelIndex[4];
	__int16 animScriptedAnim;
	__int16 attachedEntNum;
	int attachedEntTime;
	__int16 exploderIndex;
	unsigned __int16 scale;
	char flags;
	unsigned __int16 aiType;
};
struct LerpEntityStateBulletHit
{
	Vector3 start;
};
struct LerpEntityStateEarthquake
{
	float scale;
	float radius;
	int duration;
};
struct LerpEntityStateCustomExplode
{
	int startTime;
	int effectIndex;
};

struct LerpEntityStateExplosion
{
	float innerRadius;
	float magnitude;
	float innerDamage;
	int dummy;
	float outerDamage;
};
struct LerpEntityStateExplosionJolt
{
	float innerRadius;
	Vector3 impulse;
};
struct LerpEntityStateJetThrust
{
	Vector3 thrustDir;
	int dummy;
	float dotLimit;
};
struct LerpEntityStatePhysicsJitter
{
	float innerRadius;
	float minDisplacement;
	float maxDisplacement;
};
struct LerpEntityStateDestructibleHit
{
	unsigned int modelState[3];
};
struct LerpEntityStateCreateDynEnt
{
	int model;
	int fxId;
	int mature;
};
struct LerpEntityStateStreamerHint
{
	float factor;
};
struct LerpEntityStateZBarrierPiece
{
	char flags;
	char animTime;
};
struct LerpEntityStateZBarrier
{
	unsigned int barrierTypeIndex;
	LerpEntityStateZBarrierPiece pieces[6];
};
struct LerpEntityStateAnonymous
{
	int data[9];
};







struct LerpEntityStateTypeUnion
{
	LerpEntityStateTurret turret;
	LerpEntityStateLoopFx loopFx;
	LerpEntityStateActor actor;
	LerpEntityStatePrimaryLight primaryLight;
	LerpEntityStatePlayer player;
	LerpEntityStateVehicle vehicle;
	LerpEntityStateMissile missile;
	LerpEntityStateScriptMover scriptMover;
	LerpEntityStateBulletHit bulletHit;
	LerpEntityStateEarthquake earthquake;
	LerpEntityStateCustomExplode customExplode;
	LerpEntityStateExplosion explosion;
	LerpEntityStateExplosionJolt explosionJolt;
	LerpEntityStateJetThrust jetThrust;
	LerpEntityStatePhysicsJitter physicsJitter;
	LerpEntityStateDestructibleHit destructibleHit;
	LerpEntityStateCreateDynEnt createDynEnt;
	LerpEntityStateStreamerHint streamerHint;
	LerpEntityStateZBarrier zbarrier;
	LerpEntityStateAnonymous anonymous;
};

struct LerpEntityState
{
	int eFlags;
	int eFlags2;
	trajectory_t pos;
	trajectory_t apos;
	LerpEntityStateTypeUnion u;
	__int16 useCount;
	$9B35D18BE7DE1A49784D3DA3953D5C89 faction;
	unsigned int clientFields;
};
union $8A55D3BB0C758A956A56F8E75035F352
{
	int hintString;
	int vehicleXModel;
	unsigned int secondBcAlias;
	unsigned int soundTag;
};
struct actorAnimState_t
{
	__int16 state;
	char subState;
	float fLeanAmount;
	float fAimUpDown;
	float fAimLeftRight;
};
struct playerAnimState_t
{
	int legsAnim;
	int torsoAnim;
	float fTorsoPitch;
	float fWaistPitch;
};
struct vehicleState_t
{
	__int16 flags;
	char vehicleDefIndex;
	char treeId;
	__int16 animId;
	__int16 attachModelIndex[2];
	char attachTagIndex[2];
};
struct hardlineHint_t
{
	char team;
	char perk;
	char hint;
};
struct scriptMoverState_t
{
	char fov;
	char treeId;
	__int16 animId;
};
struct fxLightingState_t
{
	float primaryLightFraction;
	int lightingOriginOffset;
};
union $0AB763B46362EB201C0633506E2BA78D
{
	actorAnimState_t animState;
	playerAnimState_t anim;
	vehicleState_t vehicleState;
	hardlineHint_t hardline;
	scriptMoverState_t moverState;
	fxLightingState_t fx;
};
struct renderOptions_s
{
	unsigned int s;
};
struct clientLinkInfo_t
{
	__int16 parentEnt;
	char tagIndex;
	char flags;
};
union $32A75A724673AB33BA2D603F67D50EA7
{
	__int16 brushmodel;
	__int16 xmodel;
	__int16 primaryLight;
	unsigned __int16 bone;
};
union $5941A7488DBCD59DA5C855EBC8EBAB48
{
	char scale;
	char eventParm2;
	char helicopterStage;
	char destructibleid;
	char zombieShrinkOn;
};
struct __declspec(align(2)) entityState_s
{
	int number;
	LerpEntityState lerp;
	int time2;
	unsigned int loopSoundId;
	int solid;
	renderOptions_s renderOptions;
	$0AB763B46362EB201C0633506E2BA78D un2;
	$8A55D3BB0C758A956A56F8E75035F352 un3;
	unsigned int partBits[5];
	clientLinkInfo_t clientLinkInfo;
	int clientMask[1];
	char events[4];
	unsigned int eventParms[4];
	unsigned int eventParm;
	__int16 eType;
	__int16 groundEntityNum;
	$32A75A724673AB33BA2D603F67D50EA7 index;
	__int16 otherEntityNum;
	__int16 attackerEntityNum;
	__int16 enemyModel;
	Weapon weapon;
	Weapon lastStandPrevWeapon;
	unsigned __int16 targetname;
	__int16 loopSoundFade;
	__int16 eventSequence;
	char surfType;
	char clientNum;
	char iHeadIcon;
	char weaponModel;
	$5941A7488DBCD59DA5C855EBC8EBAB48 un1;
};
struct centity_t
{
	cpose_t pose;
	LerpEntityState prevState;
	entityState_s nextState;
	short previousEventSequence;
	int miscTime;
	int lastMuzzleFlash;
	int numShotsFiredLast;
	unsigned short attachModelNames[2];
	unsigned short attachTagNames[2];
	int *tree;
	int *destructible;
	int *nitrousVeh;
	int *linkInfo;
	int *vehicle;
	int *clientTagCache;
	int *aimTargetInfo;
	int *cScriptMover;
	int *scripted;
	int *zbarrier;
	int *droppedWeaponDobjInfo;
	int nextSlideFX;
	unsigned short flagIndex;
	unsigned short flagState;
	int compassMaterial;
	int lastTrailTime;
	unsigned int fxTrailHandle;
	unsigned int fxProjExplosion;
	unsigned int fxHeartbeat;
	unsigned int fxLaserSight;
	Vector3 oldLinkOrigin;
	Vector3 originError;
	Vector3 anglesError;
	char tracerDrawRateCounter;
	centity_t *updateDelayedNext;
	unsigned short classname;
	unsigned int stepSound;
	char footstepSurfaceOverride;
	char deployedRiotshieldHits[8];
	union {
		unsigned int packed_bits[2];
		char bits[8];
		struct {
			int cState1;
			int cState2;
		};
	} pBits;
};
struct CompassVehicle
{
	int entityNum;
	int lastUpdate;
	Vector2 lastPos;
	float lastYaw;
	float turretYaw;
	team_t team;
	int ownerIndex;
};

struct CompassDogs
{
	int entityNum;
	int lastUpdate;
	Vector2 lastPos;
	float lastYaw;
	team_t team;
	int ownerIndex;
	bool enemy;
};

#define Centity_st ((centity_t**)(0xE22F20))
#define Centity_st1 ((centity_t*)(*(int*)(0xE22F20)))
#define Centity_st2 (*(centity_t**)(0xE22F20))
#define compassTurrent ((CompassTurrets*)(0xDE9220))
#define compassHeli ((CompassHelicopter*)(0xDEA600))
#define compassDog ((CompassDogs*)(0xDEB5E0))
#define compassVeh ((CompassVehicle*)(0xDE8E20))
#define cg (*(cg_s**)(0xE22F18))
#define compass_data ((compass_shit*)(*(int*)(0xE22F18) + 0x69B78))
#define cgss (*(cgs_s**)(0xE22F1C))
#define dc (*(UiContext*)(0x1C1DA90))
#define ClientActive_s (*(ClientActive_t**)(0xD689D8))
#define ClientUIActive_s (*(ClientUIActive_t**)(0xD689DC))
#define cgArray_s (*(cgArray_t**)(0xE22F18))
#define PING (*(PINGG**)(0xE22F18))
#define pcg (*(pcg_s**)(0xE22F18))
#define cgArray_ss (*(cgArray_t**)(0xE22F18))
#define pCentity_s (*(pCentity_t*)(0xE22F20))
#define cgCom (*(cg_s*)(0xE22F18))
#define cg1 (*(cg_s22**)(0xE22F18))
#define Centity (*(Centity_t**)(0xE22F20))//Centity_tdfa
#define Centity_s (*(Centity_ts**)(0xE22F20))
#define Centity_sAlive (*(Centity_tdfa**)(0xE22F20))
#define cgTest (*(cg_Test**)(0xE22F18))