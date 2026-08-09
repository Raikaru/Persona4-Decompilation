.section .text
.set noat
.set noreorder
glabel func_001dab00
    /* DAB00 001DAB00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DAB04 001DAB04 0000BFFF */  sd         $31, 0x0($29)
    /* DAB08 001DAB08 3000828C */  lw         $2, 0x30($4)
    /* DAB0C 001DAB0C A2004290 */  lbu        $2, 0xA2($2)
    /* DAB10 001DAB10 04004014 */  bnez       $2, .L001DAB24
    /* DAB14 001DAB14 00000000 */   nop
    /* DAB18 001DAB18 01000224 */  addiu      $2, $0, 0x1
    /* DAB1C 001DAB1C 02000010 */  b          .L001DAB28
    /* DAB20 001DAB20 00000000 */   nop
  .L001DAB24:
    /* DAB24 001DAB24 2D100000 */  daddu      $2, $0, $0
  .L001DAB28:
    /* DAB28 001DAB28 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DAB2C 001DAB2C 01000224 */  addiu      $2, $0, 0x1
    /* DAB30 001DAB30 04106200 */  sllv       $2, $2, $3
    /* DAB34 001DAB34 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DAB38 001DAB38 1800073C */  lui        $7, (0x180000 >> 16)
    /* DAB3C 001DAB3C 2D400000 */  daddu      $8, $0, $0
    /* DAB40 001DAB40 1E00093C */  lui        $9, %hi(func_001da270)
    /* DAB44 001DAB44 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DAB48 001DAB48 3465070C */  jal        func_001d94d0
    /* DAB4C 001DAB4C 00000000 */   nop
    /* DAB50 001DAB50 0000BFDF */  ld         $31, 0x0($29)
    /* DAB54 001DAB54 1000BD27 */  addiu      $29, $29, 0x10
    /* DAB58 001DAB58 0800E003 */  jr         $31
    /* DAB5C 001DAB5C 00000000 */   nop
.size func_001dab00, 0x60
