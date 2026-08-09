.section .text
.set noat
.set noreorder
glabel func_001da780
    /* DA780 001DA780 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA784 001DA784 0000BFFF */  sd         $31, 0x0($29)
    /* DA788 001DA788 3000828C */  lw         $2, 0x30($4)
    /* DA78C 001DA78C A2004290 */  lbu        $2, 0xA2($2)
    /* DA790 001DA790 04004014 */  bnez       $2, .L001DA7A4
    /* DA794 001DA794 00000000 */   nop
    /* DA798 001DA798 01000224 */  addiu      $2, $0, 0x1
    /* DA79C 001DA79C 02000010 */  b          .L001DA7A8
    /* DA7A0 001DA7A0 00000000 */   nop
  .L001DA7A4:
    /* DA7A4 001DA7A4 2D100000 */  daddu      $2, $0, $0
  .L001DA7A8:
    /* DA7A8 001DA7A8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DA7AC 001DA7AC 01000224 */  addiu      $2, $0, 0x1
    /* DA7B0 001DA7B0 04106200 */  sllv       $2, $2, $3
    /* DA7B4 001DA7B4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA7B8 001DA7B8 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA7BC 001DA7BC 2D400000 */  daddu      $8, $0, $0
    /* DA7C0 001DA7C0 1E00093C */  lui        $9, %hi(func_001da6f0)
    /* DA7C4 001DA7C4 F0A62925 */  addiu      $9, $9, %lo(func_001da6f0)
    /* DA7C8 001DA7C8 3465070C */  jal        func_001d94d0
    /* DA7CC 001DA7CC 00000000 */   nop
    /* DA7D0 001DA7D0 0000BFDF */  ld         $31, 0x0($29)
    /* DA7D4 001DA7D4 1000BD27 */  addiu      $29, $29, 0x10
    /* DA7D8 001DA7D8 0800E003 */  jr         $31
    /* DA7DC 001DA7DC 00000000 */   nop
.size func_001da780, 0x60
