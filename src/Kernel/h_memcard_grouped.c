/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
void func_004647a0(void);
void func_004647b0(void);
void func_004653f0(void);

/* Source unit: src/Kernel/h_memcard_004647a0.c (1 function markers) */

extern s32 D_00764BC0;

// FUN_004647A0
void func_004647a0(void)
{
    D_00764BC0 = 9;
}

/* Source unit: src/Kernel/h_memcard_004647b0.c (1 function markers) */

extern s32 D_00764BC0;

// FUN_004647B0
void func_004647b0(void)
{
    D_00764BC0 = 4;
}

/* Source unit: src/Kernel/h_memcard_004653f0.c (1 function markers) */

extern s32 D_00764B9C;

extern s32 D_00764BBC;
extern s32 D_00764BB8;
extern void *D_00764BAC;
extern s32 D_00764BB4;
extern s32 D_00764BA4;
extern s32 func_00464670(s32 *mode, u32 *result, s32 *error);
extern s32 sceMc2GetInfoAsync(s32 socket, s32 *status);
extern void func_00442088(void *dst, const void *fmt, ...);
extern void func_00431d78(s32 socket, void *data, void *result);
extern void func_00440b68(const void *fmt, ...);
extern s32 func_00431b58(s32 socket);
extern void func_00432288(s32 socket, void *a1, void *a2, s32 a3, s32 a4);
extern void func_004323a8(s32 socket, void *data);
extern s32 func_004326b8(s32 socket, void *data);
extern void func_0043f810(void *dst, void *src, s32 size);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_00442830(void *dst, const void *src);
extern void func_00442428(void *dst, void *src);
extern s32 func_00455f70(void *arg0, s32 *arg1);
extern char D_007127B0[];
extern char D_007127D0[];
extern char D_00712800[];
extern char D_00712820[];
extern char D_00712840[];
extern char D_00712860[];
extern char D_00712880[];
extern char D_00712890[];
extern char D_007126A0[];
extern char D_007126E0[];
extern char D_00712710[];
extern char D_00712740[];
extern char *D_00712760;
extern char *D_00712764;
extern char *D_00712768;
extern char *D_00712770[];
extern char D_007640F8[];
extern s32 D_008E4B20[];
extern s32 D_008E4B24[];
extern char D_008E4A20[];
extern char D_008E4900[];
extern char D_008E4410[];
extern s16 D_008E4416;
extern s32 D_008E441C;
extern char D_008E4420[];
extern char D_008E4460[];
extern char D_008E4490[];
extern char D_008E44C0[];
extern char D_008E44D0[];
extern char D_008E4514[];
extern char D_008E4554[];
extern char D_008E4594[];
#pragma opt_common_subs off
/* measured: guarded 512wd (v1 601wd, +pragma 532wd, +inner_rev 513wd, +c89 512wd) / fnalign retail 777/object 775 (2 short, 0.3% bankable); opt_common_subs off -69, loop_invariants on tie, unroll off tie, schedule on +71 regress; R2 subscript ties, R3 colour ties (baseline best); inner 0x9003-first -19 vs retail order, ifchain +115 regress; outer object order 493 (-20) kept numeric per assignment (table order) */
/* measured 004647c0 (owner, 2026-09-19): 775 against retail 777, **530 edits**, and
   tail_classify counts 125 structural hunks with ZERO register hunks - unusual, and it
   means the residual really is shape rather than allocation.
   The object is 2 instructions SHORT and most of the 125 are a knock-on: retail's branch
   spans read `.+764`, `.+747`, `.+738` where the object's read `.+761`, `.+744`, `.+735`,
   the same three-instruction shift repeated down the whole function.  Find the missing
   three and most of the diff collapses; tuning anything else first is wasted.
   Four spellings measured against the 530, all rejected:
     single exit with `res = X; goto out;` and one `return res` - does not compile as
       written, and the `goto done` variant collapses the object to 425 instrs / 626 edits
       because b210 merges the arms into a table;
     sorting every switch in the body into ascending case order - 530, neutral;
     hoisting the duplicated `D_00764BB8` argument into a local so the call emits
       `move $a3, $a2` the way retail does instead of a second `lw` - 530, neutral.
   The duplicate-argument one is worth knowing: retail loads the global once and copies
   the register, the object loads it twice, and a named temporary does NOT change that. */
