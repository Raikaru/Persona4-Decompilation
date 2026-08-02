.section .text
.set noat
.set noreorder
glabel func_002af3e0
    /* 1AF3E0 002AF3E0 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 1AF3E4 002AF3E4 7000BFFF */  sd         $31, 0x70($29)
    /* 1AF3E8 002AF3E8 6000B57F */  sq         $21, 0x60($29)
    /* 1AF3EC 002AF3EC 5000B47F */  sq         $20, 0x50($29)
    /* 1AF3F0 002AF3F0 4000B37F */  sq         $19, 0x40($29)
    /* 1AF3F4 002AF3F4 3000B27F */  sq         $18, 0x30($29)
    /* 1AF3F8 002AF3F8 2000B17F */  sq         $17, 0x20($29)
    /* 1AF3FC 002AF3FC 1000B07F */  sq         $16, 0x10($29)
    /* 1AF400 002AF400 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1AF404 002AF404 2DA0A000 */  daddu      $20, $5, $0
    /* 1AF408 002AF408 3800918C */  lw         $17, 0x38($4)
    /* 1AF40C 002AF40C CC00248E */  lw         $4, 0xCC($17)
    /* 1AF410 002AF410 14CF0A0C */  jal        func_002b3c50
    /* 1AF414 002AF414 00000000 */   nop
    /* 1AF418 002AF418 2D800000 */  daddu      $16, $0, $0
    /* 1AF41C 002AF41C 1B000010 */  b          .L002AF48C
    /* 1AF420 002AF420 00000000 */   nop
  .L002AF424:
    /* 1AF424 002AF424 2D280000 */  daddu      $5, $0, $0
    /* 1AF428 002AF428 50070224 */  addiu      $2, $0, 0x750
    /* 1AF42C 002AF42C 18206200 */  mult       $4, $3, $2
    /* 1AF430 002AF430 7F00023C */  lui        $2, %hi(D_007E8C00)
    /* 1AF434 002AF434 008C4224 */  addiu      $2, $2, %lo(D_007E8C00)
    /* 1AF438 002AF438 21204400 */  addu       $4, $2, $4
    /* 1AF43C 002AF43C 4800828C */  lw         $2, 0x48($4)
    /* 1AF440 002AF440 05004010 */  beqz       $2, .L002AF458
    /* 1AF444 002AF444 00000000 */   nop
    /* 1AF448 002AF448 5400828C */  lw         $2, 0x54($4)
    /* 1AF44C 002AF44C 02004010 */  beqz       $2, .L002AF458
    /* 1AF450 002AF450 00000000 */   nop
    /* 1AF454 002AF454 01000524 */  addiu      $5, $0, 0x1
  .L002AF458:
    /* 1AF458 002AF458 2B200500 */  sltu       $4, $0, $5
    /* 1AF45C 002AF45C 01000224 */  addiu      $2, $0, 0x1
    /* 1AF460 002AF460 07008214 */  bne        $4, $2, .L002AF480
    /* 1AF464 002AF464 00000000 */   nop
    /* 1AF468 002AF468 80100300 */  sll        $2, $3, 2
    /* 1AF46C 002AF46C 21102202 */  addu       $2, $17, $2
    /* 1AF470 002AF470 D800448C */  lw         $4, 0xD8($2)
    /* 1AF474 002AF474 2D288002 */  daddu      $5, $20, $0
    /* 1AF478 002AF478 B0D20A0C */  jal        func_002b4ac0
    /* 1AF47C 002AF47C 00000000 */   nop
  .L002AF480:
    /* 1AF480 002AF480 01000226 */  addiu      $2, $16, 0x1
    /* 1AF484 002AF484 3C840200 */  dsll32     $16, $2, 16
    /* 1AF488 002AF488 3F841000 */  dsra32     $16, $16, 16
  .L002AF48C:
    /* 1AF48C 002AF48C 3C1C1000 */  dsll32     $3, $16, 16
    /* 1AF490 002AF490 3F1C0300 */  dsra32     $3, $3, 16
    /* 1AF494 002AF494 0F006228 */  slti       $2, $3, 0xF
    /* 1AF498 002AF498 E2FF4014 */  bnez       $2, .L002AF424
    /* 1AF49C 002AF49C 00000000 */   nop
    /* 1AF4A0 002AF4A0 2D800000 */  daddu      $16, $0, $0
    /* 1AF4A4 002AF4A4 15000010 */  b          .L002AF4FC
    /* 1AF4A8 002AF4A8 00000000 */   nop
  .L002AF4AC:
    /* 1AF4AC 002AF4AC 00110300 */  sll        $2, $3, 4
    /* 1AF4B0 002AF4B0 23204300 */  subu       $4, $2, $3
    /* 1AF4B4 002AF4B4 80100400 */  sll        $2, $4, 2
    /* 1AF4B8 002AF4B8 23104400 */  subu       $2, $2, $4
    /* 1AF4BC 002AF4BC C0200200 */  sll        $4, $2, 3
    /* 1AF4C0 002AF4C0 7F00023C */  lui        $2, %hi(D_007E80A0)
    /* 1AF4C4 002AF4C4 A0804224 */  addiu      $2, $2, %lo(D_007E80A0)
    /* 1AF4C8 002AF4C8 21104400 */  addu       $2, $2, $4
    /* 1AF4CC 002AF4CC 0000428C */  lw         $2, 0x0($2)
    /* 1AF4D0 002AF4D0 07004010 */  beqz       $2, .L002AF4F0
    /* 1AF4D4 002AF4D4 00000000 */   nop
    /* 1AF4D8 002AF4D8 80100300 */  sll        $2, $3, 2
    /* 1AF4DC 002AF4DC 21102202 */  addu       $2, $17, $2
    /* 1AF4E0 002AF4E0 1401448C */  lw         $4, 0x114($2)
    /* 1AF4E4 002AF4E4 2D288002 */  daddu      $5, $20, $0
    /* 1AF4E8 002AF4E8 40D40A0C */  jal        func_002b5100
    /* 1AF4EC 002AF4EC 00000000 */   nop
  .L002AF4F0:
    /* 1AF4F0 002AF4F0 01000226 */  addiu      $2, $16, 0x1
    /* 1AF4F4 002AF4F4 3C840200 */  dsll32     $16, $2, 16
    /* 1AF4F8 002AF4F8 3F841000 */  dsra32     $16, $16, 16
  .L002AF4FC:
    /* 1AF4FC 002AF4FC 3C1C1000 */  dsll32     $3, $16, 16
    /* 1AF500 002AF500 3F1C0300 */  dsra32     $3, $3, 16
    /* 1AF504 002AF504 08006228 */  slti       $2, $3, 0x8
    /* 1AF508 002AF508 E8FF4014 */  bnez       $2, .L002AF4AC
    /* 1AF50C 002AF50C 00000000 */   nop
    /* 1AF510 002AF510 2D800000 */  daddu      $16, $0, $0
    /* 1AF514 002AF514 0C000010 */  b          .L002AF548
    /* 1AF518 002AF518 00000000 */   nop
  .L002AF51C:
    /* 1AF51C 002AF51C 80100300 */  sll        $2, $3, 2
    /* 1AF520 002AF520 21102202 */  addu       $2, $17, $2
    /* 1AF524 002AF524 D000448C */  lw         $4, 0xD0($2)
    /* 1AF528 002AF528 04008010 */  beqz       $4, .L002AF53C
    /* 1AF52C 002AF52C 00000000 */   nop
    /* 1AF530 002AF530 2D288002 */  daddu      $5, $20, $0
    /* 1AF534 002AF534 90D00A0C */  jal        func_002b4240
    /* 1AF538 002AF538 00000000 */   nop
  .L002AF53C:
    /* 1AF53C 002AF53C 01000226 */  addiu      $2, $16, 0x1
    /* 1AF540 002AF540 3C840200 */  dsll32     $16, $2, 16
    /* 1AF544 002AF544 3F841000 */  dsra32     $16, $16, 16
  .L002AF548:
    /* 1AF548 002AF548 3C1C1000 */  dsll32     $3, $16, 16
    /* 1AF54C 002AF54C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1AF550 002AF550 02006228 */  slti       $2, $3, 0x2
    /* 1AF554 002AF554 F1FF4014 */  bnez       $2, .L002AF51C
    /* 1AF558 002AF558 00000000 */   nop
    /* 1AF55C 002AF55C 64B580AF */  sw         $0, -0x4A9C($28)
    /* 1AF560 002AF560 640720A6 */  sh         $0, 0x764($17)
    /* 1AF564 002AF564 660720A6 */  sh         $0, 0x766($17)
    /* 1AF568 002AF568 2D900000 */  daddu      $18, $0, $0
    /* 1AF56C 002AF56C 26000010 */  b          .L002AF608
    /* 1AF570 002AF570 00000000 */   nop
  .L002AF574:
    /* 1AF574 002AF574 2D980000 */  daddu      $19, $0, $0
    /* 1AF578 002AF578 80110300 */  sll        $2, $3, 6
    /* 1AF57C 002AF57C 21802202 */  addu       $16, $17, $2
    /* 1AF580 002AF580 19000010 */  b          .L002AF5E8
    /* 1AF584 002AF584 00000000 */   nop
  .L002AF588:
    /* 1AF588 002AF588 80100300 */  sll        $2, $3, 2
    /* 1AF58C 002AF58C 21100202 */  addu       $2, $16, $2
    /* 1AF590 002AF590 4801448C */  lw         $4, 0x148($2)
    /* 1AF594 002AF594 2449110C */  jal        func_00452490
    /* 1AF598 002AF598 00000000 */   nop
    /* 1AF59C 002AF59C 01000324 */  addiu      $3, $0, 0x1
    /* 1AF5A0 002AF5A0 0E004314 */  bne        $2, $3, .L002AF5DC
    /* 1AF5A4 002AF5A4 00000000 */   nop
    /* 1AF5A8 002AF5A8 3C141300 */  dsll32     $2, $19, 16
    /* 1AF5AC 002AF5AC 3F140200 */  dsra32     $2, $2, 16
    /* 1AF5B0 002AF5B0 80100200 */  sll        $2, $2, 2
    /* 1AF5B4 002AF5B4 21100202 */  addu       $2, $16, $2
    /* 1AF5B8 002AF5B8 48015524 */  addiu      $21, $2, 0x148
    /* 1AF5BC 002AF5BC 4801448C */  lw         $4, 0x148($2)
    /* 1AF5C0 002AF5C0 2D288002 */  daddu      $5, $20, $0
    /* 1AF5C4 002AF5C4 3CC40A0C */  jal        func_002b10f0
    /* 1AF5C8 002AF5C8 00000000 */   nop
    /* 1AF5CC 002AF5CC 0000A48E */  lw         $4, 0x0($21)
    /* 1AF5D0 002AF5D0 2D280000 */  daddu      $5, $0, $0
    /* 1AF5D4 002AF5D4 34C40A0C */  jal        func_002b10d0
    /* 1AF5D8 002AF5D8 00000000 */   nop
  .L002AF5DC:
    /* 1AF5DC 002AF5DC 01006226 */  addiu      $2, $19, 0x1
    /* 1AF5E0 002AF5E0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1AF5E4 002AF5E4 3F9C1300 */  dsra32     $19, $19, 16
  .L002AF5E8:
    /* 1AF5E8 002AF5E8 3C1C1300 */  dsll32     $3, $19, 16
    /* 1AF5EC 002AF5EC 3F1C0300 */  dsra32     $3, $3, 16
    /* 1AF5F0 002AF5F0 10006228 */  slti       $2, $3, 0x10
    /* 1AF5F4 002AF5F4 E4FF4014 */  bnez       $2, .L002AF588
    /* 1AF5F8 002AF5F8 00000000 */   nop
    /* 1AF5FC 002AF5FC 01004226 */  addiu      $2, $18, 0x1
    /* 1AF600 002AF600 3C940200 */  dsll32     $18, $2, 16
    /* 1AF604 002AF604 3F941200 */  dsra32     $18, $18, 16
  .L002AF608:
    /* 1AF608 002AF608 3C1C1200 */  dsll32     $3, $18, 16
    /* 1AF60C 002AF60C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1AF610 002AF610 18006228 */  slti       $2, $3, 0x18
    /* 1AF614 002AF614 D7FF4014 */  bnez       $2, .L002AF574
    /* 1AF618 002AF618 00000000 */   nop
    /* 1AF61C 002AF61C 3C161400 */  dsll32     $2, $20, 24
    /* 1AF620 002AF620 3F160200 */  dsra32     $2, $2, 24
    /* 1AF624 002AF624 78004014 */  bnez       $2, .L002AF808
    /* 1AF628 002AF628 00000000 */   nop
    /* 1AF62C 002AF62C 02000224 */  addiu      $2, $0, 0x2
    /* 1AF630 002AF630 040022A2 */  sb         $2, 0x4($17)
    /* 1AF634 002AF634 B80020A2 */  sb         $0, 0xB8($17)
    /* 1AF638 002AF638 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 1AF63C 002AF63C 00608244 */  mtc1       $2, $f12
    /* 1AF640 002AF640 CB43023C */  lui        $2, (0x43CB0000 >> 16)
    /* 1AF644 002AF644 00688244 */  mtc1       $2, $f13
    /* 1AF648 002AF648 B800A427 */  addiu      $4, $29, 0xB8
    /* 1AF64C 002AF64C 5CCA0A0C */  jal        func_002b2970
    /* 1AF650 002AF650 00000000 */   nop
    /* 1AF654 002AF654 B800A1C7 */  lwc1       $f1, 0xB8($29)
    /* 1AF658 002AF658 BC00A0C7 */  lwc1       $f0, 0xBC($29)
    /* 1AF65C 002AF65C C800A1E7 */  swc1       $f1, 0xC8($29)
    /* 1AF660 002AF660 CC00A0E7 */  swc1       $f0, 0xCC($29)
    /* 1AF664 002AF664 54B5848F */  lw         $4, -0x4AAC($28)
    /* 1AF668 002AF668 0C000524 */  addiu      $5, $0, 0xC
    /* 1AF66C 002AF66C 80B4110C */  jal        func_0046d200
    /* 1AF670 002AF670 00000000 */   nop
    /* 1AF674 002AF674 2D804000 */  daddu      $16, $2, $0
    /* 1AF678 002AF678 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1AF67C 002AF67C 00608244 */  mtc1       $2, $f12
    /* 1AF680 002AF680 4807248E */  lw         $4, 0x748($17)
    /* 1AF684 002AF684 46630046 */  mov.s      $f13, $f12
    /* 1AF688 002AF688 86630046 */  mov.s      $f14, $f12
    /* 1AF68C 002AF68C 04858FC7 */  lwc1       $f15, -0x7AFC($28)
    /* 1AF690 002AF690 2D280000 */  daddu      $5, $0, $0
    /* 1AF694 002AF694 03000624 */  addiu      $6, $0, 0x3
    /* 1AF698 002AF698 2D380000 */  daddu      $7, $0, $0
    /* 1AF69C 002AF69C B0DA0A0C */  jal        func_002b6ac0
    /* 1AF6A0 002AF6A0 00000000 */   nop
    /* 1AF6A4 002AF6A4 2D200002 */  daddu      $4, $16, $0
    /* 1AF6A8 002AF6A8 BCAC110C */  jal        func_0046b2f0
    /* 1AF6AC 002AF6AC 00000000 */   nop
    /* 1AF6B0 002AF6B0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1AF6B4 002AF6B4 00088244 */  mtc1       $2, $f1
    /* 1AF6B8 002AF6B8 00000000 */  nop
    /* 1AF6BC 002AF6BC 43000146 */  div.s      $f1, $f0, $f1
    /* 1AF6C0 002AF6C0 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* 1AF6C4 002AF6C4 40030146 */  add.s      $f13, $f0, $f1
    /* 1AF6C8 002AF6C8 B000A427 */  addiu      $4, $29, 0xB0
    /* 1AF6CC 002AF6CC C800ACC7 */  lwc1       $f12, 0xC8($29)
    /* 1AF6D0 002AF6D0 5CCA0A0C */  jal        func_002b2970
    /* 1AF6D4 002AF6D4 00000000 */   nop
    /* 1AF6D8 002AF6D8 4807248E */  lw         $4, 0x748($17)
    /* 1AF6DC 002AF6DC C800A5DF */  ld         $5, 0xC8($29)
    /* 1AF6E0 002AF6E0 B000A6DF */  ld         $6, 0xB0($29)
    /* 1AF6E4 002AF6E4 2D380000 */  daddu      $7, $0, $0
    /* 1AF6E8 002AF6E8 03000824 */  addiu      $8, $0, 0x3
    /* 1AF6EC 002AF6EC 2D480000 */  daddu      $9, $0, $0
    /* 1AF6F0 002AF6F0 6CDA0A0C */  jal        func_002b69b0
    /* 1AF6F4 002AF6F4 00000000 */   nop
    /* 1AF6F8 002AF6F8 4807248E */  lw         $4, 0x748($17)
    /* 1AF6FC 002AF6FC FF000524 */  addiu      $5, $0, 0xFF
    /* 1AF700 002AF700 2D300000 */  daddu      $6, $0, $0
    /* 1AF704 002AF704 2D380000 */  daddu      $7, $0, $0
    /* 1AF708 002AF708 2D400000 */  daddu      $8, $0, $0
    /* 1AF70C 002AF70C 03000924 */  addiu      $9, $0, 0x3
    /* 1AF710 002AF710 90DA0A0C */  jal        func_002b6a40
    /* 1AF714 002AF714 00000000 */   nop
    /* 1AF718 002AF718 2D200002 */  daddu      $4, $16, $0
    /* 1AF71C 002AF71C A0B4110C */  jal        func_0046d280
    /* 1AF720 002AF720 00000000 */   nop
    /* 1AF724 002AF724 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1AF728 002AF728 00608244 */  mtc1       $2, $f12
    /* 1AF72C 002AF72C CB43023C */  lui        $2, (0x43CB0000 >> 16)
    /* 1AF730 002AF730 00688244 */  mtc1       $2, $f13
    /* 1AF734 002AF734 C800A427 */  addiu      $4, $29, 0xC8
    /* 1AF738 002AF738 5CCA0A0C */  jal        func_002b2970
    /* 1AF73C 002AF73C 00000000 */   nop
    /* 1AF740 002AF740 54B5848F */  lw         $4, -0x4AAC($28)
    /* 1AF744 002AF744 0D000524 */  addiu      $5, $0, 0xD
    /* 1AF748 002AF748 80B4110C */  jal        func_0046d200
    /* 1AF74C 002AF74C 00000000 */   nop
    /* 1AF750 002AF750 2D804000 */  daddu      $16, $2, $0
    /* 1AF754 002AF754 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1AF758 002AF758 00608244 */  mtc1       $2, $f12
    /* 1AF75C 002AF75C 4C07248E */  lw         $4, 0x74C($17)
    /* 1AF760 002AF760 46630046 */  mov.s      $f13, $f12
    /* 1AF764 002AF764 86630046 */  mov.s      $f14, $f12
    /* 1AF768 002AF768 04858FC7 */  lwc1       $f15, -0x7AFC($28)
    /* 1AF76C 002AF76C 2D280000 */  daddu      $5, $0, $0
    /* 1AF770 002AF770 03000624 */  addiu      $6, $0, 0x3
    /* 1AF774 002AF774 2D380000 */  daddu      $7, $0, $0
    /* 1AF778 002AF778 B0DA0A0C */  jal        func_002b6ac0
    /* 1AF77C 002AF77C 00000000 */   nop
    /* 1AF780 002AF780 2D200002 */  daddu      $4, $16, $0
    /* 1AF784 002AF784 BCAC110C */  jal        func_0046b2f0
    /* 1AF788 002AF788 00000000 */   nop
    /* 1AF78C 002AF78C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1AF790 002AF790 00088244 */  mtc1       $2, $f1
    /* 1AF794 002AF794 00000000 */  nop
    /* 1AF798 002AF798 43000146 */  div.s      $f1, $f0, $f1
    /* 1AF79C 002AF79C CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* 1AF7A0 002AF7A0 40030146 */  add.s      $f13, $f0, $f1
    /* 1AF7A4 002AF7A4 A800A427 */  addiu      $4, $29, 0xA8
    /* 1AF7A8 002AF7A8 C800ACC7 */  lwc1       $f12, 0xC8($29)
    /* 1AF7AC 002AF7AC 5CCA0A0C */  jal        func_002b2970
    /* 1AF7B0 002AF7B0 00000000 */   nop
    /* 1AF7B4 002AF7B4 4C07248E */  lw         $4, 0x74C($17)
    /* 1AF7B8 002AF7B8 C800A5DF */  ld         $5, 0xC8($29)
    /* 1AF7BC 002AF7BC A800A6DF */  ld         $6, 0xA8($29)
    /* 1AF7C0 002AF7C0 2D380000 */  daddu      $7, $0, $0
    /* 1AF7C4 002AF7C4 03000824 */  addiu      $8, $0, 0x3
    /* 1AF7C8 002AF7C8 2D480000 */  daddu      $9, $0, $0
    /* 1AF7CC 002AF7CC 6CDA0A0C */  jal        func_002b69b0
    /* 1AF7D0 002AF7D0 00000000 */   nop
    /* 1AF7D4 002AF7D4 4C07248E */  lw         $4, 0x74C($17)
    /* 1AF7D8 002AF7D8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1AF7DC 002AF7DC 2D300000 */  daddu      $6, $0, $0
    /* 1AF7E0 002AF7E0 2D380000 */  daddu      $7, $0, $0
    /* 1AF7E4 002AF7E4 2D400000 */  daddu      $8, $0, $0
    /* 1AF7E8 002AF7E8 03000924 */  addiu      $9, $0, 0x3
    /* 1AF7EC 002AF7EC 90DA0A0C */  jal        func_002b6a40
    /* 1AF7F0 002AF7F0 00000000 */   nop
    /* 1AF7F4 002AF7F4 2D200002 */  daddu      $4, $16, $0
    /* 1AF7F8 002AF7F8 A0B4110C */  jal        func_0046d280
    /* 1AF7FC 002AF7FC 00000000 */   nop
    /* 1AF800 002AF800 CF000010 */  b          .L002AFB40
    /* 1AF804 002AF804 00000000 */   nop
  .L002AF808:
    /* 1AF808 002AF808 03000224 */  addiu      $2, $0, 0x3
    /* 1AF80C 002AF80C 040022A2 */  sb         $2, 0x4($17)
    /* 1AF810 002AF810 01000224 */  addiu      $2, $0, 0x1
    /* 1AF814 002AF814 B80022A2 */  sb         $2, 0xB8($17)
    /* 1AF818 002AF818 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 1AF81C 002AF81C 00608244 */  mtc1       $2, $f12
    /* 1AF820 002AF820 CB43023C */  lui        $2, (0x43CB0000 >> 16)
    /* 1AF824 002AF824 00688244 */  mtc1       $2, $f13
    /* 1AF828 002AF828 A000A427 */  addiu      $4, $29, 0xA0
    /* 1AF82C 002AF82C 5CCA0A0C */  jal        func_002b2970
    /* 1AF830 002AF830 00000000 */   nop
    /* 1AF834 002AF834 A000A1C7 */  lwc1       $f1, 0xA0($29)
    /* 1AF838 002AF838 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* 1AF83C 002AF83C C000A1E7 */  swc1       $f1, 0xC0($29)
    /* 1AF840 002AF840 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* 1AF844 002AF844 54B5848F */  lw         $4, -0x4AAC($28)
    /* 1AF848 002AF848 0C000524 */  addiu      $5, $0, 0xC
    /* 1AF84C 002AF84C 80B4110C */  jal        func_0046d200
    /* 1AF850 002AF850 00000000 */   nop
    /* 1AF854 002AF854 2D804000 */  daddu      $16, $2, $0
    /* 1AF858 002AF858 68EA0234 */  ori        $2, $0, 0xEA68
    /* 1AF85C 002AF85C 00008244 */  mtc1       $2, $f0
    /* 1AF860 002AF860 00000000 */  nop
    /* 1AF864 002AF864 20038046 */  cvt.s.w    $f12, $f0
    /* 1AF868 002AF868 4807248E */  lw         $4, 0x748($17)
    /* 1AF86C 002AF86C C000A5DF */  ld         $5, 0xC0($29)
    /* 1AF870 002AF870 4D000624 */  addiu      $6, $0, 0x4D
    /* 1AF874 002AF874 F8DA0A0C */  jal        func_002b6be0
    /* 1AF878 002AF878 00000000 */   nop
    /* 1AF87C 002AF87C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1AF880 002AF880 00608244 */  mtc1       $2, $f12
    /* 1AF884 002AF884 4807248E */  lw         $4, 0x748($17)
    /* 1AF888 002AF888 46630046 */  mov.s      $f13, $f12
    /* 1AF88C 002AF88C 04858EC7 */  lwc1       $f14, -0x7AFC($28)
    /* 1AF890 002AF890 C6630046 */  mov.s      $f15, $f12
    /* 1AF894 002AF894 2D280000 */  daddu      $5, $0, $0
    /* 1AF898 002AF898 05000624 */  addiu      $6, $0, 0x5
    /* 1AF89C 002AF89C 2D380000 */  daddu      $7, $0, $0
    /* 1AF8A0 002AF8A0 B0DA0A0C */  jal        func_002b6ac0
    /* 1AF8A4 002AF8A4 00000000 */   nop
    /* 1AF8A8 002AF8A8 2D200002 */  daddu      $4, $16, $0
    /* 1AF8AC 002AF8AC BCAC110C */  jal        func_0046b2f0
    /* 1AF8B0 002AF8B0 00000000 */   nop
    /* 1AF8B4 002AF8B4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1AF8B8 002AF8B8 00088244 */  mtc1       $2, $f1
    /* 1AF8BC 002AF8BC 00000000 */  nop
    /* 1AF8C0 002AF8C0 43000146 */  div.s      $f1, $f0, $f1
    /* 1AF8C4 002AF8C4 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* 1AF8C8 002AF8C8 40030146 */  add.s      $f13, $f0, $f1
    /* 1AF8CC 002AF8CC 9800A427 */  addiu      $4, $29, 0x98
    /* 1AF8D0 002AF8D0 C000ACC7 */  lwc1       $f12, 0xC0($29)
    /* 1AF8D4 002AF8D4 5CCA0A0C */  jal        func_002b2970
    /* 1AF8D8 002AF8D8 00000000 */   nop
    /* 1AF8DC 002AF8DC 4807248E */  lw         $4, 0x748($17)
    /* 1AF8E0 002AF8E0 9800A5DF */  ld         $5, 0x98($29)
    /* 1AF8E4 002AF8E4 C000A6DF */  ld         $6, 0xC0($29)
    /* 1AF8E8 002AF8E8 2D380000 */  daddu      $7, $0, $0
    /* 1AF8EC 002AF8EC 05000824 */  addiu      $8, $0, 0x5
    /* 1AF8F0 002AF8F0 2D480000 */  daddu      $9, $0, $0
    /* 1AF8F4 002AF8F4 6CDA0A0C */  jal        func_002b69b0
    /* 1AF8F8 002AF8F8 00000000 */   nop
    /* 1AF8FC 002AF8FC 4807248E */  lw         $4, 0x748($17)
    /* 1AF900 002AF900 2D280000 */  daddu      $5, $0, $0
    /* 1AF904 002AF904 FF000624 */  addiu      $6, $0, 0xFF
    /* 1AF908 002AF908 2D380000 */  daddu      $7, $0, $0
    /* 1AF90C 002AF90C 2D400000 */  daddu      $8, $0, $0
    /* 1AF910 002AF910 2D480000 */  daddu      $9, $0, $0
    /* 1AF914 002AF914 90DA0A0C */  jal        func_002b6a40
    /* 1AF918 002AF918 00000000 */   nop
    /* 1AF91C 002AF91C 2D200002 */  daddu      $4, $16, $0
    /* 1AF920 002AF920 A0B4110C */  jal        func_0046d280
    /* 1AF924 002AF924 00000000 */   nop
    /* 1AF928 002AF928 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1AF92C 002AF92C 00608244 */  mtc1       $2, $f12
    /* 1AF930 002AF930 CB43023C */  lui        $2, (0x43CB0000 >> 16)
    /* 1AF934 002AF934 00688244 */  mtc1       $2, $f13
    /* 1AF938 002AF938 C000A427 */  addiu      $4, $29, 0xC0
    /* 1AF93C 002AF93C 5CCA0A0C */  jal        func_002b2970
    /* 1AF940 002AF940 00000000 */   nop
    /* 1AF944 002AF944 54B5848F */  lw         $4, -0x4AAC($28)
    /* 1AF948 002AF948 0D000524 */  addiu      $5, $0, 0xD
    /* 1AF94C 002AF94C 80B4110C */  jal        func_0046d200
    /* 1AF950 002AF950 00000000 */   nop
    /* 1AF954 002AF954 2D804000 */  daddu      $16, $2, $0
    /* 1AF958 002AF958 68EA0234 */  ori        $2, $0, 0xEA68
    /* 1AF95C 002AF95C 00008244 */  mtc1       $2, $f0
    /* 1AF960 002AF960 00000000 */  nop
    /* 1AF964 002AF964 20038046 */  cvt.s.w    $f12, $f0
    /* 1AF968 002AF968 4C07248E */  lw         $4, 0x74C($17)
    /* 1AF96C 002AF96C C000A5DF */  ld         $5, 0xC0($29)
    /* 1AF970 002AF970 4D000624 */  addiu      $6, $0, 0x4D
    /* 1AF974 002AF974 F8DA0A0C */  jal        func_002b6be0
    /* 1AF978 002AF978 00000000 */   nop
    /* 1AF97C 002AF97C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1AF980 002AF980 00608244 */  mtc1       $2, $f12
    /* 1AF984 002AF984 4C07248E */  lw         $4, 0x74C($17)
    /* 1AF988 002AF988 46630046 */  mov.s      $f13, $f12
    /* 1AF98C 002AF98C 04858EC7 */  lwc1       $f14, -0x7AFC($28)
    /* 1AF990 002AF990 C6630046 */  mov.s      $f15, $f12
    /* 1AF994 002AF994 2D280000 */  daddu      $5, $0, $0
    /* 1AF998 002AF998 05000624 */  addiu      $6, $0, 0x5
    /* 1AF99C 002AF99C 2D380000 */  daddu      $7, $0, $0
    /* 1AF9A0 002AF9A0 B0DA0A0C */  jal        func_002b6ac0
    /* 1AF9A4 002AF9A4 00000000 */   nop
    /* 1AF9A8 002AF9A8 2D200002 */  daddu      $4, $16, $0
    /* 1AF9AC 002AF9AC BCAC110C */  jal        func_0046b2f0
    /* 1AF9B0 002AF9B0 00000000 */   nop
    /* 1AF9B4 002AF9B4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1AF9B8 002AF9B8 00088244 */  mtc1       $2, $f1
    /* 1AF9BC 002AF9BC 00000000 */  nop
    /* 1AF9C0 002AF9C0 43000146 */  div.s      $f1, $f0, $f1
    /* 1AF9C4 002AF9C4 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* 1AF9C8 002AF9C8 40030146 */  add.s      $f13, $f0, $f1
    /* 1AF9CC 002AF9CC 9000A427 */  addiu      $4, $29, 0x90
    /* 1AF9D0 002AF9D0 C000ACC7 */  lwc1       $f12, 0xC0($29)
    /* 1AF9D4 002AF9D4 5CCA0A0C */  jal        func_002b2970
    /* 1AF9D8 002AF9D8 00000000 */   nop
    /* 1AF9DC 002AF9DC 4C07248E */  lw         $4, 0x74C($17)
    /* 1AF9E0 002AF9E0 9000A5DF */  ld         $5, 0x90($29)
    /* 1AF9E4 002AF9E4 C000A6DF */  ld         $6, 0xC0($29)
    /* 1AF9E8 002AF9E8 2D380000 */  daddu      $7, $0, $0
    /* 1AF9EC 002AF9EC 05000824 */  addiu      $8, $0, 0x5
    /* 1AF9F0 002AF9F0 2D480000 */  daddu      $9, $0, $0
    /* 1AF9F4 002AF9F4 6CDA0A0C */  jal        func_002b69b0
    /* 1AF9F8 002AF9F8 00000000 */   nop
    /* 1AF9FC 002AF9FC 4C07248E */  lw         $4, 0x74C($17)
    /* 1AFA00 002AFA00 2D280000 */  daddu      $5, $0, $0
    /* 1AFA04 002AFA04 FF000624 */  addiu      $6, $0, 0xFF
    /* 1AFA08 002AFA08 2D380000 */  daddu      $7, $0, $0
    /* 1AFA0C 002AFA0C 2D400000 */  daddu      $8, $0, $0
    /* 1AFA10 002AFA10 2D480000 */  daddu      $9, $0, $0
    /* 1AFA14 002AFA14 90DA0A0C */  jal        func_002b6a40
    /* 1AFA18 002AFA18 00000000 */   nop
    /* 1AFA1C 002AFA1C 2D200002 */  daddu      $4, $16, $0
    /* 1AFA20 002AFA20 A0B4110C */  jal        func_0046d280
    /* 1AFA24 002AFA24 00000000 */   nop
    /* 1AFA28 002AFA28 2DA00000 */  daddu      $20, $0, $0
    /* 1AFA2C 002AFA2C 3F000010 */  b          .L002AFB2C
    /* 1AFA30 002AFA30 00000000 */   nop
  .L002AFA34:
    /* 1AFA34 002AFA34 2D980000 */  daddu      $19, $0, $0
    /* 1AFA38 002AFA38 3C241400 */  dsll32     $4, $20, 16
    /* 1AFA3C 002AFA3C 3F240400 */  dsra32     $4, $4, 16
    /* 1AFA40 002AFA40 80190400 */  sll        $3, $4, 6
    /* 1AFA44 002AFA44 21902302 */  addu       $18, $17, $3
    /* 1AFA48 002AFA48 40A80400 */  sll        $21, $4, 1
    /* 1AFA4C 002AFA4C 9041033C */  lui        $3, (0x41900000 >> 16)
    /* 1AFA50 002AFA50 00088344 */  mtc1       $3, $f1
    /* 1AFA54 002AFA54 00009444 */  mtc1       $20, $f0
    /* 1AFA58 002AFA58 00000000 */  nop
    /* 1AFA5C 002AFA5C 20008046 */  cvt.s.w    $f0, $f0
    /* 1AFA60 002AFA60 020D0046 */  mul.s      $f20, $f1, $f0
    /* 1AFA64 002AFA64 29000010 */  b          .L002AFB0C
    /* 1AFA68 002AFA68 00000000 */   nop
  .L002AFA6C:
    /* 1AFA6C 002AFA6C 80100400 */  sll        $2, $4, 2
    /* 1AFA70 002AFA70 21104202 */  addu       $2, $18, $2
    /* 1AFA74 002AFA74 48015024 */  addiu      $16, $2, 0x148
    /* 1AFA78 002AFA78 4801448C */  lw         $4, 0x148($2)
    /* 1AFA7C 002AFA7C 2449110C */  jal        func_00452490
    /* 1AFA80 002AFA80 00000000 */   nop
    /* 1AFA84 002AFA84 01000524 */  addiu      $5, $0, 0x1
    /* 1AFA88 002AFA88 1D004514 */  bne        $2, $5, .L002AFB00
    /* 1AFA8C 002AFA8C 00000000 */   nop
    /* 1AFA90 002AFA90 3C241300 */  dsll32     $4, $19, 16
    /* 1AFA94 002AFA94 3F240400 */  dsra32     $4, $4, 16
    /* 1AFA98 002AFA98 04108500 */  sllv       $2, $5, $4
    /* 1AFA9C 002AFA9C FFFF4330 */  andi       $3, $2, 0xFFFF
    /* 1AFAA0 002AFAA0 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AFAA4 002AFAA4 2110A202 */  addu       $2, $21, $2
    /* 1AFAA8 002AFAA8 00004294 */  lhu        $2, 0x0($2)
    /* 1AFAAC 002AFAAC 24106200 */  and        $2, $3, $2
    /* 1AFAB0 002AFAB0 07108200 */  srav       $2, $2, $4
    /* 1AFAB4 002AFAB4 04004514 */  bne        $2, $5, .L002AFAC8
    /* 1AFAB8 002AFAB8 00000000 */   nop
    /* 1AFABC 002AFABC 0000048E */  lw         $4, 0x0($16)
    /* 1AFAC0 002AFAC0 38C40A0C */  jal        func_002b10e0
    /* 1AFAC4 002AFAC4 00000000 */   nop
  .L002AFAC8:
    /* 1AFAC8 002AFAC8 9041023C */  lui        $2, (0x41900000 >> 16)
    /* 1AFACC 002AFACC 00088244 */  mtc1       $2, $f1
    /* 1AFAD0 002AFAD0 00009344 */  mtc1       $19, $f0
    /* 1AFAD4 002AFAD4 00000000 */  nop
    /* 1AFAD8 002AFAD8 20008046 */  cvt.s.w    $f0, $f0
    /* 1AFADC 002AFADC 420B0046 */  mul.s      $f13, $f1, $f0
    /* 1AFAE0 002AFAE0 8800A427 */  addiu      $4, $29, 0x88
    /* 1AFAE4 002AFAE4 06A30046 */  mov.s      $f12, $f20
    /* 1AFAE8 002AFAE8 5CCA0A0C */  jal        func_002b2970
    /* 1AFAEC 002AFAEC 00000000 */   nop
    /* 1AFAF0 002AFAF0 0000048E */  lw         $4, 0x0($16)
    /* 1AFAF4 002AFAF4 8800A5DF */  ld         $5, 0x88($29)
    /* 1AFAF8 002AFAF8 28C40A0C */  jal        func_002b10a0
    /* 1AFAFC 002AFAFC 00000000 */   nop
  .L002AFB00:
    /* 1AFB00 002AFB00 01006326 */  addiu      $3, $19, 0x1
    /* 1AFB04 002AFB04 3C9C0300 */  dsll32     $19, $3, 16
    /* 1AFB08 002AFB08 3F9C1300 */  dsra32     $19, $19, 16
  .L002AFB0C:
    /* 1AFB0C 002AFB0C 3C241300 */  dsll32     $4, $19, 16
    /* 1AFB10 002AFB10 3F240400 */  dsra32     $4, $4, 16
    /* 1AFB14 002AFB14 10008328 */  slti       $3, $4, 0x10
    /* 1AFB18 002AFB18 D4FF6014 */  bnez       $3, .L002AFA6C
    /* 1AFB1C 002AFB1C 00000000 */   nop
    /* 1AFB20 002AFB20 01008326 */  addiu      $3, $20, 0x1
    /* 1AFB24 002AFB24 3CA40300 */  dsll32     $20, $3, 16
    /* 1AFB28 002AFB28 3FA41400 */  dsra32     $20, $20, 16
  .L002AFB2C:
    /* 1AFB2C 002AFB2C 3C1C1400 */  dsll32     $3, $20, 16
    /* 1AFB30 002AFB30 3F1C0300 */  dsra32     $3, $3, 16
    /* 1AFB34 002AFB34 18006328 */  slti       $3, $3, 0x18
    /* 1AFB38 002AFB38 BEFF6014 */  bnez       $3, .L002AFA34
    /* 1AFB3C 002AFB3C 00000000 */   nop
  .L002AFB40:
    /* 1AFB40 002AFB40 7000BFDF */  ld         $31, 0x70($29)
    /* 1AFB44 002AFB44 6000B57B */  lq         $21, 0x60($29)
    /* 1AFB48 002AFB48 5000B47B */  lq         $20, 0x50($29)
    /* 1AFB4C 002AFB4C 4000B37B */  lq         $19, 0x40($29)
    /* 1AFB50 002AFB50 3000B27B */  lq         $18, 0x30($29)
    /* 1AFB54 002AFB54 2000B17B */  lq         $17, 0x20($29)
    /* 1AFB58 002AFB58 1000B07B */  lq         $16, 0x10($29)
    /* 1AFB5C 002AFB5C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1AFB60 002AFB60 D000BD27 */  addiu      $29, $29, 0xD0
    /* 1AFB64 002AFB64 0800E003 */  jr         $31
    /* 1AFB68 002AFB68 00000000 */   nop
    /* 1AFB6C 002AFB6C 00000000 */  nop
.size func_002af3e0, 0x790
