.section .text
.set noat
.set noreorder
glabel func_00512b90
    /* 412B90 00512B90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 412B94 00512B94 0000BFFF */  sd         $31, 0x0($29)
    /* 412B98 00512B98 0420828C */  lw         $2, 0x2004($4)
    /* 412B9C 00512B9C 0000BFDF */  ld         $31, 0x0($29)
    /* 412BA0 00512BA0 0000448C */  lw         $4, 0x0($2)
    /* 412BA4 00512BA4 445A1308 */  j          func_004d6910
    /* 412BA8 00512BA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 412BAC 00512BAC 00000000 */  nop
.size func_00512b90, 0x20
