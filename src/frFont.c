#include "type.h"
#include "include_asm.h"

extern void func_002716b0_typed(s32 arg0, u64 arg1, u8 *arg2);

typedef int (*code)(...);
extern u32 DAT_00881630_abs[];
extern code DAT_008873ec_abs[];
extern u32 DAT_00881750_abs[];
extern u32 DAT_00881754_abs[];
extern u32 DAT_00881758_abs[];
extern u32 DAT_0088175c_abs[];
extern u8 DAT_00881760_abs[];

extern s16 D_00763810;

extern void func_00273140(void *param_1, u32 param_2);

extern u32 D_00764598;
extern int func_00273170(void *param_1, u32 param_2, u32 param_3);

extern u32 D_007637F8;
extern u32 D_00764594;
extern s32 D_007645A0;
extern void func_0046d730(const void *file, u32 line);
extern char D_0063BAE8[];
extern void func_00275c00(void);
extern u32 DAT_00881528_abs[];
extern u32 DAT_0088152C_abs[];
extern u32 DAT_0088179C_abs[];
extern u32 func_00271bd0(int param_1);
extern u32 func_00272cb0(int param_1);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern int func_0045af90(int param_1);
extern void func_002baa20(void);
extern int func_002e0d60(void);
extern void func_002bcd20(void);
extern void func_002e17f0(void);
extern void func_002715c0(void);
extern void func_002713b0(int param_1, int param_2);
extern s8 func_002746e0(void *param_1, int param_2);
extern void func_002746b0(u32 param_1);
extern void func_002745c0(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                         u32 param_5, u32 param_6, u32 param_7, u32 param_8,
                         u32 param_9);
extern u32 D_00763840;
extern u32 D_00763848;
extern u32 D_00763838;
extern int func_002724d0(void *param_1, int param_2, int param_3, int param_4,
                        void *param_5);
extern u32 DAT_008817A0_abs[];
extern u32 DAT_00881510_abs[];
extern u32 DAT_00881514_abs[];
extern u32 DAT_00881764_abs[];
extern u32 DAT_00881768_abs[];

void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0044ea90(const void *msg, s32 id);
extern s8 D_007645B0;

extern u32 DAT_00881518_abs[];
extern u32 DAT_0088151C_abs[];
extern u32 DAT_00881520_abs[];
extern u32 DAT_00881524_abs[];

extern s32 D_007645BC;
extern s32 D_008815B0[];
extern s32 func_0026e010();
extern void func_00275a60();
extern void func_00271860(void);
extern s32 func_00270fb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                        s32 arg5);

extern u32 DAT_0088176C_abs[];
extern u32 DAT_00881770_abs[];
extern u32 DAT_00881774_abs[];
extern u32 DAT_00881778_abs[];
extern u32 DAT_0088177C_abs[];

extern s32 D_00763830;
extern char D_0063BA00[];
extern char D_00748100[];
extern char D_00748110[];
extern s32 D_007645A4;
extern s32 D_007645A8;
extern u32 DAT_0088164C_abs[];
extern u32 DAT_00881650_abs[];
extern u32 DAT_00881670_abs[];
extern u32 DAT_00881690_abs[];
extern u32 DAT_008816B0_abs[];
extern u32 DAT_008816D0_abs[];
extern u32 DAT_008817B0_abs[];
extern char D_0063BB00[];
extern char D_0063BC10[];
extern s32 func_00454a60(const void *arg0, s32 arg1);
extern void func_00456150(s32 arg0);
extern u8 *func_00455f70(void *arg0, void *arg1);
extern void func_0026e170(int param_1);
extern void func_00275bd0(void);
extern void func_00271a40(void);
extern void func_0046d740(const void *msg, const void *file, u32 line);
extern void func_00454bd0();
extern void func_00440b68();
extern char D_0063BBB0[];
extern char D_0063BBF0[];
extern char D_0063BB40[];
extern char D_0063BB80[];

typedef struct FrFontGlyph {
    u8 unknown_00[0xc];
    int advance;
    u8 unknown_10[0x18];
    struct FrFontGlyph *next;
} FrFontGlyph;

typedef struct FrFontNode {
    u8 unknown_00[3];
    s8 line_height;
    u8 unknown_04[0x18];
    FrFontGlyph *glyphs;
    u8 unknown_20[4];
    struct FrFontNode *next;
    u8 unknown_28[0x18];
    int enabled;
} FrFontNode;
typedef struct FrFontScript {
    u8 unknown_00[0x10];
    u8 *data;
    u8 unknown_14[4];
    s32 pos;
} FrFontScript;

typedef struct FrFontSlot4 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 object;
} FrFontSlot4;

typedef struct FrFontManagerData4 {
    FrFontSlot4 slots[9];
    u8 unknown_120[0x60];
    u32 *allocations[9];
} FrFontManagerData4;

extern FrFontManagerData4 gFrFontManagerData_abs[];

extern u32 DAT_00881634_abs[];



/* measured: recipe B retest 2026-08-03. The func_002715c0 dual-assignment
   tab pattern ((void *(**) )DAT_008873ec_abs; ((code)tab[0])...) AND the
   wave's u32-cast form (u32 b = (u32)jtbl_008873E8;
   ((void *(*)(u32,u32))*(u32 *)b)(...)) BOTH hoist the vtable bases (E8 in
   $22, EC in $s0 in the failure block) - the old EC-rematerialization claim
   is stale; both forms measure nd122 with identical objects. Loop bodies
   also color exactly as retail ($a2/$a3/$t0, load-first order) once the
   value load is a named temp. Residual nd122: (1) the slot-link loops'
   D_0088152C/D_00881528 bases - retail hoists a bare lui with the lo16
   folded into each lw; a u32* pointer local materializes lui+addiu (2 extra
   words per base) and the direct-global spelling rematerializes lui+lw per
   iteration, (2) mwcc hoists the D_0088152C value load to the inner-loop
   preheader where retail re-issues lw per iteration, (3) post-loop link
   statements rotate registers ($a0/$a1 vs $v0/$v1). opt_loop_invariants
   over-hoists (loads leave the loop, nd125). Base-hoist shape + load-CSE
   scheduling floor. */
// FUN_00270FB0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00270fb0);
// Ported from P3FES FUN_003b4580 (verified MATCH there). The prior nd11
// floor was the RETURN TYPE: retail leaves the incremented count live in $v0
// at the jr, so every void spelling coloured the whole global-load chain
// $v1/$a0 instead of retail's $v0/$v1. Returning s32 count fixes it. The
// caller in this file passes a u8* node, so the param is u8* (not the donor's
// int). Struct offsets prev=0x18/next=0x1C match the donor's data[6] layout.
// FUN_00271310
s32 func_00271310(u8 *param_1)
{
  typedef struct GslListNode {
    int data[6];
    struct GslListNode *prev;
    struct GslListNode *next;
  } GslListNode;
  GslListNode *node = (GslListNode *)param_1;
  GslListNode *head;
  GslListNode *next;
  s32 count;

  if (node == 0) {
    func_0046d730(D_0063BAE8, 0x1E9);
  }
  head = (GslListNode *)DAT_0088152C_abs[0];
  next = head->next;
  node->prev = head;
  node->next = next;
  head->next = node;
  next->prev = node;
  count = DAT_00881528_abs[0] + 1;
  DAT_00881528_abs[0] = count;
  return count;
}

