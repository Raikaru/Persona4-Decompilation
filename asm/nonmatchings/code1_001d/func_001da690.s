.section .text
.set noat
.set noreorder
glabel func_001da690
    /* DA690 001DA690 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA694 001DA694 0000BFFF */  sd         $31, 0x0($29)
    /* DA698 001DA698 3000828C */  lw         $2, 0x30($4)
    /* DA69C 001DA69C A2004290 */  lbu        $2, 0xA2($2)
    /* DA6A0 001DA6A0 04004014 */  bnez       $2, .L001DA6B4
    /* DA6A4 001DA6A4 00000000 */   nop
    /* DA6A8 001DA6A8 01000224 */  addiu      $2, $0, 0x1
    /* DA6AC 001DA6AC 02000010 */  b          .L001DA6B8
    /* DA6B0 001DA6B0 00000000 */   nop
  .L001DA6B4:
    /* DA6B4 001DA6B4 2D100000 */  daddu      $2, $0, $0
  .L001DA6B8:
    /* DA6B8 001DA6B8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DA6BC 001DA6BC 01000224 */  addiu      $2, $0, 0x1
    /* DA6C0 001DA6C0 04106200 */  sllv       $2, $2, $3
    /* DA6C4 001DA6C4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA6C8 001DA6C8 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA6CC 001DA6CC 2D400000 */  daddu      $8, $0, $0
    /* DA6D0 001DA6D0 1E00093C */  lui        $9, %hi(func_001da5f0)
    /* DA6D4 001DA6D4 F0A52925 */  addiu      $9, $9, %lo(func_001da5f0)
    /* DA6D8 001DA6D8 3465070C */  jal        func_001d94d0
    /* DA6DC 001DA6DC 00000000 */   nop
    /* DA6E0 001DA6E0 0000BFDF */  ld         $31, 0x0($29)
    /* DA6E4 001DA6E4 1000BD27 */  addiu      $29, $29, 0x10
    /* DA6E8 001DA6E8 0800E003 */  jr         $31
    /* DA6EC 001DA6EC 00000000 */   nop
.size func_001da690, 0x60
