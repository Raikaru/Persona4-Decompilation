.section .text
.set noat
.set noreorder
glabel func_004cd768
    /* 3CD768 004CD768 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD76C 004CD76C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD770 004CD770 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD774 004CD774 EAB21308 */  j          func_004ecba8
    /* 3CD778 004CD778 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD77C 004CD77C 00000000 */  nop
.size func_004cd768, 0x18
