.section .text
.set noat
.set noreorder
glabel func_00511da0
    /* 411DA0 00511DA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411DA4 00511DA4 0000BFFF */  sd         $31, 0x0($29)
    /* 411DA8 00511DA8 F42C140C */  jal        func_0050b3d0
    /* 411DAC 00511DAC 00000000 */   nop
    /* 411DB0 00511DB0 5800428C */  lw         $2, 0x58($2)
    /* 411DB4 00511DB4 0000BFDF */  ld         $31, 0x0($29)
    /* 411DB8 00511DB8 0800E003 */  jr         $31
    /* 411DBC 00511DBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511da0, 0x20
