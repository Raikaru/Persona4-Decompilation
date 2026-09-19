/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
extern void func_003549d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 func_00354830();

extern void func_0036df30(u8 *arg0);
extern void func_0036d8b0(void);
extern void *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern s32 func_0038cec0(void *arg0);
extern s32 func_00388bd0(void *arg0);
extern s32 func_0038d790(void *arg0);
extern void func_0034f1e0(void);
extern void func_00374d20(u8 *arg0);
extern s32 func_00378240(u8 *arg0);
extern s32 func_00378250(u8 *arg0);
extern s32 func_00378500(u8 *arg0);
extern void func_00378280(u8 *arg0, u8 arg1);
extern void func_00371990(u8 *arg0, u8 *arg1, u8 *arg2);
extern void func_00371ba0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern void func_00370410(u8 *arg0);
extern void func_00370a80(u8 *arg0);
extern void func_003723a0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372870(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372c30(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5);
extern void func_003730f0(u8 *arg0, s32 arg1, s32 arg2, void *arg3);
extern void func_003733d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00373590(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

typedef struct RwV3d { f32 x, y, z; } ShuffleVec3;
typedef struct { f32 x, y, z, w; } ShuffleVec4;
typedef struct RtQuat { ShuffleVec3 imag; f32 real; } ShuffleQuaternion;
typedef struct { s64 a; f32 b; } ShuffleVec2s;

extern s32 func_00442088(char *buf, const char *fmt, ...);
extern char D_0064EA80[];
extern void func_003547c0(s32 *arg0, u8 *arg1);
extern char D_0064EA20[];
extern void func_0046d730(void *file, s32 line);
extern f32 func_00373cb0(f32 fparg0, f32 fparg1, s32 arg0, f32 fparg2);
extern s64 func_001060b0(void);
extern s32 func_00110d60(s16 value);
extern char iGpffffa9d0;
extern s32 iGpffffa9c8;
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_00440b68();
extern void func_00371f40(u8 *arg0, f32 fparg0, u8 *arg1);
extern void func_00373f00(u8 *arg0);
extern void func_00371e50(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3, u8 *arg4, f32 fparg0);
extern void func_0046b0d0(void *ptr);
extern void func_0044ea90(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern f32 func_00373c20(u8 *arg0);
extern s32 func_00106330(s32 arg0);
extern void func_0036c900(void);
extern void func_0036d990(u8 *arg0, u8 *arg1);
extern void func_0036dda0(u8 *arg0, void *arg1);
extern void func_0036de20(u8 *arg0, void *arg1);
extern void func_0036de40(u8 *arg0, void *arg1);
extern void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00373750(s32 arg0, s32 arg1, void *arg2);
extern s32 func_00451fc0(u8 *arg0, const void *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, u8 *arg7);
extern void func_003781d0(u8 *arg0, s32 arg1);
extern void func_00378260(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4);
extern char D_0064EA60[];
extern f32 iGpffff83e0;
extern s32 func_00371a60(u8 *arg0, s32 arg1);
extern s32 func_00371c70(u8 *arg0);
extern void func_00370640(u8 *arg0);
extern s32 func_003720c0(u8 *arg0);
extern s32 func_00372200(u8 *arg0);
extern s32 func_003724f0(u8 *arg0);
extern s32 func_003726b0(u8 *arg0);
extern s32 func_00372960(u8 *arg0);
extern s32 func_00372d60(u8 *arg0);
extern void func_00370cd0(u8 *arg0);
extern s32 func_00373170(u8 *arg0);
extern void func_003733f0(u8 *arg0);
extern void func_00373610(u8 *arg0);
extern void func_00375f00(u8 *arg0, s32 arg1);
extern s32 func_004553c0(s32 arg0);
extern u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);
extern void func_0043f810(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0046af60(s32 arg0);
extern void func_0036d230(s32 arg0);
extern s32 func_0046a750(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_003768e0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, f32 fparg0);
extern f32 func_00375a70(u8 *arg0, s32 arg1);
extern f32 iGpffff8170;
extern void func_003766f0(f32 **arg0, s32 arg1, s32 arg2, u8 *arg3);
extern void func_00376800(u8 **arg0, s32 arg1);
extern void func_00374910(u8 *arg0);
extern void func_00375d50(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 *arg2, f32 *arg3);
extern void func_00375dd0(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1);
extern void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5);
extern void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 func_0036de70(u8 *arg0);
extern f32 func_0036deb0(u8 *arg0);
extern void *func_003e0f80(void);
extern void *func_003e0c90(void *arg0, const void *arg1, s32 arg2);
extern void func_003e42a0(void *arg0, void *arg1, void *arg2);
extern void func_003717e0(void *arg0, void *arg1);
extern void func_003e0f40(void *arg0);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern f32 D_008872F8[];
extern void (*D_00887300[])(u32, u32);
extern s32 (*D_00887310[])(s32, void *, s32);
extern ShuffleQuaternion *func_003dc740(ShuffleQuaternion *dst,
                                       const ShuffleVec3 *axis,
                                       f32 angle, s32 combine);
extern s64 D_0064EA48[];
extern f32 D_0064EA50[];
extern s64 D_0064EA38[];
extern f32 D_0064EA40[];
extern f32 iGpffff840c;
extern f32 iGpffff81e0;
extern void *func_003e9700(s32 arg0);
extern void func_003e0e20(u8 *arg0, void *arg1, s32 arg2);
extern void func_003f6440(s32 arg0, s32 arg1);
extern s32 func_0036be00(void);
extern void func_00410420(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_004106a0(s32 arg0);
extern f32 DAT_007613f8;
extern f32 iGpffff8218;
extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
extern f32 func_0044b610(f32 fparg0);
extern void func_003e0a90(void *arg0, void *arg1, s32 arg2);


// FUN_00373E10
void func_00373e10(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg2 > 8) {
        func_0046d730(D_0064EA20, 0x53);
    }
    if ((arg3 < 0) || (arg3 > 4)) {
        func_0046d730(D_0064EA20, 0x54);
    }
    *(s32 *)(arg0 + 0x1F2A8) = arg1;
    *(s32 *)(arg0 + 0x1F304) = arg2;
    *(s32 *)(arg0 + 0x1F2FC) = arg3;
    *(s32 *)(arg0 + 0x1F300) = arg4;
    *(s32 *)(arg0 + 0x1F30C) = 0;
    func_00373f00(arg0);
}


// FUN_00373F00
void func_00373f00(u8 *arg0) {
    s32 count;
    s32 v;
    s32 i;
    u8 *p;

    func_0043f9c8(arg0 + 0x1F1D0, 0, 0x40);
    func_0043f9c8(arg0 + 0x1D6A0, 0, 0x1B30);
    *(u16 *)(arg0 + 0x1F2F4) = 0;
    *(s32 *)(arg0 + 0x1F2F8) = 0;
    *(u16 *)(arg0 + 0x1F2F0) = 0;
    *(u16 *)(arg0 + 0x1F2F2) = 0;
    *(s32 *)(arg0 + 0x1F308) = -1;
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    v = *(s32 *)(arg0 + 0x1F2FC);
    switch (v) {
    case 0:
    case 1:
    case 2:
        *(s32 *)(arg0 + 0x1F310) = 0x42480000;
        break;
    case 3:
    case 4:
        *(s32 *)(arg0 + 0x1F310) = 0x41200000;
        break;
    default:
        func_0046d730(D_0064EA20, 0x7C);
        break;
    }
    for (i = 0; i < count; i++) {
        p = (u8 *)(arg0 + i * 0xE8);
        *(u16 *)(p + 0x1D6A0) |= 2;
    }
}


// FUN_003740B0
void func_003740b0(u8 *arg0, s32 arg1) {
    s32 count;
    s32 i;
    u8 *p;

    if ((func_00106330(0x1403) != 0) && (func_00106330(0x142B) != 0)) {
        func_0036c900();
    }
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    for (i = 0; i < count; i++) {
        func_0036d990(arg0 + i * 0xFB0, (u8 *)(arg1 + (i % *(s32 *)(arg0 + 0x1F304)) * 8));
        p = (u8 *)(arg0 + i * 0xE8);
        *(s32 *)(p + 0x1D720) = 0;
        *(s32 *)(p + 0x1D714) = 0;
        *(s32 *)(p + 0x1D718) = 0x3F800000;
        *(s32 *)(p + 0x1D71C) = 0;
    }
}


// FUN_003741F0
void func_003741f0(u8 *arg0) {
    s32 temp_17;
    s32 temp_2;

    temp_17 = !(func_00110d60((s16)func_001060b0()) & 1);
    func_00440b68(&iGpffffa9d0, D_0064EA20, 0xB5);
    temp_2 = (s32)(func_00454a60(*(u8 **)((u8 *)&iGpffffa9c8 + temp_17 * 4), 1));
    *(s32 *)(arg0 + 0x1F2E8) = temp_2;
    if (temp_2 == 0) {
        func_0046d730(D_0064EA20, 0xB6);
    }
    *(s32 *)(arg0 + 0x1F2EC) = 0;
}


/* measured (b210 -O2, 2026-09-17): if-else dispatch with shared return1 tail
   (Ghidra FUN_003742b0 + retail beq order 2,1,0); for-loop nests with reused
   i/k/tmp/val/p (Ghidra iVar3/iVar4 reuse) give frame 0x70 and 209/212 instrs
   (836B/848B, 1.4% size diff, within 3%). probe_variants 126 words (was 184
   m2c-switch, 176 for-loop-switch, 128 if-else-switch); fnalign 65 edits +10
   reloc-only (was 136+10). Decl order state,i,size,p,val,tmp,k via
   probe_search 300 (126w/65e vs 128w/75e baseline). Levers: Ghidra if-else
   over switch (-42w), hoisted full-address p=arg0+i*4+off after alloc for
   loop1/3, sunk loop2 store (hoist +30w, confirmed load-sinking floor).
   Residual floors: (1) arg-materialisation order before D_008873F4/f43f810
   (lw sp vs constants first); (2) loop2 hoist retail $18-before vs mwcc sink
   as lui $v1,2/sw -0xd54 (tried, +30w); (3) saved-color rotation arg0 $s3 vs
   $s0 + branch-orientation beqz+b vs bnez. Production stays ASM. */
/* 2026-09-18 measurement, not installed: retail materialises
   `arg0 + i * 4 + 0x1F2AC` into a saved register before the two calls in
   the second loop (`sll / addu / lui / ori / addu s2`), where b210 forms it
   at the store.  A pointer local for that store takes the object from three
   instructions short to two (210 vs 212) but costs 126 -> 158 words in
   colouring; doing the same for the later read as well is 176.  Same
   structural-fix-costs-words pattern as func_002e5000 in src/Yajima/
   y_list.c. */
// FUN_003742B0 NONMATCHING
#ifdef NON_MATCHING
s32 func_003742b0(u8 *arg0)
{
    s32 state;
    s32 i;
    s32 size;
    u8 *p;
    s32 val;
    s32 tmp;
    s32 k;
    state = *(s32 *)(arg0 + 0x1F2EC);
    if (state != 2) {
        if (state != 1) {
            if ((state != 0) || (func_004553c0(*(s32 *)(arg0 + 0x1F2E8)) == 0)) {
                return 0;
            }
            k = 0;
            for (i = 0; i < 9; i++) {
                tmp = (s32)func_00455ea0((u8 *)(*(s32 *)(arg0 + 0x1F2E8)), k, &size);
                func_0044ea90(&D_0064EA20, 0x101);
                val = (s32)D_008873F4[0](1, size, 0x40000);
                p = arg0 + i * 4 + 0x1F2B8;
                *(s32 *)p = val;
                if (val == 0) {
                    func_0046d730(&D_0064EA20, 0x102);
                }
                func_0043f810(*(s32 *)p, tmp, size);
                k++;
            }
            for (i = 0; i < 3; i++) {
                val = func_0046af60((s32)func_00455ea0((u8 *)(*(s32 *)(arg0 + 0x1F2E8)), k, NULL));
                *(s32 *)(arg0 + i * 4 + 0x1F2AC) = val;
                if (val == 0) {
                    func_0046d730(&D_0064EA20, 0x109);
                }
                k++;
            }
            for (i = 0; i < 3; i++) {
                tmp = (s32)func_00455ea0((u8 *)(*(s32 *)(arg0 + 0x1F2E8)), k, &size);
                func_0044ea90(&D_0064EA20, 0x10F);
                val = (s32)D_008873F4[0](1, size, 0x40000);
                p = arg0 + i * 4 + 0x1F2DC;
                *(s32 *)p = val;
                if (val == 0) {
                    func_0046d730(&D_0064EA20, 0x110);
                }
                func_0043f810(*(s32 *)p, tmp, size);
                k++;
            }
            func_0036d230((s32)func_00455ea0((u8 *)(*(s32 *)(arg0 + 0x1F2E8)), k, NULL));
            *(s32 *)(arg0 + 0x1F2EC) = 1;
        }
        for (i = 0; i < 3; i++) {
            val = *(s32 *)(arg0 + i * 4 + 0x1F2AC);
            if ((val != 0) && (func_0046a750(val) == 0)) {
                return 0;
            }
        }
        func_00454bd0(*(s32 *)(arg0 + 0x1F2E8));
        *(s32 *)(arg0 + 0x1F2E8) = 0;
        *(s32 *)(arg0 + 0x1F2EC) = 2;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003742b0);
#endif
// FUN_00374610
void func_00374610(u8 *arg0) {
    s32 i;
    s32 j;
    s32 k;
    u8 *p;
    s32 v;

    for (i = 0; i < 3; i++) {
        p = (u8 *)(arg0 + i * 4 + 0x1F2DC);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        p = (u8 *)(arg0 + j * 4 + 0x1F2AC);
        v = *(s32 *)p;
        if (v != 0) {
            func_0046b0d0((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (k = 0; k < 9; k++) {
        p = (u8 *)(arg0 + k * 4 + 0x1F2B8);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
}


// FUN_00374730
void func_00374730(u8 *arg0) {
    f32 sp68[2];
    f32 sp58[3];
    f32 sp48[3];
    f32 sp30[6];
    f32 temp_f12;
    s32 temp_5;
    s32 var_16;

    sp48[0] = 0.0f;
    sp48[1] = 0.0f;
    sp48[2] = 0.0f;
    func_00374910(arg0);
    sp30[3] = 0.0f;
    sp30[0] = 0.0f;
    sp30[1] = 1.0f;
    sp30[2] = 0.0f;
    var_16 = 0;
    goto loop_test;
loop_body:
    func_00373750(var_16, temp_5, &sp68);
    func_0036dc60(arg0 + var_16 * 0xFB0, sp68, sp58, 84.0f);
    if (*(s32 *)(arg0 + 0x1F30C) != 0) {
        temp_f12 = (f32)var_16 * (2.0f - ((f32)(*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f));
        func_00375dd0(arg0, var_16, sp48, sp58, temp_f12, 10.0f + temp_f12);
    } else {
        func_00375d50(arg0, var_16, 0.0f, 0.0f, sp58, sp58);
    }
    func_003760f0(arg0, var_16, 0, 0, sp30, sp30);
    func_00376290(arg0, var_16, 0, 0xFF, 0xFF);
    var_16++;
loop_test:
    temp_5 = *(s32 *)(arg0 + 0x1F304);
    if (var_16 < temp_5) {
        goto loop_body;
    }
    if (*(s32 *)(arg0 + 0x1F30C) != 0) {
        func_0045af60(1, 0, 5, 4);
    }
}


// FUN_00374910
void func_00374910(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
}


// FUN_00374960
void func_00374960(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
    *(s32 *)(arg0 + 0x1F298) = func_0038cec0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F294) = func_00388bd0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F29C) = func_0038d790((void *)*(s32 *)(arg0 + 0x1F2A8));
}


// FUN_00374A10
void func_00374a10(u8 *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);

    switch (*(u32 *)(p + 4)) {
    case 0:
        break;
    case 1:
        if (func_00371a60(p + 0xC, 0) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 2:
        if (func_00371a60(p + 0xC, 1) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 3:
        if (func_00371a60(p + 0xC, 2) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 4:
        if (func_00371c70(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 5:
        func_00370640(p + 0xC);
        break;
    case 6:
        if (func_003720c0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 7:
        if (func_00372200(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 8:
        if (func_003724f0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 9:
        if (func_003726b0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    default:
        func_0046d730(D_0064EA20, 0x1F5);
        break;
    }
    switch (*(s32 *)(p + 8)) {
    case 0:
        break;
    case 1:
        if (func_00372960(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    case 2:
        if (func_00372d60(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    case 3:
        func_00370cd0(p + 0x6C);
        break;
    case 4:
        if (func_00373170(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    default:
        func_0046d730(D_0064EA20, 0x218);
        break;
    }
    func_003733f0(p + 0xD8);
    func_00373610(p + 0xE0);
    if ((func_00375910(p) != 0) && (*(u16 *)p & 1)) {
        func_00375f00(arg0, arg1);
        *(u16 *)p &= 0xFFFE;
    }
}


// FUN_00374CF0
void func_00374cf0(u8 *arg0) {
    func_0036df30(*(u8 **)arg0);
}


/* 1732/1744 bytes; 37 resolved relocations and twelve zero alignment bytes.
 * The scoped axis initializer binds its twelve-byte object to D_0064EA38.
 * Natural quaternion products, native byte casts, and the u16 pre-increment
 * preserve retail's MAC order, conversion paths, and callback-visible reloads. */
// FUN_00374D20
void func_00374d20(u8 *arg0) {
    ShuffleVec3 translation;
    ShuffleVec4 rotation;
    f32 inv;
    f32 t2;
    f32 t1;
    f32 t0;
    f32 q10;
    f32 q9;
    f32 q8;
    f32 q7;
    f32 q6;
    f32 q5;
    f32 q4;
    f32 q3;
    f32 q2;
    f32 pulseFrame;
    f32 fadeFrame;
    f32 pulseAlpha;
    f32 fadeAlpha;
    f32 progress;
    s32 frontVertices;
    s32 backVertices;
    s32 texture;
    u8 *card;
    s32 camera;
    u32 renderStateBase;
    u8 pulseByte;
    u8 fadeByte;
    u8 *p;
    u8 *m;

    p = arg0 + *(s32 *)(arg0 + 0x1F308) * 0xE8 + 0x1D6A0;
    translation = *(ShuffleVec3 *)(p + 0x18);
    rotation = *(ShuffleVec4 *)(p + 0x74);
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x40) {
        card = *(u8 **)(arg0 + 0x1F2A4);
    } else {
        card = *(u8 **)(arg0 + 0x1F2A0);
    }
    frontVertices = func_00378240(card);
    backVertices = func_00378250(card);
    texture = func_00378500(card);
    m = (u8 *)func_003e0f80();
    camera = *(s32 *)((u8 *)func_00457120() + 4);
    inv = 2.0f / (rotation.x * rotation.x + rotation.y * rotation.y + rotation.z * rotation.z +
                  rotation.w * rotation.w);
    t2 = rotation.x * inv;
    t1 = rotation.y * inv;
    t0 = rotation.z * inv;
    q10 = t2 * rotation.w;
    q9 = t1 * rotation.w;
    q8 = t0 * rotation.w;
    q7 = rotation.x * t2;
    q6 = rotation.y * t1;
    q5 = rotation.z * t0;
    q4 = rotation.y * t0;
    q3 = rotation.z * t2;
    q2 = rotation.x * t1;
    *(f32 *)(m + 0x00) = 1.0f - (q6 + q5);
    *(f32 *)(m + 0x04) = q2 + q8;
    *(f32 *)(m + 0x08) = q3 - q9;
    *(f32 *)(m + 0x10) = q2 - q8;
    *(f32 *)(m + 0x14) = 1.0f - (q5 + q7);
    *(f32 *)(m + 0x18) = q4 + q10;
    *(f32 *)(m + 0x20) = q3 + q9;
    *(f32 *)(m + 0x24) = q4 - q10;
    *(f32 *)(m + 0x28) = 1.0f - (q7 + q6);
    *(s32 *)(m + 0x30) = 0;
    *(s32 *)(m + 0x34) = 0;
    *(s32 *)(m + 0x38) = 0;
    *(s32 *)(m + 0x0C) = 3;
    func_003e0c90(m, &translation, 2);
    func_003e0e20(m, func_003e9700(camera), 2);
    renderStateBase = (u32)D_00887300;
    ((void (*)(s32, s32))*(u32 *)renderStateBase)(6, 0);
    ((void (*)(s32, s32))*(u32 *)renderStateBase)(8, 0);
    ((void (*)(s32, s32))*(u32 *)renderStateBase)(0x14, 2);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x20) {
        ((void (*)(s32, s32))*(u32 *)renderStateBase)(1, func_0036be00());
        func_00410420(backVertices, 4, m, 3);
        func_004106a0(4);
    }
    func_00378280(card, *(u8 *)(p + 0xD8));
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x80) {
        ShuffleVec3 axis = {0.0f, 0.0f, 1.0f};
        func_003e0870(m, &axis, 1, 180.0f);
    }
    ((void (*)(s32, s32))*(u32 *)renderStateBase)(1, texture);
    func_00410420(frontVertices, 4, m, 3);
    func_004106a0(4);
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x10) {
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);
        *(u16 *)(arg0 + 0x1F2F2) = (u16)((*(u16 *)(arg0 + 0x1F2F2) + 1) % 60);
        pulseFrame = (f32)(u32)*(u16 *)(arg0 + 0x1F2F2);
        pulseAlpha = 255.0f * (1.0f - func_0044b610((iGpffff81e0 * pulseFrame) / 60.0f)) / 2.0f;
        pulseByte = (u8)pulseAlpha;
        func_00378280(card, pulseByte & 0xFF);
        func_00410420(frontVertices, 4, m, 3);
        func_004106a0(4);
    }
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x100) {
        ShuffleVec3 scale;
        fadeFrame = (f32)(u32)++*(u16 *)(arg0 + 0x1F2F2);
        progress = func_00373cb0(fadeFrame, 0.0f, 1, 20.0f);
        if (*(u16 *)(arg0 + 0x1F2F2) >= 20) {
            *(u16 *)(arg0 + 0x1F2F4) &= 0xFEFF;
        }
        fadeAlpha = 255.0f * (1.0f - progress);
        fadeByte = (u8)fadeAlpha;
        func_00378280(card, fadeByte & 0xFF);
        scale.x = 1.0f + (f32)(iGpffff840c * progress);
        scale.y = scale.x;
        scale.z = 1.0f;
        func_003e0a90(m, &scale, 1);
        func_00410420(frontVertices, 4, m, 3);
        func_004106a0(4);
    }
    func_003e0f40(m);
}

/* measured (b210 -O2, 2026-09-17): table/index/float reconstruction (largest
   of four in TU). 0x120 frame via u8 *spA0[30] (0xA0..0x117) exact; 0xE8/0xFB0
   index scaling, 0x1D6B8/0x1D714/0x1D778 table spans, mode dispatch
   (4/3 zero, 2 div3, 1 div2, 0 compute) + u16->float two-sided + iGpffff8170
   verified. probe 183w (was 197w m2c-u32-mul); fnalign 99e+reloc (was 136e),
   object 256/256 instrs exact (0% size diff, within 3%; was 269/256 +5%).
   Levers top-down: u16 var_17 over u32 (-9w, exact frame), doubling via
   var_f0+=var_f0 over 2.0f*mul (-1w/-3 instrs), decl order via probe_search
   200 (183w/99e vs 188w/115e). Residual floors: saved-color rotation
   var_18 $s5 vs $s2 + siblings, arg-order lw-sp vs constants, loop CSE hoist
   differences. Production stays ASM. */
/* 183 -> 181 (2026-09-18): the hand-expanded unsigned-to-float conversion
   replaced by `(f32)(u32)var_17`.  b210 generates the same bltz / srl / andi
   / or / cvt.s.w / add.s sequence for the cast; the expanded copy colours
   its temporaries differently.  Companion to the float-to-unsigned lever in
   handoff 7a-quinquies - measured across the floors that carry it, this one
   and func_002566d0 (228 -> 249, rejected) are the only two that move. */
// FUN_003753F0 NONMATCHING
#ifdef NON_MATCHING
void func_003753f0(u8 *arg0) {
    u8 *temp_21;
    s32 var_19;
    u8 sp11C[4];
    s32 var_6;
    u8 *spA0[30];
    u8 *temp_16;
    f32 var_f20;
    u8 *temp_22;
    f32 var_f0;
    u8 sp118[4];
    s32 var_18;
    s32 temp_5;
    f32 var_f2;
    s32 var_16;
    u16 var_17;
    func_0034f1e0();
    sp11C[0] = 0xFF;
    sp11C[1] = 0xFF;
    sp11C[2] = 0xFF;
    if (*(u16 *)(arg0 + 0x1F2F4) & 1) {
        var_18 = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    } else {
        var_18 = *(s32 *)(arg0 + 0x1F304);
    }
    for (var_19 = 0; var_19 < var_18; var_19++) {
        if (*(u16 *)(arg0 + var_19 * 0xE8 + 0x1D6A0) & 2) {
            if ((*(u16 *)(arg0 + 0x1F2F4) & 2) == 0) {
                func_00374a10(arg0, var_19);
            }
            temp_21 = arg0 + var_19 * 0xE8;
            temp_22 = temp_21 + 0x1D6B8;
            temp_16 = arg0 + var_19 * 0xFB0;
            func_0036dda0(temp_16, temp_22);
            func_0036de20(temp_16, temp_21 + 0x1D714);
            sp11C[3] = *(temp_21 + 0x1D778);
            func_0036de40(temp_16, sp11C);
            if (var_19 != *(s32 *)(arg0 + 0x1F308)) {
                spA0[var_19] = temp_16;
                func_003766f0((f32 **)(arg0 + 0x1F24C), (s32)func_00374cf0, (s32)(spA0 + var_19), temp_22);
            }
        }
    }
    func_00376800((u8 **)(arg0 + 0x1F24C), 1);
    sp118[0] = 0x20;
    sp118[1] = 0x40;
    sp118[2] = 0xFF;
    sp118[3] = 0xFF;
    var_f2 = 1.0f;
    var_6 = *(s32 *)(arg0 + 0x1F304);
    temp_5 = *(s32 *)(arg0 + 0x1F2FC);
    if (temp_5 == 4 || temp_5 == 3) {
        var_f20 = 0.0f;
    } else {
        if (temp_5 == 2) {
            var_6 /= 3;
            var_17 = *(u16 *)(arg0 + 0x1F1D2);
            var_f2 = iGpffff8170;
        } else if (temp_5 == 1) {
            var_6 /= 2;
            var_17 = *(u16 *)(arg0 + 0x1F1D2);
        } else if (temp_5 == 0) {
            var_17 = *(u16 *)(arg0 + 0x1F1D2);
        }
        var_f0 = (f32)(u32)var_17;
        var_f20 = var_f2 * ((0.5f * var_f0) / (f32)var_6);
    }
    if (!(var_f20 <= 0.0f)) {
        for (var_16 = 0; var_16 < var_18; var_16++) {
            if (*(u16 *)(arg0 + var_16 * 0xE8 + 0x1D6A0) & 2) {
                func_003768e0(arg0, var_16, 2, sp118, var_f20 * func_00375a70(arg0, var_16));
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003753f0);
#endif


// FUN_003757F0
void func_003757f0(u8 *arg0) {
    func_0034f1e0();
    if (*(u16 *)(arg0 + 0x1F2F4) & 4) {
        func_0036df30(arg0 + *(s32 *)(arg0 + 0x1F308) * 0xFB0);
    }
    if (*(u16 *)(arg0 + 0x1F2F4) & 8) {
        func_00374d20(arg0);
    }
}


// FUN_00375890
void func_00375890(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg2) {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) |= 2;
    } else {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) &= 0xFFFD;
    }
}


// FUN_00375910
s32 func_00375910(u8 *arg0) {
    s32 b;

    b = func_00375970(arg0) != 0;
    if (b) {
        b = func_00375a00(arg0) != 0;
    }
    if (b) {
        b = func_00375a50(arg0) != 0;
    }
    return b;
}


// FUN_00375970
s32 func_00375970(u8 *arg0) {
    f32 var_f1;
    s32 temp_3;
    u32 temp_2;

    temp_3 = *(s32 *)(arg0 + 4);
    switch (temp_3) {
    case 0:
    case 5:
        return 1;
    default:
        temp_2 = *(u16 *)(arg0 + 0xC);
        if (temp_2 >= 0) {
            var_f1 = (f32)temp_2;
        } else {
            temp_2 = (temp_2 >> 1) | (temp_2 & 1);
            var_f1 = (f32)temp_2;
            var_f1 += var_f1;
        }
        return var_f1 >= *(f32 *)(arg0 + 0x10);
    }
}


// FUN_00375A00
s32 func_00375a00(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 8);
    switch (v) {
    case 0:
    case 3:
        return 1;
    default:
        return *(u16 *)(arg0 + 0x6C) >= *(u16 *)(arg0 + 0x6E);
    }
}


// FUN_00375A50
s32 func_00375a50(u8 *arg0) {
    return *(u16 *)(arg0 + 0xDC) >= *(u16 *)(arg0 + 0xDE);
}


/* The source call must place the two converted values in f12/f14 around the
   integer argument as func_00373cb0(var_f12, 0.0f, 0, var_f14); O2 CSEs the
   base-address materialization and swaps the resulting argument registers.
   measured: O1 plus that call order gives a byte-exact match, obj 204B of a
   208B window. */
#pragma optimization_level 1
// FUN_00375A70
f32 func_00375a70(u8 *arg0, s32 arg1) {
    f32 var_f12;
    f32 var_f14;
    s32 idx;

    idx = arg1 * 0xE8;
    var_f12 = (f32)(u32)*(u16 *)((u8 *)idx + (u32)arg0 + 0x1D70C);
    var_f14 = (f32)(u32)*(u16 *)((u8 *)idx + (u32)arg0 + 0x1D70E);
    return func_00373cb0(var_f12, 0.0f, 0, var_f14);
}
/* measured: O1 probe for f70 address materialization */
#pragma optimization_level 2


/* 520/528 bytes; ten resolved relocations; eight zero alignment bytes.
 * Load both parts of the twelve-byte axis before storing either part.
 * The typed quaternion dot product retains the retail ACC operand order. */
#pragma push
#pragma opt_propagation off
#pragma push
#pragma pack(4)
typedef struct { s64 xy; f32 z; } ShuffleAxis12;
typedef union { ShuffleAxis12 bits; ShuffleVec3 vector; } ShuffleAxis;
#pragma pop
typedef char ShuffleAxisSizeCheck[sizeof(ShuffleAxis) == 12 ? 1 : -1];
typedef char ShuffleQuatSizeCheck[sizeof(ShuffleQuaternion) == 16 ? 1 : -1];
extern s32 func_00378530(s32 count, s32 mode);
// FUN_00375B40
void func_00375b40(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    ShuffleAxis axis;
    s64 bits;
    f32 value;

    ShuffleQuaternion rotation;
    ShuffleVec4 output;
    s32 state;
    s64 active;
    u8 *p;
    ShuffleVec4 *current;

    bits = D_0064EA48[0];
    value = D_0064EA50[0];
    axis.bits.xy = bits;
    axis.bits.z = value;
    if (arg1 >= func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC))) {
        func_0046d730(D_0064EA20, 0x3E9);
    }
    p = arg0 + arg1 * 0xE8 + 0x1D6A0;
    state = *(s32 *)(p + 8);
    switch (state) {
    case 0:
    case 3:
        active = 1;
        break;
    default:
        if ((s64)*(u16 *)(p + 0x6C) >= (s64)*(u16 *)(p + 0x6E)) {
            active = 1;
        } else {
            active = 0;
        }
        break;
    }
    if (active) {
        func_003dc740(&rotation, &axis.vector, 180.0f, 0);
        current = (ShuffleVec4 *)(p + 0x74);
        output.w = current->w * rotation.real
            - ((current->x * rotation.imag.x + current->y * rotation.imag.y)
                + current->z * rotation.imag.z);
        output.x = current->y * rotation.imag.z - current->z * rotation.imag.y;
        output.y = current->z * rotation.imag.x - current->x * rotation.imag.z;
        output.z = current->x * rotation.imag.y - current->y * rotation.imag.x;
        output.x = (0.0f + output.x) + rotation.imag.x * current->w;
        output.y = (0.0f + output.y) + rotation.imag.y * current->w;
        output.z = (0.0f + output.z) + rotation.imag.z * current->w;
        output.x = (0.0f + output.x) + current->x * rotation.real;
        output.y = (0.0f + output.y) + current->y * rotation.real;
        output.z = (0.0f + output.z) + current->z * rotation.real;
        func_003760f0(arg0, arg1, arg2, arg3, 0, (f32 *)&output);
    }
}
#pragma pop

// FUN_00375D50
void func_00375d50(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 *arg2, f32 *arg3) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 1;
}


// FUN_00375DD0
void func_00375dd0(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 2;
}


// FUN_00375E50
void func_00375e50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371ba0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg4, arg2, arg3);
    *(s32 *)(p + 0x1D6A4) = 4;
}


// FUN_00375EC0
void func_00375ec0(u8 *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg1 * 0xE8) + (u32)arg0;
    *(u16 *)(p + 0x1D6A0) |= 1;
}


/* measured: typed O1 floor 156B/160B/2wd (fresh probe_archive D375 + fnalign 2: move $v1/$a0,$s2 vs addu $v1/$a0,$s1,$s0 at +0x48/+0x70). Retail CSEs base in $s2 with 3 saves ($16 idx,$17 arg0,$18 base); O1 recomputes, O2 folds to 1 saved. */
/* measured: ruled out this session -- O2 plain u8*base (36wd), O2 register base (36wd), O2 opt_common_subs off base (36wd), O2 differ struct-p vs arg0+idx (36wd), O2 register differ (36wd), O2 s64 idx (32wd); archive 16 combos (same-order 36wd/1-saved, differ 20wd/3-saved recompute) plus u8*base 36wd and p-reuse 24/36wd per owner note; O1-bracket re-probe on the typed body: loop-inv 2, propag-off 2, cse-off 2, sched-on 33 (baseline 2). No volatile/asm; honest 2wd floor kept. */
/* measured: pair sweep 2026-09-17 `python3 -E -s tools/pragma_sweep.py src/Battle/btlShuffleDraw.c func_00375f00 --pairs` banked 2; all 8 singles and all 28 pairs 2 (neutral, no win). Two-def pins on this body per assignment all flat: p-reuse 36, p two-def 36, C90 idx pin 2 tie, split-decl pin 2 tie, C90 base pin 36. fnalign retail/object 39/39 (move $v1/$a0,$s2 vs addu $v1/$a0,$s1,$s0 at retail[18:19]+[28:29]). Honest 2wd floor stands. */
/* 2026-09-18 micro-experiment (tools/micro_codegen.py, optimization_level 1):
   the two words are a copy-versus-rematerialise choice that no spelling tried
   reaches.  Retail keeps `arg0 + idx` in $s2 and copies it into the store's
   base (`daddu $v1, $s2, zero`), which is one instruction more than the
   minimal form; b210 either recomputes `addu $v1, $s1, $s0` (this body, 2
   words) or drops the separate base entirely and addresses off $s0 (every
   spelling that names the pointer: 36 words).  Level 1 has no CSE, so the
   recompute is expected; what retail does implies a source-level temporary
   that stays distinct from the pointer.  Measured and rejected in the micro:
   `q = p` before each store, a single `q = p` hoisted, storing through `p`
   directly, an s32 intermediate, and s64/u64 intermediates (those add
   dsll32/dsrl32 pairs).  optimization_level 0/2/3/4 are 40/36/36/36. */
/* 2026-09-18 lead pass, 14 measured variants, floor confirmed at 2 words.
   The only two differing instructions are offsets 18 and 28: retail has
   `move $v1, $s2` / `move $a0, $s2`, reusing the base pointer it computed at
   offset 11 (`addu $s2, $s1, $s0`), where this body recomputes
   `addu $v1, $s1, $s0`.  Everything else, including the 0x40 frame and the
   s0/s1/s2 assignment, is identical.
   The reuse and the frame are mutually exclusive here.  Writing `p->` at the
   two store sites does produce the copy, but it also makes `arg0` and `idx`
   dead, so the frame collapses to 0x20 and the score goes to 36; so does a
   `q = p` pointer copy, a `u8 *` copy, and separate `q1`/`q2` copies.  Turning
   CSE on has the same effect from the other direction: `opt_common_subs on`,
   `opt_common_subs on` + `opt_propagation off`, optimization_level 2 and 3,
   and level 2 + `opt_dead_assignments off` are all 36.  `opt_propagation on`
   and `opt_dead_assignments off` at level 1 tie at 2.
   Retail therefore keeps `arg0` and `idx` live across both calls *and* reuses
   the sum, which b210 will not do from any source shape tried.  Do not spend
   another session reordering this body; the open question is what third use
   of `arg0`/`idx` retail's source had. */
/* 2026-09-18: re-probed against handoff 7o, floor stands at 2.  The two
   residual words are retail keeping `arg0 + idx` in the callee-saved $s2 and
   spelling both uses `move`, where this body keeps `arg0` and `idx` in $s1
   and $s0 and re-adds them.  Every way of naming the sum once is far worse,
   because it also removes the separate `idx` live range: `p` used for the two
   stores as well 36, a second pointer `q` for the stores 36, a `u8 *base` for
   the stores 36, one pointer and no `idx` at all 36, `arg0 +=` in place 36,
   `register` on the pointer 36.  The mirror - calls through the recomputed
   expression, stores through `p` - is 18.  Converting the two declarations to
   uninitialised form with statement assignments (the 7o lever) ties at 2. */
// FUN_00375F00 NONMATCHING
#ifdef NON_MATCHING
#pragma optimization_level 1
typedef struct ShuffleMotion { u8 data[0x60]; } ShuffleMotion;
typedef struct ShuffleRotation { u8 data[0x6c]; } ShuffleRotation;
typedef struct ShuffleRecord {
    u16 flags; u16 unknown02;
    s32 motionState; s32 rotationState;
    ShuffleMotion motion;
    ShuffleRotation rotation;
    u8 trackD8[8]; u8 trackE0[8];
} ShuffleRecord;
typedef struct ShuffleContext { u8 preceding[0x1d6a0]; ShuffleRecord records[]; } ShuffleContext;
void func_00375f00(u8 *arg0, s32 arg1) {
    s32 idx = arg1 * sizeof(ShuffleRecord);
    ShuffleContext *p = (ShuffleContext *)(arg0 + idx);
    func_00370410((u8 *)&p->records[0].motion);
    ((ShuffleContext *)(arg0 + idx))->records[0].motionState = 5;
    func_00370a80((u8 *)&p->records[0].rotation);
    ((ShuffleContext *)(arg0 + idx))->records[0].rotationState = 3;
}
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375f00);
#endif

// FUN_00375FA0
void func_00375fa0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
    ShuffleVec3 v3;
    ShuffleVec3 v4;
    ShuffleVec3 v5;
    s32 idx;

    v3 = *(ShuffleVec3 *)arg3;
    v4 = *(ShuffleVec3 *)arg4;
    v5 = *(ShuffleVec3 *)arg5;
    idx = arg1 * 0xE8;
    func_00371e50((u8 *)(arg0 + idx + 0x1D6AC), arg2, (f32 *)&v3, (f32 *)&v4, (f32 *)&v5);
    *(s32 *)((u8 *)idx + (u32)arg0 + 0x1D6A4) = 6;
}


// FUN_00376070
void func_00376070(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_003723a0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A4) = 8;
}


// FUN_003760F0
void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372870((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A8) = 1;
}


// FUN_00376170
void func_00376170(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372c30((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5, (u8 *)arg6);
    *(s32 *)(p + 0x1D6A8) = 2;
}


// FUN_003761F0
void func_003761f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    ShuffleVec3 v;
    s32 idx;
    u8 *p;

    v = *(ShuffleVec3 *)arg4;
    idx = arg1 * 0xE8;
    p = (u8 *)idx + (u32)arg0;
    func_003730f0((u8 *)(arg0 + idx + 0x1D70C), arg2, arg3, &v);
    *(s32 *)(p + 0x1D6A8) = 4;
}


// FUN_00376290
void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_003733d0((u8 *)(arg0 + idx + 0x1D778), arg2, arg3, arg4);
}


// FUN_003762E0
void func_003762e0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_00373590((u8 *)(arg0 + idx + 0x1D780), arg2, arg3, arg4);
}


// FUN_00376330
void func_00376330(u8 *arg0, s32 arg1, f32 *arg2) {
    u8 *p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);
    switch (*(u32 *)(p + 4)) {
    case 0:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x18);
        return;
    case 1:
    case 2:
    case 3:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    case 5:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x54);
        return;
    case 4:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x48);
        return;
    case 6:
        func_00371160(p + 0x38, p + 0x2C, p + 0x44, arg2, p, *(f32 *)(p + 0x28));
        return;
    case 7:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    case 8:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
    case 9:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    default:
        func_0046d730(D_0064EA20, 0x4DA);
        return;
    }
}


