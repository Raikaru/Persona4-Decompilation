.section .text
.set noat
.set noreorder
glabel func_0052a438
    /* 42A438 0052A438 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42A43C 0052A43C 0000BFFF */  sd         $31, 0x0($29)
    /* 42A440 0052A440 0000BFDF */  ld         $31, 0x0($29)
    /* 42A444 0052A444 14A91408 */  j          func_0052a450
    /* 42A448 0052A448 1000BD27 */   addiu     $29, $29, 0x10
    /* 42A44C 0052A44C 00000000 */  nop
.size func_0052a438, 0x18
