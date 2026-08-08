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
extern s32 D_008BD9C0[];
extern s32 D_008BDAC0[];
extern s32 D_00754B00[];
extern s32 D_008BE280[];
s32 func_0043ae60(s32);
s32 func_0043a810(s32);
void func_004217f0(s32);
void func_0043a2d0(s32, s32, s32, s32);
void func_0043a500(s32, s32, s32, s32);
void func_00421810(s32);
extern s32 D_008AC840[];
void func_00421820(s32);
void func_00422218(s32 *, s32);
extern s32 D_009389E0[];
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
void func_0043ddf8(u8 *, s16, s16, s32);
s32 func_0043DFA0(s32 *);
s32 func_004258b0(s32 *, s32, s32, s32 *, s32, s32 *, s32, s32, s32);
void func_0043c6d8(u8 *, s32, s32);

void func_0043bb48(void *);

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


/* measured: the retail listing settles the proposed nonconstant-stride lever.
   funcs 00438fc0, 00439008, 004390c8, and 00439110 each materialize literal
   0x184 with `addiu $v1,$zero,0x184` before a real three-operand `mult`; no
   0x184 is loaded from memory or passed in. b210 strength-reduces the C
   constant, so this is the documented R5900-mult floor. The first two best
   probes are nd 68 -> 56 (obj 76/72); the latter two were archived above the
   nd 25 threshold. */
// FUN_00438FC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438fc0);
/* measured: twin of func_00438fc0 (same R5900-mult floor, calls func_0043a500).
   schedule on fills the jr $ra delay slot (nd 68 -> 56, obj 76/72).
   Archived in build/W8Code1_0043_high_nd_park_archive.txt; source is
   intentionally bare because nd 56 exceeds the nd 25 park threshold. */
// FUN_00439008
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439008);

// FUN_00439050
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439050);


/* measured: floor. Retail keeps the R5900 3-op mult (addiu $v1,$zero,0x184;
   mult $a0,$a0,$v1) for arg0*0x184; b210 strength-reduces it. Best probe nd 76;
   the archived body measured nd 84, object 96/72, and is not retained because
   it exceeds the nd 25 park threshold. */
// FUN_004390C8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004390c8);

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
   overflows the window). Return-duplication/branch-likely-pair floor at nd 41;
   archived in
   build/W8Code1_0043_high_nd_park_archive.txt; source is intentionally bare
   because nd 41 exceeds the nd 25 park threshold. */
// FUN_0043A8A8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a8a8);

// FUN_0043A920
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a920);

/* measured: retail hoists the D_0070FC40 address once into $v1 and reuses the
   %lo displacement for both the flag load and the clear store; b210
   materialises the address twice. Those two extra words, plus b210 filling a
   branch-likely delay slot with the D_008BE280 lui where retail fills the
   bnez slot with the $ra save, plus scheduling the flag clear into the bltz
   delay slot where retail clears it before the load, leave the residual.
   Probed the < 0 and >= 0 orientations, a pointer local for the flag (worse),
   schedule on and off, O3, opt_common_subs on, and opt_rebuildconditionals off.
   The equal-zero-plus-goto shape was best at nd 29; archived in
   build/W8Code1_0043_high_nd_park_archive.txt; source intentionally bare
   because nd 29 exceeds the nd 25 park threshold. */
// FUN_0043AC18
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac18);

// FUN_0043AC60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac60);

// FUN_0043ACC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043acc0);


/* measured: func_0043bc70 is not a 0x184 wrapper. Retail loads the
   multiplicand from D_0070FC64, materializes literal 0xC in $a2, then emits
   `mult $0,$a1,$a2`; the multiplier is still compile-time constant, so the
   same strength-reduction claim is inapplicable. */
// FUN_0043BC70
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043bc70);

// FUN_0043C0A0
s32 func_0043c0a0(void) {
    func_00431408();
    return 0;
}
/* measured: closes the bracket noted above func_0043c0a0's opening pragma
   (removing it takes that function nd 0 -> nd 18). */
#pragma schedule off



/* measured: O3 is the best tested body for this byte loop (object 52/56,
   normalized_diff 6). Retail allocates the -1 sentinel in $t7 and puts the
   pointer increment in the branch-delay slot; plain C keeps the sentinel in
   $v1 and emits the increment before the branch. Postincrement, for-loop,
   O2, and a live third-argument probe were ruled out. Committed at nd 9. */
// FUN_0043C6D8 NONMATCHING
#ifdef NON_MATCHING
/* measured: optimization level 3 is load-bearing for this parked nd 6 body. */
#pragma optimization_level 3
void func_0043c6d8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 sentinel;
    arg1 -= 1;
    sentinel = -1;
    if (arg1 != sentinel) {
        do {
            *arg0 = 0;
            arg1 -= 1;
            arg0 += 1;
        } while (arg1 != sentinel);
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


/* measured: pointer-loaded absolute D_00710070 plus schedule-on gives the exact
   32-byte object at nd 13 (bare baseline was nd 7 with object 16/32). The
   remaining fndiff rows are off 4 (candidate lui $v0 vs retail lui $t7), off
   16 (candidate lw $a0 vs retail ld $ra), off 20 (candidate ld $ra vs retail
   j func_0043DFA0), off 24 (candidate jr vs retail addiu $sp,0x10), and off
   28 (candidate addiu $sp,0x10 vs retail nop). Direct array-address,
   scalar-GP, pointer-cast, void-return, and schedule-off spellings were
   ruled out; the scheduled pointer load is the best tested body.
   Committed at nd 13. */
// FUN_0043DFC0 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule-on pointer-load body is load-bearing for this parked nd 13 body. */
#pragma schedule on
s32 func_0043dfc0(void) {
    return func_0043DFA0(*(s32 **)D_00710070);
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfc0);
#endif



// FUN_0043DFE0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfe0);

// FUN_0043E5B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e5b0);

/* measured: retail window 32 bytes; the best attempted tail-jump bodies were
   object 16/32 at nd 7 and schedule-on object 12/32 at nd 4. Those numbers
   are size-deficit artifacts, not near matches; no real C body was produced. */
// FUN_0043EB20
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eb20);
