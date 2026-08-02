.section .text
.set noat
.set noreorder
glabel func_001dcc50
    /* DCC50 001DCC50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCC54 001DCC54 0000BFFF */  sd         $31, 0x0($29)
    /* DCC58 001DCC58 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCC5C 001DCC5C 2D380000 */  daddu      $7, $0, $0
    /* DCC60 001DCC60 2D400000 */  daddu      $8, $0, $0
    /* DCC64 001DCC64 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DCC68 001DCC68 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DCC6C 001DCC6C E86E070C */  jal        func_001dbba0
    /* DCC70 001DCC70 00000000 */   nop
    /* DCC74 001DCC74 0000BFDF */  ld         $31, 0x0($29)
    /* DCC78 001DCC78 1000BD27 */  addiu      $29, $29, 0x10
    /* DCC7C 001DCC7C 0800E003 */  jr         $31
    /* DCC80 001DCC80 00000000 */   nop
    /* DCC84 001DCC84 00000000 */  nop
    /* DCC88 001DCC88 00000000 */  nop
    /* DCC8C 001DCC8C 00000000 */  nop
.size func_001dcc50, 0x40
