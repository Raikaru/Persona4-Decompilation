.section .text
.set noat
.set noreorder
glabel func_004f8728
    /* 3F8728 004F8728 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F872C 004F872C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8730 004F8730 0000BFDF */  ld         $31, 0x0($29)
    /* 3F8734 004F8734 52C91308 */  j          func_004f2548
    /* 3F8738 004F8738 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F873C 004F873C 00000000 */  nop
.size func_004f8728, 0x18