// FUN_004647C0 NONMATCHING
#ifdef NON_MATCHING
s32 func_004647c0(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;
    s32 out;
    s32 res;

    func_00440b68(D_007127B0, D_00764BC0);
    switch (D_00764BC0)
    {
    case 0:
        cardMode = 0;
        cardCode = 0;
        if (func_00464670(&cardMode, (u32 *)&cardCode, &cardError) == -1)
        {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            D_00764BC0 = 1;
        }
        goto done;
    case 1:
        if (func_00464670(&cardMode, (u32 *)&cardCode, &cardError) == 1)
        {
            if (cardError == 0)
            {
                switch (cardCode)
                {
                case 0x9003:
                    return -3;
                case 0x6F:
                    return -5;
                case 0x13:
                    return -5;
                case 0x9001:
                    return -4;
                case 0x2F:
                    D_00764BC0 = 3;
                    return 2;
                default:
                    break;
                }
            }
            if (D_008E4B20[0] != 2)
            {
                return -1;
            }
            if (D_008E4B24[0] == 0)
            {
                D_00764BC0 = 3;
                return 2;
            }
            func_00442088(D_008E4A20, D_007127D0, D_00764BB8, D_00764BB8);
            func_00431d78(D_00764BA4, D_008E4A20, D_008E4900);
            D_00764BC0 = 2;
        }
        goto done;
    case 2:
        if (func_00464670(&cardMode, (u32 *)&cardCode, &cardError) == 1)
        {
            if (cardError == 0)
            {
                switch (cardCode)
                {
                case 0x9002:
                    return -4;
                case 2:
                    D_00764BC0 = 6;
                    goto done;
                case 0x13:
                    return -5;
                case 0x16:
                    return -5;
                case 0x6F:
                    return -5;
                case 0x9003:
                    return -5;
                default:
                    break;
                }
            }
            else
            {
                D_00764BC0 = 8;
                return 1;
            }
        }
        goto done;
    case 3:
        res = func_00464670(&cardMode, (u32 *)&cardCode, &cardError);
        if (res == -1)
        {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
        }
        else if ((res == 1) && (cardError == 0) && (cardCode != 0x2F))
        {
            switch (cardCode)
            {
            case 0x9002:
                return -4;
            case 0x13:
                return -3;
            case 0x16:
                return -3;
            case 0x6F:
                return -3;
            case 0x9003:
                return -3;
            default:
                break;
            }
        }
        return 2;
    case 4:
        res = func_00464670(&cardMode, (u32 *)&cardCode, &cardError);
        if (res == -1)
        {
            func_00431b58(D_00764BA4);
            D_00764BC0 = 5;
        }
        else if (res == 1)
        {
            if (cardCode == 0)
            {
                switch (cardCode)
                {
                case 0x9001:
                    return -4;
                case 0x13:
                    return -3;
                case 0x6F:
                    return -3;
                case 0x9003:
                    return -3;
                default:
                    break;
                }
            }
        }
        goto done;
    case 5:
        res = func_00464670(&cardMode, (u32 *)&cardCode, &cardError);
        if (res == -1)
        {
            D_00764BC0 = 6;
        }
        else if (res == 1)
        {
            if (cardError != 0)
            {
                D_00764BC0 = 6;
                return 4;
            }
            return -3;
        }
        goto done;
    case 6:
        func_00442088(D_008E4A20, D_00712800, D_00764BB8);
        func_00440b68(D_00712820, func_004326b8(D_00764BA4, D_008E4A20));
        D_00764BC0 = 7;
        return 5;
    case 7:
        if (func_00464670(&cardMode, (u32 *)&cardCode, &cardError) == 1)
        {
            if (cardError != 0)
            {
                D_00764BC0 = 10;
            }
            else
            {
                switch (cardCode)
                {
                case 0x9002:
                    return -4;
                case 0x1C:
                    return -6;
                case 0x11:
                    D_00764BC0 = 10;
                    goto done;
                default:
                    return -3;
                }
            }
        }
        goto done;
    case 8:
        res = func_00464670(&cardMode, (u32 *)&cardCode, &cardError);
        if (res == -1)
        {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
        }
        else if ((res == 1) && (cardError == 0))
        {
            switch (cardCode)
            {
            case 0x2F:
                return -3;
            case 0x9001:
                return -4;
            case 0x13:
                return -3;
            case 0x6F:
                return -3;
            case 0x9003:
                return -3;
            default:
                break;
            }
        }
        return 1;
    case 9:
        res = func_00464670(&cardMode, (u32 *)&cardCode, &cardError);
        if (res == -1)
        {
            D_00764BC0 = 6;
        }
        else if (res == 1)
        {
            if (cardError != 0)
            {
                D_00764BC0 = 6;
            }
            else
            {
                switch (cardCode)
                {
                case 0x9003:
                    return -3;
                case 0x6F:
                    return -3;
                case 0x13:
                    return -3;
                case 0x9001:
                    return -4;
                case 0x2F:
                    return -3;
                default:
                    break;
                }
            }
        }
        goto done;
    case 10:
        switch (D_00764BBC)
        {
        case 0:
            func_00442088(D_008E4A20, D_007127D0, D_00764BB8, D_00764BB8);
            break;
        case 1:
            func_00442088(D_008E4A20, D_00712840, D_00764BB8);
            break;
        case 2:
            func_00442088(D_008E4A20, D_00712860, D_00764BB8);
            break;
        default:
            break;
        }
        func_004323a8(D_00764BA4, D_008E4A20);
        D_00764BC0 = 11;
        goto done;
    case 11:
        if (func_00464670(&cardMode, (u32 *)&cardCode, &cardError) == 1)
        {
            if (cardError != 0)
            {
                D_00764BC0 = 12;
            }
            else
            {
                switch (cardCode)
                {
                case 0x9002:
                    return -4;
                case 0x1C:
                    return -6;
                case 0x11:
                    D_00764BC0 = 12;
                    goto done;
                default:
                    return -3;
                }
            }
        }
        goto done;
    case 12:
        switch (D_00764BBC)
        {
        case 0:
            func_00442088(D_008E4A20, D_007127D0, D_00764BB8, D_00764BB8);
            func_00432288(D_00764BA4, D_008E4A20, D_00764BAC, 0, D_00764BB4);
            break;
        case 1:
            func_00442088(D_008E4A20, D_00712840, D_00764BB8);
            func_00432288(D_00764BA4, D_008E4A20, (void *)func_00455f70(D_00712880, &out), 0, out);
            break;
        case 2:
            func_00442088(D_008E4A20, D_00712860, D_00764BB8);
            func_0043f9c8(D_008E4410, 0, 0x3C4);
            func_00442830(D_008E4410, D_007640F8);
            if ((u32)D_00764BB8 < 0x10U)
            {
                func_00442830(D_008E44D0, D_00712890);
                func_00442428(D_008E44D0, D_00712770[D_00764BB8]);
            }
            D_008E4416 = 0x12;
            D_008E441C = 0x60;
            func_0043f810(D_008E4420, D_007126A0, 0x40);
            func_0043f810(D_008E4460, D_007126E0, 0x30);
            func_0043f810(D_008E4490, D_00712710, 0x30);
            func_0043f810(D_008E44C0, D_00712740, 0x10);
            func_00442830(D_008E4514, D_00712760);
            func_00442830(D_008E4554, D_00712764);
            func_00442830(D_008E4594, D_00712768);
            func_00432288(D_00764BA4, D_008E4A20, D_008E4410, 0, 0x3C4);
            break;
        default:
            break;
        }
        D_00764BC0 = 13;
        goto done;
    case 13:
        if (func_00464670(&cardMode, (u32 *)&cardCode, &cardError) == 1)
        {
            if (cardError != 0)
            {
                if (D_00764BBC == 2)
                {
                    return 100;
                }
                D_00764BBC++;
                D_00764BC0 = 10;
            }
            else
            {
                switch (cardCode)
                {
                case 0x9002:
                    return -4;
                case 0x1C:
                    return -6;
                case 0x11:
                    D_00764BC0 = 12;
                    goto done;
                default:
                    return -3;
                }
            }
        }
        goto done;
    default:
        goto done;
    }
done:
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/h_memcard_grouped", func_004647c0);
#endif
#pragma opt_common_subs on
// FUN_004653F0
void func_004653f0(void)
{
    D_00764B9C = 1;
}