// FUN_00271380
void func_00271380(s32 arg0, u8 *arg1)
{
    func_002716b0_typed(arg0, 0, arg1);
}



/* measured: recipe B retest 2026-08-03 - best nd88. Pointer locals
   (FrFontSlot4 *slots / s32 *bb0) DO hoist the &D_00881630/D_008815B0 bases
   with NO pragma (old note's pragma no longer needed; pragma + locals = same
   88), and naming the scaled offset in an s32 local fixes the addu operand
   order in both loops. Residual: the three bit-count loops' entry guard -
   retail emits [bnez $v1,check; b exit] with the check after the body; mwcc
   b210 emits [b check] when the condition is provable (loop A: 0x200) and
   [beqz exit; b check] otherwise (loops B/C, also $v0/$v1 counter colors
   swapped). The double andi on the loop-exit adjust ((var_2-1)&0xFF then
   var_2&0xFF at the store) is CSEd by mwcc to one andi per loop. Tried this
   wave: while-in-if, switch(cond){case 0/default}, m2c empty-if, u32 vars,
   statement-order swaps - guard shape never changes. Re-tested wave 14:
   fresh m2c body with direct globals (nd94 - the raw-array spelling is
   slightly worse than the recorded 88 pointer-local spelling); arg0/16
   division vs arg0>>4 manual-correction shift (94 vs 97 - the sra/bgez/
   addiu/sra plain-shift+correction matches retail's rounding, division
   duplicates it). Loop pre-test branch-layout + mask-CSE floor. */

// FUN_002713B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002713b0);

// FUN_002715C0
void func_002715c0(void)
{
    void *(**tab);

    func_00271a40();
    func_00271bd0(DAT_0088179C_abs[0]);
    func_00271bd0(DAT_008817A0_abs[0]);
    func_0026e170(DAT_0088175c_abs[0]);
    func_0026e170(*(u32 *)DAT_00881760_abs);
    if (DAT_0088152C_abs[0] != 0) {
        tab = (void *(**) )DAT_008873ec_abs;
        ((code)tab[0])(DAT_00881510_abs[0]);
        ((code)tab[0])(DAT_00881514_abs[0]);
        DAT_0088152C_abs[0] = 0;
    }
    tab = (void *(**) )DAT_008873ec_abs;
    ((code)tab[0])(DAT_00881764_abs[0]);
    ((code)tab[0])(DAT_00881768_abs[0]);
    func_00275bd0();
}

// FUN_002716B0
void func_002716b0(s32 arg0, u8 *arg1, u8 *arg2)
{
    FrFontSlot4 *slot;
    s32 var_17;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_5;

    if (arg1 == NULL && arg2 != NULL) {
        arg1 = arg2;
    }
    if (arg1 == NULL) {
        func_0046d730(D_0063BAE8, 0x2E9);
    }
    temp_4 = arg0 & 0xFF;
    slot = &gFrFontManagerData_abs[0].slots[temp_4];
    if (temp_4 >= 9) {
        func_0046d740(D_0063BB40, D_0063BAE8, 0x2ED);
    }
    slot->f00 = (u32)arg2;
    slot->f04 = (u32)arg1;
    var_17 = *(s32 *)(arg1 + 0) + (*(u8 *)(arg1 + 0xA) << 6);
    if (*(u8 *)(arg1 + 0x16) != 0) {
        slot->f08 = *(u32 *)(arg1 + var_17);
        slot->f10 = (u32)(arg1 + (var_17 + 4));
        temp_3 = var_17 + (slot->f08 + 4);
        slot->f0c = *(u32 *)(arg1 + temp_3);
        slot->f14 = (u32)(arg1 + (temp_3 + 4));
        var_17 = temp_3 + (slot->f0c + 4);
    } else {
        slot->f08 = 0;
        slot->f10 = 0;
        slot->f0c = 0;
        slot->f14 = 0;
    }
    temp_5 = arg1 + var_17;
    slot->f18 = (u32)temp_5;
    func_00440b68(D_0063BB80, temp_5, var_17, *(u16 *)(slot->f04 + 0xE));
    slot->object =
        (u32)(arg1 + (var_17 + (*(u16 *)(slot->f04 + 0xE) * 4)));
}

// FUN_00271820
void func_00271820(u32 param_1)
{
    DAT_008873ec_abs[0](DAT_00881630_abs[(param_1 & 0xff) * 8]);
}



// func_0026e120 and func_00271310 are intentionally left undeclared
// (implicit old-style calls, as in the P3 donor FUN_003b0030); a typed
// prototype would force an int->pointer cast mwcc rejects, and the P3
// retail form is the implicit call.


// FUN_00271860
void func_00271860(void)
{
    int sp1C;
    u8 *var_7;
    u8 *var_7_2;
    u8 *var_7_3;
    u8 *var_7_4;
    u8 *var_7_5;
    u8 *var_6;
    u8 *var_6_2;
    u8 *var_6_3;
    u8 *var_6_4;
    u8 *var_6_5;
    s32 temp_4;
    s32 temp_3;
    s32 temp_4_2;
    s32 temp_3_2;
    s32 temp_4_3;
    s32 temp_3_3;
    s32 temp_4_4;
    s32 temp_3_4;
    s32 temp_4_5;
    s32 temp_3_5;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    s32 temp_2;

    if (DAT_0088164C_abs[0] != 0) {
        func_00440b68(D_0063BB00, NULL);
    }
    if (DAT_008817B0_abs[0] == 0) {
        func_00440b68(&D_00763830, D_0063BAE8, 0x265);
        temp_2 = func_00454a60(D_0063BC10, 0);
        DAT_008817B0_abs[0] = temp_2;
        func_00456150(temp_2);
        func_002716b0(0, NULL, func_00455f70(D_0063BC10, &sp1C));
    }
    var_7 = (u8 *)gFrFontManagerData_abs;
    var_6 = (u8 *)DAT_00881650_abs;
    var_5 = 4;
    do {
        temp_4 = *(s32 *)(var_7 + 0);
        temp_3 = *(s32 *)(var_7 + 4);
        var_7 += 8;
        var_5 -= 1;
        *(s32 *)(var_6 + 0) = temp_4;
        *(s32 *)(var_6 + 4) = temp_3;
        var_6 += 8;
    } while (var_5 > 0);
    var_7_2 = (u8 *)gFrFontManagerData_abs;
    var_6_2 = (u8 *)DAT_00881670_abs;
    var_5_2 = 4;
    do {
        temp_4_2 = *(s32 *)(var_7_2 + 0);
        temp_3_2 = *(s32 *)(var_7_2 + 4);
        var_7_2 += 8;
        var_5_2 -= 1;
        *(s32 *)(var_6_2 + 0) = temp_4_2;
        *(s32 *)(var_6_2 + 4) = temp_3_2;
        var_6_2 += 8;
    } while (var_5_2 > 0);
    var_7_3 = (u8 *)gFrFontManagerData_abs;
    var_6_3 = (u8 *)DAT_00881690_abs;
    var_5_3 = 4;
    do {
        temp_4_3 = *(s32 *)(var_7_3 + 0);
        temp_3_3 = *(s32 *)(var_7_3 + 4);
        var_7_3 += 8;
        var_5_3 -= 1;
        *(s32 *)(var_6_3 + 0) = temp_4_3;
        *(s32 *)(var_6_3 + 4) = temp_3_3;
        var_6_3 += 8;
    } while (var_5_3 > 0);
    var_7_4 = (u8 *)gFrFontManagerData_abs;
    var_6_4 = (u8 *)DAT_008816B0_abs;
    var_5_4 = 4;
    do {
        temp_4_4 = *(s32 *)(var_7_4 + 0);
        temp_3_4 = *(s32 *)(var_7_4 + 4);
        var_7_4 += 8;
        var_5_4 -= 1;
        *(s32 *)(var_6_4 + 0) = temp_4_4;
        *(s32 *)(var_6_4 + 4) = temp_3_4;
        var_6_4 += 8;
    } while (var_5_4 > 0);
    var_7_5 = (u8 *)gFrFontManagerData_abs;
    var_6_5 = (u8 *)DAT_008816D0_abs;
    var_5_5 = 4;
    do {
        temp_4_5 = *(s32 *)(var_7_5 + 0);
        temp_3_5 = *(s32 *)(var_7_5 + 4);
        var_7_5 += 8;
        var_5_5 -= 1;
        *(s32 *)(var_6_5 + 0) = temp_4_5;
        *(s32 *)(var_6_5 + 4) = temp_3_5;
        var_6_5 += 8;
    } while (var_5_5 > 0);
    D_007645A8 = 0;
    D_007645A4 = 0;
    D_007645A0 = 0;
}

