/* Consolidated Persona 4 source units. */
/* Original translation unit effParticle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

void func_004833f0(s32 arg0);
s32 func_004830f0(s32 arg0, s32 arg1);

void func_00481ee0(s32 arg0);
s32 func_00481d80(s32 *arg0);
extern s32 func_00481e30(s32 arg0);

void func_004829c0(s32 arg0);
s32 func_00482800(s32 *arg0);
extern s32 func_00482a70(s32 arg0);

extern void func_00492d00(int param_1);
extern void func_00492cd0(u8 *arg0);
extern u8 *func_00492b20(u16 arg0, u32 arg1, void *arg2);
extern s32 func_00481300(s32 arg0);
extern void func_003c42b0(void *arg0, void *arg1);
extern void *func_00481390(void *arg0);
extern void func_003ef3a0(void *arg0);
extern void func_0044ea90(u8 *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_0046d730(void *file, s32 line);
extern u8 D_00713CC0[];
extern u8 D_00713CD0[];
extern void (*jtbl_008873EC[])(void *);
extern u8 *func_00484570(u8 *arg0);
extern void func_004846d0(u8 *arg0);
extern u8 *func_00484830(u8 *arg0);
extern u8 *func_00484bb0(u8 *arg0);
extern void func_00485b20(void *arg0);
extern void *func_00485c80(void *arg0);
extern u8 *func_00483270(void *arg0);
extern u8 *func_00484490(u8 *arg0);
extern s32 *func_004844d0(u8 *arg0);
void func_004875d0(u8 *arg0, s32 arg1, void *arg2);
void func_00487160(u8 *arg0, u8 *arg1);
void func_00487650(u8 *arg0, s32 arg1, s32 arg2);
void func_004877b0(u8 *arg0, s32 arg1);
void func_00487860(u8 *arg0, s32 *arg1);
void func_00487710(u8 *arg0, s32 arg1);
void func_004878c0(u8 *arg0, void *arg1);
void func_00487a30(u8 *arg0, void *arg1);
void func_00487ba0(u8 *arg0, s32 *arg1);
extern void func_00484970(s32 arg0);
extern void func_00484a90(s32 arg0, f32 arg1);
extern void func_00484a40(s32 arg0, void *arg1);
extern void func_004849c0(s32 arg0);
extern void func_00485fe0(s32 arg0);
extern void func_00486400(s32 arg0, f32 arg1);
extern void func_004861f0(s32 arg0, void *arg1);
extern void func_00485630(s32 arg0);
extern void func_00492df0(u8 *arg0, void *arg1);
extern void func_00492db0(u8 *arg0, void *arg1);
extern void func_004bceb0(void);

// FUN_00486A50
void *func_00486a50(s32 arg0)
{
    u8 *p;

    func_0044ea90(D_00713CC0, 0x171);
    p = (u8 *)(*jtbl_008873E8)(0x60, 0x40000);
    func_0043f9c8(p, 0, 0x60);
    if (p == NULL) {
        func_0046d730(D_00713CD0, 0x1F);
    }
    *(s32 *)(p + 0) = arg0;
    *(s32 *)(p + 4) = -1;
    *(s32 *)(p + 8) = 0x3F800000;
    return p;
}
/* measured: retail keeps the alloc result p in $s2 and reuses $s3 for both
   var_19 and the func_004844d0 result (temp_2_3); mwcc b210 puts p in $s3 and
   var_19/temp_2_3 in $s2. The base-hoist (jtbl_008873E8 -> $s1) and the switch
   jump table match exactly; only this saved-register rotation differs (42
   words). Tried declaration orders (p/var_19/temp_2_3 in every position), a
   single shared variable, the comma-operator base form, and #pragma
   opt_propagation off + typed base local -- all nd >= 42. The jtbl_008873E8
   base-hoist spelling used here (u32 base = (u32)jtbl_008873E8;
   ((void (*)(u32,u32))*(u32 *)base)()) is correct and matches retail. */
/* fresh: E486 body fixed + archived (compile blockers NULL->0 (5 sites), (int) casts removed to match owner (u8*) decls -- zero codegen change); 105wd / obj780B/window784B (4B short, 1 instr, 0.5%% gate); prior note best 42wd is unarchived (working copy lost -- E486 header said 252 stale); rotation wall stands (prior decl-order/shared/comma/propagation all >=42); parent 4938e0 levers N/A (mask is 0xFF single recompute (no 0xFFFF-per-site + frame symptom, frame -96/sqx5 matches); no ||; no COP2 unpack (allocation/jtbl code)). Bare ASM kept. */
/* measured: 105 differing words, 195/195 instrs, fnalign 56ed (+12 reloc), obj780B/window784B (4B short, 1 instr); loopinv 105 tie, schedule 162 (660B), commons 148, prop 105 tie; no lb/lbu (halfwords only) so s8 N/A; single 0xFF recompute (no 0xFFFF-per-site + frame symptom) so TRAK u16+commons N/A; no COP2-unpack in alloc/jtbl path; signatures corrected to MATCH defs. Banked floor. */
// FUN_00486B00 NONMATCHING
#ifdef NON_MATCHING
 typedef s32 EP_WORD;
 #define EP_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
 EP_WORD *func_00486b00(u8 *arg0)
 {
    u8 *arg0_p = arg0;
    u8 *temp_2_2;
    u32 base;
    s32 temp_3;
    u32 var_19;
    EP_WORD *temp_2;
    EP_WORD *temp_2_5;
    s32 *temp_2_3;
    temp_2_2 = (u8 *)func_00484490(arg0_p);
    if (0 == temp_2_2) {
        func_0046d730(D_00713CD0, 0x55);
    }
    temp_3 = (s32)(EP_FIELD(temp_2_2, s32 *, 0x20));
    if (temp_3 == 0) {
        var_19 = (u32)(EP_FIELD(temp_2_2, s32 *, 0xB8) * EP_FIELD(temp_2_2, s32 *, 0x24));
    } else {
        var_19 = (u32)(temp_3 * EP_FIELD(temp_2_2, s32 *, 0x24));
    }
    if (var_19 >= 0x12DU) var_19 = 0x12C;
    func_0044ea90(D_00713CC0, 0x171);
    base = (u32)jtbl_008873E8;
    temp_2 = (EP_WORD *)(*(void *(*)(u32, u32))*(u32 *)base)(0x60, 0x40000);
    func_0043f9c8(temp_2, 0, 0x60);
    if (temp_2 == 0) func_0046d730(D_00713CD0, 0x1F);
    EP_FIELD(temp_2, EP_WORD **, 0) = (EP_WORD *)var_19;
    EP_FIELD(temp_2, s32 *, 4) = -1;
    EP_FIELD(temp_2, s32 *, 8) = 0x3F800000;
    if (temp_2 == 0) func_0046d730(D_00713CD0, 0x57);
    func_004875d0((u8 *)temp_2, EP_FIELD(arg0, u16 *, 0xC), temp_2_2);
    if (EP_FIELD(temp_2, EP_WORD **, 0) == 0) return temp_2;
    temp_2_3 = (s32 *)func_004844d0(arg0_p);
    if (temp_2_3 != 0) {
        switch ((u16)(EP_FIELD(arg0_p, u16 *, 0x1C))) {
        case 1:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 1);
            func_004877b0((u8 *)temp_2, (s32)temp_2_3); break;
        case 2:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 2);
            func_00487860((u8 *)temp_2, temp_2_3); break;
        case 4:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 4);
            func_00487710((u8 *)temp_2, *temp_2_3); break;
        case 5: func_004878c0((u8 *)temp_2, temp_2_3); break;
        case 6: func_00487a30((u8 *)temp_2, temp_2_3); break;
        case 7:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 7);
            func_00487ba0((u8 *)temp_2, temp_2_3);
            func_0044ea90(D_00713CC0, 0x171);
            temp_2_5 = (EP_WORD *)(*(void *(*)(u32, u32))*(u32 *)base)(0x30, 0x40000);
            func_0043f9c8(temp_2_5, 0, 0x30);
            EP_FIELD(temp_2_5, s16 *, 0x18) = 0x19;
            EP_FIELD(temp_2, EP_WORD **, 0x5C) = (EP_WORD *)temp_2_5;
            EP_FIELD(EP_FIELD(temp_2, EP_WORD **, 0x5C), EP_WORD **, 0x1C) = (EP_WORD *)temp_2;
            break;
        default: func_0046d730(D_00713CD0, 0x7E); break;
        }
        EP_FIELD(temp_2, u16 *, 0xC) = (u16)EP_FIELD(arg0_p, u16 *, 0x1C);
    }
    return temp_2;
 }
