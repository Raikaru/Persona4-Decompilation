.section .text
.set noat
.set noreorder
glabel func_0026e6d0
    /* 16E6D0 0026E6D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 16E6D4 0026E6D4 0000BFFF */  sd         $31, 0x0($29)
    /* 16E6D8 0026E6D8 A8D1090C */  jal        func_002746a0
    /* 16E6DC 0026E6DC 00000000 */   nop
    /* 16E6E0 0026E6E0 2D100000 */  daddu      $2, $0, $0
    /* 16E6E4 0026E6E4 0000BFDF */  ld         $31, 0x0($29)
    /* 16E6E8 0026E6E8 1000BD27 */  addiu      $29, $29, 0x10
    /* 16E6EC 0026E6EC 0800E003 */  jr         $31
    /* 16E6F0 0026E6F0 00000000 */   nop
    /* 16E6F4 0026E6F4 00000000 */  nop
    /* 16E6F8 0026E6F8 00000000 */  nop
    /* 16E6FC 0026E6FC 00000000 */  nop
.size func_0026e6d0, 0x30