/* measured: retail emits the two saved-register setup moves (mov.s $f20,$f12 then
   move $s1,$a2) with the FP move first; mwcc b210 emits the GPR move first (nd 4).
   Everything else is solved: u8 *arg0, idx/p locals, the full 0-9 case switch, and
   func_00371f40's interleaved prototype (u8*, f32, u8*) which fixes the pre-jal
   materialisation order. Saved-register setup-order scheduling floor. */
// FUN_003764B0
/* Case values decoded from jtbl_007529D0 with tools/jtbl.py: only entry 6 has
   a body, entries 0-5 and 7-9 fall straight to the epilogue, and >= 10 hits
   the assert. The empty cases must still be listed or b210 emits a compare
   chain instead of the 10-entry table, and `default` is declared before them
   because b210 lays case bodies out in declaration order.
   The parameter list is interleaved (u8*, s32, f32, u8*), not grouped: the
   float arrives in $f12 between the second and third integer argument, and
   the grouped spelling costs nd 8. */
void func_003764b0(u8 *arg0, s32 arg1, f32 fparg0, u8 *arg2) {
    u8 *p;

    p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);
    if (arg2 == NULL) {
        func_0046d730(D_0064EA20, 0x4E5);
    }
    switch ((u32)*(s32 *)(p + 4)) {
    case 6:
        func_00371f40(p + 0xC, fparg0, arg2);
        break;
    default:
        func_0046d730(D_0064EA20, 0x508);
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
        break;
    }
}

