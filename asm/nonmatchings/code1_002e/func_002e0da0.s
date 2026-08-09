.section .text
.set noat
.set noreorder
glabel func_002e0da0
    /* 1E0DA0 002E0DA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E0DA4 002E0DA4 0000BFFF */  sd         $31, 0x0($29)
    /* 1E0DA8 002E0DA8 8C840B0C */  jal        func_002e1230
    /* 1E0DAC 002E0DAC 00000000 */   nop
    /* 1E0DB0 002E0DB0 2B100200 */  sltu       $2, $0, $2
    /* 1E0DB4 002E0DB4 3C140200 */  dsll32     $2, $2, 16
    /* 1E0DB8 002E0DB8 3F140200 */  dsra32     $2, $2, 16
    /* 1E0DBC 002E0DBC 0000BFDF */  ld         $31, 0x0($29)
    /* 1E0DC0 002E0DC0 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E0DC4 002E0DC4 0800E003 */  jr         $31
    /* 1E0DC8 002E0DC8 00000000 */   nop
    /* 1E0DCC 002E0DCC 00000000 */  nop
.size func_002e0da0, 0x30
