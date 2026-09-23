/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_shuffle_draw_internal.h"
#include "sdk_snd_internal.h"
extern s32 func_00378220(u8 *task);
extern void func_003549d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 func_00354830();

extern void func_0036df30(u8 *arg0);
extern void func_0036d8b0(void);
extern s32 func_00457120(void);
struct RwCamera;
extern void K_View_SetFov(struct RwCamera *camera, f32 fov);
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

typedef BtlShuffleVec3 ShuffleVec3;
typedef struct { f32 x, y, z, w; } ShuffleVec4;
typedef struct RtQuat { ShuffleVec3 imag; f32 real; } ShuffleQuaternion;
typedef struct { s64 a; f32 b; } ShuffleVec2s;

extern s32 sprintf(char *buf, const char *fmt, ...);
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
extern s32 datGetFlag(s32 arg0);
extern void func_0036c900(void);
extern void func_0036d990(u8 *arg0, u8 *arg1);
extern void func_0036dda0(u8 *arg0, void *arg1);
extern void func_0036de20(u8 *arg0, void *arg1);
extern void func_0036de40(u8 *arg0, void *arg1);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00373750(s32 arg0, s32 arg1, void *arg2);

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
struct HCdvd;
extern u32 H_Cdvd_IsFileLoaded(struct HCdvd *archive);
extern u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);
extern void memcpy(s32 arg0, s32 arg1, s32 arg2);
extern void func_0036d230(u8 *data);
extern u32 func_0046a750(s16 *sprite);
extern u32 H_Cdvd_Destroy(struct HCdvd *archive);
extern void func_003768e0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, f32 fparg0);
extern f32 func_00375a70(u8 *arg0, s32 arg1);
extern f32 iGpffff8170;
extern void func_003766f0(f32 **arg0, void (*arg1)(u8 **), u8 **arg2, u8 *arg3);
extern void func_00376800(u8 **arg0, s32 arg1);
extern void func_00374910(u8 *arg0);
extern void func_00375d50(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 *arg2, f32 *arg3);
extern void func_00375dd0(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1);
extern void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5);
extern void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 func_0036de70(u8 *arg0);
extern f32 func_0036deb0(u8 *arg0);
extern BtlShuffleMatrix *func_003e0f80(void);
extern BtlShuffleMatrix *RwMatrixTranslate(BtlShuffleMatrix *matrix, const BtlShuffleVec3 *translation, BtlShuffleCombine mode);
extern BtlShuffleVec3 *func_003e42a0(BtlShuffleVec3 *out, const BtlShuffleVec3 *in, const BtlShuffleMatrix *matrix);
extern s32 func_003717e0(u8 *point, u8 *screen);
extern s32 func_003e0f40(BtlShuffleMatrix *matrix);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern f32 D_008872F8[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310[];
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
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern s32 func_0036be00(void);
extern void func_00410420(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_004106a0(s32 arg0);
extern f32 DAT_007613f8;
extern f32 iGpffff8218;
extern void RwMatrixRotate(void *arg0, void *arg1, s32 arg2, f32 fparg0);
extern f32 cosf(f32 fparg0);
extern void RwMatrixScale(void *arg0, void *arg1, s32 arg2);


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

    memset(arg0 + 0x1F1D0, 0, 0x40);
    memset(arg0 + 0x1D6A0, 0, 0x1B30);
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

    if ((datGetFlag(0x1403) != 0) && (datGetFlag(0x142B) != 0)) {
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
/* The copy and sprite loops keep separate cursors; the sprite destination
   is formed before registration. opt_lifetimes on closes the remaining
   22 register words: 852/864 bytes, every relocation and zero tail proved.
   See docs/probe_archive/Shuffle_003742b0_recovery.md. */
// FUN_003742B0
#pragma push
#pragma opt_lifetimes on
s32 func_003742b0(u8 *work)
{
    s32 copyIndex;
    s32 spriteIndex;
    u8 *source;
    s32 archiveIndex;
    s32 byteCount;
    extern void *memcpy(void *, const void *, size_t);
    switch (*(s32 *)(work + 0x1F2EC)) {
    case 0:
    {
        if (H_Cdvd_IsFileLoaded(*(struct HCdvd **)(work + 0x1F2E8)) == 0) break;
        archiveIndex = 0;
        {
            u8 *val;
            u8 *p;
            for (copyIndex = 0; copyIndex < 9; copyIndex++, archiveIndex++) {
                source = func_00455ea0((u8 *)(*(s32 *)(work + 0x1F2E8)), archiveIndex, &byteCount);
                func_0044ea90(&D_0064EA20, 0x101);
                val = D_008873F4[0](1, byteCount, 0x40000);
                p = work + copyIndex * 4 + 0x1F2B8;
                *(u8 **)p = val;
                if (val == 0) {
                    func_0046d730(&D_0064EA20, 0x102);
                }
                memcpy(*(u8 **)p, source, (size_t)byteCount);
            }
        }
        {
            u8 *p;
            for (spriteIndex = 0; spriteIndex < 3; spriteIndex++, archiveIndex++) {
                p = work + spriteIndex * 4 + 0x1F2AC;
                *(u8 **)p = func_0046af60((u32)func_00455ea0((u8 *)(*(s32 *)(work + 0x1F2E8)), archiveIndex, NULL));
                if (*(u8 **)p == NULL) {
                    func_0046d730(&D_0064EA20, 0x109);
                }
            }
        }
        {
            u8 *val;
            u8 *p;
            for (copyIndex = 0; copyIndex < 3; copyIndex++, archiveIndex++) {
                source = func_00455ea0((u8 *)(*(s32 *)(work + 0x1F2E8)), archiveIndex, &byteCount);
                func_0044ea90(&D_0064EA20, 0x10F);
                val = D_008873F4[0](1, byteCount, 0x40000);
                p = work + copyIndex * 4 + 0x1F2DC;
                *(u8 **)p = val;
                if (val == 0) {
                    func_0046d730(&D_0064EA20, 0x110);
                }
                memcpy(*(u8 **)p, source, (size_t)byteCount);
            }
        }
        func_0036d230(func_00455ea0((u8 *)(*(s32 *)(work + 0x1F2E8)), archiveIndex, NULL));
        *(s32 *)(work + 0x1F2EC) = 1;
    }
    case 1:
    {
        s32 val;
        for (spriteIndex = 0; spriteIndex < 3; spriteIndex++) {
            val = *(s32 *)(work + spriteIndex * 4 + 0x1F2AC);
            if ((val != 0) && (func_0046a750(*(s16 **)(work + spriteIndex * 4 + 0x1F2AC)) == 0)) {
                return 0;
            }
        }
    }
        H_Cdvd_Destroy(*(struct HCdvd **)(work + 0x1F2E8));
        *(s32 *)(work + 0x1F2E8) = 0;
        *(s32 *)(work + 0x1F2EC) = 2;
    case 2:
        return 1;
    }
    return 0;
}

#pragma pop
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
    K_View_SetFov((struct RwCamera *)(u32)func_00457120(), *(f32 *)(arg0 + 0x1F310));
}


// FUN_00374960
void func_00374960(u8 *arg0) {
    func_0036d8b0();
    K_View_SetFov((struct RwCamera *)(u32)func_00457120(), *(f32 *)(arg0 + 0x1F310));
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
void func_00374cf0(u8 **arg0) {
    func_0036df30(*arg0);
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
    RwMatrixTranslate((BtlShuffleMatrix *)m, &translation, rwCOMBINEPOSTCONCAT);
    func_003e0e20(m, func_003e9700(camera), 2);
    renderStateBase = (u32)D_00887300;
    (*(BtlShuffleRenderStateSet *)renderStateBase)(6, 0);
    (*(BtlShuffleRenderStateSet *)renderStateBase)(8, 0);
    (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATECULLMODE, (void *)2);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x20) {
        (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATETEXTURERASTER, (void *)(u32)func_0036be00());
        func_00410420(backVertices, 4, m, 3);
        func_004106a0(4);
    }
    func_00378280(card, *(u8 *)(p + 0xD8));
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x80) {
        ShuffleVec3 axis = {0.0f, 0.0f, 1.0f};
        RwMatrixRotate(m, &axis, 1, 180.0f);
    }
    (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATETEXTURERASTER, (void *)(u32)texture);
    func_00410420(frontVertices, 4, m, 3);
    func_004106a0(4);
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x10) {
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        *(u16 *)(arg0 + 0x1F2F2) = (u16)((*(u16 *)(arg0 + 0x1F2F2) + 1) % 60);
        pulseFrame = (f32)(u32)*(u16 *)(arg0 + 0x1F2F2);
        pulseAlpha = 255.0f * (1.0f - cosf((iGpffff81e0 * pulseFrame) / 60.0f)) / 2.0f;
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
        RwMatrixScale(m, &scale, 1);
        func_00410420(frontVertices, 4, m, 3);
        func_004106a0(4);
    }
    func_003e0f40((BtlShuffleMatrix *)m);
}

