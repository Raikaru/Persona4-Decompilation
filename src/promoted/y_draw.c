/* Consolidated Persona 4 source units. */
/* Original translation unit y_draw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"


extern void func_002b82d0(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s16 arg5);

extern void func_002b8300(u8 *arg0, u32 arg1, u32 arg2, s16 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);




// FUN_002B5C90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5c90);

// FUN_002B5DA0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5da0);

// FUN_002B5DB0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5db0);

// FUN_002B5E20
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5e20);

// FUN_002B5E30
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5e30);

// FUN_002B5E90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5e90);

// FUN_002B5EF0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5ef0);

// FUN_002B5FD0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5fd0);

// FUN_002B60F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b60f0);

// FUN_002B6120
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6120);

// FUN_002B6130
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6130);

// FUN_002B6140
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6140);

// FUN_002B6150
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6150);

// FUN_002B6180
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6180);

// FUN_002B6260
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6260);

// FUN_002B6340
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6340);

// FUN_002B6560
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6560);

// FUN_002B6590
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6590);

// FUN_002B67A0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b67a0);

// FUN_002B6820
s8 func_002b6820(u8 *arg0, u32 arg1) {
    u32 n = arg1 & 0xFFFF;
    return (s8)((s32)(*(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10) & ((1 << n) & 0xFFFF)) >> n);
}




// FUN_002B6850
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6850);

// FUN_002B68D0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b68d0);

// FUN_002B6970
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6970);

// FUN_002B69B0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b69b0);

// FUN_002B69F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b69f0);

// FUN_002B6A40
void func_002b6a40(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg5;
    func_002b82d0(base + 0x10, arg1, arg2, arg3, arg4, ext);
}




// FUN_002B6A70
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6a70);

// FUN_002B6AC0
void func_002b6ac0(u8 *arg0, u32 arg1, u32 arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg3;
    func_002b8300(base + 0x10, arg1, arg2, ext, fparg0, fparg1, fparg2, fparg3);
}

// FUN_002B6AF0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6af0);

// FUN_002B6B40
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6b40);

// FUN_002B6B90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6b90);

// FUN_002B6BE0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6be0);

// FUN_002B6C30
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6c30);

// FUN_002B6D60
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6d60);

// FUN_002B6DA0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6da0);

// FUN_002B6EA0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6ea0);

// FUN_002B6EC0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6ec0);

// FUN_002B74C0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b74c0);

// FUN_002B74F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b74f0);

// FUN_002B7750
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7750);

// FUN_002B77D0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b77d0);

// FUN_002B7CD0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7cd0);

// FUN_002B7F20
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7f20);

// FUN_002B8120
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8120);

// FUN_002B8150
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8150);

// FUN_002B81F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b81f0);

// FUN_002B8200
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8200);

// FUN_002B8270
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8270);

// FUN_002B82D0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b82d0);

// FUN_002B8300
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8300);

// FUN_002B8340
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8340);

// FUN_002B8370
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8370);

// FUN_002B83E0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b83e0);

// FUN_002B89A0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b89a0);

// FUN_002B9AB0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9ab0);

// FUN_002B9E10
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9e10);

// FUN_002B9F60
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9f60);

// FUN_002B9F90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9f90);

