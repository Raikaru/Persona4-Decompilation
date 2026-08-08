#include "include_asm.h"
/* Source unit: src/Kosaka/Field/k_fldFBN.c */
#include "type.h"

typedef struct FbnEntry
{
    s32 kind;      /* 0x00 */
    s32 field_4;   /* 0x04 */
    s32 field_8;   /* 0x08 */
    s32 field_C;   /* 0x0C */
    s32 field_10;  /* 0x10 */
    s32 field_14;  /* 0x14 */
    s32 field_18;  /* 0x18 */
} FbnEntry;

typedef struct FldPart
{
    u16 field_0;   /* 0x00 */
    u16 field_2;   /* 0x02 */
    u16 type;      /* 0x04 */
    u16 flags;     /* 0x06 */
    u16 field_8;   /* 0x08 */
    u8  field_A;   /* 0x0A */
    u8  field_B;   /* 0x0B */
    f32 field_C;   /* 0x0C */
    s32 field_10;  /* 0x10 */
    u8  pad14[0x3C];
    s32 field_50;  /* 0x50 */
    u8  pad54[0xC];
    u8  field_60;  /* 0x60 */
    u8  field_61;  /* 0x61 */
    u16 field_62;  /* 0x62 */
    u8  pad64[0xC];
    f32 field_70;  /* 0x70 */
} FldPart;

typedef struct AnimEntry
{
    u16 field_0;   /* 0x00 */
    u16 field_2;   /* 0x02 */
    u16 field_4;   /* 0x04 */
    u16 field_6;   /* 0x06 */
    s32 field_8;   /* 0x08 */
    s32 field_C;   /* 0x0C */
    s32 field_10;  /* 0x10 */
    s32 field_14;  /* 0x14 */
    s32 field_18;  /* 0x18 */
    s32 field_1C;  /* 0x1C */
} AnimEntry;

typedef struct AnimEntry2
{
    u16 field_0;   /* 0x00 */
    u8  pad[0x66];
    u16 field_68;  /* 0x68 */
    u16 field_6A;  /* 0x6A */
} AnimEntry2;

extern s32 func_0014eec0(void);
extern s32 func_001060b0(void);
extern s32 func_001060c0(void);
extern s8 func_00110960(s16 arg0, s32 arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_001453a0(s32 arg0);
extern s32 func_00145780(u16 arg0, u8 arg1, u32 arg2);
extern void func_0014aa80(s32 arg0);
extern void func_0014b0c0(s32 arg0, s32 arg1);
extern u8 *func_00145270(s32 arg0);
extern f32 func_0014b660(u8 *arg0);
extern f32 func_0014b5d0(u8 *arg0);
extern f32 func_0014b6f0(u8 *arg0);
extern void func_00146e60(s32 arg0, u8 *arg1, f32 *arg2);
extern void *func_0015ca30(void);
extern void *func_0015cbe0(s32 arg0);
extern void func_0015d100(FbnEntry *arg0, s32 arg1);
extern void *func_0015d1a0(s32 arg0);
extern void func_0015d270(FbnEntry *arg0);
extern s32 func_0015d2c0(s32 arg0);
extern void *func_0015d310(s32 arg0);
extern s32 func_00168780(s32 arg0, f32 arg1);
extern s32 func_0017b9a0(s32 arg0, f32 arg1);
extern s32 func_0018bb20(s32 arg0, void *arg1);
extern s32 func_003e05d0(void *arg0);
extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
extern void func_00442088(void *arg0, const char *arg1, u16 arg2, u16 arg3, s32 arg4);
extern void func_00442830(void *arg0, const char *arg1);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern void func_0044ea90(void *arg0, s32 arg1);
extern s32 func_00454570(void *arg0);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern void func_00454bd0(void *arg0);
extern s32 func_004553c0(u8 *arg0);
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern void func_0046d700(const char *arg0, s32 arg1, char *arg2, void *arg3);
extern u32 func_00477e80(s32 arg0, s32 arg1, const char *arg2, s32 arg3);
extern s32 func_00478140(u16 arg0, u16 arg1, s32 arg2);
extern s32 func_004782b0(u32 arg0);
extern void *func_00478750(s32 arg0);
extern void func_00478e70(void *arg0);
extern void func_0047a180(void *arg0, u8 *arg1, s32 arg2);
extern void func_0047a1a0(void *arg0, void *arg1, f32 arg2, s32 arg3);
extern void func_0047a1e0(void *arg0, void *arg1, s32 arg2);
extern void *func_0047a2f0(u32 arg0);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb2a8;
extern u32 *iGpffffb2a4;
extern FbnEntry *iGpffffb2a0;
extern s32 D_0076439C;
extern s32 D_00764340;
extern u32 D_00764388;
extern s32 D_0076436C;
extern char D_00762FD0;
extern char D_00762FD8;
extern char D_005F1068[];
extern char D_005F1078[];
extern char D_005F1090[];
extern char D_005F10B0[];
extern char D_005F10D0[];
extern u64 D_005F10E8[];
extern f32 D_005F10F0[];

/* measured floor (nd 1014): the parameter pair {arg0, arg1} is coloured
 * {s4, s3} where retail uses {s3, s4} (b210's pure-reverse param colouring vs
 * retail's forward-first-two), which cascades through every s3/s4 use, the
 * n/p/entry slot reuses, the kind==1 beqz/branch orientation, and the final
 * loop's address CSE. Retail also maintains a dead loop counter (j, s5) that
 * b210 eliminates (probed: an unused induction variable is DCE'd). */



// FUN_0015E870
u8 *func_0015e870(s32 arg0, s32 arg1, s16 arg2)
{
    char spC0[0x80];
    char sp40[0x80];

    iGpffffb2a8 = 0;
    iGpffffb2a4 = 0;
    iGpffffb2a0 = 0;
    if (func_0014eec0() == 0)
    {
        func_00442830(&spC0, D_005F1078);
        func_00442088(&sp40, D_005F1090, arg0 & 0xFFFF, arg1 & 0xFFFF, arg2);
        if (func_00454570(&sp40) == 0)
        {
            return NULL;
        }
        func_00440b68(&D_00762FD0, D_005F1068, 0xD4);
        return func_00454a60(&sp40, 0);
    }
    return (u8 *)1;
}


/* measured: archived faithful reconstruction had the residual recorded in
   the notes above; re-measured for nd_audit coverage.
   Committed at nd 1014. */
// FUN_0015E960
INCLUDE_ASM("asm/nonmatchings/k_fldFBN", func_0015e960);


/* measured: archived faithful reconstruction had the residual recorded in
   the notes above; re-measured for nd_audit coverage.
   Committed at nd 983. */
// FUN_0015F000
INCLUDE_ASM("asm/nonmatchings/k_fldFBN", func_0015f000);