// FUN_00376590
s32 func_00376590(u8 *arg0, u8 *arg1) {
    ShuffleVec3 sp80;
    ShuffleVec3 sp70;
    s32 i;
    s32 count;
    s32 best;
    f32 bestf;
    f32 f;

    count = *(s32 *)(arg0 + 0x1F2FC);
    if ((count < 0) || (count > 2)) {
        func_0046d730(D_0064EA20, 0x516);
    }
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    func_00376330(arg0, 0, (f32 *)&sp70);
    bestf = func_00373c20((u8 *)&sp70);
    i = 1;
    best = 0;
    while (i < count) {
        func_00376330(arg0, i, (f32 *)&sp80);
        f = func_00373c20((u8 *)&sp80);
        if (f < bestf) {
            bestf = f;
            best = i;
            sp70 = sp80;
        }
        i++;
    }
    if (arg1 != NULL) {
        *(ShuffleVec3 *)arg1 = sp70;
    }
    return best;
}


// FUN_003766F0
void func_003766f0(f32 **arg0, s32 arg1, s32 arg2, u8 *arg3) {
    f32 **var_19;
    f32 *temp_2;
    f32 *temp_3;
    f32 key;

    func_0044ea90(D_0064EA20, 0x589);
    temp_2 = (f32 *)D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_0064EA20, 0x58A);
    }
    key = func_00373c20(arg3);
    *(s32 *)(temp_2 + 1) = arg1;
    *(s32 *)(temp_2 + 2) = arg2;
    temp_2[0] = key;
    var_19 = arg0;
    while ((temp_3 = *var_19) != NULL) {
        if (!(temp_2[0] <= temp_3[0])) break;
        var_19 = (f32 **)(temp_3 + 3);
    }
    if (temp_3 == NULL) {
        *var_19 = temp_2;
        *(f32 **)(temp_2 + 3) = NULL;
        return;
    }
    *(f32 **)(temp_2 + 3) = temp_3;
    *var_19 = temp_2;
}


