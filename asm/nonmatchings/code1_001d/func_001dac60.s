.section .text
.set noat
.set noreorder
glabel func_001dac60
    /* DAC60 001DAC60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DAC64 001DAC64 0000BFFF */  sd         $31, 0x0($29)
    /* DAC68 001DAC68 3000828C */  lw         $2, 0x30($4)
    /* DAC6C 001DAC6C A2004290 */  lbu        $2, 0xA2($2)
    /* DAC70 001DAC70 04004014 */  bnez       $2, .L001DAC84
    /* DAC74 001DAC74 00000000 */   nop
    /* DAC78 001DAC78 01000224 */  addiu      $2, $0, 0x1
    /* DAC7C 001DAC7C 02000010 */  b          .L001DAC88
    /* DAC80 001DAC80 00000000 */   nop
  .L001DAC84:
    /* DAC84 001DAC84 2D100000 */  daddu      $2, $0, $0
  .L001DAC88:
    /* DAC88 001DAC88 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DAC8C 001DAC8C 01000224 */  addiu      $2, $0, 0x1
    /* DAC90 001DAC90 04106200 */  sllv       $2, $2, $3
    /* DAC94 001DAC94 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DAC98 001DAC98 1800073C */  lui        $7, (0x180000 >> 16)
    /* DAC9C 001DAC9C 2D400000 */  daddu      $8, $0, $0
    /* DACA0 001DACA0 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DACA4 001DACA4 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DACA8 001DACA8 3465070C */  jal        func_001d94d0
    /* DACAC 001DACAC 00000000 */   nop
    /* DACB0 001DACB0 0000BFDF */  ld         $31, 0x0($29)
    /* DACB4 001DACB4 1000BD27 */  addiu      $29, $29, 0x10
    /* DACB8 001DACB8 0800E003 */  jr         $31
    /* DACBC 001DACBC 00000000 */   nop
.size func_001dac60, 0x60
