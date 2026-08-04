/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleCard.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"


extern void func_00368be0(void);
extern void func_0036c450(void);
extern void func_0036dba0(u8 *arg0);

extern void func_003dc740(void *dest, void *src, s32 mode, f32 fparg0);
extern void func_0036de20(u8 *arg0, void *arg1);

extern void func_0036b5e0(u8 *arg0, f32 *out);

extern void func_00367fb0(void);
extern void func_0036a820(u8 *arg0, s32 arg1);
extern void func_0036c7e0(s32 arg0);
extern void func_003688b0(void);
extern void func_0036a880(u8 *arg0, u16 arg1, s32 arg2);
extern void func_0036c570(s32 arg0, s32 arg1);
extern void func_00368d30(void);
extern void func_0036c900(void);
extern void func_0036b5a0(u8 *arg0, void *arg1);
extern void func_0036b5c0(u8 *arg0, void *arg1);
extern void func_0036b600(u8 *arg0, void *arg1);
extern void func_0036adc0(u8 *arg0, void *arg1);
extern void func_0036a6b0(void *arg0, const f32 *arg1, f32 fparg2, void *arg3);
extern f32 func_0036a790(const f32 *value, f32 scale);
extern void func_0036a8f0(u8 *arg0, s32 arg1);
extern void func_0036b630(u8 *arg0, s32 arg1);
extern void func_00368e80(u8 *arg0);
extern void func_003694d0(u8 *arg0);
extern void func_00369470(u8 *arg0, s32 arg1);
extern void func_0036c140(s32 arg0, s32 arg1);
extern void func_0036c230(s32 arg0);
extern void func_0036c310(void);
extern void func_0036c3b0(void);
extern void *func_00457120(void);
extern void func_0046d730(const char *file, s32 line);
extern char D_0064E5B0[];

/* Retail float-pool constant at gp - 0x7C44 = 0x007614AC (8.133125f). */
f32 fGpffff83bc = 8.133125f;

void func_0036da40(u8 *arg0, s32 arg1);
void func_0036daa0(u8 *arg0, s32 arg1, s32 arg2);
void func_0036db20(u8 *arg0);
void func_0036db60(u8 *arg0);
void func_0036dba0(u8 *arg0);
void func_0036dc60(u8 *unit, f32 *src, f32 scale, f32 *dst);
void func_0036dd10(u8 *unit, f32 *src, f32 scale);
void func_0036dda0(u8 *arg0, void *arg1);
void func_0036ddc0(u8 *arg0, void *arg1);
void func_0036dde0(u8 *arg0, void *arg1, s32 arg2, f32 fparg0);
void func_0036de20(u8 *arg0, void *arg1);
void func_0036de40(u8 *arg0, void *arg1);
f32 func_0036de70(u8 *arg0);
f32 func_0036deb0(u8 *arg0);
u16 func_0036dee0(u8 *arg0);
void func_0036df30(u8 *arg0);
void func_0036df90(u8 *arg0, s32 arg1);
void func_0036e000(u8 *arg0);

/* measured: nd 24, but the real defect is ONE extra instruction -- obj 180B vs
   window 176B. In case 1 retail loads `lhu $a2, 6($a1)` FIRST and then
   `lhu $a1, 4($a1)`, clobbering the base register last; b210 loads +4 into $v0,
   then +6 into $a2, then needs `move $a1, $v0`. That one extra word shifts every
   later branch target by 4, which is what inflates the count -- the dispatch
   chain, all five case bodies and the assert all match instruction for
   instruction.

   The ascending case order IS correct (retail tests 3,2,1,0 descending; declaring
   0,1,2,3 reproduces that). Measured and rejected for the extra move: a u16 temp
   for the +6 argument at function scope, the same temp in a braced case block,
   temps for both arguments, and a local ShuffleCard struct typedef with named
   fields -- all five score 24. Argument-clobber ordering floor. */
