.section .text
.set noat
.set noreorder
glabel func_002b6ea0
    /* 1B6EA0 002B6EA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B6EA4 002B6EA4 0000BFFF */  sd         $31, 0x0($29)
    /* 1B6EA8 002B6EA8 0028120C */  jal        func_0048a000
    /* 1B6EAC 002B6EAC 00000000 */   nop
    /* 1B6EB0 002B6EB0 0000BFDF */  ld         $31, 0x0($29)
    /* 1B6EB4 002B6EB4 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B6EB8 002B6EB8 0800E003 */  jr         $31
    /* 1B6EBC 002B6EBC 00000000 */   nop
.size func_002b6ea0, 0x20
