.section .text
.set noat
.set noreorder
glabel func_004ca668
    /* 3CA668 004CA668 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA66C 004CA66C 2D20A000 */  daddu      $4, $5, $0
    /* 3CA670 004CA670 0000BFFF */  sd         $31, 0x0($29)
    /* 3CA674 004CA674 0000BFDF */  ld         $31, 0x0($29)
    /* 3CA678 004CA678 A61A1308 */  j          func_004c6a98
    /* 3CA67C 004CA67C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca668, 0x18
