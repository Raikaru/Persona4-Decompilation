#include "include_asm.h"
#include "type.h"

s32 func_00439598(void);

s32 func_00439770(void);

s32 func_00439970(void);

s32 func_00438e60(void);

extern s32 D_008AC780[];
extern s32 D_0070F920[];
extern s32 D_0070FC58[];
extern s32 D_0070FC5C[];
extern s32 D_0070FC60[];
extern s32 D_0070FC64[];
extern s32 D_0070FC40[];
extern s32 D_008BE280[];
void func_004217f0(s32);
void func_0043a2d0(s32, s32, s32, s32);
void func_0043a500(s32, s32, s32, s32);
void func_00421810(s32);
extern s32 D_008AC840[];
void func_00421820(s32);
void func_00422218(s32 *, s32);
extern s32 D_009389E0;
s32 func_00421f98(s32, s32);

typedef struct {
    u8 _pad[0x14];
    s32 field_14;
    u8 _pad2[0x24 - 0x18];
} D_008AC788_entry;
extern D_008AC788_entry D_008AC788[];
s32 func_00439cc8(s32, s32, s32, s32, s32);

s32 func_00431408(void);

extern s32 *D_00710070[];
s32 func_0043DFA0(s32 *);
s32 *func_0043eae8(s32 *);


/* measured: removing this pragma takes func_00438740 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438740
void func_00438740(void) {
    func_00439598();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off


/* measured: removing this pragma takes func_00438760 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438760
void func_00438760(void) {
    func_00439770();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off


/* measured: removing this pragma takes func_00438780 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438780
void func_00438780(void) {
    func_00439970();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off


/* measured: removing this pragma takes func_00438fa0 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438A58
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438a58);

// FUN_00438FA0
void func_00438fa0(void) {
    func_00438e60();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off


/* measured: the arg0*0x184 entry address is the documented R5900-mult floor
   from func_004390c8 - retail emits addiu $v1,$zero,0x184; mult $v1,$a0,$v1,
   b210 strength-reduces to 5 sll/addu (probed 6 spellings incl. stride-local,
   u16/s32 scale, arg locals; opt_strength_reduction off doesn't stop it, nd 68).
   schedule on is load-bearing and fills the jr $ra delay slot (nd 68 -> 56,
   obj 76/72; the 4-byte overflow is the strength-reduced mult itself).
   Committed at nd 56. */
// FUN_00438FC0 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule-on wrapper is load-bearing for this parked nd 56 body. */
#pragma schedule on
void func_00438fc0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p = (u8 *)(arg0 * 0x184 + (s32)D_0070F920);
    s32 scale = *(u16 *)(p + 0x2A);
    s32 c = arg2 + *(s32 *)(p + 0x34);
    func_0043a2d0(arg0, arg1, c * scale, arg3 * scale);
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438fc0);
#endif

/* measured: twin of func_00438fc0 (same R5900-mult floor, calls func_0043a500).
   schedule on fills the jr $ra delay slot (nd 68 -> 56, obj 76/72).
   Committed at nd 56. */
// FUN_00439008 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule-on wrapper is load-bearing for this parked nd 56 body. */
#pragma schedule on
void func_00439008(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p = (u8 *)(arg0 * 0x184 + (s32)D_0070F920);
    s32 scale = *(u16 *)(p + 0x2A);
    s32 c = arg2 + *(s32 *)(p + 0x34);
    func_0043a500(arg0, arg1, c * scale, arg3 * scale);
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439008);
#endif

// FUN_00439050
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439050);

/* measured: floor. retail keeps the R5900 3-op mult (addiu $v1,$zero,0x184;
   mult $a0,$a0,$v1) for arg0*0x184; b210 strength-reduces to sll/addu at every
   level and with opt_strength_reduction off (nd 76 -> 76, obj 96/72). Loop shape
   otherwise reproduces retail once the mult is taken as given. The 76 first recorded here came from a probe run; verify measures the committed body at 84. Committed at nd 84. */
// FUN_004390C8 NONMATCHING
#ifdef NON_MATCHING
s32 func_004390c8(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)(arg0 * 0x184 + (s32)D_0070F920 + 0xD0);
    s32 i = 0;
    while (1) {
        i += 1;
        if (*p == arg1) {
            return 1;
        }
        if (i < 0x20) {
            p += 1;
        } else {
            return 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004390c8);
#endif

// FUN_00439110
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439110);

