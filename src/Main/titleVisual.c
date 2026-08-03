#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit titleVisual.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_0044ea90(const void *file, s32 line);
extern u8 *func_00460990();
extern void func_00460ac0(void *arg0, void *arg1);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0063EE50[];
extern void func_002aabf0(void *arg0, void *arg1);
extern void func_002ab550(u8 *arg0, s8 *arg1);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void (*D_00887300[])(u32 state, u32 value);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern void func_0047a220(void *arg0, void *arg1);
extern void func_0047a260(void *arg0);
extern void func_004789c0(void *arg0);
extern void func_0047a320(void *arg0);
extern void func_00479910(void *arg0);
extern void func_0025f3f0(s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_001102f0(void *arg0, s32 arg1, s32 arg2, f32 fparg0);
extern void *func_00457120(void);
extern u8 *func_003e9700(s32 arg0);
extern void func_003e40b0(void *a, void *b);
extern void func_003e05d0(void *arg0);
extern void func_003e0a90(void *a0, void *a1, s32 a2);
extern void func_003e05f0(void *a, void *b, void *c);
extern void func_003e0c90(void *dst, void *src, s32 mode);
extern void *func_0047a2f0(u32 arg0);
extern void func_002ab0e0(u8 *arg0, u8 *arg1);
extern void func_002ab4b0(void *arg0, u8 *arg1);

typedef struct { f32 v0, v1, v2, v3; } Float4;
typedef struct { u8 b0, b1, b2, b3; } Byte4;
typedef signed __int128 s128;

// FUN_002AAF20
void func_002aaf20(f32 fparg0, f32 fparg1, f32 fparg2, u8 *arg0, f32 fparg3, f32 fparg4, s32 arg1, void *arg2) {
    f32 sp70[4];
    u8 *var_3;
    s32 var_2;
    u8 *temp_16;
    u8 *temp_2;

    func_0044ea90(D_0063EE50, 0x91);
    temp_16 = D_008873F4[0](1, 0x1C, 0x40000);
    var_3 = (u8 *)&sp70[0];
    var_2 = 0x10;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3 += 1;
            var_2 -= 1;
        } while (var_2 != 0);
    }
    *(s32 *)&sp70[0] = (s32)fparg0;
    *(s32 *)&sp70[1] = (s32)fparg1;
    *(s32 *)&sp70[2] = (s32)(fparg0 + fparg3);
    *(s32 *)&sp70[3] = (s32)(fparg1 + fparg4);
    *(Float4 *)(temp_16 + 0) = *(Float4 *)&sp70[0];
    *(f32 *)(temp_16 + 0x10) = fparg2;
    *(Byte4 *)(temp_16 + 0x14) = *(Byte4 *)arg0;
    *(s32 *)(temp_16 + 0x18) = arg1;
    if (arg2 != NULL) {
        temp_2 = func_00460990();
        *(void **)(temp_2 + 8) = (void *)func_002aabf0;
        *(u8 **)(temp_2 + 0x10) = temp_16;
        func_00460ac0(arg2, temp_2);
    } else {
        func_002aabf0(NULL, temp_16);
    }
}

/* measured: retail hoists &D_00887300[0] into $s0 (lui+addiu once) and per
   call emits args then lw $v0,0($s0) -- 13 call sites; mwcc b210
   rematerializes lui+lw per call (nd 151, frame -0x60 vs -0x70). Same
   D_00887300 render-vtable hoist floor as func_002ab550 in this file. */
// FUN_002AB0E0
INCLUDE_ASM("asm/nonmatchings/titleVisual", func_002ab0e0);

