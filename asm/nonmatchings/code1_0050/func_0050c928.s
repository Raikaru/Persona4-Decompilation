.section .text
.set noat
.set noreorder
glabel func_0050c928
    /* 40C928 0050C928 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C92C 0050C92C 0000BFFF */  sd         $31, 0x0($29)
    /* 40C930 0050C930 0000BFDF */  ld         $31, 0x0($29)
    /* 40C934 0050C934 B8321408 */  j          func_0050cae0
    /* 40C938 0050C938 1000BD27 */   addiu     $29, $29, 0x10
    /* 40C93C 0050C93C 00000000 */  nop
.size func_0050c928, 0x18
