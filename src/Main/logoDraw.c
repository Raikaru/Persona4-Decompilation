#include "include_asm.h"
/* Source unit: src/Main/logoDraw_0012bbb0.c */
#include "type.h"


extern void func_00440b68(...);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, u32 line);
extern void *func_00454a60(const char *path, s32 flags);
extern void func_00454bd0(void *handle);
extern s32 func_004553c0(void *handle);
extern s32 func_00451de0();
extern s32 func_00452490(s32);
extern void func_00452080(s32 handle);
extern s32 func_004667d0(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern void *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern void func_00122520(s32, s32);
extern void func_00122640(s32, s32);
extern s32 func_00122720(void);
extern void func_0012b890(void);
extern void func_0012b940(void);
extern void func_0012b9a0(void);
extern void *func_00452560();
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(s32, s32, u32);

extern char D_00762D88;
extern char D_00762D98;
extern char D_005E5730[];
extern char D_005E5760[];
extern char D_005E5770[];
extern char D_005E5790[];
extern char D_005E57A8[];
extern char D_00795E60[];
extern s32 func_0012bbb0(s32);
extern void func_0012bfb0(void);


// Floor: 104 diff bytes, all at the two D_008873F4[0](...) call sites. Retail
// hoists the symbol address into $s2 once (lui/addiu before the first call's
// args, then `lw $v0, 0($s2); jalr $v0` at both sites); MWCCPS2 b210 folds the
// address into each call (`lui $v0; lw $v0, 0($v0)`) no matter how the shared
// address is expressed (plain array subscripts, function-scope or block-scope
// pointer locals, initializers, #pragma opt_common_subs/opt_loop_invariants/
// optimize_for_size/schedule). Verified: removing the nested-if var_2 shape
// regresses the tail by 8 bytes; with the nested-if shape the diff is confined
// to these two call sites (object 1024/1024).
// FUN_0012BBB0
INCLUDE_ASM("asm/nonmatchings/logoDraw", func_0012bbb0);



// FUN_0012BFB0
void func_0012bfb0(void)
{
    typedef struct LogoWork LogoWork;
    struct LogoWork
    {
        s32 state;
        s32 index;
        s32 counter;
        void *handle;
        s32 task10;
        s32 task14;
    };
    LogoWork *temp_2;
    s32 *temp_17;
    s32 *temp_17_2;
    s32 temp_18;
    s32 temp_18_2;
    s32 var_2;
    s32 var_2_2;

    temp_2 = func_00452560();
    temp_18 = temp_2->task10;
    temp_17 = func_00452560(temp_18);
    if (func_00452490(temp_18) == 0) {
        var_2 = 0;
    } else if (*temp_17 == 3) {
        var_2 = 1;
    } else {
        var_2 = 0;
    }
    if (var_2 == 0) {
        func_0046d730(&D_005E5730, 0xF8);
    }
    temp_18_2 = temp_2->task14;
    temp_17_2 = func_00452560(temp_18_2);
    if (func_00452490(temp_18_2) == 0) {
        var_2_2 = 0;
    } else if (*temp_17_2 == 3) {
        var_2_2 = 1;
    } else {
        var_2_2 = 0;
    }
    if (var_2_2 == 0) {
        func_0046d730(&D_005E5730, 0xF9);
    }
    func_00452080(temp_2->task10);
    func_00452080(temp_2->task14);
    func_00454bd0(temp_2->handle);
    jtbl_008873EC[0](temp_2);
}



// FUN_0012C110
s32 func_0012c110(void)
{
    void *temp_2;

    func_0044ea90(&D_005E5730, 0x107);
    temp_2 = D_008873F4[0](1, 0x18, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)((u8 *)temp_2 + 4) = 0;
    return func_00451de0(&D_005E57A8, 0xF, 0, 0, func_0012bbb0, func_0012bfb0, temp_2);
}

