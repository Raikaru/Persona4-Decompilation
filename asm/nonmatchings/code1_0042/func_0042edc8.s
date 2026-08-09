.section .text
.set noat
.set noreorder
glabel func_0042edc8
    /* 32EDC8 0042EDC8 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 32EDCC 0042EDCC 7000B6FF */  sd         $22, 0x70($29)
    /* 32EDD0 0042EDD0 7100163C */  lui        $22, %hi(D_0070DCD0)
    /* 32EDD4 0042EDD4 3000B2FF */  sd         $18, 0x30($29)
    /* 32EDD8 0042EDD8 D0DCC28E */  lw         $2, %lo(D_0070DCD0)($22)
    /* 32EDDC 0042EDDC 2D908000 */  daddu      $18, $4, $0
    /* 32EDE0 0042EDE0 9000BFFF */  sd         $31, 0x90($29)
    /* 32EDE4 0042EDE4 8000B7FF */  sd         $23, 0x80($29)
    /* 32EDE8 0042EDE8 6000B5FF */  sd         $21, 0x60($29)
    /* 32EDEC 0042EDEC 5000B4FF */  sd         $20, 0x50($29)
    /* 32EDF0 0042EDF0 4000B3FF */  sd         $19, 0x40($29)
    /* 32EDF4 0042EDF4 2000B1FF */  sd         $17, 0x20($29)
    /* 32EDF8 0042EDF8 04004018 */  blez       $2, .L0042EE0C
    /* 32EDFC 0042EDFC 1000B0FF */   sd        $16, 0x10($29)
    /* 32EE00 0042EE00 7500043C */  lui        $4, %hi(D_00754660)
    /* 32EE04 0042EE04 3291100C */  jal        func_004244c8
    /* 32EE08 0042EE08 60468424 */   addiu     $4, $4, %lo(D_00754660)
  .L0042EE0C:
    /* 32EE0C 0042EE0C 88AE100C */  jal        func_0042ba20
    /* 32EE10 0042EE10 00000000 */   nop
    /* 32EE14 0042EE14 7100043C */  lui        $4, %hi(D_0070DD00)
    /* 32EE18 0042EE18 01000324 */  addiu      $3, $0, 0x1
    /* 32EE1C 0042EE1C 03004010 */  beqz       $2, .L0042EE2C
    /* 32EE20 0042EE20 00DD83AC */   sw        $3, %lo(D_0070DD00)($4)
    /* 32EE24 0042EE24 9CAE100C */  jal        func_0042ba70
    /* 32EE28 0042EE28 00000000 */   nop
  .L0042EE2C:
    /* 32EE2C 0042EE2C F8B7100C */  jal        func_0042dfe0
    /* 32EE30 0042EE30 7100133C */   lui       $19, %hi(D_0070DCEC)
    /* 32EE34 0042EE34 ECDC648E */  lw         $4, %lo(D_0070DCEC)($19)
    /* 32EE38 0042EE38 0C86100C */  jal        func_00421830
    /* 32EE3C 0042EE3C 00000000 */   nop
    /* 32EE40 0042EE40 ECDC638E */  lw         $3, %lo(D_0070DCEC)($19)
    /* 32EE44 0042EE44 5B006214 */  bne        $3, $2, .L0042EFB4
    /* 32EE48 0042EE48 06000224 */   addiu     $2, $0, 0x6
    /* 32EE4C 0042EE4C 1ABA100C */  jal        func_0042e868
    /* 32EE50 0042EE50 01000424 */   addiu     $4, $0, 0x1
    /* 32EE54 0042EE54 45004014 */  bnez       $2, .L0042EF6C
    /* 32EE58 0042EE58 2D200000 */   daddu     $4, $0, $0
    /* 32EE5C 0042EE5C CA93100C */  jal        func_00424f28
    /* 32EE60 0042EE60 7100113C */   lui       $17, %hi(D_0070DD10)
    /* 32EE64 0042EE64 10DD228E */  lw         $2, %lo(D_0070DD10)($17)
    /* 32EE68 0042EE68 2C004104 */  bgez       $2, .L0042EF1C
    /* 32EE6C 0042EE6C 8900153C */   lui       $21, %hi(D_00894ED0)
    /* 32EE70 0042EE70 8900143C */  lui        $20, %hi(D_00894F10)
    /* 32EE74 0042EE74 0B000010 */  b          .L0042EEA4
    /* 32EE78 0042EE78 7100173C */   lui       $23, %hi(D_0070EEC0)
    /* 32EE7C 0042EE7C 00000000 */  nop
  .L0042EE80:
    /* 32EE80 0042EE80 FFFF0324 */  addiu      $3, $0, -0x1
    /* 32EE84 0042EE84 00000000 */  nop
  .L0042EE88:
    /* 32EE88 0042EE88 FFFF4224 */  addiu      $2, $2, %lo(D_FFFFF)
    /* 32EE8C 0042EE8C 00000000 */  nop
    /* 32EE90 0042EE90 00000000 */  nop
    /* 32EE94 0042EE94 00000000 */  nop
    /* 32EE98 0042EE98 00000000 */  nop
    /* 32EE9C 0042EE9C FAFF4314 */  bne        $2, $3, .L0042EE88
    /* 32EEA0 0042EEA0 00000000 */   nop
  .L0042EEA4:
    /* 32EEA4 0042EEA4 D04EB026 */  addiu      $16, $21, %lo(D_00894ED0)
  .L0042EEA8:
    /* 32EEA8 0042EEA8 0080053C */  lui        $5, (0x8000059A >> 16)
    /* 32EEAC 0042EEAC 2D200002 */  daddu      $4, $16, $0
    /* 32EEB0 0042EEB0 9A05A534 */  ori        $5, $5, (0x8000059A & 0xFFFF)
    /* 32EEB4 0042EEB4 B495100C */  jal        func_004256d0
    /* 32EEB8 0042EEB8 2D300000 */   daddu     $6, $0, $0
    /* 32EEBC 0042EEBC 13004304 */  bgezl      $2, .L0042EF0C
    /* 32EEC0 0042EEC0 2400028E */   lw        $2, 0x24($16)
    /* 32EEC4 0042EEC4 D0DCC28E */  lw         $2, %lo(D_0070DCD0)($22)
    /* 32EEC8 0042EEC8 05004018 */  blez       $2, .L0042EEE0
    /* 32EECC 0042EECC 1000023C */   lui       $2, %hi(D_FFFFF)
    /* 32EED0 0042EED0 7500043C */  lui        $4, %hi(D_00754678)
    /* 32EED4 0042EED4 3291100C */  jal        func_004244c8
    /* 32EED8 0042EED8 78468424 */   addiu     $4, $4, %lo(D_00754678)
    /* 32EEDC 0042EEDC 1000023C */  lui        $2, (0x100000 >> 16)
  .L0042EEE0:
    /* 32EEE0 0042EEE0 FFFF0324 */  addiu      $3, $0, -0x1
    /* 32EEE4 0042EEE4 00000000 */  nop
  .L0042EEE8:
    /* 32EEE8 0042EEE8 FFFF4224 */  addiu      $2, $2, %lo(D_FFFFF)
    /* 32EEEC 0042EEEC 00000000 */  nop
    /* 32EEF0 0042EEF0 00000000 */  nop
    /* 32EEF4 0042EEF4 00000000 */  nop
    /* 32EEF8 0042EEF8 00000000 */  nop
    /* 32EEFC 0042EEFC FAFF4314 */  bne        $2, $3, .L0042EEE8
    /* 32EF00 0042EF00 00000000 */   nop
    /* 32EF04 0042EF04 E8FF0010 */  b          .L0042EEA8
    /* 32EF08 0042EF08 D04EB026 */   addiu     $16, $21, %lo(D_00894ED0)
  .L0042EF0C:
    /* 32EF0C 0042EF0C DCFF4010 */  beqz       $2, .L0042EE80
    /* 32EF10 0042EF10 1000023C */   lui       $2, %hi(D_FFFFF)
    /* 32EF14 0042EF14 03000010 */  b          .L0042EF24
    /* 32EF18 0042EF18 10DD20AE */   sw        $0, %lo(D_0070DD10)($17)
  .L0042EF1C:
    /* 32EF1C 0042EF1C 8900143C */  lui        $20, %hi(D_00894F10)
    /* 32EF20 0042EF20 7100173C */  lui        $23, %hi(D_0070EEC0)
  .L0042EF24:
    /* 32EF24 0042EF24 104F9026 */  addiu      $16, $20, %lo(D_00894F10)
    /* 32EF28 0042EF28 104F92AE */  sw         $18, %lo(D_00894F10)($20)
    /* 32EF2C 0042EF2C 2D200002 */  daddu      $4, $16, $0
    /* 32EF30 0042EF30 9E93100C */  jal        func_00424e78
    /* 32EF34 0042EF34 04000524 */   addiu     $5, $0, 0x4
    /* 32EF38 0042EF38 C0EEF126 */  addiu      $17, $23, %lo(D_0070EEC0)
    /* 32EF3C 0042EF3C D04EA426 */  addiu      $4, $21, %lo(D_00894ED0)
    /* 32EF40 0042EF40 2D380002 */  daddu      $7, $16, $0
    /* 32EF44 0042EF44 0000A0AF */  sw         $0, 0x0($29)
    /* 32EF48 0042EF48 2D280000 */  daddu      $5, $0, $0
    /* 32EF4C 0042EF4C 2D300000 */  daddu      $6, $0, $0
    /* 32EF50 0042EF50 04000824 */  addiu      $8, $0, 0x4
    /* 32EF54 0042EF54 2D482002 */  daddu      $9, $17, $0
    /* 32EF58 0042EF58 04000A24 */  addiu      $10, $0, 0x4
    /* 32EF5C 0042EF5C 2C96100C */  jal        func_004258b0
    /* 32EF60 0042EF60 2D580000 */   daddu     $11, $0, $0
    /* 32EF64 0042EF64 09004304 */  bgezl      $2, .L0042EF8C
    /* 32EF68 0042EF68 D0DCC28E */   lw        $2, %lo(D_0070DCD0)($22)
  .L0042EF6C:
    /* 32EF6C 0042EF6C ECDC648E */  lw         $4, %lo(D_0070DCEC)($19)
    /* 32EF70 0042EF70 0086100C */  jal        func_00421800
    /* 32EF74 0042EF74 00000000 */   nop
    /* 32EF78 0042EF78 0800443A */  xori       $4, $18, 0x8
    /* 32EF7C 0042EF7C FFFF0324 */  addiu      $3, $0, -0x1
    /* 32EF80 0042EF80 06000224 */  addiu      $2, $0, 0x6
    /* 32EF84 0042EF84 0B000010 */  b          .L0042EFB4
    /* 32EF88 0042EF88 0A106400 */   movz      $2, $3, $4
  .L0042EF8C:
    /* 32EF8C 0042EF8C 03004018 */  blez       $2, .L0042EF9C
    /* 32EF90 0042EF90 7500043C */   lui       $4, %hi(D_00754698)
    /* 32EF94 0042EF94 3291100C */  jal        func_004244c8
    /* 32EF98 0042EF98 98468424 */   addiu     $4, $4, %lo(D_00754698)
  .L0042EF9C:
    /* 32EF9C 0042EF9C 0020023C */  lui        $2, (0x20000000 >> 16)
    /* 32EFA0 0042EFA0 ECDC648E */  lw         $4, %lo(D_0070DCEC)($19)
    /* 32EFA4 0042EFA4 25102202 */  or         $2, $17, $2
    /* 32EFA8 0042EFA8 0086100C */  jal        func_00421800
    /* 32EFAC 0042EFAC 0000508C */   lw        $16, (0x20000000 & 0xFFFF)($2)
    /* 32EFB0 0042EFB0 2D100002 */  daddu      $2, $16, $0
  .L0042EFB4:
    /* 32EFB4 0042EFB4 9000BFDF */  ld         $31, 0x90($29)
    /* 32EFB8 0042EFB8 8000B7DF */  ld         $23, 0x80($29)
    /* 32EFBC 0042EFBC 7000B6DF */  ld         $22, 0x70($29)
    /* 32EFC0 0042EFC0 6000B5DF */  ld         $21, 0x60($29)
    /* 32EFC4 0042EFC4 5000B4DF */  ld         $20, 0x50($29)
    /* 32EFC8 0042EFC8 4000B3DF */  ld         $19, 0x40($29)
    /* 32EFCC 0042EFCC 3000B2DF */  ld         $18, 0x30($29)
    /* 32EFD0 0042EFD0 2000B1DF */  ld         $17, 0x20($29)
    /* 32EFD4 0042EFD4 1000B0DF */  ld         $16, 0x10($29)
    /* 32EFD8 0042EFD8 0800E003 */  jr         $31
    /* 32EFDC 0042EFDC A000BD27 */   addiu     $29, $29, 0xA0
.size func_0042edc8, 0x218
