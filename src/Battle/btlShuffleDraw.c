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
extern void func_003723a0(u8 *arg0, u16 arg1, u16 arg2, u8 *arg3, u8 *arg4, f32 fparg0);
extern void func_00372c30(u8 *arg0, u16 arg1, u16 arg2, u8 *arg3, u8 *arg4, u8 *arg5);
extern void func_003733d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00373590(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

typedef BtlShuffleVec3 ShuffleVec3;
typedef struct { f32 x, y, z, w; } ShuffleVec4;
extern void func_00372870(u8 *arg0, u16 arg1, u16 arg2, u8 *arg3, ShuffleVec4 *arg4);
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
extern void func_003760f0(u8 *arg0, s32 arg1, u16 arg2, u16 arg3, f32 *arg4, f32 *arg5);
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
struct RwFrame;
extern BtlShuffleMatrix *func_003e9700(struct RwFrame *frame);
extern void func_003e0e20(u8 *arg0, void *arg1, s32 arg2);
typedef enum RpSkyRenderState {
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,
    rpSKYRENDERSTATEALPHA_1,
    rpSKYRENDERSTATEATEST_1,
    rpSKYRENDERSTATEFARFOGPLANE,
    rpSKYRENDERSTATEMAXMIPLEVELS,
    rpSKYRENDERSTATEFORCEENUMSIZEINT = 0x7fffffff
} RpSkyRenderState;
extern s32 RpSkyRenderStateSet(RpSkyRenderState state, void *value);
extern s32 func_0036be00(void);
struct RxObjSpace3DVertex;
extern void *func_00410420(struct RxObjSpace3DVertex *vertices, u32 count, BtlShuffleMatrix *matrix, u32 flags);
extern s32 func_004106a0(BtlShufflePrimitive primitive);
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
    func_003e0e20(m, func_003e9700((struct RwFrame *)camera), 2);
    renderStateBase = (u32)D_00887300;
    (*(BtlShuffleRenderStateSet *)renderStateBase)(6, 0);
    (*(BtlShuffleRenderStateSet *)renderStateBase)(8, 0);
    (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATECULLMODE, (void *)2);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x20) {
        (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATETEXTURERASTER, (void *)(u32)func_0036be00());
        func_00410420((struct RxObjSpace3DVertex *)backVertices, 4, (BtlShuffleMatrix *)m, 3);
        func_004106a0(4);
    }
    func_00378280(card, *(u8 *)(p + 0xD8));
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x80) {
        ShuffleVec3 axis = {0.0f, 0.0f, 1.0f};
        RwMatrixRotate(m, &axis, 1, 180.0f);
    }
    (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATETEXTURERASTER, (void *)(u32)texture);
    func_00410420((struct RxObjSpace3DVertex *)frontVertices, 4, (BtlShuffleMatrix *)m, 3);
    func_004106a0(4);
    if (*(u16 *)(arg0 + 0x1F2F4) & 0x10) {
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        *(u16 *)(arg0 + 0x1F2F2) = (u16)((*(u16 *)(arg0 + 0x1F2F2) + 1) % 60);
        pulseFrame = (f32)(u32)*(u16 *)(arg0 + 0x1F2F2);
        pulseAlpha = 255.0f * (1.0f - cosf((iGpffff81e0 * pulseFrame) / 60.0f)) / 2.0f;
        pulseByte = (u8)pulseAlpha;
        func_00378280(card, pulseByte & 0xFF);
        func_00410420((struct RxObjSpace3DVertex *)frontVertices, 4, (BtlShuffleMatrix *)m, 3);
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
        func_00410420((struct RxObjSpace3DVertex *)frontVertices, 4, (BtlShuffleMatrix *)m, 3);
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
void func_00375b40(u8 *arg0, s32 arg1, u16 arg2, u16 arg3) {
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
void func_00375e50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4) {
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


/* Reset one shuffle record: reinitialise its motion and rotation objects and
   set their states to 5 and 3. Each state store forms the record address
   again from the byte offset, as integer arithmetic. Those address
   expressions differ from the pointer's in the frontend, so it keeps
   `arg0`/`idx` live in $s1/$s0. b210's post-colouring CSE then turns each
   recomputed `addu` into a copy of the pointer in $s2, as in retail. */
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
// FUN_00375F00
void func_00375f00(u8 *arg0, s32 arg1) {
    s32 idx = arg1 * sizeof(ShuffleRecord);
    ShuffleContext *p = (ShuffleContext *)(arg0 + idx);
    func_00370410((u8 *)&p->records[0].motion);
    ((ShuffleContext *)((u32)arg0 + idx))->records[0].motionState = 5;
    func_00370a80((u8 *)&p->records[0].rotation);
    ((ShuffleContext *)(arg0 + (u32)idx))->records[0].rotationState = 3;
}

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
void func_00376070(u8 *arg0, s32 arg1, u16 arg2, u16 arg3, f32 *arg4, f32 *arg5, f32 fparg0) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_003723a0((u8 *)(arg0 + idx + 0x1D6AC), arg2, arg3, (u8 *)arg4, (u8 *)arg5, fparg0);
    *(s32 *)(p + 0x1D6A4) = 8;
}


// FUN_003760F0
void func_003760f0(u8 *arg0, s32 arg1, u16 arg2, u16 arg3, f32 *arg4, f32 *arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372870((u8 *)(arg0 + idx + 0x1D70C), arg2, arg3, (u8 *)arg4, (ShuffleVec4 *)arg5);
    *(s32 *)(p + 0x1D6A8) = 1;
}


// FUN_00376170
void func_00376170(u8 *arg0, s32 arg1, u16 arg2, u16 arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372c30((u8 *)(arg0 + idx + 0x1D70C), arg2, arg3, (u8 *)arg4, (u8 *)arg5, (u8 *)arg6);
    *(s32 *)(p + 0x1D6A8) = 2;
}


// FUN_003761F0
void func_003761f0(u8 *arg0, s32 arg1, u16 arg2, u16 arg3, const BtlShuffleVec3 *arg4, f32 start, f32 end) {
    ShuffleVec3 v;
    s32 idx;
    u8 *p;

    v = *arg4;
    idx = arg1 * 0xE8;
    p = (u8 *)((u32)idx + (u32)arg0);
    func_003730f0((u8 *)(arg0 + idx + 0x1D70C), arg2, arg3, &v, start, end);
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


/* Guarded trail recovery: native 4176/4176 bytes and frame 0xF50;
 * 511 fully resolved differing words. Uses 21 samples, two 42-vertex
 * strips, native alpha conversions and finite 4/4/2 render passes.
 * Matrix flags are explicitly initialized; retail's SDK identity
 * macro reads an unwritten flag word. ASM remains the production
 * implementation. See docs/probe_archive/Shuffle_trail_003768e0_20261006. */
// FUN_003768E0 NONMATCHING
#ifdef NON_MATCHING
/* Scratch recovery of the three trail styles. The 0x24-byte vertex and
 * position/color setters follow include/rw/sky2/rwcore.h. Matrix flags are
 * defined explicitly: retail's load/OR of an unwritten stack flag word is
 * retained as an unresolved difference, not copied as an uninitialized read. */
typedef struct RwRGBA {
    u8 red, green, blue, alpha;
} TrailRGBA;

typedef union RxColorUnion {
    TrailRGBA preLitColor;
    TrailRGBA color;
} TrailColor;

typedef struct RxObjSpace3DVertex {
    ShuffleVec3 objVertex;
    TrailColor c;
    ShuffleVec3 objNormal;
    f32 u, v;
} TrailVertex;

typedef char TrailVertexSizeCheck[(sizeof(TrailVertex) == 0x24) ? 1 : -1];

#define TRAIL_POSITION(_vertex, _x, _y, _z) do { \
    ShuffleVec3 packed; \
    packed.x = (_x); \
    packed.y = (_y); \
    packed.z = (_z); \
    (_vertex)->objVertex = packed; \
} while (0)

#define TRAIL_COLOR(_vertex, _r, _g, _b, _a) do { \
    TrailRGBA *const color = &(_vertex)->c.color; \
    color->red = (_r); \
    color->green = (_g); \
    color->blue = (_b); \
    color->alpha = (_a); \
} while (0)

