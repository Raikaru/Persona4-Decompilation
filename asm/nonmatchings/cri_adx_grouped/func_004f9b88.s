.section .text
.set noat
.set noreorder
glabel func_004f9b88
    /* 3F9B88 004F9B88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9B8C 004F9B8C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9B90 004F9B90 D4E6130C */  jal        func_004f9b50
    /* 3F9B94 004F9B94 00000000 */   nop
    /* 3F9B98 004F9B98 0000428C */  lw         $2, 0x0($2)
    /* 3F9B9C 004F9B9C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9BA0 004F9BA0 0800E003 */  jr         $31
    /* 3F9BA4 004F9BA4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f9b88, 0x20
