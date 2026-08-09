.section .text
.set noat
.set noreorder
glabel func_0019bcb0
    /* 9BCB0 0019BCB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 9BCB4 0019BCB4 0000BFFF */  sd         $31, 0x0($29)
    /* 9BCB8 0019BCB8 0000848C */  lw         $4, 0x0($4)
    /* 9BCBC 0019BCBC 1074060C */  jal        func_0019d040
    /* 9BCC0 0019BCC0 00000000 */   nop
    /* 9BCC4 0019BCC4 01000224 */  addiu      $2, $0, 0x1
    /* 9BCC8 0019BCC8 0000BFDF */  ld         $31, 0x0($29)
    /* 9BCCC 0019BCCC 1000BD27 */  addiu      $29, $29, 0x10
    /* 9BCD0 0019BCD0 0800E003 */  jr         $31
    /* 9BCD4 0019BCD4 00000000 */   nop
    /* 9BCD8 0019BCD8 00000000 */  nop
    /* 9BCDC 0019BCDC 00000000 */  nop
.size func_0019bcb0, 0x30
