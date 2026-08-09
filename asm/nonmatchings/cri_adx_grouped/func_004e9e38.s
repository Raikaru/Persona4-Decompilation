.section .text
.set noat
.set noreorder
glabel func_004e9e38
    /* 3E9E38 004E9E38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E9E3C 004E9E3C 0000BFFF */  sd         $31, 0x0($29)
    /* 3E9E40 004E9E40 0000BFDF */  ld         $31, 0x0($29)
    /* 3E9E44 004E9E44 88C11308 */  j          func_004f0620
    /* 3E9E48 004E9E48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E9E4C 004E9E4C 00000000 */  nop
.size func_004e9e38, 0x18