// FUN_002AB380
void func_002ab380(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    u8 *temp_2;
    u8 *temp_2_2;

    func_0044ea90(D_0063EE50, 0xE1);
    temp_2 = D_008873F4[0](1, 0x1C, 0x40000);
    *(f32 *)(temp_2 + 0) = fparg0;
    *(f32 *)(temp_2 + 4) = fparg1;
    *(f32 *)(temp_2 + 8) = fparg2;
    *(s32 *)(temp_2 + 0xC) = (arg0 << 8) | arg1;
    *(s32 *)(temp_2 + 0x10) = arg4;
    *(s32 *)(temp_2 + 0x14) = arg3;
    *(s32 *)(temp_2 + 0x18) = arg2;
    if (arg5 != NULL) {
        temp_2_2 = func_00460990();
        *(void **)(temp_2_2 + 8) = (void *)func_002ab0e0;
        *(u8 **)(temp_2_2 + 0x10) = temp_2;
        func_00460ac0(arg5, temp_2_2);
        return;
    }
    func_002ab0e0(NULL, temp_2);
}

// FUN_002AB4B0
void func_002ab4b0(void *arg0, u8 *arg1) {
    s8 sp4C[4];
    u8 *temp_18;
    s32 temp_17;
    u32 temp_3;

    temp_3 = *(u32 *)arg1;
    sp4C[0] = (s8)(temp_3 >> 24);
    sp4C[1] = (s8)(temp_3 >> 16);
    sp4C[2] = (s8)(temp_3 >> 8);
    sp4C[3] = (s8)temp_3;
    temp_18 = *(u8 **)(arg1 + 0x54);
    temp_17 = *(s32 *)(temp_18 + 0xD8);
    *(s32 *)(temp_18 + 0xD8) = *(s32 *)(arg1 + 0x50);
    func_0047a1c0(temp_18, arg1 + 0x10, 0);
    func_002ab550(temp_18, sp4C);
    *(s32 *)(temp_18 + 0xD8) = temp_17;
    jtbl_008873EC[0](arg1);
}

/* measured: retail hoists &D_00887300[0] into $s0 (lui+addiu once) and per
   call emits the args then lw $v0,0($s0); mwcc b210 rematerializes lui+lw
   per call before the args -- 14 call sites (nd 128 for D_00887300[0](),
   128 for (*D_00887300)(), 126 for a cached local table pointer). Same
   D_00887300 render-vtable hoist floor as mainDraw.c func_001015c0. */
// FUN_002AB550
INCLUDE_ASM("asm/nonmatchings/titleVisual", func_002ab550);