/* measured: recipe B retest 2026-08-03 - nd66..71 across four spellings
   (u8* arithmetic, named storep local, struct-element indexing with
   &slots[temp_17], mixed u8/s32 mask locals). Root cause confirmed: retail
   re-issues var_19&0xFF three times (andi $18/$17/$v0) so FOUR values live
   across the jals (frame 0x50, 4 saved regs); mwcc b210 CSEs every spelling
   (var_19&0xFF, (u8)var_19, (u8)(var_19&0xFF), %256, type-split u8/s32 - all
   one AND node) down to 2 andis, dropping to 3 saved regs (frame 0x40) and
   rematerializing the store address after jal func_00454bd0 - the recorded
   nd29 was not reproducible this wave. Struct indexing additionally folds
   0x1C into the base addiu where retail keeps it in the lw. CSE-of-mask
   floor. */

// FUN_00271A40 NONMATCHING
#ifdef NON_MATCHING
/* measured: nd18. retail keeps the par-load base in $a1 and reuses it for the
   free-slot store at +0x180 (`addu $v0,$a1,$v0; addiu $s1,$v0,0x180` before the
   jal, `sw ($s1)` after). Expressing the store as `par + ((u8)i - idx)*4`
   forces b210 to reuse the live par temp (call-clobbered) so the address is
   computed before the jal instead of re-materialising the base (nd67); the
   residual 18 is the subu from the (u8)i-idx delta plus the par-load temp
   register names ($a0/$v1 vs retail $v1/$a1). opt_common_subs off is required
   register names ($a0/$v1 vs retail $v1/$a1). opt_common_subs off is required
   for the three re-issued andi masks (retail andi $s2/$s1/$v0 from $s3).
   A measured optimization_level 1 bracket (with and without opt_common_subs
   off) leaves nd18 unchanged; the load-sinking family remains a floor.
   Committed at nd 18. */
#pragma opt_common_subs off
void func_00271a40(void)
{
    s32 i;
    s32 mask;
    s32 idx;
    u32 tmp;
    u8 *slot;
    u8 *par;

    for (i = 0; i < 9; i++) {
        if (*(u32 *)((u8 *)DAT_00881630_abs + i * 0x20 + 0x1c) == 0)
            continue;
        mask = i & 0xff;
        if (mask >= 9)
            func_0046d740(D_0063BBB0, D_0063BAE8, 0x319);
        idx = i & 0xff;
        slot = (u8 *)DAT_00881630_abs + idx * 0x20;
        if (*(u32 *)(slot + 0x1c) == 0)
            func_0046d730(D_0063BAE8, 0x31D);
        par = (u8 *)DAT_00881630_abs + idx * 4;
        tmp = *(u32 *)(par + 0x180);
        if (tmp == 0)
            continue;
        *(u32 *)(par + ((u8)i - idx) * 4 + 0x180) = 0;
        func_00454bd0(tmp);
        func_00440b68(D_0063BBF0, mask);
        *(u32 *)slot = 0;
        *(u32 *)(slot + 0x1c) = 0;
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271a40);
#endif

// FUN_00271B70
int func_00271b70(int param_1)
{
    char cVar1;
    int uVar2;

    cVar1 = (char)func_00272cb0(param_1);
    if (cVar1 != '\0') {
        uVar2 = param_1;
    } else {
        uVar2 = func_00271bd0(param_1);
    }
    return uVar2;
}
// FUN_00271BD0
u32 func_00271bd0(int param_1)
{
    int iVar4;
    int iVar1;
    int next_list;
    int iVar2;
    u32 *puVar3;

    if (param_1 == 0) {
        return param_1;
    }

    while (param_1 != 0) {
        iVar4 = *(int *)(param_1 + 0x1c);

        while (iVar4 != 0) {
            iVar1 = *(int *)(iVar4 + 0x28);

            if (*(int *)(iVar4 + 0x20) == 0) {
                *(u16 *)(*(int *)(iVar4 + 0x1c) + 4) =
                    *(u16 *)(*(int *)(iVar4 + 0x1c) + 4) + -1;
                iVar2 = *(int *)(iVar4 + 0x1c);

                if ((iVar2 != 0) && (*(u16 *)(iVar2 + 4) == 0)) {
                    puVar3 = *(u32 **)(iVar2 + 0xc);

                    if (puVar3 != (u32 *)0x0) {
                        *puVar3 = *puVar3 & 0xfffffffe;
                        puVar3[4] = 0;
                    }

                    func_00271310((u8 *)*(u32 *)(iVar2 + 8));
                    DAT_00881750_abs[0] = DAT_00881750_abs[0] + -1;
                }
            }

            func_0026e120(iVar4, DAT_0088175c_abs[0]);
            iVar4 = iVar1;
            DAT_00881754_abs[0] = DAT_00881754_abs[0] + -1;
        }

        next_list = *(int *)(param_1 + 0x24);
        func_0026e120(param_1, *(u32 *)DAT_00881760_abs);
        param_1 = next_list;
        DAT_00881758_abs[0] = DAT_00881758_abs[0] + -1;
    }

    return 0;
}



extern char D_00763808;



/* measured: retail's signed x/32 divisions write the mult product into the
   SECOND operand's register ($a2) and sra from it; mwcc b210 writes it into
   the FIRST operand's register ($a1) at all six division sites (nd42; the
   switch-case + empty-if + explicit-shift forms fixed everything else).
   Tried operand-order swaps, no change. Re-tested wave 14 (fresh m2c body
   with resolved globals D_007645A8/-0x4B48, D_007645A0/-0x4B50,
   D_007645A4/-0x4B4C, D_00763808/-0x58E8): nd113 for both manual >>5/>>7
   +correction and /32 /128 spelling - the whole-function register map
   diverges from the start (retail lbu $a3 vs my $t0), not just the mult;
   the recorded nd42 spelling was not reproduced. Mult register-alloc +
   prologue-coloring floor. */
// FUN_00271D10
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271d10);
// FUN_00271F50
extern char D_0063BC20[];
extern u32 func_00276260(u32 param_1, int param_2);
extern u32 func_002761f0(u32 param_1, u32 param_2, u32 param_3);
extern u16 func_00273910(u32 param_1);
extern u16 func_00273940(u32 param_1);

