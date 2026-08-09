.section .text
.set noat
.set noreorder
glabel func_004cccd0
    /* 3CCCD0 004CCCD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCCD4 004CCCD4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCCD8 004CCCD8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCCDC 004CCCDC 26331308 */  j          func_004ccc98
    /* 3CCCE0 004CCCE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCCE4 004CCCE4 00000000 */  nop
.size func_004cccd0, 0x18
