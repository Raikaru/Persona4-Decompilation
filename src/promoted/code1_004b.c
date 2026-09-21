#include "include_asm.h"
#include "type.h"
#include "effect_update_internal.h"
extern u8 *func_00457120(void);
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);
extern void func_00484bb0();
extern void func_00485b20();
extern void func_00485fe0();
extern void func_00485630(u8 *object);
extern u8 *func_00485c80(u8 *arg0);
extern void func_00486400();
extern void func_00486060();
extern void func_004860f0();
extern void func_00486180();


extern void func_004b0ce0();
extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern void func_004a7c00(u8 *arg0, s32 arg1);
extern void func_004a7a50(void);
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
extern void func_00492dd0(u8 *arg0);
extern void func_00492e10(u8 *arg0);
extern void func_00492e30(u8 *arg0);
extern void func_00481440(void *arg0);
extern void func_00485870(void *arg0);
extern void func_00485ae0(void *arg0);
extern void func_004861f0(void *arg0, f32 *arg1);
extern void func_004b1ad0(u8 *arg0);
extern void func_004b4cb0(u16 arg0, s32 arg1);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;
extern void func_004b36b0(void);
extern void func_003efd20(u8 *arg0, s32 arg1);
extern void func_003e9390(s32 arg0);
extern void func_003ec330(s32 arg0);
extern void func_0040fcd0(s32 arg0, s32 arg1);
extern void func_003e8440(u8 *arg0);
extern u8 *func_004b16c0(u8 *arg0);
extern u8 *func_00483270(s32 arg0);
extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
extern void func_004b1a00(u8 *arg0, u8 *arg1);
extern s32 func_00481e30(s32 arg0);
extern void func_00481ee0(s32 arg0);
extern void func_004829c0(s32 arg0);
extern s32 func_00482a70(s32 arg0);

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */



extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern void func_004866e0(u8 *arg0, u32 *arg1);
extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *arg0, s32 arg1);
extern void func_004bd9f8(u8 *arg0);
extern void func_00486330(s32 arg0, void *arg1);
extern void func_004bcf20(f32 arg0, f32 arg1, f32 arg2);
extern f32 iGpffff836c;
extern void func_004866f0(u8 *arg0, u32 *arg1);
extern void func_0048a150(void *arg0, void *arg1);
extern void func_0048a980(f32 *arg0);
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void func_0044ea90(void *arg0, s32 arg1);
extern void func_0046d730(void *arg0, s32 arg1);
extern void *(*jtbl_008873E8[])(u32 arg0, u32 arg1);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern u8 *func_00484490(u8 *arg0);
extern u16 *func_004844d0(u8 *arg0);
extern u16 *func_00482f70(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
extern void func_00483970(u8 *arg0, u16 *arg1);
extern s32 func_00481d80(u16 *arg0);
extern s32 func_00481300(u16 arg0);
extern void func_003c42b0(s32 arg0, s32 arg1);
extern s32 func_00482800(u16 *arg0);
extern void func_003e8110(u8 *arg0);
extern s32 func_003e8120(u8 *arg0);
extern void func_003f6440(s32 arg0, s32 arg1);
extern u8 *func_00401b80(void);
extern u8 D_008872FC_abs[];
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern s32 (*D_00887310_abs[])(s32 arg0, void *arg1, s32 arg2);

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

// FUN_004B0F70
void func_004b0f70(void *object) {
    func_004b0ce0(object, 0);
}


extern void func_004b0ce0();


// FUN_004B0FA0
void func_004b0fa0(void *object) {
    func_004b0ce0(object, 1);
}


extern void func_004865c0(u8 *arg0, s32 arg1);


// FUN_004B0FD0
void func_004b0fd0(u8 *arg0)
{
    u8 *node;
    u8 *inner;

    node = *(u8 **)(arg0 + 0x5C);
    if (node != NULL) {
        inner = *(u8 **)(node + 0x20);
        *(s32 *)(arg0 + 0x6C) = 0;
        *(s32 *)(arg0 + 0x70) = 0;
        func_00460ac0(func_00481460(*(u16 *)(inner + 0x54)), arg0 + 0x6C);
    }
}

// FUN_004B1030
void func_004b1030(u8 *arg0)
{
    u8 *node;
    u8 *inner;

    func_004b0a80();
    node = *(u8 **)(arg0 + 0x5C);
    if (node != NULL) {
        inner = *(u8 **)(node + 0x20);
        *(s32 *)(arg0 + 0x6C) = 0;
        *(s32 *)(arg0 + 0x70) = 0;
        func_00460ac0(func_00481460(*(u16 *)(inner + 0x54)), arg0 + 0x6C);
    }
}

// FUN_004B1090
void func_004b1090(u8 *arg0)
{
    func_00492dd0(*(u8 **)(arg0 + 0x5c));
}
// FUN_004B10C0
void func_004b10c0(u8 *arg0)
{
    func_00492e10(*(u8 **)(arg0 + 0x5c));
}
// FUN_004B10F0
void func_004b10f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x4) = arg1;
}
// FUN_004B1100
void func_004b1100(u8 *arg0, f32 arg1)
{
    *(f32 *)(arg0 + 8) = arg1;
    func_00492e30(*(u8 **)(arg0 + 0x5c));
}
// FUN_004B1130
void func_004b1130(void)
{
    func_00484bb0();
}

// FUN_004B1150
void func_004b1150(void)
{
    func_00485b20();
}

// FUN_004B1170
void func_004b1170(void)
{
    func_00485fe0();
}

// FUN_004B1190
void func_004b1190(u8 *object)
{
    func_00485630(object);
}

// FUN_004B11B0
s32 func_004b11b0(s32 arg0)
{
    return (s32)(u32)func_00485c80((u8 *)arg0);
}

// FUN_004B11D0
void func_004b11d0(void *arg0, void *arg1)
{
    if (arg0 != NULL) {
        func_00481440(arg0);
    }
    func_00485870(arg1);
}
// FUN_004B1210
void func_004b1210(void *arg0, void *arg1)
{
    if (arg0 != NULL) {
        func_00481440(arg0);
    }
    func_00485ae0(arg1);
}
// FUN_004B1250
void func_004b1250(void *arg0, f32 *arg1)
{
    f32 work[4];

    work[0] = arg1[0];
    work[1] = arg1[1];
    work[2] = arg1[2];
    work[3] = 0.0f;
    func_004861f0(arg0, work);
}
// FUN_004B1290
void func_004b1290(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    u8 scratch[16];

    func_004bcf20(iGpffff836c * arg1, iGpffff836c * arg2, iGpffff836c * arg3);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(scratch) : "memory");
    func_00486330(arg0, scratch);
}

