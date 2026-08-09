.section .text
.set noat
.set noreorder
glabel func_004bd670
    /* 3BD670 004BD670 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD674 004BD674 0000BFFF */  sd         $31, 0x0($29)
    /* 3BD678 004BD678 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD67C 004BD67C B2C11308 */  j          func_004f06c8
    /* 3BD680 004BD680 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD684 004BD684 00000000 */  nop
.size func_004bd670, 0x18
