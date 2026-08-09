.section .text
.set noat
.set noreorder
glabel func_0021ae80
    /* 11AE80 0021AE80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 11AE84 0021AE84 0000BFFF */  sd         $31, 0x0($29)
    /* 11AE88 0021AE88 3C0A8424 */  addiu      $4, $4, 0xA3C
    /* 11AE8C 0021AE8C C46C080C */  jal        func_0021b310
    /* 11AE90 0021AE90 00000000 */   nop
    /* 11AE94 0021AE94 0000BFDF */  ld         $31, 0x0($29)
    /* 11AE98 0021AE98 1000BD27 */  addiu      $29, $29, 0x10
    /* 11AE9C 0021AE9C 0800E003 */  jr         $31
    /* 11AEA0 0021AEA0 00000000 */   nop
    /* 11AEA4 0021AEA4 00000000 */  nop
    /* 11AEA8 0021AEA8 00000000 */  nop
    /* 11AEAC 0021AEAC 00000000 */  nop
.size func_0021ae80, 0x30
