.section .text
.set noat
.set noreorder
glabel func_001df520
    /* DF520 001DF520 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF524 001DF524 1000BFFF */  sd         $31, 0x10($29)
    /* DF528 001DF528 0000B07F */  sq         $16, 0x0($29)
    /* DF52C 001DF52C 2D200000 */  daddu      $4, $0, $0
    /* DF530 001DF530 00730A0C */  jal        func_0029cc00
    /* DF534 001DF534 00000000 */   nop
    /* DF538 001DF538 3C1A0200 */  dsll32     $3, $2, 8
    /* DF53C 001DF53C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF540 001DF540 0004023C */  lui        $2, (0x4000000 >> 16)
    /* DF544 001DF544 25806200 */  or         $16, $3, $2
    /* DF548 001DF548 14740A0C */  jal        func_0029d050
    /* DF54C 001DF54C 00000000 */   nop
    /* DF550 001DF550 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF554 001DF554 24180302 */  and        $3, $16, $3
    /* DF558 001DF558 021E0300 */  srl        $3, $3, 24
    /* DF55C 001DF55C 3C2A1000 */  dsll32     $5, $16, 8
    /* DF560 001DF560 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF564 001DF564 04006014 */  bnez       $3, .L001DF578
    /* DF568 001DF568 00000000 */   nop
    /* DF56C 001DF56C 2D100000 */  daddu      $2, $0, $0
    /* DF570 001DF570 0B000010 */  b          .L001DF5A0
    /* DF574 001DF574 00000000 */   nop
  .L001DF578:
    /* DF578 001DF578 2D204000 */  daddu      $4, $2, $0
    /* DF57C 001DF57C 40100300 */  sll        $2, $3, 1
    /* DF580 001DF580 21104300 */  addu       $2, $2, $3
    /* DF584 001DF584 80180200 */  sll        $3, $2, 2
    /* DF588 001DF588 6100023C */  lui        $2, %hi(D_00609850)
    /* DF58C 001DF58C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF590 001DF590 21104300 */  addu       $2, $2, $3
    /* DF594 001DF594 0000428C */  lw         $2, 0x0($2)
    /* DF598 001DF598 09F84000 */  jalr       $2
    /* DF59C 001DF59C 00000000 */   nop
  .L001DF5A0:
    /* DF5A0 001DF5A0 2B200200 */  sltu       $4, $0, $2
    /* DF5A4 001DF5A4 D4730A0C */  jal        func_0029cf50
    /* DF5A8 001DF5A8 00000000 */   nop
    /* DF5AC 001DF5AC 01000224 */  addiu      $2, $0, 0x1
    /* DF5B0 001DF5B0 1000BFDF */  ld         $31, 0x10($29)
    /* DF5B4 001DF5B4 0000B07B */  lq         $16, 0x0($29)
    /* DF5B8 001DF5B8 2000BD27 */  addiu      $29, $29, 0x20
    /* DF5BC 001DF5BC 0800E003 */  jr         $31
    /* DF5C0 001DF5C0 00000000 */   nop
    /* DF5C4 001DF5C4 00000000 */  nop
    /* DF5C8 001DF5C8 00000000 */  nop
    /* DF5CC 001DF5CC 00000000 */  nop
.size func_001df520, 0xb0
