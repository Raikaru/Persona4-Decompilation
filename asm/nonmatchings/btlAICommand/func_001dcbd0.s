.section .text
.set noat
.set noreorder
glabel func_001dcbd0
    /* DCBD0 001DCBD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCBD4 001DCBD4 0000BFFF */  sd         $31, 0x0($29)
    /* DCBD8 001DCBD8 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCBDC 001DCBDC 2D380000 */  daddu      $7, $0, $0
    /* DCBE0 001DCBE0 2D400000 */  daddu      $8, $0, $0
    /* DCBE4 001DCBE4 1E00093C */  lui        $9, %hi(func_001da230)
    /* DCBE8 001DCBE8 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DCBEC 001DCBEC E86E070C */  jal        func_001dbba0
    /* DCBF0 001DCBF0 00000000 */   nop
    /* DCBF4 001DCBF4 0000BFDF */  ld         $31, 0x0($29)
    /* DCBF8 001DCBF8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCBFC 001DCBFC 0800E003 */  jr         $31
    /* DCC00 001DCC00 00000000 */   nop
    /* DCC04 001DCC04 00000000 */  nop
    /* DCC08 001DCC08 00000000 */  nop
    /* DCC0C 001DCC0C 00000000 */  nop
.size func_001dcbd0, 0x40
