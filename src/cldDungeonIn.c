/* Consolidated Persona 4 source units. */
/* Original translation unit cldDungeonIn.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u8 *func_00452560();
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00268230(u8 *arg0);
extern u8 D_007964F0[];
extern void func_002e1ef0(void *a);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0045a8d0(s32 a, s32 b);
extern void func_00106390(s32 a, s32 b);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *func_002e1db0(s32 a, s32 b, s32 c, s32 d);
extern void func_0045b2e0(s32 a);
extern u8 D_00638FC0[];
extern u8 D_0063B070[];
s32 func_00451fc0(s32 window, const void *data, s32 a, s32 b, s32 c,
                  s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
s32 func_00268870(u8 *arg0);
void func_00268920(void);

// FUN_00268920
void func_00268920(void) {
    u8 *s0 = func_00452560();
    func_002e1ef0((void *)**(s32 **)(s0 + 8));
    jtbl_008873EC[0](s0);
    func_0045a8d0(3, 0);
    func_00106390(0x1470, 0);
}

/* measured: retail dispatch is beq 3,2,1,0 (state 3 -> -1, else 0) with body
   layout [-1 body first, 0 body second]. mwcc b210 linear-chain switch emits
   TESTS in reverse of declaration order but BODIES in declaration order, so the
   two are mutually exclusive here: declaring [0,1,2,3] gives test [3,2,1,0]
   (correct) but body [0,3] (wrong, nd 18); declaring [3,0,1,2] gives body
   [3,0] (correct) but test [2,1,0,3] (wrong, nd 8). if/else-if chains give
   inline bne (not out-of-line beq), and if+switch / two-switch splits collapse
   the all-return-0 sub-switch into a single return 0. Best nd 8. */
// FUN_00268870
s32 func_00268870(u8 *arg0)
{
    u8 *state;
    u8 *obj;

    state = func_00452560();
    obj = func_00460990();
    *(void **)(obj + 8) = (void *)func_00268230;
    *(u8 **)(obj + 0x10) = arg0;
    func_00460ac0(D_007964F0, obj);
    switch (*(s32 *)state) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        return -1;
    }
    return 0;
}
// FUN_00268990
s32 func_00268990(s32 arg0) {
    u8 *s0;
    u8 *v0;
    u8 **v1;
    s32 ret;

    func_0044ea90(D_00638FC0, 0x33D);
    s0 = D_008873F4[0](1, 0xC, 0x40000);
    *(s32 *)s0 = 0;
    v0 = func_002e1db0(0x10, 0, 0, 0);
    v1 = *(u8 ***)(v0 + 0x24);
    *v1 = v0;
    *(u8 ***)(s0 + 8) = v1;
    ret = func_00451fc0(arg0, D_0063B070, 0xF, 0, 0, func_00268870, (void (*)(u8 *))func_00268920, s0);
    func_0045b2e0(0x40);
    func_00106390(0x1470, 1);
    return ret;
}

/* measured: 1600B state-machine (switch on work->state, cases 0/1/2/default).
   Case 1 embeds a PS2 FPU multiply-accumulate polynomial chain that m2c cannot
   decode (M2C_ERROR): mula.s $f0,$f1 / madda.s $f14,$f2 / madda.s $f3,$f4 /
   madd.s $f2,$f8,$f5 computes f16 = f6*(f0*f1 + f14*f2 + f3*f4 + f8*f5) feeding
   func_00267b20's 12 args. Heavy register pressure (8 saved regs + $f20), a
   0x169-word D_0063AAB0 copy loop, a nested 0x13-iteration node loop with
   func_002e2170, and the 0x4F000000 range-guard (f32)(s32) idiom in case 2.
   The m2c draft is not compilable (M2C_ERROR blocks); full reconstruction not
   attempted beyond FPU decode. */
// FUN_00268230
INCLUDE_ASM("asm/nonmatchings/cldDungeonIn", func_00268230);
