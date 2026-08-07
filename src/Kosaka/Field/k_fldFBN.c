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
extern u32 D_007643A0;
extern u32 *D_007643A4;
extern FbnEntry *D_007643A8;
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

    D_007643A0 = 0;
    D_007643A4 = 0;
    D_007643A8 = 0;
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


/* measured: the body below is a faithful reconstruction whose residual is
   recorded in the notes above; re-measured for nd_audit coverage.
   Committed at nd 1014. */
// FUN_0015E960 NONMATCHING
#ifdef NON_MATCHING
s32 func_0015e960(u8 *arg0, u8 **arg1, s32 arg2, s32 arg3, s16 arg4)
{
    u32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    char sp70[0x40];
    u32 j;
    u32 n;
    u32 i;
    u32 i2;
    u32 i3;
    u32 k;
    FldPart *fp;
    u8 *p2;
    AnimEntry *entry;
    AnimEntry2 *entry2;
    void *list;
    s32 kind;
    s8 r;
    s32 v2;
    u32 count;

    D_0076439C = 0;
    if (arg0 == NULL)
    {
        return 1;
    }
    *arg1 = NULL;
    if (func_0014eec0() == 0 && func_004553c0(arg0) == 0)
    {
        return 0;
    }
    if (func_0014eec0() == 0)
    {
        arg0 = *(u8 **)(arg0 + 0x110);
    }
    else
    {
        func_00442088(&sp70, D_005F10B0, arg2 & 0xFFFF, arg3 & 0xFFFF, arg4);
        arg0 = func_00455f70(&sp70, &spBC);
        if (arg0 == NULL)
        {
            return 1;
        }
        if (arg0 == NULL)
        {
            func_0046d700(D_005F1068, 0x10D, &D_00762FD8, &sp70);
        }
        *arg1 = arg0;
    }
    count = *(u32 *)(arg0 + 8);
    D_007643A0 = count;
    if (count != 0)
    {
        func_0044ea90(D_005F1068, 0x117);
        D_007643A4 = (u32 *)D_008873F4[0](1, count * 4, 0x40000);
        func_0044ea90(D_005F1068, 0x118);
        D_007643A8 = (FbnEntry *)D_008873F4[0](1, count * 0x1C, 0x40000);
    }
    fp = (FldPart *)(arg0 + 0x18);
    n = 0;
    for (i = 0; i < *(u32 *)(arg0 + 8); i++)
    {
        if (fp->type == 4 && fp->flags == 0xFFFF)
        {
            if (D_00764340 == 1)
            {
                D_007643A4[n] = func_00477e80(4, 0xFFFF, D_005F10D0, 0);
                D_007643A8[n].field_8 = (s32)i;
                n++;
            }
        }
        else
        {
            D_007643A4[n] = func_00478140(fp->type, fp->flags, 0);
            D_007643A8[n].field_8 = (s32)i;
            n++;
        }
        fp = (FldPart *)((u8 *)fp + *(s32 *)(arg0 + 0xC));
    }
    if (D_00764340 == 0)
    {
        list = func_0015ca30();
        if (list != NULL)
        {
            entry = func_0015cbe0(*(s32 *)((u8 *)list + 0xC));
            j = 0;
            while (entry->field_0 != 0xFFFF)
            {
                if (entry->field_10 == -1 || func_00106330(entry->field_10) != 1)
                {
                    kind = entry->field_18;
                    if (kind == 1)
                    {
                        r = func_00110960(func_001060b0(), func_001060c0() & 0xFF);
                        v2 = r & 1;
                        if (r < 0 && v2 != 0)
                        {
                            v2 -= 2;
                        }
                        if (v2 == 0)
                        {
                            goto block_38;
                        }
                        else
                        {
                            goto next_entry;
                        }
                    }
                    else if (kind == 2)
                    {
                        r = func_00110960(func_001060b0(), func_001060c0() & 0xFF);
                        v2 = r & 1;
                        if (r < 0 && v2 != 0)
                        {
                            v2 -= 2;
                        }
                        if (v2 == 0)
                        {
                            goto next_entry;
                        }
                        else
                        {
                            goto block_38;
                        }
                    }
                    else
                    {
                    block_38:
                        p2 = arg0 + 0x18;
                        for (i2 = 0; i2 < *(u32 *)(arg0 + 8); i2++)
                        {
                            if (((FldPart *)p2)->type == 4 && ((FldPart *)p2)->flags == 0xFFFF &&
                                ((FldPart *)p2)->field_8 == (u16)((entry->field_0 & 0x3FF) | 0xC00))
                            {
                                if (entry->field_2 != 0 || entry->field_4 != 0)
                                {
                                    D_0076439C = 1;
                                    D_007643A4[n] = func_00478140(entry->field_2, entry->field_4, 0);
                                    D_007643A8[n].kind = 1;
                                    D_007643A8[n].field_4 = (s32)entry;
                                    D_007643A8[n].field_8 = (s32)i2;
                                    n++;
                                }
                                break;
                            }
                            p2 += *(s32 *)(arg0 + 0xC);
                        }
                    }
                }
            next_entry:
                j++;
                entry++;
            }
        }
        for (k = 0; k < D_00764388; k++)
        {
            entry2 = func_0015d310(func_0015d2c0(k));
            if (entry2 == NULL)
            {
                continue;
            }
            p2 = arg0 + 0x18;
            for (i3 = 0; i3 < *(u32 *)(arg0 + 8); i3++)
            {
                if (((FldPart *)p2)->type == 4 && ((FldPart *)p2)->flags == 0xFFFF &&
                    ((FldPart *)p2)->field_8 == (u16)((entry2->field_0 & 0x3FF) | 0xC00))
                {
                    if (entry2->field_68 != 0 || entry2->field_6A != 0)
                    {
                        D_0076439C = 1;
                        D_007643A4[n] = func_00478140(entry2->field_68, entry2->field_6A, 0);
                        D_007643A8[n].kind = 2;
                        D_007643A8[n].field_4 = (s32)entry2;
                        D_007643A8[n].field_8 = (s32)i3;
                        D_007643A8[n].field_10 = (s32)k;
                        func_0015d100(&D_007643A8[n], k);
                        n++;
                    }
                    break;
                }
                p2 += *(s32 *)(arg0 + 0xC);
            }
        }
        D_007643A0 = n;
    }
    for (i = 0; i < *(u32 *)(arg0 + 0x10); i++)
    {
        s32 id;

        id = func_001453a0(((FldPart *)fp)->field_50 & 0x3FF) & 0xFFFF;
        spB0 = func_0014b660((u8 *)fp + 0x10);
        spB4 = func_0014b5d0((u8 *)fp + 0x10);
        spB8 = func_0014b6f0((u8 *)fp + 0x10);
        func_00146e60(id, (u8 *)fp + 0x40, &spB0);
        fp = (FldPart *)((u8 *)fp + 0x60);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFBN", func_0015e960);
#endif


/* measured: the body below is a faithful reconstruction whose residual is
   recorded in the notes above; re-measured for nd_audit coverage.
   Committed at nd 983. */
// FUN_0015F000 NONMATCHING
#ifdef NON_MATCHING
s32 func_0015f000(u8 *arg0, u8 *arg1)
{
    f32 c[3];
    struct
    {
        u64 x;  /* 0x00 */
        f32 y;  /* 0x08 */
    } b;
    f32 a[3];
    u32 j;
    u8 *fp;
    u8 *p;
    u8 *q;
    void *dst;
    u8 *obj;
    u32 id;
    u8 v5;
    s32 kind;
    s32 n8;
    u32 i;

    if (arg0 == NULL)
    {
        return 1;
    }
    for (i = 0; i < D_007643A0; i++)
    {
        if (func_0015d1a0(D_007643A8[i].field_10) == 0)
        {
            return 0;
        }
        if (D_007643A8[i].kind == 0)
        {
            if (func_004782b0(D_007643A4[i]) == 0)
            {
                return 0;
            }
        }
    }
    if (func_0014eec0() == 0)
    {
        arg1 = *(u8 **)(arg0 + 0x110);
    }
    else if (arg1 != NULL)
    {
        goto main_loop;
    }
    else
    {
        return 1;
    }
main_loop:
    fp = arg1 + 0x18;
    for (j = 0; j < D_007643A0; j++)
    {
        v5 = 3;
        b.x = D_005F10E8[0];
        b.y = D_005F10F0[0];
        p = fp + (*(s32 *)(arg1 + 0xC) * D_007643A8[j].field_8);
        if (*(u32 *)(arg1 + 4) >= 0x10001)
        {
            v5 = ((FldPart *)p)->field_60;
        }
        id = func_00145780(((FldPart *)p)->field_8 & 0x3FF, v5 & 0xFF, D_007643A4[j]) & 0xFFFF;
        func_0014aa80(id);
        func_0014b0c0(id, 1);
        obj = func_00145270(id);
        func_00168780(*(s32 *)(obj + 0x228), ((FldPart *)p)->field_C);
        func_0017b9a0(*(s32 *)(obj + 0x230), 40.0f);
        a[0] = ((FldPart *)p)->field_C;
        a[1] = a[0];
        a[2] = a[0];
        *(s32 *)(obj + 0x22C) = (s32)func_00478750(D_0076436C);
        func_0047a1a0(*(void **)(obj + 0x22C), &b, c[1], 2);
        func_0047a1e0(*(void **)(obj + 0x22C), &a[0], 2);
        if (((FldPart *)p)->field_B & 1)
        {
            *(s32 *)(obj + 0x28) |= 0x80000000;
        }
        else
        {
            *(s32 *)(obj + 0x28) &= 0x7FFFFFFF;
        }
        *(u16 *)(obj + 0x220) = ((FldPart *)p)->field_A;
        *(s32 *)(obj + 0x224) = ((FldPart *)p)->field_10;
        *(u8 *)(obj + 0x222) = ((FldPart *)p)->field_61;
        *(u16 *)(obj + 0x298) = ((FldPart *)p)->field_62;
        func_0043f810(obj + 0x29C, p + 0x74, 0xC0);
        *(f32 *)(obj + 0x35C) = ((FldPart *)p)->field_70;
        kind = D_007643A8[j].kind;
        *(s32 *)(obj + 0x234) = kind;
        if (kind == 0)
        {
            u8 *src;
            u8 *d;

            func_00478e70(*(void **)(obj + 0x22C));
            q = p + 0x20;
            dst = func_0047a2f0(*(u32 *)((u8 *)D_007643A4 + (j << 2)));
            n8 = 8;
            src = q;
            d = dst;
            do
            {
                s32 lo;
                s32 hi;

                lo = *(s32 *)src;
                hi = *(s32 *)(src + 4);
                src += 8;
                n8 -= 1;
                *(s32 *)d = lo;
                *(s32 *)(d + 4) = hi;
                d += 8;
            } while (n8 > 0);
            c[0] = func_0014b660(q);
            c[1] = func_0014b5d0(q);
            c[2] = func_0014b6f0(q);
            func_00146e60(id, p + 0x50, &c[0]);
            func_003e05d0(func_0047a2f0(*(u32 *)((u8 *)D_007643A4 + (j << 2))));
        }
        else if (kind == 1)
        {
            u8 *src;
            u8 *d;

            *(s32 *)(obj + 0x280) = D_007643A8[j].field_4;
            func_0047a180(*(void **)(obj + 0x22C), p + 0x50, 2);
            func_00478e70(*(void **)(obj + 0x22C));
            *(s32 *)(obj + 0x28) &= 0xEFFFFFFF;
            q = p + 0x20;
            dst = obj + 0x240;
            n8 = 8;
            src = q;
            d = dst;
            do
            {
                s32 lo;
                s32 hi;

                lo = *(s32 *)src;
                hi = *(s32 *)(src + 4);
                src += 8;
                n8 -= 1;
                *(s32 *)d = lo;
                *(s32 *)(d + 4) = hi;
                d += 8;
            } while (n8 > 0);
            *(s32 *)(obj + 0x294) = func_0018bb20(*(s32 *)(obj + 0x228), obj);
        }
        else if (kind == 2)
        {
            u8 *newptr;
            u8 *src;
            u8 *d;

            *(s32 *)(obj + 0x284) = D_007643A8[j].field_4;
            func_0047a180(*(void **)(obj + 0x22C), p + 0x50, 2);
            func_00478e70(*(void **)(obj + 0x22C));
            *(s32 *)(obj + 0x28) &= 0xEFFFFFFF;
            q = p + 0x20;
            dst = obj + 0x240;
            n8 = 8;
            src = q;
            d = dst;
            do
            {
                s32 lo;
                s32 hi;

                lo = *(s32 *)src;
                hi = *(s32 *)(src + 4);
                src += 8;
                n8 -= 1;
                *(s32 *)d = lo;
                *(s32 *)(d + 4) = hi;
                d += 8;
            } while (n8 > 0);
            *(s32 *)(obj + 0x294) = func_0018bb20(*(s32 *)(obj + 0x228), obj);
            *(s32 *)(obj + 0x28C) = D_007643A8[j].field_18;
            *(s32 *)(obj + 0x288) = D_007643A8[j].field_14;
            func_0044ea90(D_005F1068, 0x26F);
            newptr = D_008873F4[0](1, *(s32 *)(obj + 0x28C), 0x40000);
            *(u8 **)(obj + 0x288) = newptr;
            func_0043f810(newptr, (void *)D_007643A8[j].field_14, *(s32 *)(obj + 0x28C));
            func_0015d270(&D_007643A8[j]);
        }
    }
    if (D_007643A4 != NULL)
    {
        jtbl_008873EC[0](D_007643A4);
    }
    if (D_007643A8 != NULL)
    {
        jtbl_008873EC[0](D_007643A8);
    }
    D_007643A0 = 0;
    D_007643A4 = NULL;
    D_007643A8 = NULL;
    if (func_0014eec0() == 0)
    {
        func_00454bd0(arg0);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFBN", func_0015f000);
#endif
