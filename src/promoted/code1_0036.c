#include "include_asm.h"
#include "type.h"
extern void func_0036bbf0();

extern void func_003642e0(u8 *arg0, void *arg1);

extern void memset(void *dst, s32 value, s32 size);

extern void func_0036b650(u8 *arg0);
extern void func_0036aa20(void);
extern void func_0036d8b0(void);

extern void func_0036b750(void);
extern s32 func_0036bb60(void);
extern void func_001437b0(u8 *arg0, s16 arg1, s32 arg2);



extern s32 func_0034c210(void);

extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00369440(void);

// FUN_00361970
void func_00361970(u8 *arg0)
{
    *(s32 *)(arg0 + 0x5C4) = 0;
    if (*(s16 *)(arg0 + 0x2C) > *(s16 *)(arg0 + 0x32)) {
        *(f32 *)(arg0 + 0x5BC) = -10.0f;
    } else {
        *(f32 *)(arg0 + 0x5BC) = 10.0f;
    }
    *(s16 *)(arg0 + 0x26) = 0;
}



// FUN_003619B0
s32 func_003619b0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 29) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x74)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

/* measured: nd 8 at retail's exact 128-byte object. The odd `i <= 0` bound is
   real - retail's back edge is a blez, so the body runs exactly once. The
   residual is the argument order before the call: retail loads the counter
   into $a1 before biasing the record address into $a0, b210 does the reverse.
   Hoisting the address into a local and hoisting the counter into a local
   both leave it at nd 8. Committed at nd 8. */
// FUN_00361CA0 NONMATCHING
#ifdef NON_MATCHING
void func_00361ca0(u8 *arg0) {
    s16 c = *(s16 *)(arg0 + 0x26);
    s32 i;

    if (c < 100) {
        *(s16 *)(arg0 + 0x26) = c + 1;
    }
    for (i = 0; i <= 0; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x5B8, *(s16 *)(arg0 + 0x26), 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00361ca0);
#endif

// FUN_003642A0
void func_003642a0(u8 *arg0)
{
    u16 *temp = *(u16 **)(arg0 + 0x38);

    func_003642e0(arg0, NULL);
    *temp |= 2;
}



// FUN_003671D0
void func_003671d0(s16 *arg0)
{
    memset((u8 *)arg0 + 4, 0, 0x18);
    *arg0 = 0;
}



// FUN_00367940
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00367940);

// FUN_00369470
void func_00369470(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00369440;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_0036D860
void func_0036d860(u8 *arg0, s32 arg1)
{
    func_0036b650(arg0);
    func_0036aa20();
    if (arg1 != 0) {
        func_0036d8b0();
    }
}



// FUN_0036D940
void func_0036d940(void)
{
    func_0036bbf0();
}

// FUN_0036D960
s32 func_0036d960(void)
{
    func_0036b750();
    return !func_0036bb60();
}
