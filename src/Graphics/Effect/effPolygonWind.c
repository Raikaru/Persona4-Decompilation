#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonWind.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void *func_004844d0(void);
extern void *func_00484490(void *);
extern void func_0046d730(void *, s32);
extern void *func_004a5630(s32, void *);
extern char D_00714134[];
extern char D_00714130[];
extern char D_00714110[];

// FUN_004A20B0
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a20b0);

// FUN_004A21E0
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a21e0);

// FUN_004A2310
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a2310);

// FUN_004A2C90
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a2c90);

// FUN_004A3010
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a3010);

// FUN_004A30E0
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a30e0);

// FUN_004A33E0
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a33e0);

// FUN_004A3510
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a3510);

// FUN_004A3640
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a3640);

// FUN_004A4000
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4000);

// FUN_004A4380
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4380);

// FUN_004A4450
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4450);

// FUN_004A4790
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4790);

// FUN_004A48D0
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a48d0);

// FUN_004A4A10
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a4a10);

// FUN_004A52B0
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a52b0);

// FUN_004A5630
INCLUDE_ASM("asm/nonmatchings/effPolygonWind", func_004a5630);

// FUN_004A5750
void *func_004a5750(u8 *arg0)
{
    u8 *p16;
    u8 *p19;
    u8 *p18;
    u8 *p17;
    u32 idx;

    p18 = func_004844d0();
    if (p18 == NULL) {
        func_0046d730(D_00714110, 0x5D5);
    }
    switch (*(u16 *)(arg0 + 0x1C)) {
    case 1:
        break;
    case 4:
        p18 = NULL;
        break;
    default:
        func_0046d730(D_00714110, 0x5DE);
        break;
    }
    p19 = func_00484490(arg0);
    if (p19 == NULL) {
        func_0046d730(D_00714110, 0x5E3);
    }
    p16 = (u8 *)(*(u16 *)(arg0 + 0xC) & 0xFFFF);
    p17 = func_004a5630((s32)p16, p19);
    idx = ((u32)p16 & 0xFFFF) * 28;
    *(u32 *)(p17 + 0x3C) = (u32)((void *(*)(void *, void *))(*(void **)(D_00714134 + idx)))(p19, p18);
    ((void (*)(void *))(*(void **)(D_00714130 + idx)))(p17);
    if (p17 == NULL) {
        func_0046d730(D_00714110, 0x5E5);
    }
    return p17;
}
