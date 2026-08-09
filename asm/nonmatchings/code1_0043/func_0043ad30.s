.section .text
.set noat
.set noreorder
glabel func_0043ad30
    /* 33AD30 0043AD30 90FFBD27 */  addiu      $29, $29, -0x70
    /* 33AD34 0043AD34 7100023C */  lui        $2, %hi(D_0070FC40)
    /* 33AD38 0043AD38 4000B3FF */  sd         $19, 0x40($29)
    /* 33AD3C 0043AD3C 3000B2FF */  sd         $18, 0x30($29)
    /* 33AD40 0043AD40 2D98C000 */  daddu      $19, $6, $0
    /* 33AD44 0043AD44 1000B0FF */  sd         $16, 0x10($29)
    /* 33AD48 0043AD48 2D90A000 */  daddu      $18, $5, $0
    /* 33AD4C 0043AD4C 40FC438C */  lw         $3, %lo(D_0070FC40)($2)
    /* 33AD50 0043AD50 2D808000 */  daddu      $16, $4, $0
    /* 33AD54 0043AD54 6000BFFF */  sd         $31, 0x60($29)
    /* 33AD58 0043AD58 5000B4FF */  sd         $20, 0x50($29)
    /* 33AD5C 0043AD5C 03006014 */  bnez       $3, .L0043AD6C
    /* 33AD60 0043AD60 2000B1FF */   sd        $17, 0x20($29)
    /* 33AD64 0043AD64 36000010 */  b          .L0043AE40
    /* 33AD68 0043AD68 2D100000 */   daddu     $2, $0, $0
  .L0043AD6C:
    /* 33AD6C 0043AD6C 8C00143C */  lui        $20, %hi(D_008BE280)
    /* 33AD70 0043AD70 0886100C */  jal        func_00421820
    /* 33AD74 0043AD74 80E2848E */   lw        $4, %lo(D_008BE280)($20)
    /* 33AD78 0043AD78 0000028E */  lw         $2, 0x0($16)
    /* 33AD7C 0043AD7C 8C00073C */  lui        $7, %hi(D_008BDAC0)
    /* 33AD80 0043AD80 C0DAF124 */  addiu      $17, $7, %lo(D_008BDAC0)
    /* 33AD84 0043AD84 14000626 */  addiu      $6, $16, 0x14
    /* 33AD88 0043AD88 C0DAE2AC */  sw         $2, %lo(D_008BDAC0)($7)
    /* 33AD8C 0043AD8C 14002826 */  addiu      $8, $17, 0x14
    /* 33AD90 0043AD90 280032AE */  sw         $18, 0x28($17)
    /* 33AD94 0043AD94 2D280000 */  daddu      $5, $0, $0
    /* 33AD98 0043AD98 0400028E */  lw         $2, 0x4($16)
    /* 33AD9C 0043AD9C 2C0033AE */  sw         $19, 0x2C($17)
    /* 33ADA0 0043ADA0 040022AE */  sw         $2, 0x4($17)
    /* 33ADA4 0043ADA4 0800038E */  lw         $3, 0x8($16)
    /* 33ADA8 0043ADA8 080023AE */  sw         $3, 0x8($17)
    /* 33ADAC 0043ADAC 0C00028E */  lw         $2, 0xC($16)
    /* 33ADB0 0043ADB0 0C0022AE */  sw         $2, 0xC($17)
    /* 33ADB4 0043ADB4 1000038E */  lw         $3, 0x10($16)
    /* 33ADB8 0043ADB8 100023AE */  sw         $3, 0x10($17)
    /* 33ADBC 0043ADBC 00000000 */  nop
  .L0043ADC0:
    /* 33ADC0 0043ADC0 2110C500 */  addu       $2, $6, $5
    /* 33ADC4 0043ADC4 21200501 */  addu       $4, $8, $5
    /* 33ADC8 0043ADC8 00004390 */  lbu        $3, 0x0($2)
    /* 33ADCC 0043ADCC 0100A524 */  addiu      $5, $5, 0x1
    /* 33ADD0 0043ADD0 1000A228 */  slti       $2, $5, 0x10
    /* 33ADD4 0043ADD4 000083A0 */  sb         $3, 0x0($4)
    /* 33ADD8 0043ADD8 F9FF4014 */  bnez       $2, .L0043ADC0
    /* 33ADDC 0043ADDC 00000000 */   nop
    /* 33ADE0 0043ADE0 C0DAE724 */  addiu      $7, $7, %lo(D_008BDAC0)
    /* 33ADE4 0043ADE4 0080053C */  lui        $5, (0x80001301 >> 16)
    /* 33ADE8 0043ADE8 8C00043C */  lui        $4, %hi(D_008BD9C0)
    /* 33ADEC 0043ADEC 0000A0AF */  sw         $0, 0x0($29)
    /* 33ADF0 0043ADF0 C0D98424 */  addiu      $4, $4, %lo(D_008BD9C0)
    /* 33ADF4 0043ADF4 0113A534 */  ori        $5, $5, (0x80001301 & 0xFFFF)
    /* 33ADF8 0043ADF8 2D300000 */  daddu      $6, $0, $0
    /* 33ADFC 0043ADFC 90000824 */  addiu      $8, $0, 0x90
    /* 33AE00 0043AE00 2D48E000 */  daddu      $9, $7, $0
    /* 33AE04 0043AE04 90000A24 */  addiu      $10, $0, 0x90
    /* 33AE08 0043AE08 2C96100C */  jal        func_004258b0
    /* 33AE0C 0043AE0C 2D580000 */   daddu     $11, $0, $0
    /* 33AE10 0043AE10 08004104 */  bgez       $2, .L0043AE34
    /* 33AE14 0043AE14 80E2848E */   lw        $4, %lo(D_008BE280)($20)
    /* 33AE18 0043AE18 7500043C */  lui        $4, %hi(D_00754B20)
    /* 33AE1C 0043AE1C D2EE100C */  jal        func_0043bb48
    /* 33AE20 0043AE20 204B8424 */   addiu     $4, $4, %lo(D_00754B20)
    /* 33AE24 0043AE24 0086100C */  jal        func_00421800
    /* 33AE28 0043AE28 80E2848E */   lw        $4, %lo(D_008BE280)($20)
    /* 33AE2C 0043AE2C 04000010 */  b          .L0043AE40
    /* 33AE30 0043AE30 2D100000 */   daddu     $2, $0, $0
  .L0043AE34:
    /* 33AE34 0043AE34 0086100C */  jal        func_00421800
    /* 33AE38 0043AE38 2400308E */   lw        $16, 0x24($17)
    /* 33AE3C 0043AE3C 2D100002 */  daddu      $2, $16, $0
  .L0043AE40:
    /* 33AE40 0043AE40 6000BFDF */  ld         $31, 0x60($29)
    /* 33AE44 0043AE44 5000B4DF */  ld         $20, 0x50($29)
    /* 33AE48 0043AE48 4000B3DF */  ld         $19, 0x40($29)
    /* 33AE4C 0043AE4C 3000B2DF */  ld         $18, 0x30($29)
    /* 33AE50 0043AE50 2000B1DF */  ld         $17, 0x20($29)
    /* 33AE54 0043AE54 1000B0DF */  ld         $16, 0x10($29)
    /* 33AE58 0043AE58 0800E003 */  jr         $31
    /* 33AE5C 0043AE5C 7000BD27 */   addiu     $29, $29, 0x70
.size func_0043ad30, 0x130
