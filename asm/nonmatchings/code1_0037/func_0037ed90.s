.section .text
.set noat
.set noreorder
glabel func_0037ed90
    /* 27ED90 0037ED90 80FFBD27 */  addiu      $29, $29, -0x80
    /* 27ED94 0037ED94 5000BFFF */  sd         $31, 0x50($29)
    /* 27ED98 0037ED98 4000B37F */  sq         $19, 0x40($29)
    /* 27ED9C 0037ED9C 3000B27F */  sq         $18, 0x30($29)
    /* 27EDA0 0037EDA0 2000B17F */  sq         $17, 0x20($29)
    /* 27EDA4 0037EDA4 1000B07F */  sq         $16, 0x10($29)
    /* 27EDA8 0037EDA8 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 27EDAC 0037EDAC 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 27EDB0 0037EDB0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 27EDB4 0037EDB4 2D808000 */  daddu      $16, $4, $0
    /* 27EDB8 0037EDB8 03000624 */  addiu      $6, $0, 0x3
    /* 27EDBC 0037EDBC 1A00A600 */  div        $0, $5, $6
    /* 27EDC0 0037EDC0 12100000 */  mflo       $2
    /* 27EDC4 0037EDC4 FFFF4324 */  addiu      $3, $2, -0x1
    /* 27EDC8 0037EDC8 6B000224 */  addiu      $2, $0, 0x6B
    /* 27EDCC 0037EDCC 18106200 */  mult       $2, $3, $2
    /* 27EDD0 0037EDD0 00008244 */  mtc1       $2, $f0
    /* 27EDD4 0037EDD4 00000000 */  nop
    /* 27EDD8 0037EDD8 60008046 */  cvt.s.w    $f1, $f0
    /* 27EDDC 0037EDDC 9D43023C */  lui        $2, (0x439D0000 >> 16)
    /* 27EDE0 0037EDE0 00008244 */  mtc1       $2, $f0
    /* 27EDE4 0037EDE4 00000000 */  nop
    /* 27EDE8 0037EDE8 00050146 */  add.s      $f20, $f0, $f1
    /* 27EDEC 0037EDEC 1A00A600 */  div        $0, $5, $6
    /* 27EDF0 0037EDF0 10100000 */  mfhi       $2
    /* 27EDF4 0037EDF4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 27EDF8 0037EDF8 00008244 */  mtc1       $2, $f0
    /* 27EDFC 0037EDFC 00000000 */  nop
    /* 27EE00 0037EE00 E0008046 */  cvt.s.w    $f3, $f0
    /* 27EE04 0037EE04 F042023C */  lui        $2, (0x42F00000 >> 16)
    /* 27EE08 0037EE08 00108244 */  mtc1       $2, $f2
    /* 27EE0C 0037EE0C 6C43023C */  lui        $2, (0x436C0000 >> 16)
    /* 27EE10 0037EE10 00088244 */  mtc1       $2, $f1
    /* 27EE14 0037EE14 00008044 */  mtc1       $0, $f0
    /* 27EE18 0037EE18 00000000 */  nop
    /* 27EE1C 0037EE1C 18000146 */  adda.s     $f0, $f1
    /* 27EE20 0037EE20 5C150346 */  madd.s     $f21, $f2, $f3
    /* 27EE24 0037EE24 0200023C */  lui        $2, (0x20000 >> 16)
    /* 27EE28 0037EE28 21108200 */  addu       $2, $4, $2
    /* 27EE2C 0037EE2C 04F3448C */  lw         $4, -0xCFC($2)
    /* 27EE30 0037EE30 0200023C */  lui        $2, (0x20000 >> 16)
    /* 27EE34 0037EE34 21100202 */  addu       $2, $16, $2
    /* 27EE38 0037EE38 FCF2458C */  lw         $5, -0xD04($2)
    /* 27EE3C 0037EE3C 4CE10D0C */  jal        func_00378530
    /* 27EE40 0037EE40 00000000 */   nop
    /* 27EE44 0037EE44 2D884000 */  daddu      $17, $2, $0
    /* 27EE48 0037EE48 2D200002 */  daddu      $4, $16, $0
    /* 27EE4C 0037EE4C 2D280000 */  daddu      $5, $0, $0
    /* 27EE50 0037EE50 6000A627 */  addiu      $6, $29, 0x60
    /* 27EE54 0037EE54 CCD80D0C */  jal        func_00376330
    /* 27EE58 0037EE58 00000000 */   nop
    /* 27EE5C 0037EE5C 6000A427 */  addiu      $4, $29, 0x60
    /* 27EE60 0037EE60 7800A527 */  addiu      $5, $29, 0x78
    /* 27EE64 0037EE64 F8C50D0C */  jal        func_003717e0
    /* 27EE68 0037EE68 00000000 */   nop
    /* 27EE6C 0037EE6C 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* 27EE70 0037EE70 01001446 */  sub.s      $f0, $f0, $f20
    /* 27EE74 0037EE74 7000A0E7 */  swc1       $f0, 0x70($29)
    /* 27EE78 0037EE78 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* 27EE7C 0037EE7C 01001546 */  sub.s      $f0, $f0, $f21
    /* 27EE80 0037EE80 7400A0E7 */  swc1       $f0, 0x74($29)
    /* 27EE84 0037EE84 7000A427 */  addiu      $4, $29, 0x70
    /* 27EE88 0037EE88 6C900F0C */  jal        func_003e41b0
    /* 27EE8C 0037EE8C 00000000 */   nop
    /* 27EE90 0037EE90 86050046 */  mov.s      $f22, $f0
    /* 27EE94 0037EE94 01001324 */  addiu      $19, $0, 0x1
    /* 27EE98 0037EE98 2D900000 */  daddu      $18, $0, $0
    /* 27EE9C 0037EE9C 19000010 */  b          .L0037EF04
    /* 27EEA0 0037EEA0 00000000 */   nop
  .L0037EEA4:
    /* 27EEA4 0037EEA4 2D200002 */  daddu      $4, $16, $0
    /* 27EEA8 0037EEA8 2D286002 */  daddu      $5, $19, $0
    /* 27EEAC 0037EEAC 6000A627 */  addiu      $6, $29, 0x60
    /* 27EEB0 0037EEB0 CCD80D0C */  jal        func_00376330
    /* 27EEB4 0037EEB4 00000000 */   nop
    /* 27EEB8 0037EEB8 6000A427 */  addiu      $4, $29, 0x60
    /* 27EEBC 0037EEBC 7800A527 */  addiu      $5, $29, 0x78
    /* 27EEC0 0037EEC0 F8C50D0C */  jal        func_003717e0
    /* 27EEC4 0037EEC4 00000000 */   nop
    /* 27EEC8 0037EEC8 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* 27EECC 0037EECC 01001446 */  sub.s      $f0, $f0, $f20
    /* 27EED0 0037EED0 7000A0E7 */  swc1       $f0, 0x70($29)
    /* 27EED4 0037EED4 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* 27EED8 0037EED8 01001546 */  sub.s      $f0, $f0, $f21
    /* 27EEDC 0037EEDC 7400A0E7 */  swc1       $f0, 0x74($29)
    /* 27EEE0 0037EEE0 7000A427 */  addiu      $4, $29, 0x70
    /* 27EEE4 0037EEE4 6C900F0C */  jal        func_003e41b0
    /* 27EEE8 0037EEE8 00000000 */   nop
    /* 27EEEC 0037EEEC 34001646 */  c.lt.s     $f0, $f22
    /* 27EEF0 0037EEF0 03000045 */  bc1f       .L0037EF00
    /* 27EEF4 0037EEF4 00000000 */   nop
    /* 27EEF8 0037EEF8 2D906002 */  daddu      $18, $19, $0
    /* 27EEFC 0037EEFC 86050046 */  mov.s      $f22, $f0
  .L0037EF00:
    /* 27EF00 0037EF00 01007326 */  addiu      $19, $19, 0x1
  .L0037EF04:
    /* 27EF04 0037EF04 2A107102 */  slt        $2, $19, $17
    /* 27EF08 0037EF08 E6FF4014 */  bnez       $2, .L0037EEA4
    /* 27EF0C 0037EF0C 00000000 */   nop
    /* 27EF10 0037EF10 2D104002 */  daddu      $2, $18, $0
    /* 27EF14 0037EF14 5000BFDF */  ld         $31, 0x50($29)
    /* 27EF18 0037EF18 4000B37B */  lq         $19, 0x40($29)
    /* 27EF1C 0037EF1C 3000B27B */  lq         $18, 0x30($29)
    /* 27EF20 0037EF20 2000B17B */  lq         $17, 0x20($29)
    /* 27EF24 0037EF24 1000B07B */  lq         $16, 0x10($29)
    /* 27EF28 0037EF28 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 27EF2C 0037EF2C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 27EF30 0037EF30 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 27EF34 0037EF34 8000BD27 */  addiu      $29, $29, 0x80
    /* 27EF38 0037EF38 0800E003 */  jr         $31
    /* 27EF3C 0037EF3C 00000000 */   nop
.size func_0037ed90, 0x1b0
