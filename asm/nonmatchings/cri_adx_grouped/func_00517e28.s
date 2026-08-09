.section .text
.set noat
.set noreorder
glabel func_00517e28
    /* 417E28 00517E28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417E2C 00517E2C 2D30A000 */  daddu      $6, $5, $0
    /* 417E30 00517E30 0000BFFF */  sd         $31, 0x0($29)
    /* 417E34 00517E34 441F858C */  lw         $5, 0x1F44($4)
    /* 417E38 00517E38 0000BFDF */  ld         $31, 0x0($29)
    /* 417E3C 00517E3C 24531408 */  j          func_00514c90
    /* 417E40 00517E40 1000BD27 */   addiu     $29, $29, 0x10
    /* 417E44 00517E44 00000000 */  nop
.size func_00517e28, 0x20
