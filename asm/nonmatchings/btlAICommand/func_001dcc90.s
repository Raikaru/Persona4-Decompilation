.section .text
.set noat
.set noreorder
glabel func_001dcc90
    /* DCC90 001DCC90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCC94 001DCC94 0000BFFF */  sd         $31, 0x0($29)
    /* DCC98 001DCC98 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCC9C 001DCC9C 2D380000 */  daddu      $7, $0, $0
    /* DCCA0 001DCCA0 2D400000 */  daddu      $8, $0, $0
    /* DCCA4 001DCCA4 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DCCA8 001DCCA8 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DCCAC 001DCCAC E86E070C */  jal        func_001dbba0
    /* DCCB0 001DCCB0 00000000 */   nop
    /* DCCB4 001DCCB4 0000BFDF */  ld         $31, 0x0($29)
    /* DCCB8 001DCCB8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCCBC 001DCCBC 0800E003 */  jr         $31
    /* DCCC0 001DCCC0 00000000 */   nop
    /* DCCC4 001DCCC4 00000000 */  nop
    /* DCCC8 001DCCC8 00000000 */  nop
    /* DCCCC 001DCCCC 00000000 */  nop
.size func_001dcc90, 0x40
