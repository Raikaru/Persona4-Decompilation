.section .text
.set noat
.set noreorder
glabel func_00374cf0
    /* 274CF0 00374CF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 274CF4 00374CF4 0000BFFF */  sd         $31, 0x0($29)
    /* 274CF8 00374CF8 0000848C */  lw         $4, 0x0($4)
    /* 274CFC 00374CFC CCB70D0C */  jal        func_0036df30
    /* 274D00 00374D00 00000000 */   nop
    /* 274D04 00374D04 0000BFDF */  ld         $31, 0x0($29)
    /* 274D08 00374D08 1000BD27 */  addiu      $29, $29, 0x10
    /* 274D0C 00374D0C 0800E003 */  jr         $31
    /* 274D10 00374D10 00000000 */   nop
    /* 274D14 00374D14 00000000 */  nop
    /* 274D18 00374D18 00000000 */  nop
    /* 274D1C 00374D1C 00000000 */  nop
.size func_00374cf0, 0x30
