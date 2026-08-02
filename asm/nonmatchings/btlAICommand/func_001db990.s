.section .text
.set noat
.set noreorder
glabel func_001db990
    /* DB990 001DB990 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB994 001DB994 0000BFFF */  sd         $31, 0x0($29)
    /* DB998 001DB998 3000828C */  lw         $2, 0x30($4)
    /* DB99C 001DB99C A2004290 */  lbu        $2, 0xA2($2)
    /* DB9A0 001DB9A0 04004014 */  bnez       $2, .L001DB9B4
    /* DB9A4 001DB9A4 00000000 */   nop
    /* DB9A8 001DB9A8 01000224 */  addiu      $2, $0, 0x1
    /* DB9AC 001DB9AC 02000010 */  b          .L001DB9B8
    /* DB9B0 001DB9B0 00000000 */   nop
  .L001DB9B4:
    /* DB9B4 001DB9B4 2D100000 */  daddu      $2, $0, $0
  .L001DB9B8:
    /* DB9B8 001DB9B8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DB9BC 001DB9BC 01000224 */  addiu      $2, $0, 0x1
    /* DB9C0 001DB9C0 04106200 */  sllv       $2, $2, $3
    /* DB9C4 001DB9C4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DB9C8 001DB9C8 0800073C */  lui        $7, (0x80000 >> 16)
    /* DB9CC 001DB9CC 2D400000 */  daddu      $8, $0, $0
    /* DB9D0 001DB9D0 1E00093C */  lui        $9, %hi(func_001db900)
    /* DB9D4 001DB9D4 00B92925 */  addiu      $9, $9, %lo(func_001db900)
    /* DB9D8 001DB9D8 3465070C */  jal        func_001d94d0
    /* DB9DC 001DB9DC 00000000 */   nop
    /* DB9E0 001DB9E0 0000BFDF */  ld         $31, 0x0($29)
    /* DB9E4 001DB9E4 1000BD27 */  addiu      $29, $29, 0x10
    /* DB9E8 001DB9E8 0800E003 */  jr         $31
    /* DB9EC 001DB9EC 00000000 */   nop
.size func_001db990, 0x60
