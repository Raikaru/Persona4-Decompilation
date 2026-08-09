.section .text
.set noat
.set noreorder
glabel func_00517aa0
    /* 417AA0 00517AA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417AA4 00517AA4 0000BFFF */  sd         $31, 0x0($29)
    /* 417AA8 00517AA8 0000BFDF */  ld         $31, 0x0($29)
    /* 417AAC 00517AAC AE5E1408 */  j          func_00517ab8
    /* 417AB0 00517AB0 1000BD27 */   addiu     $29, $29, 0x10
    /* 417AB4 00517AB4 00000000 */  nop
.size func_00517aa0, 0x18
