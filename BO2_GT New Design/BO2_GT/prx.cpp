#define CColor (float*)&
#include "Include.h"



sys_ppu_thread_t ThreadModuleID;
sys_ppu_thread_t ButtonThread;

union $B7EE5DEE94244A362C0890E15CDB15ED
{
	int localTree;
	int tree;
};

struct DSkelPartBits
{
	int anim[5];
	int control[5];
	int skel[5];
};

struct DObjAnimMat
{
	vec4_t quat;
	Vector3 trans;
	float transWeight;
};

/* 2992 */
union $9C63AB98174C43F39B65F67424F26C70
{
	DObjAnimMat *mat;
	DObjAnimMat *localMat;
};

struct DSkel
{
	DSkelPartBits partBits;
	int timeStamp;
	$9C63AB98174C43F39B65F67424F26C70 ___u2;
};

struct XModel
{
	const char *name;
	char numBones;
	char numRootBones;
	char numsurfs;
	char lodRampType;
	int ___u5;
	int ___u6;
	int ___u7;
	int ___u8;
	char *partClassification;
	DObjAnimMat *baseMat;
	int *surfs;
	Material **materialHandles;
	int lodInfo[4];
	int *collSurfs;
	int numCollSurfs;
	int contents;
	int ___u17;
	float radius;
	Vector3 mins;
	Vector3 maxs;
	__int16 numLods;
	__int16 collLod;
	float *himipInvSqRadii;
	int memUsage;
	int flags;
	bool bad;
	int *physPreset;
	char numCollmaps;
	int *collmaps;
	int *physConstraints;
	Vector3 lightingOriginOffset;
	float lightingOriginRange;
};

union $F11C8BFDFE02B2810F7CA03A784F7193
{
	XModel **localModels;
	XModel **models;
};

struct DObj
{
	$B7EE5DEE94244A362C0890E15CDB15ED ___u0;
	unsigned __int16 duplicateParts;
	unsigned __int16 entnum;
	char duplicatePartsSize;
	char numModels;
	char numBones;
	unsigned int ignoreCollision;
	volatile int locked;
	DSkel skel;
	float radius;
	unsigned int hidePartBits[5];
	char localClientIndex;
	char flags;
	char numRootAdjustMats;
	char *ikState;
	$F11C8BFDFE02B2810F7CA03A784F7193 ___u15;
};


enum GfxRenderCommand
{
	RC_END_OF_LIST = 0x0,
	RC_SET_CUSTOM_CONSTANT = 0x1,
	RC_SET_MATERIAL_COLOR = 0x2,
	RC_SAVE_SCREEN = 0x3,
	RC_SAVE_SCREEN_SECTION = 0x4,
	RC_CLEAR_SCREEN = 0x5,
	RC_BEGIN_VIEW = 0x6,
	RC_SET_VIEWPORT = 0x7,
	RC_SET_SCISSOR = 0x8,
	RC_RESOLVE_COMPOSITE = 0x9,
	RC_PC_COPY_IMAGE_GEN_MIP = 0xA,
	RC_FIRST_NONCRITICAL = 0xB,
	RC_STRETCH_PIC = 0xB,
	RC_STRETCH_PIC_FLIP_ST = 0xC,
	RC_STRETCH_PIC_ROTATE_XY = 0xD,
	RC_STRETCH_PIC_ROTATE_ST = 0xE,
	RC_DRAW_QUAD_PIC = 0xF,
	RC_DRAW_FULL_SCREEN_COLORED_QUAD = 0x10,
	RC_DRAW_TEXT_2D = 0x11,
	RC_DRAW_TEXT_3D = 0x12,
	RC_BLEND_SAVED_SCREEN_BLURRED = 0x13,
	RC_BLEND_SAVED_SCREEN_FLASHED = 0x14,
	RC_DRAW_POINTS = 0x15,
	RC_DRAW_LINES = 0x16,
	RC_DRAW_UI_QUADS = 0x17,
	RC_DRAW_UI_QUADS_REPLACE_IMAGE = 0x18,
	RC_DRAW_TRIANGLES = 0x19,
	RC_DRAW_UI_TRIANGLES = 0x1A,
	RC_DRAW_QUADLIST_2D = 0x1B,
	RC_DRAW_EMBLEM_LAYER = 0x1C,
	RC_STRETCH_COMPOSITE = 0x1D,
	RC_PROJECTION_SET = 0x1E,
	RC_DRAW_FRAMED = 0x1F,
	RC_CONSTANT_SET = 0x20,
	RC_COUNT = 0x21,
};

struct ShaderConstantSet
{
	vec4_t value[7];
	char constantSource[7];
	char used;
};

GfxCmdHeader *__cdecl R_GetCommandBuffer(GfxRenderCommand renderCmd, int bytes)
{
	Invoke<GfxCmdHeader*>(0x769F6C, renderCmd, bytes);
}

void sR_AddDObjToScene(...)
{
	__asm("li %r3, 0x8;");
}
void CL_DrawStretchPic_Stub(...)
{
	__asm("li %r3, 0x10;");
}

bool R_MapShaderConstantSet(int scs, int index, const char* cN)
{
	Invoke<bool>(0x763DB8, scs, index, cN);
}

