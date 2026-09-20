typedef signed __int128 s128;
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
extern f32 fGpffff9cA0;
extern f32 fGpffff9cA4;
extern s128 D_005E5740;
extern s128 D_005E5750;
extern s32 func_00366c70(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb, s32 alpha, s32 mode, s16 centerX, s16 centerY, void *matrix, s32 texture, void *uv);
extern f32 fGpffff84a4;
extern u8 iGpffffb1d8;
extern u8 iGpffffb1d4;
extern u8 iGpffffb1d0;
extern f32 func_0044b7b0();
extern void func_0045d6e0(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_0045dfd0(void *arg0, void *arg1, f32 fparg0, s32 arg2,
                          s32 arg3, s32 arg4);
extern f32 fGpffff8478;
extern f32 func_0044b610(f32 fparg0);
extern s32 func_0047a510(void *arg0, s32 arg1, void *arg2);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void func_002ab550(void *arg0, void *arg1);
extern void func_00478e70(void *arg0);
static inline s32 code1_0012_stride(s32 index, s32 base)
{
    return index + base;
}
static inline s32 code1_0012_stride_loop(s32 base, s32 index)
{
    return base + index;
}

extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);

extern void func_00264d90();
extern s32 D_00796670[];
extern u8 D_005E50D0[];
extern u8 D_005E5870[];
extern s32 func_0046a770(void *arg0);
extern void func_001238c0(s32 arg0);

extern void func_00267570();

extern s32 iGpffffb1e0;
extern s32 iGpffffb1e8;
extern s32 iGpffffb1cc;
extern s32 iGpffff9c58;
extern void func_00103a60(void);

extern s32 func_00121af0(u8 *task);
extern u8 *func_00460990(void);
extern void func_00460ac0(char *name, u8 *task);
extern void func_001221a0(void *arg0, u8 *arg1);
extern void func_00122a40(void *arg0, u8 *arg1);
extern char D_00796340[];
extern char D_00795F50[];
extern s64 func_001060b0(void);
extern s32 func_001060c0(void);
extern s32 func_00110850(s16 arg0, s16 arg1);
extern s32 func_0015a160(void);
extern s32 func_0028b650(void);
extern s32 iGpffffb1c8;
extern s32 func_001060d0(void);
extern s32 func_001060e0(void);
extern s32 func_001060f0(void);
extern void func_00106300();
extern void func_00106310();
extern void func_00106320();
extern s32 func_00110d30();
extern void func_00260450(void);
extern s16 func_00123810(void);
extern s16 func_00123830(void);
extern void func_00123850(void);
extern s32 func_00268990(s32 arg0);
extern void func_00103b00(void);
extern void func_0046a340(s32 arg0);
extern void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern s32 func_00453dc0(void *arg0);
extern u16 D_008C024E[];
extern void func_00442088(void *arg0, const char *arg1, ...);
extern s32 func_00455f70(void *arg0, s32 *arg1);
extern u8 *func_00477f10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_004782b0(void *arg0);
extern u8 D_005E5560[];
extern u8 D_005E5570[];
extern void func_00111bc0(void);
extern s32 func_0025e800(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0025e8b0(s32 arg0);
extern s32 func_0025e8f0(s32 arg0);
extern s32 func_002aa300(u8 *arg0, s32 arg1);
extern s32 func_002aa3f0(void);
extern s32 func_0012dea0(u8 *arg0, s32 arg1);
extern void func_0046d280(void *node);
extern void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 z, s32 arg6);
extern s32 func_0034c210(void);


typedef struct {
    u8 pad0[0x18];
    s32 field_18;
} B810Obj;

extern s32 func_00452490();
extern void *func_00452560();
extern void func_00452080();

typedef struct {
    u8 pad0[4];
    s32 field_4;
} C1A0Obj;
typedef struct {
    f32 x;
    f32 y;
} SVec2_0012;



extern void func_003ef3a0(void *arg0);
extern void func_001437b0(void *arg0, s32 arg1, s32 arg2);
extern void func_0034f5d0(u8 *arg0);
extern s32 func_0044ea90(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005E57B8[];
extern u8 D_005E57D0[];
extern s32 func_0012c220(u8 *arg0);
extern void func_0012e9d0(u8 *arg0);
extern void func_0012fdf0(u8 *arg0);
extern void func_0012feb0(u8 *arg0);
extern s32 func_001228c0(u8 *task);
extern u8 *iGpffffb1dc;
extern s32 func_00123b70(u8 *arg0);
extern u8 D_005E5170[];
extern u8 D_005E5180[];
extern u8 D_005E5190[];
extern u8 D_005E51A0[];
extern u8 D_005E51B0[];
extern void func_00123d50(u8 *arg0);
extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern void func_0046d730(const void *file, s32 line);
extern u8 D_005E5548[];
extern s32 func_00106600(s16 id);
extern u8 D_005E76C8[];
extern u8 D_005E5720[];
extern s32 func_0012aa70(u8 *arg0);
extern void func_0012b660(u8 *task);
extern void func_0025f230(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_004598e0(s32 arg0);
extern void func_004787e0(s32 arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s16 func_00353b50(void *arg0);
extern s32 func_0046d200(void *arg0, s32 arg1);
extern u8 D_005E5F40[];
extern u8 D_005E7670[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern s32 func_00106330(s32 arg0);
extern u8 D_005E5810[];
extern s32 D_005E5B60[];
extern u8 D_005E5BB8[];
extern u8 D_005E76C8[];
extern void func_0012e7c0(u8 *arg0);
extern s32 func_0012ff60(u8 *arg0, u32 arg1);
/* measured: func_001203a0 obj 1824B window 1856B (32B short, 1.7% within 3%), 382 reloc-masked differing words; fnalign retail 463 instrs object 456 instrs (7 short); frame -0xD0 vs -0x100, missing swc1 f23 save, sd/mov park order, s-reg coloring (s5/s3, s0/s2, s7/fp) + f22/f21 vs f12/f13 + stack offsets (0xE0 vs 0xB8 etc.); arg-setup float-first (00275020/00120ae0/0046d4c0) + u32 color unions + s32 D/C via cvt kept; opt_propagation+opt_common_subs off gives 382 (vs 398 single-inner, 397 both-inners, 400 flat); no slti/slt levers in retail; best honest exact-size draft, parked as compiler floor. Width 2026-09-17: 24 dsll/dsra pairs are s16-temp vs s32-callee tension; temp_18 s16->s32 400 worse, 0010d620 s16->s32 390 worse; keep s16, allocation wall. */
// FUN_001203A0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma opt_common_subs off
void func_001203a0(s64 arg0, s8 arg1, u8 *arg2, s32 arg3, s32 arg4, f32 fparg0)
{
    extern s32 func_0046a770(void *arg0);
    extern void func_0046d730(const void *file, s32 line);
    extern u8 *func_0010d620(s16 arg0);
    extern u8 *func_0010d6d0(s16 arg0);
    extern int func_00275020(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int charWidth);
    extern u32 func_00104ce0(s32 arg0);
    extern u32 func_00104dc0(s32 arg0);
    extern u32 func_00104d50(s32 arg0);
    extern u32 func_00104e30(s32 arg0);
    extern void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 z, s32 arg6);
    extern void func_0046d2b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, f32 z, s32 arg3);
    extern void func_0045d6e0(void *arg0, void *arg1, f32 fparg0, s32 arg2);
    extern void func_00120ae0(s64 arg0, f32 fparg0, s32 arg1, u32 arg2, s32 arg3);
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern u8 D_005E4F88[];
    union { u32 w; u8 b[4]; } colFC, colF4, colF0;
    u8 blkF8[4];
    f32 spEC;
    f32 spE8;
    s32 spDC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    s64 spB8;
    s32 var_19;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f23;
    s16 temp_18;
    s16 temp_3;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_19;
    s32 temp_20;
    s32 temp_21;
    u8 *temp_str;
    s32 temp_lo;
    s32 temp_4;
    u32 temp_6;
    u32 temp_6_2;
    u32 temp_6_3;
    u32 temp_6_4;

    spB8 = arg0;
    temp_21 = func_0046a770(D_005E5830);
    temp_20 = func_0046a770(D_005E5850);
    if (temp_21 == 0) {
        func_0046d730(D_005E4F88, 0xB1);
    }
    if (temp_20 == 0) {
        func_0046d730(D_005E4F88, 0xB2);
    }
    temp_18 = *(s16 *)arg2;
    temp_3 = *(s16 *)(arg2 + 6);
    switch (temp_3) {
    case 0:
        var_19 = 6;
        colFC.b[0] = 0xEC; colFC.b[1] = 0x7C; colFC.b[2] = 0;
        break;
    case 1:
        var_19 = 7;
        colFC.b[0] = 0x2D; colFC.b[1] = 0x2D; colFC.b[2] = 0x2D;
        break;
    case 2:
        var_19 = 6;
        colFC.b[0] = 0xEC; colFC.b[1] = 0x7C; colFC.b[2] = 0;
        break;
    default:
        var_19 = 6;
        colFC.b[0] = 0xFF; colFC.b[1] = 0xFF; colFC.b[2] = 0x81;
        break;
    }
    colFC.b[3] = (u8)arg1;
    spE8 = *((f32 *)&spB8);
    spEC = *((f32 *)&spB8 + 1);
    if (*(s32 *)(arg2 + 8) == 3) {
        spEC = *((f32 *)&spB8 + 1) - 5.0f;
    }
    temp_17 = arg1 & 0xFF;
    if (arg4 != 0) {
        temp_str = func_0010d620(temp_18);
    } else {
        temp_str = func_0010d6d0(temp_18);
    }
    func_00275020(spE8, spEC, 0.0f, temp_17 | ~0xFF, (s8)var_19, 1, (const char *)temp_str, 0, -1);
    temp_6 = func_00104ce0(temp_18) & 0xFFFF;
    temp_f20 = 30.0f + *((f32 *)&spB8);
    spE8 = temp_f20;
    spEC = 27.0f + *((f32 *)&spB8 + 1);
    func_00120ae0(*((s64 *)&spE8), fparg0, (s32)colFC.w, temp_6, temp_21);
    if (arg3 != 0) {
        temp_f12 = 52.0f + *((f32 *)&spB8);
        spE8 = temp_f12;
        temp_f23 = 27.0f + *((f32 *)&spB8 + 1);
        spEC = temp_f23;
        func_0046d4c0(0, temp_20, 0x3D, temp_f12, temp_f23, (0xFF - temp_17) & 0xFF, 0xFF, 0xA2, 0, fparg0, 0);
        spE8 = 103.0f + *((f32 *)&spB8);
        spEC = temp_f23;
        temp_6_2 = func_00104dc0(temp_18) & 0xFFFF;
        colF4.b[0] = 0xFB; colF4.b[1] = 0xA2; colF4.b[2] = 0; colF4.b[3] = (u8)arg1;
        func_00120ae0(*((s64 *)&spE8), fparg0, (s32)colF4.w, temp_6_2, temp_21);
        spE8 = 123.0f + *((f32 *)&spB8);
        spEC = 31.0f + *((f32 *)&spB8 + 1);
    } else {
        spE8 = 49.0f + *((f32 *)&spB8);
        spEC = 30.0f + *((f32 *)&spB8 + 1);
    }
    temp_17_2 = 0xFF - (arg1 & 0xFF);
    func_0046d2b0(0, temp_21, 0x4B, spE8, spEC, temp_17_2 & 0xFF, fparg0, 0);
    func_0046d2b0(0, temp_21, 0x4C, spE8, spEC, temp_17_2 & 0xFF, fparg0, 0);
    temp_19 = func_00104ce0(temp_18) & 0xFFFF;
    temp_4 = func_00104dc0(temp_18) & 0xFFFF;
    temp_lo = (s32)((temp_4 - (temp_19 & 0xFFFF)) * 0x58) / temp_4;
    spD8 = temp_lo;
    spDC = 6;
    spD0 = (s32)((95.0f + spE8) - (f32)temp_lo);
    spD4 = (s32)(4.0f + spEC);
    blkF8[0] = 0x2D; blkF8[1] = 0x2D; blkF8[2] = 0x2D; blkF8[3] = (u8)arg1;
    {
        s32 blkD[4];
        blkD[0] = spD0; blkD[1] = spD4; blkD[2] = spD8; blkD[3] = spDC;
        func_0045d6e0(blkF8, blkD, 0.0f, 1);
    }
    temp_6_3 = func_00104d50(temp_18) & 0xFFFF;
    spE8 = temp_f20;
    spEC = 43.0f + *((f32 *)&spB8 + 1);
    func_00120ae0(*((s64 *)&spE8), fparg0, (s32)colFC.w, temp_6_3, temp_21);
    if (arg3 != 0) {
        temp_f12_2 = 52.0f + *((f32 *)&spB8);
        spE8 = temp_f12_2;
        temp_f20_2 = 43.0f + *((f32 *)&spB8 + 1);
        spEC = temp_f20_2;
        func_0046d4c0(0, temp_20, 0x3D, temp_f12_2, temp_f20_2, temp_17_2 & 0xFF, 0xFF, 0xA2, 0, fparg0, 0);
        spE8 = 103.0f + *((f32 *)&spB8);
        spEC = temp_f20_2;
        temp_6_4 = func_00104e30(temp_18) & 0xFFFF;
        colF0.b[0] = 0xFB; colF0.b[1] = 0xA2; colF0.b[2] = 0; colF0.b[3] = (u8)arg1;
        func_00120ae0(*((s64 *)&spE8), fparg0, (s32)colF0.w, temp_6_4, temp_21);
        spE8 = 123.0f + *((f32 *)&spB8);
        spEC = 42.0f + *((f32 *)&spB8 + 1);
    } else {
        spE8 = 49.0f + *((f32 *)&spB8);
        spEC = 41.0f + *((f32 *)&spB8 + 1);
    }
    temp_17_3 = 0xFF - (arg1 & 0xFF);
    func_0046d2b0(0, temp_21, 0x4B, spE8, spEC, temp_17_3 & 0xFF, fparg0, 0);
    func_0046d2b0(0, temp_21, 0x4D, spE8, spEC, temp_17_3 & 0xFF, fparg0, 0);
    {
        s32 t19 = func_00104ce0(temp_18) & 0xFFFF;
        s32 t4 = func_00104dc0(temp_18) & 0xFFFF;
        s32 tlo = (s32)((t4 - (t19 & 0xFFFF)) * 0x58) / t4;
        spC8 = tlo;
        spCC = 6;
        spC0 = (s32)((95.0f + spE8) - (f32)tlo);
        spC4 = (s32)(4.0f + spEC);
    }
    blkF8[0] = 0x2D; blkF8[1] = 0x2D; blkF8[2] = 0x2D; blkF8[3] = (u8)arg1;
    func_0045d6e0(blkF8, &spC0, 0.0f, 1);
}

#pragma opt_common_subs on
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001203a0);
#endif
// FUN_00120AE0
void func_00120ae0(s64 arg0, f32 fparg0, s32 arg1, u32 arg2, s32 arg3)
{
    s32 temp_alpha;
    u32 var_20;
    s32 temp_arg3;
    u8 temp_byte2;
    u8 temp_byte1;
    s32 sp7C;

    sp7C = arg1;
    var_20 = arg2;
    temp_arg3 = arg3;
    temp_byte2 = *((u8 *)&sp7C + 2);
    temp_byte1 = *((u8 *)&sp7C + 1);
    temp_alpha = 0xFF;
    temp_alpha -= *((u8 *)&sp7C + 3);
    do {
        func_0046d4c0(0, temp_arg3, (var_20 % 10U) + 9,
                      *((f32 *)&arg0), *((f32 *)&arg0 + 1),
                      temp_alpha & 0xFF, *((u8 *)&sp7C), temp_byte1,
                      temp_byte2, fparg0, 0);
        *((f32 *)&arg0) = *((f32 *)&arg0) - 16.0f;
        var_20 = var_20 / 10U;
    } while (var_20 != 0);
}
// FUN_00120EE0
s32 func_00120ee0(void *arg0)
{
    return *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38)) == 2;
}
// FUN_00120F00
void func_00120f00(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x14) = 1;
}
// FUN_00120F20
void func_00120f20(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x10) = 1;
}
// FUN_00120F40
void func_00120f40(u8 *arg0, s64 arg1)
{
    SVec2_0012 sp8;
    u8 *temp_3;
    *(s64 *)&sp8 = arg1;
    temp_3 = *(u8 **)(arg0 + 0x38);
    *(SVec2_0012 *)(temp_3 + 0x1C) = sp8;
}
// FUN_00120F70
s32 func_00120f70(u8 *arg0) {
    s32 *temp_16;
    s32 temp_3;

    temp_16 = *(s32 **)(arg0 + 0x38);
    temp_3 = *temp_16;
    switch (temp_3) {
    case 0:
        *temp_16 = 2;
    case 2:
        if ((iGpffffb1c8 == 0) && (func_001060f0() != 0)) {
            func_00106100(func_001060d0());
            func_001062f0(func_001060e0());
            func_00106320(0);
        }
        if ((func_001060c0() & 0xFF) == 5) {
            func_00106300((s64)(s16)((s16)func_001060b0() + 1));
            func_00106310(0);
        } else if (func_00110d30(
                       (s64)(s16)func_001060b0()) == 0) {
            func_00106300(func_001060b0());
            func_00106310(((func_001060c0() & 0xFF) + 1) & 0xFF);
        } else {
            func_00106300(func_001060b0());
            if ((func_001060c0() & 0xFF) == 0) {
                func_00106310(3);
            } else if ((func_001060c0() & 0xFF) == 3) {
                func_00106310(5);
            } else {
                func_00106310(((func_001060c0() & 0xFF) + 1) & 0xFF);
            }
        }
        func_00106320(1);
        *temp_16 = 3;
    case 3:
        func_00260450();
        return -1;
    default:
        return 0;
    }
}
// FUN_00121170
void func_00121170(u8 *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B0 = 0;
    jtbl_008873EC[0](p);
}



// FUN_001211A0
s32 func_001211a0(u8 *unusedTask)
{
    return 0;
}

// FUN_00121AF0
s32 func_00121af0(u8 *unusedTask)
{
    func_00103b00();
    return 0;
}
// FUN_00121B20
void func_00121b20(void) {
    func_00103a60();
    func_00451de0((const void *)(&iGpffff9c58), 0xF, 0, 0, func_00121af0, 0, (u8 *)(0));
}

// FUN_00121B70
s32 func_00121b70(u8 *unusedTask) {
    extern s32 func_00122820(s32 arg0, s32 arg1);
    extern s32 func_00122860(s32 arg0, s32 arg1);
    extern s32 func_00123810(void);
    extern s32 func_00123830(void);
    extern void func_00123850(void);
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = (u8 *)iGpffffb1cc;
    temp_2 = *(u32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        *(s32 *)(temp_16 + 0x14) = 0;
        break;
    case 1:
        *(s32 *)(temp_16 + 0x10) = 1;
        *(u32 *)(temp_16 + 0) = 2;
        break;
    case 2:
        *(s32 *)(temp_16 + 0x10) = 1;
        temp_2_2 = *(s32 *)(temp_16 + 0xC) + 1;
        *(s32 *)(temp_16 + 0xC) = temp_2_2;
        temp_3 = *(s32 *)(temp_16 + 8);
        if (temp_2_2 >= temp_3) {
            *(s32 *)(temp_16 + 0xC) = temp_3;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    case 3:
        *(s32 *)(temp_16 + 0x10) = 1;
        if (*(s32 *)(temp_16 + 0x14) != 0) {
            *(u32 *)(temp_16 + 0) = 6;
        } else if ((*(s32 *)(temp_16 + 4) == 4) &&
                   (*(s32 *)(temp_16 + 0x18) != 0)) {
            *(s32 *)(temp_16 + 0x1C) = func_00268990(0);
            *(u32 *)(temp_16 + 0) = 7;
            *(s32 *)(temp_16 + 0x18) = 0;
        }
        break;
    case 4:
        *(s32 *)(temp_16 + 0x10) = 1;
        *(u32 *)(temp_16 + 0) = 5;
        break;
    case 5:
        *(s32 *)(temp_16 + 0x10) = 1;
        temp_2_3 = *(s32 *)(temp_16 + 0xC) - 1;
        *(s32 *)(temp_16 + 0xC) = temp_2_3;
        if (temp_2_3 <= 0) {
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 0xC) = 0;
            *(u32 *)(temp_16 + 0) = 0;
        }
        break;
    case 6:
        temp_17 = func_00123830();
        temp_18 = func_00123810();
        func_00123850();
        temp_19 = func_00123830();
        temp_2_4 = func_00123810();
        if (temp_17 != temp_19) {
            *(s32 *)(temp_16 + 0x1C) = func_00122820(temp_17, temp_19);
            *(u32 *)(temp_16 + 0) = 7;
        } else if (temp_18 != temp_2_4) {
            *(s32 *)(temp_16 + 0x1C) = func_00122860(temp_18, temp_2_4);
            *(u32 *)(temp_16 + 0) = 7;
        } else {
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    case 7:
        if (func_004522d0(*(s32 *)(temp_16 + 0x1C)) == 3) {
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u32 *)(temp_16 + 0) = 3;
        }
        break;
    }
    return 0;
}
// FUN_00121DB0
void func_00121db0(u8 *unusedTask)
{
    jtbl_008873EC[0]((void *)iGpffffb1cc);
    iGpffffb1cc = 0;
}
typedef struct {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    u8 pad10[0xC];
    u8 c1c;
    u8 c1d;
    u8 c1e;
    u8 c1f;
} Frame00121DE0;
// FUN_00121DE0
void func_00121de0(void)
{
    extern f32 func_0044b7b0(void *arg0, f32 arg1);
    Frame00121DE0 sp;
    u8 *temp_4;
    s32 temp_3;
    s32 var_16;
    s32 var_2;
    f32 result;
    f32 high_temp;
    f32 ratio;

    temp_4 = (u8 *)iGpffffb1cc;
    if (temp_4 != NULL) {
        temp_3 = *(s32 *)(temp_4 + 8);
        if (*(s32 *)temp_4 >= 4) {
            ratio = (fGpffff84a4 * (f32)*(s32 *)(temp_4 + 0xC)) / (f32)temp_3;
            result = func_0044b7b0(temp_4, ratio);
            high_temp = 640.0f - (640.0f * result);
            var_16 = (s32)high_temp;
            var_2 = 0x280;
        } else {
            var_16 = 0;
            ratio = (fGpffff84a4 * (f32)*(s32 *)(temp_4 + 0xC)) / (f32)temp_3;
            result = func_0044b7b0(temp_4, ratio);
            var_2 = (s32)(640.0f * result);
        }
        sp.s0 = var_16;
        sp.s1 = 0;
        sp.s2 = var_2 - var_16;
        sp.s3 = 0x1E0;
        sp.c1f = 0xFF;
        sp.c1c = iGpffffb1d8;
        sp.c1d = iGpffffb1d4;
        sp.c1e = iGpffffb1d0;
        func_0045d6e0(&sp.c1c, &sp.s0, 0.0f, 1);
    }
}
// FUN_00121F20
void func_00121f20(void)
{
    typedef struct {
        f32 p0;
        f32 p1;
        f32 p2;
        f32 p3;
    } Code1Point4;
    typedef struct {
        f32 p0;
        f32 p1;
    } Code1Point2;
    typedef struct {
        u8 c0;
        u8 c1;
        u8 c2;
        u8 c3;
    } Code1Color4;
    extern f32 func_0044b7b0(f32 fparg0);
    Code1Point4 points[0x25];
    Code1Point2 quad[4];
    Code1Color4 color[4];
    u8 *temp_6;
    Code1Point4 *point;
    f32 result;
    f32 angle;
    f32 scale;
    f32 x;
    f32 sine;
    f32 cosine;
    s32 i;

    temp_6 = (u8 *)iGpffffb1cc;
    if (temp_6 != NULL) {
        color[0].c3 = 0xFF;
        color[0].c0 = iGpffffb1d8;
        color[0].c1 = iGpffffb1d4;
        color[0].c2 = iGpffffb1d0;
        color[3] = color[0];
        color[2] = color[3];
        color[1] = color[2];
        result = func_0044b7b0(
            (fGpffff84a4 * (f32)*(s32 *)(temp_6 + 0xC)) /
            (f32)*(s32 *)(temp_6 + 8));
        scale = 600.0f - (600.0f * result);
        angle = 0.0f;
        i = 0;
        while (i < 0x25) {
            x = fGpffff8478 * angle;
            sine = func_0044b610(x);
            cosine = func_0044b7b0(x);
            point = &points[i];
            point->p0 = ((scale * sine * 1066.0f) / 1000.0f) + 320.0f;
            point->p1 = (scale * cosine) + 224.0f;
            point->p2 = ((sine * 600.0f * 1066.0f) / 1000.0f) + 320.0f;
            point->p3 = (cosine * 600.0f) + 224.0f;
            angle += 10.0f;
            i++;
        }
        i = 0;
        while (i < 0x24) {
            point = &points[i];
            quad[0] = *(Code1Point2 *)point;
            quad[1] = *(Code1Point2 *)((u8 *)point + 8);
            quad[2] = *(Code1Point2 *)(point + 1);
            quad[3] = *(Code1Point2 *)((u8 *)(point + 1) + 8);
            func_0045dfd0(color, quad, 0.0f, 4, 4, 1);
            i++;
        }
    }
}
// FUN_001221A0
/* measured: opt_propagation off preserves the single hoisted D_00887300 base
   used by retail across this callback's state setup sequence. */
#pragma opt_propagation off
void func_001221a0(void *arg0, u8 *arg1)
{
    typedef struct {
        s32 s0;
        s32 s1;
        s32 s2;
        s32 s3;
        u8 pad10[8];
        u8 c1c;
        u8 c1d;
        u8 c1e;
        u8 c1f;
    } Frame001221A0;
    extern s32 (*D_00887304[])(s32 arg0, void *arg1);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    Frame001221A0 sp;
    void (**base)(s32 arg0, s32 arg1);
    s32 result;
    s32 state;
    s32 alpha;

    if ((*(u32 *)(arg1 + 0x10) & 1) != 0) {
        D_00887304[0](0xE, &result);
        base = D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](7, 2);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        base[0](0xB, 6);
        base[0](0xA, 5);
        base[0](2, 4);
        base[0](0xE, 0);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
        state = *(s32 *)(arg1 + 4);
        if (state == 3)
            goto state3;
        if (state == 2)
            goto state2;
        if (state == 4)
            goto draw;
        if (state == 1)
            goto draw;
        if (state == 0 || state != 0)
            goto done;
        goto done;
    draw:
        if (iGpffffb1cc != 0) {
            alpha = ((*(s32 *)(iGpffffb1cc + 0xC) * 0xFF) /
                     *(s32 *)(iGpffffb1cc + 8));
            sp.s0 = 0;
            sp.s1 = 0;
            sp.s2 = 0x280;
            sp.s3 = 0x1E0;
            sp.c1f = (u8)alpha;
            sp.c1c = iGpffffb1d8;
            sp.c1d = iGpffffb1d4;
            sp.c1e = iGpffffb1d0;
            func_0045d6e0(&sp.c1c, &sp.s0, 0.0f, 1);
        }
        goto done;
    state2:
        func_00121de0();
        goto done;
    state3:
        func_00121f20();
    done:
        base[0](0xE, result);
    }
}
/* measured: closes the opt_propagation bracket for func_001221a0. */
#pragma opt_propagation on
// FUN_001223D0
s32 func_001223d0(u8 *unusedTask) {
    u8 *p;
    s32 x;

    p = func_00460990();
    x = iGpffffb1cc;
    if (x == 0) {
        return 0;
    }
    *(void **)(p + 8) = (void *)func_001221a0;
    *(s32 *)(p + 0x10) = x;
    func_00460ac0(D_00796340, p);
    return 0;
}

// FUN_00122720
/* The case values come from decoding the jump table at 0x007466C0 with
   tools/jtbl.py: entry 0 returns 1, entries 1/2/4/5 share one body returning
   0, entry 3 returns 2, and anything >= 6 falls through to the default 1.
   The labels are declared in that object order because b210 lays case bodies
   out in declaration order. */
s32 func_00122720(void) {
    s32 *state;

    state = (s32 *)iGpffffb1cc;
    if (state == NULL) {
        return 1;
    }
    switch ((u32)state[0]) {
    case 0:
        return 1;
    case 1:
    case 2:
    case 4:
    case 5:
        return 0;
    case 3:
        return 2;
    }
    return 1;
}

// FUN_001227A0
s32 func_001227a0(void)
{
    if (iGpffffb1cc == 0) {
        return 1;
    }
    return *(s32 *)(iGpffffb1cc + 4);
}
// FUN_001227D0
void func_001227d0(void)
{
    if (iGpffffb1cc != 0) {
        *(s32 *)(iGpffffb1cc + 0x14) = 1;
    }
}
// FUN_001227F0
s32 func_001227f0(void)
{
    s32 result;
    u8 *temp_3;
    result = 1;
    temp_3 = (u8 *)iGpffffb1cc;
    if (temp_3 == NULL)
        return 1;
    if (*(s32 *)(temp_3 + 0x14) != 0)
        result = 0;
    return result;
}
// FUN_00122820
void func_00122820(s32 arg0, s32 arg1)
{
    func_00264d90(0, arg0, arg1, D_00796670);
}



// FUN_00122860
void func_00122860(s32 arg0, s32 arg1)
{
    func_00267570(0, arg0, arg1, D_00796670);
}



