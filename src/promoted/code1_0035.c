#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"

extern void func_0034f5d0(u8 *arg0);

extern void func_002bb550(s8 arg0);
extern void (*D_008873EC[])(void *);

extern void func_003549d0();
extern s32 func_001060b0(void);
extern s32 func_00110d60(s64 arg0);
extern s32 func_00353dc0(s64 arg0);
extern s32 func_00106330(s32 arg0);
extern u8 *func_00452380(const void *arg0);
extern s32 func_0029cc00(s32 arg0);
extern u8 D_0064B320[];
extern void func_00354280(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_0064B3B0[];
extern u8 D_0064B3D0[];
extern s32 func_00355460(u8 *arg0);
extern void func_003554b0(u8 *arg0);
extern void func_00442de8(void *dst, const void *src, u32 size);
extern f32 func_003e40b0(void *out, const void *in);

extern void func_0046d280(void *node);
extern void func_00452080(s32 arg0);
extern void func_002bc060(s32 arg0);
extern s32 func_002467b0(u16 arg0);
extern void func_0046d730(const void *module, u32 line);
extern void func_00442088(void *dst, const void *fmt, ...);
extern u8 D_0064CCF0[];
extern u8 D_0064CD10[];
extern u32 D_0064B310[];
extern u8 D_0064B3F0[];
extern u8 D_0064CC60[];
extern u8 D_0064CC70[];
extern u8 D_0064CC78[];

extern f32 D_00761260;

typedef struct Float2
{
    f32 x;
    f32 y;
} Float2;
extern void func_003550d0(u8 *arg0, Float2 *arg1, Float2 *arg2);
extern void func_00355370(u8 *arg0, u8 *arg1);
extern void func_00355190(u8 *arg0, u16 arg1);

typedef struct S64u
{
    s32 lo;
    s32 hi;
} S64u;
static inline void interpolation_accumulate(f32 *total, f32 weight, f32 projection)
{
    *total += weight * projection;
}

static inline u32 add_offset_first(u32 offset, u32 base)
{
    return offset + base;
}

extern s32 func_0034c210(void);

extern u32 D_0064B1E0[];

extern void func_004672c0(s32 arg0, s32 arg1);
extern void func_00454bd0(u8 *arg0);
extern void func_003ef3a0(void *arg0);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_00355740(u8 *arg0, s64 arg1);
extern void func_00355920(u8 *arg0, u8 *arg1);
extern void func_0035bc10(u8 *arg0, s8 arg1, s32 arg2);
extern void func_0035c480(s32 arg0, u16 arg1, s32 arg2);
extern void func_001437b0(void *arg0, s32 arg1, s32 arg2);
extern void func_00361ae0(u8 *arg0);
extern void func_00361ca0(u8 *arg0);
extern void func_0035fd60(u8 *arg0);
extern s32 func_0035aec0(u8 *arg0);
extern void func_0035af10(u8 *arg0);
extern u8 D_0064CC98[];
extern u8 D_0064CD40[];
extern u8 D_0064CCB0[];
extern u8 D_0064CCD0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_00440b68();
extern s32 func_00454a60(u8 *arg0, s32 arg1);
extern s32 func_004553c0(s32 arg0);
extern s32 func_004667d0();
extern s32 func_004669d0(s32 arg0, void *arg1, s32 arg2);
extern u8 iGpffffa960;
extern u8 D_0064B360[];
extern u8 D_0064B380[];
extern void func_0044ea90(const void *arg0, s32 arg1);
extern u8 *func_00451fc0(s32 arg0, const void *arg1, s32 arg2, s32 arg3,
                         s32 arg4, void *arg5, void *arg6, u8 *arg7);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c,
                         void *init, void *close, void *buf);
extern u8 D_0064B410[];
extern s32 func_003558a0(u8 *arg0);
extern void func_00356140(u8 *arg0);
extern void func_003556a0(u8 *arg0, s64 arg1, s32 arg2);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern f32 iGpffff83d4;
extern f32 iGpffff8544;
extern f32 func_0044b7b0(f32 arg0);
extern f32 fGpffff84a4;
extern void func_002bb7c0(s32 arg0);
extern s32 func_002bb600(void);
extern void func_002bb1e0(s32 arg0);
extern void func_002bb9e0(s8 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb290(s8 arg0, s32 arg1);
extern s32 func_002bb4e0(void);
extern s32 func_002bd7b0(const void *arg0);
extern s32 func_002bd840(s32 arg0);
extern u8 D_0064A790[];
extern void func_00149680(s32 arg0);
extern void func_0015a560(void);
extern void func_0034c260(s32 arg0);
extern void func_0034bb10(void);
extern s64 func_00105ee0(s32 arg0);
// FUN_00353B50
s16 func_00353b50(s16 *arg0)
{
    s16 var_17;
    s16 temp_3;
    s32 var_16;

    var_17 = 1;
    *arg0 = 1;
    for (var_16 = 0; var_16 < 3; var_16++) {
        temp_3 = func_00105ee0(var_16);
        if (temp_3 != 0) {
            ((s16 *)arg0)[var_17] = temp_3;
            var_17++;
        }
    }
    if (var_17 <= 4) {
        goto done;
    }
    func_0046d730(&D_0064B310, 0x259);
done:
    return var_17;
}
// FUN_00353C10
s16 func_00353c10(s16 *arg0)
{
    s16 var_17;
    s16 temp_3;
    s32 var_16;

    var_17 = 1;
    *arg0 = 1;
    for (var_16 = 1; var_16 < 8; var_16++) {
        temp_3 = (s16)(var_16 + 1);
        if (func_00353dc0(temp_3) != 0) {
            ((s16 *)arg0)[var_17] = temp_3;
            var_17++;
        }
    }
    if (var_17 <= 8) {
        goto done;
    }
    func_0046d730(&D_0064B310, 0x26F);
done:
    return var_17;
}
// FUN_00353CE0
s16 func_00353ce0(s16 *arg0)
{
    s16 var_17;
    s16 temp_3;
    s32 var_16;

    var_17 = 1;
    *arg0 = 1;
    for (var_16 = 1; var_16 < 8; var_16++) {
        temp_3 = (s16)(var_16 + 1);
        if (temp_3 == 5) {
            goto skip;
        }
        if (func_00353dc0(temp_3) != 0) {
            ((s16 *)arg0)[var_17] = temp_3;
            var_17++;
        }
skip:
        ;
    }
    if (var_17 <= 8) {
        goto done;
    }
    func_0046d730(&D_0064B310, 0x286);
done:
    return var_17;
}
// FUN_00353DC0
s32 func_00353dc0(s64 arg0)
{
    s64 value;
    s32 result;

    result = 0;
    value = (s16)arg0;
    if ((value <= 0) || (value >= 0xB)) {
        func_0046d730(&D_0064B310, 0x292);
    }
    switch (value) {
    case 1:
        result = 1;
        break;
    case 2:
        if (func_00106330(0x30) != 0) {
            result = 1;
        }
        break;
    case 3:
        if (func_00106330(0x31) != 0) {
            result = 1;
        }
        break;
    case 4:
        if (func_00106330(0x32) != 0) {
            result = 1;
        }
        break;
    case 5:
        if (func_00106330(0x34) != 0) {
            result = 1;
        }
        break;
    case 6:
        if (func_00106330(0x33) != 0) {
            result = 1;
        }
        break;
    case 8:
        if (func_00106330(0x35) != 0) {
            result = 1;
        }
        break;
    case 7:
        if (func_00106330(0x36) != 0) {
            result = 1;
        }
        break;
    default:
        func_0046d730(&D_0064B310, 0x2B0);
        break;
    }
    return result;
}
// FUN_00353F50
s32 func_00353f50(s32 arg0)
{
    func_002bb7c0(arg0);
    if (func_002bb600() == 0) {
        func_002bb1e0(arg0);
        return 0;
    }
    return 1;
}
// FUN_00353FB0
void func_00353fb0(void)
{
    func_00149680(0);
}
// FUN_00353FE0
void func_00353fe0(void)
{
    func_00149680(1);
}
// FUN_00354010
void func_00354010(void)
{
    func_0015a560();
}
// FUN_00354030
void func_00354030(void)
{
    func_0045af60(0, 2, 0, 4);
    func_0034c260(0);
    func_00149680(0);
    func_0034bb10();
}
// FUN_00354080
void func_00354080(s32 arg0)
{
    if ((u32)(arg0 - 1) < 2U) {
        func_0045af60(0, 1, 0, 0);
        return;
    }
    if ((u32)(arg0 - 3) < 2U) {
        func_0045af60(0, 1, 0, 5);
    }
}
// FUN_003540F0
s32 func_003540f0(u8 *arg0)
{
    u8 *work;
    s32 state;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(work + 4);
    switch (state) {
    case 0:
        *(s32 *)(work + 4) = 1;
        break;
    case 1:
        func_002bb9e0(*(s8 *)(work + 8), 1);
        if (func_002bb680(*(s8 *)(work + 8)) == 0) {
            func_002bb290(*(s8 *)(work + 8), 1);
            if ((*(u16 *)work & 1) != 0) {
                func_002bd7b0(D_0064A790);
                func_002bd840(7);
                *(s32 *)(work + 4) = 2;
            } else {
                *(s32 *)(work + 4) = 3;
            }
        }
        break;
    case 2:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            func_002bb4e0();
            *(s32 *)(work + 4) = 3;
        }
        break;
    case 3:
        break;
    default:
        func_0046d730(&D_0064B310, 0x34A);
        break;
    }
    return 0;
}
// FUN_00354230
void func_00354230(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002bb550(*(s8 *)(temp_16 + 8));
    (*D_008873EC)(temp_16);
}

// FUN_00354280
void func_00354280(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 sp90[0x40];
    u8 sp50[0x40];
    s32 temp_8;
    s32 var_17;
    s32 var_16;
    s32 temp_16;
    extern s8 func_002bab80(void *arg0);
    extern void func_00106390(s32 arg0, s32 arg1);
    extern void func_00275980(void *src, void *dst, s32 maxlen);
    extern void func_002badc0(s8 arg0, s32 arg1);
    extern void func_002bbd80(s8 arg0, s32 arg1, void *arg2);
    extern u8 func_0045aeb0(s16 channelIndex, const char *name);
    extern u8 D_0064B340[];
    extern char iGpffffa958;
    extern u32 func_00354490(s32 arg0);

    *(s8 *)(arg0 + 8) = func_002bab80(D_0064A790);
    if (arg2 == 0) {
        temp_16 = arg1 + 0x100;
        if (func_00106330(temp_16) != 0)
            func_0046d730(&D_0064B310, 0x369);
        var_17 = 0;
        while (var_17 < 0x40) {
            func_00106390(var_17 + 0x180, 0);
            var_17++;
        }
        func_00106390(arg1 + 0x180, 1);
        func_00106390(temp_16, 1);
        temp_8 = 5;
        var_16 = 0x2CF;
        if (func_00106330(0xC3) == 0) {
            *(u16 *)arg0 = *(u16 *)arg0 | 1;
            func_00106390(0xC3, 1);
        }
    } else {
        if (func_00106330(arg1 + 0x100) == 0)
            func_0046d730(&D_0064B310, 0x37E);
        func_00106390(arg1 + 0x180, 0);
        func_00106390(arg1 + 0x140, 1);
        temp_8 = 6;
        var_16 = 0x2D0;
    }
    func_00442088(sp90, &D_0064B340, var_16);
    func_0045aeb0(2, (const char *)sp90);
    func_00275980((void *)(u32)func_00354490(arg1), sp90, 0x40);
    func_002bbd80(*(s8 *)(arg0 + 8), 0, sp90);
    func_00442088(sp50, &iGpffffa958, arg1 + 1);
    func_00275980(sp50, sp90, 0x40);
    func_002bbd80(*(s8 *)(arg0 + 8), 1, sp90);
    func_002badc0(*(s8 *)(arg0 + 8), temp_8);
}
// FUN_00354490
u32 func_00354490(s32 arg0)
{
    if (!(arg0 < 0x40)) {
        func_0046d730(D_0064B310, 0x3D6);
    }
    return D_0064B1E0[arg0];
}

// FUN_003544F0
s32 func_003544f0(void)
{
    return 50;
}

// FUN_00354500
s32 func_00354500(void) {
    s32 temp_17;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    if ((temp_2 = func_00452380(&D_0064B320)) != NULL) {
        temp_3 = *(s32 *)(*(u8 **)(temp_2 + 0x38) + 4);
        if (temp_3 == 3) {
            if (temp_3 != 3) {
                func_0046d730(&D_0064B310, 0x3CC);
            }
            func_00452080((s32)(u32)temp_2);
            return 1;
        }
        goto block_10;
    }
    temp_17 = func_0029cc00(0) - 1;
    func_0044ea90(&D_0064B310, 0x3AB);
    temp_2_2 = D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2_2 == NULL) {
        func_0046d730(&D_0064B310, 0x3AC);
    }
    if (func_00451fc0(0, &D_0064B320, 0xF, 0, 0,
                      (void *)func_003540f0, (void *)func_00354230,
                      temp_2_2) == NULL) {
        func_0046d730(&D_0064B310, 0x3B5);
    }
    func_00354280(temp_2_2, temp_17, 0);
block_10:
    return 0;
}
// FUN_00354660
s32 func_00354660(void) {
    s32 temp_17;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    if ((temp_2 = func_00452380(&D_0064B320)) != NULL) {
        temp_3 = *(s32 *)(*(u8 **)(temp_2 + 0x38) + 4);
        if (temp_3 == 3) {
            if (temp_3 != 3) {
                func_0046d730(&D_0064B310, 0x3CC);
            }
            func_00452080((s32)(u32)temp_2);
            return 1;
        }
        goto block_10_2;
    }
    temp_17 = func_0029cc00(0) - 1;
    func_0044ea90(&D_0064B310, 0x3AB);
    temp_2_2 = D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2_2 == NULL) {
        func_0046d730(&D_0064B310, 0x3AC);
    }
    if (func_00451fc0(0, &D_0064B320, 0xF, 0, 0,
                      (void *)func_003540f0, (void *)func_00354230,
                      temp_2_2) == NULL) {
        func_0046d730(&D_0064B310, 0x3B5);
    }
    func_00354280(temp_2_2, temp_17, 1);
block_10_2:
    return 0;
}
// FUN_003547C0
void func_003547c0(s32 *arg0, u8 *arg1)
{
    func_003549d0();
    if (arg1 == NULL) {
        *arg0 = 3;
        return;
    }
    func_00442de8((u8 *)arg0 + 0x10, arg1, 0x100);
    *arg0 = 0;
}

// FUN_00354830
s32 func_00354830(u8 *arg0) {
    s32 sp3C;
    s32 temp_2;
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0);
    switch (temp_3) {
    case 0:
        if (func_00452380(&D_0064B360) != NULL) {
            func_00440b68(&D_0064B380);
        } else {
            func_00440b68(&iGpffffa960, &D_0064B310, 0x433);
            temp_2 = func_00454a60(arg0 + 0x10, 0);
            *(s32 *)(arg0 + 8) = temp_2;
            if (temp_2 == 0) {
                func_0046d730(&D_0064B310, 0x434);
            }
            *(s32 *)(arg0 + 0) = 1;
        }
        goto block_15;
    case 1:
        if (func_004553c0(*(s32 *)(arg0 + 8)) != 0) {
            *(s32 *)(arg0 + 4) =
                func_004667d0(0, arg0 + 0x10, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg0 + 0) = 2;
        }
        goto block_15;
    case 2:
        *(s32 *)(arg0 + 0xC) =
            func_004669d0(*(s32 *)(arg0 + 4), &sp3C, 0);
        if (sp3C != 0) {
            *(s32 *)(arg0 + 4) = 0;
            func_00454bd0(*(u8 **)(arg0 + 8));
            *(s32 *)(arg0 + 8) = 0;
            *(s32 *)(arg0 + 0) = 3;
        }
        goto block_15;
    case 3:
        return 1;
    default:
        break;
    }
block_15:
    return 0;
}
// FUN_003549D0
void func_003549d0(u8 *arg0)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg0 + 4);
    if (temp_4 != 0) {
        func_004672c0(temp_4, *(s32 *)(arg0 + 8));
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)(arg0 + 8) = 0;
        *(s32 *)(arg0 + 0xC) = 0;
        return;
    }
    if (*(s32 *)(arg0 + 8) != 0) {
        func_00454bd0(*(u8 **)(arg0 + 8));
        *(s32 *)(arg0 + 8) = 0;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        func_003ef3a0(*(u8 **)(arg0 + 0xC));
        *(s32 *)(arg0 + 0xC) = 0;
    }
}

// FUN_00354A50
u8 *func_00354a50(s32 arg0, u16 arg1) {
    Float2 sp48;
    u8 *temp_2;
    u8 *temp_2_2;

    func_0044ea90(&D_0064B310, 0x48C);
    temp_2_2 = D_008873F4[0](1, 0x258, 0x40000);
    if (temp_2_2 == NULL) {
        return NULL;
    }
    temp_2 = func_00451fc0(arg0, &D_0064B3D0, 0xC7, 0, 0,
                           (void *)func_00355460, (void *)func_003554b0,
                           temp_2_2);
    if (temp_2 == NULL) {
        return NULL;
    }
    *(s16 *)(temp_2_2 + 8) = 0;
    *(u8 *)(temp_2_2 + 0xA) = 0xFF;
    *(s32 *)(temp_2_2 + 0xC) =
        *(u8 *)(temp_2_2 + 0xA) | 0x2D2D2D00;
    sp48.x = 640.0f;
    sp48.y = 640.0f;
    func_003550d0(temp_2, &sp48, &sp48);
    func_00355370(temp_2, NULL);
    *(s32 *)(temp_2_2 + 0x150) = 0;
    *(s32 *)(temp_2_2 + 0x148) = 0;
    *(s32 *)(temp_2_2 + 0x14C) = 0;
    *(void **)(temp_2_2 + 0x254) = (void *)&D_0064B3B0;
    func_00355190(temp_2, arg1);
    return temp_2;
}
/* measured: live body obj 1224B/window 1232B (-8B, -0.65%); verify nd 58; probe_variants 16 differing words; fnalign 306/306 instrs, 6 edits (+7 reloc-only). Reconstructed from retail asm + P4_UNIT_00354BA0 draft (160 lines, noise 5: two adda/madd lerps); frame locals as 4x Q40 quads at sp+0x40/0x80/0xC0/0x100 (x,y,z,q,a floats; u,v,r,g,b s32); each jal checked (00457120 no-arg+0x80, 0044b7b0 f12, 00364680 s32,s32*,s32,s32+7 floats sx/sy in f17/f18, 003f6440 s32,s32, D_00887300 u32-cast hoist into $s0, D_00887310 s32,ptr,s32 daddu). File-scope decls differ here so body carries function-local externs. Tried || vs two-ifs (|| matches bnez+b), u32-cast hoist vs opt_propagation off (u32 avoids extra f22). Residuals are call-arg-setup-order + scheduling floors. */
/* measured 2026-09-17 full pragma_sweep --pairs: banked 16 via measure_guarded; */
/* best stays 16 (ties: loopinv on, strength off, unroll off and pairs; 81 prop */
/* group, 238 dead group, 272-279 schedule group, 276 peephole ties, 283 csoff */
/* group, 292-308 peephole/csoff high). No pair wins; floor stands. */
/* MATCHED 2026-09-18.  func_00364680's parameter order is
   (f32, s32, f32, f32, f32, f32, f32, f32, s32 *, s32, s32) - the spelling
   already used in src/promoted/shdPersona.c and src/promoted/code1_0022.c -
   not the ints-first shape that was here.  b210 emits call-argument setup in
   source order, so the trailing `mtc1 $zero, $f12` and the early
   `lw $a1, 0x150($s1)` were reading back the wrong argument list; the EABI
   gives integer and float arguments separate register files, so the two
   spellings are the same ABI.  The alpha divisor also has to stay inside the
   colour expression: hoisting it to a local costs the scheduler the slot
   retail fills with `mtc1 $zero, $f12`. */
