#include "include_asm.h"
#include "type.h"

/* Remaining CRI SRD/PS2EE 2.22 functions. Independently reconstructed
 * history/counters/filesystem live in src/cri/libadxe/cri_srd.c; server
 * dispatch lives in cri_srd_exec.c; wait/control/status/diagnostics live
 * in cri_srd_control.c. Names below follow older CRI API order and retail calls. */


/* srd_exec_dvd: sceCdBreak and the 0x1600/0x1601 history pair. */
// FUN_004E3DC8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e3dc8);
/* srd_exec_hst: host seek/read state machine. */
// FUN_004E3FB0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e3fb0);


