.section .text
.set noat
.set noreorder
glabel func_001dce10
    /* DCE10 001DCE10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCE14 001DCE14 0000BFFF */  sd         $31, 0x0($29)
    /* DCE18 001DCE18 2D300000 */  daddu      $6, $0, $0
    /* DCE1C 001DCE1C 01000724 */  addiu      $7, $0, 0x1
    /* DCE20 001DCE20 2D400000 */  daddu      $8, $0, $0
    /* DCE24 001DCE24 1E00093C */  lui        $9, %hi(func_001da270)
    /* DCE28 001DCE28 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DCE2C 001DCE2C E86E070C */  jal        func_001dbba0
    /* DCE30 001DCE30 00000000 */   nop
    /* DCE34 001DCE34 0000BFDF */  ld         $31, 0x0($29)
    /* DCE38 001DCE38 1000BD27 */  addiu      $29, $29, 0x10
    /* DCE3C 001DCE3C 0800E003 */  jr         $31
    /* DCE40 001DCE40 00000000 */   nop
    /* DCE44 001DCE44 00000000 */  nop
    /* DCE48 001DCE48 00000000 */  nop
    /* DCE4C 001DCE4C 00000000 */  nop
.size func_001dce10, 0x40