// FUN_002AB790
void func_002ab790(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, f32 fparg3, s32 arg2, u8 *arg3, void *arg4) {
    s8 sp14C[4];
    f32 sp140[3];
    f32 sp130[3];
    f32 sp120[3];
    f32 spE0[16];
    f32 spA0[16];
    void *temp_ret;
    s32 v17;
    s32 v16;
    u8 *var_2;
    u8 *var_6;
    s32 var_5;
    s128 *var_5_2;
    s128 *var_4;
    s32 var_3;
    u8 *temp_2_2;
    u8 *temp_2_4;
    s32 temp_17;
    u8 *temp_18;
    u32 temp_3_4;
    u8 *var_2_2;
    s32 temp_4;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_2_3;
    s32 temp_4_2;
    s32 temp_3_3;
    s128 temp_2;
    u8 *var_6_2;
    u8 *var_5_3;
    s32 var_4_2;
    u8 *var_6_3;
    s32 var_5_4;

    temp_ret = func_0047a2f0((u32)(s32)arg3);
    v17 = (s32)fparg1;
    v16 = (s32)fparg0;
    func_001102f0(sp120, v16, v17, fparg2);
    var_2 = func_003e9700(*(s32 *)((u8 *)func_00457120() + 4));
    var_6 = (u8 *)spE0;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_2 + 0);
        temp_3 = *(s32 *)(var_2 + 4);
        var_2 += 8;
        var_5 -= 1;
        *(s32 *)(var_6 + 0) = temp_4;
        *(s32 *)(var_6 + 4) = temp_3;
        var_6 += 8;
    } while (var_5 > 0);
    spE0[8] = sp120[0] - spE0[12];
    spE0[9] = sp120[1] - spE0[13];
    spE0[10] = sp120[2] - spE0[14];
    func_003e40b0(&spE0[8], &spE0[8]);
    spE0[12] -= spE0[12];
    spE0[13] -= spE0[13];
    spE0[14] -= spE0[14];
    func_003e05d0(spE0);
    sp130[2] = fparg3;
    sp130[1] = fparg3;
    sp130[0] = fparg3;
    func_003e0a90(spE0, sp130, 0);
    func_003e05f0(spA0, spE0, temp_ret);
    var_5_2 = (s128 *)spA0;
    var_4 = (s128 *)spE0;
    var_3 = 4;
    do {
        temp_2 = *var_5_2;
        var_5_2 += 1;
        var_3 -= 1;
        *var_4 = temp_2;
        var_4 += 1;
    } while (var_3 > 0);
    if (arg2 != 0) {
        func_001102f0(sp140, v16, v17, fparg2);
    } else {
        sp140[0] = fparg0;
        sp140[1] = fparg1;
        sp140[2] = fparg2;
    }
    func_003e0c90(spE0, sp140, 2);
    func_0044ea90(D_0063EE50, 0x16B);
    temp_2_2 = D_008873F4[0](1, 0x60, 0x40000);
    *(u32 *)(temp_2_2 + 0) = (arg0 << 8) | arg1;
    *(s32 *)(temp_2_2 + 0x50) = *(s32 *)(arg3 + 0xD8);
    var_6_2 = (u8 *)spE0;
    var_5_3 = temp_2_2 + 0x10;
    var_4_2 = 8;
    do {
        temp_3_2 = *(s32 *)(var_6_2 + 0);
        temp_2_3 = *(s32 *)(var_6_2 + 4);
        var_6_2 += 8;
        var_4_2 -= 1;
        *(s32 *)(var_5_3 + 0) = temp_3_2;
        *(s32 *)(var_5_3 + 4) = temp_2_3;
        var_5_3 += 8;
    } while (var_4_2 > 0);
    *(u8 **)(temp_2_2 + 0x54) = arg3;
    if (arg4 != NULL) {
        temp_2_4 = func_00460990();
        *(void **)(temp_2_4 + 8) = (void *)func_002ab4b0;
        *(u8 **)(temp_2_4 + 0x10) = temp_2_2;
        func_00460ac0(arg4, temp_2_4);
    } else {
        var_2_2 = func_0047a2f0((u32)(s32)arg3);
        var_6_3 = (u8 *)spE0;
        var_5_4 = 8;
        do {
            temp_4_2 = *(s32 *)(var_2_2 + 0);
            temp_3_3 = *(s32 *)(var_2_2 + 4);
            var_2_2 += 8;
            var_5_4 -= 1;
            *(s32 *)(var_6_3 + 0) = temp_4_2;
            *(s32 *)(var_6_3 + 4) = temp_3_3;
            var_6_3 += 8;
        } while (var_5_4 > 0);
        temp_3_4 = *(u32 *)(temp_2_2 + 0);
        sp14C[0] = (s8)(temp_3_4 >> 24);
        sp14C[1] = (s8)(temp_3_4 >> 16);
        sp14C[2] = (s8)(temp_3_4 >> 8);
        sp14C[3] = (s8)temp_3_4;
        temp_18 = *(u8 **)(temp_2_2 + 0x54);
        temp_17 = *(s32 *)(temp_18 + 0xD8);
        *(s32 *)(temp_18 + 0xD8) = *(s32 *)(temp_2_2 + 0x50);
        func_0047a1c0(temp_18, temp_2_2 + 0x10, 0);
        func_002ab550(temp_18, sp14C);
        *(s32 *)(temp_18 + 0xD8) = temp_17;
        jtbl_008873EC[0](temp_2_2);
        func_0047a1c0(arg3, spE0, 0);
    }
}

/* measured: retail hoists &D_008873F4[0] into $s0 right after the first
   assert (3 alloc calls, each lw $v0,0($s0)); mwcc b210 never reproduces
   that placement: a declaration initializer materializes the base at
   function entry (nd 19, 2-word shift), an assignment at the right spot
   makes the FIRST alloc call re-derive lui+lw (nd 211, 1-word cascade).
   Same constant-address base-materialization family as the D_00887300
   render-vtable hoist floor. */
// FUN_002ABB30
INCLUDE_ASM("asm/nonmatchings/titleVisual", func_002abb30);