// FUN_00354BA0
void func_00354ba0(u8 *arg0) {
    extern u8 *func_00457120(void);
    extern f32 D_008872F8[];
    extern f32 D_00761470;
    extern void func_00364680(f32 depth, s32 color, f32 x, f32 y, f32 sx, f32 sy, f32 w, f32 h, s32 *tex, s32 mode, s32 flag);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern u8 D_00887300[];
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        s32 _c;
        s32 u;
        s32 v;
        f32 q;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } Q40;
    Q40 qs[4];
    u8 *p;
    f32 z;
    f32 q;
    s32 cnt;
    f32 ft;
    f32 blend;
    f32 sx;
    f32 sy;
    u8 alpha;
    u32 col;
    u32 base;

    p = *(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / *(f32 *)(func_00457120() + 0x80);
    if ((*(s32 *)(p + 0x40) == 0) || (*(u16 *)(p + 8) == 0)) {
        return;
    }
    cnt = *(s32 *)(p + 4);
    if (cnt < 100) {
        *(s32 *)(p + 4) = cnt + 1;
    }
    ft = (f32)*(s32 *)(p + 4);
    if (ft < 10.0f) {
        blend = func_0044b7b0(D_00761470 * (ft / 10.0f));
    } else {
        blend = 1.0f;
    }
    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x18) + blend * (*(f32 *)(p + 0x20) - *(f32 *)(p + 0x18));
    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x1C) + blend * (*(f32 *)(p + 0x24) - *(f32 *)(p + 0x1C));
    *(f32 *)(p + 0x30) += (*(f32 *)(p + 0x10) - *(f32 *)(p + 0x30)) / 3.0f;
    *(f32 *)(p + 0x34) += (*(f32 *)(p + 0x14) - *(f32 *)(p + 0x34)) / 3.0f;
    alpha = *(u8 *)(p + 0xA);
    sx = 256.0f * *(f32 *)(p + 0x38);
    sy = 512.0f * *(f32 *)(p + 0x3C);
    qs[0].x = *(f32 *)(p + 0x10);
    qs[0].y = *(f32 *)(p + 0x14);
    qs[0].z = z;
    qs[0].r = 0x437F0000;
    qs[0].g = 0x437F0000;
    qs[0].b = 0x437F0000;
    qs[0].a = (f32)(u32)alpha;
    qs[0].u = 0;
    qs[0].v = 0;
    qs[0].q = q;
    qs[1].x = *(f32 *)(p + 0x10) + sx;
    qs[1].y = *(f32 *)(p + 0x14);
    qs[1].z = z;
    qs[1].r = 0x437F0000;
    qs[1].g = 0x437F0000;
    qs[1].b = 0x437F0000;
    qs[1].a = (f32)(u32)alpha;
    qs[1].u = 0x3F800000;
    qs[1].v = 0;
    qs[1].q = q;
    qs[2].x = *(f32 *)(p + 0x10);
    qs[2].y = *(f32 *)(p + 0x14) + sy;
    qs[2].z = z;
    qs[2].r = 0x437F0000;
    qs[2].g = 0x437F0000;
    qs[2].b = 0x437F0000;
    qs[2].a = (f32)(u32)alpha;
    qs[2].u = 0;
    qs[2].v = 0x3F800000;
    qs[2].q = q;
    qs[3].x = *(f32 *)(p + 0x10) + sx;
    qs[3].y = *(f32 *)(p + 0x14) + sy;
    qs[3].z = z;
    qs[3].r = 0x437F0000;
    qs[3].g = 0x437F0000;
    qs[3].b = 0x437F0000;
    qs[3].a = (f32)(u32)alpha;
    qs[3].u = 0x3F800000;
    qs[3].v = 0x3F800000;
    qs[3].q = q;
    func_00364680(0.0f, (*(u32 *)(p + 0xC) & ~0xFF) | (((((*(u32 *)(p + 0xC)) & 0xFF) * 0xFF) / *(u8 *)(p + 0xA)) & 0xFF), *(f32 *)(p + 0x28) + *(f32 *)(p + 0x30), *(f32 *)(p + 0x2C) + *(f32 *)(p + 0x34), *(f32 *)(p + 0x10), *(f32 *)(p + 0x14), sx, sy, *(s32 **)(p + 0x150), 1, 0);
    base = (u32)D_00887300;
    ((void (*)(u32, u32))*(u32 *)base)(6, 0);
    ((void (*)(u32, u32))*(u32 *)base)(7, 2);
    ((void (*)(u32, u32))*(u32 *)base)(8, 0);
    ((void (*)(u32, u32))*(u32 *)base)(9, 2);
    ((void (*)(u32, u32))*(u32 *)base)(0xC, 1);
    ((void (*)(u32, u32))*(u32 *)base)(0xB, 6);
    ((void (*)(u32, u32))*(u32 *)base)(0xA, 5);
    ((void (*)(u32, u32))*(u32 *)base)(2, 4);
    ((void (*)(u32, u32))*(u32 *)base)(0xE, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    ((void (*)(u32, u32))*(u32 *)base)(1, *(*(u32 **)(p + 0x150)));
    D_00887310[0](4, &qs[0], 4);
}
// FUN_00355070
void func_00355070(u8 *arg0, u8 *arg1) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(temp_3 + 0x18) = (f32) *(f32 *)(temp_3 + 0x10);
        *(f32 *)(temp_3 + 0x1C) = (f32) *(f32 *)(temp_3 + 0x14);
        *(f32 *)(temp_3 + 0x20) = (f32) *(f32 *)(arg1 + 0);
        *(f32 *)(temp_3 + 0x24) = (f32) *(f32 *)(arg1 + 4);
    } else {
        *(f32 *)(temp_3 + 0x10) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x14) = (f32) *(f32 *)(temp_3 + 0x1C);
        *(f32 *)(temp_3 + 0x30) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x34) = (f32) *(f32 *)(temp_3 + 0x1C);
    }
    *(s32 *)(temp_3 + 4) = 0;
}

// FUN_003550D0
void func_003550d0(u8 *arg0, Float2 *arg1, Float2 *arg2)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(&D_0064B310, 0x53A);
    }
    if (arg2 == NULL) {
        func_0046d730(&D_0064B310, 0x53B);
    }
    *(f32 *)(temp_16 + 0x18) = arg1->x;
    *(f32 *)(temp_16 + 0x1C) = arg1->y;
    *(f32 *)(temp_16 + 0x10) = arg1->x;
    *(f32 *)(temp_16 + 0x14) = arg1->y;
    *(f32 *)(temp_16 + 0x20) = arg2->x;
    *(f32 *)(temp_16 + 0x24) = arg2->y;
    *(f32 *)(temp_16 + 0x30) = arg1->x;
    *(f32 *)(temp_16 + 0x34) = arg1->y;
    *(s32 *)(temp_16 + 4) = 0;
}
// FUN_00355190
void func_00355190(u8 *arg0, u16 arg1)
{
    u8 sp50[0x100];
    s32 temp_17;
    s8 var_2;
    u8 *temp_16;
    u8 *temp_3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_17 = arg1 & 0xFFFF;
    if (*(u16 *)(temp_16 + 8) != temp_17) {
        if (func_00110d60((s64)(s16)func_001060b0()) & 1) {
            var_2 = 0x61;
        } else {
            var_2 = 0x62;
        }
        if (temp_17 == 0) {
            func_003549d0(temp_16 + 0x144);
            *(s32 *)(temp_16 + 0x144) = 3;
        } else {
            func_00442088(sp50, &D_0064B3F0, temp_17, var_2);
            func_003549d0(temp_16 + 0x144);
            if ((u8 *)sp50 == NULL) {
                *(s32 *)(temp_16 + 0x144) = 3;
            } else {
                func_00442de8(temp_16 + 0x154, sp50, 0x100);
                *(s32 *)(temp_16 + 0x144) = 0;
            }
        }
        *(u16 *)(temp_16 + 8) = arg1;
        *(s32 *)(temp_16 + 0x40) = 0;
        temp_3 = *(u8 **)(arg0 + 0x38);
        *(f32 *)(temp_3 + 0x10) = *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x14) = *(f32 *)(temp_3 + 0x1C);
        *(f32 *)(temp_3 + 0x30) = *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x34) = *(f32 *)(temp_3 + 0x1C);
        *(s32 *)(temp_3 + 4) = 0;
    }
}
// FUN_003552D0
void func_003552d0(u8 *arg0, Float2 arg1)
{
    f32 *b = *(f32 **)(arg0 + 0x38);

    b[0xA] = arg1.x;
    b[0xB] = arg1.y;
}
// FUN_00355300
void func_00355300(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = arg1;
}

// FUN_00355310
void func_00355310(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(arg1 + 4) = (f32) *(f32 *)(temp_3 + 0x1C);
    }
    if (arg2 != NULL) {
        *(f32 *)(arg2 + 0) = (f32) *(f32 *)(temp_3 + 0x10);
        *(f32 *)(arg2 + 4) = (f32) *(f32 *)(temp_3 + 0x14);
    }
    if (arg3 != NULL) {
        *(f32 *)(arg3 + 0) = (f32) *(f32 *)(temp_3 + 0x20);
        *(f32 *)(arg3 + 4) = (f32) *(f32 *)(temp_3 + 0x24);
    }
}

// FUN_00355370
void func_00355370(u8 *arg0, u8 *arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(u32 *)(temp_4 + 0x38) = 0x3F800000;
        *(u32 *)(temp_4 + 0x3C) = 0x3F800000;
    } else {
        *(f32 *)(temp_4 + 0x38) = *(f32 *)(arg1 + 0);
        *(f32 *)(temp_4 + 0x3C) = *(f32 *)(arg1 + 4);
    }
}

// FUN_003553B0
void func_003553b0(u8 *arg0, f32 *arg1)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(D_0064B310, 0x5CD);
    }
    arg1[0] = *(f32 *)(temp_16 + 0x38);
    arg1[1] = *(f32 *)(temp_16 + 0x3C);
}

/* measured: the read and the write of the same field must use DIFFERENT
   spellings. Written identically both times, b210 CSEs the address into a
   callee-saved register (addiu $s0, $v1, 0x40 then sw at 0) and leaves the
   struct pointer in a caller-saved one; retail keeps the POINTER in $s0 and
   stores at 0x40($s0). Reading through the array index and writing through the
   cast-and-offset breaks the CSE and the function matches exactly. Same shape
   in func_0035aec0 and func_0035be70. */

// FUN_00355410
void func_00355410(u8 *arg0, s8 arg1)
{
    u8 *temp_4;

    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0xA) = arg1;
    temp_4 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_4 + 0xC) = ((s32 *)temp_4)[3];
}

// FUN_00355430
s32 func_00355430(u8 *arg0)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_3 + 0x40) != 0) {
        return *(s32 *)(temp_3 + 0x150);
    }
    return 0;
}
// FUN_00355460
s32 func_00355460(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[16] == 0) && (*(u16 *)(p + 8) != 0)) {
        *(s32 *)(p + 0x40) = func_00354830(p + 0x144);
    }
    return 0;
}

// FUN_003554B0
void func_003554b0(u8 *arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s32 *)(p + 0x148);
    if (temp_4 != 0) {
        func_004672c0(temp_4, *(s32 *)(p + 0x14C));
        *(s32 *)(p + 0x148) = 0;
        *(s32 *)(p + 0x14C) = 0;
        *(s32 *)(p + 0x150) = 0;
    } else {
        temp_4_2 = *(s32 *)(p + 0x14C);
        if (temp_4_2 != 0) {
            func_00454bd0((u8 *)temp_4_2);
            *(s32 *)(p + 0x14C) = 0;
        }
        temp_4_3 = *(s32 *)(p + 0x150);
        if (temp_4_3 != 0) {
            func_003ef3a0((void *)temp_4_3);
            *(s32 *)(p + 0x150) = 0;
        }
    }
    (*D_008873EC)(p);
}
/* measured: object 328B/window 336B; normalized_diff 33; differing offsets
   0x2C-0x44, 0xDC-0xF4, 0xFC-0x100, 0x10C-0x140. Trial body archived in
   build/V035_00355550_body.c; no conversion idiom present. */
/* measured: optimization_level 1 probe for byte-load register order. */
#pragma optimization_level 1
// FUN_00355550
s32 func_00355550(s16 arg0, s32 arg1, s16 arg2, s16 arg3,
                  s64 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    s32 result;
    u8 *temp_2;
    func_0044ea90(&D_0064B310, 0x63D);
    temp_2 = D_008873F4[0](1, 0x22C, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&D_0064B310, 0x63E);
    }
    result = func_00451de0(&D_0064B410, arg6, 0, 0,
                           (void *)func_003558a0, (void *)func_00356140,
                           temp_2);
    *(s16 *)(temp_2 + 0x0) = arg0;
    *(s32 *)(temp_2 + 0x4) = arg5;
    *(s16 *)(temp_2 + 0xC) = arg2;
    *(s16 *)(temp_2 + 0xE) = arg3;
    {
        u8 color_0 = ((u8 *)&arg1)[0];
        u8 color_1 = ((u8 *)&arg1)[1];
        u8 color_2 = ((u8 *)&arg1)[2];
        u8 color_3 = ((u8 *)&arg1)[3];
        *(u8 *)(temp_2 + 0x14) = color_0;
        *(u8 *)(temp_2 + 0x15) = color_1;
        *(u8 *)(temp_2 + 0x16) = color_2;
        *(u8 *)(temp_2 + 0x17) = color_3;
    }
    func_003556a0(temp_2, arg4, arg7);
    return result;
}
#pragma optimization_level 2
// FUN_003556A0
void func_003556a0(u8 *arg0, s64 arg1, s32 arg2)
{
    s32 i;
    u8 *p;

    *(s32 *)(arg0 + 8) = 1;
    i = 0;
    while (i < 0xF) {
        p = arg0 + (i << 5);
        *(s32 *)(p + 0x20) = 0;
        *(s32 *)(p + 0x24) = 0;
        i += 1;
    }
    func_00355740(arg0, (s16)arg1);
    func_0043f9c8(arg0 + 0x1F8, 0, 0x30);
    *(s32 *)(arg0 + 0x200) = (s32)func_00355920;
    *(s32 *)(arg0 + 0x208) = (s32)arg0;
    *(s32 *)(arg0 + 0x228) = arg2;
}
/* measured: optimization_level 1 with integer/float declaration shaping and
   an explicit second conversion local closes func_00355740 at normalized_diff 0. */
#pragma optimization_level 1
// FUN_00355740
void func_00355740(u8 *arg0, s64 arg1)
{
    f32 step;
    f32 scale;
    f32 temp;
    f32 three_quarters;
    s32 x;
    s32 y;
    s32 i;
    s32 i2;
    s32 j;
    s32 divisor;
    u8 *p;
    u8 *q;
    u8 *r;
    extern f32 fGpffff83d0;

    i = 0;
    while (i < 0xF) {
        p = arg0 + (i << 5);
        *(f32 *)(p + 0x28) = *(f32 *)(p + 0x20);
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x24);
        i += 1;
    }
    switch (arg1) {
    case 0:
        i2 = 0;
        while (i2 < 0xF) {
            q = arg0 + (i2 << 5);
            *(s32 *)(q + 0x18) = 0;
            *(s32 *)(q + 0x1C) = 0;
            *(s32 *)(q + 0x30) = 0;
            *(f32 *)(q + 0x34) = (f32)*(s16 *)(arg0 + 0xC);
            i2 += 1;
        }
        break;
    case 1:
        j = 0;
        divisor = 5;
        step = fGpffff83d0;
        three_quarters = 0.75f;
        while (j < 0xF) {
            x = (j % divisor) - 2;
            if (x < 0) {
                x = -x;
            }
            y = (j / divisor) - 1;
            if (y < 0) {
                y = -y;
            }
            scale = step * (f32)(x + y);
            r = arg0 + (j << 5);
            *(s32 *)(r + 0x18) = 0;
            *(s32 *)(r + 0x1C) = 0;
            *(f32 *)(r + 0x30) = (f32)*(s16 *)(arg0 + 0xC) * scale;
            temp = (f32)*(s16 *)(arg0 + 0xC);
            *(f32 *)(r + 0x34) = temp * (three_quarters + scale);
            j += 1;
        }
        break;
    default:
        break;
    }
}
#pragma optimization_level 2
// FUN_003558A0
s32 func_003558a0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_16 + 0x1F8) = 0;
    *(s32 *)(temp_16 + 0x1FC) = 0;
    func_00460ac0((u8 *)&D_00793E80 + (*(s32 *)(temp_16 + 0x228) * 0x30), temp_16 + 0x1F8);
    if (!(*(s32 *)(temp_16 + 8) & 4)) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}