u8 *func_00271f50(u8 *arg0, u32 arg1)
{
    u8 *var_18;
    u8 *temp_17;
    u8 *temp_2;
    u8 *var_16;
    u8 *temp_20;
    u8 sp60[0x10];

    if ((var_18 = (u8 *)(u32)func_00276260(arg1, arg0[0x14])) != NULL) {
        temp_2 = *(u8 **)(var_18 + 0x10);
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 4) += 1;
            return temp_2;
        }
    }
    if (var_18 == NULL) {
        temp_17 = (u8 *)((u32)gFrFontManagerData_abs + (arg0[0x15] << 5));
        func_0044ea90(D_0063BAE8, 0x526);
        temp_20 = (u8 *)jtbl_008873E8[0](0x200, 0x40000);
        func_0026e1a0(*(int **)(temp_17 + 0x1C), (int *)sp60);
        func_0026e1e0((int)temp_20, (int)arg1, *(int *)(temp_17 + 0x1C), (int *)sp60);
        var_18 = (u8 *)(u32)func_002761f0(arg1, (u32)temp_20, arg0[0x14]);
        if (var_18 == NULL) {
            func_0046d730(D_0063BAE8, 0x560);
        }
        DAT_008873ec_abs[0](temp_20);
    }
    func_00273910(arg0[0x15]);
    func_00273940(arg0[0x15]);
    var_16 = *(u8 **)(DAT_0088152C_abs[0] + 0x1C);
    if (*(s32 *)var_16 == 0) {
        var_16 = NULL;
    } else {
        *(u32 *)(*(u32 *)(var_16 + 0x18) + 0x1C) = *(u32 *)(var_16 + 0x1C);
        *(u32 *)(*(u32 *)(var_16 + 0x1C) + 0x18) = *(u32 *)(var_16 + 0x18);
        DAT_00881528_abs[0] -= 1;
    }
    if (var_16 == NULL) {
        func_0046d740(D_0063BC20, D_0063BAE8, 0x508);
    }
    temp_17 = *(u8 **)(var_16 + 0x14);
    if (temp_17 == NULL) {
        func_0046d730(D_0063BAE8, 0x50D);
    }
    *(u16 *)(temp_17 + 4) = 1;
    *(u32 *)(temp_17 + 8) = (u32)var_16;
    *(u16 *)(temp_17 + 0) = (u16)arg1;
    *(u32 *)(temp_17 + 0xC) = (u32)var_18;
    *(u32 *)(var_18 + 0x10) = (u32)temp_17;
    DAT_00881750_abs[0] += 1;
    return temp_17;
}
extern char D_0063BC50[];
extern u8 *func_0026e0e0(s32 param_1);



// FUN_00272170
u8 * func_00272170(u16 arg0, u8 arg1, s8 arg2, s8 arg3)
{
    u8 *node;
    u16 ch;
    s32 width;
    s32 temp;
    s32 temp2;
    u16 glyphcount;
    s8 hit;
    s32 value;

    node = (u8 *)func_0026e0e0(DAT_0088175c_abs[0]);
    DAT_00881754_abs[0] += 1;
    if (node == NULL) {
        func_0046d740(D_0063BC50, D_0063BAE8, 0x5D2);
    }
    *(u16 *)(node + 0) = arg0;
    *(u8 *)(node + 0x15) = arg1;
    *(u32 *)(node + 4) = 0;
    *(u32 *)(node + 8) = 0;
    *(u32 *)(node + 0xC) = 0;
    *(u8 *)(node + 0x14) = arg2;
    *(u32 *)(node + 0x10) = -0x100;
    *(u8 *)(node + 0x16) = arg3;
    *(u8 *)(node + 0x17) = D_00763810;
    *(u16 *)(node + 2) = 0;
    *(u32 *)(node + 0x1C) = 0;
    *(u32 *)(node + 0x20) = 0;
    *(u32 *)(node + 0x24) = 0;
    *(u32 *)(node + 0x28) = 0;
    ch = *(u16 *)node;
    if (ch < 0x80) {
        if (ch == 0x20) {
            width = 0x1F6;
        } else {
            width = ch - 0x20;
        }
    } else {
        temp = ch - 0x8000;
        temp2 = temp - 0x80;
        width = ((temp2 & 0xFF00) >> 1) + (temp2 & 0x7F);
    }
    glyphcount = *(u16 *)((u8 *)*(u32 **)((u8 *)DAT_00881630_abs + (arg1 & 0xFF) * 0x20 + 4) + 0xE);
    if (glyphcount > width) {
        goto width_ok;
    }
    width = 0x147;
width_ok:
    *(u32 *)(node + 0x1C) = (u32)func_00271f50(node, width);
    func_00271d10(node, width);
    if ((*(u8 *)(node + 0x17) & 0x10) == 0) {
        goto zero_store;
    }
    hit = 0;
    switch (width + 0x20) {
    case 0x51:
    case 0x67:
    case 0x6A:
    case 0x70:
    case 0x71:
    case 0x79:
        hit = 1;
        break;
    default:
        break;
    }
    if ((s8)hit == 0) {
        value = 0;
    } else {
        value = 0x10;
    }
    *(u32 *)(node + 8) = (s8)value;
    goto done;
zero_store:
    *(u32 *)(node + 8) = 0;
done:
    return node;
}
// FUN_00272390
int func_00272390(short *param_1)
{
    u16 *puVar3;
    u16 sVar1;
    int iVar2;
    int iVar3;

    puVar3 = *(u16 **)((int)param_1 + 0x24);
    iVar2 = 0;
    if (*(u8 *)((int)param_1 + 0x15) == 0) {
        goto LAB_002723B0;
    }
    if (*(u8 *)((int)param_1 + 0x15) != 1) {
        goto LAB_002724C4;
    }
LAB_002723B0:
    if (puVar3 == (u16 *)0x0) {
        goto LAB_002724C4;
    }
    sVar1 = *(u16 *)param_1;
    switch (sVar1) {
    case 0x61:
    case 0x65:
    case 0x6f:
    case 0x75:
    case 0x80c1:
    case 0x80c5:
    case 0x80cf:
    case 0x80d5:
        goto LAB_00272424;
    default:
        goto LAB_002724C4;
    }
LAB_00272424:
    sVar1 = *puVar3;
    if (sVar1 == 0x54) {
        goto LAB_00272458;
    }
    if (sVar1 == 0x80b4) {
        goto LAB_00272458;
    }
    if (sVar1 == 0x59) {
        goto LAB_00272458;
    }
    if (sVar1 == 0x80b9) {
        goto LAB_00272458;
    }
    goto LAB_00272484;
LAB_00272458:
    iVar2 = 3;
    iVar3 = D_007645A0;
    if (iVar3 <= 0) {
        goto LAB_00272484;
    }
    iVar3 = iVar3 * 3;
    iVar2 = iVar3 >> 7;
    if (iVar3 < 0) {
        iVar2 = iVar3 + 0x7f >> 7;
    }
LAB_00272484:
    if (sVar1 == 0x56) {
        goto LAB_0027249C;
    }
    if (sVar1 != 0x80b6) {
        goto LAB_002724C4;
    }
LAB_0027249C:
    iVar2 = 2;
    iVar3 = D_007645A0;
    if (iVar3 <= 0) {
        goto LAB_002724C4;
    }
    iVar3 = iVar3 * 2;
    iVar2 = iVar3 >> 7;
    if (iVar3 < 0) {
        iVar2 = iVar3 + 0x7f >> 7;
    }
LAB_002724C4:
    return iVar2;
}

