.section .text
.set noat
.set noreorder
glabel func_00519c88
    /* 419C88 00519C88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 419C8C 00519C8C 0000BFFF */  sd         $31, 0x0($29)
    /* 419C90 00519C90 0000BFDF */  ld         $31, 0x0($29)
    /* 419C94 00519C94 020F1408 */  j          func_00503c08
    /* 419C98 00519C98 1000BD27 */   addiu     $29, $29, 0x10
    /* 419C9C 00519C9C 00000000 */  nop
.size func_00519c88, 0x18