// FUN_0036D990 NONMATCHING
#ifdef NON_MATCHING
void func_0036d990(u8 *arg0, u8 *arg1)
{
    switch (*(s32 *)arg1) {
    case 0:
        func_0036da40(arg0, *(u16 *)(arg1 + 4));
        break;
    case 1:
        func_0036daa0(arg0, *(u16 *)(arg1 + 4), *(u16 *)(arg1 + 6));
        break;
    case 2:
        func_0036db20(arg0);
        break;
    case 3:
        func_0036db60(arg0);
        break;
    default:
        func_0046d730(D_0064E5B0, 0x72);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036d990);
#endif
// FUN_0036DA40
void func_0036da40(u8 *arg0, s32 arg1)
{
    func_00367fb0();
    func_0036a820(arg0, arg1);
    func_0036c7e0(arg1);
    func_0036dba0(arg0);
}

// FUN_0036DAA0
void func_0036daa0(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 masked;

    func_003688b0();
    masked = arg1 & 0xFFFF;
    func_0036a880(arg0, masked, arg2);
    func_0036c570(masked, arg2);
    func_0036dba0(arg0);
}




// FUN_0036DB20
void func_0036db20(u8 *arg0)
{
    func_00368be0();
    func_0036c450();
    func_0036dba0(arg0);
}

// FUN_0036DB60
void func_0036db60(u8 *arg0)
{
    func_00368d30();
    func_0036c900();
    func_0036dba0(arg0);
}

// FUN_0036DBA0
void func_0036dba0(u8 *arg0)
{
    f32 sp30[3];
    f32 sp20[3];
    u8 sp3C[4];

    *(s32 *)(arg0 + 0xFA8) = 0;
    sp30[0] = 10.0f;
    sp30[1] = 10.0f;
    sp30[2] = 10.0f;
    func_0036ddc0(arg0, sp30);
    sp20[0] = 0.0f;
    sp20[1] = 1.0f;
    sp20[2] = 0.0f;
    func_0036dde0(arg0, sp20, 0, 0.0f);
    sp3C[0] = 0xFF;
    sp3C[1] = 0xFF;
    sp3C[2] = 0xFF;
    sp3C[3] = 0xFF;
    func_0036de40(arg0, sp3C);
    func_0036a8f0(arg0, *(s32 *)((u8 *)func_00457120() + 4));
    *(u16 *)(arg0 + 0xFAC) |= 1;
}

// FUN_0036DC60
void func_0036dc60(u8 *unit, f32 *src, f32 scale, f32 *dst)
{
    if (src == NULL) {
        func_0046d730(D_0064E5B0, 0xD4);
    }
    if (dst == NULL) {
        func_0046d730(D_0064E5B0, 0xD5);
    }
    func_0036a6b0(unit, src, func_0036a790((const f32 *)unit, scale), dst);
}

// FUN_0036DD10
void func_0036dd10(u8 *unit, f32 *src, f32 scale)
{
    f32 sp40[4];

    if (src == NULL) {
        func_0046d730(D_0064E5B0, 0xD4);
    }
    func_0036a6b0(unit, src, func_0036a790((const f32 *)unit, scale), sp40);
    func_0036dda0(unit, sp40);
}

// FUN_0036DDA0
void func_0036dda0(u8 *arg0, void *arg1)
{
    func_0036b5c0(arg0, arg1);
}

// FUN_0036DDC0
void func_0036ddc0(u8 *arg0, void *arg1)
{
    func_0036b5a0(arg0, arg1);
}




// FUN_0036DDE0
void func_0036dde0(u8 *arg0, void *arg1, s32 arg2, f32 fparg0)
{
    f32 sp20[4];

    func_003dc740(sp20, arg1, arg2, fparg0);
    func_0036de20(arg0, sp20);
}

// FUN_0036DE20
void func_0036de20(u8 *arg0, void *arg1)
{
    func_0036b600(arg0, arg1);
}

// FUN_0036DE40
void func_0036de40(u8 *arg0, void *arg1)
{
    func_0036adc0(arg0, arg1);
}




// FUN_0036DE70
f32 func_0036de70(u8 *arg0)
{
    f32 sp10[3];

    func_0036b5e0(arg0, sp10);
    return 6.0f * sp10[0];
}

// FUN_0036DEB0
f32 func_0036deb0(u8 *arg0)
{
    f32 sp10[3];

    func_0036b5e0(arg0, sp10);
    return fGpffff83bc * sp10[1];
}

// FUN_0036DEE0
u16 func_0036dee0(u8 *arg0)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        func_0046d730(D_0064E5B0, 0x160);
    }
    return *(u16 *)(arg0 + 0x174);
}

// FUN_0036DF30
void func_0036df30(u8 *arg0)
{
    s32 temp;

    temp = *(s32 *)(arg0 + 0xFA8);
    if (temp != 0) {
        func_0036b630(arg0 + 0x600, temp);
    }
    func_00368e80(arg0);
    func_003694d0(arg0);
}

// FUN_0036DF90
void func_0036df90(u8 *arg0, s32 arg1)
{
    s32 temp;

    temp = *(s32 *)(arg0 + 0xFA8);
    if (temp != 0) {
        func_0036b630(arg0 + 0x600, temp);
    }
    func_00368e80(arg0);
    func_00369470(arg0, arg1);
}

// FUN_0036E000
void func_0036e000(u8 *arg0)
{
    s32 temp_17;
    s32 temp_3;

    if (*(u16 *)(arg0 + 0xFAC) & 1) {
        temp_3 = *(s32 *)(arg0 + 4);
        switch (temp_3) {
        case 0:
            if (temp_3 != 0) {
                func_0046d730(D_0064E5B0, 0x160);
            }
            func_0036c230(*(u16 *)(arg0 + 0x174));
            break;
        case 1:
            if (temp_3 != 1) {
                func_0046d730(D_0064E5B0, 0x16A);
            }
            temp_17 = *(s32 *)(arg0 + 0x170);
            if (*(s32 *)(arg0 + 4) != 1) {
                func_0046d730(D_0064E5B0, 0x174);
            }
            func_0036c140(temp_17, *(s32 *)(arg0 + 0x174));
            break;
        case 2:
            func_0036c310();
            break;
        case 3:
            func_0036c3b0();
            break;
        default:
            func_0046d730(D_0064E5B0, 0x1E5);
            break;
        }
        *(u16 *)(arg0 + 0xFAC) &= ~1;
    }
}
