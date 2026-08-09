.section .text
.set noat
.set noreorder
glabel func_005112e8
    /* 4112E8 005112E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4112EC 005112EC 0000BFFF */  sd         $31, 0x0($29)
    /* 4112F0 005112F0 0000BFDF */  ld         $31, 0x0($29)
    /* 4112F4 005112F4 F8C11308 */  j          func_004f07e0
    /* 4112F8 005112F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4112FC 005112FC 00000000 */  nop
.size func_005112e8, 0x18