void func_00376880(u8 **arg0);

// FUN_00376800
void func_00376800(u8 **arg0, s32 arg1) {
    u8 *var_16;

    var_16 = *arg0;
    while (var_16 != NULL) {
        (*(void (**)(s32))(var_16 + 4))(*(s32 *)(var_16 + 8));
        var_16 = *(u8 **)(var_16 + 0xC);
    }
    if (arg1 != 0) {
        func_00376880(arg0);
    }
}


/* Retail re-loads *arg0 at every use. The fix is simply NOT to cache it: a `cur`
   local lets b210 CSE the load with the loop test and the body comes out two
   instructions short (nd 44), and a for(;;)-with-break shape scores nd 33.
   Dereferencing *arg0 at each use is byte-exact - measured. */
// FUN_00376880
void func_00376880(u8 **arg0) {
    u8 *next;

    while (*arg0 != NULL) {
        next = *(u8 **)(*arg0 + 0xC);
        jtbl_008873EC[0](*arg0);
        *arg0 = next;
    }
}


/* measured 003768e0: archived LaneBtlShuffleDraw_fclCombineMisc_003768e0_body.c */
/* (725 lines, raw m2c with M2C_FIELD/M2C_BITWISE, goto loops, s64 arg2) does */
/* not compile as-is: s64 vs existing s32 prototype, missing M2C defines, */
/* missing D_0060A0E0/E4/E8 and iGpffff8400/8404/8408/8308, D_00887300 */
/* render_table indirection vs existing array-of-fn-ptr, (s32) casts needed */
/* for the six func_00410420 pointer args. Fixed candidate */
/* /var/tmp/bank3768e0/candidate.c (s32 arg2 with */
/* (s64)((s64)arg2<<0x38)>>0x38, M2C defines, 7 missing f32 externs, */
/* D_00887300[0] direct, 6x(s32)&stack casts) compiles. fnalign retail 1042 */
/* vs object 997 (45 short, 4.3%, outside +-3% gate 1011-1073), edit 813 */
/* (+2 reloc-only) via `python3 -E -s tools/fnalign.py */
/* src/Battle/btlShuffleDraw.c func_003768e0 --candidate */
/* /var/tmp/bank3768e0/candidate.c`. jal counts exact both sides (28: */
/* 3x0036de70, 3x0036deb0, 3x003764b0, 1x003e9700, 4x003f6440, 6x00410420, */
/* 6x004106a0, 1x00457120, 1x0046d730 + 3xjalr D_00887300), switch/loop */
/* bounds intact (0x15 and 4-iteration loops present), so excluded: dropped */
/* else arm, off-by-one bound, omitted call, folded switch, collapsed */
/* per-lane vector. Gap is distributed FP/stack-spill shape (early */
/* dsll/dsra 2->4 expansion vs 7->2 div collapse, large replaces in the */
/* 0x15-loop tails and final 52-word replace), not a single deleted block. */
/* Archive header claims no score (only "rejected after scoped mismatch"), */
/* so no disagreement. Production stays ASM. */
/* 2026-09-18, two passes.  Refused, still ASM.  Read the numbers carefully -
   the first pass's note conflated two different gaps and named a mechanism
   that a census then disproved, so this replaces it.
   Retail: 1042 trimmed instructions (1044 in the 4176B window), frame -0xF50,
   28 `jal` plus 3 `jalr` through D_00887300[0] = 31 calls.  The best faithful
   candidate is 45 instructions short (997), which is -4.3% and outside the
   gate; an earlier fuller attempt was 158 short.  The often-quoted "432B" is
   the FRAME difference (3920 against 3488), not the code gap - keep the two
   apart.
   Structure is complete and that is measured, not assumed: 13 case labels
   covering the outer 2/1/0 plus default and every inner arm, all 31 calls on
   both sides, and no large `delete` run - the biggest are four of length 19,
   nothing like the 200-instruction hole that turned out to be a missing
   `case 7` in func_00263cb0.  So pragmas are not the story here.
   The mechanism is per-lane reloads, NOT missing spills.  A census says
   `swc1` is 150 on both sides - exactly equal - so no spill pair is missing,
   because a missing pair would move stores too.  The deficit is `lwc1` -24,
   `nop` -17 and `mfc1` -6, which is 41 of the 45.  Those 24 loads localise to
   four retail-only blocks of length 19 at candidate indices 343, 401, 459 and
   517 (retail 0x376E3C, 0x376F24, 0x37700C, 0x3770F4) - four lanes with about
   six missing loads each - plus one secondary block of length 12.  The
   candidate stores each lane value once and then carries it in a register
   where retail reloads it per lane.
   Next pass: print those four spans against the aligned object code and add
   the per-lane reloads as array reads, two variants, before anything else.
   Then audit the six `mfc1` sites.  Only after the reloads land should the
   `cvt`/`dsll32` width noise be cleaned up, because it currently offsets the
   shortfall.  The earlier "raise live-float pressure" theory is unmeasured
   and the census argues against it.
   Working notes: /var/tmp/cold3768e0b/NOTE.md and the census script at
   /var/tmp/cold263cb0b/census768e0.py. */
