.section .text
.set noat
.set noreorder
glabel func_001fce30
    /* FCE30 001FCE30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FCE34 001FCE34 0000BFFF */  sd         $31, 0x0($29)
    /* FCE38 001FCE38 6200043C */  lui        $4, %hi(D_00625230)
    /* FCE3C 001FCE3C 30528424 */  addiu      $4, $4, %lo(D_00625230)
    /* FCE40 001FCE40 D3010524 */  addiu      $5, $0, 0x1D3
    /* FCE44 001FCE44 A43A110C */  jal        func_0044ea90
    /* FCE48 001FCE48 00000000 */   nop
    /* FCE4C 001FCE4C 20000424 */  addiu      $4, $0, 0x20
    /* FCE50 001FCE50 0400053C */  lui        $5, (0x40000 >> 16)
    /* FCE54 001FCE54 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* FCE58 001FCE58 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* FCE5C 001FCE5C 09F84000 */  jalr       $2
    /* FCE60 001FCE60 00000000 */   nop
    /* FCE64 001FCE64 0000BFDF */  ld         $31, 0x0($29)
    /* FCE68 001FCE68 1000BD27 */  addiu      $29, $29, 0x10
    /* FCE6C 001FCE6C 0800E003 */  jr         $31
    /* FCE70 001FCE70 00000000 */   nop
    /* FCE74 001FCE74 00000000 */  nop
    /* FCE78 001FCE78 00000000 */  nop
    /* FCE7C 001FCE7C 00000000 */  nop
.size func_001fce30, 0x50