// FUN_004B12E0
void func_004b12e0(s32 arg0, u8 *arg1) {
    struct {
        f32 first[4];
        u8 result[16];
        f32 values[16];
    } work;

    work.first[0] = *(f32 *)(arg1 + 0x30);
    work.first[1] = *(f32 *)(arg1 + 0x34);
    work.first[2] = *(f32 *)(arg1 + 0x38);
    work.first[3] = 0.0f;
    func_004861f0((void *)arg0, work.first);
    work.values[0] = *(f32 *)(arg1 + 0);
    work.values[1] = *(f32 *)(arg1 + 4);
    work.values[2] = *(f32 *)(arg1 + 8);
    work.values[3] = 0.0f;
    work.values[4] = *(f32 *)(arg1 + 0x10);
    work.values[5] = *(f32 *)(arg1 + 0x14);
    work.values[6] = *(f32 *)(arg1 + 0x18);
    work.values[7] = 0.0f;
    work.values[8] = *(f32 *)(arg1 + 0x20);
    work.values[9] = *(f32 *)(arg1 + 0x24);
    work.values[10] = *(f32 *)(arg1 + 0x28);
    work.values[11] = 0.0f;
    work.values[12] = *(f32 *)(arg1 + 0x30);
    work.values[13] = *(f32 *)(arg1 + 0x34);
    work.values[14] = *(f32 *)(arg1 + 0x38);
    work.values[15] = 0.0f;
    func_0048a980(work.values);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(work.result) : "memory");
    func_00486330(arg0, work.result);
}
// FUN_004B13D0
void func_004b13d0(void)
{
    func_00486400();
}

// FUN_004B13F0
void func_004b13f0(void *object, s32 *arg1) {
    func_004865c0(object, *arg1);
}


extern u32 func_00486700(void *object);


// FUN_004B1420
void func_004b1420(u8 *arg0, f32 *arg1) {
    f32 sp20[4];

    func_004866e0(arg0, (u32 *)sp20);
    arg1[0] = sp20[0];
    arg1[1] = sp20[1];
    arg1[2] = sp20[2];
}

// FUN_004B1470
void func_004b1470(u8 *arg0, u8 *arg1)
{
    struct {
        f32 projected[3];
        u32 alignment;
        u8 vector[16];
    } scratch;

    func_004866f0(arg0, (u32 *)scratch.vector);
    func_0048a150(arg1, scratch.vector);
    func_004866e0(arg0, (u32 *)scratch.projected);
    *(f32 *)(arg1 + 0x30) = scratch.projected[0];
    *(f32 *)(arg1 + 0x34) = scratch.projected[1];
    *(f32 *)(arg1 + 0x38) = scratch.projected[2];
}

// FUN_004B14F0
void func_004b14f0(void *object, s32 *arg1) {
    *arg1 = func_00486700(object);
}


typedef signed __int128 s128;


// FUN_004B1520
void func_004b1520(void)
{
    func_00486060();
}

// FUN_004B1540
void func_004b1540(void)
{
    func_004860f0();
}

// FUN_004B1560
void func_004b1560(void)
{
    func_00486180();
}

// FUN_004B1590
void func_004b1590(s32 arg0, s16 arg1)
{
    D_00922DA0[0] = arg0;
    D_00922DA4[0] = arg1;
    D_00922DA8[0] = 0;
    D_00922DAC[0] = 0;
    iGpffffbb94 = 0;
    iGpffffbb98 = 1;
}
// FUN_004B15D0
void func_004b15d0(void)
{
    func_004a7a50();
    iGpffffbb98 = 0;
}
// FUN_004B1600
void func_004b1600(void)
{
    s32 temp_5;
    s32 limit;

    if (iGpffffbb98 != 0) {
        limit = D_00922DA0[0];
        if ((iGpffffbb94 < limit) || (limit == 0)) {
            temp_5 = iGpffffbb94;
            func_004a7c00((u8 *)&D_00922DA0[0], temp_5);
        } else {
            func_004a7a50();
            iGpffffbb98 = 0;
        }
        iGpffffbb94 = iGpffffbb94 + 1;
    }
}
// FUN_004B1680
void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3)
{
    D_00922DA0[0] = arg0;
    D_00922DA4[0] = arg1;
    D_00922DA8[0] = arg2;
    D_00922DAC[0] = arg3;
    iGpffffbb94 = 0;
    iGpffffbb98 = 1;
}
// FUN_004B16C0
u8 *func_004b16c0(u8 *arg0) {
    u16 *temp_2_3;
    u16 *temp_2_4;
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;

    func_0044ea90(&iGpffffb118, 0x1A);
    temp_2 = (u8 *)jtbl_008873E8[0](0xB0, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&iGpffffb118, 0x1B);
    }
    func_0043f9c8(temp_2, 0, 0xB0);
    *(s32 *)(temp_2 + 0) = -1;
    if (arg0 == NULL) {
        return temp_2;
    }
    *(s32 *)(temp_2 + 4) = *(u16 *)(arg0 + 0xC);
    temp_2_2 = func_00484490(arg0);
    if (temp_2_2 == NULL) {
        func_0046d730(&iGpffffb118, 0x2C);
    }
    func_0043f810(temp_2 + 0xC, temp_2_2, 0x98);
    temp_2_3 = func_00482f70(1, 2, 4, D_00713408, 0x4C);
    *(u16 **)(temp_2 + 0xA4) = temp_2_3;
    *temp_2_3 = *temp_2_3 & 0xFFFB;
    temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0xA4) + 0x10) + 0x18);
    temp_3 = *(u8 **)(temp_3 + 0x30);
    *(s32 *)(temp_3 + 0) = -1;
    *(s32 *)(temp_3 + 4) = -1;
    *(s32 *)(temp_3 + 8) = -1;
    *(s32 *)(temp_3 + 0xC) = -1;
    temp_2_4 = func_004844d0(arg0);
    if (temp_2_4 != NULL) {
        temp_4 = *(u16 *)(arg0 + 0x1C);
        switch (temp_4) {
        case 1:
            func_00483970(*(u8 **)(temp_2 + 0xA4), temp_2_4);
            break;
        case 2:
            *(s32 *)(temp_2 + 0xAC) = func_00481d80(temp_2_4);
            break;
        case 4:
            func_003c42b0(*(s32 *)(*(u8 **)(temp_2 + 0xA4) + 0x14),
                          func_00481300(*temp_2_4));
            break;
        case 7:
            *(s32 *)(temp_2 + 0xA8) = func_00482800(temp_2_4);
            break;
        default:
            func_0046d730(&iGpffffb118, 0x5C);
            break;
        }
    }
    return temp_2;
}
// FUN_004B18E0
void func_004b18e0(u8 *arg0)
{
    s32 h;

    h = *(s32 *)(arg0 + 0xA8);
    if (h != 0) {
        func_004829c0(h);
    }
    h = *(s32 *)(arg0 + 0xAC);
    if (h != 0) {
        func_00481ee0(h);
    }
    func_004833f0(*(s32 *)(arg0 + 0xA4));
    (*jtbl_008873EC)(arg0);
}

// FUN_004B1950
u8 *func_004b1950(u8 *arg0) {
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;

    temp_2 = func_004b16c0(NULL);
    *(s32 *)(temp_2 + 4) = *(s32 *)(arg0 + 4);
    func_0043f810(temp_2 + 0xC, arg0 + 0xC, 0x98);
    temp_4 = *(s32 *)(arg0 + 0xA4);
    if (temp_4 != 0) {
        temp_2_2 = func_00483270(temp_4);
        *(u8 **)(temp_2 + 0xA4) = temp_2_2;
        temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2_2 + 0x10) + 0x18) + 0x30);
        *(s32 *)(temp_3 + 0) = -1;
        *(s32 *)(temp_3 + 4) = -1;
        *(s32 *)(temp_3 + 8) = -1;
        *(s32 *)(temp_3 + 0xC) = -1;
    }
    func_004b1a00(temp_2, arg0);
    return temp_2;
}
// FUN_004B1A00
void func_004b1a00(u8 *arg0, u8 *arg1) {
    s32 temp_4;
    s32 temp_4_2;

    if (*(s32 *)(arg1 + 0xAC) != 0) {
        temp_4 = *(s32 *)(arg0 + 0xAC);
        if (temp_4 != 0) {
            func_00481ee0(temp_4);
        }
        *(s32 *)(arg0 + 0xAC) = func_00481e30(*(s32 *)(arg1 + 0xAC));
        return;
    }
    if (*(s32 *)(arg1 + 0xA8) != 0) {
        temp_4_2 = *(s32 *)(arg0 + 0xA8);
        if (temp_4_2 != 0) {
            func_004829c0(temp_4_2);
        }
        *(s32 *)(arg0 + 0xA8) = func_00482a70(*(s32 *)(arg1 + 0xA8));
    }
}
// FUN_004B1AA0
void func_004b1aa0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x8) = 0;
}