// FUN_003768E0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003768e0);


/* measured: the old "FPU FMA-fusion floor" note is REFUTED -- b210 emits the exact
   retail accumulator chain (mula/madda/madda/madd + 2.0f/div + the 9 rotation
   products) from the plain spelling 2.0f / (y*y + x*x + z*z + w*w), verified
   against a bare compile. Reconstructed the whole function to nd 15 (obj 1236B):
   prologue, all stack slots (sp1B8v ShuffleVec3, sp1C8[2], spB0[0x40] at 0xB0,
   sp80[12], sp70v ShuffleVec4 at 0x70), the f20-f23 saved-FP mapping
   (declaration order alphaBase/halfW/halfH/scale), the alpha lbu/bltz/mtc1/cvt/
   srl/andi/or/add.s recipe-A blocks and the D_00887300/D_00887310 tail all match
   byte-for-byte. Remaining 3 residuals: (1) the two arg1*0xE8 chains emit
   addu $v0,$s4,$v0 where retail has addu $v0,$v0,$s4 -- inline operand flips
   (arg1*0xE8+arg0) did not change it, lever-10 named s32 local untested;
   (2) the dot sum canonicalises to mula(x),madda(y) where retail has
   mula(y),madda(x) -- survived direct-struct-field and 4-temp spellings;
   (3) alpha else-arm or/mtc1 result register $v0 vs retail $v1 (scheduling
   residual, 8 words). 4 attempts: nd 108->15->51. */