#else
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00486b00);
#endif

// FUN_00486E10
void func_00486e10(u8 *arg0)
{
    u32 count;
    u32 i;

    if (*(s32 *)(arg0 + 0x38) != 0) {
        if (*(s32 *)(arg0 + 0x4C) != 0) {
            count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
        } else {
            count = *(s32 *)(arg0 + 0);
        }
        for (i = 0; i < count; i++) {
            func_004846d0(*(u8 **)(*(u8 **)(arg0 + 0x34) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    }
    if (*(s32 *)(arg0 + 0x40) != 0) {
        if (*(s32 *)(arg0 + 0x4C) != 0) {
            count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
        } else {
            count = *(s32 *)(arg0 + 0);
        }
        for (i = 0; i < count; i++) {
            func_00485b20(*(u8 **)(*(u8 **)(arg0 + 0x3C) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x40));
    }
    if (*(s32 *)(arg0 + 0x44) != 0) {
        func_00481ee0(*(s32 *)(arg0 + 0x44));
    }
    if (*(s32 *)(arg0 + 0x48) != 0) {
        func_004829c0(*(s32 *)(arg0 + 0x48));
    }
    if (*(u8 *)(arg0 + 0xE) & 1) {
        func_00492cd0((u8 *)*(s32 *)(arg0 + 0x4C));
    }
    if (*(s32 *)(arg0 + 0x50) != 0) {
        func_004833f0(*(s32 *)(arg0 + 0x50));
    }
    if (*(s32 *)(arg0 + 0x5C) != 0) {
        jtbl_008873EC[0](*(void **)(arg0 + 0x5C));
    }
    jtbl_008873EC[0](arg0);
}
// FUN_00486FB0
void *func_00486fb0(u8 *arg0)
{
    u32 s19;
    u8 *s17;
    u8 *p;
    u32 v;

    if (*(s32 *)(arg0 + 0x4C) == 0) {
        func_0046d730(D_00713CD0, 0xE0);
    }
    s17 = *(u8 **)(*(u8 **)(arg0 + 0x4C) + 0x24);
    if (s17 == NULL) {
        func_0046d730(D_00713CD0, 0xE2);
    }
    v = *(u32 *)(s17 + 0x20);
    if (v == 0) {
        s19 = *(u32 *)(s17 + 0xB8) * *(u32 *)(s17 + 0x24);
    } else {
        s19 = v * *(u32 *)(s17 + 0x24);
    }
    if (s19 > 0x12C) {
        s19 = 0x12C;
    }
    func_0044ea90(D_00713CC0, 0x171);
    p = (u8 *)(*jtbl_008873E8)(0x60, 0x40000);
    func_0043f9c8(p, 0, 0x60);
    if (p == NULL) {
        func_0046d730(D_00713CD0, 0x1F);
    }
    *(u32 *)(p + 0) = s19;
    *(s32 *)(p + 4) = -1;
    *(s32 *)(p + 8) = 0x3F800000;
    if (p == NULL) {
        func_0046d730(D_00713CD0, 0xE4);
    }
    func_004875d0(p, *(u16 *)(*(u8 **)(arg0 + 0x4C)), (void *)s17);
    if (*(s32 *)(p + 0) == 0) {
        return p;
    }
    if (*(s32 *)(arg0 + 0x50) != 0) {
        *(s32 *)(p + 0x50) = (s32)func_00483270((void *)*(s32 *)(arg0 + 0x50));
    }
    func_00487160(p, arg0);
    return p;
}
/* measured: case-local count/index pairs make b210 color the loop locals
   $s2/$s3 and the parameters $s1/$s0, matching retail. The named case-7
   allocation result remains in $s2 through memset before being stored at
   arg0+0x5C. Shared function-scope counters rotate all four saved registers.
   Object/window 1136B, normalized_diff 0. */
// FUN_00487160
void func_00487160(u8 *arg0, u8 *arg1)
{
    switch (*(u16 *)(arg1 + 0xC)) {
    case 1:
    case 4:
        *(f32 *)(arg0 + 0x54) = *(f32 *)(arg1 + 0x54);
        *(f32 *)(arg0 + 0x58) = *(f32 *)(arg1 + 0x58);
        break;
    case 2:
        if (*(s32 *)(arg1 + 0x44) == 0) {
            func_0046d730(D_00713CD0, 0x10D);
        }
        if (*(s32 *)(arg1 + 0x4C) == 0) {
            func_0046d730(D_00713CD0, 0x10E);
        }
        if (*(s32 *)(arg0 + 0x44) != 0) {
            func_00481ee0(*(s32 *)(arg0 + 0x44));
        }
        *(s32 *)(arg0 + 0x44) = func_00481e30(*(s32 *)(arg1 + 0x44));
        break;
    case 5: {
        u32 count5;
        u32 i5;

        count5 = *(u32 *)(*(u8 **)(arg1 + 0x4C) + 8);
        if (count5 == 0) {
            return;
        }
        if (*(s32 *)(arg1 + 0x38) == 0) {
            func_0046d730(D_00713CD0, 0x119);
        }
        if (*(s32 *)(arg1 + 0x4C) == 0) {
            func_0046d730(D_00713CD0, 0x11A);
        }
        if (*(s32 *)(arg0 + 0x38) != 0) {
            for (i5 = 0; i5 < count5; i5++) {
                func_004846d0(*(u8 **)(*(u8 **)(arg0 + 0x34) + i5 * 4));
            }
            jtbl_008873EC[0](*(void **)(arg0 + 0x38));
            *(u8 **)(arg0 + 0x34) = NULL;
            *(u8 **)(arg0 + 0x38) = NULL;
        }
        if (count5 * 4 == 0) {
            return;
        }
        func_0044ea90(D_00713CD0, 0x12C);
        *(u8 **)(arg0 + 0x38) = (u8 *)(*jtbl_008873E8)(count5 * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x38) == NULL) {
            func_0046d730(D_00713CD0, 0x12D);
        }
        *(u8 **)(arg0 + 0x34) = *(u8 **)(arg0 + 0x38);
        for (i5 = 0; i5 < count5; i5++) {
            *(u8 **)(*(u8 **)(arg0 + 0x34) + i5 * 4) =
                func_00484830(*(u8 **)(*(u8 **)(arg1 + 0x34)));
        }
        break;
    }
    case 6: {
        u32 count6;
        u32 i6;

        count6 = *(u32 *)(*(u8 **)(arg1 + 0x4C) + 8);
        if (count6 == 0) {
            return;
        }
        if (*(s32 *)(arg1 + 0x40) == 0) {
            func_0046d730(D_00713CD0, 0x139);
        }
        if (*(s32 *)(arg1 + 0x4C) == 0) {
            func_0046d730(D_00713CD0, 0x13A);
        }
        if (*(s32 *)(arg0 + 0x40) != 0) {
            for (i6 = 0; i6 < count6; i6++) {
                func_00485b20(*(u8 **)(*(u8 **)(arg0 + 0x3C) + i6 * 4));
            }
            jtbl_008873EC[0](*(void **)(arg0 + 0x40));
            *(u8 **)(arg0 + 0x3C) = NULL;
            *(u8 **)(arg0 + 0x40) = NULL;
        }
        if (count6 * 4 == 0) {
            return;
        }
        func_0044ea90(D_00713CD0, 0x14C);
        *(u8 **)(arg0 + 0x40) = (u8 *)(*jtbl_008873E8)(count6 * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x40) == NULL) {
            func_0046d730(D_00713CD0, 0x14D);
        }
        *(u8 **)(arg0 + 0x3C) = *(u8 **)(arg0 + 0x40);
        for (i6 = 0; i6 < count6; i6++) {
            *(u8 **)(*(u8 **)(arg0 + 0x3C) + i6 * 4) =
                func_00485c80(*(u8 **)(*(u8 **)(arg1 + 0x3C)));
        }
        break;
    }
    case 7: {
        u8 *p;

        if (*(s32 *)(arg1 + 0x48) == 0) {
            func_0046d730(D_00713CD0, 0x156);
        }
        if (*(s32 *)(arg0 + 0x48) != 0) {
            func_004829c0(*(s32 *)(arg0 + 0x48));
        }
        *(s32 *)(arg0 + 0x48) = func_00482a70(*(s32 *)(arg1 + 0x48));
        if (*(s32 *)(arg0 + 0x5C) != 0) {
            func_0046d730(D_00713CD0, 0x15F);
        }
        func_0044ea90(D_00713CC0, 0x171);
        p = (u8 *)(*jtbl_008873E8)(0x30, 0x40000);
        func_0043f9c8(p, 0, 0x30);
        *(u8 **)(arg0 + 0x5C) = p;
        *(u16 *)(p + 0x18) = 0x19;
        *(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x1C) = arg0;
        break;
    }
    default:
        func_0046d730(D_00713CD0, 0x16A);
        break;
    }
    *(u16 *)(arg0 + 0xC) = *(u16 *)(arg1 + 0xC);
}

// FUN_004875D0
void func_004875d0(u8 *arg0, s32 arg1, void *arg2)
{
    if (*(u32 *)(arg0 + 0x4C) != 0) {
        func_00492cd0((u8 *)*(u32 *)(arg0 + 0x4C));
    }
    *(u32 *)(arg0 + 0x4C) = (u32)func_00492b20(arg1 & 0xFFFF, *(u32 *)(arg0 + 0), arg2);
    *(u8 *)(arg0 + 0xE) |= 1;
}




// FUN_00487650
void func_00487650(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x50);

    if (temp_4 != 0) {
        func_004833f0(temp_4);
    }
    switch (arg2) {
    case 1:
    case 4:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x20080027);
        return;
    case 2:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x200000A7);
        /* fallthrough */
    case 7:
        return;
    }
}