extern ShuffleVec3 D_0060A0E0;
extern f32 iGpffff8400;
extern f32 iGpffff8404;
extern f32 iGpffff8408;
extern f32 iGpffff8308;

#pragma push
#pragma opt_loop_invariants on
void func_003768e0(u8 *work, s32 cardIndex, s32 mode, u8 *rgba, f32 length)
{
    TrailVertex first[42];
    TrailVertex second[42];
    ShuffleVec3 samples[21];
    BtlShuffleMatrix identity;
    TrailVertex *front;
    TrailVertex *back;
    ShuffleVec3 *sample;
    u8 *card;
    u8 *motion;
    s32 kind;
    f32 opacity;

    kind = (s8)mode;
    if (kind >= 3) {
        func_0046d730(D_0064EA20, 0x5DE);
    }
    identity.right.x = identity.up.y = identity.at.z = 1.0f;
    identity.right.y = identity.right.z = identity.up.x = 0.0f;
    identity.up.z = identity.at.x = identity.at.y = 0.0f;
    identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
    identity.flags = 0x20003;
    RpSkyRenderStateSet(2, (void *)0x48);
    RpSkyRenderStateSet(3, (void *)0x71801);
    D_00887300[0](rwRENDERSTATECULLMODE, (void *)1);
    D_00887300[0](rwRENDERSTATEZTESTENABLE, (void *)1);
    D_00887300[0](rwRENDERSTATEZWRITEENABLE, NULL);
    motion = work + cardIndex * 0xE8 + 0x1D6A0;
    card = work + cardIndex * 0xFB0;
    if (*(s32 *)(motion + 4) == 6) {
        opacity = (f32)(u32)rgba[3] * ((f32)(u32)motion[0xD8] / 255.0f);
        switch (kind) {
        case 0:
            {
                s32 point;
                s32 side;
                f32 fadedOpacity;
                f32 taper;
                f32 time;
                f32 halfWidth;
                f32 halfHeight;
                front = first;
                back = second;
                fadedOpacity = iGpffff8400 * opacity;
                taper = 1.0f;
                time = 0.0f;
                length /= 21.0f;
                for (point = 0; point < 21; point++) {
                    func_003764b0(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= length;
                    TRAIL_COLOR(&front[0], rgba[0], rgba[1], rgba[2], (u8)(opacity * taper));
                    TRAIL_COLOR(&front[1], rgba[0], rgba[1], rgba[2], (u8)(fadedOpacity * taper));
                    TRAIL_COLOR(&back[0], rgba[0], rgba[1], rgba[2], (u8)(fadedOpacity * taper));
                    TRAIL_COLOR(&back[1], rgba[0], rgba[1], rgba[2], (u8)(opacity * taper));
                    taper += iGpffff8404;
                    front += 2;
                    back += 2;
                }
                halfWidth = 0.5f * func_0036de70(card);
                halfHeight = 0.5f * func_0036deb0(card);
                for (side = 0; side < 4; side++) {
                    front = first;
                    back = second;
                    switch (side) {
                    case 0:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], halfWidth + sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front[1], halfWidth + sample->x, sample->y, sample->z);
                            TRAIL_POSITION(&back[0], halfWidth + sample->x, sample->y, sample->z);
                            TRAIL_POSITION(&back[1], halfWidth + sample->x, halfHeight + sample->y, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    case 1:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], sample->x - halfWidth, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front[1], sample->x - halfWidth, sample->y, sample->z);
                            TRAIL_POSITION(&back[0], sample->x - halfWidth, sample->y, sample->z);
                            TRAIL_POSITION(&back[1], sample->x - halfWidth, halfHeight + sample->y, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    case 2:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], halfWidth + sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&front[1], sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&back[0], sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&back[1], sample->x - halfWidth, halfHeight + sample->y, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    case 3:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], halfWidth + sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front[1], sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&back[0], sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&back[1], sample->x - halfWidth, sample->y - halfHeight, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
                break;
            }
        case 1:
            {
                s32 point;
                s32 side;
                f32 taper;
                f32 time;
                f32 halfWidth;
                f32 halfHeight;
                f32 x;
                f32 y;
                f32 z;
                f32 offsetX;
                f32 offsetY;
                u8 alpha;
                f32 negativeWidth;
                f32 negativeHeight;
                front = first;
                back = second;
                alpha = (u8)opacity;
                time = 0.0f;
                length /= 21.0f;
                for (point = 0; point < 21; point++) {
                    func_003764b0(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= length;
                    TRAIL_COLOR(&front[0], rgba[0], rgba[1], rgba[2], 0);
                    TRAIL_COLOR(&front[1], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[0], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[1], rgba[0], rgba[1], rgba[2], 0);
                    front += 2;
                    back += 2;
                }
                halfWidth = 0.5f * func_0036de70(card);
                halfHeight = 0.5f * func_0036deb0(card);
                side = 0;
                negativeWidth = -halfWidth;
                negativeHeight = -halfHeight;
                for (; side < 4; side++) {
                    switch (side) {
                    case 0: offsetX = halfWidth; offsetY = halfHeight; break;
                    case 1: offsetX = negativeWidth; offsetY = halfHeight; break;
                    case 2: offsetX = halfWidth; offsetY = negativeHeight; break;
                    case 3: offsetX = negativeWidth; offsetY = negativeHeight; break;
                    }
                    front = first;
                    back = second;
                    taper = 1.0f;
                    for (point = 0; point < 21; point++) {
                        f32 magnitude = 3.0f * taper;
                        f32 dx = D_0060A0E0.x * magnitude;
                        f32 dy = D_0060A0E0.y * magnitude;
                        f32 dz = D_0060A0E0.z * magnitude;
                        sample = &samples[point];
                        x = sample->x;
                        y = sample->y;
                        z = sample->z;
                        TRAIL_POSITION(&front[0], dx + x + offsetX, dy + y + offsetY, dz + z);
                        TRAIL_POSITION(&front[1], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[0], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[1], x - dx + offsetX, y - dy + offsetY, z - dz);
                        taper += iGpffff8404;
                        front += 2;
                        back += 2;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
            }
            break;
        case 2:
            {
                s32 point;
                s32 side;
                f32 taper;
                f32 time;
                f32 halfWidth;
                f32 halfHeight;
                f32 x;
                f32 y;
                f32 z;
                f32 offsetX;
                f32 offsetY;
                u8 alpha;
                f32 right;
                f32 left;
                f32 height;
                func_003e9700(*(struct RwFrame **)((u8 *)func_00457120() + 4));
                front = first;
                back = second;
                alpha = (u8)opacity;
                time = 0.0f;
                length /= 21.0f;
                for (point = 0; point < 21; point++) {
                    func_003764b0(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= length;
                    TRAIL_COLOR(&front[0], rgba[0], rgba[1], rgba[2], 0);
                    TRAIL_COLOR(&front[1], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[0], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[1], rgba[0], rgba[1], rgba[2], 0);
                    front += 2;
                    back += 2;
                }
                halfWidth = 0.5f * func_0036de70(card);
                halfHeight = 0.5f * func_0036deb0(card);
                side = 0;
                right = iGpffff8218 * halfWidth;
                height = iGpffff8308 * halfHeight;
                left = iGpffff8218 * -halfWidth;
                for (; side < 2; side++) {
                    switch (side) {
                    case 0: offsetX = right; offsetY = height; break;
                    case 1: offsetX = left; offsetY = height; break;
                    }
                    front = first;
                    back = second;
                    taper = 1.0f;
                    for (point = 0; point < 21; point++) {
                        f32 magnitude = iGpffff8408 * taper;
                        f32 dx = D_0060A0E0.x * magnitude;
                        f32 dy = D_0060A0E0.y * magnitude;
                        f32 dz = D_0060A0E0.z * magnitude;
                        sample = &samples[point];
                        x = sample->x;
                        y = sample->y;
                        z = sample->z;
                        TRAIL_POSITION(&front[0], dx + x + offsetX, dy + y + offsetY, dz + z);
                        TRAIL_POSITION(&front[1], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[0], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[1], x - dx + offsetX, y - dy + offsetY, z - dz);
                        taper += iGpffff8404;
                        front += 2;
                        back += 2;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
            }
            break;
        }
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
    }
}
#pragma pop
#undef TRAIL_COLOR
#undef TRAIL_POSITION


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