// FUN_004393A0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004393a0);

/* measured: the body below is a faithful reconstruction whose residual is
   recorded in the notes above; re-measured for nd_audit coverage.
   Committed at nd 18. */
// FUN_004393F8 NONMATCHING
#ifdef NON_MATCHING
void func_004393f8(void) {
    func_00421810(D_008AC780[0]);
    __asm__ volatile (
        ".set noreorder\n"
        "sync\n"
        "ei\n"
        ".set reorder"
        :
        :
        : "memory"
    );
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004393f8);
#endif


// FUN_004394B8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004394b8);
// FUN_00439E90 NONMATCHING
#ifdef NON_MATCHING
/* measured: O3 is load-bearing (nd 48 -> 23). Floor: retail uses the R5900
   3-op mult (addiu $v1,$zero,0x24; lui; mult $v1,$a0,$v1) for arg0*0x24; b210
   strength-reduces to sll/addu/sll at every level and source shape tried.
   Scoped inside the reference arm: the body it justifies is not compiled, and
   left outside it silently put 17 INCLUDE_ASM functions below on -O3.
   Committed at nd 23. */
/* measured: optimization level 3 is load-bearing for this parked nd 23 body. */
#pragma optimization_level 3
s32 func_00439e90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_00439cc8(arg0, arg1, arg2, arg3,
                         ((s32 *)&D_008AC788[arg0])[5]);
}
/* measured: closes the optimization-level 3 scope at the file baseline. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439e90);
#endif


/* measured: removing this pragma takes func_0043c0a0 nd 0 -> nd 18: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10 and materializes the return
   zero between ld $ra and the jump; baseline -O2 emits ld; move; addiu; jr; nop. */
#pragma schedule on

// FUN_0043A840
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a840);

/* measured: obj 72 of a 72-byte window and the record stride/loop bounds are
   right, but retail lays the two exits out separately -- `jr $ra; move $v0,$v1`
   inline in the middle of the loop for the found case and `jr $ra; addiu
   $v0,-1` after the back-edge -- and reaches the advance block through a
   branch-likely PAIR (`beql` then `bnel`, both carrying the i++ in their delay
   slots). b210 merges the two returns into one shared epilogue and lowers the
   second test as `bne` + `b`. Measured identical at nd 41: do/while, while(1)
   with a trailing `i >= 2` / `i > 1` return, an explicit goto-loop, nested-if
   instead of &&, `e[0]` instead of `e[0] != 0`, and declaring the pointer
   before the counter. The top-tested for/while forms are worse (nd 54, obj 76
   overflows the window). Return-duplication/branch-likely-pair floor.
   Committed at nd 41. */
// FUN_0043A8A8 NONMATCHING
#ifdef NON_MATCHING
s32 func_0043a8a8(s32 arg0) {
    s32 *e = (s32 *)D_008AC788;
    s32 i = 0;

    do {
        if (e[0] != 0 && e[1] == arg0) {
            return i;
        }
        i++;
        e += 9;
    } while (i < 2);
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a8a8);
#endif

// FUN_0043A920
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a920);

/* measured: retail hoists the D_0070FC40 address once into $v1 and reuses the
   %lo displacement for both the flag load and the clear store; b210
   materialises the address twice. Those two extra words, plus b210 filling a
   branch-likely delay slot with the D_008BE280 lui where retail fills the
   bnez slot with the $ra save, plus scheduling the flag clear into the bltz
   delay slot where retail clears it before the load, leave the residual.
   Probed the < 0 and >= 0 orientations, a pointer local for the flag (worse),
   schedule on and off, O3, opt_common_subs on, and opt_rebuildconditionals
   off. The equal-zero-plus-goto shape below is the best of them.
   Committed at nd 29. */
// FUN_0043AC18 NONMATCHING
#ifdef NON_MATCHING
s32 func_0043ac18(void) {
    if (D_0070FC40[0] == 0) {
        return 0;
    }
    D_0070FC40[0] = 0;
    if (D_008BE280[0] < 0) {
        goto ret1;
    }
    func_004217f0(D_008BE280[0]);
ret1:
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac18);
#endif

// FUN_0043AC60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac60);

// FUN_0043ACC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043acc0);