/* Shuffle-render floor (1248B window). First probe nd 378
   (obj 1616B, 368B overrun); frame verified, int homes exact,
   mula/madda/madd fusion emitted from plain spelling. Model:
   5 int-saves, 4 FP-saves + scalar-replacement gap (quad kept
   in regs vs retail stacked). Open: FP homes, addu flips,
   mula order, alpha-reg, scheduler cascade. Variants tied:
   folding, block-scope, counter-reuse all neutral. Ghidra
   phantoms killed (per-iter div, +C0 store, denormal).
   Quad-built, retail-arbitrated; prior nd-15 note on file. */
/* measured 00377930: `schedule on` inside the guard is worth 38 words (378 -> 340). */
/* measured 00377930: `opt_propagation off` inside the guard is worth 2 words (340 -> 338). */
// FUN_00377930 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma schedule on
void func_00377930(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4)
{
    extern f32 D_008872F8_abs[];
    f32 datw;
    f32 halfW;
    f32 halfH;
    f32 scale;
    f32 norm;
    f32 n0;
    f32 n1;
    f32 n2;
    f32 sp1B8v[3];
    f32 sp1C8[2];
    f32 sp80[12];
    f32 sp70v[4];
    f32 mat[4][16];
    u8 *chain;
    u8 *cbase;
    void *matrix;
    f32 *slot;

    datw = D_008872F8_abs[0];
    scale = 1.0f / *(f32 *)((u8 *)func_00457120() + 0x80);
    if (arg2 != 0) {
        sp1B8v[0] = *(f32 *)arg2;
        sp1B8v[1] = *(f32 *)(arg2 + 4);
        sp1B8v[2] = *(f32 *)(arg2 + 8);
    } else {
        chain = arg1 * 0xE8 + arg0;
        cbase = chain + 0x1D6B8;
        sp1B8v[0] = *(f32 *)(chain + 0x1D6B8);
        sp1B8v[1] = *(f32 *)(cbase + 4);
        sp1B8v[2] = *(f32 *)(cbase + 8);
    }
    chain = arg1 * 0xE8 + arg0;
    sp70v[0] = *(f32 *)(chain + 0x1D714);
    sp70v[1] = *(f32 *)(chain + 0x1D718);
    sp70v[2] = *(f32 *)(chain + 0x1D71C);
    sp70v[3] = *(f32 *)(chain + 0x1D720);
    arg2 = (s32)(arg0 + arg1 * 0xFB0);
    halfW = func_0036de70((u8 *)arg2) / 2.0f;
    halfH = func_0036deb0((u8 *)arg2) / 2.0f;
    matrix = func_003e0f80();
    func_00457120();
    norm = 2.0f / (sp70v[3] * sp70v[3] + sp70v[2] * sp70v[2] + sp70v[0] * sp70v[0] + sp70v[1] * sp70v[1]);
    n0 = sp70v[0] * norm;
    n1 = sp70v[1] * norm;
    n2 = sp70v[2] * norm;
    ((f32 *)matrix)[0] = 1.0f - (sp70v[1] * n1 + sp70v[2] * n2);
    ((f32 *)matrix)[1] = sp70v[0] * n1 + n2 * sp70v[3];
    ((f32 *)matrix)[2] = sp70v[2] * n0 - n1 * sp70v[3];
    ((f32 *)matrix)[4] = sp70v[0] * n1 - n2 * sp70v[3];
    ((f32 *)matrix)[5] = 1.0f - (sp70v[2] * n2 + sp70v[0] * n0);
    ((f32 *)matrix)[6] = sp70v[1] * n2 + n0 * sp70v[3];
    ((f32 *)matrix)[8] = sp70v[2] * n0 + n1 * sp70v[3];
    ((f32 *)matrix)[9] = sp70v[1] * n2 - n0 * sp70v[3];
    ((f32 *)matrix)[10] = 1.0f - (sp70v[0] * n0 + sp70v[1] * n1);
    ((s32 *)matrix)[12] = 0;
    ((s32 *)matrix)[13] = 0;
    ((s32 *)matrix)[14] = 0;
    ((s32 *)matrix)[3] = 3;
    func_003e0c90(matrix, sp1B8v, 2);
    sp80[0] = halfW;
    sp80[1] = halfH;
    sp80[2] = 0.0f;
    sp80[3] = -halfW;
    ((s32 *)sp80)[4] = 0;
    sp80[5] = -halfH;
    ((s32 *)sp80)[6] = 0;
    ((s32 *)sp80)[7] = 0;
    sp80[8] = halfH;
    sp80[9] = halfW;
    sp80[10] = -halfW;
    sp80[11] = -halfH;
    for (arg2 = 0; arg2 < 4; arg2 = arg2 + 1) {
        u32 t;
        f32 f;
        func_003e42a0(sp1B8v, &sp80[arg2 * 3], matrix);
        func_003717e0(sp1B8v, sp1C8);
        slot = mat[arg2];
        slot[0] = sp1C8[0];
        slot[1] = sp1C8[1];
        slot[2] = datw;
        slot[6] = scale;
        t = arg3[0];
        if ((s32)t < 0) {
            f = (f32)((t >> 1) | (t & 1));
            f += f;
        } else {
            f = (f32)t;
        }
        slot[8] = f;
        t = arg3[1];
        if ((s32)t < 0) {
            f = (f32)((t >> 1) | (t & 1));
            f += f;
        } else {
            f = (f32)t;
        }
        slot[9] = f;
        t = arg3[2];
        if ((s32)t < 0) {
            f = (f32)((t >> 1) | (t & 1));
            f += f;
        } else {
            f = (f32)t;
        }
        slot[10] = f;
        t = arg3[3];
        if ((s32)t < 0) {
            f = (f32)((t >> 1) | (t & 1));
            f += f;
        } else {
            f = (f32)t;
        }
        slot[11] = f;
    }
    D_00887300[0](1, 0);
    if (arg4 != 0 && arg3[3] == 0xFF) {
        func_00364c50();
    }
    D_00887310[0](4, mat, 4);
    if (arg4 != 0 && arg3[3] == 0xFF) {
        func_00364c70();
    }
    func_003e0f40(matrix);
}
#pragma schedule off
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377930);
#endif
// FUN_00377E10
s32 func_00377e10(u8 *arg0) {
    s32 *p = *(s32 **)(arg0 + 0x38);

    if (func_00378220() == 0) {
        *p = func_00354830((u8 *)p + 8);
    }
    return 0;
}


