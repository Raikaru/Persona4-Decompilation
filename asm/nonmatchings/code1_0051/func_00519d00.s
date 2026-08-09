.section .text
.set noat
.set noreorder
glabel func_00519d00
    /* 419D00 00519D00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 419D04 00519D04 00FF053C */  lui        $5, (0xFF000D0B >> 16)
    /* 419D08 00519D08 0000BFFF */  sd         $31, 0x0($29)
    /* 419D0C 00519D0C 0B0DA534 */  ori        $5, $5, (0xFF000D0B & 0xFFFF)
    /* 419D10 00519D10 0000BFDF */  ld         $31, 0x0($29)
    /* 419D14 00519D14 B45E1408 */  j          func_00517ad0
    /* 419D18 00519D18 1000BD27 */   addiu     $29, $29, 0x10
    /* 419D1C 00519D1C 00000000 */  nop
.size func_00519d00, 0x20
