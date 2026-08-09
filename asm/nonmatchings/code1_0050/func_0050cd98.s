.section .text
.set noat
.set noreorder
glabel func_0050cd98
    /* 40CD98 0050CD98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CD9C 0050CD9C 0000BFFF */  sd         $31, 0x0($29)
    /* 40CDA0 0050CDA0 0000BFDF */  ld         $31, 0x0($29)
    /* 40CDA4 0050CDA4 50321408 */  j          func_0050c940
    /* 40CDA8 0050CDA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CDAC 0050CDAC 00000000 */  nop
.size func_0050cd98, 0x18
