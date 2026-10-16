#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
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



extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u32 func_00106a90(s16 arg0);
extern u8 *D_00882F40[];
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 iGpffffb57c;
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern f32 cosf(f32 arg0);
extern f32 sinf(f32 arg0);
extern u8 D_0063F3B0[];


extern s32 smapWorldToColumn(u8 *arg0);
extern s32 smapWorldToRow(u8 *arg0);

extern f32 smapPlayerOffsetX(s32 arg0, f32 fparg0);
extern f32 smapPlayerOffsetZ(s32 arg0, f32 fparg0);
extern void mapSymbolMarkerDraw(u8 *arg0, s64 arg1, f32 fparg0, s32 arg2);
extern u8 *mdlGetMatrix(u32 arg0);
extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern void strcpy(void *arg0, ...);
extern void strcat(void *arg0, void *arg1);
extern void strncpy(void *arg0, void *arg1, s32 arg2);
extern void frFontExCopyString(void *arg0, void *arg1, s32 arg2);
extern s32 func_00443010(u8 *arg0, u8 *arg1);
extern s32 func_002b3520(u8 *arg0, s64 arg1);
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



/* Retail digit RGBA occupies the four bytes at draw+0x75.
   MWCC requires packed after the typedef name. These guarded
   storage views preserve the native FclDrawColor call interface.
   See docs/probe_archive/Fcl_digit_packed_storage_ui_20261006. */
#ifdef NON_MATCHING
typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];
#endif

/* Source unit: src/promoted/code1_002b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002b.c; members 002b2940-002b3960 */

// FUN_002B2940
u8 *func_002b2940(u8 *arg0)
{
    return *(u8 **)(arg0 + 0x38);
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
FclVec2 func_002b2970(f32 x, f32 y)
{
    FclVec2 val;

    val.x = x;
    val.y = y;
    return val;
}

// FUN_002B29A0
FclVec3 func_002b29a0(f32 x, f32 y, f32 z)
{
    FclVec3 val;

    val.x = x;
    val.y = y;
    val.z = z;
    return val;
}

// FUN_002B29E0
FclBoundsPacket func_002b29e0(f32 width, f32 height)
{
    FclBoundsPacket val;

    val.dimensions.width = (s32)width;
    val.dimensions.height = (s32)height;
    return val;
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
FclDrawColor func_002b2a60(u8 arg1, u8 arg2, u8 arg3, u8 arg4)
{
    FclDrawColor val;

    val.c0 = (u8)arg1;
    val.c1 = (u8)arg2;
    val.c2 = (u8)arg3;
    val.c3 = (u8)arg4;
    return val;
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
        temp_f0 = sinf(p4_mul_left(fparg2, iGpffff82fc / (2.0f * fparg3)));
        temp_f2 = temp_f21 - temp_f20;
        return temp_f20 + temp_f2 * temp_f0;
    case 2:
        temp_f0 = cosf(p4_mul_left(fparg2, iGpffff82fc / (2.0f * fparg3)));
        temp_f2 = temp_f21 - temp_f20;
        return temp_f21 - temp_f2 * temp_f0;
    default:
        return -1.0f;
    }
}

// FUN_002B2BD0
void func_002b2bd0(f32 *arg0, s64 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3)
{
    FclVec2 sp;

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
    *(FclVec2 *)arg0 = sp;
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
/* measured: func_002b3110, func_002b3140 MATCH -> MISMATCH without this pragma. */
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
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
/* measured: func_002b3170 MATCH -> MISMATCH without this pragma. */
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
/* measured: func_002b32d0 MATCH -> MISMATCH without this pragma. */
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
s32 func_002b3230(const void *arg0, const void *arg1) {
    s16 b;
    u32 x;
    u32 y;

    b = *(const s16 *)arg1;
    x = func_00106a90(*(const s16 *)arg0);
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

    strcpy(sp130);
    strcpy(sp1b0, arg2);
    strcpy(sp230, arg3);
    strcpy(sp2b0, arg4);
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
                strncpy(spf0, arg0, size);
                frFontExCopyString(spf0, spb0, 0x40);
                strcat(sp70, spb0);
                strcat(sp70, dest);
                strcpy(arg0, arg0 + size + offset);
            } while (func_00443010(arg0, *entry) != 0);
        }
    }
    frFontExCopyString(arg0, spb0, 0x40);
    strcat(sp70, spb0);
    strcpy(arg0, sp70);
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
/* measured: func_002b3520 MATCH -> MISMATCH without this pragma. */
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
// FUN_002B3720
s32 func_002b3720(u8 *arg0)
{
    FclVec2 out;
    FclVec2 work;
    f32 temp_f20;
    u8 *p;
    s32 color;

    p = *(u8 **)(arg0 + 0x38);
    func_002b2bd0(&work.x, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    out = *(FclVec2 *)&work;
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
        temp_f20 = ((f32)smapWorldToColumn(
                        mdlGetMatrix(D_007EFA00[0]) + 0x30) *
                    18.0f) + 172.0f;
        out.x = temp_f20 -
                smapPlayerOffsetX(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f);
        temp_f20 = ((f32)smapWorldToRow(
                        mdlGetMatrix(D_007EFA00[0]) + 0x30) *
                    18.0f) + 9.0f;
        out.y = temp_f20 -
                smapPlayerOffsetZ(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f) - 2.0f;
    }
    color = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
    mapSymbolMarkerDraw(arg0, *(s64 *)&out, 60002.0f, color);
    return 0;
}

// FUN_002B3960
void func_002b3960(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

