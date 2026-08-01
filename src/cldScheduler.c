#include "include_asm.h"
/* Source unit: src/cldScheduler.c */
#include "type.h"

extern void func_0044ea90(void *msg, s32 id);
extern void func_0046d730(const void *file, u32 line);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern char D_006372B0[];
extern u32 D_008814F0[3];
extern s32 D_0076457C;

typedef struct SdlSched
{
    s32 state;   /* 0x00 */
    s32 unk4;    /* 0x04 */
    s32 unk8;    /* 0x08 */
} SdlSched;

extern s64 func_001060b0(void);
extern s32 func_001060c0(void);
extern void func_001104d0(s16 year, s32 *month, s32 *day);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);
extern void func_00248240(void);
extern s32 func_0029da90(s32 kind, s32 a, s32 b);
extern s32 func_0029de20(s32 a, void *b);
extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
extern void func_00440b68(char *fmt, ...);
extern s32 func_00442088(char *buf, char *fmt, ...);
extern s32 func_00452490(s32 handle);
extern void *func_00452560(void);
extern s32 func_00454a60(void *msg, s32 kind);
extern void func_00454bd0(void *handle);
extern s32 func_004553c0(u8 *ptr);
extern char D_006372C0[];
extern char D_006372E0[];
extern char D_00637310[];
extern char D_00637320[];
extern s32 D_007637A0;
extern char D_007637A8;
extern s32 D_00764578;
extern s32 D_00764574;
extern void func_00452080(s32 handle);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c,
                         void *init, void *close, void *buf);
extern char D_00637348[];
extern s32 func_00260020(void);
extern void func_00260440(void);



// FUN_0025FF90
void func_0025ff90(void)
{
    if (D_0076457C != 0)
    {
        func_0046d730(D_006372B0, 0x3E);
    }
    func_0044ea90(D_006372B0, 0x3F);
    D_0076457C = (s32)D_008873F4[0](1, 0x20000, 0x40000);
    func_0043f9c8(&D_008814F0[0], 0, 0xC);
}



// FUN_00260020 NONMATCHING
/* Floor: b210 allocates the day-of-week temp ($a3 retail) ahead of the
 * 0x18 copy-loop counter ($a0 retail); every source ordering tried
 * (statement order, declaration order, for/do-while, block scope, u32
 * counter, comma-init) pins the counter last instead, swapping the two
 * registers in 5 instructions (nd 5/1056, obj 1048/1056). */
#ifdef NON_MATCHING
s32 func_00260020(void)
{
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    char buf90[0x100];
    char buf70[0x20];
    char buf40[0x30];
    SdlSched *sched;
    s32 flag;
    s32 flag2;
    s32 day;
    s32 i;
    s32 b;
    s32 a;
    s32 ret;
    s32 msg;

    sched = func_00452560();
    v1 = 0;
    v2 = 0;
    func_001104d0((s16)func_001060b0(), &v1, &v2);
    switch (sched->state)
    {
    case 0:
        day = v1;
        flag = 1;
        if (D_007637A0 != -1 && D_007637A0 == day)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        if (flag == 0)
        {
            if (D_00764578 != 0)
            {
                func_0046d730(D_006372B0, 0x54);
            }
            D_007637A0 = day;
            func_00442088(buf90, D_006372C0, day);
            func_00440b68(&D_007637A8, D_006372B0, 0x57);
            D_00764578 = func_00454a60(buf90, 0);
            sched->state = 1;
        }
        else
        {
            s32 dow;
            sched->state = 2;
            v3 = 0;
            v4 = 0;
            func_001104d0((s16)func_001060b0(), &v3, &v4);
            dow = func_001060c0() & 0xFF;
            {
                s32 t0;
                s32 t1;
                s8 *src = (s8 *)D_006372E0;
                s8 *dst = (s8 *)buf40;
                i = 0x18;
                do
                {
                    t0 = src[0];
                    t1 = src[1];
                    src += 2;
                    i--;
                    dst[0] = t0;
                    dst[1] = t1;
                    dst += 2;
                } while (i > 0);
            }
            func_00442088(buf70, D_00637310, v3, v4, &buf40[(dow & 0xFF) * 8]);
            if (D_007637A0 == -1)
            {
                a = 0;
            }
            else
            {
                a = D_0076457C;
                a = (a != 0) ? a : 0;
            }
            if (a == 0)
            {
                func_0046d730(D_006372B0, 0x82);
            }
            ret = func_0029de20(a, buf70);
            if (ret == -1)
            {
                func_00440b68(D_00637320, buf70);
                msg = 0;
            }
            else
            {
                msg = func_0029da90(0xF, a, ret);
            }
            sched->unk4 = msg;
            if (msg == 0)
            {
                func_0046d730(D_006372B0, 0xA4);
            }
        }
        break;
    case 1:
        if (func_004553c0((u8 *)D_00764578) != 0)
        {
            a = *(s32 *)((u8 *)D_00764578 + 0x118);
            b = *(s32 *)((u8 *)D_00764578 + 0x110);
            if (a > 0x20000)
            {
                func_0046d730(D_006372B0, 0x49);
            }
            if (D_0076457C == 0)
            {
                func_0046d730(D_006372B0, 0x4A);
            }
            func_0043f9c8((void *)D_0076457C, 0, 0x20000);
            func_0043f810((void *)D_0076457C, (void *)b, (u32)a);
            func_00454bd0((void *)D_00764578);
            D_00764578 = 0;
            flag2 = 1;
        }
        else
        {
            flag2 = 0;
        }
        if (flag2)
        {
            sched->state = 0;
        }
        break;
    case 2:
        sched->state = 3;
        if (D_00764574 != (s16)func_001060b0())
        {
            func_00248240();
        }
        D_00764574 = (s16)func_001060b0();
        /* fallthrough */
    case 3:
        if (func_00452490(sched->unk4) == 0)
        {
            sched->unk4 = 0;
            sched->state = 4;
        }
        break;
    case 4:
        if ((sched->unk8 & 1) != 1)
        {
            func_001029a0(0x19, 0, 0, 0);
        }
        return -1;
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/cldScheduler", func_00260020);
#endif



// FUN_00260440
void func_00260440(void)
{
}



// FUN_00260450
void func_00260450(void)
{
    u32 *base = D_008814F0;

    if (D_008814F0[1] != 0 && func_00452490(base[1]) != 0)
    {
        func_00452080(base[1]);
        base[1] = 0;
    }
    func_0043f9c8(base, 0, 0xC);
    if (base == 0)
    {
        func_0046d730(D_006372B0, 0xD8);
    }
    func_00451de0(D_00637348, 0x100, 0, 0, (void *)&func_00260020,
                  (void *)&func_00260440, base);
}
