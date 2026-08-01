#include "include_asm.h"
#include "type.h"

s32 func_00439598(void);

s32 func_00439770(void);

s32 func_00439970(void);

s32 func_00438e60(void);

extern s32 D_008AC780[];
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

// FUN_00438FA0
void func_00438fa0(void) {
    func_00438e60();
}
#pragma schedule off


/* floor: retail hoists the arg load above the frame (lui; addiu $sp; lw; sd $ra)
   and fills the jr $ra delay slot; b210 at every level either keeps the O2 order
   (nd 18: addiu $sp; sd $ra; lui; lw; jal; nop; sync; ei; ld; addiu $sp; jr; nop)
   or moves the lw into the jal delay slot (nd 24). The sync/ei asm itself matches. */

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


/* measured: O3 is load-bearing (nd 48 -> 23). Floor: retail uses the R5900
   3-op mult (addiu $v1,$zero,0x24; lui; mult $v1,$a0,$v1) for arg0*0x24; b210
   strength-reduces to sll/addu/sll at every level and source shape tried. */
#pragma optimization_level 3

// FUN_00439E90 NONMATCHING
#ifdef NON_MATCHING
s32 func_00439e90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_00439cc8(arg0, arg1, arg2, arg3,
                         ((s32 *)&D_008AC788[arg0])[5]);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439e90);
#endif


/* measured: removing this pragma takes func_0043c0a0 nd 0 -> nd 18: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10 and materializes the return
   zero between ld $ra and the jump; baseline -O2 emits ld; move; addiu; jr; nop. */
#pragma schedule on

// FUN_0043C0A0
s32 func_0043c0a0(void) {
    func_00431408();
    return 0;
}
#pragma schedule off



// FUN_0043C6D8 NONMATCHING
#ifdef NON_MATCHING
/* measured: O3 is load-bearing (nd 13 -> 9). Floor: retail keeps the -1 compare
   constant in $t7 and places the pointer increment in the bne delay slot; b210
   colours the constant $v1 and leaves the delay slot nop at all levels. */
#pragma optimization_level 3
void func_0043c6d8(u8 *arg0, s32 arg1) {
    s32 var_5 = arg1 - 1;
    if (var_5 != -1) {
        do {
            *arg0 = 0;
            var_5 -= 1;
            arg0 += 1;
        } while (var_5 != -1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c6d8);
#endif



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
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfc0);
#endif
#pragma schedule on



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
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eb20);
#endif
#pragma schedule on
