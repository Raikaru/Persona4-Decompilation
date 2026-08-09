.section .text
.set noat
.set noreorder
glabel func_004ae0a0
    /* 3AE0A0 004AE0A0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3AE0A4 004AE0A4 3000BFFF */  sd         $31, 0x30($29)
    /* 3AE0A8 004AE0A8 2000B17F */  sq         $17, 0x20($29)
    /* 3AE0AC 004AE0AC 1000B07F */  sq         $16, 0x10($29)
    /* 3AE0B0 004AE0B0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3AE0B4 004AE0B4 2D888000 */  daddu      $17, $4, $0
    /* 3AE0B8 004AE0B8 2D80A000 */  daddu      $16, $5, $0
    /* 3AE0BC 004AE0BC 10008290 */  lbu        $2, 0x10($4)
    /* 3AE0C0 004AE0C0 09004014 */  bnez       $2, .L004AE0E8
    /* 3AE0C4 004AE0C4 00000000 */   nop
    /* 3AE0C8 004AE0C8 140020C6 */  lwc1       $f0, 0x14($17)
    /* 3AE0CC 004AE0CC 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 3AE0D0 004AE0D0 180020C6 */  lwc1       $f0, 0x18($17)
    /* 3AE0D4 004AE0D4 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 3AE0D8 004AE0D8 1C0020C6 */  lwc1       $f0, 0x1C($17)
    /* 3AE0DC 004AE0DC 4800A0E7 */  swc1       $f0, 0x48($29)
    /* 3AE0E0 004AE0E0 25000010 */  b          .L004AE178
    /* 3AE0E4 004AE0E4 00000000 */   nop
  .L004AE0E8:
    /* 3AE0E8 004AE0E8 2D200000 */  daddu      $4, $0, $0
    /* 3AE0EC 004AE0EC 2CF4120C */  jal        func_004bd0b0
    /* 3AE0F0 004AE0F0 00000000 */   nop
    /* 3AE0F4 004AE0F4 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3AE0F8 004AE0F8 00088244 */  mtc1       $2, $f1
    /* 3AE0FC 004AE0FC 00000000 */  nop
    /* 3AE100 004AE100 41000146 */  sub.s      $f1, $f0, $f1
    /* 3AE104 004AE104 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 3AE108 004AE108 00008244 */  mtc1       $2, $f0
    /* 3AE10C 004AE10C 00000000 */  nop
    /* 3AE110 004AE110 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AE114 004AE114 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 3AE118 004AE118 2D200000 */  daddu      $4, $0, $0
    /* 3AE11C 004AE11C 2CF4120C */  jal        func_004bd0b0
    /* 3AE120 004AE120 00000000 */   nop
    /* 3AE124 004AE124 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3AE128 004AE128 00088244 */  mtc1       $2, $f1
    /* 3AE12C 004AE12C 00000000 */  nop
    /* 3AE130 004AE130 41000146 */  sub.s      $f1, $f0, $f1
    /* 3AE134 004AE134 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 3AE138 004AE138 00008244 */  mtc1       $2, $f0
    /* 3AE13C 004AE13C 00000000 */  nop
    /* 3AE140 004AE140 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AE144 004AE144 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 3AE148 004AE148 2D200000 */  daddu      $4, $0, $0
    /* 3AE14C 004AE14C 2CF4120C */  jal        func_004bd0b0
    /* 3AE150 004AE150 00000000 */   nop
    /* 3AE154 004AE154 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 3AE158 004AE158 00088244 */  mtc1       $2, $f1
    /* 3AE15C 004AE15C 00000000 */  nop
    /* 3AE160 004AE160 41000146 */  sub.s      $f1, $f0, $f1
    /* 3AE164 004AE164 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 3AE168 004AE168 00008244 */  mtc1       $2, $f0
    /* 3AE16C 004AE16C 00000000 */  nop
    /* 3AE170 004AE170 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AE174 004AE174 4800A0E7 */  swc1       $f0, 0x48($29)
  .L004AE178:
    /* 3AE178 004AE178 4000A327 */  addiu      $3, $29, 0x40
    /* 3AE17C 004AE17C 00006AD8 */  lqc2       $vf10, 0x0($3)
    /* 3AE180 004AE180 AA50CA4B */  vmul.xyz   $vf2, $vf10, $vf10
    /* 3AE184 004AE184 8110024B */  vaddy.x    $vf2, $vf2, $vf2y
    /* 3AE188 004AE188 8210024B */  vaddz.x    $vf2, $vf2, $vf2z
    /* 3AE18C 004AE18C BD03024A */  .word      0x4A0203BD                    # vsqrt      $Q, $vf2x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>
    /* 3AE190 004AE190 BF03004A */  vwaitq
    /* 3AE194 004AE194 00B04248 */  cfc2.ni    $2, $vi22
    /* 3AE198 004AE198 00088244 */  mtc1       $2, $f1
    /* 3AE19C 004AE19C 00008044 */  mtc1       $0, $f0
    /* 3AE1A0 004AE1A0 00000000 */  nop
    /* 3AE1A4 004AE1A4 32000146 */  c.eq.s     $f0, $f1
    /* 3AE1A8 004AE1A8 11000145 */  bc1t       .L004AE1F0
    /* 3AE1AC 004AE1AC 00000000 */   nop
    /* 3AE1B0 004AE1B0 AA50CA4B */  vmul.xyz   $vf2, $vf10, $vf10
    /* 3AE1B4 004AE1B4 BC01224A */  vmulax.w   $ACC, $vf0, $vf2x
    /* 3AE1B8 004AE1B8 BD00224A */  vmadday.w  $ACC, $vf0, $vf2y
    /* 3AE1BC 004AE1BC 8A00224A */  vmaddz.w   $vf2, $vf0, $vf2z
    /* 3AE1C0 004AE1C0 BE03E24B */  vrsqrt     $Q, $vf0w, $vf2w
    /* 3AE1C4 004AE1C4 BF03004A */  vwaitq
    /* 3AE1C8 004AE1C8 9C52C04B */  vmulq.xyz  $vf10, $vf10, $Q
    /* 3AE1CC 004AE1CC 00006AF8 */  sqc2       $vf10, 0x0($3)
    /* 3AE1D0 004AE1D0 4000A0C7 */  lwc1       $f0, 0x40($29)
    /* 3AE1D4 004AE1D4 000000E6 */  swc1       $f0, 0x0($16)
    /* 3AE1D8 004AE1D8 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* 3AE1DC 004AE1DC 040000E6 */  swc1       $f0, 0x4($16)
    /* 3AE1E0 004AE1E0 4800A0C7 */  lwc1       $f0, 0x48($29)
    /* 3AE1E4 004AE1E4 080000E6 */  swc1       $f0, 0x8($16)
    /* 3AE1E8 004AE1E8 05000010 */  b          .L004AE200
    /* 3AE1EC 004AE1EC 00000000 */   nop
  .L004AE1F0:
    /* 3AE1F0 004AE1F0 000000E6 */  swc1       $f0, 0x0($16)
    /* 3AE1F4 004AE1F4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AE1F8 004AE1F8 040002AE */  sw         $2, 0x4($16)
    /* 3AE1FC 004AE1FC 080000E6 */  swc1       $f0, 0x8($16)
  .L004AE200:
    /* 3AE200 004AE200 280034C6 */  lwc1       $f20, 0x28($17)
    /* 3AE204 004AE204 2D200000 */  daddu      $4, $0, $0
    /* 3AE208 004AE208 2CF4120C */  jal        func_004bd0b0
    /* 3AE20C 004AE20C 00000000 */   nop
    /* 3AE210 004AE210 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AE214 004AE214 00088244 */  mtc1       $2, $f1
    /* 3AE218 004AE218 00000000 */  nop
    /* 3AE21C 004AE21C 81081446 */  sub.s      $f2, $f1, $f20
    /* 3AE220 004AE220 00088044 */  mtc1       $0, $f1
    /* 3AE224 004AE224 00000000 */  nop
    /* 3AE228 004AE228 18080246 */  adda.s     $f1, $f2
    /* 3AE22C 004AE22C 5CA00046 */  madd.s     $f1, $f20, $f0
    /* 3AE230 004AE230 240020C6 */  lwc1       $f0, 0x24($17)
    /* 3AE234 004AE234 02000146 */  mul.s      $f0, $f0, $f1
    /* 3AE238 004AE238 100000E6 */  swc1       $f0, 0x10($16)
    /* 3AE23C 004AE23C 2D200000 */  daddu      $4, $0, $0
    /* 3AE240 004AE240 2CF4120C */  jal        func_004bd0b0
    /* 3AE244 004AE244 00000000 */   nop
    /* 3AE248 004AE248 808081C7 */  lwc1       $f1, -0x7F80($28)
    /* 3AE24C 004AE24C 02080046 */  mul.s      $f0, $f1, $f0
    /* 3AE250 004AE250 0C0000E6 */  swc1       $f0, 0xC($16)
    /* 3AE254 004AE254 3400248E */  lw         $4, 0x34($17)
    /* 3AE258 004AE258 02000324 */  addiu      $3, $0, 0x2
    /* 3AE25C 004AE25C 0F008310 */  beq        $4, $3, .L004AE29C
    /* 3AE260 004AE260 00000000 */   nop
    /* 3AE264 004AE264 01000324 */  addiu      $3, $0, 0x1
    /* 3AE268 004AE268 03008310 */  beq        $4, $3, .L004AE278
    /* 3AE26C 004AE26C 00000000 */   nop
    /* 3AE270 004AE270 15000010 */  b          .L004AE2C8
    /* 3AE274 004AE274 00000000 */   nop
  .L004AE278:
    /* 3AE278 004AE278 2D200000 */  daddu      $4, $0, $0
    /* 3AE27C 004AE27C 14F4120C */  jal        func_004bd050
    /* 3AE280 004AE280 00000000 */   nop
    /* 3AE284 004AE284 06000324 */  addiu      $3, $0, 0x6
    /* 3AE288 004AE288 1B004300 */  divu       $0, $2, $3
    /* 3AE28C 004AE28C 10180000 */  mfhi       $3
    /* 3AE290 004AE290 140003A2 */  sb         $3, 0x14($16)
    /* 3AE294 004AE294 0E000010 */  b          .L004AE2D0
    /* 3AE298 004AE298 00000000 */   nop
  .L004AE29C:
    /* 3AE29C 004AE29C 5C00238E */  lw         $3, 0x5C($17)
    /* 3AE2A0 004AE2A0 23200302 */  subu       $4, $16, $3
    /* 3AE2A4 004AE2A4 18000324 */  addiu      $3, $0, 0x18
    /* 3AE2A8 004AE2A8 1B008300 */  divu       $0, $4, $3
    /* 3AE2AC 004AE2AC 12200000 */  mflo       $4
    /* 3AE2B0 004AE2B0 06000324 */  addiu      $3, $0, 0x6
    /* 3AE2B4 004AE2B4 1B008300 */  divu       $0, $4, $3
    /* 3AE2B8 004AE2B8 10180000 */  mfhi       $3
    /* 3AE2BC 004AE2BC 140003A2 */  sb         $3, 0x14($16)
    /* 3AE2C0 004AE2C0 03000010 */  b          .L004AE2D0
    /* 3AE2C4 004AE2C4 00000000 */   nop
  .L004AE2C8:
    /* 3AE2C8 004AE2C8 FFFF0324 */  addiu      $3, $0, -0x1
    /* 3AE2CC 004AE2CC 140003A2 */  sb         $3, 0x14($16)
  .L004AE2D0:
    /* 3AE2D0 004AE2D0 3000BFDF */  ld         $31, 0x30($29)
    /* 3AE2D4 004AE2D4 2000B17B */  lq         $17, 0x20($29)
    /* 3AE2D8 004AE2D8 1000B07B */  lq         $16, 0x10($29)
    /* 3AE2DC 004AE2DC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3AE2E0 004AE2E0 5000BD27 */  addiu      $29, $29, 0x50
    /* 3AE2E4 004AE2E4 0800E003 */  jr         $31
    /* 3AE2E8 004AE2E8 00000000 */   nop
    /* 3AE2EC 004AE2EC 00000000 */  nop
.size func_004ae0a0, 0x250