/* Native b210 O2: 1016/1024 bytes, thirteen resolved relocations and
 * eight zero alignment bytes. Queue pointers to the complete card
 * slots, then dispatch them before the stack-backed payloads expire.
 * See docs/probe_archive/Shuffle_draw_003753f0_20260923.md. */
// FUN_003753F0
void func_003753f0(u8 *work) {
    u8 *cardState;
    s32 cardIndex;
    u8 cardColor[4];
    s32 groupCount;
    u8 *queuedCards[30];
    f32 effectScale;
    u8 *transform;
    f32 phase;
    u8 effectColor[4];
    s32 cardCount;
    s32 mode;
    f32 modeScale;
    s32 effectIndex;
    u32 phaseCounter;
    u8 *card;
    func_0034f1e0();
    cardColor[0] = 0xFF;
    cardColor[1] = 0xFF;
    cardColor[2] = 0xFF;
    if (*(u16 *)(work + 0x1F2F4) & 1) {
        cardCount = func_00378530(*(s32 *)(work + 0x1F304), *(s32 *)(work + 0x1F2FC));
    } else {
        cardCount = *(s32 *)(work + 0x1F304);
    }
    for (cardIndex = 0; cardIndex < cardCount; cardIndex++) {
        if (*(u16 *)(work + (u32)cardIndex * 0xE8 + 0x1D6A0) & 2) {
            if ((*(u16 *)(work + 0x1F2F4) & 2) == 0) {
                func_00374a10(work, cardIndex);
            }
            cardState = work + cardIndex * 0xE8;
            transform = cardState + 0x1D6B8;
            card = work + cardIndex * 0xFB0;
            func_0036dda0(card, transform);
            func_0036de20(card, cardState + 0x1D714);
            cardColor[3] = *(cardState + 0x1D778);
            func_0036de40(card, cardColor);
            if (cardIndex != *(s32 *)(work + 0x1F308)) {
                queuedCards[cardIndex] = card;
                func_003766f0((f32 **)(work + 0x1F24C), func_00374cf0,
                              queuedCards + cardIndex, transform);
            }
        }
    }
    func_00376800((u8 **)(work + 0x1F24C), 1);
    effectColor[0] = 0x20;
    effectColor[1] = 0x40;
    effectColor[2] = 0xFF;
    effectColor[3] = 0xFF;
    modeScale = 1.0f;
    groupCount = *(s32 *)(work + 0x1F304);
    mode = *(s32 *)(work + 0x1F2FC);
    if (mode == 4) {
        goto mode_zero;
    }
    if (mode == 3) {
        goto mode_zero;
    }
    if (mode == 2) {
        goto mode_two;
    }
    if (mode == 1) {
        goto mode_one;
    }
    /* Retail leaves phaseCounter untouched for modes outside 0..4;
     * retain that default path rather than inventing a fallback value. */
    switch (mode) {
    case 0:
        goto mode_zero_value;
    default:
        goto mode_calc;
    }
mode_zero_value:
    phaseCounter = *(u16 *)(work + 0x1F1D2);
    goto mode_calc;
mode_one:
    groupCount /= 2;
    phaseCounter = *(u16 *)(work + 0x1F1D2);
    goto mode_calc;
mode_two:
    groupCount /= 3;
    phaseCounter = *(u16 *)(work + 0x1F1D2);
    modeScale = iGpffff8170;
    goto mode_calc;
mode_zero:
    effectScale = 0.0f;
    goto mode_done;
mode_calc:
    phase = (f32)phaseCounter;
    effectScale = modeScale * ((0.5f * phase) / (f32)groupCount);
mode_done:
    if (!(effectScale <= 0.0f)) {
        for (effectIndex = 0; effectIndex < cardCount; effectIndex++) {
            if (*(u16 *)(work + effectIndex * 0xE8 + 0x1D6A0) & 2) {
                func_003768e0(work, effectIndex, 2, effectColor, effectScale * func_00375a70(work, effectIndex));
            }
        }
    }
}

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
/* measured 2026-09-19: object 39 instrs against retail 39, exact, 2 differing
   words - the closest first-party floor in the tree.  Both differences are
   the same thing: retail keeps `arg0 + idx` in the saved register `$s2` and
   emits `move $v1, $s2` and `move $a0, $s2`, where b210 recomputes
   `addu $v1, $s1, $s0` at each site.
   Eight spellings measured with `python3 tools/probe_variants.py`: the mixed
   form below (2 words) and `register` on the pointer (2) tie for best; using
   the `p` pointer uniformly is 36, inverting which uses re-cast and which use
   `p` is 18, all-re-cast is 29, a `u8 *base` intermediate is 36, and dropping
   the optimization-level pragmas is 36.  The re-cast at the two store sites
   is therefore deliberate and load-bearing, not an accident of the draft.
   What remains is b210's refusal to keep the base live across the two calls
   in a callee-saved register.  Do not re-run the spelling search. */
