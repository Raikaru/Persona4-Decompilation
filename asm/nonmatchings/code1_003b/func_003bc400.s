.section .text
.set noat
.set noreorder
glabel func_003bc400
    /* 2BC400 003BC400 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2BC404 003BC404 5000BFFF */  sd         $31, 0x50($29)
    /* 2BC408 003BC408 4000B47F */  sq         $20, 0x40($29)
    /* 2BC40C 003BC40C 3000B37F */  sq         $19, 0x30($29)
    /* 2BC410 003BC410 2DA08000 */  daddu      $20, $4, $0
    /* 2BC414 003BC414 2000B27F */  sq         $18, 0x20($29)
    /* 2BC418 003BC418 1000B17F */  sq         $17, 0x10($29)
    /* 2BC41C 003BC41C 0000B07F */  sq         $16, 0x0($29)
    /* 2BC420 003BC420 0000848C */  lw         $4, 0x0($4)
    /* 2BC424 003BC424 07008010 */  beqz       $4, .L003BC444
    /* 2BC428 003BC428 2D98A000 */   daddu     $19, $5, $0
    /* 2BC42C 003BC42C 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2BC430 003BC430 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2BC434 003BC434 09F84000 */  jalr       $2
    /* 2BC438 003BC438 00000000 */   nop
    /* 2BC43C 003BC43C 02000010 */  b          .L003BC448
    /* 2BC440 003BC440 01004224 */   addiu     $2, $2, 0x1
  .L003BC444:
    /* 2BC444 003BC444 2D100000 */  daddu      $2, $0, $0
  .L003BC448:
    /* 2BC448 003BC448 6C00A2AF */  sw         $2, 0x6C($29)
    /* 2BC44C 003BC44C 2D206002 */  daddu      $4, $19, $0
    /* 2BC450 003BC450 6C00A527 */  addiu      $5, $29, 0x6C
    /* 2BC454 003BC454 907C0F0C */  jal        func_003df240
    /* 2BC458 003BC458 04000624 */   addiu     $6, $0, 0x4
    /* 2BC45C 003BC45C 0B004010 */  beqz       $2, .L003BC48C
    /* 2BC460 003BC460 00000000 */   nop
    /* 2BC464 003BC464 6C00A68F */  lw         $6, 0x6C($29)
    /* 2BC468 003BC468 0A00C018 */  blez       $6, .L003BC494
    /* 2BC46C 003BC46C 00000000 */   nop
    /* 2BC470 003BC470 0000858E */  lw         $5, 0x0($20)
    /* 2BC474 003BC474 AC8A0F0C */  jal        func_003e2ab0
    /* 2BC478 003BC478 2D206002 */   daddu     $4, $19, $0
    /* 2BC47C 003BC47C 05004014 */  bnez       $2, .L003BC494
    /* 2BC480 003BC480 00000000 */   nop
    /* 2BC484 003BC484 5C000010 */  b          .L003BC5F8
    /* 2BC488 003BC488 2D100000 */   daddu     $2, $0, $0
  .L003BC48C:
    /* 2BC48C 003BC48C 5A000010 */  b          .L003BC5F8
    /* 2BC490 003BC490 2D100000 */   daddu     $2, $0, $0
  .L003BC494:
    /* 2BC494 003BC494 2D206002 */  daddu      $4, $19, $0
    /* 2BC498 003BC498 04008526 */  addiu      $5, $20, 0x4
    /* 2BC49C 003BC49C 907C0F0C */  jal        func_003df240
    /* 2BC4A0 003BC4A0 04000624 */   addiu     $6, $0, 0x4
    /* 2BC4A4 003BC4A4 03004014 */  bnez       $2, .L003BC4B4
    /* 2BC4A8 003BC4A8 00000000 */   nop
    /* 2BC4AC 003BC4AC 52000010 */  b          .L003BC5F8
    /* 2BC4B0 003BC4B0 2D100000 */   daddu     $2, $0, $0
  .L003BC4B4:
    /* 2BC4B4 003BC4B4 2D206002 */  daddu      $4, $19, $0
    /* 2BC4B8 003BC4B8 08008526 */  addiu      $5, $20, 0x8
    /* 2BC4BC 003BC4BC 907C0F0C */  jal        func_003df240
    /* 2BC4C0 003BC4C0 04000624 */   addiu     $6, $0, 0x4
    /* 2BC4C4 003BC4C4 42004010 */  beqz       $2, .L003BC5D0
    /* 2BC4C8 003BC4C8 00000000 */   nop
    /* 2BC4CC 003BC4CC 0400838E */  lw         $3, 0x4($20)
    /* 2BC4D0 003BC4D0 03000224 */  addiu      $2, $0, 0x3
    /* 2BC4D4 003BC4D4 1B006210 */  beq        $3, $2, .L003BC544
    /* 2BC4D8 003BC4D8 00000000 */   nop
    /* 2BC4DC 003BC4DC 02000224 */  addiu      $2, $0, 0x2
    /* 2BC4E0 003BC4E0 0F006210 */  beq        $3, $2, .L003BC520
    /* 2BC4E4 003BC4E4 00000000 */   nop
    /* 2BC4E8 003BC4E8 01000224 */  addiu      $2, $0, 0x1
    /* 2BC4EC 003BC4EC 03006210 */  beq        $3, $2, .L003BC4FC
    /* 2BC4F0 003BC4F0 00000000 */   nop
    /* 2BC4F4 003BC4F4 34000010 */  b          .L003BC5C8
    /* 2BC4F8 003BC4F8 2D100000 */   daddu     $2, $0, $0
  .L003BC4FC:
    /* 2BC4FC 003BC4FC 0800828E */  lw         $2, 0x8($20)
    /* 2BC500 003BC500 2D206002 */  daddu      $4, $19, $0
    /* 2BC504 003BC504 0C00858E */  lw         $5, 0xC($20)
    /* 2BC508 003BC508 907C0F0C */  jal        func_003df240
    /* 2BC50C 003BC50C 80300200 */   sll       $6, $2, 2
    /* 2BC510 003BC510 2B004014 */  bnez       $2, .L003BC5C0
    /* 2BC514 003BC514 00000000 */   nop
    /* 2BC518 003BC518 37000010 */  b          .L003BC5F8
    /* 2BC51C 003BC51C 2D100000 */   daddu     $2, $0, $0
  .L003BC520:
    /* 2BC520 003BC520 0800828E */  lw         $2, 0x8($20)
    /* 2BC524 003BC524 2D206002 */  daddu      $4, $19, $0
    /* 2BC528 003BC528 0C00858E */  lw         $5, 0xC($20)
    /* 2BC52C 003BC52C 687C0F0C */  jal        func_003df1a0
    /* 2BC530 003BC530 80300200 */   sll       $6, $2, 2
    /* 2BC534 003BC534 22004014 */  bnez       $2, .L003BC5C0
    /* 2BC538 003BC538 00000000 */   nop
    /* 2BC53C 003BC53C 2E000010 */  b          .L003BC5F8
    /* 2BC540 003BC540 2D100000 */   daddu     $2, $0, $0
  .L003BC544:
    /* 2BC544 003BC544 0800828E */  lw         $2, 0x8($20)
    /* 2BC548 003BC548 0C00918E */  lw         $17, 0xC($20)
    /* 2BC54C 003BC54C 2A080200 */  slt        $1, $0, $2
    /* 2BC550 003BC550 1B002010 */  beqz       $1, .L003BC5C0
    /* 2BC554 003BC554 2D900000 */   daddu     $18, $0, $0
    /* 2BC558 003BC558 8800103C */  lui        $16, %hi(D_008873D4)
    /* 2BC55C 003BC55C D4731026 */  addiu      $16, $16, %lo(D_008873D4)
  .L003BC560:
    /* 2BC560 003BC560 0000248E */  lw         $4, 0x0($17)
    /* 2BC564 003BC564 06008010 */  beqz       $4, .L003BC580
    /* 2BC568 003BC568 00000000 */   nop
    /* 2BC56C 003BC56C 0000028E */  lw         $2, 0x0($16)
    /* 2BC570 003BC570 09F84000 */  jalr       $2
    /* 2BC574 003BC574 00000000 */   nop
    /* 2BC578 003BC578 02000010 */  b          .L003BC584
    /* 2BC57C 003BC57C 01004224 */   addiu     $2, $2, 0x1
  .L003BC580:
    /* 2BC580 003BC580 2D100000 */  daddu      $2, $0, $0
  .L003BC584:
    /* 2BC584 003BC584 6C00A2AF */  sw         $2, 0x6C($29)
    /* 2BC588 003BC588 2D206002 */  daddu      $4, $19, $0
    /* 2BC58C 003BC58C 6C00A527 */  addiu      $5, $29, 0x6C
    /* 2BC590 003BC590 907C0F0C */  jal        func_003df240
    /* 2BC594 003BC594 04000624 */   addiu     $6, $0, 0x4
    /* 2BC598 003BC598 0F004010 */  beqz       $2, .L003BC5D8
    /* 2BC59C 003BC59C 00000000 */   nop
    /* 2BC5A0 003BC5A0 6C00A68F */  lw         $6, 0x6C($29)
    /* 2BC5A4 003BC5A4 0E00C01C */  bgtz       $6, .L003BC5E0
    /* 2BC5A8 003BC5A8 00000000 */   nop
  .L003BC5AC:
    /* 2BC5AC 003BC5AC 0800828E */  lw         $2, 0x8($20)
    /* 2BC5B0 003BC5B0 01005226 */  addiu      $18, $18, 0x1
    /* 2BC5B4 003BC5B4 2A104202 */  slt        $2, $18, $2
    /* 2BC5B8 003BC5B8 E9FF4014 */  bnez       $2, .L003BC560
    /* 2BC5BC 003BC5BC 04003126 */   addiu     $17, $17, 0x4
  .L003BC5C0:
    /* 2BC5C0 003BC5C0 0D000010 */  b          .L003BC5F8
    /* 2BC5C4 003BC5C4 2D106002 */   daddu     $2, $19, $0
  .L003BC5C8:
    /* 2BC5C8 003BC5C8 0C000010 */  b          .L003BC5FC
    /* 2BC5CC 003BC5CC 5000BFDF */   ld        $31, 0x50($29)
  .L003BC5D0:
    /* 2BC5D0 003BC5D0 09000010 */  b          .L003BC5F8
    /* 2BC5D4 003BC5D4 2D100000 */   daddu     $2, $0, $0
  .L003BC5D8:
    /* 2BC5D8 003BC5D8 07000010 */  b          .L003BC5F8
    /* 2BC5DC 003BC5DC 2D100000 */   daddu     $2, $0, $0
  .L003BC5E0:
    /* 2BC5E0 003BC5E0 0000258E */  lw         $5, 0x0($17)
    /* 2BC5E4 003BC5E4 AC8A0F0C */  jal        func_003e2ab0
    /* 2BC5E8 003BC5E8 2D206002 */   daddu     $4, $19, $0
    /* 2BC5EC 003BC5EC EFFF4014 */  bnez       $2, .L003BC5AC
    /* 2BC5F0 003BC5F0 00000000 */   nop
    /* 2BC5F4 003BC5F4 2D100000 */  daddu      $2, $0, $0
  .L003BC5F8:
    /* 2BC5F8 003BC5F8 5000BFDF */  ld         $31, 0x50($29)
  .L003BC5FC:
    /* 2BC5FC 003BC5FC 4000B47B */  lq         $20, 0x40($29)
    /* 2BC600 003BC600 3000B37B */  lq         $19, 0x30($29)
    /* 2BC604 003BC604 2000B27B */  lq         $18, 0x20($29)
    /* 2BC608 003BC608 1000B17B */  lq         $17, 0x10($29)
    /* 2BC60C 003BC60C 0000B07B */  lq         $16, 0x0($29)
    /* 2BC610 003BC610 0800E003 */  jr         $31
    /* 2BC614 003BC614 7000BD27 */   addiu     $29, $29, 0x70
    /* 2BC618 003BC618 00000000 */  nop
    /* 2BC61C 003BC61C 00000000 */  nop
.size func_003bc400, 0x220
