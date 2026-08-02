.section .text
.set noat
.set noreorder
glabel func_004aed70
    /* 3AED70 004AED70 D0FDBD27 */  addiu      $29, $29, -0x230
    /* 3AED74 004AED74 9000BFFF */  sd         $31, 0x90($29)
    /* 3AED78 004AED78 8000B67F */  sq         $22, 0x80($29)
    /* 3AED7C 004AED7C 7000B57F */  sq         $21, 0x70($29)
    /* 3AED80 004AED80 6000B47F */  sq         $20, 0x60($29)
    /* 3AED84 004AED84 5000B37F */  sq         $19, 0x50($29)
    /* 3AED88 004AED88 4000B27F */  sq         $18, 0x40($29)
    /* 3AED8C 004AED8C 3000B17F */  sq         $17, 0x30($29)
    /* 3AED90 004AED90 2000B07F */  sq         $16, 0x20($29)
    /* 3AED94 004AED94 1800BAE7 */  swc1       $f26, 0x18($29)
    /* 3AED98 004AED98 1400B9E7 */  swc1       $f25, 0x14($29)
    /* 3AED9C 004AED9C 1000B8E7 */  swc1       $f24, 0x10($29)
    /* 3AEDA0 004AEDA0 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 3AEDA4 004AEDA4 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 3AEDA8 004AEDA8 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 3AEDAC 004AEDAC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3AEDB0 004AEDB0 2D988000 */  daddu      $19, $4, $0
    /* 3AEDB4 004AEDB4 0400828C */  lw         $2, 0x4($4)
    /* 3AEDB8 004AEDB8 2802A2AF */  sw         $2, 0x228($29)
    /* 3AEDBC 004AEDBC 2802A227 */  addiu      $2, $29, 0x228
    /* 3AEDC0 004AEDC0 F48199C7 */  lwc1       $f25, -0x7E0C($28)
    /* 3AEDC4 004AEDC4 0000428C */  lw         $2, 0x0($2)
    /* 3AEDC8 004AEDC8 88160270 */  pextlb     $2, $0, $2
    /* 3AEDCC 004AEDCC 88150270 */  pextlh     $2, $0, $2
    /* 3AEDD0 004AEDD0 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AEDD4 004AEDD4 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AEDD8 004AEDD8 00C80344 */  mfc1       $3, $f25
    /* 3AEDDC 004AEDDC 00000000 */  nop
    /* 3AEDE0 004AEDE0 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AEDE4 004AEDE4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AEDE8 004AEDE8 C001A327 */  addiu      $3, $29, 0x1C0
    /* 3AEDEC 004AEDEC 00006AF8 */  sqc2       $vf10, 0x0($3)
    /* 3AEDF0 004AEDF0 5800848C */  lw         $4, 0x58($4)
    /* 3AEDF4 004AEDF4 0800958C */  lw         $21, 0x8($4)
    /* 3AEDF8 004AEDF8 B601A012 */  beqz       $21, .L004AF4D4
    /* 3AEDFC 004AEDFC 00000000 */   nop
    /* 3AEE00 004AEE00 1000838C */  lw         $3, 0x10($4)
    /* 3AEE04 004AEE04 B3016010 */  beqz       $3, .L004AF4D4
    /* 3AEE08 004AEE08 00000000 */   nop
    /* 3AEE0C 004AEE0C 1800928C */  lw         $18, 0x18($4)
    /* 3AEE10 004AEE10 5C00718E */  lw         $17, 0x5C($19)
    /* 3AEE14 004AEE14 5400708E */  lw         $16, 0x54($19)
    /* 3AEE18 004AEE18 080061C6 */  lwc1       $f1, 0x8($19)
    /* 3AEE1C 004AEE1C 00008044 */  mtc1       $0, $f0
    /* 3AEE20 004AEE20 00000000 */  nop
    /* 3AEE24 004AEE24 32000146 */  c.eq.s     $f0, $f1
    /* 3AEE28 004AEE28 0A000145 */  bc1t       .L004AEE54
    /* 3AEE2C 004AEE2C 00000000 */   nop
    /* 3AEE30 004AEE30 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AEE34 004AEE34 00A88244 */  mtc1       $2, $f21
    /* 3AEE38 004AEE38 00000000 */  nop
    /* 3AEE3C 004AEE3C 83AE0146 */  div.s      $f26, $f21, $f1
    /* 3AEE40 004AEE40 00000000 */  nop
    /* 3AEE44 004AEE44 00000000 */  nop
    /* 3AEE48 004AEE48 00000000 */  nop
    /* 3AEE4C 004AEE4C 05000010 */  b          .L004AEE64
    /* 3AEE50 004AEE50 00000000 */   nop
  .L004AEE54:
    /* 3AEE54 004AEE54 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AEE58 004AEE58 00A88244 */  mtc1       $2, $f21
    /* 3AEE5C 004AEE5C 00000000 */  nop
    /* 3AEE60 004AEE60 86AE0046 */  mov.s      $f26, $f21
  .L004AEE64:
    /* 3AEE64 004AEE64 0C006396 */  lhu        $3, 0xC($19)
    /* 3AEE68 004AEE68 03000224 */  addiu      $2, $0, 0x3
    /* 3AEE6C 004AEE6C 03006210 */  beq        $3, $2, .L004AEE7C
    /* 3AEE70 004AEE70 00000000 */   nop
    /* 3AEE74 004AEE74 90010010 */  b          .L004AF4B8
    /* 3AEE78 004AEE78 00000000 */   nop
  .L004AEE7C:
    /* 3AEE7C 004AEE7C 0C00828C */  lw         $2, 0xC($4)
    /* 3AEE80 004AEE80 01004230 */  andi       $2, $2, 0x1
    /* 3AEE84 004AEE84 C7004014 */  bnez       $2, .L004AF1A4
    /* 3AEE88 004AEE88 00000000 */   nop
    /* 3AEE8C 004AEE8C A001A527 */  addiu      $5, $29, 0x1A0
    /* 3AEE90 004AEE90 7C4B120C */  jal        func_00492df0
    /* 3AEE94 004AEE94 00000000 */   nop
    /* 3AEE98 004AEE98 A001A227 */  addiu      $2, $29, 0x1A0
    /* 3AEE9C 004AEE9C 00004AD8 */  lqc2       $vf10, 0x0($2)
    /* 3AEEA0 004AEEA0 ACF3120C */  jal        func_004bceb0
    /* 3AEEA4 004AEEA4 00000000 */   nop
    /* 3AEEA8 004AEEA8 6001A227 */  addiu      $2, $29, 0x160
    /* 3AEEAC 004AEEAC 00005CF8 */  sqc2       $vf28, 0x0($2)
    /* 3AEEB0 004AEEB0 10005DF8 */  sqc2       $vf29, 0x10($2)
    /* 3AEEB4 004AEEB4 20005EF8 */  sqc2       $vf30, 0x20($2)
    /* 3AEEB8 004AEEB8 30005FF8 */  sqc2       $vf31, 0x30($2)
    /* 3AEEBC 004AEEBC 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* 3AEEC0 004AEEC0 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* 3AEEC4 004AEEC4 6401A0C7 */  lwc1       $f0, 0x164($29)
    /* 3AEEC8 004AEEC8 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* 3AEECC 004AEECC 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* 3AEED0 004AEED0 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* 3AEED4 004AEED4 7001A0C7 */  lwc1       $f0, 0x170($29)
    /* 3AEED8 004AEED8 F000A0E7 */  swc1       $f0, 0xF0($29)
    /* 3AEEDC 004AEEDC 7401A0C7 */  lwc1       $f0, 0x174($29)
    /* 3AEEE0 004AEEE0 F400A0E7 */  swc1       $f0, 0xF4($29)
    /* 3AEEE4 004AEEE4 7801A0C7 */  lwc1       $f0, 0x178($29)
    /* 3AEEE8 004AEEE8 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* 3AEEEC 004AEEEC 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* 3AEEF0 004AEEF0 0001A0E7 */  swc1       $f0, 0x100($29)
    /* 3AEEF4 004AEEF4 8401A0C7 */  lwc1       $f0, 0x184($29)
    /* 3AEEF8 004AEEF8 0401A0E7 */  swc1       $f0, 0x104($29)
    /* 3AEEFC 004AEEFC 8801A0C7 */  lwc1       $f0, 0x188($29)
    /* 3AEF00 004AEF00 0801A0E7 */  swc1       $f0, 0x108($29)
    /* 3AEF04 004AEF04 9001A0C7 */  lwc1       $f0, 0x190($29)
    /* 3AEF08 004AEF08 1001A0E7 */  swc1       $f0, 0x110($29)
    /* 3AEF0C 004AEF0C 9401A0C7 */  lwc1       $f0, 0x194($29)
    /* 3AEF10 004AEF10 1401A0E7 */  swc1       $f0, 0x114($29)
    /* 3AEF14 004AEF14 9801A0C7 */  lwc1       $f0, 0x198($29)
    /* 3AEF18 004AEF18 1801A0E7 */  swc1       $f0, 0x118($29)
    /* 3AEF1C 004AEF1C 2DA00000 */  daddu      $20, $0, $0
    /* 3AEF20 004AEF20 9B000010 */  b          .L004AF190
    /* 3AEF24 004AEF24 00000000 */   nop
  .L004AEF28:
    /* 3AEF28 004AEF28 1000468E */  lw         $6, 0x10($18)
    /* 3AEF2C 004AEF2C 9500C004 */  bltz       $6, .L004AF184
    /* 3AEF30 004AEF30 00000000 */   nop
    /* 3AEF34 004AEF34 1400428E */  lw         $2, 0x14($18)
    /* 3AEF38 004AEF38 2402A2AF */  sw         $2, 0x224($29)
    /* 3AEF3C 004AEF3C 2402A227 */  addiu      $2, $29, 0x224
    /* 3AEF40 004AEF40 0000428C */  lw         $2, 0x0($2)
    /* 3AEF44 004AEF44 88160270 */  pextlb     $2, $0, $2
    /* 3AEF48 004AEF48 88150270 */  pextlh     $2, $0, $2
    /* 3AEF4C 004AEF4C 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AEF50 004AEF50 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AEF54 004AEF54 00C80244 */  mfc1       $2, $f25
    /* 3AEF58 004AEF58 00000000 */  nop
    /* 3AEF5C 004AEF5C 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AEF60 004AEF60 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AEF64 004AEF64 C001A227 */  addiu      $2, $29, 0x1C0
    /* 3AEF68 004AEF68 00004BD8 */  lqc2       $vf11, 0x0($2)
    /* 3AEF6C 004AEF6C AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AEF70 004AEF70 14002282 */  lb         $2, 0x14($17)
    /* 3AEF74 004AEF74 05004004 */  bltz       $2, .L004AEF8C
    /* 3AEF78 004AEF78 00000000 */   nop
    /* 3AEF7C 004AEF7C 2D206002 */  daddu      $4, $19, $0
    /* 3AEF80 004AEF80 2D282002 */  daddu      $5, $17, $0
    /* 3AEF84 004AEF84 BCB8120C */  jal        func_004ae2f0
    /* 3AEF88 004AEF88 00000000 */   nop
  .L004AEF8C:
    /* 3AEF8C 004AEF8C 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3AEF90 004AEF90 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AEF94 004AEF94 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AEF98 004AEF98 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AEF9C 004AEF9C 00502248 */  qmfc2.ni   $2, $vf10
    /* 3AEFA0 004AEFA0 C8150270 */  ppach      $2, $0, $2
    /* 3AEFA4 004AEFA4 C8160270 */  ppacb      $2, $0, $2
    /* 3AEFA8 004AEFA8 1C02A2AF */  sw         $2, 0x21C($29)
    /* 3AEFAC 004AEFAC 1C02A28F */  lw         $2, 0x21C($29)
    /* 3AEFB0 004AEFB0 2C02A2AF */  sw         $2, 0x22C($29)
    /* 3AEFB4 004AEFB4 2D200002 */  daddu      $4, $16, $0
    /* 3AEFB8 004AEFB8 4B00053C */  lui        $5, %hi(func_004ae020)
    /* 3AEFBC 004AEFBC 20E0A524 */  addiu      $5, $5, %lo(func_004ae020)
    /* 3AEFC0 004AEFC0 2C02A627 */  addiu      $6, $29, 0x22C
    /* 3AEFC4 004AEFC4 CCFF0E0C */  jal        func_003bff30
    /* 3AEFC8 004AEFC8 00000000 */   nop
    /* 3AEFCC 004AEFCC 100040C6 */  lwc1       $f0, 0x10($18)
    /* 3AEFD0 004AEFD0 60008046 */  cvt.s.w    $f1, $f0
    /* 3AEFD4 004AEFD4 100020C6 */  lwc1       $f0, 0x10($17)
    /* 3AEFD8 004AEFD8 1A000146 */  mula.s     $f0, $f1
    /* 3AEFDC 004AEFDC 2C0060C6 */  lwc1       $f0, 0x2C($19)
    /* 3AEFE0 004AEFE0 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AEFE4 004AEFE4 82080046 */  mul.s      $f2, $f1, $f0
    /* 3AEFE8 004AEFE8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3AEFEC 004AEFEC 00088244 */  mtc1       $2, $f1
    /* 3AEFF0 004AEFF0 00008044 */  mtc1       $0, $f0
    /* 3AEFF4 004AEFF4 00000000 */  nop
    /* 3AEFF8 004AEFF8 5C080246 */  madd.s     $f1, $f1, $f2
    /* 3AEFFC 004AEFFC 34080046 */  c.lt.s     $f1, $f0
    /* 3AF000 004AF000 14000045 */  bc1f       .L004AF054
    /* 3AF004 004AF004 00000000 */   nop
    /* 3AF008 004AF008 C800B5E7 */  swc1       $f21, 0xC8($29)
    /* 3AF00C 004AF00C B400B5E7 */  swc1       $f21, 0xB4($29)
    /* 3AF010 004AF010 A000B5E7 */  swc1       $f21, 0xA0($29)
    /* 3AF014 004AF014 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* 3AF018 004AF018 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 3AF01C 004AF01C A400A0E7 */  swc1       $f0, 0xA4($29)
    /* 3AF020 004AF020 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* 3AF024 004AF024 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* 3AF028 004AF028 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* 3AF02C 004AF02C D800A0E7 */  swc1       $f0, 0xD8($29)
    /* 3AF030 004AF030 D400A0E7 */  swc1       $f0, 0xD4($29)
    /* 3AF034 004AF034 D000A0E7 */  swc1       $f0, 0xD0($29)
    /* 3AF038 004AF038 AC00A38F */  lw         $3, 0xAC($29)
    /* 3AF03C 004AF03C 0200023C */  lui        $2, (0x20003 >> 16)
    /* 3AF040 004AF040 03004234 */  ori        $2, $2, (0x20003 & 0xFFFF)
    /* 3AF044 004AF044 25106200 */  or         $2, $3, $2
    /* 3AF048 004AF048 AC00A2AF */  sw         $2, 0xAC($29)
    /* 3AF04C 004AF04C 10000010 */  b          .L004AF090
    /* 3AF050 004AF050 00000000 */   nop
  .L004AF054:
    /* 3AF054 004AF054 000020C6 */  lwc1       $f0, 0x0($17)
    /* 3AF058 004AF058 E801A0E7 */  swc1       $f0, 0x1E8($29)
    /* 3AF05C 004AF05C 040020C6 */  lwc1       $f0, 0x4($17)
    /* 3AF060 004AF060 EC01A0E7 */  swc1       $f0, 0x1EC($29)
    /* 3AF064 004AF064 080020C6 */  lwc1       $f0, 0x8($17)
    /* 3AF068 004AF068 F001A0E7 */  swc1       $f0, 0x1F0($29)
    /* 3AF06C 004AF06C 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* 3AF070 004AF070 40080046 */  add.s      $f1, $f1, $f0
    /* 3AF074 004AF074 488080C7 */  lwc1       $f0, -0x7FB8($28)
    /* 3AF078 004AF078 02030146 */  mul.s      $f12, $f0, $f1
    /* 3AF07C 004AF07C A000A427 */  addiu      $4, $29, 0xA0
    /* 3AF080 004AF080 E801A527 */  addiu      $5, $29, 0x1E8
    /* 3AF084 004AF084 2D300000 */  daddu      $6, $0, $0
    /* 3AF088 004AF088 1C820F0C */  jal        func_003e0870
    /* 3AF08C 004AF08C 00000000 */   nop
  .L004AF090:
    /* 3AF090 004AF090 2001A427 */  addiu      $4, $29, 0x120
    /* 3AF094 004AF094 A000A527 */  addiu      $5, $29, 0xA0
    /* 3AF098 004AF098 E000A627 */  addiu      $6, $29, 0xE0
    /* 3AF09C 004AF09C 7C810F0C */  jal        func_003e05f0
    /* 3AF0A0 004AF0A0 00000000 */   nop
    /* 3AF0A4 004AF0A4 30006296 */  lhu        $2, 0x30($19)
    /* 3AF0A8 004AF0A8 10004014 */  bnez       $2, .L004AF0EC
    /* 3AF0AC 004AF0AC 00000000 */   nop
    /* 3AF0B0 004AF0B0 7100023C */  lui        $2, %hi(D_00713D20)
    /* 3AF0B4 004AF0B4 203D40C4 */  lwc1       $f0, %lo(D_00713D20)($2)
    /* 3AF0B8 004AF0B8 180041C6 */  lwc1       $f1, 0x18($18)
    /* 3AF0BC 004AF0BC 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF0C0 004AF0C0 0802A0E7 */  swc1       $f0, 0x208($29)
    /* 3AF0C4 004AF0C4 7100023C */  lui        $2, %hi(D_00713D24)
    /* 3AF0C8 004AF0C8 243D40C4 */  lwc1       $f0, %lo(D_00713D24)($2)
    /* 3AF0CC 004AF0CC 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF0D0 004AF0D0 0C02A0E7 */  swc1       $f0, 0x20C($29)
    /* 3AF0D4 004AF0D4 7100023C */  lui        $2, %hi(D_00713D28)
    /* 3AF0D8 004AF0D8 283D40C4 */  lwc1       $f0, %lo(D_00713D28)($2)
    /* 3AF0DC 004AF0DC 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF0E0 004AF0E0 1002A0E7 */  swc1       $f0, 0x210($29)
    /* 3AF0E4 004AF0E4 0F000010 */  b          .L004AF124
    /* 3AF0E8 004AF0E8 00000000 */   nop
  .L004AF0EC:
    /* 3AF0EC 004AF0EC 180040C6 */  lwc1       $f0, 0x18($18)
    /* 3AF0F0 004AF0F0 42001A46 */  mul.s      $f1, $f0, $f26
    /* 3AF0F4 004AF0F4 7100023C */  lui        $2, %hi(D_00713D20)
    /* 3AF0F8 004AF0F8 203D40C4 */  lwc1       $f0, %lo(D_00713D20)($2)
    /* 3AF0FC 004AF0FC 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF100 004AF100 0802A0E7 */  swc1       $f0, 0x208($29)
    /* 3AF104 004AF104 7100023C */  lui        $2, %hi(D_00713D24)
    /* 3AF108 004AF108 243D40C4 */  lwc1       $f0, %lo(D_00713D24)($2)
    /* 3AF10C 004AF10C 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF110 004AF110 0C02A0E7 */  swc1       $f0, 0x20C($29)
    /* 3AF114 004AF114 7100023C */  lui        $2, %hi(D_00713D28)
    /* 3AF118 004AF118 283D40C4 */  lwc1       $f0, %lo(D_00713D28)($2)
    /* 3AF11C 004AF11C 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF120 004AF120 1002A0E7 */  swc1       $f0, 0x210($29)
  .L004AF124:
    /* 3AF124 004AF124 2001A427 */  addiu      $4, $29, 0x120
    /* 3AF128 004AF128 0802A527 */  addiu      $5, $29, 0x208
    /* 3AF12C 004AF12C 02000624 */  addiu      $6, $0, 0x2
    /* 3AF130 004AF130 A4820F0C */  jal        func_003e0a90
    /* 3AF134 004AF134 00000000 */   nop
    /* 3AF138 004AF138 000040C6 */  lwc1       $f0, 0x0($18)
    /* 3AF13C 004AF13C 0802A0E7 */  swc1       $f0, 0x208($29)
    /* 3AF140 004AF140 040040C6 */  lwc1       $f0, 0x4($18)
    /* 3AF144 004AF144 0C02A0E7 */  swc1       $f0, 0x20C($29)
    /* 3AF148 004AF148 080040C6 */  lwc1       $f0, 0x8($18)
    /* 3AF14C 004AF14C 1002A0E7 */  swc1       $f0, 0x210($29)
    /* 3AF150 004AF150 2001A427 */  addiu      $4, $29, 0x120
    /* 3AF154 004AF154 0802A527 */  addiu      $5, $29, 0x208
    /* 3AF158 004AF158 02000624 */  addiu      $6, $0, 0x2
    /* 3AF15C 004AF15C 24830F0C */  jal        func_003e0c90
    /* 3AF160 004AF160 00000000 */   nop
    /* 3AF164 004AF164 0400048E */  lw         $4, 0x4($16)
    /* 3AF168 004AF168 2001A527 */  addiu      $5, $29, 0x120
    /* 3AF16C 004AF16C 2D300000 */  daddu      $6, $0, $0
    /* 3AF170 004AF170 2CA70F0C */  jal        func_003e9cb0
    /* 3AF174 004AF174 00000000 */   nop
    /* 3AF178 004AF178 2D200002 */  daddu      $4, $16, $0
    /* 3AF17C 004AF17C A4FF0E0C */  jal        func_003bfe90
    /* 3AF180 004AF180 00000000 */   nop
  .L004AF184:
    /* 3AF184 004AF184 01009426 */  addiu      $20, $20, 0x1
    /* 3AF188 004AF188 20005226 */  addiu      $18, $18, 0x20
    /* 3AF18C 004AF18C 18003126 */  addiu      $17, $17, 0x18
  .L004AF190:
    /* 3AF190 004AF190 2A109502 */  slt        $2, $20, $21
    /* 3AF194 004AF194 64FF4014 */  bnez       $2, .L004AEF28
    /* 3AF198 004AF198 00000000 */   nop
    /* 3AF19C 004AF19C CB000010 */  b          .L004AF4CC
    /* 3AF1A0 004AF1A0 00000000 */   nop
  .L004AF1A4:
    /* 3AF1A4 004AF1A4 A001A527 */  addiu      $5, $29, 0x1A0
    /* 3AF1A8 004AF1A8 7C4B120C */  jal        func_00492df0
    /* 3AF1AC 004AF1AC 00000000 */   nop
    /* 3AF1B0 004AF1B0 5800648E */  lw         $4, 0x58($19)
    /* 3AF1B4 004AF1B4 B001A527 */  addiu      $5, $29, 0x1B0
    /* 3AF1B8 004AF1B8 6C4B120C */  jal        func_00492db0
    /* 3AF1BC 004AF1BC 00000000 */   nop
    /* 3AF1C0 004AF1C0 A001A227 */  addiu      $2, $29, 0x1A0
    /* 3AF1C4 004AF1C4 00004AD8 */  lqc2       $vf10, 0x0($2)
    /* 3AF1C8 004AF1C8 ACF3120C */  jal        func_004bceb0
    /* 3AF1CC 004AF1CC 00000000 */   nop
    /* 3AF1D0 004AF1D0 B001A227 */  addiu      $2, $29, 0x1B0
    /* 3AF1D4 004AF1D4 00005FD8 */  lqc2       $vf31, 0x0($2)
    /* 3AF1D8 004AF1D8 6001A227 */  addiu      $2, $29, 0x160
    /* 3AF1DC 004AF1DC 00005CF8 */  sqc2       $vf28, 0x0($2)
    /* 3AF1E0 004AF1E0 10005DF8 */  sqc2       $vf29, 0x10($2)
    /* 3AF1E4 004AF1E4 20005EF8 */  sqc2       $vf30, 0x20($2)
    /* 3AF1E8 004AF1E8 30005FF8 */  sqc2       $vf31, 0x30($2)
    /* 3AF1EC 004AF1EC 2DA00000 */  daddu      $20, $0, $0
    /* 3AF1F0 004AF1F0 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3AF1F4 004AF1F4 00C08244 */  mtc1       $2, $f24
    /* 3AF1F8 004AF1F8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3AF1FC 004AF1FC 00B88244 */  mtc1       $2, $f23
    /* 3AF200 004AF200 00B08044 */  mtc1       $0, $f22
    /* 3AF204 004AF204 0200023C */  lui        $2, (0x20003 >> 16)
    /* 3AF208 004AF208 03005634 */  ori        $22, $2, (0x20003 & 0xFFFF)
    /* 3AF20C 004AF20C 488094C7 */  lwc1       $f20, -0x7FB8($28)
    /* 3AF210 004AF210 A4000010 */  b          .L004AF4A4
    /* 3AF214 004AF214 00000000 */   nop
  .L004AF218:
    /* 3AF218 004AF218 1000428E */  lw         $2, 0x10($18)
    /* 3AF21C 004AF21C 9E004004 */  bltz       $2, .L004AF498
    /* 3AF220 004AF220 00000000 */   nop
    /* 3AF224 004AF224 6001A227 */  addiu      $2, $29, 0x160
    /* 3AF228 004AF228 00005CD8 */  lqc2       $vf28, 0x0($2)
    /* 3AF22C 004AF22C 10005DD8 */  lqc2       $vf29, 0x10($2)
    /* 3AF230 004AF230 20005ED8 */  lqc2       $vf30, 0x20($2)
    /* 3AF234 004AF234 30005FD8 */  lqc2       $vf31, 0x30($2)
    /* 3AF238 004AF238 00004ADA */  lqc2       $vf10, 0x0($18)
    /* 3AF23C 004AF23C BCE1EA4B */  vmulax.xyzw $ACC, $vf28, $vf10x
    /* 3AF240 004AF240 BDE8EA4B */  vmadday.xyzw $ACC, $vf29, $vf10y
    /* 3AF244 004AF244 BEF0EA4B */  vmaddaz.xyzw $ACC, $vf30, $vf10z
    /* 3AF248 004AF248 8BFAE04B */  vmaddw.xyzw $vf10, $vf31, $vf0w
    /* 3AF24C 004AF24C 7100023C */  lui        $2, %hi(D_00713D10)
    /* 3AF250 004AF250 103D4224 */  addiu      $2, $2, %lo(D_00713D10)
    /* 3AF254 004AF254 00004AF8 */  sqc2       $vf10, 0x0($2)
    /* 3AF258 004AF258 7100023C */  lui        $2, %hi(D_00713D10)
    /* 3AF25C 004AF25C 103D40C4 */  lwc1       $f0, %lo(D_00713D10)($2)
    /* 3AF260 004AF260 F801A0E7 */  swc1       $f0, 0x1F8($29)
    /* 3AF264 004AF264 7100023C */  lui        $2, %hi(D_00713D14)
    /* 3AF268 004AF268 143D40C4 */  lwc1       $f0, %lo(D_00713D14)($2)
    /* 3AF26C 004AF26C FC01A0E7 */  swc1       $f0, 0x1FC($29)
    /* 3AF270 004AF270 7100023C */  lui        $2, %hi(D_00713D18)
    /* 3AF274 004AF274 183D40C4 */  lwc1       $f0, %lo(D_00713D18)($2)
    /* 3AF278 004AF278 0002A0E7 */  swc1       $f0, 0x200($29)
    /* 3AF27C 004AF27C 1400428E */  lw         $2, 0x14($18)
    /* 3AF280 004AF280 2002A2AF */  sw         $2, 0x220($29)
    /* 3AF284 004AF284 2002A227 */  addiu      $2, $29, 0x220
    /* 3AF288 004AF288 0000428C */  lw         $2, 0x0($2)
    /* 3AF28C 004AF28C 88160270 */  pextlb     $2, $0, $2
    /* 3AF290 004AF290 88150270 */  pextlh     $2, $0, $2
    /* 3AF294 004AF294 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AF298 004AF298 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AF29C 004AF29C 00C80244 */  mfc1       $2, $f25
    /* 3AF2A0 004AF2A0 00000000 */  nop
    /* 3AF2A4 004AF2A4 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AF2A8 004AF2A8 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AF2AC 004AF2AC C001A227 */  addiu      $2, $29, 0x1C0
    /* 3AF2B0 004AF2B0 00004BD8 */  lqc2       $vf11, 0x0($2)
    /* 3AF2B4 004AF2B4 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AF2B8 004AF2B8 14002282 */  lb         $2, 0x14($17)
    /* 3AF2BC 004AF2BC 06004004 */  bltz       $2, .L004AF2D8
    /* 3AF2C0 004AF2C0 00000000 */   nop
    /* 3AF2C4 004AF2C4 2D206002 */  daddu      $4, $19, $0
    /* 3AF2C8 004AF2C8 2D282002 */  daddu      $5, $17, $0
    /* 3AF2CC 004AF2CC 1000468E */  lw         $6, 0x10($18)
    /* 3AF2D0 004AF2D0 BCB8120C */  jal        func_004ae2f0
    /* 3AF2D4 004AF2D4 00000000 */   nop
  .L004AF2D8:
    /* 3AF2D8 004AF2D8 00C00244 */  mfc1       $2, $f24
    /* 3AF2DC 004AF2DC 00000000 */  nop
    /* 3AF2E0 004AF2E0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AF2E4 004AF2E4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AF2E8 004AF2E8 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AF2EC 004AF2EC 00502248 */  qmfc2.ni   $2, $vf10
    /* 3AF2F0 004AF2F0 C8150270 */  ppach      $2, $0, $2
    /* 3AF2F4 004AF2F4 C8160270 */  ppacb      $2, $0, $2
    /* 3AF2F8 004AF2F8 1802A2AF */  sw         $2, 0x218($29)
    /* 3AF2FC 004AF2FC 1802A28F */  lw         $2, 0x218($29)
    /* 3AF300 004AF300 2C02A2AF */  sw         $2, 0x22C($29)
    /* 3AF304 004AF304 2D200002 */  daddu      $4, $16, $0
    /* 3AF308 004AF308 4B00053C */  lui        $5, %hi(func_004ae020)
    /* 3AF30C 004AF30C 20E0A524 */  addiu      $5, $5, %lo(func_004ae020)
    /* 3AF310 004AF310 2C02A627 */  addiu      $6, $29, 0x22C
    /* 3AF314 004AF314 CCFF0E0C */  jal        func_003bff30
    /* 3AF318 004AF318 00000000 */   nop
    /* 3AF31C 004AF31C 100040C6 */  lwc1       $f0, 0x10($18)
    /* 3AF320 004AF320 60008046 */  cvt.s.w    $f1, $f0
    /* 3AF324 004AF324 100020C6 */  lwc1       $f0, 0x10($17)
    /* 3AF328 004AF328 1A000146 */  mula.s     $f0, $f1
    /* 3AF32C 004AF32C 2C0060C6 */  lwc1       $f0, 0x2C($19)
    /* 3AF330 004AF330 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF334 004AF334 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AF338 004AF338 5CB80046 */  madd.s     $f1, $f23, $f0
    /* 3AF33C 004AF33C 34081646 */  c.lt.s     $f1, $f22
    /* 3AF340 004AF340 12000045 */  bc1f       .L004AF38C
    /* 3AF344 004AF344 00000000 */   nop
    /* 3AF348 004AF348 4801B5E7 */  swc1       $f21, 0x148($29)
    /* 3AF34C 004AF34C 3401B5E7 */  swc1       $f21, 0x134($29)
    /* 3AF350 004AF350 2001B5E7 */  swc1       $f21, 0x120($29)
    /* 3AF354 004AF354 3001B6E7 */  swc1       $f22, 0x130($29)
    /* 3AF358 004AF358 2801B6E7 */  swc1       $f22, 0x128($29)
    /* 3AF35C 004AF35C 2401B6E7 */  swc1       $f22, 0x124($29)
    /* 3AF360 004AF360 4401B6E7 */  swc1       $f22, 0x144($29)
    /* 3AF364 004AF364 4001B6E7 */  swc1       $f22, 0x140($29)
    /* 3AF368 004AF368 3801B6E7 */  swc1       $f22, 0x138($29)
    /* 3AF36C 004AF36C 5801B6E7 */  swc1       $f22, 0x158($29)
    /* 3AF370 004AF370 5401B6E7 */  swc1       $f22, 0x154($29)
    /* 3AF374 004AF374 5001B6E7 */  swc1       $f22, 0x150($29)
    /* 3AF378 004AF378 2C01A28F */  lw         $2, 0x12C($29)
    /* 3AF37C 004AF37C 25105600 */  or         $2, $2, $22
    /* 3AF380 004AF380 2C01A2AF */  sw         $2, 0x12C($29)
    /* 3AF384 004AF384 0F000010 */  b          .L004AF3C4
    /* 3AF388 004AF388 00000000 */   nop
  .L004AF38C:
    /* 3AF38C 004AF38C 000020C6 */  lwc1       $f0, 0x0($17)
    /* 3AF390 004AF390 D801A0E7 */  swc1       $f0, 0x1D8($29)
    /* 3AF394 004AF394 040020C6 */  lwc1       $f0, 0x4($17)
    /* 3AF398 004AF398 DC01A0E7 */  swc1       $f0, 0x1DC($29)
    /* 3AF39C 004AF39C 080020C6 */  lwc1       $f0, 0x8($17)
    /* 3AF3A0 004AF3A0 E001A0E7 */  swc1       $f0, 0x1E0($29)
    /* 3AF3A4 004AF3A4 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* 3AF3A8 004AF3A8 00080046 */  add.s      $f0, $f1, $f0
    /* 3AF3AC 004AF3AC 02A30046 */  mul.s      $f12, $f20, $f0
    /* 3AF3B0 004AF3B0 2001A427 */  addiu      $4, $29, 0x120
    /* 3AF3B4 004AF3B4 D801A527 */  addiu      $5, $29, 0x1D8
    /* 3AF3B8 004AF3B8 2D300000 */  daddu      $6, $0, $0
    /* 3AF3BC 004AF3BC 1C820F0C */  jal        func_003e0870
    /* 3AF3C0 004AF3C0 00000000 */   nop
  .L004AF3C4:
    /* 3AF3C4 004AF3C4 7100023C */  lui        $2, %hi(D_00713CE0)
    /* 3AF3C8 004AF3C8 E03C4224 */  addiu      $2, $2, %lo(D_00713CE0)
    /* 3AF3CC 004AF3CC 00004AD8 */  lqc2       $vf10, 0x0($2)
    /* 3AF3D0 004AF3D0 30006296 */  lhu        $2, 0x30($19)
    /* 3AF3D4 004AF3D4 10004014 */  bnez       $2, .L004AF418
    /* 3AF3D8 004AF3D8 00000000 */   nop
    /* 3AF3DC 004AF3DC 7100023C */  lui        $2, %hi(D_00713D20)
    /* 3AF3E0 004AF3E0 203D40C4 */  lwc1       $f0, %lo(D_00713D20)($2)
    /* 3AF3E4 004AF3E4 180041C6 */  lwc1       $f1, 0x18($18)
    /* 3AF3E8 004AF3E8 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF3EC 004AF3EC 0802A0E7 */  swc1       $f0, 0x208($29)
    /* 3AF3F0 004AF3F0 7100023C */  lui        $2, %hi(D_00713D24)
    /* 3AF3F4 004AF3F4 243D40C4 */  lwc1       $f0, %lo(D_00713D24)($2)
    /* 3AF3F8 004AF3F8 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF3FC 004AF3FC 0C02A0E7 */  swc1       $f0, 0x20C($29)
    /* 3AF400 004AF400 7100023C */  lui        $2, %hi(D_00713D28)
    /* 3AF404 004AF404 283D40C4 */  lwc1       $f0, %lo(D_00713D28)($2)
    /* 3AF408 004AF408 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF40C 004AF40C 1002A0E7 */  swc1       $f0, 0x210($29)
    /* 3AF410 004AF410 0F000010 */  b          .L004AF450
    /* 3AF414 004AF414 00000000 */   nop
  .L004AF418:
    /* 3AF418 004AF418 180040C6 */  lwc1       $f0, 0x18($18)
    /* 3AF41C 004AF41C 42001A46 */  mul.s      $f1, $f0, $f26
    /* 3AF420 004AF420 7100023C */  lui        $2, %hi(D_00713D20)
    /* 3AF424 004AF424 203D40C4 */  lwc1       $f0, %lo(D_00713D20)($2)
    /* 3AF428 004AF428 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF42C 004AF42C 0802A0E7 */  swc1       $f0, 0x208($29)
    /* 3AF430 004AF430 7100023C */  lui        $2, %hi(D_00713D24)
    /* 3AF434 004AF434 243D40C4 */  lwc1       $f0, %lo(D_00713D24)($2)
    /* 3AF438 004AF438 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF43C 004AF43C 0C02A0E7 */  swc1       $f0, 0x20C($29)
    /* 3AF440 004AF440 7100023C */  lui        $2, %hi(D_00713D28)
    /* 3AF444 004AF444 283D40C4 */  lwc1       $f0, %lo(D_00713D28)($2)
    /* 3AF448 004AF448 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AF44C 004AF44C 1002A0E7 */  swc1       $f0, 0x210($29)
  .L004AF450:
    /* 3AF450 004AF450 2001A427 */  addiu      $4, $29, 0x120
    /* 3AF454 004AF454 0802A527 */  addiu      $5, $29, 0x208
    /* 3AF458 004AF458 02000624 */  addiu      $6, $0, 0x2
    /* 3AF45C 004AF45C A4820F0C */  jal        func_003e0a90
    /* 3AF460 004AF460 00000000 */   nop
    /* 3AF464 004AF464 2001A427 */  addiu      $4, $29, 0x120
    /* 3AF468 004AF468 F801A527 */  addiu      $5, $29, 0x1F8
    /* 3AF46C 004AF46C 02000624 */  addiu      $6, $0, 0x2
    /* 3AF470 004AF470 24830F0C */  jal        func_003e0c90
    /* 3AF474 004AF474 00000000 */   nop
    /* 3AF478 004AF478 0400048E */  lw         $4, 0x4($16)
    /* 3AF47C 004AF47C 2001A527 */  addiu      $5, $29, 0x120
    /* 3AF480 004AF480 2D300000 */  daddu      $6, $0, $0
    /* 3AF484 004AF484 2CA70F0C */  jal        func_003e9cb0
    /* 3AF488 004AF488 00000000 */   nop
    /* 3AF48C 004AF48C 2D200002 */  daddu      $4, $16, $0
    /* 3AF490 004AF490 A4FF0E0C */  jal        func_003bfe90
    /* 3AF494 004AF494 00000000 */   nop
  .L004AF498:
    /* 3AF498 004AF498 01009426 */  addiu      $20, $20, 0x1
    /* 3AF49C 004AF49C 20005226 */  addiu      $18, $18, 0x20
    /* 3AF4A0 004AF4A0 18003126 */  addiu      $17, $17, 0x18
  .L004AF4A4:
    /* 3AF4A4 004AF4A4 2A109502 */  slt        $2, $20, $21
    /* 3AF4A8 004AF4A8 5BFF4014 */  bnez       $2, .L004AF218
    /* 3AF4AC 004AF4AC 00000000 */   nop
    /* 3AF4B0 004AF4B0 06000010 */  b          .L004AF4CC
    /* 3AF4B4 004AF4B4 00000000 */   nop
  .L004AF4B8:
    /* 3AF4B8 004AF4B8 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AF4BC 004AF4BC 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AF4C0 004AF4C0 A2020524 */  addiu      $5, $0, 0x2A2
    /* 3AF4C4 004AF4C4 CCB5110C */  jal        func_0046d730
    /* 3AF4C8 004AF4C8 00000000 */   nop
  .L004AF4CC:
    /* 3AF4CC 004AF4CC FC04120C */  jal        func_004813f0
    /* 3AF4D0 004AF4D0 00000000 */   nop
  .L004AF4D4:
    /* 3AF4D4 004AF4D4 9000BFDF */  ld         $31, 0x90($29)
    /* 3AF4D8 004AF4D8 8000B67B */  lq         $22, 0x80($29)
    /* 3AF4DC 004AF4DC 7000B57B */  lq         $21, 0x70($29)
    /* 3AF4E0 004AF4E0 6000B47B */  lq         $20, 0x60($29)
    /* 3AF4E4 004AF4E4 5000B37B */  lq         $19, 0x50($29)
    /* 3AF4E8 004AF4E8 4000B27B */  lq         $18, 0x40($29)
    /* 3AF4EC 004AF4EC 3000B17B */  lq         $17, 0x30($29)
    /* 3AF4F0 004AF4F0 2000B07B */  lq         $16, 0x20($29)
    /* 3AF4F4 004AF4F4 1800BAC7 */  lwc1       $f26, 0x18($29)
    /* 3AF4F8 004AF4F8 1400B9C7 */  lwc1       $f25, 0x14($29)
    /* 3AF4FC 004AF4FC 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* 3AF500 004AF500 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 3AF504 004AF504 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 3AF508 004AF508 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 3AF50C 004AF50C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3AF510 004AF510 3002BD27 */  addiu      $29, $29, 0x230
    /* 3AF514 004AF514 0800E003 */  jr         $31
    /* 3AF518 004AF518 00000000 */   nop
    /* 3AF51C 004AF51C 00000000 */  nop
.size func_004aed70, 0x7b0