/* measured: object 2096B/window 2080B (+16B, +0.77%); probe_variants 306 differing words (reloc-masked); fnalign 520/524 instrs, 213 edits (+10 reloc-only). */
/* Reconstructed from retail asm + m2c + IDA/Ghidra in this file's idiom (union s64/Vec2f xy, union w/b col, u32 base hoist, plain (u8)f casts). Two-arg ABI (arg0 unused in $4, struct in $5) matches retail daddu $19,$5; file-scope decl updated. Switches for 0/1/2+default (reverse 2,1,0), if/else for 0/1 pairs in retail order. GP fGp8504/-7AFC, fGp8540/-7AC0, fGp84A4, iGp8544/-7ABC, fGp8548/-7AB8. Residuals are call-arg-setup + scheduling + FPR-color floors; siblings 35c040/54ba0 untouched. Counted 520 retail instrs first. */
// FUN_00355920 NONMATCHING
#ifdef NON_MATCHING
void func_00355920(u8 *arg0, u8 *arg1) {
    extern u8 D_00887300[];
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0045c870(u8 *arg0, s32 arg1);
    extern f32 func_0044b610(f32 arg0);
    extern void func_00356170(s64 arg0, f32 f0, f32 f1, f32 f2, s32 arg1, s32 arg2, s32 arg3);
    extern void func_003561d0(Vec2f arg0, s32 arg1, s32 arg2, s32 arg3, f32 dummy, f32 f0, f32 f1);
    extern f32 fGpffff8504;
    extern f32 fGpffff8540;
    extern f32 fGpffff8548;
    u8 *p;
    s32 isZero;
    u8 alpha;
    u32 base;
    s32 i;
    f32 f20;
    f32 f21;
    union { s64 bits; Vec2f vec; } xy;
    union { s32 w; u8 b[4]; } col;
    (void)arg0;
    p = arg1;
    alpha = 0xFF;
    isZero = (*(s32 *)(p + 4) == 0);
    base = (u32)D_00887300;
    ((void (*)(u32, u32))*(u32 *)base)(7, 2);
    ((void (*)(u32, u32))*(u32 *)base)(6, 0);
    ((void (*)(u32, u32))*(u32 *)base)(8, 0);
    ((void (*)(u32, u32))*(u32 *)base)(0xE, 0);
    ((void (*)(u32, u32))*(u32 *)base)(9, 2);
    ((void (*)(u32, u32))*(u32 *)base)(0xC, 1);
    ((void (*)(u32, u32))*(u32 *)base)(1, 0);
    if (isZero != 0) {
        func_00489f80();
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x31801);
        col.b[0] = 0xFF;
        col.b[1] = 0xFF;
        col.b[2] = 0xFF;
        col.b[3] = 0;
        func_0045c870(col.b, 0);
    }
    if ((*(s32 *)(p + 8) & 2) != 0) {
        *(s16 *)(p + 0x12) += 1;
        switch (*(s32 *)(p + 4)) {
        case 0: {
            s16 cnt = *(s16 *)(p + 0x12);
            s16 limit = *(s16 *)(p + 0xE);
            if (!((f32)cnt < fGpffff8504 * (f32)limit)) {
                if ((s64)limit < (s64)cnt) {
                    *(s32 *)(p + 8) |= 4;
                } else {
                    f32 ratio;
                    f32 c;
                    f32 s;
                    xy.vec.x = 320.0f;
                    xy.vec.y = 224.0f;
                    col.b[3] = 0xFF;
                    ratio = ((f32)cnt - fGpffff8504 * (f32)limit) / (fGpffff8540 * (f32)limit);
                    f20 = fGpffff84a4 * ratio;
                    c = func_0044b610(f20);
                    f21 = iGpffff8544 * (1.0f - c);
                    s = func_0044b7b0(f20);
                    if (*(s16 *)p == 1) {
                        func_003561d0(xy.vec, col.w, 0, 0, 0.0f, 800.0f * s, f21);
                    } else if (*(s16 *)p == 0) {
                        func_00356170(xy.bits, 0.0f, 800.0f * s, 0.0f, col.w, 0x30, 0);
                    }
                }
            }
            break;
        }
        case 1:
            if (*(s16 *)(p + 0x12) >= *(s16 *)(p + 0xE)) {
                *(s32 *)(p + 8) |= 4;
            }
            break;
        case 2: {
            s16 limit = *(s16 *)(p + 0xE);
            s16 cnt = *(s16 *)(p + 0x12);
            if (cnt < limit) {
                alpha = (u8)(255.0f * (1.0f - (f32)cnt / (f32)limit));
            } else {
                *(s32 *)(p + 8) |= 4;
            }
            break;
        }
        default:
            func_0046d730(D_0064B310, 0x712);
            break;
        }
    }
    if (isZero != 0) {
        func_0048a000();
        func_003f6440(3, 0x35801);
        func_003f6440(2, 0x44);
    } else {
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
    if ((*(s32 *)(p + 8) & 1) != 0) {
        s16 nw = *(s16 *)(p + 0x10) + 1;
        s16 lim;
        *(s16 *)(p + 0x10) = nw;
        lim = *(s16 *)(p + 0xC);
        if (lim < nw) {
            u32 tmp = *(u32 *)(p + 8);
            *(u32 *)(p + 8) = tmp & ~1u;
            *(u32 *)(p + 8) = (tmp & ~1u) | 2u;
        } else {
            s32 mode = *(s32 *)(p + 4);
            switch (mode) {
            case 0: {
                u32 fl = *(u32 *)(p + 8);
                if (((fl & 2) == 0) && ((lim / 3) < nw)) {
                    *(s32 *)(p + 8) |= 2;
                }
                break;
            }
            case 1:
            case 2: {
                if ((*(s32 *)(p + 8) & 2) == 0) {
                    s32 doSet;
                    if (*(s16 *)p == 0) {
                        s32 t = lim * 3;
                        s32 q = t / 4;
                        if (q < nw) {
                            doSet = 1;
                        } else {
                            doSet = 0;
                        }
                    } else if (*(s16 *)p == 1) {
                        s32 q = lim / 2;
                        if (q < nw) {
                            doSet = 1;
                        } else {
                            doSet = 0;
                        }
                    } else {
                        doSet = 0;
                    }
                    if (doSet != 0) {
                        *(s32 *)(p + 8) |= 2;
                    }
                }
                break;
            }
            default:
                func_0046d730(D_0064B310, 0x73A);
                break;
            }
        }
    }
    if ((*(s32 *)(p + 8) & 4) != 0) {
        return;
    }
    col.b[0] = *(u8 *)(p + 0x14);
    col.b[1] = *(u8 *)(p + 0x15);
    col.b[2] = *(u8 *)(p + 0x16);
    col.b[3] = alpha;
    {
        s32 doCall;
        if (*(s16 *)p == 0) {
            s32 t = *(s16 *)(p + 0xC) * 3;
            s32 q = t / 4;
            if (q < *(s16 *)(p + 0x10)) {
                doCall = 1;
            } else {
                doCall = 0;
            }
        } else if (*(s16 *)p == 1) {
            s32 q = *(s16 *)(p + 0xC) / 2;
            if (q < *(s16 *)(p + 0x10)) {
                doCall = 1;
            } else {
                doCall = 0;
            }
        } else {
            doCall = 0;
        }
        if (doCall != 0) {
            func_0045c870(col.b, 0);
            return;
        }
    }
    for (i = 0; i < 0xF; i++) {
        f32 e30;
        f32 e34;
        f32 ctr;
        u8 *e;
        f32 f13;
        xy.vec.x = 320.0f + 160.0f * (f32)(i % 5 - 2);
        xy.vec.y = 224.0f + 160.0f * (f32)(i / 5 - 1);
        e = p + (i << 5);
        e30 = *(f32 *)(e + 0x30);
        ctr = (f32)*(s16 *)(p + 0x10);
        if (ctr < e30) {
            f20 = 0.0f;
            f13 = 0.0f;
        } else {
            e34 = *(f32 *)(e + 0x34);
            if (ctr < e34) {
                f32 num = ctr - e30;
                f32 den = e34 - e30;
                f32 r = (fGpffff84a4 * num) / den;
                f32 co = func_0044b610(r);
                f20 = iGpffff8544;
                f13 = 280.0f * (1.0f - co);
                /* keep r for f20? retail keeps f20 as GP, f13 as 280*(1-co) */
                (void)r;
            } else {
                f20 = fGpffff8548;
                f13 = 280.0f;
            }
        }
        if (*(s16 *)p == 1) {
            func_00356170(xy.bits, 0.0f, f13, 0.0f, col.w, 0x30, 1);
        } else if (*(s16 *)p == 0) {
            func_003561d0(xy.vec, col.w, 1, 1, 0.0f, f13, f20);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355920);
#endif
// FUN_00356140
void func_00356140(u8 *arg0)
{
    (*D_008873EC)(*(u8 **)(arg0 + 0x38));
}

/* measured: object 96B/window 96B, normalized_diff 0. One-element integer
   arrays home arg0/arg1 to their retail stack slots; opt_propagation off keeps
   the arg2 parking move after those stores. */
#pragma push
#pragma opt_propagation off
// FUN_00356170
void func_00356170(s64 arg0, f32 f0, f32 f1, f32 f2,
                   s32 arg1, s32 arg2, s32 arg3)
{
    union { s64 bits; Vec2f position; } saved0[1];
    s32 saved1[1];
    s32 var8;
    s32 tmp2;
    u8 sel;

    saved0[0].bits = arg0;
    saved1[0] = arg1;
    tmp2 = arg2;
    var8 = arg3;
    sel = ((u8 *)saved1)[3];
    if (sel != 0xFF) {
        var8 = 0;
    }
    func_00365f00(saved0[0].position, f0,
                  *(s32 *)((u8 *)saved1), saved1[0],
                  f1, f2, tmp2, 1.0f, 1.0f, var8);
}
#pragma pop
/* measured: opt_propagation off probe for staged argument materialisation. */
#pragma opt_propagation off
/* measured: object 116B/window 128B; normalized_diff 0. Named call-argument
   locals preserve retail materialisation order under opt_propagation off; the
   12-byte tail is retail zero padding. */
// FUN_003561D0
void func_003561d0(Vec2f arg0, s32 arg1, s32 arg2, s32 arg3,
                   f32 dummy, f32 f0, f32 f1)
{
    struct Frame {
        union { s32 bits; f32 value; } saved1;
        union { f32 value; u8 bytes[4]; } temp;
    } frame;
    s32 var8;
    u8 sel;
    f32 scaled;
    f32 one;
    f32 shifted;
    f32 call_f0;
    f32 call_f1;
    f32 call_f2;
    f32 call_f3;
    s32 call_arg4;
    f32 call_f4;

    frame.saved1.bits = arg1;
    scaled = f0 / iGpffff83d4;
    shifted = iGpffff8544 + f1;
    var8 = arg2;
    frame.temp.value = frame.saved1.value;
    sel = frame.temp.bytes[3];
    if (sel != 0xFF) {
        var8 = 0;
    }
    one = 1.0f;
    call_f0 = dummy;
    call_f1 = scaled;
    call_f2 = shifted;
    call_f3 = one;
    call_arg4 = var8;
    call_f4 = one;
    func_00365f00(arg0, call_f0, frame.saved1.bits, frame.saved1.bits,
                  call_f1, call_f2, 4,
                  call_f3, call_f4, call_arg4);
}
/* measured: closes opt_propagation off probe for staged argument materialisation. */
#pragma opt_propagation on
/* measured: s16 loop width + (u16)f from same-file 00359400 + bdabase hoist + opt_loop_invariants on; probe_variants 217 differing words (hoist 220, jfirst 217, atfix 217); fnalign 370/371 instrs, 59 edits (+22 reloc-only) via `tools/fnalign.py --candidate /var/tmp/decomp/body_jfirst2.c` + guarded 217 via `tools/measure_guarded.py` (obj 1480B/window 1488B); retail window 1488B. Tried s32 loops (earliest hunk move $a0 vs $v1, missing dsll32), manual 2147483648.0f guard with (s16)(tmp&0xFFFF) (c.ole.s/bc1f vs c.le.s/bc1t + missing andi), negated guard and u16 store (no nd change), j-first ordering (220->217), >=0x16 to >0x15 for slti $at (no change). Residuals are s-reg coloring cycle (m $s1 vs $s3 with id swapped, h0-h3 scattered $s4/$s3/$s6/$s2 vs $s2/$s1/$s0) + slti $at vs $v0 + call-arg-setup-order/scheduling floors; no madd per census. */
// FUN_00356250 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_00356250(u8 *arg0)
{
    extern u8 D_0064BDA0[];
    extern u8 D_0064CBE0[];
    extern u8 D_0064CC98[];
    extern u8 D_005E57F0[];
    extern u8 D_005E5810[];
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern s32 func_00107180(s32 arg0);
    extern u8 func_00248760(s32 arg0);
    extern u16 func_00107ac0(s32 arg0);
    extern s32 func_00107ea0(s32 arg0);
    extern s32 func_00107c80(s32 arg0);
    extern s32 func_0046a770(const void *arg0);
    extern s32 func_0046d200(void *arg0, s32 arg1);
    extern void func_0046d730(const void *arg0, u32 arg1);
    extern s32 func_00246970(void);
    extern void func_002bc010(s32 arg0, s32 arg1);
    extern s32 func_00359400(u8 *arg0, s32 arg1);
    extern u8 *func_0035adc0(s32 arg0, s64 arg1, s32 arg2);
    extern u8 *func_0035bf10(s32 arg0, u16 arg1, s32 arg2);
    extern u8 *func_00354a50(s32 arg0, u16 arg1);
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    s16 n;
    s16 q;
    u8 *p;
    u8 *src;
    u8 *dst;
    s32 *slot;
    s32 h0;
    s32 h1;
    s32 h2;
    s32 h3;
    u8 *bdabase;

    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)(arg0 + 0) = 0xFF;
    *(s32 *)(arg0 + 0x18) = -1;
    *(s32 *)(arg0 + 0x14) = 0;
    for (i = 0; i < 3; i++) {
        *(s16 *)(arg0 + i * 2 + 0x24) = 0;
    }
    j = 0;
    bdabase = D_0064BDA0;
    while (j < 0x2B) {
        src = bdabase + j * 0x1C;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x160) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x164) = *(f32 *)(src + 4);
        *(u16 *)(dst + 0x170) = (u16)*(f32 *)(src + 8);
        *(u16 *)(dst + 0x176) = (u16)*(f32 *)(src + 0xC);
        *(u8 *)(dst + 0x16A) = *(u8 *)(src + 0x10);
        j++;
    }
    for (k = 0; k < 0x6C; k++) {
        p = arg0 + k * 0x14;
        *(s32 *)(p + 0x964) = k % 9;
        *(s32 *)(p + 0x96C) = 9;
        *(s32 *)(p + 0x968) = k / 9;
        *(s32 *)(p + 0x970) = 0xC;
    }
    m = 0;
    n = 0;
    while (m < 0x15) {
        s32 id = func_00107180(m) & 0xFFFF;
        if (id > 0) {
            p = arg0 + n * 0xC;
            *(s8 *)(p + 0x38) = func_00248760(id);
            *(s16 *)(p + 0x3A) = (s16)id;
            *(u16 *)(p + 0x3C) = func_00107ac0(id);
            if (*(u16 *)(p + 0x3C) == 0xA) {
                *(s32 *)(p + 0x40) = 1;
            } else if (func_00107ea0(id) != 0) {
                *(s32 *)(p + 0x40) = 3;
            } else if (func_00107c80(id) != 0) {
                *(s32 *)(p + 0x40) = 2;
            } else {
                *(s32 *)(p + 0x40) = 0;
            }
            n++;
        }
        m++;
    }
    *(s16 *)(arg0 + 0x134) = n;
    if (n >= 0x16) {
        func_0046d730(D_0064CC98, 0x1E2);
    }
    h0 = func_0046a770(D_005E5830);
    if (h0 == 0) {
        func_0046d730(D_0064CC98, 0x1E6);
    }
    h1 = func_0046a770(D_005E5850);
    if (h1 == 0) {
        func_0046d730(D_0064CC98, 0x1E8);
    }
    h2 = func_0046a770(D_005E5810);
    if (h2 == 0) {
        func_0046d730(D_0064CC98, 0x1EA);
    }
    h3 = func_0046a770(D_005E57F0);
    *(s32 *)(arg0 + 0x1304) = h3;
    if (h3 == 0) {
        func_0046d730(D_0064CC98, 0x1EC);
    }
    for (q = 0; q < 0x4D; q++) {
        if (q < 2) {
            p = arg0 + q * 4 + 0x11D0;
            slot = (s32 *)p;
            *slot = func_0046d200((void *)h0, D_0064CBE0[q]);
        } else if (q < 0x33) {
            p = arg0 + q * 4 + 0x11D0;
            slot = (s32 *)p;
            *slot = func_0046d200((void *)h1, D_0064CBE0[q]);
        } else if (q < 0x34) {
            p = arg0 + q * 4 + 0x11D0;
            slot = (s32 *)p;
            *slot = func_0046d200((void *)h3, D_0064CBE0[q]);
        } else {
            p = arg0 + q * 4 + 0x11D0;
            slot = (s32 *)p;
            *slot = func_0046d200((void *)h2, D_0064CBE0[q]);
        }
        if (*slot == 0) {
            func_0046d730(D_0064CC98, 0x1FC);
        }
    }
    func_00359400(arg0, 0);
    func_002bc010(0xB, func_00246970());
    *(s32 *)(arg0 + 0x1308) = (s32)func_00354a50(0, 1);
    *(s32 *)(arg0 + 0x130C) = (s32)func_0035adc0(0, 0, 0);
    *(s32 *)(arg0 + 0x1310) = (s32)func_0035bf10(0, 0, 0);
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356250);
#endif
// FUN_00356820
s32 func_00356820(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00356870
s32 func_00356870(u8 *arg0)
{
    s16 temp_2;
    s32 var_17;
    s32 var_16;
    u8 *var_19;
    extern void func_00356a10(u8 *arg0);
    extern void func_00359340(u8 *arg0);
    extern void func_003593b0(u8 *arg0);

    var_16 = 1;
    temp_2 = *(s16 *)(arg0 + 0x20);
    if (temp_2 < 0x64) {
        *(s16 *)(arg0 + 0x20) = temp_2 + 1;
    }
    var_17 = 0;
    goto loop_test;
loop_body:
    if (((var_17 >= 0x12) && (var_17 <= 0x1B)) ||
        ((var_17 > 0) && (var_17 <= 5)) ||
        ((var_17 >= 0x27) && (var_17 <= 0x28))) {
        var_19 = arg0 + (var_17 * 0x30);
        func_001437b0(var_19 + 0x150, *(s16 *)(arg0 + 0x20), 1);
    } else if (var_17 == 0x26) {
        var_19 = arg0 + (var_17 * 0x30);
        func_001437b0(var_19 + 0x150, *(s16 *)(arg0 + 0x20), 2);
    } else {
        var_19 = arg0 + (var_17 * 0x30);
        func_001437b0(var_19 + 0x150, *(s16 *)(arg0 + 0x20), 0);
    }
    if (*(u8 *)(var_19 + 0x16A) != 0) {
        var_16 = 0;
    }
    var_17 += 1;
loop_test:
    if (var_17 < 0x2B) {
        goto loop_body;
    }
    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) + 1;
    if (*(s16 *)(arg0 + 0x22) > 0x168) {
        *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) - 0x168;
    }
    func_00359340(arg0);
    func_003593b0(arg0);
    func_00356a10(arg0);
    return var_16;
}
/* measured: rebuilt from withheld 2714/2954 draft (retail 2636); this body 2710 obj (+74, +2.81% inside band) 2868 edits via `python3 tools/fnalign.py src/promoted/code1_0035.c func_00356a10 --candidate /tmp/body_56a10_after1.c` (was 2873 before switch2/4 dispatch reorder, -5). Dispatch: switch 1 (cases 0/1/2/3) is an if-chain in retail (beq order 2,3,1,0 at 0x357A9C) so rewrote as if (==2)/else if (==3)/else if (==1||==0); switch 2 dispatch is beq order 1,3,2 at 0x357E00 (beq 3 at 0x357E10 before beq 2 at 0x357E1C) so ordered cases as case 1 then case 2/case 3 shared with case 2 label before case 3 to emit 1,3,2; switches 3 (order 3,2,1 at 0x3586D8) is descending MWCC switch so kept as switch; switch 4 dispatch is beq order 3,2,1,0 at 0x358C14 (beq 1 at 0x358C30 before beqz 0 at 0x358C38) so ordered cases as case 0 then case 1 to emit 3,2,1,0. Float guards rewritten from if (!(x >= C)) (c.olt) to if (C <= x) (c.ole) to match retail c.le.s operand order, -77 edits. */
/* measured 00356a10 (owner, 2026-09-19): fnalign **2868 -> 2866 edits**, count
   2710 -> 2708 against retail 2636, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
// FUN_00356A10 NONMATCHING
#ifdef NON_MATCHING
void func_00356a10(u8 *arg0) {
    extern void func_0034f1e0(void);
    extern void func_0034c270(s64, s32, s32, f32);
    extern void func_0045d6e0(u8 *, u8 *, f32, s32);
    extern void func_003599c0(s32, u8 *);
    extern void func_00355410(s32, s32);
    extern void func_00354ba0(s32);
    extern void func_0034f2e0(s32, s32, s32, s32, s32, f32, f32);
    extern void func_0034f320(s32, s32, s32, s32, s32, s32, s32, s64, f32, f32, s32, f32, s64);
    extern f32 func_0046b260(s32);
    extern f32 func_0046b2f0(s32);
    extern void func_0046d730(void *, s32);
    extern f32 func_0034f720(u8 *, s32, s32, s32);
    extern void func_00275020(s32, s32, s32, void *, s32, s32, f32, f32, s32);
    extern void *func_00246830(s32);
    extern s32 func_00246910(s32);
    extern s64 func_00246940(s64);
    extern void func_002bc0b0(s32, s32, s32, s32, s32, f32, f32, s32);
    extern void func_0035aff0(u8 *, s32);
    extern f32 func_0035c040(u8 *, s32);
    extern void func_0035c670(u8 *, f32 *);
    extern u16 func_00107ac0(u16);
    extern s32 func_0010d620(s32);
    extern void func_0034f9d0(s64, s32, s32, s32, s32);
    extern s32 (*D_00887300[])(s32, s32);
    extern u8 D_0064B2E0;
    extern u8 D_0064B2E1;
    extern u8 D_0064B2E2;
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064CC30[];
    extern u8 D_0064CC48[];
    extern u8 D_0064CC98[];
    u8 spFF;
    u8 spFE;
    u8 spFD;
    u8 spFC;
    f32 spF4;
    f32 spF0;
    s32 spEC;
    s32 spE8;
    s32 spE4;
    s32 spE0;
    signed __int128 spD0;
    s32 var_22;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f12_5;
    f32 temp_f12_6;
    f32 temp_f12_7;
    f32 temp_f12_8;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f13_3;
    f32 temp_f13_4;
    f32 temp_f13_5;
    f32 temp_f13_6;
    f32 temp_f13_7;
    f32 temp_f13_8;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_12;
    f32 temp_f1_13;
    f32 temp_f1_14;
    f32 temp_f1_15;
    f32 temp_f1_16;
    f32 temp_f1_17;
    f32 temp_f1_18;
    f32 temp_f1_19;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_10;
    f32 var_f0_11;
    f32 var_f0_12;
    f32 var_f0_13;
    f32 var_f0_14;
    f32 var_f0_15;
    f32 var_f0_16;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    f32 var_f0_6;
    f32 var_f0_7;
    f32 var_f0_8;
    f32 var_f0_9;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f23;
    s16 temp_16_2;
    s16 temp_17_5;
    s32 temp_16_3;
    s32 temp_16_5;
    s32 temp_17_2;
    s32 temp_17_4;
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_19_3;
    s32 temp_19_5;
    s32 temp_20_2;
    s32 temp_20_3;
    s32 temp_23;
    s32 temp_2_19;
    s32 temp_30;
    s32 temp_5;
    s32 var_10;
    s32 var_10_10;
    s32 var_10_11;
    s32 var_10_12;
    s32 var_10_13;
    s32 var_10_2;
    s32 var_10_3;
    s32 var_10_4;
    s32 var_10_5;
    s32 var_10_6;
    s32 var_10_7;
    s32 var_10_8;
    s32 var_10_9;
    s32 var_16;
    s32 var_16_2;
    s32 var_18;
    s32 var_20;
    s32 var_20_2;
    s32 var_3;
    s32 var_3_10;
    s32 var_3_11;
    s32 var_3_12;
    s32 var_3_13;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_4;
    s32 var_3_5;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s32 var_4;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_9;
    s32 var_9_10;
    s32 var_9_11;
    s32 var_9_12;
    s32 var_9_13;
    s32 var_9_2;
    s32 var_9_3;
    s32 var_9_4;
    s32 var_9_5;
    s32 var_9_6;
    s32 var_9_7;
    s32 var_9_8;
    s32 var_9_9;
    s64 temp_17;
    s64 temp_18;
    s64 temp_20;
    s64 temp_3_2;
    s64 temp_3_3;
    u16 temp_18_3;
    u16 temp_2_15;
    u16 temp_2_16;
    u16 temp_2_6;
    u16 temp_2_8;
    u8 *var_18_2;
    u8 temp_16;
    u8 temp_16_4;
    u8 temp_17_3;
    u8 temp_18_2;
    u8 temp_19_4;
    u8 temp_19_6;
    u8 temp_20_4;
    u8 temp_2;
    u8 temp_2_10;
    u8 temp_2_12;
    u8 temp_2_14;
    u8 temp_2_17;
    u8 temp_2_18;
    u8 temp_2_20;
    u8 temp_2_21;
    u8 temp_2_22;
    u8 temp_2_2;
    u8 temp_2_4;
    u8 temp_2_5;
    u8 temp_2_7;
    u8 temp_2_9;
    u8 temp_3_6;
    u8 var_6;
    u8 var_8;
    u8 *temp_2_11;
    u8 *temp_2_13;
    u8 *temp_2_3;
    u8 *temp_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *temp_4;

    /* var_18 in $s2; default path uses incoming (no source init) */
    func_0034f1e0();
    temp_f25 = (*( f32 *)((u8 *)(arg0) + (4)));
    temp_f24 = (*( f32 *)((u8 *)(arg0) + (8)));
    temp_2 = (u8)(*( u8 *)((u8 *)(arg0) + (0)));
    if ((s32) temp_2 >= 0) {
        var_f1 = (f32) temp_2;
    } else {
        var_f1 = 2.0f * (f32) ((temp_2 >> 1) | (temp_2 & 1));
    }
    temp_f26 = var_f1 / 255.0f;
    if (*( s32 *)((u8 *)(arg0) + (0x10)) != 0) {
        spF0 = temp_f25;
        spF4 = temp_f24;
        temp_f1 = 255.0f * temp_f26;
        if (2.1474836e9f <= temp_f1) {
            var_3 = 0x4F000000 & 0xFF;
        } else {
            var_3 = (((s32)((temp_f1 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        func_0034c270(((s64)(spF0)), var_3 & 0xFF, *( s32 *)((u8 *)(arg0) + (0x10)), 0);
    }
    if (*( s32 *)((u8 *)(arg0) + (0x1C)) & 1) {
        var_16 = 0;
do {
                temp_3 = (u8 *)(arg0 + (var_16 * 0x30));
                spF0 = temp_f25 + *(f32 *)(temp_3 + 0x6A0);
                spF4 = 64.0f * (f32)var_16 + (77.0f + (temp_f24 + *(f32 *)(temp_3 + 0x6A4)));
                temp_2_2 = (u8)(*( u8 *)((u8 *)(temp_3) + (0x6AA)));
                if ((s32) temp_2_2 >= 0) {
                    var_f0 = (f32) temp_2_2;
                } else {
                    var_f0 = 2.0f * (f32) ((temp_2_2 >> 1) | (temp_2_2 & 1));
                }
                temp_f1_2 = var_f0 * temp_f26;
                if (2.1474836e9f <= temp_f1_2) {
                    var_6 = 0x4F000000 & 0xFF;
                } else {
                    var_6 = (((s32)((temp_f1_2 - 2.1474836e9f))) | 0x80000000) & 0xFF;
                }
                temp_2_3 = (u8 *)((s32)&D_0064CC30 + (var_16 * 4));
                spFC = (u8)(*( u8 *)((u8 *)(temp_2_3) + (0)));
                spFD = (u8)(*( u8 *)((u8 *)(temp_2_3) + (1)));
                spFE = (u8)(*( u8 *)((u8 *)(temp_2_3) + (2)));
                spFF = (u8)(*( u8 *)((u8 *)(temp_2_3) + (3)));
                spFF = var_6;
                spE0 = (s32)spF0;
                spE4 = (s32)spF4;
                spE8 = 0x280;
                spEC = 3;
                D_00887300[0](1, 0);
                func_0045d6e0(&spFC, (u8 *)&spE0, 0.0f, (s64)0);
                var_16 += 1;
} while (var_16 < 6);
        var_16_2 = 0;
loop_22:
        if (var_16_2 < 5) {
            if ((var_16_2 + *( s16 *)((u8 *)(arg0) + (0x26))) < *( s16 *)((u8 *)(arg0) + (0x134))) {
                func_003599c0(var_16_2, arg0);
            }
            var_16_2 += 1;
            goto loop_22;
        }
        temp_f1_3 = 255.0f * temp_f26;
        if (2.1474836e9f <= temp_f1_3) {
            var_5 = 0x4F000000 & 0xFF;
        } else {
            var_5 = (((s32)((temp_f1_3 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        func_00355410(*( s32 *)((u8 *)(arg0) + (0x1308)), var_5);
        func_00354ba0(*( s32 *)((u8 *)(arg0) + (0x1308)));
        spF0 = (f32) 0x25F + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x820)));
        spF4 = (f32) 0x107 + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x824)));
        temp_2_4 = (u8)(*( u8 *)((u8 *)(arg0) + (0x82A)));
        if ((s32) temp_2_4 >= 0) {
            var_f0_2 = (f32) temp_2_4;
        } else {
            var_f0_2 = 2.0f * (f32) ((temp_2_4 >> 1) | (temp_2_4 & 1));
        }
        temp_f1_4 = var_f0_2 * temp_f26;
        if (2.1474836e9f <= temp_f1_4) {
            var_3_2 = 0x4F000000 & 0xFF;
        } else {
            var_3_2 = (((s32)((temp_f1_4 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        temp_16 = var_3_2 & 0xFF;
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x11DC)), 0xFAU, 0xA1U, 0U, temp_16, spF0, spF4);
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x11E0)), 0xFAU, 0xA1U, 0U, temp_16, spF0, 135.0f + spF4);
        var_f1_2 = 6.0f;
        temp_5 = (s32)(*( s16 *)((u8 *)(arg0) + (0x134)) - 5);
        if (temp_5 > 0) {
            var_f1_2 = (6.0f + (f32) ((s32) (*( s16 *)((u8 *)(arg0) + (0x26)) * 0x64) / temp_5));
        }
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x11D0)), 0xFAU, 0xA1U, 0U, temp_16, spF0, spF4 + var_f1_2);
    }
    if (*( s32 *)((u8 *)(arg0) + (0x1C)) & 4) {
        temp_19 = (s32)(*( s32 *)((u8 *)(arg0) + (0x11D8)));
        temp_16_2 = (s16)(*( s16 *)((u8 *)(arg0) + (0x22)));
        spF0 = (f32) 0x20F + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x460)));
        spF4 = ((temp_f24 + *( f32 *)((u8 *)(arg0) + (0x464))) - 3.0f);
        temp_2_5 = (u8)(*( u8 *)((u8 *)(arg0) + (0x46A)));
        if ((s32) temp_2_5 >= 0) {
            var_f0_3 = (f32) temp_2_5;
        } else {
            var_f0_3 = 2.0f * (f32) ((temp_2_5 >> 1) | (temp_2_5 & 1));
        }
        temp_f1_5 = var_f0_3 * temp_f26;
        if (2.1474836e9f <= temp_f1_5) {
            var_3_3 = 0x4F000000 & 0xFF;
        } else {
            var_3_3 = (((s32)((temp_f1_5 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        temp_2_6 = (u16)(*( u16 *)((u8 *)(arg0) + (0x470)));
        if ((s32) temp_2_6 >= 0) {
            var_f20 = (f32) temp_2_6;
        } else {
            var_f20 = 2.0f * (f32) ((temp_2_6 >> 1) | (temp_2_6 & 1));
        }
        temp_20 = (s64) (((s64)((func_0046b260(temp_19) / 2.0f))) << 0x30) >> 0x30;
        temp_3_2 = (s64) (((s64)((func_0046b2f0(temp_19) / 2.0f))) << 0x30) >> 0x30;
        if (2.1474836e9f <= var_f20) {
            var_9 = 0x4F000000 & 0xFFFF;
        } else {
            var_9 = (((s32)((var_f20 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        if (2.1474836e9f <= var_f20) {
            var_10 = 0x4F000000 & 0xFFFF;
        } else {
            var_10 = (((s32)((var_f20 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        func_0034f320(temp_19, 0xFFU, 0xD1U, 0x34U, var_3_3 & 0xFF, var_9, var_10, temp_20, spF0, spF4, 0, (f32) temp_16_2, temp_3_2);
        spF0 = (f32) 0x221 + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x490)));
        spF4 = ((temp_f24 + *( f32 *)((u8 *)(arg0) + (0x494))) - 6.0f);
        temp_2_7 = (u8)(*( u8 *)((u8 *)(arg0) + (0x49A)));
        if ((s32) temp_2_7 >= 0) {
            var_f0_4 = (f32) temp_2_7;
        } else {
            var_f0_4 = 2.0f * (f32) ((temp_2_7 >> 1) | (temp_2_7 & 1));
        }
        temp_f1_6 = var_f0_4 * temp_f26;
        if (2.1474836e9f <= temp_f1_6) {
            var_3_4 = 0x4F000000 & 0xFF;
        } else {
            var_3_4 = (((s32)((temp_f1_6 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        temp_2_8 = (u16)(*( u16 *)((u8 *)(arg0) + (0x4A0)));
        if ((s32) temp_2_8 >= 0) {
            var_f20_2 = (f32) temp_2_8;
        } else {
            var_f20_2 = 2.0f * (f32) ((temp_2_8 >> 1) | (temp_2_8 & 1));
        }
        temp_17 = (s64) (((s64)((func_0046b260(temp_19) / 2.0f))) << 0x30) >> 0x30;
        temp_3_3 = (s64) (((s64)((func_0046b2f0(temp_19) / 2.0f))) << 0x30) >> 0x30;
        if (2.1474836e9f <= var_f20_2) {
            var_9_2 = 0x4F000000 & 0xFFFF;
        } else {
            var_9_2 = (((s32)((var_f20_2 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        if (2.1474836e9f <= var_f20_2) {
            var_10_2 = 0x4F000000 & 0xFFFF;
        } else {
            var_10_2 = (((s32)((var_f20_2 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        func_0034f320(temp_19, 0xFFU, 0xFFU, 0x81U, var_3_4 & 0xFF, var_9_2, var_10_2, temp_17, spF0, spF4, 0, (f32) temp_16_2, temp_3_3);
    }
    if (*( s32 *)((u8 *)(arg0) + (0x1C)) & 0x10) {
        spF0 = (f32) 0x175 + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x160)));
        spF4 = ((25.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x164)))) - 1.0f);
        temp_2_9 = (u8)(*( u8 *)((u8 *)(arg0) + (0x16A)));
        if ((s32) temp_2_9 >= 0) {
            var_f0_5 = (f32) temp_2_9;
        } else {
            var_f0_5 = 2.0f * (f32) ((temp_2_9 >> 1) | (temp_2_9 & 1));
        }
        temp_f1_7 = var_f0_5 * temp_f26;
        if (2.1474836e9f <= temp_f1_7) {
            var_3_5 = 0x4F000000 & 0xFF;
        } else {
            var_3_5 = (((s32)((temp_f1_7 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x129C)), 0xFFU, 0xFFU, 0xFFU, var_3_5 & 0xFF, spF0, spF4);
    }
    if (*( s32 *)((u8 *)(arg0) + (0x1C)) & 2) {
        temp_19_2 = (s32)(*( s16 *)((u8 *)(arg0) + (0x24)) + *( s16 *)((u8 *)(arg0) + (0x26)));
        if ((temp_19_2 < 0) || (temp_19_2 >= 0x15)) {
            func_0046d730(&D_0064CC98, 0x2DD);
        }
        temp_3_4 = (u8 *)((temp_19_2 * 0xC) + arg0);
        spD0 = (signed __int128) *( u16 *)((u8 *)(temp_3_4) + (0x3C));
        temp_30 = (s32)((*( u8 *)((u8 *)(temp_3_4) + (0x38)) - 1) & 0xFF);
        temp_17_2 = (s32)(*( s32 *)((u8 *)(temp_3_4) + (0x40)));
        temp_23 = (s32)(*( s32 *)((u8 *)(arg0) + (0x11D4)));
        spF0 = ((2.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x910)))) - 36.0f);
        spF4 = (2.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x914))));
        temp_2_10 = (u8)(*( u8 *)((u8 *)(arg0) + (0x91A)));
        if ((s32) temp_2_10 >= 0) {
            var_f0_6 = (f32) temp_2_10;
        } else {
            var_f0_6 = 2.0f * (f32) ((temp_2_10 >> 1) | (temp_2_10 & 1));
        }
        temp_f1_8 = var_f0_6 * temp_f26;
        if (2.1474836e9f <= temp_f1_8) {
            var_3_6 = 0x4F000000 & 0xFF;
        } else {
            var_3_6 = (((s32)((temp_f1_8 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        temp_16_3 = var_3_6 & 0xFF;
        var_20 = 0;
loop_95:
        if (var_20 < 0x6C) {
            temp_4 = (u8 *)(arg0 + (var_20 * 0x14));
            if (*( s16 *)((u8 *)(temp_4) + (0x960)) >= 0) {
                temp_f20 = (spF0 + (f32) ((*( s32 *)((u8 *)(temp_4) + (0x96C)) - *( s32 *)((u8 *)(temp_4) + (0x964))) * 0x2C));
                temp_f21 = (spF4 + (f32) ((*( s32 *)((u8 *)(temp_4) + (0x970)) - *( s32 *)((u8 *)(temp_4) + (0x968))) * 0x25));
                temp_f0 = (func_0034f720(temp_4 + 0x960, 0x3F000000, 0x3F000000, 0x3F800000));
                temp_2_11 = (u8 *)((s32)&D_0064CC48 + (*( s16 *)((u8 *)(temp_4) + (0x960)) * 4));
                spFC = (u8)(*( u8 *)((u8 *)(temp_2_11) + (0)));
                spFD = (u8)(*( u8 *)((u8 *)(temp_2_11) + (1)));
                spFE = (u8)(*( u8 *)((u8 *)(temp_2_11) + (2)));
                spFF = (u8)(*( u8 *)((u8 *)(temp_2_11) + (3)));
                if (temp_16_3 >= 0) {
                    var_f1_3 = (f32) temp_16_3;
                } else {
                    var_f1_3 = 2.0f * (f32) (((u32) temp_16_3 >> 1) | (temp_16_3 & 1));
                }
                temp_f1_9 = var_f1_3 * temp_f0;
                if (2.1474836e9f <= temp_f1_9) {
                    var_8 = 0x4F000000 & 0xFF;
                } else {
                    var_8 = (((s32)((temp_f1_9 - 2.1474836e9f))) | 0x80000000) & 0xFF;
                }
                func_0034f2e0(temp_23, (s32)spFC, (s32)spFD, (s32)spFE, (s32)var_8, temp_f20, temp_f21);
            }
            var_20 += 1;
            goto loop_95;
        }
        temp_2_12 = (u8)(*( u8 *)((u8 *)(arg0) + (0x85A)));
        if ((s32) temp_2_12 >= 0) {
            var_f0_7 = (f32) temp_2_12;
        } else {
            var_f0_7 = 2.0f * (f32) ((temp_2_12 >> 1) | (temp_2_12 & 1));
        }
        temp_f1_10 = var_f0_7 * temp_f26;
        if (2.1474836e9f <= temp_f1_10) {
            var_3_7 = 0x4F000000 & 0xFF;
        } else {
            var_3_7 = (((s32)((temp_f1_10 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        temp_16_4 = var_3_7 & 0xFF;
        temp_f12 = (127.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x850))));
        spF0 = temp_f12;
        temp_f13 = (17.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x854))));
        spF4 = temp_f13;
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1254)), 0xDDU, 0x74U, 0U, (s32)temp_16_4, temp_f12, temp_f13);
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1258)), 0xDDU, 0x74U, 0U, (s32)temp_16_4, (f32) 0x179 + spF0, temp_f13);
        temp_f12_2 = (135.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x850))));
        spF0 = temp_f12_2;
        temp_f13_2 = (21.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x854))));
        spF4 = temp_f13_2;
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1298)), (s32)D_0064B2E0, (s32)D_0064B2E1, (s32)D_0064B2E2, (s32)temp_16_4, temp_f12_2, temp_f13_2);
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1218)), (s32)D_0064B2E0, (s32)D_0064B2E1, (s32)D_0064B2E2, (s32)temp_16_4, 88.0f + spF0, temp_f13_2);
        temp_f0_2 = (183.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x850))));
        spF0 = temp_f0_2;
        spF4 = (22.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x854))));
        temp_20_2 = (s32)(*( s32 *)((u8 *)((((temp_30 & 0xFF) * 4) + arg0)) + (0x12A4)));
        func_0034f2e0(temp_20_2, 0xDDU, 0x74U, 0U, (s32)temp_16_4, temp_f0_2 - (func_0046b260(temp_20_2) / 2.0f), spF4);
        spF0 = (245.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x850))));
        spF4 = (19.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x854))));
        temp_20_3 = temp_16_4 & 0xFF;
        temp_2_13 = (u8 *)((temp_19_2 * 0xC) + arg0);
        func_00275020(temp_20_3 | ~0x7EFF, 0, 1, func_00246830(*( u16 *)((u8 *)(temp_2_13) + (0x3A))), 0, -2, spF0, spF4, 0);
        temp_19_3 = (s32)(func_00246910((s16) *( u16 *)((u8 *)(temp_2_13) + (0x3A))));
        spF0 = (130.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x850))));
        spF4 = (46.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x854))));
        if (temp_17_2 == 2) {
            var_18 = 0xA;
        } else if (temp_17_2 == 3) {
            var_18 = 0xB;
        } else if ((temp_17_2 == 1) || (temp_17_2 == 0)) {
            var_18 = (s32)(((func_00107ac0((s16) *( u16 *)((u8 *)(temp_2_13) + (0x3A))) & 0xFFFF) - 1) & 0xFFFF);
        }
        func_002bc0b0(temp_20_3 | ~0xFF, 1, 6, 7, *((u8 *)(temp_19_3 + ((var_18 & 0xFFFF) * 2))), spF0, spF4, 0);
        temp_f22 = (15.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x8E0))));
        temp_f21_2 = (17.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x8E4))));
        temp_2_14 = (u8)(*( u8 *)((u8 *)(arg0) + (0x8EA)));
        if ((s32) temp_2_14 >= 0) {
            var_f0_8 = (f32) temp_2_14;
        } else {
            var_f0_8 = 2.0f * (f32) ((temp_2_14 >> 1) | (temp_2_14 & 1));
        }
        temp_f1_11 = var_f0_8 * temp_f26;
        if (2.1474836e9f <= temp_f1_11) {
            var_3_8 = 0x4F000000 & 0xFF;
        } else {
            var_3_8 = (((s32)((temp_f1_11 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        temp_19_4 = var_3_8 & 0xFF;
        temp_2_15 = (u16)(*( u16 *)((u8 *)(arg0) + (0x8F0)));
        if ((s32) temp_2_15 >= 0) {
            var_f20_3 = (f32) temp_2_15;
        } else {
            var_f20_3 = 2.0f * (f32) ((temp_2_15 >> 1) | (temp_2_15 & 1));
        }
        temp_2_16 = (u16)(*( u16 *)((u8 *)(arg0) + (0x8F6)));
        if ((s32) temp_2_16 >= 0) {
            var_f23 = (f32) temp_2_16;
        } else {
            var_f23 = 2.0f * (f32) ((temp_2_16 >> 1) | (temp_2_16 & 1));
        }
        spF0 = temp_f22;
        spF4 = temp_f21_2;
        if (2.1474836e9f <= var_f20_3) {
            var_9_3 = 0x4F000000 & 0xFFFF;
        } else {
            var_9_3 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        if (2.1474836e9f <= var_f23) {
            var_10_3 = 0x4F000000 & 0xFFFF;
        } else {
            var_10_3 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        func_0034f320(*( s32 *)((u8 *)(arg0) + (0x1248)), 0xDDU, 0x74U, 0U, (s32)temp_19_4, var_9_3, var_10_3, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
        if (2.1474836e9f <= var_f20_3) {
            var_9_4 = 0x4F000000 & 0xFFFF;
        } else {
            var_9_4 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        if (2.1474836e9f <= var_f23) {
            var_10_4 = 0x4F000000 & 0xFFFF;
        } else {
            var_10_4 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        func_0034f320(*( s32 *)((u8 *)(arg0) + (0x124C)), 0xDDU, 0x74U, 0U, (s32)temp_19_4, var_9_4, var_10_4, 0, spF0, 153.0f + spF4, 0, 0.0f, (s64)0);
        switch (temp_17_2) {                        /* switch 2; irregular */
        case 2:                                     /* switch 2 */
        case 3:                                     /* switch 2 */
            spF0 = temp_f22 + ((4.0f * var_f20_3) / 4096.0f);
            spF4 = temp_f21_2 + ((23.0f * var_f23) / 4096.0f);
            if (2.1474836e9f <= var_f20_3) {
                var_9_5 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_5 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= var_f23) {
                var_10_5 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_5 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)(arg0) + (0x1284)), 0x18U, 0U, 8U, (s32)temp_19_4, var_9_5, var_10_5, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
            if (2.1474836e9f <= var_f20_3) {
                var_9_6 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_6 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= var_f23) {
                var_10_6 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_6 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)(arg0) + (0x1288)), 0x18U, 0U, 8U, (s32)temp_19_4, var_9_6, var_10_6, 0, spF0, 124.0f + spF4, 0, 0.0f, (s64)0);
            break;
        case 1:                                     /* switch 2 */
            spF0 = temp_f22 + ((4.0f * var_f20_3) / 4096.0f);
            spF4 = temp_f21_2 + ((4.0f * var_f23) / 4096.0f);
            if (2.1474836e9f <= var_f20_3) {
                var_9_7 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_7 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= var_f23) {
                var_10_7 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_7 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)(arg0) + (0x1290)), (s32)(*( u8 *)((u8 *)(&D_0064B2EC) + (0))), (s32)(*( u8 *)((u8 *)(&D_0064B2EC) + (1))), (s32)(*( u8 *)((u8 *)(&D_0064B2EC) + (2))), (s32)temp_19_4, var_9_7, var_10_7, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
            if (2.1474836e9f <= var_f20_3) {
                var_9_8 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_8 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= var_f23) {
                var_10_8 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_8 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)(arg0) + (0x1288)), (s32)(*( u8 *)((u8 *)(&D_0064B2EC) + (0))), (s32)(*( u8 *)((u8 *)(&D_0064B2EC) + (1))), (s32)(*( u8 *)((u8 *)(&D_0064B2EC) + (2))), (s32)temp_19_4, var_9_8, var_10_8, 0, spF0, 143.0f + spF4, 0, 0.0f, (s64)0);
            break;
        }
        spF0 = temp_f22 + ((6.0f * var_f20_3) / 4096.0f);
        spF4 = temp_f21_2 + ((25.0f * var_f23) / 4096.0f);
        if (2.1474836e9f <= var_f20_3) {
            var_9_9 = 0x4F000000 & 0xFFFF;
        } else {
            var_9_9 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        if (2.1474836e9f <= var_f23) {
            var_10_9 = 0x4F000000 & 0xFFFF;
        } else {
            var_10_9 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
        }
        func_0034f320(*( s32 *)((u8 *)(arg0) + (0x1250)), 0xFFU, 0xEBU, 0x3DU, (s32)temp_19_4, var_9_9, var_10_9, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
        if (temp_17_2 == 1) {
            spF0 = temp_f22 + ((19.0f * var_f20_3) / 4096.0f);
            spF4 = temp_f21_2 + ((6.0f * var_f23) / 4096.0f);
            if (2.1474836e9f <= var_f20_3) {
                var_9_10 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_10 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= var_f23) {
                var_10_10 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_10 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)(arg0) + (0x128C)), 0xDDU, 0x74U, 0U, (s32)temp_19_4, var_9_10, var_10_10, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
        } else {
            spF0 = temp_f22 + ((15.0f * var_f20_3) / 4096.0f);
            spF4 = temp_f21_2 + ((7.0f * var_f23) / 4096.0f);
            if (2.1474836e9f <= var_f20_3) {
                var_9_11 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_11 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= var_f23) {
                var_10_11 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_11 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)(arg0) + (0x11E8)), (s32)D_0064B2E0, (s32)D_0064B2E1, (s32)D_0064B2E2, (s32)temp_19_4, var_9_11, var_10_11, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
            spF0 = temp_f22 + ((79.0f * var_f20_3) / 4096.0f);
            spF4 = temp_f21_2 + ((4.0f * var_f23) / 4096.0f);
            if (2.1474836e9f <= var_f20_3) {
                var_9_12 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_12 = (((s32)((var_f20_3 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= var_f23) {
                var_10_12 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_12 = (((s32)((var_f23 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)((arg0 + (u16)spD0 * 4)) + (0x11EC)), (s32)D_0064B2E0, (s32)D_0064B2E1, (s32)D_0064B2E2, (s32)temp_19_4, var_9_12, var_10_12, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
        }
        temp_20_4 = (u8)(*( u8 *)((u8 *)(arg0) + (0x8BA)));
        if ((s32) temp_20_4 > 0) {
            if ((s32) temp_20_4 >= 0) {
                var_f0_9 = (f32) temp_20_4;
            } else {
                var_f0_9 = 2.0f * (f32) ((temp_20_4 >> 1) | (temp_20_4 & 1));
            }
            temp_f1_12 = var_f0_9 * temp_f26;
            if (2.1474836e9f <= temp_f1_12) {
                var_5_2 = 0x4F000000 & 0xFF;
            } else {
                var_5_2 = (((s32)((temp_f1_12 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            func_0035aff0(*( u8 **)((u8 *)(arg0) + (0x130C)), var_5_2);
        }
        switch (temp_17_2) {                        /* switch 3; irregular */
        case 1:                                     /* switch 3 */
            break;
        case 2:                                     /* switch 3 */
            temp_f12_3 = 69.0f + temp_f25;
            spF0 = temp_f12_3;
            temp_f13_3 = 133.0f + temp_f24;
            spF4 = temp_f13_3;
            func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1278)), 0xFFU, 0xFFU, 0xFFU, (s32)temp_20_4, temp_f12_3, temp_f13_3);
            spF0 = 21.5f + temp_f25;
            spF4 = 42.0f + temp_f24;
            temp_19_5 = (s32)(*( s32 *)((u8 *)(arg0) + (0x127C)));
            temp_18 = (s64) (((s64)((func_0046b260(temp_19_5) / 2.0f))) << 0x30) >> 0x30;
            func_0034f320(temp_19_5, 0x18U, 0U, 8U, (s32)temp_20_4, 0x1000, 0x1000, temp_18, spF0, spF4, 0, *( f32 *)((u8 *)(arg0) + (0x30)), (s64) (((s64)((func_0046b2f0(temp_19_5) / 2.0f))) << 0x30) >> 0x30);
            break;
        case 3:                                     /* switch 3 */
            temp_f12_4 = 79.0f + temp_f25;
            spF0 = temp_f12_4;
            temp_f13_4 = 133.0f + temp_f24;
            spF4 = temp_f13_4;
            func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1270)), 0xFFU, 0xFFU, 0xFFU, (s32)temp_20_4, temp_f12_4, temp_f13_4);
            spF0 = 21.5f + temp_f25;
            spF4 = 42.0f + temp_f24;
            temp_f4 = 4096.0f * (1.0f + *(f32 *)(arg0 + 0x34));
            spF0 = (21.5f + temp_f25) - (100.0f * *(f32 *)(arg0 + 0x34));
            if (2.1474836e9f <= temp_f4) {
                var_9_13 = 0x4F000000 & 0xFFFF;
            } else {
                var_9_13 = (((s32)((temp_f4 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            if (2.1474836e9f <= temp_f4) {
                var_10_13 = 0x4F000000 & 0xFFFF;
            } else {
                var_10_13 = (((s32)((temp_f4 - 2.1474836e9f))) | 0x80000000) & 0xFFFF;
            }
            func_0034f320(*( s32 *)((u8 *)(arg0) + (0x1274)), 0x18U, 0U, 8U, (s32)temp_20_4, var_9_13, var_10_13, (s64)0, spF0, spF4, 0, 0.0f, (s64)0);
            break;
        }
        var_20_2 = 0;
loop_222:
        if (var_20_2 < *( s32 *)((u8 *)(arg0) + (0x148))) {
            if (var_20_2 == *( s16 *)((u8 *)(arg0) + (0x28))) {
                var_18_2 = (u8 *)(&D_0064B2E8);
                var_22 = 8;
            } else {
                var_18_2 = (u8 *)(&D_0064B2E0);
                var_22 = 6;
            }
            temp_3_5 = (u8 *)(arg0 + (var_20_2 * 0x30));
            spF0 = 15.0f + (temp_f25 + *(f32 *)(temp_3_5 + 0x2B0));
            spF4 = 28.0f * (f32)var_20_2 + (178.0f + (temp_f24 + *(f32 *)(temp_3_5 + 0x2B4)));
            temp_2_17 = (u8)(*( u8 *)((u8 *)(temp_3_5) + (0x2BA)));
            if ((s32) temp_2_17 >= 0) {
                var_f0_10 = (f32) temp_2_17;
            } else {
                var_f0_10 = 2.0f * (f32) ((temp_2_17 >> 1) | (temp_2_17 & 1));
            }
            temp_f1_13 = var_f0_10 * temp_f26;
            if (2.1474836e9f <= temp_f1_13) {
                var_3_9 = 0x4F000000 & 0xFF;
            } else {
                var_3_9 = (((s32)((temp_f1_13 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_19_6 = var_3_9 & 0xFF;
            func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x125C)), *( u8 *)((u8 *)(var_18_2) + (0)), *( u8 *)((u8 *)(var_18_2) + (1)), *( u8 *)((u8 *)(var_18_2) + (2)), temp_19_6, spF0, spF4);
            func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1260)), *( u8 *)((u8 *)(var_18_2) + (0)), *( u8 *)((u8 *)(var_18_2) + (1)), *( u8 *)((u8 *)(var_18_2) + (2)), temp_19_6, 172.0f + spF0, spF4);
            func_00275330(temp_19_6 | ~0xFF, var_22, 2, func_0010d620(*( s16 *)((u8 *)((arg0 + (var_20_2 * 2))) + (0x136))), 8, 0x18, -1, 91.0f + spF0, spF4, 0);
            var_20_2 += 1;
            goto loop_222;
        }
        temp_18_2 = (u8)(*( u8 *)((u8 *)(arg0) + (0x94A)));
        if ((s32) temp_18_2 > 0) {
            if ((s32) temp_18_2 >= 0) {
                var_f0_11 = (f32) temp_18_2;
            } else {
                var_f0_11 = 2.0f * (f32) ((temp_18_2 >> 1) | (temp_18_2 & 1));
            }
            temp_f1_14 = var_f0_11 * temp_f26;
            if (2.1474836e9f <= temp_f1_14) {
                var_5_3 = 0x4F000000 & 0xFF;
            } else {
                var_5_3 = (((s32)((temp_f1_14 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            func_0035c040(*( u8 **)((u8 *)(arg0) + (0x1310)), var_5_3);
            switch (temp_17_2) {                    /* switch 4; irregular */
            case 0:                                 /* switch 4 */
            case 1:                                 /* switch 4 */
                break;
            case 2:                                 /* switch 4 */
                func_0035c670(*( u8 **)((u8 *)(arg0) + (0x1310)), &spF0);
                temp_f12_5 = spF0 + 162.0f;
                spF0 = temp_f12_5;
                temp_f13_5 = spF4 + 7.0f;
                spF4 = temp_f13_5;
                func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1280)), 0xFFU, 0xFFU, 0xFFU, temp_18_2, temp_f12_5, temp_f13_5);
                break;
            case 3:                                 /* switch 4 */
                func_0035c670(*( u8 **)((u8 *)(arg0) + (0x1310)), &spF0);
                temp_f12_6 = spF0 + 162.0f;
                spF0 = temp_f12_6;
                temp_f13_6 = spF4 + 7.0f;
                spF4 = temp_f13_6;
                func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1294)), 0xFFU, 0xFFU, 0xFFU, temp_18_2, temp_f12_6, temp_f13_6);
                break;
            default:                                /* switch 4 */
                func_0046d730(&D_0064CC98, 0x455);
                break;
            }
        }
        temp_2_18 = (u8)(*( u8 *)((u8 *)(arg0) + (0x88A)));
        if ((s32) temp_2_18 >= 0) {
            var_f0_12 = (f32) temp_2_18;
        } else {
            var_f0_12 = 2.0f * (f32) ((temp_2_18 >> 1) | (temp_2_18 & 1));
        }
        temp_f1_15 = var_f0_12 * temp_f26;
        if (2.1474836e9f <= temp_f1_15) {
            var_3_10 = 0x4F000000 & 0xFF;
        } else {
            var_3_10 = (((s32)((temp_f1_15 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        temp_17_3 = var_3_10 & 0xFF;
        temp_f12_7 = (227.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x880))));
        spF0 = temp_f12_7;
        temp_f13_7 = (f32) 0x13D + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x884)));
        spF4 = temp_f13_7;
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x126C)), (s32)D_0064B2E0, (s32)D_0064B2E1, (s32)D_0064B2E2, (s32)temp_17_3, temp_f12_7, temp_f13_7);
        temp_f12_8 = (234.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x880))));
        spF0 = temp_f12_8;
        temp_f13_8 = (320.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x884))));
        spF4 = temp_f13_8;
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1264)), (s32)(*( u8 *)((u8 *)(&D_0064B2E8) + (0))), (s32)(*( u8 *)((u8 *)(&D_0064B2E8) + (1))), (s32)(*( u8 *)((u8 *)(&D_0064B2E8) + (2))), (s32)temp_17_3, temp_f12_8, temp_f13_8);
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x1268)), (s32)(*( u8 *)((u8 *)(&D_0064B2E8) + (0))), (s32)(*( u8 *)((u8 *)(&D_0064B2E8) + (1))), (s32)(*( u8 *)((u8 *)(&D_0064B2E8) + (2))), (s32)temp_17_3, (f32) 0x173 + spF0, temp_f13_8);
        if (*( s32 *)((u8 *)(arg0) + (0x148)) > 0) {
            temp_18_3 = *(u16 *)((u8 *)(((*(s16 *)((u8 *)(arg0) + (0x28)) * 2) + arg0)) + (0x136));
            temp_17_4 = (s32)(func_00107ac0((s16) *( u16 *)((u8 *)(temp_2_13) + (0x3A))) & 0xFFFF);
            temp_2_19 = func_00246940((s64) ((s64) temp_18_3 << 0x30) >> 0x30);
            spF0 = (244.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x880))));
            spF4 = (320.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x884))));
            temp_3_6 = (u8)(*( u8 *)((u8 *)(arg0) + (0x88A)));
            if ((s32) temp_3_6 >= 0) {
                var_f0_13 = (f32) temp_3_6;
            } else {
                var_f0_13 = 2.0f * (f32) ((temp_3_6 >> 1) | (temp_3_6 & 1));
            }
            temp_f1_16 = var_f0_13 * temp_f26;
            if (2.1474836e9f <= temp_f1_16) {
                var_4 = 0x4F000000 & 0xFF;
            } else {
                var_4 = (((s32)((temp_f1_16 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_16_5 = var_4 & 0xFF;
            temp_17_5 = *( s16 *)((u8 *)((((temp_17_4 & 0xFFFF) * 2) + temp_2_19)) + (-2));
            func_002bc0b0(temp_16_5 | ~0x7EFF, 1, 8, 7, temp_17_5 - 1, spF0, spF4, 0);
            func_002bc0b0(temp_16_5 | ~0xFF, 1, 6, 7, temp_17_5, spF0, 28.0f + spF4, 0);
        }
    }
    if (*( s32 *)((u8 *)(arg0) + (0x1C)) & 0x20) {
        spF0 = (18.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x7C0))));
        spF4 = (f32) 0x197 + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x7C4)));
        temp_2_20 = (u8)(*( u8 *)((u8 *)(arg0) + (0x7CA)));
        if ((s32) temp_2_20 >= 0) {
            var_f0_14 = (f32) temp_2_20;
        } else {
            var_f0_14 = 2.0f * (f32) ((temp_2_20 >> 1) | (temp_2_20 & 1));
        }
        temp_f1_17 = var_f0_14 * temp_f26;
        if (2.1474836e9f <= temp_f1_17) {
            var_3_11 = 0x4F000000 & 0xFF;
        } else {
            var_3_11 = (((s32)((temp_f1_17 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x11E4)), 0xFFU, 0xFFU, 0xFFU, var_3_11 & 0xFF, spF0, spF4);
    }
    if (*( s32 *)((u8 *)(arg0) + (0x1C)) & 0x40) {
        spF0 = (18.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x7F0))));
        spF4 = (f32) 0x197 + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x7F4)));
        temp_2_21 = (u8)(*( u8 *)((u8 *)(arg0) + (0x7FA)));
        if ((s32) temp_2_21 >= 0) {
            var_f0_15 = (f32) temp_2_21;
        } else {
            var_f0_15 = 2.0f * (f32) ((temp_2_21 >> 1) | (temp_2_21 & 1));
        }
        temp_f1_18 = var_f0_15 * temp_f26;
        if (2.1474836e9f <= temp_f1_18) {
            var_3_12 = 0x4F000000 & 0xFF;
        } else {
            var_3_12 = (((s32)((temp_f1_18 - 2.1474836e9f))) | 0x80000000) & 0xFF;
        }
        func_0034f2e0(*( s32 *)((u8 *)(arg0) + (0x12A0)), 0xFFU, 0xFFU, 0xFFU, var_3_12 & 0xFF, spF0, spF4);
    }
    spF0 = (640.0f + (temp_f25 + *( f32 *)((u8 *)(arg0) + (0x430))));
    spF4 = (400.0f + (temp_f24 + *( f32 *)((u8 *)(arg0) + (0x434))));
    temp_2_22 = (u8)(*( u8 *)((u8 *)(arg0) + (0x43A)));
    if ((s32) temp_2_22 >= 0) {
        var_f0_16 = (f32) temp_2_22;
    } else {
        var_f0_16 = 2.0f * (f32) ((temp_2_22 >> 1) | (temp_2_22 & 1));
    }
    temp_f1_19 = var_f0_16 * temp_f26;
    if (2.1474836e9f <= temp_f1_19) {
        var_3_13 = 0x4F000000 & 0xFF;
    } else {
        var_3_13 = (((s32)((temp_f1_19 - 2.1474836e9f))) | 0x80000000) & 0xFF;
    }
    func_0034f9d0(((s64)(spF0)), var_3_13 & 0xFF, *( s16 *)((u8 *)(arg0) + (0x14C)), *( s32 *)((u8 *)(arg0) + (0x1304)), 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356a10);
