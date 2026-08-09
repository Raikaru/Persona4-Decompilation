.section .text
.set noat
.set noreorder
glabel func_004f8698
    /* 3F8698 004F8698 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F869C 004F869C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F86A0 004F86A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F86A4 004F86A4 92C91308 */  j          func_004f2648
    /* 3F86A8 004F86A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F86AC 004F86AC 00000000 */  nop
.size func_004f8698, 0x18
