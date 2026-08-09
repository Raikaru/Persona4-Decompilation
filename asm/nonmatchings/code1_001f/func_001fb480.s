.section .text
.set noat
.set noreorder
glabel func_001fb480
    /* FB480 001FB480 60FEBD27 */  addiu      $29, $29, -0x1A0
    /* FB484 001FB484 9000BFFF */  sd         $31, 0x90($29)
    /* FB488 001FB488 8000B67F */  sq         $22, 0x80($29)
    /* FB48C 001FB48C 7000B57F */  sq         $21, 0x70($29)
    /* FB490 001FB490 6000B47F */  sq         $20, 0x60($29)
    /* FB494 001FB494 5000B37F */  sq         $19, 0x50($29)
    /* FB498 001FB498 4000B27F */  sq         $18, 0x40($29)
    /* FB49C 001FB49C 3000B17F */  sq         $17, 0x30($29)
    /* FB4A0 001FB4A0 2000B07F */  sq         $16, 0x20($29)
    /* FB4A4 001FB4A4 1800BAE7 */  swc1       $f26, 0x18($29)
    /* FB4A8 001FB4A8 1400B9E7 */  swc1       $f25, 0x14($29)
    /* FB4AC 001FB4AC 1000B8E7 */  swc1       $f24, 0x10($29)
    /* FB4B0 001FB4B0 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* FB4B4 001FB4B4 0800B6E7 */  swc1       $f22, 0x8($29)
    /* FB4B8 001FB4B8 0400B5E7 */  swc1       $f21, 0x4($29)
    /* FB4BC 001FB4BC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* FB4C0 001FB4C0 86660046 */  mov.s      $f26, $f12
    /* FB4C4 001FB4C4 2DA08000 */  daddu      $20, $4, $0
    /* FB4C8 001FB4C8 2D98A000 */  daddu      $19, $5, $0
    /* FB4CC 001FB4CC 2D90C000 */  daddu      $18, $6, $0
    /* FB4D0 001FB4D0 2D88E000 */  daddu      $17, $7, $0
    /* FB4D4 001FB4D4 485C110C */  jal        func_00457120
    /* FB4D8 001FB4D8 00000000 */   nop
    /* FB4DC 001FB4DC 2DB04000 */  daddu      $22, $2, $0
    /* FB4E0 001FB4E0 E006100C */  jal        func_00401b80
    /* FB4E4 001FB4E4 00000000 */   nop
    /* FB4E8 001FB4E8 2D804000 */  daddu      $16, $2, $0
    /* FB4EC 001FB4EC 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* FB4F0 001FB4F0 20008046 */  cvt.s.w    $f0, $f0
    /* FB4F4 001FB4F4 2044033C */  lui        $3, (0x44200000 >> 16)
    /* FB4F8 001FB4F8 00A88344 */  mtc1       $3, $f21
    /* FB4FC 001FB4FC 00000000 */  nop
    /* FB500 001FB500 43AE0046 */  div.s      $f25, $f21, $f0
    /* FB504 001FB504 100040C4 */  lwc1       $f0, 0x10($2)
    /* FB508 001FB508 20008046 */  cvt.s.w    $f0, $f0
    /* FB50C 001FB50C E043023C */  lui        $2, (0x43E00000 >> 16)
    /* FB510 001FB510 00A08244 */  mtc1       $2, $f20
    /* FB514 001FB514 00000000 */  nop
    /* FB518 001FB518 03A60046 */  div.s      $f24, $f20, $f0
    /* FB51C 001FB51C 00000000 */  nop
    /* FB520 001FB520 00288044 */  mtc1       $0, $f5
    /* FB524 001FB524 00000000 */  nop
    /* FB528 001FB528 32281A46 */  c.eq.s     $f5, $f26
    /* FB52C 001FB52C 05000045 */  bc1f       .L001FB544
    /* FB530 001FB530 00000000 */   nop
    /* FB534 001FB534 C62D0046 */  mov.s      $f23, $f5
    /* FB538 001FB538 862D0046 */  mov.s      $f22, $f5
    /* FB53C 001FB53C 13000010 */  b          .L001FB58C
    /* FB540 001FB540 00000000 */   nop
  .L001FB544:
    /* FB544 001FB544 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* FB548 001FB548 00208244 */  mtc1       $2, $f4
    /* FB54C 001FB54C 00000000 */  nop
    /* FB550 001FB550 07200046 */  neg.s      $f0, $f4
    /* FB554 001FB554 E88283C7 */  lwc1       $f3, -0x7D18($28)
    /* FB558 001FB558 18280346 */  adda.s     $f5, $f3
    /* FB55C 001FB55C DC051A46 */  madd.s     $f23, $f0, $f26
    /* FB560 001FB560 6043023C */  lui        $2, (0x43600000 >> 16)
    /* FB564 001FB564 00108244 */  mtc1       $2, $f2
    /* FB568 001FB568 00000000 */  nop
    /* FB56C 001FB56C 47100046 */  neg.s      $f1, $f2
    /* FB570 001FB570 EC8280C7 */  lwc1       $f0, -0x7D14($28)
    /* FB574 001FB574 18280046 */  adda.s     $f5, $f0
    /* FB578 001FB578 9C0D1A46 */  madd.s     $f22, $f1, $f26
    /* FB57C 001FB57C 18280346 */  adda.s     $f5, $f3
    /* FB580 001FB580 5C251A46 */  madd.s     $f21, $f4, $f26
    /* FB584 001FB584 18280046 */  adda.s     $f5, $f0
    /* FB588 001FB588 1C151A46 */  madd.s     $f20, $f2, $f26
  .L001FB58C:
    /* FB58C 001FB58C 8800153C */  lui        $21, %hi(D_00887300)
    /* FB590 001FB590 0073B526 */  addiu      $21, $21, %lo(D_00887300)
    /* FB594 001FB594 07000424 */  addiu      $4, $0, 0x7
    /* FB598 001FB598 02000524 */  addiu      $5, $0, 0x2
    /* FB59C 001FB59C 0000A28E */  lw         $2, 0x0($21)
    /* FB5A0 001FB5A0 09F84000 */  jalr       $2
    /* FB5A4 001FB5A4 00000000 */   nop
    /* FB5A8 001FB5A8 14000424 */  addiu      $4, $0, 0x14
    /* FB5AC 001FB5AC 01000524 */  addiu      $5, $0, 0x1
    /* FB5B0 001FB5B0 0000A28E */  lw         $2, 0x0($21)
    /* FB5B4 001FB5B4 09F84000 */  jalr       $2
    /* FB5B8 001FB5B8 00000000 */   nop
    /* FB5BC 001FB5BC 0E000424 */  addiu      $4, $0, 0xE
    /* FB5C0 001FB5C0 2D280000 */  daddu      $5, $0, $0
    /* FB5C4 001FB5C4 0000A28E */  lw         $2, 0x0($21)
    /* FB5C8 001FB5C8 09F84000 */  jalr       $2
    /* FB5CC 001FB5CC 00000000 */   nop
    /* FB5D0 001FB5D0 06000424 */  addiu      $4, $0, 0x6
    /* FB5D4 001FB5D4 2D280000 */  daddu      $5, $0, $0
    /* FB5D8 001FB5D8 0000A28E */  lw         $2, 0x0($21)
    /* FB5DC 001FB5DC 09F84000 */  jalr       $2
    /* FB5E0 001FB5E0 00000000 */   nop
    /* FB5E4 001FB5E4 08000424 */  addiu      $4, $0, 0x8
    /* FB5E8 001FB5E8 2D280000 */  daddu      $5, $0, $0
    /* FB5EC 001FB5EC 0000A28E */  lw         $2, 0x0($21)
    /* FB5F0 001FB5F0 09F84000 */  jalr       $2
    /* FB5F4 001FB5F4 00000000 */   nop
    /* FB5F8 001FB5F8 09000424 */  addiu      $4, $0, 0x9
    /* FB5FC 001FB5FC 2D282002 */  daddu      $5, $17, $0
    /* FB600 001FB600 0000A28E */  lw         $2, 0x0($21)
    /* FB604 001FB604 09F84000 */  jalr       $2
    /* FB608 001FB608 00000000 */   nop
    /* FB60C 001FB60C 0C000424 */  addiu      $4, $0, 0xC
    /* FB610 001FB610 01000524 */  addiu      $5, $0, 0x1
    /* FB614 001FB614 0000A28E */  lw         $2, 0x0($21)
    /* FB618 001FB618 09F84000 */  jalr       $2
    /* FB61C 001FB61C 00000000 */   nop
    /* FB620 001FB620 01000424 */  addiu      $4, $0, 0x1
    /* FB624 001FB624 2D280002 */  daddu      $5, $16, $0
    /* FB628 001FB628 0000A28E */  lw         $2, 0x0($21)
    /* FB62C 001FB62C 09F84000 */  jalr       $2
    /* FB630 001FB630 00000000 */   nop
    /* FB634 001FB634 02000424 */  addiu      $4, $0, 0x2
    /* FB638 001FB638 2D286002 */  daddu      $5, $19, $0
    /* FB63C 001FB63C 10D90F0C */  jal        func_003f6440
    /* FB640 001FB640 00000000 */   nop
    /* FB644 001FB644 03000424 */  addiu      $4, $0, 0x3
    /* FB648 001FB648 2D284002 */  daddu      $5, $18, $0
    /* FB64C 001FB64C 10D90F0C */  jal        func_003f6440
    /* FB650 001FB650 00000000 */   nop
    /* FB654 001FB654 8800023C */  lui        $2, %hi(D_008872FC)
    /* FB658 001FB658 FC7241C4 */  lwc1       $f1, %lo(D_008872FC)($2)
    /* FB65C 001FB65C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FB660 001FB660 00108244 */  mtc1       $2, $f2
    /* FB664 001FB664 8400C0C6 */  lwc1       $f0, 0x84($22)
    /* FB668 001FB668 03100046 */  div.s      $f0, $f2, $f0
    /* FB66C 001FB66C A000B7E7 */  swc1       $f23, 0xA0($29)
    /* FB670 001FB670 A400B6E7 */  swc1       $f22, 0xA4($29)
    /* FB674 001FB674 A800A1E7 */  swc1       $f1, 0xA8($29)
    /* FB678 001FB678 00008292 */  lbu        $2, 0x0($20)
    /* FB67C 001FB67C 06004004 */  bltz       $2, .L001FB698
    /* FB680 001FB680 00000000 */   nop
    /* FB684 001FB684 00108244 */  mtc1       $2, $f2
    /* FB688 001FB688 00000000 */  nop
    /* FB68C 001FB68C A0108046 */  cvt.s.w    $f2, $f2
    /* FB690 001FB690 08000010 */  b          .L001FB6B4
    /* FB694 001FB694 00000000 */   nop
  .L001FB698:
    /* FB698 001FB698 42180200 */  srl        $3, $2, 1
    /* FB69C 001FB69C 01004230 */  andi       $2, $2, 0x1
    /* FB6A0 001FB6A0 25186200 */  or         $3, $3, $2
    /* FB6A4 001FB6A4 00108344 */  mtc1       $3, $f2
    /* FB6A8 001FB6A8 00000000 */  nop
    /* FB6AC 001FB6AC A0108046 */  cvt.s.w    $f2, $f2
    /* FB6B0 001FB6B0 80100246 */  add.s      $f2, $f2, $f2
  .L001FB6B4:
    /* FB6B4 001FB6B4 C000A2E7 */  swc1       $f2, 0xC0($29)
    /* FB6B8 001FB6B8 01008292 */  lbu        $2, 0x1($20)
    /* FB6BC 001FB6BC 06004004 */  bltz       $2, .L001FB6D8
    /* FB6C0 001FB6C0 00000000 */   nop
    /* FB6C4 001FB6C4 00108244 */  mtc1       $2, $f2
    /* FB6C8 001FB6C8 00000000 */  nop
    /* FB6CC 001FB6CC A0108046 */  cvt.s.w    $f2, $f2
    /* FB6D0 001FB6D0 08000010 */  b          .L001FB6F4
    /* FB6D4 001FB6D4 00000000 */   nop
  .L001FB6D8:
    /* FB6D8 001FB6D8 42180200 */  srl        $3, $2, 1
    /* FB6DC 001FB6DC 01004230 */  andi       $2, $2, 0x1
    /* FB6E0 001FB6E0 25186200 */  or         $3, $3, $2
    /* FB6E4 001FB6E4 00108344 */  mtc1       $3, $f2
    /* FB6E8 001FB6E8 00000000 */  nop
    /* FB6EC 001FB6EC A0108046 */  cvt.s.w    $f2, $f2
    /* FB6F0 001FB6F0 80100246 */  add.s      $f2, $f2, $f2
  .L001FB6F4:
    /* FB6F4 001FB6F4 C400A2E7 */  swc1       $f2, 0xC4($29)
    /* FB6F8 001FB6F8 02008292 */  lbu        $2, 0x2($20)
    /* FB6FC 001FB6FC 06004004 */  bltz       $2, .L001FB718
    /* FB700 001FB700 00000000 */   nop
    /* FB704 001FB704 00108244 */  mtc1       $2, $f2
    /* FB708 001FB708 00000000 */  nop
    /* FB70C 001FB70C A0108046 */  cvt.s.w    $f2, $f2
    /* FB710 001FB710 08000010 */  b          .L001FB734
    /* FB714 001FB714 00000000 */   nop
  .L001FB718:
    /* FB718 001FB718 42180200 */  srl        $3, $2, 1
    /* FB71C 001FB71C 01004230 */  andi       $2, $2, 0x1
    /* FB720 001FB720 25186200 */  or         $3, $3, $2
    /* FB724 001FB724 00108344 */  mtc1       $3, $f2
    /* FB728 001FB728 00000000 */  nop
    /* FB72C 001FB72C A0108046 */  cvt.s.w    $f2, $f2
    /* FB730 001FB730 80100246 */  add.s      $f2, $f2, $f2
  .L001FB734:
    /* FB734 001FB734 C800A2E7 */  swc1       $f2, 0xC8($29)
    /* FB738 001FB738 03008292 */  lbu        $2, 0x3($20)
    /* FB73C 001FB73C 06004004 */  bltz       $2, .L001FB758
    /* FB740 001FB740 00000000 */   nop
    /* FB744 001FB744 00108244 */  mtc1       $2, $f2
    /* FB748 001FB748 00000000 */  nop
    /* FB74C 001FB74C A0108046 */  cvt.s.w    $f2, $f2
    /* FB750 001FB750 08000010 */  b          .L001FB774
    /* FB754 001FB754 00000000 */   nop
  .L001FB758:
    /* FB758 001FB758 42180200 */  srl        $3, $2, 1
    /* FB75C 001FB75C 01004230 */  andi       $2, $2, 0x1
    /* FB760 001FB760 25186200 */  or         $3, $3, $2
    /* FB764 001FB764 00108344 */  mtc1       $3, $f2
    /* FB768 001FB768 00000000 */  nop
    /* FB76C 001FB76C A0108046 */  cvt.s.w    $f2, $f2
    /* FB770 001FB770 80100246 */  add.s      $f2, $f2, $f2
  .L001FB774:
    /* FB774 001FB774 CC00A2E7 */  swc1       $f2, 0xCC($29)
    /* FB778 001FB778 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* FB77C 001FB77C B000A0AF */  sw         $0, 0xB0($29)
    /* FB780 001FB780 B400A0AF */  sw         $0, 0xB4($29)
    /* FB784 001FB784 E000B7E7 */  swc1       $f23, 0xE0($29)
    /* FB788 001FB788 E400B4E7 */  swc1       $f20, 0xE4($29)
    /* FB78C 001FB78C E800A1E7 */  swc1       $f1, 0xE8($29)
    /* FB790 001FB790 00008292 */  lbu        $2, 0x0($20)
    /* FB794 001FB794 06004004 */  bltz       $2, .L001FB7B0
    /* FB798 001FB798 00000000 */   nop
    /* FB79C 001FB79C 00108244 */  mtc1       $2, $f2
    /* FB7A0 001FB7A0 00000000 */  nop
    /* FB7A4 001FB7A4 A0108046 */  cvt.s.w    $f2, $f2
    /* FB7A8 001FB7A8 08000010 */  b          .L001FB7CC
    /* FB7AC 001FB7AC 00000000 */   nop
  .L001FB7B0:
    /* FB7B0 001FB7B0 42180200 */  srl        $3, $2, 1
    /* FB7B4 001FB7B4 01004230 */  andi       $2, $2, 0x1
    /* FB7B8 001FB7B8 25186200 */  or         $3, $3, $2
    /* FB7BC 001FB7BC 00108344 */  mtc1       $3, $f2
    /* FB7C0 001FB7C0 00000000 */  nop
    /* FB7C4 001FB7C4 A0108046 */  cvt.s.w    $f2, $f2
    /* FB7C8 001FB7C8 80100246 */  add.s      $f2, $f2, $f2
  .L001FB7CC:
    /* FB7CC 001FB7CC 0001A2E7 */  swc1       $f2, 0x100($29)
    /* FB7D0 001FB7D0 01008292 */  lbu        $2, 0x1($20)
    /* FB7D4 001FB7D4 06004004 */  bltz       $2, .L001FB7F0
    /* FB7D8 001FB7D8 00000000 */   nop
    /* FB7DC 001FB7DC 00108244 */  mtc1       $2, $f2
    /* FB7E0 001FB7E0 00000000 */  nop
    /* FB7E4 001FB7E4 A0108046 */  cvt.s.w    $f2, $f2
    /* FB7E8 001FB7E8 08000010 */  b          .L001FB80C
    /* FB7EC 001FB7EC 00000000 */   nop
  .L001FB7F0:
    /* FB7F0 001FB7F0 42180200 */  srl        $3, $2, 1
    /* FB7F4 001FB7F4 01004230 */  andi       $2, $2, 0x1
    /* FB7F8 001FB7F8 25186200 */  or         $3, $3, $2
    /* FB7FC 001FB7FC 00108344 */  mtc1       $3, $f2
    /* FB800 001FB800 00000000 */  nop
    /* FB804 001FB804 A0108046 */  cvt.s.w    $f2, $f2
    /* FB808 001FB808 80100246 */  add.s      $f2, $f2, $f2
  .L001FB80C:
    /* FB80C 001FB80C 0401A2E7 */  swc1       $f2, 0x104($29)
    /* FB810 001FB810 02008292 */  lbu        $2, 0x2($20)
    /* FB814 001FB814 06004004 */  bltz       $2, .L001FB830
    /* FB818 001FB818 00000000 */   nop
    /* FB81C 001FB81C 00108244 */  mtc1       $2, $f2
    /* FB820 001FB820 00000000 */  nop
    /* FB824 001FB824 A0108046 */  cvt.s.w    $f2, $f2
    /* FB828 001FB828 08000010 */  b          .L001FB84C
    /* FB82C 001FB82C 00000000 */   nop
  .L001FB830:
    /* FB830 001FB830 42180200 */  srl        $3, $2, 1
    /* FB834 001FB834 01004230 */  andi       $2, $2, 0x1
    /* FB838 001FB838 25186200 */  or         $3, $3, $2
    /* FB83C 001FB83C 00108344 */  mtc1       $3, $f2
    /* FB840 001FB840 00000000 */  nop
    /* FB844 001FB844 A0108046 */  cvt.s.w    $f2, $f2
    /* FB848 001FB848 80100246 */  add.s      $f2, $f2, $f2
  .L001FB84C:
    /* FB84C 001FB84C 0801A2E7 */  swc1       $f2, 0x108($29)
    /* FB850 001FB850 03008292 */  lbu        $2, 0x3($20)
    /* FB854 001FB854 06004004 */  bltz       $2, .L001FB870
    /* FB858 001FB858 00000000 */   nop
    /* FB85C 001FB85C 00108244 */  mtc1       $2, $f2
    /* FB860 001FB860 00000000 */  nop
    /* FB864 001FB864 A0108046 */  cvt.s.w    $f2, $f2
    /* FB868 001FB868 08000010 */  b          .L001FB88C
    /* FB86C 001FB86C 00000000 */   nop
  .L001FB870:
    /* FB870 001FB870 42180200 */  srl        $3, $2, 1
    /* FB874 001FB874 01004230 */  andi       $2, $2, 0x1
    /* FB878 001FB878 25186200 */  or         $3, $3, $2
    /* FB87C 001FB87C 00108344 */  mtc1       $3, $f2
    /* FB880 001FB880 00000000 */  nop
    /* FB884 001FB884 A0108046 */  cvt.s.w    $f2, $f2
    /* FB888 001FB888 80100246 */  add.s      $f2, $f2, $f2
  .L001FB88C:
    /* FB88C 001FB88C 0C01A2E7 */  swc1       $f2, 0x10C($29)
    /* FB890 001FB890 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* FB894 001FB894 F000A0AF */  sw         $0, 0xF0($29)
    /* FB898 001FB898 F400B8E7 */  swc1       $f24, 0xF4($29)
    /* FB89C 001FB89C 2001B5E7 */  swc1       $f21, 0x120($29)
    /* FB8A0 001FB8A0 2401B6E7 */  swc1       $f22, 0x124($29)
    /* FB8A4 001FB8A4 2801A1E7 */  swc1       $f1, 0x128($29)
    /* FB8A8 001FB8A8 00008292 */  lbu        $2, 0x0($20)
    /* FB8AC 001FB8AC 06004004 */  bltz       $2, .L001FB8C8
    /* FB8B0 001FB8B0 00000000 */   nop
    /* FB8B4 001FB8B4 00108244 */  mtc1       $2, $f2
    /* FB8B8 001FB8B8 00000000 */  nop
    /* FB8BC 001FB8BC A0108046 */  cvt.s.w    $f2, $f2
    /* FB8C0 001FB8C0 08000010 */  b          .L001FB8E4
    /* FB8C4 001FB8C4 00000000 */   nop
  .L001FB8C8:
    /* FB8C8 001FB8C8 42180200 */  srl        $3, $2, 1
    /* FB8CC 001FB8CC 01004230 */  andi       $2, $2, 0x1
    /* FB8D0 001FB8D0 25186200 */  or         $3, $3, $2
    /* FB8D4 001FB8D4 00108344 */  mtc1       $3, $f2
    /* FB8D8 001FB8D8 00000000 */  nop
    /* FB8DC 001FB8DC A0108046 */  cvt.s.w    $f2, $f2
    /* FB8E0 001FB8E0 80100246 */  add.s      $f2, $f2, $f2
  .L001FB8E4:
    /* FB8E4 001FB8E4 4001A2E7 */  swc1       $f2, 0x140($29)
    /* FB8E8 001FB8E8 01008292 */  lbu        $2, 0x1($20)
    /* FB8EC 001FB8EC 06004004 */  bltz       $2, .L001FB908
    /* FB8F0 001FB8F0 00000000 */   nop
    /* FB8F4 001FB8F4 00108244 */  mtc1       $2, $f2
    /* FB8F8 001FB8F8 00000000 */  nop
    /* FB8FC 001FB8FC A0108046 */  cvt.s.w    $f2, $f2
    /* FB900 001FB900 08000010 */  b          .L001FB924
    /* FB904 001FB904 00000000 */   nop
  .L001FB908:
    /* FB908 001FB908 42180200 */  srl        $3, $2, 1
    /* FB90C 001FB90C 01004230 */  andi       $2, $2, 0x1
    /* FB910 001FB910 25186200 */  or         $3, $3, $2
    /* FB914 001FB914 00108344 */  mtc1       $3, $f2
    /* FB918 001FB918 00000000 */  nop
    /* FB91C 001FB91C A0108046 */  cvt.s.w    $f2, $f2
    /* FB920 001FB920 80100246 */  add.s      $f2, $f2, $f2
  .L001FB924:
    /* FB924 001FB924 4401A2E7 */  swc1       $f2, 0x144($29)
    /* FB928 001FB928 02008292 */  lbu        $2, 0x2($20)
    /* FB92C 001FB92C 06004004 */  bltz       $2, .L001FB948
    /* FB930 001FB930 00000000 */   nop
    /* FB934 001FB934 00108244 */  mtc1       $2, $f2
    /* FB938 001FB938 00000000 */  nop
    /* FB93C 001FB93C A0108046 */  cvt.s.w    $f2, $f2
    /* FB940 001FB940 08000010 */  b          .L001FB964
    /* FB944 001FB944 00000000 */   nop
  .L001FB948:
    /* FB948 001FB948 42180200 */  srl        $3, $2, 1
    /* FB94C 001FB94C 01004230 */  andi       $2, $2, 0x1
    /* FB950 001FB950 25186200 */  or         $3, $3, $2
    /* FB954 001FB954 00108344 */  mtc1       $3, $f2
    /* FB958 001FB958 00000000 */  nop
    /* FB95C 001FB95C A0108046 */  cvt.s.w    $f2, $f2
    /* FB960 001FB960 80100246 */  add.s      $f2, $f2, $f2
  .L001FB964:
    /* FB964 001FB964 4801A2E7 */  swc1       $f2, 0x148($29)
    /* FB968 001FB968 03008292 */  lbu        $2, 0x3($20)
    /* FB96C 001FB96C 06004004 */  bltz       $2, .L001FB988
    /* FB970 001FB970 00000000 */   nop
    /* FB974 001FB974 00108244 */  mtc1       $2, $f2
    /* FB978 001FB978 00000000 */  nop
    /* FB97C 001FB97C A0108046 */  cvt.s.w    $f2, $f2
    /* FB980 001FB980 08000010 */  b          .L001FB9A4
    /* FB984 001FB984 00000000 */   nop
  .L001FB988:
    /* FB988 001FB988 42180200 */  srl        $3, $2, 1
    /* FB98C 001FB98C 01004230 */  andi       $2, $2, 0x1
    /* FB990 001FB990 25186200 */  or         $3, $3, $2
    /* FB994 001FB994 00108344 */  mtc1       $3, $f2
    /* FB998 001FB998 00000000 */  nop
    /* FB99C 001FB99C A0108046 */  cvt.s.w    $f2, $f2
    /* FB9A0 001FB9A0 80100246 */  add.s      $f2, $f2, $f2
  .L001FB9A4:
    /* FB9A4 001FB9A4 4C01A2E7 */  swc1       $f2, 0x14C($29)
    /* FB9A8 001FB9A8 3801A0E7 */  swc1       $f0, 0x138($29)
    /* FB9AC 001FB9AC 3001B9E7 */  swc1       $f25, 0x130($29)
    /* FB9B0 001FB9B0 3401A0AF */  sw         $0, 0x134($29)
    /* FB9B4 001FB9B4 6001B5E7 */  swc1       $f21, 0x160($29)
    /* FB9B8 001FB9B8 6401B4E7 */  swc1       $f20, 0x164($29)
    /* FB9BC 001FB9BC 6801A1E7 */  swc1       $f1, 0x168($29)
    /* FB9C0 001FB9C0 00008292 */  lbu        $2, 0x0($20)
    /* FB9C4 001FB9C4 06004004 */  bltz       $2, .L001FB9E0
    /* FB9C8 001FB9C8 00000000 */   nop
    /* FB9CC 001FB9CC 00088244 */  mtc1       $2, $f1
    /* FB9D0 001FB9D0 00000000 */  nop
    /* FB9D4 001FB9D4 60088046 */  cvt.s.w    $f1, $f1
    /* FB9D8 001FB9D8 08000010 */  b          .L001FB9FC
    /* FB9DC 001FB9DC 00000000 */   nop
  .L001FB9E0:
    /* FB9E0 001FB9E0 42180200 */  srl        $3, $2, 1
    /* FB9E4 001FB9E4 01004230 */  andi       $2, $2, 0x1
    /* FB9E8 001FB9E8 25186200 */  or         $3, $3, $2
    /* FB9EC 001FB9EC 00088344 */  mtc1       $3, $f1
    /* FB9F0 001FB9F0 00000000 */  nop
    /* FB9F4 001FB9F4 60088046 */  cvt.s.w    $f1, $f1
    /* FB9F8 001FB9F8 40080146 */  add.s      $f1, $f1, $f1
  .L001FB9FC:
    /* FB9FC 001FB9FC 8001A1E7 */  swc1       $f1, 0x180($29)
    /* FBA00 001FBA00 01008292 */  lbu        $2, 0x1($20)
    /* FBA04 001FBA04 06004004 */  bltz       $2, .L001FBA20
    /* FBA08 001FBA08 00000000 */   nop
    /* FBA0C 001FBA0C 00088244 */  mtc1       $2, $f1
    /* FBA10 001FBA10 00000000 */  nop
    /* FBA14 001FBA14 60088046 */  cvt.s.w    $f1, $f1
    /* FBA18 001FBA18 08000010 */  b          .L001FBA3C
    /* FBA1C 001FBA1C 00000000 */   nop
  .L001FBA20:
    /* FBA20 001FBA20 42180200 */  srl        $3, $2, 1
    /* FBA24 001FBA24 01004230 */  andi       $2, $2, 0x1
    /* FBA28 001FBA28 25186200 */  or         $3, $3, $2
    /* FBA2C 001FBA2C 00088344 */  mtc1       $3, $f1
    /* FBA30 001FBA30 00000000 */  nop
    /* FBA34 001FBA34 60088046 */  cvt.s.w    $f1, $f1
    /* FBA38 001FBA38 40080146 */  add.s      $f1, $f1, $f1
  .L001FBA3C:
    /* FBA3C 001FBA3C 8401A1E7 */  swc1       $f1, 0x184($29)
    /* FBA40 001FBA40 02008292 */  lbu        $2, 0x2($20)
    /* FBA44 001FBA44 06004004 */  bltz       $2, .L001FBA60
    /* FBA48 001FBA48 00000000 */   nop
    /* FBA4C 001FBA4C 00088244 */  mtc1       $2, $f1
    /* FBA50 001FBA50 00000000 */  nop
    /* FBA54 001FBA54 60088046 */  cvt.s.w    $f1, $f1
    /* FBA58 001FBA58 08000010 */  b          .L001FBA7C
    /* FBA5C 001FBA5C 00000000 */   nop
  .L001FBA60:
    /* FBA60 001FBA60 42180200 */  srl        $3, $2, 1
    /* FBA64 001FBA64 01004230 */  andi       $2, $2, 0x1
    /* FBA68 001FBA68 25186200 */  or         $3, $3, $2
    /* FBA6C 001FBA6C 00088344 */  mtc1       $3, $f1
    /* FBA70 001FBA70 00000000 */  nop
    /* FBA74 001FBA74 60088046 */  cvt.s.w    $f1, $f1
    /* FBA78 001FBA78 40080146 */  add.s      $f1, $f1, $f1
  .L001FBA7C:
    /* FBA7C 001FBA7C 8801A1E7 */  swc1       $f1, 0x188($29)
    /* FBA80 001FBA80 03008292 */  lbu        $2, 0x3($20)
    /* FBA84 001FBA84 06004004 */  bltz       $2, .L001FBAA0
    /* FBA88 001FBA88 00000000 */   nop
    /* FBA8C 001FBA8C 00088244 */  mtc1       $2, $f1
    /* FBA90 001FBA90 00000000 */  nop
    /* FBA94 001FBA94 60088046 */  cvt.s.w    $f1, $f1
    /* FBA98 001FBA98 08000010 */  b          .L001FBABC
    /* FBA9C 001FBA9C 00000000 */   nop
  .L001FBAA0:
    /* FBAA0 001FBAA0 42180200 */  srl        $3, $2, 1
    /* FBAA4 001FBAA4 01004230 */  andi       $2, $2, 0x1
    /* FBAA8 001FBAA8 25186200 */  or         $3, $3, $2
    /* FBAAC 001FBAAC 00088344 */  mtc1       $3, $f1
    /* FBAB0 001FBAB0 00000000 */  nop
    /* FBAB4 001FBAB4 60088046 */  cvt.s.w    $f1, $f1
    /* FBAB8 001FBAB8 40080146 */  add.s      $f1, $f1, $f1
  .L001FBABC:
    /* FBABC 001FBABC 8C01A1E7 */  swc1       $f1, 0x18C($29)
    /* FBAC0 001FBAC0 7801A0E7 */  swc1       $f0, 0x178($29)
    /* FBAC4 001FBAC4 7001B9E7 */  swc1       $f25, 0x170($29)
    /* FBAC8 001FBAC8 7401B8E7 */  swc1       $f24, 0x174($29)
    /* FBACC 001FBACC 04000424 */  addiu      $4, $0, 0x4
    /* FBAD0 001FBAD0 A000A527 */  addiu      $5, $29, 0xA0
    /* FBAD4 001FBAD4 2D308000 */  daddu      $6, $4, $0
    /* FBAD8 001FBAD8 8800023C */  lui        $2, %hi(D_00887310)
    /* FBADC 001FBADC 1073428C */  lw         $2, %lo(D_00887310)($2)
    /* FBAE0 001FBAE0 09F84000 */  jalr       $2
    /* FBAE4 001FBAE4 00000000 */   nop
    /* FBAE8 001FBAE8 01000424 */  addiu      $4, $0, 0x1
    /* FBAEC 001FBAEC 2D280000 */  daddu      $5, $0, $0
    /* FBAF0 001FBAF0 0000A28E */  lw         $2, 0x0($21)
    /* FBAF4 001FBAF4 09F84000 */  jalr       $2
    /* FBAF8 001FBAF8 00000000 */   nop
    /* FBAFC 001FBAFC 9000BFDF */  ld         $31, 0x90($29)
    /* FBB00 001FBB00 8000B67B */  lq         $22, 0x80($29)
    /* FBB04 001FBB04 7000B57B */  lq         $21, 0x70($29)
    /* FBB08 001FBB08 6000B47B */  lq         $20, 0x60($29)
    /* FBB0C 001FBB0C 5000B37B */  lq         $19, 0x50($29)
    /* FBB10 001FBB10 4000B27B */  lq         $18, 0x40($29)
    /* FBB14 001FBB14 3000B17B */  lq         $17, 0x30($29)
    /* FBB18 001FBB18 2000B07B */  lq         $16, 0x20($29)
    /* FBB1C 001FBB1C 1800BAC7 */  lwc1       $f26, 0x18($29)
    /* FBB20 001FBB20 1400B9C7 */  lwc1       $f25, 0x14($29)
    /* FBB24 001FBB24 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* FBB28 001FBB28 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* FBB2C 001FBB2C 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* FBB30 001FBB30 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* FBB34 001FBB34 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* FBB38 001FBB38 A001BD27 */  addiu      $29, $29, 0x1A0
    /* FBB3C 001FBB3C 0800E003 */  jr         $31
    /* FBB40 001FBB40 00000000 */   nop
    /* FBB44 001FBB44 00000000 */  nop
    /* FBB48 001FBB48 00000000 */  nop
    /* FBB4C 001FBB4C 00000000 */  nop
.size func_001fb480, 0x6d0
