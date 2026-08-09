.section .text
.set noat
.set noreorder
glabel func_00519cc0
    /* 419CC0 00519CC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 419CC4 00519CC4 00FF053C */  lui        $5, (0xFF000D0B >> 16)
    /* 419CC8 00519CC8 0000BFFF */  sd         $31, 0x0($29)
    /* 419CCC 00519CCC 0B0DA534 */  ori        $5, $5, (0xFF000D0B & 0xFFFF)
    /* 419CD0 00519CD0 0000BFDF */  ld         $31, 0x0($29)
    /* 419CD4 00519CD4 B45E1408 */  j          func_00517ad0
    /* 419CD8 00519CD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 419CDC 00519CDC 00000000 */  nop
.size func_00519cc0, 0x20
