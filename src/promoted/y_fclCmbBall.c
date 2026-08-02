#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCmbBall.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);



// FUN_0034AD70
INCLUDE_ASM("asm/nonmatchings/y_fclCmbBall", func_0034ad70);

// FUN_0034AE50
u8 *func_0034ae50(u8 *arg0, s8 arg1) {
    s32 off = arg1 * 0x200;

    return *(u8 **)(arg0 + 0x38) + off + 0x104;
}

// FUN_0034AE70
INCLUDE_ASM("asm/nonmatchings/y_fclCmbBall", func_0034ae70);

// FUN_0034B380
INCLUDE_ASM("asm/nonmatchings/y_fclCmbBall", func_0034b380);
// FUN_0034B710
void func_0034b710(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0034B740
INCLUDE_ASM("asm/nonmatchings/y_fclCmbBall", func_0034b740);