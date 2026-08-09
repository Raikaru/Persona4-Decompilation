.section .text
.set noat
.set noreorder
glabel func_00517e70
    /* 417E70 00517E70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417E74 00517E74 00FF053C */  lui        $5, (0xFF000501 >> 16)
    /* 417E78 00517E78 0000BFFF */  sd         $31, 0x0($29)
    /* 417E7C 00517E7C 0105A534 */  ori        $5, $5, (0xFF000501 & 0xFFFF)
    /* 417E80 00517E80 0000BFDF */  ld         $31, 0x0($29)
    /* 417E84 00517E84 B45E1408 */  j          func_00517ad0
    /* 417E88 00517E88 1000BD27 */   addiu     $29, $29, 0x10
    /* 417E8C 00517E8C 00000000 */  nop
.size func_00517e70, 0x20
