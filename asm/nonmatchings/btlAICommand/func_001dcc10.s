.section .text
.set noat
.set noreorder
glabel func_001dcc10
    /* DCC10 001DCC10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCC14 001DCC14 0000BFFF */  sd         $31, 0x0($29)
    /* DCC18 001DCC18 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCC1C 001DCC1C 2D380000 */  daddu      $7, $0, $0
    /* DCC20 001DCC20 2D400000 */  daddu      $8, $0, $0
    /* DCC24 001DCC24 1E00093C */  lui        $9, %hi(func_001da270)
    /* DCC28 001DCC28 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DCC2C 001DCC2C E86E070C */  jal        func_001dbba0
    /* DCC30 001DCC30 00000000 */   nop
    /* DCC34 001DCC34 0000BFDF */  ld         $31, 0x0($29)
    /* DCC38 001DCC38 1000BD27 */  addiu      $29, $29, 0x10
    /* DCC3C 001DCC3C 0800E003 */  jr         $31
    /* DCC40 001DCC40 00000000 */   nop
    /* DCC44 001DCC44 00000000 */  nop
    /* DCC48 001DCC48 00000000 */  nop
    /* DCC4C 001DCC4C 00000000 */  nop
.size func_001dcc10, 0x40
