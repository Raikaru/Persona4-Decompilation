#include "include_asm.h"
#include "type.h"

/* Remaining CRI SRD/PS2EE 2.22 functions. Independently reconstructed
 * history/counters/filesystem live in src/cri/libadxe/cri_srd.c; control and
 * DVD read-status helpers live in src/cri/libadxe/cri_srd_control.c.
 * Names below follow the older CRI SRD function order and retail call graph. */


/* srd_exec_dvd: sceCdBreak and the 0x1600/0x1601 history pair. */
// FUN_004E3DC8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e3dc8);
/* srd_exec_hst: host seek/read state machine. */
// FUN_004E3FB0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e3fb0);

/* SRD_ExecServer: dispatches to srd_exec_dvd and srd_exec_hst. */
// FUN_004E4190
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4190);

/* SRD_WaitForExecServer: uses the retail 10-second timeout string. */
// FUN_004E42A0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e42a0);
/* SRD_GetReadStatusHost: host file read state and history codes. */
// FUN_004E4438
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4438);
/* SRD_GetReadStatus: selects DVD or host read status by device type. */
// FUN_004E44D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e44d8);
/* SRD_DebugPrint: prints the SRD Info and device-type diagnostics. */
// FUN_004E4528
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4528);

