.section .text
.set noat
.set noreorder
glabel func_004bd658
    /* 3BD658 004BD658 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD65C 004BD65C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BD660 004BD660 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD664 004BD664 94C11308 */  j          func_004f0650
    /* 3BD668 004BD668 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD66C 004BD66C 00000000 */  nop
.size func_004bd658, 0x18
