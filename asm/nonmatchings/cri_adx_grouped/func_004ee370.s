.section .text
.set noat
.set noreorder
glabel func_004ee370
    /* 3EE370 004EE370 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EE374 004EE374 2D408000 */  daddu      $8, $4, $0
    /* 3EE378 004EE378 0000BFFF */  sd         $31, 0x0($29)
    /* 3EE37C 004EE37C 08000015 */  bnez       $8, .L004EE3A0
    /* 3EE380 004EE380 2D48C000 */   daddu     $9, $6, $0
    /* 3EE384 004EE384 7600043C */  lui        $4, %hi(D_0075CE10)
    /* 3EE388 004EE388 7600053C */  lui        $5, %hi(D_0075CDA0)
    /* 3EE38C 004EE38C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EE390 004EE390 10CE8424 */  addiu      $4, $4, %lo(D_0075CE10)
    /* 3EE394 004EE394 A0CDA524 */  addiu      $5, $5, %lo(D_0075CDA0)
    /* 3EE398 004EE398 B4B71308 */  j          func_004eded0
    /* 3EE39C 004EE39C 1000BD27 */   addiu     $29, $29, 0x10
  .L004EE3A0:
    /* 3EE3A0 004EE3A0 0400028D */  lw         $2, 0x4($8)
    /* 3EE3A4 004EE3A4 08004054 */  bnel       $2, $0, .L004EE3C8
    /* 3EE3A8 004EE3A8 2000048D */   lw        $4, 0x20($8)
    /* 3EE3AC 004EE3AC 7600043C */  lui        $4, %hi(D_0075CE20)
    /* 3EE3B0 004EE3B0 7600053C */  lui        $5, %hi(D_0075CDD0)
    /* 3EE3B4 004EE3B4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EE3B8 004EE3B8 20CE8424 */  addiu      $4, $4, %lo(D_0075CE20)
    /* 3EE3BC 004EE3BC D0CDA524 */  addiu      $5, $5, %lo(D_0075CDD0)
    /* 3EE3C0 004EE3C0 B4B71308 */  j          func_004eded0
    /* 3EE3C4 004EE3C4 1000BD27 */   addiu     $29, $29, 0x10
  .L004EE3C8:
    /* 3EE3C8 004EE3C8 07008014 */  bnez       $4, .L004EE3E8
    /* 3EE3CC 004EE3CC 0000BFDF */   ld        $31, 0x0($29)
    /* 3EE3D0 004EE3D0 7600043C */  lui        $4, %hi(D_0075CE30)
    /* 3EE3D4 004EE3D4 7600053C */  lui        $5, %hi(D_0075CE40)
    /* 3EE3D8 004EE3D8 30CE8424 */  addiu      $4, $4, %lo(D_0075CE30)
    /* 3EE3DC 004EE3DC 40CEA524 */  addiu      $5, $5, %lo(D_0075CE40)
    /* 3EE3E0 004EE3E0 B4B71308 */  j          func_004eded0
    /* 3EE3E4 004EE3E4 1000BD27 */   addiu     $29, $29, 0x10
  .L004EE3E8:
    /* 3EE3E8 004EE3E8 1F00A014 */  bnez       $5, .L004EE468
    /* 3EE3EC 004EE3EC 01000224 */   addiu     $2, $0, 0x1
    /* 3EE3F0 004EE3F0 1400028D */  lw         $2, 0x14($8)
    /* 3EE3F4 004EE3F4 2400038D */  lw         $3, 0x24($8)
    /* 3EE3F8 004EE3F8 1000058D */  lw         $5, 0x10($8)
    /* 3EE3FC 004EE3FC 23108200 */  subu       $2, $4, $2
    /* 3EE400 004EE400 21104300 */  addu       $2, $2, $3
    /* 3EE404 004EE404 1C00068D */  lw         $6, 0x1C($8)
    /* 3EE408 004EE408 2A18A200 */  slt        $3, $5, $2
    /* 3EE40C 004EE40C 0B10A300 */  movn       $2, $5, $3
    /* 3EE410 004EE410 2A204900 */  slt        $4, $2, $9
    /* 3EE414 004EE414 0A102401 */  movz       $2, $9, $4
    /* 3EE418 004EE418 0400E2AC */  sw         $2, 0x4($7)
    /* 3EE41C 004EE41C 1400048D */  lw         $4, 0x14($8)
    /* 3EE420 004EE420 2000038D */  lw         $3, 0x20($8)
    /* 3EE424 004EE424 21108200 */  addu       $2, $4, $2
    /* 3EE428 004EE428 2130C400 */  addu       $6, $6, $4
    /* 3EE42C 004EE42C 1A004300 */  div        $0, $2, $3
    /* 3EE430 004EE430 0000E6AC */  sw         $6, 0x0($7)
    /* 3EE434 004EE434 01006050 */  beql       $3, $0, .L004EE43C
    /* 3EE438 004EE438 CD010000 */   break     0, 7
  .L004EE43C:
    /* 3EE43C 004EE43C 1000048D */  lw         $4, 0x10($8)
    /* 3EE440 004EE440 2800038D */  lw         $3, 0x28($8)
    /* 3EE444 004EE444 10280000 */  mfhi       $5
    /* 3EE448 004EE448 140005AD */  sw         $5, 0x14($8)
    /* 3EE44C 004EE44C 0400E28C */  lw         $2, 0x4($7)
    /* 3EE450 004EE450 23208200 */  subu       $4, $4, $2
    /* 3EE454 004EE454 100004AD */  sw         $4, 0x10($8)
    /* 3EE458 004EE458 0400E28C */  lw         $2, 0x4($7)
    /* 3EE45C 004EE45C 21186200 */  addu       $3, $3, $2
    /* 3EE460 004EE460 27000010 */  b          .L004EE500
    /* 3EE464 004EE464 280003AD */   sw        $3, 0x28($8)
  .L004EE468:
    /* 3EE468 004EE468 1F00A254 */  bnel       $5, $2, .L004EE4E8
    /* 3EE46C 004EE46C 3800028D */   lw        $2, 0x38($8)
    /* 3EE470 004EE470 1800028D */  lw         $2, 0x18($8)
    /* 3EE474 004EE474 2400038D */  lw         $3, 0x24($8)
    /* 3EE478 004EE478 0C00058D */  lw         $5, 0xC($8)
    /* 3EE47C 004EE47C 23108200 */  subu       $2, $4, $2
    /* 3EE480 004EE480 21104300 */  addu       $2, $2, $3
    /* 3EE484 004EE484 1C00068D */  lw         $6, 0x1C($8)
    /* 3EE488 004EE488 2A18A200 */  slt        $3, $5, $2
    /* 3EE48C 004EE48C 0B10A300 */  movn       $2, $5, $3
    /* 3EE490 004EE490 2A204900 */  slt        $4, $2, $9
    /* 3EE494 004EE494 0A102401 */  movz       $2, $9, $4
    /* 3EE498 004EE498 0400E2AC */  sw         $2, 0x4($7)
    /* 3EE49C 004EE49C 1800048D */  lw         $4, 0x18($8)
    /* 3EE4A0 004EE4A0 2000038D */  lw         $3, 0x20($8)
    /* 3EE4A4 004EE4A4 21108200 */  addu       $2, $4, $2
    /* 3EE4A8 004EE4A8 2130C400 */  addu       $6, $6, $4
    /* 3EE4AC 004EE4AC 1A004300 */  div        $0, $2, $3
    /* 3EE4B0 004EE4B0 0000E6AC */  sw         $6, 0x0($7)
    /* 3EE4B4 004EE4B4 01006050 */  beql       $3, $0, .L004EE4BC
    /* 3EE4B8 004EE4B8 CD010000 */   break     0, 7
  .L004EE4BC:
    /* 3EE4BC 004EE4BC 0C00048D */  lw         $4, 0xC($8)
    /* 3EE4C0 004EE4C0 3000038D */  lw         $3, 0x30($8)
    /* 3EE4C4 004EE4C4 10280000 */  mfhi       $5
    /* 3EE4C8 004EE4C8 180005AD */  sw         $5, 0x18($8)
    /* 3EE4CC 004EE4CC 0400E28C */  lw         $2, 0x4($7)
    /* 3EE4D0 004EE4D0 23208200 */  subu       $4, $4, $2
    /* 3EE4D4 004EE4D4 0C0004AD */  sw         $4, 0xC($8)
    /* 3EE4D8 004EE4D8 0400E28C */  lw         $2, 0x4($7)
    /* 3EE4DC 004EE4DC 21186200 */  addu       $3, $3, $2
    /* 3EE4E0 004EE4E0 07000010 */  b          .L004EE500
    /* 3EE4E4 004EE4E4 300003AD */   sw        $3, 0x30($8)
  .L004EE4E8:
    /* 3EE4E8 004EE4E8 0000E0AC */  sw         $0, 0x0($7)
    /* 3EE4EC 004EE4EC 04004010 */  beqz       $2, .L004EE500
    /* 3EE4F0 004EE4F0 0400E0AC */   sw        $0, 0x4($7)
    /* 3EE4F4 004EE4F4 3C00048D */  lw         $4, 0x3C($8)
    /* 3EE4F8 004EE4F8 09F84000 */  jalr       $2
    /* 3EE4FC 004EE4FC FDFF0524 */   addiu     $5, $0, -0x3
  .L004EE500:
    /* 3EE500 004EE500 0000BFDF */  ld         $31, 0x0($29)
    /* 3EE504 004EE504 0800E003 */  jr         $31
    /* 3EE508 004EE508 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE50C 004EE50C 00000000 */  nop
.size func_004ee370, 0x1a0
