.section .text
.set noat
.set noreorder
glabel func_004cd738
    /* 3CD738 004CD738 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD73C 004CD73C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD740 004CD740 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD744 004CD744 C2B21308 */  j          func_004ecb08
    /* 3CD748 004CD748 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD74C 004CD74C 00000000 */  nop
.size func_004cd738, 0x18
