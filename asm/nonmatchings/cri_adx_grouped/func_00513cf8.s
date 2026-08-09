.section .text
.set noat
.set noreorder
glabel func_00513cf8
    /* 413CF8 00513CF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413CFC 00513CFC 00FF053C */  lui        $5, (0xFF000C03 >> 16)
    /* 413D00 00513D00 0000BFFF */  sd         $31, 0x0($29)
    /* 413D04 00513D04 030CA534 */  ori        $5, $5, (0xFF000C03 & 0xFFFF)
    /* 413D08 00513D08 0000BFDF */  ld         $31, 0x0($29)
    /* 413D0C 00513D0C B45E1408 */  j          func_00517ad0
    /* 413D10 00513D10 1000BD27 */   addiu     $29, $29, 0x10
    /* 413D14 00513D14 00000000 */  nop
.size func_00513cf8, 0x20
