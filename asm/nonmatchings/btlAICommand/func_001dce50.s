.section .text
.set noat
.set noreorder
glabel func_001dce50
    /* DCE50 001DCE50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCE54 001DCE54 0000BFFF */  sd         $31, 0x0($29)
    /* DCE58 001DCE58 2D300000 */  daddu      $6, $0, $0
    /* DCE5C 001DCE5C 01000724 */  addiu      $7, $0, 0x1
    /* DCE60 001DCE60 2D400000 */  daddu      $8, $0, $0
    /* DCE64 001DCE64 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DCE68 001DCE68 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DCE6C 001DCE6C E86E070C */  jal        func_001dbba0
    /* DCE70 001DCE70 00000000 */   nop
    /* DCE74 001DCE74 0000BFDF */  ld         $31, 0x0($29)
    /* DCE78 001DCE78 1000BD27 */  addiu      $29, $29, 0x10
    /* DCE7C 001DCE7C 0800E003 */  jr         $31
    /* DCE80 001DCE80 00000000 */   nop
    /* DCE84 001DCE84 00000000 */  nop
    /* DCE88 001DCE88 00000000 */  nop
    /* DCE8C 001DCE8C 00000000 */  nop
.size func_001dce50, 0x40