char R_MapShaderConstantValue(int something, int i, float* R, float* G, float* B, float* A)
{
	return;
}
//r_skyRotation 0x2B28908
unsigned long createRGB(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
void __cdecl R_AddDObjToScene(int obj, int pose, unsigned int entnum, unsigned int renderFxFlags, Vector3 *lightingOrigin, const float *materialTime, const float *burnFraction, int altXModel, int textureOverrideIndex, int dobjConstantSet, float lightingOriginToleranceSq, float scale, bool isMarkableViewmodel)
{
	if (WallHacks && entnum < 18)
	{
		renderFxFlags = -1;
	}
	else if (EntityWAll && entnum > 18)
	{
		renderFxFlags = -1;
	}
	else if(!WallHacks && !EntityWAll && entnum > 18)
	{
		renderFxFlags = 1;
	}

	lightingOriginToleranceSq = 1;
	
	char FixBlur[] = { 0x00 };
	WriteProcess(0x1CBF9F8, &FixBlur, sizeof(FixBlur));

	sR_AddDObjToScene(obj, pose, entnum, renderFxFlags, lightingOrigin, materialTime, burnFraction, altXModel, textureOverrideIndex, dobjConstantSet, lightingOriginToleranceSq, scale, isMarkableViewmodel);
}

void r_endFrame()
{
	R_GetCommandBuffer(RC_END_OF_LIST, 4);
	//2D85E84
//	char NOP[] = { 0x00 };
//	write_process(0x2D85E84, NOP, sizeof(NOP));
	sr_endFrame();
}

void CL_DrawStretchPic_Hook(int scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float *color, void *material) {
	const char * Shader = *(char**)material;
	float Colro[4] = { 0, 1, 0, color[3] };
	printf("Shader: %s\n", Shader);
	if (!strcmp(Shader, "mw2_main_cloud_overlay")) {
		color = Colro;
		printf("CL_GOOKE");
	}

	CL_DrawStretchPic_Stub(scrPlace, x, y, w, h, horzAlign, vertAlign, color, material);
}

void GT()
{
	char NOP[] = { 0x60, 0x00, 0x00, 0x00 };
	//if (Invoke<bool>(0x0319ECC, SESSIONMODE_ZOMBIES))
	//{
	//	printf("GT Zombies Hooked");
	//	//HookFunctionStart(0x3971A0, (int)ZMsMenuPaint_All, (int)ZMMenuPaint_All);
	//	//HookFunctionStart(0x116524, (int)ZMsProxyFuncs, (int)ZMProxyFuncs);
	//	//HookFunctionStart(0x103024, (int)ZMsCL_SendCmd, (int)ZMCL_SendCmd);
	//	//	xPatchInJump(0x42FC8, (int)ZMESPHook, false);
	//	write_process(0x46306C, NOP, 4);//hang detect patcher
	//	sys_ppu_thread_create(&ButtonThread, MenuTZM, 0, 0x4AA, 0x7000, 0, "Apollo");
	//}
	//else
	//{

		HookFunctionStart(0x3971A0, (int)sMenuPaint_All, (int)MenuPaint_All);
		HookFunctionStart(0x000, (int)sR_AddDObjToScene, (int)R_AddDObjToScene);
		HookFunctionStart(0x116524, (int)sProxyFuncs, (int)ProxyFuncs); 
		HookFunctionStart(0x103024, (int)sCL_SendCmd, (int)CL_SendCmd);
//		HookFunctionStart(0x35EDA0, (int)CL_DrawStretchPic_Stub, (int)CL_DrawStretchPic_Hook);
		//HookFunctionStart(R_ENDFRAME, (int)sr_endFrame, (int)r_endFrame);
		xPatchInJump(0x42FC8, (int)ESPHook, false);
		write_process(0x46306C, NOP, 4);//hang detect patcher
		sys_ppu_thread_create(&ButtonThread, MenuT, 0, 0x4AA, 0x7000, 0, "GT");
//}

	//Disables + Misc Functions
//	char disableProbation[] = { 0x42, 0x80 };
	//WriteProcess(0x53FC6C, &disableProbation, sizeof(disableProbation));

	char Nop[] = { 0x60, 0x00, 0x00, 0x00 };
	WriteProcess(0x52DFC0, &Nop, sizeof(Nop)); //32 Name Changer

}

void my_dialog2(int button, void *userdata)
{
	switch (button) {
	case CELL_MSGDIALOG_BUTTON_OK:

	case CELL_MSGDIALOG_BUTTON_NONE:

	case CELL_MSGDIALOG_BUTTON_ESCAPE:
		break;
	default:
		break;
	}
}

void BeginLoad() {
	cellMsgDialogOpen(1, "Welcome to Project GT v3 Private Beta\n\nCredits\nMrReekoFTWxD\nKiwi_Modz\nDevOps\nE7ite\nItz-GodModz\nUnholyTalonTSi\nPassive\nSoul", my_dialog2, (void*)0x0000aaab, NULL);
	GT();
}

void Thread(uint64_t nothing) {
	sleep(10000);
	BeginLoad();
	sys_ppu_thread_exit(nothing);
}

extern "C" int _BO2_GT_prx_entry(void)
{
	sys_ppu_thread_create(&ThreadModuleID, Thread, 0, 0x4AA, 0x7000, 0, "GT Hook");
    return SYS_PRX_RESIDENT;
}