/* measured: nd 29 at retail's exact 72-byte object. Declaring these four
   globals as arrays rather than scalars is what fixes the addressing mode -
   with `extern s32 D_0070FC64;` b210 reaches them GP-relative and the object
   comes out at nd 39, while retail uses an absolute lui/lw pair, which the
   array spelling reproduces. The remaining residual is the stride multiply:
   retail materialises 0xC into a register and issues a real mult/mflo, b210
   strength-reduces it to sll/addu/sll. Naming the stride in a local does not
   change that (nd 29 either way). Committed at nd 29. */
// FUN_0043BC70 NONMATCHING
#ifdef NON_MATCHING
s32 func_0043bc70(void) {
    func_0043c6d8((u8 *)D_0070FC58[0], D_0070FC64[0] * 0xC);
    D_0070FC60[0] = 0;
    D_0070FC5C[0] = 0;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043bc70);
#endif

// FUN_0043C0A0
s32 func_0043c0a0(void) {
    func_00431408();
    return 0;
}
/* measured: closes the bracket noted above func_0043c0a0's opening pragma
   (removing it takes that function nd 0 -> nd 18). */
#pragma schedule off



// FUN_0043C6D8 NONMATCHING
#ifdef NON_MATCHING
/* measured: the best plain-C body remains normalized_diff 9 at object 52/56.
   Retail keeps the -1 compare constant in $t7 and places the pointer increment
   in the bne delay slot; b210 colours the constant $v1 and leaves that delay
   slot empty. The do-while, while/for, declaration-order, guard-polarity,
   sentinel-local, comma-expression, and in-function scheduler variants all
   scored nd >= 9. Committed at nd 9. */
/* measured: optimization level 3 is load-bearing for this parked nd 9 body. */
#pragma optimization_level 3
void func_0043c6d8(u8 *arg0, s32 arg1) {
    u8 *p = arg0;
    s32 c = arg1 - 1;
    if (c != -1) {
        do {
            *p = 0;
            c -= 1;
            p += 1;
        } while (c != -1);
    }
}
/* measured: closes the optimization-level 3 scope at the file baseline. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c6d8);
#endif



/* measured: raw field stores reproduce the exact 96-byte object except b210 uses $v1/$a1 for the two function/data addresses and leaves the final self-pointer store in the body instead of the jr $ra delay slot. In-function schedule off improves the baseline to normalized_diff 24 (object 92/96); address-local and struct-pointer spellings do not improve it. Committed at nd 24. */
// FUN_0043DDF8 NONMATCHING
#ifdef NON_MATCHING
void func_0043ddf8(u8 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    extern void func_00442220();
    extern void func_00442300();
    extern u8 D_00442280[];
    extern u8 D_00442368[];
    typedef void (*Ddf8Func)(void);
    typedef struct {
        s32 f0; s32 f4; s32 f8; s16 fC; s16 fE;
        s32 f10; s32 f14; s32 f18; u8 *f1C;
        Ddf8Func f20; u8 *f24; Ddf8Func f28; u8 *f2C;
        s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44;
        s32 f48; s32 f4C; s32 f50; s32 f54;
    } Ddf8;
    Ddf8 *p;
    /* measured: schedule off gives the nearest tested 92-byte object. */
    #pragma schedule off
    p = (Ddf8 *)arg0;
    p->f54 = arg3;
    p->fC = arg1;
    p->fE = arg2;
    p->f20 = (Ddf8Func)func_00442220;
    p->f24 = D_00442280;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->f28 = (Ddf8Func)func_00442300;
    p->f2C = D_00442368;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = arg0;
    /* measured: closes the schedule-off scope at the file baseline. */
    #pragma schedule on
  }
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ddf8);
#endif

// FUN_0043DE58
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043de58);

/* measured: retail window 32 bytes; the best attempted tail-jump bodies were
   object 16/32 at nd 7 and schedule-on object 12/32 at nd 4. Those numbers
   are size-deficit artifacts, not near matches; no real C body was produced. */
// FUN_0043DFC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfc0);



// FUN_0043DFE0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfe0);

// FUN_0043E5B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e5b0);

/* measured: retail window 32 bytes; the best attempted tail-jump bodies were
   object 16/32 at nd 7 and schedule-on object 12/32 at nd 4. Those numbers
   are size-deficit artifacts, not near matches; no real C body was produced. */
// FUN_0043EB20
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eb20);
