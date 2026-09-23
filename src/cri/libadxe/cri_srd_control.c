/* Persona 4 SRD/PS2EE 2.22 control and read-status routines, independently derived from
 * retail code at 0x004E4308..0x004E43F8. The older CRI 2.18a source at
 * https://github.com/crowded-street/3s-decomp/blob/main/src/anniversary/cri/libadxe/cri_srd.c
 * corroborates API order and names, not these bodies. Unlike its nonvolatile
 * locks, this build reads asynchronously updated flags and needs volatile
 * stores to reproduce the retail instructions; no external code was copied. */
#include "type.h"

extern void func_004e42a0(void); /* SRD_WaitForExecServer */
extern void func_004e4618(s32); /* SRD_SetHistory */
extern s32 func_0042e7c8(s32);
extern volatile s32 D_00731C40; /* srd_dvd_exec_locked */
extern volatile s32 D_00731C44; /* srd_hst_exec_locked */
extern volatile s32 D_00731C48; /* srd_geterror_locked */
extern volatile s32 D_00731C4C; /* srd_geterror_call */
extern s8 D_00731C02; /* srd_obj.stat */

/* SRD_LockedForDvdExec. */
// FUN_004E4308
void func_004e4308(s32 enabled) {
    func_004e42a0();
    D_00731C40 = (s8)enabled;
}
/* SRD_LockedForHstExec. */
// FUN_004E4340
void func_004e4340(s32 enabled) {
    func_004e42a0();
    D_00731C44 = (s8)enabled;
}
/* SRD_LockedForGetError. */
// FUN_004E4378
void func_004e4378(s32 enabled) {
    func_004e42a0();
    D_00731C48 = (s8)enabled;
}
/* SRD_CallForGetError. */
// FUN_004E43B0
void func_004e43b0(s32 enabled) {
    func_004e42a0();
    D_00731C4C = (s8)enabled;
}
/* SRD_SetError: srd_obj.stat = 9. */
// FUN_004E43E8
void func_004e43e8(void) { D_00731C02 = 9; }
/* SRD_GetReadStatusDvd. */
// FUN_004E43F8
s32 func_004e43f8(void) {
    s32 status;
    func_004e4618(0x2300);
    status = func_0042e7c8(1);
    func_004e4618(0x2301);
    return status;
}
