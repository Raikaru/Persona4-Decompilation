.section .text
.set noat
.set noreorder
glabel func_001fe090
    /* FE090 001FE090 70FFBD27 */  addiu      $29, $29, -0x90
    /* FE094 001FE094 6000BFFF */  sd         $31, 0x60($29)
    /* FE098 001FE098 5000B47F */  sq         $20, 0x50($29)
    /* FE09C 001FE09C 4000B37F */  sq         $19, 0x40($29)
    /* FE0A0 001FE0A0 3000B27F */  sq         $18, 0x30($29)
    /* FE0A4 001FE0A4 2000B17F */  sq         $17, 0x20($29)
    /* FE0A8 001FE0A8 1000B07F */  sq         $16, 0x10($29)
    /* FE0AC 001FE0AC 0400B5E7 */  swc1       $f21, 0x4($29)
    /* FE0B0 001FE0B0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* FE0B4 001FE0B4 3000948C */  lw         $20, 0x30($4)
    /* FE0B8 001FE0B8 3800938C */  lw         $19, 0x38($4)
    /* FE0BC 001FE0BC 2800928C */  lw         $18, 0x28($4)
    /* FE0C0 001FE0C0 0000718E */  lw         $17, 0x0($19)
    /* FE0C4 001FE0C4 2B083202 */  sltu       $1, $17, $18
    /* FE0C8 001FE0C8 03002010 */  beqz       $1, .L001FE0D8
    /* FE0CC 001FE0CC 00000000 */   nop
    /* FE0D0 001FE0D0 9F022016 */  bnez       $17, .L001FEB50
    /* FE0D4 001FE0D4 00000000 */   nop
  .L001FE0D8:
    /* FE0D8 001FE0D8 08DC060C */  jal        func_001b7020
    /* FE0DC 001FE0DC 00000000 */   nop
    /* FE0E0 001FE0E0 2D804000 */  daddu      $16, $2, $0
    /* FE0E4 001FE0E4 2D200000 */  daddu      $4, $0, $0
    /* FE0E8 001FE0E8 5E002012 */  beqz       $17, .L001FE264
    /* FE0EC 001FE0EC 00000000 */   nop
    /* FE0F0 001FE0F0 04006596 */  lhu        $5, 0x4($19)
    /* FE0F4 001FE0F4 2B08B200 */  sltu       $1, $5, $18
    /* FE0F8 001FE0F8 2C002014 */  bnez       $1, .L001FE1AC
    /* FE0FC 001FE0FC 00000000 */   nop
    /* FE100 001FE100 2500A018 */  blez       $5, .L001FE198
    /* FE104 001FE104 00000000 */   nop
    /* FE108 001FE108 06004006 */  bltz       $18, .L001FE124
    /* FE10C 001FE10C 00000000 */   nop
    /* FE110 001FE110 00009244 */  mtc1       $18, $f0
    /* FE114 001FE114 00000000 */  nop
    /* FE118 001FE118 60008046 */  cvt.s.w    $f1, $f0
    /* FE11C 001FE11C 08000010 */  b          .L001FE140
    /* FE120 001FE120 00000000 */   nop
  .L001FE124:
    /* FE124 001FE124 42201200 */  srl        $4, $18, 1
    /* FE128 001FE128 01004332 */  andi       $3, $18, 0x1
    /* FE12C 001FE12C 25208300 */  or         $4, $4, $3
    /* FE130 001FE130 00008444 */  mtc1       $4, $f0
    /* FE134 001FE134 00000000 */  nop
    /* FE138 001FE138 60008046 */  cvt.s.w    $f1, $f0
    /* FE13C 001FE13C 40080146 */  add.s      $f1, $f1, $f1
  .L001FE140:
    /* FE140 001FE140 0600A004 */  bltz       $5, .L001FE15C
    /* FE144 001FE144 00000000 */   nop
    /* FE148 001FE148 00008544 */  mtc1       $5, $f0
    /* FE14C 001FE14C 00000000 */  nop
    /* FE150 001FE150 20008046 */  cvt.s.w    $f0, $f0
    /* FE154 001FE154 08000010 */  b          .L001FE178
    /* FE158 001FE158 00000000 */   nop
  .L001FE15C:
    /* FE15C 001FE15C 42200500 */  srl        $4, $5, 1
    /* FE160 001FE160 0100A330 */  andi       $3, $5, 0x1
    /* FE164 001FE164 25208300 */  or         $4, $4, $3
    /* FE168 001FE168 00008444 */  mtc1       $4, $f0
    /* FE16C 001FE16C 00000000 */  nop
    /* FE170 001FE170 20008046 */  cvt.s.w    $f0, $f0
    /* FE174 001FE174 00000046 */  add.s      $f0, $f0, $f0
  .L001FE178:
    /* FE178 001FE178 00000000 */  nop
    /* FE17C 001FE17C 00000000 */  nop
    /* FE180 001FE180 430D0046 */  div.s      $f21, $f1, $f0
    /* FE184 001FE184 00000000 */  nop
    /* FE188 001FE188 00000000 */  nop
    /* FE18C 001FE18C 00000000 */  nop
    /* FE190 001FE190 03000010 */  b          .L001FE1A0
    /* FE194 001FE194 00000000 */   nop
  .L001FE198:
    /* FE198 001FE198 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FE19C 001FE19C 00A88344 */  mtc1       $3, $f21
  .L001FE1A0:
    /* FE1A0 001FE1A0 01000464 */  daddiu     $4, $0, 0x1
    /* FE1A4 001FE1A4 2F000010 */  b          .L001FE264
    /* FE1A8 001FE1A8 00000000 */   nop
  .L001FE1AC:
    /* FE1AC 001FE1AC 06006596 */  lhu        $5, 0x6($19)
    /* FE1B0 001FE1B0 23182502 */  subu       $3, $17, $5
    /* FE1B4 001FE1B4 2B184302 */  sltu       $3, $18, $3
    /* FE1B8 001FE1B8 2A006014 */  bnez       $3, .L001FE264
    /* FE1BC 001FE1BC 00000000 */   nop
    /* FE1C0 001FE1C0 2600A018 */  blez       $5, .L001FE25C
    /* FE1C4 001FE1C4 00000000 */   nop
    /* FE1C8 001FE1C8 23183202 */  subu       $3, $17, $18
    /* FE1CC 001FE1CC 06006004 */  bltz       $3, .L001FE1E8
    /* FE1D0 001FE1D0 00000000 */   nop
    /* FE1D4 001FE1D4 00008344 */  mtc1       $3, $f0
    /* FE1D8 001FE1D8 00000000 */  nop
    /* FE1DC 001FE1DC 60008046 */  cvt.s.w    $f1, $f0
    /* FE1E0 001FE1E0 08000010 */  b          .L001FE204
    /* FE1E4 001FE1E4 00000000 */   nop
  .L001FE1E8:
    /* FE1E8 001FE1E8 42200300 */  srl        $4, $3, 1
    /* FE1EC 001FE1EC 01006330 */  andi       $3, $3, 0x1
    /* FE1F0 001FE1F0 25208300 */  or         $4, $4, $3
    /* FE1F4 001FE1F4 00008444 */  mtc1       $4, $f0
    /* FE1F8 001FE1F8 00000000 */  nop
    /* FE1FC 001FE1FC 60008046 */  cvt.s.w    $f1, $f0
    /* FE200 001FE200 40080146 */  add.s      $f1, $f1, $f1
  .L001FE204:
    /* FE204 001FE204 0600A004 */  bltz       $5, .L001FE220
    /* FE208 001FE208 00000000 */   nop
    /* FE20C 001FE20C 00008544 */  mtc1       $5, $f0
    /* FE210 001FE210 00000000 */  nop
    /* FE214 001FE214 20008046 */  cvt.s.w    $f0, $f0
    /* FE218 001FE218 08000010 */  b          .L001FE23C
    /* FE21C 001FE21C 00000000 */   nop
  .L001FE220:
    /* FE220 001FE220 42200500 */  srl        $4, $5, 1
    /* FE224 001FE224 0100A330 */  andi       $3, $5, 0x1
    /* FE228 001FE228 25208300 */  or         $4, $4, $3
    /* FE22C 001FE22C 00008444 */  mtc1       $4, $f0
    /* FE230 001FE230 00000000 */  nop
    /* FE234 001FE234 20008046 */  cvt.s.w    $f0, $f0
    /* FE238 001FE238 00000046 */  add.s      $f0, $f0, $f0
  .L001FE23C:
    /* FE23C 001FE23C 00000000 */  nop
    /* FE240 001FE240 00000000 */  nop
    /* FE244 001FE244 430D0046 */  div.s      $f21, $f1, $f0
    /* FE248 001FE248 00000000 */  nop
    /* FE24C 001FE24C 00000000 */  nop
    /* FE250 001FE250 00000000 */  nop
    /* FE254 001FE254 02000010 */  b          .L001FE260
    /* FE258 001FE258 00000000 */   nop
  .L001FE25C:
    /* FE25C 001FE25C 00A88044 */  mtc1       $0, $f21
  .L001FE260:
    /* FE260 001FE260 02000464 */  daddiu     $4, $0, 0x2
  .L001FE264:
    /* FE264 001FE264 FF008430 */  andi       $4, $4, 0xFF
    /* FE268 001FE268 02000324 */  addiu      $3, $0, 0x2
    /* FE26C 001FE26C DA018310 */  beq        $4, $3, .L001FE9D8
    /* FE270 001FE270 00000000 */   nop
    /* FE274 001FE274 01000324 */  addiu      $3, $0, 0x1
    /* FE278 001FE278 CF008310 */  beq        $4, $3, .L001FE5B8
    /* FE27C 001FE27C 00000000 */   nop
    /* FE280 001FE280 03008010 */  beqz       $4, .L001FE290
    /* FE284 001FE284 00000000 */   nop
    /* FE288 001FE288 31020010 */  b          .L001FEB50
    /* FE28C 001FE28C 00000000 */   nop
  .L001FE290:
    /* FE290 001FE290 2F024016 */  bnez       $18, .L001FEB50
    /* FE294 001FE294 00000000 */   nop
    /* FE298 001FE298 0800628E */  lw         $2, 0x8($19)
    /* FE29C 001FE29C 8C00A2AF */  sw         $2, 0x8C($29)
    /* FE2A0 001FE2A0 8C00A293 */  lbu        $2, 0x8C($29)
    /* FE2A4 001FE2A4 06004004 */  bltz       $2, .L001FE2C0
    /* FE2A8 001FE2A8 00000000 */   nop
    /* FE2AC 001FE2AC 00008244 */  mtc1       $2, $f0
    /* FE2B0 001FE2B0 00000000 */  nop
    /* FE2B4 001FE2B4 60008046 */  cvt.s.w    $f1, $f0
    /* FE2B8 001FE2B8 08000010 */  b          .L001FE2DC
    /* FE2BC 001FE2BC 00000000 */   nop
  .L001FE2C0:
    /* FE2C0 001FE2C0 42180200 */  srl        $3, $2, 1
    /* FE2C4 001FE2C4 01004230 */  andi       $2, $2, 0x1
    /* FE2C8 001FE2C8 25186200 */  or         $3, $3, $2
    /* FE2CC 001FE2CC 00008344 */  mtc1       $3, $f0
    /* FE2D0 001FE2D0 00000000 */  nop
    /* FE2D4 001FE2D4 60008046 */  cvt.s.w    $f1, $f0
    /* FE2D8 001FE2D8 40080146 */  add.s      $f1, $f1, $f1
  .L001FE2DC:
    /* FE2DC 001FE2DC AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE2E0 001FE2E0 02000146 */  mul.s      $f0, $f0, $f1
    /* FE2E4 001FE2E4 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE2E8 001FE2E8 8D00A293 */  lbu        $2, 0x8D($29)
    /* FE2EC 001FE2EC 06004004 */  bltz       $2, .L001FE308
    /* FE2F0 001FE2F0 00000000 */   nop
    /* FE2F4 001FE2F4 00008244 */  mtc1       $2, $f0
    /* FE2F8 001FE2F8 00000000 */  nop
    /* FE2FC 001FE2FC 60008046 */  cvt.s.w    $f1, $f0
    /* FE300 001FE300 08000010 */  b          .L001FE324
    /* FE304 001FE304 00000000 */   nop
  .L001FE308:
    /* FE308 001FE308 42180200 */  srl        $3, $2, 1
    /* FE30C 001FE30C 01004230 */  andi       $2, $2, 0x1
    /* FE310 001FE310 25186200 */  or         $3, $3, $2
    /* FE314 001FE314 00008344 */  mtc1       $3, $f0
    /* FE318 001FE318 00000000 */  nop
    /* FE31C 001FE31C 60008046 */  cvt.s.w    $f1, $f0
    /* FE320 001FE320 40080146 */  add.s      $f1, $f1, $f1
  .L001FE324:
    /* FE324 001FE324 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE328 001FE328 02000146 */  mul.s      $f0, $f0, $f1
    /* FE32C 001FE32C 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE330 001FE330 8E00A293 */  lbu        $2, 0x8E($29)
    /* FE334 001FE334 06004004 */  bltz       $2, .L001FE350
    /* FE338 001FE338 00000000 */   nop
    /* FE33C 001FE33C 00008244 */  mtc1       $2, $f0
    /* FE340 001FE340 00000000 */  nop
    /* FE344 001FE344 60008046 */  cvt.s.w    $f1, $f0
    /* FE348 001FE348 08000010 */  b          .L001FE36C
    /* FE34C 001FE34C 00000000 */   nop
  .L001FE350:
    /* FE350 001FE350 42180200 */  srl        $3, $2, 1
    /* FE354 001FE354 01004230 */  andi       $2, $2, 0x1
    /* FE358 001FE358 25186200 */  or         $3, $3, $2
    /* FE35C 001FE35C 00008344 */  mtc1       $3, $f0
    /* FE360 001FE360 00000000 */  nop
    /* FE364 001FE364 60008046 */  cvt.s.w    $f1, $f0
    /* FE368 001FE368 40080146 */  add.s      $f1, $f1, $f1
  .L001FE36C:
    /* FE36C 001FE36C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE370 001FE370 02000146 */  mul.s      $f0, $f0, $f1
    /* FE374 001FE374 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE378 001FE378 8F00A293 */  lbu        $2, 0x8F($29)
    /* FE37C 001FE37C 06004004 */  bltz       $2, .L001FE398
    /* FE380 001FE380 00000000 */   nop
    /* FE384 001FE384 00008244 */  mtc1       $2, $f0
    /* FE388 001FE388 00000000 */  nop
    /* FE38C 001FE38C 60008046 */  cvt.s.w    $f1, $f0
    /* FE390 001FE390 08000010 */  b          .L001FE3B4
    /* FE394 001FE394 00000000 */   nop
  .L001FE398:
    /* FE398 001FE398 42180200 */  srl        $3, $2, 1
    /* FE39C 001FE39C 01004230 */  andi       $2, $2, 0x1
    /* FE3A0 001FE3A0 25186200 */  or         $3, $3, $2
    /* FE3A4 001FE3A4 00008344 */  mtc1       $3, $f0
    /* FE3A8 001FE3A8 00000000 */  nop
    /* FE3AC 001FE3AC 60008046 */  cvt.s.w    $f1, $f0
    /* FE3B0 001FE3B0 40080146 */  add.s      $f1, $f1, $f1
  .L001FE3B4:
    /* FE3B4 001FE3B4 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE3B8 001FE3B8 82000146 */  mul.s      $f2, $f0, $f1
    /* FE3BC 001FE3BC 7C00A2E7 */  swc1       $f2, 0x7C($29)
    /* FE3C0 001FE3C0 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* FE3C4 001FE3C4 000000C6 */  lwc1       $f0, 0x0($16)
    /* FE3C8 001FE3C8 02080046 */  mul.s      $f0, $f1, $f0
    /* FE3CC 001FE3CC 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE3D0 001FE3D0 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* FE3D4 001FE3D4 040000C6 */  lwc1       $f0, 0x4($16)
    /* FE3D8 001FE3D8 02080046 */  mul.s      $f0, $f1, $f0
    /* FE3DC 001FE3DC 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE3E0 001FE3E0 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE3E4 001FE3E4 080000C6 */  lwc1       $f0, 0x8($16)
    /* FE3E8 001FE3E8 02080046 */  mul.s      $f0, $f1, $f0
    /* FE3EC 001FE3EC 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE3F0 001FE3F0 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* FE3F4 001FE3F4 02100046 */  mul.s      $f0, $f2, $f0
    /* FE3F8 001FE3F8 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* FE3FC 001FE3FC 2827050C */  jal        func_00149ca0
    /* FE400 001FE400 00000000 */   nop
    /* FE404 001FE404 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FE408 001FE408 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FE40C 001FE40C 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE410 001FE410 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FE414 001FE414 000043E4 */  swc1       $f3, 0x0($2)
    /* FE418 001FE418 040042E4 */  swc1       $f2, 0x4($2)
    /* FE41C 001FE41C 080041E4 */  swc1       $f1, 0x8($2)
    /* FE420 001FE420 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FE424 001FE424 0C00628E */  lw         $2, 0xC($19)
    /* FE428 001FE428 8C00A2AF */  sw         $2, 0x8C($29)
    /* FE42C 001FE42C 8C00A293 */  lbu        $2, 0x8C($29)
    /* FE430 001FE430 06004004 */  bltz       $2, .L001FE44C
    /* FE434 001FE434 00000000 */   nop
    /* FE438 001FE438 00008244 */  mtc1       $2, $f0
    /* FE43C 001FE43C 00000000 */  nop
    /* FE440 001FE440 60008046 */  cvt.s.w    $f1, $f0
    /* FE444 001FE444 08000010 */  b          .L001FE468
    /* FE448 001FE448 00000000 */   nop
  .L001FE44C:
    /* FE44C 001FE44C 42180200 */  srl        $3, $2, 1
    /* FE450 001FE450 01004230 */  andi       $2, $2, 0x1
    /* FE454 001FE454 25186200 */  or         $3, $3, $2
    /* FE458 001FE458 00008344 */  mtc1       $3, $f0
    /* FE45C 001FE45C 00000000 */  nop
    /* FE460 001FE460 60008046 */  cvt.s.w    $f1, $f0
    /* FE464 001FE464 40080146 */  add.s      $f1, $f1, $f1
  .L001FE468:
    /* FE468 001FE468 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE46C 001FE46C 02000146 */  mul.s      $f0, $f0, $f1
    /* FE470 001FE470 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE474 001FE474 8D00A293 */  lbu        $2, 0x8D($29)
    /* FE478 001FE478 06004004 */  bltz       $2, .L001FE494
    /* FE47C 001FE47C 00000000 */   nop
    /* FE480 001FE480 00008244 */  mtc1       $2, $f0
    /* FE484 001FE484 00000000 */  nop
    /* FE488 001FE488 60008046 */  cvt.s.w    $f1, $f0
    /* FE48C 001FE48C 08000010 */  b          .L001FE4B0
    /* FE490 001FE490 00000000 */   nop
  .L001FE494:
    /* FE494 001FE494 42180200 */  srl        $3, $2, 1
    /* FE498 001FE498 01004230 */  andi       $2, $2, 0x1
    /* FE49C 001FE49C 25186200 */  or         $3, $3, $2
    /* FE4A0 001FE4A0 00008344 */  mtc1       $3, $f0
    /* FE4A4 001FE4A4 00000000 */  nop
    /* FE4A8 001FE4A8 60008046 */  cvt.s.w    $f1, $f0
    /* FE4AC 001FE4AC 40080146 */  add.s      $f1, $f1, $f1
  .L001FE4B0:
    /* FE4B0 001FE4B0 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE4B4 001FE4B4 02000146 */  mul.s      $f0, $f0, $f1
    /* FE4B8 001FE4B8 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE4BC 001FE4BC 8E00A293 */  lbu        $2, 0x8E($29)
    /* FE4C0 001FE4C0 06004004 */  bltz       $2, .L001FE4DC
    /* FE4C4 001FE4C4 00000000 */   nop
    /* FE4C8 001FE4C8 00008244 */  mtc1       $2, $f0
    /* FE4CC 001FE4CC 00000000 */  nop
    /* FE4D0 001FE4D0 60008046 */  cvt.s.w    $f1, $f0
    /* FE4D4 001FE4D4 08000010 */  b          .L001FE4F8
    /* FE4D8 001FE4D8 00000000 */   nop
  .L001FE4DC:
    /* FE4DC 001FE4DC 42180200 */  srl        $3, $2, 1
    /* FE4E0 001FE4E0 01004230 */  andi       $2, $2, 0x1
    /* FE4E4 001FE4E4 25186200 */  or         $3, $3, $2
    /* FE4E8 001FE4E8 00008344 */  mtc1       $3, $f0
    /* FE4EC 001FE4EC 00000000 */  nop
    /* FE4F0 001FE4F0 60008046 */  cvt.s.w    $f1, $f0
    /* FE4F4 001FE4F4 40080146 */  add.s      $f1, $f1, $f1
  .L001FE4F8:
    /* FE4F8 001FE4F8 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE4FC 001FE4FC 02000146 */  mul.s      $f0, $f0, $f1
    /* FE500 001FE500 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE504 001FE504 8F00A293 */  lbu        $2, 0x8F($29)
    /* FE508 001FE508 06004004 */  bltz       $2, .L001FE524
    /* FE50C 001FE50C 00000000 */   nop
    /* FE510 001FE510 00008244 */  mtc1       $2, $f0
    /* FE514 001FE514 00000000 */  nop
    /* FE518 001FE518 60008046 */  cvt.s.w    $f1, $f0
    /* FE51C 001FE51C 08000010 */  b          .L001FE540
    /* FE520 001FE520 00000000 */   nop
  .L001FE524:
    /* FE524 001FE524 42180200 */  srl        $3, $2, 1
    /* FE528 001FE528 01004230 */  andi       $2, $2, 0x1
    /* FE52C 001FE52C 25186200 */  or         $3, $3, $2
    /* FE530 001FE530 00008344 */  mtc1       $3, $f0
    /* FE534 001FE534 00000000 */  nop
    /* FE538 001FE538 60008046 */  cvt.s.w    $f1, $f0
    /* FE53C 001FE53C 40080146 */  add.s      $f1, $f1, $f1
  .L001FE540:
    /* FE540 001FE540 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE544 001FE544 82000146 */  mul.s      $f2, $f0, $f1
    /* FE548 001FE548 7C00A2E7 */  swc1       $f2, 0x7C($29)
    /* FE54C 001FE54C 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* FE550 001FE550 100000C6 */  lwc1       $f0, 0x10($16)
    /* FE554 001FE554 02080046 */  mul.s      $f0, $f1, $f0
    /* FE558 001FE558 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE55C 001FE55C 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* FE560 001FE560 140000C6 */  lwc1       $f0, 0x14($16)
    /* FE564 001FE564 02080046 */  mul.s      $f0, $f1, $f0
    /* FE568 001FE568 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE56C 001FE56C 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE570 001FE570 180000C6 */  lwc1       $f0, 0x18($16)
    /* FE574 001FE574 02080046 */  mul.s      $f0, $f1, $f0
    /* FE578 001FE578 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE57C 001FE57C 1C0000C6 */  lwc1       $f0, 0x1C($16)
    /* FE580 001FE580 02100046 */  mul.s      $f0, $f2, $f0
    /* FE584 001FE584 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* FE588 001FE588 3827050C */  jal        func_00149ce0
    /* FE58C 001FE58C 00000000 */   nop
    /* FE590 001FE590 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FE594 001FE594 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FE598 001FE598 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE59C 001FE59C 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FE5A0 001FE5A0 000043E4 */  swc1       $f3, 0x0($2)
    /* FE5A4 001FE5A4 040042E4 */  swc1       $f2, 0x4($2)
    /* FE5A8 001FE5A8 080041E4 */  swc1       $f1, 0x8($2)
    /* FE5AC 001FE5AC 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FE5B0 001FE5B0 67010010 */  b          .L001FEB50
    /* FE5B4 001FE5B4 00000000 */   nop
  .L001FE5B8:
    /* FE5B8 001FE5B8 15004016 */  bnez       $18, .L001FE610
    /* FE5BC 001FE5BC 00000000 */   nop
    /* FE5C0 001FE5C0 2827050C */  jal        func_00149ca0
    /* FE5C4 001FE5C4 00000000 */   nop
    /* FE5C8 001FE5C8 000043C4 */  lwc1       $f3, 0x0($2)
    /* FE5CC 001FE5CC 040042C4 */  lwc1       $f2, 0x4($2)
    /* FE5D0 001FE5D0 080041C4 */  lwc1       $f1, 0x8($2)
    /* FE5D4 001FE5D4 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* FE5D8 001FE5D8 000083E6 */  swc1       $f3, 0x0($20)
    /* FE5DC 001FE5DC 040082E6 */  swc1       $f2, 0x4($20)
    /* FE5E0 001FE5E0 080081E6 */  swc1       $f1, 0x8($20)
    /* FE5E4 001FE5E4 0C0080E6 */  swc1       $f0, 0xC($20)
    /* FE5E8 001FE5E8 3827050C */  jal        func_00149ce0
    /* FE5EC 001FE5EC 00000000 */   nop
    /* FE5F0 001FE5F0 000043C4 */  lwc1       $f3, 0x0($2)
    /* FE5F4 001FE5F4 040042C4 */  lwc1       $f2, 0x4($2)
    /* FE5F8 001FE5F8 080041C4 */  lwc1       $f1, 0x8($2)
    /* FE5FC 001FE5FC 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* FE600 001FE600 100083E6 */  swc1       $f3, 0x10($20)
    /* FE604 001FE604 140082E6 */  swc1       $f2, 0x14($20)
    /* FE608 001FE608 180081E6 */  swc1       $f1, 0x18($20)
    /* FE60C 001FE60C 1C0080E6 */  swc1       $f0, 0x1C($20)
  .L001FE610:
    /* FE610 001FE610 0800628E */  lw         $2, 0x8($19)
    /* FE614 001FE614 8C00A2AF */  sw         $2, 0x8C($29)
    /* FE618 001FE618 8C00A293 */  lbu        $2, 0x8C($29)
    /* FE61C 001FE61C 06004004 */  bltz       $2, .L001FE638
    /* FE620 001FE620 00000000 */   nop
    /* FE624 001FE624 00008244 */  mtc1       $2, $f0
    /* FE628 001FE628 00000000 */  nop
    /* FE62C 001FE62C 60008046 */  cvt.s.w    $f1, $f0
    /* FE630 001FE630 08000010 */  b          .L001FE654
    /* FE634 001FE634 00000000 */   nop
  .L001FE638:
    /* FE638 001FE638 42180200 */  srl        $3, $2, 1
    /* FE63C 001FE63C 01004230 */  andi       $2, $2, 0x1
    /* FE640 001FE640 25186200 */  or         $3, $3, $2
    /* FE644 001FE644 00008344 */  mtc1       $3, $f0
    /* FE648 001FE648 00000000 */  nop
    /* FE64C 001FE64C 60008046 */  cvt.s.w    $f1, $f0
    /* FE650 001FE650 40080146 */  add.s      $f1, $f1, $f1
  .L001FE654:
    /* FE654 001FE654 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE658 001FE658 02000146 */  mul.s      $f0, $f0, $f1
    /* FE65C 001FE65C 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE660 001FE660 8D00A293 */  lbu        $2, 0x8D($29)
    /* FE664 001FE664 06004004 */  bltz       $2, .L001FE680
    /* FE668 001FE668 00000000 */   nop
    /* FE66C 001FE66C 00008244 */  mtc1       $2, $f0
    /* FE670 001FE670 00000000 */  nop
    /* FE674 001FE674 60008046 */  cvt.s.w    $f1, $f0
    /* FE678 001FE678 08000010 */  b          .L001FE69C
    /* FE67C 001FE67C 00000000 */   nop
  .L001FE680:
    /* FE680 001FE680 42180200 */  srl        $3, $2, 1
    /* FE684 001FE684 01004230 */  andi       $2, $2, 0x1
    /* FE688 001FE688 25186200 */  or         $3, $3, $2
    /* FE68C 001FE68C 00008344 */  mtc1       $3, $f0
    /* FE690 001FE690 00000000 */  nop
    /* FE694 001FE694 60008046 */  cvt.s.w    $f1, $f0
    /* FE698 001FE698 40080146 */  add.s      $f1, $f1, $f1
  .L001FE69C:
    /* FE69C 001FE69C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE6A0 001FE6A0 02000146 */  mul.s      $f0, $f0, $f1
    /* FE6A4 001FE6A4 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE6A8 001FE6A8 8E00A293 */  lbu        $2, 0x8E($29)
    /* FE6AC 001FE6AC 06004004 */  bltz       $2, .L001FE6C8
    /* FE6B0 001FE6B0 00000000 */   nop
    /* FE6B4 001FE6B4 00008244 */  mtc1       $2, $f0
    /* FE6B8 001FE6B8 00000000 */  nop
    /* FE6BC 001FE6BC 60008046 */  cvt.s.w    $f1, $f0
    /* FE6C0 001FE6C0 08000010 */  b          .L001FE6E4
    /* FE6C4 001FE6C4 00000000 */   nop
  .L001FE6C8:
    /* FE6C8 001FE6C8 42180200 */  srl        $3, $2, 1
    /* FE6CC 001FE6CC 01004230 */  andi       $2, $2, 0x1
    /* FE6D0 001FE6D0 25186200 */  or         $3, $3, $2
    /* FE6D4 001FE6D4 00008344 */  mtc1       $3, $f0
    /* FE6D8 001FE6D8 00000000 */  nop
    /* FE6DC 001FE6DC 60008046 */  cvt.s.w    $f1, $f0
    /* FE6E0 001FE6E0 40080146 */  add.s      $f1, $f1, $f1
  .L001FE6E4:
    /* FE6E4 001FE6E4 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE6E8 001FE6E8 02000146 */  mul.s      $f0, $f0, $f1
    /* FE6EC 001FE6EC 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE6F0 001FE6F0 8F00A293 */  lbu        $2, 0x8F($29)
    /* FE6F4 001FE6F4 06004004 */  bltz       $2, .L001FE710
    /* FE6F8 001FE6F8 00000000 */   nop
    /* FE6FC 001FE6FC 00008244 */  mtc1       $2, $f0
    /* FE700 001FE700 00000000 */  nop
    /* FE704 001FE704 60008046 */  cvt.s.w    $f1, $f0
    /* FE708 001FE708 08000010 */  b          .L001FE72C
    /* FE70C 001FE70C 00000000 */   nop
  .L001FE710:
    /* FE710 001FE710 42180200 */  srl        $3, $2, 1
    /* FE714 001FE714 01004230 */  andi       $2, $2, 0x1
    /* FE718 001FE718 25186200 */  or         $3, $3, $2
    /* FE71C 001FE71C 00008344 */  mtc1       $3, $f0
    /* FE720 001FE720 00000000 */  nop
    /* FE724 001FE724 60008046 */  cvt.s.w    $f1, $f0
    /* FE728 001FE728 40080146 */  add.s      $f1, $f1, $f1
  .L001FE72C:
    /* FE72C 001FE72C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE730 001FE730 C2000146 */  mul.s      $f3, $f0, $f1
    /* FE734 001FE734 7C00A3E7 */  swc1       $f3, 0x7C($29)
    /* FE738 001FE738 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* FE73C 001FE73C 000000C6 */  lwc1       $f0, 0x0($16)
    /* FE740 001FE740 C2090046 */  mul.s      $f7, $f1, $f0
    /* FE744 001FE744 7000A7E7 */  swc1       $f7, 0x70($29)
    /* FE748 001FE748 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* FE74C 001FE74C 040000C6 */  lwc1       $f0, 0x4($16)
    /* FE750 001FE750 82080046 */  mul.s      $f2, $f1, $f0
    /* FE754 001FE754 7400A2E7 */  swc1       $f2, 0x74($29)
    /* FE758 001FE758 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE75C 001FE75C 080000C6 */  lwc1       $f0, 0x8($16)
    /* FE760 001FE760 42080046 */  mul.s      $f1, $f1, $f0
    /* FE764 001FE764 7800A1E7 */  swc1       $f1, 0x78($29)
    /* FE768 001FE768 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* FE76C 001FE76C 82190046 */  mul.s      $f6, $f3, $f0
    /* FE770 001FE770 7C00A6E7 */  swc1       $f6, 0x7C($29)
    /* FE774 001FE774 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FE778 001FE778 00008244 */  mtc1       $2, $f0
    /* FE77C 001FE77C 00000000 */  nop
    /* FE780 001FE780 01051546 */  sub.s      $f20, $f0, $f21
    /* FE784 001FE784 000080C6 */  lwc1       $f0, 0x0($20)
    /* FE788 001FE788 42011446 */  mul.s      $f5, $f0, $f20
    /* FE78C 001FE78C 040080C6 */  lwc1       $f0, 0x4($20)
    /* FE790 001FE790 02011446 */  mul.s      $f4, $f0, $f20
    /* FE794 001FE794 080080C6 */  lwc1       $f0, 0x8($20)
    /* FE798 001FE798 C2001446 */  mul.s      $f3, $f0, $f20
    /* FE79C 001FE79C 0C0080C6 */  lwc1       $f0, 0xC($20)
    /* FE7A0 001FE7A0 1A001446 */  mula.s     $f0, $f20
    /* FE7A4 001FE7A4 02381546 */  mul.s      $f0, $f7, $f21
    /* FE7A8 001FE7A8 82101546 */  mul.s      $f2, $f2, $f21
    /* FE7AC 001FE7AC 42081546 */  mul.s      $f1, $f1, $f21
    /* FE7B0 001FE7B0 00280046 */  add.s      $f0, $f5, $f0
    /* FE7B4 001FE7B4 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE7B8 001FE7B8 00200246 */  add.s      $f0, $f4, $f2
    /* FE7BC 001FE7BC 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE7C0 001FE7C0 00180146 */  add.s      $f0, $f3, $f1
    /* FE7C4 001FE7C4 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE7C8 001FE7C8 1C301546 */  madd.s     $f0, $f6, $f21
    /* FE7CC 001FE7CC 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* FE7D0 001FE7D0 2827050C */  jal        func_00149ca0
    /* FE7D4 001FE7D4 00000000 */   nop
    /* FE7D8 001FE7D8 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FE7DC 001FE7DC 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FE7E0 001FE7E0 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE7E4 001FE7E4 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FE7E8 001FE7E8 000043E4 */  swc1       $f3, 0x0($2)
    /* FE7EC 001FE7EC 040042E4 */  swc1       $f2, 0x4($2)
    /* FE7F0 001FE7F0 080041E4 */  swc1       $f1, 0x8($2)
    /* FE7F4 001FE7F4 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FE7F8 001FE7F8 0C00628E */  lw         $2, 0xC($19)
    /* FE7FC 001FE7FC 8C00A2AF */  sw         $2, 0x8C($29)
    /* FE800 001FE800 8C00A293 */  lbu        $2, 0x8C($29)
    /* FE804 001FE804 06004004 */  bltz       $2, .L001FE820
    /* FE808 001FE808 00000000 */   nop
    /* FE80C 001FE80C 00008244 */  mtc1       $2, $f0
    /* FE810 001FE810 00000000 */  nop
    /* FE814 001FE814 60008046 */  cvt.s.w    $f1, $f0
    /* FE818 001FE818 08000010 */  b          .L001FE83C
    /* FE81C 001FE81C 00000000 */   nop
  .L001FE820:
    /* FE820 001FE820 42180200 */  srl        $3, $2, 1
    /* FE824 001FE824 01004230 */  andi       $2, $2, 0x1
    /* FE828 001FE828 25186200 */  or         $3, $3, $2
    /* FE82C 001FE82C 00008344 */  mtc1       $3, $f0
    /* FE830 001FE830 00000000 */  nop
    /* FE834 001FE834 60008046 */  cvt.s.w    $f1, $f0
    /* FE838 001FE838 40080146 */  add.s      $f1, $f1, $f1
  .L001FE83C:
    /* FE83C 001FE83C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE840 001FE840 02000146 */  mul.s      $f0, $f0, $f1
    /* FE844 001FE844 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE848 001FE848 8D00A293 */  lbu        $2, 0x8D($29)
    /* FE84C 001FE84C 06004004 */  bltz       $2, .L001FE868
    /* FE850 001FE850 00000000 */   nop
    /* FE854 001FE854 00008244 */  mtc1       $2, $f0
    /* FE858 001FE858 00000000 */  nop
    /* FE85C 001FE85C 60008046 */  cvt.s.w    $f1, $f0
    /* FE860 001FE860 08000010 */  b          .L001FE884
    /* FE864 001FE864 00000000 */   nop
  .L001FE868:
    /* FE868 001FE868 42180200 */  srl        $3, $2, 1
    /* FE86C 001FE86C 01004230 */  andi       $2, $2, 0x1
    /* FE870 001FE870 25186200 */  or         $3, $3, $2
    /* FE874 001FE874 00008344 */  mtc1       $3, $f0
    /* FE878 001FE878 00000000 */  nop
    /* FE87C 001FE87C 60008046 */  cvt.s.w    $f1, $f0
    /* FE880 001FE880 40080146 */  add.s      $f1, $f1, $f1
  .L001FE884:
    /* FE884 001FE884 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE888 001FE888 02000146 */  mul.s      $f0, $f0, $f1
    /* FE88C 001FE88C 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE890 001FE890 8E00A293 */  lbu        $2, 0x8E($29)
    /* FE894 001FE894 06004004 */  bltz       $2, .L001FE8B0
    /* FE898 001FE898 00000000 */   nop
    /* FE89C 001FE89C 00008244 */  mtc1       $2, $f0
    /* FE8A0 001FE8A0 00000000 */  nop
    /* FE8A4 001FE8A4 60008046 */  cvt.s.w    $f1, $f0
    /* FE8A8 001FE8A8 08000010 */  b          .L001FE8CC
    /* FE8AC 001FE8AC 00000000 */   nop
  .L001FE8B0:
    /* FE8B0 001FE8B0 42180200 */  srl        $3, $2, 1
    /* FE8B4 001FE8B4 01004230 */  andi       $2, $2, 0x1
    /* FE8B8 001FE8B8 25186200 */  or         $3, $3, $2
    /* FE8BC 001FE8BC 00008344 */  mtc1       $3, $f0
    /* FE8C0 001FE8C0 00000000 */  nop
    /* FE8C4 001FE8C4 60008046 */  cvt.s.w    $f1, $f0
    /* FE8C8 001FE8C8 40080146 */  add.s      $f1, $f1, $f1
  .L001FE8CC:
    /* FE8CC 001FE8CC AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE8D0 001FE8D0 02000146 */  mul.s      $f0, $f0, $f1
    /* FE8D4 001FE8D4 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE8D8 001FE8D8 8F00A293 */  lbu        $2, 0x8F($29)
    /* FE8DC 001FE8DC 06004004 */  bltz       $2, .L001FE8F8
    /* FE8E0 001FE8E0 00000000 */   nop
    /* FE8E4 001FE8E4 00008244 */  mtc1       $2, $f0
    /* FE8E8 001FE8E8 00000000 */  nop
    /* FE8EC 001FE8EC 60008046 */  cvt.s.w    $f1, $f0
    /* FE8F0 001FE8F0 08000010 */  b          .L001FE914
    /* FE8F4 001FE8F4 00000000 */   nop
  .L001FE8F8:
    /* FE8F8 001FE8F8 42180200 */  srl        $3, $2, 1
    /* FE8FC 001FE8FC 01004230 */  andi       $2, $2, 0x1
    /* FE900 001FE900 25186200 */  or         $3, $3, $2
    /* FE904 001FE904 00008344 */  mtc1       $3, $f0
    /* FE908 001FE908 00000000 */  nop
    /* FE90C 001FE90C 60008046 */  cvt.s.w    $f1, $f0
    /* FE910 001FE910 40080146 */  add.s      $f1, $f1, $f1
  .L001FE914:
    /* FE914 001FE914 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FE918 001FE918 C2000146 */  mul.s      $f3, $f0, $f1
    /* FE91C 001FE91C 7C00A3E7 */  swc1       $f3, 0x7C($29)
    /* FE920 001FE920 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* FE924 001FE924 100000C6 */  lwc1       $f0, 0x10($16)
    /* FE928 001FE928 C2090046 */  mul.s      $f7, $f1, $f0
    /* FE92C 001FE92C 7000A7E7 */  swc1       $f7, 0x70($29)
    /* FE930 001FE930 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* FE934 001FE934 140000C6 */  lwc1       $f0, 0x14($16)
    /* FE938 001FE938 82080046 */  mul.s      $f2, $f1, $f0
    /* FE93C 001FE93C 7400A2E7 */  swc1       $f2, 0x74($29)
    /* FE940 001FE940 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE944 001FE944 180000C6 */  lwc1       $f0, 0x18($16)
    /* FE948 001FE948 42080046 */  mul.s      $f1, $f1, $f0
    /* FE94C 001FE94C 7800A1E7 */  swc1       $f1, 0x78($29)
    /* FE950 001FE950 1C0000C6 */  lwc1       $f0, 0x1C($16)
    /* FE954 001FE954 82190046 */  mul.s      $f6, $f3, $f0
    /* FE958 001FE958 7C00A6E7 */  swc1       $f6, 0x7C($29)
    /* FE95C 001FE95C 100080C6 */  lwc1       $f0, 0x10($20)
    /* FE960 001FE960 42011446 */  mul.s      $f5, $f0, $f20
    /* FE964 001FE964 140080C6 */  lwc1       $f0, 0x14($20)
    /* FE968 001FE968 02011446 */  mul.s      $f4, $f0, $f20
    /* FE96C 001FE96C 180080C6 */  lwc1       $f0, 0x18($20)
    /* FE970 001FE970 C2001446 */  mul.s      $f3, $f0, $f20
    /* FE974 001FE974 1C0080C6 */  lwc1       $f0, 0x1C($20)
    /* FE978 001FE978 1A001446 */  mula.s     $f0, $f20
    /* FE97C 001FE97C 02381546 */  mul.s      $f0, $f7, $f21
    /* FE980 001FE980 82101546 */  mul.s      $f2, $f2, $f21
    /* FE984 001FE984 42081546 */  mul.s      $f1, $f1, $f21
    /* FE988 001FE988 00280046 */  add.s      $f0, $f5, $f0
    /* FE98C 001FE98C 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FE990 001FE990 00200246 */  add.s      $f0, $f4, $f2
    /* FE994 001FE994 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FE998 001FE998 00180146 */  add.s      $f0, $f3, $f1
    /* FE99C 001FE99C 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FE9A0 001FE9A0 1C301546 */  madd.s     $f0, $f6, $f21
    /* FE9A4 001FE9A4 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* FE9A8 001FE9A8 3827050C */  jal        func_00149ce0
    /* FE9AC 001FE9AC 00000000 */   nop
    /* FE9B0 001FE9B0 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FE9B4 001FE9B4 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FE9B8 001FE9B8 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FE9BC 001FE9BC 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FE9C0 001FE9C0 000043E4 */  swc1       $f3, 0x0($2)
    /* FE9C4 001FE9C4 040042E4 */  swc1       $f2, 0x4($2)
    /* FE9C8 001FE9C8 080041E4 */  swc1       $f1, 0x8($2)
    /* FE9CC 001FE9CC 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FE9D0 001FE9D0 5F000010 */  b          .L001FEB50
    /* FE9D4 001FE9D4 00000000 */   nop
  .L001FE9D8:
    /* FE9D8 001FE9D8 06006296 */  lhu        $2, 0x6($19)
    /* FE9DC 001FE9DC 23102202 */  subu       $2, $17, $2
    /* FE9E0 001FE9E0 15004216 */  bne        $18, $2, .L001FEA38
    /* FE9E4 001FE9E4 00000000 */   nop
    /* FE9E8 001FE9E8 2827050C */  jal        func_00149ca0
    /* FE9EC 001FE9EC 00000000 */   nop
    /* FE9F0 001FE9F0 000043C4 */  lwc1       $f3, 0x0($2)
    /* FE9F4 001FE9F4 040042C4 */  lwc1       $f2, 0x4($2)
    /* FE9F8 001FE9F8 080041C4 */  lwc1       $f1, 0x8($2)
    /* FE9FC 001FE9FC 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* FEA00 001FEA00 000083E6 */  swc1       $f3, 0x0($20)
    /* FEA04 001FEA04 040082E6 */  swc1       $f2, 0x4($20)
    /* FEA08 001FEA08 080081E6 */  swc1       $f1, 0x8($20)
    /* FEA0C 001FEA0C 0C0080E6 */  swc1       $f0, 0xC($20)
    /* FEA10 001FEA10 3827050C */  jal        func_00149ce0
    /* FEA14 001FEA14 00000000 */   nop
    /* FEA18 001FEA18 000043C4 */  lwc1       $f3, 0x0($2)
    /* FEA1C 001FEA1C 040042C4 */  lwc1       $f2, 0x4($2)
    /* FEA20 001FEA20 080041C4 */  lwc1       $f1, 0x8($2)
    /* FEA24 001FEA24 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* FEA28 001FEA28 100083E6 */  swc1       $f3, 0x10($20)
    /* FEA2C 001FEA2C 140082E6 */  swc1       $f2, 0x14($20)
    /* FEA30 001FEA30 180081E6 */  swc1       $f1, 0x18($20)
    /* FEA34 001FEA34 1C0080E6 */  swc1       $f0, 0x1C($20)
  .L001FEA38:
    /* FEA38 001FEA38 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FEA3C 001FEA3C 00008244 */  mtc1       $2, $f0
    /* FEA40 001FEA40 00000000 */  nop
    /* FEA44 001FEA44 01051546 */  sub.s      $f20, $f0, $f21
    /* FEA48 001FEA48 000000C6 */  lwc1       $f0, 0x0($16)
    /* FEA4C 001FEA4C C2011446 */  mul.s      $f7, $f0, $f20
    /* FEA50 001FEA50 040000C6 */  lwc1       $f0, 0x4($16)
    /* FEA54 001FEA54 82011446 */  mul.s      $f6, $f0, $f20
    /* FEA58 001FEA58 080000C6 */  lwc1       $f0, 0x8($16)
    /* FEA5C 001FEA5C 42011446 */  mul.s      $f5, $f0, $f20
    /* FEA60 001FEA60 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* FEA64 001FEA64 1A001446 */  mula.s     $f0, $f20
    /* FEA68 001FEA68 000080C6 */  lwc1       $f0, 0x0($20)
    /* FEA6C 001FEA6C 02011546 */  mul.s      $f4, $f0, $f21
    /* FEA70 001FEA70 040080C6 */  lwc1       $f0, 0x4($20)
    /* FEA74 001FEA74 C2001546 */  mul.s      $f3, $f0, $f21
    /* FEA78 001FEA78 080080C6 */  lwc1       $f0, 0x8($20)
    /* FEA7C 001FEA7C 82001546 */  mul.s      $f2, $f0, $f21
    /* FEA80 001FEA80 0C0081C6 */  lwc1       $f1, 0xC($20)
    /* FEA84 001FEA84 00380446 */  add.s      $f0, $f7, $f4
    /* FEA88 001FEA88 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FEA8C 001FEA8C 00300346 */  add.s      $f0, $f6, $f3
    /* FEA90 001FEA90 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FEA94 001FEA94 00280246 */  add.s      $f0, $f5, $f2
    /* FEA98 001FEA98 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FEA9C 001FEA9C 1C081546 */  madd.s     $f0, $f1, $f21
    /* FEAA0 001FEAA0 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* FEAA4 001FEAA4 2827050C */  jal        func_00149ca0
    /* FEAA8 001FEAA8 00000000 */   nop
    /* FEAAC 001FEAAC 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FEAB0 001FEAB0 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FEAB4 001FEAB4 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FEAB8 001FEAB8 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FEABC 001FEABC 000043E4 */  swc1       $f3, 0x0($2)
    /* FEAC0 001FEAC0 040042E4 */  swc1       $f2, 0x4($2)
    /* FEAC4 001FEAC4 080041E4 */  swc1       $f1, 0x8($2)
    /* FEAC8 001FEAC8 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FEACC 001FEACC 100000C6 */  lwc1       $f0, 0x10($16)
    /* FEAD0 001FEAD0 C2011446 */  mul.s      $f7, $f0, $f20
    /* FEAD4 001FEAD4 140000C6 */  lwc1       $f0, 0x14($16)
    /* FEAD8 001FEAD8 82011446 */  mul.s      $f6, $f0, $f20
    /* FEADC 001FEADC 180000C6 */  lwc1       $f0, 0x18($16)
    /* FEAE0 001FEAE0 42011446 */  mul.s      $f5, $f0, $f20
    /* FEAE4 001FEAE4 1C0000C6 */  lwc1       $f0, 0x1C($16)
    /* FEAE8 001FEAE8 1A001446 */  mula.s     $f0, $f20
    /* FEAEC 001FEAEC 100080C6 */  lwc1       $f0, 0x10($20)
    /* FEAF0 001FEAF0 02011546 */  mul.s      $f4, $f0, $f21
    /* FEAF4 001FEAF4 140080C6 */  lwc1       $f0, 0x14($20)
    /* FEAF8 001FEAF8 C2001546 */  mul.s      $f3, $f0, $f21
    /* FEAFC 001FEAFC 180080C6 */  lwc1       $f0, 0x18($20)
    /* FEB00 001FEB00 82001546 */  mul.s      $f2, $f0, $f21
    /* FEB04 001FEB04 1C0081C6 */  lwc1       $f1, 0x1C($20)
    /* FEB08 001FEB08 00380446 */  add.s      $f0, $f7, $f4
    /* FEB0C 001FEB0C 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FEB10 001FEB10 00300346 */  add.s      $f0, $f6, $f3
    /* FEB14 001FEB14 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FEB18 001FEB18 00280246 */  add.s      $f0, $f5, $f2
    /* FEB1C 001FEB1C 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FEB20 001FEB20 1C081546 */  madd.s     $f0, $f1, $f21
    /* FEB24 001FEB24 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* FEB28 001FEB28 3827050C */  jal        func_00149ce0
    /* FEB2C 001FEB2C 00000000 */   nop
    /* FEB30 001FEB30 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FEB34 001FEB34 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FEB38 001FEB38 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FEB3C 001FEB3C 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FEB40 001FEB40 000043E4 */  swc1       $f3, 0x0($2)
    /* FEB44 001FEB44 040042E4 */  swc1       $f2, 0x4($2)
    /* FEB48 001FEB48 080041E4 */  swc1       $f1, 0x8($2)
    /* FEB4C 001FEB4C 0C0040E4 */  swc1       $f0, 0xC($2)
  .L001FEB50:
    /* FEB50 001FEB50 6000BFDF */  ld         $31, 0x60($29)
    /* FEB54 001FEB54 5000B47B */  lq         $20, 0x50($29)
    /* FEB58 001FEB58 4000B37B */  lq         $19, 0x40($29)
    /* FEB5C 001FEB5C 3000B27B */  lq         $18, 0x30($29)
    /* FEB60 001FEB60 2000B17B */  lq         $17, 0x20($29)
    /* FEB64 001FEB64 1000B07B */  lq         $16, 0x10($29)
    /* FEB68 001FEB68 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* FEB6C 001FEB6C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* FEB70 001FEB70 9000BD27 */  addiu      $29, $29, 0x90
    /* FEB74 001FEB74 0800E003 */  jr         $31
    /* FEB78 001FEB78 00000000 */   nop
    /* FEB7C 001FEB7C 00000000 */  nop
.size func_001fe090, 0xaf0