extern u8 D_007645B4;
extern u8 *func_00272170(u16 arg0, u8 arg1, s8 arg2, s8 arg3);



/* measured: nd92. Retail colors var_16=$16/var_17=$17/var_18=$18/
   arg4=$19/arg0=$20/var_21=$21/arg2=$22/arg3=$23 and hoists the arg2/arg3
   andi masks before the loop; mwcc b210 colors arg4=$16 first and keeps the
   sltu check at the top (goto-loop) - while conversion fixes the loop shape
   but not the register order; declaration reorders don't move it.
   Saved-register rotation floor. */
// FUN_002724D0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002724d0);
// FUN_00272730
void func_00272730(int param_1, u8 param_2)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x69B);
    }
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
        *(u8 *)(param_1 + 2) = param_2;
    }
}

// FUN_002727A0
void func_002727a0(u32 param_1, u16 param_2)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x6A7);
    }
    *(u16 *)param_1 = param_2;
}

// FUN_002727F0
void func_002727f0(FrFontNode *node)
{
    FrFontNode *iter;

    node->enabled = 1;
    iter = node;
    if (node == NULL) {
        func_0046d730(D_0063BAE8, 0x69B);
    }
    for (; iter != NULL; iter = iter->next) {
        iter->unknown_00[2] = 0xff;
    }
}

// FUN_00272860
void func_00272860(int param_1, int param_2)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x6C3);
    }
    *(u8 *)(param_1 + 3) = param_2;
    *(u32 *)(param_1 + 0xc) = func_002738d0(param_1);
}

// FUN_002728C0
void func_002728c0(int param_1, u8 param_2)
{
    int iVar1;

    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x6F2);
    }
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
        for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0;
             iVar1 = *(int *)(iVar1 + 0x28)) {
            *(u8 *)(iVar1 + 0x15) = param_2;
        }
    }
}

// FUN_00272950
void func_00272950(int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;

    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x708);
    }
    while (*(int *)(param_1 + 0x24) != 0) {
        param_1 = *(int *)(param_1 + 0x24);
    }
    iVar2 = param_2 - *(int *)(param_1 + 4);
    iVar1 = param_3 - *(int *)(param_1 + 8);
    while (param_1 != 0) {
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;
        param_1 = *(int *)(param_1 + 0x28);
    }
}

// FUN_00272A10
void func_00272a10(int param_1, float param_2, float param_3)
{
    int iVar1;
    int iVar2;

    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x71F);
    }
    while (*(int *)(param_1 + 0x24) != 0) {
        param_1 = *(int *)(param_1 + 0x24);
    }
    iVar2 = (int)(16.0f * param_2) - *(int *)(param_1 + 4);
    iVar1 = (int)(8.0f * param_3) - *(int *)(param_1 + 8);
    while (param_1 != 0) {
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;
        param_1 = *(int *)(param_1 + 0x28);
    }
}

/* measured: func_00272b00/00272b34 (and 00272ba0/00272bd4) are one retail
   code region split by Ghidra at a branch target: b00's entry beq jumps to
   b34's entry, whose bne branches back into b00's body. Portable C cannot
   reproduce the cross-function branch (standalone compiles give b00 15 words
   vs a 13-word window and b34 a full body vs a 7-word window). P3FES donor
   keeps the same pair as asm functions (FUN_003b0dd8/FUN_003b0e04).
   Ghidra split, not a compiler floor. */
/* Was recorded here as a Ghidra split that portable C could not express. It was a
   boundary bug, not a source problem: spimdisasm took the landing point of this
   function's opening `b 0x00272B34` - the bottom test of its rotated loop - as a second
   function, so the window stopped at 52 bytes in the middle of the loop and no body
   could ever fill it. 0x00272B34 has zero jal, zero j and zero pointer references in
   the whole image while this address has 17 jal sites. With the landing point withdrawn
   in reconcile_function_boundaries the window is 80 bytes and the obvious nested-while,
   the same shape as the already-matching func_00272b50 below, is byte-exact. */
// FUN_00272B00
void func_00272b00(int param_1, u8 param_2)
{
    FrFontGlyph *glyph;

    while (param_1 != 0) {
        glyph = *(FrFontGlyph **)(param_1 + 0x1c);
        while (glyph != NULL) {
            glyph->unknown_10[4] = param_2;
            glyph = glyph->next;
        }
        param_1 = *(int *)(param_1 + 0x24);
    }
}

// FUN_00272B50
void func_00272b50(int param_1, u8 param_2, u8 param_3)
{
    int key = param_2;
    FrFontGlyph *glyph;

    while (param_1 != 0) {
        glyph = *(FrFontGlyph **)(param_1 + 0x1c);
        while (glyph != NULL) {
            if (glyph->unknown_10[4] == key) {
                glyph->unknown_10[4] = param_3;
            }
            glyph = glyph->next;
        }
        param_1 = *(int *)(param_1 + 0x24);
    }
}

/* measured: s32 twin of the func_00272b00/00272b34 split above (stores a
   u32 at +0x10 instead of a u8 at +0x14); 00272bd4's entry bne branches back
   into 00272ba0's body. Same Ghidra split, same impossibility for portable C
   (see the note above FUN_00272B00). */
/* The u32 twin of func_00272b00 above (stores at +0x10 instead of a u8 at +0x14).
   Same withdrawn branch-landing entry (0x00272BD4, zero callers; this address has 18
   jal sites), same 80-byte window, same nested-while body. */
// FUN_00272BA0
void func_00272ba0(int param_1, u32 param_2)
{
    FrFontGlyph *glyph;

    while (param_1 != 0) {
        glyph = *(FrFontGlyph **)(param_1 + 0x1c);
        while (glyph != NULL) {
            *(u32 *)((u8 *)glyph + 0x10) = param_2;
            glyph = glyph->next;
        }
        param_1 = *(int *)(param_1 + 0x24);
    }
}

// FUN_00272BF0
int func_00272bf0(int param_1)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x77B);
    }
    while (*(int *)(param_1 + 0x24) != 0) {
        param_1 = *(int *)(param_1 + 0x24);
    }
    return param_1;
}
// FUN_00272C60
u16 func_00272c60(s16 param_1)
{
    u16 uVar1;

    uVar1 = D_00763810;
    D_00763810 = D_00763810 | param_1;
    return uVar1;
}



