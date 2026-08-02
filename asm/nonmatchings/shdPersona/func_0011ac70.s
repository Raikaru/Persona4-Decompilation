.section .text
.set noat
.set noreorder
glabel func_0011ac70
    /* 1AC70 0011AC70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1AC74 0011AC74 2000BFFF */  sd         $31, 0x20($29)
    /* 1AC78 0011AC78 1000B17F */  sq         $17, 0x10($29)
    /* 1AC7C 0011AC7C 0000B07F */  sq         $16, 0x0($29)
    /* 1AC80 0011AC80 2D888000 */  daddu      $17, $4, $0
    /* 1AC84 0011AC84 2D800000 */  daddu      $16, $0, $0
    /* 1AC88 0011AC88 5E000010 */  b          .L0011AE04
    /* 1AC8C 0011AC8C 00000000 */   nop
  .L0011AC90:
    /* 1AC90 0011AC90 08052486 */  lh         $4, 0x508($17)
    /* 1AC94 0011AC94 C0181000 */  sll        $3, $16, 3
    /* 1AC98 0011AC98 21187000 */  addu       $3, $3, $16
    /* 1AC9C 0011AC9C 80180300 */  sll        $3, $3, 2
    /* 1ACA0 0011ACA0 21182302 */  addu       $3, $17, $3
    /* 1ACA4 0011ACA4 E80262C4 */  lwc1       $f2, 0x2E8($3)
    /* 1ACA8 0011ACA8 00008444 */  mtc1       $4, $f0
    /* 1ACAC 0011ACAC 00000000 */  nop
    /* 1ACB0 0011ACB0 60008046 */  cvt.s.w    $f1, $f0
    /* 1ACB4 0011ACB4 34080246 */  c.lt.s     $f1, $f2
    /* 1ACB8 0011ACB8 04000045 */  bc1f       .L0011ACCC
    /* 1ACBC 0011ACBC 00000000 */   nop
    /* 1ACC0 0011ACC0 00008044 */  mtc1       $0, $f0
    /* 1ACC4 0011ACC4 11000010 */  b          .L0011AD0C
    /* 1ACC8 0011ACC8 00000000 */   nop
  .L0011ACCC:
    /* 1ACCC 0011ACCC EC0260C4 */  lwc1       $f0, 0x2EC($3)
    /* 1ACD0 0011ACD0 36080046 */  c.le.s     $f1, $f0
    /* 1ACD4 0011ACD4 05000145 */  bc1t       .L0011ACEC
    /* 1ACD8 0011ACD8 00000000 */   nop
    /* 1ACDC 0011ACDC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1ACE0 0011ACE0 00008344 */  mtc1       $3, $f0
    /* 1ACE4 0011ACE4 09000010 */  b          .L0011AD0C
    /* 1ACE8 0011ACE8 00000000 */   nop
  .L0011ACEC:
    /* 1ACEC 0011ACEC 41080246 */  sub.s      $f1, $f1, $f2
    /* 1ACF0 0011ACF0 01000246 */  sub.s      $f0, $f0, $f2
    /* 1ACF4 0011ACF4 43080046 */  div.s      $f1, $f1, $f0
    /* 1ACF8 0011ACF8 00000000 */  nop
    /* 1ACFC 0011ACFC 948080C7 */  lwc1       $f0, -0x7F6C($28)
    /* 1AD00 0011AD00 02030146 */  mul.s      $f12, $f0, $f1
    /* 1AD04 0011AD04 EC2D110C */  jal        func_0044b7b0
    /* 1AD08 0011AD08 00000000 */   nop
  .L0011AD0C:
    /* 1AD0C 0011AD0C C0181000 */  sll        $3, $16, 3
    /* 1AD10 0011AD10 21187000 */  addu       $3, $3, $16
    /* 1AD14 0011AD14 80180300 */  sll        $3, $3, 2
    /* 1AD18 0011AD18 21302302 */  addu       $6, $17, $3
    /* 1AD1C 0011AD1C CC02C2C4 */  lwc1       $f2, 0x2CC($6)
    /* 1AD20 0011AD20 D402C1C4 */  lwc1       $f1, 0x2D4($6)
    /* 1AD24 0011AD24 41080246 */  sub.s      $f1, $f1, $f2
    /* 1AD28 0011AD28 00188044 */  mtc1       $0, $f3
    /* 1AD2C 0011AD2C 00000000 */  nop
    /* 1AD30 0011AD30 18180246 */  adda.s     $f3, $f2
    /* 1AD34 0011AD34 5C000146 */  madd.s     $f1, $f0, $f1
    /* 1AD38 0011AD38 DC02C1E4 */  swc1       $f1, 0x2DC($6)
    /* 1AD3C 0011AD3C D002C2C4 */  lwc1       $f2, 0x2D0($6)
    /* 1AD40 0011AD40 D802C1C4 */  lwc1       $f1, 0x2D8($6)
    /* 1AD44 0011AD44 41080246 */  sub.s      $f1, $f1, $f2
    /* 1AD48 0011AD48 18180246 */  adda.s     $f3, $f2
    /* 1AD4C 0011AD4C 5C000146 */  madd.s     $f1, $f0, $f1
    /* 1AD50 0011AD50 E002C1E4 */  swc1       $f1, 0x2E0($6)
    /* 1AD54 0011AD54 E402C590 */  lbu        $5, 0x2E4($6)
    /* 1AD58 0011AD58 E502C390 */  lbu        $3, 0x2E5($6)
    /* 1AD5C 0011AD5C 23186500 */  subu       $3, $3, $5
    /* 1AD60 0011AD60 00088344 */  mtc1       $3, $f1
    /* 1AD64 0011AD64 00000000 */  nop
    /* 1AD68 0011AD68 E0088046 */  cvt.s.w    $f3, $f1
    /* 1AD6C 0011AD6C 0600A004 */  bltz       $5, .L0011AD88
    /* 1AD70 0011AD70 00000000 */   nop
    /* 1AD74 0011AD74 00088544 */  mtc1       $5, $f1
    /* 1AD78 0011AD78 00000000 */  nop
    /* 1AD7C 0011AD7C A0088046 */  cvt.s.w    $f2, $f1
    /* 1AD80 0011AD80 08000010 */  b          .L0011ADA4
    /* 1AD84 0011AD84 00000000 */   nop
  .L0011AD88:
    /* 1AD88 0011AD88 42200500 */  srl        $4, $5, 1
    /* 1AD8C 0011AD8C 0100A330 */  andi       $3, $5, 0x1
    /* 1AD90 0011AD90 25208300 */  or         $4, $4, $3
    /* 1AD94 0011AD94 00088444 */  mtc1       $4, $f1
    /* 1AD98 0011AD98 00000000 */  nop
    /* 1AD9C 0011AD9C A0088046 */  cvt.s.w    $f2, $f1
    /* 1ADA0 0011ADA0 80100246 */  add.s      $f2, $f2, $f2
  .L0011ADA4:
    /* 1ADA4 0011ADA4 00088044 */  mtc1       $0, $f1
    /* 1ADA8 0011ADA8 00000000 */  nop
    /* 1ADAC 0011ADAC 18080246 */  adda.s     $f1, $f2
    /* 1ADB0 0011ADB0 5C000346 */  madd.s     $f1, $f0, $f3
    /* 1ADB4 0011ADB4 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 1ADB8 0011ADB8 00008344 */  mtc1       $3, $f0
    /* 1ADBC 0011ADBC 00000000 */  nop
    /* 1ADC0 0011ADC0 36000146 */  c.le.s     $f0, $f1
    /* 1ADC4 0011ADC4 07000145 */  bc1t       .L0011ADE4
    /* 1ADC8 0011ADC8 00000000 */   nop
    /* 1ADCC 0011ADCC 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1ADD0 0011ADD0 00000444 */  mfc1       $4, $f0
    /* 1ADD4 0011ADD4 00000000 */  nop
    /* 1ADD8 0011ADD8 FF008430 */  andi       $4, $4, 0xFF
    /* 1ADDC 0011ADDC 07000010 */  b          .L0011ADFC
    /* 1ADE0 0011ADE0 00000000 */   nop
  .L0011ADE4:
    /* 1ADE4 0011ADE4 01080046 */  sub.s      $f0, $f1, $f0
    /* 1ADE8 0011ADE8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1ADEC 0011ADEC 00000444 */  mfc1       $4, $f0
    /* 1ADF0 0011ADF0 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 1ADF4 0011ADF4 25208300 */  or         $4, $4, $3
    /* 1ADF8 0011ADF8 FF008430 */  andi       $4, $4, 0xFF
  .L0011ADFC:
    /* 1ADFC 0011ADFC E602C4A0 */  sb         $4, 0x2E6($6)
    /* 1AE00 0011AE00 01001026 */  addiu      $16, $16, 0x1
  .L0011AE04:
    /* 1AE04 0011AE04 0A00032A */  slti       $3, $16, 0xA
    /* 1AE08 0011AE08 A1FF6014 */  bnez       $3, .L0011AC90
    /* 1AE0C 0011AE0C 00000000 */   nop
    /* 1AE10 0011AE10 0C05268E */  lw         $6, 0x50C($17)
    /* 1AE14 0011AE14 08052586 */  lh         $5, 0x508($17)
    /* 1AE18 0011AE18 2A08A600 */  slt        $1, $5, $6
    /* 1AE1C 0011AE1C 0D002010 */  beqz       $1, .L0011AE54
    /* 1AE20 0011AE20 00000000 */   nop
    /* 1AE24 0011AE24 04052492 */  lbu        $4, 0x504($17)
    /* 1AE28 0011AE28 06052392 */  lbu        $3, 0x506($17)
    /* 1AE2C 0011AE2C 23186400 */  subu       $3, $3, $4
    /* 1AE30 0011AE30 1818A300 */  mult       $3, $5, $3
    /* 1AE34 0011AE34 1A006600 */  div        $0, $3, $6
    /* 1AE38 0011AE38 00000000 */  nop
    /* 1AE3C 0011AE3C 00000000 */  nop
    /* 1AE40 0011AE40 12180000 */  mflo       $3
    /* 1AE44 0011AE44 21188300 */  addu       $3, $4, $3
    /* 1AE48 0011AE48 050523A2 */  sb         $3, 0x505($17)
    /* 1AE4C 0011AE4C 07000010 */  b          .L0011AE6C
    /* 1AE50 0011AE50 00000000 */   nop
  .L0011AE54:
    /* 1AE54 0011AE54 06052392 */  lbu        $3, 0x506($17)
    /* 1AE58 0011AE58 050523A2 */  sb         $3, 0x505($17)
    /* 1AE5C 0011AE5C 3405248E */  lw         $4, 0x534($17)
    /* 1AE60 0011AE60 FDFF0324 */  addiu      $3, $0, -0x3
    /* 1AE64 0011AE64 24188300 */  and        $3, $4, $3
    /* 1AE68 0011AE68 340523AE */  sw         $3, 0x534($17)
  .L0011AE6C:
    /* 1AE6C 0011AE6C 2000BFDF */  ld         $31, 0x20($29)
    /* 1AE70 0011AE70 1000B17B */  lq         $17, 0x10($29)
    /* 1AE74 0011AE74 0000B07B */  lq         $16, 0x0($29)
    /* 1AE78 0011AE78 3000BD27 */  addiu      $29, $29, 0x30
    /* 1AE7C 0011AE7C 0800E003 */  jr         $31
    /* 1AE80 0011AE80 00000000 */   nop
    /* 1AE84 0011AE84 00000000 */  nop
    /* 1AE88 0011AE88 00000000 */  nop
    /* 1AE8C 0011AE8C 00000000 */  nop
.size func_0011ac70, 0x220
