.section .text
.set noat
.set noreorder
glabel func_003aa370
    /* 2AA370 003AA370 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2AA374 003AA374 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2AA378 003AA378 3000BFFF */  sd         $31, 0x30($29)
    /* 2AA37C 003AA37C 00388344 */  mtc1       $3, $f7
    /* 2AA380 003AA380 2000B27F */  sq         $18, 0x20($29)
    /* 2AA384 003AA384 1000B17F */  sq         $17, 0x10($29)
    /* 2AA388 003AA388 2D90E000 */  daddu      $18, $7, $0
    /* 2AA38C 003AA38C 0000B07F */  sq         $16, 0x0($29)
    /* 2AA390 003AA390 700002C5 */  lwc1       $f2, 0x70($8)
    /* 2AA394 003AA394 0800078D */  lw         $7, 0x8($8)
    /* 2AA398 003AA398 740001C5 */  lwc1       $f1, 0x74($8)
    /* 2AA39C 003AA39C 0400838C */  lw         $3, 0x4($4)
    /* 2AA3A0 003AA3A0 0000A5C4 */  lwc1       $f5, 0x0($5)
    /* 2AA3A4 003AA3A4 0400118D */  lw         $17, 0x4($8)
    /* 2AA3A8 003AA3A8 0800A3C4 */  lwc1       $f3, 0x8($5)
    /* 2AA3AC 003AA3AC 0000908C */  lw         $16, 0x0($4)
    /* 2AA3B0 003AA3B0 0000C0C4 */  lwc1       $f0, 0x0($6)
    /* 2AA3B4 003AA3B4 0400A4C4 */  lwc1       $f4, 0x4($5)
    /* 2AA3B8 003AA3B8 82390246 */  mul.s      $f6, $f7, $f2
    /* 2AA3BC 003AA3BC 82380146 */  mul.s      $f2, $f7, $f1
    /* 2AA3C0 003AA3C0 42280646 */  mul.s      $f1, $f5, $f6
    /* 2AA3C4 003AA3C4 5000A1E7 */  swc1       $f1, 0x50($29)
    /* 2AA3C8 003AA3C8 42180646 */  mul.s      $f1, $f3, $f6
    /* 2AA3CC 003AA3CC 02000246 */  mul.s      $f0, $f0, $f2
    /* 2AA3D0 003AA3D0 5800A1E7 */  swc1       $f1, 0x58($29)
    /* 2AA3D4 003AA3D4 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 2AA3D8 003AA3D8 0400C1C4 */  lwc1       $f1, 0x4($6)
    /* 2AA3DC 003AA3DC 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 2AA3E0 003AA3E0 02210646 */  mul.s      $f4, $f4, $f6
    /* 2AA3E4 003AA3E4 42080246 */  mul.s      $f1, $f1, $f2
    /* 2AA3E8 003AA3E8 02000246 */  mul.s      $f0, $f0, $f2
    /* 2AA3EC 003AA3EC 5400A4E7 */  swc1       $f4, 0x54($29)
    /* 2AA3F0 003AA3F0 4400A1E7 */  swc1       $f1, 0x44($29)
    /* 2AA3F4 003AA3F4 5D01E314 */  bne        $7, $3, .L003AA96C
    /* 2AA3F8 003AA3F8 4800A0E7 */   swc1      $f0, 0x48($29)
    /* 2AA3FC 003AA3FC 9886100C */  jal        func_00421a60
    /* 2AA400 003AA400 2D200000 */   daddu     $4, $0, $0
    /* 2AA404 003AA404 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA408 003AA408 00D0648C */  lw         $4, -0x3000($3)
    /* 2AA40C 003AA40C 00018430 */  andi       $4, $4, 0x100
    /* 2AA410 003AA410 0C008010 */  beqz       $4, .L003AA444
    /* 2AA414 003AA414 00000000 */   nop
    /* 2AA418 003AA418 00010424 */  addiu      $4, $0, 0x100
    /* 2AA41C 003AA41C 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AA420 003AA420 0F000000 */  sync
    /* 2AA424 003AA424 0F040000 */  sync.p
  .L003AA428:
    /* 2AA428 003AA428 00000000 */  nop
    /* 2AA42C 003AA42C 00000000 */  nop
    /* 2AA430 003AA430 00000000 */  nop
    /* 2AA434 003AA434 00000000 */  nop
    /* 2AA438 003AA438 00000000 */  nop
    /* 2AA43C 003AA43C FAFF0041 */  bc0f       .L003AA428 /* handwritten instruction */
    /* 2AA440 003AA440 00000000 */   nop
  .L003AA444:
    /* 2AA444 003AA444 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA448 003AA448 00D0648C */  lw         $4, -0x3000($3)
    /* 2AA44C 003AA44C 00018430 */  andi       $4, $4, 0x100
    /* 2AA450 003AA450 0C008010 */  beqz       $4, .L003AA484
    /* 2AA454 003AA454 00000000 */   nop
    /* 2AA458 003AA458 00010424 */  addiu      $4, $0, 0x100
    /* 2AA45C 003AA45C 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AA460 003AA460 0F000000 */  sync
    /* 2AA464 003AA464 0F040000 */  sync.p
  .L003AA468:
    /* 2AA468 003AA468 00000000 */  nop
    /* 2AA46C 003AA46C 00000000 */  nop
    /* 2AA470 003AA470 00000000 */  nop
    /* 2AA474 003AA474 00000000 */  nop
    /* 2AA478 003AA478 00000000 */  nop
    /* 2AA47C 003AA47C FAFF0041 */  bc0f       .L003AA468 /* handwritten instruction */
    /* 2AA480 003AA480 00000000 */   nop
  .L003AA484:
    /* 2AA484 003AA484 CD00412A */  slti       $1, $18, 0xCD
    /* 2AA488 003AA488 9D002014 */  bnez       $1, .L003AA700
    /* 2AA48C 003AA48C 00000000 */   nop
    /* 2AA490 003AA490 00700D3C */  lui        $13, (0x70000CC0 >> 16)
    /* 2AA494 003AA494 0110063C */  lui        $6, (0x10010000 >> 16)
    /* 2AA498 003AA498 5000AB27 */  addiu      $11, $29, 0x50
    /* 2AA49C 003AA49C 4000AA27 */  addiu      $10, $29, 0x40
    /* 2AA4A0 003AA4A0 00010524 */  addiu      $5, $0, 0x100
    /* 2AA4A4 003AA4A4 00020424 */  addiu      $4, $0, 0x200
    /* 2AA4A8 003AA4A8 CC000324 */  addiu      $3, $0, 0xCC
    /* 2AA4AC 003AA4AC C00C0824 */  addiu      $8, $0, 0xCC0
    /* 2AA4B0 003AA4B0 C00CAC35 */  ori        $12, $13, (0x70000CC0 & 0xFFFF)
    /* 2AA4B4 003AA4B4 30030724 */  addiu      $7, $0, 0x330
  .L003AA4B8:
    /* 2AA4B8 003AA4B8 00D0C98C */  lw         $9, -0x3000($6)
    /* 2AA4BC 003AA4BC 00012931 */  andi       $9, $9, 0x100
    /* 2AA4C0 003AA4C0 0D002011 */  beqz       $9, .L003AA4F8
    /* 2AA4C4 003AA4C4 00000000 */   nop
    /* 2AA4C8 003AA4C8 20E0C5AC */  sw         $5, -0x1FE0($6)
    /* 2AA4CC 003AA4CC 0F000000 */  sync
    /* 2AA4D0 003AA4D0 0F040000 */  sync.p
    /* 2AA4D4 003AA4D4 00000000 */  nop
  .L003AA4D8:
    /* 2AA4D8 003AA4D8 00000000 */  nop
    /* 2AA4DC 003AA4DC 00000000 */  nop
    /* 2AA4E0 003AA4E0 00000000 */  nop
    /* 2AA4E4 003AA4E4 00000000 */  nop
    /* 2AA4E8 003AA4E8 00000000 */  nop
    /* 2AA4EC 003AA4EC FAFF0041 */  bc0f       .L003AA4D8 /* handwritten instruction */
    /* 2AA4F0 003AA4F0 00000000 */   nop
    /* 2AA4F4 003AA4F4 00000000 */  nop
  .L003AA4F8:
    /* 2AA4F8 003AA4F8 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AA4FC 003AA4FC 00012931 */  andi       $9, $9, 0x100
    /* 2AA500 003AA500 15002011 */  beqz       $9, .L003AA558
    /* 2AA504 003AA504 00000000 */   nop
    /* 2AA508 003AA508 20E0C4AC */  sw         $4, -0x1FE0($6)
    /* 2AA50C 003AA50C 0F000000 */  sync
    /* 2AA510 003AA510 0F040000 */  sync.p
    /* 2AA514 003AA514 00000000 */  nop
  .L003AA518:
    /* 2AA518 003AA518 00000000 */  nop
    /* 2AA51C 003AA51C 00000000 */  nop
    /* 2AA520 003AA520 00000000 */  nop
    /* 2AA524 003AA524 00000000 */  nop
    /* 2AA528 003AA528 00000000 */  nop
    /* 2AA52C 003AA52C FAFF0041 */  bc0f       .L003AA518 /* handwritten instruction */
    /* 2AA530 003AA530 00000000 */   nop
    /* 2AA534 003AA534 00000000 */  nop
  .L003AA538:
    /* 2AA538 003AA538 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AA53C 003AA53C 00012931 */  andi       $9, $9, 0x100
    /* 2AA540 003AA540 00000000 */  nop
    /* 2AA544 003AA544 00000000 */  nop
    /* 2AA548 003AA548 00000000 */  nop
    /* 2AA54C 003AA54C FAFF2015 */  bnez       $9, .L003AA538
    /* 2AA550 003AA550 00000000 */   nop
    /* 2AA554 003AA554 00000000 */  nop
  .L003AA558:
    /* 2AA558 003AA558 10E0C4AC */  sw         $4, -0x1FF0($6)
    /* 2AA55C 003AA55C 80D4C0AC */  sw         $0, -0x2B80($6)
    /* 2AA560 003AA560 10D4D1AC */  sw         $17, -0x2BF0($6)
    /* 2AA564 003AA564 20D4C3AC */  sw         $3, -0x2BE0($6)
    /* 2AA568 003AA568 00D4C5AC */  sw         $5, -0x2C00($6)
    /* 2AA56C 003AA56C 0F000000 */  sync
    /* 2AA570 003AA570 0F040000 */  sync.p
    /* 2AA574 003AA574 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AA578 003AA578 00012931 */  andi       $9, $9, 0x100
    /* 2AA57C 003AA57C 14002011 */  beqz       $9, .L003AA5D0
    /* 2AA580 003AA580 00000000 */   nop
    /* 2AA584 003AA584 20E0C4AC */  sw         $4, -0x1FE0($6)
    /* 2AA588 003AA588 0F000000 */  sync
    /* 2AA58C 003AA58C 0F040000 */  sync.p
  .L003AA590:
    /* 2AA590 003AA590 00000000 */  nop
    /* 2AA594 003AA594 00000000 */  nop
    /* 2AA598 003AA598 00000000 */  nop
    /* 2AA59C 003AA59C 00000000 */  nop
    /* 2AA5A0 003AA5A0 00000000 */  nop
    /* 2AA5A4 003AA5A4 FAFF0041 */  bc0f       .L003AA590 /* handwritten instruction */
    /* 2AA5A8 003AA5A8 00000000 */   nop
    /* 2AA5AC 003AA5AC 00000000 */  nop
  .L003AA5B0:
    /* 2AA5B0 003AA5B0 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AA5B4 003AA5B4 00012931 */  andi       $9, $9, 0x100
    /* 2AA5B8 003AA5B8 00000000 */  nop
    /* 2AA5BC 003AA5BC 00000000 */  nop
    /* 2AA5C0 003AA5C0 00000000 */  nop
    /* 2AA5C4 003AA5C4 FAFF2015 */  bnez       $9, .L003AA5B0
    /* 2AA5C8 003AA5C8 00000000 */   nop
    /* 2AA5CC 003AA5CC 00000000 */  nop
  .L003AA5D0:
    /* 2AA5D0 003AA5D0 2D78A001 */  daddu      $15, $13, $0
    /* 2AA5D4 003AA5D4 2D708001 */  daddu      $14, $12, $0
    /* 2AA5D8 003AA5D8 2DC00000 */  daddu      $24, $0, $0
    /* 2AA5DC 003AA5DC 00000000 */  nop
  .L003AA5E0:
    /* 2AA5E0 003AA5E0 0000E1D9 */  lqc2       $vf1, (0x70000000 & 0xFFFF)($15)
    /* 2AA5E4 003AA5E4 000062D9 */  lqc2       $vf2, 0x0($11)
    /* 2AA5E8 003AA5E8 000043D9 */  lqc2       $vf3, 0x0($10)
    /* 2AA5EC 003AA5EC 2C09C24B */  vsub.xyz   $vf4, $vf1, $vf2
    /* 2AA5F0 003AA5F0 6809C24B */  vadd.xyz   $vf5, $vf1, $vf2
    /* 2AA5F4 003AA5F4 A809C24B */  vadd.xyz   $vf6, $vf1, $vf2
    /* 2AA5F8 003AA5F8 EC09C24B */  vsub.xyz   $vf7, $vf1, $vf2
    /* 2AA5FC 003AA5FC 2C21C34B */  vsub.xyz   $vf4, $vf4, $vf3
    /* 2AA600 003AA600 6C29C34B */  vsub.xyz   $vf5, $vf5, $vf3
    /* 2AA604 003AA604 A831C34B */  vadd.xyz   $vf6, $vf6, $vf3
    /* 2AA608 003AA608 E839C34B */  vadd.xyz   $vf7, $vf7, $vf3
    /* 2AA60C 003AA60C 0000C4F9 */  sqc2       $vf4, 0x0($14)
    /* 2AA610 003AA610 1000C5F9 */  sqc2       $vf5, 0x10($14)
    /* 2AA614 003AA614 2000C6F9 */  sqc2       $vf6, 0x20($14)
    /* 2AA618 003AA618 3000C7F9 */  sqc2       $vf7, 0x30($14)
    /* 2AA61C 003AA61C 01001827 */  addiu      $24, $24, 0x1
    /* 2AA620 003AA620 4000CE25 */  addiu      $14, $14, 0x40
    /* 2AA624 003AA624 CC00092B */  slti       $9, $24, 0xCC
    /* 2AA628 003AA628 EDFF2015 */  bnez       $9, .L003AA5E0
    /* 2AA62C 003AA62C 1000EF25 */   addiu     $15, $15, %lo(D_70000010)
    /* 2AA630 003AA630 00D0C98C */  lw         $9, -0x3000($6)
    /* 2AA634 003AA634 00012931 */  andi       $9, $9, 0x100
    /* 2AA638 003AA638 0D002011 */  beqz       $9, .L003AA670
    /* 2AA63C 003AA63C 00000000 */   nop
    /* 2AA640 003AA640 20E0C5AC */  sw         $5, -0x1FE0($6)
    /* 2AA644 003AA644 0F000000 */  sync
    /* 2AA648 003AA648 0F040000 */  sync.p
    /* 2AA64C 003AA64C 00000000 */  nop
  .L003AA650:
    /* 2AA650 003AA650 00000000 */  nop
    /* 2AA654 003AA654 00000000 */  nop
    /* 2AA658 003AA658 00000000 */  nop
    /* 2AA65C 003AA65C 00000000 */  nop
    /* 2AA660 003AA660 00000000 */  nop
    /* 2AA664 003AA664 FAFF0041 */  bc0f       .L003AA650 /* handwritten instruction */
    /* 2AA668 003AA668 00000000 */   nop
    /* 2AA66C 003AA66C 00000000 */  nop
  .L003AA670:
    /* 2AA670 003AA670 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AA674 003AA674 00012931 */  andi       $9, $9, 0x100
    /* 2AA678 003AA678 15002011 */  beqz       $9, .L003AA6D0
    /* 2AA67C 003AA67C 00000000 */   nop
    /* 2AA680 003AA680 20E0C4AC */  sw         $4, -0x1FE0($6)
    /* 2AA684 003AA684 0F000000 */  sync
    /* 2AA688 003AA688 0F040000 */  sync.p
    /* 2AA68C 003AA68C 00000000 */  nop
  .L003AA690:
    /* 2AA690 003AA690 00000000 */  nop
    /* 2AA694 003AA694 00000000 */  nop
    /* 2AA698 003AA698 00000000 */  nop
    /* 2AA69C 003AA69C 00000000 */  nop
    /* 2AA6A0 003AA6A0 00000000 */  nop
    /* 2AA6A4 003AA6A4 FAFF0041 */  bc0f       .L003AA690 /* handwritten instruction */
    /* 2AA6A8 003AA6A8 00000000 */   nop
    /* 2AA6AC 003AA6AC 00000000 */  nop
  .L003AA6B0:
    /* 2AA6B0 003AA6B0 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AA6B4 003AA6B4 00012931 */  andi       $9, $9, 0x100
    /* 2AA6B8 003AA6B8 00000000 */  nop
    /* 2AA6BC 003AA6BC 00000000 */  nop
    /* 2AA6C0 003AA6C0 00000000 */  nop
    /* 2AA6C4 003AA6C4 FAFF2015 */  bnez       $9, .L003AA6B0
    /* 2AA6C8 003AA6C8 00000000 */   nop
    /* 2AA6CC 003AA6CC 00000000 */  nop
  .L003AA6D0:
    /* 2AA6D0 003AA6D0 10E0C5AC */  sw         $5, -0x1FF0($6)
    /* 2AA6D4 003AA6D4 80D0C8AC */  sw         $8, -0x2F80($6)
    /* 2AA6D8 003AA6D8 10D0D0AC */  sw         $16, -0x2FF0($6)
    /* 2AA6DC 003AA6DC 20D0C7AC */  sw         $7, -0x2FE0($6)
    /* 2AA6E0 003AA6E0 00D0C5AC */  sw         $5, -0x3000($6)
    /* 2AA6E4 003AA6E4 0F000000 */  sync
    /* 2AA6E8 003AA6E8 0F040000 */  sync.p
    /* 2AA6EC 003AA6EC 34FF5226 */  addiu      $18, $18, -0xCC
    /* 2AA6F0 003AA6F0 C00C3126 */  addiu      $17, $17, 0xCC0
    /* 2AA6F4 003AA6F4 CD00412A */  slti       $1, $18, 0xCD
    /* 2AA6F8 003AA6F8 6FFF2010 */  beqz       $1, .L003AA4B8
    /* 2AA6FC 003AA6FC 00331026 */   addiu     $16, $16, 0x3300
  .L003AA700:
    /* 2AA700 003AA700 B5004012 */  beqz       $18, .L003AA9D8
    /* 2AA704 003AA704 00000000 */   nop
    /* 2AA708 003AA708 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA70C 003AA70C 00D0648C */  lw         $4, -0x3000($3)
    /* 2AA710 003AA710 00018430 */  andi       $4, $4, 0x100
    /* 2AA714 003AA714 0C008010 */  beqz       $4, .L003AA748
    /* 2AA718 003AA718 00000000 */   nop
    /* 2AA71C 003AA71C 00010424 */  addiu      $4, $0, 0x100
    /* 2AA720 003AA720 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AA724 003AA724 0F000000 */  sync
    /* 2AA728 003AA728 0F040000 */  sync.p
  .L003AA72C:
    /* 2AA72C 003AA72C 00000000 */  nop
    /* 2AA730 003AA730 00000000 */  nop
    /* 2AA734 003AA734 00000000 */  nop
    /* 2AA738 003AA738 00000000 */  nop
    /* 2AA73C 003AA73C 00000000 */  nop
    /* 2AA740 003AA740 FAFF0041 */  bc0f       .L003AA72C /* handwritten instruction */
    /* 2AA744 003AA744 00000000 */   nop
  .L003AA748:
    /* 2AA748 003AA748 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA74C 003AA74C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AA750 003AA750 00018430 */  andi       $4, $4, 0x100
    /* 2AA754 003AA754 14008010 */  beqz       $4, .L003AA7A8
    /* 2AA758 003AA758 00000000 */   nop
    /* 2AA75C 003AA75C 00020424 */  addiu      $4, $0, 0x200
    /* 2AA760 003AA760 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AA764 003AA764 0F000000 */  sync
    /* 2AA768 003AA768 0F040000 */  sync.p
  .L003AA76C:
    /* 2AA76C 003AA76C 00000000 */  nop
    /* 2AA770 003AA770 00000000 */  nop
    /* 2AA774 003AA774 00000000 */  nop
    /* 2AA778 003AA778 00000000 */  nop
    /* 2AA77C 003AA77C 00000000 */  nop
    /* 2AA780 003AA780 FAFF0041 */  bc0f       .L003AA76C /* handwritten instruction */
    /* 2AA784 003AA784 00000000 */   nop
    /* 2AA788 003AA788 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AA78C:
    /* 2AA78C 003AA78C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AA790 003AA790 00018430 */  andi       $4, $4, 0x100
    /* 2AA794 003AA794 00000000 */  nop
    /* 2AA798 003AA798 00000000 */  nop
    /* 2AA79C 003AA79C 00000000 */  nop
    /* 2AA7A0 003AA7A0 FAFF8014 */  bnez       $4, .L003AA78C
    /* 2AA7A4 003AA7A4 00000000 */   nop
  .L003AA7A8:
    /* 2AA7A8 003AA7A8 00020524 */  addiu      $5, $0, 0x200
    /* 2AA7AC 003AA7AC 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA7B0 003AA7B0 00010424 */  addiu      $4, $0, 0x100
    /* 2AA7B4 003AA7B4 10E065AC */  sw         $5, -0x1FF0($3)
    /* 2AA7B8 003AA7B8 80D460AC */  sw         $0, -0x2B80($3)
    /* 2AA7BC 003AA7BC 10D471AC */  sw         $17, -0x2BF0($3)
    /* 2AA7C0 003AA7C0 20D472AC */  sw         $18, -0x2BE0($3)
    /* 2AA7C4 003AA7C4 00D464AC */  sw         $4, -0x2C00($3)
    /* 2AA7C8 003AA7C8 0F000000 */  sync
    /* 2AA7CC 003AA7CC 0F040000 */  sync.p
    /* 2AA7D0 003AA7D0 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AA7D4 003AA7D4 00018430 */  andi       $4, $4, 0x100
    /* 2AA7D8 003AA7D8 13008010 */  beqz       $4, .L003AA828
    /* 2AA7DC 003AA7DC 00000000 */   nop
    /* 2AA7E0 003AA7E0 20E065AC */  sw         $5, -0x1FE0($3)
    /* 2AA7E4 003AA7E4 0F000000 */  sync
    /* 2AA7E8 003AA7E8 0F040000 */  sync.p
  .L003AA7EC:
    /* 2AA7EC 003AA7EC 00000000 */  nop
    /* 2AA7F0 003AA7F0 00000000 */  nop
    /* 2AA7F4 003AA7F4 00000000 */  nop
    /* 2AA7F8 003AA7F8 00000000 */  nop
    /* 2AA7FC 003AA7FC 00000000 */  nop
    /* 2AA800 003AA800 FAFF0041 */  bc0f       .L003AA7EC /* handwritten instruction */
    /* 2AA804 003AA804 00000000 */   nop
    /* 2AA808 003AA808 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AA80C:
    /* 2AA80C 003AA80C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AA810 003AA810 00018430 */  andi       $4, $4, 0x100
    /* 2AA814 003AA814 00000000 */  nop
    /* 2AA818 003AA818 00000000 */  nop
    /* 2AA81C 003AA81C 00000000 */  nop
    /* 2AA820 003AA820 FAFF8014 */  bnez       $4, .L003AA80C
    /* 2AA824 003AA824 00000000 */   nop
  .L003AA828:
    /* 2AA828 003AA828 00700F3C */  lui        $15, (0x70000CC0 >> 16)
    /* 2AA82C 003AA82C 2A081200 */  slt        $1, $0, $18
    /* 2AA830 003AA830 C00CEE35 */  ori        $14, $15, (0x70000CC0 & 0xFFFF)
    /* 2AA834 003AA834 18002010 */  beqz       $1, .L003AA898
    /* 2AA838 003AA838 2D300000 */   daddu     $6, $0, $0
    /* 2AA83C 003AA83C 5000A527 */  addiu      $5, $29, 0x50
    /* 2AA840 003AA840 4000A427 */  addiu      $4, $29, 0x40
  .L003AA844:
    /* 2AA844 003AA844 0000E1D9 */  lqc2       $vf1, (0x70000000 & 0xFFFF)($15)
    /* 2AA848 003AA848 0000A2D8 */  lqc2       $vf2, 0x0($5)
    /* 2AA84C 003AA84C 000083D8 */  lqc2       $vf3, 0x0($4)
    /* 2AA850 003AA850 2C09C24B */  vsub.xyz   $vf4, $vf1, $vf2
    /* 2AA854 003AA854 6809C24B */  vadd.xyz   $vf5, $vf1, $vf2
    /* 2AA858 003AA858 A809C24B */  vadd.xyz   $vf6, $vf1, $vf2
    /* 2AA85C 003AA85C EC09C24B */  vsub.xyz   $vf7, $vf1, $vf2
    /* 2AA860 003AA860 2C21C34B */  vsub.xyz   $vf4, $vf4, $vf3
    /* 2AA864 003AA864 6C29C34B */  vsub.xyz   $vf5, $vf5, $vf3
    /* 2AA868 003AA868 A831C34B */  vadd.xyz   $vf6, $vf6, $vf3
    /* 2AA86C 003AA86C E839C34B */  vadd.xyz   $vf7, $vf7, $vf3
    /* 2AA870 003AA870 0000C4F9 */  sqc2       $vf4, 0x0($14)
    /* 2AA874 003AA874 1000C5F9 */  sqc2       $vf5, 0x10($14)
    /* 2AA878 003AA878 2000C6F9 */  sqc2       $vf6, 0x20($14)
    /* 2AA87C 003AA87C 3000C7F9 */  sqc2       $vf7, 0x30($14)
    /* 2AA880 003AA880 0100C624 */  addiu      $6, $6, 0x1
    /* 2AA884 003AA884 4000CE25 */  addiu      $14, $14, 0x40
    /* 2AA888 003AA888 2A18D200 */  slt        $3, $6, $18
    /* 2AA88C 003AA88C EDFF6014 */  bnez       $3, .L003AA844
    /* 2AA890 003AA890 1000EF25 */   addiu     $15, $15, %lo(D_70000010)
    /* 2AA894 003AA894 00000000 */  nop
  .L003AA898:
    /* 2AA898 003AA898 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA89C 003AA89C 00D0648C */  lw         $4, -0x3000($3)
    /* 2AA8A0 003AA8A0 00018430 */  andi       $4, $4, 0x100
    /* 2AA8A4 003AA8A4 0C008010 */  beqz       $4, .L003AA8D8
    /* 2AA8A8 003AA8A8 00000000 */   nop
    /* 2AA8AC 003AA8AC 00010424 */  addiu      $4, $0, 0x100
    /* 2AA8B0 003AA8B0 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AA8B4 003AA8B4 0F000000 */  sync
    /* 2AA8B8 003AA8B8 0F040000 */  sync.p
  .L003AA8BC:
    /* 2AA8BC 003AA8BC 00000000 */  nop
    /* 2AA8C0 003AA8C0 00000000 */  nop
    /* 2AA8C4 003AA8C4 00000000 */  nop
    /* 2AA8C8 003AA8C8 00000000 */  nop
    /* 2AA8CC 003AA8CC 00000000 */  nop
    /* 2AA8D0 003AA8D0 FAFF0041 */  bc0f       .L003AA8BC /* handwritten instruction */
    /* 2AA8D4 003AA8D4 00000000 */   nop
  .L003AA8D8:
    /* 2AA8D8 003AA8D8 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA8DC 003AA8DC 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AA8E0 003AA8E0 00018430 */  andi       $4, $4, 0x100
    /* 2AA8E4 003AA8E4 14008010 */  beqz       $4, .L003AA938
    /* 2AA8E8 003AA8E8 00000000 */   nop
    /* 2AA8EC 003AA8EC 00020424 */  addiu      $4, $0, 0x200
    /* 2AA8F0 003AA8F0 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AA8F4 003AA8F4 0F000000 */  sync
    /* 2AA8F8 003AA8F8 0F040000 */  sync.p
  .L003AA8FC:
    /* 2AA8FC 003AA8FC 00000000 */  nop
    /* 2AA900 003AA900 00000000 */  nop
    /* 2AA904 003AA904 00000000 */  nop
    /* 2AA908 003AA908 00000000 */  nop
    /* 2AA90C 003AA90C 00000000 */  nop
    /* 2AA910 003AA910 FAFF0041 */  bc0f       .L003AA8FC /* handwritten instruction */
    /* 2AA914 003AA914 00000000 */   nop
    /* 2AA918 003AA918 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AA91C:
    /* 2AA91C 003AA91C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AA920 003AA920 00018430 */  andi       $4, $4, 0x100
    /* 2AA924 003AA924 00000000 */  nop
    /* 2AA928 003AA928 00000000 */  nop
    /* 2AA92C 003AA92C 00000000 */  nop
    /* 2AA930 003AA930 FAFF8014 */  bnez       $4, .L003AA91C
    /* 2AA934 003AA934 00000000 */   nop
  .L003AA938:
    /* 2AA938 003AA938 00010624 */  addiu      $6, $0, 0x100
    /* 2AA93C 003AA93C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AA940 003AA940 C00C0524 */  addiu      $5, $0, 0xCC0
    /* 2AA944 003AA944 10E066AC */  sw         $6, -0x1FF0($3)
    /* 2AA948 003AA948 80201200 */  sll        $4, $18, 2
    /* 2AA94C 003AA94C 80D065AC */  sw         $5, -0x2F80($3)
    /* 2AA950 003AA950 10D070AC */  sw         $16, -0x2FF0($3)
    /* 2AA954 003AA954 20D064AC */  sw         $4, -0x2FE0($3)
    /* 2AA958 003AA958 00D066AC */  sw         $6, -0x3000($3)
    /* 2AA95C 003AA95C 0F000000 */  sync
    /* 2AA960 003AA960 0F040000 */  sync.p
    /* 2AA964 003AA964 1C000010 */  b          .L003AA9D8
    /* 2AA968 003AA968 00000000 */   nop
  .L003AA96C:
    /* 2AA96C 003AA96C 2A081200 */  slt        $1, $0, $18
    /* 2AA970 003AA970 19002010 */  beqz       $1, .L003AA9D8
    /* 2AA974 003AA974 2D400000 */   daddu     $8, $0, $0
    /* 2AA978 003AA978 80200300 */  sll        $4, $3, 2
    /* 2AA97C 003AA97C 5000A627 */  addiu      $6, $29, 0x50
    /* 2AA980 003AA980 4000A527 */  addiu      $5, $29, 0x40
  .L003AA984:
    /* 2AA984 003AA984 000021DA */  lqc2       $vf1, 0x0($17)
    /* 2AA988 003AA988 0000C2D8 */  lqc2       $vf2, 0x0($6)
    /* 2AA98C 003AA98C 0000A3D8 */  lqc2       $vf3, 0x0($5)
    /* 2AA990 003AA990 2C09C24B */  vsub.xyz   $vf4, $vf1, $vf2
    /* 2AA994 003AA994 6809C24B */  vadd.xyz   $vf5, $vf1, $vf2
    /* 2AA998 003AA998 A809C24B */  vadd.xyz   $vf6, $vf1, $vf2
    /* 2AA99C 003AA99C EC09C24B */  vsub.xyz   $vf7, $vf1, $vf2
    /* 2AA9A0 003AA9A0 2C21C34B */  vsub.xyz   $vf4, $vf4, $vf3
    /* 2AA9A4 003AA9A4 6C29C34B */  vsub.xyz   $vf5, $vf5, $vf3
    /* 2AA9A8 003AA9A8 A831C34B */  vadd.xyz   $vf6, $vf6, $vf3
    /* 2AA9AC 003AA9AC E839C34B */  vadd.xyz   $vf7, $vf7, $vf3
    /* 2AA9B0 003AA9B0 000004FA */  sqc2       $vf4, 0x0($16)
    /* 2AA9B4 003AA9B4 100005FA */  sqc2       $vf5, 0x10($16)
    /* 2AA9B8 003AA9B8 200006FA */  sqc2       $vf6, 0x20($16)
    /* 2AA9BC 003AA9BC 300007FA */  sqc2       $vf7, 0x30($16)
    /* 2AA9C0 003AA9C0 01000825 */  addiu      $8, $8, 0x1
    /* 2AA9C4 003AA9C4 21800402 */  addu       $16, $16, $4
    /* 2AA9C8 003AA9C8 2A181201 */  slt        $3, $8, $18
    /* 2AA9CC 003AA9CC EDFF6014 */  bnez       $3, .L003AA984
    /* 2AA9D0 003AA9D0 21882702 */   addu      $17, $17, $7
    /* 2AA9D4 003AA9D4 00000000 */  nop
  .L003AA9D8:
    /* 2AA9D8 003AA9D8 3000BFDF */  ld         $31, 0x30($29)
    /* 2AA9DC 003AA9DC 2000B27B */  lq         $18, 0x20($29)
    /* 2AA9E0 003AA9E0 1000B17B */  lq         $17, 0x10($29)
    /* 2AA9E4 003AA9E4 0000B07B */  lq         $16, 0x0($29)
    /* 2AA9E8 003AA9E8 0800E003 */  jr         $31
    /* 2AA9EC 003AA9EC 6000BD27 */   addiu     $29, $29, 0x60
.size func_003aa370, 0x680