// FUN_00377E60
void func_00377e60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_003549d0(p + 8);
    jtbl_008873EC[0](p);
}


/* measured: retail allocates the copy loops as dst=$a0, i=$a1, p=$v0, 0xFF=$v1
   (0xFF hoisted to the preheader); mwcc b210 rotates i to $v0/$a0 and p to $v1,
   materialising 0xFF inside the loop — every instruction is otherwise identical
   (nd 64, obj 800B = window). Everything else in this function is solved: the
   stack layout spA0[3]@0xA0 / sp90[3]@0x90 / sp60[4][3]@0x60 / sp50[4]@0x50 /
   sp40[4]@0x40, the element-wise spill copies via a block-scoped f32* q, the
   +30/-30 shared materialisation (temp_f1 = 30.0f, stores via -temp_f1), the gp
   value in temp_f0/temp_f0_2, the two 4-iteration copy loops to mem[i*0x24+0x120]
   and +0x1B0, and func_00451fc0's 8-arg call. Temp-register rotation floor.
   Re-measured 2026-09-15 at nd 120 (s-reg work/p/arg1 rotation plus the loop
   rotation; decl and assignment swaps inert); banked as guarded floor. */
/* measured 00377eb0: `opt_loop_invariants on` inside the guard is worth 2 words (119 -> 117), the loop-preheader constant hoist. */
/* 117 -> 112 (2026-09-18), and the object goes from three instructions short
   of retail to exact (199/199).  The first loop's three-float copy out of
   stack.spA0 is a struct assignment, not three element stores: written as
   elements b210 forwards the three stores it just made into spA0 and never
   reloads, where retail reloads all three from the stack before storing.
   Same lever as func_0025dd30 in src/shdWindow.c.  Measured and rejected:
   applying it to the second loop's sp90 copy as well (115). */
