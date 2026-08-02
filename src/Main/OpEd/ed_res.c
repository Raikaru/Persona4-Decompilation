#include "include_asm.h"
/* Persona 4 USA decompilation - ed_res.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

/* GP-owned work record shared with the adjacent opening/ending TU. */
extern u32 *D_007246AC;
#define sOpTailC D_007246AC

extern char D_0064F250[];
extern char D_0064F260[];

extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const void *msg, s32 id);
/* Defined below in this file; called at line 33, above its definition. */
extern void func_0038f8d0(void);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern s32 func_004553c0(u8 *ptr);
extern void *func_00455ea0(u32 resource, s32 index, s32 *size);
extern void func_00454bd0(u8 *ptr);
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_00271380(s32 slot, void *data);
extern void func_00271820(s32 slot);
extern u32 func_0038f400(const u32 *data);
extern void func_0038f590(u32 value);

// FUN_0038F620
void func_0038f620(void)
{
    if (sOpTailC == NULL) {
        func_0046d730(D_0064F250, 0x28);
    }
    if ((sOpTailC[1] & 1) != 0) {
        func_0038f8d0();
    }
    sOpTailC = NULL;
}

// FUN_0038F680
void func_0038f680(void)
{
    u32 *work;
    s32 size;
    s32 i;
    void *data;
    void *copy;

    if (sOpTailC == NULL) {
        func_0046d730(D_0064F250, 0x28);
    }
    work = sOpTailC;
    if ((work[0] & 1) != 0 && func_004553c0((u8 *)(uintptr_t)work[2]) != 0) {
        for (i = 0; i < 2; i++) {
            data = func_00455ea0((u32)(uintptr_t)work[2], i, &size);
            switch (i) {
            case 0:
                work[3] = (u32)func_0038f400((const u32 *)data);
                break;
            case 1:
                func_0044ea90(D_0064F250, 0x56);
                copy = (*jtbl_008873E8)(size, 0x40000);
                func_0043f810(copy, data, size);
                func_00271380(6, copy);
                break;
            }
        }
        work[1] |= 1;
        func_00454bd0((u8 *)(uintptr_t)work[2]);
        work[0] &= ~1u;
    }
}

// FUN_0038F7F0
void func_0038f7f0(void)
{
    u32 *work;

    if (sOpTailC == NULL) {
        func_0046d730(D_0064F250, 0x28);
    }
    work = sOpTailC;
    if ((~work[0] & 1) == 0) {
        func_0046d730(D_0064F250, 0x68);
    }
    work[2] = (u32)func_00454a60((u8 *)D_0064F260, 1);
    work[0] |= 1;
}

// FUN_0038F880
u32 func_0038f880(void)
{
    if (sOpTailC == NULL) {
        func_0046d730(D_0064F250, 0x28);
    }
    return sOpTailC[0] & 1;
}

// FUN_0038F8D0
void func_0038f8d0(void)
{
    u32 *work;

    if (sOpTailC == NULL) {
        func_0046d730(D_0064F250, 0x28);
    }
    work = sOpTailC;
    if ((work[1] & 1) == 0) {
        func_0046d730(D_0064F250, 0x84);
    }
    func_0038f590(work[3]);
    func_00271820(6);
}

// FUN_0038F950
u32 func_0038f950(void)
{
    if (sOpTailC == NULL) {
        func_0046d730(D_0064F250, 0x28);
    }
    return sOpTailC[3];
}
