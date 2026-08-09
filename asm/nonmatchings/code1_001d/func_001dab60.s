.section .text
.set noat
.set noreorder
glabel func_001dab60
    /* DAB60 001DAB60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DAB64 001DAB64 0000BFFF */  sd         $31, 0x0($29)
    /* DAB68 001DAB68 3000828C */  lw         $2, 0x30($4)
    /* DAB6C 001DAB6C A2004390 */  lbu        $3, 0xA2($2)
    /* DAB70 001DAB70 01000224 */  addiu      $2, $0, 0x1
    /* DAB74 001DAB74 04106200 */  sllv       $2, $2, $3
    /* DAB78 001DAB78 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DAB7C 001DAB7C 1800073C */  lui        $7, (0x180000 >> 16)
    /* DAB80 001DAB80 2D400000 */  daddu      $8, $0, $0
    /* DAB84 001DAB84 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DAB88 001DAB88 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DAB8C 001DAB8C 3465070C */  jal        func_001d94d0
    /* DAB90 001DAB90 00000000 */   nop
    /* DAB94 001DAB94 0000BFDF */  ld         $31, 0x0($29)
    /* DAB98 001DAB98 1000BD27 */  addiu      $29, $29, 0x10
    /* DAB9C 001DAB9C 0800E003 */  jr         $31
    /* DABA0 001DABA0 00000000 */   nop
    /* DABA4 001DABA4 00000000 */  nop
    /* DABA8 001DABA8 00000000 */  nop
    /* DABAC 001DABAC 00000000 */  nop
.size func_001dab60, 0x50
