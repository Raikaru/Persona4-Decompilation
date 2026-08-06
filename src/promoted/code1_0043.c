#include "include_asm.h"
#include "type.h"

s32 func_00439598(void);

s32 func_00439770(void);

s32 func_00439970(void);

s32 func_00438e60(void);

extern s32 D_008AC780[];
extern s32 D_0070F920[];
void func_00421810(s32);

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
#pragma schedule off


/* measured: removing this pragma takes func_00438760 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438760
void func_00438760(void) {
    func_00439770();
}
#pragma schedule off


/* measured: removing this pragma takes func_00438780 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438780
void func_00438780(void) {
    func_00439970();
}
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
#pragma schedule off


/* floor: retail hoists the arg load above the frame (lui; addiu $sp; lw; sd $ra)
   and fills the jr $ra delay slot; b210 at every level either keeps the O2 order
   (nd 18: addiu $sp; sd $ra; lui; lw; jal; nop; sync; ei; ld; addiu $sp; jr; nop)
   or moves the lw into the jal delay slot (nd 24). The sync/ei asm itself matches.
   measured: best candidate (plain O2, func_00421810(D_008AC780[0]) + sync/ei asm)
   gives nd 6 (reloc-masked): only the lui/lw-vs-frame order and the jr-delay-slot
   order differ; schedule on / O3 both move the lw into the jal delay slot (nd 11). */

// FUN_00438FC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438fc0);

// FUN_00439008
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439008);

// FUN_00439050
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439050);

/* measured: floor. retail keeps the R5900 3-op mult (addiu $v1,$zero,0x184;
   mult $a0,$a0,$v1) for arg0*0x184; b210 strength-reduces to sll/addu at every
   level and with opt_strength_reduction off (nd 76 -> 76, obj 96/72). Loop shape
   otherwise reproduces retail once the mult is taken as given. */
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
   left outside it silently put 17 INCLUDE_ASM functions below on -O3. */
#pragma optimization_level 3
s32 func_00439e90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_00439cc8(arg0, arg1, arg2, arg3,
                         ((s32 *)&D_008AC788[arg0])[5]);
}
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
   overflows the window). Return-duplication/branch-likely-pair floor. */
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

// FUN_0043AC18
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac18);

// FUN_0043AC60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac60);

// FUN_0043ACC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043acc0);

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



// FUN_0043C6D8 NONMATCHING
#ifdef NON_MATCHING
/* measured: O3 is load-bearing (nd 13 -> 9). Floor: retail keeps the -1 compare
   constant in $t7 and places the pointer increment in the bne delay slot; b210
   colours the constant $v1 and leaves the delay slot nop at all levels.
   Best candidate (do-while, local ptr/counter) gives nd 6 (reloc-masked): the
   loop body is identical except the -1 constant is $v1 not $t7 and the pointer
   increment is inline (offset 0x18) not in the bne delay slot (offset 0x28).
   probed while/for/order-swap/dummy variants, all nd >= 6. */
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
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c6d8);
#endif



// FUN_0043DDF8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ddf8);

// FUN_0043DE58
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043de58);

// FUN_0043DFC0 NONMATCHING
#ifdef NON_MATCHING
/* floor: retail is the frame-preserving tail call addiu $sp; lui $t7; sd $ra;
   lw $a0; ld $ra; j func; addiu $sp (28B). b210 O2 does not collapse (40B, nd 25);
   O3/tailcall on collapse but eliminate the frame (12-16B); schedule on does not
   merge and fills the jal delay slot with the load (32B). Residual nd 7, obj 16/32.
   measured: the O3+schedule-off bracket below is load-bearing (nd 25 -> 7). */
#pragma optimization_level 3
#pragma schedule off
s32 func_0043dfc0(s32 arg0) {
    return func_0043DFA0(D_00710070[0]);
}
#pragma schedule on
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfc0);
#endif



// FUN_0043DFE0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfe0);

// FUN_0043E5B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e5b0);

// FUN_0043EB20 NONMATCHING
#ifdef NON_MATCHING
/* floor: retail is the frame-preserving tail call addiu $sp; lui $t7; sd $ra;
   lw $a0; ld $ra; j func; addiu $sp (28B). b210 O2 does not collapse (40B, nd 25);
   O3/tailcall on collapse but eliminate the frame (12-16B); schedule on does not
   merge and fills the jal delay slot with the load (32B). Residual nd 7, obj 16/32.
   measured: the O3+schedule-off bracket below is load-bearing (nd 25 -> 7). */
#pragma optimization_level 3
#pragma schedule off
s32 *func_0043eb20(s32 arg0) {
    return func_0043eae8(D_00710070[0]);
}
#pragma schedule on
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eb20);
#endif