#endif
// FUN_00359340
void func_00359340(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x960);
    }
}

// FUN_003593B0
void func_003593b0(u8 *arg0)
{
    *(f32 *)(arg0 + 0x34) *= 0.5f;
    *(f32 *)(arg0 + 0x30) *= -0.5f;
}

// FUN_003593E0
s32 func_003593e0(s32 arg0, s32 arg1, s16 arg2)
{
    s32 off = arg1 * 2;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s16 *)(p + 0x2A) = *(s16 *)(p + 0x24);
    *(s16 *)(p + 0x24) = arg2;
    return 1;
}
#pragma push
/* measured: opt_loop_invariants on hoists conversion constants for target. */
#pragma opt_loop_invariants on
// FUN_00359400
s32 func_00359400(u8 *arg0, s32 arg1)
{
    extern u8 D_0064B420[];
    extern u8 D_0064B8E0[];
    extern u8 D_0064BDA0[];
    extern u8 D_0064C260[];
    extern u8 D_0064C720[];
    u8 *table;
    f32 value1;
    f32 value2;
    s32 i;
    s32 j;
    s32 off;
    u8 *dst;
    u8 *src;

    if (arg1 == *(s32 *)(arg0 + 0x18)) {
        return 0;
    }
    for (i = 0; i < 43; i++) {
        off = i * 0x30;
        dst = arg0 + off;
        *(f32 *)(dst + 0x150) = *(f32 *)(dst + 0x160);
        *(f32 *)(dst + 0x154) = *(f32 *)(dst + 0x164);
        *(u16 *)(dst + 0x16C) = *(u16 *)(dst + 0x170);
        *(u16 *)(dst + 0x172) = *(u16 *)(dst + 0x176);
        *(u8 *)(dst + 0x168) = *(u8 *)(dst + 0x16A);
    }
    switch (arg1) {
    case 0:
        table = D_0064B420;
        *(s32 *)(arg0 + 0x1C) = 53;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    case 1:
        table = D_0064BDA0;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    case 2:
        table = D_0064C260;
        *(s32 *)(arg0 + 0x1C) = 55;
        break;
    case 3:
        table = D_0064C720;
        *(s32 *)(arg0 + 0x1C) = 70;
        *(s16 *)(arg0 + 0x14C) = 17;
        break;
    case 4:
        table = D_0064B8E0;
        *(s32 *)(arg0 + 0x1C) = 53;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    default:
        func_0046d730(&D_0064CC98, 0x51F);
        break;
    }
    if (table != NULL) {
        j = 0;
        goto table_loop_test;
table_loop_body:
        off = j * 0x1C;
        src = table + off;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x158) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x15C) = *(f32 *)(src + 4);
        value1 = *(f32 *)(src + 8);
        *(u16 *)(dst + 0x16E) = (u16)value1;
        value2 = *(f32 *)(src + 0xC);
        *(u16 *)(dst + 0x174) = (u16)value2;
        *(u8 *)(dst + 0x169) = *(u8 *)(src + 0x10);
        *(s32 *)(dst + 0x178) = *(s32 *)(src + 0x14);
        *(s32 *)(dst + 0x17C) = *(s32 *)(src + 0x18);
        j += 1;
