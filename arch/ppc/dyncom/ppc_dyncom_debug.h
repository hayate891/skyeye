#ifndef __PPC_DYNCOM_DEBUG__
#define __PPC_DYNCOM_DEBUG__

#include <math.h>

#define START_DEBUG_ICOUNT -1 
extern int ppc_dyncom_start_debug_flag;

#define DEBUG_TAG					1
#define DEBUG_TRANSLATE				1 << 1
#define DEBUG_TRANSLATE_COND		0 << 2
#define DEBUG_DEC					0 << 3
#define DEBUG_INTERFACE				0 << 4
#define DEBUG_NOT_TEST				0 << 5
#define DEBUG_RUN					0 << 6

#define DEBUG_MASK				0xffffffff
//#define DEBUG_MASK				0x0

static char *debug_name[] = {"TAG",
	"TRANSLATE",
	"TRANSLATE_COND",
	"DEC",
	"INTERFACE",
	"NOTTEST",
	"RUN"};

#define debug(debug_flag, ...)												\
	do {																	\
		if ((debug_flag & DEBUG_MASK) && ppc_dyncom_start_debug_flag){		\
			printf("[PPC_DYNCOM_DEBUG-%s] ",								\
					debug_name[(int)log2(debug_flag)]);						\
			printf(__VA_ARGS__);											\
		}																	\
	} while(0)

#endif
