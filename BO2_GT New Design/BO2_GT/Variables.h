#define ScrWidth dc.width
#define ScrHeight dc.height



typedef struct
{
	float r, g, b, a;
} Color;


Color tintColor_;
int cR[3];
int num[3];
Color tintColor(Color rgb)
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0) { cR[i] = rgb.r; }
		if (i == 1) { cR[i] = rgb.g; }
		if (i == 2) { cR[i] = rgb.b; }
		if (cR[i] > 50) { num[i] = 50; }
		else { num[i] = cR[i]; }
	}

	tintColor_.r = cR[0] - num[0];
	tintColor_.g = cR[1] - num[1];
	tintColor_.b = cR[2] - num[2];
	tintColor_.a = 1.0;
	return tintColor_;
}


Color White = { 1, 1, 1, 1 };
float Whites[4] = { 1,1,1,1 };
Color Black = { 0, 0, 0, 1 };
Color Red = { 1, 0, 0, 1 };
Color GreenC = { 0, 1, 0, 1 };
Color BlueC = { 0, 0, 1, 1 };
Color Orange = { 1, .27, 0, 1 };

Color GTBack = { 0, 0, 0, 0.6f };

Color mBackground = { 0.05, 0.05, 0.05, 0 };
Color mBackgrounda = { 0.05, 0.05, 0.05, 0 };
Color mOutline = { 0.12, 0.39, 0.82, 0 };//33, 100, 209
Color mOutlinea = { 0.08, 0.5, 0.7, 0 };
Color mText = { 1.0, 1.0, 1.0, 0 };
Color myText = { 0.95, 0.95, 0, 0 };


Color espBackground = { 0.05, 0.05, 0.05, 0 };
Color radarBackground = { 0.05, 0.05, 0.05, 0.8 };
Color radarOutline = { 0.12, 0.39, 0.82, 0.8 };

Color rBackground = { 0.05, 0.05, 0.05, 0 };
Color rOutline = { 0.12, 0.39, 0.82, 0 };
Color rText = { 0.95, 0.95, 0.95, 0 };
Color rTransparent = { 0,0,0,0 };

Color sBackground = { 0.05, 0.05, 0.05, 0 };
Color sOutline = { 0.12, 0.39, 0.82, 0 };
Color sText = { 0.95, 0.95, 0.95, 0 };
Color sTransparent = { 0,0,0,0 };

Color Rainbow;
Color Gradient1;
Color Smoke = { 1, 0, 0, 1 };
Color EvenOptions = { 0.1 , 0.1 , 0.1, 1.0f };
Color OddOptions = { 0.22 , 0.22 , 0.22, 1.0f };
Color Selector;
Color Gradient = { 1,0,0,1 };
Color TextOption = { 1 , 1 , 1, 1.0f };
Color ESPCrosshairCol = { 0.08, 0.5, 0.7, 0 };
bool DrawCrosshair;
int CrosshairSize = 20;

Color ESPEnemy = { 1, 0, 0, 1 };
Color ESPVisible = { 1, .27, 0, 1 };
Color ESPPrioritise = { .53, .25, .95, 1 };
Color ESPIgnore = { 1, 1, 1, 1 };
Color ESPTargeted = { 0.2, 0.6, 0.86, 1 };
Color ESPFriend = { 0.1, 1, 0.1, 1 };

Color LightBlack = { 0, 0, 0, 0.6f };

Color ComboBoxBG = { 0.2, 0.2, 0.2, 0.7 };
Color ComboBoxBGNoClick = { 0.3, 0.3, 0.3, 1.0f };
//{ 0.1 , 0.1 , 0.1, 1.0f };
Color RGBEditorCol;
float RGBr, RGBg, RGBb, RGBa;
int RGBscroll;
int TestScroll;

bool Flash = true;
bool Cross;

char* aimKey = "None";
char* aimType = "Regular";
char* targType = "Closest";
char* riotCheck = "Ignore";
char* SpoofedIP = "Spoofing Disabled";
char* ESPBoxT = "None";
char* ESPSnapT = "None";
char* xAntiAim = "None";
char* yAntiAim = "None";
char* CrossHair = "Disable";

