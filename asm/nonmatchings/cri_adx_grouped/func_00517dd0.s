.section .text
.set noat
.set noreorder
glabel func_00517dd0
    /* 417DD0 00517DD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417DD4 00517DD4 01000624 */  addiu      $6, $0, 0x1
    /* 417DD8 00517DD8 0000BFFF */  sd         $31, 0x0($29)
    /* 417DDC 00517DDC 5056140C */  jal        func_00515940
    /* 417DE0 00517DE0 441F858C */   lw        $5, 0x1F44($4)
    /* 417DE4 00517DE4 2D100000 */  daddu      $2, $0, $0
    /* 417DE8 00517DE8 0000BFDF */  ld         $31, 0x0($29)
    /* 417DEC 00517DEC 0800E003 */  jr         $31
    /* 417DF0 00517DF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 417DF4 00517DF4 00000000 */  nop
.size func_00517dd0, 0x28