// FUN_004B1AB0
void func_004b1ab0(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 8) + 1;
}
/* Widths are mixed here on purpose, not a tuning knob: stk80 is `s32` and */
/* stk84 stays `u32` (D0/CC casts). Both-`s32` overshoots to 768, just below */
/* the lower band edge, while the single-`s32`/single-`u32` mix lands at 802 */
/* (retail 796). Retail's widths really are mixed; do not "fix" the odd one. */
/* 2026-09-19 run table (Main request): sched 802/796 (+6), 763w probe / 782w floor, 1044e. */
/* O3 alone measured 799/796 (+3), 760w, 1038e (-3/-3/-6) but REVERTED per Main: */
/* nonbaseline level for the whole function needs more than a six-edit scheduling */
/* move; restored sched to keep the tree comparable. Singles banked 763: O3/O4 760. */
/* Largest asymmetric pair (no relocation signature): delete retail 372:509 (137: */
/* nop/cvt/sra/mtc1/cvt/swc1/lui/c.ole/bc1t/cvt/mfc1/b/sub/cvt/mfc1/lui/or/sw + */
/* c.ole UV clamp + lw/jal/b chain, see fnalign) vs insert object 611:647 (36) and */
/* 93:123 (30: srl/andi/or/mtc1/cvt + sw/lw VU pack chain). Retail keeps 137 clamped */
/* stores + call; object keeps 36+30 pack/conversion instead. No inverted-arm pair */
/* like 00137890 (384->106) or else-move like 003c1bd0 here; recorded so nobody re-runs. */
/* Mixed widths kept (s32 stk80 / u32 stk84); do not re-flip. Floor stands; stays ASM. */
/* gate: func_004b1ad0 is OUTSIDE the +-3% band at 909 against retail 796 (+14.2%).  The body previously read
   802/796, 1044 edits only because `#pragma schedule on` was filling delay slots that retail leaves
   empty.  Retail's first-party build is entirely unscheduled: across 212 byte-exact MATCH
   first-party functions there are 2909 branches and **zero** filled delay slots, and this
   function's own retail window has 76 branches with 76 empty slots and none filled.  The
   pragma therefore never reproduced retail codegen - it deleted nops to shrink the count, and
   it was hiding a genuine instruction surplus.  It is removed; the surplus is now visible and
   has to be written out of the body.  Any differing-word score measured with the pragma in
   place is not comparable to one measured inside the gate (handoff 7y, 7au). */