// FUN_001228C0
s32 func_001228c0(u8 *unusedTask)
{
    s32 temp_3;
    s32 i;
    u8 *temp_16;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *temp_6;
    u8 *table;

    temp_16 = iGpffffb1dc;
    temp_3 = *(s32 *)(temp_16 + 0);
    switch (temp_3) {
    case 0:
        *(s32 *)(temp_16 + 0x110) = func_0046a770(D_005E5870);
        temp_6 = iGpffffb1dc;
        i = 0;
        table = D_005E50D0;
        while (i < 5) {
            temp_4 = table + (i << 5);
            temp_3_2 = temp_6 + i * 0x30;
            *(f32 *)(temp_3_2 + 0x20) = *(f32 *)(temp_4 + 0);
            *(f32 *)(temp_3_2 + 0x24) = *(f32 *)(temp_4 + 4);
            *(f32 *)(temp_3_2 + 0x28) = *(f32 *)(temp_4 + 8);
            *(f32 *)(temp_3_2 + 0x2C) = *(f32 *)(temp_4 + 0xC);
            *(s32 *)(temp_3_2 + 0x48) = *(s32 *)(temp_4 + 0x14);
            *(s32 *)(temp_3_2 + 0x4C) = *(s32 *)(temp_4 + 0x18);
            *(s8 *)(temp_3_2 + 0x39) = *(s32 *)(temp_4 + 0x10);
            *(s8 *)(temp_3_2 + 0x38) = 0;
            i++;
        }
        *(s32 *)(temp_6 + 0x10) = 0;
        *(s32 *)(temp_16 + 0) = 1;
        break;
    case 1:
        *(s16 *)(temp_16 + 4) = (s16)func_001060b0();
        *(s16 *)(temp_16 + 6) = func_001060c0() & 0xFF;
        *(s16 *)(temp_16 + 8) =
            (s8)func_00110850(*(s16 *)(temp_16 + 4), *(s16 *)(temp_16 + 6));
        func_001238c0(0);
        *(s32 *)(temp_16 + 0) = 2;
        break;
    case 2:
        break;
    }
    return 0;
}
// FUN_00122A10
void func_00122a10(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
    iGpffffb1dc = 0;
}



/* Floor: 324 differing words, 804 of 804 instructions with all 46
   relocations resolved.  Body at docs/probe_archive/Lane0012_00122a40_body.c;
   production stays ASM.  The declaration of func_00122a40 above is part of
   this measurement - it takes (void *, u8 *), not (void) - and changing it
   is neutral for the rest of the unit. */
/* measured 2026-09-18: reconstructed from a bare marker; banked floor 324
   reloc-masked words at 804/804 instructions (3216B emitted into a 3232B
   window whose last 16 bytes are zero padding), 89 fnalign edits plus 4
   reloc-only, all 46 relocations resolved.  No jump table in retail - the
   two apparent switches are two-case q-remaps.  Both pragmas are load
   bearing and scoped.  Residual: the nested `14.0f + (int + field)` FPR
   colouring, the alpha GPR temporary, the 0x19 sharing, q polarity and the
   tail conversion shape. */
/* composition 2026-09-20: exact 804/804 is cancellation (INS 12 / DEL 3, replaces -9). */
/* Surplus 12 is repeated lwc1 $f1,0x90/0xf0 reloads (O294,411,445,480,509,511,686,711,743,768 etc) */
/* + addiu 0xFF reloads where retail keeps $f1/$t0 live; shortfall 3 is R606:609 b/nop/addiu */
/* $s1,0x1c tail of second q-remap where object falls through. Tail ival/2 bgez + round-trip */
/* cvt is +3 in one place but net is many smalls, no single 12-block; removing 12 alone */
/* lands 792 (worse), so not banked. Anchor is retail listing per site, not edit count. */
// FUN_00122A40 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma opt_common_subs off
void func_00122a40(void *arg0, u8 *arg1)
{
    extern s32 (*D_00887304[])(s32 arg0, void *arg1);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, f32 z, s32 arg4);
    extern f32 func_0046b2f0(u8 *arg0);
    extern void func_0046b380(u8 *arg0, s32 arg1);
    extern void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2);
    extern s32 func_00110580(s32 arg0);
    extern s32 func_00110d30(s32 arg0);
    extern s32 func_003f6440(s32 arg0, s32 arg1);
    void (**base)(s32 arg0, s32 arg1);
    u8 *node;
    u8 *obj;
    s32 tmp;
    s32 ratio;
    s32 result;
    s32 v;
    s32 w;
    s32 v2;
    s32 i;
    s32 sp68;
    s32 sp64;
    s32 ival;
    s32 q;
    f32 ft1;
    f32 ft2;
    f32 ft3;
    f32 ft4;
    obj = arg1;
    node = (u8 *)0;
    D_00887304[0](0xE, &result);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](7, 2);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](0xB, 6);
    base[0](0xA, 5);
    base[0](2, 4);
    base[0](0xE, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    if ((*(s32 *)(obj + 0xC) & 1) != 0) {
        if (*(s32 *)(obj + 0x14) != 0) {
            tmp = *(s32 *)(obj + 0x10);
            if (tmp < 0x64) {
                *(s32 *)(obj + 0x10) = tmp + 1;
            }
        } else {
            tmp = *(s32 *)(obj + 0x10);
            if (tmp != 0) {
                *(s32 *)(obj + 0x10) = tmp - 1;
            }
            if (*(s32 *)(obj + 0x10) == 0) {
                *(s32 *)(obj + 0xC) = 0;
            }
        }
        for (i = 0; i < 5; i++) {
            func_001437b0(obj + i * 0x30 + 0x20, *(s32 *)(obj + 0x10), 0);
        }
        v = *(s32 *)(obj + 0x78);
        tmp = *(s32 *)(obj + 0x10);
        if (tmp < v) {
            w = 0;
        } else {
            w = tmp - v;
        }
        v2 = *(s32 *)(obj + 0x7C) - v;
        if (v2 < w) {
            w = v2;
        }
        ratio = (w * 0x90) / v2;
        ft1 = (f32)0x23E;
        func_0046d3b0(0, *(s32 *)(obj + 0x110), 0x25, ft1 + *(f32 *)(obj + 0x30), *(f32 *)(obj + 0x34), 0, (0xFF - *(u8 *)(obj + 0x3A)) & 0xFF, 0.0f, 1);
        if (*(s32 *)(obj + 0x18) != 0) {
            if (*(s32 *)(obj + 0x1C) == 0) {
                node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1D);
            } else {
                node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1E);
            }
        } else if ((func_0015a160() == 0) && (func_0028b650() == 0)) {
            node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1D);
        } else {
            node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), 0x1E);
        }
        *(s32 *)(node + 0x24) = 0;
        ft2 = (f32)0x223;
        *(f32 *)(node + 8) = ft2 + *(f32 *)(obj + 0x60);
        *(f32 *)(node + 0xC) = -33.0f + *(f32 *)(obj + 0x64);
        *(s8 *)(node + 0x10) = (s8)(0xFF - *(u8 *)(obj + 0x6A));
        *(s16 *)(node + 0x1C) = 0x50;
        *(s16 *)(node + 0x1E) = 0x2D;
        *(f32 *)(node + 0x18) = (f32)(0x90 - ratio);
        func_0046b380(node, 1);
        func_0046d280(node);
    }
    if ((*(s32 *)(obj + 0xC) & 2) != 0) {
        func_001104d0(*(s16 *)(obj + 4), &sp68, &sp64);
        tmp = (s32)*(f32 *)(obj + 0x90);
        func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), 7, (f32)(tmp + 0x1C2), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), 8, (f32)(tmp + 0x246), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0x19, 0x19, 0x19, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp68 / 10 + 9, 14.0f + ((f32)0x1CF + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp68 % 10 + 9, 14.0f + (476.0f + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), 0x13, 14.0f + (490.0f + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp64 / 10 + 9, 14.0f + (500.0f + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), sp64 % 10 + 9, 14.0f + ((f32)0x201 + *(f32 *)(obj + 0x90)), 17.0f + *(f32 *)(obj + 0x94), 0, (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0.0f, 1);
        if (func_00110d30(*(s16 *)(obj + 4)) != 0) {
            func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), func_00110580(*(s16 *)(obj + 4)), (f32)0x219 + *(f32 *)(obj + 0x90), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0xFF, 0xAC, 0x99, 0.0f, 1);
        } else if (func_00110580(*(s16 *)(obj + 4)) == 6) {
            func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), func_00110580(*(s16 *)(obj + 4)), (f32)0x219 + *(f32 *)(obj + 0x90), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0x99, 0xA4, 0xFF, 0.0f, 1);
        } else {
            func_0046d4c0((s32)node, *(s32 *)(obj + 0x110), func_00110580(*(s16 *)(obj + 4)), (f32)0x219 + *(f32 *)(obj + 0x90), 17.0f + *(f32 *)(obj + 0x94), (0xFF - *(u8 *)(obj + 0x9A)) & 0xFF, 0xFF, 0xFF, 0xFF, 0.0f, 1);
        }
        v = *(s32 *)(obj + 0xD8);
        tmp = *(s32 *)(obj + 0x10);
        if (tmp < v) {
            w = 0;
        } else {
            w = tmp - v;
        }
        v2 = *(s32 *)(obj + 0xDC) - v;
        if (v2 < w) {
            w = v2;
        }
        ratio = (w << 0xC) / v2;
        if (func_00110d30(*(s16 *)(obj + 4)) != 0) {
            tmp = *(s16 *)(obj + 6);
            if (tmp == 3) {
                q = 0x1A;
            } else {
                q = tmp + 0x14;
            }
        } else {
            q = *(s16 *)(obj + 6) + 0x14;
        }
        if (*(s32 *)(obj + 0x18) != 0) {
            if (*(s32 *)(obj + 0x1C) == 1) {
                if (q == 0x1A) {
                    q = 0x1C;
                } else if (q == 0x18) {
                    q = 0x1B;
                }
            }
        } else if ((func_0015a160() != 0) || (func_0028b650() != 0)) {
            if (q == 0x1A) {
                q = 0x1C;
            } else if (q == 0x18) {
                q = 0x1B;
            }
        }
        node = (u8 *)func_0046d200((void *)*(s32 *)(obj + 0x110), q);
        *(s32 *)(node + 0x24) = 0;
        *(f32 *)(node + 8) = 552.0f + *(f32 *)(obj + 0xC0);
        *(f32 *)(node + 0xC) = 31.0f + *(f32 *)(obj + 0xC4);
        *(s8 *)(node + 0x10) = (s8)(0xFF - *(u8 *)(obj + 0xCA));
        ival = (s32)func_0046b2f0(node);
        *(s16 *)(node + 0x20) = 0xFF6;
        *(s16 *)(node + 0x22) = (s16)ratio;
        *(f32 *)(node + 0xC) = (f32)ival + ((31.0f + *(f32 *)(obj + 0xC4)) - (f32)(s32)(func_0046b2f0(node) / 2.0f + (f32)(ival / 2)));
        func_0046b380(node, 1);
        func_0046d280(node);
    }
    if ((*(s32 *)(obj + 0xC) & 4) != 0) {
        if (*(s32 *)(obj + 0x18) != 0) {
            if (*(s32 *)(obj + 0x1C) == 0) {
                func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), 0x1F, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
                func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), *(s16 *)(obj + 8) + 0x20, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
            }
        } else if ((func_0015a160() == 0) && (func_0028b650() == 0)) {
            func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), 0x1F, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
            func_0046d3b0((s32)node, *(s32 *)(obj + 0x110), *(s16 *)(obj + 8) + 0x20, (f32)0x247 + *(f32 *)(obj + 0xF0), 51.0f + *(f32 *)(obj + 0xF4), 0, (0xFF - *(u8 *)(obj + 0xFA)) & 0xFF, 0.0f, 1);
        }
    }
    base[0](0xE, result);
}
/* measured: closes the opt_propagation bracket. */
#pragma opt_common_subs on
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00122a40);
#endif
// FUN_001236E0
s32 func_001236e0(u8 *unusedTask) {
    u8 *p;
    u8 *q;

    p = func_00460990();
    q = iGpffffb1dc;
    *(void **)(p + 8) = (void *)func_00122a40;
    *(u8 **)(p + 0x10) = q;
    func_00460ac0(D_00795F50, p);
    return 0;
}

// FUN_00123730
s32 func_00123730(s32 arg0)
{
    s32 temp_2;
    s32 temp_2_2;
    func_0044ea90(D_005E5170, 0x179);
    temp_2_2 = (s32)D_008873F4[0](1, 0x114, 0x40000);
    if (temp_2_2 == 0)
        return 0;
    iGpffffb1dc = (u8 *)temp_2_2;
    temp_2 = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005E5180), 0x96, 0, 0, func_001228c0, func_00122a10, (u8 *)((u8 *)temp_2_2));
    (s32)func_00451fc0((void *)(temp_2), (const void *)(D_005E5190), 0x97, 0, 0, func_001236e0, 0, (u8 *)((u8 *)0));
    return temp_2;
}
// FUN_00123810
s16 func_00123810(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = iGpffffb1dc;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 6);
    }
    return var_2;
}



// FUN_00123830
s16 func_00123830(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = iGpffffb1dc;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 4);
    }
    return var_2;
}



/* measured: the named first-field load plus -O1 reproduce retail's argument setup order; exact match nd 0 (obj 104B/window 112B). */
// FUN_00123850
/* measured: opens optimization_level 1 to keep the +6 store and +4 load before the call conversion (nd 0). */
#pragma optimization_level 1
void func_00123850(void) {
    u8 *p;
    s32 t;
    s16 first;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s16 *)(p + 4) = (s16)func_001060b0();
        t = func_001060c0() & 0xFF;
        *(s16 *)(p + 6) = (s16)t;
        first = *(s16 *)(p + 4);
        *(s16 *)(p + 8) = (s8)func_00110850(first, (s16)t);
    }
}
/* measured: closes the optimization_level bracket at the file's -O2 baseline (nd 0). */
#pragma optimization_level 2

// FUN_001238C0
void func_001238c0(s32 arg0)
{
    s32 var_8;
    s32 var_9;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_8;
    u8 *table;

    temp_8 = (u8 *)iGpffffb1dc;
    if (temp_8 != NULL) {
        if (arg0 != 0) {
            *(s32 *)(temp_8 + 0x18) = 0;
        }
        if (*(s32 *)(temp_8 + 0x14) != arg0) {
            *(s32 *)(temp_8 + 0x14) = arg0;
            if (arg0 == 1) {
                temp_7 = (u8 *)iGpffffb1dc;
                var_9 = 0;
                table = D_005E50D0;
                while (var_9 < 5) {
                    temp_5 = table + (var_9 << 5);
                    temp_4 = temp_7 + (var_9 * 0x30);
                    *(f32 *)(temp_4 + 0x20) = *(f32 *)(temp_5 + 0);
                    *(f32 *)(temp_4 + 0x24) = *(f32 *)(temp_5 + 4);
                    *(f32 *)(temp_4 + 0x28) = *(f32 *)(temp_5 + 8);
                    *(f32 *)(temp_4 + 0x2C) = *(f32 *)(temp_5 + 0xC);
                    *(s32 *)(temp_4 + 0x48) = *(s32 *)(temp_5 + 0x14);
                    *(s32 *)(temp_4 + 0x4C) = *(s32 *)(temp_5 + 0x18);
                    *(s8 *)(temp_4 + 0x39) = *(s32 *)(temp_5 + 0x10);
                    *(s8 *)(temp_4 + 0x38) = 0;
                    var_9 += 1;
                }
                *(s32 *)(temp_7 + 0x10) = 0;
                *(s32 *)(temp_8 + 0xC) = 7;
                return;
            }
            temp_7_2 = (u8 *)iGpffffb1dc;
            var_8 = 0;
            table = D_005E50D0;
            while (var_8 < 5) {
                temp_5_2 = table + (var_8 << 5);
                temp_4_2 = temp_7_2 + (var_8 * 0x30);
                *(f32 *)(temp_4_2 + 0x20) = *(f32 *)(temp_5_2 + 0);
                *(f32 *)(temp_4_2 + 0x24) = *(f32 *)(temp_5_2 + 4);
                *(f32 *)(temp_4_2 + 0x28) = *(f32 *)(temp_5_2 + 8);
                *(f32 *)(temp_4_2 + 0x2C) = *(f32 *)(temp_5_2 + 0xC);
                *(s32 *)(temp_4_2 + 0x48) = *(s32 *)(temp_5_2 + 0x14);
                *(s32 *)(temp_4_2 + 0x4C) = *(s32 *)(temp_5_2 + 0x18);
                *(s8 *)(temp_4_2 + 0x39) = *(s32 *)(temp_5_2 + 0x10);
                *(s8 *)(temp_4_2 + 0x38) = 0;
                var_8 += 1;
            }
            *(s32 *)(temp_7_2 + 0x10) = 0x46;
        }
    }
}
// FUN_00123A10
void func_00123a10(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s32 *)(p + 0x18) = 1;
        if (func_0015a160() != 0) {
            goto set1;
        }
        if (func_0028b650() != 0) {
            goto set1;
        }
        *(s32 *)(p + 0x1C) = 0;
        return;
set1:
        *(s32 *)(p + 0x1C) = 1;
    }
}

// FUN_00123A80
void func_00123a80(void)
{
    u8 *temp_3;

    temp_3 = iGpffffb1dc;
    if (temp_3 != NULL) {
        *(s32 *)(temp_3 + 0x14) = 0;
        *(s32 *)(temp_3 + 0xC) = 0;
    }
}



// FUN_00123AA0
void func_00123aa0(s16 arg0) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s16 *)(p + 0xA) = *(s16 *)(p + 8);
        *(s16 *)(p + 8) = arg0;
    }
}
// FUN_00123AC0
void func_00123ac0(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        *(s16 *)(p + 8) = *(s16 *)(p + 0xA);
    }
}
// FUN_00123AE0
s8 func_00123ae0(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        return *(s8 *)(p + 8);
    }
    return -1;
}
// FUN_00123B10
s16 func_00123b10(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        return *(s16 *)(p + 4);
    }
    return -1;
}
// FUN_00123B40
s16 func_00123b40(void) {
    u8 *p;

    p = iGpffffb1dc;
    if (p != NULL) {
        return *(s16 *)(p + 6);
    }
    return -1;
}
// FUN_00123B70
s32 func_00123b70(u8 *arg0)
{
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(u32 *)temp_16;
    switch (temp_2) {
    case 0:
        func_00111bc0();
        *(u32 *)temp_16 = 1;
        goto block_20;
    case 1:
        *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x11);
        *(u32 *)temp_16 = 2;
        goto block_20;
    case 2:
        temp_2_2 = func_0025e8f0(*(s32 *)(temp_16 + 4));
        if (temp_2_2 == 1) {
            *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x12);
            *(u32 *)temp_16 = 4;
        } else if (temp_2_2 == 2) {
            *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x13);
            *(u32 *)temp_16 = 3;
        }
        goto block_20;
    case 3:
        temp_2_3 = func_0025e8f0(*(s32 *)(temp_16 + 4));
        if (temp_2_3 == 1) {
            return -1;
        }
        if (temp_2_3 == 2) {
            *(u32 *)temp_16 = 1;
        }
        goto block_20;
    case 4:
        if (func_0025e8f0(*(s32 *)(temp_16 + 4)) == 1) {
            *(s32 *)(temp_16 + 8) = func_002aa300(arg0, 1);
            *(u32 *)temp_16 = 5;
        }
        goto block_20;
    case 5:
        temp_2_4 = func_002aa3f0();
        if (temp_2_4 == 2) {
            goto case_5_action;
        }
        if (temp_2_4 == 1) {
            goto case_5_error;
        }
        if (temp_2_4 != 0) {
            goto case_5_action;
        }
        goto block_20;
case_5_error:
        return -1;
case_5_action:
        *(s32 *)(temp_16 + 4) = func_0025e800(arg0, 1, 0x13);
        *(u32 *)temp_16 = 3;
        goto block_20;
    default:
        goto block_20;
    }
block_20:
    return 0;
}
// FUN_00123D50
void func_00123d50(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00123D80
s32 func_00123d80(void)
{
    s32 temp_2;
    func_0044ea90(D_005E51A0, 0x84);
    temp_2 = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (temp_2 == 0) {
        temp_2 = 0;
    } else {
        temp_2 = (s32)func_00451fc0((void *)(0), (const void *)(D_005E51B0), 0xF, 0, 0, func_00123b70, func_00123d50, (u8 *)((u8 *)temp_2));
        if (temp_2 == 0)
            temp_2 = 0;
    }
    iGpffffb1e0 = temp_2;
    return 1;
}
// FUN_00123E30
s32 func_00123e30(void)
{
    if (func_004522d0(iGpffffb1e0) == 3) {
        iGpffffb1e0 = 0;
        return 1;
    }
    return 0;
}

// FUN_00123E80
s32 func_00123e80(u8 *arg0)
{
    extern s32 func_00122520(s32 arg0, s32 arg1);
    extern void func_00111050(s32 arg0);
    extern void func_00459880(void);
    extern void func_0045a8d0(s32 arg0, s32 arg1);
    extern s32 func_0012c110(void);
    extern s32 func_0012c1a0(s32 arg0);
    extern s32 func_0046a110(void *arg0, s32 arg1, void *arg2);
    extern void func_00121940(void);
    extern void func_00122640(s32 arg0, s32 arg1);
    extern s32 func_0012b760(void);
    extern s32 func_0012b810(s32 arg0);
    extern s32 iGpffffb1e4;
    extern s32 iGpffffb1f0;

    extern u8 D_007963A0[];
    extern u8 D_0079B698[];
    extern u8 D_0079B69C[];
    extern u8 D_0079B6A0[];
    u8 *temp_16;
    s32 temp_2;
    s16 temp_3;
    typedef struct {
        s16 s20;
        s16 s22;
        s16 s24;
        s16 s26;
        s16 s28;
        u8 pad_short[0x1E];
    } ShortWork;
    typedef struct {
        s32 s48;
        s32 s4C;
    } IntWork;
    ShortWork short_work;
    IntWork int_work;

    temp_16 = *(u8 **)(arg0 + 0x38);
    switch (*(u32 *)temp_16) {
    case 0:
        temp_2 = func_00122720();
        if (temp_2 == 0)
            break;
        switch (temp_2) {
        case 2:
            *(u32 *)temp_16 = 2;
            break;
        default:
            func_00122520(1, 1);
            *(u32 *)temp_16 = 1;
            break;
        }
        break;
    case 1:
        if (func_00122720() != 0) {
            *(u32 *)temp_16 = 2;
        }
        break;
    case 2:
        func_00111050(1);
        func_00459880();
        func_0045a8d0(3, 0);
        *(s32 *)(temp_16 + 0xC) = func_0012c110();
        *(u32 *)temp_16 = 3;
        break;
    case 3:
        if (func_0012c1a0(*(s32 *)(temp_16 + 0xC)) != 0) {
            *(u32 *)temp_16 = 4;
        }
        break;
    case 4:
        if (iGpffffb1e4 == 0) {
            *(s32 *)(temp_16 + 0xC) = func_0046a110(arg0, 0x15, D_007963A0);
        } else {
            *(s32 *)(temp_16 + 0xC) = func_0046a110(arg0, 0x16, D_007963A0);
        }
        iGpffffb1e4 = ~iGpffffb1e4;
        *(u32 *)temp_16 = 5;
        break;
    case 5:
        if (func_00452490(*(s32 *)(temp_16 + 0xC)) != 1) {
            *(u32 *)temp_16 = 6;
        }
        break;
    case 6:
        *(s32 *)(temp_16 + 0xC) = (s32)func_0012b760();
        *(u32 *)temp_16 = 7;
        break;
    case 7:
        temp_2 = func_0012b810(*(s32 *)(temp_16 + 0xC));
        if (temp_2 == 4)
            goto state4;
        if (temp_2 == 3)
            goto state3;
        if (temp_2 == 2)
            goto state2;
        switch (temp_2) {
        case 1:
            goto state1;
        default:
            goto state_done;
        }
    state1:
        *(u32 *)temp_16 = 2;
        goto state_done;
    state2:
        func_001113b0();
        func_00111290();
        func_00123850();
        func_001238c0(1);
        func_001029a0(0x19, 0, 0, 0);
        return -1;
    state3:
        iGpffffb1f0 = 1;
        func_00123850();
        func_001238c0(1);
        temp_3 = (s16)func_001060d0();
        if ((temp_3 == 9) && ((u8)func_001060e0() == 5)) {
            func_001029a0(0x19, 0, 0, 0);
            return -1;
        }
        if (*(s32 *)D_0079B6A0 != 0) {
            int_work.s48 = *(s32 *)D_0079B6A0;
            int_work.s4C = 0xFF;
            func_001029a0(0xB, &int_work, 8, 2);
        } else {
            short_work.s20 = (s16)*(s32 *)D_0079B698;
            short_work.s22 = (s16)*(s32 *)D_0079B69C;
            short_work.s24 = 0xFF;
            short_work.s26 = 0;
            short_work.s28 = 0;
            func_001029a0(9, &short_work, 0x1C, 0);
        }
        goto state_done;
    state4:
        func_001238c0(1);
        func_00121940();
        func_00122640(0, 1);
        *(u32 *)temp_16 = 8;
        goto state_done;
    state_done:
    case 8:
    default:
        break;
    }
    return 0;
}
// FUN_00124210
void func_00124210(u8 *arg0)
{
    func_0046a340(*(s32 *)(arg0 + 0x38));
}
// FUN_00124350
extern s32 func_003b7060(void);
s32 func_00124350(void)
{
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    s32 var_16;
    u32 var_3;
    u32 var_3_2;
    u32 var_3_3;
    u32 var_3_4;
    u32 var_3_5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;

    var_16 = 0;
    if (iGpffffb1e8 > 1) {
        temp_2 = func_003b7060();
        var_f0 = (f32)(u32)temp_2;
        temp_f0 = 100.0f * (var_f0 / 2147483648.0f);
        var_3 = (u32)temp_f0;
        if (var_3 > 0x3B)
            goto block_second;
    }
block_8:
    var_16 = 0;
    goto block_end;
block_second:
    temp_2_2 = func_003b7060();
    var_f0_2 = (f32)(u32)temp_2_2;
    temp_f0_2 = 100.0f * (var_f0_2 / 2147483648.0f);
    var_3_2 = (u32)temp_f0_2;
    if (var_3_2 < 0x32) {
        temp_2_3 = func_003b7060();
        var_f0_3 = (f32)(u32)temp_2_3;
        temp_f0_3 = 3.0f * (var_f0_3 / 2147483648.0f);
        var_3_3 = (u32)temp_f0_3;
        var_16 = var_3_3 + 1;
    } else {
        temp_2_4 = func_003b7060();
        var_f0_4 = (f32)(u32)temp_2_4;
        temp_f0_4 = 100.0f * (var_f0_4 / 2147483648.0f);
        var_3_4 = (u32)temp_f0_4;
        if (var_3_4 < 0xA) {
            var_16 = 7;
        } else if (iGpffffb1e8 >= 0xA) {
            temp_2_5 = func_003b7060();
            var_f0_5 = (f32)(u32)temp_2_5;
            temp_f0_5 = 3.0f * (var_f0_5 / 2147483648.0f);
            var_3_5 = (u32)temp_f0_5;
            var_16 = var_3_5 + 4;
        }
    }
block_end:
    if (var_16 >= 8) {
        var_16 = 8;
    }
    return var_16 + 0xB;
}
// FUN_001246D0
s32 func_001246d0(u8 *arg0)
{
    s32 sp7C;
    u8 sp50[0x2C];
    s32 var_16;
    s32 var_17;
    u8 *temp_2;
    u8 *temp_4;

    var_17 = 1;
    if (arg0 == NULL) {
        func_0046d730(D_005E5548, 0xF4);
    }
    var_16 = 0;
    goto loop_14;
loop_18:
    temp_2 = arg0 + (var_16 * 4);
    temp_4 = temp_2 + 0x44;
    if (*(u8 **)temp_4 == NULL) {
        if (var_16 < 8) {
            func_00442088(sp50, (const char *)D_005E5560, var_16 + 1);
        } else {
            func_00442088(sp50, (const char *)D_005E5570, var_16 - 7);
        }
        var_17 = func_00455f70(sp50, &sp7C);
        if (var_17 == 0) {
            func_0046d730(D_005E5548, 0xFE);
        }
        *(u8 **)temp_4 =
            func_00477f10(9, 0xFF01, var_17, sp7C, 0);
        var_17 = 0;
    }
    if ((*(u8 **)temp_4 != NULL) &&
        (func_004782b0(*(u8 **)temp_4) == 0)) {
        var_17 = 0;
        goto done;
    }
    var_16++;
    goto loop_14;
loop_14:
    if (var_16 < 0xF) {
        goto loop_18;
    }
done:
    return var_17;
}
// FUN_00124830
s32 func_00124830(u8 *arg0)
{
    u8 sp40[0x30];
    s32 temp_18;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_16;

    var_16 = 0;
    func_00453670(sp40, 3, 3, *(s32 *)(arg0 + 0x20), 0);
    func_004538e0(sp40, 0x4000, 0x1000, 0, 0);
    temp_2 = func_00453960(sp40);
    switch (temp_2) {
    case 1:
        var_16 = 1;
        break;
    case 2:
        var_16 = 1;
        break;
    }
    temp_18 = *(s32 *)(arg0 + 0x20);
    temp_2_2 = func_00453dc0(sp40);
    *(s32 *)(arg0 + 0x20) = temp_2_2;
    if (temp_2_2 != temp_18) {
        *(s32 *)(arg0 + 0x24) = temp_18;
        *(s32 *)(arg0 + 0x28) = temp_18 << 16;
    }
    if (D_008C024E[0] & 0x40) {
        func_0045af60(0, 0, 0, 1);
        return *(s32 *)(arg0 + 0x20) + 1;
    }
    if (var_16 != 0) {
        func_0045af60(0, 0, 0, 0);
        return 0;
    }
    return -1;
}
// FUN_00124970
void func_00124970(s32 arg0, u32 arg1, s32 arg2, u32 *arg3)
{
    u8 spAC[4];
    u8 sp60[0x4C];
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *var_17;
    u8 *var_16;

    if (arg0 >= 0xF) {
        var_17 = NULL;
    } else {
        temp_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg3);
        var_17 = temp_2 + 0x44;
        if (func_004782b0(*(u8 **)var_17) != 0) {
            var_17 = *(u8 **)var_17;
        } else {
            var_17 = NULL;
        }
    }
    if (var_17 != NULL) {
        if ((arg0 + 8) >= 0xF) {
            var_16 = NULL;
        } else {
            temp_2_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg3);
            var_16 = temp_2_2 + 0x64;
            if (func_004782b0(*(u8 **)var_16) != 0) {
                var_16 = *(u8 **)var_16;
            } else {
                var_16 = NULL;
            }
        }
        if ((var_16 != NULL) && (func_0047a510(var_17, 0x64, sp60) != 0)) {
            spAC[0] = arg1 >> 0x18;
            spAC[1] = arg1 >> 0x10;
            spAC[2] = arg1 >> 8;
            spAC[3] = arg1;
            func_0047a1c0(var_16, sp60, 0);
            if (arg2 & 1) {
                *(s32 *)(var_16 + 0xD8) |= 8;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~8;
            }
            if (arg2 & 2) {
                *(s32 *)(var_16 + 0xD8) |= 0x10;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x10;
            }
            if (arg2 & 0x10) {
                *(s32 *)(var_16 + 0xD8) |= 0x100000;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x100000;
            }
            if (arg2 & 0x40) {
                *(s32 *)(var_16 + 0xD8) |= 0x40000;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x40000;
            }
            func_002ab550(var_16, spAC);
            if (!(arg2 & 0x10000)) {
                func_00478e70(var_16);
            }
        }
    }
}
extern void *func_003e0870(void *m, void *src, f32 angle, s32 mode);
extern void *func_003e4320(void *dst, void *src, void *m);
extern void *func_003e0a90(void *m, void *v, s32 mode);
extern void *func_003e0c90(void *m, void *v, s32 mode);
extern u8 D_005E55B0[];
extern u8 D_005E55B8[];
extern u8 D_005E55C0[];
extern u8 D_005E55C8[];
extern u8 D_005E55D0[];
extern u8 D_005E55D8[];

