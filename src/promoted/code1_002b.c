#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "shd_misc_internal.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}
extern void (*jtbl_008873EC[])(void *);
extern void func_002baa50(void);
extern void func_002baa90(s32 *arg0);
extern void func_002bb7c0(s32 arg0);
extern void func_002bd440(void);



extern void func_002bcc60(u8 *arg0);
extern s32 func_002bc0e0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern void func_0046d730(const void *arg0, s32 arg1);
extern char D_0063F2A0[];
extern char D_007488E8[];
extern void func_0045a9a0(s32 arg0, s32 arg1);

extern s32 clndGetMoonPhase(void);

extern u32 func_00106a90(s16 arg0);
extern u8 *D_00882F40[];
extern void func_00278450(s32 arg0);
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s8 func_002bacb0(void);
extern s32 iGpffffb57c;
extern s32 *func_002bbf70();
extern s32 func_002bb0e0(void);
extern void func_002791f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 func_00279350(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6);
extern s32 func_00106880(void);
extern s32 func_002be1e0(s32 arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_00145080(void);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00276e70(s32 arg0, s8 arg1);
extern void func_00277250(s32 arg0);
extern void func_00277ad0(s32 arg0, s32 arg1);
extern s32 func_00276e10();
extern s32 func_00276fb0(s32 arg0);
extern s32 func_00277070(s32 arg0);
extern void func_00277be0(s32 arg0, s32 arg1);
extern void func_00277fd0(s32 arg0, s32 arg1);
extern u32 func_002786c0(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bbdd0(s32 arg0);
extern void func_002bbe90(s64 arg0, s32 arg1);
extern u32 func_002e7a60(void);
extern u8 *func_002e2170(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00442088();
extern s64 func_001060b0(void);
extern s32 func_00110d60(s16 arg0);
extern s32 func_0046aea0(void *arg0);
extern s32 func_0046a750(s32 arg0);
extern void func_0046b0d0(void *arg0);
extern void func_002e2240(void *arg0, void *arg1, void *arg2);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern f32 func_0044b610(f32 arg0);
extern f32 func_0044b7b0(f32 arg0);
extern s32 func_00106850(void);
extern s32 func_00106ac0(s64 arg0);
extern s64 func_00106af0(s64 arg0);
extern s32 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s32 func_002be100(s32 arg0);
extern void func_00144c90(s32 arg0, s32 arg1);
extern s32 func_00144f60(void);
extern s32 func_0015f660(void);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern s32 func_002cb6a0(s32 arg0);
extern void func_002caa00(s32 arg0, s32 arg1);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern s32 func_00452380(void *arg0);
extern u8 *func_00457120(void);
extern s32 func_0014b450(void);
extern f32 func_0014b4d0(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern u8 D_0063F3B0[];


extern s32 func_002b11c0(u8 *arg0);
extern s32 func_002b1210(u8 *arg0);

extern f32 func_002b1260(s32 arg0, f32 fparg0);
extern f32 func_002b1320(s32 arg0, f32 fparg0);
extern void func_002b3ae0(u8 *arg0, s64 arg1, f32 fparg0, s32 arg2);
extern u8 *func_0047a2f0(u32 arg0);
extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern void func_00442830(void *arg0, ...);
extern void func_00442428(void *arg0, void *arg1);
extern void func_00442de8(void *arg0, void *arg1, s32 arg2);
extern void func_00275980(void *arg0, void *arg1, s32 arg2);
extern s32 func_00443010(u8 *arg0, u8 *arg1);
extern s32 func_002b3520(u8 *arg0, s64 arg1);
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



// FUN_002B2940
s32 func_002b2940(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}
// FUN_002B2950
void func_002b2950(s32 arg0)
{
    iGpffffb55c = arg0;
}
// FUN_002B2960
s32 func_002b2960(void)
{
    return iGpffffb55c;
}
// FUN_002B2970
void func_002b2970(u8 *arg0, f32 arg1, f32 arg2)
{
    Vec2f val;

    val.x = arg1;
    val.y = arg2;
    *(Vec2f *)arg0 = val;
}
// FUN_002B29A0
void func_002b29a0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct Float3 {
        f32 x;
        f32 y;
        f32 z;
    } val;

    val.x = arg1;
    val.y = arg2;
    val.z = arg3;
    *(struct Float3 *)arg0 = val;
}
// FUN_002B29E0
void func_002b29e0(u8 *arg0, f32 arg1, f32 arg2)
{
    FclBoundsPacket val;

    val.dimensions.width = (s32)arg1;
    val.dimensions.height = (s32)arg2;
    ((FclBoundsPacket *)arg0)->representation = val.representation;
}
// FUN_002B2A30
s32 func_002b2a30(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    s32 result;

    result = arg3 & 0xFF;
    result = p4_pack_or(result, (arg2 & 0xFF) << 8);
    result = p4_pack_or((arg1 & 0xFF) << 16, result);
    /* The high byte must be shifted in unsigned 32-bit arithmetic. */
    result = p4_pack_or((arg0 & 0xFFU) << 24, result);
    return result;
}
// FUN_002B2A60
void func_002b2a60(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    struct Byte4 {
        u8 b0;
        u8 b1;
        u8 b2;
        u8 b3;
    } val;

    val.b0 = (u8)arg1;
    val.b1 = (u8)arg2;
    val.b2 = (u8)arg3;
    val.b3 = (u8)arg4;
    *(struct Byte4 *)arg0 = val;
}
// FUN_002B2AA0
f32 func_002b2aa0(s64 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3)
{
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f0;
    f32 temp_f2;
    s64 temp_3;

    temp_f20 = fparg0;
    temp_f21 = fparg1;
    if (fparg2 == fparg3) {
        return temp_f21;
    }
    temp_3 = (s8)arg0;
    switch (temp_3) {
    case 0:
        return temp_f20 + ((fparg2 * (temp_f21 - temp_f20)) / fparg3);
    case 1:
        temp_f0 = func_0044b7b0(p4_mul_left(fparg2, iGpffff82fc / (2.0f * fparg3)));
        temp_f2 = temp_f21 - temp_f20;
        return temp_f20 + temp_f2 * temp_f0;
    case 2:
        temp_f0 = func_0044b610(p4_mul_left(fparg2, iGpffff82fc / (2.0f * fparg3)));
        temp_f2 = temp_f21 - temp_f20;
        return temp_f21 - temp_f2 * temp_f0;
    default:
        return -1.0f;
    }
}
// FUN_002B2BD0
void func_002b2bd0(f32 *arg0, s64 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3)
{
    struct Vec2 {
        f32 x;
        f32 y;
    } sp;

    if ((s8)arg1 == 0) {
        sp.x = fparg0 / 2.0f;
        sp.y = fparg1 / 2.0f;
    } else if ((s8)arg1 == 1) {
        sp.x = (fparg2 / 2.0f) + ((fparg0 - fparg2) / 2.0f);
        sp.y = (fparg3 / 2.0f) + ((fparg1 - fparg3) / 2.0f);
    } else if ((s8)arg1 == 2) {
        sp.x = (fparg0 / 2.0f) - (fparg2 / 2.0f);
        sp.y = (fparg1 / 2.0f) - (fparg3 / 2.0f);
    }
    *(struct Vec2 *)arg0 = sp;
}
// FUN_002B2CB0
s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 + arg1;
    }
    {
        s32 var = arg0 + arg1;
        s32 bound;
        if (arg2 < var) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D00
s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 - arg1;
    }
    {
        s32 var = arg0 - arg1;
        s32 bound;
        if (var < arg2) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D50
s16 func_002b2d50(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s32 temp_2_2;
    s32 temp_2;
    s32 temp_3;
    s32 temp_6;
    s32 var_2;

    temp_6 = arg2;
    if (temp_6 == 0) {
        return 0;
    }
    temp_3 = arg4;
    temp_2_2 = arg0 + temp_3;
    if (temp_2_2 < 0) {
        return 0;
    }
    if (temp_6 < temp_2_2) {
        return arg3 - 1;
    }
    if (temp_3 > 0) {
        return (s16)func_002b3110(arg1 + temp_3, arg3 - 2, temp_6);
    }
    if (temp_3 < 0) {
        temp_2 = arg1;
        if (temp_2 == 0) {
            var_2 = temp_2 - 1;
            if (var_2 < 0) {
                var_2 = 0;
            }
            return (s16)var_2;
        }
        return (s16)func_002b3140(temp_2 + temp_3, 1, temp_6);
    }
    return arg1;
}
/* measured: archived body in build/WW15_002b2e70.c (object 276B/window 288B, normalized_diff 5); restored ASM fallback. */
// FUN_002B2E70
void func_002b2e70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 *arg4, s16 *arg5)
{
    s32 var_4;
    s32 temp_3;
    s32 var_12;
    s32 temp_6;
    s32 var_11;
    s32 var_10;
    s32 temp_7;
    s32 var_7;
    var_4 = arg0;
    var_12 = 0;
    if (arg2 == 0) { *arg4 = 0; *arg5 = 0; return; }
    var_10 = arg2 - 1;
    if (var_4 != var_10) {
        temp_3 = var_4 - arg1;
        temp_7 = (s8)arg3;
        temp_6 = arg2 - (temp_3 + temp_7);
        if (temp_6 <= 0) {
            arg2 = var_4;
            var_11 = 0;
            goto loop_10_test;
loop_10_body:
            arg2 += 1;
            if (var_10 < arg2) arg2 = var_10;
            var_12 += 1;
            if (arg2 >= var_10) { arg1 += var_12; goto loop_10_done; }
            var_11 += 1;
loop_10_test:
            if (var_11 < temp_7) goto loop_10_body;
loop_10_done:
            var_4 += var_12;
        } else {
            if (temp_6 > temp_7) goto loop_18_branch;
            goto loop_17_branch;
loop_17_branch:
            var_7 = 0;
            goto loop_17_test;
            do {
loop_17_body:
                var_4 += 1;
                if (var_10 < var_4) var_4 = var_10;
                var_7 += 1;
loop_17_test: ;
            } while (var_7 < temp_6);
            goto loop_17_done;
loop_18_branch:
            temp_3 = var_4 + temp_7;
            var_10 = (var_10 < temp_3) ? var_10 : temp_3;
            var_4 = var_10;
loop_17_done: ;
        }
    }
    *arg4 = var_4;
    *arg5 = arg1;
}
// FUN_002B2F90
void func_002b2f90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 *arg4, s16 *arg5)
{
    int condition_value;
    s32 temp_3;
    s32 var_10;
    s32 var_6;
    if (arg2 == 0) {
        *arg4 = 0;
        *arg5 = 0;
        goto exit;
    }
    temp_3 = arg0 - arg1;
    if (temp_3 == 0) {
        arg0 = 0;
        arg1 = 0;
        goto done;
    }
    var_10 = 0;
    var_6 = (s8)arg3;
    goto loop_test;
loop_body:
    temp_3 = (s16)(arg0 - arg1) - 1;
    if (temp_3 < 0) {
        temp_3 = 0;
    }
    if (temp_3 == 0) {
        arg0 -= 1;
        if (arg0 < 0) {
            arg0 = 0;
        }
        if ((!condition_value) && (!condition_value)) {
        }
        goto done;
    }
    arg0 -= 1;
    if (arg0 < 0) {
        arg0 = 0;
    }
    var_10 += 1;
loop_test:
    if (var_10 < var_6) {
        goto loop_body;
    }
done:
    *arg4 = arg0;
    *arg5 = arg1;
exit:
    ;
}
// FUN_002B3050
void func_002b3050(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4, s16 *arg5, s16 *arg6)
{
  int condition_value;
  s32 value;
  s32 iterations;
  if (arg2 != 0)
  {
    goto nonzero;
  }
  value = arg4 & 0xFF;
  *arg6 = (*arg5 = value);
  goto done;
  nonzero:
  if ((arg0 - arg1) != 0U)
  {
    goto setup;
  }
  arg0 = arg4 & 0xFF; arg1 = arg0;
  goto store;
  setup:
  iterations = 0;

  arg2 = (s8) arg3;
  goto loop_test;
  loop_body:
  value = ((s16) (arg0 - arg1)) - 1;

  if (value < 0)
  {
    value = 0;
  }
  if (value != 0)
  {
    goto decrement;
  }
  arg0 -= 1;
  if (arg0 < 0)
  {
    arg0 = 0;
  }
  if ((!condition_value) && (!condition_value))
  {
  }
  goto store;
  decrement:
  arg0 -= 1;

  if (arg0 < 0)
  {
    arg0 = 0;
  }
  iterations += 1;
  loop_test:
  if (iterations < arg2)
  {
    goto loop_body;
  }

  store:
  *arg5 = arg0;

  *arg6 = arg1;
  done:
  return;
}

/* measured: opt_rebuildconditionals off probe for min/max */
#pragma opt_rebuildconditionals off
// FUN_002B3110
s32 func_002b3110(s32 arg0, s32 arg1)
{
    s32 result;

    if (arg0 < arg1)
        goto choose;
    result = arg1;
    goto done;
choose:
    result = arg0;
done:
    return result;
}
// FUN_002B3140
s32 func_002b3140(s32 arg0, s32 arg1)
{
    s32 result;

    if (arg0 > arg1)
        goto choose;
    result = arg1;
    goto done;
choose:
    result = arg0;
done:
    return result;
}
/* measured: close opt_rebuildconditionals after min/max */
#pragma opt_rebuildconditionals on
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
#pragma opt_loop_invariants on
// FUN_002B3170
s32 func_002b3170(s32 arg0)
{
    s32 result;

    result = 0;
    do {
        arg0 /= 10;
        result++;
    } while (arg0 != 0);
    return result;
}
/* measured: close opt_loop_invariants after 3170. */
#pragma opt_loop_invariants off
// FUN_002B31A0
void func_002b31a0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 second;
    struct Vec3 result;

    first = *(struct Vec3 *)arg1;
    second = *(struct Vec3 *)arg2;
    result.x = first.x - second.x;
    result.y = first.y - second.y;
    result.z = first.z - second.z;
    *(struct Vec3 *)arg0 = result;
}
// FUN_002B3230
s32 func_002b3230(s16 *arg0, s16 *arg1) {
    s16 b;
    u32 x;
    u32 y;

    b = *arg1;
    x = func_00106a90(*arg0);
    y = func_00106a90(b);
    if (x < y) {
        return 1;
    }
    return -(s32)(y < x);
}

