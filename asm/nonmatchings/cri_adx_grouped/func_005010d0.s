.section .text
.set noat
.set noreorder
glabel func_005010d0
    /* 4010D0 005010D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4010D4 005010D4 0000BFFF */  sd         $31, 0x0($29)
    /* 4010D8 005010D8 0000BFDF */  ld         $31, 0x0($29)
    /* 4010DC 005010DC 04FE1008 */  j          func_0043f810
    /* 4010E0 005010E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4010E4 005010E4 00000000 */  nop
.size func_005010d0, 0x18
