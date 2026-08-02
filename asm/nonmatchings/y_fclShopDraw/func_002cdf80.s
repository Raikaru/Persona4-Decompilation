.section .text
.set noat
.set noreorder
glabel func_002cdf80
    /* 1CDF80 002CDF80 E0FDBD27 */  addiu      $29, $29, -0x220
    /* 1CDF84 002CDF84 B000BFFF */  sd         $31, 0xB0($29)
    /* 1CDF88 002CDF88 A000BE7F */  sq         $30, 0xA0($29)
    /* 1CDF8C 002CDF8C 9000B77F */  sq         $23, 0x90($29)
    /* 1CDF90 002CDF90 8000B67F */  sq         $22, 0x80($29)
    /* 1CDF94 002CDF94 7000B57F */  sq         $21, 0x70($29)
    /* 1CDF98 002CDF98 6000B47F */  sq         $20, 0x60($29)
    /* 1CDF9C 002CDF9C 5000B37F */  sq         $19, 0x50($29)
    /* 1CDFA0 002CDFA0 4000B27F */  sq         $18, 0x40($29)
    /* 1CDFA4 002CDFA4 3000B17F */  sq         $17, 0x30($29)
    /* 1CDFA8 002CDFA8 2000B07F */  sq         $16, 0x20($29)
    /* 1CDFAC 002CDFAC 1000B4E7 */  swc1       $f20, 0x10($29)
    /* 1CDFB0 002CDFB0 2DA08000 */  daddu      $20, $4, $0
    /* 1CDFB4 002CDFB4 D700A5A3 */  sb         $5, 0xD7($29)
    /* 1CDFB8 002CDFB8 3800908C */  lw         $16, 0x38($4)
    /* 1CDFBC 002CDFBC 11000282 */  lb         $2, 0x11($16)
    /* 1CDFC0 002CDFC0 80100200 */  sll        $2, $2, 2
    /* 1CDFC4 002CDFC4 21105000 */  addu       $2, $2, $16
    /* 1CDFC8 002CDFC8 180F448C */  lw         $4, 0xF18($2)
    /* 1CDFCC 002CDFCC C0890B0C */  jal        func_002e2700
    /* 1CDFD0 002CDFD0 00000000 */   nop
    /* 1CDFD4 002CDFD4 3C940200 */  dsll32     $18, $2, 16
    /* 1CDFD8 002CDFD8 3F941200 */  dsra32     $18, $18, 16
    /* 1CDFDC 002CDFDC 11000282 */  lb         $2, 0x11($16)
    /* 1CDFE0 002CDFE0 80100200 */  sll        $2, $2, 2
    /* 1CDFE4 002CDFE4 21105000 */  addu       $2, $2, $16
    /* 1CDFE8 002CDFE8 02000586 */  lh         $5, 0x2($16)
    /* 1CDFEC 002CDFEC 180F448C */  lw         $4, 0xF18($2)
    /* 1CDFF0 002CDFF0 0C8A0B0C */  jal        func_002e2830
    /* 1CDFF4 002CDFF4 00000000 */   nop
    /* 1CDFF8 002CDFF8 2D884000 */  daddu      $17, $2, $0
    /* 1CDFFC 002CDFFC 2D980000 */  daddu      $19, $0, $0
    /* 1CE000 002CE000 0B000010 */  b          .L002CE030
    /* 1CE004 002CE004 00000000 */   nop
  .L002CE008:
    /* 1CE008 002CE008 80100300 */  sll        $2, $3, 2
    /* 1CE00C 002CE00C 21100202 */  addu       $2, $16, $2
    /* 1CE010 002CE010 400E448C */  lw         $4, 0xE40($2)
    /* 1CE014 002CE014 2D280000 */  daddu      $5, $0, $0
    /* 1CE018 002CE018 01000624 */  addiu      $6, $0, 0x1
    /* 1CE01C 002CE01C 3C810B0C */  jal        func_002e04f0
    /* 1CE020 002CE020 00000000 */   nop
    /* 1CE024 002CE024 01006226 */  addiu      $2, $19, 0x1
    /* 1CE028 002CE028 3C9C0200 */  dsll32     $19, $2, 16
    /* 1CE02C 002CE02C 3F9C1300 */  dsra32     $19, $19, 16
  .L002CE030:
    /* 1CE030 002CE030 3C1C1300 */  dsll32     $3, $19, 16
    /* 1CE034 002CE034 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CE038 002CE038 03006228 */  slti       $2, $3, 0x3
    /* 1CE03C 002CE03C F2FF4014 */  bnez       $2, .L002CE008
    /* 1CE040 002CE040 00000000 */   nop
    /* 1CE044 002CE044 11000282 */  lb         $2, 0x11($16)
    /* 1CE048 002CE048 80100200 */  sll        $2, $2, 2
    /* 1CE04C 002CE04C 21105000 */  addu       $2, $2, $16
    /* 1CE050 002CE050 180F448C */  lw         $4, 0xF18($2)
    /* 1CE054 002CE054 808A0B0C */  jal        func_002e2a00
    /* 1CE058 002CE058 00000000 */   nop
    /* 1CE05C 002CE05C 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CE060 002CE060 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CE064 002CE064 3A0D6014 */  bnez       $3, .L002D1550
    /* 1CE068 002CE068 00000000 */   nop
    /* 1CE06C 002CE06C 11001382 */  lb         $19, 0x11($16)
    /* 1CE070 002CE070 80101300 */  sll        $2, $19, 2
    /* 1CE074 002CE074 21105000 */  addu       $2, $2, $16
    /* 1CE078 002CE078 180F448C */  lw         $4, 0xF18($2)
    /* 1CE07C 002CE07C BC890B0C */  jal        func_002e26f0
    /* 1CE080 002CE080 00000000 */   nop
    /* 1CE084 002CE084 7500033C */  lui        $3, %hi(D_00748908)
    /* 1CE088 002CE088 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1CE08C 002CE08C 21187300 */  addu       $3, $3, $19
    /* 1CE090 002CE090 00006380 */  lb         $3, 0x0($3)
    /* 1CE094 002CE094 2A086200 */  slt        $1, $3, $2
    /* 1CE098 002CE098 5F002014 */  bnez       $1, .L002CE218
    /* 1CE09C 002CE09C 00000000 */   nop
    /* 1CE0A0 002CE0A0 EA42023C */  lui        $2, (0x42EA0000 >> 16)
    /* 1CE0A4 002CE0A4 00608244 */  mtc1       $2, $f12
    /* 1CE0A8 002CE0A8 680E048E */  lw         $4, 0xE68($16)
    /* 1CE0AC 002CE0AC 57000524 */  addiu      $5, $0, 0x57
    /* 1CE0B0 002CE0B0 78820B0C */  jal        func_002e09e0
    /* 1CE0B4 002CE0B4 00000000 */   nop
    /* 1CE0B8 002CE0B8 1802A427 */  addiu      $4, $29, 0x218
    /* 1CE0BC 002CE0BC 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CE0C0 002CE0C0 2D30A000 */  daddu      $6, $5, $0
    /* 1CE0C4 002CE0C4 2D38A000 */  daddu      $7, $5, $0
    /* 1CE0C8 002CE0C8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CE0CC 002CE0CC 98CA0A0C */  jal        func_002b2a60
    /* 1CE0D0 002CE0D0 00000000 */   nop
    /* 1CE0D4 002CE0D4 680E048E */  lw         $4, 0xE68($16)
    /* 1CE0D8 002CE0D8 38810B0C */  jal        func_002e04e0
    /* 1CE0DC 002CE0DC 00000000 */   nop
    /* 1CE0E0 002CE0E0 1802A693 */  lbu        $6, 0x218($29)
    /* 1CE0E4 002CE0E4 1902A593 */  lbu        $5, 0x219($29)
    /* 1CE0E8 002CE0E8 1A02A493 */  lbu        $4, 0x21A($29)
    /* 1CE0EC 002CE0EC 1B02A393 */  lbu        $3, 0x21B($29)
    /* 1CE0F0 002CE0F0 790046A0 */  sb         $6, 0x79($2)
    /* 1CE0F4 002CE0F4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CE0F8 002CE0F8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CE0FC 002CE0FC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CE100 002CE100 EC42023C */  lui        $2, (0x42EC0000 >> 16)
    /* 1CE104 002CE104 00608244 */  mtc1       $2, $f12
    /* 1CE108 002CE108 6C0E048E */  lw         $4, 0xE6C($16)
    /* 1CE10C 002CE10C 56000524 */  addiu      $5, $0, 0x56
    /* 1CE110 002CE110 78820B0C */  jal        func_002e09e0
    /* 1CE114 002CE114 00000000 */   nop
    /* 1CE118 002CE118 1402A427 */  addiu      $4, $29, 0x214
    /* 1CE11C 002CE11C 6B000524 */  addiu      $5, $0, 0x6B
    /* 1CE120 002CE120 2D30A000 */  daddu      $6, $5, $0
    /* 1CE124 002CE124 2D38A000 */  daddu      $7, $5, $0
    /* 1CE128 002CE128 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CE12C 002CE12C 98CA0A0C */  jal        func_002b2a60
    /* 1CE130 002CE130 00000000 */   nop
    /* 1CE134 002CE134 6C0E048E */  lw         $4, 0xE6C($16)
    /* 1CE138 002CE138 38810B0C */  jal        func_002e04e0
    /* 1CE13C 002CE13C 00000000 */   nop
    /* 1CE140 002CE140 1402A693 */  lbu        $6, 0x214($29)
    /* 1CE144 002CE144 1502A593 */  lbu        $5, 0x215($29)
    /* 1CE148 002CE148 1602A493 */  lbu        $4, 0x216($29)
    /* 1CE14C 002CE14C 1702A393 */  lbu        $3, 0x217($29)
    /* 1CE150 002CE150 790046A0 */  sb         $6, 0x79($2)
    /* 1CE154 002CE154 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CE158 002CE158 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CE15C 002CE15C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CE160 002CE160 EE42023C */  lui        $2, (0x42EE0000 >> 16)
    /* 1CE164 002CE164 00608244 */  mtc1       $2, $f12
    /* 1CE168 002CE168 700E048E */  lw         $4, 0xE70($16)
    /* 1CE16C 002CE16C 56000524 */  addiu      $5, $0, 0x56
    /* 1CE170 002CE170 78820B0C */  jal        func_002e09e0
    /* 1CE174 002CE174 00000000 */   nop
    /* 1CE178 002CE178 1002A427 */  addiu      $4, $29, 0x210
    /* 1CE17C 002CE17C 6B000524 */  addiu      $5, $0, 0x6B
    /* 1CE180 002CE180 2D30A000 */  daddu      $6, $5, $0
    /* 1CE184 002CE184 2D38A000 */  daddu      $7, $5, $0
    /* 1CE188 002CE188 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CE18C 002CE18C 98CA0A0C */  jal        func_002b2a60
    /* 1CE190 002CE190 00000000 */   nop
    /* 1CE194 002CE194 700E048E */  lw         $4, 0xE70($16)
    /* 1CE198 002CE198 38810B0C */  jal        func_002e04e0
    /* 1CE19C 002CE19C 00000000 */   nop
    /* 1CE1A0 002CE1A0 1002A693 */  lbu        $6, 0x210($29)
    /* 1CE1A4 002CE1A4 1102A593 */  lbu        $5, 0x211($29)
    /* 1CE1A8 002CE1A8 1202A493 */  lbu        $4, 0x212($29)
    /* 1CE1AC 002CE1AC 1302A393 */  lbu        $3, 0x213($29)
    /* 1CE1B0 002CE1B0 790046A0 */  sb         $6, 0x79($2)
    /* 1CE1B4 002CE1B4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CE1B8 002CE1B8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CE1BC 002CE1BC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CE1C0 002CE1C0 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1CE1C4 002CE1C4 2D280000 */  daddu      $5, $0, $0
    /* 1CE1C8 002CE1C8 01000624 */  addiu      $6, $0, 0x1
    /* 1CE1CC 002CE1CC 3C810B0C */  jal        func_002e04f0
    /* 1CE1D0 002CE1D0 00000000 */   nop
    /* 1CE1D4 002CE1D4 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CE1D8 002CE1D8 2D280000 */  daddu      $5, $0, $0
    /* 1CE1DC 002CE1DC 01000624 */  addiu      $6, $0, 0x1
    /* 1CE1E0 002CE1E0 3C810B0C */  jal        func_002e04f0
    /* 1CE1E4 002CE1E4 00000000 */   nop
    /* 1CE1E8 002CE1E8 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CE1EC 002CE1EC 2D280000 */  daddu      $5, $0, $0
    /* 1CE1F0 002CE1F0 01000624 */  addiu      $6, $0, 0x1
    /* 1CE1F4 002CE1F4 3C810B0C */  jal        func_002e04f0
    /* 1CE1F8 002CE1F8 00000000 */   nop
    /* 1CE1FC 002CE1FC 900C048E */  lw         $4, 0xC90($16)
    /* 1CE200 002CE200 2D280000 */  daddu      $5, $0, $0
    /* 1CE204 002CE204 01000624 */  addiu      $6, $0, 0x1
    /* 1CE208 002CE208 3C810B0C */  jal        func_002e04f0
    /* 1CE20C 002CE20C 00000000 */   nop
    /* 1CE210 002CE210 CC030010 */  b          .L002CF144
    /* 1CE214 002CE214 00000000 */   nop
  .L002CE218:
    /* 1CE218 002CE218 80101300 */  sll        $2, $19, 2
    /* 1CE21C 002CE21C 21105000 */  addu       $2, $2, $16
    /* 1CE220 002CE220 180F448C */  lw         $4, 0xF18($2)
    /* 1CE224 002CE224 BC890B0C */  jal        func_002e26f0
    /* 1CE228 002CE228 00000000 */   nop
    /* 1CE22C 002CE22C 06004128 */  slti       $1, $2, 0x6
    /* 1CE230 002CE230 4E002014 */  bnez       $1, .L002CE36C
    /* 1CE234 002CE234 00000000 */   nop
    /* 1CE238 002CE238 11000282 */  lb         $2, 0x11($16)
    /* 1CE23C 002CE23C 80100200 */  sll        $2, $2, 2
    /* 1CE240 002CE240 21105000 */  addu       $2, $2, $16
    /* 1CE244 002CE244 180F448C */  lw         $4, 0xF18($2)
    /* 1CE248 002CE248 BC890B0C */  jal        func_002e26f0
    /* 1CE24C 002CE24C 00000000 */   nop
    /* 1CE250 002CE250 06004128 */  slti       $1, $2, 0x6
    /* 1CE254 002CE254 10002014 */  bnez       $1, .L002CE298
    /* 1CE258 002CE258 00000000 */   nop
    /* 1CE25C 002CE25C 11000282 */  lb         $2, 0x11($16)
    /* 1CE260 002CE260 80100200 */  sll        $2, $2, 2
    /* 1CE264 002CE264 21105000 */  addu       $2, $2, $16
    /* 1CE268 002CE268 180F448C */  lw         $4, 0xF18($2)
    /* 1CE26C 002CE26C BC890B0C */  jal        func_002e26f0
    /* 1CE270 002CE270 00000000 */   nop
    /* 1CE274 002CE274 FBFF4224 */  addiu      $2, $2, -0x5
    /* 1CE278 002CE278 00008244 */  mtc1       $2, $f0
    /* 1CE27C 002CE27C 00000000 */  nop
    /* 1CE280 002CE280 60008046 */  cvt.s.w    $f1, $f0
    /* 1CE284 002CE284 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1CE288 002CE288 00008244 */  mtc1       $2, $f0
    /* 1CE28C 002CE28C 00000000 */  nop
    /* 1CE290 002CE290 03000146 */  div.s      $f0, $f0, $f1
    /* 1CE294 002CE294 0C0000E6 */  swc1       $f0, 0xC($16)
  .L002CE298:
    /* 1CE298 002CE298 02000386 */  lh         $3, 0x2($16)
    /* 1CE29C 002CE29C 04000286 */  lh         $2, 0x4($16)
    /* 1CE2A0 002CE2A0 23106200 */  subu       $2, $3, $2
    /* 1CE2A4 002CE2A4 00008244 */  mtc1       $2, $f0
    /* 1CE2A8 002CE2A8 00000000 */  nop
    /* 1CE2AC 002CE2AC E0008046 */  cvt.s.w    $f3, $f0
    /* 1CE2B0 002CE2B0 0C0002C6 */  lwc1       $f2, 0xC($16)
    /* 1CE2B4 002CE2B4 0E43023C */  lui        $2, (0x430E0000 >> 16)
    /* 1CE2B8 002CE2B8 00088244 */  mtc1       $2, $f1
    /* 1CE2BC 002CE2BC 00008044 */  mtc1       $0, $f0
    /* 1CE2C0 002CE2C0 00000000 */  nop
    /* 1CE2C4 002CE2C4 18000146 */  adda.s     $f0, $f1
    /* 1CE2C8 002CE2C8 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1CE2CC 002CE2CC 21020224 */  addiu      $2, $0, 0x221
    /* 1CE2D0 002CE2D0 00008244 */  mtc1       $2, $f0
    /* 1CE2D4 002CE2D4 00000000 */  nop
    /* 1CE2D8 002CE2D8 20038046 */  cvt.s.w    $f12, $f0
    /* 1CE2DC 002CE2DC C801A427 */  addiu      $4, $29, 0x1C8
    /* 1CE2E0 002CE2E0 5CCA0A0C */  jal        func_002b2970
    /* 1CE2E4 002CE2E4 00000000 */   nop
    /* 1CE2E8 002CE2E8 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CE2EC 002CE2EC FE000524 */  addiu      $5, $0, 0xFE
    /* 1CE2F0 002CE2F0 C6000624 */  addiu      $6, $0, 0xC6
    /* 1CE2F4 002CE2F4 31000724 */  addiu      $7, $0, 0x31
    /* 1CE2F8 002CE2F8 8CCA0A0C */  jal        func_002b2a30
    /* 1CE2FC 002CE2FC 00000000 */   nop
    /* 1CE300 002CE300 2D984000 */  daddu      $19, $2, $0
    /* 1CE304 002CE304 940C048E */  lw         $4, 0xC94($16)
    /* 1CE308 002CE308 38810B0C */  jal        func_002e04e0
    /* 1CE30C 002CE30C 00000000 */   nop
    /* 1CE310 002CE310 0A43033C */  lui        $3, (0x430A0000 >> 16)
    /* 1CE314 002CE314 00608344 */  mtc1       $3, $f12
    /* 1CE318 002CE318 36000424 */  addiu      $4, $0, 0x36
    /* 1CE31C 002CE31C C801A5DF */  ld         $5, 0x1C8($29)
    /* 1CE320 002CE320 2D306002 */  daddu      $6, $19, $0
    /* 1CE324 002CE324 62004790 */  lbu        $7, 0x62($2)
    /* 1CE328 002CE328 2D400000 */  daddu      $8, $0, $0
    /* 1CE32C 002CE32C 7900093C */  lui        $9, %hi(D_00794EA0)
    /* 1CE330 002CE330 A04E2925 */  addiu      $9, $9, %lo(D_00794EA0)
    /* 1CE334 002CE334 C8820B0C */  jal        func_002e0b20
    /* 1CE338 002CE338 00000000 */   nop
    /* 1CE33C 002CE33C 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CE340 002CE340 2D280000 */  daddu      $5, $0, $0
    /* 1CE344 002CE344 2D300000 */  daddu      $6, $0, $0
    /* 1CE348 002CE348 3C810B0C */  jal        func_002e04f0
    /* 1CE34C 002CE34C 00000000 */   nop
    /* 1CE350 002CE350 900C048E */  lw         $4, 0xC90($16)
    /* 1CE354 002CE354 2D280000 */  daddu      $5, $0, $0
    /* 1CE358 002CE358 2D300000 */  daddu      $6, $0, $0
    /* 1CE35C 002CE35C 3C810B0C */  jal        func_002e04f0
    /* 1CE360 002CE360 00000000 */   nop
    /* 1CE364 002CE364 0B000010 */  b          .L002CE394
    /* 1CE368 002CE368 00000000 */   nop
  .L002CE36C:
    /* 1CE36C 002CE36C 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CE370 002CE370 2D280000 */  daddu      $5, $0, $0
    /* 1CE374 002CE374 01000624 */  addiu      $6, $0, 0x1
    /* 1CE378 002CE378 3C810B0C */  jal        func_002e04f0
    /* 1CE37C 002CE37C 00000000 */   nop
    /* 1CE380 002CE380 900C048E */  lw         $4, 0xC90($16)
    /* 1CE384 002CE384 2D280000 */  daddu      $5, $0, $0
    /* 1CE388 002CE388 01000624 */  addiu      $6, $0, 0x1
    /* 1CE38C 002CE38C 3C810B0C */  jal        func_002e04f0
    /* 1CE390 002CE390 00000000 */   nop
  .L002CE394:
    /* 1CE394 002CE394 11000282 */  lb         $2, 0x11($16)
    /* 1CE398 002CE398 2E004014 */  bnez       $2, .L002CE454
    /* 1CE39C 002CE39C 00000000 */   nop
    /* 1CE3A0 002CE3A0 02000286 */  lh         $2, 0x2($16)
    /* 1CE3A4 002CE3A4 2B004014 */  bnez       $2, .L002CE454
    /* 1CE3A8 002CE3A8 00000000 */   nop
    /* 1CE3AC 002CE3AC 4E020224 */  addiu      $2, $0, 0x24E
    /* 1CE3B0 002CE3B0 00008244 */  mtc1       $2, $f0
    /* 1CE3B4 002CE3B4 00000000 */  nop
    /* 1CE3B8 002CE3B8 20038046 */  cvt.s.w    $f12, $f0
    /* 1CE3BC 002CE3BC 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1CE3C0 002CE3C0 00688244 */  mtc1       $2, $f13
    /* 1CE3C4 002CE3C4 C001A427 */  addiu      $4, $29, 0x1C0
    /* 1CE3C8 002CE3C8 5CCA0A0C */  jal        func_002b2970
    /* 1CE3CC 002CE3CC 00000000 */   nop
    /* 1CE3D0 002CE3D0 0C02A427 */  addiu      $4, $29, 0x20C
    /* 1CE3D4 002CE3D4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CE3D8 002CE3D8 2D30A000 */  daddu      $6, $5, $0
    /* 1CE3DC 002CE3DC 2D38A000 */  daddu      $7, $5, $0
    /* 1CE3E0 002CE3E0 2D40A000 */  daddu      $8, $5, $0
    /* 1CE3E4 002CE3E4 98CA0A0C */  jal        func_002b2a60
    /* 1CE3E8 002CE3E8 00000000 */   nop
    /* 1CE3EC 002CE3EC 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1CE3F0 002CE3F0 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1CE3F4 002CE3F4 DCA9110C */  jal        func_0046a770
    /* 1CE3F8 002CE3F8 00000000 */   nop
    /* 1CE3FC 002CE3FC 2D884000 */  daddu      $17, $2, $0
    /* 1CE400 002CE400 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1CE404 002CE404 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1CE408 002CE408 DCA9110C */  jal        func_0046a770
    /* 1CE40C 002CE40C 00000000 */   nop
    /* 1CE410 002CE410 0000A2FF */  sd         $2, 0x0($29)
    /* 1CE414 002CE414 AA000224 */  addiu      $2, $0, 0xAA
    /* 1CE418 002CE418 0800A2FF */  sd         $2, 0x8($29)
    /* 1CE41C 002CE41C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1CE420 002CE420 00608244 */  mtc1       $2, $f12
    /* 1CE424 002CE424 C001A4DF */  ld         $4, 0x1C0($29)
    /* 1CE428 002CE428 0C02A58F */  lw         $5, 0x20C($29)
    /* 1CE42C 002CE42C 11000624 */  addiu      $6, $0, 0x11
    /* 1CE430 002CE430 05000724 */  addiu      $7, $0, 0x5
    /* 1CE434 002CE434 200C088E */  lw         $8, 0xC20($16)
    /* 1CE438 002CE438 70000924 */  addiu      $9, $0, 0x70
    /* 1CE43C 002CE43C 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1CE440 002CE440 2D582002 */  daddu      $11, $17, $0
    /* 1CE444 002CE444 342B0B0C */  jal        func_002cacd0
    /* 1CE448 002CE448 00000000 */   nop
    /* 1CE44C 002CE44C 31000010 */  b          .L002CE514
    /* 1CE450 002CE450 00000000 */   nop
  .L002CE454:
    /* 1CE454 002CE454 3C241100 */  dsll32     $4, $17, 16
    /* 1CE458 002CE458 3F240400 */  dsra32     $4, $4, 16
    /* 1CE45C 002CE45C A41A040C */  jal        func_00106a90
    /* 1CE460 002CE460 00000000 */   nop
    /* 1CE464 002CE464 05000324 */  addiu      $3, $0, 0x5
    /* 1CE468 002CE468 1B004300 */  divu       $0, $2, $3
    /* 1CE46C 002CE46C 12980000 */  mflo       $19
    /* 1CE470 002CE470 4E020224 */  addiu      $2, $0, 0x24E
    /* 1CE474 002CE474 00008244 */  mtc1       $2, $f0
    /* 1CE478 002CE478 00000000 */  nop
    /* 1CE47C 002CE47C 20038046 */  cvt.s.w    $f12, $f0
    /* 1CE480 002CE480 7442023C */  lui        $2, (0x42740000 >> 16)
    /* 1CE484 002CE484 00688244 */  mtc1       $2, $f13
    /* 1CE488 002CE488 B801A427 */  addiu      $4, $29, 0x1B8
    /* 1CE48C 002CE48C 5CCA0A0C */  jal        func_002b2970
    /* 1CE490 002CE490 00000000 */   nop
    /* 1CE494 002CE494 0802A427 */  addiu      $4, $29, 0x208
    /* 1CE498 002CE498 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CE49C 002CE49C 2D30A000 */  daddu      $6, $5, $0
    /* 1CE4A0 002CE4A0 2D38A000 */  daddu      $7, $5, $0
    /* 1CE4A4 002CE4A4 2D40A000 */  daddu      $8, $5, $0
    /* 1CE4A8 002CE4A8 98CA0A0C */  jal        func_002b2a60
    /* 1CE4AC 002CE4AC 00000000 */   nop
    /* 1CE4B0 002CE4B0 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1CE4B4 002CE4B4 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1CE4B8 002CE4B8 DCA9110C */  jal        func_0046a770
    /* 1CE4BC 002CE4BC 00000000 */   nop
    /* 1CE4C0 002CE4C0 2D884000 */  daddu      $17, $2, $0
    /* 1CE4C4 002CE4C4 6400043C */  lui        $4, %hi(D_0063FAA0)
    /* 1CE4C8 002CE4C8 A0FA8424 */  addiu      $4, $4, %lo(D_0063FAA0)
    /* 1CE4CC 002CE4CC DCA9110C */  jal        func_0046a770
    /* 1CE4D0 002CE4D0 00000000 */   nop
    /* 1CE4D4 002CE4D4 0000A2FF */  sd         $2, 0x0($29)
    /* 1CE4D8 002CE4D8 AA000224 */  addiu      $2, $0, 0xAA
    /* 1CE4DC 002CE4DC 0800A2FF */  sd         $2, 0x8($29)
    /* 1CE4E0 002CE4E0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1CE4E4 002CE4E4 00608244 */  mtc1       $2, $f12
    /* 1CE4E8 002CE4E8 12000286 */  lh         $2, 0x12($16)
    /* 1CE4EC 002CE4EC 18405300 */  mult       $8, $2, $19
    /* 1CE4F0 002CE4F0 B801A4DF */  ld         $4, 0x1B8($29)
    /* 1CE4F4 002CE4F4 0802A58F */  lw         $5, 0x208($29)
    /* 1CE4F8 002CE4F8 11000624 */  addiu      $6, $0, 0x11
    /* 1CE4FC 002CE4FC 05000724 */  addiu      $7, $0, 0x5
    /* 1CE500 002CE500 70000924 */  addiu      $9, $0, 0x70
    /* 1CE504 002CE504 7A000A24 */  addiu      $10, $0, 0x7A
    /* 1CE508 002CE508 2D582002 */  daddu      $11, $17, $0
    /* 1CE50C 002CE50C 342B0B0C */  jal        func_002cacd0
    /* 1CE510 002CE510 00000000 */   nop
  .L002CE514:
    /* 1CE514 002CE514 6400113C */  lui        $17, %hi(D_0063F888)
    /* 1CE518 002CE518 88F83126 */  addiu      $17, $17, %lo(D_0063F888)
    /* 1CE51C 002CE51C CC0D048E */  lw         $4, 0xDCC($16)
    /* 1CE520 002CE520 01000524 */  addiu      $5, $0, 0x1
    /* 1CE524 002CE524 5C810B0C */  jal        func_002e0570
    /* 1CE528 002CE528 00000000 */   nop
    /* 1CE52C 002CE52C 3C160200 */  dsll32     $2, $2, 24
    /* 1CE530 002CE530 3F160200 */  dsra32     $2, $2, 24
    /* 1CE534 002CE534 0C004014 */  bnez       $2, .L002CE568
    /* 1CE538 002CE538 00000000 */   nop
    /* 1CE53C 002CE53C 04000286 */  lh         $2, 0x4($16)
    /* 1CE540 002CE540 40110200 */  sll        $2, $2, 5
    /* 1CE544 002CE544 00008244 */  mtc1       $2, $f0
    /* 1CE548 002CE548 00000000 */  nop
    /* 1CE54C 002CE54C 60008046 */  cvt.s.w    $f1, $f0
    /* 1CE550 002CE550 040020C6 */  lwc1       $f0, 0x4($17)
    /* 1CE554 002CE554 00050146 */  add.s      $f20, $f0, $f1
    /* 1CE558 002CE558 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1CE55C 002CE55C 38810B0C */  jal        func_002e04e0
    /* 1CE560 002CE560 00000000 */   nop
    /* 1CE564 002CE564 300054E4 */  swc1       $f20, 0x30($2)
  .L002CE568:
    /* 1CE568 002CE568 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CE56C 002CE56C 01000524 */  addiu      $5, $0, 0x1
    /* 1CE570 002CE570 5C810B0C */  jal        func_002e0570
    /* 1CE574 002CE574 00000000 */   nop
    /* 1CE578 002CE578 3C160200 */  dsll32     $2, $2, 24
    /* 1CE57C 002CE57C 3F160200 */  dsra32     $2, $2, 24
    /* 1CE580 002CE580 0C004014 */  bnez       $2, .L002CE5B4
    /* 1CE584 002CE584 00000000 */   nop
    /* 1CE588 002CE588 04000286 */  lh         $2, 0x4($16)
    /* 1CE58C 002CE58C 40110200 */  sll        $2, $2, 5
    /* 1CE590 002CE590 00008244 */  mtc1       $2, $f0
    /* 1CE594 002CE594 00000000 */  nop
    /* 1CE598 002CE598 60008046 */  cvt.s.w    $f1, $f0
    /* 1CE59C 002CE59C 040020C6 */  lwc1       $f0, 0x4($17)
    /* 1CE5A0 002CE5A0 00050146 */  add.s      $f20, $f0, $f1
    /* 1CE5A4 002CE5A4 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CE5A8 002CE5A8 38810B0C */  jal        func_002e04e0
    /* 1CE5AC 002CE5AC 00000000 */   nop
    /* 1CE5B0 002CE5B0 300054E4 */  swc1       $f20, 0x30($2)
  .L002CE5B4:
    /* 1CE5B4 002CE5B4 680E048E */  lw         $4, 0xE68($16)
    /* 1CE5B8 002CE5B8 2D280000 */  daddu      $5, $0, $0
    /* 1CE5BC 002CE5BC 01000624 */  addiu      $6, $0, 0x1
    /* 1CE5C0 002CE5C0 3C810B0C */  jal        func_002e04f0
    /* 1CE5C4 002CE5C4 00000000 */   nop
    /* 1CE5C8 002CE5C8 6C0E048E */  lw         $4, 0xE6C($16)
    /* 1CE5CC 002CE5CC 2D280000 */  daddu      $5, $0, $0
    /* 1CE5D0 002CE5D0 01000624 */  addiu      $6, $0, 0x1
    /* 1CE5D4 002CE5D4 3C810B0C */  jal        func_002e04f0
    /* 1CE5D8 002CE5D8 00000000 */   nop
    /* 1CE5DC 002CE5DC 700E048E */  lw         $4, 0xE70($16)
    /* 1CE5E0 002CE5E0 2D280000 */  daddu      $5, $0, $0
    /* 1CE5E4 002CE5E4 01000624 */  addiu      $6, $0, 0x1
    /* 1CE5E8 002CE5E8 3C810B0C */  jal        func_002e04f0
    /* 1CE5EC 002CE5EC 00000000 */   nop
    /* 1CE5F0 002CE5F0 11000282 */  lb         $2, 0x11($16)
    /* 1CE5F4 002CE5F4 80100200 */  sll        $2, $2, 2
    /* 1CE5F8 002CE5F8 21105000 */  addu       $2, $2, $16
    /* 1CE5FC 002CE5FC 180F448C */  lw         $4, 0xF18($2)
    /* 1CE600 002CE600 BC890B0C */  jal        func_002e26f0
    /* 1CE604 002CE604 00000000 */   nop
    /* 1CE608 002CE608 2D200000 */  daddu      $4, $0, $0
    /* 1CE60C 002CE60C 2D284000 */  daddu      $5, $2, $0
    /* 1CE610 002CE610 05000624 */  addiu      $6, $0, 0x5
    /* 1CE614 002CE614 2D380000 */  daddu      $7, $0, $0
    /* 1CE618 002CE618 01000824 */  addiu      $8, $0, 0x1
    /* 1CE61C 002CE61C 2CCB0A0C */  jal        func_002b2cb0
    /* 1CE620 002CE620 00000000 */   nop
    /* 1CE624 002CE624 3C2E0200 */  dsll32     $5, $2, 24
    /* 1CE628 002CE628 3F2E0500 */  dsra32     $5, $5, 24
    /* 1CE62C 002CE62C 02000486 */  lh         $4, 0x2($16)
    /* 1CE630 002CE630 04000386 */  lh         $3, 0x4($16)
    /* 1CE634 002CE634 23188300 */  subu       $3, $4, $3
    /* 1CE638 002CE638 3CAC0300 */  dsll32     $21, $3, 16
    /* 1CE63C 002CE63C 3FAC1500 */  dsra32     $21, $21, 16
    /* 1CE640 002CE640 2DB80000 */  daddu      $23, $0, $0
    /* 1CE644 002CE644 2118A502 */  addu       $3, $21, $5
    /* 1CE648 002CE648 C000A37F */  sq         $3, 0xC0($29)
    /* 1CE64C 002CE64C B7020010 */  b          .L002CF12C
    /* 1CE650 002CE650 00000000 */   nop
  .L002CE654:
    /* 1CE654 002CE654 11000282 */  lb         $2, 0x11($16)
    /* 1CE658 002CE658 80100200 */  sll        $2, $2, 2
    /* 1CE65C 002CE65C 21100202 */  addu       $2, $16, $2
    /* 1CE660 002CE660 180F448C */  lw         $4, 0xF18($2)
    /* 1CE664 002CE664 BC890B0C */  jal        func_002e26f0
    /* 1CE668 002CE668 00000000 */   nop
    /* 1CE66C 002CE66C 2A082202 */  slt        $1, $17, $2
    /* 1CE670 002CE670 A8022010 */  beqz       $1, .L002CF114
    /* 1CE674 002CE674 00000000 */   nop
    /* 1CE678 002CE678 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CE67C 002CE67C 38810B0C */  jal        func_002e04e0
    /* 1CE680 002CE680 00000000 */   nop
    /* 1CE684 002CE684 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CE688 002CE688 AE000524 */  addiu      $5, $0, 0xAE
    /* 1CE68C 002CE68C 2D300000 */  daddu      $6, $0, $0
    /* 1CE690 002CE690 62004790 */  lbu        $7, 0x62($2)
    /* 1CE694 002CE694 8CCA0A0C */  jal        func_002b2a30
    /* 1CE698 002CE698 00000000 */   nop
    /* 1CE69C 002CE69C D000A2AF */  sw         $2, 0xD0($29)
    /* 1CE6A0 002CE6A0 2D200000 */  daddu      $4, $0, $0
    /* 1CE6A4 002CE6A4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CE6A8 002CE6A8 AE000624 */  addiu      $6, $0, 0xAE
    /* 1CE6AC 002CE6AC 2D380000 */  daddu      $7, $0, $0
    /* 1CE6B0 002CE6B0 8CCA0A0C */  jal        func_002b2a30
    /* 1CE6B4 002CE6B4 00000000 */   nop
    /* 1CE6B8 002CE6B8 2D984000 */  daddu      $19, $2, $0
    /* 1CE6BC 002CE6BC 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CE6C0 002CE6C0 38810B0C */  jal        func_002e04e0
    /* 1CE6C4 002CE6C4 00000000 */   nop
    /* 1CE6C8 002CE6C8 1C02A427 */  addiu      $4, $29, 0x21C
    /* 1CE6CC 002CE6CC FF000524 */  addiu      $5, $0, 0xFF
    /* 1CE6D0 002CE6D0 AE000624 */  addiu      $6, $0, 0xAE
    /* 1CE6D4 002CE6D4 2D380000 */  daddu      $7, $0, $0
    /* 1CE6D8 002CE6D8 62004890 */  lbu        $8, 0x62($2)
    /* 1CE6DC 002CE6DC 98CA0A0C */  jal        func_002b2a60
    /* 1CE6E0 002CE6E0 00000000 */   nop
    /* 1CE6E4 002CE6E4 2D200000 */  daddu      $4, $0, $0
    /* 1CE6E8 002CE6E8 FE000524 */  addiu      $5, $0, 0xFE
    /* 1CE6EC 002CE6EC C7000624 */  addiu      $6, $0, 0xC7
    /* 1CE6F0 002CE6F0 31000724 */  addiu      $7, $0, 0x31
    /* 1CE6F4 002CE6F4 8CCA0A0C */  jal        func_002b2a30
    /* 1CE6F8 002CE6F8 00000000 */   nop
    /* 1CE6FC 002CE6FC 2DB04000 */  daddu      $22, $2, $0
    /* 1CE700 002CE700 02000286 */  lh         $2, 0x2($16)
    /* 1CE704 002CE704 23002216 */  bne        $17, $2, .L002CE794
    /* 1CE708 002CE708 00000000 */   nop
    /* 1CE70C 002CE70C 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CE710 002CE710 38810B0C */  jal        func_002e04e0
    /* 1CE714 002CE714 00000000 */   nop
    /* 1CE718 002CE718 2D000424 */  addiu      $4, $0, 0x2D
    /* 1CE71C 002CE71C 2D288000 */  daddu      $5, $4, $0
    /* 1CE720 002CE720 2D308000 */  daddu      $6, $4, $0
    /* 1CE724 002CE724 62004790 */  lbu        $7, 0x62($2)
    /* 1CE728 002CE728 8CCA0A0C */  jal        func_002b2a30
    /* 1CE72C 002CE72C 00000000 */   nop
    /* 1CE730 002CE730 D000A2AF */  sw         $2, 0xD0($29)
    /* 1CE734 002CE734 2D200000 */  daddu      $4, $0, $0
    /* 1CE738 002CE738 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CE73C 002CE73C 2D30A000 */  daddu      $6, $5, $0
    /* 1CE740 002CE740 2D38A000 */  daddu      $7, $5, $0
    /* 1CE744 002CE744 8CCA0A0C */  jal        func_002b2a30
    /* 1CE748 002CE748 00000000 */   nop
    /* 1CE74C 002CE74C 2D984000 */  daddu      $19, $2, $0
    /* 1CE750 002CE750 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CE754 002CE754 38810B0C */  jal        func_002e04e0
    /* 1CE758 002CE758 00000000 */   nop
    /* 1CE75C 002CE75C 1C02A427 */  addiu      $4, $29, 0x21C
    /* 1CE760 002CE760 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CE764 002CE764 2D30A000 */  daddu      $6, $5, $0
    /* 1CE768 002CE768 2D38A000 */  daddu      $7, $5, $0
    /* 1CE76C 002CE76C 62004890 */  lbu        $8, 0x62($2)
    /* 1CE770 002CE770 98CA0A0C */  jal        func_002b2a60
    /* 1CE774 002CE774 00000000 */   nop
    /* 1CE778 002CE778 2D200000 */  daddu      $4, $0, $0
    /* 1CE77C 002CE77C 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CE780 002CE780 2D30A000 */  daddu      $6, $5, $0
    /* 1CE784 002CE784 2D38A000 */  daddu      $7, $5, $0
    /* 1CE788 002CE788 8CCA0A0C */  jal        func_002b2a30
    /* 1CE78C 002CE78C 00000000 */   nop
    /* 1CE790 002CE790 2DB04000 */  daddu      $22, $2, $0
  .L002CE794:
    /* 1CE794 002CE794 11000282 */  lb         $2, 0x11($16)
    /* 1CE798 002CE798 CA004014 */  bnez       $2, .L002CEAC4
    /* 1CE79C 002CE79C 00000000 */   nop
    /* 1CE7A0 002CE7A0 C8002016 */  bnez       $17, .L002CEAC4
    /* 1CE7A4 002CE7A4 00000000 */   nop
    /* 1CE7A8 002CE7A8 80100200 */  sll        $2, $2, 2
    /* 1CE7AC 002CE7AC 21100202 */  addu       $2, $16, $2
    /* 1CE7B0 002CE7B0 180F448C */  lw         $4, 0xF18($2)
    /* 1CE7B4 002CE7B4 BC890B0C */  jal        func_002e26f0
    /* 1CE7B8 002CE7B8 00000000 */   nop
    /* 1CE7BC 002CE7BC 02004128 */  slti       $1, $2, 0x2
    /* 1CE7C0 002CE7C0 54022014 */  bnez       $1, .L002CF114
    /* 1CE7C4 002CE7C4 00000000 */   nop
    /* 1CE7C8 002CE7C8 2D980000 */  daddu      $19, $0, $0
    /* 1CE7CC 002CE7CC 2F000010 */  b          .L002CE88C
    /* 1CE7D0 002CE7D0 00000000 */   nop
  .L002CE7D4:
    /* 1CE7D4 002CE7D4 3C141300 */  dsll32     $2, $19, 16
    /* 1CE7D8 002CE7D8 3F140200 */  dsra32     $2, $2, 16
    /* 1CE7DC 002CE7DC 40F10200 */  sll        $30, $2, 5
    /* 1CE7E0 002CE7E0 6F00C227 */  addiu      $2, $30, 0x6F
    /* 1CE7E4 002CE7E4 00008244 */  mtc1       $2, $f0
    /* 1CE7E8 002CE7E8 00000000 */  nop
    /* 1CE7EC 002CE7EC 20038046 */  cvt.s.w    $f12, $f0
    /* 1CE7F0 002CE7F0 0F43023C */  lui        $2, (0x430F0000 >> 16)
    /* 1CE7F4 002CE7F4 00688244 */  mtc1       $2, $f13
    /* 1CE7F8 002CE7F8 B001A427 */  addiu      $4, $29, 0x1B0
    /* 1CE7FC 002CE7FC 5CCA0A0C */  jal        func_002b2970
    /* 1CE800 002CE800 00000000 */   nop
    /* 1CE804 002CE804 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CE808 002CE808 00608244 */  mtc1       $2, $f12
    /* 1CE80C 002CE80C 3C000424 */  addiu      $4, $0, 0x3C
    /* 1CE810 002CE810 B001A5DF */  ld         $5, 0x1B0($29)
    /* 1CE814 002CE814 2D30C002 */  daddu      $6, $22, $0
    /* 1CE818 002CE818 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CE81C 002CE81C 2D400000 */  daddu      $8, $0, $0
    /* 1CE820 002CE820 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CE824 002CE824 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CE828 002CE828 C8820B0C */  jal        func_002e0b20
    /* 1CE82C 002CE82C 00000000 */   nop
    /* 1CE830 002CE830 A101C227 */  addiu      $2, $30, 0x1A1
    /* 1CE834 002CE834 00008244 */  mtc1       $2, $f0
    /* 1CE838 002CE838 00000000 */  nop
    /* 1CE83C 002CE83C 20038046 */  cvt.s.w    $f12, $f0
    /* 1CE840 002CE840 0F43023C */  lui        $2, (0x430F0000 >> 16)
    /* 1CE844 002CE844 00688244 */  mtc1       $2, $f13
    /* 1CE848 002CE848 A801A427 */  addiu      $4, $29, 0x1A8
    /* 1CE84C 002CE84C 5CCA0A0C */  jal        func_002b2970
    /* 1CE850 002CE850 00000000 */   nop
    /* 1CE854 002CE854 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CE858 002CE858 00608244 */  mtc1       $2, $f12
    /* 1CE85C 002CE85C 3C000424 */  addiu      $4, $0, 0x3C
    /* 1CE860 002CE860 A801A5DF */  ld         $5, 0x1A8($29)
    /* 1CE864 002CE864 2D30C002 */  daddu      $6, $22, $0
    /* 1CE868 002CE868 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CE86C 002CE86C 2D400000 */  daddu      $8, $0, $0
    /* 1CE870 002CE870 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CE874 002CE874 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CE878 002CE878 C8820B0C */  jal        func_002e0b20
    /* 1CE87C 002CE87C 00000000 */   nop
    /* 1CE880 002CE880 01006226 */  addiu      $2, $19, 0x1
    /* 1CE884 002CE884 3C9C0200 */  dsll32     $19, $2, 16
    /* 1CE888 002CE888 3F9C1300 */  dsra32     $19, $19, 16
  .L002CE88C:
    /* 1CE88C 002CE88C 3C141300 */  dsll32     $2, $19, 16
    /* 1CE890 002CE890 3F140200 */  dsra32     $2, $2, 16
    /* 1CE894 002CE894 03004228 */  slti       $2, $2, 0x3
    /* 1CE898 002CE898 CEFF4014 */  bnez       $2, .L002CE7D4
    /* 1CE89C 002CE89C 00000000 */   nop
    /* 1CE8A0 002CE8A0 F242023C */  lui        $2, (0x42F20000 >> 16)
    /* 1CE8A4 002CE8A4 00608244 */  mtc1       $2, $f12
    /* 1CE8A8 002CE8A8 440E048E */  lw         $4, 0xE44($16)
    /* 1CE8AC 002CE8AC 56000524 */  addiu      $5, $0, 0x56
    /* 1CE8B0 002CE8B0 78820B0C */  jal        func_002e09e0
    /* 1CE8B4 002CE8B4 00000000 */   nop
    /* 1CE8B8 002CE8B8 0402A427 */  addiu      $4, $29, 0x204
    /* 1CE8BC 002CE8BC FE000524 */  addiu      $5, $0, 0xFE
    /* 1CE8C0 002CE8C0 C7000624 */  addiu      $6, $0, 0xC7
    /* 1CE8C4 002CE8C4 31000724 */  addiu      $7, $0, 0x31
    /* 1CE8C8 002CE8C8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CE8CC 002CE8CC 98CA0A0C */  jal        func_002b2a60
    /* 1CE8D0 002CE8D0 00000000 */   nop
    /* 1CE8D4 002CE8D4 440E048E */  lw         $4, 0xE44($16)
    /* 1CE8D8 002CE8D8 38810B0C */  jal        func_002e04e0
    /* 1CE8DC 002CE8DC 00000000 */   nop
    /* 1CE8E0 002CE8E0 0402A693 */  lbu        $6, 0x204($29)
    /* 1CE8E4 002CE8E4 0502A593 */  lbu        $5, 0x205($29)
    /* 1CE8E8 002CE8E8 0602A493 */  lbu        $4, 0x206($29)
    /* 1CE8EC 002CE8EC 0702A393 */  lbu        $3, 0x207($29)
    /* 1CE8F0 002CE8F0 790046A0 */  sb         $6, 0x79($2)
    /* 1CE8F4 002CE8F4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CE8F8 002CE8F8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CE8FC 002CE8FC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CE900 002CE900 02000286 */  lh         $2, 0x2($16)
    /* 1CE904 002CE904 13002216 */  bne        $17, $2, .L002CE954
    /* 1CE908 002CE908 00000000 */   nop
    /* 1CE90C 002CE90C 0002A427 */  addiu      $4, $29, 0x200
    /* 1CE910 002CE910 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CE914 002CE914 2D30A000 */  daddu      $6, $5, $0
    /* 1CE918 002CE918 2D38A000 */  daddu      $7, $5, $0
    /* 1CE91C 002CE91C FF000824 */  addiu      $8, $0, 0xFF
    /* 1CE920 002CE920 98CA0A0C */  jal        func_002b2a60
    /* 1CE924 002CE924 00000000 */   nop
    /* 1CE928 002CE928 440E048E */  lw         $4, 0xE44($16)
    /* 1CE92C 002CE92C 38810B0C */  jal        func_002e04e0
    /* 1CE930 002CE930 00000000 */   nop
    /* 1CE934 002CE934 0002A693 */  lbu        $6, 0x200($29)
    /* 1CE938 002CE938 0102A593 */  lbu        $5, 0x201($29)
    /* 1CE93C 002CE93C 0202A493 */  lbu        $4, 0x202($29)
    /* 1CE940 002CE940 0302A393 */  lbu        $3, 0x203($29)
    /* 1CE944 002CE944 790046A0 */  sb         $6, 0x79($2)
    /* 1CE948 002CE948 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CE94C 002CE94C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CE950 002CE950 7C0043A0 */  sb         $3, 0x7C($2)
  .L002CE954:
    /* 1CE954 002CE954 F442023C */  lui        $2, (0x42F40000 >> 16)
    /* 1CE958 002CE958 00608244 */  mtc1       $2, $f12
    /* 1CE95C 002CE95C 480E048E */  lw         $4, 0xE48($16)
    /* 1CE960 002CE960 56000524 */  addiu      $5, $0, 0x56
    /* 1CE964 002CE964 78820B0C */  jal        func_002e09e0
    /* 1CE968 002CE968 00000000 */   nop
    /* 1CE96C 002CE96C FC01A427 */  addiu      $4, $29, 0x1FC
    /* 1CE970 002CE970 FE000524 */  addiu      $5, $0, 0xFE
    /* 1CE974 002CE974 C7000624 */  addiu      $6, $0, 0xC7
    /* 1CE978 002CE978 31000724 */  addiu      $7, $0, 0x31
    /* 1CE97C 002CE97C FF000824 */  addiu      $8, $0, 0xFF
    /* 1CE980 002CE980 98CA0A0C */  jal        func_002b2a60
    /* 1CE984 002CE984 00000000 */   nop
    /* 1CE988 002CE988 480E048E */  lw         $4, 0xE48($16)
    /* 1CE98C 002CE98C 38810B0C */  jal        func_002e04e0
    /* 1CE990 002CE990 00000000 */   nop
    /* 1CE994 002CE994 FC01A693 */  lbu        $6, 0x1FC($29)
    /* 1CE998 002CE998 FD01A593 */  lbu        $5, 0x1FD($29)
    /* 1CE99C 002CE99C FE01A493 */  lbu        $4, 0x1FE($29)
    /* 1CE9A0 002CE9A0 FF01A393 */  lbu        $3, 0x1FF($29)
    /* 1CE9A4 002CE9A4 790046A0 */  sb         $6, 0x79($2)
    /* 1CE9A8 002CE9A8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CE9AC 002CE9AC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CE9B0 002CE9B0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CE9B4 002CE9B4 02000286 */  lh         $2, 0x2($16)
    /* 1CE9B8 002CE9B8 13002216 */  bne        $17, $2, .L002CEA08
    /* 1CE9BC 002CE9BC 00000000 */   nop
    /* 1CE9C0 002CE9C0 F801A427 */  addiu      $4, $29, 0x1F8
    /* 1CE9C4 002CE9C4 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CE9C8 002CE9C8 2D30A000 */  daddu      $6, $5, $0
    /* 1CE9CC 002CE9CC 2D38A000 */  daddu      $7, $5, $0
    /* 1CE9D0 002CE9D0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CE9D4 002CE9D4 98CA0A0C */  jal        func_002b2a60
    /* 1CE9D8 002CE9D8 00000000 */   nop
    /* 1CE9DC 002CE9DC 480E048E */  lw         $4, 0xE48($16)
    /* 1CE9E0 002CE9E0 38810B0C */  jal        func_002e04e0
    /* 1CE9E4 002CE9E4 00000000 */   nop
    /* 1CE9E8 002CE9E8 F801A693 */  lbu        $6, 0x1F8($29)
    /* 1CE9EC 002CE9EC F901A593 */  lbu        $5, 0x1F9($29)
    /* 1CE9F0 002CE9F0 FA01A493 */  lbu        $4, 0x1FA($29)
    /* 1CE9F4 002CE9F4 FB01A393 */  lbu        $3, 0x1FB($29)
    /* 1CE9F8 002CE9F8 790046A0 */  sb         $6, 0x79($2)
    /* 1CE9FC 002CE9FC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CEA00 002CEA00 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CEA04 002CEA04 7C0043A0 */  sb         $3, 0x7C($2)
  .L002CEA08:
    /* 1CEA08 002CEA08 F042023C */  lui        $2, (0x42F00000 >> 16)
    /* 1CEA0C 002CEA0C 00608244 */  mtc1       $2, $f12
    /* 1CEA10 002CEA10 400E048E */  lw         $4, 0xE40($16)
    /* 1CEA14 002CEA14 57000524 */  addiu      $5, $0, 0x57
    /* 1CEA18 002CEA18 78820B0C */  jal        func_002e09e0
    /* 1CEA1C 002CEA1C 00000000 */   nop
    /* 1CEA20 002CEA20 F401A427 */  addiu      $4, $29, 0x1F4
    /* 1CEA24 002CEA24 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CEA28 002CEA28 2D30A000 */  daddu      $6, $5, $0
    /* 1CEA2C 002CEA2C 2D38A000 */  daddu      $7, $5, $0
    /* 1CEA30 002CEA30 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CEA34 002CEA34 98CA0A0C */  jal        func_002b2a60
    /* 1CEA38 002CEA38 00000000 */   nop
    /* 1CEA3C 002CEA3C 400E048E */  lw         $4, 0xE40($16)
    /* 1CEA40 002CEA40 38810B0C */  jal        func_002e04e0
    /* 1CEA44 002CEA44 00000000 */   nop
    /* 1CEA48 002CEA48 F401A693 */  lbu        $6, 0x1F4($29)
    /* 1CEA4C 002CEA4C F501A593 */  lbu        $5, 0x1F5($29)
    /* 1CEA50 002CEA50 F601A493 */  lbu        $4, 0x1F6($29)
    /* 1CEA54 002CEA54 F701A393 */  lbu        $3, 0x1F7($29)
    /* 1CEA58 002CEA58 790046A0 */  sb         $6, 0x79($2)
    /* 1CEA5C 002CEA5C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CEA60 002CEA60 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CEA64 002CEA64 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CEA68 002CEA68 02000386 */  lh         $3, 0x2($16)
    /* 1CEA6C 002CEA6C A9012316 */  bne        $17, $3, .L002CF114
    /* 1CEA70 002CEA70 00000000 */   nop
    /* 1CEA74 002CEA74 F001A427 */  addiu      $4, $29, 0x1F0
    /* 1CEA78 002CEA78 FE000524 */  addiu      $5, $0, 0xFE
    /* 1CEA7C 002CEA7C C7000624 */  addiu      $6, $0, 0xC7
    /* 1CEA80 002CEA80 31000724 */  addiu      $7, $0, 0x31
    /* 1CEA84 002CEA84 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CEA88 002CEA88 98CA0A0C */  jal        func_002b2a60
    /* 1CEA8C 002CEA8C 00000000 */   nop
    /* 1CEA90 002CEA90 400E048E */  lw         $4, 0xE40($16)
    /* 1CEA94 002CEA94 38810B0C */  jal        func_002e04e0
    /* 1CEA98 002CEA98 00000000 */   nop
    /* 1CEA9C 002CEA9C F001A693 */  lbu        $6, 0x1F0($29)
    /* 1CEAA0 002CEAA0 F101A593 */  lbu        $5, 0x1F1($29)
    /* 1CEAA4 002CEAA4 F201A493 */  lbu        $4, 0x1F2($29)
    /* 1CEAA8 002CEAA8 F301A393 */  lbu        $3, 0x1F3($29)
    /* 1CEAAC 002CEAAC 790046A0 */  sb         $6, 0x79($2)
    /* 1CEAB0 002CEAB0 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CEAB4 002CEAB4 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CEAB8 002CEAB8 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CEABC 002CEABC 95010010 */  b          .L002CF114
    /* 1CEAC0 002CEAC0 00000000 */   nop
  .L002CEAC4:
    /* 1CEAC4 002CEAC4 6400023C */  lui        $2, %hi(D_0063F888)
    /* 1CEAC8 002CEAC8 88F84224 */  addiu      $2, $2, %lo(D_0063F888)
    /* 1CEACC 002CEACC 3CB41700 */  dsll32     $22, $23, 16
    /* 1CEAD0 002CEAD0 3FB41600 */  dsra32     $22, $22, 16
    /* 1CEAD4 002CEAD4 40F11600 */  sll        $30, $22, 5
    /* 1CEAD8 002CEAD8 040041C4 */  lwc1       $f1, 0x4($2)
    /* 1CEADC 002CEADC 00009E44 */  mtc1       $30, $f0
    /* 1CEAE0 002CEAE0 00000000 */  nop
    /* 1CEAE4 002CEAE4 20008046 */  cvt.s.w    $f0, $f0
    /* 1CEAE8 002CEAE8 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CEAEC 002CEAEC D801A427 */  addiu      $4, $29, 0x1D8
    /* 1CEAF0 002CEAF0 00004CC4 */  lwc1       $f12, 0x0($2)
    /* 1CEAF4 002CEAF4 5CCA0A0C */  jal        func_002b2970
    /* 1CEAF8 002CEAF8 00000000 */   nop
    /* 1CEAFC 002CEAFC 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1CEB00 002CEB00 00088244 */  mtc1       $2, $f1
    /* 1CEB04 002CEB04 D801A0C7 */  lwc1       $f0, 0x1D8($29)
    /* 1CEB08 002CEB08 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CEB0C 002CEB0C 1041023C */  lui        $2, (0x41100000 >> 16)
    /* 1CEB10 002CEB10 00088244 */  mtc1       $2, $f1
    /* 1CEB14 002CEB14 DC01A0C7 */  lwc1       $f0, 0x1DC($29)
    /* 1CEB18 002CEB18 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CEB1C 002CEB1C E001A427 */  addiu      $4, $29, 0x1E0
    /* 1CEB20 002CEB20 5CCA0A0C */  jal        func_002b2970
    /* 1CEB24 002CEB24 00000000 */   nop
    /* 1CEB28 002CEB28 FC42023C */  lui        $2, (0x42FC0000 >> 16)
    /* 1CEB2C 002CEB2C 00088244 */  mtc1       $2, $f1
    /* 1CEB30 002CEB30 00009E44 */  mtc1       $30, $f0
    /* 1CEB34 002CEB34 00000000 */  nop
    /* 1CEB38 002CEB38 20008046 */  cvt.s.w    $f0, $f0
    /* 1CEB3C 002CEB3C 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CEB40 002CEB40 8C42023C */  lui        $2, (0x428C0000 >> 16)
    /* 1CEB44 002CEB44 00608244 */  mtc1       $2, $f12
    /* 1CEB48 002CEB48 D001A427 */  addiu      $4, $29, 0x1D0
    /* 1CEB4C 002CEB4C 5CCA0A0C */  jal        func_002b2970
    /* 1CEB50 002CEB50 00000000 */   nop
    /* 1CEB54 002CEB54 04000286 */  lh         $2, 0x4($16)
    /* 1CEB58 002CEB58 1C00C216 */  bne        $22, $2, .L002CEBCC
    /* 1CEB5C 002CEB5C 00000000 */   nop
    /* 1CEB60 002CEB60 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1CEB64 002CEB64 38810B0C */  jal        func_002e04e0
    /* 1CEB68 002CEB68 00000000 */   nop
    /* 1CEB6C 002CEB6C 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1CEB70 002CEB70 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1CEB74 002CEB74 00008244 */  mtc1       $2, $f0
    /* 1CEB78 002CEB78 00000000 */  nop
    /* 1CEB7C 002CEB7C 00050146 */  add.s      $f20, $f0, $f1
    /* 1CEB80 002CEB80 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1CEB84 002CEB84 38810B0C */  jal        func_002e04e0
    /* 1CEB88 002CEB88 00000000 */   nop
    /* 1CEB8C 002CEB8C 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1CEB90 002CEB90 1041023C */  lui        $2, (0x41100000 >> 16)
    /* 1CEB94 002CEB94 00008244 */  mtc1       $2, $f0
    /* 1CEB98 002CEB98 00000000 */  nop
    /* 1CEB9C 002CEB9C 40030146 */  add.s      $f13, $f0, $f1
    /* 1CEBA0 002CEBA0 E001A427 */  addiu      $4, $29, 0x1E0
    /* 1CEBA4 002CEBA4 06A30046 */  mov.s      $f12, $f20
    /* 1CEBA8 002CEBA8 5CCA0A0C */  jal        func_002b2970
    /* 1CEBAC 002CEBAC 00000000 */   nop
    /* 1CEBB0 002CEBB0 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1CEBB4 002CEBB4 38810B0C */  jal        func_002e04e0
    /* 1CEBB8 002CEBB8 00000000 */   nop
    /* 1CEBBC 002CEBBC 2C0041C4 */  lwc1       $f1, 0x2C($2)
    /* 1CEBC0 002CEBC0 300040C4 */  lwc1       $f0, 0x30($2)
    /* 1CEBC4 002CEBC4 D001A1E7 */  swc1       $f1, 0x1D0($29)
    /* 1CEBC8 002CEBC8 D401A0E7 */  swc1       $f0, 0x1D4($29)
  .L002CEBCC:
    /* 1CEBCC 002CEBCC 11000282 */  lb         $2, 0x11($16)
    /* 1CEBD0 002CEBD0 80100200 */  sll        $2, $2, 2
    /* 1CEBD4 002CEBD4 21100202 */  addu       $2, $16, $2
    /* 1CEBD8 002CEBD8 180F448C */  lw         $4, 0xF18($2)
    /* 1CEBDC 002CEBDC 2D282002 */  daddu      $5, $17, $0
    /* 1CEBE0 002CEBE0 0C8A0B0C */  jal        func_002e2830
    /* 1CEBE4 002CEBE4 00000000 */   nop
    /* 1CEBE8 002CEBE8 3C240200 */  dsll32     $4, $2, 16
    /* 1CEBEC 002CEBEC 3F240400 */  dsra32     $4, $4, 16
    /* 1CEBF0 002CEBF0 201A040C */  jal        func_00106880
    /* 1CEBF4 002CEBF4 00000000 */   nop
    /* 1CEBF8 002CEBF8 81004330 */  andi       $3, $2, 0x81
    /* 1CEBFC 002CEBFC 0E006010 */  beqz       $3, .L002CEC38
    /* 1CEC00 002CEC00 00000000 */   nop
    /* 1CEC04 002CEC04 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CEC08 002CEC08 00608244 */  mtc1       $2, $f12
    /* 1CEC0C 002CEC0C 14000424 */  addiu      $4, $0, 0x14
    /* 1CEC10 002CEC10 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CEC14 002CEC14 2D306002 */  daddu      $6, $19, $0
    /* 1CEC18 002CEC18 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CEC1C 002CEC1C 2D400000 */  daddu      $8, $0, $0
    /* 1CEC20 002CEC20 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CEC24 002CEC24 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CEC28 002CEC28 C8820B0C */  jal        func_002e0b20
    /* 1CEC2C 002CEC2C 00000000 */   nop
    /* 1CEC30 002CEC30 9D000010 */  b          .L002CEEA8
    /* 1CEC34 002CEC34 00000000 */   nop
  .L002CEC38:
    /* 1CEC38 002CEC38 02014330 */  andi       $3, $2, 0x102
    /* 1CEC3C 002CEC3C 0E006010 */  beqz       $3, .L002CEC78
    /* 1CEC40 002CEC40 00000000 */   nop
    /* 1CEC44 002CEC44 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CEC48 002CEC48 00608244 */  mtc1       $2, $f12
    /* 1CEC4C 002CEC4C 15000424 */  addiu      $4, $0, 0x15
    /* 1CEC50 002CEC50 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CEC54 002CEC54 2D306002 */  daddu      $6, $19, $0
    /* 1CEC58 002CEC58 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CEC5C 002CEC5C 2D400000 */  daddu      $8, $0, $0
    /* 1CEC60 002CEC60 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CEC64 002CEC64 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CEC68 002CEC68 C8820B0C */  jal        func_002e0b20
    /* 1CEC6C 002CEC6C 00000000 */   nop
    /* 1CEC70 002CEC70 8D000010 */  b          .L002CEEA8
    /* 1CEC74 002CEC74 00000000 */   nop
  .L002CEC78:
    /* 1CEC78 002CEC78 04024330 */  andi       $3, $2, 0x204
    /* 1CEC7C 002CEC7C 0E006010 */  beqz       $3, .L002CECB8
    /* 1CEC80 002CEC80 00000000 */   nop
    /* 1CEC84 002CEC84 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CEC88 002CEC88 00608244 */  mtc1       $2, $f12
    /* 1CEC8C 002CEC8C 16000424 */  addiu      $4, $0, 0x16
    /* 1CEC90 002CEC90 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CEC94 002CEC94 2D306002 */  daddu      $6, $19, $0
    /* 1CEC98 002CEC98 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CEC9C 002CEC9C 2D400000 */  daddu      $8, $0, $0
    /* 1CECA0 002CECA0 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CECA4 002CECA4 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CECA8 002CECA8 C8820B0C */  jal        func_002e0b20
    /* 1CECAC 002CECAC 00000000 */   nop
    /* 1CECB0 002CECB0 7D000010 */  b          .L002CEEA8
    /* 1CECB4 002CECB4 00000000 */   nop
  .L002CECB8:
    /* 1CECB8 002CECB8 08044330 */  andi       $3, $2, 0x408
    /* 1CECBC 002CECBC 0E006010 */  beqz       $3, .L002CECF8
    /* 1CECC0 002CECC0 00000000 */   nop
    /* 1CECC4 002CECC4 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CECC8 002CECC8 00608244 */  mtc1       $2, $f12
    /* 1CECCC 002CECCC 17000424 */  addiu      $4, $0, 0x17
    /* 1CECD0 002CECD0 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CECD4 002CECD4 2D306002 */  daddu      $6, $19, $0
    /* 1CECD8 002CECD8 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CECDC 002CECDC 2D400000 */  daddu      $8, $0, $0
    /* 1CECE0 002CECE0 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CECE4 002CECE4 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CECE8 002CECE8 C8820B0C */  jal        func_002e0b20
    /* 1CECEC 002CECEC 00000000 */   nop
    /* 1CECF0 002CECF0 6D000010 */  b          .L002CEEA8
    /* 1CECF4 002CECF4 00000000 */   nop
  .L002CECF8:
    /* 1CECF8 002CECF8 10084330 */  andi       $3, $2, 0x810
    /* 1CECFC 002CECFC 0E006010 */  beqz       $3, .L002CED38
    /* 1CED00 002CED00 00000000 */   nop
    /* 1CED04 002CED04 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CED08 002CED08 00608244 */  mtc1       $2, $f12
    /* 1CED0C 002CED0C 18000424 */  addiu      $4, $0, 0x18
    /* 1CED10 002CED10 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CED14 002CED14 2D306002 */  daddu      $6, $19, $0
    /* 1CED18 002CED18 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CED1C 002CED1C 2D400000 */  daddu      $8, $0, $0
    /* 1CED20 002CED20 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CED24 002CED24 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CED28 002CED28 C8820B0C */  jal        func_002e0b20
    /* 1CED2C 002CED2C 00000000 */   nop
    /* 1CED30 002CED30 5D000010 */  b          .L002CEEA8
    /* 1CED34 002CED34 00000000 */   nop
  .L002CED38:
    /* 1CED38 002CED38 20104330 */  andi       $3, $2, 0x1020
    /* 1CED3C 002CED3C 0E006010 */  beqz       $3, .L002CED78
    /* 1CED40 002CED40 00000000 */   nop
    /* 1CED44 002CED44 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CED48 002CED48 00608244 */  mtc1       $2, $f12
    /* 1CED4C 002CED4C 19000424 */  addiu      $4, $0, 0x19
    /* 1CED50 002CED50 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CED54 002CED54 2D306002 */  daddu      $6, $19, $0
    /* 1CED58 002CED58 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CED5C 002CED5C 2D400000 */  daddu      $8, $0, $0
    /* 1CED60 002CED60 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CED64 002CED64 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CED68 002CED68 C8820B0C */  jal        func_002e0b20
    /* 1CED6C 002CED6C 00000000 */   nop
    /* 1CED70 002CED70 4D000010 */  b          .L002CEEA8
    /* 1CED74 002CED74 00000000 */   nop
  .L002CED78:
    /* 1CED78 002CED78 40204330 */  andi       $3, $2, 0x2040
    /* 1CED7C 002CED7C 0E006010 */  beqz       $3, .L002CEDB8
    /* 1CED80 002CED80 00000000 */   nop
    /* 1CED84 002CED84 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CED88 002CED88 00608244 */  mtc1       $2, $f12
    /* 1CED8C 002CED8C 1A000424 */  addiu      $4, $0, 0x1A
    /* 1CED90 002CED90 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CED94 002CED94 2D306002 */  daddu      $6, $19, $0
    /* 1CED98 002CED98 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CED9C 002CED9C 2D400000 */  daddu      $8, $0, $0
    /* 1CEDA0 002CEDA0 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CEDA4 002CEDA4 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CEDA8 002CEDA8 C8820B0C */  jal        func_002e0b20
    /* 1CEDAC 002CEDAC 00000000 */   nop
    /* 1CEDB0 002CEDB0 3D000010 */  b          .L002CEEA8
    /* 1CEDB4 002CEDB4 00000000 */   nop
  .L002CEDB8:
    /* 1CEDB8 002CEDB8 00404330 */  andi       $3, $2, 0x4000
    /* 1CEDBC 002CEDBC 0E006010 */  beqz       $3, .L002CEDF8
    /* 1CEDC0 002CEDC0 00000000 */   nop
    /* 1CEDC4 002CEDC4 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CEDC8 002CEDC8 00608244 */  mtc1       $2, $f12
    /* 1CEDCC 002CEDCC 1B000424 */  addiu      $4, $0, 0x1B
    /* 1CEDD0 002CEDD0 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CEDD4 002CEDD4 2D306002 */  daddu      $6, $19, $0
    /* 1CEDD8 002CEDD8 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CEDDC 002CEDDC 2D400000 */  daddu      $8, $0, $0
    /* 1CEDE0 002CEDE0 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CEDE4 002CEDE4 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CEDE8 002CEDE8 C8820B0C */  jal        func_002e0b20
    /* 1CEDEC 002CEDEC 00000000 */   nop
    /* 1CEDF0 002CEDF0 2D000010 */  b          .L002CEEA8
    /* 1CEDF4 002CEDF4 00000000 */   nop
  .L002CEDF8:
    /* 1CEDF8 002CEDF8 00804330 */  andi       $3, $2, 0x8000
    /* 1CEDFC 002CEDFC 0E006010 */  beqz       $3, .L002CEE38
    /* 1CEE00 002CEE00 00000000 */   nop
    /* 1CEE04 002CEE04 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CEE08 002CEE08 00608244 */  mtc1       $2, $f12
    /* 1CEE0C 002CEE0C 1C000424 */  addiu      $4, $0, 0x1C
    /* 1CEE10 002CEE10 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CEE14 002CEE14 2D306002 */  daddu      $6, $19, $0
    /* 1CEE18 002CEE18 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CEE1C 002CEE1C 2D400000 */  daddu      $8, $0, $0
    /* 1CEE20 002CEE20 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CEE24 002CEE24 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CEE28 002CEE28 C8820B0C */  jal        func_002e0b20
    /* 1CEE2C 002CEE2C 00000000 */   nop
    /* 1CEE30 002CEE30 1D000010 */  b          .L002CEEA8
    /* 1CEE34 002CEE34 00000000 */   nop
  .L002CEE38:
    /* 1CEE38 002CEE38 0400033C */  lui        $3, (0x40000 >> 16)
    /* 1CEE3C 002CEE3C 24104300 */  and        $2, $2, $3
    /* 1CEE40 002CEE40 0E004010 */  beqz       $2, .L002CEE7C
    /* 1CEE44 002CEE44 00000000 */   nop
    /* 1CEE48 002CEE48 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CEE4C 002CEE4C 00608244 */  mtc1       $2, $f12
    /* 1CEE50 002CEE50 1A000424 */  addiu      $4, $0, 0x1A
    /* 1CEE54 002CEE54 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CEE58 002CEE58 2D306002 */  daddu      $6, $19, $0
    /* 1CEE5C 002CEE5C FF000724 */  addiu      $7, $0, 0xFF
    /* 1CEE60 002CEE60 2D400000 */  daddu      $8, $0, $0
    /* 1CEE64 002CEE64 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CEE68 002CEE68 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CEE6C 002CEE6C 28830B0C */  jal        func_002e0ca0
    /* 1CEE70 002CEE70 00000000 */   nop
    /* 1CEE74 002CEE74 0C000010 */  b          .L002CEEA8
    /* 1CEE78 002CEE78 00000000 */   nop
  .L002CEE7C:
    /* 1CEE7C 002CEE7C E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CEE80 002CEE80 00608244 */  mtc1       $2, $f12
    /* 1CEE84 002CEE84 1B000424 */  addiu      $4, $0, 0x1B
    /* 1CEE88 002CEE88 E001A5DF */  ld         $5, 0x1E0($29)
    /* 1CEE8C 002CEE8C 2D306002 */  daddu      $6, $19, $0
    /* 1CEE90 002CEE90 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CEE94 002CEE94 2D400000 */  daddu      $8, $0, $0
    /* 1CEE98 002CEE98 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CEE9C 002CEE9C 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CEEA0 002CEEA0 28830B0C */  jal        func_002e0ca0
    /* 1CEEA4 002CEEA4 00000000 */   nop
  .L002CEEA8:
    /* 1CEEA8 002CEEA8 5442023C */  lui        $2, (0x42540000 >> 16)
    /* 1CEEAC 002CEEAC 00088244 */  mtc1       $2, $f1
    /* 1CEEB0 002CEEB0 D001A0C7 */  lwc1       $f0, 0x1D0($29)
    /* 1CEEB4 002CEEB4 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CEEB8 002CEEB8 E040023C */  lui        $2, (0x40E00000 >> 16)
    /* 1CEEBC 002CEEBC 00088244 */  mtc1       $2, $f1
    /* 1CEEC0 002CEEC0 D401A0C7 */  lwc1       $f0, 0x1D4($29)
    /* 1CEEC4 002CEEC4 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CEEC8 002CEEC8 A001A427 */  addiu      $4, $29, 0x1A0
    /* 1CEECC 002CEECC 5CCA0A0C */  jal        func_002b2970
    /* 1CEED0 002CEED0 00000000 */   nop
    /* 1CEED4 002CEED4 A001A1C7 */  lwc1       $f1, 0x1A0($29)
    /* 1CEED8 002CEED8 A401A0C7 */  lwc1       $f0, 0x1A4($29)
    /* 1CEEDC 002CEEDC D800A1E7 */  swc1       $f1, 0xD8($29)
    /* 1CEEE0 002CEEE0 DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* 1CEEE4 002CEEE4 3C8C1500 */  dsll32     $17, $21, 16
    /* 1CEEE8 002CEEE8 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CEEEC 002CEEEC 11000282 */  lb         $2, 0x11($16)
    /* 1CEEF0 002CEEF0 80100200 */  sll        $2, $2, 2
    /* 1CEEF4 002CEEF4 21100202 */  addu       $2, $16, $2
    /* 1CEEF8 002CEEF8 180F448C */  lw         $4, 0xF18($2)
    /* 1CEEFC 002CEEFC 2D282002 */  daddu      $5, $17, $0
    /* 1CEF00 002CEF00 0C8A0B0C */  jal        func_002e2830
    /* 1CEF04 002CEF04 00000000 */   nop
    /* 1CEF08 002CEF08 3C240200 */  dsll32     $4, $2, 16
    /* 1CEF0C 002CEF0C 3F240400 */  dsra32     $4, $4, 16
    /* 1CEF10 002CEF10 FC19040C */  jal        func_001067f0
    /* 1CEF14 002CEF14 00000000 */   nop
    /* 1CEF18 002CEF18 E642033C */  lui        $3, (0x42E60000 >> 16)
    /* 1CEF1C 002CEF1C 00708344 */  mtc1       $3, $f14
    /* 1CEF20 002CEF20 D800ACC7 */  lwc1       $f12, 0xD8($29)
    /* 1CEF24 002CEF24 DC00ADC7 */  lwc1       $f13, 0xDC($29)
    /* 1CEF28 002CEF28 D000A48F */  lw         $4, 0xD0($29)
    /* 1CEF2C 002CEF2C 2D280000 */  daddu      $5, $0, $0
    /* 1CEF30 002CEF30 01000624 */  addiu      $6, $0, 0x1
    /* 1CEF34 002CEF34 2D384000 */  daddu      $7, $2, $0
    /* 1CEF38 002CEF38 2D400000 */  daddu      $8, $0, $0
    /* 1CEF3C 002CEF3C 2D480000 */  daddu      $9, $0, $0
    /* 1CEF40 002CEF40 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1CEF44 002CEF44 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1CEF48 002CEF48 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1CEF4C 002CEF4C A0D5090C */  jal        func_00275680
    /* 1CEF50 002CEF50 00000000 */   nop
    /* 1CEF54 002CEF54 11000282 */  lb         $2, 0x11($16)
    /* 1CEF58 002CEF58 80100200 */  sll        $2, $2, 2
    /* 1CEF5C 002CEF5C 21100202 */  addu       $2, $16, $2
    /* 1CEF60 002CEF60 180F448C */  lw         $4, 0xF18($2)
    /* 1CEF64 002CEF64 2D282002 */  daddu      $5, $17, $0
    /* 1CEF68 002CEF68 0C8A0B0C */  jal        func_002e2830
    /* 1CEF6C 002CEF6C 00000000 */   nop
    /* 1CEF70 002CEF70 3C240200 */  dsll32     $4, $2, 16
    /* 1CEF74 002CEF74 3F240400 */  dsra32     $4, $4, 16
    /* 1CEF78 002CEF78 A41A040C */  jal        func_00106a90
    /* 1CEF7C 002CEF7C 00000000 */   nop
    /* 1CEF80 002CEF80 05000324 */  addiu      $3, $0, 0x5
    /* 1CEF84 002CEF84 1B004300 */  divu       $0, $2, $3
    /* 1CEF88 002CEF88 12B00000 */  mflo       $22
    /* 1CEF8C 002CEF8C BA43023C */  lui        $2, (0x43BA0000 >> 16)
    /* 1CEF90 002CEF90 00088244 */  mtc1       $2, $f1
    /* 1CEF94 002CEF94 D001A0C7 */  lwc1       $f0, 0x1D0($29)
    /* 1CEF98 002CEF98 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CEF9C 002CEF9C 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1CEFA0 002CEFA0 00088244 */  mtc1       $2, $f1
    /* 1CEFA4 002CEFA4 D401A0C7 */  lwc1       $f0, 0x1D4($29)
    /* 1CEFA8 002CEFA8 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CEFAC 002CEFAC 9801A427 */  addiu      $4, $29, 0x198
    /* 1CEFB0 002CEFB0 5CCA0A0C */  jal        func_002b2970
    /* 1CEFB4 002CEFB4 00000000 */   nop
    /* 1CEFB8 002CEFB8 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1CEFBC 002CEFBC 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1CEFC0 002CEFC0 DCA9110C */  jal        func_0046a770
    /* 1CEFC4 002CEFC4 00000000 */   nop
    /* 1CEFC8 002CEFC8 280F038E */  lw         $3, 0xF28($16)
    /* 1CEFCC 002CEFCC 0000A3FF */  sd         $3, 0x0($29)
    /* 1CEFD0 002CEFD0 A9000324 */  addiu      $3, $0, 0xA9
    /* 1CEFD4 002CEFD4 0800A3FF */  sd         $3, 0x8($29)
    /* 1CEFD8 002CEFD8 E642033C */  lui        $3, (0x42E60000 >> 16)
    /* 1CEFDC 002CEFDC 00608344 */  mtc1       $3, $f12
    /* 1CEFE0 002CEFE0 9801A4DF */  ld         $4, 0x198($29)
    /* 1CEFE4 002CEFE4 1C02A58F */  lw         $5, 0x21C($29)
    /* 1CEFE8 002CEFE8 10000624 */  addiu      $6, $0, 0x10
    /* 1CEFEC 002CEFEC 05000724 */  addiu      $7, $0, 0x5
    /* 1CEFF0 002CEFF0 2D40C002 */  daddu      $8, $22, $0
    /* 1CEFF4 002CEFF4 09000924 */  addiu      $9, $0, 0x9
    /* 1CEFF8 002CEFF8 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1CEFFC 002CEFFC 2D584000 */  daddu      $11, $2, $0
    /* 1CF000 002CF000 342B0B0C */  jal        func_002cacd0
    /* 1CF004 002CF004 00000000 */   nop
    /* 1CF008 002CF008 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 1CF00C 002CF00C 00088244 */  mtc1       $2, $f1
    /* 1CF010 002CF010 D001A0C7 */  lwc1       $f0, 0x1D0($29)
    /* 1CF014 002CF014 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CF018 002CF018 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1CF01C 002CF01C 00088244 */  mtc1       $2, $f1
    /* 1CF020 002CF020 D401A0C7 */  lwc1       $f0, 0x1D4($29)
    /* 1CF024 002CF024 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CF028 002CF028 9001A427 */  addiu      $4, $29, 0x190
    /* 1CF02C 002CF02C 5CCA0A0C */  jal        func_002b2970
    /* 1CF030 002CF030 00000000 */   nop
    /* 1CF034 002CF034 E642023C */  lui        $2, (0x42E60000 >> 16)
    /* 1CF038 002CF038 00608244 */  mtc1       $2, $f12
    /* 1CF03C 002CF03C 47000424 */  addiu      $4, $0, 0x47
    /* 1CF040 002CF040 9001A5DF */  ld         $5, 0x190($29)
    /* 1CF044 002CF044 2D306002 */  daddu      $6, $19, $0
    /* 1CF048 002CF048 FF000724 */  addiu      $7, $0, 0xFF
    /* 1CF04C 002CF04C 2D400000 */  daddu      $8, $0, $0
    /* 1CF050 002CF050 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CF054 002CF054 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CF058 002CF058 C8820B0C */  jal        func_002e0b20
    /* 1CF05C 002CF05C 00000000 */   nop
    /* 1CF060 002CF060 AF010224 */  addiu      $2, $0, 0x1AF
    /* 1CF064 002CF064 00008244 */  mtc1       $2, $f0
    /* 1CF068 002CF068 00000000 */  nop
    /* 1CF06C 002CF06C 60008046 */  cvt.s.w    $f1, $f0
    /* 1CF070 002CF070 D001A0C7 */  lwc1       $f0, 0x1D0($29)
    /* 1CF074 002CF074 000B0046 */  add.s      $f12, $f1, $f0
    /* 1CF078 002CF078 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1CF07C 002CF07C 00088244 */  mtc1       $2, $f1
    /* 1CF080 002CF080 D401A0C7 */  lwc1       $f0, 0x1D4($29)
    /* 1CF084 002CF084 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CF088 002CF088 8801A427 */  addiu      $4, $29, 0x188
    /* 1CF08C 002CF08C 5CCA0A0C */  jal        func_002b2970
    /* 1CF090 002CF090 00000000 */   nop
    /* 1CF094 002CF094 11000282 */  lb         $2, 0x11($16)
    /* 1CF098 002CF098 80100200 */  sll        $2, $2, 2
    /* 1CF09C 002CF09C 21100202 */  addu       $2, $16, $2
    /* 1CF0A0 002CF0A0 180F448C */  lw         $4, 0xF18($2)
    /* 1CF0A4 002CF0A4 2D282002 */  daddu      $5, $17, $0
    /* 1CF0A8 002CF0A8 0C8A0B0C */  jal        func_002e2830
    /* 1CF0AC 002CF0AC 00000000 */   nop
    /* 1CF0B0 002CF0B0 3C240200 */  dsll32     $4, $2, 16
    /* 1CF0B4 002CF0B4 3F240400 */  dsra32     $4, $4, 16
    /* 1CF0B8 002CF0B8 8019040C */  jal        func_00106600
    /* 1CF0BC 002CF0BC 00000000 */   nop
    /* 1CF0C0 002CF0C0 FF005130 */  andi       $17, $2, 0xFF
    /* 1CF0C4 002CF0C4 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1CF0C8 002CF0C8 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1CF0CC 002CF0CC DCA9110C */  jal        func_0046a770
    /* 1CF0D0 002CF0D0 00000000 */   nop
    /* 1CF0D4 002CF0D4 280F038E */  lw         $3, 0xF28($16)
    /* 1CF0D8 002CF0D8 0000A3FF */  sd         $3, 0x0($29)
    /* 1CF0DC 002CF0DC A9000324 */  addiu      $3, $0, 0xA9
    /* 1CF0E0 002CF0E0 0800A3FF */  sd         $3, 0x8($29)
    /* 1CF0E4 002CF0E4 E642033C */  lui        $3, (0x42E60000 >> 16)
    /* 1CF0E8 002CF0E8 00608344 */  mtc1       $3, $f12
    /* 1CF0EC 002CF0EC 8801A4DF */  ld         $4, 0x188($29)
    /* 1CF0F0 002CF0F0 1C02A58F */  lw         $5, 0x21C($29)
    /* 1CF0F4 002CF0F4 10000624 */  addiu      $6, $0, 0x10
    /* 1CF0F8 002CF0F8 05000724 */  addiu      $7, $0, 0x5
    /* 1CF0FC 002CF0FC 2D402002 */  daddu      $8, $17, $0
    /* 1CF100 002CF100 09000924 */  addiu      $9, $0, 0x9
    /* 1CF104 002CF104 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1CF108 002CF108 2D584000 */  daddu      $11, $2, $0
    /* 1CF10C 002CF10C 342B0B0C */  jal        func_002cacd0
    /* 1CF110 002CF110 00000000 */   nop
  .L002CF114:
    /* 1CF114 002CF114 0100A326 */  addiu      $3, $21, 0x1
    /* 1CF118 002CF118 3CAC0300 */  dsll32     $21, $3, 16
    /* 1CF11C 002CF11C 3FAC1500 */  dsra32     $21, $21, 16
    /* 1CF120 002CF120 0100E326 */  addiu      $3, $23, 0x1
    /* 1CF124 002CF124 3CBC0300 */  dsll32     $23, $3, 16
    /* 1CF128 002CF128 3FBC1700 */  dsra32     $23, $23, 16
  .L002CF12C:
    /* 1CF12C 002CF12C 3C8C1500 */  dsll32     $17, $21, 16
    /* 1CF130 002CF130 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CF134 002CF134 C000A37B */  lq         $3, 0xC0($29)
    /* 1CF138 002CF138 2A182302 */  slt        $3, $17, $3
    /* 1CF13C 002CF13C 45FD6014 */  bnez       $3, .L002CE654
    /* 1CF140 002CF140 00000000 */   nop
  .L002CF144:
    /* 1CF144 002CF144 D700A383 */  lb         $3, 0xD7($29)
    /* 1CF148 002CF148 2D886000 */  daddu      $17, $3, $0
    /* 1CF14C 002CF14C 02000324 */  addiu      $3, $0, 0x2
    /* 1CF150 002CF150 00092312 */  beq        $17, $3, .L002D1554
    /* 1CF154 002CF154 00000000 */   nop
    /* 1CF158 002CF158 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1CF15C 002CF15C 01000524 */  addiu      $5, $0, 0x1
    /* 1CF160 002CF160 5C810B0C */  jal        func_002e0570
    /* 1CF164 002CF164 00000000 */   nop
    /* 1CF168 002CF168 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF16C 002CF16C 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF170 002CF170 F8086014 */  bnez       $3, .L002D1554
    /* 1CF174 002CF174 00000000 */   nop
    /* 1CF178 002CF178 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CF17C 002CF17C 01000524 */  addiu      $5, $0, 0x1
    /* 1CF180 002CF180 5C810B0C */  jal        func_002e0570
    /* 1CF184 002CF184 00000000 */   nop
    /* 1CF188 002CF188 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF18C 002CF18C 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF190 002CF190 F0086014 */  bnez       $3, .L002D1554
    /* 1CF194 002CF194 00000000 */   nop
    /* 1CF198 002CF198 440D048E */  lw         $4, 0xD44($16)
    /* 1CF19C 002CF19C 68810B0C */  jal        func_002e05a0
    /* 1CF1A0 002CF1A0 00000000 */   nop
    /* 1CF1A4 002CF1A4 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF1A8 002CF1A8 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF1AC 002CF1AC E9086014 */  bnez       $3, .L002D1554
    /* 1CF1B0 002CF1B0 00000000 */   nop
    /* 1CF1B4 002CF1B4 480D048E */  lw         $4, 0xD48($16)
    /* 1CF1B8 002CF1B8 68810B0C */  jal        func_002e05a0
    /* 1CF1BC 002CF1BC 00000000 */   nop
    /* 1CF1C0 002CF1C0 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF1C4 002CF1C4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF1C8 002CF1C8 E2086014 */  bnez       $3, .L002D1554
    /* 1CF1CC 002CF1CC 00000000 */   nop
    /* 1CF1D0 002CF1D0 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CF1D4 002CF1D4 68810B0C */  jal        func_002e05a0
    /* 1CF1D8 002CF1D8 00000000 */   nop
    /* 1CF1DC 002CF1DC 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF1E0 002CF1E0 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF1E4 002CF1E4 DB086014 */  bnez       $3, .L002D1554
    /* 1CF1E8 002CF1E8 00000000 */   nop
    /* 1CF1EC 002CF1EC 500D048E */  lw         $4, 0xD50($16)
    /* 1CF1F0 002CF1F0 68810B0C */  jal        func_002e05a0
    /* 1CF1F4 002CF1F4 00000000 */   nop
    /* 1CF1F8 002CF1F8 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF1FC 002CF1FC 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF200 002CF200 D4086014 */  bnez       $3, .L002D1554
    /* 1CF204 002CF204 00000000 */   nop
    /* 1CF208 002CF208 540D048E */  lw         $4, 0xD54($16)
    /* 1CF20C 002CF20C 68810B0C */  jal        func_002e05a0
    /* 1CF210 002CF210 00000000 */   nop
    /* 1CF214 002CF214 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF218 002CF218 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF21C 002CF21C CD086014 */  bnez       $3, .L002D1554
    /* 1CF220 002CF220 00000000 */   nop
    /* 1CF224 002CF224 580D048E */  lw         $4, 0xD58($16)
    /* 1CF228 002CF228 68810B0C */  jal        func_002e05a0
    /* 1CF22C 002CF22C 00000000 */   nop
    /* 1CF230 002CF230 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CF234 002CF234 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CF238 002CF238 C6086014 */  bnez       $3, .L002D1554
    /* 1CF23C 002CF23C 00000000 */   nop
    /* 1CF240 002CF240 8C00033C */  lui        $3, %hi(D_008C0276)
    /* 1CF244 002CF244 76026594 */  lhu        $5, %lo(D_008C0276)($3)
    /* 1CF248 002CF248 0010A330 */  andi       $3, $5, 0x1000
    /* 1CF24C 002CF24C 7A006010 */  beqz       $3, .L002CF438
    /* 1CF250 002CF250 00000000 */   nop
    /* 1CF254 002CF254 14000382 */  lb         $3, 0x14($16)
    /* 1CF258 002CF258 77006014 */  bnez       $3, .L002CF438
    /* 1CF25C 002CF25C 00000000 */   nop
    /* 1CF260 002CF260 11001382 */  lb         $19, 0x11($16)
    /* 1CF264 002CF264 80101300 */  sll        $2, $19, 2
    /* 1CF268 002CF268 21105000 */  addu       $2, $2, $16
    /* 1CF26C 002CF26C 180F448C */  lw         $4, 0xF18($2)
    /* 1CF270 002CF270 BC890B0C */  jal        func_002e26f0
    /* 1CF274 002CF274 00000000 */   nop
    /* 1CF278 002CF278 7500033C */  lui        $3, %hi(D_00748908)
    /* 1CF27C 002CF27C 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1CF280 002CF280 21187300 */  addu       $3, $3, $19
    /* 1CF284 002CF284 00006380 */  lb         $3, 0x0($3)
    /* 1CF288 002CF288 2A086200 */  slt        $1, $3, $2
    /* 1CF28C 002CF28C B1082010 */  beqz       $1, .L002D1554
    /* 1CF290 002CF290 00000000 */   nop
    /* 1CF294 002CF294 01000324 */  addiu      $3, $0, 0x1
    /* 1CF298 002CF298 2A002316 */  bne        $17, $3, .L002CF344
    /* 1CF29C 002CF29C 00000000 */   nop
    /* 1CF2A0 002CF2A0 28006016 */  bnez       $19, .L002CF344
    /* 1CF2A4 002CF2A4 00000000 */   nop
    /* 1CF2A8 002CF2A8 02000286 */  lh         $2, 0x2($16)
    /* 1CF2AC 002CF2AC 25004314 */  bne        $2, $3, .L002CF344
    /* 1CF2B0 002CF2B0 00000000 */   nop
    /* 1CF2B4 002CF2B4 2D200000 */  daddu      $4, $0, $0
    /* 1CF2B8 002CF2B8 2D280000 */  daddu      $5, $0, $0
    /* 1CF2BC 002CF2BC 2D300000 */  daddu      $6, $0, $0
    /* 1CF2C0 002CF2C0 2D380000 */  daddu      $7, $0, $0
    /* 1CF2C4 002CF2C4 D86B110C */  jal        func_0045af60
    /* 1CF2C8 002CF2C8 00000000 */   nop
    /* 1CF2CC 002CF2CC 11000282 */  lb         $2, 0x11($16)
    /* 1CF2D0 002CF2D0 80100200 */  sll        $2, $2, 2
    /* 1CF2D4 002CF2D4 21105000 */  addu       $2, $2, $16
    /* 1CF2D8 002CF2D8 180F448C */  lw         $4, 0xF18($2)
    /* 1CF2DC 002CF2DC BC890B0C */  jal        func_002e26f0
    /* 1CF2E0 002CF2E0 00000000 */   nop
    /* 1CF2E4 002CF2E4 3C3C0200 */  dsll32     $7, $2, 16
    /* 1CF2E8 002CF2E8 3F3C0700 */  dsra32     $7, $7, 16
    /* 1CF2EC 002CF2EC 02000486 */  lh         $4, 0x2($16)
    /* 1CF2F0 002CF2F0 01000524 */  addiu      $5, $0, 0x1
    /* 1CF2F4 002CF2F4 2D300000 */  daddu      $6, $0, $0
    /* 1CF2F8 002CF2F8 02000824 */  addiu      $8, $0, 0x2
    /* 1CF2FC 002CF2FC 40CB0A0C */  jal        func_002b2d00
    /* 1CF300 002CF300 00000000 */   nop
    /* 1CF304 002CF304 020002A6 */  sh         $2, 0x2($16)
    /* 1CF308 002CF308 11000282 */  lb         $2, 0x11($16)
    /* 1CF30C 002CF30C 80100200 */  sll        $2, $2, 2
    /* 1CF310 002CF310 21105000 */  addu       $2, $2, $16
    /* 1CF314 002CF314 180F448C */  lw         $4, 0xF18($2)
    /* 1CF318 002CF318 BC890B0C */  jal        func_002e26f0
    /* 1CF31C 002CF31C 00000000 */   nop
    /* 1CF320 002CF320 3C340200 */  dsll32     $6, $2, 16
    /* 1CF324 002CF324 3F340600 */  dsra32     $6, $6, 16
    /* 1CF328 002CF328 02000486 */  lh         $4, 0x2($16)
    /* 1CF32C 002CF32C 04000586 */  lh         $5, 0x4($16)
    /* 1CF330 002CF330 05000724 */  addiu      $7, $0, 0x5
    /* 1CF334 002CF334 FFFF0824 */  addiu      $8, $0, -0x1
    /* 1CF338 002CF338 54CB0A0C */  jal        func_002b2d50
    /* 1CF33C 002CF33C 00000000 */   nop
    /* 1CF340 002CF340 040002A6 */  sh         $2, 0x4($16)
  .L002CF344:
    /* 1CF344 002CF344 02000286 */  lh         $2, 0x2($16)
    /* 1CF348 002CF348 13004014 */  bnez       $2, .L002CF398
    /* 1CF34C 002CF34C 00000000 */   nop
    /* 1CF350 002CF350 2D200000 */  daddu      $4, $0, $0
    /* 1CF354 002CF354 2D280000 */  daddu      $5, $0, $0
    /* 1CF358 002CF358 2D300000 */  daddu      $6, $0, $0
    /* 1CF35C 002CF35C 2D380000 */  daddu      $7, $0, $0
    /* 1CF360 002CF360 D86B110C */  jal        func_0045af60
    /* 1CF364 002CF364 00000000 */   nop
    /* 1CF368 002CF368 020012A6 */  sh         $18, 0x2($16)
    /* 1CF36C 002CF36C 3C2C1200 */  dsll32     $5, $18, 16
    /* 1CF370 002CF370 3F2C0500 */  dsra32     $5, $5, 16
    /* 1CF374 002CF374 2D200000 */  daddu      $4, $0, $0
    /* 1CF378 002CF378 04000624 */  addiu      $6, $0, 0x4
    /* 1CF37C 002CF37C 2D380000 */  daddu      $7, $0, $0
    /* 1CF380 002CF380 01000824 */  addiu      $8, $0, 0x1
    /* 1CF384 002CF384 2CCB0A0C */  jal        func_002b2cb0
    /* 1CF388 002CF388 00000000 */   nop
    /* 1CF38C 002CF38C 040002A6 */  sh         $2, 0x4($16)
    /* 1CF390 002CF390 25000010 */  b          .L002CF428
    /* 1CF394 002CF394 00000000 */   nop
  .L002CF398:
    /* 1CF398 002CF398 2D200000 */  daddu      $4, $0, $0
    /* 1CF39C 002CF39C 2D280000 */  daddu      $5, $0, $0
    /* 1CF3A0 002CF3A0 2D300000 */  daddu      $6, $0, $0
    /* 1CF3A4 002CF3A4 2D380000 */  daddu      $7, $0, $0
    /* 1CF3A8 002CF3A8 D86B110C */  jal        func_0045af60
    /* 1CF3AC 002CF3AC 00000000 */   nop
    /* 1CF3B0 002CF3B0 11000282 */  lb         $2, 0x11($16)
    /* 1CF3B4 002CF3B4 80100200 */  sll        $2, $2, 2
    /* 1CF3B8 002CF3B8 21105000 */  addu       $2, $2, $16
    /* 1CF3BC 002CF3BC 180F448C */  lw         $4, 0xF18($2)
    /* 1CF3C0 002CF3C0 BC890B0C */  jal        func_002e26f0
    /* 1CF3C4 002CF3C4 00000000 */   nop
    /* 1CF3C8 002CF3C8 3C3C0200 */  dsll32     $7, $2, 16
    /* 1CF3CC 002CF3CC 3F3C0700 */  dsra32     $7, $7, 16
    /* 1CF3D0 002CF3D0 02000486 */  lh         $4, 0x2($16)
    /* 1CF3D4 002CF3D4 01000524 */  addiu      $5, $0, 0x1
    /* 1CF3D8 002CF3D8 2D300000 */  daddu      $6, $0, $0
    /* 1CF3DC 002CF3DC 02000824 */  addiu      $8, $0, 0x2
    /* 1CF3E0 002CF3E0 40CB0A0C */  jal        func_002b2d00
    /* 1CF3E4 002CF3E4 00000000 */   nop
    /* 1CF3E8 002CF3E8 020002A6 */  sh         $2, 0x2($16)
    /* 1CF3EC 002CF3EC 11000282 */  lb         $2, 0x11($16)
    /* 1CF3F0 002CF3F0 80100200 */  sll        $2, $2, 2
    /* 1CF3F4 002CF3F4 21105000 */  addu       $2, $2, $16
    /* 1CF3F8 002CF3F8 180F448C */  lw         $4, 0xF18($2)
    /* 1CF3FC 002CF3FC BC890B0C */  jal        func_002e26f0
    /* 1CF400 002CF400 00000000 */   nop
    /* 1CF404 002CF404 3C340200 */  dsll32     $6, $2, 16
    /* 1CF408 002CF408 3F340600 */  dsra32     $6, $6, 16
    /* 1CF40C 002CF40C 02000486 */  lh         $4, 0x2($16)
    /* 1CF410 002CF410 04000586 */  lh         $5, 0x4($16)
    /* 1CF414 002CF414 05000724 */  addiu      $7, $0, 0x5
    /* 1CF418 002CF418 FFFF0824 */  addiu      $8, $0, -0x1
    /* 1CF41C 002CF41C 54CB0A0C */  jal        func_002b2d50
    /* 1CF420 002CF420 00000000 */   nop
    /* 1CF424 002CF424 040002A6 */  sh         $2, 0x4($16)
  .L002CF428:
    /* 1CF428 002CF428 01000324 */  addiu      $3, $0, 0x1
    /* 1CF42C 002CF42C 140003A2 */  sb         $3, 0x14($16)
    /* 1CF430 002CF430 48080010 */  b          .L002D1554
    /* 1CF434 002CF434 00000000 */   nop
  .L002CF438:
    /* 1CF438 002CF438 8C00033C */  lui        $3, %hi(D_008C027A)
    /* 1CF43C 002CF43C 7A026494 */  lhu        $4, %lo(D_008C027A)($3)
    /* 1CF440 002CF440 00108330 */  andi       $3, $4, 0x1000
    /* 1CF444 002CF444 41006010 */  beqz       $3, .L002CF54C
    /* 1CF448 002CF448 00000000 */   nop
    /* 1CF44C 002CF44C 11001282 */  lb         $18, 0x11($16)
    /* 1CF450 002CF450 80101200 */  sll        $2, $18, 2
    /* 1CF454 002CF454 21105000 */  addu       $2, $2, $16
    /* 1CF458 002CF458 180F448C */  lw         $4, 0xF18($2)
    /* 1CF45C 002CF45C BC890B0C */  jal        func_002e26f0
    /* 1CF460 002CF460 00000000 */   nop
    /* 1CF464 002CF464 7500033C */  lui        $3, %hi(D_00748908)
    /* 1CF468 002CF468 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1CF46C 002CF46C 21187200 */  addu       $3, $3, $18
    /* 1CF470 002CF470 00006380 */  lb         $3, 0x0($3)
    /* 1CF474 002CF474 2A086200 */  slt        $1, $3, $2
    /* 1CF478 002CF478 36082010 */  beqz       $1, .L002D1554
    /* 1CF47C 002CF47C 00000000 */   nop
    /* 1CF480 002CF480 01000424 */  addiu      $4, $0, 0x1
    /* 1CF484 002CF484 06002416 */  bne        $17, $4, .L002CF4A0
    /* 1CF488 002CF488 00000000 */   nop
    /* 1CF48C 002CF48C 04004016 */  bnez       $18, .L002CF4A0
    /* 1CF490 002CF490 00000000 */   nop
    /* 1CF494 002CF494 02000386 */  lh         $3, 0x2($16)
    /* 1CF498 002CF498 2E086410 */  beq        $3, $4, .L002D1554
    /* 1CF49C 002CF49C 00000000 */   nop
  .L002CF4A0:
    /* 1CF4A0 002CF4A0 80101200 */  sll        $2, $18, 2
    /* 1CF4A4 002CF4A4 21105000 */  addu       $2, $2, $16
    /* 1CF4A8 002CF4A8 180F448C */  lw         $4, 0xF18($2)
    /* 1CF4AC 002CF4AC BC890B0C */  jal        func_002e26f0
    /* 1CF4B0 002CF4B0 00000000 */   nop
    /* 1CF4B4 002CF4B4 21004018 */  blez       $2, .L002CF53C
    /* 1CF4B8 002CF4B8 00000000 */   nop
    /* 1CF4BC 002CF4BC 02000286 */  lh         $2, 0x2($16)
    /* 1CF4C0 002CF4C0 07004010 */  beqz       $2, .L002CF4E0
    /* 1CF4C4 002CF4C4 00000000 */   nop
    /* 1CF4C8 002CF4C8 2D200000 */  daddu      $4, $0, $0
    /* 1CF4CC 002CF4CC 2D280000 */  daddu      $5, $0, $0
    /* 1CF4D0 002CF4D0 2D300000 */  daddu      $6, $0, $0
    /* 1CF4D4 002CF4D4 2D380000 */  daddu      $7, $0, $0
    /* 1CF4D8 002CF4D8 D86B110C */  jal        func_0045af60
    /* 1CF4DC 002CF4DC 00000000 */   nop
  .L002CF4E0:
    /* 1CF4E0 002CF4E0 02000486 */  lh         $4, 0x2($16)
    /* 1CF4E4 002CF4E4 01000524 */  addiu      $5, $0, 0x1
    /* 1CF4E8 002CF4E8 2D300000 */  daddu      $6, $0, $0
    /* 1CF4EC 002CF4EC 2D380000 */  daddu      $7, $0, $0
    /* 1CF4F0 002CF4F0 2D40A000 */  daddu      $8, $5, $0
    /* 1CF4F4 002CF4F4 40CB0A0C */  jal        func_002b2d00
    /* 1CF4F8 002CF4F8 00000000 */   nop
    /* 1CF4FC 002CF4FC 020002A6 */  sh         $2, 0x2($16)
    /* 1CF500 002CF500 11000282 */  lb         $2, 0x11($16)
    /* 1CF504 002CF504 80100200 */  sll        $2, $2, 2
    /* 1CF508 002CF508 21105000 */  addu       $2, $2, $16
    /* 1CF50C 002CF50C 180F448C */  lw         $4, 0xF18($2)
    /* 1CF510 002CF510 BC890B0C */  jal        func_002e26f0
    /* 1CF514 002CF514 00000000 */   nop
    /* 1CF518 002CF518 3C340200 */  dsll32     $6, $2, 16
    /* 1CF51C 002CF51C 3F340600 */  dsra32     $6, $6, 16
    /* 1CF520 002CF520 02000486 */  lh         $4, 0x2($16)
    /* 1CF524 002CF524 04000586 */  lh         $5, 0x4($16)
    /* 1CF528 002CF528 05000724 */  addiu      $7, $0, 0x5
    /* 1CF52C 002CF52C FFFF0824 */  addiu      $8, $0, -0x1
    /* 1CF530 002CF530 54CB0A0C */  jal        func_002b2d50
    /* 1CF534 002CF534 00000000 */   nop
    /* 1CF538 002CF538 040002A6 */  sh         $2, 0x4($16)
  .L002CF53C:
    /* 1CF53C 002CF53C 01000324 */  addiu      $3, $0, 0x1
    /* 1CF540 002CF540 140003A2 */  sb         $3, 0x14($16)
    /* 1CF544 002CF544 03080010 */  b          .L002D1554
    /* 1CF548 002CF548 00000000 */   nop
  .L002CF54C:
    /* 1CF54C 002CF54C 0040A330 */  andi       $3, $5, 0x4000
    /* 1CF550 002CF550 51006010 */  beqz       $3, .L002CF698
    /* 1CF554 002CF554 00000000 */   nop
    /* 1CF558 002CF558 14000382 */  lb         $3, 0x14($16)
    /* 1CF55C 002CF55C 4E006014 */  bnez       $3, .L002CF698
    /* 1CF560 002CF560 00000000 */   nop
    /* 1CF564 002CF564 11000282 */  lb         $2, 0x11($16)
    /* 1CF568 002CF568 80100200 */  sll        $2, $2, 2
    /* 1CF56C 002CF56C 21105000 */  addu       $2, $2, $16
    /* 1CF570 002CF570 180F448C */  lw         $4, 0xF18($2)
    /* 1CF574 002CF574 BC890B0C */  jal        func_002e26f0
    /* 1CF578 002CF578 00000000 */   nop
    /* 1CF57C 002CF57C 11000482 */  lb         $4, 0x11($16)
    /* 1CF580 002CF580 7500033C */  lui        $3, %hi(D_00748908)
    /* 1CF584 002CF584 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1CF588 002CF588 21186400 */  addu       $3, $3, $4
    /* 1CF58C 002CF58C 00006380 */  lb         $3, 0x0($3)
    /* 1CF590 002CF590 2A086200 */  slt        $1, $3, $2
    /* 1CF594 002CF594 EF072010 */  beqz       $1, .L002D1554
    /* 1CF598 002CF598 00000000 */   nop
    /* 1CF59C 002CF59C 2D200000 */  daddu      $4, $0, $0
    /* 1CF5A0 002CF5A0 2D280000 */  daddu      $5, $0, $0
    /* 1CF5A4 002CF5A4 2D300000 */  daddu      $6, $0, $0
    /* 1CF5A8 002CF5A8 2D380000 */  daddu      $7, $0, $0
    /* 1CF5AC 002CF5AC D86B110C */  jal        func_0045af60
    /* 1CF5B0 002CF5B0 00000000 */   nop
    /* 1CF5B4 002CF5B4 3C8C1200 */  dsll32     $17, $18, 16
    /* 1CF5B8 002CF5B8 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CF5BC 002CF5BC 02000486 */  lh         $4, 0x2($16)
    /* 1CF5C0 002CF5C0 01000524 */  addiu      $5, $0, 0x1
    /* 1CF5C4 002CF5C4 2D302002 */  daddu      $6, $17, $0
    /* 1CF5C8 002CF5C8 2D380000 */  daddu      $7, $0, $0
    /* 1CF5CC 002CF5CC 02000824 */  addiu      $8, $0, 0x2
    /* 1CF5D0 002CF5D0 2CCB0A0C */  jal        func_002b2cb0
    /* 1CF5D4 002CF5D4 00000000 */   nop
    /* 1CF5D8 002CF5D8 020002A6 */  sh         $2, 0x2($16)
    /* 1CF5DC 002CF5DC 3C240200 */  dsll32     $4, $2, 16
    /* 1CF5E0 002CF5E0 3F240400 */  dsra32     $4, $4, 16
    /* 1CF5E4 002CF5E4 0D008014 */  bnez       $4, .L002CF61C
    /* 1CF5E8 002CF5E8 00000000 */   nop
    /* 1CF5EC 002CF5EC 040000A6 */  sh         $0, 0x4($16)
    /* 1CF5F0 002CF5F0 11000382 */  lb         $3, 0x11($16)
    /* 1CF5F4 002CF5F4 24006014 */  bnez       $3, .L002CF688
    /* 1CF5F8 002CF5F8 00000000 */   nop
    /* 1CF5FC 002CF5FC 240C0482 */  lb         $4, 0xC24($16)
    /* 1CF600 002CF600 01000324 */  addiu      $3, $0, 0x1
    /* 1CF604 002CF604 20008314 */  bne        $4, $3, .L002CF688
    /* 1CF608 002CF608 00000000 */   nop
    /* 1CF60C 002CF60C 020003A6 */  sh         $3, 0x2($16)
    /* 1CF610 002CF610 040003A6 */  sh         $3, 0x4($16)
    /* 1CF614 002CF614 1C000010 */  b          .L002CF688
    /* 1CF618 002CF618 00000000 */   nop
  .L002CF61C:
    /* 1CF61C 002CF61C 0500222A */  slti       $2, $17, 0x5
    /* 1CF620 002CF620 0A004014 */  bnez       $2, .L002CF64C
    /* 1CF624 002CF624 00000000 */   nop
    /* 1CF628 002CF628 04000586 */  lh         $5, 0x4($16)
    /* 1CF62C 002CF62C 2D304002 */  daddu      $6, $18, $0
    /* 1CF630 002CF630 05000724 */  addiu      $7, $0, 0x5
    /* 1CF634 002CF634 01000824 */  addiu      $8, $0, 0x1
    /* 1CF638 002CF638 54CB0A0C */  jal        func_002b2d50
    /* 1CF63C 002CF63C 00000000 */   nop
    /* 1CF640 002CF640 040002A6 */  sh         $2, 0x4($16)
    /* 1CF644 002CF644 10000010 */  b          .L002CF688
    /* 1CF648 002CF648 00000000 */   nop
  .L002CF64C:
    /* 1CF64C 002CF64C 11000282 */  lb         $2, 0x11($16)
    /* 1CF650 002CF650 80100200 */  sll        $2, $2, 2
    /* 1CF654 002CF654 21105000 */  addu       $2, $2, $16
    /* 1CF658 002CF658 180F448C */  lw         $4, 0xF18($2)
    /* 1CF65C 002CF65C BC890B0C */  jal        func_002e26f0
    /* 1CF660 002CF660 00000000 */   nop
    /* 1CF664 002CF664 3C3C0200 */  dsll32     $7, $2, 16
    /* 1CF668 002CF668 3F3C0700 */  dsra32     $7, $7, 16
    /* 1CF66C 002CF66C 02000486 */  lh         $4, 0x2($16)
    /* 1CF670 002CF670 04000586 */  lh         $5, 0x4($16)
    /* 1CF674 002CF674 2D304002 */  daddu      $6, $18, $0
    /* 1CF678 002CF678 01000824 */  addiu      $8, $0, 0x1
    /* 1CF67C 002CF67C 54CB0A0C */  jal        func_002b2d50
    /* 1CF680 002CF680 00000000 */   nop
    /* 1CF684 002CF684 040002A6 */  sh         $2, 0x4($16)
  .L002CF688:
    /* 1CF688 002CF688 01000324 */  addiu      $3, $0, 0x1
    /* 1CF68C 002CF68C 140003A2 */  sb         $3, 0x14($16)
    /* 1CF690 002CF690 B0070010 */  b          .L002D1554
    /* 1CF694 002CF694 00000000 */   nop
  .L002CF698:
    /* 1CF698 002CF698 00408330 */  andi       $3, $4, 0x4000
    /* 1CF69C 002CF69C 4A006010 */  beqz       $3, .L002CF7C8
    /* 1CF6A0 002CF6A0 00000000 */   nop
    /* 1CF6A4 002CF6A4 11001182 */  lb         $17, 0x11($16)
    /* 1CF6A8 002CF6A8 80101100 */  sll        $2, $17, 2
    /* 1CF6AC 002CF6AC 21105000 */  addu       $2, $2, $16
    /* 1CF6B0 002CF6B0 180F448C */  lw         $4, 0xF18($2)
    /* 1CF6B4 002CF6B4 BC890B0C */  jal        func_002e26f0
    /* 1CF6B8 002CF6B8 00000000 */   nop
    /* 1CF6BC 002CF6BC 7500033C */  lui        $3, %hi(D_00748908)
    /* 1CF6C0 002CF6C0 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1CF6C4 002CF6C4 21187100 */  addu       $3, $3, $17
    /* 1CF6C8 002CF6C8 00006380 */  lb         $3, 0x0($3)
    /* 1CF6CC 002CF6CC 2A086200 */  slt        $1, $3, $2
    /* 1CF6D0 002CF6D0 A0072010 */  beqz       $1, .L002D1554
    /* 1CF6D4 002CF6D4 00000000 */   nop
    /* 1CF6D8 002CF6D8 80101100 */  sll        $2, $17, 2
    /* 1CF6DC 002CF6DC 21105000 */  addu       $2, $2, $16
    /* 1CF6E0 002CF6E0 180F448C */  lw         $4, 0xF18($2)
    /* 1CF6E4 002CF6E4 BC890B0C */  jal        func_002e26f0
    /* 1CF6E8 002CF6E8 00000000 */   nop
    /* 1CF6EC 002CF6EC 34004018 */  blez       $2, .L002CF7C0
    /* 1CF6F0 002CF6F0 00000000 */   nop
    /* 1CF6F4 002CF6F4 3C1C1200 */  dsll32     $3, $18, 16
    /* 1CF6F8 002CF6F8 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CF6FC 002CF6FC 02000286 */  lh         $2, 0x2($16)
    /* 1CF700 002CF700 07004310 */  beq        $2, $3, .L002CF720
    /* 1CF704 002CF704 00000000 */   nop
    /* 1CF708 002CF708 2D200000 */  daddu      $4, $0, $0
    /* 1CF70C 002CF70C 2D280000 */  daddu      $5, $0, $0
    /* 1CF710 002CF710 2D300000 */  daddu      $6, $0, $0
    /* 1CF714 002CF714 2D380000 */  daddu      $7, $0, $0
    /* 1CF718 002CF718 D86B110C */  jal        func_0045af60
    /* 1CF71C 002CF71C 00000000 */   nop
  .L002CF720:
    /* 1CF720 002CF720 3C8C1200 */  dsll32     $17, $18, 16
    /* 1CF724 002CF724 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CF728 002CF728 02000486 */  lh         $4, 0x2($16)
    /* 1CF72C 002CF72C 01000524 */  addiu      $5, $0, 0x1
    /* 1CF730 002CF730 2D302002 */  daddu      $6, $17, $0
    /* 1CF734 002CF734 2D380000 */  daddu      $7, $0, $0
    /* 1CF738 002CF738 2D40A000 */  daddu      $8, $5, $0
    /* 1CF73C 002CF73C 2CCB0A0C */  jal        func_002b2cb0
    /* 1CF740 002CF740 00000000 */   nop
    /* 1CF744 002CF744 020002A6 */  sh         $2, 0x2($16)
    /* 1CF748 002CF748 0500222A */  slti       $2, $17, 0x5
    /* 1CF74C 002CF74C 0B004014 */  bnez       $2, .L002CF77C
    /* 1CF750 002CF750 00000000 */   nop
    /* 1CF754 002CF754 02000486 */  lh         $4, 0x2($16)
    /* 1CF758 002CF758 04000586 */  lh         $5, 0x4($16)
    /* 1CF75C 002CF75C 2D304002 */  daddu      $6, $18, $0
    /* 1CF760 002CF760 05000724 */  addiu      $7, $0, 0x5
    /* 1CF764 002CF764 01000824 */  addiu      $8, $0, 0x1
    /* 1CF768 002CF768 54CB0A0C */  jal        func_002b2d50
    /* 1CF76C 002CF76C 00000000 */   nop
    /* 1CF770 002CF770 040002A6 */  sh         $2, 0x4($16)
    /* 1CF774 002CF774 10000010 */  b          .L002CF7B8
    /* 1CF778 002CF778 00000000 */   nop
  .L002CF77C:
    /* 1CF77C 002CF77C 11000282 */  lb         $2, 0x11($16)
    /* 1CF780 002CF780 80100200 */  sll        $2, $2, 2
    /* 1CF784 002CF784 21105000 */  addu       $2, $2, $16
    /* 1CF788 002CF788 180F448C */  lw         $4, 0xF18($2)
    /* 1CF78C 002CF78C BC890B0C */  jal        func_002e26f0
    /* 1CF790 002CF790 00000000 */   nop
    /* 1CF794 002CF794 3C3C0200 */  dsll32     $7, $2, 16
    /* 1CF798 002CF798 3F3C0700 */  dsra32     $7, $7, 16
    /* 1CF79C 002CF79C 02000486 */  lh         $4, 0x2($16)
    /* 1CF7A0 002CF7A0 04000586 */  lh         $5, 0x4($16)
    /* 1CF7A4 002CF7A4 2D304002 */  daddu      $6, $18, $0
    /* 1CF7A8 002CF7A8 01000824 */  addiu      $8, $0, 0x1
    /* 1CF7AC 002CF7AC 54CB0A0C */  jal        func_002b2d50
    /* 1CF7B0 002CF7B0 00000000 */   nop
    /* 1CF7B4 002CF7B4 040002A6 */  sh         $2, 0x4($16)
  .L002CF7B8:
    /* 1CF7B8 002CF7B8 01000324 */  addiu      $3, $0, 0x1
    /* 1CF7BC 002CF7BC 140003A2 */  sb         $3, 0x14($16)
  .L002CF7C0:
    /* 1CF7C0 002CF7C0 64070010 */  b          .L002D1554
    /* 1CF7C4 002CF7C4 00000000 */   nop
  .L002CF7C8:
    /* 1CF7C8 002CF7C8 02008330 */  andi       $3, $4, 0x2
    /* 1CF7CC 002CF7CC 04006014 */  bnez       $3, .L002CF7E0
    /* 1CF7D0 002CF7D0 00000000 */   nop
    /* 1CF7D4 002CF7D4 00208330 */  andi       $3, $4, 0x2000
    /* 1CF7D8 002CF7D8 2A006010 */  beqz       $3, .L002CF884
    /* 1CF7DC 002CF7DC 00000000 */   nop
  .L002CF7E0:
    /* 1CF7E0 002CF7E0 11000282 */  lb         $2, 0x11($16)
    /* 1CF7E4 002CF7E4 80100200 */  sll        $2, $2, 2
    /* 1CF7E8 002CF7E8 21105000 */  addu       $2, $2, $16
    /* 1CF7EC 002CF7EC 180F448C */  lw         $4, 0xF18($2)
    /* 1CF7F0 002CF7F0 BC890B0C */  jal        func_002e26f0
    /* 1CF7F4 002CF7F4 00000000 */   nop
    /* 1CF7F8 002CF7F8 11000482 */  lb         $4, 0x11($16)
    /* 1CF7FC 002CF7FC 7500033C */  lui        $3, %hi(D_00748908)
    /* 1CF800 002CF800 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1CF804 002CF804 21186400 */  addu       $3, $3, $4
    /* 1CF808 002CF808 00006380 */  lb         $3, 0x0($3)
    /* 1CF80C 002CF80C 2A086200 */  slt        $1, $3, $2
    /* 1CF810 002CF810 50072010 */  beqz       $1, .L002D1554
    /* 1CF814 002CF814 00000000 */   nop
    /* 1CF818 002CF818 02000386 */  lh         $3, 0x2($16)
    /* 1CF81C 002CF81C 3C141200 */  dsll32     $2, $18, 16
    /* 1CF820 002CF820 3F140200 */  dsra32     $2, $2, 16
    /* 1CF824 002CF824 07006210 */  beq        $3, $2, .L002CF844
    /* 1CF828 002CF828 00000000 */   nop
    /* 1CF82C 002CF82C 2D200000 */  daddu      $4, $0, $0
    /* 1CF830 002CF830 2D280000 */  daddu      $5, $0, $0
    /* 1CF834 002CF834 2D300000 */  daddu      $6, $0, $0
    /* 1CF838 002CF838 2D380000 */  daddu      $7, $0, $0
    /* 1CF83C 002CF83C D86B110C */  jal        func_0045af60
    /* 1CF840 002CF840 00000000 */   nop
  .L002CF844:
    /* 1CF844 002CF844 11000282 */  lb         $2, 0x11($16)
    /* 1CF848 002CF848 80100200 */  sll        $2, $2, 2
    /* 1CF84C 002CF84C 21105000 */  addu       $2, $2, $16
    /* 1CF850 002CF850 180F448C */  lw         $4, 0xF18($2)
    /* 1CF854 002CF854 BC890B0C */  jal        func_002e26f0
    /* 1CF858 002CF858 00000000 */   nop
    /* 1CF85C 002CF85C 02000486 */  lh         $4, 0x2($16)
    /* 1CF860 002CF860 04000586 */  lh         $5, 0x4($16)
    /* 1CF864 002CF864 2D304000 */  daddu      $6, $2, $0
    /* 1CF868 002CF868 05000724 */  addiu      $7, $0, 0x5
    /* 1CF86C 002CF86C 02000826 */  addiu      $8, $16, 0x2
    /* 1CF870 002CF870 04000926 */  addiu      $9, $16, 0x4
    /* 1CF874 002CF874 9CCB0A0C */  jal        func_002b2e70
    /* 1CF878 002CF878 00000000 */   nop
    /* 1CF87C 002CF87C 34070010 */  b          .L002D1550
    /* 1CF880 002CF880 00000000 */   nop
  .L002CF884:
    /* 1CF884 002CF884 01008330 */  andi       $3, $4, 0x1
    /* 1CF888 002CF888 04006014 */  bnez       $3, .L002CF89C
    /* 1CF88C 002CF88C 00000000 */   nop
    /* 1CF890 002CF890 00808330 */  andi       $3, $4, 0x8000
    /* 1CF894 002CF894 55006010 */  beqz       $3, .L002CF9EC
    /* 1CF898 002CF898 00000000 */   nop
  .L002CF89C:
    /* 1CF89C 002CF89C 11000382 */  lb         $3, 0x11($16)
    /* 1CF8A0 002CF8A0 7500023C */  lui        $2, %hi(D_00748908)
    /* 1CF8A4 002CF8A4 08894224 */  addiu      $2, $2, %lo(D_00748908)
    /* 1CF8A8 002CF8A8 21104300 */  addu       $2, $2, $3
    /* 1CF8AC 002CF8AC 00005180 */  lb         $17, 0x0($2)
    /* 1CF8B0 002CF8B0 80100300 */  sll        $2, $3, 2
    /* 1CF8B4 002CF8B4 21105000 */  addu       $2, $2, $16
    /* 1CF8B8 002CF8B8 180F448C */  lw         $4, 0xF18($2)
    /* 1CF8BC 002CF8BC BC890B0C */  jal        func_002e26f0
    /* 1CF8C0 002CF8C0 00000000 */   nop
    /* 1CF8C4 002CF8C4 2A082202 */  slt        $1, $17, $2
    /* 1CF8C8 002CF8C8 22072010 */  beqz       $1, .L002D1554
    /* 1CF8CC 002CF8CC 00000000 */   nop
    /* 1CF8D0 002CF8D0 240C0282 */  lb         $2, 0xC24($16)
    /* 1CF8D4 002CF8D4 1A004014 */  bnez       $2, .L002CF940
    /* 1CF8D8 002CF8D8 00000000 */   nop
    /* 1CF8DC 002CF8DC 02000286 */  lh         $2, 0x2($16)
    /* 1CF8E0 002CF8E0 07004010 */  beqz       $2, .L002CF900
    /* 1CF8E4 002CF8E4 00000000 */   nop
    /* 1CF8E8 002CF8E8 2D200000 */  daddu      $4, $0, $0
    /* 1CF8EC 002CF8EC 2D280000 */  daddu      $5, $0, $0
    /* 1CF8F0 002CF8F0 2D300000 */  daddu      $6, $0, $0
    /* 1CF8F4 002CF8F4 2D380000 */  daddu      $7, $0, $0
    /* 1CF8F8 002CF8F8 D86B110C */  jal        func_0045af60
    /* 1CF8FC 002CF8FC 00000000 */   nop
  .L002CF900:
    /* 1CF900 002CF900 11000282 */  lb         $2, 0x11($16)
    /* 1CF904 002CF904 80100200 */  sll        $2, $2, 2
    /* 1CF908 002CF908 21105000 */  addu       $2, $2, $16
    /* 1CF90C 002CF90C 180F448C */  lw         $4, 0xF18($2)
    /* 1CF910 002CF910 BC890B0C */  jal        func_002e26f0
    /* 1CF914 002CF914 00000000 */   nop
    /* 1CF918 002CF918 02000486 */  lh         $4, 0x2($16)
    /* 1CF91C 002CF91C 04000586 */  lh         $5, 0x4($16)
    /* 1CF920 002CF920 2D304000 */  daddu      $6, $2, $0
    /* 1CF924 002CF924 05000724 */  addiu      $7, $0, 0x5
    /* 1CF928 002CF928 02000826 */  addiu      $8, $16, 0x2
    /* 1CF92C 002CF92C 04000926 */  addiu      $9, $16, 0x4
    /* 1CF930 002CF930 E4CB0A0C */  jal        func_002b2f90
    /* 1CF934 002CF934 00000000 */   nop
    /* 1CF938 002CF938 05070010 */  b          .L002D1550
    /* 1CF93C 002CF93C 00000000 */   nop
  .L002CF940:
    /* 1CF940 002CF940 02000286 */  lh         $2, 0x2($16)
    /* 1CF944 002CF944 07005110 */  beq        $2, $17, .L002CF964
    /* 1CF948 002CF948 00000000 */   nop
    /* 1CF94C 002CF94C 2D200000 */  daddu      $4, $0, $0
    /* 1CF950 002CF950 2D280000 */  daddu      $5, $0, $0
    /* 1CF954 002CF954 2D300000 */  daddu      $6, $0, $0
    /* 1CF958 002CF958 2D380000 */  daddu      $7, $0, $0
    /* 1CF95C 002CF95C D86B110C */  jal        func_0045af60
    /* 1CF960 002CF960 00000000 */   nop
  .L002CF964:
    /* 1CF964 002CF964 11000282 */  lb         $2, 0x11($16)
    /* 1CF968 002CF968 11004014 */  bnez       $2, .L002CF9B0
    /* 1CF96C 002CF96C 00000000 */   nop
    /* 1CF970 002CF970 80100200 */  sll        $2, $2, 2
    /* 1CF974 002CF974 21105000 */  addu       $2, $2, $16
    /* 1CF978 002CF978 180F448C */  lw         $4, 0xF18($2)
    /* 1CF97C 002CF97C BC890B0C */  jal        func_002e26f0
    /* 1CF980 002CF980 00000000 */   nop
    /* 1CF984 002CF984 02000486 */  lh         $4, 0x2($16)
    /* 1CF988 002CF988 04000586 */  lh         $5, 0x4($16)
    /* 1CF98C 002CF98C 2D304000 */  daddu      $6, $2, $0
    /* 1CF990 002CF990 05000724 */  addiu      $7, $0, 0x5
    /* 1CF994 002CF994 01000824 */  addiu      $8, $0, 0x1
    /* 1CF998 002CF998 02000926 */  addiu      $9, $16, 0x2
    /* 1CF99C 002CF99C 04000A26 */  addiu      $10, $16, 0x4
    /* 1CF9A0 002CF9A0 14CC0A0C */  jal        func_002b3050
    /* 1CF9A4 002CF9A4 00000000 */   nop
    /* 1CF9A8 002CF9A8 E9060010 */  b          .L002D1550
    /* 1CF9AC 002CF9AC 00000000 */   nop
  .L002CF9B0:
    /* 1CF9B0 002CF9B0 80100200 */  sll        $2, $2, 2
    /* 1CF9B4 002CF9B4 21105000 */  addu       $2, $2, $16
    /* 1CF9B8 002CF9B8 180F448C */  lw         $4, 0xF18($2)
    /* 1CF9BC 002CF9BC BC890B0C */  jal        func_002e26f0
    /* 1CF9C0 002CF9C0 00000000 */   nop
    /* 1CF9C4 002CF9C4 02000486 */  lh         $4, 0x2($16)
    /* 1CF9C8 002CF9C8 04000586 */  lh         $5, 0x4($16)
    /* 1CF9CC 002CF9CC 2D304000 */  daddu      $6, $2, $0
    /* 1CF9D0 002CF9D0 05000724 */  addiu      $7, $0, 0x5
    /* 1CF9D4 002CF9D4 02000826 */  addiu      $8, $16, 0x2
    /* 1CF9D8 002CF9D8 04000926 */  addiu      $9, $16, 0x4
    /* 1CF9DC 002CF9DC E4CB0A0C */  jal        func_002b2f90
    /* 1CF9E0 002CF9E0 00000000 */   nop
    /* 1CF9E4 002CF9E4 DA060010 */  b          .L002D1550
    /* 1CF9E8 002CF9E8 00000000 */   nop
  .L002CF9EC:
    /* 1CF9EC 002CF9EC 08008330 */  andi       $3, $4, 0x8
    /* 1CF9F0 002CF9F0 E6006010 */  beqz       $3, .L002CFD8C
    /* 1CF9F4 002CF9F4 00000000 */   nop
    /* 1CF9F8 002CF9F8 240C0482 */  lb         $4, 0xC24($16)
    /* 1CF9FC 002CF9FC 01000324 */  addiu      $3, $0, 0x1
    /* 1CFA00 002CFA00 D4068310 */  beq        $4, $3, .L002D1554
    /* 1CFA04 002CFA04 00000000 */   nop
    /* 1CFA08 002CFA08 2D280000 */  daddu      $5, $0, $0
    /* 1CFA0C 002CFA0C 04000424 */  addiu      $4, $0, 0x4
    /* 1CFA10 002CFA10 1A000010 */  b          .L002CFA7C
    /* 1CFA14 002CFA14 00000000 */   nop
  .L002CFA18:
    /* 1CFA18 002CFA18 2D300000 */  daddu      $6, $0, $0
    /* 1CFA1C 002CFA1C 80100300 */  sll        $2, $3, 2
    /* 1CFA20 002CFA20 21104300 */  addu       $2, $2, $3
    /* 1CFA24 002CFA24 40110200 */  sll        $2, $2, 5
    /* 1CFA28 002CFA28 21180202 */  addu       $3, $16, $2
    /* 1CFA2C 002CFA2C 0B000010 */  b          .L002CFA5C
    /* 1CFA30 002CFA30 00000000 */   nop
  .L002CFA34:
    /* 1CFA34 002CFA34 3C140600 */  dsll32     $2, $6, 16
    /* 1CFA38 002CFA38 3F140200 */  dsra32     $2, $2, 16
    /* 1CFA3C 002CFA3C 40110200 */  sll        $2, $2, 5
    /* 1CFA40 002CFA40 21106200 */  addu       $2, $3, $2
    /* 1CFA44 002CFA44 A20F40A4 */  sh         $0, 0xFA2($2)
    /* 1CFA48 002CFA48 A00F44A4 */  sh         $4, 0xFA0($2)
    /* 1CFA4C 002CFA4C A40F46A4 */  sh         $6, 0xFA4($2)
    /* 1CFA50 002CFA50 0100C224 */  addiu      $2, $6, 0x1
    /* 1CFA54 002CFA54 3C340200 */  dsll32     $6, $2, 16
    /* 1CFA58 002CFA58 3F340600 */  dsra32     $6, $6, 16
  .L002CFA5C:
    /* 1CFA5C 002CFA5C 3C140600 */  dsll32     $2, $6, 16
    /* 1CFA60 002CFA60 3F140200 */  dsra32     $2, $2, 16
    /* 1CFA64 002CFA64 05004228 */  slti       $2, $2, 0x5
    /* 1CFA68 002CFA68 F2FF4014 */  bnez       $2, .L002CFA34
    /* 1CFA6C 002CFA6C 00000000 */   nop
    /* 1CFA70 002CFA70 0100A224 */  addiu      $2, $5, 0x1
    /* 1CFA74 002CFA74 3C2C0200 */  dsll32     $5, $2, 16
    /* 1CFA78 002CFA78 3F2C0500 */  dsra32     $5, $5, 16
  .L002CFA7C:
    /* 1CFA7C 002CFA7C 3C1C0500 */  dsll32     $3, $5, 16
    /* 1CFA80 002CFA80 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CFA84 002CFA84 03006228 */  slti       $2, $3, 0x3
    /* 1CFA88 002CFA88 E3FF4014 */  bnez       $2, .L002CFA18
    /* 1CFA8C 002CFA8C 00000000 */   nop
    /* 1CFA90 002CFA90 02000386 */  lh         $3, 0x2($16)
    /* 1CFA94 002CFA94 11000282 */  lb         $2, 0x11($16)
    /* 1CFA98 002CFA98 21105000 */  addu       $2, $2, $16
    /* 1CFA9C 002CFA9C 681143A0 */  sb         $3, 0x1168($2)
    /* 1CFAA0 002CFAA0 04000386 */  lh         $3, 0x4($16)
    /* 1CFAA4 002CFAA4 11000282 */  lb         $2, 0x11($16)
    /* 1CFAA8 002CFAA8 21105000 */  addu       $2, $2, $16
    /* 1CFAAC 002CFAAC 6B1143A0 */  sb         $3, 0x116B($2)
    /* 1CFAB0 002CFAB0 11000282 */  lb         $2, 0x11($16)
    /* 1CFAB4 002CFAB4 6E1102A2 */  sb         $2, 0x116E($16)
    /* 1CFAB8 002CFAB8 11000282 */  lb         $2, 0x11($16)
    /* 1CFABC 002CFABC 80100200 */  sll        $2, $2, 2
    /* 1CFAC0 002CFAC0 21105000 */  addu       $2, $2, $16
    /* 1CFAC4 002CFAC4 180F448C */  lw         $4, 0xF18($2)
    /* 1CFAC8 002CFAC8 BC890B0C */  jal        func_002e26f0
    /* 1CFACC 002CFACC 00000000 */   nop
    /* 1CFAD0 002CFAD0 05004228 */  slti       $2, $2, 0x5
    /* 1CFAD4 002CFAD4 0B004014 */  bnez       $2, .L002CFB04
    /* 1CFAD8 002CFAD8 00000000 */   nop
    /* 1CFADC 002CFADC 11000382 */  lb         $3, 0x11($16)
    /* 1CFAE0 002CFAE0 80100300 */  sll        $2, $3, 2
    /* 1CFAE4 002CFAE4 21104300 */  addu       $2, $2, $3
    /* 1CFAE8 002CFAE8 40110200 */  sll        $2, $2, 5
    /* 1CFAEC 002CFAEC 21105000 */  addu       $2, $2, $16
    /* 1CFAF0 002CFAF0 20104284 */  lh         $2, 0x1020($2)
    /* 1CFAF4 002CFAF4 04004224 */  addiu      $2, $2, 0x4
    /* 1CFAF8 002CFAF8 701102A6 */  sh         $2, 0x1170($16)
    /* 1CFAFC 002CFAFC 15000010 */  b          .L002CFB54
    /* 1CFB00 002CFB00 00000000 */   nop
  .L002CFB04:
    /* 1CFB04 002CFB04 11000282 */  lb         $2, 0x11($16)
    /* 1CFB08 002CFB08 80100200 */  sll        $2, $2, 2
    /* 1CFB0C 002CFB0C 21105000 */  addu       $2, $2, $16
    /* 1CFB10 002CFB10 180F448C */  lw         $4, 0xF18($2)
    /* 1CFB14 002CFB14 BC890B0C */  jal        func_002e26f0
    /* 1CFB18 002CFB18 00000000 */   nop
    /* 1CFB1C 002CFB1C 40210200 */  sll        $4, $2, 5
    /* 1CFB20 002CFB20 11000282 */  lb         $2, 0x11($16)
    /* 1CFB24 002CFB24 80180200 */  sll        $3, $2, 2
    /* 1CFB28 002CFB28 21106200 */  addu       $2, $3, $2
    /* 1CFB2C 002CFB2C 40110200 */  sll        $2, $2, 5
    /* 1CFB30 002CFB30 21105000 */  addu       $2, $2, $16
    /* 1CFB34 002CFB34 21108200 */  addu       $2, $4, $2
    /* 1CFB38 002CFB38 A00F5184 */  lh         $17, 0xFA0($2)
    /* 1CFB3C 002CFB3C 21107000 */  addu       $2, $3, $16
    /* 1CFB40 002CFB40 180F448C */  lw         $4, 0xF18($2)
    /* 1CFB44 002CFB44 BC890B0C */  jal        func_002e26f0
    /* 1CFB48 002CFB48 00000000 */   nop
    /* 1CFB4C 002CFB4C 21102202 */  addu       $2, $17, $2
    /* 1CFB50 002CFB50 701102A6 */  sh         $2, 0x1170($16)
  .L002CFB54:
    /* 1CFB54 002CFB54 11000482 */  lb         $4, 0x11($16)
    /* 1CFB58 002CFB58 01000524 */  addiu      $5, $0, 0x1
    /* 1CFB5C 002CFB5C 02000624 */  addiu      $6, $0, 0x2
    /* 1CFB60 002CFB60 2D380000 */  daddu      $7, $0, $0
    /* 1CFB64 002CFB64 2D40C000 */  daddu      $8, $6, $0
    /* 1CFB68 002CFB68 2CCB0A0C */  jal        func_002b2cb0
    /* 1CFB6C 002CFB6C 00000000 */   nop
    /* 1CFB70 002CFB70 110002A2 */  sb         $2, 0x11($16)
    /* 1CFB74 002CFB74 3C2E0200 */  dsll32     $5, $2, 24
    /* 1CFB78 002CFB78 3F2E0500 */  dsra32     $5, $5, 24
    /* 1CFB7C 002CFB7C 2D208002 */  daddu      $4, $20, $0
    /* 1CFB80 002CFB80 D8510B0C */  jal        func_002d4760
    /* 1CFB84 002CFB84 00000000 */   nop
    /* 1CFB88 002CFB88 11000582 */  lb         $5, 0x11($16)
    /* 1CFB8C 002CFB8C 2D208002 */  daddu      $4, $20, $0
    /* 1CFB90 002CFB90 045F0B0C */  jal        func_002d7c10
    /* 1CFB94 002CFB94 00000000 */   nop
    /* 1CFB98 002CFB98 020000A6 */  sh         $0, 0x2($16)
    /* 1CFB9C 002CFB9C 040000A6 */  sh         $0, 0x4($16)
    /* 1CFBA0 002CFBA0 11000282 */  lb         $2, 0x11($16)
    /* 1CFBA4 002CFBA4 21105000 */  addu       $2, $2, $16
    /* 1CFBA8 002CFBA8 681140A0 */  sb         $0, 0x1168($2)
    /* 1CFBAC 002CFBAC 11000282 */  lb         $2, 0x11($16)
    /* 1CFBB0 002CFBB0 21105000 */  addu       $2, $2, $16
    /* 1CFBB4 002CFBB4 6B1140A0 */  sb         $0, 0x116B($2)
    /* 1CFBB8 002CFBB8 11000282 */  lb         $2, 0x11($16)
    /* 1CFBBC 002CFBBC 80100200 */  sll        $2, $2, 2
    /* 1CFBC0 002CFBC0 21105000 */  addu       $2, $2, $16
    /* 1CFBC4 002CFBC4 180F448C */  lw         $4, 0xF18($2)
    /* 1CFBC8 002CFBC8 BC890B0C */  jal        func_002e26f0
    /* 1CFBCC 002CFBCC 00000000 */   nop
    /* 1CFBD0 002CFBD0 05004228 */  slti       $2, $2, 0x5
    /* 1CFBD4 002CFBD4 0B004014 */  bnez       $2, .L002CFC04
    /* 1CFBD8 002CFBD8 00000000 */   nop
    /* 1CFBDC 002CFBDC 11000382 */  lb         $3, 0x11($16)
    /* 1CFBE0 002CFBE0 80100300 */  sll        $2, $3, 2
    /* 1CFBE4 002CFBE4 21104300 */  addu       $2, $2, $3
    /* 1CFBE8 002CFBE8 40110200 */  sll        $2, $2, 5
    /* 1CFBEC 002CFBEC 21105000 */  addu       $2, $2, $16
    /* 1CFBF0 002CFBF0 20104284 */  lh         $2, 0x1020($2)
    /* 1CFBF4 002CFBF4 04004224 */  addiu      $2, $2, 0x4
    /* 1CFBF8 002CFBF8 701102A6 */  sh         $2, 0x1170($16)
    /* 1CFBFC 002CFBFC 30000010 */  b          .L002CFCC0
    /* 1CFC00 002CFC00 00000000 */   nop
  .L002CFC04:
    /* 1CFC04 002CFC04 11001382 */  lb         $19, 0x11($16)
    /* 1CFC08 002CFC08 70111286 */  lh         $18, 0x1170($16)
    /* 1CFC0C 002CFC0C 80101300 */  sll        $2, $19, 2
    /* 1CFC10 002CFC10 21105000 */  addu       $2, $2, $16
    /* 1CFC14 002CFC14 180F448C */  lw         $4, 0xF18($2)
    /* 1CFC18 002CFC18 BC890B0C */  jal        func_002e26f0
    /* 1CFC1C 002CFC1C 00000000 */   nop
    /* 1CFC20 002CFC20 40190200 */  sll        $3, $2, 5
    /* 1CFC24 002CFC24 80101300 */  sll        $2, $19, 2
    /* 1CFC28 002CFC28 21105300 */  addu       $2, $2, $19
    /* 1CFC2C 002CFC2C 40110200 */  sll        $2, $2, 5
    /* 1CFC30 002CFC30 21105000 */  addu       $2, $2, $16
    /* 1CFC34 002CFC34 21106200 */  addu       $2, $3, $2
    /* 1CFC38 002CFC38 A00F5184 */  lh         $17, 0xFA0($2)
    /* 1CFC3C 002CFC3C 11000282 */  lb         $2, 0x11($16)
    /* 1CFC40 002CFC40 80100200 */  sll        $2, $2, 2
    /* 1CFC44 002CFC44 21105000 */  addu       $2, $2, $16
    /* 1CFC48 002CFC48 180F448C */  lw         $4, 0xF18($2)
    /* 1CFC4C 002CFC4C BC890B0C */  jal        func_002e26f0
    /* 1CFC50 002CFC50 00000000 */   nop
    /* 1CFC54 002CFC54 21102202 */  addu       $2, $17, $2
    /* 1CFC58 002CFC58 3C140200 */  dsll32     $2, $2, 16
    /* 1CFC5C 002CFC5C 3F140200 */  dsra32     $2, $2, 16
    /* 1CFC60 002CFC60 2A084202 */  slt        $1, $18, $2
    /* 1CFC64 002CFC64 16002010 */  beqz       $1, .L002CFCC0
    /* 1CFC68 002CFC68 00000000 */   nop
    /* 1CFC6C 002CFC6C 11000282 */  lb         $2, 0x11($16)
    /* 1CFC70 002CFC70 80100200 */  sll        $2, $2, 2
    /* 1CFC74 002CFC74 21105000 */  addu       $2, $2, $16
    /* 1CFC78 002CFC78 180F448C */  lw         $4, 0xF18($2)
    /* 1CFC7C 002CFC7C BC890B0C */  jal        func_002e26f0
    /* 1CFC80 002CFC80 00000000 */   nop
    /* 1CFC84 002CFC84 40210200 */  sll        $4, $2, 5
    /* 1CFC88 002CFC88 11000382 */  lb         $3, 0x11($16)
    /* 1CFC8C 002CFC8C 80100300 */  sll        $2, $3, 2
    /* 1CFC90 002CFC90 21104300 */  addu       $2, $2, $3
    /* 1CFC94 002CFC94 40110200 */  sll        $2, $2, 5
    /* 1CFC98 002CFC98 21105000 */  addu       $2, $2, $16
    /* 1CFC9C 002CFC9C 21108200 */  addu       $2, $4, $2
    /* 1CFCA0 002CFCA0 A00F5184 */  lh         $17, 0xFA0($2)
    /* 1CFCA4 002CFCA4 80101300 */  sll        $2, $19, 2
    /* 1CFCA8 002CFCA8 21105000 */  addu       $2, $2, $16
    /* 1CFCAC 002CFCAC 180F448C */  lw         $4, 0xF18($2)
    /* 1CFCB0 002CFCB0 BC890B0C */  jal        func_002e26f0
    /* 1CFCB4 002CFCB4 00000000 */   nop
    /* 1CFCB8 002CFCB8 21102202 */  addu       $2, $17, $2
    /* 1CFCBC 002CFCBC 701102A6 */  sh         $2, 0x1170($16)
  .L002CFCC0:
    /* 1CFCC0 002CFCC0 11000382 */  lb         $3, 0x11($16)
    /* 1CFCC4 002CFCC4 02000224 */  addiu      $2, $0, 0x2
    /* 1CFCC8 002CFCC8 1D006210 */  beq        $3, $2, .L002CFD40
    /* 1CFCCC 002CFCCC 00000000 */   nop
    /* 1CFCD0 002CFCD0 01000724 */  addiu      $7, $0, 0x1
    /* 1CFCD4 002CFCD4 10006710 */  beq        $3, $7, .L002CFD18
    /* 1CFCD8 002CFCD8 00000000 */   nop
    /* 1CFCDC 002CFCDC 03006010 */  beqz       $3, .L002CFCEC
    /* 1CFCE0 002CFCE0 00000000 */   nop
    /* 1CFCE4 002CFCE4 1F000010 */  b          .L002CFD64
    /* 1CFCE8 002CFCE8 00000000 */   nop
  .L002CFCEC:
    /* 1CFCEC 002CFCEC 80100300 */  sll        $2, $3, 2
    /* 1CFCF0 002CFCF0 21105000 */  addu       $2, $2, $16
    /* 1CFCF4 002CFCF4 180F448C */  lw         $4, 0xF18($2)
    /* 1CFCF8 002CFCF8 0400053C */  lui        $5, (0x40000 >> 16)
    /* 1CFCFC 002CFCFC 2D300000 */  daddu      $6, $0, $0
    /* 1CFD00 002CFD00 04000724 */  addiu      $7, $0, 0x4
    /* 1CFD04 002CFD04 2D400000 */  daddu      $8, $0, $0
    /* 1CFD08 002CFD08 588D0B0C */  jal        func_002e3560
    /* 1CFD0C 002CFD0C 00000000 */   nop
    /* 1CFD10 002CFD10 14000010 */  b          .L002CFD64
    /* 1CFD14 002CFD14 00000000 */   nop
  .L002CFD18:
    /* 1CFD18 002CFD18 80100300 */  sll        $2, $3, 2
    /* 1CFD1C 002CFD1C 21105000 */  addu       $2, $2, $16
    /* 1CFD20 002CFD20 180F448C */  lw         $4, 0xF18($2)
    /* 1CFD24 002CFD24 FFFF0534 */  ori        $5, $0, 0xFFFF
    /* 1CFD28 002CFD28 E01F0624 */  addiu      $6, $0, 0x1FE0
    /* 1CFD2C 002CFD2C 2D400000 */  daddu      $8, $0, $0
    /* 1CFD30 002CFD30 588D0B0C */  jal        func_002e3560
    /* 1CFD34 002CFD34 00000000 */   nop
    /* 1CFD38 002CFD38 0A000010 */  b          .L002CFD64
    /* 1CFD3C 002CFD3C 00000000 */   nop
  .L002CFD40:
    /* 1CFD40 002CFD40 80100300 */  sll        $2, $3, 2
    /* 1CFD44 002CFD44 21105000 */  addu       $2, $2, $16
    /* 1CFD48 002CFD48 180F448C */  lw         $4, 0xF18($2)
    /* 1CFD4C 002CFD4C 0100053C */  lui        $5, (0x10000 >> 16)
    /* 1CFD50 002CFD50 2D300000 */  daddu      $6, $0, $0
    /* 1CFD54 002CFD54 01000724 */  addiu      $7, $0, 0x1
    /* 1CFD58 002CFD58 2D400000 */  daddu      $8, $0, $0
    /* 1CFD5C 002CFD5C 588D0B0C */  jal        func_002e3560
    /* 1CFD60 002CFD60 00000000 */   nop
  .L002CFD64:
    /* 1CFD64 002CFD64 33000224 */  addiu      $2, $0, 0x33
    /* 1CFD68 002CFD68 000002A2 */  sb         $2, 0x0($16)
    /* 1CFD6C 002CFD6C 2D200000 */  daddu      $4, $0, $0
    /* 1CFD70 002CFD70 2D280000 */  daddu      $5, $0, $0
    /* 1CFD74 002CFD74 2D300000 */  daddu      $6, $0, $0
    /* 1CFD78 002CFD78 05000724 */  addiu      $7, $0, 0x5
    /* 1CFD7C 002CFD7C D86B110C */  jal        func_0045af60
    /* 1CFD80 002CFD80 00000000 */   nop
    /* 1CFD84 002CFD84 F2050010 */  b          .L002D1550
    /* 1CFD88 002CFD88 00000000 */   nop
  .L002CFD8C:
    /* 1CFD8C 002CFD8C 04008330 */  andi       $3, $4, 0x4
    /* 1CFD90 002CFD90 E6006010 */  beqz       $3, .L002D012C
    /* 1CFD94 002CFD94 00000000 */   nop
    /* 1CFD98 002CFD98 240C0482 */  lb         $4, 0xC24($16)
    /* 1CFD9C 002CFD9C 01000324 */  addiu      $3, $0, 0x1
    /* 1CFDA0 002CFDA0 EC058310 */  beq        $4, $3, .L002D1554
    /* 1CFDA4 002CFDA4 00000000 */   nop
    /* 1CFDA8 002CFDA8 2D280000 */  daddu      $5, $0, $0
    /* 1CFDAC 002CFDAC 04000424 */  addiu      $4, $0, 0x4
    /* 1CFDB0 002CFDB0 1A000010 */  b          .L002CFE1C
    /* 1CFDB4 002CFDB4 00000000 */   nop
  .L002CFDB8:
    /* 1CFDB8 002CFDB8 2D300000 */  daddu      $6, $0, $0
    /* 1CFDBC 002CFDBC 80100300 */  sll        $2, $3, 2
    /* 1CFDC0 002CFDC0 21104300 */  addu       $2, $2, $3
    /* 1CFDC4 002CFDC4 40110200 */  sll        $2, $2, 5
    /* 1CFDC8 002CFDC8 21180202 */  addu       $3, $16, $2
    /* 1CFDCC 002CFDCC 0B000010 */  b          .L002CFDFC
    /* 1CFDD0 002CFDD0 00000000 */   nop
  .L002CFDD4:
    /* 1CFDD4 002CFDD4 3C140600 */  dsll32     $2, $6, 16
    /* 1CFDD8 002CFDD8 3F140200 */  dsra32     $2, $2, 16
    /* 1CFDDC 002CFDDC 40110200 */  sll        $2, $2, 5
    /* 1CFDE0 002CFDE0 21106200 */  addu       $2, $3, $2
    /* 1CFDE4 002CFDE4 A20F40A4 */  sh         $0, 0xFA2($2)
    /* 1CFDE8 002CFDE8 A00F44A4 */  sh         $4, 0xFA0($2)
    /* 1CFDEC 002CFDEC A40F46A4 */  sh         $6, 0xFA4($2)
    /* 1CFDF0 002CFDF0 0100C224 */  addiu      $2, $6, 0x1
    /* 1CFDF4 002CFDF4 3C340200 */  dsll32     $6, $2, 16
    /* 1CFDF8 002CFDF8 3F340600 */  dsra32     $6, $6, 16
  .L002CFDFC:
    /* 1CFDFC 002CFDFC 3C140600 */  dsll32     $2, $6, 16
    /* 1CFE00 002CFE00 3F140200 */  dsra32     $2, $2, 16
    /* 1CFE04 002CFE04 05004228 */  slti       $2, $2, 0x5
    /* 1CFE08 002CFE08 F2FF4014 */  bnez       $2, .L002CFDD4
    /* 1CFE0C 002CFE0C 00000000 */   nop
    /* 1CFE10 002CFE10 0100A224 */  addiu      $2, $5, 0x1
    /* 1CFE14 002CFE14 3C2C0200 */  dsll32     $5, $2, 16
    /* 1CFE18 002CFE18 3F2C0500 */  dsra32     $5, $5, 16
  .L002CFE1C:
    /* 1CFE1C 002CFE1C 3C1C0500 */  dsll32     $3, $5, 16
    /* 1CFE20 002CFE20 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CFE24 002CFE24 03006228 */  slti       $2, $3, 0x3
    /* 1CFE28 002CFE28 E3FF4014 */  bnez       $2, .L002CFDB8
    /* 1CFE2C 002CFE2C 00000000 */   nop
    /* 1CFE30 002CFE30 02000386 */  lh         $3, 0x2($16)
    /* 1CFE34 002CFE34 11000282 */  lb         $2, 0x11($16)
    /* 1CFE38 002CFE38 21105000 */  addu       $2, $2, $16
    /* 1CFE3C 002CFE3C 681143A0 */  sb         $3, 0x1168($2)
    /* 1CFE40 002CFE40 04000386 */  lh         $3, 0x4($16)
    /* 1CFE44 002CFE44 11000282 */  lb         $2, 0x11($16)
    /* 1CFE48 002CFE48 21105000 */  addu       $2, $2, $16
    /* 1CFE4C 002CFE4C 6B1143A0 */  sb         $3, 0x116B($2)
    /* 1CFE50 002CFE50 11000282 */  lb         $2, 0x11($16)
    /* 1CFE54 002CFE54 6E1102A2 */  sb         $2, 0x116E($16)
    /* 1CFE58 002CFE58 11000282 */  lb         $2, 0x11($16)
    /* 1CFE5C 002CFE5C 80100200 */  sll        $2, $2, 2
    /* 1CFE60 002CFE60 21105000 */  addu       $2, $2, $16
    /* 1CFE64 002CFE64 180F448C */  lw         $4, 0xF18($2)
    /* 1CFE68 002CFE68 BC890B0C */  jal        func_002e26f0
    /* 1CFE6C 002CFE6C 00000000 */   nop
    /* 1CFE70 002CFE70 05004228 */  slti       $2, $2, 0x5
    /* 1CFE74 002CFE74 0B004014 */  bnez       $2, .L002CFEA4
    /* 1CFE78 002CFE78 00000000 */   nop
    /* 1CFE7C 002CFE7C 11000382 */  lb         $3, 0x11($16)
    /* 1CFE80 002CFE80 80100300 */  sll        $2, $3, 2
    /* 1CFE84 002CFE84 21104300 */  addu       $2, $2, $3
    /* 1CFE88 002CFE88 40110200 */  sll        $2, $2, 5
    /* 1CFE8C 002CFE8C 21105000 */  addu       $2, $2, $16
    /* 1CFE90 002CFE90 20104284 */  lh         $2, 0x1020($2)
    /* 1CFE94 002CFE94 04004224 */  addiu      $2, $2, 0x4
    /* 1CFE98 002CFE98 701102A6 */  sh         $2, 0x1170($16)
    /* 1CFE9C 002CFE9C 15000010 */  b          .L002CFEF4
    /* 1CFEA0 002CFEA0 00000000 */   nop
  .L002CFEA4:
    /* 1CFEA4 002CFEA4 11000282 */  lb         $2, 0x11($16)
    /* 1CFEA8 002CFEA8 80100200 */  sll        $2, $2, 2
    /* 1CFEAC 002CFEAC 21105000 */  addu       $2, $2, $16
    /* 1CFEB0 002CFEB0 180F448C */  lw         $4, 0xF18($2)
    /* 1CFEB4 002CFEB4 BC890B0C */  jal        func_002e26f0
    /* 1CFEB8 002CFEB8 00000000 */   nop
    /* 1CFEBC 002CFEBC 40210200 */  sll        $4, $2, 5
    /* 1CFEC0 002CFEC0 11000282 */  lb         $2, 0x11($16)
    /* 1CFEC4 002CFEC4 80180200 */  sll        $3, $2, 2
    /* 1CFEC8 002CFEC8 21106200 */  addu       $2, $3, $2
    /* 1CFECC 002CFECC 40110200 */  sll        $2, $2, 5
    /* 1CFED0 002CFED0 21105000 */  addu       $2, $2, $16
    /* 1CFED4 002CFED4 21108200 */  addu       $2, $4, $2
    /* 1CFED8 002CFED8 A00F5184 */  lh         $17, 0xFA0($2)
    /* 1CFEDC 002CFEDC 21107000 */  addu       $2, $3, $16
    /* 1CFEE0 002CFEE0 180F448C */  lw         $4, 0xF18($2)
    /* 1CFEE4 002CFEE4 BC890B0C */  jal        func_002e26f0
    /* 1CFEE8 002CFEE8 00000000 */   nop
    /* 1CFEEC 002CFEEC 21102202 */  addu       $2, $17, $2
    /* 1CFEF0 002CFEF0 701102A6 */  sh         $2, 0x1170($16)
  .L002CFEF4:
    /* 1CFEF4 002CFEF4 11000482 */  lb         $4, 0x11($16)
    /* 1CFEF8 002CFEF8 01000524 */  addiu      $5, $0, 0x1
    /* 1CFEFC 002CFEFC 2D300000 */  daddu      $6, $0, $0
    /* 1CFF00 002CFF00 02000724 */  addiu      $7, $0, 0x2
    /* 1CFF04 002CFF04 2D40E000 */  daddu      $8, $7, $0
    /* 1CFF08 002CFF08 40CB0A0C */  jal        func_002b2d00
    /* 1CFF0C 002CFF0C 00000000 */   nop
    /* 1CFF10 002CFF10 110002A2 */  sb         $2, 0x11($16)
    /* 1CFF14 002CFF14 3C2E0200 */  dsll32     $5, $2, 24
    /* 1CFF18 002CFF18 3F2E0500 */  dsra32     $5, $5, 24
    /* 1CFF1C 002CFF1C 2D208002 */  daddu      $4, $20, $0
    /* 1CFF20 002CFF20 D8510B0C */  jal        func_002d4760
    /* 1CFF24 002CFF24 00000000 */   nop
    /* 1CFF28 002CFF28 11000582 */  lb         $5, 0x11($16)
    /* 1CFF2C 002CFF2C 2D208002 */  daddu      $4, $20, $0
    /* 1CFF30 002CFF30 045F0B0C */  jal        func_002d7c10
    /* 1CFF34 002CFF34 00000000 */   nop
    /* 1CFF38 002CFF38 020000A6 */  sh         $0, 0x2($16)
    /* 1CFF3C 002CFF3C 040000A6 */  sh         $0, 0x4($16)
    /* 1CFF40 002CFF40 11000282 */  lb         $2, 0x11($16)
    /* 1CFF44 002CFF44 21105000 */  addu       $2, $2, $16
    /* 1CFF48 002CFF48 681140A0 */  sb         $0, 0x1168($2)
    /* 1CFF4C 002CFF4C 11000282 */  lb         $2, 0x11($16)
    /* 1CFF50 002CFF50 21105000 */  addu       $2, $2, $16
    /* 1CFF54 002CFF54 6B1140A0 */  sb         $0, 0x116B($2)
    /* 1CFF58 002CFF58 11000282 */  lb         $2, 0x11($16)
    /* 1CFF5C 002CFF5C 80100200 */  sll        $2, $2, 2
    /* 1CFF60 002CFF60 21105000 */  addu       $2, $2, $16
    /* 1CFF64 002CFF64 180F448C */  lw         $4, 0xF18($2)
    /* 1CFF68 002CFF68 BC890B0C */  jal        func_002e26f0
    /* 1CFF6C 002CFF6C 00000000 */   nop
    /* 1CFF70 002CFF70 05004228 */  slti       $2, $2, 0x5
    /* 1CFF74 002CFF74 0B004014 */  bnez       $2, .L002CFFA4
    /* 1CFF78 002CFF78 00000000 */   nop
    /* 1CFF7C 002CFF7C 11000382 */  lb         $3, 0x11($16)
    /* 1CFF80 002CFF80 80100300 */  sll        $2, $3, 2
    /* 1CFF84 002CFF84 21104300 */  addu       $2, $2, $3
    /* 1CFF88 002CFF88 40110200 */  sll        $2, $2, 5
    /* 1CFF8C 002CFF8C 21105000 */  addu       $2, $2, $16
    /* 1CFF90 002CFF90 20104284 */  lh         $2, 0x1020($2)
    /* 1CFF94 002CFF94 04004224 */  addiu      $2, $2, 0x4
    /* 1CFF98 002CFF98 701102A6 */  sh         $2, 0x1170($16)
    /* 1CFF9C 002CFF9C 30000010 */  b          .L002D0060
    /* 1CFFA0 002CFFA0 00000000 */   nop
  .L002CFFA4:
    /* 1CFFA4 002CFFA4 11001382 */  lb         $19, 0x11($16)
    /* 1CFFA8 002CFFA8 70111286 */  lh         $18, 0x1170($16)
    /* 1CFFAC 002CFFAC 80101300 */  sll        $2, $19, 2
    /* 1CFFB0 002CFFB0 21105000 */  addu       $2, $2, $16
    /* 1CFFB4 002CFFB4 180F448C */  lw         $4, 0xF18($2)
    /* 1CFFB8 002CFFB8 BC890B0C */  jal        func_002e26f0
    /* 1CFFBC 002CFFBC 00000000 */   nop
    /* 1CFFC0 002CFFC0 40190200 */  sll        $3, $2, 5
    /* 1CFFC4 002CFFC4 80101300 */  sll        $2, $19, 2
    /* 1CFFC8 002CFFC8 21105300 */  addu       $2, $2, $19
    /* 1CFFCC 002CFFCC 40110200 */  sll        $2, $2, 5
    /* 1CFFD0 002CFFD0 21105000 */  addu       $2, $2, $16
    /* 1CFFD4 002CFFD4 21106200 */  addu       $2, $3, $2
    /* 1CFFD8 002CFFD8 A00F5184 */  lh         $17, 0xFA0($2)
    /* 1CFFDC 002CFFDC 11000282 */  lb         $2, 0x11($16)
    /* 1CFFE0 002CFFE0 80100200 */  sll        $2, $2, 2
    /* 1CFFE4 002CFFE4 21105000 */  addu       $2, $2, $16
    /* 1CFFE8 002CFFE8 180F448C */  lw         $4, 0xF18($2)
    /* 1CFFEC 002CFFEC BC890B0C */  jal        func_002e26f0
    /* 1CFFF0 002CFFF0 00000000 */   nop
    /* 1CFFF4 002CFFF4 21102202 */  addu       $2, $17, $2
    /* 1CFFF8 002CFFF8 3C140200 */  dsll32     $2, $2, 16
    /* 1CFFFC 002CFFFC 3F140200 */  dsra32     $2, $2, 16
    /* 1D0000 002D0000 2A084202 */  slt        $1, $18, $2
    /* 1D0004 002D0004 16002010 */  beqz       $1, .L002D0060
    /* 1D0008 002D0008 00000000 */   nop
    /* 1D000C 002D000C 11000282 */  lb         $2, 0x11($16)
    /* 1D0010 002D0010 80100200 */  sll        $2, $2, 2
    /* 1D0014 002D0014 21105000 */  addu       $2, $2, $16
    /* 1D0018 002D0018 180F448C */  lw         $4, 0xF18($2)
    /* 1D001C 002D001C BC890B0C */  jal        func_002e26f0
    /* 1D0020 002D0020 00000000 */   nop
    /* 1D0024 002D0024 40210200 */  sll        $4, $2, 5
    /* 1D0028 002D0028 11000382 */  lb         $3, 0x11($16)
    /* 1D002C 002D002C 80100300 */  sll        $2, $3, 2
    /* 1D0030 002D0030 21104300 */  addu       $2, $2, $3
    /* 1D0034 002D0034 40110200 */  sll        $2, $2, 5
    /* 1D0038 002D0038 21105000 */  addu       $2, $2, $16
    /* 1D003C 002D003C 21108200 */  addu       $2, $4, $2
    /* 1D0040 002D0040 A00F5184 */  lh         $17, 0xFA0($2)
    /* 1D0044 002D0044 80101300 */  sll        $2, $19, 2
    /* 1D0048 002D0048 21105000 */  addu       $2, $2, $16
    /* 1D004C 002D004C 180F448C */  lw         $4, 0xF18($2)
    /* 1D0050 002D0050 BC890B0C */  jal        func_002e26f0
    /* 1D0054 002D0054 00000000 */   nop
    /* 1D0058 002D0058 21102202 */  addu       $2, $17, $2
    /* 1D005C 002D005C 701102A6 */  sh         $2, 0x1170($16)
  .L002D0060:
    /* 1D0060 002D0060 11000382 */  lb         $3, 0x11($16)
    /* 1D0064 002D0064 02000224 */  addiu      $2, $0, 0x2
    /* 1D0068 002D0068 1D006210 */  beq        $3, $2, .L002D00E0
    /* 1D006C 002D006C 00000000 */   nop
    /* 1D0070 002D0070 01000724 */  addiu      $7, $0, 0x1
    /* 1D0074 002D0074 10006710 */  beq        $3, $7, .L002D00B8
    /* 1D0078 002D0078 00000000 */   nop
    /* 1D007C 002D007C 03006010 */  beqz       $3, .L002D008C
    /* 1D0080 002D0080 00000000 */   nop
    /* 1D0084 002D0084 1F000010 */  b          .L002D0104
    /* 1D0088 002D0088 00000000 */   nop
  .L002D008C:
    /* 1D008C 002D008C 80100300 */  sll        $2, $3, 2
    /* 1D0090 002D0090 21105000 */  addu       $2, $2, $16
    /* 1D0094 002D0094 180F448C */  lw         $4, 0xF18($2)
    /* 1D0098 002D0098 0400053C */  lui        $5, (0x40000 >> 16)
    /* 1D009C 002D009C 2D300000 */  daddu      $6, $0, $0
    /* 1D00A0 002D00A0 04000724 */  addiu      $7, $0, 0x4
    /* 1D00A4 002D00A4 2D400000 */  daddu      $8, $0, $0
    /* 1D00A8 002D00A8 588D0B0C */  jal        func_002e3560
    /* 1D00AC 002D00AC 00000000 */   nop
    /* 1D00B0 002D00B0 14000010 */  b          .L002D0104
    /* 1D00B4 002D00B4 00000000 */   nop
  .L002D00B8:
    /* 1D00B8 002D00B8 80100300 */  sll        $2, $3, 2
    /* 1D00BC 002D00BC 21105000 */  addu       $2, $2, $16
    /* 1D00C0 002D00C0 180F448C */  lw         $4, 0xF18($2)
    /* 1D00C4 002D00C4 FFFF0534 */  ori        $5, $0, 0xFFFF
    /* 1D00C8 002D00C8 E01F0624 */  addiu      $6, $0, 0x1FE0
    /* 1D00CC 002D00CC 2D400000 */  daddu      $8, $0, $0
    /* 1D00D0 002D00D0 588D0B0C */  jal        func_002e3560
    /* 1D00D4 002D00D4 00000000 */   nop
    /* 1D00D8 002D00D8 0A000010 */  b          .L002D0104
    /* 1D00DC 002D00DC 00000000 */   nop
  .L002D00E0:
    /* 1D00E0 002D00E0 80100300 */  sll        $2, $3, 2
    /* 1D00E4 002D00E4 21105000 */  addu       $2, $2, $16
    /* 1D00E8 002D00E8 180F448C */  lw         $4, 0xF18($2)
    /* 1D00EC 002D00EC 0100053C */  lui        $5, (0x10000 >> 16)
    /* 1D00F0 002D00F0 2D300000 */  daddu      $6, $0, $0
    /* 1D00F4 002D00F4 01000724 */  addiu      $7, $0, 0x1
    /* 1D00F8 002D00F8 2D400000 */  daddu      $8, $0, $0
    /* 1D00FC 002D00FC 588D0B0C */  jal        func_002e3560
    /* 1D0100 002D0100 00000000 */   nop
  .L002D0104:
    /* 1D0104 002D0104 34000224 */  addiu      $2, $0, 0x34
    /* 1D0108 002D0108 000002A2 */  sb         $2, 0x0($16)
    /* 1D010C 002D010C 2D200000 */  daddu      $4, $0, $0
    /* 1D0110 002D0110 2D280000 */  daddu      $5, $0, $0
    /* 1D0114 002D0114 2D300000 */  daddu      $6, $0, $0
    /* 1D0118 002D0118 05000724 */  addiu      $7, $0, 0x5
    /* 1D011C 002D011C D86B110C */  jal        func_0045af60
    /* 1D0120 002D0120 00000000 */   nop
    /* 1D0124 002D0124 0A050010 */  b          .L002D1550
    /* 1D0128 002D0128 00000000 */   nop
  .L002D012C:
    /* 1D012C 002D012C 8C00033C */  lui        $3, %hi(D_008C024E)
    /* 1D0130 002D0130 4E026494 */  lhu        $4, %lo(D_008C024E)($3)
    /* 1D0134 002D0134 40008330 */  andi       $3, $4, 0x40
    /* 1D0138 002D0138 62006010 */  beqz       $3, .L002D02C4
    /* 1D013C 002D013C 00000000 */   nop
    /* 1D0140 002D0140 11000282 */  lb         $2, 0x11($16)
    /* 1D0144 002D0144 80100200 */  sll        $2, $2, 2
    /* 1D0148 002D0148 21105000 */  addu       $2, $2, $16
    /* 1D014C 002D014C 180F448C */  lw         $4, 0xF18($2)
    /* 1D0150 002D0150 BC890B0C */  jal        func_002e26f0
    /* 1D0154 002D0154 00000000 */   nop
    /* 1D0158 002D0158 11000482 */  lb         $4, 0x11($16)
    /* 1D015C 002D015C 7500033C */  lui        $3, %hi(D_00748908)
    /* 1D0160 002D0160 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1D0164 002D0164 21186400 */  addu       $3, $3, $4
    /* 1D0168 002D0168 00006380 */  lb         $3, 0x0($3)
    /* 1D016C 002D016C 2A086200 */  slt        $1, $3, $2
    /* 1D0170 002D0170 09002014 */  bnez       $1, .L002D0198
    /* 1D0174 002D0174 00000000 */   nop
    /* 1D0178 002D0178 2D200000 */  daddu      $4, $0, $0
    /* 1D017C 002D017C 2D280000 */  daddu      $5, $0, $0
    /* 1D0180 002D0180 2D300000 */  daddu      $6, $0, $0
    /* 1D0184 002D0184 08000724 */  addiu      $7, $0, 0x8
    /* 1D0188 002D0188 D86B110C */  jal        func_0045af60
    /* 1D018C 002D018C 00000000 */   nop
    /* 1D0190 002D0190 F0040010 */  b          .L002D1554
    /* 1D0194 002D0194 00000000 */   nop
  .L002D0198:
    /* 1D0198 002D0198 01000224 */  addiu      $2, $0, 0x1
    /* 1D019C 002D019C 120002A6 */  sh         $2, 0x12($16)
    /* 1D01A0 002D01A0 11000482 */  lb         $4, 0x11($16)
    /* 1D01A4 002D01A4 16008014 */  bnez       $4, .L002D0200
    /* 1D01A8 002D01A8 00000000 */   nop
    /* 1D01AC 002D01AC 02000386 */  lh         $3, 0x2($16)
    /* 1D01B0 002D01B0 04000286 */  lh         $2, 0x4($16)
    /* 1D01B4 002D01B4 23106200 */  subu       $2, $3, $2
    /* 1D01B8 002D01B8 11004014 */  bnez       $2, .L002D0200
    /* 1D01BC 002D01BC 00000000 */   nop
    /* 1D01C0 002D01C0 80100400 */  sll        $2, $4, 2
    /* 1D01C4 002D01C4 21105000 */  addu       $2, $2, $16
    /* 1D01C8 002D01C8 180F448C */  lw         $4, 0xF18($2)
    /* 1D01CC 002D01CC BC890B0C */  jal        func_002e26f0
    /* 1D01D0 002D01D0 00000000 */   nop
    /* 1D01D4 002D01D4 02004128 */  slti       $1, $2, 0x2
    /* 1D01D8 002D01D8 09002010 */  beqz       $1, .L002D0200
    /* 1D01DC 002D01DC 00000000 */   nop
    /* 1D01E0 002D01E0 2D200000 */  daddu      $4, $0, $0
    /* 1D01E4 002D01E4 2D280000 */  daddu      $5, $0, $0
    /* 1D01E8 002D01E8 2D300000 */  daddu      $6, $0, $0
    /* 1D01EC 002D01EC 08000724 */  addiu      $7, $0, 0x8
    /* 1D01F0 002D01F0 D86B110C */  jal        func_0045af60
    /* 1D01F4 002D01F4 00000000 */   nop
    /* 1D01F8 002D01F8 D6040010 */  b          .L002D1554
    /* 1D01FC 002D01FC 00000000 */   nop
  .L002D0200:
    /* 1D0200 002D0200 11000282 */  lb         $2, 0x11($16)
    /* 1D0204 002D0204 80100200 */  sll        $2, $2, 2
    /* 1D0208 002D0208 21105000 */  addu       $2, $2, $16
    /* 1D020C 002D020C 180F448C */  lw         $4, 0xF18($2)
    /* 1D0210 002D0210 BC890B0C */  jal        func_002e26f0
    /* 1D0214 002D0214 00000000 */   nop
    /* 1D0218 002D0218 CD044018 */  blez       $2, .L002D1550
    /* 1D021C 002D021C 00000000 */   nop
    /* 1D0220 002D0220 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1D0224 002D0224 38810B0C */  jal        func_002e04e0
    /* 1D0228 002D0228 00000000 */   nop
    /* 1D022C 002D022C 79004290 */  lbu        $2, 0x79($2)
    /* 1D0230 002D0230 3E0F02A2 */  sb         $2, 0xF3E($16)
    /* 1D0234 002D0234 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1D0238 002D0238 38810B0C */  jal        func_002e04e0
    /* 1D023C 002D023C 00000000 */   nop
    /* 1D0240 002D0240 7A004290 */  lbu        $2, 0x7A($2)
    /* 1D0244 002D0244 3F0F02A2 */  sb         $2, 0xF3F($16)
    /* 1D0248 002D0248 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1D024C 002D024C 38810B0C */  jal        func_002e04e0
    /* 1D0250 002D0250 00000000 */   nop
    /* 1D0254 002D0254 7B004290 */  lbu        $2, 0x7B($2)
    /* 1D0258 002D0258 400F02A2 */  sb         $2, 0xF40($16)
    /* 1D025C 002D025C D00D048E */  lw         $4, 0xDD0($16)
    /* 1D0260 002D0260 38810B0C */  jal        func_002e04e0
    /* 1D0264 002D0264 00000000 */   nop
    /* 1D0268 002D0268 79004290 */  lbu        $2, 0x79($2)
    /* 1D026C 002D026C 420F02A2 */  sb         $2, 0xF42($16)
    /* 1D0270 002D0270 D00D048E */  lw         $4, 0xDD0($16)
    /* 1D0274 002D0274 38810B0C */  jal        func_002e04e0
    /* 1D0278 002D0278 00000000 */   nop
    /* 1D027C 002D027C 7A004290 */  lbu        $2, 0x7A($2)
    /* 1D0280 002D0280 430F02A2 */  sb         $2, 0xF43($16)
    /* 1D0284 002D0284 D00D048E */  lw         $4, 0xDD0($16)
    /* 1D0288 002D0288 38810B0C */  jal        func_002e04e0
    /* 1D028C 002D028C 00000000 */   nop
    /* 1D0290 002D0290 7B004290 */  lbu        $2, 0x7B($2)
    /* 1D0294 002D0294 440F02A2 */  sb         $2, 0xF44($16)
    /* 1D0298 002D0298 3C0F00A6 */  sh         $0, 0xF3C($16)
    /* 1D029C 002D029C 25000224 */  addiu      $2, $0, 0x25
    /* 1D02A0 002D02A0 000002A2 */  sb         $2, 0x0($16)
    /* 1D02A4 002D02A4 2D200000 */  daddu      $4, $0, $0
    /* 1D02A8 002D02A8 2D280000 */  daddu      $5, $0, $0
    /* 1D02AC 002D02AC 2D300000 */  daddu      $6, $0, $0
    /* 1D02B0 002D02B0 01000724 */  addiu      $7, $0, 0x1
    /* 1D02B4 002D02B4 D86B110C */  jal        func_0045af60
    /* 1D02B8 002D02B8 00000000 */   nop
    /* 1D02BC 002D02BC A4040010 */  b          .L002D1550
    /* 1D02C0 002D02C0 00000000 */   nop
  .L002D02C4:
    /* 1D02C4 002D02C4 80008330 */  andi       $3, $4, 0x80
    /* 1D02C8 002D02C8 CB006010 */  beqz       $3, .L002D05F8
    /* 1D02CC 002D02CC 00000000 */   nop
    /* 1D02D0 002D02D0 11000282 */  lb         $2, 0x11($16)
    /* 1D02D4 002D02D4 80100200 */  sll        $2, $2, 2
    /* 1D02D8 002D02D8 21105000 */  addu       $2, $2, $16
    /* 1D02DC 002D02DC 180F448C */  lw         $4, 0xF18($2)
    /* 1D02E0 002D02E0 BC890B0C */  jal        func_002e26f0
    /* 1D02E4 002D02E4 00000000 */   nop
    /* 1D02E8 002D02E8 11000482 */  lb         $4, 0x11($16)
    /* 1D02EC 002D02EC 7500033C */  lui        $3, %hi(D_00748908)
    /* 1D02F0 002D02F0 08896324 */  addiu      $3, $3, %lo(D_00748908)
    /* 1D02F4 002D02F4 21186400 */  addu       $3, $3, $4
    /* 1D02F8 002D02F8 00006380 */  lb         $3, 0x0($3)
    /* 1D02FC 002D02FC 2A086200 */  slt        $1, $3, $2
    /* 1D0300 002D0300 94042010 */  beqz       $1, .L002D1554
    /* 1D0304 002D0304 00000000 */   nop
    /* 1D0308 002D0308 01000524 */  addiu      $5, $0, 0x1
    /* 1D030C 002D030C 91042512 */  beq        $17, $5, .L002D1554
    /* 1D0310 002D0310 00000000 */   nop
    /* 1D0314 002D0314 380E048E */  lw         $4, 0xE38($16)
    /* 1D0318 002D0318 5C810B0C */  jal        func_002e0570
    /* 1D031C 002D031C 00000000 */   nop
    /* 1D0320 002D0320 3C1E0200 */  dsll32     $3, $2, 24
    /* 1D0324 002D0324 3F1E0300 */  dsra32     $3, $3, 24
    /* 1D0328 002D0328 01000524 */  addiu      $5, $0, 0x1
    /* 1D032C 002D032C 11006510 */  beq        $3, $5, .L002D0374
    /* 1D0330 002D0330 00000000 */   nop
    /* 1D0334 002D0334 C40C048E */  lw         $4, 0xCC4($16)
    /* 1D0338 002D0338 5C810B0C */  jal        func_002e0570
    /* 1D033C 002D033C 00000000 */   nop
    /* 1D0340 002D0340 3C1E0200 */  dsll32     $3, $2, 24
    /* 1D0344 002D0344 3F1E0300 */  dsra32     $3, $3, 24
    /* 1D0348 002D0348 01000524 */  addiu      $5, $0, 0x1
    /* 1D034C 002D034C 09006510 */  beq        $3, $5, .L002D0374
    /* 1D0350 002D0350 00000000 */   nop
    /* 1D0354 002D0354 C00C048E */  lw         $4, 0xCC0($16)
    /* 1D0358 002D0358 5C810B0C */  jal        func_002e0570
    /* 1D035C 002D035C 00000000 */   nop
    /* 1D0360 002D0360 3C260200 */  dsll32     $4, $2, 24
    /* 1D0364 002D0364 3F260400 */  dsra32     $4, $4, 24
    /* 1D0368 002D0368 01000324 */  addiu      $3, $0, 0x1
    /* 1D036C 002D036C 03008314 */  bne        $4, $3, .L002D037C
    /* 1D0370 002D0370 00000000 */   nop
  .L002D0374:
    /* 1D0374 002D0374 77040010 */  b          .L002D1554
    /* 1D0378 002D0378 00000000 */   nop
  .L002D037C:
    /* 1D037C 002D037C 11000482 */  lb         $4, 0x11($16)
    /* 1D0380 002D0380 04008014 */  bnez       $4, .L002D0394
    /* 1D0384 002D0384 00000000 */   nop
    /* 1D0388 002D0388 02000386 */  lh         $3, 0x2($16)
    /* 1D038C 002D038C 70046010 */  beqz       $3, .L002D1550
    /* 1D0390 002D0390 00000000 */   nop
  .L002D0394:
    /* 1D0394 002D0394 80100400 */  sll        $2, $4, 2
    /* 1D0398 002D0398 21105000 */  addu       $2, $2, $16
    /* 1D039C 002D039C 180F448C */  lw         $4, 0xF18($2)
    /* 1D03A0 002D03A0 BC890B0C */  jal        func_002e26f0
    /* 1D03A4 002D03A4 00000000 */   nop
    /* 1D03A8 002D03A8 69044018 */  blez       $2, .L002D1550
    /* 1D03AC 002D03AC 00000000 */   nop
    /* 1D03B0 002D03B0 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1D03B4 002D03B4 38810B0C */  jal        func_002e04e0
    /* 1D03B8 002D03B8 00000000 */   nop
    /* 1D03BC 002D03BC 79004290 */  lbu        $2, 0x79($2)
    /* 1D03C0 002D03C0 3E0F02A2 */  sb         $2, 0xF3E($16)
    /* 1D03C4 002D03C4 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1D03C8 002D03C8 38810B0C */  jal        func_002e04e0
    /* 1D03CC 002D03CC 00000000 */   nop
    /* 1D03D0 002D03D0 7A004290 */  lbu        $2, 0x7A($2)
    /* 1D03D4 002D03D4 3F0F02A2 */  sb         $2, 0xF3F($16)
    /* 1D03D8 002D03D8 CC0D048E */  lw         $4, 0xDCC($16)
    /* 1D03DC 002D03DC 38810B0C */  jal        func_002e04e0
    /* 1D03E0 002D03E0 00000000 */   nop
    /* 1D03E4 002D03E4 7B004290 */  lbu        $2, 0x7B($2)
    /* 1D03E8 002D03E8 400F02A2 */  sb         $2, 0xF40($16)
    /* 1D03EC 002D03EC D00D048E */  lw         $4, 0xDD0($16)
    /* 1D03F0 002D03F0 38810B0C */  jal        func_002e04e0
    /* 1D03F4 002D03F4 00000000 */   nop
    /* 1D03F8 002D03F8 79004290 */  lbu        $2, 0x79($2)
    /* 1D03FC 002D03FC 420F02A2 */  sb         $2, 0xF42($16)
    /* 1D0400 002D0400 D00D048E */  lw         $4, 0xDD0($16)
    /* 1D0404 002D0404 38810B0C */  jal        func_002e04e0
    /* 1D0408 002D0408 00000000 */   nop
    /* 1D040C 002D040C 7A004290 */  lbu        $2, 0x7A($2)
    /* 1D0410 002D0410 430F02A2 */  sb         $2, 0xF43($16)
    /* 1D0414 002D0414 D00D048E */  lw         $4, 0xDD0($16)
    /* 1D0418 002D0418 38810B0C */  jal        func_002e04e0
    /* 1D041C 002D041C 00000000 */   nop
    /* 1D0420 002D0420 7B004290 */  lbu        $2, 0x7B($2)
    /* 1D0424 002D0424 440F02A2 */  sb         $2, 0xF44($16)
    /* 1D0428 002D0428 3C0F00A6 */  sh         $0, 0xF3C($16)
    /* 1D042C 002D042C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D0430 002D0430 00608244 */  mtc1       $2, $f12
    /* 1D0434 002D0434 C40E048E */  lw         $4, 0xEC4($16)
    /* 1D0438 002D0438 03000524 */  addiu      $5, $0, 0x3
    /* 1D043C 002D043C 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D0440 002D0440 06000624 */  addiu      $6, $0, 0x6
    /* 1D0444 002D0444 2D380000 */  daddu      $7, $0, $0
    /* 1D0448 002D0448 2D400000 */  daddu      $8, $0, $0
    /* 1D044C 002D044C C0810B0C */  jal        func_002e0700
    /* 1D0450 002D0450 00000000 */   nop
    /* 1D0454 002D0454 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D0458 002D0458 00608244 */  mtc1       $2, $f12
    /* 1D045C 002D045C C80E048E */  lw         $4, 0xEC8($16)
    /* 1D0460 002D0460 04000524 */  addiu      $5, $0, 0x4
    /* 1D0464 002D0464 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D0468 002D0468 06000624 */  addiu      $6, $0, 0x6
    /* 1D046C 002D046C 2D380000 */  daddu      $7, $0, $0
    /* 1D0470 002D0470 2D400000 */  daddu      $8, $0, $0
    /* 1D0474 002D0474 C0810B0C */  jal        func_002e0700
    /* 1D0478 002D0478 00000000 */   nop
    /* 1D047C 002D047C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D0480 002D0480 00608244 */  mtc1       $2, $f12
    /* 1D0484 002D0484 380E048E */  lw         $4, 0xE38($16)
    /* 1D0488 002D0488 80000524 */  addiu      $5, $0, 0x80
    /* 1D048C 002D048C 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D0490 002D0490 06000624 */  addiu      $6, $0, 0x6
    /* 1D0494 002D0494 2D380000 */  daddu      $7, $0, $0
    /* 1D0498 002D0498 2D400000 */  daddu      $8, $0, $0
    /* 1D049C 002D049C C0810B0C */  jal        func_002e0700
    /* 1D04A0 002D04A0 00000000 */   nop
    /* 1D04A4 002D04A4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D04A8 002D04A8 00608244 */  mtc1       $2, $f12
    /* 1D04AC 002D04AC B40E048E */  lw         $4, 0xEB4($16)
    /* 1D04B0 002D04B0 03000524 */  addiu      $5, $0, 0x3
    /* 1D04B4 002D04B4 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D04B8 002D04B8 06000624 */  addiu      $6, $0, 0x6
    /* 1D04BC 002D04BC 01000724 */  addiu      $7, $0, 0x1
    /* 1D04C0 002D04C0 2D400000 */  daddu      $8, $0, $0
    /* 1D04C4 002D04C4 C0810B0C */  jal        func_002e0700
    /* 1D04C8 002D04C8 00000000 */   nop
    /* 1D04CC 002D04CC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D04D0 002D04D0 00608244 */  mtc1       $2, $f12
    /* 1D04D4 002D04D4 B80E048E */  lw         $4, 0xEB8($16)
    /* 1D04D8 002D04D8 04000524 */  addiu      $5, $0, 0x4
    /* 1D04DC 002D04DC 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D04E0 002D04E0 06000624 */  addiu      $6, $0, 0x6
    /* 1D04E4 002D04E4 01000724 */  addiu      $7, $0, 0x1
    /* 1D04E8 002D04E8 2D400000 */  daddu      $8, $0, $0
    /* 1D04EC 002D04EC C0810B0C */  jal        func_002e0700
    /* 1D04F0 002D04F0 00000000 */   nop
    /* 1D04F4 002D04F4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D04F8 002D04F8 00608244 */  mtc1       $2, $f12
    /* 1D04FC 002D04FC C40C048E */  lw         $4, 0xCC4($16)
    /* 1D0500 002D0500 23000524 */  addiu      $5, $0, 0x23
    /* 1D0504 002D0504 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D0508 002D0508 06000624 */  addiu      $6, $0, 0x6
    /* 1D050C 002D050C 01000724 */  addiu      $7, $0, 0x1
    /* 1D0510 002D0510 2D400000 */  daddu      $8, $0, $0
    /* 1D0514 002D0514 C0810B0C */  jal        func_002e0700
    /* 1D0518 002D0518 00000000 */   nop
    /* 1D051C 002D051C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D0520 002D0520 00608244 */  mtc1       $2, $f12
    /* 1D0524 002D0524 BC0E048E */  lw         $4, 0xEBC($16)
    /* 1D0528 002D0528 03000524 */  addiu      $5, $0, 0x3
    /* 1D052C 002D052C 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D0530 002D0530 06000624 */  addiu      $6, $0, 0x6
    /* 1D0534 002D0534 02000724 */  addiu      $7, $0, 0x2
    /* 1D0538 002D0538 2D400000 */  daddu      $8, $0, $0
    /* 1D053C 002D053C C0810B0C */  jal        func_002e0700
    /* 1D0540 002D0540 00000000 */   nop
    /* 1D0544 002D0544 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D0548 002D0548 00608244 */  mtc1       $2, $f12
    /* 1D054C 002D054C C00E048E */  lw         $4, 0xEC0($16)
    /* 1D0550 002D0550 04000524 */  addiu      $5, $0, 0x4
    /* 1D0554 002D0554 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D0558 002D0558 06000624 */  addiu      $6, $0, 0x6
    /* 1D055C 002D055C 02000724 */  addiu      $7, $0, 0x2
    /* 1D0560 002D0560 2D400000 */  daddu      $8, $0, $0
    /* 1D0564 002D0564 C0810B0C */  jal        func_002e0700
    /* 1D0568 002D0568 00000000 */   nop
    /* 1D056C 002D056C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1D0570 002D0570 00608244 */  mtc1       $2, $f12
    /* 1D0574 002D0574 C00C048E */  lw         $4, 0xCC0($16)
    /* 1D0578 002D0578 22000524 */  addiu      $5, $0, 0x22
    /* 1D057C 002D057C 04858DC7 */  lwc1       $f13, -0x7AFC($28)
    /* 1D0580 002D0580 06000624 */  addiu      $6, $0, 0x6
    /* 1D0584 002D0584 01000724 */  addiu      $7, $0, 0x1
    /* 1D0588 002D0588 2D400000 */  daddu      $8, $0, $0
    /* 1D058C 002D058C C0810B0C */  jal        func_002e0700
    /* 1D0590 002D0590 00000000 */   nop
    /* 1D0594 002D0594 DC0D048E */  lw         $4, 0xDDC($16)
    /* 1D0598 002D0598 2D280000 */  daddu      $5, $0, $0
    /* 1D059C 002D059C 01000624 */  addiu      $6, $0, 0x1
    /* 1D05A0 002D05A0 3C810B0C */  jal        func_002e04f0
    /* 1D05A4 002D05A4 00000000 */   nop
    /* 1D05A8 002D05A8 E40D048E */  lw         $4, 0xDE4($16)
    /* 1D05AC 002D05AC 2D280000 */  daddu      $5, $0, $0
    /* 1D05B0 002D05B0 01000624 */  addiu      $6, $0, 0x1
    /* 1D05B4 002D05B4 3C810B0C */  jal        func_002e04f0
    /* 1D05B8 002D05B8 00000000 */   nop
    /* 1D05BC 002D05BC E00D048E */  lw         $4, 0xDE0($16)
    /* 1D05C0 002D05C0 2D280000 */  daddu      $5, $0, $0
    /* 1D05C4 002D05C4 2D300000 */  daddu      $6, $0, $0
    /* 1D05C8 002D05C8 3C810B0C */  jal        func_002e04f0
    /* 1D05CC 002D05CC 00000000 */   nop
    /* 1D05D0 002D05D0 2F000224 */  addiu      $2, $0, 0x2F
    /* 1D05D4 002D05D4 000002A2 */  sb         $2, 0x0($16)
    /* 1D05D8 002D05D8 2D200000 */  daddu      $4, $0, $0
    /* 1D05DC 002D05DC 01000524 */  addiu      $5, $0, 0x1
    /* 1D05E0 002D05E0 2D300000 */  daddu      $6, $0, $0
    /* 1D05E4 002D05E4 03000724 */  addiu      $7, $0, 0x3
    /* 1D05E8 002D05E8 D86B110C */  jal        func_0045af60
    /* 1D05EC 002D05EC 00000000 */   nop
    /* 1D05F0 002D05F0 D7030010 */  b          .L002D1550
    /* 1D05F4 002D05F4 00000000 */   nop
  .L002D05F8:
    /* 1D05F8 002D05F8 20008330 */  andi       $3, $4, 0x20
    /* 1D05FC 002D05FC D4036010 */  beqz       $3, .L002D1550
    /* 1D0600 002D0600 00000000 */   nop
    /* 1D0604 002D0604 01000324 */  addiu      $3, $0, 0x1
    /* 1D0608 002D0608 D2032312 */  beq        $17, $3, .L002D1554
    /* 1D060C 002D060C 00000000 */   nop
    /* 1D0610 002D0610 2D200000 */  daddu      $4, $0, $0
    /* 1D0614 002D0614 2D280000 */  daddu      $5, $0, $0
    /* 1D0618 002D0618 2D300000 */  daddu      $6, $0, $0
    /* 1D061C 002D061C 02000724 */  addiu      $7, $0, 0x2
    /* 1D0620 002D0620 D86B110C */  jal        func_0045af60
    /* 1D0624 002D0624 00000000 */   nop
    /* 1D0628 002D0628 6400113C */  lui        $17, %hi(D_0063F5B8)
    /* 1D062C 002D062C B8F53126 */  addiu      $17, $17, %lo(D_0063F5B8)
    /* 1D0630 002D0630 8001A427 */  addiu      $4, $29, 0x180
    /* 1D0634 002D0634 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1D0638 002D0638 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1D063C 002D063C 5CCA0A0C */  jal        func_002b2970
    /* 1D0640 002D0640 00000000 */   nop
    /* 1D0644 002D0644 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1D0648 002D0648 9643023C */  lui        $2, (0x43960000 >> 16)
    /* 1D064C 002D064C 00008244 */  mtc1       $2, $f0
    /* 1D0650 002D0650 00000000 */  nop
    /* 1D0654 002D0654 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0658 002D0658 7801A427 */  addiu      $4, $29, 0x178
    /* 1D065C 002D065C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1D0660 002D0660 5CCA0A0C */  jal        func_002b2970
    /* 1D0664 002D0664 00000000 */   nop
    /* 1D0668 002D0668 640C048E */  lw         $4, 0xC64($16)
    /* 1D066C 002D066C 8001A5DF */  ld         $5, 0x180($29)
    /* 1D0670 002D0670 7801A6DF */  ld         $6, 0x178($29)
    /* 1D0674 002D0674 2D380000 */  daddu      $7, $0, $0
    /* 1D0678 002D0678 0A000824 */  addiu      $8, $0, 0xA
    /* 1D067C 002D067C 2D480000 */  daddu      $9, $0, $0
    /* 1D0680 002D0680 88810B0C */  jal        func_002e0620
    /* 1D0684 002D0684 00000000 */   nop
    /* 1D0688 002D0688 640C048E */  lw         $4, 0xC64($16)
    /* 1D068C 002D068C 38810B0C */  jal        func_002e04e0
    /* 1D0690 002D0690 00000000 */   nop
    /* 1D0694 002D0694 640C048E */  lw         $4, 0xC64($16)
    /* 1D0698 002D0698 62004590 */  lbu        $5, 0x62($2)
    /* 1D069C 002D069C 2D300000 */  daddu      $6, $0, $0
    /* 1D06A0 002D06A0 2D380000 */  daddu      $7, $0, $0
    /* 1D06A4 002D06A4 0A000824 */  addiu      $8, $0, 0xA
    /* 1D06A8 002D06A8 2D480000 */  daddu      $9, $0, $0
    /* 1D06AC 002D06AC 98810B0C */  jal        func_002e0660
    /* 1D06B0 002D06B0 00000000 */   nop
    /* 1D06B4 002D06B4 3041023C */  lui        $2, (0x41300000 >> 16)
    /* 1D06B8 002D06B8 00608244 */  mtc1       $2, $f12
    /* 1D06BC 002D06BC 740D048E */  lw         $4, 0xD74($16)
    /* 1D06C0 002D06C0 56000524 */  addiu      $5, $0, 0x56
    /* 1D06C4 002D06C4 78820B0C */  jal        func_002e09e0
    /* 1D06C8 002D06C8 00000000 */   nop
    /* 1D06CC 002D06CC 740D048E */  lw         $4, 0xD74($16)
    /* 1D06D0 002D06D0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1D06D4 002D06D4 2D300000 */  daddu      $6, $0, $0
    /* 1D06D8 002D06D8 2D380000 */  daddu      $7, $0, $0
    /* 1D06DC 002D06DC 0A000824 */  addiu      $8, $0, 0xA
    /* 1D06E0 002D06E0 2D480000 */  daddu      $9, $0, $0
    /* 1D06E4 002D06E4 98810B0C */  jal        func_002e0660
    /* 1D06E8 002D06E8 00000000 */   nop
    /* 1D06EC 002D06EC 1041023C */  lui        $2, (0x41100000 >> 16)
    /* 1D06F0 002D06F0 00608244 */  mtc1       $2, $f12
    /* 1D06F4 002D06F4 800D048E */  lw         $4, 0xD80($16)
    /* 1D06F8 002D06F8 56000524 */  addiu      $5, $0, 0x56
    /* 1D06FC 002D06FC 78820B0C */  jal        func_002e09e0
    /* 1D0700 002D0700 00000000 */   nop
    /* 1D0704 002D0704 800D048E */  lw         $4, 0xD80($16)
    /* 1D0708 002D0708 FF000524 */  addiu      $5, $0, 0xFF
    /* 1D070C 002D070C 2D300000 */  daddu      $6, $0, $0
    /* 1D0710 002D0710 2D380000 */  daddu      $7, $0, $0
    /* 1D0714 002D0714 0A000824 */  addiu      $8, $0, 0xA
    /* 1D0718 002D0718 2D480000 */  daddu      $9, $0, $0
    /* 1D071C 002D071C 98810B0C */  jal        func_002e0660
    /* 1D0720 002D0720 00000000 */   nop
    /* 1D0724 002D0724 43001324 */  addiu      $19, $0, 0x43
    /* 1D0728 002D0728 2D900000 */  daddu      $18, $0, $0
    /* 1D072C 002D072C 30000010 */  b          .L002D07F0
    /* 1D0730 002D0730 00000000 */   nop
  .L002D0734:
    /* 1D0734 002D0734 3C141300 */  dsll32     $2, $19, 16
    /* 1D0738 002D0738 3F140200 */  dsra32     $2, $2, 16
    /* 1D073C 002D073C 80100200 */  sll        $2, $2, 2
    /* 1D0740 002D0740 21100202 */  addu       $2, $16, $2
    /* 1D0744 002D0744 380C5124 */  addiu      $17, $2, 0xC38
    /* 1D0748 002D0748 380C448C */  lw         $4, 0xC38($2)
    /* 1D074C 002D074C 38810B0C */  jal        func_002e04e0
    /* 1D0750 002D0750 00000000 */   nop
    /* 1D0754 002D0754 2DA84000 */  daddu      $21, $2, $0
    /* 1D0758 002D0758 0000248E */  lw         $4, 0x0($17)
    /* 1D075C 002D075C 38810B0C */  jal        func_002e04e0
    /* 1D0760 002D0760 00000000 */   nop
    /* 1D0764 002D0764 7001A427 */  addiu      $4, $29, 0x170
    /* 1D0768 002D0768 2C00ACC6 */  lwc1       $f12, 0x2C($21)
    /* 1D076C 002D076C 30004DC4 */  lwc1       $f13, 0x30($2)
    /* 1D0770 002D0770 5CCA0A0C */  jal        func_002b2970
    /* 1D0774 002D0774 00000000 */   nop
    /* 1D0778 002D0778 0000248E */  lw         $4, 0x0($17)
    /* 1D077C 002D077C 38810B0C */  jal        func_002e04e0
    /* 1D0780 002D0780 00000000 */   nop
    /* 1D0784 002D0784 2DA84000 */  daddu      $21, $2, $0
    /* 1D0788 002D0788 0000248E */  lw         $4, 0x0($17)
    /* 1D078C 002D078C 38810B0C */  jal        func_002e04e0
    /* 1D0790 002D0790 00000000 */   nop
    /* 1D0794 002D0794 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0798 002D0798 2A43023C */  lui        $2, (0x432A0000 >> 16)
    /* 1D079C 002D079C 00008244 */  mtc1       $2, $f0
    /* 1D07A0 002D07A0 00000000 */  nop
    /* 1D07A4 002D07A4 40030146 */  add.s      $f13, $f0, $f1
    /* 1D07A8 002D07A8 6801A427 */  addiu      $4, $29, 0x168
    /* 1D07AC 002D07AC 2C00ACC6 */  lwc1       $f12, 0x2C($21)
    /* 1D07B0 002D07B0 5CCA0A0C */  jal        func_002b2970
    /* 1D07B4 002D07B4 00000000 */   nop
    /* 1D07B8 002D07B8 0000248E */  lw         $4, 0x0($17)
    /* 1D07BC 002D07BC 7001A5DF */  ld         $5, 0x170($29)
    /* 1D07C0 002D07C0 6801A6DF */  ld         $6, 0x168($29)
    /* 1D07C4 002D07C4 01000724 */  addiu      $7, $0, 0x1
    /* 1D07C8 002D07C8 05000824 */  addiu      $8, $0, 0x5
    /* 1D07CC 002D07CC 2D480000 */  daddu      $9, $0, $0
    /* 1D07D0 002D07D0 88810B0C */  jal        func_002e0620
    /* 1D07D4 002D07D4 00000000 */   nop
    /* 1D07D8 002D07D8 01006226 */  addiu      $2, $19, 0x1
    /* 1D07DC 002D07DC 3C9C0200 */  dsll32     $19, $2, 16
    /* 1D07E0 002D07E0 3F9C1300 */  dsra32     $19, $19, 16
    /* 1D07E4 002D07E4 01004226 */  addiu      $2, $18, 0x1
    /* 1D07E8 002D07E8 3C940200 */  dsll32     $18, $2, 16
    /* 1D07EC 002D07EC 3F941200 */  dsra32     $18, $18, 16
  .L002D07F0:
    /* 1D07F0 002D07F0 3C141300 */  dsll32     $2, $19, 16
    /* 1D07F4 002D07F4 3F140200 */  dsra32     $2, $2, 16
    /* 1D07F8 002D07F8 49004228 */  slti       $2, $2, 0x49
    /* 1D07FC 002D07FC CDFF4014 */  bnez       $2, .L002D0734
    /* 1D0800 002D0800 00000000 */   nop
    /* 1D0804 002D0804 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1D0808 002D0808 FF000524 */  addiu      $5, $0, 0xFF
    /* 1D080C 002D080C 2D300000 */  daddu      $6, $0, $0
    /* 1D0810 002D0810 2D380000 */  daddu      $7, $0, $0
    /* 1D0814 002D0814 06000824 */  addiu      $8, $0, 0x6
    /* 1D0818 002D0818 2D480000 */  daddu      $9, $0, $0
    /* 1D081C 002D081C 98810B0C */  jal        func_002e0660
    /* 1D0820 002D0820 00000000 */   nop
    /* 1D0824 002D0824 900C048E */  lw         $4, 0xC90($16)
    /* 1D0828 002D0828 FF000524 */  addiu      $5, $0, 0xFF
    /* 1D082C 002D082C 2D300000 */  daddu      $6, $0, $0
    /* 1D0830 002D0830 2D380000 */  daddu      $7, $0, $0
    /* 1D0834 002D0834 06000824 */  addiu      $8, $0, 0x6
    /* 1D0838 002D0838 2D480000 */  daddu      $9, $0, $0
    /* 1D083C 002D083C 98810B0C */  jal        func_002e0660
    /* 1D0840 002D0840 00000000 */   nop
    /* 1D0844 002D0844 2D880000 */  daddu      $17, $0, $0
    /* 1D0848 002D0848 0B000010 */  b          .L002D0878
    /* 1D084C 002D084C 00000000 */   nop
  .L002D0850:
    /* 1D0850 002D0850 80100300 */  sll        $2, $3, 2
    /* 1D0854 002D0854 21100202 */  addu       $2, $16, $2
    /* 1D0858 002D0858 400E448C */  lw         $4, 0xE40($2)
    /* 1D085C 002D085C 2D280000 */  daddu      $5, $0, $0
    /* 1D0860 002D0860 01000624 */  addiu      $6, $0, 0x1
    /* 1D0864 002D0864 3C810B0C */  jal        func_002e04f0
    /* 1D0868 002D0868 00000000 */   nop
    /* 1D086C 002D086C 01002226 */  addiu      $2, $17, 0x1
    /* 1D0870 002D0870 3C8C0200 */  dsll32     $17, $2, 16
    /* 1D0874 002D0874 3F8C1100 */  dsra32     $17, $17, 16
  .L002D0878:
    /* 1D0878 002D0878 3C1C1100 */  dsll32     $3, $17, 16
    /* 1D087C 002D087C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1D0880 002D0880 03006228 */  slti       $2, $3, 0x3
    /* 1D0884 002D0884 F2FF4014 */  bnez       $2, .L002D0850
    /* 1D0888 002D0888 00000000 */   nop
    /* 1D088C 002D088C CC0D048E */  lw         $4, 0xDCC($16)
    /* 1D0890 002D0890 2D280000 */  daddu      $5, $0, $0
    /* 1D0894 002D0894 01000624 */  addiu      $6, $0, 0x1
    /* 1D0898 002D0898 3C810B0C */  jal        func_002e04f0
    /* 1D089C 002D089C 00000000 */   nop
    /* 1D08A0 002D08A0 D00D048E */  lw         $4, 0xDD0($16)
    /* 1D08A4 002D08A4 2D280000 */  daddu      $5, $0, $0
    /* 1D08A8 002D08A8 01000624 */  addiu      $6, $0, 0x1
    /* 1D08AC 002D08AC 3C810B0C */  jal        func_002e04f0
    /* 1D08B0 002D08B0 00000000 */   nop
    /* 1D08B4 002D08B4 C40E048E */  lw         $4, 0xEC4($16)
    /* 1D08B8 002D08B8 38810B0C */  jal        func_002e04e0
    /* 1D08BC 002D08BC 00000000 */   nop
    /* 1D08C0 002D08C0 2D904000 */  daddu      $18, $2, $0
    /* 1D08C4 002D08C4 C40E048E */  lw         $4, 0xEC4($16)
    /* 1D08C8 002D08C8 38810B0C */  jal        func_002e04e0
    /* 1D08CC 002D08CC 00000000 */   nop
    /* 1D08D0 002D08D0 2D884000 */  daddu      $17, $2, $0
    /* 1D08D4 002D08D4 C40E048E */  lw         $4, 0xEC4($16)
    /* 1D08D8 002D08D8 38810B0C */  jal        func_002e04e0
    /* 1D08DC 002D08DC 00000000 */   nop
    /* 1D08E0 002D08E0 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D08E4 002D08E4 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D08E8 002D08E8 00008244 */  mtc1       $2, $f0
    /* 1D08EC 002D08EC 00000000 */  nop
    /* 1D08F0 002D08F0 40030146 */  add.s      $f13, $f0, $f1
    /* 1D08F4 002D08F4 6001A427 */  addiu      $4, $29, 0x160
    /* 1D08F8 002D08F8 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D08FC 002D08FC 5CCA0A0C */  jal        func_002b2970
    /* 1D0900 002D0900 00000000 */   nop
    /* 1D0904 002D0904 C40E048E */  lw         $4, 0xEC4($16)
    /* 1D0908 002D0908 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D090C 002D090C 3300456A */  ldl        $5, 0x33($18)
    /* 1D0910 002D0910 6001A6DF */  ld         $6, 0x160($29)
    /* 1D0914 002D0914 02000724 */  addiu      $7, $0, 0x2
    /* 1D0918 002D0918 0F000824 */  addiu      $8, $0, 0xF
    /* 1D091C 002D091C 2D480000 */  daddu      $9, $0, $0
    /* 1D0920 002D0920 88810B0C */  jal        func_002e0620
    /* 1D0924 002D0924 00000000 */   nop
    /* 1D0928 002D0928 C80E048E */  lw         $4, 0xEC8($16)
    /* 1D092C 002D092C 38810B0C */  jal        func_002e04e0
    /* 1D0930 002D0930 00000000 */   nop
    /* 1D0934 002D0934 2D904000 */  daddu      $18, $2, $0
    /* 1D0938 002D0938 C80E048E */  lw         $4, 0xEC8($16)
    /* 1D093C 002D093C 38810B0C */  jal        func_002e04e0
    /* 1D0940 002D0940 00000000 */   nop
    /* 1D0944 002D0944 2D884000 */  daddu      $17, $2, $0
    /* 1D0948 002D0948 C80E048E */  lw         $4, 0xEC8($16)
    /* 1D094C 002D094C 38810B0C */  jal        func_002e04e0
    /* 1D0950 002D0950 00000000 */   nop
    /* 1D0954 002D0954 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0958 002D0958 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D095C 002D095C 00008244 */  mtc1       $2, $f0
    /* 1D0960 002D0960 00000000 */  nop
    /* 1D0964 002D0964 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0968 002D0968 5801A427 */  addiu      $4, $29, 0x158
    /* 1D096C 002D096C 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D0970 002D0970 5CCA0A0C */  jal        func_002b2970
    /* 1D0974 002D0974 00000000 */   nop
    /* 1D0978 002D0978 C80E048E */  lw         $4, 0xEC8($16)
    /* 1D097C 002D097C 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D0980 002D0980 3300456A */  ldl        $5, 0x33($18)
    /* 1D0984 002D0984 5801A6DF */  ld         $6, 0x158($29)
    /* 1D0988 002D0988 02000724 */  addiu      $7, $0, 0x2
    /* 1D098C 002D098C 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0990 002D0990 2D480000 */  daddu      $9, $0, $0
    /* 1D0994 002D0994 88810B0C */  jal        func_002e0620
    /* 1D0998 002D0998 00000000 */   nop
    /* 1D099C 002D099C 380E048E */  lw         $4, 0xE38($16)
    /* 1D09A0 002D09A0 38810B0C */  jal        func_002e04e0
    /* 1D09A4 002D09A4 00000000 */   nop
    /* 1D09A8 002D09A8 2D904000 */  daddu      $18, $2, $0
    /* 1D09AC 002D09AC 380E048E */  lw         $4, 0xE38($16)
    /* 1D09B0 002D09B0 38810B0C */  jal        func_002e04e0
    /* 1D09B4 002D09B4 00000000 */   nop
    /* 1D09B8 002D09B8 2D884000 */  daddu      $17, $2, $0
    /* 1D09BC 002D09BC 380E048E */  lw         $4, 0xE38($16)
    /* 1D09C0 002D09C0 38810B0C */  jal        func_002e04e0
    /* 1D09C4 002D09C4 00000000 */   nop
    /* 1D09C8 002D09C8 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D09CC 002D09CC FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D09D0 002D09D0 00008244 */  mtc1       $2, $f0
    /* 1D09D4 002D09D4 00000000 */  nop
    /* 1D09D8 002D09D8 40030146 */  add.s      $f13, $f0, $f1
    /* 1D09DC 002D09DC 5001A427 */  addiu      $4, $29, 0x150
    /* 1D09E0 002D09E0 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D09E4 002D09E4 5CCA0A0C */  jal        func_002b2970
    /* 1D09E8 002D09E8 00000000 */   nop
    /* 1D09EC 002D09EC 380E048E */  lw         $4, 0xE38($16)
    /* 1D09F0 002D09F0 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D09F4 002D09F4 3300456A */  ldl        $5, 0x33($18)
    /* 1D09F8 002D09F8 5001A6DF */  ld         $6, 0x150($29)
    /* 1D09FC 002D09FC 02000724 */  addiu      $7, $0, 0x2
    /* 1D0A00 002D0A00 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0A04 002D0A04 2D480000 */  daddu      $9, $0, $0
    /* 1D0A08 002D0A08 88810B0C */  jal        func_002e0620
    /* 1D0A0C 002D0A0C 00000000 */   nop
    /* 1D0A10 002D0A10 B40E048E */  lw         $4, 0xEB4($16)
    /* 1D0A14 002D0A14 38810B0C */  jal        func_002e04e0
    /* 1D0A18 002D0A18 00000000 */   nop
    /* 1D0A1C 002D0A1C 2D904000 */  daddu      $18, $2, $0
    /* 1D0A20 002D0A20 B40E048E */  lw         $4, 0xEB4($16)
    /* 1D0A24 002D0A24 38810B0C */  jal        func_002e04e0
    /* 1D0A28 002D0A28 00000000 */   nop
    /* 1D0A2C 002D0A2C 2D884000 */  daddu      $17, $2, $0
    /* 1D0A30 002D0A30 B40E048E */  lw         $4, 0xEB4($16)
    /* 1D0A34 002D0A34 38810B0C */  jal        func_002e04e0
    /* 1D0A38 002D0A38 00000000 */   nop
    /* 1D0A3C 002D0A3C 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0A40 002D0A40 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D0A44 002D0A44 00008244 */  mtc1       $2, $f0
    /* 1D0A48 002D0A48 00000000 */  nop
    /* 1D0A4C 002D0A4C 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0A50 002D0A50 4801A427 */  addiu      $4, $29, 0x148
    /* 1D0A54 002D0A54 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D0A58 002D0A58 5CCA0A0C */  jal        func_002b2970
    /* 1D0A5C 002D0A5C 00000000 */   nop
    /* 1D0A60 002D0A60 B40E048E */  lw         $4, 0xEB4($16)
    /* 1D0A64 002D0A64 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D0A68 002D0A68 3300456A */  ldl        $5, 0x33($18)
    /* 1D0A6C 002D0A6C 4801A6DF */  ld         $6, 0x148($29)
    /* 1D0A70 002D0A70 02000724 */  addiu      $7, $0, 0x2
    /* 1D0A74 002D0A74 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0A78 002D0A78 01000924 */  addiu      $9, $0, 0x1
    /* 1D0A7C 002D0A7C 88810B0C */  jal        func_002e0620
    /* 1D0A80 002D0A80 00000000 */   nop
    /* 1D0A84 002D0A84 B80E048E */  lw         $4, 0xEB8($16)
    /* 1D0A88 002D0A88 38810B0C */  jal        func_002e04e0
    /* 1D0A8C 002D0A8C 00000000 */   nop
    /* 1D0A90 002D0A90 2D904000 */  daddu      $18, $2, $0
    /* 1D0A94 002D0A94 B80E048E */  lw         $4, 0xEB8($16)
    /* 1D0A98 002D0A98 38810B0C */  jal        func_002e04e0
    /* 1D0A9C 002D0A9C 00000000 */   nop
    /* 1D0AA0 002D0AA0 2D884000 */  daddu      $17, $2, $0
    /* 1D0AA4 002D0AA4 B80E048E */  lw         $4, 0xEB8($16)
    /* 1D0AA8 002D0AA8 38810B0C */  jal        func_002e04e0
    /* 1D0AAC 002D0AAC 00000000 */   nop
    /* 1D0AB0 002D0AB0 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0AB4 002D0AB4 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D0AB8 002D0AB8 00008244 */  mtc1       $2, $f0
    /* 1D0ABC 002D0ABC 00000000 */  nop
    /* 1D0AC0 002D0AC0 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0AC4 002D0AC4 4001A427 */  addiu      $4, $29, 0x140
    /* 1D0AC8 002D0AC8 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D0ACC 002D0ACC 5CCA0A0C */  jal        func_002b2970
    /* 1D0AD0 002D0AD0 00000000 */   nop
    /* 1D0AD4 002D0AD4 B80E048E */  lw         $4, 0xEB8($16)
    /* 1D0AD8 002D0AD8 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D0ADC 002D0ADC 3300456A */  ldl        $5, 0x33($18)
    /* 1D0AE0 002D0AE0 4001A6DF */  ld         $6, 0x140($29)
    /* 1D0AE4 002D0AE4 02000724 */  addiu      $7, $0, 0x2
    /* 1D0AE8 002D0AE8 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0AEC 002D0AEC 01000924 */  addiu      $9, $0, 0x1
    /* 1D0AF0 002D0AF0 88810B0C */  jal        func_002e0620
    /* 1D0AF4 002D0AF4 00000000 */   nop
    /* 1D0AF8 002D0AF8 C40C048E */  lw         $4, 0xCC4($16)
    /* 1D0AFC 002D0AFC 38810B0C */  jal        func_002e04e0
    /* 1D0B00 002D0B00 00000000 */   nop
    /* 1D0B04 002D0B04 2D904000 */  daddu      $18, $2, $0
    /* 1D0B08 002D0B08 C40C048E */  lw         $4, 0xCC4($16)
    /* 1D0B0C 002D0B0C 38810B0C */  jal        func_002e04e0
    /* 1D0B10 002D0B10 00000000 */   nop
    /* 1D0B14 002D0B14 2D884000 */  daddu      $17, $2, $0
    /* 1D0B18 002D0B18 C40C048E */  lw         $4, 0xCC4($16)
    /* 1D0B1C 002D0B1C 38810B0C */  jal        func_002e04e0
    /* 1D0B20 002D0B20 00000000 */   nop
    /* 1D0B24 002D0B24 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0B28 002D0B28 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D0B2C 002D0B2C 00008244 */  mtc1       $2, $f0
    /* 1D0B30 002D0B30 00000000 */  nop
    /* 1D0B34 002D0B34 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0B38 002D0B38 3801A427 */  addiu      $4, $29, 0x138
    /* 1D0B3C 002D0B3C 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D0B40 002D0B40 5CCA0A0C */  jal        func_002b2970
    /* 1D0B44 002D0B44 00000000 */   nop
    /* 1D0B48 002D0B48 C40C048E */  lw         $4, 0xCC4($16)
    /* 1D0B4C 002D0B4C 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D0B50 002D0B50 3300456A */  ldl        $5, 0x33($18)
    /* 1D0B54 002D0B54 3801A6DF */  ld         $6, 0x138($29)
    /* 1D0B58 002D0B58 02000724 */  addiu      $7, $0, 0x2
    /* 1D0B5C 002D0B5C 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0B60 002D0B60 01000924 */  addiu      $9, $0, 0x1
    /* 1D0B64 002D0B64 88810B0C */  jal        func_002e0620
    /* 1D0B68 002D0B68 00000000 */   nop
    /* 1D0B6C 002D0B6C BC0E048E */  lw         $4, 0xEBC($16)
    /* 1D0B70 002D0B70 38810B0C */  jal        func_002e04e0
    /* 1D0B74 002D0B74 00000000 */   nop
    /* 1D0B78 002D0B78 2D904000 */  daddu      $18, $2, $0
    /* 1D0B7C 002D0B7C BC0E048E */  lw         $4, 0xEBC($16)
    /* 1D0B80 002D0B80 38810B0C */  jal        func_002e04e0
    /* 1D0B84 002D0B84 00000000 */   nop
    /* 1D0B88 002D0B88 2D884000 */  daddu      $17, $2, $0
    /* 1D0B8C 002D0B8C BC0E048E */  lw         $4, 0xEBC($16)
    /* 1D0B90 002D0B90 38810B0C */  jal        func_002e04e0
    /* 1D0B94 002D0B94 00000000 */   nop
    /* 1D0B98 002D0B98 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0B9C 002D0B9C FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D0BA0 002D0BA0 00008244 */  mtc1       $2, $f0
    /* 1D0BA4 002D0BA4 00000000 */  nop
    /* 1D0BA8 002D0BA8 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0BAC 002D0BAC 3001A427 */  addiu      $4, $29, 0x130
    /* 1D0BB0 002D0BB0 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D0BB4 002D0BB4 5CCA0A0C */  jal        func_002b2970
    /* 1D0BB8 002D0BB8 00000000 */   nop
    /* 1D0BBC 002D0BBC BC0E048E */  lw         $4, 0xEBC($16)
    /* 1D0BC0 002D0BC0 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D0BC4 002D0BC4 3300456A */  ldl        $5, 0x33($18)
    /* 1D0BC8 002D0BC8 3001A6DF */  ld         $6, 0x130($29)
    /* 1D0BCC 002D0BCC 02000724 */  addiu      $7, $0, 0x2
    /* 1D0BD0 002D0BD0 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0BD4 002D0BD4 2D48E000 */  daddu      $9, $7, $0
    /* 1D0BD8 002D0BD8 88810B0C */  jal        func_002e0620
    /* 1D0BDC 002D0BDC 00000000 */   nop
    /* 1D0BE0 002D0BE0 C00E048E */  lw         $4, 0xEC0($16)
    /* 1D0BE4 002D0BE4 38810B0C */  jal        func_002e04e0
    /* 1D0BE8 002D0BE8 00000000 */   nop
    /* 1D0BEC 002D0BEC 2D904000 */  daddu      $18, $2, $0
    /* 1D0BF0 002D0BF0 C00E048E */  lw         $4, 0xEC0($16)
    /* 1D0BF4 002D0BF4 38810B0C */  jal        func_002e04e0
    /* 1D0BF8 002D0BF8 00000000 */   nop
    /* 1D0BFC 002D0BFC 2D884000 */  daddu      $17, $2, $0
    /* 1D0C00 002D0C00 C00E048E */  lw         $4, 0xEC0($16)
    /* 1D0C04 002D0C04 38810B0C */  jal        func_002e04e0
    /* 1D0C08 002D0C08 00000000 */   nop
    /* 1D0C0C 002D0C0C 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0C10 002D0C10 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D0C14 002D0C14 00008244 */  mtc1       $2, $f0
    /* 1D0C18 002D0C18 00000000 */  nop
    /* 1D0C1C 002D0C1C 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0C20 002D0C20 2801A427 */  addiu      $4, $29, 0x128
    /* 1D0C24 002D0C24 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D0C28 002D0C28 5CCA0A0C */  jal        func_002b2970
    /* 1D0C2C 002D0C2C 00000000 */   nop
    /* 1D0C30 002D0C30 C00E048E */  lw         $4, 0xEC0($16)
    /* 1D0C34 002D0C34 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D0C38 002D0C38 3300456A */  ldl        $5, 0x33($18)
    /* 1D0C3C 002D0C3C 2801A6DF */  ld         $6, 0x128($29)
    /* 1D0C40 002D0C40 02000724 */  addiu      $7, $0, 0x2
    /* 1D0C44 002D0C44 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0C48 002D0C48 2D48E000 */  daddu      $9, $7, $0
    /* 1D0C4C 002D0C4C 88810B0C */  jal        func_002e0620
    /* 1D0C50 002D0C50 00000000 */   nop
    /* 1D0C54 002D0C54 C00C048E */  lw         $4, 0xCC0($16)
    /* 1D0C58 002D0C58 38810B0C */  jal        func_002e04e0
    /* 1D0C5C 002D0C5C 00000000 */   nop
    /* 1D0C60 002D0C60 2D904000 */  daddu      $18, $2, $0
    /* 1D0C64 002D0C64 C00C048E */  lw         $4, 0xCC0($16)
    /* 1D0C68 002D0C68 38810B0C */  jal        func_002e04e0
    /* 1D0C6C 002D0C6C 00000000 */   nop
    /* 1D0C70 002D0C70 2D884000 */  daddu      $17, $2, $0
    /* 1D0C74 002D0C74 C00C048E */  lw         $4, 0xCC0($16)
    /* 1D0C78 002D0C78 38810B0C */  jal        func_002e04e0
    /* 1D0C7C 002D0C7C 00000000 */   nop
    /* 1D0C80 002D0C80 300041C4 */  lwc1       $f1, 0x30($2)
    /* 1D0C84 002D0C84 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* 1D0C88 002D0C88 00008244 */  mtc1       $2, $f0
    /* 1D0C8C 002D0C8C 00000000 */  nop
    /* 1D0C90 002D0C90 40030146 */  add.s      $f13, $f0, $f1
    /* 1D0C94 002D0C94 2001A427 */  addiu      $4, $29, 0x120
    /* 1D0C98 002D0C98 2C002CC6 */  lwc1       $f12, 0x2C($17)
    /* 1D0C9C 002D0C9C 5CCA0A0C */  jal        func_002b2970
    /* 1D0CA0 002D0CA0 00000000 */   nop
    /* 1D0CA4 002D0CA4 C00C048E */  lw         $4, 0xCC0($16)
    /* 1D0CA8 002D0CA8 2C00456E */  ldr        $5, 0x2C($18)
    /* 1D0CAC 002D0CAC 3300456A */  ldl        $5, 0x33($18)
    /* 1D0CB0 002D0CB0 2001A6DF */  ld         $6, 0x120($29)
    /* 1D0CB4 002D0CB4 02000724 */  addiu      $7, $0, 0x2
    /* 1D0CB8 002D0CB8 0F000824 */  addiu      $8, $0, 0xF
    /* 1D0CBC 002D0CBC 2D48E000 */  daddu      $9, $7, $0
    /* 1D0CC0 002D0CC0 88810B0C */  jal        func_002e0620
    /* 1D0CC4 002D0CC4 00000000 */   nop
    /* 1D0CC8 002D0CC8 8C001124 */  addiu      $17, $0, 0x8C
    /* 1D0CCC 002D0CCC 14000010 */  b          .L002D0D20
    /* 1D0CD0 002D0CD0 00000000 */   nop
  .L002D0CD4:
    /* 1D0CD4 002D0CD4 80100300 */  sll        $2, $3, 2
    /* 1D0CD8 002D0CD8 21100202 */  addu       $2, $16, $2
    /* 1D0CDC 002D0CDC 380C5224 */  addiu      $18, $2, 0xC38
    /* 1D0CE0 002D0CE0 380C448C */  lw         $4, 0xC38($2)
    /* 1D0CE4 002D0CE4 2D280000 */  daddu      $5, $0, $0
    /* 1D0CE8 002D0CE8 5C810B0C */  jal        func_002e0570
    /* 1D0CEC 002D0CEC 00000000 */   nop
    /* 1D0CF0 002D0CF0 3C160200 */  dsll32     $2, $2, 24
    /* 1D0CF4 002D0CF4 3F160200 */  dsra32     $2, $2, 24
    /* 1D0CF8 002D0CF8 01000624 */  addiu      $6, $0, 0x1
    /* 1D0CFC 002D0CFC 05004614 */  bne        $2, $6, .L002D0D14
    /* 1D0D00 002D0D00 00000000 */   nop
    /* 1D0D04 002D0D04 0000448E */  lw         $4, 0x0($18)
    /* 1D0D08 002D0D08 2D280000 */  daddu      $5, $0, $0
    /* 1D0D0C 002D0D0C 3C810B0C */  jal        func_002e04f0
    /* 1D0D10 002D0D10 00000000 */   nop
  .L002D0D14:
    /* 1D0D14 002D0D14 01002226 */  addiu      $2, $17, 0x1
    /* 1D0D18 002D0D18 3C8C0200 */  dsll32     $17, $2, 16
    /* 1D0D1C 002D0D1C 3F8C1100 */  dsra32     $17, $17, 16
  .L002D0D20:
    /* 1D0D20 002D0D20 3C1C1100 */  dsll32     $3, $17, 16
    /* 1D0D24 002D0D24 3F1C0300 */  dsra32     $3, $3, 16
    /* 1D0D28 002D0D28 8F006228 */  slti       $2, $3, 0x8F
    /* 1D0D2C 002D0D2C E9FF4014 */  bnez       $2, .L002D0CD4
    /* 1D0D30 002D0D30 00000000 */   nop
    /* 1D0D34 002D0D34 2D880000 */  daddu      $17, $0, $0
    /* 1D0D38 002D0D38 0E000010 */  b          .L002D0D74
    /* 1D0D3C 002D0D3C 00000000 */   nop
  .L002D0D40:
    /* 1D0D40 002D0D40 80100300 */  sll        $2, $3, 2
    /* 1D0D44 002D0D44 21100202 */  addu       $2, $16, $2
    /* 1D0D48 002D0D48 380C448C */  lw         $4, 0xC38($2)
    /* 1D0D4C 002D0D4C 2D280000 */  daddu      $5, $0, $0
    /* 1D0D50 002D0D50 FF000624 */  addiu      $6, $0, 0xFF
    /* 1D0D54 002D0D54 2D380000 */  daddu      $7, $0, $0
    /* 1D0D58 002D0D58 0A000824 */  addiu      $8, $0, 0xA
    /* 1D0D5C 002D0D5C 2D480000 */  daddu      $9, $0, $0
    /* 1D0D60 002D0D60 98810B0C */  jal        func_002e0660
    /* 1D0D64 002D0D64 00000000 */   nop
    /* 1D0D68 002D0D68 01002226 */  addiu      $2, $17, 0x1
    /* 1D0D6C 002D0D6C 3C8C0200 */  dsll32     $17, $2, 16
    /* 1D0D70 002D0D70 3F8C1100 */  dsra32     $17, $17, 16
  .L002D0D74:
    /* 1D0D74 002D0D74 3C1C1100 */  dsll32     $3, $17, 16
    /* 1D0D78 002D0D78 3F1C0300 */  dsra32     $3, $3, 16
    /* 1D0D7C 002D0D7C 03006228 */  slti       $2, $3, 0x3
    /* 1D0D80 002D0D80 EFFF4014 */  bnez       $2, .L002D0D40
    /* 1D0D84 002D0D84 00000000 */   nop
    /* 1D0D88 002D0D88 2D980000 */  daddu      $19, $0, $0
    /* 1D0D8C 002D0D8C 4C000010 */  b          .L002D0EC0
    /* 1D0D90 002D0D90 00000000 */   nop
  .L002D0D94:
    /* 1D0D94 002D0D94 3C941300 */  dsll32     $18, $19, 16
    /* 1D0D98 002D0D98 3F941200 */  dsra32     $18, $18, 16
    /* 1D0D9C 002D0D9C 3A004226 */  addiu      $2, $18, 0x3A
    /* 1D0DA0 002D0DA0 C0180200 */  sll        $3, $2, 3
    /* 1D0DA4 002D0DA4 6400023C */  lui        $2, %hi(D_0063F560)
    /* 1D0DA8 002D0DA8 60F54224 */  addiu      $2, $2, %lo(D_0063F560)
    /* 1D0DAC 002D0DAC 21884300 */  addu       $17, $2, $3
    /* 1D0DB0 002D0DB0 80101200 */  sll        $2, $18, 2
    /* 1D0DB4 002D0DB4 21180202 */  addu       $3, $16, $2
    /* 1D0DB8 002D0DB8 200D7524 */  addiu      $21, $3, 0xD20
    /* 1D0DBC 002D0DBC 64004226 */  addiu      $2, $18, 0x64
    /* 1D0DC0 002D0DC0 00008244 */  mtc1       $2, $f0
    /* 1D0DC4 002D0DC4 00000000 */  nop
    /* 1D0DC8 002D0DC8 20038046 */  cvt.s.w    $f12, $f0
    /* 1D0DCC 002D0DCC 200D648C */  lw         $4, 0xD20($3)
    /* 1D0DD0 002D0DD0 56000524 */  addiu      $5, $0, 0x56
    /* 1D0DD4 002D0DD4 78820B0C */  jal        func_002e09e0
    /* 1D0DD8 002D0DD8 00000000 */   nop
    /* 1D0DDC 002D0DDC 1300401A */  blez       $18, .L002D0E2C
    /* 1D0DE0 002D0DE0 00000000 */   nop
    /* 1D0DE4 002D0DE4 EC01A427 */  addiu      $4, $29, 0x1EC
    /* 1D0DE8 002D0DE8 ED000524 */  addiu      $5, $0, 0xED
    /* 1D0DEC 002D0DEC 80000624 */  addiu      $6, $0, 0x80
    /* 1D0DF0 002D0DF0 2D380000 */  daddu      $7, $0, $0
    /* 1D0DF4 002D0DF4 FF000824 */  addiu      $8, $0, 0xFF
    /* 1D0DF8 002D0DF8 98CA0A0C */  jal        func_002b2a60
    /* 1D0DFC 002D0DFC 00000000 */   nop
    /* 1D0E00 002D0E00 0000A48E */  lw         $4, 0x0($21)
    /* 1D0E04 002D0E04 38810B0C */  jal        func_002e04e0
    /* 1D0E08 002D0E08 00000000 */   nop
    /* 1D0E0C 002D0E0C EC01A693 */  lbu        $6, 0x1EC($29)
    /* 1D0E10 002D0E10 ED01A593 */  lbu        $5, 0x1ED($29)
    /* 1D0E14 002D0E14 EE01A493 */  lbu        $4, 0x1EE($29)
    /* 1D0E18 002D0E18 EF01A393 */  lbu        $3, 0x1EF($29)
    /* 1D0E1C 002D0E1C 790046A0 */  sb         $6, 0x79($2)
    /* 1D0E20 002D0E20 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1D0E24 002D0E24 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1D0E28 002D0E28 7C0043A0 */  sb         $3, 0x7C($2)
  .L002D0E2C:
    /* 1D0E2C 002D0E2C 3C141300 */  dsll32     $2, $19, 16
    /* 1D0E30 002D0E30 3F140200 */  dsra32     $2, $2, 16
    /* 1D0E34 002D0E34 80100200 */  sll        $2, $2, 2
    /* 1D0E38 002D0E38 21100202 */  addu       $2, $16, $2
    /* 1D0E3C 002D0E3C 200D5224 */  addiu      $18, $2, 0xD20
    /* 1D0E40 002D0E40 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1D0E44 002D0E44 00088244 */  mtc1       $2, $f1
    /* 1D0E48 002D0E48 000020C6 */  lwc1       $f0, 0x0($17)
    /* 1D0E4C 002D0E4C 000B0046 */  add.s      $f12, $f1, $f0
    /* 1D0E50 002D0E50 1801A427 */  addiu      $4, $29, 0x118
    /* 1D0E54 002D0E54 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1D0E58 002D0E58 5CCA0A0C */  jal        func_002b2970
    /* 1D0E5C 002D0E5C 00000000 */   nop
    /* 1D0E60 002D0E60 1001A427 */  addiu      $4, $29, 0x110
    /* 1D0E64 002D0E64 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1D0E68 002D0E68 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1D0E6C 002D0E6C 5CCA0A0C */  jal        func_002b2970
    /* 1D0E70 002D0E70 00000000 */   nop
    /* 1D0E74 002D0E74 0000448E */  lw         $4, 0x0($18)
    /* 1D0E78 002D0E78 1801A5DF */  ld         $5, 0x118($29)
    /* 1D0E7C 002D0E7C 1001A6DF */  ld         $6, 0x110($29)
    /* 1D0E80 002D0E80 2D380000 */  daddu      $7, $0, $0
    /* 1D0E84 002D0E84 03000824 */  addiu      $8, $0, 0x3
    /* 1D0E88 002D0E88 2D486002 */  daddu      $9, $19, $0
    /* 1D0E8C 002D0E8C 88810B0C */  jal        func_002e0620
    /* 1D0E90 002D0E90 00000000 */   nop
    /* 1D0E94 002D0E94 0000448E */  lw         $4, 0x0($18)
    /* 1D0E98 002D0E98 2D280000 */  daddu      $5, $0, $0
    /* 1D0E9C 002D0E9C FF000624 */  addiu      $6, $0, 0xFF
    /* 1D0EA0 002D0EA0 2D380000 */  daddu      $7, $0, $0
    /* 1D0EA4 002D0EA4 03000824 */  addiu      $8, $0, 0x3
    /* 1D0EA8 002D0EA8 2D486002 */  daddu      $9, $19, $0
    /* 1D0EAC 002D0EAC 98810B0C */  jal        func_002e0660
    /* 1D0EB0 002D0EB0 00000000 */   nop
    /* 1D0EB4 002D0EB4 01006226 */  addiu      $2, $19, 0x1
    /* 1D0EB8 002D0EB8 3C9C0200 */  dsll32     $19, $2, 16
    /* 1D0EBC 002D0EBC 3F9C1300 */  dsra32     $19, $19, 16
  .L002D0EC0:
    /* 1D0EC0 002D0EC0 3C141300 */  dsll32     $2, $19, 16
    /* 1D0EC4 002D0EC4 3F140200 */  dsra32     $2, $2, 16
    /* 1D0EC8 002D0EC8 07004228 */  slti       $2, $2, 0x7
    /* 1D0ECC 002D0ECC B1FF4014 */  bnez       $2, .L002D0D94
    /* 1D0ED0 002D0ED0 00000000 */   nop
    /* 1D0ED4 002D0ED4 E801A427 */  addiu      $4, $29, 0x1E8
    /* 1D0ED8 002D0ED8 2D000524 */  addiu      $5, $0, 0x2D
    /* 1D0EDC 002D0EDC 2D30A000 */  daddu      $6, $5, $0
    /* 1D0EE0 002D0EE0 2D38A000 */  daddu      $7, $5, $0
    /* 1D0EE4 002D0EE4 FF000824 */  addiu      $8, $0, 0xFF
    /* 1D0EE8 002D0EE8 98CA0A0C */  jal        func_002b2a60
    /* 1D0EEC 002D0EEC 00000000 */   nop
    /* 1D0EF0 002D0EF0 07000282 */  lb         $2, 0x7($16)
    /* 1D0EF4 002D0EF4 80100200 */  sll        $2, $2, 2
    /* 1D0EF8 002D0EF8 21105000 */  addu       $2, $2, $16
    /* 1D0EFC 002D0EFC 240D448C */  lw         $4, 0xD24($2)
    /* 1D0F00 002D0F00 38810B0C */  jal        func_002e04e0
    /* 1D0F04 002D0F04 00000000 */   nop
    /* 1D0F08 002D0F08 E801A693 */  lbu        $6, 0x1E8($29)
    /* 1D0F0C 002D0F0C E901A593 */  lbu        $5, 0x1E9($29)
    /* 1D0F10 002D0F10 EA01A493 */  lbu        $4, 0x1EA($29)
    /* 1D0F14 002D0F14 EB01A393 */  lbu        $3, 0x1EB($29)
    /* 1D0F18 002D0F18 790046A0 */  sb         $6, 0x79($2)
    /* 1D0F1C 002D0F1C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1D0F20 002D0F20 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1D0F24 002D0F24 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1D0F28 002D0F28 07000982 */  lb         $9, 0x7($16)
    /* 1D0F2C 002D0F2C 440C048E */  lw         $4, 0xC44($16)
    /* 1D0F30 002D0F30 2D280000 */  daddu      $5, $0, $0
    /* 1D0F34 002D0F34 FF000624 */  addiu      $6, $0, 0xFF
    /* 1D0F38 002D0F38 2D380000 */  daddu      $7, $0, $0
    /* 1D0F3C 002D0F3C 2D400000 */  daddu      $8, $0, $0
    /* 1D0F40 002D0F40 98810B0C */  jal        func_002e0660
    /* 1D0F44 002D0F44 00000000 */   nop
    /* 1D0F48 002D0F48 07000982 */  lb         $9, 0x7($16)
    /* 1D0F4C 002D0F4C 480C048E */  lw         $4, 0xC48($16)
    /* 1D0F50 002D0F50 2D280000 */  daddu      $5, $0, $0
    /* 1D0F54 002D0F54 FF000624 */  addiu      $6, $0, 0xFF
    /* 1D0F58 002D0F58 2D380000 */  daddu      $7, $0, $0
    /* 1D0F5C 002D0F5C 2D400000 */  daddu      $8, $0, $0
    /* 1D0F60 002D0F60 98810B0C */  jal        func_002e0660
    /* 1D0F64 002D0F64 00000000 */   nop
    /* 1D0F68 002D0F68 2D880000 */  daddu      $17, $0, $0
    /* 1D0F6C 002D0F6C 0E000010 */  b          .L002D0FA8
    /* 1D0F70 002D0F70 00000000 */   nop
  .L002D0F74:
    /* 1D0F74 002D0F74 80100300 */  sll        $2, $3, 2
    /* 1D0F78 002D0F78 21100202 */  addu       $2, $16, $2
    /* 1D0F7C 002D0F7C 380C448C */  lw         $4, 0xC38($2)
    /* 1D0F80 002D0F80 2D280000 */  daddu      $5, $0, $0
    /* 1D0F84 002D0F84 FF000624 */  addiu      $6, $0, 0xFF
    /* 1D0F88 002D0F88 2D380000 */  daddu      $7, $0, $0
    /* 1D0F8C 002D0F8C 0A000824 */  addiu      $8, $0, 0xA
    /* 1D0F90 002D0F90 2D480000 */  daddu      $9, $0, $0
    /* 1D0F94 002D0F94 98810B0C */  jal        func_002e0660
    /* 1D0F98 002D0F98 00000000 */   nop
    /* 1D0F9C 002D0F9C 01002226 */  addiu      $2, $17, 0x1
    /* 1D0FA0 002D0FA0 3C8C0200 */  dsll32     $17, $2, 16
    /* 1D0FA4 002D0FA4 3F8C1100 */  dsra32     $17, $17, 16
  .L002D0FA8:
    /* 1D0FA8 002D0FA8 3C1C1100 */  dsll32     $3, $17, 16
    /* 1D0FAC 002D0FAC 3F1C0300 */  dsra32     $3, $3, 16
    /* 1D0FB0 002D0FB0 03006228 */  slti       $2, $3, 0x3
    /* 1D0FB4 002D0FB4 EFFF4014 */  bnez       $2, .L002D0F74
    /* 1D0FB8 002D0FB8 00000000 */   nop
    /* 1D0FBC 002D0FBC 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1D0FC0 002D0FC0 00608244 */  mtc1       $2, $f12
    /* 1D0FC4 002D0FC4 E80D048E */  lw         $4, 0xDE8($16)
    /* 1D0FC8 002D0FC8 41000524 */  addiu      $5, $0, 0x41
    /* 1D0FCC 002D0FCC 78820B0C */  jal        func_002e09e0
    /* 1D0FD0 002D0FD0 00000000 */   nop
    /* 1D0FD4 002D0FD4 E80D048E */  lw         $4, 0xDE8($16)
    /* 1D0FD8 002D0FD8 2D280000 */  daddu      $5, $0, $0
    /* 1D0FDC 002D0FDC FF000624 */  addiu      $6, $0, 0xFF
    /* 1D0FE0 002D0FE0 2D380000 */  daddu      $7, $0, $0
    /* 1D0FE4 002D0FE4 06000824 */  addiu      $8, $0, 0x6
    /* 1D0FE8 002D0FE8 2D480000 */  daddu      $9, $0, $0
    /* 1D0FEC 002D0FEC 98810B0C */  jal        func_002e0660
    /* 1D0FF0 002D0FF0 00000000 */   nop
    /* 1D0FF4 002D0FF4 4643023C */  lui        $2, (0x43460000 >> 16)
    /* 1D0FF8 002D0FF8 00A08244 */  mtc1       $2, $f20
    /* 1D0FFC 002D0FFC E80D048E */  lw         $4, 0xDE8($16)
    /* 1D1000 002D1000 38810B0C */  jal        func_002e04e0
    /* 1D1004 002D1004 00000000 */   nop
    /* 1D1008 002D1008 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1D100C 002D100C 51010224 */  addiu      $2, $0, 0x151
    /* 1D1010 002D1010 00008244 */  mtc1       $2, $f0
    /* 1D1014 002D1014 00000000 */  nop
    /* 1D1018 002D1018 20058046 */  cvt.s.w    $f20, $f0
    /* 1D101C 002D101C E80D048E */  lw         $4, 0xDE8($16)
    /* 1D1020 002D1020 38810B0C */  jal        func_002e04e0
    /* 1D1024 002D1024 00000000 */   nop
    /* 1D1028 002D1028 300054E4 */  swc1       $f20, 0x30($2)
    /* 1D102C 002D102C 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1D1030 002D1030 00608244 */  mtc1       $2, $f12
    /* 1D1034 002D1034 EC0D048E */  lw         $4, 0xDEC($16)
    /* 1D1038 002D1038 41000524 */  addiu      $5, $0, 0x41
    /* 1D103C 002D103C 78820B0C */  jal        func_002e09e0
    /* 1D1040 002D1040 00000000 */   nop
    /* 1D1044 002D1044 EC0D048E */  lw         $4, 0xDEC($16)
    /* 1D1048 002D1048 2D280000 */  daddu      $5, $0, $0
    /* 1D104C 002D104C FF000624 */  addiu      $6, $0, 0xFF
    /* 1D1050 002D1050 2D380000 */  daddu      $7, $0, $0
    /* 1D1054 002D1054 06000824 */  addiu      $8, $0, 0x6
    /* 1D1058 002D1058 2D480000 */  daddu      $9, $0, $0
    /* 1D105C 002D105C 98810B0C */  jal        func_002e0660
    /* 1D1060 002D1060 00000000 */   nop
    /* 1D1064 002D1064 5843023C */  lui        $2, (0x43580000 >> 16)
    /* 1D1068 002D1068 00A08244 */  mtc1       $2, $f20
    /* 1D106C 002D106C EC0D048E */  lw         $4, 0xDEC($16)
    /* 1D1070 002D1070 38810B0C */  jal        func_002e04e0
    /* 1D1074 002D1074 00000000 */   nop
    /* 1D1078 002D1078 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1D107C 002D107C B843023C */  lui        $2, (0x43B80000 >> 16)
    /* 1D1080 002D1080 00A08244 */  mtc1       $2, $f20
    /* 1D1084 002D1084 EC0D048E */  lw         $4, 0xDEC($16)
    /* 1D1088 002D1088 38810B0C */  jal        func_002e04e0
    /* 1D108C 002D108C 00000000 */   nop
    /* 1D1090 002D1090 300054E4 */  swc1       $f20, 0x30($2)
    /* 1D1094 002D1094 4442023C */  lui        $2, (0x42440000 >> 16)
    /* 1D1098 002D1098 00608244 */  mtc1       $2, $f12
    /* 1D109C 002D109C DC0D048E */  lw         $4, 0xDDC($16)
    /* 1D10A0 002D10A0 41000524 */  addiu      $5, $0, 0x41
    /* 1D10A4 002D10A4 78820B0C */  jal        func_002e09e0
    /* 1D10A8 002D10A8 00000000 */   nop
    /* 1D10AC 002D10AC DC0D048E */  lw         $4, 0xDDC($16)
    /* 1D10B0 002D10B0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1D10B4 002D10B4 2D300000 */  daddu      $6, $0, $0
    /* 1D10B8 002D10B8 2D380000 */  daddu      $7, $0, $0
    /* 1D10BC 002D10BC 0A000824 */  addiu      $8, $0, 0xA
    /* 1D10C0 002D10C0 2D480000 */  daddu      $9, $0, $0
    /* 1D10C4 002D10C4 98810B0C */  jal        func_002e0660
    /* 1D10C8 002D10C8 00000000 */   nop
    /* 1D10CC 002D10CC 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1D10D0 002D10D0 00608244 */  mtc1       $2, $f12
    /* 1D10D4 002D10D4 F00D048E */  lw         $4, 0xDF0($16)
    /* 1D10D8 002D10D8 41000524 */  addiu      $5, $0, 0x41
    /* 1D10DC 002D10DC 78820B0C */  jal        func_002e09e0
    /* 1D10E0 002D10E0 00000000 */   nop
    /* 1D10E4 002D10E4 F00D048E */  lw         $4, 0xDF0($16)
    /* 1D10E8 002D10E8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1D10EC 002D10EC 2D300000 */  daddu      $6, $0, $0
    /* 1D10F0 002D10F0 2D380000 */  daddu      $7, $0, $0
    /* 1D10F4 002D10F4 0A000824 */  addiu      $8, $0, 0xA
    /* 1D10F8 002D10F8 2D480000 */  daddu      $9, $0, $0
    /* 1D10FC 002D10FC 98810B0C */  jal        func_002e0660
    /* 1D1100 002D1100 00000000 */   nop
    /* 1D1104 002D1104 03010224 */  addiu      $2, $0, 0x103
    /* 1D1108 002D1108 00008244 */  mtc1       $2, $f0
    /* 1D110C 002D110C 00000000 */  nop
    /* 1D1110 002D1110 20038046 */  cvt.s.w    $f12, $f0
    /* 1D1114 002D1114 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1D1118 002D1118 00688244 */  mtc1       $2, $f13
    /* 1D111C 002D111C 0801A427 */  addiu      $4, $29, 0x108
    /* 1D1120 002D1120 5CCA0A0C */  jal        func_002b2970
    /* 1D1124 002D1124 00000000 */   nop
    /* 1D1128 002D1128 03010224 */  addiu      $2, $0, 0x103
    /* 1D112C 002D112C 00008244 */  mtc1       $2, $f0
    /* 1D1130 002D1130 00000000 */  nop
    /* 1D1134 002D1134 20038046 */  cvt.s.w    $f12, $f0
    /* 1D1138 002D1138 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1D113C 002D113C 00688244 */  mtc1       $2, $f13
    /* 1D1140 002D1140 0001A427 */  addiu      $4, $29, 0x100
    /* 1D1144 002D1144 5CCA0A0C */  jal        func_002b2970
    /* 1D1148 002D1148 00000000 */   nop
    /* 1D114C 002D114C F00D048E */  lw         $4, 0xDF0($16)
    /* 1D1150 002D1150 0801A5DF */  ld         $5, 0x108($29)
    /* 1D1154 002D1154 0001A6DF */  ld         $6, 0x100($29)
    /* 1D1158 002D1158 2D380000 */  daddu      $7, $0, $0
    /* 1D115C 002D115C 2D400000 */  daddu      $8, $0, $0
    /* 1D1160 002D1160 2D480000 */  daddu      $9, $0, $0
    /* 1D1164 002D1164 88810B0C */  jal        func_002e0620
    /* 1D1168 002D1168 00000000 */   nop
    /* 1D116C 002D116C 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1D1170 002D1170 00608244 */  mtc1       $2, $f12
    /* 1D1174 002D1174 E40D048E */  lw         $4, 0xDE4($16)
    /* 1D1178 002D1178 41000524 */  addiu      $5, $0, 0x41
    /* 1D117C 002D117C 78820B0C */  jal        func_002e09e0
    /* 1D1180 002D1180 00000000 */   nop
    /* 1D1184 002D1184 E40D048E */  lw         $4, 0xDE4($16)
    /* 1D1188 002D1188 FF000524 */  addiu      $5, $0, 0xFF
    /* 1D118C 002D118C 2D300000 */  daddu      $6, $0, $0
    /* 1D1190 002D1190 2D380000 */  daddu      $7, $0, $0
    /* 1D1194 002D1194 0A000824 */  addiu      $8, $0, 0xA
    /* 1D1198 002D1198 2D480000 */  daddu      $9, $0, $0
    /* 1D119C 002D119C 98810B0C */  jal        func_002e0660
    /* 1D11A0 002D11A0 00000000 */   nop
    /* 1D11A4 002D11A4 A943023C */  lui        $2, (0x43A90000 >> 16)
    /* 1D11A8 002D11A8 00608244 */  mtc1       $2, $f12
    /* 1D11AC 002D11AC CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1D11B0 002D11B0 00688244 */  mtc1       $2, $f13
    /* 1D11B4 002D11B4 F800A427 */  addiu      $4, $29, 0xF8
    /* 1D11B8 002D11B8 5CCA0A0C */  jal        func_002b2970
    /* 1D11BC 002D11BC 00000000 */   nop
    /* 1D11C0 002D11C0 A943023C */  lui        $2, (0x43A90000 >> 16)
    /* 1D11C4 002D11C4 00608244 */  mtc1       $2, $f12
    /* 1D11C8 002D11C8 CA43023C */  lui        $2, (0x43CA0000 >> 16)
    /* 1D11CC 002D11CC 00688244 */  mtc1       $2, $f13
    /* 1D11D0 002D11D0 F000A427 */  addiu      $4, $29, 0xF0
    /* 1D11D4 002D11D4 5CCA0A0C */  jal        func_002b2970
    /* 1D11D8 002D11D8 00000000 */   nop
    /* 1D11DC 002D11DC E40D048E */  lw         $4, 0xDE4($16)
    /* 1D11E0 002D11E0 F800A5DF */  ld         $5, 0xF8($29)
    /* 1D11E4 002D11E4 F000A6DF */  ld         $6, 0xF0($29)
    /* 1D11E8 002D11E8 2D380000 */  daddu      $7, $0, $0
    /* 1D11EC 002D11EC 2D400000 */  daddu      $8, $0, $0
    /* 1D11F0 002D11F0 2D480000 */  daddu      $9, $0, $0
    /* 1D11F4 002D11F4 88810B0C */  jal        func_002e0620
    /* 1D11F8 002D11F8 00000000 */   nop
    /* 1D11FC 002D11FC 4643023C */  lui        $2, (0x43460000 >> 16)
    /* 1D1200 002D1200 00A08244 */  mtc1       $2, $f20
    /* 1D1204 002D1204 E80D048E */  lw         $4, 0xDE8($16)
    /* 1D1208 002D1208 38810B0C */  jal        func_002e04e0
    /* 1D120C 002D120C 00000000 */   nop
    /* 1D1210 002D1210 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1D1214 002D1214 51010224 */  addiu      $2, $0, 0x151
    /* 1D1218 002D1218 00008244 */  mtc1       $2, $f0
    /* 1D121C 002D121C 00000000 */  nop
    /* 1D1220 002D1220 20058046 */  cvt.s.w    $f20, $f0
    /* 1D1224 002D1224 E80D048E */  lw         $4, 0xDE8($16)
    /* 1D1228 002D1228 38810B0C */  jal        func_002e04e0
    /* 1D122C 002D122C 00000000 */   nop
    /* 1D1230 002D1230 300054E4 */  swc1       $f20, 0x30($2)
    /* 1D1234 002D1234 3F43023C */  lui        $2, (0x433F0000 >> 16)
    /* 1D1238 002D1238 00608244 */  mtc1       $2, $f12
    /* 1D123C 002D123C 4C0C048E */  lw         $4, 0xC4C($16)
    /* 1D1240 002D1240 40000524 */  addiu      $5, $0, 0x40
    /* 1D1244 002D1244 78820B0C */  jal        func_002e09e0
    /* 1D1248 002D1248 00000000 */   nop
    /* 1D124C 002D124C 280F048E */  lw         $4, 0xF28($16)
    /* 1D1250 002D1250 05000524 */  addiu      $5, $0, 0x5
    /* 1D1254 002D1254 80B4110C */  jal        func_0046d200
    /* 1D1258 002D1258 00000000 */   nop
    /* 1D125C 002D125C 2D884000 */  daddu      $17, $2, $0
    /* 1D1260 002D1260 2D202002 */  daddu      $4, $17, $0
    /* 1D1264 002D1264 98AC110C */  jal        func_0046b260
    /* 1D1268 002D1268 00000000 */   nop
    /* 1D126C 002D126C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1D1270 002D1270 00000244 */  mfc1       $2, $f0
    /* 1D1274 002D1274 00000000 */  nop
    /* 1D1278 002D1278 3C940200 */  dsll32     $18, $2, 16
    /* 1D127C 002D127C 3F941200 */  dsra32     $18, $18, 16
    /* 1D1280 002D1280 4C0C048E */  lw         $4, 0xC4C($16)
    /* 1D1284 002D1284 38810B0C */  jal        func_002e04e0
    /* 1D1288 002D1288 00000000 */   nop
    /* 1D128C 002D128C 000152A4 */  sh         $18, 0x100($2)
    /* 1D1290 002D1290 2D202002 */  daddu      $4, $17, $0
    /* 1D1294 002D1294 BCAC110C */  jal        func_0046b2f0
    /* 1D1298 002D1298 00000000 */   nop
    /* 1D129C 002D129C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1D12A0 002D12A0 00000244 */  mfc1       $2, $f0
    /* 1D12A4 002D12A4 00000000 */  nop
    /* 1D12A8 002D12A8 3C940200 */  dsll32     $18, $2, 16
    /* 1D12AC 002D12AC 3F941200 */  dsra32     $18, $18, 16
    /* 1D12B0 002D12B0 4C0C048E */  lw         $4, 0xC4C($16)
    /* 1D12B4 002D12B4 38810B0C */  jal        func_002e04e0
    /* 1D12B8 002D12B8 00000000 */   nop
    /* 1D12BC 002D12BC 020152A4 */  sh         $18, 0x102($2)
    /* 1D12C0 002D12C0 2D202002 */  daddu      $4, $17, $0
    /* 1D12C4 002D12C4 A0B4110C */  jal        func_0046d280
    /* 1D12C8 002D12C8 00000000 */   nop
    /* 1D12CC 002D12CC 4C0C048E */  lw         $4, 0xC4C($16)
    /* 1D12D0 002D12D0 2D280000 */  daddu      $5, $0, $0
    /* 1D12D4 002D12D4 CC000624 */  addiu      $6, $0, 0xCC
    /* 1D12D8 002D12D8 2D380000 */  daddu      $7, $0, $0
    /* 1D12DC 002D12DC 04000824 */  addiu      $8, $0, 0x4
    /* 1D12E0 002D12E0 2D480001 */  daddu      $9, $8, $0
    /* 1D12E4 002D12E4 98810B0C */  jal        func_002e0660
    /* 1D12E8 002D12E8 00000000 */   nop
    /* 1D12EC 002D12EC 00608044 */  mtc1       $0, $f12
    /* 1D12F0 002D12F0 4C0C048E */  lw         $4, 0xC4C($16)
    /* 1D12F4 002D12F4 20858DC7 */  lwc1       $f13, -0x7AE0($28)
    /* 1D12F8 002D12F8 2D280000 */  daddu      $5, $0, $0
    /* 1D12FC 002D12FC 04000624 */  addiu      $6, $0, 0x4
    /* 1D1300 002D1300 2D38C000 */  daddu      $7, $6, $0
    /* 1D1304 002D1304 50820B0C */  jal        func_002e0940
    /* 1D1308 002D1308 00000000 */   nop
    /* 1D130C 002D130C 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1D1310 002D1310 00608244 */  mtc1       $2, $f12
    /* 1D1314 002D1314 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 1D1318 002D1318 00688244 */  mtc1       $2, $f13
    /* 1D131C 002D131C E800A427 */  addiu      $4, $29, 0xE8
    /* 1D1320 002D1320 5CCA0A0C */  jal        func_002b2970
    /* 1D1324 002D1324 00000000 */   nop
    /* 1D1328 002D1328 70C3023C */  lui        $2, (0xC3700000 >> 16)
    /* 1D132C 002D132C 00608244 */  mtc1       $2, $f12
    /* 1D1330 002D1330 9B43023C */  lui        $2, (0x439B0000 >> 16)
    /* 1D1334 002D1334 00688244 */  mtc1       $2, $f13
    /* 1D1338 002D1338 E000A427 */  addiu      $4, $29, 0xE0
    /* 1D133C 002D133C 5CCA0A0C */  jal        func_002b2970
    /* 1D1340 002D1340 00000000 */   nop
    /* 1D1344 002D1344 4C0C048E */  lw         $4, 0xC4C($16)
    /* 1D1348 002D1348 E800A5DF */  ld         $5, 0xE8($29)
    /* 1D134C 002D134C E000A6DF */  ld         $6, 0xE0($29)
    /* 1D1350 002D1350 2D380000 */  daddu      $7, $0, $0
    /* 1D1354 002D1354 04000824 */  addiu      $8, $0, 0x4
    /* 1D1358 002D1358 2D480001 */  daddu      $9, $8, $0
    /* 1D135C 002D135C 88810B0C */  jal        func_002e0620
    /* 1D1360 002D1360 00000000 */   nop
    /* 1D1364 002D1364 4043023C */  lui        $2, (0x43400000 >> 16)
    /* 1D1368 002D1368 00608244 */  mtc1       $2, $f12
    /* 1D136C 002D136C 500C048E */  lw         $4, 0xC50($16)
    /* 1D1370 002D1370 40000524 */  addiu      $5, $0, 0x40
    /* 1D1374 002D1374 78820B0C */  jal        func_002e09e0
    /* 1D1378 002D1378 00000000 */   nop
    /* 1D137C 002D137C DC42023C */  lui        $2, (0x42DC0000 >> 16)
    /* 1D1380 002D1380 00A08244 */  mtc1       $2, $f20
    /* 1D1384 002D1384 500C048E */  lw         $4, 0xC50($16)
    /* 1D1388 002D1388 38810B0C */  jal        func_002e04e0
    /* 1D138C 002D138C 00000000 */   nop
    /* 1D1390 002D1390 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1D1394 002D1394 48C2023C */  lui        $2, (0xC2480000 >> 16)
    /* 1D1398 002D1398 00A08244 */  mtc1       $2, $f20
    /* 1D139C 002D139C 500C048E */  lw         $4, 0xC50($16)
    /* 1D13A0 002D13A0 38810B0C */  jal        func_002e04e0
    /* 1D13A4 002D13A4 00000000 */   nop
    /* 1D13A8 002D13A8 300054E4 */  swc1       $f20, 0x30($2)
    /* 1D13AC 002D13AC 280F048E */  lw         $4, 0xF28($16)
    /* 1D13B0 002D13B0 06000524 */  addiu      $5, $0, 0x6
    /* 1D13B4 002D13B4 80B4110C */  jal        func_0046d200
    /* 1D13B8 002D13B8 00000000 */   nop
    /* 1D13BC 002D13BC 2D884000 */  daddu      $17, $2, $0
    /* 1D13C0 002D13C0 2D202002 */  daddu      $4, $17, $0
    /* 1D13C4 002D13C4 98AC110C */  jal        func_0046b260
    /* 1D13C8 002D13C8 00000000 */   nop
    /* 1D13CC 002D13CC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1D13D0 002D13D0 00000244 */  mfc1       $2, $f0
    /* 1D13D4 002D13D4 00000000 */  nop
    /* 1D13D8 002D13D8 3C940200 */  dsll32     $18, $2, 16
    /* 1D13DC 002D13DC 3F941200 */  dsra32     $18, $18, 16
    /* 1D13E0 002D13E0 500C048E */  lw         $4, 0xC50($16)
    /* 1D13E4 002D13E4 38810B0C */  jal        func_002e04e0
    /* 1D13E8 002D13E8 00000000 */   nop
    /* 1D13EC 002D13EC 000152A4 */  sh         $18, 0x100($2)
    /* 1D13F0 002D13F0 500C048E */  lw         $4, 0xC50($16)
    /* 1D13F4 002D13F4 38810B0C */  jal        func_002e04e0
    /* 1D13F8 002D13F8 00000000 */   nop
    /* 1D13FC 002D13FC 020140A4 */  sh         $0, 0x102($2)
    /* 1D1400 002D1400 B4C2023C */  lui        $2, (0xC2B40000 >> 16)
    /* 1D1404 002D1404 00608244 */  mtc1       $2, $f12
    /* 1D1408 002D1408 500C048E */  lw         $4, 0xC50($16)
    /* 1D140C 002D140C 24858DC7 */  lwc1       $f13, -0x7ADC($28)
    /* 1D1410 002D1410 2D280000 */  daddu      $5, $0, $0
    /* 1D1414 002D1414 04000624 */  addiu      $6, $0, 0x4
    /* 1D1418 002D1418 2D38C000 */  daddu      $7, $6, $0
    /* 1D141C 002D141C 50820B0C */  jal        func_002e0940
    /* 1D1420 002D1420 00000000 */   nop
    /* 1D1424 002D1424 500C048E */  lw         $4, 0xC50($16)
    /* 1D1428 002D1428 2D280000 */  daddu      $5, $0, $0
    /* 1D142C 002D142C FF000624 */  addiu      $6, $0, 0xFF
    /* 1D1430 002D1430 2D380000 */  daddu      $7, $0, $0
    /* 1D1434 002D1434 04000824 */  addiu      $8, $0, 0x4
    /* 1D1438 002D1438 2D480001 */  daddu      $9, $8, $0
    /* 1D143C 002D143C 98810B0C */  jal        func_002e0660
    /* 1D1440 002D1440 00000000 */   nop
    /* 1D1444 002D1444 2D202002 */  daddu      $4, $17, $0
    /* 1D1448 002D1448 A0B4110C */  jal        func_0046d280
    /* 1D144C 002D144C 00000000 */   nop
    /* 1D1450 002D1450 3E43023C */  lui        $2, (0x433E0000 >> 16)
    /* 1D1454 002D1454 00608244 */  mtc1       $2, $f12
    /* 1D1458 002D1458 7C0E048E */  lw         $4, 0xE7C($16)
    /* 1D145C 002D145C 40000524 */  addiu      $5, $0, 0x40
    /* 1D1460 002D1460 78820B0C */  jal        func_002e09e0
    /* 1D1464 002D1464 00000000 */   nop
    /* 1D1468 002D1468 3443023C */  lui        $2, (0x43340000 >> 16)
    /* 1D146C 002D146C 00A08244 */  mtc1       $2, $f20
    /* 1D1470 002D1470 7C0E048E */  lw         $4, 0xE7C($16)
    /* 1D1474 002D1474 38810B0C */  jal        func_002e04e0
    /* 1D1478 002D1478 00000000 */   nop
    /* 1D147C 002D147C 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1D1480 002D1480 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 1D1484 002D1484 00A08244 */  mtc1       $2, $f20
    /* 1D1488 002D1488 7C0E048E */  lw         $4, 0xE7C($16)
    /* 1D148C 002D148C 38810B0C */  jal        func_002e04e0
    /* 1D1490 002D1490 00000000 */   nop
    /* 1D1494 002D1494 300054E4 */  swc1       $f20, 0x30($2)
    /* 1D1498 002D1498 280F048E */  lw         $4, 0xF28($16)
    /* 1D149C 002D149C 06000524 */  addiu      $5, $0, 0x6
    /* 1D14A0 002D14A0 80B4110C */  jal        func_0046d200
    /* 1D14A4 002D14A4 00000000 */   nop
    /* 1D14A8 002D14A8 2D904000 */  daddu      $18, $2, $0
    /* 1D14AC 002D14AC 2D204002 */  daddu      $4, $18, $0
    /* 1D14B0 002D14B0 98AC110C */  jal        func_0046b260
    /* 1D14B4 002D14B4 00000000 */   nop
    /* 1D14B8 002D14B8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1D14BC 002D14BC 00000244 */  mfc1       $2, $f0
    /* 1D14C0 002D14C0 00000000 */  nop
    /* 1D14C4 002D14C4 3C8C0200 */  dsll32     $17, $2, 16
    /* 1D14C8 002D14C8 3F8C1100 */  dsra32     $17, $17, 16
    /* 1D14CC 002D14CC 7C0E048E */  lw         $4, 0xE7C($16)
    /* 1D14D0 002D14D0 38810B0C */  jal        func_002e04e0
    /* 1D14D4 002D14D4 00000000 */   nop
    /* 1D14D8 002D14D8 000151A4 */  sh         $17, 0x100($2)
    /* 1D14DC 002D14DC 7C0E048E */  lw         $4, 0xE7C($16)
    /* 1D14E0 002D14E0 38810B0C */  jal        func_002e04e0
    /* 1D14E4 002D14E4 00000000 */   nop
    /* 1D14E8 002D14E8 020140A4 */  sh         $0, 0x102($2)
    /* 1D14EC 002D14EC 2D204002 */  daddu      $4, $18, $0
    /* 1D14F0 002D14F0 A0B4110C */  jal        func_0046d280
    /* 1D14F4 002D14F4 00000000 */   nop
    /* 1D14F8 002D14F8 AAC2023C */  lui        $2, (0xC2AA0000 >> 16)
    /* 1D14FC 002D14FC 00608244 */  mtc1       $2, $f12
    /* 1D1500 002D1500 7C0E048E */  lw         $4, 0xE7C($16)
    /* 1D1504 002D1504 28858DC7 */  lwc1       $f13, -0x7AD8($28)
    /* 1D1508 002D1508 2D280000 */  daddu      $5, $0, $0
    /* 1D150C 002D150C 04000624 */  addiu      $6, $0, 0x4
    /* 1D1510 002D1510 02000724 */  addiu      $7, $0, 0x2
    /* 1D1514 002D1514 50820B0C */  jal        func_002e0940
    /* 1D1518 002D1518 00000000 */   nop
    /* 1D151C 002D151C 7C0E048E */  lw         $4, 0xE7C($16)
    /* 1D1520 002D1520 2D280000 */  daddu      $5, $0, $0
    /* 1D1524 002D1524 FF000624 */  addiu      $6, $0, 0xFF
    /* 1D1528 002D1528 2D380000 */  daddu      $7, $0, $0
    /* 1D152C 002D152C 04000824 */  addiu      $8, $0, 0x4
    /* 1D1530 002D1530 02000924 */  addiu      $9, $0, 0x2
    /* 1D1534 002D1534 98810B0C */  jal        func_002e0660
    /* 1D1538 002D1538 00000000 */   nop
    /* 1D153C 002D153C 2D208002 */  daddu      $4, $20, $0
    /* 1D1540 002D1540 8C740B0C */  jal        func_002dd230
    /* 1D1544 002D1544 00000000 */   nop
    /* 1D1548 002D1548 11000324 */  addiu      $3, $0, 0x11
    /* 1D154C 002D154C 000003A2 */  sb         $3, 0x0($16)
  .L002D1550:
    /* 1D1550 002D1550 140000A2 */  sb         $0, 0x14($16)
  .L002D1554:
    /* 1D1554 002D1554 B000BFDF */  ld         $31, 0xB0($29)
    /* 1D1558 002D1558 A000BE7B */  lq         $30, 0xA0($29)
    /* 1D155C 002D155C 9000B77B */  lq         $23, 0x90($29)
    /* 1D1560 002D1560 8000B67B */  lq         $22, 0x80($29)
    /* 1D1564 002D1564 7000B57B */  lq         $21, 0x70($29)
    /* 1D1568 002D1568 6000B47B */  lq         $20, 0x60($29)
    /* 1D156C 002D156C 5000B37B */  lq         $19, 0x50($29)
    /* 1D1570 002D1570 4000B27B */  lq         $18, 0x40($29)
    /* 1D1574 002D1574 3000B17B */  lq         $17, 0x30($29)
    /* 1D1578 002D1578 2000B07B */  lq         $16, 0x20($29)
    /* 1D157C 002D157C 1000B4C7 */  lwc1       $f20, 0x10($29)
    /* 1D1580 002D1580 2002BD27 */  addiu      $29, $29, 0x220
    /* 1D1584 002D1584 0800E003 */  jr         $31
    /* 1D1588 002D1588 00000000 */   nop
    /* 1D158C 002D158C 00000000 */  nop
.size func_002cdf80, 0x3610
