.section .text
.set noat
.set noreorder
glabel func_005122a0
    /* 4122A0 005122A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4122A4 005122A4 0000BFFF */  sd         $31, 0x0($29)
    /* 4122A8 005122A8 0000BFDF */  ld         $31, 0x0($29)
    /* 4122AC 005122AC FE471308 */  j          func_004d1ff8
    /* 4122B0 005122B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4122B4 005122B4 00000000 */  nop
.size func_005122a0, 0x18