char* aimKeys[] = { "None", "L1", "L2", "R1", "R2" };
char* aimTypes[] = { "Regular", "Silent" };
char* targetTypes[] = { "Closest", "Logical", "Visible Only" };
char* riotTypes[] = { "Regular", "Feet" };
char* IPs[] = { "Spoofing Disabled", "0.0.0.0", "1.3.3.7", "255.255.255.255" };
char* ESPBoxTs[] = { "None", "2D", "3D", "Triangle", "Corner" };
char* ESPSnapTs[] = { "None", "Top", "Middle", "Bottom" };
char* xAntiAims[] = { "None", "Emotion", "Down", "Up", "Invert on Shoot", "AimAngles" };
char* yAntiAims[] = { "None", "Jitter", "Spin Bot", "Shield", "Invert on Shoot", "Body to Enemy", "Shield to Enemy" };
char* Crosshairs[] = { "Disable", "+", "X" };

int xAntiAimType, yAntiAimType, spinSpeed = 10, spinAngle, LagAmount = 10;
bool ReverseDir, FakeLag;

int InParty;

bool IgnorePlayer[18], PrioritisePlayer[18];
bool PlayersMenuHasBeenSeled = false;
int playerscroll, pMaxScroll = 1;
bool* Thrid;

bool Loaded;
bool AutoBone;
bool MenuOpen = false;
bool PreGameMenuOpen = false;
bool RGBEditorOpen = false;
bool SubTest = false;
bool InGame;
bool SaveEditorBool = false;
bool TargetScan;

bool WallHacks;
bool EntityWAll;

int SubmenuScroll = 0;
int SubmenuScrdoll = 0;
int PreSubmenuScroll;
int subScrollSize = 15;
int PreScroll = 0;

int menuHeight = 0;
int MaxScroll = 0;
int scroll = 0;
int subScrolls = 0;

int Widths = 0;
int Heights = 0;

bool MenuHasBeenSeled = true;
bool PreGameMenuHasBeenSeled = true;
bool comboBoxOpen = false;
bool flashSmoke;
int comboScroll, maxComboScroll;

bool bEntityShader = false;

bool targetInfo;
bool Wallhack;
bool NoRecoil;
bool VSAT;
bool ThirdPerson;
int cg_fov = 65;
bool FlashName;
bool FlashPreGame;
bool ForceHost;
bool JoinParties;

bool Laser;
bool SteadyAim;

bool ZombieESP;
bool DistanceESP;
bool onESP;
bool PlayerESP;

bool AimbotEnabled;
bool AimingRequired;
bool noSway;
int AimingKey = 0;
bool sAimbot;
bool AntiAimEnabled;
int aimbotType;
bool noSpread;
bool Stealth;
bool Logical;
int nearestClient;
bool TeamCheck = true;
bool shootNow;
bool autowallEnabled;
bool autoShoot;
int LocalPlayer;
bool playerReady;
int ignoreShields = 0;
char* Tag = "j_head";
char* _Tag = "j_head";

bool MissileCheck;
bool ItemCheck;
bool PlaneCheck;
bool ActorCheck;

bool serverInfo;
bool EnemyESP, FriendESP, DrawName, DrawDistance, DrawSnapline, DrawBones, Radar, bCompass, DrawWeapon, bRank, vAngles;
bool RadarWeapons, RadarScavenger, RadarItems, RadarPlane, RadarTurrent, RadarDogs, RadarHeli;
int BoxType = 0;
int SnapType = 0;
bool bEntityLine;
bool bEntityBox;

bool Health;
bool HealthBARR;

int CrossType;

bool constRadar;

float fRadarDist = 20;
float fCompassSize = 100;

float LSD = 0;
int collum = 1;

char *tagList[] = { "j_head",
"j_neck",
"j_spine4",
"back_mid",
"back_low",
"torso_stabilizer",
"pelvis",
"j_mainroot",
"j_wrist_ri",
"j_wrist_le",
"j_elbow_ri",
"j_elbow_le",
"j_shoulder_ri",
"j_shoulder_le",
"j_ankle_ri",
"j_ankle_le",
"j_knee_ri",
"j_knee_le" };