// FUN_002B32A0
s32 func_002b32a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 var;

    var = arg3;
    if (arg0 >= arg1) {
        return arg1;
    }
    if (arg2 == 0) {
        var = 0;
    }
    return var;
}
// FUN_002B32D0
u8 *func_002b32d0(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4)
{
    u8 sp2b0[0x80];
    u8 sp230[0x80];
    u8 sp1b0[0x80];
    u8 sp130[0x80];
    u8 spf0[0x40];
    u8 spb0[0x40];
    u8 sp70[0x40];
    u8 **entry;
    s32 outer;
    u8 *dest;
    s32 size;
    s32 offset;
    s32 initial;
    s32 inner;

    func_00442830(sp130);
    func_00442830(sp1b0, arg2);
    func_00442830(sp230, arg3);
    func_00442830(sp2b0, arg4);
    initial = 0;
    while ((s16)initial < 0x40) {
        sp70[(s16)initial] = 0;
        initial = (s16)(initial + 1);
    }
    outer = 0;
    while ((s16)outer < 4) {
        entry = &D_0063F110[(s16)outer];
        if (func_00443010(arg0, *entry) == 0) {
            outer = (s16)(outer + 1);
        } else {
            dest = sp130 + ((s16)outer * 0x80);
            offset = D_007488C0[(s16)outer];
            do {
                inner = 0;
                while ((s16)inner < 0x40) {
                    spb0[(s16)inner] = 0;
                    spf0[(s16)inner] = 0;
                    inner = (s16)(inner + 1);
                }
                size = func_002b3520(arg0, (s8)outer);
                func_00442de8(spf0, arg0, size);
                func_00275980(spf0, spb0, 0x40);
                func_00442428(sp70, spb0);
                func_00442428(sp70, dest);
                func_00442830(arg0, arg0 + size + offset);
            } while (func_00443010(arg0, *entry) != 0);
        }
    }
    func_00275980(arg0, spb0, 0x40);
    func_00442428(sp70, spb0);
    func_00442830(arg0, sp70);
    return arg0;
}
/* measured: object 504B/window 512B, nd 0. Retail hoists the nine tag-byte and
   case constants into $v1/$a1-$a3/$t0-$t2/$t5/$t6 ahead of the scan loop,
   which needs opt_loop_invariants on (the unit default here is off); the SJIS
   lead-byte test spelled `uc > 0x80` gives the `slti $at` form, and the four
   match exits are `goto found` to a label in front of the single return so
   the last byte compare branches straight to `jr ra`. The s64 second
   parameter (file prototype) is narrowed once into an s32 `mode`. */
