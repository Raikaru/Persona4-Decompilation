.section .text
.set noat
.set noreorder
glabel func_00517e90
    /* 417E90 00517E90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417E94 00517E94 00FF053C */  lui        $5, (0xFF000501 >> 16)
    /* 417E98 00517E98 0000BFFF */  sd         $31, 0x0($29)
    /* 417E9C 00517E9C 0105A534 */  ori        $5, $5, (0xFF000501 & 0xFFFF)
    /* 417EA0 00517EA0 0000BFDF */  ld         $31, 0x0($29)
    /* 417EA4 00517EA4 B45E1408 */  j          func_00517ad0
    /* 417EA8 00517EA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 417EAC 00517EAC 00000000 */  nop
.size func_00517e90, 0x20