/* measured: 2026-09-20 second-branch signedness fix (spA0 u16s (u16)->(s16), stk78/7c (u32)->(s32)): obj 3192B/window 3184B (798/796 +0.3% INSIDE, was 909/796 +14.2%), 705wd (was 845). Micro: (u16)(float*16) store 24w with clamp vs (s16) 9w without (retail has no clamp there); (f32)(u32)>>5 unsigned 47w vs (s32) signed 24w (retail uses sra+cvt.s.w). No bare doubles (all floats suffixed). Stays ASM. */
// FUN_004B1AD0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
void func_004b1ad0(u8 *arg0)
{
    extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
    extern f32 func_0048aff0(u8 *a, s32 b, s32 c);
    extern void func_00482730(int a, u32 b);
    extern void func_00482700(int a, float *b);
    extern void func_00482ad0(u8 *a, s32 b, u8 *c);
    extern void func_004839d0(int a, u32 *b);
    extern u8 *func_003c2290(u8 *a, s32 b);
    extern void func_003c22f0(u8 *a);
    extern void func_003e9cb0(void *a, void *b, s32 c);
    extern void func_00460ac0(void *a, void *b);
    extern s32 func_004814d0(u16 a);
    extern u8 *func_00457120(void);
    extern f32 func_0044b610(f32 a);
    extern f32 func_0044b7b0(f32 a);
    extern f32 fGpffff8044;
    extern f32 fGpffff8084;
    s32 tmp_98;
    s32 tmp_08;
    u8 *tmp_a4;
    s32 tmp_abd0;
    u32 packed0;
    u32 packed1;
    u8 *dst_ptr;
    f32 scale;
    f32 div100;
    f32 off_y;
    s32 tmp_ac;
    s32 tmp_a8;
    f32 stk70;
    f32 stk74;
    f32 stk78;
    f32 stk7c;
    s32 stk80;
    u32 stk84;
    u16 stk88;
    u16 stk8a;
    u16 stk8c;
    u16 stk8e;
    u16 stk90;
    u16 stk92;
    u16 stk94;
    u16 stk96;
    f32 buf_c0[7];
    f32 f_d8;
    f32 f_dc;
    f32 f_e0;
    f32 f_e4;
    f32 f_f0;
    f32 f_f4;
    u32 loc100;
    u32 loc104;
    f32 *out_mat;
    f32 *out_uv;
    f32 t70;
    f32 t74;
    f32 t78;
    f32 t7c;
    f32 c_ang;
    f32 s_ang;
    f32 f1;
    f32 f2;
    s32 i;
    u8 *tmp2_a4;
    u8 *ctx18;
    u8 *cam;
    f32 cam80;
    f32 cam84;
    f32 persp;
    f32 px;
    f32 py;
    f32 inv_w;
    f32 inv_h;
    tmp_98 = *(s32 *)(arg0 + 0x98);
    tmp_08 = *(s32 *)(arg0 + 0x08);
    tmp_a4 = *(u8 **)(arg0 + 0xA4);
    if ((tmp_08 != 0) && (tmp_08 < tmp_98)) {
        tmp_abd0 = func_0048abd0(arg0 + 0x0C, arg0 + 0x30, tmp_08, tmp_98);
        packed0 = *(u32 *)arg0;
        scale = fGpffff8044;
        {
            u32 c1slot = (u32)tmp_abd0;
            u32 *p0 = &packed0;
            u32 *p1 = &c1slot;
            __asm__ volatile(
                "lw $2, 0(%1)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2.ni $2, $vf10    \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %2           \n"
                "nop                   \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vmove.xyzw $vf11, $vf10 \n"
                :
                : "r"(p0), "r"(p0), "f"(scale)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
            __asm__ volatile(
                "lw $2, 0(%1)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2.ni $2, $vf10    \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %2           \n"
                "nop                   \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                "lui $2, 0x437F        \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vftoi0.xyzw $vf10, $vf10 \n"
                "qmfc2.ni $2, $vf10    \n"
                "ppach $2, $0, $2      \n"
                "ppacb $2, $0, $2      \n"
                "move %0, $2           \n"
                : "=r"(packed1)
                : "r"(p1), "f"(scale)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
        }
        packed0 = packed1;
        if (((packed1 >> 24) & 0xFF) != 0xFF) {
            dst_ptr = *(u8 **)(tmp_a4 + 0x14);
            *(u32 *)(dst_ptr + 4) = packed1;
        } else {
            dst_ptr = *(u8 **)(tmp_a4 + 0x14);
            *(u32 *)(dst_ptr + 4) = (packed1 & 0x00FFFFFF) | 0xFE000000;
            packed1 = (packed1 & 0x00FFFFFF) | 0xFF000000;
            packed0 = packed1;
        }
        div100 = func_0048aff0(arg0 + 0x40, tmp_08, tmp_98) / 100.0f;
        off_y = func_0048aff0(arg0 + 0x6C, tmp_08, tmp_98) + fGpffff8084;
        tmp_ac = *(s32 *)(arg0 + 0xAC);
        if (tmp_ac != 0) {
            func_00482730(tmp_ac, tmp_08);
            func_00482700(*(s32 *)(arg0 + 0xAC), buf_c0);
            f_f0 = buf_c0[4];
            f_f4 = buf_c0[5];
            f_d8 = buf_c0[3];
            f_dc = buf_c0[4];
            f_e0 = buf_c0[5];
            f_e4 = buf_c0[6];
            stk8c = (u16)(f_d8 * (16.0f * f_f0));
            stk8e = (u16)(f_dc * (16.0f * f_f4));
            stk88 = (u16)(f_e0 * (16.0f * f_f0));
            stk8a = (u16)(f_dc * (16.0f * f_f4));
            stk94 = (u16)(f_e0 * (16.0f * f_f0));
            stk96 = (u16)(f_e4 * (16.0f * f_f4));
            stk90 = (u16)(f_d8 * (16.0f * f_f0));
            stk92 = (u16)(f_e4 * (16.0f * f_f0));
            stk70 = buf_c0[0];
            stk74 = buf_c0[1];
            stk78 = buf_c0[2];
            stk7c = buf_c0[3];
            stk80 = (s32)f_f0;
            stk84 = (u32)f_f4;
            off_y = off_y + buf_c0[2];
            func_003c42b0(*(s32 *)(tmp_a4 + 0x14), *(s32 *)(&buf_c0[5]));
        } else {
            tmp_a8 = *(s32 *)(arg0 + 0xA8);
            if (tmp_a8 != 0) {
                f32 spA0[4];
                func_00482ad0((u8 *)tmp_a8, tmp_08, (u8 *)spA0);
                stk8c = 0;
                stk8e = 0;
                stk88 = (s16)(spA0[1] * 16.0f);
                stk8a = 0;
                stk94 = (s16)(spA0[1] * 16.0f);
                stk96 = (s16)(spA0[2] * 16.0f);
                stk90 = 0;
                stk92 = (s16)(spA0[2] * 16.0f);
                stk70 = 0.0f;
                stk74 = 0.0f;
                stk78 = (f32)(s32)((s32)((f32)stk88 * spA0[0]) >> 5);
                stk7c = (f32)(s32)((s32)((f32)stk96 * spA0[3]) >> 5);
                stk80 = (s32)spA0[1];
                stk84 = (u32)spA0[2];
                func_003c42b0(*(s32 *)(tmp_a4 + 0x14), *(s32 *)(&spA0[3]));
            } else {
                u32 out0;
                u32 out1;
                func_004839d0((s32)tmp_a4, &out0);
                stk8c = 0;
                stk8e = 0;
                stk88 = (u16)(out0 * 0x10);
                stk8a = 0;
                stk94 = (u16)(out0 * 0x10);
                stk96 = (u16)(out1 * 0x10);
                stk90 = 0;
                stk92 = (u16)(out1 * 0x10);
                stk70 = 0.0f;
                stk74 = 0.0f;
                stk78 = (f32)(out0 * 0x10);
                stk7c = (f32)(out1 * 0x10);
                stk80 = out0;
                stk84 = out1;
            }
        }
        func_003c2290(*(u8 **)(*(u8 **)(tmp_a4 + 0x10) + 0x18), 0xFF2);
        ctx18 = *(u8 **)(*(u8 **)(tmp_a4 + 0x10) + 0x18);
        out_mat = *(f32 **)(*(u8 **)(ctx18 + 0x5C) + 0x14);
        out_uv = *(f32 **)(ctx18 + 0x34);
        t70 = stk70 * div100;
        t74 = stk74 * div100;
        t78 = stk78 * div100;
        t7c = stk7c * div100;
        c_ang = func_0044b610(off_y);
        s_ang = func_0044b7b0(off_y);
        out_mat[0] = ((t70 + t78) * c_ang) - ((t74 + t7c) * s_ang);
        out_mat[1] = ((t70 + t78) * s_ang) + ((t74 + t7c) * c_ang);
        out_mat[3] = ((t70 - t78) * c_ang) - ((t74 + t7c) * s_ang);
        out_mat[4] = ((t70 - t78) * s_ang) + ((t74 + t7c) * c_ang);
        out_mat[9] = ((t70 - t78) * c_ang) - (((t74 - t7c) * s_ang));
        out_mat[10] = (((t70 - t78) * s_ang)) + ((t74 - t7c) * c_ang);
        out_mat[6] = ((t70 + t78) * c_ang) - (((t74 - t7c) * s_ang));
        out_mat[7] = ((t70 + t78) * s_ang) + (((t74 - t7c) * c_ang));
        inv_w = 1.0f / (f32)(stk80 * 0x10);
        inv_h = 1.0f / (f32)(stk84 * 0x10);
        out_uv[2] = (f32)stk88 * inv_w;
        out_uv[3] = (f32)stk8a * inv_h;
        out_uv[0] = (f32)stk8c * inv_w;
        out_uv[1] = (f32)stk8e * inv_h;
        out_uv[6] = (f32)stk94 * inv_w;
        out_uv[7] = (f32)stk96 * inv_h;
        out_uv[4] = (f32)stk90 * inv_w;
        out_uv[5] = (f32)stk92 * inv_h;
        cam = func_00457120();
        cam80 = *(f32 *)(cam + 0x80);
        cam84 = *(f32 *)(cam + 0x84);
        f1 = (f32)*(s32 *)(arg0 + 0x9C);
        f2 = (f32)*(s32 *)(arg0 + 0xA0);
        persp = ((cam80 * -65535.0f) * cam84) / ((cam84 * -65535.0f) - ((cam84 - cam80) * -31.0f));
        px = 2.0f * (*(f32 *)(cam + 0x68) * persp);
        py = 2.0f * (*(f32 *)(cam + 0x6C) * persp);
        f1 = persp + 1.0f;
        {
            f32 arg9C = (f32)*(s32 *)(arg0 + 0x9C);
            f32 argA0 = (f32)*(s32 *)(arg0 + 0xA0);
        for (i = 0; i < 4; i++) {
            out_mat[0] = px * (0.5f - ((out_mat[0] + arg9C) / 640.0f));
            out_mat[1] = py * (0.5f - ((out_mat[1] + argA0) / 448.0f));
            out_mat[2] = f1;
            out_mat += 3;
        }
        }
        tmp2_a4 = *(u8 **)(arg0 + 0xA4);
        ctx18 = *(u8 **)(tmp2_a4 + 0x10);
        ctx18 = *(u8 **)(ctx18 + 0x18);
        func_003c22f0(ctx18);
        if ((*(u16 *)tmp2_a4 & 4) != 0) {
            *(u16 *)(ctx18 + 0x0C) = *(u16 *)(ctx18 + 0x0C) | 1;
        }
        cam = func_00457120();
        func_003e9cb0((void *)(u32)*(u32 *)(tmp_a4 + 0x0C), (void *)(*(u8 **)(cam + 4) + 0x10), 0);
        *(u16 *)tmp_a4 = *(u16 *)tmp_a4 & 0xFFFE;
        *(u32 *)(tmp_a4 + 0x18) = 0;
        *(u32 *)(tmp_a4 + 0x1C) = 0;
        func_00460ac0((void *)(u32)func_004814d0(*(u16 *)(arg0 + 0x34)), (void *)(tmp_a4 + 0x18));
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b1ad0);
#endif
// FUN_004B2740
void func_004b2740(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 8) + 1;
    func_004b1ad0(arg0);
}
/* measured: opt_propagation off retains the cached D_00887300 base and retail frame. */
// FUN_004B2780
#pragma opt_propagation off
s32 func_004b2780(u8 *arg0) {
    struct {
        u8 packet[0xF0];
        u8 pad[0x10];
    } work;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f2;
    void (**base)(u32,u32);
    u8 *temp_17;
    u8 *temp_2;

    if (func_003e8120(*(u8 **)(arg0 + 0xC)) == 0) {
        return 0;
    }
    temp_2 = func_00401b80();
    temp_17 = temp_2;
    temp_f21 = 640.0f / (f32)*(s32 *)(temp_2 + 0xC);
    temp_f20 = 448.0f / (f32)*(s32 *)(temp_2 + 0x10);
    func_003f6440(2, 0x2024);
    func_003f6440(3, 0x717FB);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, (u32)temp_17);
    base[0](3, 3);
    base[0](4, 3);
    temp_f2 = *(f32 *)D_008872FC_abs;
    temp_f0 = 1.0f / *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x84);
    *(s32 *)(work.packet + 0x00) = 0;
    *(s32 *)(work.packet + 0x04) = 0;
    *(f32 *)(work.packet + 0x08) = temp_f2;
    *(s32 *)(work.packet + 0x20) = 0x437F0000;
    *(s32 *)(work.packet + 0x24) = 0x437F0000;
    *(s32 *)(work.packet + 0x28) = 0x437F0000;
    *(s32 *)(work.packet + 0x2C) = 0x437F0000;
    *(f32 *)(work.packet + 0x18) = temp_f0;
    *(s32 *)(work.packet + 0x10) = 0;
    *(s32 *)(work.packet + 0x14) = 0;
    *(s32 *)(work.packet + 0x40) = 0;
    *(s32 *)(work.packet + 0x44) = 0x43800000;
    *(f32 *)(work.packet + 0x48) = temp_f2;
    *(s32 *)(work.packet + 0x60) = 0x437F0000;
    *(s32 *)(work.packet + 0x64) = 0x437F0000;
    *(s32 *)(work.packet + 0x68) = 0x437F0000;
    *(s32 *)(work.packet + 0x6C) = 0x437F0000;
    *(f32 *)(work.packet + 0x58) = temp_f0;
    *(s32 *)(work.packet + 0x50) = 0;
    *(f32 *)(work.packet + 0x54) = temp_f20;
    *(s32 *)(work.packet + 0x80) = 0x44000000;
    *(s32 *)(work.packet + 0x84) = 0;
    *(f32 *)(work.packet + 0x88) = temp_f2;
    *(s32 *)(work.packet + 0xA0) = 0x437F0000;
    *(s32 *)(work.packet + 0xA4) = 0x437F0000;
    *(s32 *)(work.packet + 0xA8) = 0x437F0000;
    *(s32 *)(work.packet + 0xAC) = 0x437F0000;
    *(f32 *)(work.packet + 0x98) = temp_f0;
    *(f32 *)(work.packet + 0x90) = temp_f21;
    *(s32 *)(work.packet + 0x94) = 0;
    *(s32 *)(work.packet + 0xC0) = 0x44000000;
    *(s32 *)(work.packet + 0xC4) = 0x43800000;
    *(f32 *)(work.packet + 0xC8) = temp_f2;
    *(s32 *)(work.packet + 0xE0) = 0x437F0000;
    *(s32 *)(work.packet + 0xE4) = 0x437F0000;
    *(s32 *)(work.packet + 0xE8) = 0x437F0000;
    *(s32 *)(work.packet + 0xEC) = 0x437F0000;
    *(f32 *)(work.packet + 0xD8) = temp_f0;
    *(f32 *)(work.packet + 0xD0) = temp_f21;
    *(f32 *)(work.packet + 0xD4) = temp_f20;
    D_00887310_abs[0](4, work.packet, 4);
    base[0](1, 0);
    func_003e8110(*(u8 **)(arg0 + 0xC));
    return 1;
}
/* measured: close the opt_propagation bracket around func_004b2780. */
#pragma opt_propagation on
/* Archived C body: docs/probe_archive/C4B_004b2a00_body.c (v10); object 1016B; */
/* retail window 1024B; 17 reloc-masked differing words. Remaining: or-dest */
/* v0-vs-v1 wall at six sites plus (u8)-conversion f-reg f1-vs-f0 wall at five */
/* rows; single-expr/split/two-temp and separate div-result variants inert. */
/* Fnalign edit 17 plus six reloc-only pairs; production remains ASM. */
/* measured 2026-09-17 full pragma_sweep --pairs: banked 17 via measure_guarded */
/* (already carries opt_propagation off + opt_common_subs off); best stays 17 */
/* with that pair (105 prop+peephole next, 175 loopinv/strength/unroll ties, 195 */
/* csoff singles, 222 dead group, 231-240 schedule/prop groups, 251-258 peephole */
/* high). No pair wins; installed pair is load-bearing. */
/* `python3 -E -s tools/pragma_sweep.py src/promoted/code1_004b.c func_004b2a00 --pairs`. */
/* measured 2026-09-17 earliest-hunk only (fnalign 254/254, 17 edits +6 reloc-only; */
/* earliest replace retail[16:18] or $v1 vs or $v0 + mtc1): u32 temp_2 for the */
/* *(u16*)(arg0+4) load fixes earliest hunk, 17->15 words (fnalign 15 edits +6 */
/* reloc-only, still 254/254) via `tools/fnalign.py ... --candidate */
/* /var/tmp/pairteen/earliest_b.c`; inclusive flip >-1 243 and u32 t2a 241 both */
/* worse (probe_variants a 243, c 241, b 15). Remaining 15 are the second or-site */
/* onward plus f-reg wall; stop per earliest-hunk-only. */
/* 2026-09-18: part of this floor is caused by `opt_common_subs off`, not by the
   source.  That pragma makes b210 allocate the float-to-integer conversion
   temporary out of the CSE table, so the `(u8)`-of-float idiom emits
   `cvt.w.s $f1, $f1` where retail has `cvt.w.s $f0, $f1` (measured with
   tools/micro_codegen.py; every other setting writes the fresh register).
   Removing it costs 240 words and removing both pragmas costs 171, so it
   stays for now - but the conversion rows here are not a source-shape
   residual and should not be probed as one. */
