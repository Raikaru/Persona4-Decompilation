.section .text
.set noat
.set noreorder
glabel func_002baa20
    /* 1BAA20 002BAA20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BAA24 002BAA24 0000BFFF */  sd         $31, 0x0($29)
    /* 1BAA28 002BAA28 8800043C */  lui        $4, %hi(D_00882F60)
    /* 1BAA2C 002BAA2C 602F8424 */  addiu      $4, $4, %lo(D_00882F60)
    /* 1BAA30 002BAA30 A4EA0A0C */  jal        func_002baa90
    /* 1BAA34 002BAA34 00000000 */   nop
    /* 1BAA38 002BAA38 94EA0A0C */  jal        func_002baa50
    /* 1BAA3C 002BAA3C 00000000 */   nop
    /* 1BAA40 002BAA40 0000BFDF */  ld         $31, 0x0($29)
    /* 1BAA44 002BAA44 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BAA48 002BAA48 0800E003 */  jr         $31
    /* 1BAA4C 002BAA4C 00000000 */   nop
.size func_002baa20, 0x30