// FUN_00487710
void func_00487710(u8 *arg0, s32 arg1)
{
    void *temp_2 = (void *)func_00481300(arg1 & 0xFFFF);
    u8 *temp_2_2 = *(u8 **)temp_2;
    f32 f_10 = (f32)*(s32 *)(temp_2_2 + 0x10);
    f32 f_0c = (f32)*(s32 *)(temp_2_2 + 0xC);

    *(f32 *)(arg0 + 0x54) = f_0c / 2.0f / 16.0f;
    *(f32 *)(arg0 + 0x58) = f_10 / 2.0f / 16.0f;
    func_003c42b0(*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x50) + 0x10) + 0x18) + 0x20)), temp_2);
}
// FUN_004877B0
void func_004877b0(u8 *arg0, s32 arg1)
{
    void *temp_2 = func_00481390((void *)arg1);
    u8 *temp_2_2 = *(u8 **)temp_2;
    f32 f_10 = (f32)*(s32 *)(temp_2_2 + 0x10);
    f32 f_0c = (f32)*(s32 *)(temp_2_2 + 0xC);

    *(f32 *)(arg0 + 0x54) = f_0c / 2.0f / 16.0f;
    *(f32 *)(arg0 + 0x58) = f_10 / 2.0f / 16.0f;
    func_003c42b0(*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x50) + 0x10) + 0x18) + 0x20)), temp_2);
    func_003ef3a0(temp_2);
}




// FUN_00487860
void func_00487860(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x44);

    if (temp_4 != 0) {
        func_00481ee0(temp_4);
    }
    *(s32 *)(arg0 + 0x44) = func_00481d80(arg1);
}

