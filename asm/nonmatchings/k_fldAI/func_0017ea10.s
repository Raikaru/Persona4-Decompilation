.section .text
.set noat
.set noreorder
glabel func_0017ea10
    /* 7EA10 0017EA10 70FFBD27 */  addiu      $29, $29, -0x90
    /* 7EA14 0017EA14 4000BFFF */  sd         $31, 0x40($29)
    /* 7EA18 0017EA18 3000B27F */  sq         $18, 0x30($29)
    /* 7EA1C 0017EA1C 2000B17F */  sq         $17, 0x20($29)
    /* 7EA20 0017EA20 1000B07F */  sq         $16, 0x10($29)
    /* 7EA24 0017EA24 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 7EA28 0017EA28 2D908000 */  daddu      $18, $4, $0
    /* 7EA2C 0017EA2C 2D880000 */  daddu      $17, $0, $0
    /* 7EA30 0017EA30 CA018390 */  lbu        $3, 0x1CA($4)
    /* 7EA34 0017EA34 40100300 */  sll        $2, $3, 1
    /* 7EA38 0017EA38 21104300 */  addu       $2, $2, $3
    /* 7EA3C 0017EA3C C0190200 */  sll        $3, $2, 7
    /* 7EA40 0017EA40 C8B2828F */  lw         $2, -0x4D38($28)
    /* 7EA44 0017EA44 21184300 */  addu       $3, $2, $3
    /* 7EA48 0017EA48 C8018294 */  lhu        $2, 0x1C8($4)
    /* 7EA4C 0017EA4C 80110200 */  sll        $2, $2, 6
    /* 7EA50 0017EA50 21806200 */  addu       $16, $3, $2
    /* 7EA54 0017EA54 5CB2838F */  lw         $3, -0x4DA4($28)
    /* 7EA58 0017EA58 01000224 */  addiu      $2, $0, 0x1
    /* 7EA5C 0017EA5C 04006214 */  bne        $3, $2, .L0017EA70
    /* 7EA60 0017EA60 00000000 */   nop
    /* 7EA64 0017EA64 2D100000 */  daddu      $2, $0, $0
    /* 7EA68 0017EA68 AB000010 */  b          .L0017ED18
    /* 7EA6C 0017EA6C 00000000 */   nop
  .L0017EA70:
    /* 7EA70 0017EA70 CB014292 */  lbu        $2, 0x1CB($18)
    /* 7EA74 0017EA74 19004014 */  bnez       $2, .L0017EADC
    /* 7EA78 0017EA78 00000000 */   nop
    /* 7EA7C 0017EA7C 5000448E */  lw         $4, 0x50($18)
    /* 7EA80 0017EA80 BCE8110C */  jal        func_0047a2f0
    /* 7EA84 0017EA84 00000000 */   nop
    /* 7EA88 0017EA88 2D904000 */  daddu      $18, $2, $0
    /* 7EA8C 0017EA8C 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 7EA90 0017EA90 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 7EA94 0017EA94 BCE8110C */  jal        func_0047a2f0
    /* 7EA98 0017EA98 00000000 */   nop
    /* 7EA9C 0017EA9C 4040033C */  lui        $3, (0x40400000 >> 16)
    /* 7EAA0 0017EAA0 00088344 */  mtc1       $3, $f1
    /* 7EAA4 0017EAA4 140000C6 */  lwc1       $f0, 0x14($16)
    /* 7EAA8 0017EAA8 03030146 */  div.s      $f12, $f0, $f1
    /* 7EAAC 0017EAAC 00000000 */  nop
    /* 7EAB0 0017EAB0 30004426 */  addiu      $4, $18, 0x30
    /* 7EAB4 0017EAB4 30004524 */  addiu      $5, $2, 0x30
    /* 7EAB8 0017EAB8 3031050C */  jal        func_0014c4c0
    /* 7EABC 0017EABC 00000000 */   nop
    /* 7EAC0 0017EAC0 01000324 */  addiu      $3, $0, 0x1
    /* 7EAC4 0017EAC4 02004314 */  bne        $2, $3, .L0017EAD0
    /* 7EAC8 0017EAC8 00000000 */   nop
    /* 7EACC 0017EACC 2D886000 */  daddu      $17, $3, $0
  .L0017EAD0:
    /* 7EAD0 0017EAD0 2D102002 */  daddu      $2, $17, $0
    /* 7EAD4 0017EAD4 90000010 */  b          .L0017ED18
    /* 7EAD8 0017EAD8 00000000 */   nop
  .L0017EADC:
    /* 7EADC 0017EADC 5000448E */  lw         $4, 0x50($18)
    /* 7EAE0 0017EAE0 BCE8110C */  jal        func_0047a2f0
    /* 7EAE4 0017EAE4 00000000 */   nop
    /* 7EAE8 0017EAE8 300042C4 */  lwc1       $f2, 0x30($2)
    /* 7EAEC 0017EAEC 340041C4 */  lwc1       $f1, 0x34($2)
    /* 7EAF0 0017EAF0 380040C4 */  lwc1       $f0, 0x38($2)
    /* 7EAF4 0017EAF4 5000A2E7 */  swc1       $f2, 0x50($29)
    /* 7EAF8 0017EAF8 5400A1E7 */  swc1       $f1, 0x54($29)
    /* 7EAFC 0017EAFC 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 7EB00 0017EB00 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 7EB04 0017EB04 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 7EB08 0017EB08 BCE8110C */  jal        func_0047a2f0
    /* 7EB0C 0017EB0C 00000000 */   nop
    /* 7EB10 0017EB10 300042C4 */  lwc1       $f2, 0x30($2)
    /* 7EB14 0017EB14 340041C4 */  lwc1       $f1, 0x34($2)
    /* 7EB18 0017EB18 380040C4 */  lwc1       $f0, 0x38($2)
    /* 7EB1C 0017EB1C 5C00A2E7 */  swc1       $f2, 0x5C($29)
    /* 7EB20 0017EB20 6000A1E7 */  swc1       $f1, 0x60($29)
    /* 7EB24 0017EB24 6400A0E7 */  swc1       $f0, 0x64($29)
    /* 7EB28 0017EB28 5400A0C7 */  lwc1       $f0, 0x54($29)
    /* 7EB2C 0017EB2C B442023C */  lui        $2, (0x42B40000 >> 16)
    /* 7EB30 0017EB30 00088244 */  mtc1       $2, $f1
    /* 7EB34 0017EB34 00000000 */  nop
    /* 7EB38 0017EB38 00000146 */  add.s      $f0, $f0, $f1
    /* 7EB3C 0017EB3C 5400A0E7 */  swc1       $f0, 0x54($29)
    /* 7EB40 0017EB40 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* 7EB44 0017EB44 00000146 */  add.s      $f0, $f0, $f1
    /* 7EB48 0017EB48 6000A0E7 */  swc1       $f0, 0x60($29)
    /* 7EB4C 0017EB4C 5000A427 */  addiu      $4, $29, 0x50
    /* 7EB50 0017EB50 7000A527 */  addiu      $5, $29, 0x70
    /* 7EB54 0017EB54 28AE050C */  jal        func_0016b8a0
    /* 7EB58 0017EB58 00000000 */   nop
    /* 7EB5C 0017EB5C 01000324 */  addiu      $3, $0, 0x1
    /* 7EB60 0017EB60 04004314 */  bne        $2, $3, .L0017EB74
    /* 7EB64 0017EB64 00000000 */   nop
    /* 7EB68 0017EB68 2D100000 */  daddu      $2, $0, $0
    /* 7EB6C 0017EB6C 6A000010 */  b          .L0017ED18
    /* 7EB70 0017EB70 00000000 */   nop
  .L0017EB74:
    /* 7EB74 0017EB74 5000A427 */  addiu      $4, $29, 0x50
    /* 7EB78 0017EB78 7000A527 */  addiu      $5, $29, 0x70
    /* 7EB7C 0017EB7C 5000A2DF */  ld         $2, 0x50($29)
    /* 7EB80 0017EB80 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* 7EB84 0017EB84 7000A2FF */  sd         $2, 0x70($29)
    /* 7EB88 0017EB88 7800A0E7 */  swc1       $f0, 0x78($29)
    /* 7EB8C 0017EB8C 5C00A2C7 */  lwc1       $f2, 0x5C($29)
    /* 7EB90 0017EB90 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* 7EB94 0017EB94 6400A0C7 */  lwc1       $f0, 0x64($29)
    /* 7EB98 0017EB98 5000A2E7 */  swc1       $f2, 0x50($29)
    /* 7EB9C 0017EB9C 5400A1E7 */  swc1       $f1, 0x54($29)
    /* 7EBA0 0017EBA0 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 7EBA4 0017EBA4 7000A2C7 */  lwc1       $f2, 0x70($29)
    /* 7EBA8 0017EBA8 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* 7EBAC 0017EBAC 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* 7EBB0 0017EBB0 5C00A2E7 */  swc1       $f2, 0x5C($29)
    /* 7EBB4 0017EBB4 6000A1E7 */  swc1       $f1, 0x60($29)
    /* 7EBB8 0017EBB8 6400A0E7 */  swc1       $f0, 0x64($29)
    /* 7EBBC 0017EBBC 28AE050C */  jal        func_0016b8a0
    /* 7EBC0 0017EBC0 00000000 */   nop
    /* 7EBC4 0017EBC4 01000324 */  addiu      $3, $0, 0x1
    /* 7EBC8 0017EBC8 04004314 */  bne        $2, $3, .L0017EBDC
    /* 7EBCC 0017EBCC 00000000 */   nop
    /* 7EBD0 0017EBD0 2D100000 */  daddu      $2, $0, $0
    /* 7EBD4 0017EBD4 50000010 */  b          .L0017ED18
    /* 7EBD8 0017EBD8 00000000 */   nop
  .L0017EBDC:
    /* 7EBDC 0017EBDC 5000448E */  lw         $4, 0x50($18)
    /* 7EBE0 0017EBE0 BCE8110C */  jal        func_0047a2f0
    /* 7EBE4 0017EBE4 00000000 */   nop
    /* 7EBE8 0017EBE8 2D884000 */  daddu      $17, $2, $0
    /* 7EBEC 0017EBEC 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 7EBF0 0017EBF0 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 7EBF4 0017EBF4 BCE8110C */  jal        func_0047a2f0
    /* 7EBF8 0017EBF8 00000000 */   nop
    /* 7EBFC 0017EBFC 2D202002 */  daddu      $4, $17, $0
    /* 7EC00 0017EC00 30004524 */  addiu      $5, $2, 0x30
    /* 7EC04 0017EC04 0C000CC6 */  lwc1       $f12, 0xC($16)
    /* 7EC08 0017EC08 FC2F050C */  jal        func_0014bff0
    /* 7EC0C 0017EC0C 00000000 */   nop
    /* 7EC10 0017EC10 01000324 */  addiu      $3, $0, 0x1
    /* 7EC14 0017EC14 2C004314 */  bne        $2, $3, .L0017ECC8
    /* 7EC18 0017EC18 00000000 */   nop
    /* 7EC1C 0017EC1C 5000448E */  lw         $4, 0x50($18)
    /* 7EC20 0017EC20 BCE8110C */  jal        func_0047a2f0
    /* 7EC24 0017EC24 00000000 */   nop
    /* 7EC28 0017EC28 300054C4 */  lwc1       $f20, 0x30($2)
    /* 7EC2C 0017EC2C 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 7EC30 0017EC30 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 7EC34 0017EC34 BCE8110C */  jal        func_0047a2f0
    /* 7EC38 0017EC38 00000000 */   nop
    /* 7EC3C 0017EC3C 300040C4 */  lwc1       $f0, 0x30($2)
    /* 7EC40 0017EC40 01001446 */  sub.s      $f0, $f0, $f20
    /* 7EC44 0017EC44 8000A0E7 */  swc1       $f0, 0x80($29)
    /* 7EC48 0017EC48 5000448E */  lw         $4, 0x50($18)
    /* 7EC4C 0017EC4C BCE8110C */  jal        func_0047a2f0
    /* 7EC50 0017EC50 00000000 */   nop
    /* 7EC54 0017EC54 340054C4 */  lwc1       $f20, 0x34($2)
    /* 7EC58 0017EC58 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 7EC5C 0017EC5C 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 7EC60 0017EC60 BCE8110C */  jal        func_0047a2f0
    /* 7EC64 0017EC64 00000000 */   nop
    /* 7EC68 0017EC68 340040C4 */  lwc1       $f0, 0x34($2)
    /* 7EC6C 0017EC6C 01001446 */  sub.s      $f0, $f0, $f20
    /* 7EC70 0017EC70 8400A0E7 */  swc1       $f0, 0x84($29)
    /* 7EC74 0017EC74 5000448E */  lw         $4, 0x50($18)
    /* 7EC78 0017EC78 BCE8110C */  jal        func_0047a2f0
    /* 7EC7C 0017EC7C 00000000 */   nop
    /* 7EC80 0017EC80 380054C4 */  lwc1       $f20, 0x38($2)
    /* 7EC84 0017EC84 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 7EC88 0017EC88 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 7EC8C 0017EC8C BCE8110C */  jal        func_0047a2f0
    /* 7EC90 0017EC90 00000000 */   nop
    /* 7EC94 0017EC94 380040C4 */  lwc1       $f0, 0x38($2)
    /* 7EC98 0017EC98 01001446 */  sub.s      $f0, $f0, $f20
    /* 7EC9C 0017EC9C 8800A0E7 */  swc1       $f0, 0x88($29)
    /* 7ECA0 0017ECA0 8000A427 */  addiu      $4, $29, 0x80
    /* 7ECA4 0017ECA4 60900F0C */  jal        func_003e4180
    /* 7ECA8 0017ECA8 00000000 */   nop
    /* 7ECAC 0017ECAC 100001C6 */  lwc1       $f1, 0x10($16)
    /* 7ECB0 0017ECB0 34000146 */  c.lt.s     $f0, $f1
    /* 7ECB4 0017ECB4 04000045 */  bc1f       .L0017ECC8
    /* 7ECB8 0017ECB8 00000000 */   nop
    /* 7ECBC 0017ECBC 01000224 */  addiu      $2, $0, 0x1
    /* 7ECC0 0017ECC0 15000010 */  b          .L0017ED18
    /* 7ECC4 0017ECC4 00000000 */   nop
  .L0017ECC8:
    /* 7ECC8 0017ECC8 5000448E */  lw         $4, 0x50($18)
    /* 7ECCC 0017ECCC BCE8110C */  jal        func_0047a2f0
    /* 7ECD0 0017ECD0 00000000 */   nop
    /* 7ECD4 0017ECD4 2D884000 */  daddu      $17, $2, $0
    /* 7ECD8 0017ECD8 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 7ECDC 0017ECDC 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 7ECE0 0017ECE0 BCE8110C */  jal        func_0047a2f0
    /* 7ECE4 0017ECE4 00000000 */   nop
    /* 7ECE8 0017ECE8 30002426 */  addiu      $4, $17, 0x30
    /* 7ECEC 0017ECEC 30004524 */  addiu      $5, $2, 0x30
    /* 7ECF0 0017ECF0 14000CC6 */  lwc1       $f12, 0x14($16)
    /* 7ECF4 0017ECF4 3031050C */  jal        func_0014c4c0
    /* 7ECF8 0017ECF8 00000000 */   nop
    /* 7ECFC 0017ECFC 01000324 */  addiu      $3, $0, 0x1
    /* 7ED00 0017ED00 04004314 */  bne        $2, $3, .L0017ED14
    /* 7ED04 0017ED04 00000000 */   nop
    /* 7ED08 0017ED08 2D106000 */  daddu      $2, $3, $0
    /* 7ED0C 0017ED0C 02000010 */  b          .L0017ED18
    /* 7ED10 0017ED10 00000000 */   nop
  .L0017ED14:
    /* 7ED14 0017ED14 2D100000 */  daddu      $2, $0, $0
  .L0017ED18:
    /* 7ED18 0017ED18 4000BFDF */  ld         $31, 0x40($29)
    /* 7ED1C 0017ED1C 3000B27B */  lq         $18, 0x30($29)
    /* 7ED20 0017ED20 2000B17B */  lq         $17, 0x20($29)
    /* 7ED24 0017ED24 1000B07B */  lq         $16, 0x10($29)
    /* 7ED28 0017ED28 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 7ED2C 0017ED2C 9000BD27 */  addiu      $29, $29, 0x90
    /* 7ED30 0017ED30 0800E003 */  jr         $31
    /* 7ED34 0017ED34 00000000 */   nop
    /* 7ED38 0017ED38 00000000 */  nop
    /* 7ED3C 0017ED3C 00000000 */  nop
.size func_0017ea10, 0x330
