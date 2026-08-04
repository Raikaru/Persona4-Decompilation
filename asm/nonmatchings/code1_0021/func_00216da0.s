.section .text
.set noat
.set noreorder
glabel func_00216da0
    /* 116DA0 00216DA0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 116DA4 00216DA4 1000BFFF */  sd         $31, 0x10($29)
    /* 116DA8 00216DA8 0000B07F */  sq         $16, 0x0($29)
    /* 116DAC 00216DAC 2D808000 */  daddu      $16, $4, $0
    /* 116DB0 00216DB0 2D30A000 */  daddu      $6, $5, $0
    /* 116DB4 00216DB4 2000A427 */  addiu      $4, $29, 0x20
    /* 116DB8 00216DB8 98A58527 */  addiu      $5, $28, -0x5A68
    /* 116DBC 00216DBC 2208110C */  jal        func_00442088
    /* 116DC0 00216DC0 00000000 */   nop
    /* 116DC4 00216DC4 2D200002 */  daddu      $4, $16, $0
    /* 116DC8 00216DC8 01000524 */  addiu      $5, $0, 0x1
    /* 116DCC 00216DCC 2000A627 */  addiu      $6, $29, 0x20
    /* 116DD0 00216DD0 14E1090C */  jal        func_00278450
    /* 116DD4 00216DD4 00000000 */   nop
    /* 116DD8 00216DD8 1000BFDF */  ld         $31, 0x10($29)
    /* 116DDC 00216DDC 0000B07B */  lq         $16, 0x0($29)
    /* 116DE0 00216DE0 A000BD27 */  addiu      $29, $29, 0xA0
    /* 116DE4 00216DE4 0800E003 */  jr         $31
    /* 116DE8 00216DE8 00000000 */   nop
    /* 116DEC 00216DEC 00000000 */  nop
.size func_00216da0, 0x50