// FUN_00272C80
u16 func_00272c80(u16 param_1)
{
    u16 uVar1;
    long mask;

    uVar1 = D_00763810;
    mask = (s16)~param_1;
    D_00763810 = D_00763810 & mask;
    return uVar1;
}


// Ported from P3FES FUN_003b0ec0 (verified MATCH there). Retail hoists the
// loop-invariant mask/type constants here; removing opt_loop_invariants
// measured nd102 at 136B instead of nd1 at 140B (P3 donor annotation).

// FUN_00272CB0
#pragma push
#pragma opt_loop_invariants on

u32 func_00272cb0(int list)
{
    u32 result = 0;
    u32 mask = ~0xff;
    u32 changed = 1;
    u32 type = 2;

    while (list != 0) {
        int node = *(int *)(list + 0x1c);

        while (node != 0) {
            if (*(u8 *)(node + 0x16) == type) {
                u32 word = *(u32 *)(node + 0x10);
                u32 fade = word & 0xff;
                u32 merged;

                if (fade != 0) {
                    fade -= 8;
                    if ((s32)fade < 0) {
                        fade = 0;
                    }
                    merged = word & mask;
                    merged |= fade;
                    *(u32 *)(node + 0x10) = merged;
                    *(u32 *)(node + 8) += 0x10;
                    result = changed;
                }
            }
            node = *(int *)(node + 0x28);
        }
        list = *(int *)(list + 0x24);
    }
    return result;
}
#pragma opt_loop_invariants off
#pragma pop



// FUN_00272D40
u8 *func_00272d40(u8 *arg0)
{
    s32 temp;

    temp = *(s32 *)(arg0 + 0x30);
    switch (temp) {
    case 0xF222:
    case 0xF227:
        temp = *(s32 *)(arg0 + 0x3C);
        if (temp == -1) {
            break;
        }
        if (temp > 0) {
            return arg0;
        }
        break;
    case 0xF223:
    case 0xF226:
        temp = *(s32 *)(arg0 + 0x3C);
        if (temp == -1) {
            if (func_0045af90(1) != 0) {
                return arg0;
            }
        } else if (temp > 0) {
            return arg0;
        }
        break;
    }
    return 0;
}
/* measured: retail keeps arg1=$16/arg0=$17/temp_18=$18/var_19=$19/var_20=$20/
   var_21=$21/var_22=$22/arg3=$23; mwcc b210 colors arg3=$16 FIRST and omits
   the arg1+0x10 hoist (nd167). Declaration reorders (4 orders probed), u32
   param widths, ternary float, early hoist, switch-wrapped final if: no
   combination moves it. Float if/else also emits a branch-to-branch where
   retail branches to the join. Re-tested wave 14 (fresh m2c body, nd170):
   confirms the pervasive rotation - retail saves 8 (frame 0x90,
   arg0=$s1/arg1=$s0/arg3=$s7), mwcc saves 7 (frame 0x80, arg0=$s3/arg1=$s2)
   from the very first move; also fixed func_00272d40's call to 1 arg (m2c
   draft wrongly shows 2; retail calls with $18 only). Saved-register
   rotation floor. */
// FUN_00272E10
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272e10);
// FUN_00273110
void func_00273110(s32 arg0)
{
    func_00273140((void *)arg0, 0);
}



// FUN_00273140
void func_00273140(void *param_1, u32 param_2)
{
    func_00273170(param_1, param_2, D_00764598);
}



extern s32 D_0076459C;
extern void func_003f6440(s32 param_1, s32 param_2);
extern s32 func_00272e10(u8 *param_1, u8 *param_2, u8 param_3, u8 param_4);
extern void func_00275d80(s32 param_1, s32 param_2, u8 *param_3,
                         u8 param_4, u8 param_5, u8 param_6, s32 param_7,
                         f32 param_8);
extern code D_00887300_abs[];



/* measured: recipe B retest 2026-08-03 - nd194..195 (recorded 131 not
   reproducible this wave). Tried the wave's u32-cast vtable form
   (u32 base = (u32)D_00887300; ((void (*)(s32,s32))*(u32 *)base)(...)) -
   nd195, the void *(**) local - nd195, named prologue s8 local, m2c-draft
   mirror, ternary arg1 test + s32 temp_23 - nd194. The hoist itself works in
   all forms (8 vtable calls match); the residual is: mwcc hoists the
   loop-invariant arg1-s8 test out of the inner loop where retail re-tests
   per iteration, re-extends the s8 temp_23 at its use (lb + dsll32/dsra32
   vs retail's single lb into $23), and saves 7 registers (frame 0x80) vs
   retail's 8 (frame 0x90) - same saved-register rotation family as the
   recorded note, plus an invariant-if hoist. */
// FUN_00273170
INCLUDE_ASM("asm/nonmatchings/frFont", func_00273170);
/* measured: retail's 4-case dispatch emits an extra scheduler nop before the
   default branch (beq;nop;nop;b vs mwcc b210's beq;nop;b), shifting the whole
   tail by one word; every instruction's content otherwise matches (nd 82 =
   = the one-word shift across ~49 words). Tried switch with goto-to-default
   NULL block (m2c block_18 shape), direct-deref switch, per-branch NULL
   assignments, reversed case declarations - the nop never appears.
   Re-tested wave 14 (5 fresh spellings: if/else || form nd76, switch
   case-decl 0xF226/223/227/222 nd80, switch reverse-order nd81, flag/sum
   decl swap nd81, result-variable switch nd78). The switch with case groups
   declared (0xF222,0xF227) then (0xF223,0xF226) DOES emit retail's exact beq
   test order (F226,F223,F227,F222); residual is the saved-register rotation
   (retail node=$s2/flag=$s1/sum=$s0, mwcc swaps flag/sum) + the shared
   default result=0 block layout. Branch-scheduling + saved-register rotation
   floors. */
// FUN_002734B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002734b0);
// FUN_00273610
u32 func_00273610(void)
{
    DAT_0088179C_abs[0] = func_00271bd0(DAT_0088179C_abs[0]);
    func_00275c00();
    return 0;
}
// FUN_00273650
int func_00273650(int param_1, int param_2, int param_3)
{
    if (param_1 != 0)
    {
        goto checkParam2;
    }
    return param_2;

checkParam2:
    if (param_2 != 0)
    {
        goto body;
    }
    return param_1;

body:
    *(u32*)(param_1 + 0x28) = *(u32*)(param_2 + 0x2c);
    *(int*)(*(int*)(param_2 + 0x2c) + 0x24) = param_1;
    *(u32*)(param_2 + 0x2c) = *(u32*)(param_1 + 0x2c);

    if (param_3 == 1)
    {
        *(int*)(param_2 + 4) = *(int*)(param_1 + 4) + *(int*)(param_1 + 0xc) * 0x10;
        *(u32*)(param_2 + 8) = *(u32*)(param_1 + 8);
    }

    return param_2;
}



extern int func_00273970(int param_1);



/* measured 2026-08-08: reconstructed the 0x40-byte-linked-list extractor
   with a typed local node and explicit goto CFG. The declaration order
   temp_3,var_18,temp_17,var_7,... plus the forward count guard
   `func_00273970(temp_17) > var_18` yields retail's saved colors and
   `slt $at`; optimization_level 1 with opt_common_subs on is load-bearing.
   MATCH nd 0, object 464/window 464 (O2 nd2; O1 without common-substitutions
   nd36). */