/* 2026-09-19 frame-first + pairs (masked 15, raw 21/24, 254/254 exact, frame */
/* both addiu $sp,$sp,-0x150): fnalign 15 (+6 reloc-only); or-dest $v0 vs $v1 at */
/* 5 sites (off 31,143,169,196,224: object or $v0,$v1,$v0 + mtc1 $v0 vs retail or */
/* $v1,$v1,$v0 + mtc1 $v1) + FP cvt/mfc/sub (off 53: cvt.w.s $f1 vs $f0, off 59: */
/* sub.s $f1 vs $f0 + cvt/mfc); stacking sched 230, nobranch 15 tie, peephole */
/* 242; oru32 single tie 15, orall u32 266 (s32 correct); propag+cs load-bearing */
/* (removal 240/171 per note, conversion rows pragma-caused per micro_codegen). */
// FUN_004B2A00 NONMATCHING
#ifdef SKIP_ASM
#pragma opt_propagation off
#pragma opt_common_subs off
void func_004b2a00(u8 *arg0) {
    struct {
        u8 packet[0xF0];
        u8 pad[0x10];
    } work;
    f32 temp_f20;
    f32 temp_f1_2;
    f32 temp_f1;
    f32 temp_f0;
    f32 f2a;
    f32 f2b;
    f32 f2c;
    f32 f2d;
    s32 ck;
    s32 three;
    s32 four;
    u32 temp_2;
    s32 temp_2_2;
    s32 var_3;
    s32 temp_17;
    u8 *temp_18;
    void (**base)(u32, u32);

    temp_2 = *(u16 *)(arg0 + 4);
    if (temp_2 >= 0) {
        temp_f1 = (f32)temp_2;
    } else {
        s32 t2a = ((u32)temp_2 >> 1);
        t2a = t2a | (temp_2 & 1);
        temp_f1 = (f32)t2a;
        temp_f1 += temp_f1;
    }
    temp_2_2 = *(u16 *)(arg0 + 2);
    if (temp_2_2 >= 0) {
        temp_f0 = (f32)temp_2_2;
    } else {
        s32 t2b = ((u32)temp_2_2 >> 1);
        t2b = t2b | (temp_2_2 & 1);
        temp_f0 = (f32)t2b;
        temp_f0 += temp_f0;
    }
    temp_f1 = 255.0f * (1.0f - (temp_f1 / temp_f0));
    var_3 = (u8)temp_f1;
    temp_17 = var_3 & 0xFF;
    temp_18 = *(u8 **)(*(u8 **)(arg0 + 12) + 96);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, (u32)temp_18);
    three = 3;
    base[0](three, three);
    base[0](4, 3);
    temp_f20 = *(f32 *)D_008872FC_abs;
    temp_f1_2 = 1.0f / *(f32 *)(func_00457120() + 132);
    *(s32 *)(work.packet + 0x00) = 0;
    *(s32 *)(work.packet + 0x04) = 0;
    *(f32 *)(work.packet + 0x08) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0x20) = ck;
    *(s32 *)(work.packet + 0x24) = ck;
    *(s32 *)(work.packet + 0x28) = ck;
    if (temp_17 >= 0) {
        f2a = (f32)temp_17;
    } else {
        s32 u2a = ((u32)temp_17 >> 1);
        u2a = u2a | (temp_17 & 1);
        f2a = (f32)u2a;
        f2a += f2a;
    }
    *(f32 *)(work.packet + 0x2C) = f2a;
    *(f32 *)(work.packet + 0x18) = temp_f1_2;
    *(s32 *)(work.packet + 0x10) = 0;
    *(s32 *)(work.packet + 0x14) = 0;
    *(s32 *)(work.packet + 0x40) = 0;
    *(s32 *)(work.packet + 0x44) = 0x43E00000;
    *(f32 *)(work.packet + 0x48) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0x60) = ck;
    *(s32 *)(work.packet + 0x64) = ck;
    *(s32 *)(work.packet + 0x68) = ck;
    if (temp_17 >= 0) {
        f2b = (f32)temp_17;
    } else {
        s32 u2b = ((u32)temp_17 >> 1);
        u2b = u2b | (temp_17 & 1);
        f2b = (f32)u2b;
        f2b += f2b;
    }
    *(f32 *)(work.packet + 0x6C) = f2b;
    *(f32 *)(work.packet + 0x58) = temp_f1_2;
    *(s32 *)(work.packet + 0x50) = 0;
    *(s32 *)(work.packet + 0x54) = 0x3F800000;
    *(s32 *)(work.packet + 0x80) = 0x44200000;
    *(s32 *)(work.packet + 0x84) = 0;
    *(f32 *)(work.packet + 0x88) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0xA0) = ck;
    *(s32 *)(work.packet + 0xA4) = ck;
    *(s32 *)(work.packet + 0xA8) = ck;
    if (temp_17 >= 0) {
        f2c = (f32)temp_17;
    } else {
        s32 u2c = ((u32)temp_17 >> 1);
        u2c = u2c | (temp_17 & 1);
        f2c = (f32)u2c;
        f2c += f2c;
    }
    *(f32 *)(work.packet + 0xAC) = f2c;
    *(f32 *)(work.packet + 0x98) = temp_f1_2;
    *(s32 *)(work.packet + 0x90) = 0x3F800000;
    *(s32 *)(work.packet + 0x94) = 0;
    *(s32 *)(work.packet + 0xC0) = 0x44200000;
    *(s32 *)(work.packet + 0xC4) = 0x43E00000;
    *(f32 *)(work.packet + 0xC8) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0xE0) = ck;
    *(s32 *)(work.packet + 0xE4) = ck;
    *(s32 *)(work.packet + 0xE8) = ck;
    if (temp_17 >= 0) {
        f2d = (f32)temp_17;
    } else {
        s32 u2d = ((u32)temp_17 >> 1);
        u2d = u2d | (temp_17 & 1);
        f2d = (f32)u2d;
        f2d += f2d;
    }
    *(f32 *)(work.packet + 0xEC) = f2d;
    *(f32 *)(work.packet + 0xD8) = temp_f1_2;
    ck = 0x3F800000;
    *(s32 *)(work.packet + 0xD0) = ck;
    *(s32 *)(work.packet + 0xD4) = ck;
    four = 4;
    D_00887310_abs[0](four, work.packet, four);
    base[0](1, 0);
}
#pragma opt_common_subs on
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b2a00);
#endif
// FUN_004B2E00
void func_004b2e00(u8 *object) {
    u8 *base;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;
    s32 *slot_1;
    s32 *slot_2;
    s32 temp_17;
    s32 temp_4_2;
    s32 temp_4_3;

    base = object;
    temp_4 = *(u8 **)(base + 0xC);
    if (temp_4 != NULL) {
        temp_17 = *(s32 *)(temp_4 + 4);
        if (temp_17 != 0) {
            func_003efd20(temp_4, 0);
            func_003e9390(temp_17);
        }
        temp_3 = *(u8 **)(base + 0xC);
        slot_1 = (s32 *)(temp_3 + 0x64);
        temp_4_2 = *(s32 *)(temp_3 + 0x64);
        if (temp_4_2 != 0) {
            *slot_1 = 0;
            func_003ec330(temp_4_2);
        }
        temp_2 = *(u8 **)(base + 0xC);
        slot_2 = (s32 *)(temp_2 + 0x60);
        if (*(s32 *)(temp_2 + 0x60) != 0) {
            *slot_2 = 0;
        }
        func_003e8440(*(u8 **)(base + 0xC));
        *(u8 **)(base + 0xC) = NULL;
    }
    temp_4_3 = *(s32 *)(base + 8);
    if (temp_4_3 != 0) {
        func_0040fcd0(temp_4_3, 0);
        func_003ec330(*(s32 *)(base + 8));
        *(s32 *)(base + 8) = 0;
    }
}
// FUN_004B3250
void func_004b3250(s32 arg0)
{
    iGpffffbb9c = arg0;
}

