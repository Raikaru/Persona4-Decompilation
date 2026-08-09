.section .text
.set noat
.set noreorder
glabel func_00513cb8
    /* 413CB8 00513CB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413CBC 00513CBC 00FF053C */  lui        $5, (0xFF000C03 >> 16)
    /* 413CC0 00513CC0 0000BFFF */  sd         $31, 0x0($29)
    /* 413CC4 00513CC4 030CA534 */  ori        $5, $5, (0xFF000C03 & 0xFFFF)
    /* 413CC8 00513CC8 0000BFDF */  ld         $31, 0x0($29)
    /* 413CCC 00513CCC B45E1408 */  j          func_00517ad0
    /* 413CD0 00513CD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 413CD4 00513CD4 00000000 */  nop
.size func_00513cb8, 0x20
