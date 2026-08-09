.section .text
.set noat
.set noreorder
glabel func_001be050
    /* BE050 001BE050 E0FEBD27 */  addiu      $29, $29, -0x120
    /* BE054 001BE054 4000BFFF */  sd         $31, 0x40($29)
    /* BE058 001BE058 3000B17F */  sq         $17, 0x30($29)
    /* BE05C 001BE05C 2000B07F */  sq         $16, 0x20($29)
    /* BE060 001BE060 1400B9E7 */  swc1       $f25, 0x14($29)
    /* BE064 001BE064 1000B8E7 */  swc1       $f24, 0x10($29)
    /* BE068 001BE068 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* BE06C 001BE06C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* BE070 001BE070 0400B5E7 */  swc1       $f21, 0x4($29)
    /* BE074 001BE074 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BE078 001BE078 2D888000 */  daddu      $17, $4, $0
    /* BE07C 001BE07C 46660046 */  mov.s      $f25, $f12
    /* BE080 001BE080 066E0046 */  mov.s      $f24, $f13
    /* BE084 001BE084 E000828C */  lw         $2, 0xE0($4)
    /* BE088 001BE088 3000508C */  lw         $16, 0x30($2)
    /* BE08C 001BE08C 900001C6 */  lwc1       $f1, 0x90($16)
    /* BE090 001BE090 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* BE094 001BE094 020D0046 */  mul.s      $f20, $f1, $f0
    /* BE098 001BE098 5000A427 */  addiu      $4, $29, 0x50
    /* BE09C 001BE09C 9C002526 */  addiu      $5, $17, 0x9C
    /* BE0A0 001BE0A0 58F5060C */  jal        func_001bd560
    /* BE0A4 001BE0A4 00000000 */   nop
    /* BE0A8 001BE0A8 2D200002 */  daddu      $4, $16, $0
    /* BE0AC 001BE0AC E000A527 */  addiu      $5, $29, 0xE0
    /* BE0B0 001BE0B0 1456060C */  jal        func_00195850
    /* BE0B4 001BE0B4 00000000 */   nop
    /* BE0B8 001BE0B8 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* BE0BC 001BE0BC 8C0000C6 */  lwc1       $f0, 0x8C($16)
    /* BE0C0 001BE0C0 02010146 */  mul.s      $f4, $f0, $f1
    /* BE0C4 001BE0C4 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BE0C8 001BE0C8 00188244 */  mtc1       $2, $f3
    /* BE0CC 001BE0CC E400A2C7 */  lwc1       $f2, 0xE4($29)
    /* BE0D0 001BE0D0 00088044 */  mtc1       $0, $f1
    /* BE0D4 001BE0D4 00000000 */  nop
    /* BE0D8 001BE0D8 18080246 */  adda.s     $f1, $f2
    /* BE0DC 001BE0DC 5C1D0446 */  madd.s     $f21, $f3, $f4
    /* BE0E0 001BE0E0 3443023C */  lui        $2, (0x43340000 >> 16)
    /* BE0E4 001BE0E4 00008244 */  mtc1       $2, $f0
    /* BE0E8 001BE0E8 00000000 */  nop
    /* BE0EC 001BE0EC 34A00046 */  c.lt.s     $f20, $f0
    /* BE0F0 001BE0F0 13000045 */  bc1f       .L001BE140
    /* BE0F4 001BE0F4 00000000 */   nop
    /* BE0F8 001BE0F8 188180C7 */  lwc1       $f0, -0x7EE8($28)
    /* BE0FC 001BE0FC 18080246 */  adda.s     $f1, $f2
    /* BE100 001BE100 1C000446 */  madd.s     $f0, $f0, $f4
    /* BE104 001BE104 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* BE108 001BE108 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* BE10C 001BE10C 021B0046 */  mul.s      $f12, $f3, $f0
    /* BE110 001BE110 1A2E110C */  jal        func_0044b868
    /* BE114 001BE114 00000000 */   nop
    /* BE118 001BE118 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* BE11C 001BE11C 00088244 */  mtc1       $2, $f1
    /* BE120 001BE120 00000000 */  nop
    /* BE124 001BE124 42081446 */  mul.s      $f1, $f1, $f20
    /* BE128 001BE128 830D0046 */  div.s      $f22, $f1, $f0
    /* BE12C 001BE12C 00000000 */  nop
    /* BE130 001BE130 00000000 */  nop
    /* BE134 001BE134 00000000 */  nop
    /* BE138 001BE138 10000010 */  b          .L001BE17C
    /* BE13C 001BE13C 00000000 */   nop
  .L001BE140:
    /* BE140 001BE140 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* BE144 001BE144 00008244 */  mtc1       $2, $f0
    /* BE148 001BE148 00000000 */  nop
    /* BE14C 001BE14C 18080246 */  adda.s     $f1, $f2
    /* BE150 001BE150 1C000446 */  madd.s     $f0, $f0, $f4
    /* BE154 001BE154 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* BE158 001BE158 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* BE15C 001BE15C 021B0046 */  mul.s      $f12, $f3, $f0
    /* BE160 001BE160 1A2E110C */  jal        func_0044b868
    /* BE164 001BE164 00000000 */   nop
    /* BE168 001BE168 2040023C */  lui        $2, (0x40200000 >> 16)
    /* BE16C 001BE16C 00088244 */  mtc1       $2, $f1
    /* BE170 001BE170 00000000 */  nop
    /* BE174 001BE174 42081446 */  mul.s      $f1, $f1, $f20
    /* BE178 001BE178 830D0046 */  div.s      $f22, $f1, $f0
  .L001BE17C:
    /* BE17C 001BE17C 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* BE180 001BE180 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* BE184 001BE184 01080046 */  sub.s      $f0, $f1, $f0
    /* BE188 001BE188 0001A0E7 */  swc1       $f0, 0x100($29)
    /* BE18C 001BE18C 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* BE190 001BE190 E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* BE194 001BE194 01080046 */  sub.s      $f0, $f1, $f0
    /* BE198 001BE198 0401A0E7 */  swc1       $f0, 0x104($29)
    /* BE19C 001BE19C 5800A1C7 */  lwc1       $f1, 0x58($29)
    /* BE1A0 001BE1A0 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* BE1A4 001BE1A4 01080046 */  sub.s      $f0, $f1, $f0
    /* BE1A8 001BE1A8 0801A0E7 */  swc1       $f0, 0x108($29)
    /* BE1AC 001BE1AC 0001A427 */  addiu      $4, $29, 0x100
    /* BE1B0 001BE1B0 60900F0C */  jal        func_003e4180
    /* BE1B4 001BE1B4 00000000 */   nop
    /* BE1B8 001BE1B8 408181C7 */  lwc1       $f1, -0x7EC0($28)
    /* BE1BC 001BE1BC C2050146 */  mul.s      $f23, $f0, $f1
    /* BE1C0 001BE1C0 36B01746 */  c.le.s     $f22, $f23
    /* BE1C4 001BE1C4 02000145 */  bc1t       .L001BE1D0
    /* BE1C8 001BE1C8 00000000 */   nop
    /* BE1CC 001BE1CC C6B50046 */  mov.s      $f23, $f22
  .L001BE1D0:
    /* BE1D0 001BE1D0 0001A427 */  addiu      $4, $29, 0x100
    /* BE1D4 001BE1D4 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* BE1D8 001BE1D8 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* BE1DC 001BE1DC 01000624 */  addiu      $6, $0, 0x1
    /* BE1E0 001BE1E0 1C000726 */  addiu      $7, $16, 0x1C
    /* BE1E4 001BE1E4 D0720F0C */  jal        func_003dcb40
    /* BE1E8 001BE1E8 00000000 */   nop
    /* BE1EC 001BE1EC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BE1F0 001BE1F0 00008244 */  mtc1       $2, $f0
    /* BE1F4 001BE1F4 00000000 */  nop
    /* BE1F8 001BE1F8 42001446 */  mul.s      $f1, $f0, $f20
    /* BE1FC 001BE1FC 0001A5C7 */  lwc1       $f5, 0x100($29)
    /* BE200 001BE200 02280146 */  mul.s      $f0, $f5, $f1
    /* BE204 001BE204 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BE208 001BE208 0401A4C7 */  lwc1       $f4, 0x104($29)
    /* BE20C 001BE20C 82200146 */  mul.s      $f2, $f4, $f1
    /* BE210 001BE210 1401A2E7 */  swc1       $f2, 0x114($29)
    /* BE214 001BE214 0801A3C7 */  lwc1       $f3, 0x108($29)
    /* BE218 001BE218 42180146 */  mul.s      $f1, $f3, $f1
    /* BE21C 001BE21C 1801A1E7 */  swc1       $f1, 0x118($29)
    /* BE220 001BE220 E000A8C7 */  lwc1       $f8, 0xE0($29)
    /* BE224 001BE224 00400046 */  add.s      $f0, $f8, $f0
    /* BE228 001BE228 F000A0E7 */  swc1       $f0, 0xF0($29)
    /* BE22C 001BE22C E400A7C7 */  lwc1       $f7, 0xE4($29)
    /* BE230 001BE230 00380246 */  add.s      $f0, $f7, $f2
    /* BE234 001BE234 F400A0E7 */  swc1       $f0, 0xF4($29)
    /* BE238 001BE238 E800A6C7 */  lwc1       $f6, 0xE8($29)
    /* BE23C 001BE23C 00300146 */  add.s      $f0, $f6, $f1
    /* BE240 001BE240 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* BE244 001BE244 82281646 */  mul.s      $f2, $f5, $f22
    /* BE248 001BE248 1001A2E7 */  swc1       $f2, 0x110($29)
    /* BE24C 001BE24C 42201646 */  mul.s      $f1, $f4, $f22
    /* BE250 001BE250 1401A1E7 */  swc1       $f1, 0x114($29)
    /* BE254 001BE254 02181646 */  mul.s      $f0, $f3, $f22
    /* BE258 001BE258 1801A0E7 */  swc1       $f0, 0x118($29)
    /* BE25C 001BE25C 40110846 */  add.s      $f5, $f2, $f8
    /* BE260 001BE260 1001A5E7 */  swc1       $f5, 0x110($29)
    /* BE264 001BE264 00090746 */  add.s      $f4, $f1, $f7
    /* BE268 001BE268 1401A4E7 */  swc1       $f4, 0x114($29)
    /* BE26C 001BE26C C0000646 */  add.s      $f3, $f0, $f6
    /* BE270 001BE270 1801A3E7 */  swc1       $f3, 0x118($29)
    /* BE274 001BE274 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* BE278 001BE278 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* BE27C 001BE27C 82080046 */  mul.s      $f2, $f1, $f0
    /* BE280 001BE280 288181C7 */  lwc1       $f1, -0x7ED8($28)
    /* BE284 001BE284 00008044 */  mtc1       $0, $f0
    /* BE288 001BE288 00000000 */  nop
    /* BE28C 001BE28C 18000446 */  adda.s     $f0, $f4
    /* BE290 001BE290 5C080246 */  madd.s     $f1, $f1, $f2
    /* BE294 001BE294 1401A1E7 */  swc1       $f1, 0x114($29)
    /* BE298 001BE298 01280846 */  sub.s      $f0, $f5, $f8
    /* BE29C 001BE29C 0001A0E7 */  swc1       $f0, 0x100($29)
    /* BE2A0 001BE2A0 01080746 */  sub.s      $f0, $f1, $f7
    /* BE2A4 001BE2A4 0401A0E7 */  swc1       $f0, 0x104($29)
    /* BE2A8 001BE2A8 01180646 */  sub.s      $f0, $f3, $f6
    /* BE2AC 001BE2AC 0801A0E7 */  swc1       $f0, 0x108($29)
    /* BE2B0 001BE2B0 0001A427 */  addiu      $4, $29, 0x100
    /* BE2B4 001BE2B4 2D288000 */  daddu      $5, $4, $0
    /* BE2B8 001BE2B8 2C900F0C */  jal        func_003e40b0
    /* BE2BC 001BE2BC 00000000 */   nop
    /* BE2C0 001BE2C0 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BE2C4 001BE2C4 C2001646 */  mul.s      $f3, $f0, $f22
    /* BE2C8 001BE2C8 1001A3E7 */  swc1       $f3, 0x110($29)
    /* BE2CC 001BE2CC 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* BE2D0 001BE2D0 82001646 */  mul.s      $f2, $f0, $f22
    /* BE2D4 001BE2D4 1401A2E7 */  swc1       $f2, 0x114($29)
    /* BE2D8 001BE2D8 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* BE2DC 001BE2DC 42001646 */  mul.s      $f1, $f0, $f22
    /* BE2E0 001BE2E0 1801A1E7 */  swc1       $f1, 0x118($29)
    /* BE2E4 001BE2E4 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* BE2E8 001BE2E8 00180046 */  add.s      $f0, $f3, $f0
    /* BE2EC 001BE2EC 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BE2F0 001BE2F0 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* BE2F4 001BE2F4 00100046 */  add.s      $f0, $f2, $f0
    /* BE2F8 001BE2F8 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BE2FC 001BE2FC F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* BE300 001BE300 00080046 */  add.s      $f0, $f1, $f0
    /* BE304 001BE304 1801A0E7 */  swc1       $f0, 0x118($29)
    /* BE308 001BE308 7800A427 */  addiu      $4, $29, 0x78
    /* BE30C 001BE30C 1001A527 */  addiu      $5, $29, 0x110
    /* BE310 001BE310 F000A627 */  addiu      $6, $29, 0xF0
    /* BE314 001BE314 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BE318 001BE318 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BE31C 001BE31C E0F5060C */  jal        func_001bd780
    /* BE320 001BE320 00000000 */   nop
    /* BE324 001BE324 5C00A427 */  addiu      $4, $29, 0x5C
    /* BE328 001BE328 7800A527 */  addiu      $5, $29, 0x78
    /* BE32C 001BE32C ACB0070C */  jal        func_001ec2b0
    /* BE330 001BE330 00000000 */   nop
    /* BE334 001BE334 86050046 */  mov.s      $f22, $f0
    /* BE338 001BE338 6C8181C7 */  lwc1       $f1, -0x7E94($28)
    /* BE33C 001BE33C 020D1946 */  mul.s      $f20, $f1, $f25
    /* BE340 001BE340 36001446 */  c.le.s     $f0, $f20
    /* BE344 001BE344 CE000145 */  bc1t       .L001BE680
    /* BE348 001BE348 00000000 */   nop
    /* BE34C 001BE34C 42081846 */  mul.s      $f1, $f1, $f24
    /* BE350 001BE350 36000146 */  c.le.s     $f0, $f1
    /* BE354 001BE354 19000145 */  bc1t       .L001BE3BC
    /* BE358 001BE358 00000000 */   nop
    /* BE35C 001BE35C E4002396 */  lhu        $3, 0xE4($17)
    /* BE360 001BE360 02000224 */  addiu      $2, $0, 0x2
    /* BE364 001BE364 15006210 */  beq        $3, $2, .L001BE3BC
    /* BE368 001BE368 00000000 */   nop
    /* BE36C 001BE36C 29000224 */  addiu      $2, $0, 0x29
    /* BE370 001BE370 12006210 */  beq        $3, $2, .L001BE3BC
    /* BE374 001BE374 00000000 */   nop
    /* BE378 001BE378 24000224 */  addiu      $2, $0, 0x24
    /* BE37C 001BE37C 0F006210 */  beq        $3, $2, .L001BE3BC
    /* BE380 001BE380 00000000 */   nop
    /* BE384 001BE384 22000224 */  addiu      $2, $0, 0x22
    /* BE388 001BE388 0C006210 */  beq        $3, $2, .L001BE3BC
    /* BE38C 001BE38C 00000000 */   nop
    /* BE390 001BE390 21000224 */  addiu      $2, $0, 0x21
    /* BE394 001BE394 09006210 */  beq        $3, $2, .L001BE3BC
    /* BE398 001BE398 00000000 */   nop
    /* BE39C 001BE39C 2D202002 */  daddu      $4, $17, $0
    /* BE3A0 001BE3A0 B43F070C */  jal        func_001cfed0
    /* BE3A4 001BE3A4 00000000 */   nop
    /* BE3A8 001BE3A8 05000424 */  addiu      $4, $0, 0x5
    /* BE3AC 001BE3AC 44CC120C */  jal        func_004b3110
    /* BE3B0 001BE3B0 00000000 */   nop
    /* BE3B4 001BE3B4 37010010 */  b          .L001BE894
    /* BE3B8 001BE3B8 00000000 */   nop
  .L001BE3BC:
    /* BE3BC 001BE3BC 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* BE3C0 001BE3C0 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BE3C4 001BE3C4 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* BE3C8 001BE3C8 1801A0E7 */  swc1       $f0, 0x118($29)
    /* BE3CC 001BE3CC 5400A0C7 */  lwc1       $f0, 0x54($29)
    /* BE3D0 001BE3D0 34A80046 */  c.lt.s     $f21, $f0
    /* BE3D4 001BE3D4 0B000045 */  bc1f       .L001BE404
    /* BE3D8 001BE3D8 00000000 */   nop
    /* BE3DC 001BE3DC 81001546 */  sub.s      $f2, $f0, $f21
    /* BE3E0 001BE3E0 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* BE3E4 001BE3E4 00088244 */  mtc1       $2, $f1
    /* BE3E8 001BE3E8 00008044 */  mtc1       $0, $f0
    /* BE3EC 001BE3EC 00000000 */  nop
    /* BE3F0 001BE3F0 18001546 */  adda.s     $f0, $f21
    /* BE3F4 001BE3F4 1C080246 */  madd.s     $f0, $f1, $f2
    /* BE3F8 001BE3F8 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BE3FC 001BE3FC 02000010 */  b          .L001BE408
    /* BE400 001BE400 00000000 */   nop
  .L001BE404:
    /* BE404 001BE404 1401A0E7 */  swc1       $f0, 0x114($29)
  .L001BE408:
    /* BE408 001BE408 C000A427 */  addiu      $4, $29, 0xC0
    /* BE40C 001BE40C 1001A527 */  addiu      $5, $29, 0x110
    /* BE410 001BE410 F000A627 */  addiu      $6, $29, 0xF0
    /* BE414 001BE414 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BE418 001BE418 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BE41C 001BE41C E0F5060C */  jal        func_001bd780
    /* BE420 001BE420 00000000 */   nop
    /* BE424 001BE424 5C00A427 */  addiu      $4, $29, 0x5C
    /* BE428 001BE428 C000A527 */  addiu      $5, $29, 0xC0
    /* BE42C 001BE42C ACB0070C */  jal        func_001ec2b0
    /* BE430 001BE430 00000000 */   nop
    /* BE434 001BE434 36001446 */  c.le.s     $f0, $f20
    /* BE438 001BE438 0B000045 */  bc1f       .L001BE468
    /* BE43C 001BE43C 00000000 */   nop
    /* BE440 001BE440 C000A3C7 */  lwc1       $f3, 0xC0($29)
    /* BE444 001BE444 C400A2C7 */  lwc1       $f2, 0xC4($29)
    /* BE448 001BE448 C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* BE44C 001BE44C CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* BE450 001BE450 7800A3E7 */  swc1       $f3, 0x78($29)
    /* BE454 001BE454 7C00A2E7 */  swc1       $f2, 0x7C($29)
    /* BE458 001BE458 8000A1E7 */  swc1       $f1, 0x80($29)
    /* BE45C 001BE45C 8400A0E7 */  swc1       $f0, 0x84($29)
    /* BE460 001BE460 87000010 */  b          .L001BE680
    /* BE464 001BE464 00000000 */   nop
  .L001BE468:
    /* BE468 001BE468 00000000 */  nop
    /* BE46C 001BE46C 00000000 */  nop
    /* BE470 001BE470 43A51646 */  div.s      $f21, $f20, $f22
    /* BE474 001BE474 5C00A427 */  addiu      $4, $29, 0x5C
    /* BE478 001BE478 7800A527 */  addiu      $5, $29, 0x78
    /* BE47C 001BE47C 9000A627 */  addiu      $6, $29, 0x90
    /* BE480 001BE480 1C730F0C */  jal        func_003dcc70
    /* BE484 001BE484 00000000 */   nop
    /* BE488 001BE488 00588044 */  mtc1       $0, $f11
    /* BE48C 001BE48C 00000000 */  nop
    /* BE490 001BE490 36A80B46 */  c.le.s     $f21, $f11
    /* BE494 001BE494 0B000045 */  bc1f       .L001BE4C4
    /* BE498 001BE498 00000000 */   nop
    /* BE49C 001BE49C 5C00A3C7 */  lwc1       $f3, 0x5C($29)
    /* BE4A0 001BE4A0 6000A2C7 */  lwc1       $f2, 0x60($29)
    /* BE4A4 001BE4A4 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* BE4A8 001BE4A8 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* BE4AC 001BE4AC C000A3E7 */  swc1       $f3, 0xC0($29)
    /* BE4B0 001BE4B0 C400A2E7 */  swc1       $f2, 0xC4($29)
    /* BE4B4 001BE4B4 C800A1E7 */  swc1       $f1, 0xC8($29)
    /* BE4B8 001BE4B8 CC00A0E7 */  swc1       $f0, 0xCC($29)
    /* BE4BC 001BE4BC 56000010 */  b          .L001BE618
    /* BE4C0 001BE4C0 00000000 */   nop
  .L001BE4C4:
    /* BE4C4 001BE4C4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BE4C8 001BE4C8 00008244 */  mtc1       $2, $f0
    /* BE4CC 001BE4CC 00000000 */  nop
    /* BE4D0 001BE4D0 36001546 */  c.le.s     $f0, $f21
    /* BE4D4 001BE4D4 0B000045 */  bc1f       .L001BE504
    /* BE4D8 001BE4D8 00000000 */   nop
    /* BE4DC 001BE4DC 7800A3C7 */  lwc1       $f3, 0x78($29)
    /* BE4E0 001BE4E0 7C00A2C7 */  lwc1       $f2, 0x7C($29)
    /* BE4E4 001BE4E4 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* BE4E8 001BE4E8 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* BE4EC 001BE4EC C000A3E7 */  swc1       $f3, 0xC0($29)
    /* BE4F0 001BE4F0 C400A2E7 */  swc1       $f2, 0xC4($29)
    /* BE4F4 001BE4F4 C800A1E7 */  swc1       $f1, 0xC8($29)
    /* BE4F8 001BE4F8 CC00A0E7 */  swc1       $f0, 0xCC($29)
    /* BE4FC 001BE4FC 46000010 */  b          .L001BE618
    /* BE500 001BE500 00000000 */   nop
  .L001BE504:
    /* BE504 001BE504 01001546 */  sub.s      $f0, $f0, $f21
    /* BE508 001BE508 B400A28F */  lw         $2, 0xB4($29)
    /* BE50C 001BE50C 26004014 */  bnez       $2, .L001BE5A8
    /* BE510 001BE510 00000000 */   nop
    /* BE514 001BE514 B000AAC7 */  lwc1       $f10, 0xB0($29)
    /* BE518 001BE518 02010A46 */  mul.s      $f4, $f0, $f10
    /* BE51C 001BE51C C2200446 */  mul.s      $f3, $f4, $f4
    /* BE520 001BE520 808189C7 */  lwc1       $f9, -0x7E80($28)
    /* BE524 001BE524 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* BE528 001BE528 18580846 */  adda.s     $f11, $f8
    /* BE52C 001BE52C 1C480346 */  madd.s     $f0, $f9, $f3
    /* BE530 001BE530 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* BE534 001BE534 18580746 */  adda.s     $f11, $f7
    /* BE538 001BE538 1C180046 */  madd.s     $f0, $f3, $f0
    /* BE53C 001BE53C 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* BE540 001BE540 18580646 */  adda.s     $f11, $f6
    /* BE544 001BE544 1C180046 */  madd.s     $f0, $f3, $f0
    /* BE548 001BE548 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* BE54C 001BE54C 18580546 */  adda.s     $f11, $f5
    /* BE550 001BE550 1C180046 */  madd.s     $f0, $f3, $f0
    /* BE554 001BE554 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* BE558 001BE558 18580246 */  adda.s     $f11, $f2
    /* BE55C 001BE55C 5C180046 */  madd.s     $f1, $f3, $f0
    /* BE560 001BE560 02180446 */  mul.s      $f0, $f3, $f4
    /* BE564 001BE564 18580446 */  adda.s     $f11, $f4
    /* BE568 001BE568 1C000146 */  madd.s     $f0, $f0, $f1
    /* BE56C 001BE56C 02A90A46 */  mul.s      $f4, $f21, $f10
    /* BE570 001BE570 C2200446 */  mul.s      $f3, $f4, $f4
    /* BE574 001BE574 18580846 */  adda.s     $f11, $f8
    /* BE578 001BE578 5C480346 */  madd.s     $f1, $f9, $f3
    /* BE57C 001BE57C 18580746 */  adda.s     $f11, $f7
    /* BE580 001BE580 5C180146 */  madd.s     $f1, $f3, $f1
    /* BE584 001BE584 18580646 */  adda.s     $f11, $f6
    /* BE588 001BE588 5C180146 */  madd.s     $f1, $f3, $f1
    /* BE58C 001BE58C 18580546 */  adda.s     $f11, $f5
    /* BE590 001BE590 5C180146 */  madd.s     $f1, $f3, $f1
    /* BE594 001BE594 18580246 */  adda.s     $f11, $f2
    /* BE598 001BE598 9C180146 */  madd.s     $f2, $f3, $f1
    /* BE59C 001BE59C 42180446 */  mul.s      $f1, $f3, $f4
    /* BE5A0 001BE5A0 18580446 */  adda.s     $f11, $f4
    /* BE5A4 001BE5A4 5C0D0246 */  madd.s     $f21, $f1, $f2
  .L001BE5A8:
    /* BE5A8 001BE5A8 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* BE5AC 001BE5AC 42090046 */  mul.s      $f5, $f1, $f0
    /* BE5B0 001BE5B0 C000A5E7 */  swc1       $f5, 0xC0($29)
    /* BE5B4 001BE5B4 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* BE5B8 001BE5B8 02090046 */  mul.s      $f4, $f1, $f0
    /* BE5BC 001BE5BC C400A4E7 */  swc1       $f4, 0xC4($29)
    /* BE5C0 001BE5C0 9800A1C7 */  lwc1       $f1, 0x98($29)
    /* BE5C4 001BE5C4 C2080046 */  mul.s      $f3, $f1, $f0
    /* BE5C8 001BE5C8 C800A3E7 */  swc1       $f3, 0xC8($29)
    /* BE5CC 001BE5CC A000A1C7 */  lwc1       $f1, 0xA0($29)
    /* BE5D0 001BE5D0 00108044 */  mtc1       $0, $f2
    /* BE5D4 001BE5D4 00000000 */  nop
    /* BE5D8 001BE5D8 18100546 */  adda.s     $f2, $f5
    /* BE5DC 001BE5DC 5C081546 */  madd.s     $f1, $f1, $f21
    /* BE5E0 001BE5E0 C000A1E7 */  swc1       $f1, 0xC0($29)
    /* BE5E4 001BE5E4 A400A1C7 */  lwc1       $f1, 0xA4($29)
    /* BE5E8 001BE5E8 18100446 */  adda.s     $f2, $f4
    /* BE5EC 001BE5EC 5C081546 */  madd.s     $f1, $f1, $f21
    /* BE5F0 001BE5F0 C400A1E7 */  swc1       $f1, 0xC4($29)
    /* BE5F4 001BE5F4 A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* BE5F8 001BE5F8 18100346 */  adda.s     $f2, $f3
    /* BE5FC 001BE5FC 5C081546 */  madd.s     $f1, $f1, $f21
    /* BE600 001BE600 C800A1E7 */  swc1       $f1, 0xC8($29)
    /* BE604 001BE604 9C00A2C7 */  lwc1       $f2, 0x9C($29)
    /* BE608 001BE608 AC00A1C7 */  lwc1       $f1, 0xAC($29)
    /* BE60C 001BE60C 1A081546 */  mula.s     $f1, $f21
    /* BE610 001BE610 1C100046 */  madd.s     $f0, $f2, $f0
    /* BE614 001BE614 CC00A0E7 */  swc1       $f0, 0xCC($29)
  .L001BE618:
    /* BE618 001BE618 0001A427 */  addiu      $4, $29, 0x100
    /* BE61C 001BE61C 6100053C */  lui        $5, %hi(D_0060A100)
    /* BE620 001BE620 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* BE624 001BE624 01000624 */  addiu      $6, $0, 0x1
    /* BE628 001BE628 C000A727 */  addiu      $7, $29, 0xC0
    /* BE62C 001BE62C D0720F0C */  jal        func_003dcb40
    /* BE630 001BE630 00000000 */   nop
    /* BE634 001BE634 F000A1C7 */  lwc1       $f1, 0xF0($29)
    /* BE638 001BE638 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BE63C 001BE63C 00080046 */  add.s      $f0, $f1, $f0
    /* BE640 001BE640 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BE644 001BE644 F400A1C7 */  lwc1       $f1, 0xF4($29)
    /* BE648 001BE648 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* BE64C 001BE64C 00080046 */  add.s      $f0, $f1, $f0
    /* BE650 001BE650 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BE654 001BE654 F800A1C7 */  lwc1       $f1, 0xF8($29)
    /* BE658 001BE658 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* BE65C 001BE65C 00080046 */  add.s      $f0, $f1, $f0
    /* BE660 001BE660 1801A0E7 */  swc1       $f0, 0x118($29)
    /* BE664 001BE664 7800A427 */  addiu      $4, $29, 0x78
    /* BE668 001BE668 1001A527 */  addiu      $5, $29, 0x110
    /* BE66C 001BE66C F000A627 */  addiu      $6, $29, 0xF0
    /* BE670 001BE670 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BE674 001BE674 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BE678 001BE678 E0F5060C */  jal        func_001bd780
    /* BE67C 001BE67C 00000000 */   nop
  .L001BE680:
    /* BE680 001BE680 26020224 */  addiu      $2, $0, 0x226
    /* BE684 001BE684 00008244 */  mtc1       $2, $f0
    /* BE688 001BE688 00000000 */  nop
    /* BE68C 001BE68C 20008046 */  cvt.s.w    $f0, $f0
    /* BE690 001BE690 34B80046 */  c.lt.s     $f23, $f0
    /* BE694 001BE694 02000045 */  bc1f       .L001BE6A0
    /* BE698 001BE698 00000000 */   nop
    /* BE69C 001BE69C C6050046 */  mov.s      $f23, $f0
  .L001BE6A0:
    /* BE6A0 001BE6A0 0001A427 */  addiu      $4, $29, 0x100
    /* BE6A4 001BE6A4 6100053C */  lui        $5, %hi(D_0060A100)
    /* BE6A8 001BE6A8 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* BE6AC 001BE6AC 01000624 */  addiu      $6, $0, 0x1
    /* BE6B0 001BE6B0 7800A727 */  addiu      $7, $29, 0x78
    /* BE6B4 001BE6B4 D0720F0C */  jal        func_003dcb40
    /* BE6B8 001BE6B8 00000000 */   nop
    /* BE6BC 001BE6BC 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BE6C0 001BE6C0 02001746 */  mul.s      $f0, $f0, $f23
    /* BE6C4 001BE6C4 0001A0E7 */  swc1       $f0, 0x100($29)
    /* BE6C8 001BE6C8 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* BE6CC 001BE6CC 02001746 */  mul.s      $f0, $f0, $f23
    /* BE6D0 001BE6D0 0401A0E7 */  swc1       $f0, 0x104($29)
    /* BE6D4 001BE6D4 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* BE6D8 001BE6D8 02001746 */  mul.s      $f0, $f0, $f23
    /* BE6DC 001BE6DC 0801A0E7 */  swc1       $f0, 0x108($29)
    /* BE6E0 001BE6E0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BE6E4 001BE6E4 00088244 */  mtc1       $2, $f1
    /* BE6E8 001BE6E8 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* BE6EC 001BE6EC 42080046 */  mul.s      $f1, $f1, $f0
    /* BE6F0 001BE6F0 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* BE6F4 001BE6F4 02030146 */  mul.s      $f12, $f0, $f1
    /* BE6F8 001BE6F8 1A2E110C */  jal        func_0044b868
    /* BE6FC 001BE6FC 00000000 */   nop
    /* BE700 001BE700 42B80046 */  mul.s      $f1, $f23, $f0
    /* BE704 001BE704 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* BE708 001BE708 00008244 */  mtc1       $2, $f0
    /* BE70C 001BE70C 00000000 */  nop
    /* BE710 001BE710 420D0046 */  mul.s      $f21, $f1, $f0
    /* BE714 001BE714 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BE718 001BE718 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* BE71C 001BE71C 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* BE720 001BE720 DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* BE724 001BE724 D800A427 */  addiu      $4, $29, 0xD8
    /* BE728 001BE728 2D288000 */  daddu      $5, $4, $0
    /* BE72C 001BE72C 78900F0C */  jal        func_003e41e0
    /* BE730 001BE730 00000000 */   nop
    /* BE734 001BE734 DC00A1C7 */  lwc1       $f1, 0xDC($29)
    /* BE738 001BE738 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* BE73C 001BE73C 00108044 */  mtc1       $0, $f2
    /* BE740 001BE740 00000000 */  nop
    /* BE744 001BE744 18100046 */  adda.s     $f2, $f0
    /* BE748 001BE748 DC081546 */  madd.s     $f3, $f1, $f21
    /* BE74C 001BE74C F000A3E7 */  swc1       $f3, 0xF0($29)
    /* BE750 001BE750 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* BE754 001BE754 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* BE758 001BE758 18100046 */  adda.s     $f2, $f0
    /* BE75C 001BE75C 9D081546 */  msub.s     $f2, $f1, $f21
    /* BE760 001BE760 F800A2E7 */  swc1       $f2, 0xF8($29)
    /* BE764 001BE764 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BE768 001BE768 00180046 */  add.s      $f0, $f3, $f0
    /* BE76C 001BE76C 6C00A0E7 */  swc1       $f0, 0x6C($29)
    /* BE770 001BE770 F400A1C7 */  lwc1       $f1, 0xF4($29)
    /* BE774 001BE774 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* BE778 001BE778 00080046 */  add.s      $f0, $f1, $f0
    /* BE77C 001BE77C 7000A0E7 */  swc1       $f0, 0x70($29)
    /* BE780 001BE780 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* BE784 001BE784 00100046 */  add.s      $f0, $f2, $f0
    /* BE788 001BE788 7400A0E7 */  swc1       $f0, 0x74($29)
    /* BE78C 001BE78C 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* BE790 001BE790 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* BE794 001BE794 00008244 */  mtc1       $2, $f0
    /* BE798 001BE798 00000000 */  nop
    /* BE79C 001BE79C 34080046 */  c.lt.s     $f1, $f0
    /* BE7A0 001BE7A0 02000045 */  bc1f       .L001BE7AC
    /* BE7A4 001BE7A4 00000000 */   nop
    /* BE7A8 001BE7A8 5400A0E7 */  swc1       $f0, 0x54($29)
  .L001BE7AC:
    /* BE7AC 001BE7AC 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* BE7B0 001BE7B0 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* BE7B4 001BE7B4 00008244 */  mtc1       $2, $f0
    /* BE7B8 001BE7B8 00000000 */  nop
    /* BE7BC 001BE7BC 34080046 */  c.lt.s     $f1, $f0
    /* BE7C0 001BE7C0 02000045 */  bc1f       .L001BE7CC
    /* BE7C4 001BE7C4 00000000 */   nop
    /* BE7C8 001BE7C8 7000A0E7 */  swc1       $f0, 0x70($29)
  .L001BE7CC:
    /* BE7CC 001BE7CC 5C00A427 */  addiu      $4, $29, 0x5C
    /* BE7D0 001BE7D0 7800A527 */  addiu      $5, $29, 0x78
    /* BE7D4 001BE7D4 ACB0070C */  jal        func_001ec2b0
    /* BE7D8 001BE7D8 00000000 */   nop
    /* BE7DC 001BE7DC E03F023C */  lui        $2, (0x3FE00000 >> 16)
    /* BE7E0 001BE7E0 00A88244 */  mtc1       $2, $f21
    /* BE7E4 001BE7E4 00088044 */  mtc1       $0, $f1
    /* BE7E8 001BE7E8 00000000 */  nop
    /* BE7EC 001BE7EC 36000146 */  c.le.s     $f0, $f1
    /* BE7F0 001BE7F0 16000145 */  bc1t       .L001BE84C
    /* BE7F4 001BE7F4 00000000 */   nop
    /* BE7F8 001BE7F8 00000000 */  nop
    /* BE7FC 001BE7FC 00000000 */  nop
    /* BE800 001BE800 43A00046 */  div.s      $f1, $f20, $f0
    /* BE804 001BE804 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BE808 001BE808 00008244 */  mtc1       $2, $f0
    /* BE80C 001BE80C 00000000 */  nop
    /* BE810 001BE810 36080046 */  c.le.s     $f1, $f0
    /* BE814 001BE814 05000145 */  bc1t       .L001BE82C
    /* BE818 001BE818 00000000 */   nop
    /* BE81C 001BE81C 7C8080C7 */  lwc1       $f0, -0x7F84($28)
    /* BE820 001BE820 420D0046 */  mul.s      $f21, $f1, $f0
    /* BE824 001BE824 02000010 */  b          .L001BE830
    /* BE828 001BE828 00000000 */   nop
  .L001BE82C:
    /* BE82C 001BE82C 7C8095C7 */  lwc1       $f21, -0x7F84($28)
  .L001BE830:
    /* BE830 001BE830 E03F023C */  lui        $2, (0x3FE00000 >> 16)
    /* BE834 001BE834 00008244 */  mtc1       $2, $f0
    /* BE838 001BE838 00000000 */  nop
    /* BE83C 001BE83C 36A80046 */  c.le.s     $f21, $f0
    /* BE840 001BE840 02000145 */  bc1t       .L001BE84C
    /* BE844 001BE844 00000000 */   nop
    /* BE848 001BE848 46050046 */  mov.s      $f21, $f0
  .L001BE84C:
    /* BE84C 001BE84C 5000A427 */  addiu      $4, $29, 0x50
    /* BE850 001BE850 2D288000 */  daddu      $5, $4, $0
    /* BE854 001BE854 E8F0060C */  jal        func_001bc3a0
    /* BE858 001BE858 00000000 */   nop
    /* BE85C 001BE85C 6C00A427 */  addiu      $4, $29, 0x6C
    /* BE860 001BE860 2D288000 */  daddu      $5, $4, $0
    /* BE864 001BE864 E8F0060C */  jal        func_001bc3a0
    /* BE868 001BE868 00000000 */   nop
    /* BE86C 001BE86C 2D202002 */  daddu      $4, $17, $0
    /* BE870 001BE870 5000A527 */  addiu      $5, $29, 0x50
    /* BE874 001BE874 6C00A627 */  addiu      $6, $29, 0x6C
    /* BE878 001BE878 01000724 */  addiu      $7, $0, 0x1
    /* BE87C 001BE87C 08EB060C */  jal        func_001bac20
    /* BE880 001BE880 00000000 */   nop
    /* BE884 001BE884 2D202002 */  daddu      $4, $17, $0
    /* BE888 001BE888 06AB0046 */  mov.s      $f12, $f21
    /* BE88C 001BE88C BCEF060C */  jal        func_001bbef0
    /* BE890 001BE890 00000000 */   nop
  .L001BE894:
    /* BE894 001BE894 4000BFDF */  ld         $31, 0x40($29)
    /* BE898 001BE898 3000B17B */  lq         $17, 0x30($29)
    /* BE89C 001BE89C 2000B07B */  lq         $16, 0x20($29)
    /* BE8A0 001BE8A0 1400B9C7 */  lwc1       $f25, 0x14($29)
    /* BE8A4 001BE8A4 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* BE8A8 001BE8A8 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* BE8AC 001BE8AC 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* BE8B0 001BE8B0 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* BE8B4 001BE8B4 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* BE8B8 001BE8B8 2001BD27 */  addiu      $29, $29, 0x120
    /* BE8BC 001BE8BC 0800E003 */  jr         $31
    /* BE8C0 001BE8C0 00000000 */   nop
    /* BE8C4 001BE8C4 00000000 */  nop
    /* BE8C8 001BE8C8 00000000 */  nop
    /* BE8CC 001BE8CC 00000000 */  nop
.size func_001be050, 0x880
