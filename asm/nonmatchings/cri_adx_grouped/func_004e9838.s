.section .text
.set noat
.set noreorder
glabel func_004e9838
    /* 3E9838 004E9838 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E983C 004E983C 0000BFFF */  sd         $31, 0x0($29)
    /* 3E9840 004E9840 0000BFDF */  ld         $31, 0x0($29)
    /* 3E9844 004E9844 1AB51308 */  j          func_004ed468
    /* 3E9848 004E9848 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E984C 004E984C 00000000 */  nop
.size func_004e9838, 0x18
