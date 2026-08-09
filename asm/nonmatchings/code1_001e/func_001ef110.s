.section .text
.set noat
.set noreorder
glabel func_001ef110
    /* EF110 001EF110 20FFBD27 */  addiu      $29, $29, -0xE0
    /* EF114 001EF114 4000BFFF */  sd         $31, 0x40($29)
    /* EF118 001EF118 3000B27F */  sq         $18, 0x30($29)
    /* EF11C 001EF11C 2000B17F */  sq         $17, 0x20($29)
    /* EF120 001EF120 1000B07F */  sq         $16, 0x10($29)
    /* EF124 001EF124 0800B6E7 */  swc1       $f22, 0x8($29)
    /* EF128 001EF128 0400B5E7 */  swc1       $f21, 0x4($29)
    /* EF12C 001EF12C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* EF130 001EF130 2D908000 */  daddu      $18, $4, $0
    /* EF134 001EF134 2D88C000 */  daddu      $17, $6, $0
    /* EF138 001EF138 000480A4 */  sh         $0, 0x400($4)
    /* EF13C 001EF13C C400A0AF */  sw         $0, 0xC4($29)
    /* EF140 001EF140 0000E0C4 */  lwc1       $f0, 0x0($7)
    /* EF144 001EF144 D000A0E7 */  swc1       $f0, 0xD0($29)
    /* EF148 001EF148 D400A0AF */  sw         $0, 0xD4($29)
    /* EF14C 001EF14C 0400E0C4 */  lwc1       $f0, 0x4($7)
    /* EF150 001EF150 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* EF154 001EF154 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* EF158 001EF158 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* EF15C 001EF15C 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* EF160 001EF160 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* EF164 001EF164 6000A427 */  addiu      $4, $29, 0x60
    /* EF168 001EF168 D000A527 */  addiu      $5, $29, 0xD0
    /* EF16C 001EF16C C000A627 */  addiu      $6, $29, 0xC0
    /* EF170 001EF170 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* EF174 001EF174 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* EF178 001EF178 E0F5060C */  jal        func_001bd780
    /* EF17C 001EF17C 00000000 */   nop
    /* EF180 001EF180 D000A1C7 */  lwc1       $f1, 0xD0($29)
    /* EF184 001EF184 C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* EF188 001EF188 01080046 */  sub.s      $f0, $f1, $f0
    /* EF18C 001EF18C B000A0E7 */  swc1       $f0, 0xB0($29)
    /* EF190 001EF190 D400A1C7 */  lwc1       $f1, 0xD4($29)
    /* EF194 001EF194 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* EF198 001EF198 01080046 */  sub.s      $f0, $f1, $f0
    /* EF19C 001EF19C B400A0E7 */  swc1       $f0, 0xB4($29)
    /* EF1A0 001EF1A0 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* EF1A4 001EF1A4 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* EF1A8 001EF1A8 01080046 */  sub.s      $f0, $f1, $f0
    /* EF1AC 001EF1AC B800A0E7 */  swc1       $f0, 0xB8($29)
    /* EF1B0 001EF1B0 B000A427 */  addiu      $4, $29, 0xB0
    /* EF1B4 001EF1B4 60900F0C */  jal        func_003e4180
    /* EF1B8 001EF1B8 00000000 */   nop
    /* EF1BC 001EF1BC 86050046 */  mov.s      $f22, $f0
    /* EF1C0 001EF1C0 000020C6 */  lwc1       $f0, 0x0($17)
    /* EF1C4 001EF1C4 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* EF1C8 001EF1C8 040020C6 */  lwc1       $f0, 0x4($17)
    /* EF1CC 001EF1CC C800A0E7 */  swc1       $f0, 0xC8($29)
    /* EF1D0 001EF1D0 5000A427 */  addiu      $4, $29, 0x50
    /* EF1D4 001EF1D4 D000A527 */  addiu      $5, $29, 0xD0
    /* EF1D8 001EF1D8 C000A627 */  addiu      $6, $29, 0xC0
    /* EF1DC 001EF1DC 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* EF1E0 001EF1E0 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* EF1E4 001EF1E4 E0F5060C */  jal        func_001bd780
    /* EF1E8 001EF1E8 00000000 */   nop
    /* EF1EC 001EF1EC D000A1C7 */  lwc1       $f1, 0xD0($29)
    /* EF1F0 001EF1F0 C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* EF1F4 001EF1F4 01080046 */  sub.s      $f0, $f1, $f0
    /* EF1F8 001EF1F8 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* EF1FC 001EF1FC D400A1C7 */  lwc1       $f1, 0xD4($29)
    /* EF200 001EF200 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* EF204 001EF204 01080046 */  sub.s      $f0, $f1, $f0
    /* EF208 001EF208 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* EF20C 001EF20C D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* EF210 001EF210 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* EF214 001EF214 01080046 */  sub.s      $f0, $f1, $f0
    /* EF218 001EF218 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* EF21C 001EF21C B000A427 */  addiu      $4, $29, 0xB0
    /* EF220 001EF220 60900F0C */  jal        func_003e4180
    /* EF224 001EF224 00000000 */   nop
    /* EF228 001EF228 06050046 */  mov.s      $f20, $f0
    /* EF22C 001EF22C 00A88044 */  mtc1       $0, $f21
    /* EF230 001EF230 6000A427 */  addiu      $4, $29, 0x60
    /* EF234 001EF234 5000A527 */  addiu      $5, $29, 0x50
    /* EF238 001EF238 8000A627 */  addiu      $6, $29, 0x80
    /* EF23C 001EF23C 1C730F0C */  jal        func_003dcc70
    /* EF240 001EF240 00000000 */   nop
    /* EF244 001EF244 2D800000 */  daddu      $16, $0, $0
    /* EF248 001EF248 01A51646 */  sub.s      $f20, $f20, $f22
    /* EF24C 001EF24C 7C000010 */  b          .L001EF440
    /* EF250 001EF250 00000000 */   nop
  .L001EF254:
    /* EF254 001EF254 00588044 */  mtc1       $0, $f11
    /* EF258 001EF258 00000000 */  nop
    /* EF25C 001EF25C 36A80B46 */  c.le.s     $f21, $f11
    /* EF260 001EF260 05000045 */  bc1f       .L001EF278
    /* EF264 001EF264 00000000 */   nop
    /* EF268 001EF268 6000A27B */  lq         $2, 0x60($29)
    /* EF26C 001EF26C 7000A27F */  sq         $2, 0x70($29)
    /* EF270 001EF270 51000010 */  b          .L001EF3B8
    /* EF274 001EF274 00000000 */   nop
  .L001EF278:
    /* EF278 001EF278 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* EF27C 001EF27C 00008244 */  mtc1       $2, $f0
    /* EF280 001EF280 00000000 */  nop
    /* EF284 001EF284 36001546 */  c.le.s     $f0, $f21
    /* EF288 001EF288 05000045 */  bc1f       .L001EF2A0
    /* EF28C 001EF28C 00000000 */   nop
    /* EF290 001EF290 5000A27B */  lq         $2, 0x50($29)
    /* EF294 001EF294 7000A27F */  sq         $2, 0x70($29)
    /* EF298 001EF298 47000010 */  b          .L001EF3B8
    /* EF29C 001EF29C 00000000 */   nop
  .L001EF2A0:
    /* EF2A0 001EF2A0 01001546 */  sub.s      $f0, $f0, $f21
    /* EF2A4 001EF2A4 86A90046 */  mov.s      $f6, $f21
    /* EF2A8 001EF2A8 A400A28F */  lw         $2, 0xA4($29)
    /* EF2AC 001EF2AC 26004014 */  bnez       $2, .L001EF348
    /* EF2B0 001EF2B0 00000000 */   nop
    /* EF2B4 001EF2B4 A000AAC7 */  lwc1       $f10, 0xA0($29)
    /* EF2B8 001EF2B8 02010A46 */  mul.s      $f4, $f0, $f10
    /* EF2BC 001EF2BC C2200446 */  mul.s      $f3, $f4, $f4
    /* EF2C0 001EF2C0 408389C7 */  lwc1       $f9, -0x7CC0($28)
    /* EF2C4 001EF2C4 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* EF2C8 001EF2C8 18580846 */  adda.s     $f11, $f8
    /* EF2CC 001EF2CC 1C480346 */  madd.s     $f0, $f9, $f3
    /* EF2D0 001EF2D0 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* EF2D4 001EF2D4 18580746 */  adda.s     $f11, $f7
    /* EF2D8 001EF2D8 1C180046 */  madd.s     $f0, $f3, $f0
    /* EF2DC 001EF2DC 448386C7 */  lwc1       $f6, -0x7CBC($28)
    /* EF2E0 001EF2E0 18580646 */  adda.s     $f11, $f6
    /* EF2E4 001EF2E4 1C180046 */  madd.s     $f0, $f3, $f0
    /* EF2E8 001EF2E8 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* EF2EC 001EF2EC 18580546 */  adda.s     $f11, $f5
    /* EF2F0 001EF2F0 1C180046 */  madd.s     $f0, $f3, $f0
    /* EF2F4 001EF2F4 488382C7 */  lwc1       $f2, -0x7CB8($28)
    /* EF2F8 001EF2F8 18580246 */  adda.s     $f11, $f2
    /* EF2FC 001EF2FC 5C180046 */  madd.s     $f1, $f3, $f0
    /* EF300 001EF300 02180446 */  mul.s      $f0, $f3, $f4
    /* EF304 001EF304 18580446 */  adda.s     $f11, $f4
    /* EF308 001EF308 1C000146 */  madd.s     $f0, $f0, $f1
    /* EF30C 001EF30C 02A90A46 */  mul.s      $f4, $f21, $f10
    /* EF310 001EF310 C2200446 */  mul.s      $f3, $f4, $f4
    /* EF314 001EF314 18580846 */  adda.s     $f11, $f8
    /* EF318 001EF318 5C480346 */  madd.s     $f1, $f9, $f3
    /* EF31C 001EF31C 18580746 */  adda.s     $f11, $f7
    /* EF320 001EF320 5C180146 */  madd.s     $f1, $f3, $f1
    /* EF324 001EF324 18580646 */  adda.s     $f11, $f6
    /* EF328 001EF328 5C180146 */  madd.s     $f1, $f3, $f1
    /* EF32C 001EF32C 18580546 */  adda.s     $f11, $f5
    /* EF330 001EF330 5C180146 */  madd.s     $f1, $f3, $f1
    /* EF334 001EF334 18580246 */  adda.s     $f11, $f2
    /* EF338 001EF338 9C180146 */  madd.s     $f2, $f3, $f1
    /* EF33C 001EF33C 42180446 */  mul.s      $f1, $f3, $f4
    /* EF340 001EF340 18580446 */  adda.s     $f11, $f4
    /* EF344 001EF344 9C090246 */  madd.s     $f6, $f1, $f2
  .L001EF348:
    /* EF348 001EF348 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* EF34C 001EF34C 42090046 */  mul.s      $f5, $f1, $f0
    /* EF350 001EF350 7000A5E7 */  swc1       $f5, 0x70($29)
    /* EF354 001EF354 8400A1C7 */  lwc1       $f1, 0x84($29)
    /* EF358 001EF358 02090046 */  mul.s      $f4, $f1, $f0
    /* EF35C 001EF35C 7400A4E7 */  swc1       $f4, 0x74($29)
    /* EF360 001EF360 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* EF364 001EF364 C2080046 */  mul.s      $f3, $f1, $f0
    /* EF368 001EF368 7800A3E7 */  swc1       $f3, 0x78($29)
    /* EF36C 001EF36C 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* EF370 001EF370 00108044 */  mtc1       $0, $f2
    /* EF374 001EF374 00000000 */  nop
    /* EF378 001EF378 18100546 */  adda.s     $f2, $f5
    /* EF37C 001EF37C 5C080646 */  madd.s     $f1, $f1, $f6
    /* EF380 001EF380 7000A1E7 */  swc1       $f1, 0x70($29)
    /* EF384 001EF384 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* EF388 001EF388 18100446 */  adda.s     $f2, $f4
    /* EF38C 001EF38C 5C080646 */  madd.s     $f1, $f1, $f6
    /* EF390 001EF390 7400A1E7 */  swc1       $f1, 0x74($29)
    /* EF394 001EF394 9800A1C7 */  lwc1       $f1, 0x98($29)
    /* EF398 001EF398 18100346 */  adda.s     $f2, $f3
    /* EF39C 001EF39C 5C080646 */  madd.s     $f1, $f1, $f6
    /* EF3A0 001EF3A0 7800A1E7 */  swc1       $f1, 0x78($29)
    /* EF3A4 001EF3A4 8C00A2C7 */  lwc1       $f2, 0x8C($29)
    /* EF3A8 001EF3A8 9C00A1C7 */  lwc1       $f1, 0x9C($29)
    /* EF3AC 001EF3AC 1A080646 */  mula.s     $f1, $f6
    /* EF3B0 001EF3B0 1C100046 */  madd.s     $f0, $f2, $f0
    /* EF3B4 001EF3B4 7C00A0E7 */  swc1       $f0, 0x7C($29)
  .L001EF3B8:
    /* EF3B8 001EF3B8 B000A427 */  addiu      $4, $29, 0xB0
    /* EF3BC 001EF3BC 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* EF3C0 001EF3C0 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* EF3C4 001EF3C4 01000624 */  addiu      $6, $0, 0x1
    /* EF3C8 001EF3C8 7000A727 */  addiu      $7, $29, 0x70
    /* EF3CC 001EF3CC D0720F0C */  jal        func_003dcb40
    /* EF3D0 001EF3D0 00000000 */   nop
    /* EF3D4 001EF3D4 00008044 */  mtc1       $0, $f0
    /* EF3D8 001EF3D8 00000000 */  nop
    /* EF3DC 001EF3DC 18001646 */  adda.s     $f0, $f22
    /* EF3E0 001EF3E0 9CA81446 */  madd.s     $f2, $f21, $f20
    /* EF3E4 001EF3E4 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* EF3E8 001EF3E8 42000246 */  mul.s      $f1, $f0, $f2
    /* EF3EC 001EF3EC B000A1E7 */  swc1       $f1, 0xB0($29)
    /* EF3F0 001EF3F0 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* EF3F4 001EF3F4 02000246 */  mul.s      $f0, $f0, $f2
    /* EF3F8 001EF3F8 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* EF3FC 001EF3FC B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* EF400 001EF400 02000246 */  mul.s      $f0, $f0, $f2
    /* EF404 001EF404 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* EF408 001EF408 C0101000 */  sll        $2, $16, 3
    /* EF40C 001EF40C 21104202 */  addu       $2, $18, $2
    /* EF410 001EF410 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* EF414 001EF414 00000146 */  add.s      $f0, $f0, $f1
    /* EF418 001EF418 000040E4 */  swc1       $f0, 0x0($2)
    /* EF41C 001EF41C D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* EF420 001EF420 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* EF424 001EF424 00080046 */  add.s      $f0, $f1, $f0
    /* EF428 001EF428 040040E4 */  swc1       $f0, 0x4($2)
    /* EF42C 001EF42C 003E023C */  lui        $2, (0x3E000000 >> 16)
    /* EF430 001EF430 00008244 */  mtc1       $2, $f0
    /* EF434 001EF434 00000000 */  nop
    /* EF438 001EF438 40AD0046 */  add.s      $f21, $f21, $f0
    /* EF43C 001EF43C 01001026 */  addiu      $16, $16, 0x1
  .L001EF440:
    /* EF440 001EF440 0700022A */  slti       $2, $16, 0x7
    /* EF444 001EF444 83FF4014 */  bnez       $2, .L001EF254
    /* EF448 001EF448 00000000 */   nop
    /* EF44C 001EF44C 000021C6 */  lwc1       $f1, 0x0($17)
    /* EF450 001EF450 040020C6 */  lwc1       $f0, 0x4($17)
    /* EF454 001EF454 380041E6 */  swc1       $f1, 0x38($18)
    /* EF458 001EF458 3C0040E6 */  swc1       $f0, 0x3C($18)
    /* EF45C 001EF45C 08000224 */  addiu      $2, $0, 0x8
    /* EF460 001EF460 000442A6 */  sh         $2, 0x400($18)
    /* EF464 001EF464 02000224 */  addiu      $2, $0, 0x2
    /* EF468 001EF468 040442A2 */  sb         $2, 0x404($18)
    /* EF46C 001EF46C 01000224 */  addiu      $2, $0, 0x1
    /* EF470 001EF470 4000BFDF */  ld         $31, 0x40($29)
    /* EF474 001EF474 3000B27B */  lq         $18, 0x30($29)
    /* EF478 001EF478 2000B17B */  lq         $17, 0x20($29)
    /* EF47C 001EF47C 1000B07B */  lq         $16, 0x10($29)
    /* EF480 001EF480 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* EF484 001EF484 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* EF488 001EF488 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* EF48C 001EF48C E000BD27 */  addiu      $29, $29, 0xE0
    /* EF490 001EF490 0800E003 */  jr         $31
    /* EF494 001EF494 00000000 */   nop
    /* EF498 001EF498 00000000 */  nop
    /* EF49C 001EF49C 00000000 */  nop
.size func_001ef110, 0x390
