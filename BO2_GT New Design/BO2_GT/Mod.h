void OpenRGBEditor(Color toEdit)
{
	RGBr = toEdit.r * 255;
	RGBg = toEdit.g * 255;
	RGBb = toEdit.b * 255;
	RGBa = toEdit.a * 255;

	RGBEditorCol = toEdit;

	MenuOpen = false;
	sleep(50);
	RGBEditorOpen = true;
}
void Rainyy(Color * rain)
{
	if (rain->a <= 0) rain->a = 0.8;
	if (rain->r <= 0 && rain->g <= 0 && rain->b <= 0)
		rain->r = 1.0;
	if (rain->r > 0 && rain->b <= 0.15 / 255.00f)
	{
		rain->r -= 2 / 255.00f;
		rain->g += 2 / 255.00f;
		rain->a = rain->a;
	}
	if (rain->g > 0 && rain->r <= 0.15 / 255.00f)
	{
		rain->g -= 2 / 255.00f;
		rain->b += 2 / 255.00f;
		rain->a = rain->a;
	}
	if (rain->b > 0 && rain->g <= 0.15 / 255.00f)
	{
		rain->r += 2 / 255.00f;
		rain->b -= 2 / 255.00f;
		rain->a = rain->a;
	}
}

void SubMenuTest()
{
	MenuOpen = false;
	sleep(50);
	SubTest = true;
}

template<typename R>
inline R ReadMemory(int Address, size_t Size)
{
	R _r = (R)_sys_malloc(Size);
	system_call_4(904, (int64_t)sys_process_getpid(), Address, Size, (uint64_t)_r);
	//return_to_user_prog(int);
	return _r;
}
inline int ReadMemory(int Address, const void * data, size_t Size)
{
	system_call_4(904, (int64_t)sys_process_getpid(), Address, Size, (uint64_t)data);
	return_to_user_prog(int);
}

static char GetMyIPBytes[0x4];
static char dump[0x00020000];
static bool IPOffsetFound = false;
static uint32_t IPSetOffset = 0;
static uint32_t FindIPSetAddress()
{
	if (IPOffsetFound == false)
	{
		ReadMemory(0x1A274E4, &dump, 0x00020000);
		ReadMemory(0x0FA9A2E, &GetMyIPBytes, 0x04);
		for (int i = 0; i < 0x00020000; i++)
		{
			if (dump[i] == 0x01 && dump[i + 1] == GetMyIPBytes[0] && dump[i + 2] == GetMyIPBytes[1] && dump[i + 3] == GetMyIPBytes[2] && dump[i + 4] == GetMyIPBytes[3])
			{
				IPOffsetFound = true;
				IPSetOffset = 0x1A274E4 + i + 1;
				return 0x1A274E4 + i;
			}
		}
		return IPSetOffset;
	}
	else
	{
		return IPSetOffset;
	}
}

bool *Reset;
void ChangeIP(int type)
{
	FindIPSetAddress();

	if (type == 0)
	{
		char SpoofIP[4] = { 0x01, 0x03, 0x03, 0x07 };
		WriteProcess(IPSetOffset, SpoofIP, 0x04);
	}
	else if (type == 1)
	{
		char SpoofIP[4] = { 0x00, 0x00, 0x00, 0x00 };
		WriteProcess(IPSetOffset, SpoofIP, 0x04);
	}
	else if (type == 2)
	{
		char SpoofIP[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
		WriteProcess(IPSetOffset, SpoofIP, 0x04);
	}
	else if (type == 3)
	{
		WriteProcess(IPSetOffset, GetMyIPBytes, 0x04);
	}
}

void ChangeNamePregame(char* newName)
{
	strcpy((char*)0x026C0658, newName);
	strcpy((char*)0x026C067F, newName);
}

void ChangeNamePreGameKeyboard()
{
	keyboard::openKeyboard(ChangeNamePregame, 255, "Set 32 Character Name", (char*)0x1F504DC);
}

bool LiveStats_SetClanTagText(int controllerIndex, char* clanTag)
{
	Invoke<bool>(0x5470D0, controllerIndex, clanTag);
}

void ChangeClanTagPreGame(char* str)
{
	LiveStats_SetClanTagText(0, str);
}

void ChangeClanTagPreGameKeyboard() {
	keyboard::openKeyboard(ChangeClanTagPreGame, 4, "Change Clan");
}

void Cbuf_AddText(char* command)
{
	Invoke<void>(0x313C18, 0, command);
}

void ChangeNameInGame(char* str)
{
	char playerClan[256];
	snprintf(playerClan, sizeof(playerClan), ";cmd userinfo \"\\name\\%s\\xuid\\%s", str, 0x26C06E8);
	Cbuf_AddText(playerClan);
}

void ChangeNameIngameKeyboard()
{
	keyboard::openKeyboard(ChangeNameInGame, 32, "Change Name In-Game");
}

dvar_t *__cdecl _Dvar_RegisterFloat(const char *dvarName, float value, float min, float max, unsigned int flags, const char *description)
{
	Invoke<dvar_t*>(0x3DD4C4, dvarName, value, min, max, flags, description);
}

void I_ChangeClan(const char* newClan)
{
	char playerClan[256];
	snprintf(playerClan, sizeof(playerClan), ";cmd userinfo \"\\clanAbbrev\\%s\\name\\%s\\xuid\\%s", newClan, cg->clients[cg->clientNum].PlayerName, 0x26C06E8);
	Cbuf_AddText(playerClan);
}

void AdvMenu(const char* Name, const char* Clan)
{
	char playerClan[256];
	snprintf(playerClan, sizeof(playerClan), ";cmd userinfo \"\\clanAbbrev\\%s\\name\\%s\\xuid\\%s", Clan, Name, 0x26C06E8);
	Cbuf_AddText(playerClan);
}