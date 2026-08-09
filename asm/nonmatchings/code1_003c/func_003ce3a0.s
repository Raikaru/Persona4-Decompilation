.section .text
.set noat
.set noreorder
glabel func_003ce3a0
    /* 2CE3A0 003CE3A0 80FFBD27 */  addiu      $29, $29, -0x80
    /* 2CE3A4 003CE3A4 0800A38C */  lw         $3, 0x8($5)
    /* 2CE3A8 003CE3A8 6000BFFF */  sd         $31, 0x60($29)
    /* 2CE3AC 003CE3AC 0001023C */  lui        $2, (0x1000000 >> 16)
    /* 2CE3B0 003CE3B0 5000B57F */  sq         $21, 0x50($29)
    /* 2CE3B4 003CE3B4 4000B47F */  sq         $20, 0x40($29)
    /* 2CE3B8 003CE3B8 3000B37F */  sq         $19, 0x30($29)
    /* 2CE3BC 003CE3BC 2DA08000 */  daddu      $20, $4, $0
    /* 2CE3C0 003CE3C0 2000B27F */  sq         $18, 0x20($29)
    /* 2CE3C4 003CE3C4 2D98A000 */  daddu      $19, $5, $0
    /* 2CE3C8 003CE3C8 1000B17F */  sq         $17, 0x10($29)
    /* 2CE3CC 003CE3CC 24106200 */  and        $2, $3, $2
    /* 2CE3D0 003CE3D0 53004010 */  beqz       $2, .L003CE520
    /* 2CE3D4 003CE3D4 0000B07F */   sq        $16, 0x0($29)
    /* 2CE3D8 003CE3D8 30B7828F */  lw         $2, -0x48D0($28)
    /* 2CE3DC 003CE3DC 21106202 */  addu       $2, $19, $2
    /* 2CE3E0 003CE3E0 0000528C */  lw         $18, 0x0($2)
    /* 2CE3E4 003CE3E4 0000558E */  lw         $21, 0x0($18)
    /* 2CE3E8 003CE3E8 2B081500 */  sltu       $1, $0, $21
    /* 2CE3EC 003CE3EC 0A002010 */  beqz       $1, .L003CE418
    /* 2CE3F0 003CE3F0 2D880000 */   daddu     $17, $0, $0
    /* 2CE3F4 003CE3F4 2D804002 */  daddu      $16, $18, $0
  .L003CE3F8:
    /* 2CE3F8 003CE3F8 B8310F0C */  jal        func_003cc6e0
    /* 2CE3FC 003CE3FC 0400048E */   lw        $4, 0x4($16)
    /* 2CE400 003CE400 01003126 */  addiu      $17, $17, 0x1
    /* 2CE404 003CE404 04001026 */  addiu      $16, $16, 0x4
    /* 2CE408 003CE408 2B103502 */  sltu       $2, $17, $21
    /* 2CE40C 003CE40C FAFF4014 */  bnez       $2, .L003CE3F8
    /* 2CE410 003CE410 00000000 */   nop
    /* 2CE414 003CE414 00000000 */  nop
  .L003CE418:
    /* 2CE418 003CE418 103A0F0C */  jal        func_003ce840
    /* 2CE41C 003CE41C 2D206002 */   daddu     $4, $19, $0
    /* 2CE420 003CE420 F4FF4624 */  addiu      $6, $2, -0xC
    /* 2CE424 003CE424 2D208002 */  daddu      $4, $20, $0
    /* 2CE428 003CE428 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2CE42C 003CE42C 01000524 */  addiu      $5, $0, 0x1
    /* 2CE430 003CE430 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2CE434 003CE434 FC7B0F0C */  jal        func_003deff0
    /* 2CE438 003CE438 37000824 */   addiu     $8, $0, 0x37
    /* 2CE43C 003CE43C 03004014 */  bnez       $2, .L003CE44C
    /* 2CE440 003CE440 00000000 */   nop
    /* 2CE444 003CE444 3D000010 */  b          .L003CE53C
    /* 2CE448 003CE448 2D100000 */   daddu     $2, $0, $0
  .L003CE44C:
    /* 2CE44C 003CE44C 2D208002 */  daddu      $4, $20, $0
    /* 2CE450 003CE450 B8AA8527 */  addiu      $5, $28, -0x5548
    /* 2CE454 003CE454 AC8A0F0C */  jal        func_003e2ab0
    /* 2CE458 003CE458 04000624 */   addiu     $6, $0, 0x4
    /* 2CE45C 003CE45C 32004010 */  beqz       $2, .L003CE528
    /* 2CE460 003CE460 00000000 */   nop
    /* 2CE464 003CE464 0000428E */  lw         $2, 0x0($18)
    /* 2CE468 003CE468 2B080200 */  sltu       $1, $0, $2
    /* 2CE46C 003CE46C 2C002010 */  beqz       $1, .L003CE520
    /* 2CE470 003CE470 2D880000 */   daddu     $17, $0, $0
    /* 2CE474 003CE474 2D984002 */  daddu      $19, $18, $0
  .L003CE478:
    /* 2CE478 003CE478 0400708E */  lw         $16, 0x4($19)
    /* 2CE47C 003CE47C 2D208002 */  daddu      $4, $20, $0
    /* 2CE480 003CE480 7C00A527 */  addiu      $5, $29, 0x7C
    /* 2CE484 003CE484 04000624 */  addiu      $6, $0, 0x4
    /* 2CE488 003CE488 2000038E */  lw         $3, 0x20($16)
    /* 2CE48C 003CE48C 18001526 */  addiu      $21, $16, 0x18
    /* 2CE490 003CE490 0800028E */  lw         $2, 0x8($16)
    /* 2CE494 003CE494 23187000 */  subu       $3, $3, $16
    /* 2CE498 003CE498 23104300 */  subu       $2, $2, $3
    /* 2CE49C 003CE49C AC8A0F0C */  jal        func_003e2ab0
    /* 2CE4A0 003CE4A0 7C00A2AF */   sw        $2, 0x7C($29)
    /* 2CE4A4 003CE4A4 03004014 */  bnez       $2, .L003CE4B4
    /* 2CE4A8 003CE4A8 00000000 */   nop
    /* 2CE4AC 003CE4AC 23000010 */  b          .L003CE53C
    /* 2CE4B0 003CE4B0 2D100000 */   daddu     $2, $0, $0
  .L003CE4B4:
    /* 2CE4B4 003CE4B4 5C380F0C */  jal        func_003ce170
    /* 2CE4B8 003CE4B8 2D20A002 */   daddu     $4, $21, $0
    /* 2CE4BC 003CE4BC 7800A2AF */  sw         $2, 0x78($29)
    /* 2CE4C0 003CE4C0 2D208002 */  daddu      $4, $20, $0
    /* 2CE4C4 003CE4C4 7800A527 */  addiu      $5, $29, 0x78
    /* 2CE4C8 003CE4C8 AC8A0F0C */  jal        func_003e2ab0
    /* 2CE4CC 003CE4CC 04000624 */   addiu     $6, $0, 0x4
    /* 2CE4D0 003CE4D0 17004010 */  beqz       $2, .L003CE530
    /* 2CE4D4 003CE4D4 00000000 */   nop
    /* 2CE4D8 003CE4D8 0800A58E */  lw         $5, 0x8($21)
    /* 2CE4DC 003CE4DC 7C00A68F */  lw         $6, 0x7C($29)
    /* 2CE4E0 003CE4E0 AC8A0F0C */  jal        func_003e2ab0
    /* 2CE4E4 003CE4E4 2D208002 */   daddu     $4, $20, $0
    /* 2CE4E8 003CE4E8 13004010 */  beqz       $2, .L003CE538
    /* 2CE4EC 003CE4EC 00000000 */   nop
    /* 2CE4F0 003CE4F0 8C380F0C */  jal        func_003ce230
    /* 2CE4F4 003CE4F4 2D20A002 */   daddu     $4, $21, $0
    /* 2CE4F8 003CE4F8 0800028E */  lw         $2, 0x8($16)
    /* 2CE4FC 003CE4FC 2D200002 */  daddu      $4, $16, $0
    /* 2CE500 003CE500 21100202 */  addu       $2, $16, $2
    /* 2CE504 003CE504 3688100C */  jal        func_004220d8
    /* 2CE508 003CE508 18004524 */   addiu     $5, $2, 0x18
    /* 2CE50C 003CE50C 0000428E */  lw         $2, 0x0($18)
    /* 2CE510 003CE510 01003126 */  addiu      $17, $17, 0x1
    /* 2CE514 003CE514 2B102202 */  sltu       $2, $17, $2
    /* 2CE518 003CE518 D7FF4014 */  bnez       $2, .L003CE478
    /* 2CE51C 003CE51C 04007326 */   addiu     $19, $19, 0x4
  .L003CE520:
    /* 2CE520 003CE520 06000010 */  b          .L003CE53C
    /* 2CE524 003CE524 2D108002 */   daddu     $2, $20, $0
  .L003CE528:
    /* 2CE528 003CE528 04000010 */  b          .L003CE53C
    /* 2CE52C 003CE52C 2D100000 */   daddu     $2, $0, $0
  .L003CE530:
    /* 2CE530 003CE530 02000010 */  b          .L003CE53C
    /* 2CE534 003CE534 2D100000 */   daddu     $2, $0, $0
  .L003CE538:
    /* 2CE538 003CE538 2D100000 */  daddu      $2, $0, $0
  .L003CE53C:
    /* 2CE53C 003CE53C 6000BFDF */  ld         $31, 0x60($29)
    /* 2CE540 003CE540 5000B57B */  lq         $21, 0x50($29)
    /* 2CE544 003CE544 4000B47B */  lq         $20, 0x40($29)
    /* 2CE548 003CE548 3000B37B */  lq         $19, 0x30($29)
    /* 2CE54C 003CE54C 2000B27B */  lq         $18, 0x20($29)
    /* 2CE550 003CE550 1000B17B */  lq         $17, 0x10($29)
    /* 2CE554 003CE554 0000B07B */  lq         $16, 0x0($29)
    /* 2CE558 003CE558 0800E003 */  jr         $31
    /* 2CE55C 003CE55C 8000BD27 */   addiu     $29, $29, 0x80
.size func_003ce3a0, 0x1c0
