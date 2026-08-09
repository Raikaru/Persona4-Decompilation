.section .text
.set noat
.set noreorder
glabel func_00517e48
    /* 417E48 00517E48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417E4C 00517E4C 2D10A000 */  daddu      $2, $5, $0
    /* 417E50 00517E50 0000BFFF */  sd         $31, 0x0($29)
    /* 417E54 00517E54 2D38C000 */  daddu      $7, $6, $0
    /* 417E58 00517E58 2D304000 */  daddu      $6, $2, $0
    /* 417E5C 00517E5C 441F858C */  lw         $5, 0x1F44($4)
    /* 417E60 00517E60 0000BFDF */  ld         $31, 0x0($29)
    /* 417E64 00517E64 5A531408 */  j          func_00514d68
    /* 417E68 00517E68 1000BD27 */   addiu     $29, $29, 0x10
    /* 417E6C 00517E6C 00000000 */  nop
.size func_00517e48, 0x28
