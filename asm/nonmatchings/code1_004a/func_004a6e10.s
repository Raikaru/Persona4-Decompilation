.section .text
.set noat
.set noreorder
glabel func_004a6e10
    /* 3A6E10 004A6E10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3A6E14 004A6E14 0000BFFF */  sd         $31, 0x0($29)
    /* 3A6E18 004A6E18 18008424 */  addiu      $4, $4, 0x18
    /* 3A6E1C 004A6E1C 009B120C */  jal        func_004a6c00
    /* 3A6E20 004A6E20 00000000 */   nop
    /* 3A6E24 004A6E24 0000BFDF */  ld         $31, 0x0($29)
    /* 3A6E28 004A6E28 1000BD27 */  addiu      $29, $29, 0x10
    /* 3A6E2C 004A6E2C 0800E003 */  jr         $31
    /* 3A6E30 004A6E30 00000000 */   nop
    /* 3A6E34 004A6E34 00000000 */  nop
    /* 3A6E38 004A6E38 00000000 */  nop
    /* 3A6E3C 004A6E3C 00000000 */  nop
.size func_004a6e10, 0x30
