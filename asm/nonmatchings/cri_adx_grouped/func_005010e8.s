.section .text
.set noat
.set noreorder
glabel func_005010e8
    /* 4010E8 005010E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4010EC 005010EC 0000BFFF */  sd         $31, 0x0($29)
    /* 4010F0 005010F0 0000BFDF */  ld         $31, 0x0($29)
    /* 4010F4 005010F4 04FE1008 */  j          func_0043f810
    /* 4010F8 005010F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4010FC 005010FC 00000000 */  nop
.size func_005010e8, 0x18
