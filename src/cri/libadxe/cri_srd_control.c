/* Persona 4 SRD/PS2EE 2.22 server wait, control, read-status and diagnostics,
 * independently derived from retail code at 0x004E42A0..0x004E4528.
 * The older CRI 2.18a source at
 * https://github.com/crowded-street/3s-decomp/blob/main/src/anniversary/cri/libadxe/cri_srd.c
 * corroborates API order and names, not these bodies. The wait counter and
 * lock stores need volatile access to reproduce retail code; no external
 * source bodies were copied. */
#include "type.h"

extern void func_004e4618(s32); /* SRD_SetHistory */
extern s32 func_0042e7c8(s32);
extern volatile s32 D_00731C40; /* srd_dvd_exec_locked */
extern volatile s32 D_00731C44; /* srd_hst_exec_locked */
extern volatile s32 D_00731C48; /* srd_geterror_locked */
extern volatile s32 D_00731C4C; /* srd_geterror_call */
extern s32 D_00731C3C; /* srd_enter_fg */
extern volatile u32 D_00731C50; /* srd_wait_svr_cnt */
extern const char D_0075ABC8[]; /* SRD server timeout message */
extern volatile s32 D_00731C54; /* srd_dvd_read_cnt */
extern const char D_0075ABF8[], D_0075AC08[], D_0075AC28[];
extern const char D_0075AC48[], D_0075AC68[], D_0075AC88[], D_0075ACA8[];
extern void func_004244c8(const char *, ...);
extern s8 D_00731C00[]; /* srd_obj */
extern s8 D_00731C01; /* srd_obj.devtype */
extern s8 D_00731C02; /* srd_obj.stat */
extern void func_004f0608(void), func_004f0620(void);
extern s32 func_004e48b0(s32, s32, s32 *);

/* Only the retail object fields read by status and diagnostics are named. */
typedef struct {
    s8 used, devtype, stat, pad;
    u8 rest[0x2c];
    s32 fd; /* +0x30 */
} SRD;

/* SRD_WaitForExecServer. */
// FUN_004E42A0
void func_004e42a0(void) {
    D_00731C50 = 0;
    while (D_00731C3C == 1) {
        if (++D_00731C50 > 0x19640000u) {
            func_004244c8(D_0075ABC8);
            break;
        }
    }
}

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

/* SRD_GetReadStatusHost. */
// FUN_004E4438
s32 func_004e4438(void) {
    s32 done;
    SRD *srd = (SRD *)D_00731C00;
    if (srd->stat == 2) {
        func_004f0608();
        func_004e4618(0x2400);
        if (func_004e48b0(srd->fd, 1, &done) < 0) {
            func_004e4618(0x2401);
        } else {
            func_004e4618(0x2402);
            if (done) {
                func_004f0620();
                return 1;
            }
        }
        func_004f0620();
    }
    return 0;
}

/* SRD_GetReadStatus. */
// FUN_004E44D8
s32 func_004e44d8(void) {
    s8 devtype = D_00731C01;
    if (devtype == 1) return func_004e43f8() * 2;
    if (devtype == 2) return func_004e4438();
    return 0;
}

/* SRD_DebugPrint. */
// FUN_004E4528
s32 func_004e4528(void) {
    SRD *srd;
    const char *fmt;
    func_004244c8(D_0075ABF8);
    func_004244c8(D_0075AC08, D_00731C3C);
    func_004244c8(D_0075AC28, D_00731C54);
    fmt = D_0075AC48;
    srd = (SRD *)D_00731C00;
    func_004244c8(fmt, srd->stat);
    if (srd->devtype == 1) func_004244c8(D_0075AC68);
    if (srd->devtype == 2) func_004244c8(D_0075AC88);
    func_004244c8(D_0075ACA8, func_004e44d8());
    return 0;
}
