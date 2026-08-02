/* Consolidated Persona 4 source units. */
/* Original translation unit btlCutin.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern u8 *iGpffffb3ac;
extern void func_00485b20();
extern void func_001fa190();
extern u8 *func_00194470();
extern s32 func_001fa370();


// FUN_001F9CF0
INCLUDE_ASM("asm/nonmatchings/btlCutin", func_001f9cf0);

// FUN_001F9FA0
INCLUDE_ASM("asm/nonmatchings/btlCutin", func_001f9fa0);

// FUN_001FA110
INCLUDE_ASM("asm/nonmatchings/btlCutin", func_001fa110);

// FUN_001FA190
INCLUDE_ASM("asm/nonmatchings/btlCutin", func_001fa190);

// FUN_001FA320
void func_001fa320(void) {
    u8 *p = func_00194470(0xC01, 4);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x6C) = (void *)func_001fa190;
    **(s32 **)(p + 0x78) = 0;
}

// FUN_001FA370
s32 func_001fa370(void) {
    s32 i;
    s32 off;
    u8 *base;
    u8 *p;
    s32 h;

    for (i = 0; i < 4; i++) {
        base = iGpffffb3ac;
        off = i * 4;
        p = base + off;
        if (*(s32 *)(p + 0xB6C) != 0) {
            *(s32 *)(base + 0xB4C) |= 1;
        } else {
            h = *(s32 *)(p + 0xB5C);
            if (h != 0) {
                func_00485b20(h);
                *(s32 *)(iGpffffb3ac + off + 0xB5C) = 0;
            }
        }
    }
    base = iGpffffb3ac;
    if (*(s32 *)(base + 0xB58) != 0) {
        *(s32 *)(base + 0xB4C) |= 1;
    } else {
        h = *(s32 *)(base + 0xB54);
        if (h != 0) {
            func_00485b20(h);
            *(s32 *)(iGpffffb3ac + 0xB54) = 0;
        }
    }
    return 1;
}

// FUN_001FA450
void func_001fa450(void) {
    u8 *p = func_00194470(0xC02, 0);

    *(u8 *)(p + 0x47) &= 0xEE;
    *(void **)(p + 0x6C) = (void *)func_001fa370;
}

// FUN_001FA490
INCLUDE_ASM("asm/nonmatchings/btlCutin", func_001fa490);
