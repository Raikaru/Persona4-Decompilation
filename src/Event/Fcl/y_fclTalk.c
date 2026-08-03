#include "include_asm.h"
/* Persona 4 USA decompilation - y_fclTalk.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern char D_0064A000[];
extern char D_0064A018[];
extern char D_0064A030[];
extern char D_0064A050[];
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                         void *arg5, void *arg6, u8 *arg7);
extern s8 func_002bab80(void *);
extern void func_002badc0(s8, s32);
extern void func_002bbd80(s8, s32, void *);
extern void *func_001067f0(s16);
extern s32 func_002be1b0(s16);
extern void func_00275980(void *, void *, s32);
extern s32 func_00106330(s32);
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s32 func_002be100(u8);
extern s32 func_002bb680(s8);
extern void func_002bbcf0(s8);
extern void func_002bb550(s8);
extern u8 D_00645240[];
extern u8 D_006450E0[];
extern u8 D_00647EE0[];
extern u32 D_0064A078[];
extern u32 D_0064A07C[];
extern u32 D_0064A080[];
extern void func_00331a20();
extern void func_00331f90();
extern s32 func_00332060();
extern void func_003322a0();
extern void func_00332520();
extern void func_003329b0();

// FUN_00331FC0
void func_00331fc0(u8 *arg0) {
    u8 *temp_2;

    func_0044ea90(D_0064A018, 0xC8);
    temp_2 = D_008873F4[0](1, 2, 0x40000);
    func_00451fc0(arg0, D_0064A030, 0xF, 0, 0, (void *)func_00331a20,
                  (void *)func_00331f90, temp_2);
    *temp_2 = 0;
}
/* measured: nd 165 with a full C body (object 592B against a 576B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_00332060
INCLUDE_ASM("asm/nonmatchings/y_fclTalk", func_00332060);
// FUN_003322A0
void func_003322a0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_003322D0
void func_003322d0(u8 *arg0) {
    u8 *temp_2;

    func_0044ea90(D_0064A018, 0x12D);
    temp_2 = D_008873F4[0](1, 2, 0x40000);
    func_00451fc0(arg0, D_0064A050, 0xF, 0, 0, (void *)func_00332060,
                  (void *)func_003322a0, temp_2);
    *temp_2 = 0;
}

// FUN_00332370
void func_00332370(u8 *arg0, s32 arg1, s32 arg2) {
    u8 sp40[0x20];
    s32 temp_2;
    u8 *work;
    s16 t;

    work = *(u8 **)(arg0 + 0x38);
    t = (s16)((arg2 & 0xFFF00) >> 8);
    if (arg2 == 0) {
        *(work + 1) = func_002bab80(D_00645240);
        func_002bbd80(*(work + 1), 0, func_001067f0(t));
        func_002badc0(*(work + 1), 0x1E);
        return;
    }
    *(work + 1) = func_002bab80(D_00645240);
    func_002bbd80(*(work + 1), 0, func_001067f0(t));
    temp_2 = func_002be1b0((s16)arg1);
    if (temp_2 == 0xE) {
        func_00275980((void *)D_0064A07C[0], sp40, 0x20);
        func_002bbd80(*(work + 1), 1, sp40);
    } else if (temp_2 == 0xF) {
        func_00275980((void *)D_0064A080[0], sp40, 0x20);
        func_002bbd80(*(work + 1), 1, sp40);
    } else {
        func_00275980((void *)D_0064A078[0], sp40, 0x20);
        func_002bbd80(*(work + 1), 1, sp40);
    }
    func_002badc0(*(work + 1), 0x1F);
}

// FUN_00332520
INCLUDE_ASM("asm/nonmatchings/y_fclTalk", func_00332520);

// FUN_003329B0
void func_003329b0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_003329E0
void func_003329e0(u8 *arg0) {
    u8 *temp_2;

    func_0044ea90(D_0064A018, 0x1EC);
    temp_2 = D_008873F4[0](1, 0x180C, 0x40000);
    func_00451fc0(arg0, D_0064A000, 0xF, 0, 0, (void *)func_00332520,
                  (void *)func_003329b0, temp_2);
    *temp_2 = 0;
    *(temp_2 + 0x1808) = 0;
}
