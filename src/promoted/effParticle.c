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
// FUN_00486B00
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00486b00);

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
// FUN_00487C30
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00487c30);
// FUN_00487FB0
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00487fb0);
// FUN_00488D70
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00488d70);