// FUN_002B3520
/* measured: opt_loop_invariants on hoists the tag constants out of the loop. */
#pragma opt_loop_invariants on
s32 func_002b3520(u8 *p, s64 arg1)
{
    s32 count;
    s32 mode;
    s8 c;
    u8 uc;

    count = 0;
    mode = (s8)arg1;
    for (;;) {
        c = *(s8 *)p;
        uc = c;
        switch (mode) {
        case 0:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && *(s8 *)(p + 1) == 'P' && *(s8 *)(p + 2) == '1' && *(s8 *)(p + 3) == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        case 1:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && *(s8 *)(p + 1) == 'P' && *(s8 *)(p + 2) == '2' && *(s8 *)(p + 3) == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        case 2:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && *(s8 *)(p + 1) == 'R' && *(s8 *)(p + 2) == '1' && *(s8 *)(p + 3) == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        case 3:
            if (uc > 0x80) {
                p += 1;
                count += 1;
            } else if (c == '<' && *(s8 *)(p + 1) == 'R' && *(s8 *)(p + 2) == '2' && *(s8 *)(p + 3) == '>') {
                goto found;
            }
            p += 1;
            count += 1;
            break;
        }
    }
found:
    return count;
}
/* measured: closes the loop-invariant bracket; the unit default is off. */
#pragma opt_loop_invariants off
// FUN_002B3720
s32 func_002b3720(u8 *arg0)
{
    struct Vec2 {
        f32 x;
        f32 y;
    } out;
    struct Vec2 work;
    f32 temp_f20;
    u8 *p;
    s32 color;

    p = *(u8 **)(arg0 + 0x38);
    func_002b2bd0(&work.x, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    out = *(struct Vec2 *)&work;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s8 *)(p + 0x21) == 1) {
        return 0;
    }
    if (*(s8 *)(p + 0x20) == 0) {
        out.x = out.x + 17.0f;
        out.y = out.y + 264.0f;
        out.x = out.x - 10.0f;
        out.y = out.y - 10.0f;
        out.y = out.y - 2.0f;
    } else if (*(s8 *)(p + 0x20) == 1) {
        temp_f20 = ((f32)func_002b11c0(
                        func_0047a2f0(D_007EFA00[0]) + 0x30) *
                    18.0f) + 172.0f;
        out.x = temp_f20 -
                func_002b1260(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f);
        temp_f20 = ((f32)func_002b1210(
                        func_0047a2f0(D_007EFA00[0]) + 0x30) *
                    18.0f) + 9.0f;
        out.y = temp_f20 -
                func_002b1320(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f) - 2.0f;
    }
    color = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
    func_002b3ae0(arg0, *(s64 *)&out, 60002.0f, color);
    return 0;
}
// FUN_002B3960
void func_002b3960(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B5100
void func_002b5100(u8 *arg0, s8 arg1)
{
    if (arg0 != NULL) {
        *(s8 *)(*(u8 **)(arg0 + 0x38) + 8) = arg1;
    }
}
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
#pragma opt_propagation off
// FUN_002B5120
void func_002b5120(s32 arg0, u8 *arg1)
{
    void (**base)(s32 arg0, s32 arg1);
    s8 temp_5;

    base = D_00887300;
    base[0](6, 1);
    base[0](7, 2);
    base[0](8, 1);
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
    if (*(s8 *)(arg1 + 0x184) == 1) {
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        temp_5 = *(s8 *)(arg1 + 0x18C);
        switch (temp_5) {
        case 1:
            func_003f6440(2, 0x48);
            func_003f6440(3, 0x71801);
            return;
        case 2:
            func_003f6440(2, 0x42);
            func_003f6440(3, 0x71801);
            break;
        }
    }
}
/* measured: restores opt_propagation after func_002b5120. */
#pragma opt_propagation on
/* measured: first C reconstruction (m2c 222 + rw 190 + types 3-vs-2 de-noised to file idiom, truthful externs D_008872F8[]/00461390(void*,s32,void*,s32) per tree, s32(u8*) + s8/u16/s16 + (s32)int-store + (u8)color + branchy u8-to-f32 + quad + (void*)callback, corrected active!=0 early-return without shared tail and mode3/4 folded); retail 624 object 632 (8 over, 1.3% in 3% gate) probe 548 via probe_variants, 304 edits +4 reloc-only via fnalign --candidate /var/tmp/cold2b52a0/guarded_extracted.c; step2 pragma singles all tie/regress (548 tie dead/prop/strength/unroll, 555 loop_invariants, 584 schedule, 611 common_subs, 627 L1, 676 peephole, 810 L0) and pairs best 548 tie via pragma_sweep; step3 subscript v3a direct/v3b off-local/v3c P-index all 548 tie; step4 colouring v4a count/half, v4b floats, v4c ptrs/bytes, v4d counters-first all 548 tie; residual is dispatch polarity (beq vs bne + addiu -1), sra $v0/$v1 swap, float mov.s surplus, folded mode3/4 vs retail duplicated blocks, vertex sub.s order; above 60 so two-tie stop met. */
/* measured 002b52a0 (hand switch, 2026-09-20): mode chain (braced multi-line arms, chain_variables mode) */
/* hand switch ascending 330 edits +4 reloc-only / probe 577, reversed 521 +4 / 567 vs chain 304 +4 / 548 */
/* (chain wins; switch not installed. dup fixes 61-run at 0x002b5600 but breaks gate: switch-asc-dup 271/644 */
/* 694 vs 624 +11.2% outside, chain-dup 241/586 692 vs 624 +10.9% outside, rejected per handoff 7y. state */
/* 1-then-0 and 0-then-1 both tie 304/548. deficit retail+ lwc1 12/cvt 6/lh 4/jal 4, runs 61 at 0x002b5600, */
/* 13 at 0x002b5808, 11 at 0x002b5a48; tail 43 structure vs 16 register. floor stays ASM.) */
// FUN_002B52A0 NONMATCHING
#ifdef NON_MATCHING
s32 func_002b52a0(u8 *arg0)
{
    extern f32 D_008872F8[];
    extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
    u8 *work;
    s8 state;
    u16 active;
    s16 mode;
    s16 frame;
    s32 count;
    s32 half;
    s32 v;
    s32 i;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    f32 x0;
    f32 y0;
    f32 f0;
    f32 factor;
    u8 *item;
    u8 *node;
    u8 *pkt;
    work = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(work + 0x154) == 1) {
        return 0;
    }
    state = *(s8 *)work;
    if (state == 3) {
        return -1;
    }
    if (state == 0 || state == 1) {
        goto shared;
    }
    if (state != 2) {
        return 0;
    }
    active = *(u16 *)(work + 0x182);
    if (active != 0) {
        *(u16 *)(work + 0x182) = func_002b2d00(active, 1, 0, 0, 1);
        return 0;
    }
    mode = *(s16 *)(work + 0x156);
    if (mode == 0) {
        x0 = *(f32 *)(work + 0x13C);
        count = *(s32 *)(work + 0x170);
        half = count >> 1;
        if (count < 0) {
            half = (count + 1) >> 1;
        }
        *(f32 *)(work + 0x134) = func_002b2aa0(0, x0 + (f32)half, x0, (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        x0 = *(f32 *)(work + 0x140);
        count = *(s32 *)(work + 0x174);
        half = count >> 1;
        if (count < 0) {
            half = (count + 1) >> 1;
        }
        *(f32 *)(work + 0x138) = func_002b2aa0(0, x0 + (f32)half, x0, (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(s32 *)(work + 0x128) = (s32)func_002b2aa0(0, (f32)*(s32 *)(work + 0x160), (f32)*(s32 *)(work + 0x170), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(s32 *)(work + 0x12C) = (s32)func_002b2aa0(0, (f32)*(s32 *)(work + 0x164), (f32)*(s32 *)(work + 0x174), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
    } else if (mode == 1) {
        x0 = *(f32 *)(work + 0x13C);
        count = *(s32 *)(work + 0x160);
        half = count >> 1;
        if (count < 0) {
            half = (count + 1) >> 1;
        }
        *(f32 *)(work + 0x134) = func_002b2aa0(0, x0, x0 + (f32)half, (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        x0 = *(f32 *)(work + 0x140);
        count = *(s32 *)(work + 0x164);
        half = count >> 1;
        if (count < 0) {
            half = (count + 1) >> 1;
        }
        *(f32 *)(work + 0x138) = func_002b2aa0(0, x0, x0 + (f32)half, (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(s32 *)(work + 0x128) = (s32)func_002b2aa0(0, (f32)*(s32 *)(work + 0x160), (f32)*(s32 *)(work + 0x170), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(s32 *)(work + 0x12C) = (s32)func_002b2aa0(0, (f32)*(s32 *)(work + 0x164), (f32)*(s32 *)(work + 0x174), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
    } else if (mode == 2) {
        *(f32 *)(work + 0x134) = func_002b2aa0(0, *(f32 *)(work + 0x13C), *(f32 *)(work + 0x144), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(f32 *)(work + 0x138) = func_002b2aa0(0, *(f32 *)(work + 0x140), *(f32 *)(work + 0x148), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
    } else if (mode == 3 || mode == 4) {
        *(f32 *)(work + 0x134) = func_002b2aa0(0, *(f32 *)(work + 0x13C), *(f32 *)(work + 0x144), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(f32 *)(work + 0x138) = func_002b2aa0(0, *(f32 *)(work + 0x140), *(f32 *)(work + 0x148), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(s32 *)(work + 0x128) = (s32)func_002b2aa0(0, (f32)*(s32 *)(work + 0x160), (f32)*(s32 *)(work + 0x170), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
        *(s32 *)(work + 0x12C) = (s32)func_002b2aa0(0, (f32)*(s32 *)(work + 0x164), (f32)*(s32 *)(work + 0x174), (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
    }
    if (*(u8 *)(work + 0x180) == 1) {
        b0 = *(u8 *)(work + 0x178);
        if ((s32)b0 >= 0) {
            x0 = (f32)b0;
        } else {
            u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
            x0 = (f32)(s32)t;
            x0 = x0 + x0;
        }
        b1 = *(u8 *)(work + 0x179);
        if ((s32)b1 >= 0) {
            y0 = (f32)b1;
        } else {
            u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
            y0 = (f32)(s32)t;
            y0 = y0 + y0;
        }
        *(u8 *)(work + 0x113) = (u8)func_002b2aa0(2, x0, y0, (f32)*(s16 *)(work + 0x17A), (f32)*(s32 *)(work + 0x17C));
        v = 1;
        while (v < 4) {
            *(u8 *)(work + v * 4 + 0x113) = *(u8 *)(work + 0x113);
            v += 1;
        }
        v = func_002b2cb0(*(s16 *)(work + 0x17A), 1, *(s32 *)(work + 0x17C), 0, 1);
        *(s16 *)(work + 0x17A) = (s16)v;
        if ((s16)v >= *(s32 *)(work + 0x17C)) {
            *(u8 *)(work + 0x113) = *(u8 *)(work + 0x179);
            v = 1;
            while (v < 4) {
                *(u8 *)(work + v * 4 + 0x113) = *(u8 *)(work + 0x113);
                v += 1;
            }
            *(u8 *)(work + 0x180) = 0;
        }
    }
    frame = *(s16 *)(work + 0x14C);
    if (frame < *(s32 *)(work + 0x150)) {
        *(s16 *)(work + 0x14C) = frame + 1;
    } else {
        *(s16 *)(work + 0x156) = -1;
        if (*(s32 *)(work + 0x128) == 0 || *(s32 *)(work + 0x12C) == 0) {
            *(s8 *)(work + 0x154) = 1;
        }
        if (*(u8 *)(work + 0x180) == 0 && *(s16 *)(work + 0x156) == -1) {
            *(s8 *)work = 1;
        }
    }
shared:
    factor = 1.0f / *(f32 *)(func_00457120() + 0x80);
    v = 0;
    while (v < 4) {
        item = work + (v << 6);
        *(f32 *)(item + 0x18) = D_008872F8[0] - *(f32 *)(work + 0x130);
        *(f32 *)(item + 0x28) = factor;
        node = work + v * 4;
        b0 = *(u8 *)(node + 0x110);
        if ((s32)b0 >= 0) {
            f0 = (f32)b0;
        } else {
            u32 t = ((u32)b0 >> 1) | ((u32)b0 & 1);
            f0 = (f32)(s32)t;
            f0 = f0 + f0;
        }
        *(f32 *)(item + 0x30) = f0;
        b1 = *(u8 *)(node + 0x111);
        if ((s32)b1 >= 0) {
            f0 = (f32)b1;
        } else {
            u32 t = ((u32)b1 >> 1) | ((u32)b1 & 1);
            f0 = (f32)(s32)t;
            f0 = f0 + f0;
        }
        *(f32 *)(item + 0x34) = f0;
        b2 = *(u8 *)(node + 0x112);
        if ((s32)b2 >= 0) {
            f0 = (f32)b2;
        } else {
            u32 t = ((u32)b2 >> 1) | ((u32)b2 & 1);
            f0 = (f32)(s32)t;
            f0 = f0 + f0;
        }
        *(f32 *)(item + 0x38) = f0;
        b3 = *(u8 *)(node + 0x113);
        if ((s32)b3 >= 0) {
            f0 = (f32)b3;
        } else {
            u32 t = ((u32)b3 >> 1) | ((u32)b3 & 1);
            f0 = (f32)(s32)t;
            f0 = f0 + f0;
        }
        *(f32 *)(item + 0x3C) = f0;
        v += 1;
    }
    *(f32 *)(work + 0x10) = *(f32 *)(work + 0x134);
    *(f32 *)(work + 0x14) = *(f32 *)(work + 0x138);
    *(f32 *)(work + 0x50) = *(f32 *)(work + 0x134) + (f32)*(s32 *)(work + 0x128);
    *(f32 *)(work + 0x54) = *(f32 *)(work + 0x138);
    *(f32 *)(work + 0x90) = *(f32 *)(work + 0x134);
    *(f32 *)(work + 0x94) = *(f32 *)(work + 0x138) + (f32)*(s32 *)(work + 0x12C);
    *(f32 *)(work + 0xD0) = *(f32 *)(work + 0x134) + (f32)*(s32 *)(work + 0x128);
    *(f32 *)(work + 0xD4) = *(f32 *)(work + 0x138) + (f32)*(s32 *)(work + 0x12C);
    pkt = func_00461390(D_00793E80 + *(s32 *)(work + 0x188) * 0x30, 4, work + 0x10, 4);
    *(void **)(pkt + 8) = (void *)func_002b5120;
    *(u8 **)(pkt + 0x10) = work;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b52a0);
#endif
// FUN_002B5C60
void func_002b5c60(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
/* Floor: 288 differing words (probe_variants) over 278 fnalign edits, 335 emitted against */
/* retail 336 (99.7%, 1340B/1360B window, 20B short). WALL: spill-offset rotation (retail src@0xF0/pos@0x120 */
/* vs object src@0xE0/spC0@0xF0, invariant under decl/assign reorder) plus scheduling cascade; frame 0x130 both */
/* sides, single saved-FP f20 (extra f21 fixed via int->float 9th arg). Honest levers: (f32)src.dimensions.height cvt.s.w from */
/* 0xFC (+15 instrs 320->335, 311->288 words), 22.0f/17.0f/284.0f/6.0f/18.0f/1.0f, s16 indices/s8 flags, block-scope */
/* offsets, tmpCol byte-3 alpha, tmpA intermediate, swapped (0,alpha)/(alpha,0) 12-arg 002b83e0 calls. Ruled out: */
/* opt_common_subs off (288->337 with cvt), srctemp (+21), !flag (+16), no-tmpCol (+10), f32-cast/mulswap neutral. */
/* measured: python3 tools/probe_variants.py src/promoted/code1_002b.c func_002ba080 --candidate v2=/tmp/a080_probe/v2_cvt.c */
/* measured: python3 tools/fnalign.py src/promoted/code1_002b.c func_002ba080 --candidate /tmp/a080_probe/v2_cvt.c */
/* measured: python3 tools/measure_guarded.py src/promoted/code1_002b.c func_002ba080 (after install) */
// FUN_002BA080 NONMATCHING
#ifdef NON_MATCHING
void func_002ba080(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s32 arg4, s64 arg5, s64 arg6, s16 arg7, f32 fparg0, s8 arg_sp0)
{
    extern void func_002b83e0(u8 *arg0, s64 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, s64 arg6, s64 arg7, f32 fparg0, f32 fparg1, s8 arg_sp0, s8 arg_sp8);
    FclBoundsPacket src;
    FclBoundsBytes copy1, copy2;
    struct Float2 { f32 x; f32 y; } pos1, pos2, tmpA, tmpB, tmpC;
    s64 field;
    u8 *object;
    s64 spC0;
    s32 spCC;
    s32 tmpCol1;
    s32 tmpCol2;
    s16 value;
    s16 pair_index;
    s16 next_index;
    s8 ones;
    s8 tens;
    s8 flag;
    object = arg0;
    field = arg6;
    (void)field;
    spC0 = arg3;
    spCC = arg4;
    func_002b29e0((u8 *)&src, 22.0f, 17.0f);
    func_002b2970((u8 *)&pos1, *(f32 *)((u8 *)&spC0) + 284.0f, *(f32 *)((u8 *)&spC0 + 4) + 6.0f);
    value = (s16)arg2;
    if ((value == -1) || (value == 0)) { ones = 10; tens = 10; }
    else { ones = (s8)(value % 10); tens = (s8)(value / 10); }
    pair_index = (s16)((s16)arg1 * 2);
    next_index = (s16)(pair_index + 1);
    flag = arg_sp0;
    if (flag == 0) {
        u8 *digit; u8 *slot; s32 offset;
        offset = (s32)pair_index * 0x220;
        digit = D_0063F1F0 + ((s32)ones * 0x10);
        slot = *(u8 **)(object + 0x38) + offset;
        *(f32 *)(slot + 0x1F4) = *(f32 *)(digit + 0);
        *(f32 *)(slot + 0x1F8) = *(f32 *)(digit + 4);
        *(f32 *)(slot + 0x1FC) = *(f32 *)(digit + 8);
        *(f32 *)(slot + 0x200) = *(f32 *)(digit + 0xC);
        copy1 = src.representation;
        *(f32 *)(slot + 0x12C) = pos1.x;
        *(f32 *)(slot + 0x130) = pos1.y;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        tmpCol1 = spCC;
        *(u8 *)(slot + 0x162) = ((u8 *)&tmpCol1)[3];
        *(u8 *)(slot + 0x179) = ((u8 *)&spCC)[0];
        *(u8 *)(slot + 0x17A) = ((u8 *)&spCC)[1];
        *(u8 *)(slot + 0x17B) = ((u8 *)&spCC)[2];
        *(u8 *)(slot + 0x17C) = ((u8 *)&spCC)[3];
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = fparg0;
        *(s16 *)(slot + 0x104) = (s16)(*(s16 *)(slot + 0x104) | 1);
        ((FclBoundsPacket *)(slot + 0x204))->representation = copy1;
        *(s16 *)(slot + 0x100) = arg7;
        func_002b83e0(slot + 0x104, *(s64 *)((u8 *)&pos1), spCC, spCC, 0, ((u8 *)&spCC)[3], arg5, arg6, (f32)src.dimensions.height, fparg0, arg_sp0, 0);
    } else {
        u8 *slot;
        s32 offset;
        offset = (s32)pair_index * 0x220;
        slot = *(u8 **)(object + 0x38) + offset;
        if ((*(s16 *)(slot + 0x104) & 1) == 1) {
            u8 *a0 = slot + 0x104;
            func_002b83e0(a0, *(s64 *)(a0 + 0x28), *(s32 *)(a0 + 0x75), *(s32 *)(a0 + 0x75), *(u8 *)(a0 + 0x5E), 0, arg5, arg6, (f32)src.dimensions.height, fparg0, arg_sp0, 0);
        }
    }
    if (flag == 0) {
        if ((value >= 10) || (value == 0)) {
            u8 *digit; u8 *slot; s32 offset;
            offset = (s32)next_index * 0x220;
            digit = D_0063F1F0 + ((s32)tens * 0x10);
            slot = *(u8 **)(object + 0x38) + offset;
            *(f32 *)(slot + 0x1F4) = *(f32 *)(digit + 0);
            *(f32 *)(slot + 0x1F8) = *(f32 *)(digit + 4);
            *(f32 *)(slot + 0x1FC) = *(f32 *)(digit + 8);
            *(f32 *)(slot + 0x200) = *(f32 *)(digit + 0xC);
            func_002b2970((u8 *)&pos2, pos1.x - 18.0f, pos1.y);
            tmpA = pos2;
            copy2 = src.representation;
            tmpCol2 = spCC;
            *(f32 *)(slot + 0x12C) = tmpA.x;
            *(f32 *)(slot + 0x130) = tmpA.y;
            *(f32 *)(slot + 0x1A0) = 1.0f;
            *(f32 *)(slot + 0x194) = 1.0f;
            *(u8 *)(slot + 0x162) = ((u8 *)&tmpCol2)[3];
            *(u8 *)(slot + 0x179) = ((u8 *)&spCC)[0];
            *(u8 *)(slot + 0x17A) = ((u8 *)&spCC)[1];
            *(u8 *)(slot + 0x17B) = ((u8 *)&spCC)[2];
            *(u8 *)(slot + 0x17C) = ((u8 *)&spCC)[3];
            *(s32 *)(slot + 0x1C4) = 0;
            *(f32 *)(slot + 0x108) = fparg0;
            *(s16 *)(slot + 0x104) = (s16)(*(s16 *)(slot + 0x104) | 1);
            ((FclBoundsPacket *)(slot + 0x204))->representation = copy2;
            *(s16 *)(slot + 0x100) = arg7;
            func_002b2970((u8 *)&tmpB, pos1.x - 18.0f, pos1.y);
            func_002b83e0(slot + 0x104, *(s64 *)((u8 *)&tmpB), spCC, spCC, 0, ((u8 *)&spCC)[3], arg5, arg6, (f32)src.dimensions.height, fparg0, arg_sp0, 0);
        }
    } else {
        u8 *slot;
        s32 offset;
        offset = (s32)next_index * 0x220;
        slot = *(u8 **)(object + 0x38) + offset;
        if ((*(s16 *)(slot + 0x104) & 1) == 1) {
            u8 *a0 = slot + 0x104;
            func_002b2970((u8 *)&tmpC, pos1.x - 18.0f, *(f32 *)(a0 + 0x2C));
            func_002b83e0(a0, *(s64 *)((u8 *)&tmpC), *(s32 *)(a0 + 0x75), *(s32 *)(a0 + 0x75), *(u8 *)(a0 + 0x5E), 0, arg5, arg6, (f32)src.dimensions.height, fparg0, arg_sp0, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba080);
#endif
/* Floor: 186 differing words (probe_variants) over 207 fnalign edits (+2 reloc-only), 230 emitted against */
/* retail's 230 (100%, 8B zero tail in 928B window). WALL: saved-register rotation (retail s1=a2/s2=t1 */
/* vs object s2=a2/s1=t1, invariant under field/value decl swap) plus spill offsets (sd a3 96 vs 152, */
/* sw t0 108 vs 188) and scheduling cascade; frame now 0xC0 both sides after `opt_common_subs off` */
/* (old 0xD0 claim stale). Ruled out: inclusive-bound flip >=10->>9 (neutral at 186). */
/* measured 002ba5d0: `opt_common_subs off` inside the guard is worth 21 words (207 -> 186); retail rematerialises what b210 hoists. */
// FUN_002BA5D0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
/* Guarded body: 186 words over 207 edits, 230/230 instrs (920B/928B, 8B zero tail); frame 0xC0 both sides, s1/s2 rotation remains. */
void func_002ba5d0(u8 *arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4, s64 arg5, f32 fparg0)
{
    FclBoundsPacket src;
    FclBoundsBytes copy1, copy2;
    struct Float2 { f32 x; f32 y; } pos1, pos2;
    s64 field;
    u8 *object;
    s64 sp60;
    s32 sp6C;
    s32 spBC;
    s32 spB8;
    s16 value;
    s16 pair_index;
    s16 next_index;
    s8 ones;
    s8 tens;
    object = arg0;
    field = arg5;
    sp60 = arg3;
    sp6C = arg4;
    func_002b29e0((u8 *)&src, 88.0f, 17.0f);
    func_002b2970((u8 *)&pos1, *(f32 *)((u8 *)&sp60) + 284.0f, *(f32 *)((u8 *)&sp60 + 4) + 6.0f);
    value = (s16)arg2;
    if ((value == -1) || (value == 0)) { ones = 10; tens = 10; }
    else { ones = (s8)(value % 10); tens = (s8)(value / 10); }
    pair_index = (s16)((s16)arg1 * 2);
    next_index = (s16)(pair_index + 1);
    {
        u8 *digit; u8 *slot; s32 offset;
        offset = (s32)pair_index * 0x220;
        digit = D_0063F1F0 + ((s32)ones * 0x10);
        slot = *(u8 **)(object + 0x38) + offset;
        *(f32 *)(slot + 0x1F4) = *(f32 *)(digit + 0);
        *(f32 *)(slot + 0x1F8) = *(f32 *)(digit + 4);
        *(f32 *)(slot + 0x1FC) = *(f32 *)(digit + 8);
        *(f32 *)(slot + 0x200) = *(f32 *)(digit + 0xC);
        copy1 = src.representation;
        *(f32 *)(slot + 0x12C) = pos1.x;
        *(f32 *)(slot + 0x130) = pos1.y;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        spBC = sp6C;
        *(u8 *)(slot + 0x162) = ((u8 *)&spBC)[3];
        *(u8 *)(slot + 0x179) = ((u8 *)&sp6C)[0];
        *(u8 *)(slot + 0x17A) = ((u8 *)&sp6C)[1];
        *(u8 *)(slot + 0x17B) = ((u8 *)&sp6C)[2];
        *(u8 *)(slot + 0x17C) = ((u8 *)&sp6C)[3];
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = fparg0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
        ((FclBoundsPacket *)(slot + 0x204))->representation = copy1;
        *(s16 *)(slot + 0x100) = field;
        *(s16 *)(slot + 0x104) = 0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
    }
    if ((value >= 10) || (value == 0)) {
        u8 *digit; u8 *slot; s32 offset;
        offset = (s32)next_index * 0x220;
        digit = D_0063F1F0 + ((s32)tens * 0x10);
        slot = *(u8 **)(object + 0x38) + offset;
        *(f32 *)(slot + 0x1F4) = *(f32 *)(digit + 0);
        *(f32 *)(slot + 0x1F8) = *(f32 *)(digit + 4);
        *(f32 *)(slot + 0x1FC) = *(f32 *)(digit + 8);
        *(f32 *)(slot + 0x200) = *(f32 *)(digit + 0xC);
        func_002b2970((u8 *)&pos2, pos1.x - 18.0f, pos1.y);
        copy2 = src.representation;
        *(f32 *)(slot + 0x12C) = pos2.x;
        *(f32 *)(slot + 0x130) = pos2.y;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        spB8 = sp6C;
        *(u8 *)(slot + 0x162) = ((u8 *)&spB8)[3];
        *(u8 *)(slot + 0x179) = ((u8 *)&sp6C)[0];
        *(u8 *)(slot + 0x17A) = ((u8 *)&sp6C)[1];
        *(u8 *)(slot + 0x17B) = ((u8 *)&sp6C)[2];
        *(u8 *)(slot + 0x17C) = ((u8 *)&sp6C)[3];
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = fparg0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
        ((FclBoundsPacket *)(slot + 0x204))->representation = copy2;
        *(s16 *)(slot + 0x100) = field;
        *(s16 *)(slot + 0x104) = 0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
    } else {
        u8 *slot; s32 offset;
        offset = (s32)next_index * 0x220;
        slot = *(u8 **)(object + 0x38) + offset;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) & ~1;
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba5d0);
#endif
/* Preserve the RGBA snapshot and later alpha reload across byte stores.
   Measured: object 168B/window 176B, no instruction differences; 8B zero tail. */
#pragma opt_common_subs off
// FUN_002BA970
void func_002ba970(u8 *arg0, s16 arg1, u32 color)
{
    s32 first;
    s32 second;
    u8 *p;
    u8 r, g, b, a;
    s32 index;
    u8 alpha;

    index = arg1 * 2;
    first = (s16)index * 0x220;
    p = *(u8 **)(arg0 + 0x38) + first;
    r = ((u8 *)&color)[0];
    g = ((u8 *)&color)[1];
    b = ((u8 *)&color)[2];
    a = ((u8 *)&color)[3];
    p[0x179] = r;
    p[0x17A] = g;
    p[0x17B] = b;
    p[0x17C] = a;
    second = (s16)(index + 1) * 0x220;
    p = *(u8 **)(arg0 + 0x38) + second;
    p[0x179] = r;
    p[0x17A] = g;
    p[0x17B] = b;
    p[0x17C] = a;
    p = *(u8 **)(arg0 + 0x38) + first;
    alpha = ((u8 *)&color)[3];
    p[0x162] = alpha;
    p = *(u8 **)(arg0 + 0x38) + second;
    p[0x162] = alpha;
}
#pragma opt_common_subs on
// FUN_002BAA20
void func_002baa20(void)
{
    func_002baa90(D_00882F60);
    func_002baa50();
}
// FUN_002BAA50
void func_002baa50(void)
{
    s32 i;
    u8 **t;

    i = 0;
    t = D_00882F40;
    while (i < 5) {
        t[i] = NULL;
        i++;
    }
}
// FUN_002BAB80
s64 func_002bab80(void *arg0)
{
    s32 **temp_18;
    s32 *temp_2;
    s64 temp_16;
    s32 temp_4;
    s64 var_2;
    extern s32 func_002774d0(s32 arg0);
    extern s32 func_002bbf80(s32 *arg0, s32 arg1);
    extern void func_0044ea90(const void *arg0, s32 arg1);

    temp_16 = func_002bacb0();
    if (temp_16 == -1) {
        return -1;
    }
    func_0044ea90(&D_0063F2A0, 0x90);
    temp_2 = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
    {
        s32 **temp_5;

        temp_5 = (s32 **)&D_00882F40[(s8)temp_16];
        *temp_5 = temp_2;
        if (temp_2 != NULL) {
            temp_2[0] = -1;
            *(s8 *)(temp_2 + 1) = 0;
            *(s8 *)((u8 *)temp_2 + 5) = 0;
            *(s32 *)(temp_2 + 2) = -1;
            *(s8 *)((u8 *)temp_2 + 0xC) = 1;
            *(s8 *)((u8 *)temp_2 + 0xD) = 1;
        }
        temp_4 = (s32)temp_16;
        (&D_00764670)[(s8)temp_4] = -1;
        var_2 = -1;
        if (**temp_5 < 0) {
            temp_18 = (s32 **)&D_00882F40[(s8)temp_4];
            **temp_18 = func_002774d0((s32)arg0);
            func_002bbf80(*temp_18, 0);
            var_2 = temp_16;
        }
    }
    return var_2;
}
// FUN_002BACB0
s8 func_002bacb0(void) {
    s32 i = 0;
    u8 **t = D_00882F40;

    while (i < 5) {
        if (t[i] == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002BAD10
s32 func_002bad10(s32 arg0)
{
    s32 *temp_2;
    s32 temp_4;

    temp_2 = func_002bbf70();
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = temp_2[0];
    if (temp_4 < 0) {
        return 0;
    }
    func_00278610(temp_4, 0);
    func_00278170(temp_2[0], 0x200000);
    func_002778c0(temp_2[0], arg0, 0);
    func_00277010(temp_2[0], -1);
    *(s8 *)((u8 *)temp_2 + 4) = 1;
    return 1;
}
// FUN_002BADC0
s32 func_002badc0(s64 arg0, s32 arg1)
{
    s32 temp_4;
    u8 **temp_17;

    temp_17 = &D_00882F40[(s8)arg0];
    temp_4 = *(s32 *)*temp_17;
    if (temp_4 < 0) {
        return 0;
    }
    func_00278610(temp_4, 0);
    func_00278170(*(s32 *)*temp_17, 0x200000);
    func_002778c0(*(s32 *)*temp_17, arg1, 0);
    func_00277010(*(s32 *)*temp_17, -1);
    *(s8 *)(*temp_17 + 4) = 1;
    return 1;
}
// FUN_002BAE80
s32 func_002bae80(s64 arg0, s32 arg1)
{
    s32 temp_4;
    u8 **temp_17;

    temp_17 = &D_00882F40[(s8)arg0];
    temp_4 = *(s32 *)*temp_17;
    if (temp_4 < 0) {
        return 0;
    }
    func_00278610(temp_4, 1);
    func_00278170(*(s32 *)*temp_17, 0x200000);
    func_002778c0(*(s32 *)*temp_17, arg1, 0);
    func_00277010(*(s32 *)*temp_17, -1);
    *(s8 *)(*temp_17 + 4) = 1;
    return 1;
}
// FUN_002BAF40
s32 func_002baf40(s32 arg0) {
    s32 *p;

    p = func_002bbf70();
    if (p == NULL) {
        return 0;
    }
    if (*p < 0) {
        return 0;
    }
    p[2] = arg0;
    *((s8 *)p + 0xD) = func_002bb0e0();
    iGpffffb578 = 0;
    return 1;
}
// FUN_002BAFC0
s32 func_002bafc0(s64 arg0, s32 arg1)
{
    u8 **temp_16;
    u8 *temp_3;

    temp_16 = &D_00882F40[(s8)arg0];
    temp_3 = *temp_16;
    if (temp_3 == NULL) {
        return 0;
    }
    if (*(s32 *)temp_3 < 0) {
        return 0;
    }
    *(s32 *)(temp_3 + 8) = arg1;
    *(s8 *)(*temp_16 + 0xD) = func_002bb0e0();
    iGpffffb578 = 0;
    return 1;
}
// FUN_002BB180
s8 func_002bb180(s64 arg0)
{
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p == NULL) {
        return -1;
    }
    return *(s8 *)(p + 0xD);
}
// FUN_002BB420
s32 func_002bb420(s64 arg0)
{
    s32 temp_4;
    u8 **temp_17;
    u8 *temp_2;

    temp_17 = &D_00882F40[(s8)arg0];
    temp_2 = *temp_17;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)temp_2;
    if (temp_4 < 0) {
        return 0;
    }
    func_00276e70(temp_4, 0);
    func_00277250(*(s32 *)*temp_17);
    func_00277ad0(*(s32 *)*temp_17, 0);
    func_002bbe90(arg0, 1);
    *(s8 *)(*temp_17 + 4) = 0;
    return 1;
}
// FUN_002BB4E0
s32 func_002bb4e0(void) {
    s32 *temp_2;
    s32 temp_4;

    temp_2 = (s32 *)(func_002bbf70());
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = (s32)(*(s32 *)((u8 *)(temp_2) + 0));
    if (temp_4 >= 0) {
        func_002777f0(temp_4);
        *(s32 *)((u8 *)(temp_2) + 0) = -1;
        *(s8 *)((u8 *)(temp_2) + 4) = 0;
        *(s8 *)((u8 *)(temp_2) + 5) = 0;
    }
    func_002e0dd0();
    return 1;
}

// FUN_002BB550
s32 func_002bb550(s64 arg0)
{
    s32 temp_4;
    u8 **temp_16;
    u8 *temp_2;

    temp_16 = D_00882F40 + (s8)arg0;
    temp_2 = *temp_16;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)(temp_2 + 0);
    if (temp_4 >= 0) {
        func_002777f0(temp_4);
        *(s32 *)(*temp_16 + 0) = -1;
        *(s8 *)(*temp_16 + 4) = 0;
        *(s8 *)(*temp_16 + 5) = 0;
        jtbl_008873EC[0](*temp_16);
        *temp_16 = NULL;
    }
    func_002e0dd0();
    return 1;
}
// FUN_002BB680
s32 func_002bb680(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p == NULL) {
        return 0;
    }
    if (*(s32 *)p < 0) {
        return 0;
    }
    if (*(s8 *)(p + 5) != 0) {
        if (*(s8 *)(p + 4) == 2) {
            return 0;
        }
    }
    return *(s8 *)(p + 4);
}

// FUN_002BB7C0
void func_002bb7c0(s32 arg0)
{
    typedef struct {
        s32 id;
        s8 status;
        s8 flag;
        u8 pad6[2];
        s32 next;
        s8 fieldC;
        s8 result;
    } Item;
    s32 temp_4;
    s8 temp_5;
    Item *temp_2;

    temp_2 = (Item *)func_002bbf70();
    if ((temp_2 != NULL) && (temp_4 = temp_2->id, temp_4 >= 0)) {
        temp_5 = temp_2->status;
        switch (temp_5) {
        case 0:
            return;
        case 1:
            if (func_00276e10(temp_4, temp_5) < 0) {
                temp_2->status = 2;
                break;
            }
            break;
        case 2:
        {
            s32 *temp_2_2;
            s32 *temp_2_3;
            s32 temp_4_2;
            s32 var_3;
            s32 var_3_2;

            if (temp_2->next >= 0) {
                if (iGpffffb578 == 1) {
                    func_002786c0(temp_4, 6, 1);
                }
                func_00277fd0(temp_2->id, temp_2->fieldC);
                func_00277be0(temp_2->id, temp_2->next);
                temp_2->next = -1;
            }
            if (temp_2->flag == 0) {
                temp_2_2 = func_002bbf70();
                if (temp_2_2 == NULL) {
                    var_3 = 0;
                } else {
                    temp_4_2 = temp_2_2[0];
                    if (temp_4_2 < 0) {
                        var_3 = 0;
                    } else if (func_00276fb0(temp_4_2) < 0) {
                        var_3 = 0;
                    } else {
                        temp_2_3 = func_002bbf70();
                        if (temp_2_3 == NULL) {
                            var_3_2 = -1;
                        } else {
                            temp_4_2 = temp_2_3[0];
                            if (temp_4_2 < 0) {
                                var_3_2 = -1;
                            } else {
                                var_3_2 = func_00277070(temp_4_2);
                            }
                        }
                        *((s8 *)temp_2_2 + 0xD) = var_3_2;
                        var_3 = 1;
                    }
                }
                if (var_3 == 0) {
                    temp_2->status = 3;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            Item *temp_2_4;

            temp_2_4 = (Item *)func_002bbf70();
            if (temp_2_4 != NULL) {
                temp_4 = temp_2_4->id;
                if (temp_4 >= 0) {
                    func_00276e70(temp_4, 0);
                    if (arg0 != 0) {
                        func_00277250(temp_2_4->id);
                    }
                    func_00277ad0(temp_2_4->id, 0);
                    func_002bbdd0(1);
                    temp_2_4->status = 0;
                }
            }
            break;
        }
        }
    }
}
// FUN_002BB9E0
void func_002bb9e0(u8 *arg0, s32 arg1)
{
    typedef struct {
        s32 id;
        s8 status;
        s8 flag;
        u8 pad6[2];
        s32 next;
        s8 fieldC;
        s8 result;
    } Item;
    extern void func_002bbe90();
    s32 temp_4;
    s32 saved_arg1;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 var_3;
    s64 temp_18;
    s8 temp_5;
    s32 var_4;
    s32 var_4_2;
    Item **temp_16;
    Item **temp_16_2;
    Item **temp_17;
    Item **temp_5_2;
    Item *temp_2;
    Item *temp_2_2;
    Item *temp_3;
    Item *temp_3_2;
    Item *temp_4_2;
    Item *temp_6;
    saved_arg1 = arg1;
    temp_18 = (s8)arg0;
    temp_17 = &((Item **)D_00882F40)[(s8)temp_18];
    temp_6 = *temp_17;
    if ((temp_6 != NULL) && (temp_4 = temp_6->id, temp_4 >= 0)) {
        temp_5 = temp_6->status;
        switch (temp_5) {
        case 0:
            return;
        case 1:
            if (func_00276e10(temp_4, temp_5, temp_6) < 0) {
                (*temp_17)->status = 2;
                return;
            }
            break;
        case 2:
            if (temp_6->next >= 0) {
                if (iGpffffb578 == 1) {
                    func_002786c0(temp_4, 6, 1);
                }
                temp_16 = &((Item **)D_00882F40)[(s8)arg0];
                temp_2 = *temp_16;
                func_00277fd0(temp_2->id, temp_2->fieldC);
                temp_2_2 = *temp_16;
                func_00277be0(temp_2_2->id, temp_2_2->next);
                (*temp_16)->next = -1;
            }
            temp_4_2 = *temp_17;
            if (temp_4_2->flag == 0) {
                if (temp_4_2 == NULL) {
                    var_3 = 0;
                } else {
                    temp_4_3 = temp_4_2->id;
                    if (temp_4_3 < 0) {
                        var_3 = 0;
                    } else if (func_00276fb0(temp_4_3) < 0) {
                        var_3 = 0;
                    } else {
                        temp_3 = *temp_17;
                        if (temp_3 == NULL) {
                            var_4 = -1;
                        } else {
                            temp_4_4 = temp_3->id;
                            if (temp_4_4 < 0) {
                                var_4 = -1;
                            } else {
                                var_4 = func_00277070(temp_4_4);
                            }
                        }
                        (*temp_17)->result = var_4;
                        var_3 = 1;
                    }
                }
                if (var_3 == 0) {
                    temp_5_2 = &((Item **)D_00882F40)[(s8)arg0];
                    (*temp_5_2)->status = 3;
                    temp_3_2 = *temp_5_2;
                    if (temp_3_2 == NULL) {
                        var_4_2 = -1;
                    } else {
                        temp_4_5 = temp_3_2->id;
                        if (temp_4_5 < 0) {
                            var_4_2 = -1;
                        } else {
                            var_4_2 = func_00277070(temp_4_5);
                        }
                    }
                    (&iGpffffb580)[(s8)temp_18] = var_4_2;
                    return;
                }
            }
            break;
        case 3:
            if ((temp_6 != NULL) && (temp_4 = temp_6->id, temp_4 >= 0)) {
                func_00276e70(temp_4, 0);
                if (saved_arg1 != 0) {
                    func_00277250((*temp_17)->id);
                }
                temp_16_2 = &((Item **)D_00882F40)[(s8)arg0];
                func_00277ad0((*temp_16_2)->id, 0);
                func_002bbe90(arg0, 1);
                (*temp_16_2)->status = 0;
            }
            break;
        }
    }
}
// FUN_002BBCC0
void func_002bbcc0(void)
{
    func_002bb7c0(1);
}
// FUN_002BBCF0
void func_002bbcf0(u8 *arg0) {
    func_002bb9e0(arg0, 1);
}



// FUN_002BBD80
void func_002bbd80(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p != NULL) {
        func_00278450(*(s32 *)p);
    }
}

// FUN_002BC0B0
void func_002bc0b0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    f32 f0;
    f32 f1;
    f32 f2;
    func_002bc0e0(f0, f1, f2, arg0, arg1, arg2, 1, arg3, arg4);
}



// FUN_002BC0E0
 s32 func_002bc0e0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    extern s32 func_00106600(s16 id);
    extern u32 func_00106880(s16 arg0);
    extern s64 func_00106b80(s32 arg0);
    extern s32 func_00278e90(s32 arg0);
    extern s32 func_002791f0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    extern s32 func_00279470(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10);
    extern s32 D_0063F2F0[];
    extern s32 D_0063F310[];
    extern s32 D_0063F2C0[];
    s32 spC0[6];
    s32 sp90[9];
    s32 *src;
    s32 *dst;
    u32 temp_22;
    s32 *src2;
    s32 *dst2;
    s32 loop;
    s32 loop2;
    s32 temp_1;
    s32 temp_2;
    s32 temp_index;
    s32 temp_item_index;
    s32 temp_item;
    s32 temp_level;
    u32 temp_index_2;
    s32 temp_count;

    src = D_0063F2F0;
    dst = spC0;
    loop = 3;
    do {
        temp_1 = src[0];
        temp_2 = src[1];
        src += 2;
        loop -= 1;
        dst[0] = temp_1;
        dst[1] = temp_2;
        dst += 2;
    } while (loop > 0);
    src2 = D_0063F310;
    dst2 = sp90;
    loop2 = 9;
    do {
        temp_1 = *src2;
        src2 += 1;
        loop2 -= 1;
        *dst2 = temp_1;
        dst2 += 1;
    } while (loop2 > 0);
    switch (arg4) {
    case 0:
        if (arg5 >= 0x400) {
            temp_index = 5;
        } else {
            temp_index = (s32)func_00106880((s16)arg5);
        }
        temp_item_index = spC0[temp_index];
        arg5 = (s16)func_00106b80((s16)arg5);
        goto block_23;
    case 1:
        temp_index_2 = arg5 & 0xFFFF;
        temp_item_index = spC0[func_00106880((s16)temp_index_2)];
        temp_item = D_0063F2B0[temp_item_index];
        temp_count = (s16)func_00106b80((s16)temp_index_2);
        if ((u32)func_00278e90(temp_item) < (u32)temp_count) {
            return 0;
        }
        temp_level = arg5 >> 16;
        if ((u32)func_00278e90(D_0063F2C0[0]) < (u32)temp_level) {
            return 0;
        }
        func_00279470(fparg0, fparg1, fparg2,
                      arg0, arg1, arg2, 1, temp_item, temp_count,
                      D_0063F2C0[0], temp_level);
        return 0;
    case 2:
        temp_index_2 = func_00106600((s16)arg5) & 0xFF;
        temp_item_index = spC0[func_00106880((s16)temp_index_2)];
        temp_item = D_0063F2B0[temp_item_index];
        temp_count = (s16)func_00106b80((s16)temp_index_2);
        if ((u32)func_00278e90(temp_item) < (u32)temp_count) {
            return 0;
        }
        temp_22 = func_00278e90(D_0063F2C0[0]);
        if (temp_22 < (u32)(func_00106600((s16)arg5) & 0xFF)) {
            return 0;
        }
        func_00279470(fparg0, fparg1, fparg2,
                      arg0, arg1, arg2, 1, temp_item, temp_count,
                      D_0063F2C0[0], func_00106600((s16)arg5) & 0xFF);
        return 0;
    default:
        temp_item_index = sp90[arg4];
        goto block_23;
    }
block_23:
    temp_item = D_0063F2B0[temp_item_index];
    if ((u32)func_00278e90(temp_item) < (u32)arg5) {
        return 0;
    }
    func_002791f0(fparg0, fparg1, fparg2,
                  arg0, arg1, arg2, arg3, temp_item, arg5);
    return 0;
}
/* Preserve the word-sized ID through both metadata queries. Capture the
 * remaining inputs before those calls; scoped propagation preserves their
 * retail entry order, all 740 code bytes, and the six-way table. */
#pragma push
#pragma opt_propagation off
// FUN_002BC4B0
void func_002bc4b0(f32 inputDepth, s32 arg0, s32 arg1, s32 arg2,
                    s32 inputArg3, s32 inputArg4, s32 inputArg5)
{
    extern u32 func_00106850(s32 arg0);
    extern s64 func_00106b80(s32 arg0);
    extern s32 func_002791f0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    u32 temp_2;
    f32 fparg0;
    s32 arg3;
    s32 arg4;
    s32 arg5;

    fparg0 = inputDepth;
    arg3 = inputArg3;
    arg4 = inputArg4;
    arg5 = inputArg5;
    temp_2 = func_00106850(arg0);
    switch (temp_2) {
    case 0:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[0],
                      (s16)func_00106b80(arg0));
        return;
    case 1:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[1],
                      (s16)func_00106b80(arg0));
        return;
    case 2:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[2],
                      (s16)func_00106b80(arg0));
        return;
    case 3:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[4],
                      (s16)func_00106b80(arg0));
        return;
    case 4:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[5],
                      (s16)func_00106b80(arg0));
        return;
    case 5:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[7],
                      (s16)func_00106b80(arg0));
    default:
        return;
    }
}
#pragma pop
// FUN_002BC7A0
void func_002bc7a0(s32 item, f32 x, f32 y, f32 depth,
                    s32 color, s32 font, s32 mode, s32 table)
{
    extern s32 func_002791f0(f32 x, f32 y, f32 depth, s32 color, s32 font,
                            s32 mode, s32 flags, s32 table, s32 item);
    func_002791f0(x, y, depth, color, font, mode, 1, D_0063F2B0[(s8)table], item);
}

// FUN_002BC7F0
void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0, f32 fparg1, f32 fparg2) {
    func_00279350(fparg0, fparg1, fparg2, arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0, &D_00793E80[arg5 * 0x30]);
}

// FUN_002BC860
void func_002bc860(f32 x, f32 y, f32 depth,
                    s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    extern s32 func_002791f0(f32 x, f32 y, f32 depth, s32 arg0, s32 arg1,
                            s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    func_002791f0(x, y, depth, arg0, arg1, arg2, 1, D_0063F2C8[0], arg3);
}
// FUN_002BC890
s32 func_002bc890(u8 *arg0, s32 arg1)
{
    s32 temp_3;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_4;
    u8 *owner;
    u8 *var_4;
    u8 *var_5;

    if (arg0 == NULL) func_0046d730(&D_0063F2A0, 0x541);
    if (arg1 < 0) goto invalid_arg;
    if (arg1 > 0xB) goto invalid_arg;
    goto valid_arg;
invalid_arg:
    func_0046d730(&D_0063F2A0, 0x542);
valid_arg:
    temp_2 = arg0 + (arg1 * 0xC);
    temp_16 = temp_2 + 0x1C;
    temp_3 = *(s32 *)temp_16;
    if (!(temp_3 & 2)) {
        var_4 = *(u8 **)(*(u8 **)(arg0 + 0x18) + 4);
        goto loop_test;
loop_body:
        var_5 = *(u8 **)(var_4 + 0x14);
        if (*(s32 *)(var_5 + 4) == arg1) {
            owner = var_5;
        } else {
            var_4 = *(u8 **)(var_4 + 0x10);
loop_test:
            if (var_4 != NULL) {
                goto loop_body;
            }
            owner = NULL;
        }
        goto loop_done;
loop_done:
        if (owner == NULL) {
            *(s32 *)(temp_16 + 4) = arg1;
            temp_4 = *(u8 **)(arg0 + 0x18);
            temp_2_2 = func_002e2170(temp_4, *(u16 *)(temp_4 + 0x10) + 1, 0);
            if (temp_2_2 == NULL) func_0046d730(&D_007488E8, 0x52);
            *(u8 **)(temp_2_2 + 0x14) = temp_16;
            return 1;
        }
    }
    if (temp_3 & 4) *(s32 *)temp_16 = temp_3 & ~4;
    return 0;
}
// FUN_002BC9E0
s32 func_002bc9e0(u8 *arg0)
{
    u8 sp40[0x20];
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_4_3;
    s32 var_17;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_4_2;
    u8 *var_16;

    if (arg0 == NULL) {
        func_0046d730(&D_0063F2A0, 0x558);
    }
    temp_18 = *(u8 **)(*(u8 **)(arg0 + 0x18) + 4);
    if (temp_18 != NULL) {
        temp_17 = *(u8 **)(temp_18 + 0x14);
        temp_4 = *(s32 *)(temp_17 + 8);
        if (temp_4 == 0) {
            if (*(s32 *)(temp_17 + 4) == 0) {
                func_00442088(sp40, &D_0063F340);
            } else if ((func_00110d60((s16)func_001060b0()) & 1) != 0) {
                func_00442088(sp40, &D_0063F360, *(s32 *)(temp_17 + 4));
            } else {
                func_00442088(sp40, &D_0063F380, *(s32 *)(temp_17 + 4));
            }
            *(s32 *)(temp_17 + 8) = func_0046aea0(sp40);
        } else if (func_0046a750(temp_4) != 0) {
            *(s32 *)(temp_17 + 0) = *(s32 *)(temp_17 + 0) | 2;
            temp_4_2 = *(u8 **)(arg0 + 0x18);
            func_002e2240(temp_4_2, temp_4_2 + 4, temp_18);
        }
    }
    var_16 = arg0 + 0x1C;
    var_17 = 0;
    goto loop_19;
loop_20:
    temp_3 = *(s32 *)var_16;
    if (temp_3 & 4) {
        temp_4_3 = *(s32 *)(var_16 + 8);
        if (temp_4_3 != 0) {
            if (func_0046a750(temp_4_3) != 0) {
                temp_3_2 = *(s32 *)var_16 & ~4;
                *(s32 *)var_16 = temp_3_2;
                *(s32 *)var_16 = temp_3_2 & ~2;
                func_0046b0d0(*(void **)(var_16 + 8));
                *(s32 *)(var_16 + 8) = 0;
            }
        } else {
            temp_3_3 = temp_3 & ~4;
            *(s32 *)var_16 = temp_3_3;
            *(s32 *)var_16 = temp_3_3 & ~2;
        }
    }
    var_16 += 0xC;
    var_17 += 1;
loop_19:
    if (var_17 < 0xB) {
        goto loop_20;
    }
    return 0;
}
// FUN_002BCBC0
s32 func_002bcbc0(s32 arg0, s32 arg1)
{
    u8 *temp_3;

    if (arg0 == 0) {
        func_0046d730(D_0063F2A0, 0x58F);
    }
    if (arg1 < 0) {
        goto error;
    }
    if (arg1 <= 0xB) {
        goto done;
    }
error:
    func_0046d730(D_0063F2A0, 0x590);
done:
    temp_3 = (u8 *)(arg0 + arg1 * 0xC);
    *(s32 *)(temp_3 + 0x1C) |= 4;
    return 0;
}
// FUN_002BD280
s32 func_002bd280(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    s32 temp_20;
    u8 *temp_21;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;

    temp_21 = (u8 *)iGpffffb57c;
    if (*(s32 *)(temp_21 + 0xC) == 0) {
        func_0046d730(&D_0063F2A0, 0x668);
    }
    temp_20 = *(s32 *)(temp_21 + 0xC);
    temp_4 = *(u8 **)(temp_21 + 0);
    temp_2 = func_002e2170(temp_4, *(u16 *)(temp_4 + 0x10) + 1, 0x30);
    temp_3 = *(u8 **)(temp_2 + 0x14);
    *(u8 **)(temp_3 + 0) = temp_2;
    *(s32 *)(temp_3 + 0x2C) = arg0;
    *(s32 *)(temp_3 + 0x20) = arg1;
    *(s32 *)(temp_3 + 0x24) = arg2;
    *(s32 *)(temp_3 + 0x28) = temp_20;
    *(s16 *)(temp_3 + 0xE) = arg3;
    return 0;
}
// FUN_002BD3E0
void func_002bd3e0(void) {
    func_002bcc60(D_0072466C);
}



// FUN_002BD410
void func_002bd410(void)
{
    func_0045a9a0(1, 0);
    func_002bd440();
}
// FUN_002BD7B0
s32 func_002bd7b0(void)
{
    u8 *p;
    s32 temp_2;

    p = (u8 *)D_00882F60;
    if (p != NULL) {
        *(s32 *)(p + 0) = -1;
        *(s8 *)(p + 4) = 0;
        *(s8 *)(p + 5) = 0;
        *(s32 *)(p + 8) = -1;
        *(s8 *)(p + 0xC) = 1;
        *(s8 *)(p + 0xD) = 1;
    }
    if (*(s32 *)(p + 0) < 0) {
        temp_2 = func_002774d0();
        *(s32 *)(p + 0) = temp_2;
        func_00278610(temp_2, 1);
        return 1;
    }
    return 0;
}
// FUN_002BD840
s32 func_002bd840(s32 arg0)
{
    u8 *p;

    p = (u8 *)D_00882F60;
    if (*(s32 *)(p + 0) < 0) {
        return 0;
    }
    func_00278610(*(s32 *)(p + 0), 1);
    func_00278170(*(s32 *)(p + 0), 0x200000);
    func_002778c0(*(s32 *)(p + 0), arg0, 0);
    *(s8 *)(p + 4) = 1;
    func_00277010(*(s32 *)(p + 0), -1);
    return 1;
}
// FUN_002BD8E0
s32 func_002bd8e0(u8 *arg0)
{
    s8 temp_3;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s8 *)(temp_16 + 0);
    switch (temp_3) {
    case 1:
        func_00144c90(8, 4);
        *(s8 *)(temp_16 + 0) = 2;
    case 2:
        if ((func_00144f60() != 0) && (func_0015f660() != 0)) {
            if (func_002cb6a0(*(s32 *)(temp_16 + 4)) == 0) {
                return 0;
            }
            func_0045a3e0(0x15, 1);
            temp_17 = func_00457120();
            func_004577d0(temp_17, func_0014b4d0());
            temp_17_2 = func_00457120();
            func_003e9cb0(*(s32 *)(temp_17_2 + 4), (void *)func_0014b450(), 0);
            *(s8 *)(temp_16 + 0) = 3;
        }
        goto block_26;
    case 3:
        func_00122640(1, 0);
        *(s8 *)(temp_16 + 0) = 4;
    case 4:
        if (func_00122720() != 0) {
            func_002caa00(*(s32 *)(temp_16 + 4), 0xD);
            *(s8 *)(temp_16 + 0) = 7;
        }
        goto block_26;
    case 5:
        func_00122520(1, 0);
        *(s8 *)(temp_16 + 0) = 6;
    case 6:
        if (func_00122720() != 0) {
            *(s8 *)(temp_16 + 0) = 0x11;
        }
        goto block_26;
    case 7:
        if (func_00452380(&D_0063F3B0) == 0) {
            *(s8 *)(temp_16 + 0) = 5;
        }
        goto block_26;
    case 17:
        return -1;
    case 35:
        return -1;
    default:
    block_26:
        return 0;
    }
}
// FUN_002BDB10
void func_002bdb10(u8 *arg0)
{
    func_00145080();
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_002BDFF0
s32 func_002bdff0(s64 arg0)
{
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;

    if (func_00106850() != 3) {
        goto false_result;
    }
    temp_16 = func_002be100(func_00106ac0(arg0) & 0xFF) & 0xFF;
    if (temp_16 < (func_002be100(func_002e78a0()) & 0xFF)) {
        return 1;
    }
    temp_16_2 = func_002be100(func_00106ac0(arg0) & 0xFF) & 0xFF;
    if (temp_16_2 != (func_002be100(func_002e78a0()) & 0xFF)) {
        goto false_result;
    }
    temp_16_3 = (s8)func_00106af0(arg0);
    if (temp_16_3 <= (func_002e78e0() & 0xFF)) {
        return 1;
    }
false_result:
    return 0;
}
// FUN_002BE100
s32 func_002be100(s32 arg0) {
    s32 i = 0;
    s32 key = arg0 & 0xFF;
    s8 *t = D_007488F8;

    while ((i & 0xFF) < 0xC) {
        if (key == t[i & 0xFF]) {
            return i;
        }
        i = (i + 1) & 0xFF;
    }
    return 0;
}

// FUN_002BE160
s32 func_002be160(u8 *arg0, s32 arg1) {
    s32 n = arg1 & 0xFFFF;
    if (n == 0) {
        return 1;
    }
    return (clndGetMoonPhase() & 0xFF) >= n;
}

// FUN_002BE1B0
void func_002be1b0(void)
{
    func_002be1e0(func_00106880());
}
// FUN_002BE1E0
s32 func_002be1e0(s32 arg0)
{
    if (arg0 & 1) {
        return 0;
    }
    if (arg0 & 2) {
        return 1;
    }
    if (arg0 & 4) {
        return 2;
    }
    if (arg0 & 8) {
        return 3;
    }
    if (arg0 & 0x10) {
        return 4;
    }
    if (arg0 & 0x20) {
        return 5;
    }
    if (arg0 & 0x40) {
        return 6;
    }
    if (arg0 & 0x80) {
        return 7;
    }
    if (arg0 & 0x100) {
        return 8;
    }
    if (arg0 & 0x200) {
        return 9;
    }
    if (arg0 & 0x400) {
        return 0xA;
    }
    if (arg0 & 0x800) {
        return 0xB;
    }
    if (arg0 & 0x1000) {
        return 0xC;
    }
    if (arg0 & 0x2000) {
        return 0xD;
    }
    if (arg0 & 0x4000) {
        return 0xE;
    }
    if (arg0 & 0x8000) {
        return 0xF;
    }
    if (arg0 & 0x10000) {
        return 0x10;
    }
    if (arg0 & 0x20000) {
        return 0x11;
    }
    if (arg0 & 0x40000) {
        return 0x12;
    }
    return 0;
}
// FUN_002BE3C0
void func_002be3c0(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x7100D);
}
// FUN_002BE4A0
void func_002be4a0(void)
{
    Vec2f sp18;

    func_002b2970((u8 *)&sp18,
                  580.0f - 21.0f * (f32)func_002b3170(func_002e7a60()),
                  15.0f);
    func_00364320(sp18, 1.0f, 0xFF, func_002e7a60());
}