// FUN_002736D0
/* measured: opens the optimization_level 1 scope for func_002736d0; the
   common-substitution setting is required for MATCH nd 0. */
#pragma optimization_level 1
#pragma opt_common_subs on
u8 *func_002736d0(u8 **arg0, s32 arg1)
{
    struct FrFontTreeNode {
        u8 unknown_00[8];
        s32 type;
        u8 unknown_0C[0x18];
        struct FrFontTreeNode *prev;
        struct FrFontTreeNode *next;
        struct FrFontTreeNode *root;
    };
    s32 temp_3;
    s32 var_18;
    struct FrFontTreeNode *temp_17;
    struct FrFontTreeNode *var_7;
    struct FrFontTreeNode *temp_3_2;
    struct FrFontTreeNode *temp_4;
    struct FrFontTreeNode *temp_6;
    struct FrFontTreeNode *var_2;
    struct FrFontTreeNode *var_3;
    struct FrFontTreeNode *var_4;
    struct FrFontTreeNode *var_5;

    var_18 = arg1;
    if (arg0 == NULL) {
        func_0046d730(&D_0063BAE8, 0x96B);
    }
    temp_17 = (struct FrFontTreeNode *)*arg0;
    if (temp_17 == NULL) {
        return NULL;
    }
    if (func_00273970((int)temp_17) < 2) {
        return NULL;
    }
    if (func_00273970((int)temp_17) > var_18) {
        goto count_ok;
    }
    return NULL;
count_ok:
    var_7 = temp_17->root;
    goto outer_check;
outer_body:
    temp_3 = var_7->type;
    var_7 = var_7->next;
    goto inner_check;
inner_body:
    temp_3_2 = (struct FrFontTreeNode *)var_7->type;
    if ((s32)temp_3_2 != temp_3) {
        goto outer_decrement;
    }
    var_7 = var_7->next;
inner_check:
    if (var_7 != NULL) {
        goto inner_body;
    }
outer_decrement:
    var_18 -= 1;
outer_check:
    if (var_18 > 0) {
        goto outer_body;
    }
    if (var_7 == NULL) {
        return NULL;
    }
    var_2 = var_7;
    goto result_check;
result_body:
    if (temp_6->type != var_7->type) {
        goto result_done;
    }
    var_2 = temp_6;
result_check:
    temp_6 = var_2->next;
    if (temp_6 != NULL) {
        goto result_body;
    }
result_done:
    var_5 = var_7->root;
    if (var_5 != var_7) {
        goto root_done;
    }
    var_5 = temp_6;
root_done:
    temp_3_2 = var_7->prev;
    if (temp_3_2 == NULL) {
        goto prev_done;
    }
    temp_3_2->next = temp_6;
prev_done:
    temp_4 = var_2->next;
    if (temp_4 == NULL) {
        goto next_done;
    }
    temp_4->prev = var_7->prev;
next_done:
    var_7->prev = NULL;
    var_2->next = NULL;
    var_3 = var_7;
    goto loop29_check;
loop29_body:
    var_3->root = var_7;
    var_3 = var_3->next;
loop29_check:
    if (var_3 != NULL) {
        goto loop29_body;
    }
    var_4 = var_5;
    goto loop32_check;
loop32_body:
    var_4->root = var_5;
    var_4 = var_4->next;
loop32_check:
    if (var_4->next != NULL) {
        goto loop32_body;
    }
    var_4->root = var_5;
    *arg0 = (u8 *)var_4;
    return (u8 *)var_2;
}
/* measured: closes the optimization_level 1 scope; func_002736d0 remains
   MATCH nd 0, object 464/window 464 at the file's O2 baseline. */
#pragma optimization_level 2



// FUN_002738A0
void func_002738a0(u64 param_1)
{
    func_002716b0_typed(8, param_1, 0);
}



// FUN_002738D0
int func_002738d0(FrFontNode *node)
{
    int total = 0;
    FrFontGlyph *glyph;

    for (glyph = node->glyphs; glyph != NULL; glyph = glyph->next) {
        total += glyph->advance;
        total += node->line_height;
    }
    return total;
}




// FUN_00273910
u16 func_00273910(u32 param_1)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(param_1 & 0xff) * 8];
    return *(u16 *)((u8 *)entry + 0x10);
}




// FUN_00273940
u16 func_00273940(u32 param_1)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(param_1 & 0xff) * 8];
    return *(u16 *)((u8 *)entry + 0x12);
}


// func_002745c0 is intentionally left undeclared (implicit old-style call,
// as in the P3 donor): a typed u8 prototype makes mwcc emit andi
// zero-extensions the retail never has.

// FUN_00273970
int func_00273970(int node)
{
    int result = 0;
    int child;

    if (node == 0) {
        return result;
    }
    node = *(int *)(node + 0x2c);
    while (node != 0) {
        child = *(int *)(node + 0x28);
        node = *(int *)(node + 8);
        while (child != 0) {
            if (*(int *)(child + 8) != node) {
                break;
            }
            child = *(int *)(child + 0x28);
        }
        result++;
        node = child;
    }
    return result;
}

/* measured: nd132 at 704B vs 720B retail body. Two independent residuals:
   (1) all three if(body with a call){func_002724d0/73650} sites compile
   inline-with-negated-skip (beqz) in b210, retail places each out-of-line
   with a positive bnez + skip-b (same floor as FUN_00273F70; 4 spellings
   tried there); (2) saved-register permutation - retail colors arg1=$20/
   temp_19=$19/var_18=$18/temp_17=$17, b210 colors arg1=$19/temp_19=$18/
   var_18=$17/temp_17=$20 (var_16=$16, var_21=$21, temp_22=$22 match) and
   no declaration order tried moved them. sp8C slot fixed with int+cast.
   Re-tested wave 14 (fresh m2c body, u8 arg0 type, nd155): the s8 sp8C/
   sp8D locals place the stack bytes at 0x8f (my spelling) vs the note's
   int+cast 0x8c fix; register rotation is pervasive from the first arg
   (retail arg1=$s4, mine $s3). Also fixed func_002724d0's extern param_5
   from int to void* (retail passes a pointer there) - no codegen change to
   the matched 40. If-body placement + saved-register rotation floors. */
// FUN_002739E0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002739e0);

extern s8 D_0076380C;
extern s32 func_00442948(const void *param_1);



/* measured: nd124. mwcc b210 places the sp8C/sp8D stack bytes at 0x8f (top
   byte) with s8 locals; declaring `int sp8` + (s8*)&sp8 fixes the 0x8c slot.
   Remaining: zero-loop ptr/counter registers (v1/a0 vs a0/v1), outer loop
   check-at-top vs retail's b-to-bottom, func_00273650 bodies inline vs
   retail's out-of-line - all layout/alloc floors (like FUN_00273F70). */