// FUN_004B3260
void func_004b3260(u8 *arg0) {
    u8 *temp_1;
    u8 *temp_2;
    u8 *dst;

    temp_1 = *(u8 **)(arg0 + 0x20);
    temp_2 = *(u8 **)(temp_1 + 4);
    if (iGpffffbb64.c3 != 0xFF) {
        dst = *(u8 **)(temp_2 + 0x14);
        *(Code1_004bColor *)(dst + 4) = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = *(u8 **)(temp_2 + 0x14);
        *(Code1_004bColor *)(dst + 4) = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    *(void (**)(void))(temp_2 + 0x20) = func_004b36b0;
    *(u8 **)(temp_2 + 0x28) = arg0;
}
// FUN_004B4EA0
void func_004b4ea0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = arg0;
    (*(void (**)(u8 *))(D_00714658 + (*(s32 *)(temp_16 + 0x18) * 0x18)))(
        *(u8 **)(temp_16 + 0x20));
    jtbl_008873EC[0](temp_16);
}

// FUN_004B4F10
void func_004b4f10(u8 *arg0)
{
    func_004b4cb0(*(u16 *)(arg0 + 0x18), *(s32 *)(arg0 + 0x24));
}
// FUN_004B4F40
void func_004b4f40(u8 *arg0)
{
    ((void (*)(void *))(*(u32 *)(D_00714650 + (*(s32 *)(arg0 + 0x18) * 24))))(arg0);
    *(s32 *)(arg0 + 0x14) = 0;
}