// FUN_004878C0
void func_004878c0(u8 *arg0, void *arg1)
{
    u32 count;
    u32 i;

    if (*(s32 *)(arg0 + 0x4C) != 0) {
        count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
    } else {
        count = *(s32 *)(arg0 + 0);
    }
    if (*(s32 *)(arg0 + 0x38) != 0) {
        for (i = 0; i < count; i++) {
            func_004846d0(*(u8 **)(*(u8 **)(arg0 + 0x34) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x38));
        *(u8 **)(arg0 + 0x34) = NULL;
        *(u8 **)(arg0 + 0x38) = NULL;
    }
    if (count * 4 != 0) {
        func_0044ea90(D_00713CD0, 0x21C);
        *(u8 **)(arg0 + 0x38) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x38) == NULL) {
            func_0046d730(D_00713CD0, 0x21D);
        }
        *(u8 **)(arg0 + 0x34) = *(u8 **)(arg0 + 0x38);
        *(u8 **)(*(u8 **)(arg0 + 0x34)) = func_00484570((u8 *)arg1);
        for (i = 1; i < count; i++) {
            *(u8 **)(*(u8 **)(arg0 + 0x34) + i * 4) = func_00484830(*(u8 **)(*(u8 **)(arg0 + 0x34)));
        }
    }
}
// FUN_00487A30
void func_00487a30(u8 *arg0, void *arg1)
{
    u32 count;
    u32 i;

    if (*(s32 *)(arg0 + 0x4C) != 0) {
        count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
    } else {
        count = *(s32 *)(arg0 + 0);
    }
    if (*(s32 *)(arg0 + 0x40) != 0) {
        for (i = 0; i < count; i++) {
            func_00485b20(*(u8 **)(*(u8 **)(arg0 + 0x3C) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x40));
        *(u8 **)(arg0 + 0x3C) = NULL;
        *(u8 **)(arg0 + 0x40) = NULL;
    }
    if (count * 4 != 0) {
        func_0044ea90(D_00713CD0, 0x24F);
        *(u8 **)(arg0 + 0x40) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x40) == NULL) {
            func_0046d730(D_00713CD0, 0x250);
        }
        *(u8 **)(arg0 + 0x3C) = *(u8 **)(arg0 + 0x40);
        *(u8 **)(*(u8 **)(arg0 + 0x3C)) = func_00484bb0((u8 *)arg1);
        for (i = 1; i < count; i++) {
            *(u8 **)(*(u8 **)(arg0 + 0x3C) + i * 4) = func_00485c80(*(u8 **)(*(u8 **)(arg0 + 0x3C)));
        }
    }
}




// FUN_00487BA0
void func_00487ba0(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x48);

    if (temp_4 != 0) {
        func_004829c0(temp_4);
    }
    *(s32 *)(arg0 + 0x48) = func_00482800(arg1);
}



// FUN_00487C00
void func_00487c00(int param_1)
{
  if (*(int *)(param_1 + 0x4c) != 0) {
    func_00492d00(*(int *)(param_1 + 0x4c));
  }
  return;
}

/* measured: reconstructed full switch/VU0 particle path; retail and candidate differ only by temp_17/var_16 saved-register assignment (retail $s1/$s0, candidate $s0/$s1), nd 27, object 892B/window 896B. Tried saved-local declaration permutations, case-local splits, register qualifiers, pointer/count types, expression shapes, and O1; no improvement. Parked near-match. */
// Archived C body: build/WBHygiene_func_00487c30_archive.txt; no current park body remains.
/* measured: 27 differing words, 223/223 instrs, fnalign 49ed, obj892B/window896B; loopinv 27wd/49ed tie, schedule 194 (764B), commons 27 tie, prop 27 tie; decl-swap var_16-front 64ed (worse); temp_17/var_16 $s0/$s1 vs retail $s1/$s0 rotation stands from earliest hunk (retail[18] lw $s0 vs object $s1); no lb/lbu so s8 N/A; no sunk address chain so double-def N/A; VU0 lqc2/sqc2 split blocks reproduce. Banked near-match. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/promoted/effParticle.c func_00487c30 --pairs` banked 27; best ties 27 (all 8 singles except schedule/peephole plus 13 pairs among them); all 28 pairs neutral or worse (peephole 175-191, schedule 190-194). Singles loopinv/commons/prop already tie per above; pairs confirm $s0/$s1 rotation floor. fnalign retail/object 223/223 per assignment. Floor stands; production stays ASM. */
/* 2026-09-18 lead pass; section 7m exchanged-register-pair class, floor
   confirmed at 27 words.  223/223 instructions and every differing word is
   an instruction naming `var_16` or `temp_17`: retail puts the pointer
   loaded from `0x18(temp_18)` in $s0 and the count from `8(temp_18)` in
   $s1, this body has them the other way round.  The load order already
   matches retail, so it is the allocation and not the sequence.
   Declaration order does not reach it: moving `temp_17` above `var_19` ties
   at 27, while swapping `var_16` with `temp_18` costs 27 -> 42 and moving
   `var_16` after `var_19` costs the same.  One more member of the class
   documented in handoff 7m; stop here. */