// FUN_00377EB0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
s32 func_00377eb0(u8 *arg0, s32 arg1)
{
    struct ShuffleDrawVec3 { f32 x, y, z; };
    struct ShuffleDrawStack {
        s32 sp40[4];
        s32 sp50[4];
        f32 sp60[4][3];
        f32 sp90[3];
        s32 gap;
        f32 spA0[3];
    } stack;
    s32 saved_arg1;
    u8 *p;
    u8 *saved_arg0;
    u8 *q;
    s32 i;
    f32 temp_f0;
    f32 temp_f1;

    saved_arg0 = arg0;
    saved_arg1 = arg1;
    func_0044ea90(D_0064EA20, 0x76C);
    p = D_008873F4[0](1, 0x240, 0x40000);
    if (p == NULL) {
        func_0046d730(D_0064EA20, 0x76D);
    }
    p = (u8 *)func_00451fc0(saved_arg0, D_0064EA60, 0x12, 0, 0,
                             (void *)func_00377e10, (void *)func_00377e60, p);
    if (p == NULL) {
        func_0046d730(D_0064EA20, 0x777);
    }
    func_003781d0(p, saved_arg1);
    func_00378260(p, 0xFF, 0xFF, 0xFF, 0);

    temp_f1 = 30.0f;
    stack.sp60[0][0] = -temp_f1;
    temp_f0 = iGpffff81e0;
    stack.sp60[0][1] = temp_f0;
    stack.sp60[0][2] = 0.0f;
    stack.sp50[0] = 0x3F7E0000;
    stack.sp40[0] = 0;
    stack.sp60[1][0] = temp_f1;
    stack.sp60[1][1] = temp_f0;
    stack.sp60[1][2] = 0.0f;
    stack.sp50[1] = 0;
    stack.sp40[1] = 0;
    stack.sp60[2][0] = -temp_f1;
    temp_f0 = -temp_f0;
    stack.sp60[2][1] = temp_f0;
    stack.sp60[2][2] = 0.0f;
    stack.sp50[2] = 0x3F7E0000;
    stack.sp40[2] = 0x3F250000;
    stack.sp60[3][0] = temp_f1;
    stack.sp60[3][1] = temp_f0;
    stack.sp60[3][2] = 0.0f;
    stack.sp50[3] = 0;
    stack.sp40[3] = 0x3F250000;

    for (i = 0; i < 4; i++) {
        q = (u8 *)&stack.sp60[i][0];
        sp: ;
        stack.spA0[0] = *(f32 *)(q + 0);
        stack.spA0[1] = *(f32 *)(q + 4);
        stack.spA0[2] = *(f32 *)(q + 8);
        q = p + i * 0x24;
        *(struct ShuffleDrawVec3 *)(q + 0x120) = *(struct ShuffleDrawVec3 *)stack.spA0;
        q[0x12C] = 0xFF;
        q[0x12D] = 0xFF;
        q[0x12E] = 0xFF;
        q[0x12F] = 0xFF;
        *(f32 *)(q + 0x13C) = *(f32 *)&stack.sp50[i];
        *(f32 *)(q + 0x140) = *(f32 *)&stack.sp40[i];
    }

    temp_f1 = 30.0f;
    stack.sp60[0][0] = temp_f1;
    temp_f0 = iGpffff81e0;
    stack.sp60[0][1] = temp_f0;
    stack.sp60[0][2] = 0.0f;
    stack.sp50[0] = 0x3F7E0000;
    stack.sp40[0] = 0;
    stack.sp60[1][0] = -temp_f1;
    stack.sp60[1][1] = temp_f0;
    stack.sp60[1][2] = 0.0f;
    stack.sp50[1] = 0;
    stack.sp40[1] = 0;
    stack.sp60[2][0] = temp_f1;
    temp_f0 = -temp_f0;
    stack.sp60[2][1] = temp_f0;
    stack.sp60[2][2] = 0.0f;
    stack.sp50[2] = 0x3F7E0000;
    stack.sp40[2] = 0x3F250000;
    stack.sp60[3][0] = -temp_f1;
    stack.sp60[3][1] = temp_f0;
    stack.sp60[3][2] = 0.0f;
    stack.sp50[3] = 0;
    stack.sp40[3] = 0x3F250000;

    for (i = 0; i < 4; i++) {
        q = (u8 *)&stack.sp60[i][0];
        stack.sp90[0] = *(f32 *)(q + 0);
        stack.sp90[1] = *(f32 *)(q + 4);
        stack.sp90[2] = *(f32 *)(q + 8);
        q = p + i * 0x24;
        *(f32 *)(q + 0x1B0) = stack.sp90[0];
        *(f32 *)(q + 0x1B4) = stack.sp90[1];
        *(f32 *)(q + 0x1B8) = stack.sp90[2];
        q[0x1BC] = 0xFF;
        q[0x1BD] = 0xFF;
        q[0x1BE] = 0xFF;
        q[0x1BF] = 0xFF;
        *(f32 *)(q + 0x1CC) = *(f32 *)&stack.sp50[i];
        *(f32 *)(q + 0x1D0) = *(f32 *)&stack.sp40[i];
    }
    return (s32)p;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377eb0);
#endif
// FUN_003781D0
void func_003781d0(u8 *arg0, s32 arg1) {
    char buf[0x100];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_00442088(buf, D_0064EA80, arg1 & 0xFF);
    func_003547c0((s32 *)(temp_16 + 8), (u8 *)buf);
    *(s32 *)temp_16 = 0;
}


// FUN_00378220
s32 func_00378220(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38)) != 0;
}


// FUN_00378240
s32 func_00378240(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x120;
}


// FUN_00378250
s32 func_00378250(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x1B0;
}


// FUN_00378260
void func_00378260(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    temp[0x11C] = arg1;
    temp[0x11D] = arg2;
    temp[0x11E] = arg3;
    *(s32 *)(temp + 4) = arg4;
}


/* measured: u32->f32 and f32->u8 written as plain (f32)/(u8) casts;
   opt_loop_invariants on hoists the FMA constants and 0x4f00/0xff. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00378280
void func_00378280(u8 *arg0, u8 arg1) {
    u8 *temp_4;
    u8 *temp_11;
    u8 *temp_10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 global_a;
    f32 global_b;
    s32 var_5;
    s32 temp_8;
    u32 temp_6;
    u32 temp_6_2;
    u32 temp_6_3;

    temp_4 = *(u8 **)(arg0 + 0x38);
    temp_4[0x11F] = arg1;
    if (*(s32 *)(temp_4 + 4) != 0) {
        global_a = DAT_007613f8;
        global_b = iGpffff8218;
    } else {
        global_a = 0.0f;
        global_b = 0.0f;
    }
    for (var_5 = 0; var_5 < 4; var_5++) {
        temp_8 = 3 - var_5;
        temp_f4 = (1.0f + 0.0f) - global_a * (f32)(temp_8 % 2) -
            global_b * (f32)(temp_8 / 2);

        temp_11 = temp_4 + var_5 * 0x24;
        temp_10 = temp_11 + 0x12C;

        temp_6 = temp_4[0x11C];
        var_f0 = (f32)temp_6;
        temp_f0 = var_f0 * temp_f4;
        temp_10[0] = (u8)temp_f0;

        temp_6_2 = temp_4[0x11D];
        var_f0_2 = (f32)temp_6_2;
        temp_f0_2 = var_f0_2 * temp_f4;
        temp_10[1] = (u8)temp_f0_2;

        temp_6_3 = temp_4[0x11E];
        var_f0_3 = (f32)temp_6_3;
        temp_f0_3 = var_f0_3 * temp_f4;
        temp_10[2] = (u8)temp_f0_3;

        temp_10[3] = temp_4[0x11F];
        temp_11[0x1BC] = 0xFF;
        temp_11[0x1BD] = 0xFF;
        temp_11[0x1BE] = 0xFF;
        temp_11[0x1BF] = temp_4[0x11F];
    }
}
#pragma pop

// FUN_00378500
s32 func_00378500(u8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    if ((u8)(*(u32 *)temp != 0) != 0) {
        return *(u32 *)(*(u8 **)(temp + 0x14));
    }
    return 0;
}


// FUN_00378530
s32 func_00378530(s32 arg0, s32 arg1) {
    s32 var_2;

    switch (arg1) {
    case 0:
        return arg0;
    case 1:
        return arg0;
    case 2:
        return arg0;
    case 3:
        return arg0 * 2;
    case 4:
        if (arg0 < 6) {
            var_2 = arg0 * 6;
        } else {
            var_2 = arg0 * 3;
        }
        return var_2;
    default:
        func_0046d730(&D_0064EA20, 0x854);
        return 0;
    }
}