// FUN_004B4F90
void func_004b4f90(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_0071465C + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
    *(s32 *)((char *)param_1 + 0x14) += 1;
}

// FUN_004B4FF0
void func_004b4ff0(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x14) > 0) {
        ((void (*)(void *))(*(u32 *)(D_00714660 + (*(s32 *)(arg0 + 0x18) * 24))))(arg0);
    }
}

// FUN_004B5040
void func_004b5040(void *param_1) {
    u8 *object;

    object = param_1;
    ((void (*)(void *))(*(u32 *)(D_0071465C + *(s32 *)(object + 0x18) * 24)))(object);
    *(s32 *)(object + 0x14) += 1;
    if (*(s32 *)(object + 0x14) > 0) {
        ((void (*)(void *))(*(u32 *)(D_00714660 + *(s32 *)(object + 0x18) * 24)))(object);
    }
}
// FUN_004B50D0
s128 func_004b50d0(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


typedef signed __int128 s128;


// FUN_004B50E0
void func_004b50e0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x10) = arg1;
}

// FUN_004B5340
/* The handler-table address is built through two named locals on purpose:
   retail adds the sub-table offset to the base, then the 0x1C-strided index,
   then loads at displacement 0. Folding either step into the expression makes
   b210 sink the offset into the load displacement and flip the addu operands
   (nd 40-54). */
void func_004b5340(u8 *arg0) {
    s32 tbl;
    s32 idx;
    void (*fn)(s32);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 8;
        idx = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn = *(void (**)(s32))(tbl + idx);
        if (fn != NULL) {
            fn(*(s32 *)(arg0 + 0x30));
        }
    }
    jtbl_008873EC[0](arg0);
}

// FUN_004B53C0
u8 *func_004b53c0(u8 *arg0)
{
    u8 *result;
    u8 *work;
    s32 base;
    s32 id;
    s32 off;
    s32 tex;
    s32 (*setup4)(s32, s32, s32, s32);
    void (*post)(u8 *);
    extern u8 *func_004b50f0();

    id = *(s32 *)(arg0 + 0x2C);
    base = (s32)iGpffffbba0;
    off = (base, id * 0x1C);
    if (*(s32 *)(off + base + 0xC) == 0) {
        tex = *(s32 *)(arg0 + 0x38);
        off = id & 0xFFFF;
        work = func_004b50f0(off, tex);
        if (iGpffffbba4() != 0) {
            off = (off & 0xFFFF) * 0x1C;
            base = (s32)iGpffffbba0;
            base += 4;
            base += off;
            setup4 = *(s32 (**)(s32, s32, s32, s32))base;
            if (setup4 != NULL) {
                *(s32 *)(work + 0x30) = setup4(tex, 0, 0, 0);
            }
            base = (s32)iGpffffbba0;
            base += off;
            post = *(void (**)(u8 *))base;
            if (post != NULL) {
                post(work);
            }
        }
        result = work;
    } else {
        work = func_004b50f0((id = id & 0xFFFF),
                             (id, *(s32 *)(arg0 + 0x38)));
        {
            s32 idx2;
            idx2 = *(s32 *)(arg0 + 0x2C) * 0x1C;
            *(s32 *)(work + 0x30) =
                (*(s32 (**)(u8 *))((u8 *)(idx2 + (s32)iGpffffbba0 + 0xC)))(arg0);
        }
        off = *(s32 *)(arg0 + 0x2C) * 0x1C;
        base = (s32)iGpffffbba0;
        post = *(void (**)(u8 *))(base + off);
        if (post != NULL) {
            post(work);
        }
        result = work;
    }
    return result;
}
// FUN_004B5530
void func_004b5530(u8 *arg0) {
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        fn = *(void (**)(u8 *))(iGpffffbba0 + 0 + *(s32 *)(arg0 + 0x2C) * 0x1C);
        if (fn != NULL) {
            fn(arg0);
        }
        *(s32 *)(arg0 + 0x28) = 0;
    }
}

// FUN_004B55A0
/* The handler-table address is built through two named locals on purpose:
   retail adds the sub-table offset to the base, then the 0x1C-strided index,
   then loads at displacement 0. Folding either step into the expression makes
   b210 sink the offset into the load displacement and flip the addu operands
   (nd 40-54). */
void func_004b55a0(u8 *arg0) {
    s32 tbl;
    s32 idx;
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 0x10;
        idx = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn = *(void (**)(u8 *))(tbl + idx);
        if (fn != NULL) {
            fn(arg0);
        }
        *(s32 *)(arg0 + 0x28) += 1;
    }
}

// FUN_004B5620
/* The handler-table address is built through two named locals on purpose:
   retail adds the sub-table offset to the base, then the 0x1C-strided index,
   then loads at displacement 0. Folding either step into the expression makes
   b210 sink the offset into the load displacement and flip the addu operands
   (nd 40-54). */
void func_004b5620(u8 *arg0) {
    s32 tbl;
    s32 idx;
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 0x14;
        idx = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn = *(void (**)(u8 *))(tbl + idx);
        if (fn != NULL) {
            fn(arg0);
        }
    }
}