typedef struct {
    u8 q[8];
    f32 f;
} Code1GlobalPair12;

// FUN_00124BB0
/* 956/960 bytes; twenty-five resolved relocations and one zero alignment word. */
#pragma push
#pragma opt_propagation off
void func_00124bb0(s32 arg0,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, f32 fparg5,
                   u32 arg1, u32 arg2,
                   f32 fparg6,
                   s32 arg3, u32 *arg4)
{
    u8 color[4];
    Code1GlobalPair12 global_pair;
    u8 vec_f[0x10];
    u8 vec_e[0x10];
    u8 vec_d[0x10];
    u8 matrix[0x40];
    u8 *temp_2;
    u8 *var_16;

    {
        s64 q = *(s64 *)D_005E55B0;
        f32 f = *(f32 *)D_005E55B8;
        *(s64 *)global_pair.q = q;
        global_pair.f = f;
    }
    {
        s64 q = *(s64 *)D_005E55C0;
        f32 f = *(f32 *)D_005E55C8;
        *(s64 *)vec_f = q;
        *(f32 *)(vec_f + 8) = f;
    }
    {
        s64 q = *(s64 *)D_005E55D0;
        f32 f = *(f32 *)D_005E55D8;
        *(s64 *)vec_e = q;
        *(f32 *)(vec_e + 8) = f;
    }
    if (arg0 >= 0xF) {
        var_16 = NULL;
    } else {
        temp_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg4);
        var_16 = temp_2 + 0x44;
        if (func_004782b0(*(u8 **)var_16) != 0) {
            var_16 = *(u8 **)var_16;
        } else {
            var_16 = NULL;
        }
    }
    if (var_16 != NULL) {
        *(s32 *)(matrix + 0x28) = 0x3F800000;
        *(s32 *)(matrix + 0x14) = 0x3F800000;
        *(s32 *)(matrix + 0x00) = 0x3F800000;
        *(s32 *)(matrix + 0x10) = 0;
        *(s32 *)(matrix + 0x08) = 0;
        *(s32 *)(matrix + 0x04) = 0;
        *(s32 *)(matrix + 0x24) = 0;
        *(s32 *)(matrix + 0x20) = 0;
        *(s32 *)(matrix + 0x18) = 0;
        *(s32 *)(matrix + 0x38) = 0;
        *(s32 *)(matrix + 0x34) = 0;
        *(s32 *)(matrix + 0x30) = 0;
        *(s32 *)(matrix + 0x0C) |= 0x20003;
        func_003e0870(matrix, &global_pair, fparg4, 0);
        *(s32 *)(vec_f + 0x00) = 0x3F800000;
        *(s32 *)(vec_f + 0x04) = 0;
        *(s32 *)(vec_f + 0x08) = 0;
        func_003e4320(vec_f, vec_f, matrix);
        func_003e0870(matrix, vec_f, fparg3, 2);
        *(s32 *)(vec_e + 0x00) = 0;
        *(s32 *)(vec_e + 0x04) = 0;
        *(s32 *)(vec_e + 0x08) = 0x3F800000;
        func_003e4320(vec_e, vec_e, matrix);
        func_003e0870(matrix, vec_e, fparg5, 2);
        *(f32 *)(vec_d + 0x00) = fparg6;
        *(f32 *)(vec_d + 0x04) = fparg6;
        *(f32 *)(vec_d + 0x08) = fparg6;
        func_003e0a90(matrix, vec_d, 2);
        *(f32 *)(vec_d + 0x00) = fparg0;
        *(f32 *)(vec_d + 0x04) = fparg1;
        *(f32 *)(vec_d + 0x08) = fparg2;
        func_003e0c90(matrix, vec_d, 2);
        func_0047a1c0(var_16, matrix, 0);
        color[0] = arg1 >> 0x18;
        color[1] = arg1 >> 0x10;
        color[2] = arg1 >> 8;
        color[3] = arg1;
        if (arg3 & 1) {
            *(s32 *)(var_16 + 0xD8) |= 8;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~8;
        }
        if (arg3 & 2) {
            *(s32 *)(var_16 + 0xD8) |= 0x10;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x10;
        }
        if (arg3 & 0x10) {
            *(s32 *)(var_16 + 0xD8) |= 0x100000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x100000;
        }
        if (arg3 & 0x40) {
            *(s32 *)(var_16 + 0xD8) |= 0x40000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x40000;
        }
        if (!(arg3 & 0x10000)) {
            func_00478e70(var_16);
        }
        func_00124970(arg0, arg2, arg3 | 2, arg4);
        func_002ab550(var_16, color);
        func_00124970(arg0, arg2, arg3 | 1, arg4);
    }
}
#pragma opt_propagation on
#pragma pop
/* Floor: 844 differing words (was 900), 967 of 964 instrs (+3, +0.3% well inside 3% band, 26 slack to 993 edge; was 993/+29 edge), 932 fnalign edits (was 1077). Surplus was 6 extra clamped float->u8 (cvt.w.s/mfc1 +12, c.ole/sub/bc1t +6, lui +6) from double-converting white via f intermediates + a2; fix is u32 r/g/b for retail's unsigned bltz/srl doubling, a0 as (s32)(f32)*(s32 *) for lwc1/cvt.s.w/cvt.w.s/mfc1, and 5 of 6 f intermediates folded to direct sums (first f0 double retained to center count). Cheap causes ruled out: all literals f-suffixed, 13 jals both with no __ soft-float relocs, no 2.0f in body (mul.s 3/3). Gate 8 inside 0 outside. Body also at docs/probe_archive/Lane0012_00124f70_body.c; production stays ASM. */
/* measured 2026-09-18: reconstructed from bare marker (retail 0x00124F70, 3856B window, 964 instrs). v1c baseline 921 (Ghidra-direct, [6] frame exact at 0x360; [8] gave 0x370 at 922). v2 908 (-13: D_5530/40 array not scalar + 002aaf20 640/448 not 512/480,512/1216). v3 904 (-4: flag beqz polarity + col order + buffers address-ascending). v4 903 (-1: buffers descending, first-declared highest per micro stacktest2). v5 900 (-3: explicit p5234/5230/524C/5248/5244/5240/523C/5238 locals, first two spill to 0xA0/0xB0). Free pragmas tie/worse: loopinv 922 (+1), nounroll 921 tie, sched 921 tie, propoff 943 (+22), commonsubs 940 (+19). 7o eight skipped: body already in 7o form (bare decls + statement assigns, no Type name = ...; initialisers). Full proof in archive. */
// FUN_00124F70 NONMATCHING
#ifdef NON_MATCHING
void func_00124f70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4)
{
    extern void func_002aaf20(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, s32 arg1, s32 arg2);
    extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    extern void func_002aaac0(void);
    extern s32 func_003f6440(s32 arg0, s32 arg1);
    extern void func_00124bb0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, u32 arg1, u32 arg2, f32 fparg6, s32 arg3, u32 *arg4);
    extern u8 D_005E5530[];
    extern u8 D_005E5540[];
    extern u8 D_005E5230[];
    extern u8 D_005E5234[];
    extern u8 D_005E5238[];
    extern u8 D_005E523C[];
    extern u8 D_005E5240[];
    extern u8 D_005E5244[];
    extern u8 D_005E5248[];
    extern u8 D_005E524C[];
    u32 b340[6];
    u32 b320[6];
    u32 b300[6];
    u32 b2E0[6];
    u32 b2C0[6];
    u32 b2A0[6];
    u32 b280[6];
    u32 b260[6];
    u32 b240[6];
    u32 b220[6];
    u32 b200[6];
    u32 b1E0[6];
    u32 b1C0[6];
    u32 b1A0[6];
    u32 b180[6];
    u32 b160[6];
    u32 b140[6];
    u32 b120[6];
    u32 b100[6];
    u32 bE0[6];
    u32 bC0[6];
    u8 colBuf[4];
    u8 col4[4];
    u8 *p;
    s32 n;
    s32 *src;
    s32 *dst;
    s32 count;
    s32 t1;
    s32 t2;
    s32 idx;
    s32 *tbl;
    s32 vidx;
    u32 word;
    u32 r;
    u32 g;
    u32 b;
    u8 c0;
    u8 c1;
    u8 c2;
    f32 f0;
    f32 f1;
    f32 f2;
    u8 *p5234;
    u8 *p5230;
    u8 *p524C;
    u8 *p5248;
    u8 *p5244;
    u8 *p5240;
    u8 *p523C;
    u8 *p5238;
    s32 flag;
    (void)arg2;
    if (arg3 != 0) {
        flag = 0;
    } else {
        flag = 0x10000;
    }
    p = col4;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    *(f32 *)colBuf = *(f32 *)col4;
    func_002aaf20(colBuf, 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x12, 0);
    *(s128 *)b140 = *(s128 *)D_005E5530;
    *(s64 *)(b140 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)b140;
    dst = (s32 *)b1C0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    idx = arg0 * 0x28;
    tbl = (s32 *)(D_005E524C + idx);
    p524C = D_005E524C + idx;
    p5248 = D_005E5248 + idx;
    p5244 = D_005E5244 + idx;
    p5240 = D_005E5240 + idx;
    p523C = D_005E523C + idx;
    p5238 = D_005E5238 + idx;
    p5234 = D_005E5234 + idx;
    p5230 = D_005E5230 + idx;
    vidx = *tbl * 4;
    word = *(u32 *)((u8 *)b1C0 + vidx);
    src = (s32 *)b140;
    dst = (s32 *)b1A0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    r = (word >> 0x18) & 0xFF;
    g = (word >> 0x10) & 0xFF;
    b = (word >> 8) & 0xFF;
    f0 = (f32)(u8)((f32)(0xFF - r) * 1.0f + (f32)r);
    f1 = (f32)(0xFF - g) * 1.0f + (f32)g;
    f2 = (f32)(0xFF - b) * 1.0f + (f32)b;
    {
        s32 a0 = (s32)(f32)*(s32 *)p5230;
        u32 a1 = (*(u32 *)((u8 *)b1A0 + vidx) & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)(u8)f2 << 8) | ((u32)(u8)f0 << 0x18) | ((u32)(u8)f1 << 0x10) | 0xFF;
        func_00124bb0(a0, *(f32 *)p5234, 0.0f, *(f32 *)p5238, *(f32 *)p523C, *(f32 *)p5240, *(f32 *)p5244, a1, a2, *(f32 *)p5248, 0x10052, (u32 *)arg4);
    }
    *(s128 *)b120 = *(s128 *)D_005E5530;
    *(s64 *)(b120 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)b120;
    dst = (s32 *)b180;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    word = *(u32 *)((u8 *)b180 + vidx);
    src = (s32 *)b120;
    dst = (s32 *)b160;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    r = (word >> 0x18) & 0xFF;
    g = (word >> 0x10) & 0xFF;
    b = (word >> 8) & 0xFF;
    f0 = (f32)(0xFF - r) * 1.0f + (f32)r;
    f1 = (f32)(0xFF - g) * 1.0f + (f32)g;
    f2 = (f32)(0xFF - b) * 1.0f + (f32)b;
    {
        s32 a0 = (s32)(f32)*(s32 *)p5230;
        u32 a1 = (*(u32 *)((u8 *)b160 + vidx) & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)(u8)f2 << 8) | ((u32)(u8)f0 << 0x18) | ((u32)(u8)f1 << 0x10) | 0xFF;
        func_00124bb0(a0, *(f32 *)p5234, 0.0f, *(f32 *)p5238, *(f32 *)p523C, *(f32 *)p5240, *(f32 *)p5244, a1, a2, *(f32 *)p5248, flag | 0x12, (u32 *)arg4);
    }
    *(s128 *)b100 = *(s128 *)D_005E5530;
    *(s64 *)(b100 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)b100;
    dst = (s32 *)b340;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    colBuf[0] = (u8)(*(u32 *)((u8 *)b340 + vidx) >> 0x18);
    src = (s32 *)b100;
    dst = (s32 *)b320;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[1] = (u8)(*(u32 *)((u8 *)b320 + vidx) >> 0x10);
    src = (s32 *)b100;
    dst = (s32 *)b300;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[2] = (u8)(*(u32 *)((u8 *)b300 + vidx) >> 8);
    src = (s32 *)b100;
    dst = (s32 *)b2E0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[3] = (u8)*(u32 *)((u8 *)b2E0 + vidx);
    colBuf[0] = (u8)arg1;
    colBuf[1] = (u8)arg1;
    colBuf[2] = (u8)arg1;
    func_002aaac0();
    func_003f6440(3, 0x53001);
    func_003f6440(2, 0x52);
    {
        s32 c = arg1 & 0xFF;
        s32 rep = (c << 24) | (c << 16) | (c << 8) | 0xFF;
        func_0025f3f0(-1.0f, -1.0f, 0.0f, rep >> 8, 0xFF, 0, 0, *(s32 *)(arg4 + 0x3C), 0);
    }
    *(s128 *)bE0 = *(s128 *)D_005E5530;
    *(s64 *)(bE0 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)bE0;
    dst = (s32 *)b2C0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    colBuf[0] = (u8)(*(u32 *)((u8 *)b2C0 + vidx) >> 0x18);
    src = (s32 *)bE0;
    dst = (s32 *)b2A0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[1] = (u8)(*(u32 *)((u8 *)b2A0 + vidx) >> 0x10);
    src = (s32 *)bE0;
    dst = (s32 *)b280;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[2] = (u8)(*(u32 *)((u8 *)b280 + vidx) >> 8);
    src = (s32 *)bE0;
    dst = (s32 *)b260;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    colBuf[3] = (u8)*(u32 *)((u8 *)b260 + vidx);
    {
        f32 base = (f32)arg1 / 255.0f;
        f32 v0 = (f32)colBuf[0] * base;
        f32 v1 = (f32)colBuf[1] * base;
        f32 v2 = (f32)colBuf[2] * base;
        colBuf[0] = (u8)v0;
        colBuf[1] = (u8)v1;
        colBuf[2] = (u8)v2;
    }
    func_002aaac0();
    func_003f6440(3, 0x53001);
    func_003f6440(2, 0x58);
    func_002aaf20(colBuf, 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x300, 0);
    *(s128 *)bC0 = *(s128 *)D_005E5530;
    *(s64 *)(bC0 + 4) = *(s64 *)D_005E5540;
    src = (s32 *)bC0;
    dst = (s32 *)b240;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    vidx = *tbl * 4;
    {
        u32 w0 = *(u32 *)((u8 *)b240 + vidx);
        colBuf[0] = (u8)(((w0 & 0xFFFFFF00) | (u32)(u8)arg1) >> 0x18);
    }
    src = (s32 *)bC0;
    dst = (s32 *)b220;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    {
        u32 w1 = *(u32 *)((u8 *)b220 + vidx);
        colBuf[1] = (u8)(((w1 & 0xFFFFFF00) | (u32)(u8)arg1) >> 0x10);
    }
    src = (s32 *)bC0;
    dst = (s32 *)b200;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    {
        u32 w2 = *(u32 *)((u8 *)b200 + vidx);
        colBuf[2] = (u8)(((w2 & 0xFFFFFF00) | (u32)(u8)arg1) >> 8);
    }
    src = (s32 *)bC0;
    dst = (s32 *)b1E0;
    count = 3;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        count--;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (count > 0);
    {
        u32 w3 = *(u32 *)((u8 *)b1E0 + vidx);
        colBuf[3] = (u8)((w3 & 0xFFFFFF00) | (u32)(u8)arg1);
    }
    func_002aaac0();
    func_002aaf20(colBuf, 0.0f, 0.0f, 1.0f, 640.0f, 448.0f, 1, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00124f70);
#endif
extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2,
                         s32 arg0, u8 arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 arg5);
extern void func_002aaac0(void);
extern s32 func_003f6440(s32 arg0, s32 arg1);
extern void func_0045e6a0(void *arg0, void *arg1, f32 fparg0, s32 arg2,
                          s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                          f32 fparg1, f32 fparg2, f32 fparg3);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 D_005E55E0[];
extern s8 D_005E5610[];
extern void (*D_00887300[])(s32 arg0, s32 arg1);

// FUN_00125E80
void func_00125e80(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 *arg1)
{
    u8 spCC[4];
    s32 sp90[12];
    s8 sp70[0x20];
    f32 sp40[12];
    s32 *src;
    s32 *dst;
    s32 count;
    s32 temp1;
    s32 temp2;
    s8 *src8;
    s8 *dst8;
    s32 count8;
    s8 temp8_1;
    s8 temp8_2;
    u8 *p;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    f32 *out;
    f32 *in;

    src = D_005E55E0;
    dst = sp90;
    count = 6;
    do {
        temp1 = src[0];
        temp2 = src[1];
        src += 2;
        count--;
        dst[0] = temp1;
        dst[1] = temp2;
        dst += 2;
    } while (count > 0);

    src8 = D_005E5610;
    dst8 = sp70;
    count8 = 0xC;
    do {
        temp8_1 = src8[0];
        temp8_2 = src8[1];
        src8 += 2;
        count8--;
        dst8[0] = temp8_1;
        dst8[1] = temp8_2;
        dst8 += 2;
    } while (count8 > 0);

    p = spCC;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }

    func_00489f80();
    func_0025f3f0(0.0f, 0.0f, fparg2, 0xFFFFFF, arg0 & 0xFF, 0x1000D,
                  0, *(s32 *)(arg1 + 0x3C), 1);
    func_0048a000();

    i = 0;
    x = -100.0f + fparg0;
    y = -200.0f + fparg1;
    while ((u32)i < 6) {
        in = &((f32 *)sp90)[i * 2];
        out = &sp40[i * 2];
        out[0] = x + in[0];
        out[1] = y + in[1];
        i++;
    }

    func_002aaac0();
    D_00887300[0](6, 1);
    func_003f6440(3, 0x5000D);
    func_003f6440(2, 0x58);
    func_0045e6a0(sp70, sp40, fparg2, 6, 4, 0, 0, 0,
                  -20.0f, 1.0f, 1.0f);
}
/* Floor (1296B window; obj 1288B fndiff 155 verify 465 fnalign 32 plus 15 reloc-only
   retail 322/object 322 exact; width check 2026-09-17: no dsll/dsra pairs, clean.
   Open: stack-address scheduling (sp+0x7c/0x74/0x60 ordering), gp-relative immediates
   are reloc-only phantoms. Triple-built m2c+IDA+Ghidra; frame exact. */
/* 155 -> 148 (2026-09-18): the three scratch-slot addresses retail
   materialises before the statement that fills the slot are pointer locals
   (`q7C`, `q74`, `q60`), not argument expressions - b210 emits argument
   setup at the call, so `func_002aaf20(sp7C, ...)` put `addiu $a0, $sp,
   0x7c` seven slots after retail's.  Measured and rejected: assigning the
   pointer but storing through the array instead (155 - the pointer folds
   away), pointer locals only for the func_0045d6e0 pair (155). */
/* 148 -> 112 (2026-09-19): the eight func_0025f430 calls stage their s16
   radius arguments early - retail loads each (s16)fGp const well before its
   call, so the inline `(s16)fGpXXXX, (s16)fGpXXXX` pairs are hoisted s16
   temps (`r40`..`r90`, extending the existing `radius` idiom), six sites,
   25 fnalign edits (plus 21 reloc-only).  Measured and rejected: hoisting
   the trailing (Fy, Fy) float pairs the same way (112 - the compiler had
   already commoned the duplicate loads, identical codegen); scoped
   `#pragma opt_common_subs off` around the function (303 - retail is not
   rematerialising here, the whole function depends on load CSE; reverted).
   Residual is the MMI s128-copy shape plus the f16 load-order pairs. */
// FUN_00126090 NONMATCHING
#ifdef NON_MATCHING
void func_00126090(s32 arg0, u8 *arg1)
{
extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2,
                         s32 arg0, u8 arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 arg5);
extern void func_002aaac0(void);
extern s32 func_003f6440(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern f32 fGpffff8230;
extern f32 fGpffff8234;
extern f32 fGpffff8238;
extern f32 fGpffff823c;
extern f32 fGpffff8240;
extern f32 fGpffff8244;
extern f32 fGpffff8248;
extern f32 fGpffff824c;
extern f32 fGpffff8250;
extern f32 fGpffff8254;
extern f32 fGpffff8258;
extern f32 fGpffff825c;
extern f32 fGpffff8260;
extern f32 fGpffff8264;
extern f32 fGpffff8268;
extern f32 fGpffff826c;
extern f32 fGpffff8270;
extern f32 fGpffff8274;
extern f32 fGpffff8278;
extern f32 fGpffff827c;
extern f32 fGpffff8280;
extern f32 fGpffff8284;
extern f32 fGpffff8288;
extern f32 fGpffff828c;
extern f32 fGpffff8290;
extern f32 fGpffff8294;
extern f32 fGpffff8298;
extern f32 fGpffff829c;
extern s128 D_005E5590;
extern s128 D_005E55A0;
extern void func_002aaf20(void *arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, f32 farg4, s32 arg1, s32 arg2);
extern void func_0025f430(f32 farg0, f32 farg1, f32 farg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, f32 farg3, f32 farg5, f32 farg4);

    u8 sp7C[4];
    u8 sp78[4];
    u8 sp74[4];
    u8 sp70[4];
    s32 sp60[4];
    s32 sp50[4];
    s32 sp40[4];
    u8 *p;
    s32 n;
    s32 temp_2;
    f32 temp_f20;
    f32 *q7C;
    u8 *q74;
    s32 *q60;
    f32 temp_f21;
    s16 radius;
    s16 r40;
    s16 r50;
    s16 r60;
    s16 r70;
    s16 r80;
    s16 r90;
    f32 r64;

    p = sp78;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    q7C = (f32 *)sp7C;
    *q7C = *(f32 *)sp78;
    func_002aaf20(q7C, 0.0f, 0.0f, 0.0f, 640.0f, 480.0f, 0x12, 0);
    func_00489f80();
    func_0025f3f0(0.0f, 0.0f, 0.0f, 0xFFFFFF, arg0 & 0xFF, 0x1000C, 0,
                  *(s32 *)(arg1 + 0x3C), 1);
    func_0048a000();
    func_00489f80();
    p = sp70;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    sp70[3] = 0;
    q74 = sp74;
    *(f32 *)q74 = *(f32 *)sp70;
    *(s128 *)sp50 = D_005E5590;
    q60 = sp60;
    *(s128 *)q60 = D_005E5590;
    func_0045d6e0(q74, q60, 0.0f, 0);
    *(s128 *)sp40 = D_005E55A0;
    q60 = sp60;
    *(s128 *)q60 = D_005E55A0;
    func_0045d6e0(q74, q60, 0.0f, 0);
    func_0048a000();
    temp_2 = *(s32 *)(arg1 + 0x80) + 1;
    *(s32 *)(arg1 + 0x80) = temp_2;
    if (temp_2 >= 0xC8) {
        *(s32 *)(arg1 + 0x80) = 0;
    }
    temp_f21 = (f32)*(s32 *)(arg1 + 0x80) / 200.0f;
    func_002aaac0();
    func_003f6440(3, 0x53001);
    func_003f6440(2, 0x58);
    temp_f20 = 360.0f * temp_f21;
    r64 = 64.0f;
    radius = (s16)fGpffff8230;
    func_0025f430(fGpffff8234, fGpffff8238, 0.0f, 0x202020, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, radius, radius, temp_f20, fGpffff823c, fGpffff823c);
    r40 = (s16)fGpffff8240;
    func_0025f430(fGpffff8244, fGpffff8248, 0.0f, 0x808080, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, r40, r40, temp_f20, fGpffff824c, fGpffff824c);
    r50 = (s16)fGpffff8250;
    func_0025f430(fGpffff8254, fGpffff8258, 0.0f, 0x808080, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, r50, r50, temp_f20, fGpffff825c, fGpffff825c);
    r60 = (s16)fGpffff8260;
    func_0025f430(fGpffff8264, fGpffff8268, 0.0f, 0x808080, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, r60, r60, temp_f20, fGpffff826c, fGpffff826c);
    temp_f20 = -360.0f * temp_f21;
    r70 = (s16)fGpffff8270;
    func_0025f430(fGpffff8274, fGpffff8278, 0.0f, 0x808080, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, r70, r70, temp_f20, fGpffff827c, fGpffff827c);
    r80 = (s16)fGpffff8280;
    func_0025f430(fGpffff8284, fGpffff8288, 0.0f, 0x808080, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, r80, r80, temp_f20, fGpffff828c, fGpffff828c);
    func_0025f430(313.0f, 29.0f, 0.0f, 0x808080, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, (s16)r64, (s16)r64, temp_f20, 1.0f, 1.0f);
    r90 = (s16)fGpffff8290;
    func_0025f430(fGpffff8294, fGpffff8298, 0.0f, 0x808080, 0x80, 0x1000F, 0, *(s32 *)(arg1 + 0x3C), 0, r90, r90, temp_f20, fGpffff829c, fGpffff829c);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_00126090);
#endif
/* measured: archived build/func_001265a0_floor_v1.c (1791L m2c) + jtbl-bound fix cases 10-15 to tail per ELF jtbl_00746730 dump at file-off 0x6467B0 (16 entries 0:26660,1-2:26664,3:26688,4-5:2679C,6-7:29778,8-9:2A024,10-15:2A948 tail; sltiu 0xa->0x10 exact). Installed fnalign retail 4404/object 4404 (exact, 0.0%, 80 edits +124 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_0012.c func_001265a0`; probe 3842 words via measure_guarded. Candidate-method fnalign (--candidate floor) reports retail 4400/object 3779 (-14.1%, 6325 edits) due to scratch-vs-real TU compilation difference (header/guard placement), not body quality; installed is exact. Call census: all 202 retail jals +14 jalr have counterparts (30x0045d6e0,22x0025f3f0,17x0044b7b0,14x003f6440/002aaf20/002aaac0,11x0048a000/00489f80,etc.). Loops: 40 retail backward branches (30x6-instr zeroing +8x8-instr bgtz copy +3 large 414/240/240 at 0x126D9C/0x12742C/0x129B0C) all present as draft loop_93/loop_128/loop_351 + 4-word do-whiles. Frame -0x6C0 exact, sltiu 0x10 exact. Residual 80 edits are lui symbol materialization (0x5e vs 0) + MMI lq/add_a.w vs plain + VU0 adda/madd + scheduling, no missing regions by address (no deletes in installed alignment). */
/* gate: func_001265a0 is INSIDE the +-3% band at 4404 against retail 4404 (+0.0%, band
   4272-4536), deficit 0, via --candidate measurement 2026-09-20.  Filled the 46-run
   (0x12A794-0x12A84C) that deficit_scan named ABSENT: the empty-if at 0x12A7F4 is the
   same defect as its 0x12A794 neighbour - retail's 0.25f normalization
   ((f32)(0x20<<16)+0.25f*(f32)((0x20-0x24)<<16)-(f32)0x28), (s32) compare, recomputed $3
   ((f32)$2+$f1), and 32.0f*((f32)$3/65535.0f)+327.0f madd for the first 0x10006
   func_0025f3f0 call, which m2c had left as an empty if plus blend/0.0f args.  The 46
   dissolves into small register-color replaces; deficit_scan now reports only CROSS runs
   (2350 at 0x127930, 142 at 0x129E18, 48 at 0x12A6F8) with mtc1 +207/lui +108/sb +40.
   Prior stamp described 4348/4400 -1.2% deficit 52 (15 color channels + quantized factor;
   159-run and 104-run dissolved; 2350/142/46 phantoms + sb+40/lwc1+37/empty-if gaps) and
   3779/-14.1% floor, kept for history.  Candidate fnalign is 6509 edits +15 reloc-only,
   probe 3903 words (base 3899); installed TU stays 74 MATCH/8 ASM with func_0012d630
   untouched.  The old 4404/4404 +0.0% 80-edit number came from running `fnalign.py
   <file> <func>` with NO --candidate on this guarded floor, which compiles the
   INCLUDE_ASM fallback and therefore aligns retail against itself; fnalign now refuses
   that invocation outright and tests/test_fnalign.py pins it. */