/* measured 00375f00 (owner, 2026-09-19): 39/39 exact, **2 edits** - the closest first-party
   floor in the tree.  Both are the same difference: retail keeps `arg0 + idx` live in $s2 and
   spells the two later uses `move $v1, $s2` / `move $a0, $s2`, while b210 rematerialises
   `addu $v1, $s1, $s0`.  Eight spellings were measured against the 2 and every one is worse:
     stores through `p` 32/22; calls through the cast and stores through `p` 38/13;
     a `ShuffleRecord *` held across all four uses 38/10; a `ShuffleContext *q = p` copy 32/22;
     a `u8 *raw = arg0 + idx` reused by the stores 35/21; a raw `base` with literal 0x1d6ac /
     0x1d6a4 / 0x1d70c / 0x1d6a8 offsets 32/22; and two flat `ShuffleRecord *` forms 27/28.
   The recomputed cast is load-bearing: it is what holds the object at retail's 39.  Sharing
   the pointer lets b210 fold the address arithmetic and costs instructions, so the last two
   edits are a rematerialise-versus-copy choice inside the register allocator.
   `#pragma optimization_level 1` here is a measured pair per 7aw, not inflation: with it the
   object is 39 instrs / 2 edits, without it 32 instrs / 22 edits - count and edits both
   improve, which is the whole test. */
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
void func_003766f0(f32 **arg0, void (*arg1)(u8 **), u8 **arg2, u8 *arg3) {
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
    *(void (**)(u8 **))(temp_2 + 1) = arg1;
    *(u8 ***)(temp_2 + 2) = arg2;
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
        (*(void (**)(u8 **))(var_16 + 4))(*(u8 ***)(var_16 + 8));
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
/* measured: store-once-hoisted lane reloads banked as guarded floor.
   Retail 1042 trimmed (1044 window), band 1011-1073. Before 997 (-45, -4.3%, outside),
   after 1021 (-21, -2.0%, inside). lwc1 85/109 -> 109/109 exact from four 19-blocks
   at 343/401/459/517 (retail 0x376E3C/0x376F24/0x37700C/0x3770F4); edits 813 -> 677
   (+2 reloc-only), probe words 964 -> 963.
   Two per-lane reload spellings in one probe: ShuffleVec3 struct block kept
   (12-byte copy from stack spill, 1021/677/963) and Vec3Arr array block
   (same 1021/677/963, not kept to avoid new typedef); constant-index f32 array read tried, no change.
   Pattern reusable: lane values stored once and carried in regs must be reloaded per lane as block reads
   to get lwc1x3 swc1x3; swc1 150/150 exact throughout.
   Left: six mfc1 (four case-0 head, one case-1, one case-2) and cvt.s.w +5 dsll32 +7 width noise.
   WARNING: cleaning widths first makes count look worse (offsets shortfall); fix mfc1 only after reloads landed.
   Do not disturb func_00375f00. */
/* measured 003768e0 (owner, 2026-09-19): fnalign **677 -> 658 edits** by spelling the six
   float-to-unsigned guards the way retail does.  m2c writes the lowering as
   `if (!(x >= 2.1474836e9f)) A else B`, which b210 compiles to `c.olt.s` plus a negated
   branch; retail's shape is `c.le.s` with the constant on the LEFT, which is what
   `if (2.1474836e9f <= x) B else A` produces.  The two are complements, so the arms swap
   with the comparison and the logic is unchanged.
   Swept across the 18 first-party floors carrying the pattern (81 sites): this one is the
   best at -19 for six sites, func_002a7920 / func_002a03b0 / func_00119810 give -2 each,
   func_00117980 and func_00119210 give -1, func_002f9d90 / func_00254a70 / func_00172e00
   are neutral and func_00253850 is WORSE by 10.  It is a real lever but a small one -
   roughly three edits per site here, under one elsewhere - so it only pays where the
   sites are dense. */
/* measured 003768e0 (owner, 2026-09-19): fnalign **658 -> 656 edits**, count
   1021 -> 1019 against retail 1042, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
// FUN_003768E0 NONMATCHING
#ifdef NON_MATCHING
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
extern f32 D_0060A0E0;
extern f32 D_0060A0E4;
extern f32 D_0060A0E8;
extern f32 iGpffff8400;
extern f32 iGpffff8404;
extern f32 iGpffff8408;
extern f32 iGpffff8308;
typedef struct ShuffleStackProbe {
    s32 spB0[3];
    s32 spBC;
    s32 spC0;
    s32 spC4;
    s32 spC8;
    u8 _pad_0BC[0x4];
    s32 spD0;
    s32 spD4;
    s32 spD8;
    u8 _pad_0CC[0x4];
    s32 spE0;
    s32 spE4;
    s32 spE8;
    u8 _pad_0DC[0x4];
    f32 spF0[0x40];
    u8 sp1F0[0x5F0];
    u8 sp7E0[0x5F0];
    f32 spDD0;
    f32 spDD4;
    f32 spDD8;
    u8 _pad_DCC[0x4];
    f32 spDE0;
    f32 spDE4;
    f32 spDE8;
    u8 _pad_DDC[0x4];
    f32 spDF0;
    f32 spDF4;
    f32 spDF8;
    u8 _pad_DEC[0x4];
    f32 spE00;
    f32 spE04;
    f32 spE08;
    u8 _pad_DFC[0x4];
    f32 spE10;
    f32 spE14;
    f32 spE18;
    u8 _pad_E0C[0x4];
    f32 spE20;
    f32 spE24;
    f32 spE28;
    u8 _pad_E1C[0x4];
    f32 spE30;
    f32 spE34;
    f32 spE38;
    u8 _pad_E2C[0x4];
    f32 spE40;
    f32 spE44;
    f32 spE48;
    u8 _pad_E3C[0x4];
    f32 spE50;
    f32 spE54;
    f32 spE58;
    u8 _pad_E4C[0x4];
    f32 spE60;
    f32 spE64;
    f32 spE68;
    u8 _pad_E5C[0x4];
    f32 spE70;
    f32 spE74;
    f32 spE78;
    u8 _pad_E6C[0x4];
    f32 spE80;
    f32 spE84;
    f32 spE88;
    u8 _pad_E7C[0x4];
    f32 spE90;
    f32 spE94;
    f32 spE98;
    u8 _pad_E8C[0x4];
    f32 spEA0;
    f32 spEA4;
    f32 spEA8;
    u8 _pad_E9C[0x4];
    f32 spEB0;
    f32 spEB4;
    f32 spEB8;
    u8 _pad_EAC[0x4];
    f32 spEC0;
    f32 spEC4;
    f32 spEC8;
    u8 _pad_EBC[0x4];
    f32 spED0;
    f32 spED4;
    f32 spED8;
    u8 _pad_ECC[0x4];
    f32 spEE0;
    f32 spEE4;
    f32 spEE8;
    u8 _pad_EDC[0x4];
    f32 spEF0;
    f32 spEF4;
    f32 spEF8;
    u8 _pad_EEC[0x4];
    f32 spF00;
    f32 spF04;
    f32 spF08;
    u8 _pad_EFC[0x4];
    f32 spF10;
    f32 spF14;
    f32 spF18;
    u8 _pad_F0C[0x4];
    f32 spF20;
    f32 spF24;
    f32 spF28;
    u8 _pad_F1C[0x4];
    f32 spF30;
    f32 spF34;
    f32 spF38;
    u8 _pad_F2C[0x4];
    f32 spF40;
    f32 spF44;
    f32 spF48;
    u8 _tail[0x4];
} ShuffleStackProbe;
void func_003768e0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, f32 fparg0) {
    ShuffleStackProbe stack;
    u8 *var_19;
    u8 *var_19_2;
    u8 *var_19_3;
    u8 *var_20;
    u8 *var_20_2;
    u8 *var_20_3;
    u8 *var_2;
    u8 *var_3_5;
    u8 *var_4;
    u8 *var_4_2;
    u8 *var_5_5;
    u8 *var_5_6;
    f32 temp_f10;
    f32 temp_f10_2;
    f32 temp_f11;
    f32 temp_f11_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f15;
    f32 temp_f15_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f22_4;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f25;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f5_4;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f9;
    f32 temp_f9_2;
    f32 var_f1;
    f32 var_f20;
    f32 var_f21;
    f32 var_f21_2;
    f32 var_f24;
    f32 var_f24_2;
    f32 var_f24_3;
    f32 var_f2;
    f32 var_f4;
    f32 var_f4_2;
    u8 *temp_21;
    s32 temp_4;
    s32 var_16;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s64 temp_18;
    s8 temp_23;
    s8 temp_23_2;
    s8 var_3;
    s8 var_3_2;
    s8 var_3_3;
    s8 var_3_4;
    u32 temp_2;
    u32 temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_7;
    u8 *temp_4_8;
    u8 *temp_4_9;
    u8 *temp_5;

    temp_18 = (s64) ((s64)arg2 << 0x38) >> 0x38;
    if (temp_18 >= 3) {
        func_0046d730(&D_0064EA20, 0x5DE);
    }
    stack.spD8 = 0x3F800000;
    stack.spC4 = 0x3F800000;
    stack.spB0[0] = 0x3F800000;
    stack.spC0 = 0;
    stack.spB0[2] = 0;
    stack.spB0[1] = 0;
    stack.spD4 = 0;
    stack.spD0 = 0;
    stack.spC8 = 0;
    stack.spE8 = 0;
    stack.spE4 = 0;
    stack.spE0 = 0;
    stack.spBC |= 0x20003;
    RpSkyRenderStateSet(2, 0x48);
    RpSkyRenderStateSet(3, 0x71801);
    D_00887300[0](rwRENDERSTATECULLMODE, (void *)1);
    D_00887300[0](rwRENDERSTATEZTESTENABLE, (void *)1);
    D_00887300[0](8, 0);
    temp_5 = (u8 *)(arg0 + (arg1 * 0xE8) + 0x1D6A0);
    temp_21 = arg0 + (arg1 * 0xFB0);
    temp_4 = (s32)(M2C_FIELD(temp_5, s32 *, 4));
    if (temp_4 == 6) {
        temp_2 = M2C_FIELD(arg3, u8 *, 3);
        if (temp_2 >= 0) {
            var_f2 = (f32) temp_2;
        } else {
            var_f2 = 2.0f * (f32) ((temp_2 >> 1) | (temp_2 & 1));
        }
        temp_2_2 = M2C_FIELD(temp_5, u8 *, 0xD8);
        if (temp_2_2 >= 0) {
            var_f1 = (f32) temp_2_2;
        } else {
            var_f1 = 2.0f * (f32) ((temp_2_2 >> 1) | (temp_2_2 & 1));
        }
        temp_f22 = var_f2 * (var_f1 / 255.0f);
        switch (temp_18) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            var_20 = (u8 *)(&stack.sp7E0);
            var_19 = (u8 *)(&stack.sp1F0);
            temp_f20 = iGpffff8400 * temp_f22;
            var_f21_2 = 1.0f;
            var_f24 = 0.0f;
            var_18 = 0;
do {
                    func_003764b0(arg0, arg1, var_f24, ((u8 *)stack.spF0 + (var_18 * 0xC)));
                    var_f24 -= fparg0 / 21.0f;
                    M2C_FIELD(var_20, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                    M2C_FIELD(var_20, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                    M2C_FIELD(var_20, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                    temp_f1 = temp_f22 * var_f21_2;
                    if (2.1474836e9f <= temp_f1) {
                        var_3 = (M2C_BITWISE(s32, (temp_f1 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                    } else {
                        var_3 = 0x4F000000 & 0xFF;
                    }
                    M2C_FIELD((var_20 + 0xC), s8 *, 3) = var_3;
                    M2C_FIELD(var_20, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                    M2C_FIELD(var_20, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                    M2C_FIELD(var_20, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                    temp_f2 = temp_f20 * var_f21_2;
                    if (2.1474836e9f <= temp_f2) {
                        var_3_2 = (M2C_BITWISE(s32, (temp_f2 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                    } else {
                        var_3_2 = 0x4F000000 & 0xFF;
                    }
                    M2C_FIELD((var_20 + 0x30), s8 *, 3) = var_3_2;
                    M2C_FIELD(var_19, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                    M2C_FIELD(var_19, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                    M2C_FIELD(var_19, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                    if (2.1474836e9f <= temp_f2) {
                        var_3_3 = (M2C_BITWISE(s32, (temp_f2 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                    } else {
                        var_3_3 = 0x4F000000 & 0xFF;
                    }
                    M2C_FIELD((var_19 + 0xC), s8 *, 3) = var_3_3;
                    M2C_FIELD(var_19, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                    M2C_FIELD(var_19, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                    M2C_FIELD(var_19, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                    if (2.1474836e9f <= temp_f1) {
                        var_3_4 = (M2C_BITWISE(s32, (temp_f1 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                    } else {
                        var_3_4 = 0x4F000000 & 0xFF;
                    }
                    M2C_FIELD((var_19 + 0x30), s8 *, 3) = var_3_4;
                    var_f21_2 += (f32)(s32)(iGpffff8404);
                    var_18 += 1;
                    var_20 += 0x48;
                    var_19 += 0x48;
} while (var_18 < 0x15);
            temp_f21 = 0.5f * func_0036de70(temp_21);
            temp_f20_2 = 0.5f * func_0036deb0(temp_21);
            var_16 = 0;
loop_50:
            if (var_16 < 4) {
                var_3_5 = (u8 *)(&stack.sp7E0);
                var_2 = (u8 *)(&stack.sp1F0);
                switch (var_16) {                   /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    var_5 = 0;
loop_36:
                    if (var_5 < 0x15) {
                        temp_4_2 = (u8 *)((u8 *)stack.spF0 + (var_5 * 0xC));
                        temp_4_3 = (u8 *)(temp_4_2 + 0xF0);
                        temp_f5 = temp_f21 + M2C_FIELD(temp_4_2, f32 *, 0xF0);
                        stack.spF40 = temp_f5;
                        temp_f4 = M2C_FIELD(temp_4_3, f32 *, 4);
                        stack.spF44 = temp_f4 - temp_f20_2;
                        temp_f3 = M2C_FIELD(temp_4_3, f32 *, 8);
                        stack.spF48 = temp_f3;
                        *(ShuffleVec3 *)var_3_5 = *(ShuffleVec3 *)&stack.spF40;
                        stack.spF30 = temp_f5;
                        stack.spF34 = temp_f4;
                        stack.spF38 = temp_f3;
                        *(ShuffleVec3 *)((u8 *)var_3_5 + 0x24) = *(ShuffleVec3 *)&stack.spF30;
                        stack.spF20 = temp_f5;
                        stack.spF24 = temp_f4;
                        stack.spF28 = temp_f3;
                        *(ShuffleVec3 *)var_2 = *(ShuffleVec3 *)&stack.spF20;
                        stack.spF10 = temp_f5;
                        stack.spF14 = temp_f20_2 + temp_f4;
                        stack.spF18 = temp_f3;
                        *(ShuffleVec3 *)((u8 *)var_2 + 0x24) = *(ShuffleVec3 *)&stack.spF10;
                        var_5 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_36;
                    }
                    break;
                case 1:                             /* switch 2 */
                    var_5_2 = 0;
loop_40:
                    if (var_5_2 < 0x15) {
                        temp_4_4 = (u8 *)((u8 *)stack.spF0 + (var_5_2 * 0xC));
                        temp_4_5 = (u8 *)(temp_4_4 + 0xF0);
                        temp_f5_2 = M2C_FIELD(temp_4_4, f32 *, 0xF0) - temp_f21;
                        stack.spF00 = temp_f5_2;
                        temp_f4_2 = M2C_FIELD(temp_4_5, f32 *, 4);
                        stack.spF04 = temp_f4_2 - temp_f20_2;
                        temp_f3_2 = M2C_FIELD(temp_4_5, f32 *, 8);
                        stack.spF08 = temp_f3_2;
                        *(ShuffleVec3 *)var_3_5 = *(ShuffleVec3 *)&stack.spF00;
                        stack.spEF0 = temp_f5_2;
                        stack.spEF4 = temp_f4_2;
                        stack.spEF8 = temp_f3_2;
                        *(ShuffleVec3 *)((u8 *)var_3_5 + 0x24) = *(ShuffleVec3 *)&stack.spEF0;
                        stack.spEE0 = temp_f5_2;
                        stack.spEE4 = temp_f4_2;
                        stack.spEE8 = temp_f3_2;
                        *(ShuffleVec3 *)var_2 = *(ShuffleVec3 *)&stack.spEE0;
                        stack.spED0 = temp_f5_2;
                        stack.spED4 = temp_f20_2 + temp_f4_2;
                        stack.spED8 = temp_f3_2;
                        *(ShuffleVec3 *)((u8 *)var_2 + 0x24) = *(ShuffleVec3 *)&stack.spED0;
                        var_5_2 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_40;
                    }
                    break;
                case 2:                             /* switch 2 */
                    var_5_3 = 0;
loop_44:
                    if (var_5_3 < 0x15) {
                        temp_4_6 = (u8 *)((u8 *)stack.spF0 + (var_5_3 * 0xC));
                        temp_4_7 = (u8 *)(temp_4_6 + 0xF0);
                        temp_f5_3 = M2C_FIELD(temp_4_6, f32 *, 0xF0);
                        stack.spEC0 = temp_f21 + temp_f5_3;
                        temp_f4_3 = temp_f20_2 + M2C_FIELD(temp_4_7, f32 *, 4);
                        stack.spEC4 = temp_f4_3;
                        temp_f3_3 = M2C_FIELD(temp_4_7, f32 *, 8);
                        stack.spEC8 = temp_f3_3;
                        *(ShuffleVec3 *)var_3_5 = *(ShuffleVec3 *)&stack.spEC0;
                        stack.spEB0 = temp_f5_3;
                        stack.spEB4 = temp_f4_3;
                        stack.spEB8 = temp_f3_3;
                        *(ShuffleVec3 *)((u8 *)var_3_5 + 0x24) = *(ShuffleVec3 *)&stack.spEB0;
                        stack.spEA0 = temp_f5_3;
                        stack.spEA4 = temp_f4_3;
                        stack.spEA8 = temp_f3_3;
                        *(ShuffleVec3 *)var_2 = *(ShuffleVec3 *)&stack.spEA0;
                        stack.spE90 = temp_f5_3 - temp_f21;
                        stack.spE94 = temp_f4_3;
                        stack.spE98 = temp_f3_3;
                        *(ShuffleVec3 *)((u8 *)var_2 + 0x24) = *(ShuffleVec3 *)&stack.spE90;
                        var_5_3 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_44;
                    }
                    break;
                case 3:                             /* switch 2 */
                    var_5_4 = 0;
loop_48:
                    if (var_5_4 < 0x15) {
                        temp_4_8 = (u8 *)((u8 *)stack.spF0 + (var_5_4 * 0xC));
                        temp_4_9 = (u8 *)(temp_4_8 + 0xF0);
                        temp_f5_4 = M2C_FIELD(temp_4_8, f32 *, 0xF0);
                        stack.spE80 = temp_f21 + temp_f5_4;
                        temp_f4_4 = M2C_FIELD(temp_4_9, f32 *, 4) - temp_f20_2;
                        stack.spE84 = temp_f4_4;
                        temp_f3_4 = M2C_FIELD(temp_4_9, f32 *, 8);
                        stack.spE88 = temp_f3_4;
                        *(ShuffleVec3 *)var_3_5 = *(ShuffleVec3 *)&stack.spE80;
                        stack.spE70 = temp_f5_4;
                        stack.spE74 = temp_f4_4;
                        stack.spE78 = temp_f3_4;
                        *(ShuffleVec3 *)((u8 *)var_3_5 + 0x24) = *(ShuffleVec3 *)&stack.spE70;
                        stack.spE60 = temp_f5_4;
                        stack.spE64 = temp_f4_4;
                        stack.spE68 = temp_f3_4;
                        *(ShuffleVec3 *)var_2 = *(ShuffleVec3 *)&stack.spE60;
                        stack.spE50 = temp_f5_4 - temp_f21;
                        stack.spE54 = temp_f4_4;
                        stack.spE58 = temp_f3_4;
                        *(ShuffleVec3 *)((u8 *)var_2 + 0x24) = *(ShuffleVec3 *)&stack.spE50;
                        var_5_4 += 1;
                        var_3_5 += 0x48;
                        var_2 += 0x48;
                        goto loop_48;
                    }
                    break;
                }
                func_00410420((s32)&stack.sp7E0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                func_00410420((s32)&stack.sp1F0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                var_16 += 1;
                goto loop_50;
            }
            break;
        case 1:                                     /* switch 1 */
            var_20_2 = (u8 *)(&stack.sp7E0);
            var_19_2 = (u8 *)(&stack.sp1F0);
            if (2.1474836e9f <= temp_f22) {
                var_3_6 = (M2C_BITWISE(s32, (temp_f22 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            } else {
                var_3_6 = 0x4F000000 & 0xFF;
            }
            temp_23 = var_3_6 & 0xFF;
            var_f24_2 = 0.0f;
            var_18_2 = 0;
loop_57:
            if (var_18_2 < 0x15) {
                func_003764b0(arg0, arg1, var_f24_2, ((u8 *)stack.spF0 + (var_18_2 * 0xC)));
                var_f24_2 -= fparg0 / 21.0f;
                M2C_FIELD(var_20_2, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_2, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_2, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_2, s8 *, 0xF) = 0;
                M2C_FIELD(var_20_2, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_2, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_2, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_2, s8 *, 0x33) = temp_23;
                M2C_FIELD(var_19_2, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_2, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_2, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_2, s8 *, 0xF) = temp_23;
                M2C_FIELD(var_19_2, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_2, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_2, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_2, s8 *, 0x33) = 0;
                var_18_2 += 1;
                var_20_2 += 0x48;
                var_19_2 += 0x48;
                goto loop_57;
            }
            temp_f25 = 0.5f * func_0036de70(temp_21);
            temp_f24 = 0.5f * func_0036deb0(temp_21);
            var_16_2 = 0;
            temp_f23 = -temp_f25;
            temp_f22_2 = -temp_f24;
loop_72:
            switch (var_16_2) {                     /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                var_f21 = temp_f25;
                var_f20 = temp_f24;
            default:                                /* switch 3 */
block_68:
                var_5_5 = (u8 *)(&stack.sp7E0);
                var_4 = (u8 *)(&stack.sp1F0);
                var_f4 = 1.0f;
                var_3_7 = 0;
loop_70:
                if (var_3_7 < 0x15) {
                    temp_f6 = 3.0f * var_f4;
                    temp_f11 = D_0060A0E0 * temp_f6;
                    temp_f16 = D_0060A0E4 * temp_f6;
                    temp_f15 = D_0060A0E8 * temp_f6;
                    temp_2_3 = (u8 *)((u8 *)stack.spF0 + (var_3_7 * 0xC));
                    temp_2_4 = (u8 *)(temp_2_3 + 0xF0);
                    temp_f10 = M2C_FIELD(temp_2_3, f32 *, 0xF0);
                    temp_f9 = M2C_FIELD(temp_2_4, f32 *, 4);
                    temp_f14 = M2C_FIELD(temp_2_4, f32 *, 8);
                    stack.spE40 = temp_f11 + temp_f10 + var_f21;
                    stack.spE44 = temp_f16 + temp_f9 + var_f20;
                    stack.spE48 = temp_f15 + temp_f14;
                    *(ShuffleVec3 *)var_5_5 = *(ShuffleVec3 *)&stack.spE40;
                    temp_f13 = var_f21 + temp_f10;
                    stack.spE30 = temp_f13;
                    temp_f12 = var_f20 + temp_f9;
                    stack.spE34 = temp_f12;
                    stack.spE38 = temp_f14;
                    *(ShuffleVec3 *)((u8 *)var_5_5 + 0x24) = *(ShuffleVec3 *)&stack.spE30;
                    stack.spE20 = temp_f13;
                    stack.spE24 = temp_f12;
                    stack.spE28 = temp_f14;
                    *(ShuffleVec3 *)var_4 = *(ShuffleVec3 *)&stack.spE20;
                    stack.spE10 = (temp_f10 - temp_f11) + var_f21;
                    stack.spE14 = (temp_f9 - temp_f16) + var_f20;
                    stack.spE18 = temp_f14 - temp_f15;
                    *(ShuffleVec3 *)((u8 *)var_4 + 0x24) = *(ShuffleVec3 *)&stack.spE10;
                    var_f4 += (f32)(s32)(iGpffff8404);
                    var_3_7 += 1;
                    var_5_5 += 0x48;
                    var_4 += 0x48;
                    goto loop_70;
                }
                func_00410420((s32)&stack.sp7E0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                func_00410420((s32)&stack.sp1F0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                var_16_2 += 1;
                goto loop_72;
            case 1:                                 /* switch 3 */
                var_f21 = temp_f23;
                var_f20 = temp_f24;
                goto block_68;
            case 2:                                 /* switch 3 */
                var_f21 = temp_f25;
                var_f20 = temp_f22_2;
                goto block_68;
            case 3:                                 /* switch 3 */
                var_f21 = temp_f23;
                var_f20 = temp_f22_2;
                goto block_68;
            }
            break;
        case 2:                                     /* switch 1 */
            func_003e9700(*(s32 *)((u8 *)func_00457120() + 4));
            var_20_3 = (u8 *)(&stack.sp7E0);
            var_19_3 = (u8 *)(&stack.sp1F0);
            if (2.1474836e9f <= temp_f22) {
                var_3_8 = (M2C_BITWISE(s32, (temp_f22 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            } else {
                var_3_8 = 0x4F000000 & 0xFF;
            }
            temp_23_2 = var_3_8 & 0xFF;
            var_f24_3 = 0.0f;
            var_18_3 = 0;
loop_79:
            if (var_18_3 < 0x15) {
                func_003764b0(arg0, arg1, var_f24_3, ((u8 *)stack.spF0 + (var_18_3 * 0xC)));
                var_f24_3 -= fparg0 / 21.0f;
                M2C_FIELD(var_20_3, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_3, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_3, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_3, s8 *, 0xF) = 0;
                M2C_FIELD(var_20_3, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_20_3, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_20_3, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_20_3, s8 *, 0x33) = temp_23_2;
                M2C_FIELD(var_19_3, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_3, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_3, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_3, s8 *, 0xF) = temp_23_2;
                M2C_FIELD(var_19_3, u8 *, 0x30) = (u8) M2C_FIELD(arg3, u8 *, 0);
                M2C_FIELD(var_19_3, u8 *, 0x31) = (u8) M2C_FIELD(arg3, u8 *, 1);
                M2C_FIELD(var_19_3, u8 *, 0x32) = (u8) M2C_FIELD(arg3, u8 *, 2);
                M2C_FIELD(var_19_3, s8 *, 0x33) = 0;
                var_18_3 += 1;
                var_20_3 += 0x48;
                var_19_3 += 0x48;
                goto loop_79;
            }
            temp_f22_3 = 0.5f * func_0036de70(temp_21);
            var_16_3 = 0;
            temp_f1_2 = (f32)(s32)(iGpffff8218);
            temp_f24_2 = temp_f1_2 * temp_f22_3;
            temp_f23_2 = (f32)(s32)(iGpffff8308 * (0.5f * func_0036deb0(temp_21)));
            temp_f22_4 = temp_f1_2 * -temp_f22_3;
loop_90:
            switch (var_16_3) {                     /* switch 4; irregular */
            case 0:                                 /* switch 4 */
                var_f21 = temp_f24_2;
                var_f20 = temp_f23_2;
            default:                                /* switch 4 */
block_86:
                var_5_6 = (u8 *)(&stack.sp7E0);
                var_4_2 = (u8 *)(&stack.sp1F0);
                var_f4_2 = 1.0f;
                var_3_9 = 0;
loop_88:
                if (var_3_9 < 0x15) {
                    temp_f6_2 = iGpffff8408 * var_f4_2;
                    temp_f11_2 = D_0060A0E0 * temp_f6_2;
                    temp_f16_2 = D_0060A0E4 * temp_f6_2;
                    temp_f15_2 = D_0060A0E8 * temp_f6_2;
                    temp_2_5 = (u8 *)((u8 *)stack.spF0 + (var_3_9 * 0xC));
                    temp_2_6 = (u8 *)(temp_2_5 + 0xF0);
                    temp_f10_2 = M2C_FIELD(temp_2_5, f32 *, 0xF0);
                    temp_f9_2 = M2C_FIELD(temp_2_6, f32 *, 4);
                    temp_f14_2 = M2C_FIELD(temp_2_6, f32 *, 8);
                    stack.spE00 = temp_f11_2 + temp_f10_2 + var_f21;
                    stack.spE04 = temp_f16_2 + temp_f9_2 + var_f20;
                    stack.spE08 = temp_f15_2 + temp_f14_2;
                    *(ShuffleVec3 *)var_5_6 = *(ShuffleVec3 *)&stack.spE00;
                    temp_f13_2 = var_f21 + temp_f10_2;
                    stack.spDF0 = temp_f13_2;
                    temp_f12_2 = var_f20 + temp_f9_2;
                    stack.spDF4 = temp_f12_2;
                    stack.spDF8 = temp_f14_2;
                    *(ShuffleVec3 *)((u8 *)var_5_6 + 0x24) = *(ShuffleVec3 *)&stack.spDF0;
                    stack.spDE0 = temp_f13_2;
                    stack.spDE4 = temp_f12_2;
                    stack.spDE8 = temp_f14_2;
                    *(ShuffleVec3 *)var_4_2 = *(ShuffleVec3 *)&stack.spDE0;
                    stack.spDD0 = (temp_f10_2 - temp_f11_2) + var_f21;
                    stack.spDD4 = (temp_f9_2 - temp_f16_2) + var_f20;
                    stack.spDD8 = temp_f14_2 - temp_f15_2;
                    *(ShuffleVec3 *)((u8 *)var_4_2 + 0x24) = *(ShuffleVec3 *)&stack.spDD0;
                    var_f4_2 += (f32)(s32)(iGpffff8404);
                    var_3_9 += 1;
                    var_5_6 += 0x48;
                    var_4_2 += 0x48;
                    goto loop_88;
                }
                func_00410420((s32)&stack.sp7E0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                func_00410420((s32)&stack.sp1F0, 0x2A, &stack.spB0[0], 2);
                func_004106a0(4);
                var_16_3 += 1;
                goto loop_90;
            case 1:                                 /* switch 4 */
                var_f21 = temp_f22_4;
                var_f20 = temp_f23_2;
                goto block_86;
            }
            break;
        }
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003768e0);
#endif


/* Build an untextured screen-space quad from the card's position and rotation.
 * The four 64-byte sky2 vertices retain the PS2 screen/color/reciprocal-Z layout.
 * measured b210 -O2: 1236/1248 bytes, complete resolved retail instructions.
 * See docs/probe_archive/Shuffle_00377930_recovery.md. */
static inline u8 *shuffleVertexSource377930(s32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
// FUN_00377930
void func_00377930(u8 *arg0, s32 arg1, const BtlShuffleVec3 *arg2, u8 *arg3, s32 arg4)
{
    extern f32 D_008872F8_abs[];
    typedef char AssertSkyVertexSize[(sizeof(BtlShuffleSkyVertex) == 64) ? 1 : -1];
    f32 datw;
    f32 halfW;
    f32 halfH;
    f32 scale;
    f32 norm;
    f32 n0;
    f32 n1;
    f32 n2;
    f32 xw, yw, zw, xx, yy, zz, yz, zx, xy;
    f32 sp1C8[2];
    BtlShuffleVec3 sp1B8v;
    BtlShuffleSkyVertex mat[4];
    BtlShuffleVec3 sp80[4];
    ShuffleVec4 sp70v;
    u8 *chain;
    u8 *card;
    BtlShuffleMatrix *matrix;
    BtlShuffleSkyFields *slot;
    s32 index;

    datw = D_008872F8_abs[0];
    scale = 1.0f / *(f32 *)((u8 *)func_00457120() + 0x80);
    if (arg2 != 0) {
        sp1B8v = *(BtlShuffleVec3 *)arg2;
    } else {
        chain = shuffleVertexSource377930(arg1 * 0xE8, arg0);
        sp1B8v = *(BtlShuffleVec3 *)(chain + 0x1D6B8);
    }
    chain = shuffleVertexSource377930(arg1 * 0xE8, arg0);
    sp70v = *(ShuffleVec4 *)(chain + 0x1D714);
    card = arg0 + arg1 * 0xFB0;
    halfW = func_0036de70(card) / 2.0f;
    halfH = func_0036deb0(card) / 2.0f;
    matrix = func_003e0f80();
    func_00457120();
    norm = 2.0f / (sp70v.x * sp70v.x + sp70v.y * sp70v.y + sp70v.z * sp70v.z + sp70v.w * sp70v.w);
    n0 = sp70v.x * norm;
    n1 = sp70v.y * norm;
    n2 = sp70v.z * norm;
    xw = n0 * sp70v.w;
    yw = n1 * sp70v.w;
    zw = n2 * sp70v.w;
    xx = sp70v.x * n0;
    yy = sp70v.y * n1;
    zz = sp70v.z * n2;
    yz = sp70v.y * n2;
    zx = sp70v.z * n0;
    xy = sp70v.x * n1;
    matrix->right.x = 1.0f - (yy + zz);
    matrix->right.y = xy + zw;
    matrix->right.z = zx - yw;
    matrix->up.x = xy - zw;
    matrix->up.y = 1.0f - (zz + xx);
    matrix->up.z = yz + xw;
    matrix->at.x = zx + yw;
    matrix->at.y = yz - xw;
    matrix->at.z = 1.0f - (xx + yy);
    matrix->pos.x = 0.0f;
    matrix->pos.y = 0.0f;
    matrix->pos.z = 0.0f;
    matrix->flags = 3;
    RwMatrixTranslate(matrix, &sp1B8v, 2);
    sp80[0].x = halfW;
    sp80[0].y = halfH;
    sp80[0].z = 0.0f;
    sp80[1].x = -halfW;
    sp80[1].y = halfH;
    sp80[1].z = 0.0f;
    sp80[2].x = halfW;
    sp80[2].y = -halfH;
    sp80[2].z = 0.0f;
    sp80[3].x = -halfW;
    sp80[3].y = -halfH;
    sp80[3].z = 0.0f;
    for (index = 0; index < 4; index++) {
        func_003e42a0(&sp1B8v, &sp80[index], matrix);
        func_003717e0((u8 *)&sp1B8v, (u8 *)sp1C8);
        slot = &mat[index].u.els;
        slot->scrVertex.x = sp1C8[0];
        slot->scrVertex.y = sp1C8[1];
        slot->scrVertex.z = datw;
        slot->color.r = (f32)(u32)arg3[0];
        slot->color.g = (f32)(u32)arg3[1];
        slot->color.b = (f32)(u32)arg3[2];
        slot->color.a = (f32)(u32)arg3[3];
        slot->recipZ = scale;
    }
    D_00887300[0](rwRENDERSTATETEXTURERASTER, NULL);
    if (arg4 != 0 && arg3[3] == 0xFF) {
        func_00364c50();
    }
    D_00887310[0](rwPRIMTYPETRISTRIP, mat, 4);
    if (arg4 != 0 && arg3[3] == 0xFF) {
        func_00364c70();
    }
    func_003e0f40(matrix);
}
// FUN_00377E10
s32 func_00377e10(u8 *arg0) {
    s32 *p = *(s32 **)(arg0 + 0x38);

    if (func_00378220(arg0) == 0) {
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


/* The two faces belong to the allocated 0x240-byte work buffer; the
   registered task is retained separately and returned to the caller. Each
   loop snapshots one position before writing a 0x24-byte vertex. Independent
   loop indices and the existing invariant hoist reproduce all 800 bytes.
   Full code/caller/data proof: docs/probe_archive/Shuffle_00377eb0_recovery.md. */
// FUN_00377EB0
#pragma push
#pragma opt_loop_invariants on
s32 func_00377eb0(u8 *arg0, s32 arg1)
{
    struct ShuffleCardPosition { f32 x, y, z; };
    struct ShuffleCardPosition front;
    struct ShuffleCardPosition back;
    struct ShuffleCardPosition positions[4];
    f32 u[4];
    f32 v[4];
    s32 cardIndex;
    u8 *work;
    u8 *task;
    u8 *parent;
    u8 *vertex;
    f32 height;
    f32 halfWidth;

    parent = arg0;
    cardIndex = arg1;
    func_0044ea90(D_0064EA20, 0x76C);
    work = D_008873F4[0](1, 0x240, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064EA20, 0x76D);
    }
    task = (u8 *)(s32)func_00451fc0((void *)(parent), (const void *)(D_0064EA60), 0x12, 0, 0, func_00377e10, func_00377e60, work);
    if (task == NULL) {
        func_0046d730(D_0064EA20, 0x777);
    }
    func_003781d0(task, cardIndex);
    func_00378260(task, 0xFF, 0xFF, 0xFF, 0);

    halfWidth = 30.0f;
    positions[0].x = -halfWidth;
    height = iGpffff83e0;
    positions[0].y = height;
    positions[0].z = 0.0f;
    u[0] = 0.9921875f;
    v[0] = 0;
    positions[1].x = halfWidth;
    positions[1].y = height;
    positions[1].z = 0.0f;
    u[1] = 0;
    v[1] = 0;
    positions[2].x = -halfWidth;
    height = -height;
    positions[2].y = height;
    positions[2].z = 0.0f;
    u[2] = 0.9921875f;
    v[2] = 0.64453125f;
    positions[3].x = halfWidth;
    positions[3].y = height;
    positions[3].z = 0.0f;
    u[3] = 0;
    v[3] = 0.64453125f;

    {
        s32 index;
        for (index = 0; index < 4; index++) {
            vertex = (u8 *)&positions[index];
            front.x = *(f32 *)(vertex + 0);
            front.y = *(f32 *)(vertex + 4);
            front.z = *(f32 *)(vertex + 8);
            vertex = work + index * 0x24;
            *(struct ShuffleCardPosition *)(vertex + 0x120) = front;
            vertex[0x12C] = 0xFF;
            vertex[0x12D] = 0xFF;
            vertex[0x12E] = 0xFF;
            vertex[0x12F] = 0xFF;
            *(f32 *)(vertex + 0x13C) = u[index];
            *(f32 *)(vertex + 0x140) = v[index];
        }
    }

    halfWidth = 30.0f;
    positions[0].x = halfWidth;
    height = iGpffff83e0;
    positions[0].y = height;
    positions[0].z = 0.0f;
    u[0] = 0.9921875f;
    v[0] = 0;
    positions[1].x = -halfWidth;
    positions[1].y = height;
    positions[1].z = 0.0f;
    u[1] = 0;
    v[1] = 0;
    positions[2].x = halfWidth;
    height = -height;
    positions[2].y = height;
    positions[2].z = 0.0f;
    u[2] = 0.9921875f;
    v[2] = 0.64453125f;
    positions[3].x = -halfWidth;
    positions[3].y = height;
    positions[3].z = 0.0f;
    u[3] = 0;
    v[3] = 0.64453125f;

    {
        s32 index;
        for (index = 0; index < 4; index++) {
            vertex = (u8 *)&positions[index];
            back.x = *(f32 *)(vertex + 0);
            back.y = *(f32 *)(vertex + 4);
            back.z = *(f32 *)(vertex + 8);
            vertex = work + index * 0x24;
            *(struct ShuffleCardPosition *)(vertex + 0x1B0) = back;
            vertex[0x1BC] = 0xFF;
            vertex[0x1BD] = 0xFF;
            vertex[0x1BE] = 0xFF;
            vertex[0x1BF] = 0xFF;
            *(f32 *)(vertex + 0x1CC) = u[index];
            *(f32 *)(vertex + 0x1D0) = v[index];
        }
    }
    return (s32)task;
}
#pragma pop
// FUN_003781D0
void func_003781d0(u8 *arg0, s32 arg1) {
    char buf[0x100];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    sprintf(buf, D_0064EA80, arg1 & 0xFF);
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
