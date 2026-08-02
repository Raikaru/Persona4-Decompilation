.section .text
.set noat
.set noreorder
glabel func_0045ad50
    /* 35AD50 0045AD50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 35AD54 0045AD54 0000BFFF */  sd         $31, 0x0($29)
    /* 35AD58 0045AD58 3C240400 */  dsll32     $4, $4, 16
    /* 35AD5C 0045AD5C 3F240400 */  dsra32     $4, $4, 16
    /* 35AD60 0045AD60 05008128 */  slti       $1, $4, 0x5
    /* 35AD64 0045AD64 25002010 */  beqz       $1, .L0045ADFC
    /* 35AD68 0045AD68 00000000 */   nop
    /* 35AD6C 0045AD6C 34010224 */  addiu      $2, $0, 0x134
    /* 35AD70 0045AD70 18408200 */  mult       $8, $4, $2
    /* 35AD74 0045AD74 01000324 */  addiu      $3, $0, 0x1
    /* 35AD78 0045AD78 8D00023C */  lui        $2, %hi(D_008D2B90)
    /* 35AD7C 0045AD7C 902B4224 */  addiu      $2, $2, %lo(D_008D2B90)
    /* 35AD80 0045AD80 21104800 */  addu       $2, $2, $8
    /* 35AD84 0045AD84 000043AC */  sw         $3, 0x0($2)
    /* 35AD88 0045AD88 E7030324 */  addiu      $3, $0, 0x3E7
    /* 35AD8C 0045AD8C 8D00023C */  lui        $2, %hi(D_008D2B98)
    /* 35AD90 0045AD90 982B4224 */  addiu      $2, $2, %lo(D_008D2B98)
    /* 35AD94 0045AD94 21104800 */  addu       $2, $2, $8
    /* 35AD98 0045AD98 000043A4 */  sh         $3, 0x0($2)
    /* 35AD9C 0045AD9C 8D00023C */  lui        $2, %hi(D_008D2B9C)
    /* 35ADA0 0045ADA0 9C2B4224 */  addiu      $2, $2, %lo(D_008D2B9C)
    /* 35ADA4 0045ADA4 21104800 */  addu       $2, $2, $8
    /* 35ADA8 0045ADA8 000040A4 */  sh         $0, 0x0($2)
    /* 35ADAC 0045ADAC 8D00023C */  lui        $2, %hi(D_008D2BA4)
    /* 35ADB0 0045ADB0 A42B4224 */  addiu      $2, $2, %lo(D_008D2BA4)
    /* 35ADB4 0045ADB4 21384800 */  addu       $7, $2, $8
    /* 35ADB8 0045ADB8 0000E384 */  lh         $3, 0x0($7)
    /* 35ADBC 0045ADBC 8D00023C */  lui        $2, %hi(D_008D2BA6)
    /* 35ADC0 0045ADC0 A62B4224 */  addiu      $2, $2, %lo(D_008D2BA6)
    /* 35ADC4 0045ADC4 21104800 */  addu       $2, $2, $8
    /* 35ADC8 0045ADC8 000043A4 */  sh         $3, 0x0($2)
    /* 35ADCC 0045ADCC 04000224 */  addiu      $2, $0, 0x4
    /* 35ADD0 0045ADD0 0000E2A4 */  sh         $2, 0x0($7)
    /* 35ADD4 0045ADD4 8D00023C */  lui        $2, %hi(D_008D2CB0)
    /* 35ADD8 0045ADD8 B02C4224 */  addiu      $2, $2, %lo(D_008D2CB0)
    /* 35ADDC 0045ADDC 21104800 */  addu       $2, $2, $8
    /* 35ADE0 0045ADE0 000046AC */  sw         $6, 0x0($2)
    /* 35ADE4 0045ADE4 8D00023C */  lui        $2, %hi(D_008D2CA8)
    /* 35ADE8 0045ADE8 A82C4224 */  addiu      $2, $2, %lo(D_008D2CA8)
    /* 35ADEC 0045ADEC 21104800 */  addu       $2, $2, $8
    /* 35ADF0 0045ADF0 000045AC */  sw         $5, 0x0($2)
    /* 35ADF4 0045ADF4 B466110C */  jal        func_00459ad0
    /* 35ADF8 0045ADF8 00000000 */   nop
  .L0045ADFC:
    /* 35ADFC 0045ADFC 01000224 */  addiu      $2, $0, 0x1
    /* 35AE00 0045AE00 0000BFDF */  ld         $31, 0x0($29)
    /* 35AE04 0045AE04 1000BD27 */  addiu      $29, $29, 0x10
    /* 35AE08 0045AE08 0800E003 */  jr         $31
    /* 35AE0C 0045AE0C 00000000 */   nop
.size func_0045ad50, 0xc0
