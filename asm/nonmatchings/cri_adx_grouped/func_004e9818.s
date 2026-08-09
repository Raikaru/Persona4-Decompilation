.section .text
.set noat
.set noreorder
glabel func_004e9818
    /* 3E9818 004E9818 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E981C 004E981C 0000BFFF */  sd         $31, 0x0($29)
    /* 3E9820 004E9820 14B5130C */  jal        func_004ed450
    /* 3E9824 004E9824 00000000 */   nop
    /* 3E9828 004E9828 0000BFDF */  ld         $31, 0x0($29)
    /* 3E982C 004E982C 0800E003 */  jr         $31
    /* 3E9830 004E9830 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E9834 004E9834 00000000 */  nop
.size func_004e9818, 0x20
