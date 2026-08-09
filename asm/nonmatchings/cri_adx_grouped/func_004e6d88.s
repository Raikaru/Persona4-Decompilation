.section .text
.set noat
.set noreorder
glabel func_004e6d88
    /* 3E6D88 004E6D88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E6D8C 004E6D8C 7300043C */  lui        $4, %hi(D_00733DB0)
    /* 3E6D90 004E6D90 0000BFFF */  sd         $31, 0x0($29)
    /* 3E6D94 004E6D94 2D280000 */  daddu      $5, $0, $0
    /* 3E6D98 004E6D98 B03D8424 */  addiu      $4, $4, %lo(D_00733DB0)
    /* 3E6D9C 004E6D9C 10000624 */  addiu      $6, $0, 0x10
    /* 3E6DA0 004E6DA0 0000BFDF */  ld         $31, 0x0($29)
    /* 3E6DA4 004E6DA4 72FE1008 */  j          func_0043f9c8
    /* 3E6DA8 004E6DA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E6DAC 004E6DAC 00000000 */  nop
.size func_004e6d88, 0x28
