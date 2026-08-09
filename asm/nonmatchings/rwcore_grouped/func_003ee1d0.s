.section .text
.set noat
.set noreorder
glabel func_003ee1d0
    /* 2EE1D0 003EE1D0 80F9BD27 */  addiu      $29, $29, -0x680
    /* 2EE1D4 003EE1D4 00010624 */  addiu      $6, $0, 0x100
    /* 2EE1D8 003EE1D8 4000BFFF */  sd         $31, 0x40($29)
    /* 2EE1DC 003EE1DC 3000B37F */  sq         $19, 0x30($29)
    /* 2EE1E0 003EE1E0 2000B27F */  sq         $18, 0x20($29)
    /* 2EE1E4 003EE1E4 2D988000 */  daddu      $19, $4, $0
    /* 2EE1E8 003EE1E8 1000B17F */  sq         $17, 0x10($29)
    /* 2EE1EC 003EE1EC 2D90A000 */  daddu      $18, $5, $0
    /* 2EE1F0 003EE1F0 8800113C */  lui        $17, %hi(D_008873B0)
    /* 2EE1F4 003EE1F4 0000B07F */  sq         $16, 0x0($29)
    /* 2EE1F8 003EE1F8 B0733126 */  addiu      $17, $17, %lo(D_008873B0)
    /* 2EE1FC 003EE1FC 5001A427 */  addiu      $4, $29, 0x150
    /* 2EE200 003EE200 0000228E */  lw         $2, 0x0($17)
    /* 2EE204 003EE204 09F84000 */  jalr       $2
    /* 2EE208 003EE208 2D286002 */   daddu     $5, $19, $0
    /* 2EE20C 003EE20C 8800103C */  lui        $16, %hi(D_008873D4)
    /* 2EE210 003EE210 D4731026 */  addiu      $16, $16, %lo(D_008873D4)
    /* 2EE214 003EE214 0000028E */  lw         $2, 0x0($16)
    /* 2EE218 003EE218 09F84000 */  jalr       $2
    /* 2EE21C 003EE21C 2D206002 */   daddu     $4, $19, $0
    /* 2EE220 003EE220 0001412C */  sltiu      $1, $2, 0x100
    /* 2EE224 003EE224 68002010 */  beqz       $1, .L003EE3C8
    /* 2EE228 003EE228 00000000 */   nop
  .L003EE22C:
    /* 2EE22C 003EE22C 1C004012 */  beqz       $18, .L003EE2A0
    /* 2EE230 003EE230 5000A0A3 */   sb        $0, 0x50($29)
    /* 2EE234 003EE234 00004282 */  lb         $2, 0x0($18)
    /* 2EE238 003EE238 19004010 */  beqz       $2, .L003EE2A0
    /* 2EE23C 003EE23C 00000000 */   nop
    /* 2EE240 003EE240 0000228E */  lw         $2, 0x0($17)
    /* 2EE244 003EE244 5000A427 */  addiu      $4, $29, 0x50
    /* 2EE248 003EE248 2D284002 */  daddu      $5, $18, $0
    /* 2EE24C 003EE24C 09F84000 */  jalr       $2
    /* 2EE250 003EE250 00010624 */   addiu     $6, $0, 0x100
    /* 2EE254 003EE254 0000028E */  lw         $2, 0x0($16)
    /* 2EE258 003EE258 09F84000 */  jalr       $2
    /* 2EE25C 003EE25C 2D204002 */   daddu     $4, $18, $0
    /* 2EE260 003EE260 0001422C */  sltiu      $2, $2, 0x100
    /* 2EE264 003EE264 0E004014 */  bnez       $2, .L003EE2A0
    /* 2EE268 003EE268 00000000 */   nop
    /* 2EE26C 003EE26C FF004882 */  lb         $8, 0xFF($18)
    /* 2EE270 003EE270 01000224 */  addiu      $2, $0, 0x1
    /* 2EE274 003EE274 5806A2AF */  sw         $2, 0x658($29)
    /* 2EE278 003EE278 2D284002 */  daddu      $5, $18, $0
    /* 2EE27C 003EE27C 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE280 003EE280 00010624 */  addiu      $6, $0, 0x100
    /* 2EE284 003EE284 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE288 003EE288 647D0F0C */  jal        func_003df590
    /* 2EE28C 003EE28C FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE290 003EE290 5C06A2AF */  sw         $2, 0x65C($29)
    /* 2EE294 003EE294 347D0F0C */  jal        func_003df4d0
    /* 2EE298 003EE298 5806A427 */   addiu     $4, $29, 0x658
    /* 2EE29C 003EE29C 4F01A0A3 */  sb         $0, 0x14F($29)
  .L003EE2A0:
    /* 2EE2A0 003EE2A0 5001A427 */  addiu      $4, $29, 0x150
    /* 2EE2A4 003EE2A4 5000A527 */  addiu      $5, $29, 0x50
    /* 2EE2A8 003EE2A8 2D300000 */  daddu      $6, $0, $0
    /* 2EE2AC 003EE2AC BCBD0F0C */  jal        func_003ef6f0
    /* 2EE2B0 003EE2B0 04000724 */   addiu     $7, $0, 0x4
    /* 2EE2B4 003EE2B4 5001A427 */  addiu      $4, $29, 0x150
    /* 2EE2B8 003EE2B8 5000A527 */  addiu      $5, $29, 0x50
    /* 2EE2BC 003EE2BC 04000624 */  addiu      $6, $0, 0x4
    /* 2EE2C0 003EE2C0 7806A727 */  addiu      $7, $29, 0x678
    /* 2EE2C4 003EE2C4 7406A827 */  addiu      $8, $29, 0x674
    /* 2EE2C8 003EE2C8 7006A927 */  addiu      $9, $29, 0x670
    /* 2EE2CC 003EE2CC 6C06AA27 */  addiu      $10, $29, 0x66C
    /* 2EE2D0 003EE2D0 7806A0AF */  sw         $0, 0x678($29)
    /* 2EE2D4 003EE2D4 94B70F0C */  jal        func_003ede50
    /* 2EE2D8 003EE2D8 7406A0AF */   sw        $0, 0x674($29)
    /* 2EE2DC 003EE2DC 48004010 */  beqz       $2, .L003EE400
    /* 2EE2E0 003EE2E0 7C06A2AF */   sw        $2, 0x67C($29)
    /* 2EE2E4 003EE2E4 7406A58F */  lw         $5, 0x674($29)
    /* 2EE2E8 003EE2E8 7006A68F */  lw         $6, 0x670($29)
    /* 2EE2EC 003EE2EC 6C06A78F */  lw         $7, 0x66C($29)
    /* 2EE2F0 003EE2F0 64B10F0C */  jal        func_003ec590
    /* 2EE2F4 003EE2F4 7806A48F */   lw        $4, 0x678($29)
    /* 2EE2F8 003EE2F8 2D804000 */  daddu      $16, $2, $0
    /* 2EE2FC 003EE2FC 42000012 */  beqz       $16, .L003EE408
    /* 2EE300 003EE300 00000000 */   nop
    /* 2EE304 003EE304 23000292 */  lbu        $2, 0x23($16)
    /* 2EE308 003EE308 001A0200 */  sll        $3, $2, 8
    /* 2EE30C 003EE30C 00606230 */  andi       $2, $3, 0x6000
    /* 2EE310 003EE310 15004010 */  beqz       $2, .L003EE368
    /* 2EE314 003EE314 00000000 */   nop
    /* 2EE318 003EE318 00406230 */  andi       $2, $3, 0x4000
    /* 2EE31C 003EE31C 09004010 */  beqz       $2, .L003EE344
    /* 2EE320 003EE320 00000000 */   nop
    /* 2EE324 003EE324 5002A427 */  addiu      $4, $29, 0x250
    /* 2EE328 003EE328 2D280000 */  daddu      $5, $0, $0
    /* 2EE32C 003EE32C 7C06A627 */  addiu      $6, $29, 0x67C
    /* 2EE330 003EE330 01000724 */  addiu      $7, $0, 0x1
    /* 2EE334 003EE334 0CB70F0C */  jal        func_003edc30
    /* 2EE338 003EE338 04000824 */   addiu     $8, $0, 0x4
    /* 2EE33C 003EE33C 08000010 */  b          .L003EE360
    /* 2EE340 003EE340 7C06A28F */   lw        $2, 0x67C($29)
  .L003EE344:
    /* 2EE344 003EE344 5002A427 */  addiu      $4, $29, 0x250
    /* 2EE348 003EE348 2D280000 */  daddu      $5, $0, $0
    /* 2EE34C 003EE34C 7C06A627 */  addiu      $6, $29, 0x67C
    /* 2EE350 003EE350 01000724 */  addiu      $7, $0, 0x1
    /* 2EE354 003EE354 0CB70F0C */  jal        func_003edc30
    /* 2EE358 003EE358 08000824 */   addiu     $8, $0, 0x8
    /* 2EE35C 003EE35C 7C06A28F */  lw         $2, 0x67C($29)
  .L003EE360:
    /* 2EE360 003EE360 5002A327 */  addiu      $3, $29, 0x250
    /* 2EE364 003EE364 180043AC */  sw         $3, 0x18($2)
  .L003EE368:
    /* 2EE368 003EE368 78AF0F0C */  jal        func_003ebde0
    /* 2EE36C 003EE36C 7C06A48F */   lw        $4, 0x67C($29)
    /* 2EE370 003EE370 7C06A58F */  lw         $5, 0x67C($29)
    /* 2EE374 003EE374 60B00F0C */  jal        func_003ec180
    /* 2EE378 003EE378 2D200002 */   daddu     $4, $16, $0
    /* 2EE37C 003EE37C 26004010 */  beqz       $2, .L003EE418
    /* 2EE380 003EE380 00000000 */   nop
    /* 2EE384 003EE384 DCA80F0C */  jal        func_003ea370
    /* 2EE388 003EE388 7C06A48F */   lw        $4, 0x67C($29)
    /* 2EE38C 003EE38C B8BC0F0C */  jal        func_003ef2e0
    /* 2EE390 003EE390 2D200002 */   daddu     $4, $16, $0
    /* 2EE394 003EE394 2D884000 */  daddu      $17, $2, $0
    /* 2EE398 003EE398 25002012 */  beqz       $17, .L003EE430
    /* 2EE39C 003EE39C 00000000 */   nop
    /* 2EE3A0 003EE3A0 2D286002 */  daddu      $5, $19, $0
    /* 2EE3A4 003EE3A4 1CBD0F0C */  jal        func_003ef470
    /* 2EE3A8 003EE3A8 2D202002 */   daddu     $4, $17, $0
    /* 2EE3AC 003EE3AC 24004012 */  beqz       $18, .L003EE440
    /* 2EE3B0 003EE3B0 00000000 */   nop
    /* 2EE3B4 003EE3B4 2D284002 */  daddu      $5, $18, $0
    /* 2EE3B8 003EE3B8 44BD0F0C */  jal        func_003ef510
    /* 2EE3BC 003EE3BC 2D202002 */   daddu     $4, $17, $0
  .L003EE3C0:
    /* 2EE3C0 003EE3C0 24000010 */  b          .L003EE454
    /* 2EE3C4 003EE3C4 2D102002 */   daddu     $2, $17, $0
  .L003EE3C8:
    /* 2EE3C8 003EE3C8 FF006882 */  lb         $8, 0xFF($19)
    /* 2EE3CC 003EE3CC 01000224 */  addiu      $2, $0, 0x1
    /* 2EE3D0 003EE3D0 6006A2AF */  sw         $2, 0x660($29)
    /* 2EE3D4 003EE3D4 2D286002 */  daddu      $5, $19, $0
    /* 2EE3D8 003EE3D8 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE3DC 003EE3DC 00010624 */  addiu      $6, $0, 0x100
    /* 2EE3E0 003EE3E0 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE3E4 003EE3E4 647D0F0C */  jal        func_003df590
    /* 2EE3E8 003EE3E8 FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE3EC 003EE3EC 6406A2AF */  sw         $2, 0x664($29)
    /* 2EE3F0 003EE3F0 347D0F0C */  jal        func_003df4d0
    /* 2EE3F4 003EE3F4 6006A427 */   addiu     $4, $29, 0x660
    /* 2EE3F8 003EE3F8 8CFF0010 */  b          .L003EE22C
    /* 2EE3FC 003EE3FC 4F02A0A3 */   sb        $0, 0x24F($29)
  .L003EE400:
    /* 2EE400 003EE400 14000010 */  b          .L003EE454
    /* 2EE404 003EE404 2D100000 */   daddu     $2, $0, $0
  .L003EE408:
    /* 2EE408 003EE408 DCA80F0C */  jal        func_003ea370
    /* 2EE40C 003EE40C 7C06A48F */   lw        $4, 0x67C($29)
    /* 2EE410 003EE410 10000010 */  b          .L003EE454
    /* 2EE414 003EE414 2D100000 */   daddu     $2, $0, $0
  .L003EE418:
    /* 2EE418 003EE418 CCB00F0C */  jal        func_003ec330
    /* 2EE41C 003EE41C 2D200002 */   daddu     $4, $16, $0
    /* 2EE420 003EE420 DCA80F0C */  jal        func_003ea370
    /* 2EE424 003EE424 7C06A48F */   lw        $4, 0x67C($29)
    /* 2EE428 003EE428 0A000010 */  b          .L003EE454
    /* 2EE42C 003EE42C 2D100000 */   daddu     $2, $0, $0
  .L003EE430:
    /* 2EE430 003EE430 CCB00F0C */  jal        func_003ec330
    /* 2EE434 003EE434 2D200002 */   daddu     $4, $16, $0
    /* 2EE438 003EE438 06000010 */  b          .L003EE454
    /* 2EE43C 003EE43C 2D100000 */   daddu     $2, $0, $0
  .L003EE440:
    /* 2EE440 003EE440 2D202002 */  daddu      $4, $17, $0
    /* 2EE444 003EE444 44BD0F0C */  jal        func_003ef510
    /* 2EE448 003EE448 B0AB8527 */   addiu     $5, $28, -0x5450
    /* 2EE44C 003EE44C DCFF0010 */  b          .L003EE3C0
    /* 2EE450 003EE450 00000000 */   nop
  .L003EE454:
    /* 2EE454 003EE454 4000BFDF */  ld         $31, 0x40($29)
    /* 2EE458 003EE458 3000B37B */  lq         $19, 0x30($29)
    /* 2EE45C 003EE45C 2000B27B */  lq         $18, 0x20($29)
    /* 2EE460 003EE460 1000B17B */  lq         $17, 0x10($29)
    /* 2EE464 003EE464 0000B07B */  lq         $16, 0x0($29)
    /* 2EE468 003EE468 0800E003 */  jr         $31
    /* 2EE46C 003EE46C 8006BD27 */   addiu     $29, $29, 0x680
.size func_003ee1d0, 0x2a0
