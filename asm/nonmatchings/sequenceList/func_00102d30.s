.section .text
.set noat
.set noreorder
glabel func_00102d30
    /* 2D30 00102D30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D34 00102D34 0000BFFF */  sd         $31, 0x0($29)
    /* 2D38 00102D38 5E00043C */  lui        $4, %hi(D_005DCB98)
    /* 2D3C 00102D3C 98CB8424 */  addiu      $4, $4, %lo(D_005DCB98)
    /* 2D40 00102D40 E048110C */  jal        func_00452380
    /* 2D44 00102D44 00000000 */   nop
    /* 2D48 00102D48 2B100200 */  sltu       $2, $0, $2
    /* 2D4C 00102D4C 0000BFDF */  ld         $31, 0x0($29)
    /* 2D50 00102D50 1000BD27 */  addiu      $29, $29, 0x10
    /* 2D54 00102D54 0800E003 */  jr         $31
    /* 2D58 00102D58 00000000 */   nop
    /* 2D5C 00102D5C 00000000 */  nop
.size func_00102d30, 0x30
