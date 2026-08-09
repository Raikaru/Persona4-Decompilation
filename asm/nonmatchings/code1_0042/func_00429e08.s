.section .text
.set noat
.set noreorder
glabel func_00429e08
    /* 329E08 00429E08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 329E0C 00429E0C 0000BFFF */  sd         $31, 0x0($29)
    /* 329E10 00429E10 64A7100C */  jal        func_00429d90
    /* 329E14 00429E14 00000000 */   nop
    /* 329E18 00429E18 0000BFDF */  ld         $31, 0x0($29)
    /* 329E1C 00429E1C 0800E003 */  jr         $31
    /* 329E20 00429E20 1000BD27 */   addiu     $29, $29, 0x10
    /* 329E24 00429E24 00000000 */  nop
.size func_00429e08, 0x20
