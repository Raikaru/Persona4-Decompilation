.section .text
.set noat
.set noreorder
glabel func_001dcd10
    /* DCD10 001DCD10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCD14 001DCD14 0000BFFF */  sd         $31, 0x0($29)
    /* DCD18 001DCD18 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCD1C 001DCD1C 2D380000 */  daddu      $7, $0, $0
    /* DCD20 001DCD20 01000824 */  addiu      $8, $0, 0x1
    /* DCD24 001DCD24 1E00093C */  lui        $9, %hi(func_001da270)
    /* DCD28 001DCD28 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DCD2C 001DCD2C E86E070C */  jal        func_001dbba0
    /* DCD30 001DCD30 00000000 */   nop
    /* DCD34 001DCD34 0000BFDF */  ld         $31, 0x0($29)
    /* DCD38 001DCD38 1000BD27 */  addiu      $29, $29, 0x10
    /* DCD3C 001DCD3C 0800E003 */  jr         $31
    /* DCD40 001DCD40 00000000 */   nop
    /* DCD44 001DCD44 00000000 */  nop
    /* DCD48 001DCD48 00000000 */  nop
    /* DCD4C 001DCD4C 00000000 */  nop
.size func_001dcd10, 0x40
