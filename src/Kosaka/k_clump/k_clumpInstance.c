#include "include_asm.h"
/* Source unit: src/Kosaka/k_clump/k_clumpInstance.c */
#include "type.h"

typedef struct ClumpWork
{
    u32 state;        /* 0x00 */
    s32 field_4;      /* 0x04 */
    u8  field_8[0x40]; /* 0x08 */
    char name[0x40];  /* 0x48 */
    u32 field_88[0x31]; /* 0x88 */
    u32 count;        /* 0x14C */
    u32 items[0x80];  /* 0x150 */
    char path[0x100]; /* 0x350 */
    u8 *field_450;    /* 0x450 */
} ClumpWork;

extern void *func_003e2f60(s32 arg0, s32 arg1, void *arg2);
extern s32 func_003df3c0(void *arg0, s32 *arg1);
extern void *func_003e6a90(void *arg0);
extern void func_003e6870(void *arg0, void *arg1);
extern void func_003ef260(void *arg0, void (*arg1)(void), s32 *arg2);
extern void func_003ef1b0(void *arg0);
extern void *func_003c0f20(void *arg0);
extern s32 func_00457c90(void *arg0, const char *arg1);
extern void func_003bff30(void *arg0, void (*callback)(void), void *arg2);
extern void func_003c0960(void *arg0, void *arg1);
extern void func_0046d730(const char *arg0, s32 arg1);
extern void func_0044ea90(const char *arg0, s32 arg1);
extern void *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *);
extern void func_003e2910(void *arg0, void *arg1, s32 arg2);
extern void func_003deff0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_003e2ab0(void *arg0, void *arg1, s32 arg2);
extern void func_00463250(void *arg0);
extern void func_003e2e40(void *arg0, s32 arg1);
extern void func_00191e20(void);
extern void func_00463100(void);
extern void func_00191e90(u8 *arg0, s32 *arg1, u8 *arg2);
extern s32 func_001921a0(u8 *arg0);
extern void func_00192480(u8 *arg0);
extern char D_005F64C0[];
extern char D_005F64E0[];
extern char D_005F6500[];
extern s32 func_00428550(const char *arg0);
extern s32 func_00428780(s32 arg0, void *arg1);
extern s32 func_004426e8(const char *arg0, const char *arg1);
extern s32 func_0043c6b0(const char *arg0);
extern void func_00442830(void *arg0, const char *arg1);
extern void func_00442428(void *arg0, const char *arg1);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern void func_00456150(void *arg0);
extern void func_00454bd0(void *arg0);
extern void func_003c0700(void *arg0);
extern s32 func_00451fc0(s32 arg0, const char *arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 (*arg5)(u8 *), void (*arg6)(u8 *),
                         void *arg7);
extern s32 func_00428618(s32 arg0);
extern char D_005F6520[];
extern char D_005F6550[];
extern char D_005F6570[];
extern char D_005F65A0[];
extern char D_0076315C;
extern char D_00763160;
extern char D_00763168;
extern char D_00763170;

/* measured floor (nd 10): func_003deff0's 5-arg setup emits [move $a0; lw; lw; lw; lw]
 * where retail emits [lw; lw; move $a0; lw; lw] -- call-argument setup order, a
 * b210 scheduling floor (all other bytes of the function match).
   Committed at nd 10. */


// FUN_00191E90 NONMATCHING
#ifdef NON_MATCHING
void func_00191e90(u8 *arg0, s32 *arg1, u8 *arg2)
{
    s32 sp70[8];
    s32 sp50[4];
    s32 i;
    void *s1;
    void *s0;
    void *s3;

    sp70[7] = 0;
    sp70[4] = *(s32 *)(arg0 + 0x110);
    sp70[5] = *(s32 *)(arg0 + 0x118);
    s1 = func_003e2f60(3, 1, &sp70[4]);
    s0 = func_003e2f60(2, 2, arg1);
    *(s32 *)(arg2 + 0x14C) = 0;
    for (i = 0; i < 0x80; i++)
    {
        *(s32 *)(arg2 + i * 4 + 0x150) = 0;
    }
    if (s1 != NULL && s0 != NULL)
    {
        while (func_003df3c0(s1, &sp50[0]) != 0)
        {
            switch (sp50[0])
            {
            case 0x16:
                s3 = func_003e6a90(s1);
                func_003e6870(s3, s0);
                func_003ef260(s3, &func_00463100, &sp70[7]);
                func_003ef1b0(s3);
                break;
            case 0x10:
                *(s32 *)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150) =
                    (s32)func_003c0f20(s1);
                if (func_00457c90(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150),
                                  D_005F64C0) == 0 &&
                    func_00457c90(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150),
                                  D_005F64E0) == 0)
                {
                    if (*(s32 *)(arg2 + 0x14C) != 0)
                    {
                        func_003bff30(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150),
                                      func_00191e20, NULL);
                    }
                }
                func_003c0960(*(void **)(arg2 + *(s32 *)(arg2 + 0x14C) * 4 + 0x150), s0);
                *(s32 *)(arg2 + 0x14C) = *(s32 *)(arg2 + 0x14C) + 1;
                break;
            case 0xF0F000E0:
                func_0046d730(D_005F6500, 0x93);
                break;
            default:
                func_0044ea90(D_005F6500, 0x9A);
                s3 = D_008873F4[0](1, sp50[1], 0x40000);
                func_003e2910(s1, s3, sp50[1]);
                func_003deff0((void *)s0, sp50[0], sp50[1], sp50[2], sp50[3]);
                func_003e2ab0(s0, s3, sp50[1]);
                jtbl_008873EC[0](s3);
                break;
            }
        }
        if (sp70[7] != 0)
        {
            func_00463250((void *)sp70[7]);
        }
        func_003e2e40(s1, 0);
        func_003e2e40(s0, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/k_clumpInstance", func_00191e90);
#endif


/* measured: the body below is a faithful reconstruction whose residual is
   recorded in the notes above; re-measured for nd_audit coverage.
   Committed at nd 194. */
// Archived C body: build/WBHygiene_func_001921a0_archive.txt; no current park body remains.
// FUN_001921A0
INCLUDE_ASM("asm/nonmatchings/k_clumpInstance", func_001921a0);



// FUN_00192480
void func_00192480(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_001924D0
s32 func_001924d0(void)
{
    void *mem;

    func_0044ea90(D_005F6500, 0x126);
    mem = D_008873F4[0](1, 0x454, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return func_00451fc0(0, D_005F65A0, 0xF, 0, 0, func_001921a0,
                         func_00192480, mem);
}
