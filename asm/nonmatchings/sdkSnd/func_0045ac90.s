.section .text
.set noat
.set noreorder
glabel func_0045ac90
    /* 35AC90 0045AC90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 35AC94 0045AC94 0000BFFF */  sd         $31, 0x0($29)
    /* 35AC98 0045AC98 3C240400 */  dsll32     $4, $4, 16
    /* 35AC9C 0045AC9C 3F240400 */  dsra32     $4, $4, 16
    /* 35ACA0 0045ACA0 05008128 */  slti       $1, $4, 0x5
    /* 35ACA4 0045ACA4 25002010 */  beqz       $1, .L0045AD3C
    /* 35ACA8 0045ACA8 00000000 */   nop
    /* 35ACAC 0045ACAC 34010224 */  addiu      $2, $0, 0x134
    /* 35ACB0 0045ACB0 18408200 */  mult       $8, $4, $2
    /* 35ACB4 0045ACB4 01000324 */  addiu      $3, $0, 0x1
    /* 35ACB8 0045ACB8 8D00023C */  lui        $2, %hi(D_008D2B90)
    /* 35ACBC 0045ACBC 902B4224 */  addiu      $2, $2, %lo(D_008D2B90)
    /* 35ACC0 0045ACC0 21104800 */  addu       $2, $2, $8
    /* 35ACC4 0045ACC4 000043AC */  sw         $3, 0x0($2)
    /* 35ACC8 0045ACC8 E7030324 */  addiu      $3, $0, 0x3E7
    /* 35ACCC 0045ACCC 8D00023C */  lui        $2, %hi(D_008D2B98)
    /* 35ACD0 0045ACD0 982B4224 */  addiu      $2, $2, %lo(D_008D2B98)
    /* 35ACD4 0045ACD4 21104800 */  addu       $2, $2, $8
    /* 35ACD8 0045ACD8 000043A4 */  sh         $3, 0x0($2)
    /* 35ACDC 0045ACDC 8D00023C */  lui        $2, %hi(D_008D2B9C)
    /* 35ACE0 0045ACE0 9C2B4224 */  addiu      $2, $2, %lo(D_008D2B9C)
    /* 35ACE4 0045ACE4 21104800 */  addu       $2, $2, $8
    /* 35ACE8 0045ACE8 000040A4 */  sh         $0, 0x0($2)
    /* 35ACEC 0045ACEC 8D00023C */  lui        $2, %hi(D_008D2BA4)
    /* 35ACF0 0045ACF0 A42B4224 */  addiu      $2, $2, %lo(D_008D2BA4)
    /* 35ACF4 0045ACF4 21384800 */  addu       $7, $2, $8
    /* 35ACF8 0045ACF8 0000E384 */  lh         $3, 0x0($7)
    /* 35ACFC 0045ACFC 8D00023C */  lui        $2, %hi(D_008D2BA6)
    /* 35AD00 0045AD00 A62B4224 */  addiu      $2, $2, %lo(D_008D2BA6)
    /* 35AD04 0045AD04 21104800 */  addu       $2, $2, $8
    /* 35AD08 0045AD08 000043A4 */  sh         $3, 0x0($2)
    /* 35AD0C 0045AD0C 02000224 */  addiu      $2, $0, 0x2
    /* 35AD10 0045AD10 0000E2A4 */  sh         $2, 0x0($7)
    /* 35AD14 0045AD14 8D00023C */  lui        $2, %hi(D_008D2CB0)
    /* 35AD18 0045AD18 B02C4224 */  addiu      $2, $2, %lo(D_008D2CB0)
    /* 35AD1C 0045AD1C 21104800 */  addu       $2, $2, $8
    /* 35AD20 0045AD20 000046AC */  sw         $6, 0x0($2)
    /* 35AD24 0045AD24 8D00023C */  lui        $2, %hi(D_008D2CA8)
    /* 35AD28 0045AD28 A82C4224 */  addiu      $2, $2, %lo(D_008D2CA8)
    /* 35AD2C 0045AD2C 21104800 */  addu       $2, $2, $8
    /* 35AD30 0045AD30 000045AC */  sw         $5, 0x0($2)
    /* 35AD34 0045AD34 B466110C */  jal        func_00459ad0
    /* 35AD38 0045AD38 00000000 */   nop
  .L0045AD3C:
    /* 35AD3C 0045AD3C 01000224 */  addiu      $2, $0, 0x1
    /* 35AD40 0045AD40 0000BFDF */  ld         $31, 0x0($29)
    /* 35AD44 0045AD44 1000BD27 */  addiu      $29, $29, 0x10
    /* 35AD48 0045AD48 0800E003 */  jr         $31
    /* 35AD4C 0045AD4C 00000000 */   nop
.size func_0045ac90, 0xc0
