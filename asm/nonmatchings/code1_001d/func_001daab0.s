.section .text
.set noat
.set noreorder
glabel func_001daab0
    /* DAAB0 001DAAB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DAAB4 001DAAB4 0000BFFF */  sd         $31, 0x0($29)
    /* DAAB8 001DAAB8 3000828C */  lw         $2, 0x30($4)
    /* DAABC 001DAABC A2004390 */  lbu        $3, 0xA2($2)
    /* DAAC0 001DAAC0 01000224 */  addiu      $2, $0, 0x1
    /* DAAC4 001DAAC4 04106200 */  sllv       $2, $2, $3
    /* DAAC8 001DAAC8 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DAACC 001DAACC 1800073C */  lui        $7, (0x180000 >> 16)
    /* DAAD0 001DAAD0 2D400000 */  daddu      $8, $0, $0
    /* DAAD4 001DAAD4 1E00093C */  lui        $9, %hi(func_001da270)
    /* DAAD8 001DAAD8 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DAADC 001DAADC 3465070C */  jal        func_001d94d0
    /* DAAE0 001DAAE0 00000000 */   nop
    /* DAAE4 001DAAE4 0000BFDF */  ld         $31, 0x0($29)
    /* DAAE8 001DAAE8 1000BD27 */  addiu      $29, $29, 0x10
    /* DAAEC 001DAAEC 0800E003 */  jr         $31
    /* DAAF0 001DAAF0 00000000 */   nop
    /* DAAF4 001DAAF4 00000000 */  nop
    /* DAAF8 001DAAF8 00000000 */  nop
    /* DAAFC 001DAAFC 00000000 */  nop
.size func_001daab0, 0x50
