.section .text
.set noat
.set noreorder
glabel func_00519d20
    /* 419D20 00519D20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 419D24 00519D24 00FF053C */  lui        $5, (0xFF000D0B >> 16)
    /* 419D28 00519D28 0000BFFF */  sd         $31, 0x0($29)
    /* 419D2C 00519D2C 0B0DA534 */  ori        $5, $5, (0xFF000D0B & 0xFFFF)
    /* 419D30 00519D30 0000BFDF */  ld         $31, 0x0($29)
    /* 419D34 00519D34 B45E1408 */  j          func_00517ad0
    /* 419D38 00519D38 1000BD27 */   addiu     $29, $29, 0x10
    /* 419D3C 00519D3C 00000000 */  nop
.size func_00519d20, 0x20