// FUN_00273CC0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00273cc0);
/* measured: retail places the if(temp_5 != 0){func_00273650 call} body
   OUT-OF-LINE with a positive branch (bnez $a1,Lbody; b Lafter; Lbody:
   call; Lafter: sw) - nd49 with the whole tail shifted; mwcc b210 compiles
   the same call inline-with-negated-skip (beqz) in every spelling tried
   (plain if, switch case0/default in both declaration orders, empty-if +
   else). The remaining 48 words are the resulting layout shift only.
   If-body placement floor. Re-tested wave 14 (fresh m2c reconstruction with
   D_007645B4/&D_00763838 globals, nd51): #pragma opt_propagation off (lever
   2) and the goto out-of-line form both leave nd51 - b210 still inlines the
   func_00273650 call block with beqz, retail branches positively to it. The
   assert-branch (if arg0->0x14 && arg0->0x14->0x1C==0) and the register map
   (retail var_18=$s2, mwcc $s1) also rotate. If-body placement + saved-
   register rotation floors. */
// FUN_00273F70
/* measured: full func_002736d0 recipe stack. */
#pragma optimization_level 1
#pragma opt_common_subs on
void func_00273f70(u8 *arg0)
{
    extern u8 iGpffffa748;
    struct FrFontNode2 {
        u16 value_00;
        u8 code_02;
        u8 unknown_03;
        u32 value_04;
        u32 value_08;
        u8 unknown_0C[0x10];
        u32 flag_1C;
        u8 unknown_20[4];
        struct FrFontNode2 *next;
    };
    struct FrFontWork2 {
        u32 value_00;
        u32 value_04;
        u8 unknown_08[5];
        s8 code_0D;
        s8 code_0E;
        u8 code_0F;
        u8 unknown_10[4];
        struct FrFontNode2 *list_14;
        u8 unknown_18[4];
        s8 active_1C;
        s8 pending_1D;
        s16 height_1E;
    };
    struct FrFontWork2 *work;
    s16 height;
    struct FrFontNode2 *node;
    struct FrFontNode2 *list;
    struct FrFontNode2 *updated;
    u8 code;
    u32 pending_value;
    u8 *result;

    work = (struct FrFontWork2 *)arg0;
    node = work->list_14;
    if ((node != NULL) && (node->flag_1C == 0)) {
        work->active_1C = 0;
    }
    if (work->active_1C == 0) {
        goto done;
    }
    list = work->list_14;
    result = (u8 *)func_002724d0(&iGpffffa748, 0, work->code_0D, work->code_0E, NULL);
    if (result == NULL) {
        updated = list;
        goto call_after;
    }
    updated = (struct FrFontNode2 *)func_00273650((int)list, (int)result, 1);
    goto call_after;
call_after:
    list = updated;
    work->list_14 = list;
    code = work->code_0F;
    if (list != NULL) {
        goto loop_check;
    }
    func_0046d730(&D_0063BAE8, 0x69B);
    goto loop_check;
loop_body:
    list->code_02 = code;
    list = list->next;
loop_check:
    if (list != NULL) {
        goto loop_body;
    }
    height = work->height_1E;
    node = work->list_14;
    if (node == NULL) {
        func_0046d730(&D_0063BAE8, 0x6A7);
    }
    node->value_00 = (u32)(s32)height;
    work->active_1C = 0;
done:
    if (work->pending_1D == 0) {
        goto return_point;
    }
    pending_value = work->value_00;
    node = work->list_14;
    node->value_04 = pending_value;
    pending_value = work->value_04;
    node = work->list_14;
    node->value_08 = pending_value;
    work->pending_1D = 0;
return_point:
    return;
}
/* measured: close recipe stack. */
#pragma optimization_level 2




/* measured: nd217 at 1208B vs 1216B window. Structure matches (first-if,
   D_00763810 update, while loop with comma-condition); residual is (1) the
   proven if-body-out-of-line floor at the func_002724d0/00273650 site (see
   FUN_00273F70/FUN_002739E0 - b210 inlines the call block, retail branches
   positively to it), which alone shifts the tail, and (2) a saved-register
   map one register off - retail saves only $16-$19 (temp_16/temp_17/temp_18/
   arg0, reusing $17 for var_17), b210 adds a 5th saved reg for the separate
   var_17 local and masks temp_16 through $s0 (andi 0xFF) at the loop test.
   Frame 0x70 vs retail 0x60. If-body placement + saved-register rotation
   floors. */
// FUN_002740B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002740b0);


// FUN_00274570
void func_00274570(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                   u32 param_5, u32 param_6, u32 param_7, u32 param_8)
{
    func_002745c0(param_1, param_2, 0, param_3, param_4, param_5, param_6, param_7, param_8);
}

// FUN_002745C0
void func_002745c0(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                   u32 param_5, u32 param_6, u32 param_7, u32 param_8,
                   u32 param_9)
{
    struct {
        u32 f00;
        u32 f04;
        u32 f08;
        u8 f0c;
        u8 f0d;
        u8 f0e;
        u8 f0f;
        u32 f10;
        u32 f14;
        u32 f18;
        u8 f1c;
        u8 f1d;
        u16 f1e;
    } data;

    data.f00 = param_1;
    data.f04 = param_2;
    data.f08 = param_3 << 4;
    data.f0c = param_4;
    data.f0d = param_5;
    data.f0e = param_6;
    data.f0f = param_7;
    data.f10 = param_8;
    data.f14 = param_9;
    data.f18 = 0;
    data.f1c = 1;
    data.f1d = 1;
    data.f1e = 0x20;
    func_002746b0(0);
    func_002740b0(&data);
}


// FUN_00274640
void func_00274640(void)
{
    D_007637F8 = 0;
}

// FUN_00274660
void func_00274660(u32 param_1, int param_2)
{
    if (param_2 != 0) {
        D_007637F8 |= param_1;
    } else {
        D_007637F8 &= ~param_1;
    }
}

// FUN_002746A0
u32 func_002746a0(void)
{
    return D_00764594;
}

// FUN_002746B0
void func_002746b0(u32 param_1)
{
    D_00764594 = param_1;
}

/* measured: retail colors arg0=$s3 first, arg1=$s4, and enters the script
   loop via b to the bottom check (while shape); mwcc b210 colors arg1=$s3
   first and falls into the loop body (do-while shape), nd109 best (struct
   field access for 0x10/0x18 kills the address hoisting mwcc adds with raw
   pointer casts; nd125 with inline casts, nd125 original). Register-order +
   loop-entry floor. */
// FUN_002746E0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002746e0);
// FUN_002748E0
s8 func_002748e0(int param_1, int param_2, int param_3)
{
    struct {
        u8 f00[0x10];
        u32 f10;
        u32 f14;
        u32 f18;
        u8 f1c;
        u8 f1d;
        u16 f1e;
    } data;
    u32 old;
    s8 result;

    func_0043f9c8(&data, 0, 0x20);
    data.f10 = param_1;
    data.f18 = 0;
    data.f1c = 1;
    data.f1d = 1;
    data.f1e = 0x20;
    old = D_00764594;
    D_00764594 = param_2;
    result = func_002746e0(&data, param_3);
    D_00764594 = old;
    return result;
}

// FUN_00274970
void func_00274970(void)
{
    int v;

    func_002baa20();
    v = func_002e0d60();
    *(int *)v = func_00451de0(&D_00763840, 0xC8, 0, 0, func_002e17f0, 0, 0);
    func_002713b0(0x100, 0x100);
    func_00451de0(&D_00763848, 0, 0, 0, func_00273610, func_002715c0, 0);
    func_002bcd20();
}

