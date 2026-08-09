.section .text
.set noat
.set noreorder
glabel func_005261f0
    /* 4261F0 005261F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4261F4 005261F4 0000BFFF */  sd         $31, 0x0($29)
    /* 4261F8 005261F8 0000BFDF */  ld         $31, 0x0($29)
    /* 4261FC 005261FC 52EC1308 */  j          func_004fb148
    /* 426200 00526200 1000BD27 */   addiu     $29, $29, 0x10
    /* 426204 00526204 00000000 */  nop
.size func_005261f0, 0x18
