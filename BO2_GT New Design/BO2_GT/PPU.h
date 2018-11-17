void sleep(usecond_t time)
{
	sys_timer_usleep(time * 1000);
}

int32_t WriteProcess(uint64_t ea, const void * data, uint32_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), ea, size, (uint64_t)data);
	return_to_user_prog(int32_t);
}

int write_process1(void* destination, const void* source, size_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, size, (uint64_t)source);//dex only
	return_to_user_prog(int);
}

int console_write(const char * s)
{
	uint32_t len;
	system_call_4(403, 0, (uint64_t)s, 32, (uint64_t)&len);
	return_to_user_prog(int);
}

typedef void *PVOID;

int Memcpy(PVOID destination, const PVOID source, size_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, size, (uint64_t)source);
	__dcbst(destination);
	__sync();
	__isync();
	return_to_user_prog(int);
}

void xPatchInJump(int Address, int Destination, bool Linked) {

	// use this data to copy over the address
	int FuncBytes[4];

	// Get the actual destination address
	Destination = *(int *)Destination;

	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF); // lis     %r11, dest>>16
	if (Destination & 0x8000) // If bit 16 is 1
		FuncBytes[0] += 1;

	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF); // addi    %r11, %r11, dest&0xFFFF
	FuncBytes[2] = 0x7D6903A6; // mtctr    %r11

	FuncBytes[3] = 0x4E800420; // bctr

	if (Linked)
		FuncBytes[3] += 1; // bctrl

	Memcpy((void*)Address, FuncBytes, 4 * 4);
}

void HookFunctionStart(int Address, int saveStub, int Destination)
{
	saveStub = *(int*)saveStub;
	int BranchtoAddress = Address + (4 * 4);
	int StubData[8];
	StubData[0] = 0x3D600000 + ((BranchtoAddress >> 16) & 0xFFFF);
	if (BranchtoAddress & 0x8000) {
		StubData[0] += 1;
	}
	StubData[1] = 0x396B0000 + (BranchtoAddress & 0xFFFF);
	StubData[2] = 0x7D6903A6;
	Memcpy(&StubData[3], (void*)Address, 4 * 4);
	StubData[7] = 0x4E800420;
	Memcpy((void*)saveStub, StubData, 8 * 4);
	xPatchInJump(Address, Destination, false);
}

int tick;
int wait;
#define Sys_Milliseconds() Invoke<int>(0x465CE0)
void Wait(int timeout)
{
	tick = Sys_Milliseconds();
	wait = timeout;
}

#define KEYBOARD_MAX_LENGTH 256
namespace keyboard {
	wchar_t Title[KEYBOARD_MAX_LENGTH];
	wchar_t Preset[KEYBOARD_MAX_LENGTH];
	void GetWC(char *c, wchar_t *save) {
		int len = strlen(c);
		for (int i = 0; i < len; i++)
			save[i] = (wchar_t)c[i];
		save[len + 1] = (wchar_t)'\0';
	}
	void(*callbackFunction)(char *) = 0;
	char str[KEYBOARD_MAX_LENGTH + 1];
	void keyboardCallback(int LocalClientNum, const wchar_t * wString, int Length) {
		for (int i = 0; i < Length; i++) {
			str[i] = wString[i];
		}
		str[Length] = '\0';
		callbackFunction(str);
	}
	void OnScreenKeyboard(int LocalClientNum, wchar_t *Title, wchar_t *PresetMessage, int Length, void(*CompleteFunction)(int LocalClientNum, const wchar_t * wString, int Length), int PanelMode) {
		*(char*)0xD82144 = 1;
		Invoke<void>(0x46710C, LocalClientNum, Title, PresetMessage, Length, CompleteFunction, PanelMode);
	}
	void openKeyboard(void(*callbackFunc)(char *), int maxLength = KEYBOARD_MAX_LENGTH, char *title = "Enter Value", char *presetMessage = "") {
		callbackFunction = callbackFunc;
		GetWC(title, Title);
		GetWC(presetMessage, Preset);
		OnScreenKeyboard(0, Title, Preset, KEYBOARD_MAX_LENGTH, keyboardCallback, 1);
	}
}

int ReadInt(int address)
{
	return *(int*)address;
}

bool Dvar_GetBool(const char* dvarName) {
	return Invoke<bool>(0x3DA948, Invoke<void*>(0x3DA628, dvarName));
}

bool DvarGetBool(const char *dvarName)
{
	if (Dvar_GetBool(dvarName))
		return true;
	else
		return false;
}

int Dvar_FindVar(const char* dvarName) {
	return Invoke<int>(0x3DA628, dvarName);
}

const char *Dvar_GetString(const char *dvar) {
	int dvar_t = Dvar_FindVar(dvar);
	if (dvar_t == 0)
		return false;
	return (const char*)(*(int*)(dvar_t + 0x18));
}