table_loop_test:
        if (j < 43) {
            goto table_loop_body;
        }
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0x20) = 0;
    return 1;
}
#pragma pop
// FUN_003596A0
s32 func_003596a0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 43) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x17C)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_00359720
void func_00359720(u8 *arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_17;
    u8 *temp_2;

    var_17 = 0;
    goto loop_test;
loop_body:
    temp_2 = arg0 + (var_17 * 4) + 0x11D0;
    temp_4 = *(s32 *)temp_2;
    if (temp_4 != 0) {
        func_0046d280((void *)temp_4);
        *(s32 *)temp_2 = 0;
    }
    var_17 += 1;
loop_test:
    if (var_17 < 0x4D) {
        goto loop_body;
    }
    temp_4_2 = *(s32 *)(arg0 + 0x1308);
    if (temp_4_2 != 0) {
        func_00452080(temp_4_2);
        *(s32 *)(arg0 + 0x1308) = 0;
    }
    temp_4_3 = *(s32 *)(arg0 + 0x130C);
    if (temp_4_3 != 0) {
        func_00452080(temp_4_3);
        *(s32 *)(arg0 + 0x130C) = 0;
    }
    temp_4_4 = *(s32 *)(arg0 + 0x1310);
    if (temp_4_4 != 0) {
        func_00452080(temp_4_4);
        *(s32 *)(arg0 + 0x1310) = 0;
    }
    *(s32 *)(arg0 + 0x1C) = 0;
    func_002bc060(0xB);
}
// FUN_003597F0
void func_003597f0(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4_2;
    s32 var_18;
    s32 var_17;
    u8 *temp_4;
    u8 *temp_5;

    temp_16 = func_002467b0(
        *(u16 *)((u8 *)add_offset_first(
            (s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC,
            (u32)arg0) + 0x3A));
    var_18 = 0;
    var_17 = 0;
    goto loop_test;
loop_body:
    temp_4 = (u8 *)(temp_16 + (var_18 * 8));
    temp_5 = temp_4 + 0x28;
    if ((*(s32 *)temp_5 != 0) &&
        ((temp_4_2 = *(s32 *)(temp_4 + 0x24), temp_4_2 == 0) ||
         (func_00106330(temp_4_2) != 0))) {
        *(s16 *)(arg0 + (var_17 * 2) + 0x136) = *(s32 *)temp_5;
        var_17 += 1;
    }
    var_18 += 1;
loop_test:
    if (var_18 < 8) {
        goto loop_body;
    }
    *(s32 *)(arg0 + 0x148) = var_17;
}
/* measured: probe loop-invariant constant hoisting for func_003598d0. */
#pragma opt_loop_invariants on
// FUN_003598D0
void func_003598d0(u8 *arg0)
{
    s32 temp_3;
    s32 var_5;
    f32 value_1;
    f32 value_2;
    f32 value_3;
    s32 value_4;
    f32 value_5;

    temp_3 = *(s16 *)(arg0 + 0x24);
    var_5 = 0;
    value_1 = 800.0f;
    value_2 = -400.0f;
    value_3 = 29.5f;
    value_4 = 1;
    value_5 = 22.0f;
    goto loop_test;
loop_body:
    if (var_5 != temp_3) {
        if (var_5 < temp_3) {
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x5AC) = value_2;
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x18C) = value_2;
        } else {
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x5AC) = value_1;
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x18C) = value_1;
        }
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x4B8) = value_5;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x4CE) = value_4;
    } else {
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x5AC) = value_3;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x5C4) = value_4;
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x18C) = value_3;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x1A4) = value_4;
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x4BC) = value_3;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x4D4) = value_4;
    }
    var_5 += 1;
loop_test:
    if (var_5 < 5) {
        goto loop_body;
    }
}
/* measured: restore loop-invariant optimization after func_003598d0. */
#pragma opt_loop_invariants off
// FUN_003599A0
void func_003599a0(u8 *arg0)
{
    *(u32 *)(arg0 + 0x30) = 0x42700000;
    *(f32 *)(arg0 + 0x34) = D_00761260;
}

/* measured 003599c0: object 1163 instrs against retail 1190 stripped (1192 raw; -27, -2.3%; band
   1156-1228) via `python3 tools/fnalign.py src/promoted/code1_0035.c func_003599c0 --candidate
   /tmp/3599c0_v5.c`, 1022 edits (+2 reloc-only), probe 1072 differing words. Frame object 0x130 vs
   retail 0x120 (long-lived u16 spills quad, not half); calls 17/17 (11x0034f320 + 0046d730/0046b260/
   0045d6e0/00275020/00246830 + D_00887300 jalr); lwc1 20/20, swc1 12/12. Float landmarks exact
   (f25/f24/f26/f21/f22/f23/f28/f27/f20/f29/f30, shared madd products per 7r, descending float decls);
   residual is int-color allocation (params stuck $s0/$s1), v30 stack spill, and two CSE-held recomputes
   (o2 base, f20 div). Honest: slti for retail slti, sltiu only where retail sltiu (isSelf ==), u8/u16
   casts, s128 quad move with (u16) narrow, indirect D_00887300[0]; prototypes per recon (0034f320 x13,
   0045d6e0 x4, 00246830 returns u8 *). No sltiu-for-slti, no s64 flat, no opt_propagation, no volatile,
   no asm. Mid-function propoff scopes tried for the two recomputes: no-op, removed. */
