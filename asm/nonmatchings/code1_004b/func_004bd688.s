.section .text
.set noat
.set noreorder
glabel func_004bd688
    /* 3BD688 004BD688 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD68C 004BD68C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BD690 004BD690 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD694 004BD694 9EC41308 */  j          func_004f1278
    /* 3BD698 004BD698 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD69C 004BD69C 00000000 */  nop
.size func_004bd688, 0x18
