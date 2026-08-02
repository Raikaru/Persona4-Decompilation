.section .text
.set noat
.set noreorder
glabel func_001dccd0
    /* DCCD0 001DCCD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCCD4 001DCCD4 0000BFFF */  sd         $31, 0x0($29)
    /* DCCD8 001DCCD8 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCCDC 001DCCDC 2D380000 */  daddu      $7, $0, $0
    /* DCCE0 001DCCE0 01000824 */  addiu      $8, $0, 0x1
    /* DCCE4 001DCCE4 1E00093C */  lui        $9, %hi(func_001da230)
    /* DCCE8 001DCCE8 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DCCEC 001DCCEC E86E070C */  jal        func_001dbba0
    /* DCCF0 001DCCF0 00000000 */   nop
    /* DCCF4 001DCCF4 0000BFDF */  ld         $31, 0x0($29)
    /* DCCF8 001DCCF8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCCFC 001DCCFC 0800E003 */  jr         $31
    /* DCD00 001DCD00 00000000 */   nop
    /* DCD04 001DCD04 00000000 */  nop
    /* DCD08 001DCD08 00000000 */  nop
    /* DCD0C 001DCD0C 00000000 */  nop
.size func_001dccd0, 0x40
