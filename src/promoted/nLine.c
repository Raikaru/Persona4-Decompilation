#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit nLine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*D_00887310[])(s32, void *, s32);

void func_0034e0b0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2);




// FUN_0034B970
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034b970);

// FUN_0034BA20
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034ba20);

// FUN_0034BA30
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034ba30);

// FUN_0034BB10
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034bb10);

// FUN_0034BB20
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034bb20);

// FUN_0034BD60
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034bd60);

// FUN_0034BEA0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034bea0);
// FUN_0034C120
void func_0034c120(u8 *arg0) {
    f32 temp_f2 = *(f32 *)(arg0 + 8);

    if (temp_f2 < 0.0f) {
        *(f32 *)(arg0 + 0) += 640.0f;
        *(f32 *)(arg0 + 0x18) += 640.0f;
    } else if (!(temp_f2 < 640.0f)) {
        *(f32 *)(arg0 + 0) -= 640.0f;
        *(f32 *)(arg0 + 0x18) -= 640.0f;
    }
    temp_f2 = *(f32 *)(arg0 + 0xC);
    if (temp_f2 < 0.0f) {
        *(f32 *)(arg0 + 4) += 448.0f;
        *(f32 *)(arg0 + 0x1C) += 448.0f;
        return;
    }
    if (!(temp_f2 < 448.0f)) {
        *(f32 *)(arg0 + 4) -= 448.0f;
        *(f32 *)(arg0 + 0x1C) -= 448.0f;
    }
}




// FUN_0034C210
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c210);

// FUN_0034C260
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c260);

// FUN_0034C270
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c270);

// FUN_0034C4A0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c4a0);

// FUN_0034C500
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c500);

// FUN_0034C6C0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c6c0);
// FUN_0034C820
void func_0034c820(u8 *arg0) {
    D_00887310[0](5, arg0, 4);
}




// FUN_0034C860
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034c860);

// FUN_0034CEF0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034cef0);
// FUN_0034D040
void func_0034d040(u8 *arg0) {
    func_0034e0b0(arg0, 0.0f, 0.0f, 1.0f);
}

// FUN_0034D070
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d070);

// FUN_0034D280
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d280);

// FUN_0034D490
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d490);

// FUN_0034D690
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d690);

// FUN_0034D890
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034d890);

// FUN_0034DB60
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034db60);

// FUN_0034DDF0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034ddf0);

// FUN_0034E0B0
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034e0b0);

// FUN_0034E290
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034e290);

// FUN_0034E360
INCLUDE_ASM("asm/nonmatchings/nLine", func_0034e360);
