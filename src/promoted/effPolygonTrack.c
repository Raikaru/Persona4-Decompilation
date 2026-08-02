/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonTrack.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void func_00486e10(void *arg0);
extern void func_00494680(void *arg0);
extern void func_00492cd0(u8 *arg0);
extern void (*jtbl_008873EC[])(void *);



// FUN_00492E70
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00492e70);

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
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493790);

// FUN_00493820
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493820);

// FUN_004938B0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_004938b0);

// FUN_004938E0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_004938e0);

// FUN_00493B90
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493b90);

// FUN_00493C90
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493c90);

// FUN_00493DA0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493da0);

// FUN_00493DD0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493dd0);

// FUN_00493E00
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493e00);

// FUN_00493E30
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493e30);

// FUN_00493E60
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493e60);

