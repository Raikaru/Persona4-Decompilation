/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonTrack.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void func_00486e10(void *arg0);
extern void func_00494680(void *arg0);
extern void func_00492cd0(u8 *arg0);
extern void func_00492d00(int arg0);
extern void func_00492dd0(int arg0);
extern void func_00492e10(int arg0);
extern void func_00492e30(u16 *arg0);
extern void func_00489f40(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern char D_00713E20[];
extern char D_00713E30[];
extern u8 *func_00484490(u8 *obj);
extern s32 func_004844d0(u8 *obj);
extern u8 *func_00486a50(u8 *arg0);
extern u8 *func_00483270(u8 *arg0);
extern void func_00487160(void *arg0, void *arg1);
extern u8 *func_00492b20(u16 arg0, u32 arg1, void *arg2);
extern void func_004941f0(void *arg0, void *arg1);
extern u8 *func_00493e60(u16 arg0, u16 arg1);
extern void func_004936d0(u8 *arg0, u8 *arg1);
extern void func_00493790(u8 *arg0, u16 arg1, u8 *arg2);
extern void func_00493820(u8 *arg0, u16 arg1, u8 *arg2);
extern void func_00492df0(void *arg0, u32 *arg1);
extern void func_00492db0(void *arg0, u32 *arg1);
extern void func_00484350(void *arg0, void *arg1, void *arg2, f32 arg3);
extern void func_00487fb0(void *arg0, f32 arg1);
extern void func_00495090(void *arg0, u32 arg1);
extern void func_00492d10(void *arg0);
extern s32 func_00494710(void *arg0, u32 arg1);
extern void func_00494740(void *arg0, u32 arg1, f32 arg2, void *arg3);
extern void func_004940d0(void *arg0, u32 arg1, void *arg2);
extern void func_004946f0(void *arg0, u32 arg1);
extern void func_004946d0(void *arg0, u32 arg1);
extern void func_00494f90(void *arg0);
extern void func_00494ff0(void *arg0);
extern u8 *func_00483e10(u16 arg0, u16 arg1, void *arg2, s32 arg3, s32 arg4);
extern u8 *func_00483c40(u16 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern void func_00487650(void *arg0, void *arg1);
extern void func_004877b0(void *arg0, void *arg1);
extern void func_00487860(void *arg0, void *arg1);
extern void func_00487710(void *arg0, void *arg1);
extern void func_004878c0(void *arg0, void *arg1);
extern void func_00487a30(void *arg0, void *arg1);
extern void func_00487ba0(void *arg0, void *arg1);
extern u8 D_00764C54[4];
extern f32 D_00761134;
extern u8 D_00922D80[];
extern u8 D_00713310[];
extern u8 D_00713420[];



// FUN_00492E70
void *func_00492e70(u32 arg0)
{
    u8 *w;

    func_0044ea90(&D_00713E20, 0x171);
    w = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    func_0043f9c8(w, 0, 0x38);
    if (w == NULL) {
        func_0046d730(&D_00713E30, 0x32);
    }
    *(u32 *)(w + 0) = arg0;
    *(u32 *)(w + 4) = -1;
    *(f32 *)(w + 8) = 1.0f;
    *(u16 *)(w + 0x34) = 1;
    return w;
}

// FUN_00492F20
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00492f20);

// FUN_00493080
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493080);

// FUN_00493200
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493200);

// FUN_00493320
void func_00493320(u8 *arg0)
{
    u32 temp_4;
    u32 temp_4_2;
    u8 *temp_4_3;

    temp_4 = *(u32 *)(arg0 + 0x2C);
    if (temp_4 != 0) {
        func_00486e10((void *)temp_4);
    }
    temp_4_2 = *(u32 *)(arg0 + 0x28);
    if (temp_4_2 != 0) {
        func_00494680((void *)temp_4_2);
    }
    temp_4_3 = *(u8 **)(arg0 + 0x30);
    if (temp_4_3 != NULL) {
        func_00492cd0(temp_4_3);
    }
    jtbl_008873EC[0](arg0);
}
// FUN_004933A0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_004933a0);

// FUN_00493530
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493530);

// FUN_004936D0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_004936d0);

// FUN_00493790
void func_00493790(u8 *arg0, u16 arg1, u8 *arg2)
{
    u8 *v;

    func_0043f810(arg0 + 0xC, arg2, 0x1C);
    if (*(u32 *)(arg0 + 0) != 0) {
        if (*(u32 *)(arg0 + 0x28) != 0) {
            func_00494680((void *)*(u32 *)(arg0 + 0x28));
        }
        v = func_00493e60(*(u16 *)(arg0 + 0), *(u16 *)arg2);
        *(u8 **)(arg0 + 0x28) = v;
        func_004941f0(v, arg2 + 8);
    }
}

// FUN_00493820
void func_00493820(u8 *arg0, u16 arg1, u8 *arg2)
{
    if (*(u32 *)(arg0 + 0x30) != 0) {
        func_00492cd0((u8 *)*(u32 *)(arg0 + 0x30));
    }
    if (*(u32 *)(arg2 + 0xC0) != 0) {
        func_0046d730(&D_00713E30, 0x14E);
    }
    *(u32 *)(arg0 + 0x30) = (u32)func_00492b20(arg1 & 0xFFFF, *(u32 *)(arg0 + 0), arg2);
}

// FUN_004938B0
void func_004938b0(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x30);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// FUN_004938E0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_004938e0);

// FUN_00493B90
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493b90);

// FUN_00493C90
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493c90);

// FUN_00493DA0
void func_00493da0(u8 *arg0)
{
    func_00492dd0(*(u32 *)(arg0 + 0x30));
}

// FUN_00493DD0
void func_00493dd0(u8 *arg0)
{
    func_00492e10(*(u32 *)(arg0 + 0x30));
}

// FUN_00493E00
void func_00493e00(u8 *arg0, u32 arg1)
{
    u32 temp_4;

    *(u32 *)(arg0 + 4) = arg1;
    temp_4 = *(u32 *)(arg0 + 0x2C);
    if (temp_4 != 0) {
        func_00489f40((void *)temp_4);
    }
}

// FUN_00493E30
void func_00493e30(u8 *arg0, f32 fparg0)
{
    *(f32 *)(arg0 + 8) = fparg0;
    func_00492e30((u16 *)*(u32 *)(arg0 + 0x30));
}

// FUN_00493E60
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493e60);

