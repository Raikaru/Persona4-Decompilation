.section .text
.set noat
.set noreorder
glabel func_001daa00
    /* DAA00 001DAA00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DAA04 001DAA04 0000BFFF */  sd         $31, 0x0($29)
    /* DAA08 001DAA08 3000828C */  lw         $2, 0x30($4)
    /* DAA0C 001DAA0C A2004390 */  lbu        $3, 0xA2($2)
    /* DAA10 001DAA10 01000224 */  addiu      $2, $0, 0x1
    /* DAA14 001DAA14 04106200 */  sllv       $2, $2, $3
    /* DAA18 001DAA18 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DAA1C 001DAA1C 1800073C */  lui        $7, (0x180000 >> 16)
    /* DAA20 001DAA20 2D400000 */  daddu      $8, $0, $0
    /* DAA24 001DAA24 1E00093C */  lui        $9, %hi(func_001da230)
    /* DAA28 001DAA28 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DAA2C 001DAA2C 3465070C */  jal        func_001d94d0
    /* DAA30 001DAA30 00000000 */   nop
    /* DAA34 001DAA34 0000BFDF */  ld         $31, 0x0($29)
    /* DAA38 001DAA38 1000BD27 */  addiu      $29, $29, 0x10
    /* DAA3C 001DAA3C 0800E003 */  jr         $31
    /* DAA40 001DAA40 00000000 */   nop
    /* DAA44 001DAA44 00000000 */  nop
    /* DAA48 001DAA48 00000000 */  nop
    /* DAA4C 001DAA4C 00000000 */  nop
.size func_001daa00, 0x50
