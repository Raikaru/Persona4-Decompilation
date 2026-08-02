.section .text
.set noat
.set noreorder
glabel func_0019acd0
    /* 9ACD0 0019ACD0 50FFBD27 */  addiu      $29, $29, -0xB0
    /* 9ACD4 0019ACD4 2000BFFF */  sd         $31, 0x20($29)
    /* 9ACD8 0019ACD8 1000B17F */  sq         $17, 0x10($29)
    /* 9ACDC 0019ACDC 0000B07F */  sq         $16, 0x0($29)
    /* 9ACE0 0019ACE0 2D888000 */  daddu      $17, $4, $0
    /* 9ACE4 0019ACE4 0000908C */  lw         $16, 0x0($4)
    /* 9ACE8 0019ACE8 A0000396 */  lhu        $3, 0xA0($16)
    /* 9ACEC 0019ACEC 01006324 */  addiu      $3, $3, 0x1
    /* 9ACF0 0019ACF0 A00003A6 */  sh         $3, 0xA0($16)
    /* 9ACF4 0019ACF4 08008394 */  lhu        $3, 0x8($4)
    /* 9ACF8 0019ACF8 00026330 */  andi       $3, $3, 0x200
    /* 9ACFC 0019ACFC 21006014 */  bnez       $3, .L0019AD84
    /* 9AD00 0019AD00 00000000 */   nop
    /* 9AD04 0019AD04 000A048E */  lw         $4, 0xA00($16)
    /* 9AD08 0019AD08 0C008010 */  beqz       $4, .L0019AD3C
    /* 9AD0C 0019AD0C 00000000 */   nop
    /* 9AD10 0019AD10 04002596 */  lhu        $5, 0x4($17)
    /* 9AD14 0019AD14 D4008394 */  lhu        $3, 0xD4($4)
    /* 9AD18 0019AD18 0500A314 */  bne        $5, $3, .L0019AD30
    /* 9AD1C 0019AD1C 00000000 */   nop
    /* 9AD20 0019AD20 06002596 */  lhu        $5, 0x6($17)
    /* 9AD24 0019AD24 D6008394 */  lhu        $3, 0xD6($4)
    /* 9AD28 0019AD28 3500A310 */  beq        $5, $3, .L0019AE00
    /* 9AD2C 0019AD2C 00000000 */   nop
  .L0019AD30:
    /* 9AD30 0019AD30 F8E1110C */  jal        func_004787e0
    /* 9AD34 0019AD34 00000000 */   nop
    /* 9AD38 0019AD38 000A00AE */  sw         $0, 0xA00($16)
  .L0019AD3C:
    /* 9AD3C 0019AD3C 04002496 */  lhu        $4, 0x4($17)
    /* 9AD40 0019AD40 06002596 */  lhu        $5, 0x6($17)
    /* 9AD44 0019AD44 2D300000 */  daddu      $6, $0, $0
    /* 9AD48 0019AD48 10DF110C */  jal        func_00477c40
    /* 9AD4C 0019AD4C 00000000 */   nop
    /* 9AD50 0019AD50 2D204000 */  daddu      $4, $2, $0
    /* 9AD54 0019AD54 0B008010 */  beqz       $4, .L0019AD84
    /* 9AD58 0019AD58 00000000 */   nop
    /* 9AD5C 0019AD5C D4E1110C */  jal        func_00478750
    /* 9AD60 0019AD60 00000000 */   nop
    /* 9AD64 0019AD64 000A02AE */  sw         $2, 0xA00($16)
    /* 9AD68 0019AD68 9800038E */  lw         $3, 0x98($16)
    /* 9AD6C 0019AD6C 02006334 */  ori        $3, $3, 0x2
    /* 9AD70 0019AD70 980003AE */  sw         $3, 0x98($16)
    /* 9AD74 0019AD74 01006334 */  ori        $3, $3, 0x1
    /* 9AD78 0019AD78 980003AE */  sw         $3, 0x98($16)
    /* 9AD7C 0019AD7C 20000010 */  b          .L0019AE00
    /* 9AD80 0019AD80 00000000 */   nop
  .L0019AD84:
    /* 9AD84 0019AD84 08002396 */  lhu        $3, 0x8($17)
    /* 9AD88 0019AD88 10006330 */  andi       $3, $3, 0x10
    /* 9AD8C 0019AD8C 14006014 */  bnez       $3, .L0019ADE0
    /* 9AD90 0019AD90 00000000 */   nop
    /* 9AD94 0019AD94 04002496 */  lhu        $4, 0x4($17)
    /* 9AD98 0019AD98 06002596 */  lhu        $5, 0x6($17)
    /* 9AD9C 0019AD9C 3000A627 */  addiu      $6, $29, 0x30
    /* 9ADA0 0019ADA0 44F4110C */  jal        func_0047d110
    /* 9ADA4 0019ADA4 00000000 */   nop
    /* 9ADA8 0019ADA8 B0A08427 */  addiu      $4, $28, -0x5F50
    /* 9ADAC 0019ADAC 5F00053C */  lui        $5, %hi(D_005F6D00)
    /* 9ADB0 0019ADB0 006DA524 */  addiu      $5, $5, %lo(D_005F6D00)
    /* 9ADB4 0019ADB4 980D0624 */  addiu      $6, $0, 0xD98
    /* 9ADB8 0019ADB8 DA02110C */  jal        func_00440b68
    /* 9ADBC 0019ADBC 00000000 */   nop
    /* 9ADC0 0019ADC0 3000A427 */  addiu      $4, $29, 0x30
    /* 9ADC4 0019ADC4 2D280000 */  daddu      $5, $0, $0
    /* 9ADC8 0019ADC8 9852110C */  jal        func_00454a60
    /* 9ADCC 0019ADCC 00000000 */   nop
    /* 9ADD0 0019ADD0 0C0022AE */  sw         $2, 0xC($17)
    /* 9ADD4 0019ADD4 9800038E */  lw         $3, 0x98($16)
    /* 9ADD8 0019ADD8 01006334 */  ori        $3, $3, 0x1
    /* 9ADDC 0019ADDC 980003AE */  sw         $3, 0x98($16)
  .L0019ADE0:
    /* 9ADE0 0019ADE0 08002396 */  lhu        $3, 0x8($17)
    /* 9ADE4 0019ADE4 00026330 */  andi       $3, $3, 0x200
    /* 9ADE8 0019ADE8 05006014 */  bnez       $3, .L0019AE00
    /* 9ADEC 0019ADEC 00000000 */   nop
    /* 9ADF0 0019ADF0 9800048E */  lw         $4, 0x98($16)
    /* 9ADF4 0019ADF4 FDFF0324 */  addiu      $3, $0, -0x3
    /* 9ADF8 0019ADF8 24188300 */  and        $3, $4, $3
    /* 9ADFC 0019ADFC 980003AE */  sw         $3, 0x98($16)
  .L0019AE00:
    /* 9AE00 0019AE00 2000BFDF */  ld         $31, 0x20($29)
    /* 9AE04 0019AE04 1000B17B */  lq         $17, 0x10($29)
    /* 9AE08 0019AE08 0000B07B */  lq         $16, 0x0($29)
    /* 9AE0C 0019AE0C B000BD27 */  addiu      $29, $29, 0xB0
    /* 9AE10 0019AE10 0800E003 */  jr         $31
    /* 9AE14 0019AE14 00000000 */   nop
    /* 9AE18 0019AE18 00000000 */  nop
    /* 9AE1C 0019AE1C 00000000 */  nop
.size func_0019acd0, 0x150
