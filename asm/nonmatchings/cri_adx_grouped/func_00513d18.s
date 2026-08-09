.section .text
.set noat
.set noreorder
glabel func_00513d18
    /* 413D18 00513D18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413D1C 00513D1C 00FF053C */  lui        $5, (0xFF000C03 >> 16)
    /* 413D20 00513D20 0000BFFF */  sd         $31, 0x0($29)
    /* 413D24 00513D24 030CA534 */  ori        $5, $5, (0xFF000C03 & 0xFFFF)
    /* 413D28 00513D28 0000BFDF */  ld         $31, 0x0($29)
    /* 413D2C 00513D2C B45E1408 */  j          func_00517ad0
    /* 413D30 00513D30 1000BD27 */   addiu     $29, $29, 0x10
    /* 413D34 00513D34 00000000 */  nop
.size func_00513d18, 0x20
