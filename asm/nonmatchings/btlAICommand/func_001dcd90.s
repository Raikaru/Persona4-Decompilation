.section .text
.set noat
.set noreorder
glabel func_001dcd90
    /* DCD90 001DCD90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCD94 001DCD94 0000BFFF */  sd         $31, 0x0($29)
    /* DCD98 001DCD98 1000063C */  lui        $6, (0x100000 >> 16)
    /* DCD9C 001DCD9C 2D380000 */  daddu      $7, $0, $0
    /* DCDA0 001DCDA0 01000824 */  addiu      $8, $0, 0x1
    /* DCDA4 001DCDA4 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DCDA8 001DCDA8 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DCDAC 001DCDAC E86E070C */  jal        func_001dbba0
    /* DCDB0 001DCDB0 00000000 */   nop
    /* DCDB4 001DCDB4 0000BFDF */  ld         $31, 0x0($29)
    /* DCDB8 001DCDB8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCDBC 001DCDBC 0800E003 */  jr         $31
    /* DCDC0 001DCDC0 00000000 */   nop
    /* DCDC4 001DCDC4 00000000 */  nop
    /* DCDC8 001DCDC8 00000000 */  nop
    /* DCDCC 001DCDCC 00000000 */  nop
.size func_001dcd90, 0x40
