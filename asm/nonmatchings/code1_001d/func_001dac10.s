.section .text
.set noat
.set noreorder
glabel func_001dac10
    /* DAC10 001DAC10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DAC14 001DAC14 0000BFFF */  sd         $31, 0x0($29)
    /* DAC18 001DAC18 3000828C */  lw         $2, 0x30($4)
    /* DAC1C 001DAC1C A2004390 */  lbu        $3, 0xA2($2)
    /* DAC20 001DAC20 01000224 */  addiu      $2, $0, 0x1
    /* DAC24 001DAC24 04106200 */  sllv       $2, $2, $3
    /* DAC28 001DAC28 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DAC2C 001DAC2C 1800073C */  lui        $7, (0x180000 >> 16)
    /* DAC30 001DAC30 2D400000 */  daddu      $8, $0, $0
    /* DAC34 001DAC34 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DAC38 001DAC38 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DAC3C 001DAC3C 3465070C */  jal        func_001d94d0
    /* DAC40 001DAC40 00000000 */   nop
    /* DAC44 001DAC44 0000BFDF */  ld         $31, 0x0($29)
    /* DAC48 001DAC48 1000BD27 */  addiu      $29, $29, 0x10
    /* DAC4C 001DAC4C 0800E003 */  jr         $31
    /* DAC50 001DAC50 00000000 */   nop
    /* DAC54 001DAC54 00000000 */  nop
    /* DAC58 001DAC58 00000000 */  nop
    /* DAC5C 001DAC5C 00000000 */  nop
.size func_001dac10, 0x50