// FUN_004B5690
void func_004b5690(u8 *arg0)
{
    s32 tbl1;
    s32 idx1;
    void (*fn1)(u8 *);
    s32 tbl2;
    s32 idx2;
    void (*fn2)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl1 = (s32)iGpffffbba0 + 0x10;
        idx1 = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn1 = *(void (**)(u8 *))(tbl1 + idx1);
        if (fn1 != NULL) {
            fn1(arg0);
        }
        *(s32 *)(arg0 + 0x28) += 1;
    }
    if (iGpffffbba4() != 0) {
        tbl2 = (s32)iGpffffbba0 + 0x14;
        idx2 = *(s32 *)(arg0 + 0x2C) * 0x1C;
        fn2 = *(void (**)(u8 *))(tbl2 + idx2);
        if (fn2 != NULL) {
            fn2(arg0);
        }
    }
}
// FUN_004B5750
s128 func_004b5750(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


typedef signed __int128 s128;


// FUN_004B5760
s128 func_004b5760(u8 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *(s128 *)(arg0 + 0x10) = temp;
    return temp;
}


extern u8 *func_004b6030();
extern u8 *func_004b6900();
extern void func_004b6bb0();
extern void func_004b6da0();


// FUN_004B5770
void func_004b5770(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}

// FUN_004B5780
void func_004b5780(u8 *arg0, f32 arg1)
{
    *(f32 *)(arg0 + 0x20) = arg1;
}
// FUN_004B5790
void func_004b5790(u8 *arg0, s32 arg1)
{
    iGpffffbba0 = arg0;
    iGpffffbba4 = (s32 (*)(void))arg1;
}
// FUN_004B57A0
u8 *func_004b57a0(void *object, s32 arg1) {
    u8 *temp_2;
    u8 *temp_2_2;

    temp_2_2 = func_004b6030(object);
    *(s32 *)(temp_2_2 + 0x20) = arg1;
    temp_2 = func_004b6900(temp_2_2);
    func_004b6da0(temp_2);
    func_004b6bb0(temp_2);
    return temp_2;
}


// FUN_004BC4D0
void func_004bc4d0(u8 *arg0, f32 arg1)
{
    *(s32 *)(arg0 + 0x28) = 0;
    *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x2c);
    *(f32 *)(arg0 + 0x34) = arg1;
    *(s32 *)(arg0 + 4) |= 1;
}
// FUN_004BC500
void func_004bc500(u8 *arg0)
{
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x2c) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0xc) = 0;
}
// FUN_004BC520
void func_004bc520(u8 *arg0, f32 *arg1)
{
    *(f32 *)(arg0 + 0x2c) += *arg1;
}
/* measured: opt_propagation off with `arg1 = arg1 << 3;` as its own statement keeps the
   shift ahead of the table loads (retail sll/lw/lw/addu); with propagation on the shift
   is folded into the address expression and emitted after the loads. */
// FUN_004BC540
#pragma opt_propagation off
void func_004bc540(u8 *arg0, s32 arg1, u8 *arg2, f32 fparg0)
{
    u8 *temp_5;
    struct {
        u8 *sp8;
        u8 *spC;
    } stack;
    u8 *var_7;
    s32 var_3;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;

    var_7 = (u8 *)&stack;
    var_3 = 8;
    if (var_7 != NULL) {
        do {
            *var_7 = 0;
            var_7++;
            var_3--;
        } while (var_3 != 0);
    }
    arg1 = arg1 << 3;
    temp_5 = *(u8 **)(*(u8 **)(arg0 + 0) + 4) + arg1;
    stack.sp8 = temp_5 + 8;
    stack.spC = temp_5 + 0xC;
    temp_f1 = 1.0f - fparg0;

    if (*(s32 *)(arg0 + 4) & 1) {
        temp_f4 = *(f32 *)(arg0 + 0x34);
        if (temp_f4 > 0.0f) {
            temp_f2 = 1.0f - ((*(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x30)) / temp_f4);
            if (temp_f2 < 0.0f) {
                temp_f2 = 0.0f;
            }
        } else if (temp_f4 == 0.0f) {
            if (*(f32 *)(arg0 + 0x2C) < *(f32 *)(arg0 + 0x30)) {
                goto set_one;
            }
            temp_f2 = 0.0f;
            goto set_progress;
        set_one:
            temp_f2 = 1.0f;
        set_progress:
            ;
        }
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0]);
        arg2[0] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1]);
        arg2[1] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2]);
        arg2[2] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3]);
        arg2[3] = (u8)temp_f3;
        return;
    }
    temp_f3 = fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0];
    arg2[0] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1];
    arg2[1] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2];
    arg2[2] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3];
    arg2[3] = (u8)temp_f3;
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
} Code1_004bBccf0Temp;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code1_004bBddVec4;
// FUN_004BCCF0
void func_004bccf0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3)
{
    Code1_004bBccf0Temp temp;
    s16 temp_6;
    u8 *var_6_2;
    s32 var_6;
    s32 var_7;
    u8 *temp_3;
    u8 *var_4;
    s32 var_4_2;

    var_7 = arg3;
    temp_6 = *(s16 *)(arg0 + 0x38);
    switch (temp_6) {
    case 0:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 2) + 1;
        break;
    case 1:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 3) + 6;
        break;
    case 2:
        var_7 = (*(s32 *)(*(u8 **)(arg0 + 0) + 0xC) * 3) + 6;
        break;
    }
    var_4 = *(u8 **)(arg1 + 0x30);
    var_6 = 0;
    while (var_6 < var_7) {
        *(u8 *)(var_4 + 0) = 0;
        *(u8 *)(var_4 + 1) = 0;
        *(u8 *)(var_4 + 2) = 0;
        *(u8 *)(var_4 + 3) = 0;
        var_6 += 1;
        var_4 += 4;
    }
    var_6_2 = *(u8 **)(*(u8 **)(arg1 + 0x5C) + 0x14);
    var_4_2 = 0;
    while (var_4_2 < var_7) {
        *(s32 *)(var_6_2 + 0) = 0;
        *(s32 *)(var_6_2 + 4) = 0;
        *(s32 *)(var_6_2 + 8) = 0;
        var_4_2 += 1;
        var_6_2 += 0xC;
    }
    temp.a = 0;
    temp.b = 0;
    temp.c = 0;
    temp.d = (f32)1000000000;
    temp_3 = *(u8 **)(arg1 + 0x5C);
    *(Code1_004bBccf0Temp *)(temp_3 + 4) = temp;
}
// FUN_004BD4A0
f32 func_004bd4a0(u8 *arg0, u8 *arg1)
{
    Code1_004bBddVec4 a;
    Code1_004bBddVec4 b;
    f32 ad;
    f32 bd;
    f32 dot;

    a = *(Code1_004bBddVec4 *)arg0;
    b = *(Code1_004bBddVec4 *)arg1;
    ad = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
    ad = __sqrt(ad, 0.0f);
    a.x = a.x / ad;
    a.y = a.y / ad;
    a.z = a.z / ad;
    a.w = a.w / ad;
    bd = b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w;
    bd = __sqrt(bd, 0.0f);
    b.x = b.x / bd;
    b.y = b.y / bd;
    b.z = b.z / bd;
    b.w = b.w / bd;
    if ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w)) {
        return 0.0f;
    }
    dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    if (dot > 1.0f) {
        dot = 1.0f;
    } else if (dot < -1.0f) {
        dot = -1.0f;
    }
    return dot;
}
// FUN_004BD628
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd628);
// FUN_004BD640
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd640);
// FUN_004BD658
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd658);
// FUN_004BD670
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd670);
// FUN_004BD688
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd688);
// FUN_004BD6A0
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd6a0);
// Archived C body: build/WBHygiene_func_004bd6b8_archive.txt; no current park body remains.
// FUN_004BD6B8
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd6b8);

// FUN_004BD750
/* measured: schedule on fills func_004bd750's retail jr delay-slot load. */
#pragma schedule on
s32 func_004bd750(u8 *arg0) {
    return *(s32 *)(arg0 + 8);
}
/* measured: close the schedule bracket around func_004bd750. */
#pragma schedule off
