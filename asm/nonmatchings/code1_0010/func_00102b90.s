.section .text
.set noat
.set noreorder
glabel func_00102b90
    /* 2B90 00102B90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2B94 00102B94 0000BFFF */  sd         $31, 0x0($29)
    /* 2B98 00102B98 CC46040C */  jal        func_00111b30
    /* 2B9C 00102B9C 00000000 */   nop
    /* 2BA0 00102BA0 0000BFDF */  ld         $31, 0x0($29)
    /* 2BA4 00102BA4 1000BD27 */  addiu      $29, $29, 0x10
    /* 2BA8 00102BA8 0800E003 */  jr         $31
    /* 2BAC 00102BAC 00000000 */   nop
.size func_00102b90, 0x20
