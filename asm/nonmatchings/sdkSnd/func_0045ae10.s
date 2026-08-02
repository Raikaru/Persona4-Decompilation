.section .text
.set noat
.set noreorder
glabel func_0045ae10
    /* 35AE10 0045AE10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 35AE14 0045AE14 0000BFFF */  sd         $31, 0x0($29)
    /* 35AE18 0045AE18 34010224 */  addiu      $2, $0, 0x134
    /* 35AE1C 0045AE1C 1838A200 */  mult       $7, $5, $2
    /* 35AE20 0045AE20 01000324 */  addiu      $3, $0, 0x1
    /* 35AE24 0045AE24 8D00023C */  lui        $2, %hi(D_008D2B90)
    /* 35AE28 0045AE28 902B4224 */  addiu      $2, $2, %lo(D_008D2B90)
    /* 35AE2C 0045AE2C 21104700 */  addu       $2, $2, $7
    /* 35AE30 0045AE30 000043AC */  sw         $3, 0x0($2)
    /* 35AE34 0045AE34 8D00023C */  lui        $2, %hi(D_008D2B98)
    /* 35AE38 0045AE38 982B4224 */  addiu      $2, $2, %lo(D_008D2B98)
    /* 35AE3C 0045AE3C 21104700 */  addu       $2, $2, $7
    /* 35AE40 0045AE40 000046A4 */  sh         $6, 0x0($2)
    /* 35AE44 0045AE44 8D00023C */  lui        $2, %hi(D_008D2CAC)
    /* 35AE48 0045AE48 AC2C4224 */  addiu      $2, $2, %lo(D_008D2CAC)
    /* 35AE4C 0045AE4C 21104700 */  addu       $2, $2, $7
    /* 35AE50 0045AE50 000044AC */  sw         $4, 0x0($2)
    /* 35AE54 0045AE54 8D00023C */  lui        $2, %hi(D_008D2B9C)
    /* 35AE58 0045AE58 9C2B4224 */  addiu      $2, $2, %lo(D_008D2B9C)
    /* 35AE5C 0045AE5C 21104700 */  addu       $2, $2, $7
    /* 35AE60 0045AE60 000040A4 */  sh         $0, 0x0($2)
    /* 35AE64 0045AE64 8D00023C */  lui        $2, %hi(D_008D2BA4)
    /* 35AE68 0045AE68 A42B4224 */  addiu      $2, $2, %lo(D_008D2BA4)
    /* 35AE6C 0045AE6C 21204700 */  addu       $4, $2, $7
    /* 35AE70 0045AE70 00008384 */  lh         $3, 0x0($4)
    /* 35AE74 0045AE74 8D00023C */  lui        $2, %hi(D_008D2BA6)
    /* 35AE78 0045AE78 A62B4224 */  addiu      $2, $2, %lo(D_008D2BA6)
    /* 35AE7C 0045AE7C 21104700 */  addu       $2, $2, $7
    /* 35AE80 0045AE80 000043A4 */  sh         $3, 0x0($2)
    /* 35AE84 0045AE84 05000224 */  addiu      $2, $0, 0x5
    /* 35AE88 0045AE88 000082A4 */  sh         $2, 0x0($4)
    /* 35AE8C 0045AE8C 2D20A000 */  daddu      $4, $5, $0
    /* 35AE90 0045AE90 B466110C */  jal        func_00459ad0
    /* 35AE94 0045AE94 00000000 */   nop
    /* 35AE98 0045AE98 01000224 */  addiu      $2, $0, 0x1
    /* 35AE9C 0045AE9C 0000BFDF */  ld         $31, 0x0($29)
    /* 35AEA0 0045AEA0 1000BD27 */  addiu      $29, $29, 0x10
    /* 35AEA4 0045AEA4 0800E003 */  jr         $31
    /* 35AEA8 0045AEA8 00000000 */   nop
    /* 35AEAC 0045AEAC 00000000 */  nop
.size func_0045ae10, 0xa0
