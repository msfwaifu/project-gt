
enum buttons {
	X = 0x1000,
	Triangle = 0x8000,
	Square = 0x4000,
	Circle = 0x2000,
	DpadUp = 0x0001,
	DpadDown = 0x0002,
	DpadLeft = 0x0004,
	DpadRight = 0x0008,
	R1 = 0x0200,
	R2 = 0x0800,
	R3 = 0x0080,
	L1 = 0x0100,
	L2 = 0x0400,
	L3 = 0x0040,
	Start = 0x0010,
	Select = 0x0020
};

bool Key_IsDown(int button) {
	return *(short*)0x1EF77B2 & button;
}