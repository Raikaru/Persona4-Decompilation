#include "include_asm.h"
#include "sdk_task_registration.h"
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
extern s32 datGetFlag(s32 arg0);
extern u8 *func_00452380(const void *arg0);
extern s32 func_0029cc00(s32 arg0);
extern u8 D_0064B320[];
extern void func_00354280(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_0064B3B0[];
extern u8 D_0064B3D0[];
extern s32 func_00355460(u8 *arg0);
extern void func_003554b0(u8 *arg0);
extern void strncpy(void *dst, const void *src, u32 size);
extern f32 RwV3dNormalize(void *out, const void *in);

extern void func_0046d280(void *node);
extern void func_00452080(s32 arg0);
extern void func_002bc060(s32 arg0);
extern s32 func_002467b0(u16 arg0);
extern void func_0046d730(const void *module, u32 line);
extern void sprintf(void *dst, const void *fmt, ...);
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
extern void H_Cdvd_Destroy(u8 *arg0);
extern void func_003ef3a0(void *arg0);
extern void memset(void *dst, s32 value, s32 size);
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
extern s32 H_Cdvd_IsFileLoaded(s32 arg0);
extern s32 func_004667d0();
extern s32 func_004669d0(s32 arg0, void *arg1, s32 arg2);
extern u8 iGpffffa960;
extern u8 D_0064B360[];
extern u8 D_0064B380[];
extern void func_0044ea90(const void *arg0, s32 arg1);


extern u8 D_0064B410[];
extern s32 func_003558a0(u8 *arg0);
extern void func_00356140(u8 *arg0);
extern void func_003556a0(u8 *arg0, s64 arg1, s32 arg2);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern f32 iGpffff83d4;
extern f32 iGpffff8544;
extern f32 sinf(f32 arg0);
extern f32 fGpffff84a4;
extern void func_002bb7c0(s32 arg0);
extern s32 func_002bb600(void);
extern void func_002bb1e0(s32 arg0);
extern void func_002bb9e0(s32 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb290(s8 arg0, s32 arg1);
extern s32 func_002bb4e0(void);
extern s32 func_002bd7b0(const void *arg0);
extern s32 func_002bd840(s32 arg0);
extern u8 D_0064A790[];
extern void func_00149680(s32 arg0);
extern s32 func_0015a560(void);
extern void func_0034c260(s32 arg0);
extern s32 func_0034bb10(void);
extern s64 datGetPartyId(s32 arg0);
// FUN_00353B50
s16 func_00353b50(s16 *arg0)
{
    s16 var_17;
    s16 temp_3;
    s32 var_16;

    var_17 = 1;
    *arg0 = 1;
    for (var_16 = 0; var_16 < 3; var_16++) {
        temp_3 = datGetPartyId(var_16);
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
        if (datGetFlag(0x30) != 0) {
            result = 1;
        }
        break;
    case 3:
        if (datGetFlag(0x31) != 0) {
            result = 1;
        }
        break;
    case 4:
        if (datGetFlag(0x32) != 0) {
            result = 1;
        }
        break;
    case 5:
        if (datGetFlag(0x34) != 0) {
            result = 1;
        }
        break;
    case 6:
        if (datGetFlag(0x33) != 0) {
            result = 1;
        }
        break;
    case 8:
        if (datGetFlag(0x35) != 0) {
            result = 1;
        }
        break;
    case 7:
        if (datGetFlag(0x36) != 0) {
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
s32 func_00354010(void)
{
    return func_0015a560();
}
// FUN_00354030
s32 func_00354030(void)
{
    func_0045af60(0, 2, 0, 4);
    func_0034c260(0);
    func_00149680(0);
    return func_0034bb10();
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
    extern s32 func_002badc0(s8 arg0, s32 arg1);
    extern void func_002bbd80(s8 arg0, s32 arg1, void *arg2);
    extern u8 func_0045aeb0(s16 channelIndex, const char *name);
    extern u8 D_0064B340[];
    extern char iGpffffa958;
    extern u32 func_00354490(s32 arg0);

    *(s8 *)(arg0 + 8) = func_002bab80(D_0064A790);
    if (arg2 == 0) {
        temp_16 = arg1 + 0x100;
        if (datGetFlag(temp_16) != 0)
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
        if (datGetFlag(0xC3) == 0) {
            *(u16 *)arg0 = *(u16 *)arg0 | 1;
            func_00106390(0xC3, 1);
        }
    } else {
        if (datGetFlag(arg1 + 0x100) == 0)
            func_0046d730(&D_0064B310, 0x37E);
        func_00106390(arg1 + 0x180, 0);
        func_00106390(arg1 + 0x140, 1);
        temp_8 = 6;
        var_16 = 0x2D0;
    }
    sprintf(sp90, &D_0064B340, var_16);
    func_0045aeb0(2, (const char *)sp90);
    func_00275980((void *)(u32)func_00354490(arg1), sp90, 0x40);
    func_002bbd80(*(s8 *)(arg0 + 8), 0, sp90);
    sprintf(sp50, &iGpffffa958, arg1 + 1);
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
    if (func_00451fc0((void *)(0), (const void *)(&D_0064B320), 0xF, 0, 0, func_003540f0, func_00354230, (u8 *)(temp_2_2)) == NULL) {
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
    if (func_00451fc0((void *)(0), (const void *)(&D_0064B320), 0xF, 0, 0, func_003540f0, func_00354230, (u8 *)(temp_2_2)) == NULL) {
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
    strncpy((u8 *)arg0 + 0x10, arg1, 0x100);
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
        if (H_Cdvd_IsFileLoaded(*(s32 *)(arg0 + 8)) != 0) {
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
            H_Cdvd_Destroy(*(u8 **)(arg0 + 8));
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
        H_Cdvd_Destroy(*(u8 **)(arg0 + 8));
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
    temp_2 = func_00451fc0((void *)(arg0), (const void *)(&D_0064B3D0), 0xC7, 0, 0, func_00355460, func_003554b0, (u8 *)(temp_2_2));
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
    extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
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
        blend = sinf(D_00761470 * (ft / 10.0f));
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
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
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
            sprintf(sp50, &D_0064B3F0, temp_17, var_2);
            func_003549d0(temp_16 + 0x144);
            if ((u8 *)sp50 == NULL) {
                *(s32 *)(temp_16 + 0x144) = 3;
            } else {
                strncpy(temp_16 + 0x154, sp50, 0x100);
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
/* The opacity component is a byte, as stored by the state and passed by every caller. */
void func_00355410(u8 *arg0, u8 arg1)
{
    u8 *temp_4;

    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0xA) = arg1;
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
            H_Cdvd_Destroy((u8 *)temp_4_2);
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
    result = (s32)func_00451de0((const void *)(&D_0064B410), arg6, 0, 0, func_003558a0, func_00356140, (u8 *)(temp_2));
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
    memset(arg0 + 0x1F8, 0, 0x30);
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

/* Whether the frame counter at +0x10 has passed the style's threshold of the
   duration at +0xC (3/4 for style 0, 1/2 for style 1). */
static inline s32 effect_timer_past_threshold(u8 *p)
{
    switch (*(s16 *)p) {
    case 1:
        if (*(s16 *)(p + 0x10) > *(s16 *)(p + 0xC) / 2) {
            return 1;
        }
        break;
    case 0:
        if (*(s16 *)(p + 0x10) > *(s16 *)(p + 0xC) * 3 / 4) {
            return 1;
        }
        break;
    }
    return 0;
}
// FUN_00355920
void func_00355920(u8 *arg0, u8 *arg1) {
    extern u8 D_00887300[];
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern void func_0045c870(u8 *arg0, s32 arg1);
    extern f32 cosf(f32 arg0);
    extern void func_00356170(s64 arg0, f32 f0, f32 f1, s32 arg1, f32 f2, s32 arg2, s32 arg3);
    extern void func_003561d0(Vec2f arg0, s32 arg1, f32 dummy, f32 f0, f32 f1, s32 arg2);
    extern f32 fGpffff8504;
    extern f32 fGpffff8540;
    extern f32 fGpffff8548;
    u8 *p;
    s32 isZero;
    u8 alpha;
    void (**tbl)(u32, u32);
    s32 i;
    f32 f20;
    f32 f21;
    union { s64 bits; Vec2f vec; } xy;
    union { s32 w; u8 b[4]; } col;
    (void)arg0;
    p = arg1;
    alpha = 0xFF;
    isZero = (*(s32 *)(p + 4) == 0);
    tbl = (void (**)(u32, u32))D_00887300;
    tbl[0](7, 2);
    tbl[0](6, 0);
    tbl[0](8, 0);
    tbl[0](0xE, 0);
    tbl[0](9, 2);
    tbl[0](0xC, 1);
    tbl[0](1, 0);
    if (isZero != 0) {
        func_00489f80();
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x31801);
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
            s16 limit = *(s16 *)(p + 0xE);
            s16 cnt = *(s16 *)(p + 0x12);
            f32 fcnt = (f32)cnt;
            f32 flimit = (f32)limit;
            f32 start = fGpffff8504;

            if (fcnt < fGpffff8504 * flimit) {
                break;
            }
            if (cnt <= limit) {
                f32 s;

                xy.vec.x = 320.0f;
                xy.vec.y = 224.0f;
                col.b[3] = 0xFF;
                f20 = fGpffff84a4 * ((fcnt - start * flimit) / (fGpffff8540 * flimit));
                f21 = iGpffff8544 * (1.0f - cosf(f20));
                s = 800.0f * sinf(f20);
                switch (*(s16 *)p) {
                case 0:
                    func_00356170(xy.bits, 0.0f, s, col.w, 0.0f, 0x30, 0);
                    break;
                case 1:
                    func_003561d0(xy.vec, col.w, 0.0f, s, f21, 0);
                    break;
                }
            } else {
                *(s32 *)(p + 8) |= 4;
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
        RpSkyRenderStateSet(3, 0x35801);
        RpSkyRenderStateSet(2, 0x44);
    } else {
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
    }
    if ((*(s32 *)(p + 8) & 1) != 0) {
        *(s16 *)(p + 0x10) += 1;
        if (*(s16 *)(p + 0x10) <= *(s16 *)(p + 0xC)) {
            switch (*(s32 *)(p + 4)) {
            case 0:
                if ((*(s32 *)(p + 8) & 2) == 0 && *(s16 *)(p + 0xC) / 3 < *(s16 *)(p + 0x10)) {
                    *(s32 *)(p + 8) |= 2;
                }
                break;
            case 1:
            case 2:
                if ((*(s32 *)(p + 8) & 2) == 0) {
                    if (effect_timer_past_threshold(p) != 0) {
                        *(s32 *)(p + 8) |= 2;
                    }
                }
                break;
            default:
                func_0046d730(D_0064B310, 0x73A);
                break;
            }
        } else {
            *(s32 *)(p + 8) &= ~1;
            *(s32 *)(p + 8) |= 2;
        }
    }
    if ((*(s32 *)(p + 8) & 4) != 0) {
        return;
    }
    col.b[0] = *(u8 *)(p + 0x14);
    col.b[1] = *(u8 *)(p + 0x15);
    col.b[2] = *(u8 *)(p + 0x16);
    col.b[3] = alpha;
    if (effect_timer_past_threshold(p) != 0) {
        func_0045c870(col.b, 0);
        return;
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
        f13 = 0.0f;
        if (ctr < e30) {
            f20 = f13;
        } else {
            e34 = *(f32 *)(e + 0x34);
            if (ctr < e34) {
                f20 = iGpffff8544;
                f13 = 280.0f * (1.0f - cosf((fGpffff84a4 * (ctr - e30)) / (e34 - e30)));
            } else {
                f20 = fGpffff8548;
                f13 = 280.0f;
            }
        }
        switch (*(s16 *)p) {
        case 0:
            func_003561d0(xy.vec, col.w, 0.0f, f13, f20, 1);
            break;
        case 1:
            func_00356170(xy.bits, 0.0f, f13, col.w, 0.0f, 0x30, 1);
            break;
        }
    }
}
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
void func_00356170(s64 arg0, f32 f0, f32 f1, s32 arg1,
                   f32 f2, s32 arg2, s32 arg3)
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
void func_003561d0(Vec2f arg0, s32 arg1, f32 dummy,
                   f32 f0, f32 f1, s32 arg2)
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
// FUN_00356250
#pragma opt_loop_invariants on
void func_00356250(u8 *arg0)
{
    extern u8 D_0064BDA0[];
    extern u8 D_0064CBE0[];
    extern u8 D_0064CC98[];
    extern char D_005E57F0[];
    extern char D_005E5810[];
    extern char D_005E5830[];
    extern char D_005E5850[];
    extern s32 func_00107180(s16 arg0);
    extern s64 func_00248760(s32 arg0);
    extern u16 func_00107ac0(s32 arg0);
    extern s32 func_00107ea0(s32 arg0);
    extern s32 func_00107c80(s32 arg0);
    extern u8 *func_0046a770(char *arg0);
    extern u8 *func_0046d200(u32 arg0, u32 arg1);
    extern void func_0046d730(const void *arg0, u32 arg1);
    extern s32 func_00246970(void);
    extern void func_002bc010(s32 arg0, u8 *arg1);
    extern u8 *func_0035adc0(s32 arg0, s64 arg1, s32 arg2);
    extern u8 *func_0035bf10(s32 arg0, u16 arg1, s32 arg2);
    s16 i;
    s16 j;
    s16 k;
    u8 *src;
    u8 *dst;
    u8 *bdabase;
    u8 *h0;
    u8 *h1;
    u8 *h3;
    u8 *h2;
    u8 **slot;
    s16 q;
    u16 *kind;
    s32 id;
    s16 n;
    s16 m;
    u8 *p;

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
        id = func_00107180(m) & 0xFFFF;
        if (id > 0) {
            p = arg0 + n * 0xC;
            *(s8 *)(p + 0x38) = func_00248760(id);
            *(s16 *)(p + 0x3A) = id;
            kind = (u16 *)(p + 0x3C);
            *kind = func_00107ac0(id);
            if (*kind == 0xA) {
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
    if (n > 0x15) {
        func_0046d730(D_0064CC98, 0x1E2);
    }
    h0 = func_0046a770(D_005E5830);
    if (h0 == NULL) {
        func_0046d730(D_0064CC98, 0x1E6);
    }
    h1 = func_0046a770(D_005E5850);
    if (h1 == NULL) {
        func_0046d730(D_0064CC98, 0x1E8);
    }
    h2 = func_0046a770(D_005E5810);
    if (h2 == NULL) {
        func_0046d730(D_0064CC98, 0x1EA);
    }
    *(u8 **)(arg0 + 0x1304) = h3 = func_0046a770(D_005E57F0);
    if (h3 == NULL) {
        func_0046d730(D_0064CC98, 0x1EC);
    }
    for (q = 0; q < 0x4D; q++) {
        if (q < 2) {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = func_0046d200((u32)h0, D_0064CBE0[q]);
        } else if (q < 0x33) {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = func_0046d200((u32)h1, D_0064CBE0[q]);
        } else if (q < 0x34) {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = func_0046d200((u32)h3, D_0064CBE0[q]);
        } else {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = func_0046d200((u32)h2, D_0064CBE0[q]);
        }
        if (*slot == NULL) {
            func_0046d730(D_0064CC98, 0x1FC);
        }
    }
    func_00359400(arg0, 0);
    func_002bc010(0xB, (u8 *)func_00246970());
    *(u8 **)(arg0 + 0x1308) = func_00354a50(0, 1);
    *(u8 **)(arg0 + 0x130C) = func_0035adc0(0, 0, 0);
    *(u8 **)(arg0 + 0x1310) = func_0035bf10(0, 0, 0);
}
#pragma opt_loop_invariants off
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
/* Community-list renderer: 10536/10544 bytes, all 115 relocations exact.
 * Native byte-opacity contracts, the Vec2f output, and real RGBA/rectangle
 * objects replace the former decompiler carriers and expanded conversions.
 * Measured: lifetime analysis retains the phased register roles; disabling
 * propagation keeps packed text colors captured before callbacks, while
 * disabling literal extraction avoids extra call-crossing float constants.
 * The sparse context view preserves observed offsets without allocating data.
 * See docs/probe_archive/Community_menu_renderer_00356a10_20260930.md. */
// FUN_00356A10
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_pulloutconstants off
void func_00356a10(u8 *work) {
    typedef struct {
        u8 opacity;
        u8 unknown0001[0x3];
        Vec2f origin;
        u8 unknown000C[0x4];
        s32 background;
        u8 unknown0014[0x8];
        s32 flags;
        u8 unknown0020[0x2];
        s16 angle;
        s16 selectedRow;
        s16 firstRow;
        s16 selectedDetail;
        u8 unknown002A[0x6];
        f32 rotation;
        f32 zoom;
        u8 unknown0038[0xFC];
        s16 rowCount;
        u8 unknown0136[0x12];
        s32 detailCount;
        s16 footerId;
        u8 unknown014E[0x12];
        Vec2f markerOffset;
        u8 unknown0168[0x2];
        u8 markerOpacity;
        u8 unknown016B[0x2C5];
        Vec2f footerOffset;
        u8 unknown0438[0x2];
        u8 footerOpacity;
        u8 unknown043B[0x25];
        Vec2f backEmblemOffset;
        u8 unknown0468[0x2];
        u8 backEmblemOpacity;
        u8 unknown046B[0x5];
        u16 backEmblemScaleX;
        u8 unknown0472[0x1E];
        Vec2f frontEmblemOffset;
        u8 unknown0498[0x2];
        u8 frontEmblemOpacity;
        u8 unknown049B[0x5];
        u16 frontEmblemScaleX;
        u8 unknown04A2[0x31E];
        Vec2f leftHintOffset;
        u8 unknown07C8[0x2];
        u8 leftHintOpacity;
        u8 unknown07CB[0x25];
        Vec2f rightHintOffset;
        u8 unknown07F8[0x2];
        u8 rightHintOpacity;
        u8 unknown07FB[0x25];
        Vec2f scrollOffset;
        u8 unknown0828[0x2];
        u8 scrollOpacity;
        u8 unknown082B[0x25];
        Vec2f titleOffset;
        u8 unknown0858[0x2];
        u8 titleOpacity;
        u8 unknown085B[0x25];
        Vec2f detailFooterOffset;
        u8 unknown0888[0x2];
        u8 detailFooterOpacity;
        u8 unknown088B[0x25];
        Vec2f portraitOffset;
        u8 unknown08B8[0x2];
        u8 portraitOpacity;
        u8 unknown08BB[0x25];
        Vec2f panelOffset;
        u8 unknown08E8[0x2];
        u8 panelOpacity;
        u8 unknown08EB[0x5];
        u16 panelScaleX;
        u8 unknown08F2[0x4];
        u16 panelScaleY;
        u8 unknown08F8[0x18];
        Vec2f gridOffset;
        u8 unknown0918[0x2];
        u8 gridOpacity;
        u8 unknown091B[0x25];
        Vec2f detailOffset;
        u8 unknown0948[0x2];
        u8 detailOpacity;
        u8 unknown094B[0x885];
        u8 * resource11D0;
        u8 * resource11D4;
        u8 * resource11D8;
        u8 * resource11DC;
        u8 * resource11E0;
        u8 * resource11E4;
        u8 * resource11E8;
        u8 * resource11EC;
        u8 * resource11F0;
        u8 * resource11F4;
        u8 * resource11F8;
        u8 * resource11FC;
        u8 * resource1200;
        u8 * resource1204;
        u8 * resource1208;
        u8 * resource120C;
        u8 * resource1210;
        u8 * resource1214;
        u8 * resource1218;
        u8 * resource121C;
        u8 * resource1220;
        u8 * resource1224;
        u8 * resource1228;
        u8 * resource122C;
        u8 * resource1230;
        u8 * resource1234;
        u8 * resource1238;
        u8 * resource123C;
        u8 * resource1240;
        u8 * resource1244;
        u8 * resource1248;
        u8 * resource124C;
        u8 * resource1250;
        u8 * resource1254;
        u8 * resource1258;
        u8 * resource125C;
        u8 * resource1260;
        u8 * resource1264;
        u8 * resource1268;
        u8 * resource126C;
        u8 * resource1270;
        u8 * resource1274;
        u8 * resource1278;
        u8 * resource127C;
        u8 * resource1280;
        u8 * resource1284;
        u8 * resource1288;
        u8 * resource128C;
        u8 * resource1290;
        u8 * resource1294;
        u8 * resource1298;
        u8 * resource129C;
        u8 * resource12A0;
        u8 * resource12A4;
        u8 * resource12A8;
        u8 * resource12AC;
        u8 * resource12B0;
        u8 * resource12B4;
        u8 * resource12B8;
        u8 unknown12BC[0x48];
        s32 resource1304;
        u8 * resource1308;
        u8 * resource130C;
        u8 * resource1310;
    } CommunityMenuView;
    CommunityMenuView *menu;
    extern void func_0034f1e0(void);
    extern s32 func_00275330(f32, f32, f32, s32, s8, s32, const char *, s32, s32, s32);
    extern void func_0034c270(Vec2f, s32, s32, f32);
    extern void func_0045d6e0(u8 *, f32 *, f32, s32);
    extern void func_003599c0(s32, u8 *);
    extern void func_00355410(u8 *, u8);
    extern void func_00354ba0(u8 *);
    extern void func_0034f2e0(void *, f32, f32, u8, u8, u8, u8);
    extern void func_0034f320(u8 *, f32, f32, f32, u8, u8, u8, u8, u16, u16, s16, f32, s16);
    extern f32 func_0046b260(u8 *);
    extern f32 func_0046b2f0(u8 *);
    extern void func_0046d730(const void *, u32);
    extern f32 func_0034f720(u8 *, f32, f32, f32);
    extern s32 func_00275020(f32, f32, f32, s32, s8, s32, const char *, s32, s32);
    extern u8 *func_00246830(u32);
    extern u8 *func_00246910(s16);
    extern u8 *func_00246940(s16);
    extern void func_002bc0b0(f32, f32, f32, u32, u32, u32, s32, s32);
    extern f32 func_0035aff0(u8 *, u8);
    extern f32 func_0035c040(u8 *, u8);
    extern void func_0035c670(u8 *, Vec2f *);
    extern u16 func_00107ac0(s32);
    extern u32 func_0010d620(s16);
    extern void func_0034f9d0(Vec2f, f32, u8, s32, s32);
    extern s32 (*D_00887300[])(s32, void *);
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064CC30[];
    extern u8 D_0064CC48[];
    extern u8 D_0064CC98[];
    typedef struct { u8 r, g, b, a; } MenuColor;
    MenuColor color;
    Vec2f position;
    union { s32 integer[4]; f32 transport[4]; } rectangle;
    s16 backPivotX;
    u8 frontEmblemOpacity;
    u8 *emblemTexture;
    u8 backEmblemOpacity;
    s16 frontPivotX;
    s16 emblemAngle;
    u8 portraitOpacity;
    u8 *portraitTexture;
    s16 portraitPivotX;
    u16 selectedCount;
    s8 rowFontMode;
    f32 globalOpacity;
    f32 originX;
    f32 originY;
    f32 panelScaleY;
    f32 panelX;
    f32 panelY;
    f32 panelScaleX;
    f32 cellBlend;
    f32 lockedHeaderX;
    f32 specialHeaderX;
    f32 lockedHeaderY;
    f32 specialHeaderY;
    f32 backgroundOpacityProduct;
    f32 titleOpacityProduct;
    f32 panelOpacityProduct;
    f32 portraitOpacityProduct;
    f32 rowOpacityProduct;
    f32 detailOpacityProduct;
    f32 footerOpacityProduct;
    f32 numberOpacityProduct;
    f32 leftHintOpacityProduct;
    f32 rightHintOpacityProduct;
    f32 cursorOpacityProduct;
    f32 separatorOpacityProduct;
    f32 menuOpacityProduct;
    f32 scrollOpacityProduct;
    f32 backEmblemOpacityProduct;
    f32 frontEmblemOpacityProduct;
    f32 markerOpacityProduct;
    f32 gridBaseOpacityProduct;
    f32 cellOpacityProduct;
    f32 cellX;
    f32 cellY;
    f32 zoomRatio;
    f32 portraitScale;
    f32 separatorAlphaFloat;
    f32 rowAlphaFloat;
    f32 detailAlphaFloat;
    f32 footerAlphaFloat;
    f32 numberAlphaFloat;
    f32 leftHintAlphaFloat;
    f32 rightHintAlphaFloat;
    f32 cursorAlphaFloat;
    f32 scrollAlphaFloat;
    f32 backEmblemAlphaFloat;
    f32 frontEmblemAlphaFloat;
    f32 markerAlphaFloat;
    f32 gridAlphaFloat;
    f32 titleAlphaFloat;
    f32 panelAlphaFloat;
    f32 portraitAlphaFloat;
    f32 globalAlphaFloat;
    f32 scrollThumbOffset;
    f32 gridOpacityFloat;
    f32 backEmblemScale;
    f32 frontEmblemScale;
    s16 detailValue;
    u32 gridOpacity;
    u32 numberOpacity;
    u32 numberColor;
    s32 selectedMode;
    s32 currentRank;
    s32 selectedIndex;
    u8 *rankNames;
    u8 *categoryTexture;
    u32 rankColor;
    s32 nameColor;
    s32 rowColor;
    u8 *tileTexture;
    u8 *detailValues;
    s32 categoryIndex;
    s32 scrollRange;
    s32 separatorIndex;
    s32 visibleIndex;
    u16 rankIndex;
    s32 cellIndex;
    s32 detailIndex;
    s32 backgroundOpacity;
    s32 footerQuantized;
    s32 leftHintOpacity;
    s32 rightHintOpacity;
    s32 cursorOpacity;
    s32 scrollQuantized;
    s32 markerOpacity;
    s32 gridQuantized;
    s32 titleQuantized;
    s32 panelQuantized;
    s32 rowQuantized;
    s32 numberQuantized;
    s16 backPivotY;
    s16 frontPivotY;
    u16 detailId;
    u16 panelScaleXBits;
    u16 panelScaleYBits;
    u16 backScaleBits;
    u16 frontScaleBits;
    MenuColor *palette;
    u8 scrollOpacity;
    u8 titleOpacity;
    u8 footerOpacity;
    u8 detailOpacity;
    u8 panelOpacity;
    u8 rowOpacity;
    u8 globalAlpha;
    u8 gridAlpha;
    u8 titleAlpha;
    u8 panelAlpha;
    u8 rowAlpha;
    u8 footerAlpha;
    u8 leftHintAlpha;
    u8 rightHintAlpha;
    u8 cursorAlpha;
    u8 separatorAlpha;
    u8 scrollAlpha;
    u8 backEmblemAlpha;
    u8 frontEmblemAlpha;
    u8 markerAlpha;
    u8 numberAlpha;
    u8 separatorOpacity;
    u8 *cellPaletteBytes;
    u16 *nameId;
    u8 *separatorAnimation;
    u8 *selectedEntry;
    u8 *rowAnimation;
    u8 *sprite;
    u8 *cell;

    /* Entries are initialized by func_00356250 with display modes 0 through 3. */
    menu = (CommunityMenuView *)work;
    func_0034f1e0();
    originX = (menu->origin.x);
    originY = (menu->origin.y);
    globalAlpha = (u8)(menu->opacity);
    globalAlphaFloat = (f32)globalAlpha;
    globalOpacity = globalAlphaFloat / 255.0f;
    if (menu->background != 0) {
        position.x = originX;
        position.y = originY;
        backgroundOpacityProduct = 255.0f * globalOpacity;
        backgroundOpacity = (u8)backgroundOpacityProduct;
        func_0034c270(position, backgroundOpacity & 0xFF, menu->background, 0);
    }
    if (menu->flags & 1) {
        for (separatorIndex = 0; separatorIndex < 6; separatorIndex++) {
                separatorAnimation = (u8 *)(work + (separatorIndex * 0x30));
                position.x = originX + *(f32 *)(separatorAnimation + 0x6A0);
                position.y = 64.0f * (f32)separatorIndex + (77.0f + (originY + *(f32 *)(separatorAnimation + 0x6A4)));
                separatorAlpha = (u8)(*( u8 *)((u8 *)(separatorAnimation) + (0x6AA)));
                separatorAlphaFloat = (f32)separatorAlpha;
                separatorOpacityProduct = separatorAlphaFloat * globalOpacity;
                separatorOpacity = (u8)separatorOpacityProduct;
                color = ((MenuColor *)D_0064CC30)[separatorIndex];
                color.a = separatorOpacity;
                rectangle.integer[0] = (s32)position.x;
                rectangle.integer[1] = (s32)position.y;
                rectangle.integer[2] = 0x280;
                rectangle.integer[3] = 3;
                D_00887300[0](1, 0);
                func_0045d6e0((u8 *)&color, rectangle.transport, 0.0f, (s64)0);
        }
        for (visibleIndex = 0; visibleIndex < 5; visibleIndex++) {
            if (menu->rowCount > (visibleIndex + menu->firstRow)) {
                func_003599c0(visibleIndex, work);
            }
        }
        menuOpacityProduct = 255.0f * globalOpacity;


        func_00355410(menu->resource1308, (u8)menuOpacityProduct);
        func_00354ba0(menu->resource1308);
        position.x = (f32) 0x25F + (originX + menu->scrollOffset.x);
        position.y = (f32) 0x107 + (originY + menu->scrollOffset.y);
        scrollAlpha = (u8)(menu->scrollOpacity);
        scrollAlphaFloat = (f32)scrollAlpha;
        scrollOpacityProduct = scrollAlphaFloat * globalOpacity;
        scrollQuantized = (u8)scrollOpacityProduct;
        scrollOpacity = scrollQuantized & 0xFF;
        sprite = menu->resource11DC;
        func_0034f2e0(sprite, position.x, position.y, 0xFAU, 0xA1U, 0U, scrollOpacity);
        sprite = menu->resource11E0;
        func_0034f2e0(sprite, position.x, 135.0f + position.y, 0xFAU, 0xA1U, 0U, scrollOpacity);
        sprite = menu->resource11D0;
        scrollThumbOffset = 6.0f;
        scrollRange = (s32)(menu->rowCount - 5);
        if (scrollRange > 0) {
            scrollThumbOffset = (6.0f + (f32) ((s32) (menu->firstRow * 0x64) / scrollRange));
        }
        func_0034f2e0(sprite, position.x, position.y + scrollThumbOffset, 0xFAU, 0xA1U, 0U, scrollOpacity);
    }
    if (menu->flags & 4) {
        emblemTexture = (u8 *)(menu->resource11D8);
        emblemAngle = (s16)(menu->angle);
        position.x = (f32) 0x20F + (originX + menu->backEmblemOffset.x);
        position.y = ((originY + menu->backEmblemOffset.y) - 3.0f);
        backEmblemAlpha = (u8)(menu->backEmblemOpacity);
        backEmblemAlphaFloat = (f32)backEmblemAlpha;
        backEmblemOpacityProduct = backEmblemAlphaFloat * globalOpacity;
        backEmblemOpacity = (u8)backEmblemOpacityProduct;
        backScaleBits = (u16)(menu->backEmblemScaleX);
        backEmblemScale = (f32)backScaleBits;
        backPivotX = (s16)(func_0046b260(emblemTexture) / 2.0f);
        backPivotY = (s16)(func_0046b2f0(emblemTexture) / 2.0f);
        func_0034f320(emblemTexture, position.x, position.y, 0.0f, 0xFFU, 0xD1U, 0x34U, backEmblemOpacity, (u16)backEmblemScale, (u16)backEmblemScale, backPivotX, (f32) emblemAngle, backPivotY);
        position.x = (f32) 0x221 + (originX + menu->frontEmblemOffset.x);
        position.y = ((originY + menu->frontEmblemOffset.y) - 6.0f);
        frontEmblemAlpha = (u8)(menu->frontEmblemOpacity);
        frontEmblemAlphaFloat = (f32)frontEmblemAlpha;
        frontEmblemOpacityProduct = frontEmblemAlphaFloat * globalOpacity;
        frontEmblemOpacity = (u8)frontEmblemOpacityProduct;
        frontScaleBits = (u16)(menu->frontEmblemScaleX);
        frontEmblemScale = (f32)frontScaleBits;
        frontPivotX = (s16)(func_0046b260(emblemTexture) / 2.0f);
        frontPivotY = (s16)(func_0046b2f0(emblemTexture) / 2.0f);
        func_0034f320(emblemTexture, position.x, position.y, 0.0f, 0xFFU, 0xFFU, 0x81U, frontEmblemOpacity, (u16)frontEmblemScale, (u16)frontEmblemScale, frontPivotX, (f32) emblemAngle, frontPivotY);
    }
    if (menu->flags & 0x10) {
        position.x = (f32) 0x175 + (originX + menu->markerOffset.x);
        position.y = ((25.0f + (originY + menu->markerOffset.y)) - 1.0f);
        markerAlpha = (u8)(menu->markerOpacity);
        markerAlphaFloat = (f32)markerAlpha;
        markerOpacityProduct = markerAlphaFloat * globalOpacity;
        markerOpacity = (u8)markerOpacityProduct;
        func_0034f2e0(menu->resource129C, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, markerOpacity & 0xFF);
    }
    if (menu->flags & 2) {
        selectedIndex = (s32)(menu->selectedRow + menu->firstRow);
        if ((selectedIndex < 0) || (selectedIndex >= 0x15)) {
            func_0046d730(&D_0064CC98, 0x2DD);
        }
        selectedEntry = (u8 *)add_offset_first((u32)selectedIndex * 12, (u32)work);
        selectedCount = *( u16 *)((u8 *)(selectedEntry) + (0x3C));
        categoryIndex = (s32)((*( u8 *)((u8 *)(selectedEntry) + (0x38)) - 1) & 0xFF);
        selectedMode = (s32)(*( s32 *)((u8 *)(selectedEntry) + (0x40)));
        tileTexture = (u8 *)(menu->resource11D4);
        position.x = ((2.0f + (originX + menu->gridOffset.x)) - 36.0f);
        position.y = (2.0f + (originY + menu->gridOffset.y));
        gridAlpha = (u8)(menu->gridOpacity);
        gridAlphaFloat = (f32)gridAlpha;
        gridBaseOpacityProduct = gridAlphaFloat * globalOpacity;
        gridQuantized = (u8)gridBaseOpacityProduct;
        gridOpacity = gridQuantized & 0xFF;
        for (cellIndex = 0; cellIndex < 0x6C; cellIndex++) {
            cell = (u8 *)(work + (cellIndex * 0x14));
            if (*( s16 *)((u8 *)(cell) + (0x960)) >= 0) {
                cellX = (position.x + (f32) ((*( s32 *)((u8 *)(cell) + (0x96C)) - *( s32 *)((u8 *)(cell) + (0x964))) * 0x2C));
                cellY = (position.y + (f32) ((*( s32 *)((u8 *)(cell) + (0x970)) - *( s32 *)((u8 *)(cell) + (0x968))) * 0x25));
                cellBlend = (func_0034f720(cell + 0x960, 0.5f, 0.5f, 1.0f));
                cellPaletteBytes = (u8 *)((s32)&D_0064CC48 + (*( s16 *)((u8 *)(cell) + (0x960)) * 4));
                color = *(MenuColor *)cellPaletteBytes;
                gridOpacityFloat = (f32)gridOpacity;
                cellOpacityProduct = gridOpacityFloat * cellBlend;
                func_0034f2e0(tileTexture, cellX, cellY, color.r, color.g, color.b, (u8)cellOpacityProduct);
            }
        }
        titleAlpha = (u8)(menu->titleOpacity);
        titleAlphaFloat = (f32)titleAlpha;
        titleOpacityProduct = titleAlphaFloat * globalOpacity;
        titleQuantized = (u8)titleOpacityProduct;
        titleOpacity = titleQuantized & 0xFF;
        position.x = (127.0f + (originX + menu->titleOffset.x));
        position.y = (17.0f + (originY + menu->titleOffset.y));
        sprite = menu->resource1254;
        func_0034f2e0(sprite, position.x, position.y, 0xDDU, 0x74U, 0U, titleOpacity);
        sprite = menu->resource1258;
        func_0034f2e0(sprite, (f32) 0x179 + position.x, position.y, 0xDDU, 0x74U, 0U, titleOpacity);
        position.x = (135.0f + (originX + menu->titleOffset.x));
        position.y = (21.0f + (originY + menu->titleOffset.y));
        sprite = menu->resource1298;
        func_0034f2e0(sprite, position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], titleOpacity);
        sprite = menu->resource1218;
        func_0034f2e0(sprite, 88.0f + position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], titleOpacity);
        position.x = (183.0f + (originX + menu->titleOffset.x));
        position.y = (22.0f + (originY + menu->titleOffset.y));
        categoryTexture = *(u8 **)((u8 *)add_offset_first((u32)(categoryIndex & 0xFF) * 4, (u32)work) + 0x12A4);
        func_0034f2e0(categoryTexture, position.x - (func_0046b260(categoryTexture) / 2.0f), position.y, 0xDDU, 0x74U, 0U, titleOpacity);
        position.x = (245.0f + (originX + menu->titleOffset.x));
        position.y = (19.0f + (originY + menu->titleOffset.y));
        rankColor = titleOpacity & 0xFF;
        nameColor = rankColor | ~0x7EFF;
        nameId = (u16 *)((u8 *)add_offset_first((u32)(selectedIndex * 12), (u32)work) + 0x3A);
        func_00275020(position.x, position.y, 0.0f, nameColor, 0, 1, (const char *)func_00246830(*nameId), 0, -2);
        rankNames = func_00246910((s16)*nameId);
        position.x = (130.0f + (originX + menu->titleOffset.x));
        position.y = (46.0f + (originY + menu->titleOffset.y));
        rankColor |= ~0xFF;
        switch (selectedMode) {
        case 0:
        case 1:
            rankIndex = (func_00107ac0(*nameId) - 1) & 0xFFFF;
            break;
        case 3:
            rankIndex = 11;
            break;
        case 2:
            rankIndex = 10;
            break;
        }
        func_002bc0b0(position.x, position.y, 0.0f, rankColor, 1, 6, 7, *(s16 *)(rankNames + ((rankIndex & 0xFFFF) * 2)));
        panelX = (15.0f + (originX + menu->panelOffset.x));
        panelY = (17.0f + (originY + menu->panelOffset.y));
        panelAlpha = (u8)(menu->panelOpacity);
        panelAlphaFloat = (f32)panelAlpha;
        panelOpacityProduct = panelAlphaFloat * globalOpacity;
        panelQuantized = (u8)panelOpacityProduct;
        panelOpacity = panelQuantized & 0xFF;
        panelScaleXBits = (u16)(menu->panelScaleX);
        panelScaleX = (f32)panelScaleXBits;
        panelScaleYBits = (u16)(menu->panelScaleY);
        panelScaleY = (f32)panelScaleYBits;
        position.x = panelX;
        position.y = panelY;
        sprite = menu->resource1248;
        func_0034f320(sprite, position.x, position.y, 0.0f, 0xDDU, 0x74U, 0U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        sprite = menu->resource124C;
        func_0034f320(sprite, position.x, 153.0f + position.y, 0.0f, 0xDDU, 0x74U, 0U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, 0, 0.0f, (s64)0);
        switch (selectedMode) {
        case 2:
        case 3:
            position.x = panelX + ((4.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((23.0f * panelScaleY) / 4096.0f);
            sprite = menu->resource1284;
            func_0034f320(sprite, position.x, position.y, 0.0f, 0x18U, 0U, 8U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
            sprite = menu->resource1288;
            func_0034f320(sprite, position.x, 124.0f + position.y, 0.0f, 0x18U, 0U, 8U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, 0, 0.0f, (s64)0);
            break;
        case 1:
            position.x = panelX + ((4.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((4.0f * panelScaleY) / 4096.0f);
            palette = (MenuColor *)D_0064B2EC;
            sprite = menu->resource1290;
            func_0034f320(sprite, position.x, position.y, 0.0f, palette->r, palette->g, palette->b, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
            sprite = menu->resource1288;
            func_0034f320(sprite, position.x, 143.0f + position.y, 0.0f, palette->r, palette->g, palette->b, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, 0, 0.0f, (s64)0);
            break;
        }
        position.x = panelX + ((6.0f * panelScaleX) / 4096.0f);
        position.y = panelY + ((25.0f * panelScaleY) / 4096.0f);
        sprite = menu->resource1250;
        func_0034f320(sprite, position.x, position.y, 0.0f, 0xFFU, 0xEBU, 0x3DU, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        if (selectedMode == 1) {
            position.x = panelX + ((19.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((6.0f * panelScaleY) / 4096.0f);
            sprite = menu->resource128C;
            func_0034f320(sprite, position.x, position.y, 0.0f, 0xDDU, 0x74U, 0U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        } else {
            position.x = panelX + ((15.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((7.0f * panelScaleY) / 4096.0f);
            sprite = menu->resource11E8;
            func_0034f320(sprite, position.x, position.y, 0.0f, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
            position.x = panelX + ((79.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((4.0f * panelScaleY) / 4096.0f);
            sprite = *(u8 **)((u8 *)add_offset_first((u32)(u16)selectedCount * 4, (u32)work) + 0x11EC);
        func_0034f320(sprite, position.x, position.y, 0.0f, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        }
        portraitOpacity = (u8)(menu->portraitOpacity);
        if (portraitOpacity > 0) {
            portraitAlphaFloat = (f32)portraitOpacity;
            portraitOpacityProduct = portraitAlphaFloat * globalOpacity;


            func_0035aff0(menu->resource130C, (u8)portraitOpacityProduct);
        }
        switch (selectedMode) {
        case 1:
            break;
        case 2:
            lockedHeaderX = 69.0f + originX;
            position.x = lockedHeaderX;
            lockedHeaderY = 133.0f + originY;
            position.y = lockedHeaderY;
            sprite = menu->resource1278;
            func_0034f2e0(sprite, lockedHeaderX, lockedHeaderY, 0xFFU, 0xFFU, 0xFFU, portraitOpacity);
            position.x = 21.5f + originX;
            position.y = 42.0f + originY;
            portraitTexture = (u8 *)(menu->resource127C);
            portraitPivotX = (s16)(func_0046b260(portraitTexture) / 2.0f);
            func_0034f320(portraitTexture, position.x, position.y, 0.0f, 0x18U, 0U, 8U, portraitOpacity, 0x1000, 0x1000, portraitPivotX, menu->rotation, (s16)(func_0046b2f0(portraitTexture) / 2.0f));
            break;
        case 3:
            specialHeaderX = 79.0f + originX;
            position.x = specialHeaderX;
            specialHeaderY = 133.0f + originY;
            position.y = specialHeaderY;
            sprite = menu->resource1270;
            func_0034f2e0(sprite, specialHeaderX, specialHeaderY, 0xFFU, 0xFFU, 0xFFU, portraitOpacity);
            position.x = 21.5f + originX;
            position.y = 42.0f + originY;
            sprite = menu->resource1274;
            zoomRatio = 1.0f + menu->zoom;
            portraitScale = 4096.0f * zoomRatio;
            position.x = (21.5f + originX) - (100.0f * menu->zoom);
            func_0034f320(sprite, position.x, position.y, 0.0f, 0x18U, 0U, 8U, portraitOpacity, (u16)portraitScale, (u16)portraitScale, (s64)0, 0.0f, (s64)0);
            break;
        }
        for (detailIndex = 0; detailIndex < menu->detailCount; detailIndex++) {
            if (detailIndex == menu->selectedDetail) {
                palette = (MenuColor *)D_0064B2E8;
                rowFontMode = 8;
            } else {
                palette = (MenuColor *)D_0064B2E0;
                rowFontMode = 6;
            }
            rowAnimation = (u8 *)(work + (detailIndex * 0x30));
            position.x = 15.0f + (originX + *(f32 *)(rowAnimation + 0x2B0));
            position.y = 28.0f * (f32)detailIndex + (178.0f + (originY + *(f32 *)(rowAnimation + 0x2B4)));
            rowAlpha = (u8)(*( u8 *)((u8 *)(rowAnimation) + (0x2BA)));
            rowAlphaFloat = (f32)rowAlpha;
            rowOpacityProduct = rowAlphaFloat * globalOpacity;
            rowQuantized = (u8)rowOpacityProduct;
            rowOpacity = rowQuantized & 0xFF;
            rowColor = rowOpacity | ~0xFF;
            sprite = menu->resource125C;
            func_0034f2e0(sprite, position.x, position.y, palette->r, palette->g, palette->b, rowOpacity);
            sprite = menu->resource1260;
            func_0034f2e0(sprite, 172.0f + position.x, position.y, palette->r, palette->g, palette->b, rowOpacity);
            func_00275330(91.0f + position.x, position.y, 0.0f, rowColor, rowFontMode, 2, (const char *)func_0010d620(*(s16 *)(work + detailIndex * 2 + 0x136)), 8, 0x18, -1);
        }
        detailOpacity = (u8)(menu->detailOpacity);
        if (detailOpacity > 0) {
            detailAlphaFloat = (f32)detailOpacity;
            detailOpacityProduct = detailAlphaFloat * globalOpacity;


            func_0035c040(menu->resource1310, (u8)detailOpacityProduct);
            switch (selectedMode) {
            case 0:
            case 1:
                break;
            case 2:
                func_0035c670(menu->resource1310, &position);
                position.x += 162.0f;
                position.y += 7.0f;
                sprite = menu->resource1280;
                func_0034f2e0(sprite, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, detailOpacity);
                break;
            case 3:
                func_0035c670(menu->resource1310, &position);
                position.x += 162.0f;
                position.y += 7.0f;
                sprite = menu->resource1294;
                func_0034f2e0(sprite, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, detailOpacity);
                break;
            default:
                func_0046d730(&D_0064CC98, 0x455);
                break;
            }
        }
        footerAlpha = (u8)(menu->detailFooterOpacity);
        footerAlphaFloat = (f32)footerAlpha;
        footerOpacityProduct = footerAlphaFloat * globalOpacity;
        footerQuantized = (u8)footerOpacityProduct;
        footerOpacity = footerQuantized & 0xFF;
        position.x = (227.0f + (originX + menu->detailFooterOffset.x));
        position.y = (f32) 0x13D + (originY + menu->detailFooterOffset.y);
        sprite = menu->resource126C;
        func_0034f2e0(sprite, position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], footerOpacity);
        position.x = (234.0f + (originX + menu->detailFooterOffset.x));
        position.y = (320.0f + (originY + menu->detailFooterOffset.y));
        palette = (MenuColor *)D_0064B2E8;
        sprite = menu->resource1264;
        func_0034f2e0(sprite, position.x, position.y, palette->r, palette->g, palette->b, footerOpacity);
        sprite = menu->resource1268;
        func_0034f2e0(sprite, (f32) 0x173 + position.x, position.y, palette->r, palette->g, palette->b, footerOpacity);
        if (menu->detailCount > 0) {
            detailId = *(u16 *)((u8 *)add_offset_first((u32)(menu->selectedDetail * 2), (u32)work) + 0x136);
            currentRank = (s32)(func_00107ac0(*nameId) & 0xFFFF);
            detailValues = func_00246940((s16)detailId);
            position.x = (244.0f + (originX + menu->detailFooterOffset.x));
            position.y = (320.0f + (originY + menu->detailFooterOffset.y));
            numberAlpha = (u8)(menu->detailFooterOpacity);
            numberAlphaFloat = (f32)numberAlpha;
            numberOpacityProduct = numberAlphaFloat * globalOpacity;
            numberQuantized = (u8)numberOpacityProduct;
            numberOpacity = numberQuantized & 0xFF;
            numberColor = numberOpacity | ~0x7EFF;
            detailValue = *(s16 *)((u8 *)add_offset_first((u32)(currentRank & 0xFFFF) * 2, (u32)detailValues) - 2);
            func_002bc0b0(position.x, position.y, 0.0f, numberColor, 1, 8, 7, detailValue - 1);
            numberColor = numberOpacity | ~0xFF;
            func_002bc0b0(position.x, 28.0f + position.y, 0.0f, numberColor, 1, 6, 7, detailValue);
        }
    }
    if (menu->flags & 0x20) {
        position.x = (18.0f + (originX + menu->leftHintOffset.x));
        position.y = (f32) 0x197 + (originY + menu->leftHintOffset.y);
        leftHintAlpha = (u8)(menu->leftHintOpacity);
        leftHintAlphaFloat = (f32)leftHintAlpha;
        leftHintOpacityProduct = leftHintAlphaFloat * globalOpacity;
        leftHintOpacity = (u8)leftHintOpacityProduct;
        func_0034f2e0(menu->resource11E4, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, leftHintOpacity & 0xFF);
    }
    if (menu->flags & 0x40) {
        position.x = (18.0f + (originX + menu->rightHintOffset.x));
        position.y = (f32) 0x197 + (originY + menu->rightHintOffset.y);
        rightHintAlpha = (u8)(menu->rightHintOpacity);
        rightHintAlphaFloat = (f32)rightHintAlpha;
        rightHintOpacityProduct = rightHintAlphaFloat * globalOpacity;
        rightHintOpacity = (u8)rightHintOpacityProduct;
        func_0034f2e0(menu->resource12A0, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, rightHintOpacity & 0xFF);
    }
    position.x = (640.0f + (originX + menu->footerOffset.x));
    position.y = (400.0f + (originY + menu->footerOffset.y));
    cursorAlpha = (u8)(menu->footerOpacity);
    cursorAlphaFloat = (f32)cursorAlpha;
    cursorOpacityProduct = cursorAlphaFloat * globalOpacity;
    cursorOpacity = (u8)cursorOpacityProduct;
    func_0034f9d0(position, 0.0f, (u8)(cursorOpacity & 0xFF), menu->footerId, menu->resource1304);
}

#pragma pop

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
         (datGetFlag(temp_4_2) != 0))) {
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

/* measured 003599c0: object 1173 instrs against retail 1190 stripped (1192 raw; -17, -1.4%; band
   1156-1228) via `python3 tools/fnalign.py src/promoted/code1_0035.c func_003599c0 --candidate
   /tmp/3599c0_fix6.c`, 853 edits (+2 reloc-only). Frame object 0x130 vs retail 0x120
   (long-lived u16 spills quad, not half); calls 17/17 (11x0034f320 + 0046d730/0046b260/
   0045d6e0/00275020/00246830 + D_00887300 jalr); lwc1 20/20, swc1 12/12. Float landmarks exact
   (f25/f24/f26/f21/f22/f23/f28/f27/f20/f29/f30, shared madd products per 7r, descending float decls);
   residual is int-color allocation (params stuck $s0/$s1), v30 stack spill, and CSE-held o-base
   recomputes (first-3 via b, last-2 via o but CSE to b) plus conversion scheduling (object converts
   before lui/lw, retail after). Fixes: e0=(s128)*(u16*)(e+0x3C) quad plus f0v direct (was missing
   0x3C load, w3A word intermediate removed) for lhu/sh/sq; b-split f3/f2/f28/f27/f4b/f1c via o
   to keep o live (addu +9 residual); f20 inside if(mode!=1) for second div (lui/mtc1 +1 each);
   switch(mode) case1/case0 fallthrough shared (was (mode==1)||(mode==0) sltiu, now beq 3,2,1,0
   with bodies loop,2,3 per M2C order 1/0,2,3); unsigned av for divu. Honest: slti for retail
   slti, sltiu only where retail sltiu (isSelf ==), u8/u16 casts, s128 quad, indirect D_00887300[0];
   prototypes per recon (0034f320 x13, 0045d6e0 x4, 00246830 returns u8 *). No sltiu-for-slti,
   no s64 flat, no opt_propagation, no volatile, no asm.
   Deficit-vs-composition (2026-09-20): deficit is 17; `deficit_scan` classes the large runs CROSS
   (125 at 0x35a02c, 96 at 0x359cfc paired 2/92 nearby, 60 at 0x35a400), so the composition
   223 missing / 212 extra (7 deletes, 11 inserts, 74 replaces with 71 <=13) is alignment artefact
   of the repeated (u16) clamp + 0034f320 idiom, not unwritten code. Counterparts: obj 92
   (164:256) against ret 96 (207:303) col[3]/rc/o2 block; obj 79+42 (383:462, 337:379) against
   ret 125 (411:536) 0x11ec block; obj 21 (632:653) against ret 60 (656:716) 0x122c block.
   Probes: f3 via b1 1173/854/223/212 unchanged; f0v load late 1175/852/223/212 (adds lq, worse).
   No mass apply; body left unchanged, in band near finished. */
// FUN_003599C0 NONMATCHING
#ifdef NON_MATCHING
void func_003599c0(s32 arg0, u8 *arg1)
{
    typedef signed __int128 s128;
    extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
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
    u8 *sprE;
    u8 *sprL;
    u8 *spr;
    u8 *ns;
    s32 i;
    s32 cnt;
    u32 av;
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
    f0v = *(u16 *)(e + 0x3A);
    e0 = (s128)*(u16 *)(e + 0x3C);
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
    f3 = (f32)*(u16 *)(arg1 + o1 + 0x5C0);
    f2 = (f32)*(u16 *)(arg1 + o1 + 0x5C6);
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
    f28 = (f32)*(u16 *)(arg1 + o2 + 0x1A0);
    f27 = (f32)*(u16 *)(arg1 + o2 + 0x1A6);
    if (isSelf) {
        ptab = D_0064B2EC;
        ctab = &D_0064B2E8;
        v30 = 8;
    } else {
        ptab = D_0064B2F8;
        ctab = &D_0064B2E0;
        v30 = 6;
    }
    if (mode != 1) {
        f20 = f27 / 4096.0f;
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
    switch (mode) {
    case 1:
    case 0:
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
        break;
    case 2:
        spr = isSelf ? *(u8 **)(arg1 + 0x1240) : *(u8 **)(arg1 + 0x1244);
        func_0034f320(spr, 198.0f + f23, f22 + 14.0f * f20, 0.0f,
                      0xFF, 0xFF, 0xFF, alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
        break;
    case 3:
        spr = isSelf ? *(u8 **)(arg1 + 0x1238) : *(u8 **)(arg1 + 0x123C);
        func_0034f320(spr, 204.0f + f23, f22 + 14.0f * f20, 0.0f,
                      0xFF, 0xFF, 0xFF, alpha, (u16)f28, (u16)f27, 0, 0.0f, 0);
        break;
    default:
        break;
    }
    if (f27 == 4096.0f) {
        f23 = 157.0f + f23;
        f20 = f22 + 30.0f * f20;
        av = ((u32)(alpha & 0xFF) * 0xFF) / 255U;
        color = -256;
        color |= (s32)av;
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
    f4b = (f32)*(u16 *)(arg1 + o3 + 0x4D0);
    f1c = (f32)*(u16 *)(arg1 + o3 + 0x4D6);
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
    temp_18 = func_00451fc0((void *)(arg0), (const void *)(&D_0064CCD0), 0xC7, 0, 0, func_0035aec0, func_0035af10, (u8 *)(temp_2));
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

/* Community portrait and selected-state passes. Measured whole-owner MATCH:
 * 2772 bytes plus twelve retail zero bytes; byte-opacity/RGBA and the complete
 * Sky2 vertex layout retain the actual ABI. The work pointer is captured on
 * entry, visibility is re-read after the camera query, and texture and mode
 * are loaded after their rendering callbacks. Keep the table addresses while
 * reloading their callback slots. Loop invariants and scoped lifetimes retain
 * the retail color conversions and row/index bases without synthetic padding.
 * See docs/probe_archive/Community_portrait_0035aff0_20260930.md. */
// FUN_0035AFF0
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_pulloutconstants off
#pragma opt_propagation off
f32 func_0035aff0(u8 *arg0, u8 arg1)
{
    extern u8 *func_00457120(void);
    extern f32 D_008872F8[];
    extern f32 func_0035bad0(u8 *arg0);
    extern void func_0034f1e0(void);
    extern s32 (*D_00887300[])(s32, void *);
    extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern s32 (*D_00887314[])(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
    extern s32 RpSkyRenderStateSet(s32 arg0, void *arg1);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern f32 cosf(f32 arg0);
    extern f32 func_0035bd20(Float2 first, Float2 second, Float2 origin);
    extern f32 fGpffff81e0;
    extern f32 fGpffff82fc;
    /* Full Sky2 layout from rw/sky2/rwplcore.h. The strip backends copy all
     * 64 bytes. This renderer initializes only position, UV/reciprocal depth
     * and RGBA; fog is disabled and the SDK declares normals unused. */
    typedef struct {
        f32 x, y, z, cameraZ;
        f32 u, v, reciprocalZ, fogPadding;
        f32 red, green, blue, alpha;
        f32 normalX, normalY, normalZ, alignmentPadding;
    } CommunityVertex;
    typedef struct { u8 red, green, blue, alpha; } CommunityColor;
    typedef struct { void *raster; } CommunityTexture;
    typedef struct {
        Float2 position;
        Float2 scale;
        Float2 targetScale;
        Float2 startScale;
        s8 portraitId;
        u8 unknown0021;
        s16 transitionFrame;
        s16 effectFrame;
        u8 unknown0026[2];
        s32 flags;
        s32 loaded;
        u8 unknown0030[12];
        CommunityTexture *texture;
        u8 unknown0040[0x100];
        const char *module;
    } CommunityPortrait;
    typedef struct {
        u8 unknown0000[0x38];
        u8 *work;
    } CommunityPortraitTask;
    typedef struct {
        u8 unknown0000[0x80];
        f32 nearClip;
    } CommunityCameraView;
    CommunityVertex qs[4];
    Float2 cur;
    Float2 ptA;
    Float2 ptB;
    CommunityVertex verts[35];
    struct IndexPair { s16 top, bottom; } idx[32];
    CommunityPortrait *portrait;
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
    s32 j;
    s32 vtx;
    s32 i;
    s32 ii;
    s32 jj;
    CommunityColor color;
    s32 (**stateSet)(s32, void *);

    /* The SDK task transports its work as u8 *; the captured value and the
     * post-camera visibility view deliberately have separate lifetimes. */
    portrait = (CommunityPortrait *)*(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / ((CommunityCameraView *)func_00457120())->nearClip;
    {
        CommunityPortrait *t = (CommunityPortrait *)((CommunityPortraitTask *)arg0)->work;
        s32 flag;
        if ((t->loaded == 0) || (t->portraitId == 0)) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag == 0) {
            return 0.0f;
        }
    }
    blend = func_0035bad0((u8 *)portrait);
    sx = 50.0f * portrait->scale.x;
    sy = 64.0f * portrait->scale.y;
    if (portrait->flags & 1) {
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
    qs[0].x = portrait->position.x - sx;
    qs[0].y = portrait->position.y - sy;
    qs[0].z = z;
    qs[0].red = 255.0f;
    qs[0].green = 255.0f;
    qs[0].blue = 255.0f;
    qs[0].alpha = (f32)arg1;
    qs[0].u = u0;
    qs[0].v = v0;
    qs[0].reciprocalZ = q;
    qs[1].x = portrait->position.x + sx;
    qs[1].y = portrait->position.y - sy;
    qs[1].z = z;
    qs[1].red = 255.0f;
    qs[1].green = 255.0f;
    qs[1].blue = 255.0f;
    qs[1].alpha = (f32)arg1;
    qs[1].u = u0 + u1;
    qs[1].v = v0;
    qs[1].reciprocalZ = q;
    qs[2].x = portrait->position.x - sx;
    qs[2].y = portrait->position.y + sy;
    qs[2].z = z;
    qs[2].red = 255.0f;
    qs[2].green = 255.0f;
    qs[2].blue = 255.0f;
    qs[2].alpha = (f32)arg1;
    qs[2].u = u0;
    qs[2].v = v0 + v1;
    qs[2].reciprocalZ = q;
    qs[3].x = portrait->position.x + sx;
    qs[3].y = portrait->position.y + sy;
    qs[3].z = z;
    qs[3].red = 255.0f;
    qs[3].green = 255.0f;
    qs[3].blue = 255.0f;
    qs[3].alpha = (f32)arg1;
    qs[3].u = u0 + u1;
    qs[3].v = v0 + v1;
    qs[3].reciprocalZ = q;
    {
        s32 (**drawFirst)(s32, void *, s32);
        func_0034f1e0();
        stateSet = D_00887300;
        stateSet[0](1, portrait->texture->raster);
        drawFirst = D_00887310;
        drawFirst[0](4, &qs[0], 4);
    }
    mode = portrait->flags;
    if (((mode & 1) != 0) || ((mode & 2) != 0)) {
        {
            s32 k;
            if ((mode & 1) != 0) {
                color.red = 0xF2;
                color.green = 0x15;
                color.blue = 0;
                color.alpha = 0xFF;
            } else {
                color.red = 0xF2;
                color.green = 0;
                color.blue = 0xBA;
                color.alpha = 0xFF;
            }
            for (k = 0; k < 4; k++) {
                CommunityVertex *vertex = &qs[k];
                vertex->red = (f32)color.red;
                vertex->green = (f32)color.green;
                vertex->blue = (f32)color.blue;
                vertex->alpha = (f32)color.alpha;
            }
        }
        {
            s32 (**drawPrimitive)(s32, void *, s32);
            func_00489f80();
            RpSkyRenderStateSet(3, (void *)0x31801);
            drawPrimitive = D_00887310;
            drawPrimitive[0](4, &qs[0], 4);
            func_0048a000();
            stateSet[0](1, 0);
            RpSkyRenderStateSet(3, (void *)0x31801);
            RpSkyRenderStateSet(2, (void *)0x58);
            drawPrimitive[0](4, &qs[0], 4);
            RpSkyRenderStateSet(3, (void *)0x717FB);
            RpSkyRenderStateSet(2, (void *)0x44);
        }
    } else if (mode & 4) {
        f32 f;
        f = (f32)portrait->effectFrame / 100.0f;
        ang1 = fGpffff81e0 * f;
        ang2 = fGpffff82fc + ang1;
        s1 = sinf(ang1);
        c1 = cosf(ang1);
        s2 = sinf(ang2);
        c2 = cosf(ang2);
        ptA.x = portrait->position.x + 0.78125f * (64.0f * s1);
        ptA.y = portrait->position.y - 64.0f * c1;
        ptB.x = portrait->position.x + 0.78125f * (64.0f * s2);
        ptB.y = portrait->position.y - 64.0f * c2;
        i = 0;
        vtx = 0;
        while (i < 7) {
            f32 rowDY;
            f32 rowV;
            j = 0;
            rowDY = 2.0f * (sy * ((f32)i / 6.0f - 0.5f));
            rowV = v0 + v1 * ((f32)i / 6.0f);
            while (j < 5) {
                f32 grey;
                u8 g8;
                cur.x = portrait->position.x + 2.0f * (sx * ((f32)j / 4.0f - 0.5f));
                cur.y = portrait->position.y + rowDY;
                verts[vtx].x = cur.x;
                verts[vtx].y = cur.y;
                verts[vtx].z = z;
                verts[vtx].u = u0 + u1 * ((f32)j / 4.0f);
                verts[vtx].v = rowV;
                verts[vtx].reciprocalZ = q;
                grey = 255.0f * func_0035bd20(ptA, ptB, cur);
                g8 = (u8)grey;
                verts[vtx].red = (f32)g8;
                verts[vtx].green = (f32)g8;
                verts[vtx].blue = (f32)g8;
                verts[vtx].alpha = (f32)g8;
                vtx++;
                j++;
            }
            i++;
        }
        if (vtx > 35) {
            func_0046d730(&D_0064CC98, 0x835);
        }
        for (ii = 0; ii < 6; ii++) {
            for (jj = 0; jj < 5; jj++) {
                idx[ii * 5 + jj].top = (s16)(jj + ii * 5);
                idx[ii * 5 + jj].bottom = (s16)(jj + (ii + 1) * 5);
            }
        }
        func_00489f80();
        RpSkyRenderStateSet(3, (void *)0x31801);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 5], 10);
        }
        func_0048a000();
        stateSet[0](1, 0);
        RpSkyRenderStateSet(3, (void *)0x31801);
        RpSkyRenderStateSet(2, (void *)0x58);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 5], 10);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
    return blend;
}

#pragma pop

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
    *(f32 *)(arg0 + 8) = temp_f21 + ((*(f32 *)(arg0 + 0x10) - temp_f21) * sinf(temp_f22));
    temp_f21_2 = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0xC) = temp_f21_2 + ((*(f32 *)(arg0 + 0x14) - temp_f21_2) * sinf(temp_f22));
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
    sprintf(buf, D_0064CCF0);
    func_003547c0((s32 *)(base + 0x30), buf);
    goto done;
zero_case:
    func_003547c0((s32 *)(base + 0x30), NULL);
    goto done;
other_case:
    sprintf(buf, D_0064CD10, (s32)arg1 - 1);
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
    RwV3dNormalize(&direction, &direction);
    projection = direction.xy.x * normal.xy.x + direction.xy.y * normal.xy.y + direction.z * normal.z;
    interpolation_accumulate(&total, 1.0f, projection);
    direction.xy.x = second.x - origin.x;
    direction.xy.y = second.y - origin.y;
    direction.z = 20.0f;
    RwV3dNormalize(&direction, &direction);
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
    temp_16 = func_00451fc0((void *)(arg0), (const void *)(&D_0064CD40), 0xC7, 0, 0, func_0035be70, func_0035bec0, (u8 *)(temp_2));
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
f32 func_0035c040(u8 *arg0, u8 arg1)
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
    ret = sinf(fGpffff84a4 * ((f32)*(s16 *)(p + 0x22) / 10.0f));
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
    qs[0].a = (f32)arg1;
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
    qs[1].a = (f32)arg1;
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
    qs[2].a = (f32)arg1;
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
    qs[3].a = (f32)arg1;
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
                sprintf(sp168, &iGpffffa968);
            } else {
                sprintf(sp168, &iGpffffa96c);
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
        sprintf(sp60, D_0064CD60, temp_17, (s8)var_18, sp168);
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
void func_0035c670(u8 *arg0, Vec2f *position)
{
    *position = *(Vec2f *)(*(u8 **)(arg0 + 0x38));
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
/* Draw the animated menu panels, eleven-column pip grids and scrolling list.
 * Position, texture and opacity snapshots preserve the values used by each
 * draw group. The label pass uses the final row's alpha; the scrollbar keeps
 * its fractional origin, while the solid primitive requires integer geometry.
 * Measured b210 O2 with scoped lifetime/loop-invariant optimization:
 * 7176 instruction bytes plus the retail window's eight-byte zero tail.
 * See docs/probe_archive/Menu_renderer_0035fd60_20260930.md. */
// FUN_0035FD60
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
void func_0035fd60(u8 *work)
{
    extern void func_0034f1e0(void);
    extern void func_0034c270(Vec2f position, s32 alpha, s32 background, f32 depth);
    extern void func_0034f2e0(void *ptr, f32 x, f32 y, u8 r, u8 g, u8 b, u8 a);
    extern void func_0034f9d0(Vec2f position, f32 depth, u8 alpha, s32 mode, s32 resource);
    extern void func_00275980(void *src, void *dst, s32 n);
    extern s32 func_00274ed0(f32 x, f32 y, f32 depth, s32 color, s8 character, s32 font,
                            const char *text, s32 flags, s32 reserved);
    extern void func_002bc7a0(s32 item, f32 x, f32 y, f32 depth,
                              s32 textColor, s32 font, s32 mode, s32 table);
    extern void func_00361d20(s32 idx, u8 *ctx);
    extern s32 RpSkyRenderStateSet(s32 cmd, void *val);
    extern void func_0045c870(u8 *color, s32 flags);
    extern void func_0045d6e0(u8 *color, f32 *rectangle, f32 depth, s32 flags);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B300[];
    extern u8 D_0064B2E0[];
    extern void *D_0064D448[];
    extern s32 (*D_00887300[])(s32, void *);
    u8 colorBytes[4];
    /* The primitive wrapper copies four words through its float transport view;
     * their actual payload is the integer x, y, width and height. */
    union { s32 integer[4]; f32 transport[4]; } rectangle;
    char text[0x100];
    Vec2f position;
    s32 column;
    s32 pip;
    u8 *entry;
    void *pipSprite;
    void *cursorSprite;
    void *sprite;
    typedef struct { u8 r, g, b, a; } PaletteColor;
    PaletteColor *palette;
    f32 gridX;
    f32 gridY;
    f32 offsetY;
    f32 offsetX;
    f32 opacityScale;
    f32 originX;
    f32 originY;
    s32 background;
    u8 gridAlpha;
    s32 rowOffset;
    s32 textColor;
    s32 itemIndex;
    s32 displayItem;
    u8 opacity;
    u8 labelOpacity;
    u32 lastRowAlpha;
    func_0034f1e0();
    originX = *(f32 *)(work + 4);
    originY = *(f32 *)(work + 8);
    opacityScale = (f32)*(u8 *)work / 255.0f;
    background = *(s32 *)(work + 0x10);
    if (background != 0) {
        position.x = originX;
        position.y = originY;
        gridAlpha = (u8)(255.0f * opacityScale);
        func_0034c270(position, (u8)gridAlpha, background, 0.0f);
    }
    if (*(s32 *)(work + 0x1C) & 1) {
        position.x = originX + *(f32 *)(work + 0x178) + 90.0f;
        position.y = originY + *(f32 *)(work + 0x17C) + 91.0f;
        gridAlpha = (u8)((f32)*(u8 *)(work + 0x182) * opacityScale);
        func_0034f2e0(*(void **)(work + 0x6FC), position.x, position.y, 0xFF, 0xFF, 0xFF, gridAlpha);
    }
    if (*(s32 *)(work + 0x1C) & 2) {
        gridX = 23.0f + (595.0f + (originX + *(f32 *)(work + 0x148)));
        gridY = 280.0f + (originY + *(f32 *)(work + 0x14C));
        gridAlpha = (u8)((f32)*(u8 *)(work + 0x152) * opacityScale);
        /* The shared pip texture and phase opacity are snapshots for this grid. */
        pipSprite = *(void **)(work + 0x678);

        for (column = 0; column < 0xB; column++) {
            position.x = gridX - (f32)(column * 0x2D);
            pip = 0;
            entry = work + column * 0xA;
            for (; pip < *(s16 *)(entry + 0x5EA); pip++) {
                if (pip == *(s16 *)(entry + 0x5EA) - 1) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0xA4;
                    colorBytes[3] = (u8)(0.6f * (f32)gridAlpha);
                } else if (pip < *(s16 *)(entry + 0x5EE)) {
                    colorBytes[0] = 0xFE;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0x56;
                    colorBytes[3] = (u8)(0.5f * (f32)gridAlpha);
                } else {
                    continue;
                }
                position.y = gridY - (f32)(pip * 0x11);
                func_0034f2e0(pipSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
            }
        }
        for (column = 0; column < 3; column++) {
            rowOffset = column * 0x30;
            entry = work + rowOffset;
            position.x = 144.0f + (originX + *(f32 *)(entry + 0x58));
            position.y = 136.0f + (originY + *(f32 *)(entry + 0x5C) + (f32)(column * 0x30));
            opacity = (u8)((f32)*(u8 *)(entry + 0x62) * opacityScale);
            colorBytes[0] = D_0064B2E8[0];
            colorBytes[1] = D_0064B2E8[1];
            colorBytes[2] = D_0064B2E8[2];
            colorBytes[3] = opacity;
            func_0034f2e0(*(void **)(work + column * 8 + 0x65C), position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
        }
        /* Smooth the cursor halfway toward the selected row using its old pair. */
        offsetX = 303.0f + originX;
        offsetY = 133.0f + originY + (f32)(*(s16 *)(work + 0x28) * 0x30);
        position = *(Vec2f *)(work + 0x40);
        offsetX = offsetX - position.x;
        offsetY = offsetY - position.y;
        offsetX = offsetX * 0.5f;
        offsetY = offsetY * 0.5f;
        *(f32 *)(work + 0x40) = position.x + offsetX;
        *(f32 *)(work + 0x44) = position.y + offsetY;
        position.x = *(f32 *)(work + 0x118) + *(f32 *)(work + 0x40);
        position.y = *(f32 *)(work + 0x11C) + *(f32 *)(work + 0x44);
        lastRowAlpha = (u8)((f32)*(u8 *)(work + 0x122) * opacityScale);
        cursorSprite = *(void **)(work + 0x658);
        colorBytes[0] = D_0064B2E8[0];
        colorBytes[1] = D_0064B2E8[1];
        colorBytes[2] = D_0064B2E8[2];
        func_0034f2e0(cursorSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], lastRowAlpha);
        func_00489f80();
        D_00887300[0](1, 0);
        colorBytes[3] = 0;
        func_0045c870(colorBytes, 0);
        func_0034f2e0(cursorSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], 0xFF);
        func_0048a000();
        RpSkyRenderStateSet(3, (void *)0x2D801);
        RpSkyRenderStateSet(2, (void *)0x44);
        for (column = 0; column < 3; column++) {
            rowOffset = column * 0x30;
            entry = work + rowOffset;
            position.x = 144.0f + (originX + *(f32 *)(entry + 0x58));
            position.y = 136.0f + (originY + *(f32 *)(entry + 0x5C) + (f32)(column * 0x30));
            lastRowAlpha = (u8)((f32)*(u8 *)(entry + 0x62) * opacityScale);
            colorBytes[0] = D_0064B2EC[0];
            colorBytes[1] = D_0064B2EC[1];
            colorBytes[2] = D_0064B2EC[2];
            colorBytes[3] = lastRowAlpha;
            func_0034f2e0(*(void **)(work + column * 8 + 0x65C), position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        /* The label pass uses the alpha left by the final animated row. */
        labelOpacity = lastRowAlpha;
        for (column = 0; column < 3; column++) {
            rowOffset = column * 0x30;
            entry = work + rowOffset;
            position.x = 144.0f + (originX + *(f32 *)(entry + 0x58));
            position.y = 136.0f + (originY + *(f32 *)(entry + 0x5C) + (f32)(column * 0x30));
            sprite = *(void **)(work + column * 8 + 0x660);
            func_0034f2e0(sprite, position.x + 4.0f, position.y + 20.0f, 0x80, 0x80, 0x80, labelOpacity);
        }
        position.x = 468.0f + (originX + *(f32 *)(work + 0xE8));
        position.y = 139.0f + (originY + *(f32 *)(work + 0xEC));
        opacity = (u8)((f32)*(u8 *)(work + 0xF2) * opacityScale);
        sprite = *(void **)(work + 0x674);
        colorBytes[0] = D_0064B2E8[0];
        colorBytes[1] = D_0064B2E8[1];
        colorBytes[2] = D_0064B2E8[2];
        func_0034f2e0(sprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], opacity);
        position.x = 53.0f + (567.0f + (originX + *(f32 *)(work + 0xE8)));
        position.y = 269.0f + (originY + *(f32 *)(work + 0xEC));
        opacity = (u8)((f32)*(u8 *)(work + 0xF2) * opacityScale);
        textColor = opacity | ~0xFF;
        func_00275980(D_0064D448[*(s16 *)(work + 0x28)], text, 0x100);
        func_00274ed0(position.x, position.y, 0.0f, textColor, 7, 1, text, 2, 0);
        position.x = 640.0f + (originX + *(f32 *)(work + 0x1A8));
        position.y = 400.0f + (originY + *(f32 *)(work + 0x1AC));
        opacity = (u8)((f32)*(u8 *)(work + 0x1B2) * opacityScale);
        func_0034f9d0(position, 0.0f, opacity, *(s16 *)(work + 0x34), *(s32 *)(work + 0x700));
    }
    if (*(s32 *)(work + 0x1C) & 4) {
        gridX = 23.0f + (595.0f + (originX + *(f32 *)(work + 0x148)));
        gridY = 430.0f + (originY + *(f32 *)(work + 0x14C));
        gridAlpha = (u8)((f32)*(u8 *)(work + 0x152) * opacityScale);
        /* The shared pip texture and phase opacity are snapshots for this grid. */
        pipSprite = *(void **)(work + 0x678);
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);

        for (column = 0; column < 0xB; column++) {
            position.x = gridX - (f32)(column * 0x2D);
            pip = 0;
            entry = work + column * 0xA;
            for (; pip < *(s16 *)(entry + 0x5EA); pip++) {
                if (pip == *(s16 *)(entry + 0x5EA) - 1) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0xF0;
                    colorBytes[3] = (u8)(0.5f * (f32)gridAlpha);
                } else if (pip < *(s16 *)(entry + 0x5EE)) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFC;
                    colorBytes[2] = 0x40;
                    colorBytes[3] = (u8)(0.45f * (f32)gridAlpha);
                } else {
                    continue;
                }
                position.y = gridY - (f32)(pip * 0x11);
                func_0034f2e0(pipSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
            }
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        position.x = 29.0f + (originX + *(f32 *)(work + 0x3B8));
        position.y = -13.0f + (54.0f + (originY + *(f32 *)(work + 0x3BC)));
        opacity = (u8)((f32)*(u8 *)(work + 0x3C2) * opacityScale);
        palette = (PaletteColor *)D_0064B2E8;
        sprite = *(void **)(work + 0x6DC);
        func_0034f2e0(sprite, position.x, position.y, palette->r, palette->g, palette->b, opacity);
        sprite = *(void **)(work + 0x6E0);
        func_0034f2e0(sprite, position.x + 73.0f, position.y, palette->r, palette->g, palette->b, opacity);
        palette = (PaletteColor *)D_0064B2EC;
        sprite = *(void **)(work + 0x6D8);
        func_0034f2e0(sprite, position.x + 19.0f, position.y + 2.0f, palette->r, palette->g, palette->b, opacity);
        position.x = 89.0f + (originX + *(f32 *)(work + 0x3B8));
        position.y = -13.0f + (86.0f + (originY + *(f32 *)(work + 0x3BC)));
        opacity = (u8)((f32)*(u8 *)(work + 0x3C2) * opacityScale);
        palette = (PaletteColor *)D_0064B300;
        sprite = *(void **)(work + 0x68C);
        offsetY = position.y + 4.0f;
        func_0034f2e0(sprite, position.x - 6.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sprite = *(void **)(work + 0x690);
        func_0034f2e0(sprite, position.x + 41.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        func_0034f2e0(*(void **)(work + 0x680), position.x, position.y, palette->r, palette->g, palette->b, opacity);
        func_0034f2e0(*(void **)(work + 0x67C), position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], opacity);
        position.x = 302.0f + (originX + *(f32 *)(work + 0x3B8));
        position.y = -13.0f + (79.0f + (originY + *(f32 *)(work + 0x3BC)));
        opacity = (u8)((f32)*(u8 *)(work + 0x3C2) * opacityScale);
        palette = (PaletteColor *)D_0064B300;
        sprite = *(void **)(work + 0x694);
        offsetY = position.y + 11.0f;
        func_0034f2e0(sprite, position.x - 157.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sprite = *(void **)(work + 0x698);
        func_0034f2e0(sprite, position.x + 255.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        func_0034f2e0(*(void **)(work + 0x688), position.x, position.y, palette->r, palette->g, palette->b, opacity);
        func_0034f2e0(*(void **)(work + 0x684), position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], opacity);
        /* Preserve the unrounded scrollbar origin across all three draws. */
        offsetX = 583.0f + (*(f32 *)(work + 0x5C8) + (originX + *(f32 *)(work + 0x328)));
        offsetY = (-13.0f + (132.0f + (*(f32 *)(work + 0x5CC) + (originY + *(f32 *)(work + 0x32C))))) - 17.0f;
        opacity = (u8)((f32)*(u8 *)(work + 0x332) * opacityScale);
        position.x = offsetX;
        position.y = offsetY;
        func_0034f2e0(*(void **)(work + 0x6F0), position.x, position.y, 0xFF, 0xFF, 0xFF, opacity);
        position.x = offsetX;
        position.y = offsetY + 165.0f;
        func_0034f2e0(*(void **)(work + 0x6F4), position.x, position.y, 0xFF, 0xFF, 0xFF, opacity);
        position.x = offsetX;
        position.y = offsetY + 3.0f;
        position.y += (f32)((s32)(*(s16 *)(work + 0x2C) * 0x86) / (s32)(*(s32 *)(work + 0x38) - 6));
        palette = (PaletteColor *)D_0064B2E8;
        func_0034f2e0(*(void **)(work + 0x6EC), position.x, position.y, palette->r, palette->g, palette->b, opacity);
        for (column = 0; column < 6; column++) {
            if ((*(s16 *)(work + 0x2C) + column) < *(s32 *)(work + 0x38)) {
                func_00361d20(column, work);
            }
        }
        offsetX = originX + *(f32 *)(work + 0x598);
        offsetY = originY + *(f32 *)(work + 0x59C);
        opacity = (u8)((f32)*(u8 *)(work + 0x5A2) * opacityScale);
        rectangle.integer[0] = (s32)(73.0f + offsetX);
        rectangle.integer[1] = (s32)(297.0f + offsetY);
        rectangle.integer[2] = 0x241;
        rectangle.integer[3] = 0x55;
        colorBytes[0] = D_0064B2E8[0];
        colorBytes[1] = D_0064B2E8[1];
        colorBytes[2] = D_0064B2E8[2];
        colorBytes[3] = opacity;
        D_00887300[0](1, 0);
        func_0045d6e0(colorBytes, rectangle.transport, 0.0f, 0);
        position.x = 212.0f + offsetX;
        position.y = (304.0f + offsetY) - 5.0f;
        itemIndex = (s32)(*(s16 *)(work + 0x2A) + *(s16 *)(work + 0x2C));
        if (datGetFlag(itemIndex + 0x100) != 0) {
            if (datGetFlag(itemIndex + 0x140) != 0) {
                textColor = (opacity | 0xADADAD00);
            } else {
                textColor = (opacity | ~0xFF);
            }
            displayItem = itemIndex + 1;
        } else {
            textColor = (opacity | 0xADADAD00);
            displayItem = 0;
        }
        func_002bc7a0(displayItem, (f32)(s32)position.x, (f32)(s32)position.y, 0.0f, textColor, 1, 8, 8);
        if (*(s32 *)(work + 0x1C) & 8) {
            position.x = 85.0f + (originX + *(f32 *)(work + 0x388));
            position.y = 325.0f + (originY + *(f32 *)(work + 0x38C));
            opacity = (u8)((f32)*(u8 *)(work + 0x392) * opacityScale);
            func_0034f2e0(*(void **)(work + 0x6E4), position.x, position.y, 0xFF, 0xE9, 0x2C, opacity);
        }
        position.x = 640.0f + (originX + *(f32 *)(work + 0x568));
        position.y = 400.0f + (originY + *(f32 *)(work + 0x56C));
        opacity = (u8)((f32)*(u8 *)(work + 0x572) * opacityScale);
        func_0034f9d0(position, 0.0f, opacity, *(s16 *)(work + 0x34), *(s32 *)(work + 0x700));
    }
}
#pragma pop
