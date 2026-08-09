.section .text
.set noat
.set noreorder
glabel func_005123b8
    /* 4123B8 005123B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4123BC 005123BC 0000BFFF */  sd         $31, 0x0($29)
    /* 4123C0 005123C0 0420828C */  lw         $2, 0x2004($4)
    /* 4123C4 005123C4 0000BFDF */  ld         $31, 0x0($29)
    /* 4123C8 005123C8 0000448C */  lw         $4, 0x0($2)
    /* 4123CC 005123CC 70541308 */  j          func_004d51c0
    /* 4123D0 005123D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4123D4 005123D4 00000000 */  nop
.size func_005123b8, 0x20
