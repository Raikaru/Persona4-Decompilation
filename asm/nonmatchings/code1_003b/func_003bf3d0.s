.section .text
.set noat
.set noreorder
glabel func_003bf3d0
    /* 2BF3D0 003BF3D0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2BF3D4 003BF3D4 3000BFFF */  sd         $31, 0x30($29)
    /* 2BF3D8 003BF3D8 2000B27F */  sq         $18, 0x20($29)
    /* 2BF3DC 003BF3DC 1000B17F */  sq         $17, 0x10($29)
    /* 2BF3E0 003BF3E0 0000B07F */  sq         $16, 0x0($29)
    /* 2BF3E4 003BF3E4 2D888000 */  daddu      $17, $4, $0
    /* 2BF3E8 003BF3E8 1000A28C */  lw         $2, 0x10($5)
    /* 2BF3EC 003BF3EC 10004014 */  bnez       $2, .L003BF430
    /* 2BF3F0 003BF3F0 2D80A000 */   daddu     $16, $5, $0
    /* 2BF3F4 003BF3F4 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2BF3F8 003BF3F8 40020F0C */  jal        func_003c0900
    /* 2BF3FC 003BF3FC 02705234 */   ori       $18, $2, (0x37002 & 0xFFFF)
    /* 2BF400 003BF400 0000048E */  lw         $4, 0x0($16)
    /* 2BF404 003BF404 2D304000 */  daddu      $6, $2, $0
    /* 2BF408 003BF408 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2BF40C 003BF40C 14000524 */  addiu      $5, $0, 0x14
    /* 2BF410 003BF410 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2BF414 003BF414 FC7B0F0C */  jal        func_003deff0
    /* 2BF418 003BF418 37000824 */   addiu     $8, $0, 0x37
    /* 2BF41C 003BF41C 18004014 */  bnez       $2, .L003BF480
    /* 2BF420 003BF420 00000000 */   nop
    /* 2BF424 003BF424 140000AE */  sw         $0, 0x14($16)
    /* 2BF428 003BF428 6B000010 */  b          .L003BF5D8
    /* 2BF42C 003BF42C 2D100000 */   daddu     $2, $0, $0
  .L003BF430:
    /* 2BF430 003BF430 2D100000 */  daddu      $2, $0, $0
    /* 2BF434 003BF434 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2BF438 003BF438 70AF8424 */  addiu      $4, $4, %lo(D_0070AF70)
    /* 2BF43C 003BF43C 1C005224 */  addiu      $18, $2, 0x1C
    /* 2BF440 003BF440 DC8C0F0C */  jal        func_003e3370
    /* 2BF444 003BF444 2D282002 */   daddu     $5, $17, $0
    /* 2BF448 003BF448 0000048E */  lw         $4, 0x0($16)
    /* 2BF44C 003BF44C 0C004324 */  addiu      $3, $2, 0xC
    /* 2BF450 003BF450 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2BF454 003BF454 21304302 */  addu       $6, $18, $3
    /* 2BF458 003BF458 02705234 */  ori        $18, $2, (0x37002 & 0xFFFF)
    /* 2BF45C 003BF45C 14000524 */  addiu      $5, $0, 0x14
    /* 2BF460 003BF460 2D384002 */  daddu      $7, $18, $0
    /* 2BF464 003BF464 FC7B0F0C */  jal        func_003deff0
    /* 2BF468 003BF468 37000824 */   addiu     $8, $0, 0x37
    /* 2BF46C 003BF46C 04004014 */  bnez       $2, .L003BF480
    /* 2BF470 003BF470 00000000 */   nop
    /* 2BF474 003BF474 140000AE */  sw         $0, 0x14($16)
    /* 2BF478 003BF478 57000010 */  b          .L003BF5D8
    /* 2BF47C 003BF47C 2D100000 */   daddu     $2, $0, $0
  .L003BF480:
    /* 2BF480 003BF480 0000048E */  lw         $4, 0x0($16)
    /* 2BF484 003BF484 2D384002 */  daddu      $7, $18, $0
    /* 2BF488 003BF488 01000524 */  addiu      $5, $0, 0x1
    /* 2BF48C 003BF48C 10000624 */  addiu      $6, $0, 0x10
    /* 2BF490 003BF490 FC7B0F0C */  jal        func_003deff0
    /* 2BF494 003BF494 37000824 */   addiu     $8, $0, 0x37
    /* 2BF498 003BF498 25004010 */  beqz       $2, .L003BF530
    /* 2BF49C 003BF49C 00000000 */   nop
    /* 2BF4A0 003BF4A0 02002292 */  lbu        $2, 0x2($17)
    /* 2BF4A4 003BF4A4 4800A2AF */  sw         $2, 0x48($29)
    /* 2BF4A8 003BF4A8 4C00A0AF */  sw         $0, 0x4C($29)
    /* 2BF4AC 003BF4AC 0800028E */  lw         $2, 0x8($16)
    /* 2BF4B0 003BF4B0 21004014 */  bnez       $2, .L003BF538
    /* 2BF4B4 003BF4B4 00000000 */   nop
  .L003BF4B8:
    /* 2BF4B8 003BF4B8 1000028E */  lw         $2, 0x10($16)
    /* 2BF4BC 003BF4BC 27004010 */  beqz       $2, .L003BF55C
    /* 2BF4C0 003BF4C0 00000000 */   nop
    /* 2BF4C4 003BF4C4 1000028E */  lw         $2, 0x10($16)
    /* 2BF4C8 003BF4C8 1800238E */  lw         $3, 0x18($17)
    /* 2BF4CC 003BF4CC 2A080200 */  slt        $1, $0, $2
    /* 2BF4D0 003BF4D0 11002010 */  beqz       $1, .L003BF518
    /* 2BF4D4 003BF4D4 2D280000 */   daddu     $5, $0, $0
    /* 2BF4D8 003BF4D8 0C00048E */  lw         $4, 0xC($16)
  .L003BF4DC:
    /* 2BF4DC 003BF4DC 0000828C */  lw         $2, 0x0($4)
    /* 2BF4E0 003BF4E0 07004314 */  bne        $2, $3, .L003BF500
    /* 2BF4E4 003BF4E4 00000000 */   nop
    /* 2BF4E8 003BF4E8 4400A227 */  addiu      $2, $29, 0x44
    /* 2BF4EC 003BF4EC 02004010 */  beqz       $2, .L003BF4F8
    /* 2BF4F0 003BF4F0 00000000 */   nop
    /* 2BF4F4 003BF4F4 000045AC */  sw         $5, 0x0($2)
  .L003BF4F8:
    /* 2BF4F8 003BF4F8 08000010 */  b          .L003BF51C
    /* 2BF4FC 003BF4FC 01000224 */   addiu     $2, $0, 0x1
  .L003BF500:
    /* 2BF500 003BF500 1000028E */  lw         $2, 0x10($16)
    /* 2BF504 003BF504 0100A524 */  addiu      $5, $5, 0x1
    /* 2BF508 003BF508 2A10A200 */  slt        $2, $5, $2
    /* 2BF50C 003BF50C F3FF4014 */  bnez       $2, .L003BF4DC
    /* 2BF510 003BF510 04008424 */   addiu     $4, $4, 0x4
    /* 2BF514 003BF514 00000000 */  nop
  .L003BF518:
    /* 2BF518 003BF518 2D100000 */  daddu      $2, $0, $0
  .L003BF51C:
    /* 2BF51C 003BF51C 0F004014 */  bnez       $2, .L003BF55C
    /* 2BF520 003BF520 00000000 */   nop
    /* 2BF524 003BF524 140000AE */  sw         $0, 0x14($16)
    /* 2BF528 003BF528 2B000010 */  b          .L003BF5D8
    /* 2BF52C 003BF52C 2D100000 */   daddu     $2, $0, $0
  .L003BF530:
    /* 2BF530 003BF530 29000010 */  b          .L003BF5D8
    /* 2BF534 003BF534 2D100000 */   daddu     $2, $0, $0
  .L003BF538:
    /* 2BF538 003BF538 0400258E */  lw         $5, 0x4($17)
    /* 2BF53C 003BF53C 04000426 */  addiu      $4, $16, 0x4
    /* 2BF540 003BF540 64960F0C */  jal        func_003e5990
    /* 2BF544 003BF544 4000A627 */   addiu     $6, $29, 0x40
    /* 2BF548 003BF548 DBFF4014 */  bnez       $2, .L003BF4B8
    /* 2BF54C 003BF54C 00000000 */   nop
    /* 2BF550 003BF550 140000AE */  sw         $0, 0x14($16)
    /* 2BF554 003BF554 20000010 */  b          .L003BF5D8
    /* 2BF558 003BF558 2D100000 */   daddu     $2, $0, $0
  .L003BF55C:
    /* 2BF55C 003BF55C 0000048E */  lw         $4, 0x0($16)
    /* 2BF560 003BF560 4000A527 */  addiu      $5, $29, 0x40
    /* 2BF564 003BF564 AC8A0F0C */  jal        func_003e2ab0
    /* 2BF568 003BF568 10000624 */   addiu     $6, $0, 0x10
    /* 2BF56C 003BF56C 15004010 */  beqz       $2, .L003BF5C4
    /* 2BF570 003BF570 00000000 */   nop
    /* 2BF574 003BF574 1000028E */  lw         $2, 0x10($16)
    /* 2BF578 003BF578 09004014 */  bnez       $2, .L003BF5A0
    /* 2BF57C 003BF57C 00000000 */   nop
    /* 2BF580 003BF580 0000058E */  lw         $5, 0x0($16)
    /* 2BF584 003BF584 3C0B0F0C */  jal        func_003c2cf0
    /* 2BF588 003BF588 1800248E */   lw        $4, 0x18($17)
    /* 2BF58C 003BF58C 04004014 */  bnez       $2, .L003BF5A0
    /* 2BF590 003BF590 00000000 */   nop
    /* 2BF594 003BF594 140000AE */  sw         $0, 0x14($16)
    /* 2BF598 003BF598 0F000010 */  b          .L003BF5D8
    /* 2BF59C 003BF59C 2D100000 */   daddu     $2, $0, $0
  .L003BF5A0:
    /* 2BF5A0 003BF5A0 0000058E */  lw         $5, 0x0($16)
    /* 2BF5A4 003BF5A4 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2BF5A8 003BF5A8 70AF8424 */  addiu      $4, $4, %lo(D_0070AF70)
    /* 2BF5AC 003BF5AC FC8C0F0C */  jal        func_003e33f0
    /* 2BF5B0 003BF5B0 2D302002 */   daddu     $6, $17, $0
    /* 2BF5B4 003BF5B4 06004010 */  beqz       $2, .L003BF5D0
    /* 2BF5B8 003BF5B8 00000000 */   nop
    /* 2BF5BC 003BF5BC 06000010 */  b          .L003BF5D8
    /* 2BF5C0 003BF5C0 2D102002 */   daddu     $2, $17, $0
  .L003BF5C4:
    /* 2BF5C4 003BF5C4 140000AE */  sw         $0, 0x14($16)
    /* 2BF5C8 003BF5C8 03000010 */  b          .L003BF5D8
    /* 2BF5CC 003BF5CC 2D100000 */   daddu     $2, $0, $0
  .L003BF5D0:
    /* 2BF5D0 003BF5D0 140000AE */  sw         $0, 0x14($16)
    /* 2BF5D4 003BF5D4 2D100000 */  daddu      $2, $0, $0
  .L003BF5D8:
    /* 2BF5D8 003BF5D8 3000BFDF */  ld         $31, 0x30($29)
    /* 2BF5DC 003BF5DC 2000B27B */  lq         $18, 0x20($29)
    /* 2BF5E0 003BF5E0 1000B17B */  lq         $17, 0x10($29)
    /* 2BF5E4 003BF5E4 0000B07B */  lq         $16, 0x0($29)
    /* 2BF5E8 003BF5E8 0800E003 */  jr         $31
    /* 2BF5EC 003BF5EC 5000BD27 */   addiu     $29, $29, 0x50
.size func_003bf3d0, 0x220