// FUN_003599C0 NONMATCHING
#ifdef NON_MATCHING
void func_003599c0(s32 arg0, u8 *arg1)
{
    typedef signed __int128 s128;
    extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u32 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
    extern void func_0045d6e0(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2);
    extern u8 *func_00246830(s32 arg0);
    extern s32 func_00275020(f32 arg0, f32 fparg0, f32 fparg1, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5, s32 arg6);
    extern f32 func_0046b260(u8 *arg0);
    extern s32 (*D_00887300[])(s32, s32);
    extern u8 D_0064B2E0;
    extern u8 D_0064B2E8;
    extern u8 D_0064B2E9;
    extern u8 D_0064B2EA;
    extern u8 D_0064B2EB;
    extern u8 D_0064B2EC[];
    extern u8 D_0064B2F8[];
    u8 col[4];
    s32 rc[4];
    u16 f0v;
    s128 e0;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;
    f32 f25;
    f32 f24;
    f32 f23;
    f32 f22;
    f32 f21;
    f32 f20;
    f32 f5;
    f32 f1t;
    f32 f4;
    f32 f3;
    f32 f2;
    f32 b5B0;
    f32 b5B4;
    f32 c190;
    f32 c194;
    f32 c4C0;
    f32 c4C4;
    f32 f3b;
    f32 f1b;
    f32 f2b;
    f32 f4b;
    f32 f1c;
    f32 fb;
    u8 *e;
    u8 *b1;
    u8 *b2;
    u8 *b3;
    s32 v30;
    u8 t23;
    s32 isSelf;
    s32 o1;
    s32 o2;
    s32 o3;
    s32 w3A;
    u8 *sprE;
    u8 *sprL;
    u8 *spr;
    u8 *ns;
    s32 i;
    s32 cnt;
    s32 av;
    s32 color;
    u8 a3;
    u8 alpha2;
    u8 *ptab;
    u8 *ctab;
    u8 alpha;
    s32 mode;

    f25 = *(f32 *)(arg1 + 4);
    f24 = *(f32 *)(arg1 + 8);
    f26 = (f32)arg1[0] / 255.0f;
    e = arg1 + (*(s16 *)(arg1 + 0x26) + arg0) * 12;
    t23 = e[0x38];
    w3A = *(u16 *)(e + 0x3A);
    f0v = (u16)w3A;
    if (t23 >= 0x20) {
        func_0046d730(D_0064CC98, 0x5D5);
    }
    isSelf = (arg0 == *(s16 *)(arg1 + 0x24));
    mode = *(s32 *)(e + 0x40);
    o1 = arg0 * 48;
    b1 = arg1 + o1;
    b5B0 = *(f32 *)(b1 + 0x5B0);
    b5B4 = *(f32 *)(b1 + 0x5B4);
    f5 = f25 + b5B0;
    f21 = 64.0f * (f32)arg0;
    f1t = f21 + (f24 + b5B4);
    f4 = 81.0f + f1t;
    a3 = (u8)((f32)b1[0x5BA] * f26);
    f3 = (f32)*(u16 *)(b1 + 0x5C0);
    f2 = (f32)*(u16 *)(b1 + 0x5C6);
    if (isSelf) {
        col[0] = D_0064B2E8;
        col[1] = D_0064B2E9;
        col[2] = D_0064B2EA;
        col[3] = D_0064B2EB;
    } else {
        *(f32 *)col = *(f32 *)&D_0064B2E0;
    }
    col[3] = (u8)((f32)a3 * f26);
    rc[0] = (s32)f5;
    rc[1] = (s32)f4;
    rc[2] = (s32)(640.0f * f3 / 4096.0f);
    rc[3] = (s32)(59.0f * f2 / 4096.0f);
    D_00887300[0](1, 0);
    func_0045d6e0(col, (u8 *)rc, 0.0f, 0);
    o2 = arg0 * 48;
    b2 = arg1 + o2;
    c190 = *(f32 *)(b2 + 0x190);
    c194 = *(f32 *)(b2 + 0x194);
    f23 = 5.0f + (f25 + c190);
    f22 = 78.0f + (f21 + (f24 + c194));
    alpha = (u8)((f32)b2[0x19A] * f26);
    f28 = (f32)*(u16 *)(b2 + 0x1A0);
    f27 = (f32)*(u16 *)(b2 + 0x1A6);
    if (isSelf) {
        ptab = D_0064B2EC;
        ctab = &D_0064B2E8;
        v30 = 8;
    } else {
        ptab = D_0064B2F8;
        ctab = &D_0064B2E0;
        v30 = 6;
    }
    f20 = f27 / 4096.0f;
    if (mode != 1) {
        func_0034f320(*(u8 **)(arg1 + 0x11E8), 60.0f + f23, f22 + 16.0f * f20, 0.0f,
                      ptab[0], ptab[1], ptab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
        func_0034f320(*(u8 **)(arg1 + (u16)e0 * 4 + 0x11EC), 124.0f + f23, f22 + 14.0f * f20, 0.0f,
                      ptab[0], ptab[1], ptab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    }
    f30 = 59.0f + f23;
    f20 = f27 / 4096.0f;
    f29 = f22 + 32.0f * f20;
    func_0034f320(*(u8 **)(arg1 + 0x1214), f30, f29, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    func_0034f320(*(u8 **)(arg1 + 0x1218), 88.0f + f30, f29, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    f30 = 105.0f + f23;
    f29 = f22 + 33.0f * f20;
    sprE = *(u8 **)(arg1 + t23 * 4 + 0x12A0);
    fb = func_0046b260(sprE);
    func_0034f320(sprE, f30 - fb / 2.0f, f29, 0.0f,
                  ctab[0], ctab[1], ctab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    f30 = 156.0f + f23;
    f29 = f22 + 18.0f * f20;
    func_0034f320(*(u8 **)(arg1 + 0x122C), f30, f29, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    func_0034f320(*(u8 **)(arg1 + 0x1230), 214.0f + f30, f29, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    if (mode == 3) {
        spr = isSelf ? *(u8 **)(arg1 + 0x1238) : *(u8 **)(arg1 + 0x123C);
        func_0034f320(spr, 204.0f + f23, f22 + 14.0f * f20, 0.0f,
                      0xFF, 0xFF, 0xFF, alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    } else if (mode == 2) {
        spr = isSelf ? *(u8 **)(arg1 + 0x1240) : *(u8 **)(arg1 + 0x1244);
        func_0034f320(spr, 198.0f + f23, f22 + 14.0f * f20, 0.0f,
                      0xFF, 0xFF, 0xFF, alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
    } else if ((mode == 1) || (mode == 0)) {
        f30 = 4.0f + (157.0f + f23);
        f29 = f22 + 20.0f * f20;
        sprL = *(u8 **)(arg1 + 0x1234);
        cnt = (u16)e0;
        i = 0;
        while ((i < 10) && (i < cnt)) {
            func_0034f320(sprL, f30 + (f32)(i * 21), f29, 0.0f,
                          ctab[0], ctab[1], ctab[2], alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
            i++;
        }
    }
    if (f27 == 4096.0f) {
        f23 = 157.0f + f23;
        f20 = f22 + 30.0f * f20;
        av = ((alpha & 0xFF) * 0xFF) / 255;
        color = -256;
        color |= av;
        ns = func_00246830(f0v);
        func_00275020(f23, f20, 0.0f, color, v30, 1, ns, 0, -1);
    }
    o3 = arg0 * 48;
    b3 = arg1 + o3;
    c4C0 = *(f32 *)(b3 + 0x4C0);
    c4C4 = *(f32 *)(b3 + 0x4C4);
    f3b = 5.0f + (f25 + c4C0);
    f1b = f21 + (f24 + c4C4);
    f2b = 78.0f + f1b;
    alpha2 = (u8)((f32)b3[0x4CA] * f26);
    f4b = (f32)*(u16 *)(b3 + 0x4D0);
    f1c = (f32)*(u16 *)(b3 + 0x4D6);
    func_0034f320(*(u8 **)(arg1 + mode * 4 + 0x121C), 15.0f + f3b, 2.0f + f2b, 0.0f,
                  0xFF, 0xFF, 0xFF, alpha2, (u16)f4b, (u16)f1c, 0, 0.0f, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003599c0);
#endif
// FUN_0035AC60
void func_0035ac60(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    Float2 pair;
    s32 temp_17;
    u8 *temp_2;
    u8 *var_5;
    u8 *var_6;

    if ((arg1 < 0) || (arg1 >= 2)) {
        func_0046d730(&D_0064CC98, 0x6B8);
    }
    if (arg0 == NULL) {
        func_0046d730(&D_0064CC98, 0x6B9);
    }
    if (arg3 != 0) {
        var_6 = D_0064CC60 + (arg1 * 0x1C);
        var_5 = var_6 + 8;
    } else {
        var_5 = D_0064CC60 + (arg1 * 0x1C);
        var_6 = var_5 + 8;
    }
    temp_2 = D_0064CC70 + (arg1 * 0x1C);
    pair = *(Float2 *)temp_2;
    temp_17 = *(s32 *)(D_0064CC78 + (arg1 * 0x1C));
    if (arg2 != 0) {
        func_003550d0(arg0, (Float2 *)var_5, (Float2 *)var_6);
    } else {
        func_00355070(arg0, var_6);
    }
    func_003552d0(arg0, pair);
    func_00355300(arg0, temp_17);
}
// FUN_0035ADC0
u8 *func_0035adc0(s32 arg0, s64 arg1, s32 arg2)
{
    u8 *temp_2;
    u8 *temp_18;

    func_0044ea90(&D_0064CC98, 0x6ED);
    temp_2 = D_008873F4[0](1, 0x144, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&D_0064CC98, 0x6EE);
    }
    temp_18 = func_00451fc0(arg0, &D_0064CCD0, 0xC7, 0, 0,
                            (void *)func_0035aec0, (void *)func_0035af10,
                            temp_2);
    *(s8 *)(temp_2 + 0x20) = 0;
    *(s32 *)(temp_2 + 0x2C) = 0;
    *(u8 **)(temp_2 + 0x140) = D_0064CCB0;
    {
        extern void func_0035bc10();
        func_0035bc10((s32)temp_18, arg1, arg2);
    }
    return temp_18;
}
// FUN_0035AEC0
s32 func_0035aec0(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(s8 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = func_00354830(p + 0x30);
    }
    return 0;
}

// FUN_0035AF10
void func_0035af10(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}

// FUN_0035AF60
s32 func_0035af60(u8 *arg0)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(temp_3 + 0x2C) == 0) || (*(s8 *)(temp_3 + 0x20) == 0)) {
        return 0;
    }
    return 1;
}
// FUN_0035AFA0
s32 func_0035afa0(u8 *arg0) {
    s32 var_2;
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if ((*(s32 *)(temp_3 + 0x2C) == 0) || (*(s8 *)(temp_3 + 0x20) == 0)) {
        var_2 = 0;
    } else {
        var_2 = 1;
    }
    if (var_2 != 0) {
        return (s32)(**(s32 **)(temp_3 + 0x3C));
    }
    return 0;
}

/* func_0035aff0: NOT banked -- outside +-3% band (retail 692 vs object 646 = -46, -6.6%; band 671-713; window 2784B=696 words). Frame both 0xB10 (retail addiu sp,sp,-2832; object same), so no aggregate-spill deficit. Calls complete: retail 23 direct jal + 8 jalr = 31; object same (1x00457120,1x0035bad0,1x0034f1e0,10x003f6440,2x0044b7b0,2x0044b610,1x0035bd20,1x0046d730,2x00489f80,2x0048a000 + 3x87300/3x87310/2x87314 jalr). Both if arms present (flat mode&1|&2 with flatA/B sub-arms; wave mode&4 with 7x5 verts, 6x idx, 2x6 draws); no switch, so not the case-7 (200-instr) missing-arm class. Transfers: lwc1 31/31 exact, swc1 59/61 (-2) -- rules out missing spills (cf. 150-swci example); deficit is ALU/FPU conversions, concentrated in four retail-longer blocks (net 46 = retail-group 155 - object-group 109): [272:301]/[245:251] +23 (flat per-quad bltz/cvt/srl/or/mtc1 + swc1 0x28/0x2C + loop inc vs lui/sw), [545:567]/[517:519] +20 (wave 4th grey srl/andi/or/mtc1/cvt/add/swc1 0x2C + vtx/j/i inc + vtx>=0x24 guard + D_0064CC98+0x835), [584:596]/[546:548] +10 (idx i*10+j*2 sll/addu/sh chain + outer inc), [232:246]/[228:232] +10 (flat entry daddiu 0xF2/0x15/0xBA/0xFF + andi/mtc1 x4). Pragma 446 (opt_dead_assignments off) is false win per handoff 7s: measured on 46-short body, object 641 (-51) and 225 edits (worse) -- rejected on instruction count, do not re-run. Archive numbers stale per 7q: task 696 vs fnalign 692, task 317 lines vs file 316 (wc -l 316) -- re-measured 449w/194e+8, frame 0xB10. Repaired body kept in docs/probe_archive/F350_0035aff0_body.c (314 lines incl. repair note, 449w). Compiler b210 -O2. */
// measured: honest u32-flat retry (flatA/B/cR/cW as u32 with (f32)(u32), s32 counters kept); retail 692 object 668 (-24, -3.5% outside 671-713 by 3) edit 198 (+8 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_0035.c func_0035aff0 --candidate /tmp/35aff0_u32flat.c`; probe 456 via `python3 tools/probe_variants.py src/promoted/code1_0035.c func_0035aff0 --candidate u32flat=/tmp/35aff0_u32flat.c` (base 449); frame 0xB10 exact, jal 31==31, composition hole 2 lump 16 clean per 7aa; remaining -24 across four retail-longer blocks (flat entry retail[232:246] 0x35B390-0x35B3C8 daddiu/andi/mtc1 x4, flat per-quad retail[273:301] 0x35B434-0x35B4A4 bltz/cvt + loop inc, wave grey retail[545:567] 0x35B874-0x35B8CC srl/andi/or/mtc1/cvt/add 0x2C + vtx/j/i inc + guard + D_0064CC98, idx retail[584:596] 0x35B910-0x35B940 sll/addu/sh + outer inc); u32 counters (A, 690) and s64 flat (672) reach gate only via sltiu/dsll retail lacks -- rejected as dishonest per 7g/7v, production stays INCLUDE_ASM.
// measured: honest best direct_split (u32 flat + direct &qs[k].r/g/b/a addressing per 7a + fresh ii/jj for idx per 7n, s32 counters kept); retail 692 object 669 (-23, -3.3% outside 671-713 by 2) edit 198 (+8 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_0035.c func_0035aff0 --candidate /tmp/35aff0_direct_split.c`; probe 448 via `python3 tools/probe_variants.py src/promoted/code1_0035.c func_0035aff0 --candidate directsplit=/tmp/35aff0_direct_split.c` (base 449, u32flat 456); frame 0xB10 exact, jal 31==31, pure hole 2 (retail[201:203]/[209:211]/[309:311]) lump 16 (retail[493:493] object[467:483] extra grey a swc1 0x15C) clean per 7aa strict (needs both >=25); loose holes are four retail-longer replaces net +23 (flat entry +10, flat per-quad +22, wave +20, idx +10 minus surplus -16-6 as shift artefact from flat root propagation wall per file note); archived F350 base 646 s32 vs u32flat 668 +22 via unsigned (honest per micro bltz), direct +1 via addressing, split -1 edits via temps; in-gate A 690 via sltiu (retail slti) and s64flat 672 via dsll (retail 0 dsll) and propoff 684 via +154 words rejected per 7g/7v/7u, production stays INCLUDE_ASM.
// preserved per Main: archived F350_0035aff0_body.c is 314 lines (231-line body) measuring 646/692 -46 honest because it uses signed flat (s32 flatA/B/cR/cW with (f32)s32, 4 instrs via mtc1/cvt) where retail is unsigned (u32 with (f32)(u32), 15 instrs via bltz/srl/andi/or/mtc1/cvt/add); micro-measured conversion cost is 15 vs 4 (u32 bltz 15: bltz/nop/mtc1/nop/cvt/b/nop/srl/andi/or/mtc1/nop/cvt/add/swc1 vs s32 4: mtc1/nop/cvt/swc1), independently priced today at 16 vs plain mtc1/cvt by another agent -- two measurements, same number, best-evidenced conversion cost in project.
// attempted textbook 7aa repair per Main: write missing wave retail[545:567] 0x35B874-0x35B8CC (fourth grey srl/andi/or/mtc1/cvt/add/swc1 0x2C + addiu/slti/bnez x2 + slti guard + lui/addiu D) + delete object-only lump object[467:483] 16 (extra grey a bltz/swc1 0x15C verts[0].a due to flat shift) net +4 (669+4=673 inside); wave-pointer variant (verts a via u8 vp+0x2C per 7a) resists via flat-shift propagation wall: retail 692 object 666 (-26, -3.8% outside) edit 273 (+8 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_0035.c func_0035aff0 --candidate /tmp/35aff0_waveptr.c` (direct_split 669/198 honest best, 2 short); flat wall (constants fold to lui without whole-function propoff +154 words fake per 7u, scoped inert) shifts wave, hole+lump cancel, production stays INCLUDE_ASM.
/* measured 0035aff0 (owner, installing Fn0035's candidate): 700 against retail's 696-word
   window (+0.6%, band 671-713) and 692 stripped instructions (+1.2%), 167 edits down from the
   198 baseline, 453 differing words.  Frame 0xB10 exact with prologue 0-22 equal, 31 calls
   against 31 (23 direct, 8 indirect), lwc1 31/31, swc1 60/61.  Composition is clean: no lump or
   hole of 16 or more, longest insert 3 and longest delete 3.  Reached by the grey r,g,b,a store
   order, a staged texId, and duplicated cR/cW tails; no sltiu-for-slti, no s64 flat, no
   opt_propagation off, no volatile and no inline asm - the four dishonest routes to this band
   are listed in the notes above and all remain rejected. */
/* measured 0035aff0 (owner, 2026-09-19): fnalign **167 -> 164 edits**, count
   700 -> 698 against retail 696, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
// FUN_0035AFF0 NONMATCHING
#ifdef NON_MATCHING
f32 func_0035aff0(u8 *arg0, s32 arg1)
{
    extern u8 *func_00457120(void);
    extern f32 D_008872F8[];
    extern f32 func_0035bad0(u8 *arg0);
    extern void func_0034f1e0(void);
    extern s32 (*D_00887300[])(s32, s32);
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern void (*D_00887314[])(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0035bd20(Float2 first, Float2 second, Float2 origin);
    extern f32 fGpffff81e0;
    extern f32 fGpffff82fc;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        s32 _c;
        f32 u;
        f32 v;
        f32 q;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } Qf;
    Qf qs[4];
    Float2 cur;
    Float2 ptA;
    Float2 ptB;
    Qf verts[35];
    s16 idx[64];
    u8 *p;
    f32 sx;
    f32 sy;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    f32 blend;
    f32 z;
    f32 q;
    f32 ang1;
    f32 ang2;
    f32 s1;
    f32 c1;
    f32 s2;
    f32 c2;
    s32 mode;
    s32 i;
    s32 j;
    s32 vtx;
    s32 ii;
    s32 jj;
    u32 flatA;
    u32 flatB;

    p = *(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / *(f32 *)(func_00457120() + 0x80);
    {
        u8 *t = *(u8 **)(arg0 + 0x38);
        s32 flag;
        if ((*(s32 *)(t + 0x2C) == 0) || (*(s8 *)(t + 0x20) == 0)) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag == 0) {
            return 0.0f;
        }
    }
    blend = func_0035bad0(p);
    sx = 50.0f * *(f32 *)(p + 8);
    sy = 64.0f * *(f32 *)(p + 12);
    if (*(s32 *)(p + 0x28) & 1) {
        u0 = 0.78125f;
        v0 = 1.0f;
        u1 = -0.78125f;
        v1 = -1.0f;
    } else {
        u0 = 0.0f;
        v0 = 0.0f;
        u1 = 0.78125f;
        v1 = 1.0f;
    }
    qs[0].x = *(f32 *)p - sx;
    qs[0].y = *(f32 *)(p + 4) - sy;
    qs[0].z = z;
    qs[0].r = 0x437F0000;
    qs[0].g = 0x437F0000;
    qs[0].b = 0x437F0000;
    qs[0].a = (f32)(u32)arg1;
    qs[0].u = u0;
    qs[0].v = v0;
    qs[0].q = q;
    qs[1].x = *(f32 *)p + sx;
    qs[1].y = *(f32 *)(p + 4) - sy;
    qs[1].z = z;
    qs[1].r = 0x437F0000;
    qs[1].g = 0x437F0000;
    qs[1].b = 0x437F0000;
    qs[1].a = (f32)(u32)arg1;
    qs[1].u = u0 + u1;
    qs[1].v = v0;
    qs[1].q = q;
    qs[2].x = *(f32 *)p - sx;
    qs[2].y = *(f32 *)(p + 4) + sy;
    qs[2].z = z;
    qs[2].r = 0x437F0000;
    qs[2].g = 0x437F0000;
    qs[2].b = 0x437F0000;
    qs[2].a = (f32)(u32)arg1;
    qs[2].u = u0;
    qs[2].v = v0 + v1;
    qs[2].q = q;
    qs[3].x = *(f32 *)p + sx;
    qs[3].y = *(f32 *)(p + 4) + sy;
    qs[3].z = z;
    qs[3].r = 0x437F0000;
    qs[3].g = 0x437F0000;
    qs[3].b = 0x437F0000;
    qs[3].a = (f32)(u32)arg1;
    qs[3].u = u0 + u1;
    qs[3].v = v0 + v1;
    qs[3].q = q;
    {
        s32 texId = **(s32 **)(p + 0x3C);
        func_0034f1e0();
        D_00887300[0](1, texId);
        D_00887310[0](4, &qs[0], 4);
    }
    mode = *(s32 *)(p + 0x28);
    if (((mode & 1) != 0) || ((mode & 2) != 0)) {
        {
            u32 cR;
            u32 cW;
            s32 k;
            if ((mode & 1) != 0) {
                flatA = 0x15;
                flatB = 0;
                cR = 0xF2;
                cW = 0xFF;
            } else {
                flatA = 0;
                flatB = 0xBA;
                cR = 0xF2;
                cW = 0xFF;
            }
            k = 0;
            do {
                *(f32 *)&qs[k].r = (f32)(u32)cR;
                *(f32 *)&qs[k].g = (f32)(u32)flatA;
                *(f32 *)&qs[k].b = (f32)(u32)flatB;
                qs[k].a = (f32)(u32)cW;
                k++;
            } while (k < 4);
        }
        func_00489f80();
        func_003f6440(3, 0x31801);
        D_00887310[0](4, &qs[0], 4);
        func_0048a000();
        D_00887300[0](1, 0);
        func_003f6440(3, 0x31801);
        func_003f6440(2, 0x58);
        D_00887310[0](4, &qs[0], 4);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    } else if (mode & 4) {
        f32 f;
        f = (f32)*(s16 *)(p + 0x24) / 100.0f;
        ang1 = fGpffff81e0 * f;
        ang2 = fGpffff82fc + ang1;
        s1 = func_0044b7b0(ang1);
        c1 = func_0044b610(ang1);
        s2 = func_0044b7b0(ang2);
        c2 = func_0044b610(ang2);
        ptA.x = *(f32 *)p + 0.78125f * (64.0f * s1);
        ptA.y = *(f32 *)(p + 4) - 64.0f * c1;
        ptB.x = *(f32 *)p + 0.78125f * (64.0f * s2);
        ptB.y = *(f32 *)(p + 4) - 64.0f * c2;
        vtx = 0;
        for (i = 0; i < 7; i++) {
            f32 rowDY;
            f32 rowV;
            rowDY = 2.0f * (sy * ((f32)i / 6.0f - 0.5f));
            rowV = v0 + v1 * ((f32)i / 6.0f);
            for (j = 0; j < 5; j++) {
                f32 grey;
                u8 g8;
                cur.x = *(f32 *)p + 2.0f * (sx * ((f32)j / 4.0f - 0.5f));
                cur.y = *(f32 *)(p + 4) + rowDY;
                verts[vtx].x = cur.x;
                verts[vtx].y = cur.y;
                verts[vtx].z = z;
                verts[vtx].u = u0 + u1 * ((f32)j / 4.0f);
                verts[vtx].v = rowV;
                verts[vtx].q = q;
                grey = 255.0f * func_0035bd20(ptA, ptB, cur);
                g8 = (u8)grey;
                *(f32 *)&verts[vtx].r = (f32)g8;
                *(f32 *)&verts[vtx].g = (f32)g8;
                *(f32 *)&verts[vtx].b = (f32)g8;
                verts[vtx].a = (f32)g8;
                vtx++;
            }
        }
        if (vtx >= 0x24) {
            func_0046d730(&D_0064CC98, 0x835);
        }
        for (ii = 0; ii < 6; ii++) {
            for (jj = 0; jj < 5; jj++) {
                idx[ii * 10 + jj * 2] = (s16)(jj + ii * 5);
                idx[ii * 10 + jj * 2 + 1] = (s16)(jj + (ii + 1) * 5);
            }
        }
        func_00489f80();
        func_003f6440(3, 0x31801);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 10], 10);
        }
        func_0048a000();
        D_00887300[0](1, 0);
        func_003f6440(3, 0x31801);
        func_003f6440(2, 0x58);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 10], 10);
        }
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
    return blend;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035aff0);
#endif
/* measured: object 320B/window 320B; normalized_diff 14; differing offsets
   0x22, 0x24-0x28, 0x2C-0x2F, 0xE9-0xEA, 0x115-0x116. Retail uses
   mula.s/madda.s/madd.s; the remaining candidate residual also includes the
   temp_2 v1/v0 prologue naming. This is a COP1 accumulator compiler floor;
   body and all plain-C order/helper probes are archived in build/V035_0035bad0_body.c. */
/* measured: inline func_0044b7b0 calls at both interpolation sites preserve
   source multiply order and reproduce the retail madd.s operands; target now
   matches at normalized_diff 0. */
// FUN_0035BAD0
f32 func_0035bad0(u8 *arg0)
{
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f21_2;
    s16 temp_2;
    s16 temp_2_2;

    *(s16 *)(arg0 + 0x24) = *(s16 *)(arg0 + 0x24) + 1;
    if (*(s16 *)(arg0 + 0x24) >= 0x64) {
        *(s16 *)(arg0 + 0x24) = 0;
    }
    temp_2_2 = *(s16 *)(arg0 + 0x22);
    if (temp_2_2 < 0xA) {
        *(s16 *)(arg0 + 0x22) = (s16)(temp_2_2 + 1);
    }
    temp_f20 = (f32)*(s16 *)(arg0 + 0x22) / 10.0f;
    if ((temp_f20 < 0.0f) || (temp_f20 > 1.0f)) {
        func_0046d730(&D_0064CC98, 0x881);
    }
    temp_f22 = fGpffff84a4 * temp_f20;
    temp_f21 = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg0 + 8) = temp_f21 + ((*(f32 *)(arg0 + 0x10) - temp_f21) * func_0044b7b0(temp_f22));
    temp_f21_2 = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0xC) = temp_f21_2 + ((*(f32 *)(arg0 + 0x14) - temp_f21_2) * func_0044b7b0(temp_f22));
    return temp_f20;
}
// FUN_0035BC10
void func_0035bc10(u8 *arg0, s8 arg1, s32 arg2)
{
    u8 *base;
    s8 old;
    u8 buf[0x100];

    base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x22) = 0;
    *(f32 *)(base + 0x0) = 71.5f;
    *(f32 *)(base + 0x4) = 106.0f;
    *(f32 *)(base + 0x10) = 1.0f;
    *(s32 *)(base + 0x18) = 0;
    *(f32 *)(base + 0x1C) = 1.0f;
    *(f32 *)(base + 0x14) = 1.0f;
    old = *(s8 *)(base + 0x20);
    if (old == arg1) {
        goto unchanged;
    }
    switch (arg1) {
    case -1:
        goto minus_one_case;
    case 0:
        goto zero_case;
    default:
        goto other_case;
    }
minus_one_case:
    func_00442088(buf, D_0064CCF0);
    func_003547c0((s32 *)(base + 0x30), buf);
    goto done;
zero_case:
    func_003547c0((s32 *)(base + 0x30), NULL);
    goto done;
other_case:
    func_00442088(buf, D_0064CD10, (s32)arg1 - 1);
    func_003547c0((s32 *)(base + 0x30), buf);
done:
    *(s8 *)(base + 0x20) = arg1;
    *(s32 *)(base + 0x28) = arg2;
    *(s32 *)(base + 0x2C) = 0;
unchanged: ;
}
// FUN_0035BD20
// MATCH: 332B/336B; retail ends with four zero bytes.
// IDA-backed Float2 values and in-place weighted COP1 accumulation.
f32 func_0035bd20(Float2 first, Float2 second, Float2 origin)
{
    struct Vector3 { Float2 xy; f32 z; } normal, direction;
    extern struct Vector3 D_0064CD30;
    f32 total;
    f32 projection;

    normal = D_0064CD30;
    total = 0.0f;
    direction.xy.x = first.x - origin.x;
    direction.xy.y = first.y - origin.y;
    direction.z = 20.0f;
    func_003e40b0(&direction, &direction);
    projection = direction.xy.x * normal.xy.x + direction.xy.y * normal.xy.y + direction.z * normal.z;
    interpolation_accumulate(&total, 1.0f, projection);
    direction.xy.x = second.x - origin.x;
    direction.xy.y = second.y - origin.y;
    direction.z = 20.0f;
    func_003e40b0(&direction, &direction);
    projection = direction.xy.x * normal.xy.x + direction.xy.y * normal.xy.y + direction.z * normal.z;
    interpolation_accumulate(&total, 1.0f, projection);
    if (!(total <= 1.0f)) total = 1.0f;
    return total;
}
// FUN_0035BE70
s32 func_0035be70(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(u16 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = func_00354830(p + 0x30);
    }
    return 0;
}

// FUN_0035BEC0
void func_0035bec0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}

// FUN_0035BF10
u8 *func_0035bf10(s32 arg0, u16 arg1, s32 arg2)
{
    u8 *temp_2;
    u8 *temp_16;

    func_0044ea90(&D_0064CC98, 0x905);
    temp_2 = D_008873F4[0](1, 0x144, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&D_0064CC98, 0x906);
    }
    temp_16 = func_00451fc0(arg0, &D_0064CD40, 0xC7, 0, 0,
                            (void *)func_0035be70, (void *)func_0035bec0,
                            temp_2);
    *(s16 *)(temp_2 + 0x20) = 0;
    *(s32 *)(temp_2 + 0x2C) = 0;
    *(f32 *)(temp_2 + 0x10) = 353.0f;
    *(s32 *)(temp_2 + 0x14) = 0x42BC0000;
    *(f32 *)(temp_2 + 8) = 300.0f + *(f32 *)(temp_2 + 0x10);
    *(f32 *)(temp_2 + 0xC) = *(f32 *)(temp_2 + 0x14);
    func_0035c480((s32)temp_16, arg1, arg2);
    return temp_16;
}
/* MATCHED 2026-09-18.  Two levers, both measured:
   1. the four `256.0f + load` adds needed splitting into a load statement and
      an accumulate statement through an f32 local (`tx = *(f32 *)p;
      tx = tx + 256.0f;`) - written as one expression b210 puts the constant
      in rs whichever way the operands are spelled (15 -> 11);
   2. func_00364680 takes (f32, s32, f32, f32, f32, f32, f32, f32, s32 *,
      s32, s32), as src/promoted/shdPersona.c already had it, not the
      ints-first list that was here (11 -> 0).  Argument setup is emitted in
      source order, so the late `mtc1 $zero, $f12` and early `lw $a1` were
      pure argument-list evidence.  Same registers either way: the EABI keeps
      integer and float arguments in separate files. */
// FUN_0035C040
f32 func_0035c040(u8 *arg0, s32 arg1)
{
    f32 tx;
    f32 ty;
    extern u8 *func_00457120(void);
    extern f32 D_008872F8[];
    extern void func_00364680(f32 depth, s32 color, f32 x, f32 y, f32 sx, f32 sy, f32 w, f32 h, s32 *tex, s32 mode, s32 flag);
    extern void func_0034f1e0(void);
    extern s32 (*D_00887300[])(s32, s32);
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        s32 _c;
        s32 u;
        s32 v;
        f32 q;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } Q40;
    u8 *p;
    f32 z;
    f32 q;
    f32 ret;
    s16 v;
    Q40 qs[4];

    p = *(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / *(f32 *)(func_00457120() + 0x80);
    {
        u8 *t = *(u8 **)(arg0 + 0x38);
        s32 flag;
        if ((*(s32 *)(t + 0x2C) == 0) || (*(u16 *)(t + 0x20) == 0)) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag == 0) {
            return 0.0f;
        }
    }
    v = *(s16 *)(p + 0x22);
    if (v <= 9) {
        *(s16 *)(p + 0x22) = v + 1;
    }
    ret = func_0044b7b0(fGpffff84a4 * ((f32)*(s16 *)(p + 0x22) / 10.0f));
    if ((ret < 0.0f) || (ret > 1.0f)) {
        func_0046d730(&D_0064CC98, 0x936);
    }
    *(f32 *)p = *(f32 *)(p + 8) + ret * (*(f32 *)(p + 0x10) - *(f32 *)(p + 8));
    *(f32 *)(p + 4) = *(f32 *)(p + 0xC) + ret * (*(f32 *)(p + 0x14) - *(f32 *)(p + 0xC));
    *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + 0.25f * (*(f32 *)p - *(f32 *)(p + 0x18));
    *(f32 *)(p + 0x1C) = *(f32 *)(p + 0x1C) + 0.25f * (*(f32 *)(p + 4) - *(f32 *)(p + 0x1C));
    qs[0].x = *(f32 *)p;
    qs[0].y = *(f32 *)(p + 4);
    qs[0].z = z;
    qs[0].r = 0x437F0000;
    qs[0].g = 0x437F0000;
    qs[0].b = 0x437F0000;
    qs[0].a = (f32)(u32)arg1;
    qs[0].u = 0;
    qs[0].v = 0;
    qs[0].q = q;
    tx = *(f32 *)p;
    tx = tx + 256.0f;
    qs[1].x = tx;
    qs[1].y = *(f32 *)(p + 4);
    qs[1].z = z;
    qs[1].r = 0x437F0000;
    qs[1].g = 0x437F0000;
    qs[1].b = 0x437F0000;
    qs[1].a = (f32)(u32)arg1;
    qs[1].u = 0x3F800000;
    qs[1].v = 0;
    qs[1].q = q;
    qs[2].x = *(f32 *)p;
    ty = *(f32 *)(p + 4);
    ty = ty + 256.0f;
    qs[2].y = ty;
    qs[2].z = z;
    qs[2].r = 0x437F0000;
    qs[2].g = 0x437F0000;
    qs[2].b = 0x437F0000;
    qs[2].a = (f32)(u32)arg1;
    qs[2].u = 0;
    qs[2].v = 0x3F800000;
    qs[2].q = q;
    tx = *(f32 *)p;
    tx = tx + 256.0f;
    qs[3].x = tx;
    ty = *(f32 *)(p + 4);
    ty = ty + 256.0f;
    qs[3].y = ty;
    qs[3].z = z;
    qs[3].r = 0x437F0000;
    qs[3].g = 0x437F0000;
    qs[3].b = 0x437F0000;
    qs[3].a = (f32)(u32)arg1;
    qs[3].u = 0x3F800000;
    qs[3].v = 0x3F800000;
    qs[3].q = q;
    func_00364680(0.0f, *(s32 *)(p + 0x28) | (arg1 & 0xFF), *(f32 *)(p + 0x18) + -30.0f, *(f32 *)(p + 0x1C), *(f32 *)p, *(f32 *)(p + 4), 256.0f, 256.0f, *(s32 **)(p + 0x3C), 1, 0);
    func_0034f1e0();
    D_00887300[0](1, **(s32 **)(p + 0x3C));
    D_00887310[0](4, &qs[0], 4);
    return ret;
}
/* measured: opt_propagation off preserves paired field-load order. */
#pragma push
#pragma opt_propagation off

// FUN_0035C480
void func_0035c480(s32 arg0, u16 arg1, s32 arg2)
{
    s8 sp168[8];
    u8 sp60[0x100];
    f32 temp_f1;
    f32 temp_f0;
    s64 var_18;
    u32 temp_17;
    u8 *temp_16;
    extern u8 iGpffffa968;
    extern u8 iGpffffa96c;
    extern u8 D_0064CD60[];

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(s16 *)(temp_16 + 0x22) = 0;
    temp_f1 = *(f32 *)(temp_16 + 8);
    temp_f0 = *(f32 *)(temp_16 + 0xC);
    *(f32 *)(temp_16 + 0x18) = temp_f1;
    *(f32 *)(temp_16 + 0x1C) = temp_f0;
    temp_f1 = *(f32 *)(temp_16 + 8);
    temp_f0 = *(f32 *)(temp_16 + 0xC);
    *(f32 *)(temp_16 + 0) = temp_f1;
    *(f32 *)(temp_16 + 4) = temp_f0;
    temp_17 = arg1 & 0xFFFF;
    if ((*(u16 *)(temp_16 + 0x20) != temp_17) ||
        (*(s32 *)(temp_16 + 0x24) != arg2)) {
        switch (temp_17) {
        case 0:
            goto zero_case;
        default:
            goto nonzero_case;
        }
zero_case:
        func_003547c0((s32 *)(temp_16 + 0x30), NULL);
        goto done;
nonzero_case:
        if (arg2 & 1) {
            *(s32 *)(temp_16 + 0x28) = 0xF6001600;
            var_18 = 0x62;
        } else if (arg2 & 2) {
            *(s32 *)(temp_16 + 0x28) = 0xF600B000;
            var_18 = 0x63;
        } else {
            *(s32 *)(temp_16 + 0x28) = 0xFFD13400;
            var_18 = 0x61;
        }
        switch (temp_17) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 19:
        case 21:
        case 24:
        case 26:
        case 27:
        case 29:
            if (func_00110d60((s64)(s16)func_001060b0()) & 1) {
                func_00442088(sp168, &iGpffffa968);
            } else {
                func_00442088(sp168, &iGpffffa96c);
            }
            break;
        case 8:
        case 16:
        case 17:
        case 18:
        case 20:
        case 22:
        case 23:
        case 25:
        case 28:
        case 30:
            sp168[0] = 0;
            break;
        default:
            func_0046d730(&D_0064CC98, 0xA05);
            break;
        }
        func_00442088(sp60, D_0064CD60, temp_17, (s8)var_18, sp168);
        func_003547c0((s32 *)(temp_16 + 0x30), sp60);
        goto done;
done:
        *(u16 *)(temp_16 + 0x20) = arg1;
        *(s32 *)(temp_16 + 0x24) = arg2;
        *(s32 *)(temp_16 + 0x2C) = 0;
    }
}
#pragma pop
// FUN_0035C670
void func_0035c670(u8 *arg0, f32 *arg1)
{
    *(Float2 *)arg1 = *(Float2 *)(*(u8 **)(arg0 + 0x38));
}

