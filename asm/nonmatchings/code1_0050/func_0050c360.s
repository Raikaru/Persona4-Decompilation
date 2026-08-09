.section .text
.set noat
.set noreorder
glabel func_0050c360
    /* 40C360 0050C360 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C364 0050C364 0000BFFF */  sd         $31, 0x0($29)
    /* 40C368 0050C368 0000BFDF */  ld         $31, 0x0($29)
    /* 40C36C 0050C36C DE301408 */  j          func_0050c378
    /* 40C370 0050C370 1000BD27 */   addiu     $29, $29, 0x10
    /* 40C374 0050C374 00000000 */  nop
.size func_0050c360, 0x18
