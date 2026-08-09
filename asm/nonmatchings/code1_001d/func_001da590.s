.section .text
.set noat
.set noreorder
glabel func_001da590
    /* DA590 001DA590 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA594 001DA594 0000BFFF */  sd         $31, 0x0($29)
    /* DA598 001DA598 3000828C */  lw         $2, 0x30($4)
    /* DA59C 001DA59C A2004290 */  lbu        $2, 0xA2($2)
    /* DA5A0 001DA5A0 04004014 */  bnez       $2, .L001DA5B4
    /* DA5A4 001DA5A4 00000000 */   nop
    /* DA5A8 001DA5A8 01000224 */  addiu      $2, $0, 0x1
    /* DA5AC 001DA5AC 02000010 */  b          .L001DA5B8
    /* DA5B0 001DA5B0 00000000 */   nop
  .L001DA5B4:
    /* DA5B4 001DA5B4 2D100000 */  daddu      $2, $0, $0
  .L001DA5B8:
    /* DA5B8 001DA5B8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DA5BC 001DA5BC 01000224 */  addiu      $2, $0, 0x1
    /* DA5C0 001DA5C0 04106200 */  sllv       $2, $2, $3
    /* DA5C4 001DA5C4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA5C8 001DA5C8 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA5CC 001DA5CC 2D400000 */  daddu      $8, $0, $0
    /* DA5D0 001DA5D0 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DA5D4 001DA5D4 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DA5D8 001DA5D8 3465070C */  jal        func_001d94d0
    /* DA5DC 001DA5DC 00000000 */   nop
    /* DA5E0 001DA5E0 0000BFDF */  ld         $31, 0x0($29)
    /* DA5E4 001DA5E4 1000BD27 */  addiu      $29, $29, 0x10
    /* DA5E8 001DA5E8 0800E003 */  jr         $31
    /* DA5EC 001DA5EC 00000000 */   nop
.size func_001da590, 0x60
