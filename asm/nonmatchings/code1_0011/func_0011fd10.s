.section .text
.set noat
.set noreorder
glabel func_0011fd10
    /* 1FD10 0011FD10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1FD14 0011FD14 0000BFFF */  sd         $31, 0x0($29)
    /* 1FD18 0011FD18 2048110C */  jal        func_00452080
    /* 1FD1C 0011FD1C 00000000 */   nop
    /* 1FD20 0011FD20 0000BFDF */  ld         $31, 0x0($29)
    /* 1FD24 0011FD24 1000BD27 */  addiu      $29, $29, 0x10
    /* 1FD28 0011FD28 0800E003 */  jr         $31
    /* 1FD2C 0011FD2C 00000000 */   nop
.size func_0011fd10, 0x20