// FUN_00487C30 NONMATCHING
#ifdef NON_MATCHING
void func_00487c30(u8 *arg0, f32 arg1)
{
    u8 spC0[16];
    u8 spB0[16];
    u8 spA0[16];
    u8 sp60[0x40];
    s32 *var_19;
    s32 temp_17;
    s32 var_18;
    u16 temp_5;
    u8 *temp_18;
    u8 *var_16;

    temp_18 = *(u8 **)(arg0 + 0x4C);
    temp_5 = *(u16 *)(arg0 + 0xC);
    switch (temp_5) {
    case 5:
        var_16 = *(u8 **)(temp_18 + 0x18);
        var_19 = *(s32 **)(arg0 + 0x34);
        temp_17 = *(s32 *)(temp_18 + 8);
        if ((*(u32 *)(temp_18 + 0xC) & 1) == 0) {
            var_18 = 0;
            while (var_18 < temp_17) {
                if (*(s32 *)(var_16 + 0x10) == 0) {
                    func_00484970(*var_19);
                }
                if (*(s32 *)(var_16 + 0x10) >= 0) {
                    func_00484a90(*var_19,
                                  *(f32 *)(var_16 + 0x18) * arg1);
                    func_00484a40(*var_19, var_16);
                    func_004849c0(*var_19);
                }
                var_18++;
                var_16 += 0x20;
                var_19++;
            }
            return;
        }
        func_00492df0(temp_18, spA0);
        func_00492db0(temp_18, spB0);
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf10, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spA0)
            : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf31, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spB0)
            : "$vf31", "memory");
        __asm__ volatile(
            ".set noreorder       \n"
            "sqc2 $vf28, 0(%0)    \n"
            "sqc2 $vf29, 16(%0)   \n"
            "sqc2 $vf30, 32(%0)   \n"
            "sqc2 $vf31, 48(%0)   \n"
            ".set reorder         \n"
            :
            : "r"(sp60)
            : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
        var_18 = 0;
        while (var_18 < temp_17) {
            if (*(s32 *)(var_16 + 0x10) >= 0) {
                __asm__ volatile(
                    ".set noreorder                  \n"
                    "lqc2 $vf28, 0(%0)                \n"
                    "lqc2 $vf29, 16(%0)               \n"
                    "lqc2 $vf30, 32(%0)               \n"
                    "lqc2 $vf31, 48(%0)               \n"
                    "lqc2 $vf10, 0(%1)                \n"
                    "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                    "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                    "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                    "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                    ".set reorder                    \n"
                    :
                    : "r"(sp60), "r"(var_16)
                    : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10",
                      "ACC", "memory");
                __asm__ volatile(
                    ".set noreorder       \n"
                    "sqc2 $vf10, 0(%0)    \n"
                    ".set reorder         \n"
                    :
                    : "r"(spC0)
                    : "$vf10", "memory");
                func_00484a90(*var_19,
                              *(f32 *)(var_16 + 0x18) * arg1);
                func_00484a40(*var_19, spC0);
                func_004849c0(*var_19);
            }
            var_18++;
            var_16 += 0x20;
            var_19++;
        }
        return;
    case 6:
        var_16 = *(u8 **)(temp_18 + 0x18);
        var_19 = *(s32 **)(arg0 + 0x3C);
        temp_17 = *(s32 *)(temp_18 + 8);
        if ((*(u32 *)(temp_18 + 0xC) & 1) == 0) {
            var_18 = 0;
            while (var_18 < temp_17) {
                if (*(s32 *)(var_16 + 0x10) == 0) {
                    func_00485fe0(*var_19);
                }
                if (*(s32 *)(var_16 + 0x10) >= 0) {
                    func_00486400(*var_19,
                                  *(f32 *)(var_16 + 0x18) * arg1);
                    func_004861f0(*var_19, var_16);
                    func_00485630(*var_19);
                }
                var_18++;
                var_16 += 0x20;
                var_19++;
            }
            return;
        }
        func_00492df0(temp_18, spA0);
        func_00492db0(temp_18, spB0);
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf10, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spA0)
            : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf31, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spB0)
            : "$vf31", "memory");
        __asm__ volatile(
            ".set noreorder       \n"
            "sqc2 $vf28, 0(%0)    \n"
            "sqc2 $vf29, 16(%0)   \n"
            "sqc2 $vf30, 32(%0)   \n"
            "sqc2 $vf31, 48(%0)   \n"
            ".set reorder         \n"
            :
            : "r"(sp60)
            : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
        var_18 = 0;
        while (var_18 < temp_17) {
            if (*(s32 *)(var_16 + 0x10) == 0) {
                func_00485fe0(*var_19);
            }
            if (*(s32 *)(var_16 + 0x10) >= 0) {
                __asm__ volatile(
                    ".set noreorder                  \n"
                    "lqc2 $vf28, 0(%0)                \n"
                    "lqc2 $vf29, 16(%0)               \n"
                    "lqc2 $vf30, 32(%0)               \n"
                    "lqc2 $vf31, 48(%0)               \n"
                    "lqc2 $vf10, 0(%1)                \n"
                    "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                    "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                    "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                    "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                    ".set reorder                    \n"
                    :
                    : "r"(sp60), "r"(var_16)
                    : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10",
                      "ACC", "memory");
                __asm__ volatile(
                    ".set noreorder       \n"
                    "sqc2 $vf10, 0(%0)    \n"
                    ".set reorder         \n"
                    :
                    : "r"(spC0)
                    : "$vf10", "memory");
                func_00486400(*var_19,
                              *(f32 *)(var_16 + 0x18) * arg1);
                func_004861f0(*var_19, spC0);
                func_00485630(*var_19);
            }
            var_18++;
            var_16 += 0x20;
            var_19++;
        }
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00487c30);
#endif
/* measured v3: 768 differing words (reloc-masked), retail 878 vs object 856 instrs (-22, -2.5% inside 3% gate), fnalign 733 edits +4 reloc-only. VU parent (mfc1 $3) + VU colour (lui 0x437F) from effObjectParticle 004aed70 idiom; scalar parent v1 781/764 outside gate, VU colour v2 791/870 inside, VU parent v3 768/856 best. Pragmas ties/worse: v1 commons_off 793 loopinv_on 789 unroll_off 781 sched_off 781; v3 commons 773 loopinv 778 unroll 768 tie sched 768 tie. Fresh counters i1-i6 per loop (7n), pointer-increment subscript matches retail addu. Biggest residuals: prologue frame 0x1C0 vs 0x1D0 + saved-reg colour, buffer stride reloads, float-wrap c.le.s polarity. Banked as guarded floor. */
// FUN_00487FB0 NONMATCHING
#ifdef NON_MATCHING
void func_00487fb0(u8 *arg0, f32 arg1)
{
    extern void func_003a5180(u8 *a);
    extern void func_003a2770(u8 *a, u8 *b, s32 c, s32 d);
    extern s32 func_003a2920(s32 a);
    extern void func_00492df0(void *a, void *b);
    extern void func_00492db0(void *a, void *b);
    extern void func_004bceb0(void);
    extern void func_00482730(int a, u32 b);
    extern void func_00482700(int a, float *b);
    extern s32 func_00482790(u8 **a, u32 b);
    extern void func_003c42b0(void *a, void *b);
    extern void func_004834e0(u8 *a, u16 b);
    extern void func_00483490(u8 *a, u16 b);
    extern void func_00484ae0(u8 *a, s32 b);
    extern void func_00484a00(u8 *a);
    extern void func_004865c0(u8 *a, s32 b);
    extern void func_00485870(s32 a);
    extern u8 *func_00481460(u16 a);
    extern void func_00460ac0(void *a, void *b);
    extern void func_0046d730(void *a, s32 b);
    extern f32 fGpffff8044;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff80a0;
    extern f32 fGpffff80a4;
    extern f32 fGpffff80a8;
    extern f32 fGpffff80ac;
    extern f32 fGpffff80b0;
    extern f32 fGpffff80b4;
    extern f32 fGpffff80b8;
    extern s32 iGpffffb610;
    extern u8 D_00713CD0[];
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    f32 parent[4] __attribute__((aligned(16)));
    u8 snapA[16] __attribute__((aligned(16)));
    u8 snapB[16] __attribute__((aligned(16)));
    u8 base[64] __attribute__((aligned(16)));
    u8 tmp160[16] __attribute__((aligned(16)));
    u8 tmpB0[64] __attribute__((aligned(16)));
    u8 *b178_ptr; s32 b178_stride;
    u8 *b180_ptr; s32 b180_stride;
    u8 *b188_ptr; s32 b188_stride;
    u8 *b190_ptr; s32 b190_stride;
    u8 *b198_ptr; s32 b198_stride;
    u8 *temp_19;
    u8 *var_18;
    u8 *temp_17;
    u8 *temp_22;
    u8 *temp_23;
    s32 temp_16;
    s32 var_21;
    s32 var_22;
    f32 temp_f21;
    f32 temp_f20;
    s32 cw;
    s32 i1; s32 i2; s32 i3; s32 i4; s32 i5; s32 i6;
    {
        s32 w = *(s32 *)(arg0 + 4);
        f32 sc = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 $3, %1\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "sqc2 $vf10, 0(%2)\n"
            : : "r"(&w), "f"(sc), "r"(parent) : "$2", "$3", "$vf2", "$vf10", "memory");
    }
    temp_19 = *(u8 **)(arg0 + 0x4C);
    temp_16 = *(s32 *)(temp_19 + 8);
    if (temp_16 == 0 || *(s32 *)(temp_19 + 0x10) == 0) {
        return;
    }
    var_18 = *(u8 **)(temp_19 + 0x18);
    switch (*(u16 *)(arg0 + 0xC)) {
    case 1:
    case 4:
        var_21 = 0;
        temp_f21 = *(f32 *)(arg0 + 0x54) * arg1;
        temp_f20 = *(f32 *)(arg0 + 0x58) * arg1;
        temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x50) + 0x10);
        temp_22 = *(u8 **)(temp_19 + 0x20);
        func_003a5180(temp_17);
        func_003a2770(temp_17, (u8 *)&b190_ptr, 1, 0x40000000);
        func_003a2770(temp_17, (u8 *)&b180_ptr, 2, 0x40000000);
        func_003a2770(temp_17, (u8 *)&b188_ptr, 4, 0x40000000);
        func_003a2770(temp_17, (u8 *)&b198_ptr, 0x20, 0x40000000);
        if ((*(u32 *)(temp_19 + 0xC) & 1) == 0) {
            f32 f3 = fGpffff8080;
            f32 f4 = fGpffff8084;
            f32 f2 = fGpffff80a0;
            i1 = 0;
            while (i1 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    *(f32 *)(b190_ptr + 0) = *(f32 *)(var_18 + 0);
                    *(f32 *)(b190_ptr + 4) = *(f32 *)(var_18 + 4);
                    *(f32 *)(b190_ptr + 8) = *(f32 *)(var_18 + 8);
                    b190_ptr += b190_stride;
                    *(s32 *)b180_ptr = *(s32 *)(var_18 + 0x14);
                    b180_ptr += b180_stride;
                    {
                        f32 f = *(f32 *)(var_18 + 0x1C);
                        if (f > f4) {
                            while (f > f4) { f -= f3; }
                        } else if (f < f2) {
                            while (f < f2) { f += f3; }
                        }
                        *(f32 *)(var_18 + 0x1C) = f;
                        *(f32 *)b198_ptr = f;
                        b198_ptr += b198_stride;
                    }
                    {
                        f32 s = *(f32 *)(var_18 + 0x18);
                        *(f32 *)(b188_ptr + 0) = temp_f21 * s;
                        *(f32 *)(b188_ptr + 4) = temp_f20 * s;
                        b188_ptr += b188_stride;
                    }
                    var_21++;
                }
                i1++;
                var_18 += 0x20;
            }
        } else {
            f32 f4 = fGpffff8084;
            f32 f3 = fGpffff80a4;
            f32 f2 = fGpffff80a8;
            func_00492df0(temp_19, snapA);
            func_00492db0(temp_19, snapB);
            __asm__ volatile("lqc2 $vf10, 0(%0)\n" : : "r"(snapA) : "$vf10", "memory");
            func_004bceb0();
            __asm__ volatile("lqc2 $vf31, 0(%0)\n" : : "r"(snapB) : "$vf31", "memory");
            __asm__ volatile("sqc2 $vf28, 0(%0)\nsqc2 $vf29, 16(%0)\nsqc2 $vf30, 32(%0)\nsqc2 $vf31, 48(%0)\n" : : "r"(base) : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            i2 = 0;
            while (i2 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    __asm__ volatile("lqc2 $vf28, 0(%0)\nlqc2 $vf29, 16(%0)\nlqc2 $vf30, 32(%0)\nlqc2 $vf31, 48(%0)\nlqc2 $vf10, 0(%1)\nvmulax.xyzw $ACC, $vf28, $vf10x\nvmadday.xyzw $ACC, $vf29, $vf10y\nvmaddaz.xyzw $ACC, $vf30, $vf10z\nvmaddw.xyzw $vf10, $vf31, $vf0w\n" : : "r"(base), "r"(var_18) : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                    __asm__ volatile("sqc2 $vf10, 0(%0)\n" : : "r"(tmp160) : "$vf10", "memory");
                    *(f32 *)(b190_ptr + 0) = *(f32 *)(tmp160 + 0);
                    *(f32 *)(b190_ptr + 4) = *(f32 *)(tmp160 + 4);
                    *(f32 *)(b190_ptr + 8) = *(f32 *)(tmp160 + 8);
                    b190_ptr += b190_stride;
                    *(s32 *)b180_ptr = *(s32 *)(var_18 + 0x14);
                    b180_ptr += b180_stride;
                    {
                        f32 f = *(f32 *)(var_18 + 0x1C);
                        if (f > f4) {
                            while (f > f4) { f -= f3; }
                        } else if (f < f2) {
                            while (f < f2) { f += f3; }
                        }
                        *(f32 *)(var_18 + 0x1C) = f;
                        *(f32 *)b198_ptr = f;
                        b198_ptr += b198_stride;
                    }
                    {
                        f32 s = *(f32 *)(var_18 + 0x18);
                        *(f32 *)(b188_ptr + 0) = temp_f21 * s;
                        *(f32 *)(b188_ptr + 4) = temp_f20 * s;
                        b188_ptr += b188_stride;
                    }
                    var_21++;
                }
                i2++;
                var_18 += 0x20;
            }
        }
        func_003a2920((s32)temp_17);
        if (var_21 != 0) {
            s32 col = *(s32 *)(arg0 + 4);
            u8 *p6 = *(u8 **)(*(u8 **)(temp_17 + 0x18) + 0x20);
            *(u8 *)(p6 + 4) = (u8)col;
            *(u8 *)(p6 + 5) = (u8)(col >> 8);
            *(u8 *)(p6 + 6) = (u8)(col >> 16);
            *(u8 *)(p6 + 7) = (u8)(col >> 24);
            {
                u8 *b = *(u8 **)(temp_17 + iGpffffb610);
                *(s32 *)(b + 0x40) = *(s32 *)(b + 0x40) | 0x800000;
                *(s32 *)(b + 4) = var_21;
            }
            cw = (s32)(*(u16 *)(temp_22 + 0x54));
            func_004834e0(*(u8 **)(arg0 + 0x50), (u16)cw);
            func_00483490(*(u8 **)(arg0 + 0x50), (u16)cw);
        }
        break;
    case 2:
        {
            u8 *pp = *(u8 **)(arg0 + 0x44);
            if (pp == 0) { func_0046d730(D_00713CD0, 0x380); }
            var_22 = 0;
            temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x50) + 0x10);
            temp_23 = *(u8 **)(temp_19 + 0x20);
            func_003a5180(temp_17);
            func_003a2770(temp_17, (u8 *)&b190_ptr, 1, 0x40000000);
            func_003a2770(temp_17, (u8 *)&b180_ptr, 2, 0x40000000);
            func_003a2770(temp_17, (u8 *)&b188_ptr, 4, 0x40000000);
            func_003a2770(temp_17, (u8 *)&b198_ptr, 0x20, 0x40000000);
            func_003a2770(temp_17, (u8 *)&b178_ptr, 0x80, 0x40000000);
            {
                s32 t = func_00482790((u8 **)pp, 0);
                func_003c42b0(*(void **)(*(u8 **)(temp_17 + 0x18) + 0x20), (void *)t);
            }
            if ((*(u32 *)(temp_19 + 0xC) & 1) == 0) {
                i3 = 0;
                while (i3 < temp_16) {
                    if (*(s32 *)(var_18 + 0x10) >= 0) {
                        func_00482730((int)pp, *(u32 *)(var_18 + 0x10));
                        func_00482700((int)pp, (float *)tmpB0);
                        *(f32 *)(b178_ptr + 0) = *(f32 *)(tmpB0 + 0x18);
                        *(f32 *)(b178_ptr + 4) = *(f32 *)(tmpB0 + 0x1C);
                        *(f32 *)(b178_ptr + 8) = *(f32 *)(tmpB0 + 0x20);
                        *(f32 *)(b178_ptr + 12) = *(f32 *)(tmpB0 + 0x24);
                        b178_ptr += b178_stride;
                        *(f32 *)(b190_ptr + 0) = *(f32 *)(var_18 + 0);
                        *(f32 *)(b190_ptr + 4) = *(f32 *)(var_18 + 4);
                        *(f32 *)(b190_ptr + 8) = *(f32 *)(var_18 + 8);
                        b190_ptr += b190_stride;
                        {
                            s32 cw1 = *(s32 *)(var_18 + 0x14);
                            s32 cw2 = *(s32 *)(tmpB0 + 0x2C);
                            s32 packed;
                            f32 sc = fGpffff8044;
                            __asm__ volatile(
                                "lw $2, 0(%0)\n"
                                "pextlb $2, $0, $2\n"
                                "pextlh $2, $0, $2\n"
                                "qmtc2.ni $2, $vf11\n"
                                "vitof0.xyzw $vf11, $vf11\n"
                                "mfc1 $2, %1\n"
                                "nop\n"
                                "qmtc2.ni $2, $vf2\n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                                "lw $2, 0(%2)\n"
                                "pextlb $2, $0, $2\n"
                                "pextlh $2, $0, $2\n"
                                "qmtc2.ni $2, $vf10\n"
                                "vitof0.xyzw $vf10, $vf10\n"
                                "mfc1 $2, %1\n"
                                "nop\n"
                                "qmtc2.ni $2, $vf2\n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                "vmul.xyzw $vf10, $vf10, $vf11\n"
                                "lui $2, 0x437F\n"
                                "qmtc2.ni $2, $vf2\n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                "vftoi0.xyzw $vf10, $vf10\n"
                                "qmfc2.ni $2, $vf10\n"
                                "ppach $2, $0, $2\n"
                                "ppacb $2, $0, $2\n"
                                "sw $2, 0(%3)\n"
                                : : "r"(&cw1), "f"(sc), "r"(&cw2), "r"(&packed) : "$2", "$vf2", "$vf10", "$vf11", "memory");
                            *(s32 *)b180_ptr = packed;
                            b180_ptr += b180_stride;
                        }
                        {
                            f32 f = *(f32 *)(var_18 + 0x1C) + *(f32 *)(tmpB0 + 0x10);
                            f32 mx = fGpffff8084;
                            f32 st = fGpffff80ac;
                            f32 mn = fGpffff80b0;
                            if (f > mx) { while (f > mx) { f -= st; } }
                            else if (f < mn) { while (f < mn) { f += fGpffff80b4; } }
                            *(f32 *)b198_ptr = f;
                            b198_ptr += b198_stride;
                        }
                        {
                            f32 s = *(f32 *)(var_18 + 0x18) * arg1;
                            *(f32 *)(b188_ptr + 0) = *(f32 *)(tmpB0 + 0x08) * s;
                            *(f32 *)(b188_ptr + 4) = *(f32 *)(tmpB0 + 0x0C) * s;
                            b188_ptr += b188_stride;
                        }
                        var_22++;
                    }
                    i3++;
                    var_18 += 0x20;
                }
            } else {
                func_00492df0(temp_19, snapA);
                func_00492db0(temp_19, snapB);
                __asm__ volatile("lqc2 $vf10, 0(%0)\n" : : "r"(snapA) : "$vf10", "memory");
                func_004bceb0();
                __asm__ volatile("lqc2 $vf31, 0(%0)\n" : : "r"(snapB) : "$vf31", "memory");
                __asm__ volatile("sqc2 $vf28, 0(%0)\nsqc2 $vf29, 16(%0)\nsqc2 $vf30, 32(%0)\nsqc2 $vf31, 48(%0)\n" : : "r"(base) : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
                i4 = 0;
                while (i4 < temp_16) {
                    if (*(s32 *)(var_18 + 0x10) >= 0) {
                        func_00482730((int)pp, *(u32 *)(var_18 + 0x10));
                        func_00482700((int)pp, (float *)tmpB0);
                        __asm__ volatile("lqc2 $vf28, 0(%0)\nlqc2 $vf29, 16(%0)\nlqc2 $vf30, 32(%0)\nlqc2 $vf31, 48(%0)\nlqc2 $vf10, 0(%1)\nvmulax.xyzw $ACC, $vf28, $vf10x\nvmadday.xyzw $ACC, $vf29, $vf10y\nvmaddaz.xyzw $ACC, $vf30, $vf10z\nvmaddw.xyzw $vf10, $vf31, $vf0w\n" : : "r"(base), "r"(var_18) : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                        __asm__ volatile("sqc2 $vf10, 0(%0)\n" : : "r"(tmp160) : "$vf10", "memory");
                        *(f32 *)(b178_ptr + 0) = *(f32 *)(tmpB0 + 0x18);
                        *(f32 *)(b178_ptr + 4) = *(f32 *)(tmpB0 + 0x1C);
                        *(f32 *)(b178_ptr + 8) = *(f32 *)(tmpB0 + 0x20);
                        *(f32 *)(b178_ptr + 12) = *(f32 *)(tmpB0 + 0x24);
                        b178_ptr += b178_stride;
                        *(f32 *)(b190_ptr + 0) = *(f32 *)(tmp160 + 0);
                        *(f32 *)(b190_ptr + 4) = *(f32 *)(tmp160 + 4);
                        *(f32 *)(b190_ptr + 8) = *(f32 *)(tmp160 + 8);
                        b190_ptr += b190_stride;
                        {
                            s32 cw1 = *(s32 *)(var_18 + 0x14);
                            s32 cw2 = *(s32 *)(tmpB0 + 0x2C);
                            s32 packed;
                            f32 sc = fGpffff8044;
                            __asm__ volatile(
                                "lw $2, 0(%0)\n"
                                "pextlb $2, $0, $2\n"
                                "pextlh $2, $0, $2\n"
                                "qmtc2.ni $2, $vf11\n"
                                "vitof0.xyzw $vf11, $vf11\n"
                                "mfc1 $2, %1\n"
                                "nop\n"
                                "qmtc2.ni $2, $vf2\n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                                "lw $2, 0(%2)\n"
                                "pextlb $2, $0, $2\n"
                                "pextlh $2, $0, $2\n"
                                "qmtc2.ni $2, $vf10\n"
                                "vitof0.xyzw $vf10, $vf10\n"
                                "mfc1 $2, %1\n"
                                "nop\n"
                                "qmtc2.ni $2, $vf2\n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                "vmul.xyzw $vf10, $vf10, $vf11\n"
                                "lui $2, 0x437F\n"
                                "qmtc2.ni $2, $vf2\n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                "vftoi0.xyzw $vf10, $vf10\n"
                                "qmfc2.ni $2, $vf10\n"
                                "ppach $2, $0, $2\n"
                                "ppacb $2, $0, $2\n"
                                "sw $2, 0(%3)\n"
                                : : "r"(&cw1), "f"(sc), "r"(&cw2), "r"(&packed) : "$2", "$vf2", "$vf10", "$vf11", "memory");
                            *(s32 *)b180_ptr = packed;
                            b180_ptr += b180_stride;
                        }
                        {
                            f32 f = *(f32 *)(var_18 + 0x1C) + *(f32 *)(tmpB0 + 0x10);
                            f32 mx = fGpffff8084;
                            f32 st = fGpffff80b4;
                            f32 mn = fGpffff80b8;
                            if (f > mx) { while (f > mx) { f -= st; } }
                            else if (f < mn) { while (f < mn) { f += st; } }
                            *(f32 *)b198_ptr = f;
                            b198_ptr += b198_stride;
                        }
                        {
                            f32 s = *(f32 *)(var_18 + 0x18) * arg1;
                            *(f32 *)(b188_ptr + 0) = *(f32 *)(tmpB0 + 0x08) * s;
                            *(f32 *)(b188_ptr + 4) = *(f32 *)(tmpB0 + 0x0C) * s;
                            b188_ptr += b188_stride;
                        }
                        var_22++;
                    }
                    i4++;
                    var_18 += 0x20;
                }
            }
            func_003a2920((s32)temp_17);
            if (var_22 != 0) {
                s32 col = *(s32 *)(arg0 + 4);
                u8 *p6 = *(u8 **)(*(u8 **)(temp_17 + 0x18) + 0x20);
                *(u8 *)(p6 + 4) = (u8)col;
                *(u8 *)(p6 + 5) = (u8)(col >> 8);
                *(u8 *)(p6 + 6) = (u8)(col >> 16);
                *(u8 *)(p6 + 7) = (u8)(col >> 24);
                {
                    u8 *b = *(u8 **)(temp_17 + iGpffffb610);
                    *(s32 *)(b + 0x40) = *(s32 *)(b + 0x40) | 0x800000;
                    *(s32 *)(b + 4) = var_22;
                }
                cw = (s32)(*(u16 *)(temp_23 + 0x54));
                func_004834e0(*(u8 **)(arg0 + 0x50), (u16)cw);
                func_00483490(*(u8 **)(arg0 + 0x50), (u16)cw);
            }
        }
        break;
    case 5:
        {
            s32 *plist = *(s32 **)(arg0 + 0x34);
            if (plist == 0) { func_0046d730(D_00713CD0, 0x3F3); }
            i5 = 0;
            while (i5 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    s32 cw = *(s32 *)(var_18 + 0x14);
                    s32 packed;
                    f32 sc = fGpffff8044;
                    __asm__ volatile(
                        "lw $2, 0(%0)\n"
                        "pextlb $2, $0, $2\n"
                        "pextlh $2, $0, $2\n"
                        "qmtc2.ni $2, $vf10\n"
                        "vitof0.xyzw $vf10, $vf10\n"
                        "mfc1 $2, %1\n"
                        "nop\n"
                        "qmtc2.ni $2, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "lqc2 $vf11, 0(%2)\n"
                        "vmul.xyzw $vf10, $vf10, $vf11\n"
                        "lui $2, 0x437F\n"
                        "qmtc2.ni $2, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "vftoi0.xyzw $vf10, $vf10\n"
                        "qmfc2.ni $2, $vf10\n"
                        "ppach $2, $0, $2\n"
                        "ppacb $2, $0, $2\n"
                        "sw $2, 0(%3)\n"
                        : : "r"(&cw), "f"(sc), "r"(parent), "r"(&packed) : "$2", "$vf2", "$vf10", "$vf11", "memory");
                    func_00484ae0((u8 *)*plist, packed);
                    func_00484a00((u8 *)*plist);
                }
                i5++;
                var_18 += 0x20;
                plist++;
            }
        }
        break;
    case 6:
        {
            s32 *plist = *(s32 **)(arg0 + 0x3C);
            if (plist == 0) { func_0046d730(D_00713CD0, 0x406); }
            i6 = 0;
            while (i6 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) >= 0) {
                    s32 cw = *(s32 *)(var_18 + 0x14);
                    s32 packed;
                    f32 sc = fGpffff8044;
                    __asm__ volatile(
                        "lw $2, 0(%0)\n"
                        "pextlb $2, $0, $2\n"
                        "pextlh $2, $0, $2\n"
                        "qmtc2.ni $2, $vf10\n"
                        "vitof0.xyzw $vf10, $vf10\n"
                        "mfc1 $2, %1\n"
                        "nop\n"
                        "qmtc2.ni $2, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "lqc2 $vf11, 0(%2)\n"
                        "vmul.xyzw $vf10, $vf10, $vf11\n"
                        "lui $2, 0x437F\n"
                        "qmtc2.ni $2, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "vftoi0.xyzw $vf10, $vf10\n"
                        "qmfc2.ni $2, $vf10\n"
                        "ppach $2, $0, $2\n"
                        "ppacb $2, $0, $2\n"
                        "sw $2, 0(%3)\n"
                        : : "r"(&cw), "f"(sc), "r"(parent), "r"(&packed) : "$2", "$vf2", "$vf10", "$vf11", "memory");
                    func_004865c0((u8 *)*plist, packed);
                    func_00485870(*plist);
                }
                i6++;
                var_18 += 0x20;
                plist++;
            }
        }
        break;
    case 7:
        {
            u8 *t = *(u8 **)(temp_19 + 0x20);
            *(s32 *)(*(u8 **)(arg0 + 0x5C) + 0) = 0;
            *(s32 *)(*(u8 **)(arg0 + 0x5C) + 4) = 0;
            {
                u8 *pb = func_00481460(*(u16 *)(t + 0x54));
                func_00460ac0(pb, *(u8 **)(arg0 + 0x5C));
            }
        }
        break;
    default:
        func_0046d730(D_00713CD0, 0x41D);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00487fb0);
#endif
// FUN_00488D70
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00488d70);