/* fix 2026-09-20: old 4404/4404 was two errors cancelling, not evidence the body was right. */
/* Hole (-1): s64 temp_10 = (s64)(BITWISE(s64,var_f0)<<0x30)>>0x30 called __fixsfdi@+0x2c04 */
/* (obj jal+nop+dsll+dsra = 4); retail is cvt.w.s/mfc1/nop/dsll32 16/dsra32 16 = 5 */
/* (R2866-2870 0x129268-0x129278, $f2 = 137.0*temp_f16). Narrow s32 <<16>>16 gives */
/* the 5 and clears census 1->0 but lands 4405/6516 alone. Lump (+1): temp_f1_28 had */
/* (f32)(temp_4<<0x10) where retail is (f32)temp_4 (R4175 0x12a6dc mtc1 $v1 vs obj sll+mtc1). */
/* Removing that sll returns 4404/4404 at 6514+15, census 0, both sites matching. */
/* Trap: s32 keep 0x30 clears census at 4400/6509 and s32 no-shift at 4402/6511, both */
/* LOWER edits than the right answer but wrong: they drop the dsll32/dsra32 16 pair */
/* retail emits. Lower edits at worse count is not a better body. */
// FUN_001265A0 NONMATCHING
#ifdef NON_MATCHING
#ifndef M2C_GUARD
#define M2C_GUARD
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#endif
void func_001265a0(s32 arg1) {
    extern s32 func_0025f3f0();
    extern s32 func_0025f430();
    extern void func_002aaac0(void);
    extern void func_002aaf20();
    extern s32 func_002ab380();
    extern s32 func_002abb30();
    extern s32 func_00366c70();
    extern s32 func_003e0870();
    extern s32 func_003e0c90();
    extern s32 func_003f6440();
    extern s64 func_00401b80();
    extern s32 func_0043c6a0(f32);
    extern f32 func_0044b7b0(f32);
    extern u32 *func_00452560(s32);
    extern s32 func_00455f70();
    extern s32 func_0045ad50();
    extern s32 func_0045c870();
    extern s32 func_0045d6e0();
    extern s32 func_0046d730();
    extern s32 func_004782b0();
    extern s32 func_00478e70();
    extern s32 func_00479940();
    extern s32 func_0047a0e0();
    extern s32 func_0047a1c0();
    extern s32 func_00489f80();
    extern s32 func_0048a000();
    extern s32 D_005E5230;
    extern u8 D_005E523C[];
    extern u8 D_005E5240[];
    extern u8 D_005E5248[];
    extern u8 D_005E5254[];
    extern s32 D_005E5370;
    extern s32 D_005E538C;
    extern s32 D_005E5398;
    extern s32 D_005E53B4;
    extern s128 D_005E5530;
    extern s64 D_005E5540;
    extern u8 D_005E5548[];
    extern s128 D_005E5590;
    extern s128 D_005E55A0;
    extern s64 D_005E5628;
    extern f32 D_005E5630;
    extern s64 D_005E5638;
    extern f32 D_005E5640;
    extern s128 D_005E5650;
    extern s128 D_005E5660;
    extern s128 D_005E5670;
    extern s128 D_005E5680;
    extern s128 D_005E5690;
    extern s128 D_005E56A0;
    extern u8 D_005E56B0[];
    extern u8 D_005E56D0[];
    extern void (*D_00887300[])(s32, s32);
    extern s32 func_00124bb0();
    extern s32 func_00124f70();
    extern s32 func_00125e80();
    extern s32 func_00126090();
    extern u8 *sp;
    extern u8 *saved_reg_gp;
    extern f32 fGpffff9c70;
    extern f32 fGpffff9c74;
    extern f32 fGpffff9c78;
    extern f32 fGpffff9c7c;
    extern f32 fGpffff9c80;
    extern f32 fGpffff9c84;
    extern f32 fGpffff9c88;
    extern f32 fGpffff9c8c;
    extern f32 fGpffff82a0;
    extern f32 fGpffff822c;
    extern f32 fGpffff8228;
    extern f32 fGpffff8170;
    extern f32 fGpffff8110;
    extern f32 fGpffff80bc;
    extern f32 fGpffff81e0;
    extern f32 fGpffff81dc;
    extern f32 fGpffff8094;

M2C_UNK unksp514;
    M2C_UNK unksp524;
    M2C_UNK unksp69B;
    M2C_UNK unksp69F;
    f32 sp6BC;
    s32 sp6B8;
    f32 sp6B4;
    f32 sp6B0;
    f32 sp6AC;
    f32 sp6A8;
    f32 sp6A4;
    f32 sp6A0;
    f32 sp69C;
    f32 sp698;
    f32 sp694;
    f32 sp690;
    f32 sp68C;
    f32 sp688;
    s8 sp687;
    M2C_UNK sp684;
    f32 sp680;
    f32 sp67C;
    f32 sp678;
    f32 sp674;
    f32 sp670;
    f32 sp66C;
    f32 sp668;
    f32 sp664;
    f32 sp660;
    f32 sp65C;
    f32 sp658;
    f32 sp654;
    f32 sp650;
    f32 sp64C;
    f32 sp648;
    f32 sp644;
    f32 sp640;
    f32 sp63C;
    f32 sp638;
    f32 sp634;
    f32 sp630;
    f32 sp62C;
    f32 sp628;
    s8 sp627;
    M2C_UNK sp624;
    f32 sp620;
    s8 sp61F;
    M2C_UNK sp61C;
    f32 sp618;
    s8 sp617;
    M2C_UNK sp614;
    f32 sp610;
    s8 sp60F;
    M2C_UNK sp60C;
    f32 sp608;
    s8 sp607;
    M2C_UNK sp604;
    f32 sp600;
    s8 sp5FF;
    M2C_UNK sp5FC;
    f32 sp5F8;
    s8 sp5F7;
    M2C_UNK sp5F4;
    f32 sp5F0;
    s8 sp5EF;
    M2C_UNK sp5EC;
    f32 sp5E8;
    s8 sp5E7;
    M2C_UNK sp5E4;
    f32 sp5E0;
    s8 sp5DF;
    M2C_UNK sp5DC;
    f32 sp5D8;
    s8 sp5D7;
    M2C_UNK sp5D4;
    f32 sp5D0;
    s64 sp5C8;
    f32 sp5C0;
    s64 sp5B8;
    s32 sp5B0;
    s32 sp5AC;
    f32 sp5A8;
    s128 sp590;
    s32 sp550;
    M2C_UNK sp530;
    s128 sp520;
    s128 sp510;
    s128 sp500;
    s128 sp4F0;
    s128 sp4E0;
    s128 sp4D0;
    s128 sp4C0;
    s128 sp4B0;
    s128 sp4A0;
    s128 sp490;
    s128 sp480;
    s128 sp470;
    M2C_UNK sp450;
    M2C_UNK sp430;
    M2C_UNK sp410;
    M2C_UNK sp3F0;
    M2C_UNK sp3D0;
    M2C_UNK sp3B0;
    s128 sp3A0;
    s128 sp390;
    s128 sp380;
    s128 sp370;
    s128 sp360;
    s128 sp350;
    s128 sp340;
    s128 sp330;
    s128 sp320;
    s128 sp310;
    s128 sp300;
    s128 sp2F0;
    s128 sp2E0;
    s128 sp2D0;
    s128 sp2C0;
    s128 sp2B0;
    s128 sp2A0;
    s128 sp290;
    s128 sp280;
    s128 sp270;
    s128 sp260;
    s128 sp250;
    s128 sp240;
    s128 sp230;
    s128 sp220;
    s128 sp210;
    s128 sp200;
    s128 sp1F0;
    s128 sp1E0;
    s128 sp1D0;
    M2C_UNK sp1B0;
    M2C_UNK sp190;
    M2C_UNK sp170;
    M2C_UNK sp150;
    s64 sp140;
    s128 sp130;
    s64 sp120;
    s128 sp110;
    s64 sp100;
    s128 spF0;
    s64 spE0;
    s128 spD0;
    s64 spC0;
    s128 spB0;
    M2C_UNK *var_5_16;
    M2C_UNK *var_5_17;
    M2C_UNK *var_5_21;
    M2C_UNK *var_5_2;
    M2C_UNK *var_5_3;
    M2C_UNK *var_5_4;
    M2C_UNK *var_5_5;
    M2C_UNK *var_5_6;
    M2C_UNK *var_5_7;
    M2C_UNK *var_5_8;
    M2C_UNK *var_5_9;
    M2C_UNK *var_6_16;
    f32 *var_3_10;
    f32 *var_3_12;
    f32 *var_3_14;
    f32 *var_3_16;
    f32 *var_3_18;
    f32 *var_3_20;
    f32 *var_3_22;
    f32 *var_3_24;
    f32 *var_3_27;
    f32 *var_3_2;
    f32 *var_3_31;
    f32 *var_3_33;
    f32 *var_3_4;
    f32 *var_3_5;
    f32 temp_f0;
    f32 temp_f0_11;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_f1;
    f32 temp_cA;
    f32 temp_cB;
    f32 temp_q1;
    f32 temp_one_S2A;
    f32 temp_one_S2B;
    f32 temp_one_S2C;
    f32 temp_one_S3A;
    f32 temp_one_S3B;
    f32 temp_one_S3C;
    f32 temp_one_S4A;
    f32 temp_one_S4B;
    f32 temp_one_S4C;
    f32 temp_one_S5A;
    f32 temp_one_S5B;
    f32 temp_one_S5C;
    f32 temp_f1_28;
    f32 temp_f13_28;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_12;
    f32 temp_f1_13;
    f32 temp_f1_14;
    f32 temp_f1_15;
    f32 temp_f1_16;
    f32 temp_f1_17;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f7;
    f32 temp_f7_2;
    f32 temp_f7_3;
    f32 temp_f8;
    f32 temp_f8_2;
    f32 temp_f8_3;
    f32 var_f0;
    s128 *var_6;
    s128 *var_6_10;
    s128 *var_6_11;
    s128 *var_6_13;
    s128 *var_6_14;
    s128 *var_6_2;
    s128 *var_6_4;
    s128 *var_6_5;
    s128 *var_6_7;
    s128 *var_6_8;
    M2C_UNK *var_3;
    M2C_UNK *var_3_11;
    M2C_UNK *var_3_13;
    M2C_UNK *var_3_15;
    M2C_UNK *var_3_17;
    M2C_UNK *var_3_19;
    M2C_UNK *var_3_21;
    M2C_UNK *var_3_23;
    M2C_UNK *var_3_25;
    M2C_UNK *var_3_28;
    M2C_UNK *var_3_32;
    M2C_UNK *var_3_3;
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_10;
    s32 temp_2_13;
    s32 temp_2_14;
    s32 temp_2_15;
    s32 temp_2_16;
    s32 temp_2_17;
    s32 temp_2_18;
    s32 temp_2_19;
    s32 temp_2_20;
    s32 temp_2_21;
    s32 temp_2_22;
    s32 temp_2_24;
    s32 temp_2_26;
    s32 temp_2_27;
    s32 temp_2_2;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_2_9;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_12;
    s32 temp_3_13;
    s32 temp_3_14;
    s32 temp_3_15;
    s32 temp_3_16;
    s32 temp_3_17;
    s32 temp_3_18;
    s32 temp_3_19;
    s32 temp_3_20;
    s32 temp_3_21;
    s32 temp_3_22;
    s32 temp_3_23;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_3_8;
    s32 temp_3_9;
    s32 temp_4;
    s32 temp_5;
    s32 temp_8_3;
    s32 temp_8_4;
    s32 temp_8_5;
    s32 temp_8_6;
    s32 temp_9;
    s32 temp_9_2;
    s32 temp_9_3;
    s32 temp_9_4;
    s32 temp_9_5;
    s32 temp_9_6;
    s32 temp_9_7;
    s32 temp_9_8;
    s32 temp_9_9;
    s32 temp_f0_10;
    s32 temp_28;
    s32 temp_i28;
    s32 var_16;
    s32 var_17;
    s32 var_17_2;
    s32 var_19;
    s32 var_2;
    s32 var_2_10;
    s32 var_2_11;
    s32 var_2_12;
    s32 var_2_13;
    s32 var_2_14;
    s32 var_2_15;
    s32 var_2_16;
    s32 var_2_17;
    s32 var_2_18;
    s32 var_2_19;
    s32 var_2_20;
    s32 var_2_21;
    s32 var_2_22;
    s32 var_2_23;
    s32 var_2_24;
    s32 var_2_25;
    s32 var_2_26;
    s32 var_2_27;
    s32 var_2_28;
    s32 var_2_29;
    s32 var_2_2;
    s32 var_2_30;
    s32 var_2_31;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_2_6;
    s32 var_2_7;
    s32 var_2_8;
    s32 var_2_9;
    s32 var_3_30;
    s32 var_3_34;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s32 var_4_10;
    s32 var_4_11;
    s32 var_4_12;
    s32 var_4_13;
    s32 var_4_14;
    s32 var_4_15;
    s32 var_4_17;
    s32 var_4_18;
    s32 var_4_3;
    s32 var_4_4;
    s32 var_4_5;
    s32 var_4_6;
    s32 var_5;
    s32 var_5_10;
    s32 var_5_11;
    s32 var_5_12;
    s32 var_5_13;
    s32 var_5_14;
    s32 var_5_15;
    s32 var_5_18;
    s32 var_5_19;
    s32 var_5_20;
    s32 var_6_12;
    s32 var_6_15;
    s32 var_6_3;
    s32 var_6_6;
    s32 var_6_9;
    s32 var_7;
    s32 var_7_2;
    s32 var_8;
    s32 var_8_2;
    s32 var_8_3;
    s32 temp_10;
    s8 var_3_26;
    s8 var_3_29;
    u32 *temp_20;
    u32 *temp_2_11;
    u32 *temp_2_12;
    u32 *temp_2_23;
    u32 *temp_2_25;
    u32 *temp_2_3;
    u32 *temp_2_4;
    u32 temp_17_2;
    u32 temp_3;
    u32 temp_7_3;
    u32 temp_7_4;
    u32 temp_8;
    u32 temp_8_2;
    u32 temp_8_7;
    u8 *temp_21;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_7_5;
    u8 *var_16_2;
    u8 *var_4;
    u8 *var_4_16;
    u8 *var_4_2;
    u8 *var_4_7;
    u8 *var_4_8;
    u8 *var_4_9;

    temp_20 = (u32 *)(func_00452560(arg1));
    sp5C8 = D_005E5628;
    sp5D0 = D_005E5630;
    sp5B8 = D_005E5638;
    sp5C0 = D_005E5640;
    sp6B8 = 0;
    temp_f0 = (f32)(s32)(fGpffff9c70);
    sp6B4 = temp_f0;
    sp6BC = temp_f0;
    func_0045c870(&sp6BC, 1);
    temp_3 = (u32)(M2C_FIELD(temp_20, u32 *, 4));
    switch (temp_3) {
    case 0:
        M2C_FIELD(temp_20, s32 *, 0x88) = 0;
        /* fallthrough */
    case 1:
    case 2:
        temp_f0_2 = (f32)(s32)(fGpffff9c74);
        sp6B0 = temp_f0_2;
        sp6BC = temp_f0_2;
        func_0045c870(&sp6BC, 1);
        break;
    case 3:
        temp_f0_3 = (f32)(s32)(fGpffff9c78);
        sp6AC = temp_f0_3;
        sp6BC = temp_f0_3;
        func_0045c870(&sp6BC, 1);
        temp_2 = (s32)(M2C_FIELD(temp_20, s32 *, 0x88) + 1);
        M2C_FIELD(temp_20, s32 *, 0x88) = temp_2;
        if (temp_2 >= 0x14) {
            M2C_FIELD(temp_20, s32 *, 0x88) = 0x14;
        }
        temp_f0_4 = (f32)(s32)(fGpffff9c7c);
        sp6A8 = temp_f0_4;
        sp6BC = temp_f0_4;
        sp520 = D_005E5650;
        temp_f20 = (f32)(s32)(42.0f * (1.0f - ((f32) M2C_FIELD(temp_20, s32 *, 0x88) / 20.0f)));
        unksp524 = -temp_f20;
        sp590 = D_005E5650;
        func_0045d6e0(&sp6BC, &sp590, 1, 0);
        sp510 = D_005E5660;
        unksp514 = 406.0f + temp_f20;
        sp590 = D_005E5660;
        func_0045d6e0(&sp6BC, &sp590, 1, 0);
        break;
    case 4:
    case 5:
        temp_16 = (s32)(M2C_FIELD(temp_20, s32 *, 0xC) + 1);
        M2C_FIELD(temp_20, s32 *, 0xC) = temp_16;
        if (temp_16 >= 0x1A) {
            if (temp_16 < 0x74) {
                func_0025f3f0(0xFFFFFFU, 0xFF, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, -1.0f, -1.0f, 0.0f);
                func_003f6440(3, 0x50003);
                func_003f6440(2, 0x48);
                func_0025f3f0(0xFFFFFFU, 0x4C, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 0, -1.0f, -1.0f, 0.0f);
            } else if (temp_16 < 0xA1) {
                temp_f20_2 = (f32)(s32)(func_0044b7b0((fGpffff8094 * (f32) (temp_16 - 0x73)) / 45.0f));
                func_0025f3f0(0xFFFFFFU, 0xFF, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, -1.0f, -1.0f, 0.0f);
                func_003f6440(3, 0x50003);
                func_003f6440(2, 0x48);
    /* ACC seed */;
                temp_f1 = 255.0f * (temp_f20 * temp_f21 + temp_f7 * temp_f8);
                if (!(temp_f1 >= 2.1474836e9f)) {
                    var_5 = 0x4F000000 & 0xFF;
                } else {
                    var_5 = (M2C_BITWISE(s32, (temp_f1 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                func_0025f3f0(0xFFFFFFU, var_5, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 0, -1.0f, -1.0f, 0.0f);
            } else {
                func_0025f3f0(0xFFFFFFU, 0xFF, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, -1.0f, -1.0f, 0.0f);
                func_003f6440(3, 0x50003);
                func_003f6440(2, 0x48);
                func_0025f3f0(0xFFFFFFU, 0x2D, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 0, -1.0f, -1.0f, 0.0f);
            }
            var_3 = (M2C_UNK *)(&sp684);
            var_2 = 4;
            if ((u8 *)(var_3) != NULL) {
                do {
                    *var_3 = 0;
                    var_3 += 1;
                    var_2 -= 1;
                } while (var_2 != 0);
            }
            sp687 = 0xFF;
            sp688 = (f32) sp684;
            sp4B0 = D_005E5590;
            sp4C0 = D_005E5590;
            func_0045d6e0(&sp688, &sp4C0, 1, 0);
            sp4A0 = D_005E55A0;
            sp4C0 = D_005E55A0;
            func_0045d6e0(&sp688, &sp4C0, 1, 0);
            func_00126090(0xFF, temp_20, 0, 0, 0);
            if (temp_16 >= 0xCD) {
                var_3_2 = (f32 *)(&sp67C);
                var_2_2 = 4;
                if (var_3_2 != NULL) {
                    do {
                        *var_3_2 = 0;
                        var_3_2 += 1;
                        var_2_2 -= 1;
                    } while (var_2_2 != 0);
                }
                sp680 = sp67C;
                func_002aaf20(&sp680, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_3 = (M2C_UNK *)(&sp624);
                var_2_3 = 4;
                if ((u8 *)(var_3_3) != NULL) {
                    do {
                        *var_3_3 = 0;
                        var_3_3 += 1;
                        var_2_3 -= 1;
                    } while (var_2_3 != 0);
                }
                sp627 = 0xFF;
                sp628 = (f32) sp624;
                sp480 = D_005E5590;
                sp490 = D_005E5590;
                func_0045d6e0(&sp628, &sp490, 0, 0);
                sp470 = D_005E55A0;
                sp490 = D_005E55A0;
                func_0045d6e0(&sp628, &sp490, 0, 0);
                func_0048a000();
                temp_2_2 = (s32)(M2C_FIELD(temp_20, s32 *, 0x10) + 1);
                M2C_FIELD(temp_20, s32 *, 0x10) = temp_2_2;
                if (temp_2_2 >= 0x168) {
                    M2C_FIELD(temp_20, s32 *, 0x10) = 0;
                }
                func_0044b7b0((((fGpffff81dc + ((fGpffff81e0 * (f32) M2C_FIELD(temp_20, s32 *, 0x10)) / 360.0f)))));
                func_00125e80(0xB2, temp_20, (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f);
            }
            if (temp_16 >= 0x3E) {
                if (temp_16 < 0x11A) {
                    var_3_4 = (f32 *)(&sp6A4);
                    var_2_4 = 4;
                    if (var_3_4 != NULL) {
                        do {
                            *var_3_4 = 0;
                            var_3_4 += 1;
                            var_2_4 -= 1;
                        } while (var_2_4 != 0);
                    }
                    sp6BC = sp6A4;
                    func_002aaf20(&sp6BC, 0x12, 0, 0, 0, 0.0f, 0x44200000, 0x43E00000);
                    func_0044b7b0(((((fGpffff8094 * (f32) (temp_16 - 0x3D)) / 80.0f))));
                    var_19 = 1;
loop_93:
                    if (var_19 < 8) {
                        if ((u32) var_19 >= 0x13U) {
                            func_0046d730(D_005E5548, 0xD1);
                        }
                        temp_21 = (u8 *)((s32)&D_005E5230 + (var_19 * 0x28));
                        var_17 = (s32)((temp_16 - 0x3D) - M2C_FIELD(temp_21, s32 *, 0x20));
                        if (var_17 > 0) {
                            var_2_5 = var_17 - 0x32;
                            if (var_2_5 < 0) {
                                var_2_5 = 0;
                            } else if (var_2_5 >= 0x1F) {
                                var_2_5 = 0x1E;
                            }
                            temp_f20_3 = (f32)(s32)(func_0044b7b0(((((fGpffff8094 * (f32) var_2_5) / 30.0f)))));
                            if (var_17 >= 0x32) {
                                var_17 = 0x32;
                            }
                            temp_f21 = (f32)(s32)(func_0044b7b0(((((fGpffff8094 * (f32) var_17) / 50.0f)))));
                            if (var_17 == 1) {
                                temp_3_2 = (s32)(M2C_FIELD(temp_21, s32 *, 0));
                                if (temp_3_2 >= 0xF) {
                                    var_4 = NULL;
                                } else {
                                    temp_2_3 = (u32 *)(&temp_20[temp_3_2]);
                                    if (func_004782b0(M2C_FIELD(temp_2_3, u8 **, 0x44)) != 0) {
                                        var_4 = (u8 *)(M2C_FIELD(temp_2_3, u8 **, 0x44));
                                    } else {
                                        var_4 = NULL;
                                    }
                                }
                                if (var_4 != NULL) {
                                    func_00479940(var_4, 0, 1, 0, 1);
                                }
                            } else if (var_17 == 0x1E) {
                                temp_3_3 = (s32)(M2C_FIELD(temp_21, s32 *, 0));
                                if (temp_3_3 >= 0xF) {
                                    var_4_2 = NULL;
                                } else {
                                    temp_2_4 = (u32 *)(&temp_20[temp_3_3]);
                                    if (func_004782b0(M2C_FIELD(temp_2_4, u8 **, 0x44)) != 0) {
                                        var_4_2 = (u8 *)(M2C_FIELD(temp_2_4, u8 **, 0x44));
                                    } else {
                                        var_4_2 = NULL;
                                    }
                                }
                                if (var_4_2 != NULL) {
                                    func_00479940(var_4_2, 0, 0, 0x1E, 1);
                                }
                            }
                            if (temp_f21 < 1.0f) {
                                func_00124f70(var_19, M2C_BITWISE(s8, (255.0f * temp_f21)), 0, (u32 *)1, temp_20);
                            } else {
                                var_3_5 = (f32 *)(&sp6A0);
                                var_2_6 = 4;
                                if (var_3_5 != NULL) {
                                    do {
                                        *var_3_5 = 0;
                                        var_3_5 += 1;
                                        var_2_6 -= 1;
                                    } while (var_2_6 != 0);
                                }
                                sp6BC = sp6A0;
                                func_002aaf20(&sp6BC, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                                var_6 = (s128 *)(&sp130);
                                sp130 = D_005E5530;
                                sp140 = D_005E5540;
                                var_5_2 = (M2C_UNK *)(&sp450);
                                var_4_3 = 3;
                                do {
                                    temp_3_4 = (s32)(M2C_FIELD(var_6, s32 *, 0));
                                    temp_2_5 = (s32)(M2C_FIELD(var_6, s32 *, 4));
                                    var_6 += 8;
                                    var_4_3 -= 1;
                                    M2C_FIELD(var_5_2, s32 *, 0) = temp_3_4;
                                    M2C_FIELD(var_5_2, s32 *, 4) = temp_2_5;
                                    var_5_2 += 8;
                                } while (var_4_3 > 0);
                                temp_7 = (u8 *)((s32)&D_005E5230 + (var_19 * 0x28));
                                temp_9 = (s32)(M2C_FIELD(temp_7, s32 *, 0x1C) * 4);
                                temp_8 = (u32)(M2C_FIELD((temp_9 + sp), u32 *, 0x450));
                                temp_q1 = (f32)(s32)(255.0f * temp_f20) / 255.0f;
                                var_6_2 = (s128 *)(&sp130);
                                var_5_3 = (M2C_UNK *)(&sp430);
                                var_4_4 = 3;
                                do {
                                    temp_3_5 = (s32)(M2C_FIELD(var_6_2, s32 *, 0));
                                    temp_2_6 = (s32)(M2C_FIELD(var_6_2, s32 *, 4));
                                    var_6_2 += 8;
                                    var_4_4 -= 1;
                                    M2C_FIELD(var_5_3, s32 *, 0) = temp_3_5;
                                    M2C_FIELD(var_5_3, s32 *, 4) = temp_2_6;
                                    var_5_3 += 8;
                                } while (var_4_4 > 0);
                                temp_3_6 = (temp_8 >> 0x10) & 0xFF;
                                temp_9_2 = (temp_8 >> 0x18) & 0xFF;
                                temp_2_7 = (temp_8 >> 8) & 0xFF;
                                temp_cA = (f32)(u32)(0xFF - temp_9_2);
                                temp_cB = (f32)(u32)temp_9_2;
    /* ACC seed */;
                                temp_f1_2 = temp_cB + temp_cA * temp_q1;
                                var_8 = (u8)(u32)temp_f1_2;
                                temp_9_3 = (var_8 & 0xFF) << 0x18;
                                temp_cA = (f32)(u32)(0xFF - temp_3_6);
                                temp_cB = (f32)(u32)temp_3_6;
    /* ACC seed */;
                                temp_f1_3 = temp_cB + temp_cA * temp_q1;
                                var_6_3 = (u8)(u32)temp_f1_3;
                                temp_cA = (f32)(u32)(0xFF - temp_2_7);
                                temp_cB = (f32)(u32)temp_2_7;
    /* ACC seed */;
                                temp_f1_4 = temp_cB + temp_cA * temp_q1;
                                var_3_6 = (u8)(u32)temp_f1_4;
                                func_00124bb0(M2C_BITWISE(s32, (f32) M2C_FIELD(temp_7, s32 *, 0)), (M2C_FIELD((temp_9 + sp), s32 *, 0x430) & ~0xFF) | 0xFF, ((var_3_6 & 0xFF) << 8) | (temp_9_3 | ((var_6_3 & 0xFF) << 0x10)) | 0xFF, 0x42, temp_20, M2C_BITWISE(f32, temp_9_3), M2C_FIELD(temp_7, f32 *, 4), 0.0f, M2C_FIELD(temp_7, f32 *, 8), M2C_FIELD(temp_7, f32 *, 0xC), M2C_FIELD(temp_7, f32 *, 0x10), M2C_FIELD(temp_7, f32 *, 0x14), M2C_FIELD(temp_7, f32 *, 0x18));
                            }
                        }
                        var_19 += 1;
                        goto loop_93;
                    }
                } else {
                    var_17_2 = 1;
loop_128:
                    if (var_17_2 < 8) {
                        var_6_4 = (s128 *)(&sp110);
                        sp110 = D_005E5530;
                        sp120 = D_005E5540;
                        var_5_4 = (M2C_UNK *)(&sp1B0);
                        var_4_5 = 3;
                        do {
                            temp_3_7 = (s32)(M2C_FIELD(var_6_4, s32 *, 0));
                            temp_2_8 = (s32)(M2C_FIELD(var_6_4, s32 *, 4));
                            var_6_4 += 8;
                            var_4_5 -= 1;
                            M2C_FIELD(var_5_4, s32 *, 0) = temp_3_7;
                            M2C_FIELD(var_5_4, s32 *, 4) = temp_2_8;
                            var_5_4 += 8;
                        } while (var_4_5 > 0);
                        temp_7_2 = (u8 *)((s32)&D_005E5230 + (var_17_2 * 0x28));
                        temp_9_4 = (s32)(M2C_FIELD(temp_7_2, s32 *, 0x1C) * 4);
                        temp_8_2 = (u32)(M2C_FIELD((temp_9_4 + sp), u32 *, 0x1B0));
                        var_6_5 = (s128 *)(&sp110);
                        var_5_5 = (M2C_UNK *)(&sp190);
                        var_4_6 = 3;
                        do {
                            temp_3_8 = (s32)(M2C_FIELD(var_6_5, s32 *, 0));
                            temp_2_9 = (s32)(M2C_FIELD(var_6_5, s32 *, 4));
                            var_6_5 += 8;
                            var_4_6 -= 1;
                            M2C_FIELD(var_5_5, s32 *, 0) = temp_3_8;
                            M2C_FIELD(var_5_5, s32 *, 4) = temp_2_9;
                            var_5_5 += 8;
                        } while (var_4_6 > 0);
                        temp_3_9 = (temp_8_2 >> 0x10) & 0xFF;
                        temp_9_5 = (temp_8_2 >> 0x18) & 0xFF;
                        temp_2_10 = (temp_8_2 >> 8) & 0xFF;
                        temp_cA = (f32)(u32)(0xFF - temp_9_5);
                        temp_one_S2A = 1.0f;
                        temp_cB = (f32)(u32)temp_9_5;
    /* ACC seed */;
                        temp_f1_5 = temp_cB + temp_cA * temp_one_S2A;
                        var_8_2 = (u8)(u32)temp_f1_5;
                        temp_9_6 = (var_8_2 & 0xFF) << 0x18;
                        temp_cA = (f32)(u32)(0xFF - temp_3_9);
                        temp_one_S2B = 1.0f;
                        temp_cB = (f32)(u32)temp_3_9;
    /* ACC seed */;
                        temp_f1_6 = temp_cB + temp_cA * temp_one_S2B;
                        var_6_6 = (u8)(u32)temp_f1_6;
                        temp_cA = (f32)(u32)(0xFF - temp_2_10);
                        temp_one_S2C = 1.0f;
                        temp_cB = (f32)(u32)temp_2_10;
    /* ACC seed */;
                        temp_f1_7 = temp_cB + temp_cA * temp_one_S2C;
                        var_3_7 = (u8)(u32)temp_f1_7;
                        func_00124bb0(M2C_BITWISE(s32, (f32) M2C_FIELD(temp_7_2, s32 *, 0)), (M2C_FIELD((temp_9_4 + sp), s32 *, 0x190) & ~0xFF) | 0xFF, ((var_3_7 & 0xFF) << 8) | (temp_9_6 | ((var_6_6 & 0xFF) << 0x10)) | 0xFF, 0x42, temp_20, M2C_BITWISE(f32, temp_9_6), M2C_FIELD(temp_7_2, f32 *, 4), 0.0f, M2C_FIELD(temp_7_2, f32 *, 8), M2C_FIELD(temp_7_2, f32 *, 0xC), M2C_FIELD(temp_7_2, f32 *, 0x10), M2C_FIELD(temp_7_2, f32 *, 0x14), M2C_FIELD(temp_7_2, f32 *, 0x18));
                        var_17_2 += 1;
                        goto loop_128;
                    }
                }
            }
            if (temp_16 >= 0x82) {
                if (temp_16 < 0xBE) {
                    temp_17 = temp_16 - 0x81;
                    func_0044b7b0(((((fGpffff8094 * (f32) temp_17) / 60.0f))));
                    if (temp_17 == 1) {
                        if (D_005E5230 >= 0xF) {
                            var_4_7 = NULL;
                        } else {
                            temp_2_11 = (u32 *)(&temp_20[D_005E5230]);
                            if (func_004782b0(M2C_FIELD(temp_2_11, u8 **, 0x44)) != 0) {
                                var_4_7 = (u8 *)(M2C_FIELD(temp_2_11, u8 **, 0x44));
                            } else {
                                var_4_7 = NULL;
                            }
                        }
                        if (var_4_7 != NULL) {
                            func_00479940(var_4_7, 0, 2, 0, 1);
                        }
                        if (func_004782b0(M2C_FIELD(temp_20, u8 **, 0x44)) != 0) {
                            var_4_8 = (u8 *)(M2C_FIELD(temp_20, u8 **, 0x44));
                        } else {
                            var_4_8 = NULL;
                        }
                        func_0047a0e0(var_4_8, 0, fGpffff8110);
                    } else if (temp_17 == 0x3A) {
                        if (D_005E5230 >= 0xF) {
                            var_4_9 = NULL;
                        } else {
                            temp_2_12 = (u32 *)(&temp_20[D_005E5230]);
                            if (func_004782b0(M2C_FIELD(temp_2_12, u8 **, 0x44)) != 0) {
                                var_4_9 = (u8 *)(M2C_FIELD(temp_2_12, u8 **, 0x44));
                            } else {
                                var_4_9 = NULL;
                            }
                        }
                        if (var_4_9 != NULL) {
                            func_00479940(var_4_9, 0, 0, 0xF, 1);
                        }
                    }
                    var_6_7 = (s128 *)(&spF0);
                    spF0 = D_005E5530;
                    sp100 = D_005E5540;
                    var_5_6 = (M2C_UNK *)(&sp410);
                    var_4_10 = 3;
                    do {
                        temp_3_10 = (s32)(M2C_FIELD(var_6_7, s32 *, 0));
                        temp_2_13 = (s32)(M2C_FIELD(var_6_7, s32 *, 4));
                        var_6_7 += 8;
                        var_4_10 -= 1;
                        M2C_FIELD(var_5_6, s32 *, 0) = temp_3_10;
                        M2C_FIELD(var_5_6, s32 *, 4) = temp_2_13;
                        var_5_6 += 8;
                    } while (var_4_10 > 0);
                    temp_8_3 = D_005E538C * 4;
                    temp_7_3 = (u32)(M2C_FIELD((temp_8_3 + sp), u32 *, 0x410));
                    var_6_8 = (s128 *)(&spF0);
                    var_5_7 = (M2C_UNK *)(&sp3F0);
                    var_4_11 = 3;
                    do {
                        temp_3_11 = (s32)(M2C_FIELD(var_6_8, s32 *, 0));
                        temp_2_14 = (s32)(M2C_FIELD(var_6_8, s32 *, 4));
                        var_6_8 += 8;
                        var_4_11 -= 1;
                        M2C_FIELD(var_5_7, s32 *, 0) = temp_3_11;
                        M2C_FIELD(var_5_7, s32 *, 4) = temp_2_14;
                        var_5_7 += 8;
                    } while (var_4_11 > 0);
                    temp_3_12 = (temp_7_3 >> 0x10) & 0xFF;
                    temp_8_4 = (temp_7_3 >> 0x18) & 0xFF;
                    temp_2_15 = (temp_7_3 >> 8) & 0xFF;
                    temp_cA = (f32)(u32)(0xFF - temp_8_4);
                    temp_one_S3A = 1.0f;
                    temp_cB = (f32)(u32)temp_8_4;
    /* ACC seed */;
                    temp_f7 = temp_cB + temp_cA * temp_one_S3A;
                    var_7 = (u8)(u32)temp_f7;
                    temp_cA = (f32)(u32)(0xFF - temp_3_12);
                    temp_one_S3B = 1.0f;
                    temp_cB = (f32)(u32)temp_3_12;
    /* ACC seed */;
                    temp_f7_2 = temp_cB + temp_cA * temp_one_S3B;
                    var_6_9 = (u8)(u32)temp_f7_2;
                    temp_cA = (f32)(u32)(0xFF - temp_2_15);
                    temp_one_S3C = 1.0f;
                    temp_cB = (f32)(u32)temp_2_15;
    /* ACC seed */;
                    temp_f7_3 = temp_cB + temp_cA * temp_one_S3C;
                    var_3_8 = (u8)(u32)temp_f7_3;
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
                    func_00124bb0(M2C_BITWISE(s32, (f32) D_005E5370), (M2C_FIELD((temp_8_3 + sp), s32 *, 0x3F0) & ~0xFF) | 0xFF, ((var_3_8 & 0xFF) << 8) | (((var_7 & 0xFF) << 0x18) | ((var_6_9 & 0xFF) << 0x10)) | 0xFF, 0x40, temp_20, (temp_f20 * temp_f21 + temp_f7 * temp_f8), 0.0f, (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8));
                } else if (temp_16 < 0xD2) {
                    func_0044b7b0(((((fGpffff8094 * (f32) (temp_16 - 0xBD)) / 20.0f))));
                    var_6_10 = (s128 *)(&spD0);
                    spD0 = D_005E5530;
                    spE0 = D_005E5540;
                    var_5_8 = (M2C_UNK *)(&sp3D0);
                    var_4_12 = 3;
                    do {
                        temp_3_13 = (s32)(M2C_FIELD(var_6_10, s32 *, 0));
                        temp_2_16 = (s32)(M2C_FIELD(var_6_10, s32 *, 4));
                        var_6_10 += 8;
                        var_4_12 -= 1;
                        M2C_FIELD(var_5_8, s32 *, 0) = temp_3_13;
                        M2C_FIELD(var_5_8, s32 *, 4) = temp_2_16;
                        var_5_8 += 8;
                    } while (var_4_12 > 0);
                    temp_8_5 = D_005E53B4 * 4;
                    temp_7_4 = (u32)(M2C_FIELD((temp_8_5 + sp), u32 *, 0x3D0));
                    var_6_11 = (s128 *)(&spD0);
                    var_5_9 = (M2C_UNK *)(&sp3B0);
                    var_4_13 = 3;
                    do {
                        temp_3_14 = (s32)(M2C_FIELD(var_6_11, s32 *, 0));
                        temp_2_17 = (s32)(M2C_FIELD(var_6_11, s32 *, 4));
                        var_6_11 += 8;
                        var_4_13 -= 1;
                        M2C_FIELD(var_5_9, s32 *, 0) = temp_3_14;
                        M2C_FIELD(var_5_9, s32 *, 4) = temp_2_17;
                        var_5_9 += 8;
                    } while (var_4_13 > 0);
                    temp_3_15 = (temp_7_4 >> 0x10) & 0xFF;
                    temp_8_6 = (temp_7_4 >> 0x18) & 0xFF;
                    temp_2_18 = (temp_7_4 >> 8) & 0xFF;
                    temp_cA = (f32)(u32)(0xFF - temp_8_6);
                    temp_one_S4A = 1.0f;
                    temp_cB = (f32)(u32)temp_8_6;
    /* ACC seed */;
                    temp_f8 = temp_cB + temp_cA * temp_one_S4A;
                    var_7_2 = (u8)(u32)temp_f8;
                    temp_cA = (f32)(u32)(0xFF - temp_3_15);
                    temp_one_S4B = 1.0f;
                    temp_cB = (f32)(u32)temp_3_15;
    /* ACC seed */;
                    temp_f8_2 = temp_cB + temp_cA * temp_one_S4B;
                    var_6_12 = (u8)(u32)temp_f8_2;
                    temp_cA = (f32)(u32)(0xFF - temp_2_18);
                    temp_one_S4C = 1.0f;
                    temp_cB = (f32)(u32)temp_2_18;
    /* ACC seed */;
                    temp_f8_3 = temp_cB + temp_cA * temp_one_S4C;
                    var_3_9 = (u8)(u32)temp_f8_3;
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
                    func_00124bb0(M2C_BITWISE(s32, (f32) D_005E5398), (M2C_FIELD((temp_8_5 + sp), s32 *, 0x3B0) & ~0xFF) | 0xFF, ((var_3_9 & 0xFF) << 8) | (((var_7_2 & 0xFF) << 0x18) | ((var_6_12 & 0xFF) << 0x10)) | 0xFF, 0x40, temp_20, (temp_f20 * temp_f21 + temp_f7 * temp_f8), 0.0f, (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8));
                } else {
                    func_00124f70(0xA, 0xFF, 0xFF, (u32 *)0x40, temp_20);
                }
            }
            if (temp_16 < 0x74) {
                temp_f20_4 = (f32)(s32)(func_0044b7b0(((((fGpffff8094 * (f32) (temp_16 - 0x19)) / 90.0f)))));
                var_3_10 = (f32 *)(&sp674);
                var_2_7 = 4;
                if (var_3_10 != NULL) {
                    do {
                        *var_3_10 = 0;
                        var_3_10 += 1;
                        var_2_7 -= 1;
                    } while (var_2_7 != 0);
                }
                sp678 = sp674;
                func_002aaf20(&sp678, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_11 = (M2C_UNK *)(&sp61C);
                var_2_8 = 4;
                if ((u8 *)(var_3_11) != NULL) {
                    do {
                        *var_3_11 = 0;
                        var_3_11 += 1;
                        var_2_8 -= 1;
                    } while (var_2_8 != 0);
                }
                sp61F = 0xFF;
                sp620 = (f32) sp61C;
                sp390 = D_005E5590;
                sp3A0 = D_005E5590;
                func_0045d6e0(&sp620, &sp3A0, 0, 0);
                sp380 = D_005E55A0;
                sp3A0 = D_005E55A0;
                func_0045d6e0(&sp620, &sp3A0, 0, 0);
                func_0048a000();
                func_002aaac0();
                D_00887300[0](6, 1);
                func_003f6440(3, 0x50003);
                func_003f6440(2, 0x48);
                temp_f1_8 = 255.0f * (1.0f - temp_f20_4);
                if (!(temp_f1_8 >= 2.1474836e9f)) {
                    var_5_10 = 0x4F000000 & 0xFF;
                } else {
                    var_5_10 = (M2C_BITWISE(s32, (temp_f1_8 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                func_0025f3f0(0xFFFFFFU, var_5_10, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 0, -1.0f, -1.0f, 10.0f);
            }
            if (temp_16 == 0x55) {
                func_0045ad50(2, func_00455f70(&D_005E56D0, &sp6B8), sp6B8);
            }
            if (temp_16 >= 0x5B) {
                if (temp_16 < 0x65) {
                    temp_f2 = (f32)(s32)(255.0f * func_0044b7b0(((((fGpffff8094 * (f32) (temp_16 - 0x5A)) / 10.0f)))));
                    if (!(temp_f2 >= 2.1474836e9f)) {
                        var_5_11 = 0x4F000000 & 0xFF;
                    } else {
                        var_5_11 = (M2C_BITWISE(s32, (temp_f2 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                    }
    /* ACC seed */;
                    temp_f14 = 0.0f;
                    func_0025f430(0xFFFFFFU, var_5_11, 0x10001, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 0, 0, (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), temp_f14, temp_f14, 1.0f, 1.0f);
                } else {
                    func_0025f3f0(0xFFFFFFU, 0xFF, 0x10001, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 195.0f, 72.0f, 0.0f);
                }
            }
            if ((temp_16 >= 0xBC) && (temp_16 < 0xDF)) {
                temp_f2_2 = (f32)(s32)(fGpffff8094);
                temp_f1_9 = 255.0f * func_0044b7b0((((temp_f2_2 + ((temp_f2_2 * (f32) (temp_16 - 0xBB)) / 35.0f)))));
                if (!(temp_f1_9 >= 2.1474836e9f)) {
                    var_5_12 = 0x4F000000 & 0xFF;
                } else {
                    var_5_12 = (M2C_BITWISE(s32, (temp_f1_9 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                func_0025f3f0(0xFFFFFFU, var_5_12, 0x10009, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 195.0f, 72.0f, 0.0f);
            }
            if (temp_16 < 0x74) {
                var_3_12 = (f32 *)(&sp66C);
                var_2_9 = 4;
                if (var_3_12 != NULL) {
                    do {
                        *var_3_12 = 0;
                        var_3_12 += 1;
                        var_2_9 -= 1;
                    } while (var_2_9 != 0);
                }
                sp670 = sp66C;
                func_002aaf20(&sp670, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_13 = (M2C_UNK *)(&sp614);
                var_2_10 = 4;
                if ((u8 *)(var_3_13) != NULL) {
                    do {
                        *var_3_13 = 0;
                        var_3_13 += 1;
                        var_2_10 -= 1;
                    } while (var_2_10 != 0);
                }
                sp617 = 0xFF;
                sp618 = (f32) sp614;
                sp360 = D_005E5590;
                sp370 = D_005E5590;
                func_0045d6e0(&sp618, &sp370, 0, 0);
                sp350 = D_005E55A0;
                sp370 = D_005E55A0;
                func_0045d6e0(&sp618, &sp370, 0, 0);
                func_0048a000();
                func_0025f3f0(0xFFFFFFU, 0xFF, 0x10002, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 268.0f, (f32) 0x169, 10.0f);
            } else {
                func_0025f3f0(0xFFFFFFU, 0xFF, 0x10002, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 268.0f, (f32) 0x169, 0.0f);
            }
            if (temp_16 < 0x56) {
                var_3_14 = (f32 *)(&sp664);
                var_2_11 = 4;
                if (var_3_14 != NULL) {
                    do {
                        *var_3_14 = 0;
                        var_3_14 += 1;
                        var_2_11 -= 1;
                    } while (var_2_11 != 0);
                }
                sp668 = sp664;
                func_002aaf20(&sp668, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_15 = (M2C_UNK *)(&sp60C);
                var_2_12 = 4;
                if ((u8 *)(var_3_15) != NULL) {
                    do {
                        *var_3_15 = 0;
                        var_3_15 += 1;
                        var_2_12 -= 1;
                    } while (var_2_12 != 0);
                }
                sp60F = 0xFF;
                sp610 = (f32) sp60C;
                sp330 = D_005E5590;
                sp340 = D_005E5590;
                func_0045d6e0(&sp610, &sp340, 0, 0);
                sp320 = D_005E55A0;
                sp340 = D_005E55A0;
                func_0045d6e0(&sp610, &sp340, 0, 0);
                func_0048a000();
                func_002aaac0();
                D_00887300[0](6, 1);
                func_003f6440(3, 0x50003);
                func_003f6440(2, 0x48);
                func_0025f3f0(0xFFFFFFU, 0xFF, 0x1000A, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 0, 268.0f, (f32) 0x169, 10.0f);
            } else if (temp_16 < 0x92) {
                var_3_16 = (f32 *)(&sp65C);
                var_2_13 = 4;
                if (var_3_16 != NULL) {
                    do {
                        *var_3_16 = 0;
                        var_3_16 += 1;
                        var_2_13 -= 1;
                    } while (var_2_13 != 0);
                }
                sp660 = sp65C;
                func_002aaf20(&sp660, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_17 = (M2C_UNK *)(&sp604);
                var_2_14 = 4;
                if ((u8 *)(var_3_17) != NULL) {
                    do {
                        *var_3_17 = 0;
                        var_3_17 += 1;
                        var_2_14 -= 1;
                    } while (var_2_14 != 0);
                }
                sp607 = 0xFF;
                sp608 = (f32) sp604;
                sp300 = D_005E5590;
                sp310 = D_005E5590;
                func_0045d6e0(&sp608, &sp310, 0, 0);
                sp2F0 = D_005E55A0;
                sp310 = D_005E55A0;
                func_0045d6e0(&sp608, &sp310, 0, 0);
                func_0048a000();
                temp_f22 = (f32)(s32)(func_0044b7b0(((((fGpffff8094 * (f32) (temp_16 - 0x55)) / 60.0f)))));
                func_002aaac0();
                D_00887300[0](6, 1);
                func_003f6440(3, 0x50003);
                func_003f6440(2, 0x48);
                temp_f1_10 = 255.0f * (1.0f - temp_f22);
                if (!(temp_f1_10 >= 2.1474836e9f)) {
                    var_5_13 = 0x4F000000 & 0xFF;
                } else {
                    var_5_13 = (M2C_BITWISE(s32, (temp_f1_10 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                func_0025f3f0(0xFFFFFFU, var_5_13, 0x1000A, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 0, 268.0f, (f32) 0x169, 10.0f);
            }
            if (temp_16 < 0x56) {
                var_3_18 = (f32 *)(&sp654);
                var_2_15 = 4;
                if (var_3_18 != NULL) {
                    do {
                        *var_3_18 = 0;
                        var_3_18 += 1;
                        var_2_15 -= 1;
                    } while (var_2_15 != 0);
                }
                sp658 = sp654;
                func_002aaf20(&sp658, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_19 = (M2C_UNK *)(&sp5FC);
                var_2_16 = 4;
                if ((u8 *)(var_3_19) != NULL) {
                    do {
                        *var_3_19 = 0;
                        var_3_19 += 1;
                        var_2_16 -= 1;
                    } while (var_2_16 != 0);
                }
                sp5FF = 0xFF;
                sp600 = (f32) sp5FC;
                sp2D0 = D_005E5590;
                sp2E0 = D_005E5590;
                func_0045d6e0(&sp600, &sp2E0, 0, 0);
                sp2C0 = D_005E55A0;
                sp2E0 = D_005E55A0;
                func_0045d6e0(&sp600, &sp2E0, 0, 0);
                func_0048a000();
                func_00125e80(0xFF, temp_20, 200.0f, 0.0f, 10.0f);
            } else if (temp_16 < 0xCE) {
                var_3_20 = (f32 *)(&sp64C);
                var_2_17 = 4;
                if (var_3_20 != NULL) {
                    do {
                        *var_3_20 = 0;
                        var_3_20 += 1;
                        var_2_17 -= 1;
                    } while (var_2_17 != 0);
                }
                sp650 = sp64C;
                func_002aaf20(&sp650, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_21 = (M2C_UNK *)(&sp5F4);
                var_2_18 = 4;
                if ((u8 *)(var_3_21) != NULL) {
                    do {
                        *var_3_21 = 0;
                        var_3_21 += 1;
                        var_2_18 -= 1;
                    } while (var_2_18 != 0);
                }
                sp5F7 = 0xFF;
                sp5F8 = (f32) sp5F4;
                sp2A0 = D_005E5590;
                sp2B0 = D_005E5590;
                func_0045d6e0(&sp5F8, &sp2B0, 0, 0);
                sp290 = D_005E55A0;
                sp2B0 = D_005E55A0;
                func_0045d6e0(&sp5F8, &sp2B0, 0, 0);
                func_0048a000();
                func_0044b7b0(((((fGpffff8094 * (f32) (temp_16 - 0x55)) / 120.0f))));
                func_00125e80(0xFF, temp_20, (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f);
            }
            if (temp_16 < 0xE2) {
                var_3_22 = (f32 *)(&sp644);
                var_2_19 = 4;
                if (var_3_22 != NULL) {
                    do {
                        *var_3_22 = 0;
                        var_3_22 += 1;
                        var_2_19 -= 1;
                    } while (var_2_19 != 0);
                }
                sp648 = sp644;
                func_002aaf20(&sp648, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
                func_002aaac0();
                D_00887300[0](8, 1);
                func_00489f80();
                var_3_23 = (M2C_UNK *)(&sp5EC);
                var_2_20 = 4;
                if ((u8 *)(var_3_23) != NULL) {
                    do {
                        *var_3_23 = 0;
                        var_3_23 += 1;
                        var_2_20 -= 1;
                    } while (var_2_20 != 0);
                }
                sp5EF = 0xFF;
                sp5F0 = (f32) sp5EC;
                sp270 = D_005E5590;
                sp280 = D_005E5590;
                func_0045d6e0(&sp5F0, &sp280, 0, 0);
                sp260 = D_005E55A0;
                sp280 = D_005E55A0;
                func_0045d6e0(&sp5F0, &sp280, 0, 0);
                func_0048a000();
                temp_f20_5 = (f32)(s32)(func_0044b7b0(((((fGpffff8094 * (f32) temp_16) / 225.0f)))));
                if (temp_16 >= 0x88) {
                    var_2_21 = temp_16 - 0x87;
                } else {
                    var_2_21 = 0;
                }
                temp_f16 = (f32)(s32)(fGpffff8170 + (1.5f * temp_f20_5));
                temp_f21_2 = (f32)(s32)(255.0f * (1.0f - func_0044b7b0(((((fGpffff8094 * (f32) var_2_21) / 90.0f))))));
                var_f0 = 2.1474836e9f;
                if (!(temp_f21_2 >= 2.1474836e9f)) {
                    var_5_14 = 0x4F000000 & 0xFF;
                } else {
                    var_f0 = temp_f21_2 - 2.1474836e9f;
                    var_5_14 = (M2C_BITWISE(s32, var_f0) | 0x80000000) & 0xFF;
                }
                temp_10 = (s32) (M2C_BITWISE(s32, var_f0) << 16) >> 16;
    /* ACC seed */;
                func_0025f430(0xFFFFFFU, var_5_14, 0x1000E, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, temp_10, temp_10, -3.0f, -76.0f, 10.0f, (temp_f20 * temp_f21 + temp_f7 * temp_f8), temp_f16, temp_f16);
                if (!(temp_f21_2 >= 2.1474836e9f)) {
                    var_5_15 = 0x4F000000 & 0xFF;
                } else {
                    var_5_15 = (M2C_BITWISE(s32, (temp_f21_2 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
    /* ACC seed */;
                temp_f16_2 = (f32)(s32)(fGpffff80bc);
                func_0025f430(0xFFFFFFU, var_5_15, 0x1000E, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 0x6B, 0xE6, -9.0f, 33.0f, 10.0f, (temp_f20 * temp_f21 + temp_f7 * temp_f8), temp_f16_2, temp_f16_2);
            }
        }
        if (temp_16 < 0x19) {
            var_3_24 = (f32 *)(&sp63C);
            var_2_22 = 4;
            if (var_3_24 != NULL) {
                do {
                    *var_3_24 = 0;
                    var_3_24 += 1;
                    var_2_22 -= 1;
                } while (var_2_22 != 0);
            }
            sp640 = sp63C;
            func_002aaf20(&sp640, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
            func_002aaac0();
            D_00887300[0](8, 1);
            func_00489f80();
            var_3_25 = (M2C_UNK *)(&sp5E4);
            var_2_23 = 4;
            if ((u8 *)(var_3_25) != NULL) {
                do {
                    *var_3_25 = 0;
                    var_3_25 += 1;
                    var_2_23 -= 1;
                } while (var_2_23 != 0);
            }
            sp5E7 = 0xFF;
            sp5E8 = (f32) sp5E4;
            sp240 = D_005E5590;
            sp250 = D_005E5590;
            func_0045d6e0(&sp5E8, &sp250, 0, 0);
            sp230 = D_005E55A0;
            sp250 = D_005E55A0;
            func_0045d6e0(&sp5E8, &sp250, 0, 0);
            func_0048a000();
            sp69C = (f32)(s32)(fGpffff9c80);
            if (!(2.1474836e9f <= 255.0f)) {
                var_3_26 = 0x4F000000 & 0xFF;
            } else {
                var_3_26 = (M2C_BITWISE(s32, (255.0f - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            unksp69F = var_3_26;
            sp6BC = sp69C;
            sp500 = D_005E5670;
            sp590 = D_005E5670;
            func_0045d6e0(&sp6BC, &sp590, 1, 0x41200000);
        } else if (temp_16 < 0x56) {
            var_3_27 = (f32 *)(&sp634);
            var_2_24 = 4;
            if (var_3_27 != NULL) {
                do {
                    *var_3_27 = 0;
                    var_3_27 += 1;
                    var_2_24 -= 1;
                } while (var_2_24 != 0);
            }
            sp638 = sp634;
            func_002aaf20(&sp638, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
            func_002aaac0();
            D_00887300[0](8, 1);
            func_00489f80();
            var_3_28 = (M2C_UNK *)(&sp5DC);
            var_2_25 = 4;
            if ((u8 *)(var_3_28) != NULL) {
                do {
                    *var_3_28 = 0;
                    var_3_28 += 1;
                    var_2_25 -= 1;
                } while (var_2_25 != 0);
            }
            sp5DF = 0xFF;
            sp5E0 = (f32) sp5DC;
            sp210 = D_005E5590;
            sp220 = D_005E5590;
            func_0045d6e0(&sp5E0, &sp220, 0, 0);
            sp200 = D_005E55A0;
            sp220 = D_005E55A0;
            func_0045d6e0(&sp5E0, &sp220, 0, 0);
            func_0048a000();
            temp_f2_3 = (f32)(s32)(fGpffff8094);
            temp_f0_5 = func_0044b7b0((((temp_f2_3 + ((temp_f2_3 * (f32) (temp_16 - 0x19)) / 60.0f)))));
            sp698 = (f32)(s32)(fGpffff9c84);
            temp_f1_11 = 255.0f * temp_f0_5;
            if (!(temp_f1_11 >= 2.1474836e9f)) {
                var_3_29 = 0x4F000000 & 0xFF;
            } else {
                var_3_29 = (M2C_BITWISE(s32, (temp_f1_11 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            unksp69B = var_3_29;
            sp6BC = sp698;
            sp4F0 = D_005E5680;
            sp590 = D_005E5680;
            func_0045d6e0(&sp6BC, &sp590, 1, 0x41200000);
        }
        break;
    case 6:
    case 7:
        var_3_30 = (s32)(M2C_FIELD(temp_20, s32 *, 0xC) + 1);
        M2C_FIELD(temp_20, s32 *, 0xC) = var_3_30;
        if (var_3_30 >= 0x14) {
            var_3_30 = 0x14;
        }
        func_0025f3f0(0xFFFFFFU, 0xFF, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, -1.0f, -1.0f, 0.0f);
        func_003f6440(3, 0x50003);
        func_003f6440(2, 0x48);
        func_0025f3f0(0xFFFFFFU, 0x2D, 0, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 0, -1.0f, -1.0f, 0.0f);
        temp_f0_6 = (f32)(s32)(fGpffff9c88);
        sp694 = temp_f0_6;
        sp6BC = temp_f0_6;
        sp4E0 = D_005E5690;
        sp590 = D_005E5690;
        func_0045d6e0(&sp6BC, &sp590, 1, 0);
        sp4D0 = D_005E56A0;
        sp590 = D_005E56A0;
        func_0045d6e0(&sp6BC, &sp590, 1, 0);
        func_00126090(0xFF, temp_20, 0, 0, 0);
        var_3_31 = (f32 *)(&sp62C);
        var_2_26 = 4;
        if (var_3_31 != NULL) {
            do {
                *var_3_31 = 0;
                var_3_31 += 1;
                var_2_26 -= 1;
            } while (var_2_26 != 0);
        }
        sp630 = sp62C;
        func_002aaf20(&sp630, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
        func_002aaac0();
        D_00887300[0](8, 1);
        func_00489f80();
        var_3_32 = (M2C_UNK *)(&sp5D4);
        var_2_27 = 4;
        if ((u8 *)(var_3_32) != NULL) {
            do {
                *var_3_32 = 0;
                var_3_32 += 1;
                var_2_27 -= 1;
            } while (var_2_27 != 0);
        }
        sp5D7 = 0xFF;
        sp5D8 = (f32) sp5D4;
        sp1E0 = D_005E5590;
        sp1F0 = D_005E5590;
        func_0045d6e0(&sp5D8, &sp1F0, 0, 0);
        sp1D0 = D_005E55A0;
        sp1F0 = D_005E55A0;
        func_0045d6e0(&sp5D8, &sp1F0, 0, 0);
        func_0048a000();
        temp_2_19 = (s32)(M2C_FIELD(temp_20, s32 *, 0x10) + 1);
        M2C_FIELD(temp_20, s32 *, 0x10) = temp_2_19;
        if (temp_2_19 >= 0x168) {
            M2C_FIELD(temp_20, s32 *, 0x10) = 0;
        }
        func_0044b7b0((((fGpffff81dc + ((fGpffff81e0 * (f32) M2C_FIELD(temp_20, s32 *, 0x10)) / 360.0f)))));
        func_00125e80(0x99, temp_20, (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f);
        var_3_33 = (f32 *)(&sp690);
        var_2_28 = 4;
        if (var_3_33 != NULL) {
            do {
                *var_3_33 = 0;
                var_3_33 += 1;
                var_2_28 -= 1;
            } while (var_2_28 != 0);
        }
        sp6BC = sp690;
        func_002aaf20(&sp6BC, 0x12, 0, 0, 0, (f32) 0xFFFF, 0x44200000, 0x43E00000);
        var_16 = 1;
loop_351:
        if (var_16 < 8) {
            var_6_13 = (s128 *)(&spB0);
            spB0 = D_005E5530;
            spC0 = D_005E5540;
            var_5_16 = (M2C_UNK *)(&sp170);
            var_4_14 = 3;
            do {
                temp_3_16 = (s32)(M2C_FIELD(var_6_13, s32 *, 0));
                temp_2_20 = (s32)(M2C_FIELD(var_6_13, s32 *, 4));
                var_6_13 += 8;
                var_4_14 -= 1;
                M2C_FIELD(var_5_16, s32 *, 0) = temp_3_16;
                M2C_FIELD(var_5_16, s32 *, 4) = temp_2_20;
                var_5_16 += 8;
            } while (var_4_14 > 0);
            temp_7_5 = (u8 *)((s32)&D_005E5230 + (var_16 * 0x28));
            temp_9_7 = (s32)(M2C_FIELD(temp_7_5, s32 *, 0x1C) * 4);
            temp_8_7 = (u32)(M2C_FIELD((temp_9_7 + sp), u32 *, 0x170));
            var_6_14 = (s128 *)(&spB0);
            var_5_17 = (M2C_UNK *)(&sp150);
            var_4_15 = 3;
            do {
                temp_3_17 = (s32)(M2C_FIELD(var_6_14, s32 *, 0));
                temp_2_21 = (s32)(M2C_FIELD(var_6_14, s32 *, 4));
                var_6_14 += 8;
                var_4_15 -= 1;
                M2C_FIELD(var_5_17, s32 *, 0) = temp_3_17;
                M2C_FIELD(var_5_17, s32 *, 4) = temp_2_21;
                var_5_17 += 8;
            } while (var_4_15 > 0);
            temp_3_18 = (temp_8_7 >> 0x10) & 0xFF;
            temp_9_8 = (temp_8_7 >> 0x18) & 0xFF;
            temp_2_22 = (temp_8_7 >> 8) & 0xFF;
            temp_cA = (f32)(u32)(0xFF - temp_9_8);
            temp_one_S5A = 1.0f;
            temp_cB = (f32)(u32)temp_9_8;
    /* ACC seed */;
            temp_f1_12 = temp_cB + temp_cA * temp_one_S5A;
            var_8_3 = (u8)(u32)temp_f1_12;
            temp_9_9 = (var_8_3 & 0xFF) << 0x18;
            temp_cA = (f32)(u32)(0xFF - temp_3_18);
            temp_one_S5B = 1.0f;
            temp_cB = (f32)(u32)temp_3_18;
    /* ACC seed */;
            temp_f1_13 = temp_cB + temp_cA * temp_one_S5B;
            var_6_15 = (u8)(u32)temp_f1_13;
            temp_cA = (f32)(u32)(0xFF - temp_2_22);
            temp_one_S5C = 1.0f;
            temp_cB = (f32)(u32)temp_2_22;
    /* ACC seed */;
            temp_f1_14 = temp_cB + temp_cA * temp_one_S5C;
            var_3_34 = (u8)(u32)temp_f1_14;
            func_00124bb0(M2C_BITWISE(s32, (f32) M2C_FIELD(temp_7_5, s32 *, 0)), (M2C_FIELD((temp_9_7 + sp), s32 *, 0x150) & ~0xFF) | 0xFF, ((var_3_34 & 0xFF) << 8) | (temp_9_9 | ((var_6_15 & 0xFF) << 0x10)) | 0xFF, 0x42, temp_20, M2C_BITWISE(f32, temp_9_9), M2C_FIELD(temp_7_5, f32 *, 4), 0.0f, M2C_FIELD(temp_7_5, f32 *, 8), M2C_FIELD(temp_7_5, f32 *, 0xC), M2C_FIELD(temp_7_5, f32 *, 0x10), M2C_FIELD(temp_7_5, f32 *, 0x14), M2C_FIELD(temp_7_5, f32 *, 0x18));
            var_16 += 1;
            goto loop_351;
        }
        func_00124f70(0xA, 0xFF, 0xFF, (u32 *)0x40, temp_20);
        func_0025f3f0(0xFFFFFFU, 0xFF, 0x10001, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 195.0f, 72.0f, 0.0f);
        temp_f1_15 = 255.0f * ((f32) var_3_30 / 20.0f);
        if (!(temp_f1_15 >= 2.1474836e9f)) {
            var_5_18 = 0x4F000000 & 0xFF;
        } else {
            var_5_18 = (M2C_BITWISE(s32, (temp_f1_15 - 2.1474836e9f)) | 0x80000000) & 0xFF;
        }
        func_0025f430(0xFFFFFFU, var_5_18, 0x10007, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 0, 0, 204.0f, (f32) 0x143, 0.0f, 0.0f, 1.0f, 1.0f);
        func_0025f3f0(0xFFFFFFU, 0xFF, 0x10002, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 268.0f, (f32) 0x169, 0.0f);
        break;
    case 8:
    case 9:
        if (M2C_FIELD(temp_20, s32 *, 0xC) == 0) {
            temp_f0_7 = (f32) *((u8 *)(&D_005E5230 + (M2C_FIELD(temp_20, u32 *, 0x84) * 0x28)));
            if (M2C_BITWISE(s32, temp_f0_7) >= 0xF) {
                var_4_16 = NULL;
            } else {
                temp_2_23 = (u32 *)(&temp_20[M2C_BITWISE(s32, temp_f0_7)]);
                if (func_004782b0(M2C_FIELD(temp_2_23, u8 **, 0x44)) != 0) {
                    var_4_16 = (u8 *)(M2C_FIELD(temp_2_23, u8 **, 0x44));
                } else {
                    var_4_16 = NULL;
                }
            }
            if (var_4_16 != NULL) {
                func_00479940(var_4_16, 0, 2, 0, 1);
            }
        }
        temp_2_24 = (s32)(M2C_FIELD(temp_20, s32 *, 0xC));
        if (temp_2_24 < 0x258) {
            M2C_FIELD(temp_20, s32 *, 0xC) = (s32) (temp_2_24 + 1);
        }
        temp_f0_8 = (f32)(s32)(fGpffff9c8c);
        sp68C = temp_f0_8;
        sp6BC = temp_f0_8;
        func_0045c870(&sp6BC, 1);
        temp_f0_9 = (f32) *((u8 *)(&D_005E5230 + (M2C_FIELD(temp_20, u32 *, 0x84) * 0x28)));
        if (M2C_BITWISE(s32, temp_f0_9) >= 0xF) {
            var_16_2 = NULL;
        } else {
            temp_2_25 = (u32 *)(&temp_20[M2C_BITWISE(s32, temp_f0_9)]);
            if (func_004782b0(M2C_FIELD(temp_2_25, u8 **, 0x44)) != 0) {
                var_16_2 = (u8 *)(M2C_FIELD(temp_2_25, u8 **, 0x44));
            } else {
                var_16_2 = NULL;
            }
        }
        if (var_16_2 != NULL) {
            temp_3_19 = (s32)(M2C_FIELD(temp_20, u32 *, 0x84) * 0x28);
            temp_f24 = (f32)(s32)(*((u8 *)((s32)&D_005E523C + temp_3_19)));
            temp_f23 = (f32)(s32)(*((u8 *)((s32)&D_005E5240 + temp_3_19)));
            temp_f21_3 = (f32)(s32)(*((u8 *)((s32)&D_005E5248 + temp_3_19)));
            temp_2_26 = (s32)(M2C_FIELD(var_16_2, s32 *, 0xD8) & ~8);
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_2_26;
            temp_3_20 = temp_2_26 | 0x10;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_3_20;
            temp_3_21 = temp_3_20 | 0x100000;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_3_21;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = (s32) (temp_3_21 | 0x40000);
            temp_17_2 = (u32)(M2C_FIELD(temp_20, u32 *, 0x84));
            if (temp_17_2 >= 0x13U) {
                func_0046d730(D_005E5548, 0xEB);
            }
            func_0047a0e0(var_16_2, 0, *((u8 *)((s32)&D_005E5254 + (temp_17_2 * 0x28))));
            func_003e0870(&sp550, &sp5C8, 0, temp_f23);
            func_003e0870(&sp550, &sp5B8, 2, temp_f24);
            sp5A8 = 0.0f;
            sp5AC = 0xC2B40000;
            sp5B0 = 0;
            func_003e0c90(&sp550, &sp5A8, 1);
            func_0047a1c0(var_16_2, &sp550, 0);
            var_2_29 = (s32)(M2C_FIELD(temp_20, s32 *, 0xC) - 5);
            if (var_2_29 > 0) {
                if (var_2_29 >= 6) {
                    var_2_29 = 5;
                }
                func_0044b7b0(((((fGpffff8094 * (f32) var_2_29) / 5.0f))));
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
    /* ACC seed */;
                func_002abb30(0xFFFF81, 0xFF, 1, var_16_2, 0, (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0x42C80000, temp_f21_3);
    /* ACC seed */;
    /* ACC seed */;
                func_002abb30(0xFFFFFF, 0xFF, 1, var_16_2, 0, (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0x42C80000, temp_f21_3);
    /* ACC seed */;
    /* ACC seed */;
                func_002abb30(0xFFC705, 0xFF, 1, var_16_2, 0, (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0x42C80000, temp_f21_3);
                func_002abb30(0xFFF000, 0xFF, 1, var_16_2, 0, (temp_f20 * temp_f21 + temp_f7 * temp_f8), (temp_f20 * temp_f21 + temp_f7 * temp_f8), 0x42C80000, temp_f21_3);
                func_00478e70(var_16_2);
                func_002ab380(0xFFFFFF, 0xFF, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 9, 0, 0xBF800000, 0xBF800000, 0x3F800000);
            }
        }
        var_2_30 = (s32)(M2C_FIELD(temp_20, s32 *, 0xC));
        if (var_2_30 >= 6) {
            var_2_30 = 5;
        }
        temp_f1_16 = 255.0f * (1.0f - ((f32) var_2_30 / 5.0f));
        if (!(temp_f1_16 >= 2.1474836e9f)) {
            var_5_19 = 0x4F000000 & 0xFF;
        } else {
            var_5_19 = (M2C_BITWISE(s32, (temp_f1_16 - 2.1474836e9f)) | 0x80000000) & 0xFF;
        }
        func_0025f3f0(0xFFFFFFU, var_5_19, 0x10001, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 195.0f, 72.0f, 0.0f);
        var_2_31 = (s32)(M2C_FIELD(temp_20, s32 *, 0xC) - 2);
        if (var_2_31 > 0) {
            if (var_2_31 >= 3) {
                var_2_31 = 5;
            }
            temp_f1_17 = 255.0f * ((f32) var_2_31 / 5.0f);
            if (!(temp_f1_17 >= 2.1474836e9f)) {
                var_5_20 = 0x4F000000 & 0xFF;
            } else {
                var_5_20 = (M2C_BITWISE(s32, (temp_f1_17 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            temp_f14_2 = 0.0f;
            temp_f16_3 = (f32)(s32)(fGpffff82a0);
            func_0025f430(0xFFFFFFU, var_5_20, 0x10001, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 0, 0, (temp_f20 * temp_f21 + temp_f7 * temp_f8), 81.0f, temp_f14_2, temp_f14_2, temp_f16_3, temp_f16_3);
        }
        if (M2C_FIELD(temp_20, s32 *, 0x28) != (M2C_FIELD(temp_20, s32 *, 0x20) << 0x10)) {
    /* ACC seed */;
            temp_f0_10 = (temp_f20 * temp_f21 + temp_f7 * temp_f8);
            if (func_0043c6a0(temp_f0_10) < 0xB) {
                M2C_FIELD(temp_20, s32 *, 0x28) = (s32) (M2C_FIELD(temp_20, s32 *, 0x20) << 0x10);
                M2C_FIELD(temp_20, s32 *, 8) = (s32) ~(M2C_FIELD(temp_20, s32 *, 8) ^ -5);
            } else {
                M2C_FIELD(temp_20, s32 *, 0x28) = (s32) (M2C_FIELD(temp_20, s32 *, 0x28) + M2C_BITWISE(s32, ((f32) temp_f0_10 * 0.5f)));
            }
        }
        temp_5 = (s32)(M2C_FIELD(temp_20, s32 *, 0x24));
        temp_4 = (s32)(M2C_FIELD(temp_20, s32 *, 0x20));
        temp_28 = (s32)M2C_FIELD(temp_20, s32 *, 0x28);
        temp_f1_28 = (f32)temp_4 + 0.25f * (f32)((temp_4 - temp_5) << 0x10);
        temp_f0_11 = temp_f1_28 - (f32)temp_28;
        temp_i28 = (s32)temp_f0_11;
        if (((temp_5 < temp_4) && (temp_i28 < 0)) || ((temp_4 < temp_5) && (temp_i28 > 0))) {
            temp_28 = (s32)((f32)temp_i28 + temp_f1_28);
        }
        temp_f13_28 = 32.0f * ((f32)temp_28 / 65535.0f) + 327.0f;
        func_0025f3f0(0xFFFFFFU, 0xFF, 0x10006, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, (f32) 0x18B, temp_f13_28, 0.0f);
        func_0025f3f0(0xFFFFFFU, 0xFF, 0x10003, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 414.0f, 330.0f, 0.0f);
        func_0025f3f0(0xFFFFFFU, 0xFF, 0x10004, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, 444.0f, 362.0f, 0.0f);
        func_0025f3f0(0xFFFFFFU, 0xFF, 0x10005, 0, M2C_FIELD(temp_20, s32 *, 0x3C), 1, (f32) 0x193, 394.0f, 0.0f);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
    if (M2C_FIELD(temp_20, s32 *, 0x2C) > 0) {
        var_6_16 = (M2C_UNK *)(&D_005E56B0);
        var_5_21 = (M2C_UNK *)(&sp530);
        var_4_17 = 4;
        do {
            temp_3_22 = (s32)(M2C_FIELD(var_6_16, s32 *, 0));
            temp_2_27 = (s32)(M2C_FIELD(var_6_16, s32 *, 4));
            var_6_16 += 8;
            var_4_17 -= 1;
            M2C_FIELD(var_5_21, s32 *, 0) = temp_3_22;
            M2C_FIELD(var_5_21, s32 *, 4) = temp_2_27;
            var_5_21 += 8;
        } while (var_4_17 > 0);
        var_4_18 = 0xD;
        if (M2C_FIELD(temp_20, u32 *, 0) == 0x10) {
            var_4_18 = 0xA;
        }
        temp_3_23 = (s32)(M2C_FIELD(temp_20, s32 *, 0x2C) - 1);
        M2C_FIELD(temp_20, s32 *, 0x2C) = temp_3_23;
        func_00366c70(0, 0, 0x280, 0x1C0, 0xFFFFFF, (f32) (temp_3_23 * 0xFF) / (f32) var_4_18, 1, 0, 0, 0, 0, func_00401b80(var_4_18, var_5_21, var_6_16), (s64) &sp530);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);
#endif
/* measured: R1 651 reloc-masked words via probe_variants (fnalign retail 763/object 741 instrs, 187 edits +30 reloc-only; 22 short 2.9% within 3% gate). De-noised generated m2c 476L (switch 0..16 fallthroughs 0->1->2/4->5/6->7/8->9/10->11/12->13/14->15, inners 0..3/1..2) + romwright 518L (quat formulas, table loops, tail) into file idiom (word stores, s32 offsets, s128 copies). Array lever: scalar matrix single swc1 (657 instrs), f32 mat[9] 9 swc1 (737 instrs, micro mat_arr vs mat_sca). Inners to switch ascending per 7i: if/else 234 edits -> switch 184 edits, 737->741. Index (s32)(f32)*(s32*)row 4 instrs (lwc1+cvt.s.w+cvt.w.s+mfc1) vs (s32)*(f32*) 3 (micro conv.c f2). Free pragmas tie: loopinv/unroll/sched 654, commonsubs 654->748 worse; subscripts A/B/C tie 654; decl R1 654->651, R2 tie. Residual is stack offsets (mat 0x60 vs 0x80, D0 0xA8 vs 0xD0, frame 0xB0 vs 0xE0) + reg/FPR colour + lbu/sb sched; time-boxed per batch. */
// FUN_0012AA70 NONMATCHING
#ifdef NON_MATCHING
s32 func_0012aa70(u8 *arg0)
{
    extern s128 D_005E56F0;
    extern s64 D_005E5700;
    extern f32 D_005E5708;
    extern u8 D_005E5220[];
    extern u8 D_005E5230[];
    extern u8 D_005E5710[];
    extern u8 D_005E5548[];
    extern char D_00795E60[];
    extern f32 fGpffff813c;
    extern void func_00440b68(void *arg0, u8 *arg1, s32 arg2);
    extern u8 *func_00454a60(u8 *arg0, s32 arg1);
    extern s32 func_004553c0(void *arg0);
    extern u8 *func_0025ef20(u8 *arg0);
    extern s32 func_0025f110(u8 *arg0);
    extern s32 func_001246d0(u8 *arg0);
    extern s32 func_00124830(u8 *arg0);
    extern s32 func_00124350(void);
    extern s32 func_001110e0(void);
    extern void func_00111160(s32 arg0);
    extern s32 func_00111200(void);
    extern void func_001113b0(void);
    extern void func_00122520(s32 arg0, s32 arg1);
    extern void func_00122640(s32 arg0, s32 arg1);
    extern s32 func_00122720(void);
    extern s32 func_0035c690(void *arg0, s32 arg1);
    extern s32 func_0035c7d0(u8 *arg0);
    extern s32 func_0035c810(u8 *arg0);
    extern u8 *func_00457120(void);
    extern void func_004577d0(void *arg0, f32 arg1);
    extern void func_003e8180(u8 *arg0, f32 arg1);
    extern void func_003e81c0(u8 *arg0, f32 arg1);
    extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
    extern void func_003e9c10(u8 *arg0, void *arg1, s32 arg2);
    extern void func_004599a0(s32 arg0, s32 arg1);
    extern void func_0045aac0(s16 arg0, s32 arg1, s32 arg2);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern s32 func_00479940(u8 *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
    extern char iGpffff9c90;
    extern void func_001265a0(void);

    f32 mat[9];
    s128 sp60 __attribute__((aligned(16)));
    s128 sp70 __attribute__((aligned(16)));
    s64 spC0;
    f32 spC8;
    s64 spD0;
    f32 spD8;
    s32 spB0;
    s32 spB4;
    s32 spB8;
    s32 sp8C;
    u8 *p;
    s32 state;
    s32 tmp;
    s32 i;
    s32 idx;
    u16 pad;
    u8 *model;
    u8 *row;
    f32 q0;
    f32 q1;
    f32 q2;
    f32 q3;

    p = (u8 *)func_00452560(arg0);
    sp60 = D_005E56F0;
    sp70 = sp60;
    spC0 = D_005E5700;
    spC8 = D_005E5708;
    spD0 = spC0;
    spD8 = spC8;
    *(s32 *)(p + 4) = *(s32 *)p;
    state = *(s32 *)p;
    switch (state) {
    case 0:
        *(s32 *)p = 1;
        func_00122640(1, 1);
    case 1:
        *(s32 *)p = 2;
        func_00440b68(&iGpffff9c90, D_005E5548, 0x5D0);
        *(u8 **)(p + 0x38) = func_00454a60(D_005E5710, 1);
    case 2:
        if (func_004553c0(*(u8 **)(p + 0x38)) != 0) {
            *(s32 *)p = 3;
            *(u8 **)(p + 0x3C) = func_0025ef20(D_005E5220);
        }
        break;
    case 3:
        if ((func_0025f110(*(u8 **)(p + 0x3C)) != 0) && (func_001246d0(p) != 0)) {
            *(s32 *)p = 4;
            func_004599a0(0x13, 0x1E);
        }
        break;
    case 4:
        q0 = *(f32 *)((u8 *)&sp70 + 0);
        q1 = *(f32 *)((u8 *)&sp70 + 4);
        q2 = *(f32 *)((u8 *)&sp70 + 8);
        q3 = *(f32 *)((u8 *)&sp70 + 12);
        mat[0] = 1.0f - (q1 * q1 + q2 * q2) * 2.0f;
        mat[1] = (q0 * q1 + q3 * q2) * 2.0f;
        mat[2] = (q2 * q0 - q3 * q1) * 2.0f;
        mat[3] = (q0 * q1 - q3 * q2) * 2.0f;
        mat[4] = 1.0f - (q0 * q0 + q2 * q2) * 2.0f;
        mat[5] = (q1 * q2 + q3 * q0) * 2.0f;
        mat[6] = (q2 * q0 + q3 * q1) * 2.0f;
        mat[7] = (q1 * q2 - q3 * q0) * 2.0f;
        mat[8] = 1.0f - (q0 * q0 + q1 * q1) * 2.0f;
        spB0 = 0;
        spB4 = 0;
        spB8 = 0;
        sp8C = 3;
        func_003e9cb0(*(s32 *)(func_00457120() + 4), mat, 0);
        func_003e9c10(func_00457120(), &spD0, 2);
        func_004577d0(func_00457120(), 50.0f);
        func_003e81c0(func_00457120(), 25600.0f);
        func_003e8180(func_00457120(), 10.0f);
        *(s32 *)p = 5;
        *(s32 *)(p + 0x14) = 0;
        *(s32 *)(p + 0xC) = 0;
        *(s32 *)(p + 0x10) = 0;
    case 5:
        *(s32 *)(p + 0x14) = *(s32 *)(p + 0x14) + 1;
        if ((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x40) || (D_008C024E[0] & 4) || (D_008C024E[0] & 1) || (D_008C024E[0] & 8) || (D_008C024E[0] & 2) || (D_008C024E[0] & 0x800) || (D_008C024E[0] & 0x100)) {
            func_0045af60(0, 0, 0, 1);
            pad = D_008C024E[0];
        } else {
            pad = 0;
        }
        if ((pad != 0) || (*(s32 *)(p + 0x14) >= 0xEC)) {
            *(s32 *)(p + 8) = *(s32 *)(p + 8) & ~2;
            if (*(s32 *)(p + 0x14) < 0xEC) {
                *(s32 *)(p + 8) = *(s32 *)(p + 8) | 2;
                *(s32 *)(p + 0x2C) = 0xA;
            }
            *(s32 *)p = 6;
        }
        break;
    case 6:
        func_0045aac0(2, 0, 0x1E);
        *(s32 *)p = 7;
        *(s32 *)(p + 0x14) = 0;
        *(s32 *)(p + 0xC) = 0;
        q0 = *(f32 *)((u8 *)&sp70 + 0);
        q1 = *(f32 *)((u8 *)&sp70 + 4);
        q2 = *(f32 *)((u8 *)&sp70 + 8);
        q3 = *(f32 *)((u8 *)&sp70 + 12);
        mat[0] = 1.0f - (q1 * q1 + q2 * q2) * 2.0f;
        mat[1] = (q0 * q1 + q3 * q2) * 2.0f;
        mat[2] = (q2 * q0 - q3 * q1) * 2.0f;
        mat[3] = (q0 * q1 - q3 * q2) * 2.0f;
        mat[4] = 1.0f - (q0 * q0 + q2 * q2) * 2.0f;
        mat[5] = (q1 * q2 + q3 * q0) * 2.0f;
        mat[6] = (q2 * q0 + q3 * q1) * 2.0f;
        mat[7] = (q1 * q2 - q3 * q0) * 2.0f;
        mat[8] = 1.0f - (q0 * q0 + q1 * q1) * 2.0f;
        spB0 = 0;
        spB4 = 0;
        spB8 = 0;
        sp8C = 3;
        func_003e9cb0(*(s32 *)(func_00457120() + 4), mat, 0);
        func_003e9c10(func_00457120(), &spD0, 2);
        func_004577d0(func_00457120(), 50.0f);
        func_003e81c0(func_00457120(), 25600.0f);
        func_003e8180(func_00457120(), 10.0f);
        if (func_004782b0(*(u8 **)(p + 0x44)) != 0) {
            model = *(u8 **)(p + 0x44);
        } else {
            model = 0;
        }
        func_0047a0e0(model, 0, fGpffff813c);
        i = 1;
        while (i < 8) {
            row = D_005E5230 + i * 0x28;
            idx = (s32)(f32)*(s32 *)row;
            if (idx >= 0xF) {
                model = 0;
            } else {
                tmp = func_004782b0(*(u8 **)(p + idx * 4 + 0x44));
                if (tmp != 0) {
                    model = *(u8 **)(p + idx * 4 + 0x44);
                } else {
                    model = 0;
                }
            }
            if (model != 0) {
                if ((u32)i >= 0x13) {
                    func_0046d730(D_005E5548, 0xEB);
                }
                func_0047a0e0(model, 0, *(f32 *)(row + 0x24));
            }
            i++;
        }
        if ((*(s32 *)(p + 8) & 2) != 0) {
            idx = *(s32 *)D_005E5230;
            if (idx >= 0xF) {
                model = 0;
            } else {
                tmp = func_004782b0(*(u8 **)(p + idx * 4 + 0x44));
                if (tmp != 0) {
                    model = *(u8 **)(p + idx * 4 + 0x44);
                } else {
                    model = 0;
                }
            }
            if (model != 0) {
                func_00479940(model, 0, 0, 0, 1);
            }
            i = 1;
            while (i < 8) {
                row = D_005E5230 + i * 0x28;
                idx = *(s32 *)row;
                if (idx >= 0xF) {
                    model = 0;
                } else {
                    tmp = func_004782b0(*(u8 **)(p + idx * 4 + 0x44));
                    if (tmp != 0) {
                        model = *(u8 **)(p + idx * 4 + 0x44);
                    } else {
                        model = 0;
                    }
                }
                if (model != 0) {
                    func_00479940(model, 0, 0, 0, 1);
                }
                i++;
            }
        }
        *(s32 *)(p + 8) = *(s32 *)(p + 8) | 2;
    case 7:
        tmp = *(s32 *)(p + 0x14) + 1;
        *(s32 *)(p + 0x14) = tmp;
        if (tmp >= 0x1C2) {
            *(s32 *)p = 0x10;
            *(s32 *)(p + 0x1C) = 1;
            *(s32 *)(p + 0x2C) = 0xA;
            func_00122520(1, 0xA);
        } else {
            if ((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x40) || (D_008C024E[0] & 4) || (D_008C024E[0] & 1) || (D_008C024E[0] & 8) || (D_008C024E[0] & 2) || (D_008C024E[0] & 0x800) || (D_008C024E[0] & 0x100)) {
                func_0045af60(0, 0, 0, 1);
                pad = D_008C024E[0];
            } else {
                pad = 0;
            }
            if (pad != 0) {
                *(s32 *)p = 8;
            }
        }
        break;
    case 8:
        iGpffffb1e8 = iGpffffb1e8 + 1;
        *(s32 *)p = 9;
        *(s32 *)(p + 0x14) = 0;
        *(s32 *)(p + 0xC) = 0;
        *(s32 *)(p + 0x84) = func_00124350();
        mat[0] = 1.0f;
        mat[4] = 1.0f;
        mat[8] = 1.0f;
        mat[1] = 0.0f;
        mat[2] = 0.0f;
        mat[3] = 0.0f;
        mat[5] = 0.0f;
        mat[6] = 0.0f;
        mat[7] = 0.0f;
        spB8 = 0;
        spB4 = 0;
        spB0 = 0;
        sp8C = sp8C | 0x20003;
        func_003e9cb0(*(s32 *)(func_00457120() + 4), mat, 0);
        func_004577d0(func_00457120(), 70.0f);
        *(s32 *)(p + 0x28) = 0;
        *(s32 *)(p + 0x24) = 0;
        *(s32 *)(p + 0x20) = 0;
    case 9:
        *(s32 *)(p + 0x14) = *(s32 *)(p + 0x14) + 1;
        if ((D_008C024E[0] & 0x20) || (*(s32 *)(p + 0x14) >= 0x1C2)) {
            *(s32 *)(p + 0x2C) = 0xD;
            *(s32 *)p = 6;
        } else {
            tmp = func_00124830(p);
            switch (tmp) {
            case 0:
                *(s32 *)(p + 0x14) = 0;
                break;
            case 1:
                *(s32 *)p = 0xA;
                break;
            case 2:
                *(s32 *)p = 0xC;
                func_0045aac0(2, 0, 0);
                break;
            case 3:
                *(s32 *)p = 0xE;
                break;
            }
        }
        break;
    case 10:
        *(s32 *)(p + 0x8C) = func_001110e0();
        func_001113b0();
        *(s32 *)p = 0xB;
        *(s32 *)(p + 0x34) = func_002aa300(arg0, 0);
    case 11:
        tmp = func_002aa3f0();
        switch (tmp) {
        case 1:
            func_00122520(1, 0xA);
            *(s32 *)(p + 0x1C) = 3;
            *(s32 *)p = 0x10;
            break;
        case 2:
            *(s32 *)p = 8;
            func_00111160(*(s32 *)(p + 0x8C));
            break;
        }
        break;
    case 12:
        *(s32 *)p = 0xD;
        func_00122520(1, 0xA);
    case 13:
        if (func_00122720() != 0) {
            *(s32 *)(p + 0x1C) = 2;
            *(s32 *)p = 0x10;
        }
        break;
    case 14:
        *(s32 *)p = 0xF;
        *(s32 *)(p + 0x34) = func_0035c690(arg0, 1);
    case 15:
        if (func_0035c7d0(*(u8 **)(p + 0x34)) != 0) {
            if (func_0035c810(*(u8 **)(p + 0x34)) != 0) {
                func_00111200();
            }
            func_00452080(*(u8 **)(p + 0x34));
            *(s32 *)(p + 0x34) = 0;
            *(s32 *)p = 8;
        }
        break;
    case 16:
        if ((func_00122720() != 0) && (*(s32 *)(p + 0x2C) == 0)) {
            *(s32 *)(p + 0x18) = *(s32 *)(p + 0x1C);
        }
        break;
    }
    p = func_00460990();
    *(void **)(p + 8) = (void *)func_001265a0;
    *(u8 **)(p + 0x10) = arg0;
    func_00460ac0(D_00795E60, p);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012aa70);
#endif
// FUN_0012B660
void func_0012b660(u8 *unusedTask)
{
    u8 *temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    temp_2 = func_00452560();
    temp_3 = *(s32 *)(temp_2 + 0x1C);
    switch (temp_3) {
    case 2:
        break;
    case 3:
        if ((s64)(s16)func_001060b0() == 9 &&
            (func_001060c0() & 0xFF) == 5) {
            break;
        }
        goto error;
    default:
error:
        func_004598e0(0x1E);
        break;
    }
    var_17 = 0;
    goto loop_10_test;
loop_10_body:
    temp_4 = *(s32 *)(temp_2 + var_17 * 4 + 0x44);
    if (temp_4 != 0) {
        func_004787e0(temp_4);
    }
    var_17 += 1;
loop_10_test:
    if (var_17 < 0xF) {
        goto loop_10_body;
    }
    func_0025f230(*(s32 *)(temp_2 + 0x3C));
    func_00454bd0(*(s32 *)(temp_2 + 0x38));
    jtbl_008873EC[0](temp_2);
}
// FUN_0012B760
s32 func_0012b760(void)
{
    u8 *temp_2;
    func_0044ea90(D_005E5548, 0x728);
    temp_2 = D_008873F4[0](1, 0x90, 0x40000);
    if (temp_2 == NULL)
        func_0046d730(D_005E5548, 0x729);
    *(s32 *)(temp_2 + 0x18) = 0;
    func_00451de0((const void *)(D_005E5720), 0xF, 0, 0, func_0012aa70, func_0012b660, (u8 *)(temp_2));
}
// FUN_0012B810
s32 func_0012b810(s32 arg0)
{
    B810Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (B810Obj *)(func_00452560(arg0));
    if (temp_2->field_18 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_18;
}



// FUN_0012B890
s32 func_0012b890(u8 *unusedTask)
{
    s32 sp2C;
    u8 *temp_2;
    s32 temp_3;
    temp_2 = (u8 *)func_00452560();
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 0:
        *(s32 *)(temp_2 + 0) = 1;
    case 1:
        *(s32 *)(temp_2 + 0) = 2;
    case 2:
        *(s32 *)(temp_2 + 8) = func_004669d0(*(s32 *)(temp_2 + 4), &sp2C, 0);
        if (sp2C != 0) {
            *(s32 *)(temp_2 + 0) = 3;
            *(s32 *)(temp_2 + 4) = 0;
        }
        break;
    case 3:
        break;
    }
    return 0;
}
// FUN_0012B940
void func_0012b940(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 8);
    if (v != 0) {
        func_003ef3a0((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_0012B9A0
void func_0012b9a0(s32 unused, s32 arg1)
{
    typedef struct {
        s128 sp50;
        s128 sp60;
        s128 sp70;
        u8 gap[4];
        f32 sp84;
        f32 sp88;
        f32 sp8C;
    } B9Stack;
    B9Stack stack;
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_17;
    s32 temp_17_2;
    s32 var_2;
    s32 var_2_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_2;
    s32 temp_3;
    f32 *sp8c_ptr;
    s32 *sp70_ptr;

    temp_2 = (u8 *)func_00452560(arg1);
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 4:
    case 5:
    case 6:
        temp_f0 = fGpffff9cA0;
        stack.sp88 = temp_f0;
        sp8c_ptr = &stack.sp8C;
        stack.sp8C = temp_f0;
        stack.sp60 = D_005E5740;
        sp70_ptr = (s32 *)&stack.sp70;
        stack.sp70 = D_005E5740;
        func_0045d6e0(sp8c_ptr, sp70_ptr, 0.0f, 1);
        temp_17 = *(s32 *)(temp_2 + 0x10);
        temp_16 = (u8 *)func_00452560(temp_17);
        if (func_00452490(temp_17) == 0) {
            var_2 = 0;
        } else if (*(s32 *)(temp_16 + 0) == 3) {
            var_2 = *(s32 *)(*(u8 **)(temp_16 + 8));
        } else {
            var_2 = 0;
        }
        func_00366c70(0x77, 0xAA, 0.0f, 0x200, 0x80, 0xFFFFFF, 0xFF, 1, 0, 0, 0, var_2, 0);
        return;
    case 7:
    case 8:
    case 9:
        temp_f0_2 = fGpffff9cA4;
        stack.sp84 = temp_f0_2;
        sp8c_ptr = &stack.sp8C;
        stack.sp8C = temp_f0_2;
        stack.sp50 = D_005E5750;
        sp70_ptr = (s32 *)&stack.sp70;
        stack.sp70 = D_005E5750;
        func_0045d6e0(sp8c_ptr, sp70_ptr, 0.0f, 1);
        temp_17_2 = *(s32 *)(temp_2 + 0x14);
        temp_16_2 = (u8 *)func_00452560(temp_17_2);
        if (func_00452490(temp_17_2) == 0) {
            var_2_2 = 0;
        } else if (*(s32 *)(temp_16_2 + 0) == 3) {
            var_2_2 = *(s32 *)(*(u8 **)(temp_16_2 + 8));
        } else {
            var_2_2 = 0;
        }
        func_00366c70(0, 0, 0.0f, 0x400, 0x200, 0xFFFFFF, 0xFF, 1, 0, 0, 0, var_2_2, 0);
        /* fall through */
    default:
        return;
    }
}
// FUN_0012C1A0
s32 func_0012c1a0(s32 arg0)
{
    C1A0Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (C1A0Obj *)(func_00452560(arg0));
    if (temp_2->field_4 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_4;
}

// FUN_0012C220
s32 func_0012c220(u8 *arg0) {
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(u32 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        if ((func_0045a890(0) != 0) && (func_0045a890(1) != 0)) {
            *(u32 *)(temp_16 + 0) = 1U;
        }
        goto block_20;
    default:
        goto block_20;
    case 1:
        *(s32 *)(temp_16 + 0xC) = func_0025e800(arg0, 1, 0xF);
        *(s32 *)(temp_16 + 8) = 0x3C;
        *(u32 *)(temp_16 + 0) = 2U;
        goto block_20;
    case 2:
        temp_2_2 = *(s32 *)(temp_16 + 8) - 1;
        *(s32 *)(temp_16 + 8) = temp_2_2;
        if (temp_2_2 == 0) {
            func_00465f20();
            *(u32 *)(temp_16 + 0) = 3U;
        }
        goto block_20;
    case 3:
        temp_2_3 = func_00465f40();
        *(s32 *)(temp_16 + 4) = temp_2_3;
        if (temp_2_3 != 0) {
            if (temp_2_3 == 0x64) {
                func_0025e8b0(*(s32 *)(temp_16 + 0xC));
                return -1;
            }
            *(u32 *)(temp_16 + 0) = 4U;
            goto block_20;
        }
        goto block_20;
    case 4:
        func_0025e8b0(*(s32 *)(temp_16 + 0xC));
        if (*(s32 *)(temp_16 + 4) == -6) {
            *(s32 *)(temp_16 + 0xC) = func_0025e800(arg0, 1, 0x15);
        } else {
            *(s32 *)(temp_16 + 0xC) = func_0025e800(arg0, 1, 0x10);
        }
        *(u32 *)(temp_16 + 0) = 5U;
        goto block_20;
    case 5:
        temp_2_4 = func_0025e8f0(*(s32 *)(temp_16 + 0xC));
        if (temp_2_4 == 1) {
            func_0025e8b0(*(s32 *)(temp_16 + 0xC));
            return -1;
        }
        if (temp_2_4 == 2) {
            func_0025e8b0(*(s32 *)(temp_16 + 0xC));
            *(u32 *)(temp_16 + 0) = 1U;
        }
        goto block_20;
    }
block_20:
    return 0;
}
// FUN_0012C410
void func_0012c410(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    func_001029a0(1, 0, 0, 5);
}
// FUN_0012C460
s32 func_0012c460(s32 arg0) {
    s32 var_2;
    u8 *temp_2;

    func_0044ea90(D_005E57B8, 0x74);
    temp_2 = D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    var_2 = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005E57D0), 0xF, 0, 0, func_0012c220, func_0012c410, (u8 *)(temp_2));
    if (var_2 == 0) {
        return 0;
    }
    return var_2;
}
#pragma push
/* measured: opt_loop_invariants on hoists the loop constants into the
   retail preheader and opt_propagation off keeps the pre-call indexed
   destination address materialised; 92 differing words -> 0 (532/544). */
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_0012D410
void func_0012d410(u8 *arg0)
{
    u8 *temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    s32 var_18_2;
    s32 var_18;
    s32 var_17;
    s32 var_2;
    s32 var_5;
    s32 temp_5;
    s32 temp_6;
    s32 *temp_4;

    *(s16 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x18) = -1;
    var_5 = 0;
    temp_5 = 0x42700000;
    temp_6 = 0x1000;
    while (var_5 < 0xB) {
        *(s32 *)(arg0 + (var_5 * 0x30) + 0xA4) = temp_5;
        *(s32 *)(arg0 + (var_5 * 0x30) + 0xA8) = 0;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0xBA) = temp_6;
        *(s8 *)(arg0 + (var_5 * 0x30) + 0xAE) = 0;
        var_5++;
    }
    temp_2_2 = (u8 *)func_0046a770(D_005E5810);
    if (temp_2_2 == 0) {
        func_0046d730(D_005E5BB8, 0xC1);
    }
    temp_2_3 = func_0046a770(D_005E57F0);
    *(s32 *)(arg0 + 0x90) = temp_2_3;
    if (temp_2_3 == 0) {
        func_0046d730(D_005E5BB8, 0xC3);
    }
    var_18 = 0;
    while (var_18 < 0x15) {
        temp_3 = var_18 * 4;
        temp_4 = (s32 *)(arg0 + temp_3 + 0x3C);
        temp_2_4 = func_0046d200(temp_2_2,
                                 *(s32 *)((u8 *)D_005E5B60 + temp_3));
        *temp_4 = temp_2_4;
        if (temp_2_4 == 0) {
            func_0046d730(D_005E5BB8, 0xC9);
        }
        var_18++;
    }
    var_17 = 0;
    var_18_2 = 0;
    while (var_17 < 7) {
        switch (var_17) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
            var_2 = 1;
            break;
        case 5:
            if (func_00106330(0x1F) != 0) {
                var_2 = 0;
            } else {
                var_2 = 1;
            }
            break;
        default:
            func_0046d730(D_005E5BB8, 0xA7);
            var_2 = 0;
            break;
        }
        if (var_2 != 0) {
            *(s32 *)(arg0 + (var_18_2 * 4) + 0x1C) = var_17;
            var_18_2++;
        }
        var_17++;
    }
    *(s32 *)(arg0 + 0x38) = var_18_2;
    func_0012dea0(arg0, 0);
}
#pragma opt_propagation on
#pragma opt_loop_invariants off
#pragma pop
/* Floor: 1360B window, obj 1348B, 13 differing words (was 66).
   Typed record views closed two of them: the per-entry alpha/tally pair is
   a 0x30-stride record based at p+0xAE, and the sprite lookups are an array
   of pointers at p+0x74 - indexing those views naturally beats byte-offset
   arithmetic (kit recipe S03).
   WINS: the per-entry alpha byte is read into a u32 temp before the
   sprite if/else, which is where retail emits `lbu $t0,0xae(...)`;
   declaring func_0034f320's 10th parameter u16 (it takes the raw
   *(u16 *)(q + 0xBA) tally) removes the promotion that reordered the
   whole argument block - 28 -> 16 words; and func_00364320 takes
   (pos, z, color, num), so the palette byte is the colour argument and
   -1 the number - the previous body had those two swapped, which was a
   real ABI error, not just a codegen difference.
/*   WALL: the remaining rows are evaluation-order artifacts - retail */
/*   computes `index + base` (addu $v1,$v0,$s1) and converts the 0x17D */
/*   constant before loading its float addend, this build does both the */
/*   other way round. Integer-cast pointer arithmetic, operand swaps and */
/*   named temporaries for either side were all measured inert. Pairs */
/*   2026-09-17 (`tools/pragma_sweep.py --pairs`, 8 singles + 28 pairs, */
/*   banked 13): ties at 13 among loopinv/strength_off/unroll_off + 3 pairs */
/*   among them; dead 37, prop 61, cse 307, sched 315, peephole 332 */
/*   (pairs 37-357). Three causes stand: addu order, lbu/sd-mtc1 */
/*   scheduling, cvt.s.w into $f1; floor stands at 13 (337/337). */
/*   7o 2026-09-18 (`tools/residual_signature.py src/promoted/code1_0012.c func_0012d630`: */
/*   edits 12 mask 0 cvt 1 class 1 perm 0 other 6 [$s1->$v0 $v0->$s1], probe 13 words; */
/*   class/perm 1/12 not majority - single addu operand swap (retail $v0,$v0,$s1 */
/*   vs object $v0,$s1,$v0 for p+sel*4) plus lbu/sd-mtc1 scheduling and cvt.s.w. */
/*   Eight q/idx probes (strip q init, q before idx vs idx before q, F/B scopes, */
/*   one batched probe_variants call, all truthful): v1_FF_retail 13, v2_FF_rev 44, */
/*   v3_FB_retail 13, v4_FB_rev 44, v5_BF_retail 13, v6_BF_rev 44, */
/*   v7_BB_retail 13, v8_BB_rev 44. Retail ties, reverse 13->44, scopes neutral. */
/*   Floor stands at 13 (337/337). */
/*   2026-09-19 verbatim residual, masked 13 (raw 12/26, 337/337 exact, frame */
/*   both addiu $sp,$sp,-0x80): object vs retail, FPU scheduling + addu + cvt: */
/*   off 1080: object sd $zero,($sp) vs retail lbu $t0,0xAE($v1); */
/*   off 1092: object addu $v0,$s1,$v0 vs retail addu $v0,$v0,$s1 (p+sel*4); */
/*   off 1108: object mtc1 $zero,$f14 vs retail lw $a0,0x74($v0); */
/*   off 1112: object lbu $t0,0xAE($v1) vs retail sd $zero,($sp); */
/*   off 1116: object lw $a0,0x74($v0) vs retail mtc1 $zero,$f14; */
/*   off 1180: object lwc1 $f1,0x228($s1) vs retail addiu $v0,$zero,0x17D; */
/*   off 1184: object addiu $v0,$zero,0x17D vs retail mtc1 $v0,$f0; */
/*   off 1188: object mtc1 $v0,$f0 vs retail nop; */
/*   off 1192: object nop vs retail cvt.s.w $f1,$f0; */
/*   off 1196: object cvt.s.w $f0,$f0 vs retail lwc1 $f0,0x228($s1); */
/*   off 1200: object add.s $f0,$f0,$f1 vs retail add.s $f0,$f1,$f0; */
/*   off 1208: object mtc1 $zero,$f12 vs retail lbu $a1,0x22E($s1); */
/*   off 1212: object lbu $a1,0x22E($s1) vs retail mtc1 $zero,$f12. */
/*   Immediates same (0x17D, 0x228/0x22E), branches same targets, nop/work is */
/*   FPU scheduling (sched 315, peephole 332, nobranch tie 13). */
/* measured 0012d630 (owner, 2026-09-19): 337/337 exact, **12 edits**.  Two of them are
   commutative operand order - retail `addu $v0, $v0, $s1` against the object's
   `addu $v0, $s1, $v0`, and an `add.s` with its operands the other way round.  Writing the
   source additions in retail's order (`j * 0x30 + p`, and the 0x228 load before the (f32)
   cast, separately and together) measures 12 every time: b210 canonicalises commutative
   operand order before allocation, so it cannot be steered from source. */
// FUN_0012D630 NONMATCHING
#ifdef NON_MATCHING
s32 func_0012d630(u8 *arg0)
{
    typedef struct {
        u8 alpha;
        u8 pad01[0xB];
        u16 tally;
        u8 padE[0x30 - 0xE];
    } Rec0012d630;
    typedef struct {
        f32 x;
        f32 y;
    } Vec2f_0012d630;
    extern s32 func_0012e1d0(u8 *arg0);
    extern void func_0034f1e0(void);
    extern void func_0034f320(u8 *arg0, f32 farg0, f32 farg1, f32 farg2,
                              u8 arg1, u8 arg2, u8 arg3, s32 arg4, s32 arg5,
                              u16 arg6, s32 arg7, f32 farg3, s16 arg_sp0);
    extern void func_00364320(Vec2f_0012d630 pos, f32 z, s32 color, s32 num);
    extern void func_0034f9d0(Vec2f_0012d630 pos, s32 arg1, f32 z, s32 arg2, s32 arg3);
    Vec2f_0012d630 pos;
    Vec2f_0012d630 pos2;
    s32 result;
    u8 *p;
    s32 i;
    s32 count;
    s32 sel;
    s32 j;
    f32 x;
    f32 y;

    result = 1;
    p = arg0;
    switch (*(s32 *)(p + 0x18)) {
    case 0:
        if (1) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 0);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    case 1:
        if (0) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 0);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    case 2:
        if (1) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 2);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    case 3:
        if (0) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 0);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    }
    func_0034f1e0();
    sel = *(s32 *)(p + 0x10);
    count = *(s32 *)(p + 0x38);
    for (j = 0; j < count; j++) {
        u8 *q = p + j * 0x30;
        s32 idx;
        u8 *sprite;
        u32 alpha;

        x = *(f32 *)(p + 4) + 173.0f + *(f32 *)(q + 0xA4);
        pos.x = x;
        y = *(f32 *)(p + 8) + 52.0f + *(f32 *)(q + 0xA8) + (f32)(j * 0x16);
        pos.y = y;
        alpha = *(u8 *)(q + 0xAE);
        idx = *(s32 *)(p + j * 4 + 0x1C);
        if (j == sel) {
            pos.x += 2.0f;
            pos.y += 11.0f;
            sprite = *(u8 **)(p + idx * 4 + 0x58);
        } else {
            pos.x += 1.0f;
            if (sel < j) {
                pos.y += 45.0f;
            }
            sprite = *(u8 **)(p + idx * 4 + 0x3C);
        }
        func_0034f320(sprite, pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF,
                      alpha, 0x1000, *(u16 *)(q + 0xBA), 0,
                      0.0f, 0);
    }
    pos.x = *(f32 *)(p + 4) + 173.0f + *(f32 *)(p + 0x1F4) + 3.0f;
    pos.y = *(f32 *)(p + 8) + 52.0f + *(f32 *)(p + 0x1F8) + 311.0f;
    func_0034f320(((u8 **)(p + 0x74))[*(s32 *)(p + *(s32 *)(p + 0x10) * 4 + 0x1C)],
                  pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF,
                  ((Rec0012d630 *)(p + 0xAE))[j].alpha, 0x1000,
                  ((Rec0012d630 *)(p + 0xAE))[j].tally, 0, 0.0f, 0);
    pos.x = *(f32 *)(p + 0x224) + 18.0f;
    pos.y = (f32)0x17D + *(f32 *)(p + 0x228);
    func_00364320(pos, 0.0f, *(u8 *)(p + 0x22E), -1);
    pos2.x = *(f32 *)(p + 0x254) + 640.0f;
    pos2.y = *(f32 *)(p + 0x258) + 400.0f;
    func_0034f9d0(pos2, *(u8 *)(p + 0x25E), 0.0f, 0, *(s32 *)(p + 0x90));
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012d630);
#endif
// FUN_0012DB80
s32 func_0012db80(u8 *arg0, s32 arg1)
{
    if (arg1 != *(s32 *)(arg0 + 0x10)) {
        func_0045af60(0, 1, 0, 0);
        *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x10);
        *(s32 *)(arg0 + 0x10) = arg1;
        *(s32 *)(arg0 + 0x18) = -1;
        func_0012dea0(arg0, 2);
    }
    return 1;
}
/* measured: opt_loop_invariants on is load-bearing for 0012DC00 -- without it
   the object grows to 676 bytes against the 672-byte window at nd 243. */
#pragma opt_loop_invariants on
// FUN_0012DC00
void func_0012dc00(u8 *arg0)
{
    s32 temp_10;
    s32 temp_3;
    s32 temp_5;
    s32 temp_7;
    s32 temp_9;
    s32 temp_8;
    s32 var_11;
    s32 var_11_2;
    s32 var_12;
    s32 var_c_ff;
    f32 var_c_1;
    f32 var_c_2;
    s32 var_c_7f;
    s32 var_c_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_5_2;
    u8 *temp_5_3;
    u8 *temp_6;
    u8 *temp_6_2;
    u8 *temp_6_3;
    u8 *temp_6_4;
    u8 *temp_6_5;

    temp_5 = *(s32 *)(arg0 + 0x10);
    temp_10 = *(s32 *)(arg0 + 0x14);
    temp_3 = *(s32 *)(arg0 + 0x38);
    temp_9 = temp_3 - 1;
    temp_8 = -temp_9;
    temp_7 = temp_5 - temp_10;
    var_11 = 0;
    goto loop_0012dc00_2_check;
loop_0012dc00_2_body:
    temp_6 = (var_11 * 0x30) + arg0;
    *(s32 *)(temp_6 + 0xBC) = 0;
    *(s32 *)(temp_6 + 0xC0) = 0;
    var_11 += 1;
loop_0012dc00_2_check:
    if (var_11 < 0xB) {
        goto loop_0012dc00_2_body;
    }
    if (temp_7 == 1) {
        temp_3_2 = (u8 *)code1_0012_stride(temp_10 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_3_2 + 0x9C) = 0;
        *(s32 *)(temp_3_2 + 0x98) = 0;
        *(s32 *)(temp_3_2 + 0xA0) = 0;
        *(u8 *)(temp_3_2 + 0xAC) = 0xFF;
        *(u8 *)(temp_3_2 + 0xAD) = 0xFF;
        *(s32 *)(temp_3_2 + 0xC0) = 0;
        temp_5_2 = (u8 *)code1_0012_stride(temp_5 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_5_2 + 0x9C) = 0;
        *(s32 *)(temp_5_2 + 0x98) = (s32)0xC1700000;
        *(s32 *)(temp_5_2 + 0xA0) = (s32)0x40B00000;
        *(s8 *)(temp_5_2 + 0xAC) = 0x7F;
        *(u8 *)(temp_5_2 + 0xAD) = 0xFF;
        *(s32 *)(temp_5_2 + 0xC0) = 3;
        *(s32 *)(arg0 + 0x278) = (s32)0x3F800000;
        *(s32 *)(arg0 + 0x280) = (s32)0x3F800000;
    } else if (temp_7 == -1) {
        temp_3_3 = (u8 *)code1_0012_stride(temp_10 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_3_3 + 0x9C) = 0;
        *(s32 *)(temp_3_3 + 0x98) = 0;
        *(s32 *)(temp_3_3 + 0xA0) = 0;
        *(u8 *)(temp_3_3 + 0xAC) = 0xFF;
        *(u8 *)(temp_3_3 + 0xAD) = 0xFF;
        *(s32 *)(temp_3_3 + 0xC0) = 0;
        temp_5_3 = (u8 *)code1_0012_stride(temp_5 * 0x30, (s32)(u32)arg0);
        *(s32 *)(temp_5_3 + 0x9C) = 0;
        *(s32 *)(temp_5_3 + 0x98) = (s32)0x41700000;
        *(s32 *)(temp_5_3 + 0xA0) = (s32)0xC0B00000;
        *(s8 *)(temp_5_3 + 0xAC) = 0x7F;
        *(u8 *)(temp_5_3 + 0xAD) = 0xFF;
        *(s32 *)(temp_5_3 + 0xC0) = 3;
        *(s32 *)(arg0 + 0x278) = 0;
        *(s32 *)(arg0 + 0x280) = 0;
    } else if (temp_7 == temp_9) {
        var_12 = 0;
        var_c_ff = 0xFF;
        var_c_1 = -15.0f;
        var_c_2 = 5.5f;
        var_c_7f = 0x7F;
        var_c_3 = 3;
        goto loop_0012dc00_13_check;
loop_0012dc00_13_body:
        if (var_12 == temp_5) {
            temp_6_2 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_12 * 0x30);
            *(f32 *)(temp_6_2 + 0x98) = var_c_1;
            *(f32 *)(temp_6_2 + 0xA0) = var_c_2;
            *(s8 *)(temp_6_2 + 0xAC) = var_c_7f;
            *(u8 *)(temp_6_2 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_2 + 0xC0) = var_c_3;
        } else {
            temp_6_3 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_12 * 0x30);
            *(s32 *)(temp_6_3 + 0x9C) = 0;
            *(s32 *)(temp_6_3 + 0x98) = 0;
            *(s32 *)(temp_6_3 + 0xA0) = 0;
            *(u8 *)(temp_6_3 + 0xAC) = var_c_ff;
            *(u8 *)(temp_6_3 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_3 + 0xC0) = 0;
        }
        var_12 += 1;
loop_0012dc00_13_check:
        if (var_12 < temp_3) {
            goto loop_0012dc00_13_body;
        }
        *(s32 *)(arg0 + 0x278) = (s32)0x3F800000;
        *(s32 *)(arg0 + 0x280) = (s32)0x3F800000;
    } else if (temp_7 == temp_8) {
        var_11_2 = 0;
        var_c_ff = 0xFF;
        var_c_1 = 15.0f;
        var_c_2 = -5.5f;
        var_c_3 = 3;
        goto loop_0012dc00_21_check;
loop_0012dc00_21_body:
        if (var_11_2 == temp_5) {
            temp_6_4 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_11_2 * 0x30);
            *(f32 *)(temp_6_4 + 0x98) = var_c_1;
            *(f32 *)(temp_6_4 + 0xA0) = var_c_2;
            *(s8 *)(temp_6_4 + 0xAC) = 0;
            *(u8 *)(temp_6_4 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_4 + 0xC0) = var_c_3;
        } else {
            temp_6_5 = (u8 *)code1_0012_stride_loop((s32)(u32)arg0, var_11_2 * 0x30);
            *(s32 *)(temp_6_5 + 0x9C) = 0;
            *(s32 *)(temp_6_5 + 0x98) = 0;
            *(s32 *)(temp_6_5 + 0xA0) = 0;
            *(u8 *)(temp_6_5 + 0xAC) = var_c_ff;
            *(u8 *)(temp_6_5 + 0xAD) = var_c_ff;
            *(s32 *)(temp_6_5 + 0xC0) = 0;
        }
        var_11_2 += 1;
loop_0012dc00_21_check:
        if (var_11_2 < temp_3) {
            goto loop_0012dc00_21_body;
        }
        *(s32 *)(arg0 + 0x278) = 0;
        *(s32 *)(arg0 + 0x280) = 0;
    }
    *(s16 *)(arg0 + 0xC) = 0;
}
/* measured: closes the opt_loop_invariants bracket opened above func_0012dc00. */
#pragma opt_loop_invariants off
extern u8 D_005E58C0[];
extern u8 D_005E59A0[];
extern u8 D_005E5A80[];
extern void func_0012dc00(u8 *arg0);

#pragma push
/* measured: opt_loop_invariants on is load-bearing: removing it yields MISMATCH nd 383 (obj 684B/window 688B); on yields MATCH nd 0 (obj 680B/window 688B) by hoisting the case-zero constants. */
#pragma opt_loop_invariants on
// FUN_0012DEA0
s32 func_0012dea0(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 i0;
    s32 i1;
    s32 i3;
    u8 *p;
    u8 *src0;
    u8 *dst0;
    u8 *src1;
    u8 *dst1;
    u8 *src3;
    u8 *dst3;

    if (*(s32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0xC) = 0;
    i = 0;
    while (i < 0xB) {
        p = arg0 + i * 0x30;
        *(f32 *)(p + 0x94) = *(f32 *)(p + 0xA4);
        *(f32 *)(p + 0x98) = *(f32 *)(p + 0xA8);
        *(u8 *)(p + 0xAC) = *(u8 *)(p + 0xAE);
        *(u16 *)(p + 0xB0) = *(u16 *)(p + 0xB4);
        *(u16 *)(p + 0xB6) = *(u16 *)(p + 0xBA);
        i++;
    }
    switch (arg1) {
    case 0:
        i0 = 0;
        while (i0 < 0xB) {
            if (i0 != *(s32 *)(arg0 + 0x10)) {
                src0 = D_005E58C0 + i0 * 0x14;
                dst0 = arg0 + i0 * 0x30;
                *(f32 *)(dst0 + 0x9C) = *(f32 *)(src0 + 0);
                *(f32 *)(dst0 + 0xA0) = *(f32 *)(src0 + 4);
                *(u8 *)(dst0 + 0xAD) = *(u8 *)(src0 + 8);
                *(u16 *)(dst0 + 0xB8) = *(u16 *)(src0 + 0xA);
                *(s32 *)(dst0 + 0xBC) = *(s32 *)(src0 + 0xC);
                *(s32 *)(dst0 + 0xC0) = *(s32 *)(src0 + 0x10);
            } else {
                dst0 = arg0 + i0 * 0x30;
                *(s32 *)(dst0 + 0x94) = 0;
                *(s32 *)(dst0 + 0x9C) = 0;
                *(s32 *)(dst0 + 0x98) = 0x41B80000;
                *(s32 *)(dst0 + 0xA0) = 0;
                *(u8 *)(dst0 + 0xAC) = 0;
                *(u8 *)(dst0 + 0xAD) = 0xFF;
                *(u16 *)(dst0 + 0xB6) = 1;
                *(u16 *)(dst0 + 0xB8) = 0x1000;
                *(s32 *)(dst0 + 0xBC) = 0xB;
                *(s32 *)(dst0 + 0xC0) = 0xD;
            }
            i0++;
        }
        break;
    case 1:
        i1 = 0;
        while (i1 < 0xB) {
            src1 = D_005E59A0 + i1 * 0x14;
            dst1 = arg0 + i1 * 0x30;
            *(f32 *)(dst1 + 0x9C) = *(f32 *)(src1 + 0);
            *(f32 *)(dst1 + 0xA0) = *(f32 *)(src1 + 4);
            *(u8 *)(dst1 + 0xAD) = *(u8 *)(src1 + 8);
            *(u16 *)(dst1 + 0xB8) = *(u16 *)(src1 + 0xA);
            *(s32 *)(dst1 + 0xBC) = *(s32 *)(src1 + 0xC);
            *(s32 *)(dst1 + 0xC0) = *(s32 *)(src1 + 0x10);
            i1++;
        }
        break;
    case 2:
        func_0012dc00(arg0);
        break;
    case 3:
        i3 = 0;
        while (i3 < 0xB) {
            dst3 = arg0 + i3 * 0x30;
            *(s32 *)(dst3 + 0x94) = 0;
            *(s32 *)(dst3 + 0x98) = 0;
            src3 = D_005E5A80 + i3 * 0x14;
            *(f32 *)(dst3 + 0x9C) = *(f32 *)(src3 + 0);
            *(f32 *)(dst3 + 0xA0) = *(f32 *)(src3 + 4);
            *(u8 *)(dst3 + 0xAD) = *(u8 *)(src3 + 8);
            *(u16 *)(dst3 + 0xB8) = *(u16 *)(src3 + 0xA);
            *(s32 *)(dst3 + 0xBC) = *(s32 *)(src3 + 0xC);
            *(s32 *)(dst3 + 0xC0) = *(s32 *)(src3 + 0x10);
            i3++;
        }
        break;
    }
    return 1;
}
/* measured: closes the opt_loop_invariants bracket for func_0012dea0. */
#pragma opt_loop_invariants off
#pragma pop
// FUN_0012E150
void func_0012e150(s32 arg0)
{
    s32 temp_4;
    s32 var_17;
    u8 *temp_3;
    u8 *temp_16;

    var_17 = 0;
    while (var_17 < 0x15) {
        temp_3 = (u8 *)(arg0 + (var_17 * 4));
        temp_16 = temp_3 + 0x3C;
        temp_4 = *(s32 *)temp_16;
        if (temp_4 != 0) {
            func_0046d280((void *)temp_4);
            *(s32 *)temp_16 = 0;
        }
        var_17 += 1;
    }
}
// FUN_0012E1D0
s32 func_0012e1d0(u8 *arg0)
{
    s32 var_16 = 1;
    s32 var_5 = 0;
    s32 temp_3 = *(s16 *)(arg0 + 0xC);

    while (var_5 < 0xB) {
        if (temp_3 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & func_0034c210();
}
// FUN_0012E250
s32 func_0012e250(u8 *arg0)
{
    s32 temp_3 = *(s32 *)(arg0 + 0x18);
    s32 var_16 = 1;
    s32 var_5;
    s32 temp_4;

    if (temp_3 == var_16) {
        goto block_early;
    }
    if (temp_3 != 2) {
        goto block_loop;
    }
block_early:
    return 1;
block_loop:
    var_5 = 0;
    temp_4 = *(s16 *)(arg0 + 0xC);
    while (var_5 < 0xB) {
        if (temp_4 < *(s32 *)(arg0 + (var_5 * 0x30) + 0xC0)) {
            var_16 = 0;
        }
        var_5 += 1;
    }
    return var_16 & func_0034c210();
}
/* measured: opt_loop_invariants on hoists the conversion constants into the loop preheader. */
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
// FUN_0012E2F0
s32 func_0012e2f0(u8 *arg0)
{
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    s16 n;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;
    u8 *base_5f40;
    u8 *res_1;
    u8 *res_2;
    u8 *res_3;
    u8 *res_slot;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    u16 temp_u16;
    s32 temp_byte;
    s16 ii;

    func_0043f9c8(arg0, 0, 0x1BE8);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)arg0 = 0xFF;
    *(s32 *)(arg0 + 0x30) = -1;
    *(s16 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    for (i = 0; i < 3; i++) {
        *(s16 *)(arg0 + (i * 2) + 0x22) = 0;
    }
    j = 0;
    base_5f40 = D_005E5F40;
    for (; j < 30; j++) {
        temp_2 = base_5f40 + (j * 0x1C);
        temp_3 = arg0 + (j * 0x30);
        *(f32 *)(temp_3 + 0x12E8) = *(f32 *)temp_2;
        *(f32 *)(temp_3 + 0x12EC) = *(f32 *)(temp_2 + 4);
        *(u8 *)(temp_3 + 0x12F2) = *(u8 *)(temp_2 + 0x10);
        temp_u16 = (u16)*(f32 *)(temp_2 + 8);
        *(u16 *)(temp_3 + 0x12F8) = temp_u16;
        temp_u16 = (u16)*(f32 *)(temp_2 + 0xC);
        *(u16 *)(temp_3 + 0x12FE) = temp_u16;
    }
    for (k = 0; k < 12; k++) {
        *(s32 *)(arg0 + (k * 0x30) + 0x1888) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x1878) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x1884) = -1027080192;
        *(s32 *)(arg0 + (k * 0x30) + 0x187C) = -1027080192;
        *(u8 *)(arg0 + (k * 0x30) + 0x1891) = 127;
        *(u8 *)(arg0 + (k * 0x30) + 0x1890) = 127;
        *(s32 *)(arg0 + (k * 0x30) + 0x18A0) = 0;
        *(s32 *)(arg0 + (k * 0x30) + 0x18A4) = 10;
    }
    for (m = 0; m < 84; m++) {
        *(s32 *)(arg0 + (m * 0x14) + 0xC4C) = m % 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC54) = 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC50) = m / 7;
        *(s32 *)(arg0 + (m * 0x14) + 0xC58) = 12;
    }
    for (n = 0; n < 2; n++) {
        *(s32 *)(arg0 + (n * 0x30) + 0x1AC8) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AB8) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AC4) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1ABC) = 0;
        *(u8 *)(arg0 + (n * 0x30) + 0x1AD1) = 0;
        *(u8 *)(arg0 + (n * 0x30) + 0x1AD0) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AE0) = 0;
        *(s32 *)(arg0 + (n * 0x30) + 0x1AE4) = 3;
    }
    *(s16 *)(arg0 + 0x3C) = func_00353b50(arg0 + 0x34);
    res_1 = (u8 *)func_0046a770(D_005E5830);
    if (res_1 == NULL) {
        func_0046d730(D_005E76C8, 0x1FA);
    }
    res_2 = (u8 *)func_0046a770(D_005E5850);
    if (res_2 == NULL) {
        func_0046d730(D_005E76C8, 0x1FC);
    }
    temp_16 = (s32)func_0046a770(D_005E57F0);
    res_3 = (u8 *)temp_16;
    *(u8 **)(arg0 + 0x1BE4) = (u8 *)temp_16;
    if (res_3 == NULL) {
        func_0046d730(D_005E76C8, 0x1FE);
    }
    ii = 0;
    while (ii < 51) {
        if (ii < 28) {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = func_0046d200(res_1, temp_byte);
            *(s32 *)res_slot = temp_16;
        } else if (ii < 49) {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = func_0046d200(res_2, temp_byte);
            *(s32 *)res_slot = temp_16;
        } else {
            res_slot = arg0 + (ii * 4) + 0x1B18;
            temp_byte = D_005E7670[ii];
            temp_16 = func_0046d200(res_3, temp_byte);
            *(s32 *)res_slot = temp_16;
        }
        if (*(s32 *)res_slot == 0) {
            func_0046d730(D_005E76C8, 0x20B);
        }
        ii++;
    }
    func_0012e7c0(arg0);
    return func_0012ff60(arg0, 0);
}
#pragma opt_rebuildconditionals on
/* measured: closes the opt_loop_invariants bracket for func_0012e2f0. */
#pragma opt_loop_invariants off
/* measured: opt_propagation off probe for temp16 width in func_0012e7c0 */
#pragma opt_propagation off
// FUN_0012E7C0
void func_0012e7c0(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4;
    s64 temp_4_2;
    s16 var_18;
    s16 var_17;
    u8 *temp_3;

    var_17 = 0;
    var_18 = 0;
    goto loop_test;
loop_body:
    temp_16 = (s32)temp_4 + 0x300;
    temp_4_2 = (s64)(s16)(func_00106600(temp_16) & 0xFF);
    if (temp_4_2 != 0) {
        temp_3 = arg0 + ((s16)var_17 * 4);
        *(s16 *)(temp_3 + 0x3E) = (s16)temp_16;
        *(s16 *)(temp_3 + 0x40) = (s16)temp_4_2;
        var_17 += 1;
    }
    var_18 += 1;
loop_test:
    temp_4 = var_18;
    if (temp_4 < 0x300) {
        goto loop_body;
    }
    *(s16 *)(arg0 + 0xC3E) = var_17;
    if (var_17 <= 0x300) {
        goto guard_done;
    }
    func_0046d730(D_005E76C8, 0x225);
guard_done:
    ;
}
/* measured: opt_propagation on closes the temp16 width probe */
#pragma opt_propagation on
// FUN_0012E8B0
s32 func_0012e8b0(u8 *arg0)
{
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0x18);
    switch (temp_3) {
    case 0:
        *(s32 *)(arg0 + 0x18) = temp_3 + 1;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
// FUN_0012E900
s32 func_0012e900(u8 *arg0) {
    s16 temp_2;
    s32 var_17;
    s32 var_16;
    u8 *temp_19;

    var_16 = 1;
    temp_2 = *(s16 *)(arg0 + 0x1C);
    if (temp_2 < 0x64) {
        *(s16 *)(arg0 + 0x1C) = temp_2 + 1;
    }
    var_17 = 0;
    goto loop_test_0012e900;
loop_body_0012e900:
    temp_19 = arg0 + (var_17 * 0x30);
    func_001437b0(temp_19 + 0x12D8, *(s16 *)(arg0 + 0x1C), 0);
    if (*(u8 *)(temp_19 + 0x12F2) != 0) {
        var_16 = 0;
    }
    var_17 += 1;
loop_test_0012e900:
    if (var_17 < 0x1E) {
        goto loop_body_0012e900;
    }
    func_0012fdf0(arg0);
    func_0012feb0(arg0);
    func_0012e9d0(arg0);
    return var_16;
}
/* measured func_0012e9d0: retail 5152B/1288 vs B8a draft 4968B/1242 (-184B/-46, -3.6%, below 3% floor 4997B/1249 by 29B/7; probe 1188w; fnalign 635 edits +1 reloc-only (retail 1286 vs object 1242); frame -0x100 both; stb[4] top-staging @0xFC + fx/fy spills @0xF0/0xF4 match; gp-fidelity kept (iGpffff9cc8 lw, fGpffff854c/8170 lwc1); s32 idx; two-pointer r. Path: single u32 dances (-154B vs manual-double), tu/fs/fret folds, stb+stack[0x30]. Parked: clamp bc1f (both source forms canonicalize), f26 colour wall (block-scoping inert: B6a -13B/neutral words), fx/fy spill-vs-save, struct home 0xB0 vs 0xC4. Prior best 5552B/1388 GUARDED_SCORE 1291. */
/* measured 0012e9d0 (owner, 2026-09-19): fnalign **659 -> 657 edits**, count
   1264 -> 1262 against retail 1286, by turning one constant-bound `for` loop into
   the `do { } while` retail emits - no guard before the first iteration, one compare
   at the bottom.  Second pass of the sweep: 13 of 69 further floors improved. */
/* measured 0012e9d0 (owner, 2026-09-19): fnalign **657 -> 655 edits**, count
   1262 -> 1260 against retail 1286, converting a SECOND constant-bound `for` loop
   to `do { } while` after the first conversion was already banked.
   The lever is iterative, which the first sweep hid: it converts the single best loop
   per function, so re-running it after installing finds the next one.  The third pass
   improved 14 more floors, `func_001ed700` by 89 edits on its own. */
// FUN_0012E9D0 NONMATCHING
#ifdef NON_MATCHING
void func_0012e9d0(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
    } V2_0012e9d0;
    typedef union {
        s64 s;
        f32 f[2];
    } Pack_0012e9d0;
    extern void func_0034f1e0(void);
    extern void func_0034c270(V2_0012e9d0 arg0, s32 arg1, s32 arg2, f32 fparg0);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u32 arg4);
    extern f32 func_0034f720(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2);
    extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u32 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
    extern void func_00130c30(u8 *arg0, s64 arg1, s32 arg2);
    extern void func_001125d0(u8 *arg0);
    extern void func_00112300(s64 arg0, f32 fparg0, u8 arg1, u8 *arg2);
    extern void func_00130680(u8 *arg0, s32 arg1);
    extern u32 func_00106880(s16 arg0);
    extern void func_00274ed0(s32 color, s32 font, s32 mode, s32 glyph, s32 arg4, s32 arg5, f32 x, f32 y, f32 scale);
    extern void func_00130ce0(u8 *arg0, s64 arg1, s32 arg2, s16 *arg3);
    extern void func_0034f9d0(V2_0012e9d0 arg0, s32 arg1, f32 fparg0, s32 arg2, s32 arg3);
    extern u8 D_005E76B0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E4[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2F4[];
    extern u8 D_005E5BD0[];
    extern u8 *iGpffff9cc8;
    extern f32 fGpffff854c;
    extern f32 fGpffff8170;
    Pack_0012e9d0 pack;
    f32 f23;
    f32 f22;
    f32 f24;
    s32 tu;
    f32 fs;
    f32 fmul;
    s32 aval;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 temp21;
    void *h19;
    u8 *q;
    u8 *r;
    f32 fx;
    f32 fy;
    f32 f20;
    f32 f21;
    f32 f25;
    f32 fret;
    u8 stack[0x30];
    u8 stb[4];
    s32 idx;
    s16 s16a;
    s16 s16b;
    u32 uret;
    u8 *tab;
    s32 divd;
    s32 divn;
    func_0034f1e0();
    f23 = *(f32 *)(arg0 + 4);
    f22 = *(f32 *)(arg0 + 8);
    tu = *(u8 *)(arg0 + 0);
    if (tu >= 0) {
        fs = (f32)tu;
    } else {
        fs = (f32)(((u32)tu >> 1) | (tu & 1));
        fs += fs;
    }
    f24 = fs / 255.0f;
    if (*(s32 *)(arg0 + 0x10) != 0) {
        V2_0012e9d0 pos;
        pos.x = f23;
        pos.y = f22;
        fmul = 255.0f * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        func_0034c270(pos, aval & 0xFF, *(s32 *)(arg0 + 0x10), 0.0f);
    }
    temp21 = *(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x22);
    if ((*(s32 *)(arg0 + 0x14) & 0x200) != 0) {
        h19 = *(void **)(arg0 + 0x1B50);
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);
        fmul = 190.0f * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        m = aval & 0xFF;
        i = 0;
        do {
            q = arg0 + i * 0x30;
            fx = 363.0f + (f23 + *(f32 *)(q + 0x1888));
            fy = 8.0f + (f22 + *(f32 *)(q + 0x188C));
            func_0034f2e0(h19, fx, fy, 0, 0xFF, 0x64, (u32)m);
            i++;
        } while (i < 0xC);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
        fx = 363.0f + (f23 + *(f32 *)(arg0 + 0x17F8));
        fy = 8.0f + (f22 + *(f32 *)(arg0 + 0x17FC));
        fmul = (f32)(u32)*(u8 *)(arg0 + 0x1802) * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        m = aval & 0xFF;
        j = 0;
        do {
            q = arg0 + j * 0x14;
            r = q + 0xC48;
            if (*(s16 *)r >= 0) {
                f21 = fx + (f32)(*(s32 *)(r + 4) * 44);
                f25 = fy + (f32)(*(s32 *)(r + 8) * 37);

                tab = D_005E76B0 + *(s16 *)r * 4;
                stb[0] = tab[0];
                stb[1] = tab[1];
                stb[2] = tab[2];
                stb[3] = tab[3];
                fmul = (f32)(u32)m * func_0034f720(r, fGpffff854c, fGpffff854c, fGpffff8170);
                if (!(2147483648.0f <= fmul)) {
                    aval = (s32)fmul & 0xFF;
                } else {
                    aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
                }
                stb[3] = (u8)(aval & 0xFF);
                func_0034f2e0(h19, f21, f25, stb[0], stb[1], stb[2], (u32)(aval & 0xFF));
            }
            j++;
        } while (j < 0x54);
    }
    if ((*(s32 *)(arg0 + 0x14) & 1) != 0) {
        fx = 152.0f + (f23 + *(f32 *)(arg0 + 0x12E8));
        fy = 370.0f + (f22 + *(f32 *)(arg0 + 0x12EC));
        fmul = (f32)(u32)*(u8 *)(arg0 + 0x12F2) * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        func_0034f2e0(*(void **)(arg0 + 0x1BDC), fx, fy, 0xFF, 0xFF, 0xFF, (u32)(aval & 0xFF));
    }
    if ((*(s32 *)(arg0 + 0x14) & 0x40) != 0) {
        fx = 16.0f + (f23 + *(f32 *)(arg0 + 0x1798));
        fy = 405.0f + (f22 + *(f32 *)(arg0 + 0x179C));
        fmul = (f32)(u32)*(u8 *)(arg0 + 0x17A2) * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        func_0034f2e0(*(void **)(arg0 + 0x1B88), fx, fy, 0xFF, 0xFF, 0xFF, (u32)(aval & 0xFF));
    }
    if ((*(s32 *)(arg0 + 0x14) & 0x80) != 0) {
        fx = 62.0f + (f23 + *(f32 *)(arg0 + 0x17C8));
        fy = 405.0f + (f22 + *(f32 *)(arg0 + 0x17CC));
        fmul = (f32)(u32)*(u8 *)(arg0 + 0x17D2) * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        func_0034f2e0(*(void **)(arg0 + 0x1B8C), fx, fy, 0xFF, 0xFF, 0xFF, (u32)(aval & 0xFF));
    }
    if ((*(s32 *)(arg0 + 0x14) & 8) != 0) {
        fx = 271.0f + (f23 + *(f32 *)(arg0 + 0x1468));
        fy = 21.0f + (f22 + *(f32 *)(arg0 + 0x146C));
        fmul = (f32)(u32)*(u8 *)(arg0 + 0x1472) * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        pack.f[0] = fx;
        pack.f[1] = fy;
        stb[0] = D_0064B2F4[0];
        stb[1] = D_0064B2F4[1];
        stb[2] = D_0064B2F4[2];
        stb[3] = (u8)(aval & 0xFF);
        func_00130c30(arg0, pack.s, *(s32 *)stb);
        func_001125d0(stack);
        q = arg0 + temp21 * 4;
        *(s16 *)(stack + 0) = *(s16 *)(q + 0x3E);
        *(s16 *)(stack + 2) = *(s16 *)(q + 0x40);
        *(s32 *)(stack + 8) = -1;
        *(s32 *)(stack + 0xC) = 1;
        *(s32 *)(stack + 0x10) = 0;
        *(s16 *)(stack + 0x18) = 4;
        *(s16 *)(stack + 0x14) = 1;
        *(s16 *)(stack + 0x16) = 4;
        pack.f[0] = fx + 1.0f;
        pack.f[1] = fy;
        func_00112300(pack.s, 0.0f, (u8)(aval & 0xFF), stack);
    }
    if ((*(s32 *)(arg0 + 0x14) & 4) != 0) {
        for (k = 0; k < *(s16 *)(arg0 + 0x3C); k++) {
            func_00130680(arg0, k);
        }
    }
    if ((*(s32 *)(arg0 + 0x14) & 0x400) != 0) {
        f20 = *(f32 *)(arg0 + 0x1AFC) + (f22 + *(f32 *)(arg0 + 0x15BC));
        fmul = (f32)(u32)*(u8 *)(arg0 + 0x15C2) * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        m = aval & 0xFF;
        f21 = 573.0f + (*(f32 *)(arg0 + 0x1AF8) + (f23 + *(f32 *)(arg0 + 0x15B8)));
        fx = f21;
        fy = 32.0f + f20;
        func_0034f2e0(*(void **)(arg0 + 0x1B44), fx, fy, 0xFF, 0xFF, 0xFF, (u32)m);
        fy = 197.0f + f20;
        func_0034f2e0(*(void **)(arg0 + 0x1B48), fx, fy, 0xFF, 0xFF, 0xFF, (u32)m);
        fy = 35.0f + f20;
        divd = (s32)*(s16 *)(arg0 + 0xC3E) - 6;
        if (divd > 0) {
            divn = (s32)*(s16 *)(arg0 + 0x24) * 134;
            fy += (f32)(divn / divd);
        }
        func_0034f2e0(*(void **)(arg0 + 0x1B4C), fx, fy, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], (u32)m);
    }
    if ((*(s32 *)(arg0 + 0x14) & 2) != 0) {
        if (*(s16 *)(arg0 + 0xC3E) == 0) {
            fx = 280.0f + (f23 + *(f32 *)(arg0 + 0x1318));
            fy = 20.0f + (f22 + *(f32 *)(arg0 + 0x131C));
            func_00274ed0((s32)(*(u8 *)(arg0 + 0x1322) | 0xFFFFFF00), 6, 1, (s32)iGpffff9cc8, 0, 0, fx, fy, 0.0f);
        } else {
            if (*(u8 *)(arg0 + 0x1AD2) != 0) {
                fx = f23 + *(f32 *)(arg0 + 0x1AC8);
                fy = f22 + *(f32 *)(arg0 + 0x1ACC);
                func_0034f320(*(u8 **)(arg0 + 0x1B18), fx, fy, 0.0f, D_0064B2E4[0], D_0064B2E4[1], D_0064B2E4[2], *(u8 *)(arg0 + 0x1AD2), 0x1000, 0x1000, 0, 0.0f, 0);
            }
            for (n = 0; n < 6; n++) {
                idx = n + *(s16 *)(arg0 + 0x24);
                if (idx < *(s16 *)(arg0 + 0xC3E)) {
                    q = arg0 + idx * 4;
                    s16a = *(s16 *)(q + 0x3E);
                    s16b = *(s16 *)(q + 0x40);
                    uret = func_00106880(s16a);
                    if (n == *(s16 *)(arg0 + 0x22)) {
                        tab = D_0064B2EC;
                        if ((*(s32 *)(arg0 + 0x14) & 0x100) != 0) {
                            continue;
                        }
                            fx = 223.0f + (f23 + *(f32 *)(arg0 + 0x1318));
                            fy = 21.0f + (*(f32 *)(arg0 + 0x131C) + (f22 + 34.0f * (f32)n));
                            fmul = (f32)(u32)*(u8 *)(arg0 + 0x1322) * f24;
                            if (!(2147483648.0f <= fmul)) {
                                aval = (s32)fmul & 0xFF;
                            } else {
                                aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
                            }
                            stb[0] = D_0064B2E8[0];
                            stb[1] = D_0064B2E8[1];
                            stb[2] = D_0064B2E8[2];
                            stb[3] = (u8)(aval & 0xFF);
                            pack.f[0] = fx;
                            pack.f[1] = fy;
                            func_00130c30(arg0, pack.s, *(s32 *)stb);
                    } else {
                        tab = D_0064B2E0;
                        q = arg0 + n * 0x30;
                        fx = 221.0f + (f23 + *(f32 *)(q + 0x1498));
                        fy = 21.0f + (*(f32 *)(q + 0x149C) + (f22 + 34.0f * (f32)n));
                        fmul = (f32)(u32)*(u8 *)(q + 0x14A2) * f24;
                        if (!(2147483648.0f <= fmul)) {
                            aval = (s32)fmul & 0xFF;
                        } else {
                            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
                        }
                        func_0034f320(*(u8 **)(arg0 + 0x1B18), fx, fy, 0.0f, D_0064B2E4[0], D_0064B2E4[1], D_0064B2E4[2], (u32)(aval & 0xFF), 0x1000, *(u16 *)(q + 0x14AE), 0, 0.0f, 0);
                    }
                    q = arg0 + n * 0x30;
                    fx = 224.0f + (f23 + *(f32 *)(q + 0x1498));
                    f20 = 34.0f * (f32)n;
                    fy = f20 + (23.0f + (f22 + *(f32 *)(q + 0x149C)));
                    fmul = (f32)(u32)*(u8 *)(q + 0x14A2) * f24;
                    if (!(2147483648.0f <= fmul)) {
                        aval = (s32)fmul & 0xFF;
                    } else {
                        aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
                    }
                    if ((uret & 0x10000) != 0) {
                        h19 = *(void **)(arg0 + 0x1B9C);
                    } else if ((uret & 0x20000) != 0) {
                        h19 = *(void **)(arg0 + 0x1BA0);
                    } else {
                        h19 = *(void **)(arg0 + 0x1B98);
                    }
                    func_0034f320(h19, fx, fy, 0.0f, tab[0], tab[1], tab[2], (u32)(aval & 0xFF), 0x1000, *(u16 *)(q + 0x14AE), 0, 0.0f, 0);
                    fx = 266.0f + (f23 + *(f32 *)(q + 0x1348));
                    fy = 21.0f + (*(f32 *)(q + 0x134C) + (f22 + f20));
                    pack.f[0] = fx;
                    pack.f[1] = fy;
                    func_001125d0(stack);
                    *(s16 *)(stack + 0) = s16a;
                    *(s16 *)(stack + 2) = s16b;
                    *(s32 *)(stack + 8) = -1;
                    *(s32 *)(stack + 0xC) = 1;
                    *(s32 *)(stack + 0x10) = 0;
                    *(s16 *)(stack + 0x18) = 4;
                    if (n == *(s16 *)(arg0 + 0x22)) {
                        *(s16 *)(stack + 0x14) = 0;
                        *(s16 *)(stack + 0x16) = 3;
                    } else {
                        *(s16 *)(stack + 0x14) = 0;
                        *(s16 *)(stack + 0x16) = 2;
                    }
                    fmul = (f32)(u32)*(u8 *)(q + 0x1352) * f24;
                    if (!(2147483648.0f <= fmul)) {
                        aval = (s32)fmul & 0xFF;
                    } else {
                        aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
                    }
                    func_00112300(pack.s, 0.0f, (u8)(aval & 0xFF), stack);
                }
            }
        }
    }
    if (((*(s32 *)(arg0 + 0x14) & 0x100) != 0) && (*(s16 *)(arg0 + 0xC3E) != 0)) {
        fx = 223.0f + (f23 + *(f32 *)(arg0 + 0x1318));
        fy = 21.0f + (*(f32 *)(arg0 + 0x131C) + (f22 + 34.0f * (f32)*(s16 *)(arg0 + 0x22)));
        fmul = (f32)(u32)*(u8 *)(arg0 + 0x15F2) * f24;
        if (!(2147483648.0f <= fmul)) {
            aval = (s32)fmul & 0xFF;
        } else {
            aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        s16a = *(s16 *)(arg0 + 0x24);
        q = arg0 + (s16a + *(s16 *)(arg0 + 0x22)) * 4;
        *(s16 *)(stack + 0) = *(s16 *)(q + 0x3E);
        *(s16 *)(stack + 2) = *(s16 *)(q + 0x40);
        *(s32 *)(stack + 8) = -1;
        *(s32 *)(stack + 0xC) = 1;
        *(s32 *)(stack + 0x10) = 0;
        *(s16 *)(stack + 0x14) = 1;
        *(s16 *)(stack + 0x16) = 3;
        *(s16 *)(stack + 0x18) = 4;
        pack.f[0] = fx;
        pack.f[1] = fy;
        func_00130ce0(arg0, pack.s, aval & 0xFF, (s16 *)stack);
    }
    {
        V2_0012e9d0 pos;
        pos.x = 640.0f + (f23 + *(f32 *)(arg0 + 0x1828));
    pos.y = 400.0f + (f22 + *(f32 *)(arg0 + 0x182C));
    tu = *(u8 *)(arg0 + 0x1832);
    if (tu >= 0) {
        fs = (f32)tu;
    } else {
        fs = (f32)(((u32)tu >> 1) | (tu & 1));
        fs += fs;
    }
    fmul = fs * f24;
    if (!(2147483648.0f <= fmul)) {
        aval = (s32)fmul & 0xFF;
    } else {
        aval = ((s32)(fmul - 2147483648.0f) | 0x80000000) & 0xFF;
    }
    func_0034f9d0(pos, aval & 0xFF, 0.0f, *(s16 *)(arg0 + 0xC40), *(s32 *)(arg0 + 0x1BE4));
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0012", func_0012e9d0);
#endif
// FUN_0012FDF0
void func_0012fdf0(u8 *arg0)
{
    s16 temp_3;
    s32 var_16;
    s32 var_16_2;
    u8 *temp_2;

    temp_3 = *(s16 *)(arg0 + 0x1E);
    if (temp_3 < 0x64) {
        temp_3 += 1;
        *(s16 *)(arg0 + 0x1E) = temp_3;
    }
    for (var_16 = 0; var_16 < 0xC; var_16++) {
        temp_2 = arg0 + (var_16 * 0x30);
        func_001437b0(temp_2 + 0x1878, *(s16 *)(arg0 + 0x1E), 0);
    }
    for (var_16_2 = 0; var_16_2 < 0x54; var_16_2++) {
        temp_2 = arg0 + (var_16_2 * 0x14);
        func_0034f5d0(temp_2 + 0xC48);
    }
}
/* measured: opt_common_subs off preserves the retail base+offset accesses in
   the two-record callback loop. */
#pragma opt_common_subs off
// FUN_0012FEB0
void func_0012feb0(u8 *arg0)
{
    s32 i;
    u8 *p;
    s32 v;

    v = *(s16 *)(arg0 + 0x20);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = arg0 + i * 0x30 + 0x1AB8;
        func_001437b0(p, *(s16 *)(arg0 + 0x20), 0);
    }
}
/* measured: opt_common_subs on closes the callback-loop probe. */
#pragma opt_common_subs on
/* The selection is passed as a word; the field stores its low halfword. */
// FUN_0012FF40
s32 func_0012ff40(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *p;

    p = (u8 *)code1_0012_stride(arg1 * 2, arg0);
    *(s16 *)(p + 0x28) = *(s16 *)(p + 0x22);
    *(s16 *)(p + 0x22) = arg2;
    return 1;
}
extern u8 D_005E5BF0[];
extern u8 D_005E6290[];
extern u8 D_005E65E0[];
extern u8 D_005E6930[];
extern u8 D_005E6C80[];
extern u8 D_005E6FD0[];
extern u8 D_005E7320[];

/* measured: opt_common_subs off preserves retail's first-loop base/index
   addressing and setup order; on reverts immediately after the switch. */
#pragma opt_common_subs off
// FUN_0012FF60
s32 func_0012ff60(u8 *arg0, u32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    table = 0;
    if (arg1 == *(u32 *)(arg0 + 0x30)) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        dst = arg0 + (i * 0x30);
        *(f32 *)(dst + 0x12d8) = *(f32 *)(dst + 0x12e8);
        *(f32 *)(dst + 0x12dc) = *(f32 *)(dst + 0x12ec);
        *(u16 *)(dst + 0x12f4) = *(u16 *)(dst + 0x12f8);
        *(u16 *)(dst + 0x12fa) = *(u16 *)(dst + 0x12fe);
        *(u8 *)(dst + 0x12f0) = *(u8 *)(dst + 0x12f2);
    }
    switch (arg1) {
    case 0:
        *(s32 *)(arg0 + 0x14) = 0x447;
        table = D_005E5BF0;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 1:
        table = D_005E5F40;
        break;
    case 2:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E6290;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 3:
        *(s32 *)(arg0 + 0x14) = 0x447;
        table = D_005E6290;
        *(s16 *)(arg0 + 0xc40) = 0x13;
        break;
    case 4:
        *(s32 *)(arg0 + 0x14) = 0x2dd;
        table = D_005E65E0;
        *(s16 *)(arg0 + 0x2c) = *(s16 *)(arg0 + 0x26);
        *(s16 *)(arg0 + 0x26) = 0;
        *(f32 *)(arg0 + 0x145c) = 34.0f * (f32)*(s16 *)(arg0 + 0x22);
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 5:
        *(s32 *)(arg0 + 0x14) = 0x2ed;
        table = D_005E6C80;
        *(f32 *)(arg0 + 0x145c) = 34.0f * (f32)*(s16 *)(arg0 + 0x22);
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 6:
        *(s32 *)(arg0 + 0x14) = 0x29d;
        table = D_005E6930;
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 7:
        *(s32 *)(arg0 + 0x14) = 0x2ad;
        table = D_005E6FD0;
        *(s16 *)(arg0 + 0xc40) = 0;
        break;
    case 8:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(arg0 + 0xc40) = 0x14;
        break;
    case 9:
        *(s32 *)(arg0 + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(arg0 + 0xc40) = 0x14;
        break;
    default:
        func_0046d730(D_005E76C8, 0x4ab);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table-loop constants and
   stride calculations into retail's preheader (without it, nd is nonzero). */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 30; j++) {
            src = table + (j * 0x1c);
            dst = arg0 + (j * 0x30);
            *(f32 *)(dst + 0x12e0) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x12e4) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0x12f1) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0x12f6) = (u16)value;
            value = *(f32 *)(src + 0xc);
            *(u16 *)(dst + 0x12fc) = (u16)value;
            *(s32 *)(dst + 0x1300) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x1304) = *(s32 *)(src + 0x18);
        }
        *(u32 *)(arg0 + 0x30) = arg1;
        *(s16 *)(arg0 + 0x1c) = 0;
    }
    return 1;
}
/* measured: closes opt_loop_invariants for func_0012ff60. */
#pragma opt_loop_invariants off