// FUN_0035E820
void func_0035e820(u8 *arg0)
{
    u8 *base;
    s32 i;
    s32 *slot;

    base = *(u8 **)(arg0 + 0x38);
    i = 0;
    goto loop_test;
loop_body:
    slot = (s32 *)(base + i * 4 + 0x448);
    if (*slot != 0) {
        func_0046d280((void *)*slot);
        *slot = 0;
    }
    i++;
loop_test:
    if (i < 11) {
        goto loop_body;
    }
    *(s32 *)(base + 0x24) = 0;
    (*D_008873EC)(base);
}
// FUN_0035E8B0
s32 func_0035e8b0(u32 *arg0, s32 *arg1, u8 *arg2)
{
    extern u16 D_008C024E[];
    extern s32 func_00354030(void);
    extern s32 func_003593e0(s32, s32, s32);
    extern void func_0035ef80(u8 *);
    extern void func_0035f020(u8 *);
    u8 buf[44];
    f32 temp_f1;
    f32 var_f1;
    s32 temp_2;
    s32 var_6;
    s32 var_3;
    s16 temp_2_3;
    s16 temp_2_4;
    u32 temp_2_5;

    *arg1 = (var_6 = 1);
    temp_2_5 = *arg0;
    switch (temp_2_5) {
    case 0:
        *(s32 *)(arg2 + 4) = 0;
        *(s32 *)(arg2 + 8) = 0;
        *(u8 *)arg2 = 0xFF;
        func_00356250(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        if ((func_00356820(arg2) & func_0034c210()) != 0) {
            *arg0 = 3;
            func_0034bb20(0x19);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (func_003596a0(arg2) != 0) {
            func_00359720(arg2);
            return 1;
        }
        break;
    case 3:
        if (func_003596a0(arg2) != 0) {
            func_00353fe0();
            func_00355190((u8 *)*(s32 *)(arg2 + 0x1308), 1);
            func_0035ac60((u8 *)*(s32 *)(arg2 + 0x1308), 0, 1, 0);
            *arg0 = 4;
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            func_00359400(arg2, 1);
            *arg0 = 2;
            func_00353fb0();
            func_0034bb20(0x1B);
            func_0035ac60((u8 *)*(s32 *)(arg2 + 0x1308), 0, 0, 1);
            func_0045af60(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            if (*(s16 *)(arg2 + 0x134) > 0) {
                func_00359400(arg2, 2);
                func_003598d0(arg2);
                *arg0 = 5;
                func_003593e0((s32)arg2, 2, 0);
                func_0034bb20(0x1A);
                func_0035ac60((u8 *)*(s32 *)(arg2 + 0x1308), 1, 0, 0);
                func_0035ef80(arg2);
                func_003597f0(arg2);
                func_0035f020(arg2);
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 7;
        } else {
            func_00453670(buf, 5, *(s16 *)(arg2 + 0x134), *(s16 *)(arg2 + 0x24), *(s16 *)(arg2 + 0x26));
            func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((temp_2 = func_00453960(buf)) > 0) {
                func_003593e0((s32)arg2, 1, *(s32 *)(buf + 0x28));
                func_003593e0((s32)arg2, 0, *(s32 *)(buf + 0x24));
                func_00354080(temp_2);
            }
        }
        break;
    case 5:
        if (func_003596a0(arg2) != 0) {
            func_00359400(arg2, 3);
            *arg0 = 6;
            func_0034bb20(0x1C);
            func_003599a0(arg2);
            func_00355190((u8 *)*(s32 *)(arg2 + 0x1308), 0);
        }
        break;
    case 6:
        if (func_003596a0(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                func_00359400(arg2, 4);
                *arg0 = 3;
                func_0034bd60(0x19);
                func_0035c480(*(s32 *)(arg2 + 0x1310), 0, 0);
                func_0045af60(0, 0, 0, 2);
            } else if (D_008C024E[0] & 0x10) {
                *(s32 *)(arg2 + 0x10) = func_00354030();
                *arg0 = 7;
            } else {
                func_00453670(buf, 5, *(s16 *)(arg2 + 0x134), *(s16 *)(arg2 + 0x24), *(s16 *)(arg2 + 0x26));
                func_00453760(buf, 0);
                func_004538e0(buf, 8, 4, 0, 0);
                if (func_00453960(buf) != 0) {
                    func_003593e0((s32)arg2, 1, *(s32 *)(buf + 0x28));
                    func_003593e0((s32)arg2, 0, *(s32 *)(buf + 0x24));
                    func_003593e0((s32)arg2, 2, 0);
                    func_0035ef80(arg2);
                    func_003599a0(arg2);
                    func_003597f0(arg2);
                    func_0035f020(arg2);
                    func_0045af60(0, 1, 0, 5);
                } else if (*(s32 *)(arg2 + 0x148) > 1) {
                    func_00453670(buf, 8, *(s32 *)(arg2 + 0x148), *(s16 *)(arg2 + 0x28), 0);
                    func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                    if (func_00453960(buf) != 0) {
                        func_003593e0((s32)arg2, 2, *(s32 *)(buf + 0x24));
                        func_0035f020(arg2);
                        func_0045af60(0, 1, 0, 0);
                    }
                }
            }
        }
        break;
    case 7:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            var_6 = 1;
        } else {
            temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            var_3 = (u8)temp_f1;
            *(u8 *)arg2 = var_3;
            var_6 = 0;
        }
        if (var_6 != 0) {
            return 2;
        }
        break;
    }
    return 0;
}
// FUN_0035EF80
void func_0035ef80(u8 *arg0)
{
    s32 var_6;
    s32 temp_3;
    s8 temp_4;
    u8 *temp_2;

    temp_2 = (u8 *)add_offset_first((s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC, (u32)arg0);
    temp_4 = *(s8 *)(temp_2 + 0x38);
    var_6 = 0;
    temp_3 = *(s32 *)(temp_2 + 0x40);
    switch (temp_3) {
    case 2:
        var_6 |= 1;
        break;
    case 3:
        var_6 |= 2;
        break;
    case 1:
        var_6 |= 4;
        break;
    }
    func_0035bc10((u8 *)*(s32 *)(arg0 + 0x130C), temp_4, var_6);
}
// FUN_0035F020
void func_0035f020(u8 *arg0)
{
    s32 var_6;
    s32 temp_3;
    u16 temp_4;
    u8 *temp_2;

    temp_4 = *(u16 *)((u8 *)add_offset_first((s32)*(s16 *)(arg0 + 0x28) * 2, (u32)arg0) + 0x136);
    var_6 = 0;
    temp_2 = (u8 *)add_offset_first((s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC, (u32)arg0);
    temp_3 = *(s32 *)(temp_2 + 0x40);
    switch (temp_3) {
    case 2:
        var_6 |= 1;
        break;
    case 3:
        var_6 |= 2;
        break;
    case 1:
        var_6 |= 4;
        break;
    }
    func_0035c480(*(s32 *)(arg0 + 0x1310), temp_4, var_6);
}
/* MATCHED: built from func_0035e8b0 in this file, which is the same state
   machine - `*arg1 = (resultFlag = 1);`, a switch on `*arg0` whose arms
   `break` to a shared `return 0`, and the fade arm returning 2.  Three of
   m2c's call arguments are stale registers: func_0035c830, func_0035cfb0,
   func_0035dcc0 and func_0035dd40 all take the context alone.  The inner
   `*(s32 *)(arg2 + 0x1C)` switches are written `case 0:` before `case 1:`
   so the compare chain comes out 1-then-0 the way retail's does, and the
   two query arguments are full words, not the s16 narrowings m2c printed. */
// FUN_0035F0C0
s32 func_0035f0c0(u32 *arg0, s32 *arg1, u8 *arg2)
{
    extern u16 D_008C024E[];
    extern u16 D_008C0276[];
    extern s32 func_00354030(void);
    u8 query[0x30];
    f32 alpha;
    s32 resultFlag;
    s32 kind;
    s32 hit;
    s32 value;

    *arg1 = (resultFlag = 1);
    switch (*arg0) {
    case 0:
        *(s32 *)(arg2 + 8) = 0;
        *(s32 *)(arg2 + 0xC) = 0;
        *(u8 *)arg2 = 0xFF;
        func_0035c830(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        if (func_0035cfb0(arg2) & func_0034c210()) {
            *arg0 = 3;
            func_0034bb20(0x21);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (func_0035dcc0(arg2) != 0) {
            func_0035e6a0(arg2);
            return 1;
        }
        break;
    case 3:
        if (func_0035dcc0(arg2) != 0) {
            switch (*(s32 *)(arg2 + 0x1C)) {
            case 0:
                func_00353fe0();
                break;
            case 1:
                break;
            }
            func_0035ce10(arg2, 2);
            *arg0 = 4;
            goto do_state4;
        }
        break;
    case 4:
    do_state4:
        if (D_008C024E[0] & 0x40) {
            kind = *(s32 *)(arg2 + 0x30);
            if (kind == 6) {
                func_0035dd40(arg2);
                func_0035ce10(arg2, 1);
                *arg0 = 2;
                func_0034bb20(0x22);
                switch (*(s32 *)(arg2 + 0x1C)) {
                case 0:
                    func_00353fb0();
                    break;
                case 1:
                    break;
                }
                func_0045af60(0, 0, 0, 1);
            } else if (func_0035cb00(arg2, kind) != 0) {
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            func_0035ce10(arg2, 1);
            *arg0 = 2;
            func_0034bb20(0x22);
            switch (*(s32 *)(arg2 + 0x1C)) {
            case 0:
                func_00353fb0();
                break;
            case 1:
                break;
            }
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            if (*(s32 *)(arg2 + 0x1C) == 0) {
                *(s32 *)(arg2 + 0x14) = func_00354030();
                *arg0 = 5;
            }
        } else {
            func_00453670(query, 7, 7, *(s32 *)(arg2 + 0x30), 0);
            func_004538e0(query, 0x4000, 0x1000, 0, 0);
            if (func_00453960(query) != 0) {
                func_0035cab0(arg2, 0, *(s32 *)(query + 0x24));
                func_0045af60(0, 1, 0, 0);
            } else {
                kind = *(s32 *)(arg2 + 0x30);
                if (kind != 6) {
                    hit = 0;
                    if (D_008C0276[0] & 0x8000) {
                        hit = func_0035cc80(arg2, kind, 1);
                    } else if (D_008C0276[0] & 0x2000) {
                        hit = func_0035cc80(arg2, kind, 0);
                    }
                    if (hit != 0) {
                        func_0045af60(0, 0, 0, 1);
                    }
                }
            }
        }
        break;
    case 5:
        if ((++*(u16 *)(arg2 + 0x10) & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alpha = (1.0f - ((f32)*(u16 *)(arg2 + 0x10) / 3.0f)) * 255.0f;
            value = (u8)alpha;
            *(u8 *)arg2 = value;
            resultFlag = 0;
        }
        if (resultFlag != 0) {
            return 2;
        }
        break;
    }
    return 0;
}
// FUN_0035FC40
s32 func_0035fc40(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
// FUN_0035FC90
s32 func_0035fc90(u8 *arg0)
{
    s16 temp_2;
    s32 var_17;
    s32 var_16;
    u8 *temp_19;

    var_16 = 1;
    temp_2 = *(s16 *)(arg0 + 0x20);
    if (temp_2 < 0x64) {
        *(s16 *)(arg0 + 0x20) = temp_2 + 1;
    }
    var_17 = 0;
    goto loop_test;
loop_body:
    temp_19 = arg0 + var_17 * 0x30;
    func_001437b0(temp_19 + 0x48, *(s16 *)(arg0 + 0x20), 0);
    if (*(u8 *)(temp_19 + 0x62) != 0) {
        var_16 = 0;
    }
    var_17 += 1;
loop_test:
    if (var_17 < 0x1D) {
        goto loop_body;
    }
    func_00361ae0(arg0);
    func_00361ca0(arg0);
    func_0035fd60(arg0);
    return var_16;
}
/* Floor: 1689 words via `tools/measure_guarded.py` (fndiff, no alignment, +52B over shifted; use fnalign), 7236B emitted against a 7184B window (1809/1796 instructions, +13), frame exact 0x1A0, 478 fnalign edits (+20 reloc-only) via `tools/fnalign.py --candidate` (was 849 at 1707 instrs; pos-union 1522->1689 fndiff (+167, size over), fnalign 849->478 (-371, -44%); u8alpha (f32)alpha->(f32)(u8)alpha fixes bltz/srl/or 17->21 exact; col3 (0x65C/0x658/0x674 via col) fixes lbu/sb -11->+1, mov.s +22->+1; float reverse (base $f25/$f24->$f21/$f20 exact) -42 edits. Mechanism is the same one that cracked func_003768e0: scalar posX/posY replaced by pos.f[0]/pos.f[1] union array elements so the spill/reload pairs appear. NOT the menu state machine family: `void func_0035fd60(u8 *)` with a single `jr $ra` and no `$v0` result (void, not `s32 (u32 *, s32 *, u8 *)` with a shared `return 0` / fade `return 2`); frame 0x1A0 saving $s16-$s20/$f20-$f26, not `u8 buf[0x30]` with a `+0x24` query read; `lbu $3,0x0($18)` feeds `cvt.s.w`/`div.s` (`*arg0/255.0f` alpha scale), not a `switch (*arg0)` dispatch (no jump table); phases gated on `*(s32 *)(arg0+0x1C)` bits 1/2/4 (with &8 nested inside &4), 14 callees. Census 54->41: mov.s +22->+1, swc1 -35->-10, lwc1 -35->-3, frame exact at 0x1A0.
   WALL: outer $f24 vs $f26 (two saves short of $f26; f26first $f25 off by 1 gives 482 edits (+4, worse); declaration order), lui +29 (D_0064B2E8/B2EC/B300 rematerialised per byte via $v0 (3 lui, dest $v0 same clobbers) vs hoisted $s1 (1 lui, dest $a1/$a2/$a3 different base preserved); long-lived pB saves 23 lui (160->137, +29->+6) but breaks the frame to 0x1B0 and costs 3232 edits; short-lived p per group saves 2-4 lui with base $s2/frame exact but forwarded (tie, no saving) unless long live across calls (saved, pressure); swc1 -10/lwc1 -3 (need 10/3 more stores/loads, likely fy/fx dead stores with s64 packing), andi +3 (was -2, surplus from u8alpha per-j (4 conversions)), unsigned-branch staging/FPU choice with s64 packing, and `andi $s1` masking/re-read scheduling. */
/* measured 0035fd60: `opt_loop_invariants on` inside the guard is worth 114 words (1636 -> 1522), the loop-preheader constant hoist. */
/* measured 0035fd60 (WWidthD): pragmas via `tools/probe_variants.py` singly post-flock on the loopinv base (1522): `schedule on` 1662 (+140), `opt_common_subs off` 1673 (+151), `opt_propagation off` 1657 (+135); `tools/wscan_pairs.py` 1 vs 0 (single 0x18 pair for `(s8)alpha`, ignored until size matches per assignment); slti all `$v0` both sides (no `$at` lever; src `$s1` vs `$s4`/`$s0` colour wall); relocs match retail call sites (24x34f2e0, 8x3f6440, 2x34f9d0, 1x361d20, etc.) so the -86 is in `(u8)` clamping at 21 sites (`c.ole.s`/`bc1t` large-x paths) + FPR colour (`$f25`/`$f24` vs `$f21`/`$f20`, one save short of `$f26`), not missing calls. */
/* 2026-09-19 lead adjudication of the two candidates, like for like:
     previous  1522 words, object 1707 against retail 1793 - **-86, -4.8%,
               OUTSIDE the +-3% band of 1739-1847** - fnalign 849 edits.
     current   1689 words, object 1809 against retail 1796 - +13, +0.7%,
               inside the band - fnalign 478 edits (+20 reloc-only).
   The word score rose by 167 and the body still got much closer to retail.
   That is not a paradox: `measure_guarded` counts reloc-masked differing
   words over a fixed window, so a body 86 instructions short scores well by
   being shifted out of alignment with the parts it is missing.  The previous
   floor should never have been banked - it failed the count gate.  The
   current one meets it and halves the alignment edits.
   When the two metrics disagree, check the counts first: if one candidate is
   outside the gate, its word score is not comparable to anything.  See also
   func_00468ff0, where edits fell 674 -> 316 while words rose 898 -> 911 for
   the same reason. */
// FUN_0035FD60 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_0035fd60(u8 *arg0) {
    extern void func_0034f1e0(void);
    extern void func_0034c270(s64 pos, s8 alpha, s32 flag, f32 zero);
    extern void func_0034f2e0(void *ptr, f32 x, f32 y, u8 r, u8 g, u8 b, u32 a);
    extern void func_0034f9d0(s64 pos, f32 z, u32 alpha, s32 arg2, s32 arg3);
    extern void func_00275980(void *src, void *dst, s32 n);
    extern void func_00274ed0(f32 x, f32 y, f32 scale, s32 color, s32 a, s32 b, void *buf, s32 c, s32 d);
    extern void func_002bc7a0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 f0, f32 f1, f32 f2);
    extern void func_00361d20(s32 idx, u8 *ctx);
    extern void func_003f6440(s32 cmd, s32 val);
    extern void func_0045c870(u8 *color, s32 flag);
    extern void func_0045d6e0(u8 *color, u8 *rect, f32 zero, s32 flag);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B300[];
    extern u8 D_0064B2E0[];
    extern void *D_0064D448[];
    extern s32 (*D_00887300[])(s32, s32);
    extern f32 fGpffff8170;
    extern f32 fGpffff8554;
    typedef union {
        f32 f[2];
        s64 s;
    } PosBits;
    u8 col[4];
    u8 textbuf[0x100];
    struct {
        f32 x;
        f32 y;
        s32 w;
        s32 h;
    } rect;
    PosBits pos;
    f32 f25;
    f32 f26;
    f32 fy;
    f32 fx;
    f32 scale;
    f32 baseY;
    f32 baseX;
    s32 flag;
    s32 alpha;
    s32 i;
    s32 j;
    s32 k;
    s32 color;
    s32 v0;
    s32 v1;
    u8 *row;
    u8 a0;
    u8 alpha122;
    func_0034f1e0();
    baseX = *(f32 *)(arg0 + 4);
    baseY = *(f32 *)(arg0 + 8);
    scale = (f32)*(u8 *)arg0 / 255.0f;
    flag = *(s32 *)(arg0 + 0x10);
    if (flag != 0) {
        pos.f[0] = baseX;
        pos.f[1] = baseY;
        alpha = (u8)(255.0f * scale);
        func_0034c270(pos.s, (s8)alpha, flag, 0.0f);
    }
    if (*(s32 *)(arg0 + 0x1C) & 1) {
        pos.f[0] = baseX + *(f32 *)(arg0 + 0x178) + 90.0f;
        pos.f[1] = baseY + *(f32 *)(arg0 + 0x17C) + 91.0f;
        alpha = (u8)((f32)*(u8 *)(arg0 + 0x182) * scale);
        func_0034f2e0(*(void **)(arg0 + 0x6FC), pos.f[0], pos.f[1], 0xFF, 0xFF, 0xFF, alpha);
    }
    if (*(s32 *)(arg0 + 0x1C) & 2) {
        f26 = 23.0f + (595.0f + (baseX + *(f32 *)(arg0 + 0x148)));
        f25 = 280.0f + (baseY + *(f32 *)(arg0 + 0x14C));
        alpha = (u8)((f32)*(u8 *)(arg0 + 0x152) * scale);

        for (i = 0; i < 0xB; i++) {
            pos.f[0] = f26 - (f32)(i * 0x2D);
            row = arg0 + i * 0xA;
            for (j = 0; j < *(s16 *)(row + 0x5EA); j++) {
                if (j == *(s16 *)(row + 0x5EA) - 1) {
                    col[0] = 0xFF;
                    col[1] = 0xFF;
                    col[2] = 0xA4;
                    col[3] = (u8)(fGpffff8170 * (f32)(u8)alpha);
                } else if (j < *(s16 *)(row + 0x5EE)) {
                    col[0] = 0xFE;
                    col[1] = 0xFF;
                    col[2] = 0x56;
                    col[3] = (u8)(0.5f * (f32)(u8)alpha);
                } else {
                    continue;
                }
                pos.f[1] = f25 - (f32)(j * 0x11);
                func_0034f2e0(*(void **)(arg0 + 0x678), pos.f[0], pos.f[1], col[0], col[1], col[2], col[3]);
            }
        }
        for (i = 0; i < 3; i++) {
            k = i * 0x30;
            row = arg0 + k;
            pos.f[0] = 144.0f + (baseX + *(f32 *)(row + 0x58));
            pos.f[1] = 136.0f + (baseY + *(f32 *)(row + 0x5C) + (f32)k);
            a0 = (u8)((f32)*(u8 *)(row + 0x62) * scale);
            col[0] = D_0064B2E8[0];
            col[1] = D_0064B2E8[1];
            col[2] = D_0064B2E8[2];
            col[3] = a0;
            func_0034f2e0(*(void **)(arg0 + i * 8 + 0x65C), pos.f[0], pos.f[1], col[0], col[1], col[2], col[3]);
        }
        fx = *(f32 *)(arg0 + 0x40);
        fy = *(f32 *)(arg0 + 0x44);
        *(f32 *)(arg0 + 0x40) = fx + (((303.0f + baseX) - fx) * 0.5f);
        *(f32 *)(arg0 + 0x44) = fy + (((133.0f + baseY + (f32)(*(s16 *)(arg0 + 0x28) * 0x30)) - fy) * 0.5f);
        pos.f[0] = *(f32 *)(arg0 + 0x118) + *(f32 *)(arg0 + 0x40);
        pos.f[1] = *(f32 *)(arg0 + 0x11C) + *(f32 *)(arg0 + 0x44);
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x122) * scale);
        alpha122 = a0;
        col[0] = D_0064B2E8[0];
        col[1] = D_0064B2E8[1];
        col[2] = D_0064B2E8[2];
        col[3] = a0;
        func_0034f2e0(*(void **)(arg0 + 0x658), pos.f[0], pos.f[1], col[0], col[1], col[2], col[3]);
        func_00489f80();
        D_00887300[0](1, 0);
        col[0] = D_0064B2E8[0];
        col[1] = D_0064B2E8[1];
        col[2] = D_0064B2E8[2];
        col[3] = 0;
        func_0045c870(col, 0);
        func_0034f2e0(*(void **)(arg0 + 0x658), pos.f[0], pos.f[1], col[0], col[1], col[2], 0xFF);
        func_0048a000();
        func_003f6440(3, 0x2D801);
        func_003f6440(2, 0x44);
        for (i = 0; i < 3; i++) {
            k = i * 0x30;
            row = arg0 + k;
            pos.f[0] = 144.0f + (baseX + *(f32 *)(row + 0x58));
            pos.f[1] = 136.0f + (baseY + *(f32 *)(row + 0x5C) + (f32)k);
            a0 = (u8)((f32)*(u8 *)(row + 0x62) * scale);
            func_0034f2e0(*(void **)(arg0 + i * 8 + 0x65C), pos.f[0], pos.f[1], D_0064B2EC[0], D_0064B2EC[1], D_0064B2EC[2], a0);
        }
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
        for (i = 0; i < 3; i++) {
            k = i * 0x30;
            row = arg0 + k;
            fx = 144.0f + (baseX + *(f32 *)(row + 0x58));
            fy = 136.0f + (baseY + *(f32 *)(row + 0x5C) + (f32)k);
            func_0034f2e0(*(void **)(arg0 + i * 8 + 0x660), fx + 4.0f, fy + 20.0f, 0x80, 0x80, 0x80, alpha122);
        }
        pos.f[0] = 468.0f + (baseX + *(f32 *)(arg0 + 0xE8));
        pos.f[1] = 139.0f + (baseY + *(f32 *)(arg0 + 0xEC));
        a0 = (u8)((f32)*(u8 *)(arg0 + 0xF2) * scale);
        col[0] = D_0064B2E8[0];
        col[1] = D_0064B2E8[1];
        col[2] = D_0064B2E8[2];
        col[3] = a0;
        func_0034f2e0(*(void **)(arg0 + 0x674), pos.f[0], pos.f[1], col[0], col[1], col[2], col[3]);
        pos.f[0] = 53.0f + (567.0f + (baseX + *(f32 *)(arg0 + 0xE8)));
        pos.f[1] = 269.0f + (baseY + *(f32 *)(arg0 + 0xEC));
        a0 = (u8)((f32)*(u8 *)(arg0 + 0xF2) * scale);
        func_00275980(D_0064D448[*(s16 *)(arg0 + 0x28)], textbuf, 0x100);
        func_00274ed0(pos.f[0], pos.f[1], 0.0f, (a0 | ~0xFF), 7, 1, textbuf, 2, 0);
        pos.f[0] = 640.0f + (baseX + *(f32 *)(arg0 + 0x1A8));
        pos.f[1] = 400.0f + (baseY + *(f32 *)(arg0 + 0x1AC));
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x1B2) * scale);
        func_0034f9d0(pos.s, 0.0f, a0, *(s16 *)(arg0 + 0x34), *(s32 *)(arg0 + 0x700));
    }
    if (*(s32 *)(arg0 + 0x1C) & 4) {
        f26 = 23.0f + (595.0f + (baseX + *(f32 *)(arg0 + 0x148)));
        f25 = 430.0f + (baseY + *(f32 *)(arg0 + 0x14C));
        alpha = (u8)((f32)*(u8 *)(arg0 + 0x152) * scale);
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);

        for (i = 0; i < 0xB; i++) {
            pos.f[0] = f26 - (f32)(i * 0x2D);
            row = arg0 + i * 0xA;
            for (j = 0; j < *(s16 *)(row + 0x5EA); j++) {
                if (j == *(s16 *)(row + 0x5EA) - 1) {
                    col[0] = 0xFF;
                    col[1] = 0xFF;
                    col[2] = 0xF0;
                    col[3] = (u8)(0.5f * (f32)(u8)alpha);
                } else if (j < *(s16 *)(row + 0x5EE)) {
                    col[0] = 0xFF;
                    col[1] = 0xFC;
                    col[2] = 0x40;
                    col[3] = (u8)(fGpffff8554 * (f32)(u8)alpha);
                } else {
                    continue;
                }
                pos.f[1] = f25 - (f32)(j * 0x11);
                func_0034f2e0(*(void **)(arg0 + 0x678), pos.f[0], pos.f[1], col[0], col[1], col[2], col[3]);
            }
        }
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
        pos.f[0] = 29.0f + (baseX + *(f32 *)(arg0 + 0x3B8));
        pos.f[1] = -13.0f + (54.0f + (baseY + *(f32 *)(arg0 + 0x3BC)));
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x3C2) * scale);
        func_0034f2e0(*(void **)(arg0 + 0x6DC), pos.f[0], pos.f[1], D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x6E0), pos.f[0] + 73.0f, pos.f[1], D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x6D8), pos.f[0] + 19.0f, pos.f[1] + 2.0f, D_0064B2EC[0], D_0064B2EC[1], D_0064B2EC[2], a0);
        pos.f[0] = 89.0f + (baseX + *(f32 *)(arg0 + 0x3B8));
        pos.f[1] = -13.0f + (86.0f + (baseY + *(f32 *)(arg0 + 0x3BC)));
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x3C2) * scale);
        fy = pos.f[1] + 4.0f;
        func_0034f2e0(*(void **)(arg0 + 0x68C), pos.f[0] - 6.0f, fy, D_0064B300[0], D_0064B300[1], D_0064B300[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x690), pos.f[0] + 41.0f, fy, D_0064B300[0], D_0064B300[1], D_0064B300[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x680), pos.f[0], pos.f[1], D_0064B300[0], D_0064B300[1], D_0064B300[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x67C), pos.f[0], pos.f[1], D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], a0);
        pos.f[0] = 302.0f + (baseX + *(f32 *)(arg0 + 0x3B8));
        pos.f[1] = -13.0f + (79.0f + (baseY + *(f32 *)(arg0 + 0x3BC)));
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x3C2) * scale);
        fy = pos.f[1] + 11.0f;
        func_0034f2e0(*(void **)(arg0 + 0x694), pos.f[0] - 157.0f, fy, D_0064B300[0], D_0064B300[1], D_0064B300[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x698), pos.f[0] + 255.0f, fy, D_0064B300[0], D_0064B300[1], D_0064B300[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x688), pos.f[0], pos.f[1], D_0064B300[0], D_0064B300[1], D_0064B300[2], a0);
        func_0034f2e0(*(void **)(arg0 + 0x684), pos.f[0], pos.f[1], D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], a0);
        fx = 583.0f + (*(f32 *)(arg0 + 0x5C8) + (baseX + *(f32 *)(arg0 + 0x328)));
        fy = (f32)(s32)((-13.0f + (132.0f + (*(f32 *)(arg0 + 0x5CC) + (baseY + *(f32 *)(arg0 + 0x32C))))) - 17.0f);
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x332) * scale);
        func_0034f2e0(*(void **)(arg0 + 0x6F0), fx, fy, 0xFF, 0xFF, 0xFF, a0);
        fy = fy + 165.0f;
        func_0034f2e0(*(void **)(arg0 + 0x6F4), fx, fy, 0xFF, 0xFF, 0xFF, a0);
        fy = fy - 165.0f + 3.0f;
        fy = (f32)(s32)(fy + (f32)((s32)(*(s16 *)(arg0 + 0x2C) * 0x86) / (s32)(*(s32 *)(arg0 + 0x38) - 6)));
        func_0034f2e0(*(void **)(arg0 + 0x6EC), fx, fy, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], a0);
        for (i = 0; i < 6; i++) {
            if ((*(s16 *)(arg0 + 0x2C) + i) < *(s32 *)(arg0 + 0x38)) {
                func_00361d20(i, arg0);
            }
        }
        fx = baseX + *(f32 *)(arg0 + 0x598);
        fy = baseY + *(f32 *)(arg0 + 0x59C);
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x5A2) * scale);
        rect.x = 73.0f + fx;
        rect.y = 297.0f + fy;
        rect.w = 0x241;
        rect.h = 0x55;
        col[0] = D_0064B2E8[0];
        col[1] = D_0064B2E8[1];
        col[2] = D_0064B2E8[2];
        col[3] = a0;
        D_00887300[0](1, 0);
        func_0045d6e0(col, (u8 *)&rect, 0.0f, 0);
        pos.f[0] = 212.0f + fx;
        pos.f[1] = (304.0f + fy) - 5.0f;
        v0 = (s32)(*(s16 *)(arg0 + 0x2A) + *(s16 *)(arg0 + 0x2C));
        if (func_00106330(v0 + 0x100) != 0) {
            if (func_00106330(v0 + 0x140) != 0) {
                color = (a0 | 0xADADAD00);
            } else {
                color = (a0 | ~0xFF);
            }
            v1 = v0 + 1;
        } else {
            color = (a0 | 0xADADAD00);
            v1 = 0;
        }
        func_002bc7a0(v1, color, 1, 8, 8, (f32)(s32)pos.f[0], (f32)(s32)pos.f[1], 0.0f);
        if (*(s32 *)(arg0 + 0x1C) & 8) {
            pos.f[0] = 85.0f + (baseX + *(f32 *)(arg0 + 0x388));
            pos.f[1] = 325.0f + (baseY + *(f32 *)(arg0 + 0x38C));
            a0 = (u8)((f32)*(u8 *)(arg0 + 0x392) * scale);
            func_0034f2e0(*(void **)(arg0 + 0x6E4), pos.f[0], pos.f[1], 0xFF, 0xE9, 0x2C, a0);
        }
        pos.f[0] = 640.0f + (baseX + *(f32 *)(arg0 + 0x568));
        pos.f[1] = 400.0f + (baseY + *(f32 *)(arg0 + 0x56C));
        a0 = (u8)((f32)*(u8 *)(arg0 + 0x572) * scale);
        func_0034f9d0(pos.s, 0.0f, a0, *(s16 *)(arg0 + 0x34), *(s32 *)(arg0 + 0x700));
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035fd60);
#endif
