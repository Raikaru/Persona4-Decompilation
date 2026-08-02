.section .text
.set noat
.set noreorder
glabel func_0010ad80
    /* AD80 0010AD80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AD84 0010AD84 1000BFFF */  sd         $31, 0x10($29)
    /* AD88 0010AD88 0000B07F */  sq         $16, 0x0($29)
    /* AD8C 0010AD8C 2D808000 */  daddu      $16, $4, $0
    /* AD90 0010AD90 6C2D040C */  jal        func_0010b5b0
    /* AD94 0010AD94 00000000 */   nop
    /* AD98 0010AD98 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* AD9C 0010AD9C 2D380000 */  daddu      $7, $0, $0
    /* ADA0 0010ADA0 3C2C1000 */  dsll32     $5, $16, 16
    /* ADA4 0010ADA4 3F2C0500 */  dsra32     $5, $5, 16
    /* ADA8 0010ADA8 7900043C */  lui        $4, %hi(D_007973A0)
    /* ADAC 0010ADAC A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* ADB0 0010ADB0 13000010 */  b          .L0010AE00
    /* ADB4 0010ADB4 00000000 */   nop
  .L0010ADB8:
    /* ADB8 0010ADB8 FFFFE330 */  andi       $3, $7, 0xFFFF
    /* ADBC 0010ADBC 40100300 */  sll        $2, $3, 1
    /* ADC0 0010ADC0 21104300 */  addu       $2, $2, $3
    /* ADC4 0010ADC4 00110200 */  sll        $2, $2, 4
    /* ADC8 0010ADC8 21188200 */  addu       $3, $4, $2
    /* ADCC 0010ADCC EC0B6294 */  lhu        $2, 0xBEC($3)
    /* ADD0 0010ADD0 01004230 */  andi       $2, $2, 0x1
    /* ADD4 0010ADD4 08004010 */  beqz       $2, .L0010ADF8
    /* ADD8 0010ADD8 00000000 */   nop
    /* ADDC 0010ADDC EE0B6294 */  lhu        $2, 0xBEE($3)
    /* ADE0 0010ADE0 05004514 */  bne        $2, $5, .L0010ADF8
    /* ADE4 0010ADE4 00000000 */   nop
    /* ADE8 0010ADE8 3C240700 */  dsll32     $4, $7, 16
    /* ADEC 0010ADEC 3F240400 */  dsra32     $4, $4, 16
    /* ADF0 0010ADF0 08000010 */  b          .L0010AE14
    /* ADF4 0010ADF4 00000000 */   nop
  .L0010ADF8:
    /* ADF8 0010ADF8 0100E224 */  addiu      $2, $7, 0x1
    /* ADFC 0010ADFC FFFF4730 */  andi       $7, $2, 0xFFFF
  .L0010AE00:
    /* AE00 0010AE00 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AE04 0010AE04 2A104600 */  slt        $2, $2, $6
    /* AE08 0010AE08 EBFF4014 */  bnez       $2, .L0010ADB8
    /* AE0C 0010AE0C 00000000 */   nop
    /* AE10 0010AE10 FFFF0424 */  addiu      $4, $0, -0x1
  .L0010AE14:
    /* AE14 0010AE14 8C2B040C */  jal        func_0010ae30
    /* AE18 0010AE18 00000000 */   nop
    /* AE1C 0010AE1C 1000BFDF */  ld         $31, 0x10($29)
    /* AE20 0010AE20 0000B07B */  lq         $16, 0x0($29)
    /* AE24 0010AE24 2000BD27 */  addiu      $29, $29, 0x20
    /* AE28 0010AE28 0800E003 */  jr         $31
    /* AE2C 0010AE2C 00000000 */   nop
.size func_0010ad80, 0xb0
