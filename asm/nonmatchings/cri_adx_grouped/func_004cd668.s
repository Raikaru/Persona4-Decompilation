.section .text
.set noat
.set noreorder
glabel func_004cd668
    /* 3CD668 004CD668 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD66C 004CD66C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD670 004CD670 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD674 004CD674 CAB01308 */  j          func_004ec328
    /* 3CD678 004CD678 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD67C 004CD67C 00000000 */  nop
.size func_004cd668, 0x18
