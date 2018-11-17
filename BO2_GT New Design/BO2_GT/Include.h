#include <cellstatus.h>
#include <sys/prx.h>
#include "Invoker.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <sys/prx.h>
#include <sys/syscall.h>
#include <sys/ppu_thread.h>
#include <sys/sys_time.h>
#include <sys/time_util.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/types.h>
#include <math.h>
#include <fastmath.h>
#include <cellstatus.h>
#include <sys/timer.h>
#include <cell/sysmodule.h>
#include <sys/random_number.h>
#include <ppu_intrinsics.h>
#include <spu_printf.h>
#include <ctype.h>
#include <limits.h>
#include <np.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netex/net.h>
#include <netex/errno.h>
#include <netex/libnetctl.h>
#include <netex/sockinfo.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/return_code.h>
#include <sysutil/sysutil_oskdialog.h>
#include <sysutil/sysutil_msgdialog.h>
#include <cell/pad.h>

#include "va.h"
#include "Buttons.h"
#include "Structs.h"
#include "Variables.h"
#include "PPU.h"
#include "NonhostUIFuncts.h"
#include "Mod.h"
#include "CallBacks.h"
#include "ESPHandle.h"
#include "AutoWall.h"
#include "Aimbot.h"
#include "ESP.h"
#include "MPFunctions.h"
//#include "ZMFunctions.h"
#include "Option.h"
#include "Monitor.h"
#include "AntiAim.h"
#include "NonhostUI.h"
//#include "ZMMenu.h"


SYS_MODULE_INFO(BO2_GT, 0, 1, 1);
SYS_MODULE_START(_BO2_GT_prx_entry);

SYS_LIB_DECLARE_WITH_STUB(LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME);
SYS_LIB_EXPORT(_BO2_GT_export_function, LIBNAME);

// An exported function is needed to generate the project's PRX stub export library
extern "C" int _BO2_GT_export_function(void)
{
	return CELL_OK;
}
