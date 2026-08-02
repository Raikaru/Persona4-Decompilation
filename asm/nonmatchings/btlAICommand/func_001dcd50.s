.section .text
.set noat
.set noreorder
glabel func_001dcd50
    /* DCD50 001DCD50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCD54 001DCD54 0000BFFF */  sd         $31, 0x0($29)
    /* DCD58 001DCD58 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCD5C 001DCD5C 2D380000 */  daddu      $7, $0, $0
    /* DCD60 001DCD60 01000824 */  addiu      $8, $0, 0x1
    /* DCD64 001DCD64 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DCD68 001DCD68 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DCD6C 001DCD6C E86E070C */  jal        func_001dbba0
    /* DCD70 001DCD70 00000000 */   nop
    /* DCD74 001DCD74 0000BFDF */  ld         $31, 0x0($29)
    /* DCD78 001DCD78 1000BD27 */  addiu      $29, $29, 0x10
    /* DCD7C 001DCD7C 0800E003 */  jr         $31
    /* DCD80 001DCD80 00000000 */   nop
    /* DCD84 001DCD84 00000000 */  nop
    /* DCD88 001DCD88 00000000 */  nop
    /* DCD8C 001DCD8C 00000000 */  nop
.size func_001dcd50, 0x40
