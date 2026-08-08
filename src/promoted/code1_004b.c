#include "include_asm.h"
#include "type.h"
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);
extern void func_00484bb0();
extern void func_00485b20();
extern void func_00485fe0();
extern void func_00485630();
extern void func_00485c80();
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

extern void (*jtbl_008873EC[])(u8 *arg0);

// FUN_004B0F70
void func_004b0f70(void *object) {
    func_004b0ce0(object, 0);
}


extern void func_004b0ce0();


// FUN_004B0FA0
void func_004b0fa0(void *object) {
    func_004b0ce0(object, 1);
}


extern void func_004865c0();


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

// FUN_004B10F0
void func_004b10f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x4) = arg1;
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
void func_004b1190(void)
{
    func_00485630();
}

// FUN_004B11B0
void func_004b11b0(void)
{
    func_00485c80();
}

// FUN_004B1290
void func_004b1290(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    u8 scratch[16];

    func_004bcf20(iGpffff836c * arg1, iGpffff836c * arg2, iGpffff836c * arg3);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(scratch) : "memory");
    func_00486330(arg0, scratch);
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

// FUN_004B1AA0
void func_004b1aa0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x8) = 0;
}

// FUN_004B3250
void func_004b3250(s32 arg0)
{
    iGpffffbb9c = arg0;
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
