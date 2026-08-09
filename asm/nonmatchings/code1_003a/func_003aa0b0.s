.section .text
.set noat
.set noreorder
glabel func_003aa0b0
    /* 2AA0B0 003AA0B0 10B6868F */  lw         $6, -0x49F0($28)
    /* 2AA0B4 003AA0B4 3B00033C */  lui        $3, %hi(func_003b6680)
    /* 2AA0B8 003AA0B8 80666324 */  addiu      $3, $3, %lo(func_003b6680)
    /* 2AA0BC 003AA0BC 08000524 */  addiu      $5, $0, 0x8
    /* 2AA0C0 003AA0C0 21208600 */  addu       $4, $4, $6
    /* 2AA0C4 003AA0C4 0000848C */  lw         $4, 0x0($4)
    /* 2AA0C8 003AA0C8 240083AC */  sw         $3, 0x24($4)
    /* 2AA0CC 003AA0CC A800878C */  lw         $7, 0xA8($4)
    /* 2AA0D0 003AA0D0 0800E630 */  andi       $6, $7, 0x8
    /* 2AA0D4 003AA0D4 0D00C514 */  bne        $6, $5, .L003AA10C
    /* 2AA0D8 003AA0D8 50008324 */   addiu     $3, $4, 0x50
    /* 2AA0DC 003AA0DC 0001063C */  lui        $6, (0x1000000 >> 16)
    /* 2AA0E0 003AA0E0 2428E600 */  and        $5, $7, $6
    /* 2AA0E4 003AA0E4 0500A614 */  bne        $5, $6, .L003AA0FC
    /* 2AA0E8 003AA0E8 00000000 */   nop
    /* 2AA0EC 003AA0EC 3B00053C */  lui        $5, %hi(func_003b12a0)
    /* 2AA0F0 003AA0F0 A012A524 */  addiu      $5, $5, %lo(func_003b12a0)
    /* 2AA0F4 003AA0F4 50000010 */  b          .L003AA238
    /* 2AA0F8 003AA0F8 280085AC */   sw        $5, 0x28($4)
  .L003AA0FC:
    /* 2AA0FC 003AA0FC 3B00053C */  lui        $5, %hi(func_003b0b80)
    /* 2AA100 003AA100 800BA524 */  addiu      $5, $5, %lo(func_003b0b80)
    /* 2AA104 003AA104 4C000010 */  b          .L003AA238
    /* 2AA108 003AA108 280085AC */   sw        $5, 0x28($4)
  .L003AA10C:
    /* 2AA10C 003AA10C 0080E630 */  andi       $6, $7, 0x8000
    /* 2AA110 003AA110 00800534 */  ori        $5, $0, 0x8000
    /* 2AA114 003AA114 0D00C514 */  bne        $6, $5, .L003AA14C
    /* 2AA118 003AA118 00000000 */   nop
    /* 2AA11C 003AA11C 0001063C */  lui        $6, (0x1000000 >> 16)
    /* 2AA120 003AA120 2428E600 */  and        $5, $7, $6
    /* 2AA124 003AA124 0500A614 */  bne        $5, $6, .L003AA13C
    /* 2AA128 003AA128 00000000 */   nop
    /* 2AA12C 003AA12C 3B00053C */  lui        $5, %hi(func_003aa9f0)
    /* 2AA130 003AA130 F0A9A524 */  addiu      $5, $5, %lo(func_003aa9f0)
    /* 2AA134 003AA134 40000010 */  b          .L003AA238
    /* 2AA138 003AA138 280085AC */   sw        $5, 0x28($4)
  .L003AA13C:
    /* 2AA13C 003AA13C 3B00053C */  lui        $5, %hi(func_003aa370)
    /* 2AA140 003AA140 70A3A524 */  addiu      $5, $5, %lo(func_003aa370)
    /* 2AA144 003AA144 3C000010 */  b          .L003AA238
    /* 2AA148 003AA148 280085AC */   sw        $5, 0x28($4)
  .L003AA14C:
    /* 2AA14C 003AA14C 2000E630 */  andi       $6, $7, 0x20
    /* 2AA150 003AA150 20000524 */  addiu      $5, $0, 0x20
    /* 2AA154 003AA154 1D00C514 */  bne        $6, $5, .L003AA1CC
    /* 2AA158 003AA158 00000000 */   nop
    /* 2AA15C 003AA15C 0400E630 */  andi       $6, $7, 0x4
    /* 2AA160 003AA160 04000524 */  addiu      $5, $0, 0x4
    /* 2AA164 003AA164 0D00C514 */  bne        $6, $5, .L003AA19C
    /* 2AA168 003AA168 00000000 */   nop
    /* 2AA16C 003AA16C 0001063C */  lui        $6, (0x1000000 >> 16)
    /* 2AA170 003AA170 2428E600 */  and        $5, $7, $6
    /* 2AA174 003AA174 0500A614 */  bne        $5, $6, .L003AA18C
    /* 2AA178 003AA178 00000000 */   nop
    /* 2AA17C 003AA17C 3B00053C */  lui        $5, %hi(func_003af990)
    /* 2AA180 003AA180 90F9A524 */  addiu      $5, $5, %lo(func_003af990)
    /* 2AA184 003AA184 2C000010 */  b          .L003AA238
    /* 2AA188 003AA188 280085AC */   sw        $5, 0x28($4)
  .L003AA18C:
    /* 2AA18C 003AA18C 3B00053C */  lui        $5, %hi(func_003acb10)
    /* 2AA190 003AA190 10CBA524 */  addiu      $5, $5, %lo(func_003acb10)
    /* 2AA194 003AA194 28000010 */  b          .L003AA238
    /* 2AA198 003AA198 280085AC */   sw        $5, 0x28($4)
  .L003AA19C:
    /* 2AA19C 003AA19C 0001063C */  lui        $6, (0x1000000 >> 16)
    /* 2AA1A0 003AA1A0 2428E600 */  and        $5, $7, $6
    /* 2AA1A4 003AA1A4 0500A614 */  bne        $5, $6, .L003AA1BC
    /* 2AA1A8 003AA1A8 00000000 */   nop
    /* 2AA1AC 003AA1AC 3B00053C */  lui        $5, %hi(func_003adc40)
    /* 2AA1B0 003AA1B0 40DCA524 */  addiu      $5, $5, %lo(func_003adc40)
    /* 2AA1B4 003AA1B4 20000010 */  b          .L003AA238
    /* 2AA1B8 003AA1B8 280085AC */   sw        $5, 0x28($4)
  .L003AA1BC:
    /* 2AA1BC 003AA1BC 3B00053C */  lui        $5, %hi(func_003ab100)
    /* 2AA1C0 003AA1C0 00B1A524 */  addiu      $5, $5, %lo(func_003ab100)
    /* 2AA1C4 003AA1C4 1C000010 */  b          .L003AA238
    /* 2AA1C8 003AA1C8 280085AC */   sw        $5, 0x28($4)
  .L003AA1CC:
    /* 2AA1CC 003AA1CC 0400E630 */  andi       $6, $7, 0x4
    /* 2AA1D0 003AA1D0 04000524 */  addiu      $5, $0, 0x4
    /* 2AA1D4 003AA1D4 0D00C514 */  bne        $6, $5, .L003AA20C
    /* 2AA1D8 003AA1D8 00000000 */   nop
    /* 2AA1DC 003AA1DC 0001063C */  lui        $6, (0x1000000 >> 16)
    /* 2AA1E0 003AA1E0 2428E600 */  and        $5, $7, $6
    /* 2AA1E4 003AA1E4 0500A614 */  bne        $5, $6, .L003AA1FC
    /* 2AA1E8 003AA1E8 00000000 */   nop
    /* 2AA1EC 003AA1EC 3B00053C */  lui        $5, %hi(func_003aed60)
    /* 2AA1F0 003AA1F0 60EDA524 */  addiu      $5, $5, %lo(func_003aed60)
    /* 2AA1F4 003AA1F4 10000010 */  b          .L003AA238
    /* 2AA1F8 003AA1F8 280085AC */   sw        $5, 0x28($4)
  .L003AA1FC:
    /* 2AA1FC 003AA1FC 3B00053C */  lui        $5, %hi(func_003abf60)
    /* 2AA200 003AA200 60BFA524 */  addiu      $5, $5, %lo(func_003abf60)
    /* 2AA204 003AA204 0C000010 */  b          .L003AA238
    /* 2AA208 003AA208 280085AC */   sw        $5, 0x28($4)
  .L003AA20C:
    /* 2AA20C 003AA20C 0001063C */  lui        $6, (0x1000000 >> 16)
    /* 2AA210 003AA210 2428E600 */  and        $5, $7, $6
    /* 2AA214 003AA214 0500A614 */  bne        $5, $6, .L003AA22C
    /* 2AA218 003AA218 00000000 */   nop
    /* 2AA21C 003AA21C 3B00053C */  lui        $5, %hi(func_003aa9f0)
    /* 2AA220 003AA220 F0A9A524 */  addiu      $5, $5, %lo(func_003aa9f0)
    /* 2AA224 003AA224 04000010 */  b          .L003AA238
    /* 2AA228 003AA228 280085AC */   sw        $5, 0x28($4)
  .L003AA22C:
    /* 2AA22C 003AA22C 3B00053C */  lui        $5, %hi(func_003aa370)
    /* 2AA230 003AA230 70A3A524 */  addiu      $5, $5, %lo(func_003aa370)
    /* 2AA234 003AA234 280085AC */  sw         $5, 0x28($4)
  .L003AA238:
    /* 2AA238 003AA238 5800678C */  lw         $7, 0x58($3)
    /* 2AA23C 003AA23C 80000524 */  addiu      $5, $0, 0x80
    /* 2AA240 003AA240 8000E630 */  andi       $6, $7, 0x80
    /* 2AA244 003AA244 2F00C510 */  beq        $6, $5, .L003AA304
    /* 2AA248 003AA248 00000000 */   nop
    /* 2AA24C 003AA24C 0001E630 */  andi       $6, $7, 0x100
    /* 2AA250 003AA250 00010524 */  addiu      $5, $0, 0x100
    /* 2AA254 003AA254 2F00C510 */  beq        $6, $5, .L003AA314
    /* 2AA258 003AA258 00000000 */   nop
    /* 2AA25C 003AA25C 0800063C */  lui        $6, (0x80000 >> 16)
    /* 2AA260 003AA260 2428E600 */  and        $5, $7, $6
    /* 2AA264 003AA264 2F00A610 */  beq        $5, $6, .L003AA324
    /* 2AA268 003AA268 00000000 */   nop
    /* 2AA26C 003AA26C 1000063C */  lui        $6, (0x100000 >> 16)
    /* 2AA270 003AA270 2428E600 */  and        $5, $7, $6
    /* 2AA274 003AA274 0500A614 */  bne        $5, $6, .L003AA28C
    /* 2AA278 003AA278 00000000 */   nop
    /* 2AA27C 003AA27C 3B00053C */  lui        $5, %hi(func_003b4120)
    /* 2AA280 003AA280 2041A524 */  addiu      $5, $5, %lo(func_003b4120)
    /* 2AA284 003AA284 02000010 */  b          .L003AA290
    /* 2AA288 003AA288 2C0085AC */   sw        $5, 0x2C($4)
  .L003AA28C:
    /* 2AA28C 003AA28C 2C0080AC */  sw         $0, 0x2C($4)
  .L003AA290:
    /* 2AA290 003AA290 5800678C */  lw         $7, 0x58($3)
    /* 2AA294 003AA294 02000524 */  addiu      $5, $0, 0x2
    /* 2AA298 003AA298 0200E630 */  andi       $6, $7, 0x2
    /* 2AA29C 003AA29C 2500C510 */  beq        $6, $5, .L003AA334
    /* 2AA2A0 003AA2A0 00000000 */   nop
    /* 2AA2A4 003AA2A4 4000E630 */  andi       $6, $7, 0x40
    /* 2AA2A8 003AA2A8 40000524 */  addiu      $5, $0, 0x40
    /* 2AA2AC 003AA2AC 2500C510 */  beq        $6, $5, .L003AA344
    /* 2AA2B0 003AA2B0 00000000 */   nop
    /* 2AA2B4 003AA2B4 0400063C */  lui        $6, (0x40000 >> 16)
    /* 2AA2B8 003AA2B8 2428E600 */  and        $5, $7, $6
    /* 2AA2BC 003AA2BC 0500A614 */  bne        $5, $6, .L003AA2D4
    /* 2AA2C0 003AA2C0 00000000 */   nop
    /* 2AA2C4 003AA2C4 3B00053C */  lui        $5, %hi(func_003b3240)
    /* 2AA2C8 003AA2C8 4032A524 */  addiu      $5, $5, %lo(func_003b3240)
    /* 2AA2CC 003AA2CC 04000010 */  b          .L003AA2E0
    /* 2AA2D0 003AA2D0 300085AC */   sw        $5, 0x30($4)
  .L003AA2D4:
    /* 2AA2D4 003AA2D4 3B00053C */  lui        $5, %hi(func_003b3570)
    /* 2AA2D8 003AA2D8 7035A524 */  addiu      $5, $5, %lo(func_003b3570)
    /* 2AA2DC 003AA2DC 300085AC */  sw         $5, 0x30($4)
  .L003AA2E0:
    /* 2AA2E0 003AA2E0 5800658C */  lw         $5, 0x58($3)
    /* 2AA2E4 003AA2E4 10000324 */  addiu      $3, $0, 0x10
    /* 2AA2E8 003AA2E8 1000A530 */  andi       $5, $5, 0x10
    /* 2AA2EC 003AA2EC 1900A310 */  beq        $5, $3, .L003AA354
    /* 2AA2F0 003AA2F0 00000000 */   nop
  .L003AA2F4:
    /* 2AA2F4 003AA2F4 3B00033C */  lui        $3, %hi(func_003b6cb0)
    /* 2AA2F8 003AA2F8 B06C6324 */  addiu      $3, $3, %lo(func_003b6cb0)
    /* 2AA2FC 003AA2FC 19000010 */  b          .L003AA364
    /* 2AA300 003AA300 380083AC */   sw        $3, 0x38($4)
  .L003AA304:
    /* 2AA304 003AA304 3B00053C */  lui        $5, %hi(func_003b3880)
    /* 2AA308 003AA308 8038A524 */  addiu      $5, $5, %lo(func_003b3880)
    /* 2AA30C 003AA30C E0FF0010 */  b          .L003AA290
    /* 2AA310 003AA310 2C0085AC */   sw        $5, 0x2C($4)
  .L003AA314:
    /* 2AA314 003AA314 3B00053C */  lui        $5, %hi(func_003b3f50)
    /* 2AA318 003AA318 503FA524 */  addiu      $5, $5, %lo(func_003b3f50)
    /* 2AA31C 003AA31C DCFF0010 */  b          .L003AA290
    /* 2AA320 003AA320 2C0085AC */   sw        $5, 0x2C($4)
  .L003AA324:
    /* 2AA324 003AA324 3B00053C */  lui        $5, %hi(func_003b4020)
    /* 2AA328 003AA328 2040A524 */  addiu      $5, $5, %lo(func_003b4020)
    /* 2AA32C 003AA32C D8FF0010 */  b          .L003AA290
    /* 2AA330 003AA330 2C0085AC */   sw        $5, 0x2C($4)
  .L003AA334:
    /* 2AA334 003AA334 3B00053C */  lui        $5, %hi(func_003b1a10)
    /* 2AA338 003AA338 101AA524 */  addiu      $5, $5, %lo(func_003b1a10)
    /* 2AA33C 003AA33C E8FF0010 */  b          .L003AA2E0
    /* 2AA340 003AA340 300085AC */   sw        $5, 0x30($4)
  .L003AA344:
    /* 2AA344 003AA344 3B00053C */  lui        $5, %hi(func_003b31a0)
    /* 2AA348 003AA348 A031A524 */  addiu      $5, $5, %lo(func_003b31a0)
    /* 2AA34C 003AA34C E4FF0010 */  b          .L003AA2E0
    /* 2AA350 003AA350 300085AC */   sw        $5, 0x30($4)
  .L003AA354:
    /* 2AA354 003AA354 3B00033C */  lui        $3, %hi(func_003b4230)
    /* 2AA358 003AA358 30426324 */  addiu      $3, $3, %lo(func_003b4230)
    /* 2AA35C 003AA35C E5FF0010 */  b          .L003AA2F4
    /* 2AA360 003AA360 340083AC */   sw        $3, 0x34($4)
  .L003AA364:
    /* 2AA364 003AA364 0800E003 */  jr         $31
    /* 2AA368 003AA368 00000000 */   nop
    /* 2AA36C 003AA36C 00000000 */  nop
.size func_003aa0b0, 0x2c0
