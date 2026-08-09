.section .text
.set noat
.set noreorder
glabel func_001cc0a0
    /* CC0A0 001CC0A0 00FFBD27 */  addiu      $29, $29, -0x100
    /* CC0A4 001CC0A4 5000BFFF */  sd         $31, 0x50($29)
    /* CC0A8 001CC0A8 4000B37F */  sq         $19, 0x40($29)
    /* CC0AC 001CC0AC 3000B27F */  sq         $18, 0x30($29)
    /* CC0B0 001CC0B0 2000B17F */  sq         $17, 0x20($29)
    /* CC0B4 001CC0B4 1000B07F */  sq         $16, 0x10($29)
    /* CC0B8 001CC0B8 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CC0BC 001CC0BC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CC0C0 001CC0C0 2D908000 */  daddu      $18, $4, $0
    /* CC0C4 001CC0C4 E000828C */  lw         $2, 0xE0($4)
    /* CC0C8 001CC0C8 3000518C */  lw         $17, 0x30($2)
    /* CC0CC 001CC0CC A2003092 */  lbu        $16, 0xA2($17)
    /* CC0D0 001CC0D0 3800428C */  lw         $2, 0x38($2)
    /* CC0D4 001CC0D4 3000538C */  lw         $19, 0x30($2)
    /* CC0D8 001CC0D8 900061C6 */  lwc1       $f1, 0x90($19)
    /* CC0DC 001CC0DC 2C0060C6 */  lwc1       $f0, 0x2C($19)
    /* CC0E0 001CC0E0 420D0046 */  mul.s      $f21, $f1, $f0
    /* CC0E4 001CC0E4 2D206002 */  daddu      $4, $19, $0
    /* CC0E8 001CC0E8 F000A527 */  addiu      $5, $29, 0xF0
    /* CC0EC 001CC0EC 1456060C */  jal        func_00195850
    /* CC0F0 001CC0F0 00000000 */   nop
    /* CC0F4 001CC0F4 2D202002 */  daddu      $4, $17, $0
    /* CC0F8 001CC0F8 E000A527 */  addiu      $5, $29, 0xE0
    /* CC0FC 001CC0FC 1456060C */  jal        func_00195850
    /* CC100 001CC100 00000000 */   nop
    /* CC104 001CC104 F400A5C7 */  lwc1       $f5, 0xF4($29)
    /* CC108 001CC108 E400A4C7 */  lwc1       $f4, 0xE4($29)
    /* CC10C 001CC10C 36280446 */  c.le.s     $f5, $f4
    /* CC110 001CC110 13000145 */  bc1t       .L001CC160
    /* CC114 001CC114 00000000 */   nop
    /* CC118 001CC118 8C0061C6 */  lwc1       $f1, 0x8C($19)
    /* CC11C 001CC11C 2C0060C6 */  lwc1       $f0, 0x2C($19)
    /* CC120 001CC120 42080046 */  mul.s      $f1, $f1, $f0
    /* CC124 001CC124 188180C7 */  lwc1       $f0, -0x7EE8($28)
    /* CC128 001CC128 00108044 */  mtc1       $0, $f2
    /* CC12C 001CC12C 00000000 */  nop
    /* CC130 001CC130 18100546 */  adda.s     $f2, $f5
    /* CC134 001CC134 1D000146 */  msub.s     $f0, $f0, $f1
    /* CC138 001CC138 F400A0E7 */  swc1       $f0, 0xF4($29)
    /* CC13C 001CC13C 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* CC140 001CC140 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CC144 001CC144 42080046 */  mul.s      $f1, $f1, $f0
    /* CC148 001CC148 888180C7 */  lwc1       $f0, -0x7E78($28)
    /* CC14C 001CC14C 18100446 */  adda.s     $f2, $f4
    /* CC150 001CC150 1C000146 */  madd.s     $f0, $f0, $f1
    /* CC154 001CC154 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* CC158 001CC158 10000010 */  b          .L001CC19C
    /* CC15C 001CC15C 00000000 */   nop
  .L001CC160:
    /* CC160 001CC160 8C0061C6 */  lwc1       $f1, 0x8C($19)
    /* CC164 001CC164 2C0060C6 */  lwc1       $f0, 0x2C($19)
    /* CC168 001CC168 02080046 */  mul.s      $f0, $f1, $f0
    /* CC16C 001CC16C 188183C7 */  lwc1       $f3, -0x7EE8($28)
    /* CC170 001CC170 00108044 */  mtc1       $0, $f2
    /* CC174 001CC174 00000000 */  nop
    /* CC178 001CC178 18100546 */  adda.s     $f2, $f5
    /* CC17C 001CC17C 1C180046 */  madd.s     $f0, $f3, $f0
    /* CC180 001CC180 F400A0E7 */  swc1       $f0, 0xF4($29)
    /* CC184 001CC184 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* CC188 001CC188 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CC18C 001CC18C 02080046 */  mul.s      $f0, $f1, $f0
    /* CC190 001CC190 18100446 */  adda.s     $f2, $f4
    /* CC194 001CC194 1D180046 */  msub.s     $f0, $f3, $f0
    /* CC198 001CC198 E400A0E7 */  swc1       $f0, 0xE4($29)
  .L001CC19C:
    /* CC19C 001CC19C F400A1C7 */  lwc1       $f1, 0xF4($29)
    /* CC1A0 001CC1A0 8242023C */  lui        $2, (0x42820000 >> 16)
    /* CC1A4 001CC1A4 00008244 */  mtc1       $2, $f0
    /* CC1A8 001CC1A8 00000000 */  nop
    /* CC1AC 001CC1AC 34080046 */  c.lt.s     $f1, $f0
    /* CC1B0 001CC1B0 02000045 */  bc1f       .L001CC1BC
    /* CC1B4 001CC1B4 00000000 */   nop
    /* CC1B8 001CC1B8 F400A0E7 */  swc1       $f0, 0xF4($29)
  .L001CC1BC:
    /* CC1BC 001CC1BC F000A7C7 */  lwc1       $f7, 0xF0($29)
    /* CC1C0 001CC1C0 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* CC1C4 001CC1C4 81010746 */  sub.s      $f6, $f0, $f7
    /* CC1C8 001CC1C8 B000A6E7 */  swc1       $f6, 0xB0($29)
    /* CC1CC 001CC1CC F400A5C7 */  lwc1       $f5, 0xF4($29)
    /* CC1D0 001CC1D0 E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* CC1D4 001CC1D4 81000546 */  sub.s      $f2, $f0, $f5
    /* CC1D8 001CC1D8 B400A2E7 */  swc1       $f2, 0xB4($29)
    /* CC1DC 001CC1DC F800A4C7 */  lwc1       $f4, 0xF8($29)
    /* CC1E0 001CC1E0 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* CC1E4 001CC1E4 C1000446 */  sub.s      $f3, $f0, $f4
    /* CC1E8 001CC1E8 B800A3E7 */  swc1       $f3, 0xB8($29)
    /* CC1EC 001CC1EC 3C8181C7 */  lwc1       $f1, -0x7EC4($28)
    /* CC1F0 001CC1F0 02300146 */  mul.s      $f0, $f6, $f1
    /* CC1F4 001CC1F4 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* CC1F8 001CC1F8 82100146 */  mul.s      $f2, $f2, $f1
    /* CC1FC 001CC1FC B400A2E7 */  swc1       $f2, 0xB4($29)
    /* CC200 001CC200 42180146 */  mul.s      $f1, $f3, $f1
    /* CC204 001CC204 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* CC208 001CC208 00380046 */  add.s      $f0, $f7, $f0
    /* CC20C 001CC20C C000A0E7 */  swc1       $f0, 0xC0($29)
    /* CC210 001CC210 00280246 */  add.s      $f0, $f5, $f2
    /* CC214 001CC214 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* CC218 001CC218 00200146 */  add.s      $f0, $f4, $f1
    /* CC21C 001CC21C C800A0E7 */  swc1       $f0, 0xC8($29)
    /* CC220 001CC220 9C0040C6 */  lwc1       $f0, 0x9C($18)
    /* CC224 001CC224 41380046 */  sub.s      $f1, $f7, $f0
    /* CC228 001CC228 B000A1E7 */  swc1       $f1, 0xB0($29)
    /* CC22C 001CC22C A00040C6 */  lwc1       $f0, 0xA0($18)
    /* CC230 001CC230 01280046 */  sub.s      $f0, $f5, $f0
    /* CC234 001CC234 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* CC238 001CC238 A40040C6 */  lwc1       $f0, 0xA4($18)
    /* CC23C 001CC23C 01200046 */  sub.s      $f0, $f4, $f0
    /* CC240 001CC240 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* CC244 001CC244 9800A1E7 */  swc1       $f1, 0x98($29)
    /* CC248 001CC248 9C00A0E7 */  swc1       $f0, 0x9C($29)
    /* CC24C 001CC24C 9800A427 */  addiu      $4, $29, 0x98
    /* CC250 001CC250 2D288000 */  daddu      $5, $4, $0
    /* CC254 001CC254 78900F0C */  jal        func_003e41e0
    /* CC258 001CC258 00000000 */   nop
    /* CC25C 001CC25C B000A427 */  addiu      $4, $29, 0xB0
    /* CC260 001CC260 6100053C */  lui        $5, %hi(D_0060A0D0)
    /* CC264 001CC264 D0A0A524 */  addiu      $5, $5, %lo(D_0060A0D0)
    /* CC268 001CC268 01000624 */  addiu      $6, $0, 0x1
    /* CC26C 001CC26C 1C006726 */  addiu      $7, $19, 0x1C
    /* CC270 001CC270 D0720F0C */  jal        func_003dcb40
    /* CC274 001CC274 00000000 */   nop
    /* CC278 001CC278 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CC27C 001CC27C 9000A0E7 */  swc1       $f0, 0x90($29)
    /* CC280 001CC280 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CC284 001CC284 9400A0E7 */  swc1       $f0, 0x94($29)
    /* CC288 001CC288 9000A427 */  addiu      $4, $29, 0x90
    /* CC28C 001CC28C 2D288000 */  daddu      $5, $4, $0
    /* CC290 001CC290 78900F0C */  jal        func_003e41e0
    /* CC294 001CC294 00000000 */   nop
    /* CC298 001CC298 9000A3C7 */  lwc1       $f3, 0x90($29)
    /* CC29C 001CC29C 9800A2C7 */  lwc1       $f2, 0x98($29)
    /* CC2A0 001CC2A0 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* CC2A4 001CC2A4 9C00A0C7 */  lwc1       $f0, 0x9C($29)
    /* CC2A8 001CC2A8 1A080046 */  mula.s     $f1, $f0
    /* CC2AC 001CC2AC 00208044 */  mtc1       $0, $f4
    /* CC2B0 001CC2B0 5C190246 */  madd.s     $f5, $f3, $f2
    /* CC2B4 001CC2B4 FFFF1032 */  andi       $16, $16, 0xFFFF
    /* CC2B8 001CC2B8 07000016 */  bnez       $16, .L001CC2D8
    /* CC2BC 001CC2BC 00000000 */   nop
    /* CC2C0 001CC2C0 F000A2DF */  ld         $2, 0xF0($29)
    /* CC2C4 001CC2C4 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CC2C8 001CC2C8 D000A2FF */  sd         $2, 0xD0($29)
    /* CC2CC 001CC2CC D800A0E7 */  swc1       $f0, 0xD8($29)
    /* CC2D0 001CC2D0 25000010 */  b          .L001CC368
    /* CC2D4 001CC2D4 00000000 */   nop
  .L001CC2D8:
    /* CC2D8 001CC2D8 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* CC2DC 001CC2DC 00008244 */  mtc1       $2, $f0
    /* CC2E0 001CC2E0 00000000 */  nop
    /* CC2E4 001CC2E4 42001546 */  mul.s      $f1, $f0, $f21
    /* CC2E8 001CC2E8 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CC2EC 001CC2EC C2000146 */  mul.s      $f3, $f0, $f1
    /* CC2F0 001CC2F0 B000A3E7 */  swc1       $f3, 0xB0($29)
    /* CC2F4 001CC2F4 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CC2F8 001CC2F8 82000146 */  mul.s      $f2, $f0, $f1
    /* CC2FC 001CC2FC B400A2E7 */  swc1       $f2, 0xB4($29)
    /* CC300 001CC300 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CC304 001CC304 42000146 */  mul.s      $f1, $f0, $f1
    /* CC308 001CC308 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* CC30C 001CC30C 34280446 */  c.lt.s     $f5, $f4
    /* CC310 001CC310 0C000045 */  bc1f       .L001CC344
    /* CC314 001CC314 00000000 */   nop
    /* CC318 001CC318 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CC31C 001CC31C 00000346 */  add.s      $f0, $f0, $f3
    /* CC320 001CC320 D000A0E7 */  swc1       $f0, 0xD0($29)
    /* CC324 001CC324 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CC328 001CC328 00000246 */  add.s      $f0, $f0, $f2
    /* CC32C 001CC32C D400A0E7 */  swc1       $f0, 0xD4($29)
    /* CC330 001CC330 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CC334 001CC334 00000146 */  add.s      $f0, $f0, $f1
    /* CC338 001CC338 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* CC33C 001CC33C 0A000010 */  b          .L001CC368
    /* CC340 001CC340 00000000 */   nop
  .L001CC344:
    /* CC344 001CC344 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CC348 001CC348 01000346 */  sub.s      $f0, $f0, $f3
    /* CC34C 001CC34C D000A0E7 */  swc1       $f0, 0xD0($29)
    /* CC350 001CC350 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CC354 001CC354 01000246 */  sub.s      $f0, $f0, $f2
    /* CC358 001CC358 D400A0E7 */  swc1       $f0, 0xD4($29)
    /* CC35C 001CC35C F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CC360 001CC360 01000146 */  sub.s      $f0, $f0, $f1
    /* CC364 001CC364 D800A0E7 */  swc1       $f0, 0xD8($29)
  .L001CC368:
    /* CC368 001CC368 6C00A427 */  addiu      $4, $29, 0x6C
    /* CC36C 001CC36C D000A527 */  addiu      $5, $29, 0xD0
    /* CC370 001CC370 C000A627 */  addiu      $6, $29, 0xC0
    /* CC374 001CC374 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CC378 001CC378 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CC37C 001CC37C E0F5060C */  jal        func_001bd780
    /* CC380 001CC380 00000000 */   nop
    /* CC384 001CC384 C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* CC388 001CC388 8000A0E7 */  swc1       $f0, 0x80($29)
    /* CC38C 001CC38C C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* CC390 001CC390 8400A0E7 */  swc1       $f0, 0x84($29)
    /* CC394 001CC394 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CC398 001CC398 8800A0E7 */  swc1       $f0, 0x88($29)
    /* CC39C 001CC39C D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CC3A0 001CC3A0 8C00A0E7 */  swc1       $f0, 0x8C($29)
    /* CC3A4 001CC3A4 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CC3A8 001CC3A8 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* CC3AC 001CC3AC F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CC3B0 001CC3B0 AC00A0E7 */  swc1       $f0, 0xAC($29)
    /* CC3B4 001CC3B4 8000A427 */  addiu      $4, $29, 0x80
    /* CC3B8 001CC3B8 8800A527 */  addiu      $5, $29, 0x88
    /* CC3BC 001CC3BC A800A627 */  addiu      $6, $29, 0xA8
    /* CC3C0 001CC3C0 2D380000 */  daddu      $7, $0, $0
    /* CC3C4 001CC3C4 F4B0070C */  jal        func_001ec3d0
    /* CC3C8 001CC3C8 00000000 */   nop
    /* CC3CC 001CC3CC 06050046 */  mov.s      $f20, $f0
    /* CC3D0 001CC3D0 0D000016 */  bnez       $16, .L001CC408
    /* CC3D4 001CC3D4 00000000 */   nop
    /* CC3D8 001CC3D8 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* CC3DC 001CC3DC 00008244 */  mtc1       $2, $f0
    /* CC3E0 001CC3E0 00000000 */  nop
    /* CC3E4 001CC3E4 36A80046 */  c.le.s     $f21, $f0
    /* CC3E8 001CC3E8 03000145 */  bc1t       .L001CC3F8
    /* CC3EC 001CC3EC 00000000 */   nop
    /* CC3F0 001CC3F0 02000010 */  b          .L001CC3FC
    /* CC3F4 001CC3F4 00000000 */   nop
  .L001CC3F8:
    /* CC3F8 001CC3F8 46050046 */  mov.s      $f21, $f0
  .L001CC3FC:
    /* CC3FC 001CC3FC 00A51546 */  add.s      $f20, $f20, $f21
    /* CC400 001CC400 0B000010 */  b          .L001CC430
    /* CC404 001CC404 00000000 */   nop
  .L001CC408:
    /* CC408 001CC408 FA42023C */  lui        $2, (0x42FA0000 >> 16)
    /* CC40C 001CC40C 00008244 */  mtc1       $2, $f0
    /* CC410 001CC410 00000000 */  nop
    /* CC414 001CC414 36A80046 */  c.le.s     $f21, $f0
    /* CC418 001CC418 03000145 */  bc1t       .L001CC428
    /* CC41C 001CC41C 00000000 */   nop
    /* CC420 001CC420 02000010 */  b          .L001CC42C
    /* CC424 001CC424 00000000 */   nop
  .L001CC428:
    /* CC428 001CC428 46050046 */  mov.s      $f21, $f0
  .L001CC42C:
    /* CC42C 001CC42C 00A51546 */  add.s      $f20, $f20, $f21
  .L001CC430:
    /* CC430 001CC430 2043023C */  lui        $2, (0x43200000 >> 16)
    /* CC434 001CC434 00008244 */  mtc1       $2, $f0
    /* CC438 001CC438 00000000 */  nop
    /* CC43C 001CC43C 34A00046 */  c.lt.s     $f20, $f0
    /* CC440 001CC440 02000045 */  bc1f       .L001CC44C
    /* CC444 001CC444 00000000 */   nop
    /* CC448 001CC448 06050046 */  mov.s      $f20, $f0
  .L001CC44C:
    /* CC44C 001CC44C C000A1C7 */  lwc1       $f1, 0xC0($29)
    /* CC450 001CC450 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CC454 001CC454 01080046 */  sub.s      $f0, $f1, $f0
    /* CC458 001CC458 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* CC45C 001CC45C C400A1C7 */  lwc1       $f1, 0xC4($29)
    /* CC460 001CC460 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CC464 001CC464 01080046 */  sub.s      $f0, $f1, $f0
    /* CC468 001CC468 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* CC46C 001CC46C C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* CC470 001CC470 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CC474 001CC474 01080046 */  sub.s      $f0, $f1, $f0
    /* CC478 001CC478 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* CC47C 001CC47C B000A427 */  addiu      $4, $29, 0xB0
    /* CC480 001CC480 60900F0C */  jal        func_003e4180
    /* CC484 001CC484 00000000 */   nop
    /* CC488 001CC488 46050046 */  mov.s      $f21, $f0
    /* CC48C 001CC48C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CC490 001CC490 00088244 */  mtc1       $2, $f1
    /* CC494 001CC494 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* CC498 001CC498 42080046 */  mul.s      $f1, $f1, $f0
    /* CC49C 001CC49C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CC4A0 001CC4A0 02030146 */  mul.s      $f12, $f0, $f1
    /* CC4A4 001CC4A4 1A2E110C */  jal        func_0044b868
    /* CC4A8 001CC4A8 00000000 */   nop
    /* CC4AC 001CC4AC 00000000 */  nop
    /* CC4B0 001CC4B0 00000000 */  nop
    /* CC4B4 001CC4B4 03A00046 */  div.s      $f0, $f20, $f0
    /* CC4B8 001CC4B8 00AD0046 */  add.s      $f20, $f21, $f0
    /* CC4BC 001CC4BC 00008044 */  mtc1       $0, $f0
    /* CC4C0 001CC4C0 00000000 */  nop
    /* CC4C4 001CC4C4 36A00046 */  c.le.s     $f20, $f0
    /* CC4C8 001CC4C8 03000145 */  bc1t       .L001CC4D8
    /* CC4CC 001CC4CC 00000000 */   nop
    /* CC4D0 001CC4D0 02000010 */  b          .L001CC4DC
    /* CC4D4 001CC4D4 00000000 */   nop
  .L001CC4D8:
    /* CC4D8 001CC4D8 06050046 */  mov.s      $f20, $f0
  .L001CC4DC:
    /* CC4DC 001CC4DC B000A427 */  addiu      $4, $29, 0xB0
    /* CC4E0 001CC4E0 6100053C */  lui        $5, %hi(D_0060A100)
    /* CC4E4 001CC4E4 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CC4E8 001CC4E8 01000624 */  addiu      $6, $0, 0x1
    /* CC4EC 001CC4EC 6C00A727 */  addiu      $7, $29, 0x6C
    /* CC4F0 001CC4F0 D0720F0C */  jal        func_003dcb40
    /* CC4F4 001CC4F4 00000000 */   nop
    /* CC4F8 001CC4F8 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CC4FC 001CC4FC C2001446 */  mul.s      $f3, $f0, $f20
    /* CC500 001CC500 B000A3E7 */  swc1       $f3, 0xB0($29)
    /* CC504 001CC504 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CC508 001CC508 42001446 */  mul.s      $f1, $f0, $f20
    /* CC50C 001CC50C B400A1E7 */  swc1       $f1, 0xB4($29)
    /* CC510 001CC510 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CC514 001CC514 82001446 */  mul.s      $f2, $f0, $f20
    /* CC518 001CC518 B800A2E7 */  swc1       $f2, 0xB8($29)
    /* CC51C 001CC51C C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* CC520 001CC520 00000346 */  add.s      $f0, $f0, $f3
    /* CC524 001CC524 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CC528 001CC528 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* CC52C 001CC52C 40000146 */  add.s      $f1, $f0, $f1
    /* CC530 001CC530 6400A1E7 */  swc1       $f1, 0x64($29)
    /* CC534 001CC534 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* CC538 001CC538 00000246 */  add.s      $f0, $f0, $f2
    /* CC53C 001CC53C 6800A0E7 */  swc1       $f0, 0x68($29)
    /* CC540 001CC540 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CC544 001CC544 00008244 */  mtc1       $2, $f0
    /* CC548 001CC548 00000000 */  nop
    /* CC54C 001CC54C 34080046 */  c.lt.s     $f1, $f0
    /* CC550 001CC550 02000045 */  bc1f       .L001CC55C
    /* CC554 001CC554 00000000 */   nop
    /* CC558 001CC558 6400A0E7 */  swc1       $f0, 0x64($29)
  .L001CC55C:
    /* CC55C 001CC55C C843023C */  lui        $2, (0x43C80000 >> 16)
    /* CC560 001CC560 00608244 */  mtc1       $2, $f12
    /* CC564 001CC564 E000448E */  lw         $4, 0xE0($18)
    /* CC568 001CC568 6000A527 */  addiu      $5, $29, 0x60
    /* CC56C 001CC56C C000A627 */  addiu      $6, $29, 0xC0
    /* CC570 001CC570 03000724 */  addiu      $7, $0, 0x3
    /* CC574 001CC574 50F3060C */  jal        func_001bcd40
    /* CC578 001CC578 00000000 */   nop
    /* CC57C 001CC57C 2D204002 */  daddu      $4, $18, $0
    /* CC580 001CC580 6000A527 */  addiu      $5, $29, 0x60
    /* CC584 001CC584 C0EA060C */  jal        func_001bab00
    /* CC588 001CC588 00000000 */   nop
    /* CC58C 001CC58C 5000BFDF */  ld         $31, 0x50($29)
    /* CC590 001CC590 4000B37B */  lq         $19, 0x40($29)
    /* CC594 001CC594 3000B27B */  lq         $18, 0x30($29)
    /* CC598 001CC598 2000B17B */  lq         $17, 0x20($29)
    /* CC59C 001CC59C 1000B07B */  lq         $16, 0x10($29)
    /* CC5A0 001CC5A0 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CC5A4 001CC5A4 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CC5A8 001CC5A8 0001BD27 */  addiu      $29, $29, 0x100
    /* CC5AC 001CC5AC 0800E003 */  jr         $31
    /* CC5B0 001CC5B0 00000000 */   nop
    /* CC5B4 001CC5B4 00000000 */  nop
    /* CC5B8 001CC5B8 00000000 */  nop
    /* CC5BC 001CC5BC 00000000 */  nop
.size func_001cc0a0, 0x520
