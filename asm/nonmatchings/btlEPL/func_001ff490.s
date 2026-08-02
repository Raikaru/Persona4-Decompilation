.section .text
.set noat
.set noreorder
glabel func_001ff490
    /* FF490 001FF490 10FFBD27 */  addiu      $29, $29, -0xF0
    /* FF494 001FF494 9000BFFF */  sd         $31, 0x90($29)
    /* FF498 001FF498 8000B77F */  sq         $23, 0x80($29)
    /* FF49C 001FF49C 7000B67F */  sq         $22, 0x70($29)
    /* FF4A0 001FF4A0 6000B57F */  sq         $21, 0x60($29)
    /* FF4A4 001FF4A4 5000B47F */  sq         $20, 0x50($29)
    /* FF4A8 001FF4A8 4000B37F */  sq         $19, 0x40($29)
    /* FF4AC 001FF4AC 3000B27F */  sq         $18, 0x30($29)
    /* FF4B0 001FF4B0 2000B17F */  sq         $17, 0x20($29)
    /* FF4B4 001FF4B4 1000B07F */  sq         $16, 0x10($29)
    /* FF4B8 001FF4B8 0000B4E7 */  swc1       $f20, 0x0($29)
    /* FF4BC 001FF4BC 2DA88000 */  daddu      $21, $4, $0
    /* FF4C0 001FF4C0 3000948C */  lw         $20, 0x30($4)
    /* FF4C4 001FF4C4 3800938C */  lw         $19, 0x38($4)
    /* FF4C8 001FF4C8 2800928C */  lw         $18, 0x28($4)
    /* FF4CC 001FF4CC 0000718E */  lw         $17, 0x0($19)
    /* FF4D0 001FF4D0 2B083202 */  sltu       $1, $17, $18
    /* FF4D4 001FF4D4 03002010 */  beqz       $1, .L001FF4E4
    /* FF4D8 001FF4D8 00000000 */   nop
    /* FF4DC 001FF4DC 89022016 */  bnez       $17, .L001FFF04
    /* FF4E0 001FF4E0 00000000 */   nop
  .L001FF4E4:
    /* FF4E4 001FF4E4 08DC060C */  jal        func_001b7020
    /* FF4E8 001FF4E8 00000000 */   nop
    /* FF4EC 001FF4EC 2D804000 */  daddu      $16, $2, $0
    /* FF4F0 001FF4F0 2DB00000 */  daddu      $22, $0, $0
    /* FF4F4 001FF4F4 5E002012 */  beqz       $17, .L001FF670
    /* FF4F8 001FF4F8 00000000 */   nop
    /* FF4FC 001FF4FC 04006596 */  lhu        $5, 0x4($19)
    /* FF500 001FF500 2B08B200 */  sltu       $1, $5, $18
    /* FF504 001FF504 2C002014 */  bnez       $1, .L001FF5B8
    /* FF508 001FF508 00000000 */   nop
    /* FF50C 001FF50C 2500A018 */  blez       $5, .L001FF5A4
    /* FF510 001FF510 00000000 */   nop
    /* FF514 001FF514 06004006 */  bltz       $18, .L001FF530
    /* FF518 001FF518 00000000 */   nop
    /* FF51C 001FF51C 00009244 */  mtc1       $18, $f0
    /* FF520 001FF520 00000000 */  nop
    /* FF524 001FF524 60008046 */  cvt.s.w    $f1, $f0
    /* FF528 001FF528 08000010 */  b          .L001FF54C
    /* FF52C 001FF52C 00000000 */   nop
  .L001FF530:
    /* FF530 001FF530 42201200 */  srl        $4, $18, 1
    /* FF534 001FF534 01004332 */  andi       $3, $18, 0x1
    /* FF538 001FF538 25208300 */  or         $4, $4, $3
    /* FF53C 001FF53C 00008444 */  mtc1       $4, $f0
    /* FF540 001FF540 00000000 */  nop
    /* FF544 001FF544 60008046 */  cvt.s.w    $f1, $f0
    /* FF548 001FF548 40080146 */  add.s      $f1, $f1, $f1
  .L001FF54C:
    /* FF54C 001FF54C 0600A004 */  bltz       $5, .L001FF568
    /* FF550 001FF550 00000000 */   nop
    /* FF554 001FF554 00008544 */  mtc1       $5, $f0
    /* FF558 001FF558 00000000 */  nop
    /* FF55C 001FF55C 20008046 */  cvt.s.w    $f0, $f0
    /* FF560 001FF560 08000010 */  b          .L001FF584
    /* FF564 001FF564 00000000 */   nop
  .L001FF568:
    /* FF568 001FF568 42200500 */  srl        $4, $5, 1
    /* FF56C 001FF56C 0100A330 */  andi       $3, $5, 0x1
    /* FF570 001FF570 25208300 */  or         $4, $4, $3
    /* FF574 001FF574 00008444 */  mtc1       $4, $f0
    /* FF578 001FF578 00000000 */  nop
    /* FF57C 001FF57C 20008046 */  cvt.s.w    $f0, $f0
    /* FF580 001FF580 00000046 */  add.s      $f0, $f0, $f0
  .L001FF584:
    /* FF584 001FF584 00000000 */  nop
    /* FF588 001FF588 00000000 */  nop
    /* FF58C 001FF58C 030D0046 */  div.s      $f20, $f1, $f0
    /* FF590 001FF590 00000000 */  nop
    /* FF594 001FF594 00000000 */  nop
    /* FF598 001FF598 00000000 */  nop
    /* FF59C 001FF59C 03000010 */  b          .L001FF5AC
    /* FF5A0 001FF5A0 00000000 */   nop
  .L001FF5A4:
    /* FF5A4 001FF5A4 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FF5A8 001FF5A8 00A08344 */  mtc1       $3, $f20
  .L001FF5AC:
    /* FF5AC 001FF5AC 01001664 */  daddiu     $22, $0, 0x1
    /* FF5B0 001FF5B0 2F000010 */  b          .L001FF670
    /* FF5B4 001FF5B4 00000000 */   nop
  .L001FF5B8:
    /* FF5B8 001FF5B8 06006596 */  lhu        $5, 0x6($19)
    /* FF5BC 001FF5BC 23182502 */  subu       $3, $17, $5
    /* FF5C0 001FF5C0 2B184302 */  sltu       $3, $18, $3
    /* FF5C4 001FF5C4 2A006014 */  bnez       $3, .L001FF670
    /* FF5C8 001FF5C8 00000000 */   nop
    /* FF5CC 001FF5CC 2600A018 */  blez       $5, .L001FF668
    /* FF5D0 001FF5D0 00000000 */   nop
    /* FF5D4 001FF5D4 23183202 */  subu       $3, $17, $18
    /* FF5D8 001FF5D8 06006004 */  bltz       $3, .L001FF5F4
    /* FF5DC 001FF5DC 00000000 */   nop
    /* FF5E0 001FF5E0 00008344 */  mtc1       $3, $f0
    /* FF5E4 001FF5E4 00000000 */  nop
    /* FF5E8 001FF5E8 60008046 */  cvt.s.w    $f1, $f0
    /* FF5EC 001FF5EC 08000010 */  b          .L001FF610
    /* FF5F0 001FF5F0 00000000 */   nop
  .L001FF5F4:
    /* FF5F4 001FF5F4 42200300 */  srl        $4, $3, 1
    /* FF5F8 001FF5F8 01006330 */  andi       $3, $3, 0x1
    /* FF5FC 001FF5FC 25208300 */  or         $4, $4, $3
    /* FF600 001FF600 00008444 */  mtc1       $4, $f0
    /* FF604 001FF604 00000000 */  nop
    /* FF608 001FF608 60008046 */  cvt.s.w    $f1, $f0
    /* FF60C 001FF60C 40080146 */  add.s      $f1, $f1, $f1
  .L001FF610:
    /* FF610 001FF610 0600A004 */  bltz       $5, .L001FF62C
    /* FF614 001FF614 00000000 */   nop
    /* FF618 001FF618 00008544 */  mtc1       $5, $f0
    /* FF61C 001FF61C 00000000 */  nop
    /* FF620 001FF620 20008046 */  cvt.s.w    $f0, $f0
    /* FF624 001FF624 08000010 */  b          .L001FF648
    /* FF628 001FF628 00000000 */   nop
  .L001FF62C:
    /* FF62C 001FF62C 42200500 */  srl        $4, $5, 1
    /* FF630 001FF630 0100A330 */  andi       $3, $5, 0x1
    /* FF634 001FF634 25208300 */  or         $4, $4, $3
    /* FF638 001FF638 00008444 */  mtc1       $4, $f0
    /* FF63C 001FF63C 00000000 */  nop
    /* FF640 001FF640 20008046 */  cvt.s.w    $f0, $f0
    /* FF644 001FF644 00000046 */  add.s      $f0, $f0, $f0
  .L001FF648:
    /* FF648 001FF648 00000000 */  nop
    /* FF64C 001FF64C 00000000 */  nop
    /* FF650 001FF650 030D0046 */  div.s      $f20, $f1, $f0
    /* FF654 001FF654 00000000 */  nop
    /* FF658 001FF658 00000000 */  nop
    /* FF65C 001FF65C 00000000 */  nop
    /* FF660 001FF660 02000010 */  b          .L001FF66C
    /* FF664 001FF664 00000000 */   nop
  .L001FF668:
    /* FF668 001FF668 00A08044 */  mtc1       $0, $f20
  .L001FF66C:
    /* FF66C 001FF66C 02001664 */  daddiu     $22, $0, 0x2
  .L001FF670:
    /* FF670 001FF670 2DB80000 */  daddu      $23, $0, $0
    /* FF674 001FF674 0000838E */  lw         $3, 0x0($20)
    /* FF678 001FF678 30006010 */  beqz       $3, .L001FF73C
    /* FF67C 001FF67C 00000000 */   nop
    /* FF680 001FF680 A000A427 */  addiu      $4, $29, 0xA0
    /* FF684 001FF684 1000A526 */  addiu      $5, $21, 0x10
    /* FF688 001FF688 5428120C */  jal        func_0048a150
    /* FF68C 001FF68C 00000000 */   nop
    /* FF690 001FF690 0000848E */  lw         $4, 0x0($20)
    /* FF694 001FF694 A000A527 */  addiu      $5, $29, 0xA0
    /* FF698 001FF698 2D300000 */  daddu      $6, $0, $0
    /* FF69C 001FF69C 70E8110C */  jal        func_0047a1c0
    /* FF6A0 001FF6A0 00000000 */   nop
    /* FF6A4 001FF6A4 2000A1C6 */  lwc1       $f1, 0x20($21)
    /* FF6A8 001FF6A8 140060C6 */  lwc1       $f0, 0x14($19)
    /* FF6AC 001FF6AC 02080046 */  mul.s      $f0, $f1, $f0
    /* FF6B0 001FF6B0 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* FF6B4 001FF6B4 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* FF6B8 001FF6B8 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* FF6BC 001FF6BC 0000848E */  lw         $4, 0x0($20)
    /* FF6C0 001FF6C0 E000A527 */  addiu      $5, $29, 0xE0
    /* FF6C4 001FF6C4 02000624 */  addiu      $6, $0, 0x2
    /* FF6C8 001FF6C8 78E8110C */  jal        func_0047a1e0
    /* FF6CC 001FF6CC 00000000 */   nop
    /* FF6D0 001FF6D0 0000A0C6 */  lwc1       $f0, 0x0($21)
    /* FF6D4 001FF6D4 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* FF6D8 001FF6D8 0400A0C6 */  lwc1       $f0, 0x4($21)
    /* FF6DC 001FF6DC E400A0E7 */  swc1       $f0, 0xE4($29)
    /* FF6E0 001FF6E0 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* FF6E4 001FF6E4 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* FF6E8 001FF6E8 0000848E */  lw         $4, 0x0($20)
    /* FF6EC 001FF6EC E000A527 */  addiu      $5, $29, 0xE0
    /* FF6F0 001FF6F0 02000624 */  addiu      $6, $0, 0x2
    /* FF6F4 001FF6F4 60E8110C */  jal        func_0047a180
    /* FF6F8 001FF6F8 00000000 */   nop
    /* FF6FC 001FF6FC 0000848E */  lw         $4, 0x0($20)
    /* FF700 001FF700 2D280000 */  daddu      $5, $0, $0
    /* FF704 001FF704 10006CC6 */  lwc1       $f12, 0x10($19)
    /* FF708 001FF708 38E8110C */  jal        func_0047a0e0
    /* FF70C 001FF70C 00000000 */   nop
    /* FF710 001FF710 0000848E */  lw         $4, 0x0($20)
    /* FF714 001FF714 9CE3110C */  jal        func_00478e70
    /* FF718 001FF718 00000000 */   nop
    /* FF71C 001FF71C 0000848E */  lw         $4, 0x0($20)
    /* FF720 001FF720 2D280000 */  daddu      $5, $0, $0
    /* FF724 001FF724 A000A627 */  addiu      $6, $29, 0xA0
    /* FF728 001FF728 44E9110C */  jal        func_0047a510
    /* FF72C 001FF72C 00000000 */   nop
    /* FF730 001FF730 02004010 */  beqz       $2, .L001FF73C
    /* FF734 001FF734 00000000 */   nop
    /* FF738 001FF738 01001724 */  addiu      $23, $0, 0x1
  .L001FF73C:
    /* FF73C 001FF73C FF00C432 */  andi       $4, $22, 0xFF
    /* FF740 001FF740 02000324 */  addiu      $3, $0, 0x2
    /* FF744 001FF744 89018310 */  beq        $4, $3, .L001FFD6C
    /* FF748 001FF748 00000000 */   nop
    /* FF74C 001FF74C 01000324 */  addiu      $3, $0, 0x1
    /* FF750 001FF750 A8008310 */  beq        $4, $3, .L001FF9F4
    /* FF754 001FF754 00000000 */   nop
    /* FF758 001FF758 03008010 */  beqz       $4, .L001FF768
    /* FF75C 001FF75C 00000000 */   nop
    /* FF760 001FF760 DB010010 */  b          .L001FFED0
    /* FF764 001FF764 00000000 */   nop
  .L001FF768:
    /* FF768 001FF768 D9014016 */  bnez       $18, .L001FFED0
    /* FF76C 001FF76C 00000000 */   nop
    /* FF770 001FF770 0800638E */  lw         $3, 0x8($19)
    /* FF774 001FF774 EC00A3AF */  sw         $3, 0xEC($29)
    /* FF778 001FF778 EC00A393 */  lbu        $3, 0xEC($29)
    /* FF77C 001FF77C 06006004 */  bltz       $3, .L001FF798
    /* FF780 001FF780 00000000 */   nop
    /* FF784 001FF784 00008344 */  mtc1       $3, $f0
    /* FF788 001FF788 00000000 */  nop
    /* FF78C 001FF78C 60008046 */  cvt.s.w    $f1, $f0
    /* FF790 001FF790 08000010 */  b          .L001FF7B4
    /* FF794 001FF794 00000000 */   nop
  .L001FF798:
    /* FF798 001FF798 42200300 */  srl        $4, $3, 1
    /* FF79C 001FF79C 01006330 */  andi       $3, $3, 0x1
    /* FF7A0 001FF7A0 25208300 */  or         $4, $4, $3
    /* FF7A4 001FF7A4 00008444 */  mtc1       $4, $f0
    /* FF7A8 001FF7A8 00000000 */  nop
    /* FF7AC 001FF7AC 60008046 */  cvt.s.w    $f1, $f0
    /* FF7B0 001FF7B0 40080146 */  add.s      $f1, $f1, $f1
  .L001FF7B4:
    /* FF7B4 001FF7B4 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF7B8 001FF7B8 02000146 */  mul.s      $f0, $f0, $f1
    /* FF7BC 001FF7BC 9200033C */  lui        $3, %hi(D_00922CA0)
    /* FF7C0 001FF7C0 A02C60E4 */  swc1       $f0, %lo(D_00922CA0)($3)
    /* FF7C4 001FF7C4 ED00A393 */  lbu        $3, 0xED($29)
    /* FF7C8 001FF7C8 06006004 */  bltz       $3, .L001FF7E4
    /* FF7CC 001FF7CC 00000000 */   nop
    /* FF7D0 001FF7D0 00008344 */  mtc1       $3, $f0
    /* FF7D4 001FF7D4 00000000 */  nop
    /* FF7D8 001FF7D8 60008046 */  cvt.s.w    $f1, $f0
    /* FF7DC 001FF7DC 08000010 */  b          .L001FF800
    /* FF7E0 001FF7E0 00000000 */   nop
  .L001FF7E4:
    /* FF7E4 001FF7E4 42200300 */  srl        $4, $3, 1
    /* FF7E8 001FF7E8 01006330 */  andi       $3, $3, 0x1
    /* FF7EC 001FF7EC 25208300 */  or         $4, $4, $3
    /* FF7F0 001FF7F0 00008444 */  mtc1       $4, $f0
    /* FF7F4 001FF7F4 00000000 */  nop
    /* FF7F8 001FF7F8 60008046 */  cvt.s.w    $f1, $f0
    /* FF7FC 001FF7FC 40080146 */  add.s      $f1, $f1, $f1
  .L001FF800:
    /* FF800 001FF800 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF804 001FF804 02000146 */  mul.s      $f0, $f0, $f1
    /* FF808 001FF808 9200033C */  lui        $3, %hi(D_00922CA4)
    /* FF80C 001FF80C A42C60E4 */  swc1       $f0, %lo(D_00922CA4)($3)
    /* FF810 001FF810 EE00A393 */  lbu        $3, 0xEE($29)
    /* FF814 001FF814 06006004 */  bltz       $3, .L001FF830
    /* FF818 001FF818 00000000 */   nop
    /* FF81C 001FF81C 00008344 */  mtc1       $3, $f0
    /* FF820 001FF820 00000000 */  nop
    /* FF824 001FF824 60008046 */  cvt.s.w    $f1, $f0
    /* FF828 001FF828 08000010 */  b          .L001FF84C
    /* FF82C 001FF82C 00000000 */   nop
  .L001FF830:
    /* FF830 001FF830 42200300 */  srl        $4, $3, 1
    /* FF834 001FF834 01006330 */  andi       $3, $3, 0x1
    /* FF838 001FF838 25208300 */  or         $4, $4, $3
    /* FF83C 001FF83C 00008444 */  mtc1       $4, $f0
    /* FF840 001FF840 00000000 */  nop
    /* FF844 001FF844 60008046 */  cvt.s.w    $f1, $f0
    /* FF848 001FF848 40080146 */  add.s      $f1, $f1, $f1
  .L001FF84C:
    /* FF84C 001FF84C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF850 001FF850 02000146 */  mul.s      $f0, $f0, $f1
    /* FF854 001FF854 9200033C */  lui        $3, %hi(D_00922CA8)
    /* FF858 001FF858 A82C60E4 */  swc1       $f0, %lo(D_00922CA8)($3)
    /* FF85C 001FF85C EF00A393 */  lbu        $3, 0xEF($29)
    /* FF860 001FF860 06006004 */  bltz       $3, .L001FF87C
    /* FF864 001FF864 00000000 */   nop
    /* FF868 001FF868 00008344 */  mtc1       $3, $f0
    /* FF86C 001FF86C 00000000 */  nop
    /* FF870 001FF870 60008046 */  cvt.s.w    $f1, $f0
    /* FF874 001FF874 08000010 */  b          .L001FF898
    /* FF878 001FF878 00000000 */   nop
  .L001FF87C:
    /* FF87C 001FF87C 42200300 */  srl        $4, $3, 1
    /* FF880 001FF880 01006330 */  andi       $3, $3, 0x1
    /* FF884 001FF884 25208300 */  or         $4, $4, $3
    /* FF888 001FF888 00008444 */  mtc1       $4, $f0
    /* FF88C 001FF88C 00000000 */  nop
    /* FF890 001FF890 60008046 */  cvt.s.w    $f1, $f0
    /* FF894 001FF894 40080146 */  add.s      $f1, $f1, $f1
  .L001FF898:
    /* FF898 001FF898 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF89C 001FF89C 02000146 */  mul.s      $f0, $f0, $f1
    /* FF8A0 001FF8A0 9200033C */  lui        $3, %hi(D_00922CAC)
    /* FF8A4 001FF8A4 AC2C60E4 */  swc1       $f0, %lo(D_00922CAC)($3)
    /* FF8A8 001FF8A8 0C00638E */  lw         $3, 0xC($19)
    /* FF8AC 001FF8AC EC00A3AF */  sw         $3, 0xEC($29)
    /* FF8B0 001FF8B0 EC00A393 */  lbu        $3, 0xEC($29)
    /* FF8B4 001FF8B4 06006004 */  bltz       $3, .L001FF8D0
    /* FF8B8 001FF8B8 00000000 */   nop
    /* FF8BC 001FF8BC 00008344 */  mtc1       $3, $f0
    /* FF8C0 001FF8C0 00000000 */  nop
    /* FF8C4 001FF8C4 60008046 */  cvt.s.w    $f1, $f0
    /* FF8C8 001FF8C8 08000010 */  b          .L001FF8EC
    /* FF8CC 001FF8CC 00000000 */   nop
  .L001FF8D0:
    /* FF8D0 001FF8D0 42200300 */  srl        $4, $3, 1
    /* FF8D4 001FF8D4 01006330 */  andi       $3, $3, 0x1
    /* FF8D8 001FF8D8 25208300 */  or         $4, $4, $3
    /* FF8DC 001FF8DC 00008444 */  mtc1       $4, $f0
    /* FF8E0 001FF8E0 00000000 */  nop
    /* FF8E4 001FF8E4 60008046 */  cvt.s.w    $f1, $f0
    /* FF8E8 001FF8E8 40080146 */  add.s      $f1, $f1, $f1
  .L001FF8EC:
    /* FF8EC 001FF8EC AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF8F0 001FF8F0 02000146 */  mul.s      $f0, $f0, $f1
    /* FF8F4 001FF8F4 9200033C */  lui        $3, %hi(D_00922CB0)
    /* FF8F8 001FF8F8 B02C60E4 */  swc1       $f0, %lo(D_00922CB0)($3)
    /* FF8FC 001FF8FC ED00A393 */  lbu        $3, 0xED($29)
    /* FF900 001FF900 06006004 */  bltz       $3, .L001FF91C
    /* FF904 001FF904 00000000 */   nop
    /* FF908 001FF908 00008344 */  mtc1       $3, $f0
    /* FF90C 001FF90C 00000000 */  nop
    /* FF910 001FF910 60008046 */  cvt.s.w    $f1, $f0
    /* FF914 001FF914 08000010 */  b          .L001FF938
    /* FF918 001FF918 00000000 */   nop
  .L001FF91C:
    /* FF91C 001FF91C 42200300 */  srl        $4, $3, 1
    /* FF920 001FF920 01006330 */  andi       $3, $3, 0x1
    /* FF924 001FF924 25208300 */  or         $4, $4, $3
    /* FF928 001FF928 00008444 */  mtc1       $4, $f0
    /* FF92C 001FF92C 00000000 */  nop
    /* FF930 001FF930 60008046 */  cvt.s.w    $f1, $f0
    /* FF934 001FF934 40080146 */  add.s      $f1, $f1, $f1
  .L001FF938:
    /* FF938 001FF938 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF93C 001FF93C 02000146 */  mul.s      $f0, $f0, $f1
    /* FF940 001FF940 9200033C */  lui        $3, %hi(D_00922CB4)
    /* FF944 001FF944 B42C60E4 */  swc1       $f0, %lo(D_00922CB4)($3)
    /* FF948 001FF948 EE00A393 */  lbu        $3, 0xEE($29)
    /* FF94C 001FF94C 06006004 */  bltz       $3, .L001FF968
    /* FF950 001FF950 00000000 */   nop
    /* FF954 001FF954 00008344 */  mtc1       $3, $f0
    /* FF958 001FF958 00000000 */  nop
    /* FF95C 001FF95C 60008046 */  cvt.s.w    $f1, $f0
    /* FF960 001FF960 08000010 */  b          .L001FF984
    /* FF964 001FF964 00000000 */   nop
  .L001FF968:
    /* FF968 001FF968 42200300 */  srl        $4, $3, 1
    /* FF96C 001FF96C 01006330 */  andi       $3, $3, 0x1
    /* FF970 001FF970 25208300 */  or         $4, $4, $3
    /* FF974 001FF974 00008444 */  mtc1       $4, $f0
    /* FF978 001FF978 00000000 */  nop
    /* FF97C 001FF97C 60008046 */  cvt.s.w    $f1, $f0
    /* FF980 001FF980 40080146 */  add.s      $f1, $f1, $f1
  .L001FF984:
    /* FF984 001FF984 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF988 001FF988 02000146 */  mul.s      $f0, $f0, $f1
    /* FF98C 001FF98C 9200033C */  lui        $3, %hi(D_00922CB8)
    /* FF990 001FF990 B82C60E4 */  swc1       $f0, %lo(D_00922CB8)($3)
    /* FF994 001FF994 EF00A393 */  lbu        $3, 0xEF($29)
    /* FF998 001FF998 06006004 */  bltz       $3, .L001FF9B4
    /* FF99C 001FF99C 00000000 */   nop
    /* FF9A0 001FF9A0 00008344 */  mtc1       $3, $f0
    /* FF9A4 001FF9A4 00000000 */  nop
    /* FF9A8 001FF9A8 60008046 */  cvt.s.w    $f1, $f0
    /* FF9AC 001FF9AC 08000010 */  b          .L001FF9D0
    /* FF9B0 001FF9B0 00000000 */   nop
  .L001FF9B4:
    /* FF9B4 001FF9B4 42200300 */  srl        $4, $3, 1
    /* FF9B8 001FF9B8 01006330 */  andi       $3, $3, 0x1
    /* FF9BC 001FF9BC 25208300 */  or         $4, $4, $3
    /* FF9C0 001FF9C0 00008444 */  mtc1       $4, $f0
    /* FF9C4 001FF9C4 00000000 */  nop
    /* FF9C8 001FF9C8 60008046 */  cvt.s.w    $f1, $f0
    /* FF9CC 001FF9CC 40080146 */  add.s      $f1, $f1, $f1
  .L001FF9D0:
    /* FF9D0 001FF9D0 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF9D4 001FF9D4 02000146 */  mul.s      $f0, $f0, $f1
    /* FF9D8 001FF9D8 9200033C */  lui        $3, %hi(D_00922CBC)
    /* FF9DC 001FF9DC BC2C60E4 */  swc1       $f0, %lo(D_00922CBC)($3)
    /* FF9E0 001FF9E0 01000424 */  addiu      $4, $0, 0x1
    /* FF9E4 001FF9E4 9200033C */  lui        $3, %hi(D_00922CC0)
    /* FF9E8 001FF9E8 C02C64AC */  sw         $4, %lo(D_00922CC0)($3)
    /* FF9EC 001FF9EC 38010010 */  b          .L001FFED0
    /* FF9F0 001FF9F0 00000000 */   nop
  .L001FF9F4:
    /* FF9F4 001FF9F4 19004016 */  bnez       $18, .L001FFA5C
    /* FF9F8 001FF9F8 00000000 */   nop
    /* FF9FC 001FF9FC 9200033C */  lui        $3, %hi(D_00922CA0)
    /* FFA00 001FFA00 A02C63C4 */  lwc1       $f3, %lo(D_00922CA0)($3)
    /* FFA04 001FFA04 9200033C */  lui        $3, %hi(D_00922CA4)
    /* FFA08 001FFA08 A42C62C4 */  lwc1       $f2, %lo(D_00922CA4)($3)
    /* FFA0C 001FFA0C 9200033C */  lui        $3, %hi(D_00922CA8)
    /* FFA10 001FFA10 A82C61C4 */  lwc1       $f1, %lo(D_00922CA8)($3)
    /* FFA14 001FFA14 9200033C */  lui        $3, %hi(D_00922CAC)
    /* FFA18 001FFA18 AC2C60C4 */  lwc1       $f0, %lo(D_00922CAC)($3)
    /* FFA1C 001FFA1C 040083E6 */  swc1       $f3, 0x4($20)
    /* FFA20 001FFA20 080082E6 */  swc1       $f2, 0x8($20)
    /* FFA24 001FFA24 0C0081E6 */  swc1       $f1, 0xC($20)
    /* FFA28 001FFA28 100080E6 */  swc1       $f0, 0x10($20)
    /* FFA2C 001FFA2C 9200033C */  lui        $3, %hi(D_00922CB0)
    /* FFA30 001FFA30 B02C63C4 */  lwc1       $f3, %lo(D_00922CB0)($3)
    /* FFA34 001FFA34 9200033C */  lui        $3, %hi(D_00922CB4)
    /* FFA38 001FFA38 B42C62C4 */  lwc1       $f2, %lo(D_00922CB4)($3)
    /* FFA3C 001FFA3C 9200033C */  lui        $3, %hi(D_00922CB8)
    /* FFA40 001FFA40 B82C61C4 */  lwc1       $f1, %lo(D_00922CB8)($3)
    /* FFA44 001FFA44 9200033C */  lui        $3, %hi(D_00922CBC)
    /* FFA48 001FFA48 BC2C60C4 */  lwc1       $f0, %lo(D_00922CBC)($3)
    /* FFA4C 001FFA4C 140083E6 */  swc1       $f3, 0x14($20)
    /* FFA50 001FFA50 180082E6 */  swc1       $f2, 0x18($20)
    /* FFA54 001FFA54 1C0081E6 */  swc1       $f1, 0x1C($20)
    /* FFA58 001FFA58 200080E6 */  swc1       $f0, 0x20($20)
  .L001FFA5C:
    /* FFA5C 001FFA5C 0800638E */  lw         $3, 0x8($19)
    /* FFA60 001FFA60 EC00A3AF */  sw         $3, 0xEC($29)
    /* FFA64 001FFA64 EC00A393 */  lbu        $3, 0xEC($29)
    /* FFA68 001FFA68 06006004 */  bltz       $3, .L001FFA84
    /* FFA6C 001FFA6C 00000000 */   nop
    /* FFA70 001FFA70 00008344 */  mtc1       $3, $f0
    /* FFA74 001FFA74 00000000 */  nop
    /* FFA78 001FFA78 60008046 */  cvt.s.w    $f1, $f0
    /* FFA7C 001FFA7C 08000010 */  b          .L001FFAA0
    /* FFA80 001FFA80 00000000 */   nop
  .L001FFA84:
    /* FFA84 001FFA84 42200300 */  srl        $4, $3, 1
    /* FFA88 001FFA88 01006330 */  andi       $3, $3, 0x1
    /* FFA8C 001FFA8C 25208300 */  or         $4, $4, $3
    /* FFA90 001FFA90 00008444 */  mtc1       $4, $f0
    /* FFA94 001FFA94 00000000 */  nop
    /* FFA98 001FFA98 60008046 */  cvt.s.w    $f1, $f0
    /* FFA9C 001FFA9C 40080146 */  add.s      $f1, $f1, $f1
  .L001FFAA0:
    /* FFAA0 001FFAA0 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FFAA4 001FFAA4 42020146 */  mul.s      $f9, $f0, $f1
    /* FFAA8 001FFAA8 ED00A393 */  lbu        $3, 0xED($29)
    /* FFAAC 001FFAAC 06006004 */  bltz       $3, .L001FFAC8
    /* FFAB0 001FFAB0 00000000 */   nop
    /* FFAB4 001FFAB4 00008344 */  mtc1       $3, $f0
    /* FFAB8 001FFAB8 00000000 */  nop
    /* FFABC 001FFABC 60008046 */  cvt.s.w    $f1, $f0
    /* FFAC0 001FFAC0 08000010 */  b          .L001FFAE4
    /* FFAC4 001FFAC4 00000000 */   nop
  .L001FFAC8:
    /* FFAC8 001FFAC8 42200300 */  srl        $4, $3, 1
    /* FFACC 001FFACC 01006330 */  andi       $3, $3, 0x1
    /* FFAD0 001FFAD0 25208300 */  or         $4, $4, $3
    /* FFAD4 001FFAD4 00008444 */  mtc1       $4, $f0
    /* FFAD8 001FFAD8 00000000 */  nop
    /* FFADC 001FFADC 60008046 */  cvt.s.w    $f1, $f0
    /* FFAE0 001FFAE0 40080146 */  add.s      $f1, $f1, $f1
  .L001FFAE4:
    /* FFAE4 001FFAE4 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FFAE8 001FFAE8 82000146 */  mul.s      $f2, $f0, $f1
    /* FFAEC 001FFAEC EE00A393 */  lbu        $3, 0xEE($29)
    /* FFAF0 001FFAF0 06006004 */  bltz       $3, .L001FFB0C
    /* FFAF4 001FFAF4 00000000 */   nop
    /* FFAF8 001FFAF8 00008344 */  mtc1       $3, $f0
    /* FFAFC 001FFAFC 00000000 */  nop
    /* FFB00 001FFB00 60008046 */  cvt.s.w    $f1, $f0
    /* FFB04 001FFB04 08000010 */  b          .L001FFB28
    /* FFB08 001FFB08 00000000 */   nop
  .L001FFB0C:
    /* FFB0C 001FFB0C 42200300 */  srl        $4, $3, 1
    /* FFB10 001FFB10 01006330 */  andi       $3, $3, 0x1
    /* FFB14 001FFB14 25208300 */  or         $4, $4, $3
    /* FFB18 001FFB18 00008444 */  mtc1       $4, $f0
    /* FFB1C 001FFB1C 00000000 */  nop
    /* FFB20 001FFB20 60008046 */  cvt.s.w    $f1, $f0
    /* FFB24 001FFB24 40080146 */  add.s      $f1, $f1, $f1
  .L001FFB28:
    /* FFB28 001FFB28 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FFB2C 001FFB2C 02020146 */  mul.s      $f8, $f0, $f1
    /* FFB30 001FFB30 EF00A393 */  lbu        $3, 0xEF($29)
    /* FFB34 001FFB34 06006004 */  bltz       $3, .L001FFB50
    /* FFB38 001FFB38 00000000 */   nop
    /* FFB3C 001FFB3C 00008344 */  mtc1       $3, $f0
    /* FFB40 001FFB40 00000000 */  nop
    /* FFB44 001FFB44 60008046 */  cvt.s.w    $f1, $f0
    /* FFB48 001FFB48 08000010 */  b          .L001FFB6C
    /* FFB4C 001FFB4C 00000000 */   nop
  .L001FFB50:
    /* FFB50 001FFB50 42200300 */  srl        $4, $3, 1
    /* FFB54 001FFB54 01006330 */  andi       $3, $3, 0x1
    /* FFB58 001FFB58 25208300 */  or         $4, $4, $3
    /* FFB5C 001FFB5C 00008444 */  mtc1       $4, $f0
    /* FFB60 001FFB60 00000000 */  nop
    /* FFB64 001FFB64 60008046 */  cvt.s.w    $f1, $f0
    /* FFB68 001FFB68 40080146 */  add.s      $f1, $f1, $f1
  .L001FFB6C:
    /* FFB6C 001FFB6C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FFB70 001FFB70 C2010146 */  mul.s      $f7, $f0, $f1
    /* FFB74 001FFB74 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FFB78 001FFB78 00008344 */  mtc1       $3, $f0
    /* FFB7C 001FFB7C 00000000 */  nop
    /* FFB80 001FFB80 81011446 */  sub.s      $f6, $f0, $f20
    /* FFB84 001FFB84 040080C6 */  lwc1       $f0, 0x4($20)
    /* FFB88 001FFB88 42010646 */  mul.s      $f5, $f0, $f6
    /* FFB8C 001FFB8C 080080C6 */  lwc1       $f0, 0x8($20)
    /* FFB90 001FFB90 02010646 */  mul.s      $f4, $f0, $f6
    /* FFB94 001FFB94 0C0080C6 */  lwc1       $f0, 0xC($20)
    /* FFB98 001FFB98 C2000646 */  mul.s      $f3, $f0, $f6
    /* FFB9C 001FFB9C 100080C6 */  lwc1       $f0, 0x10($20)
    /* FFBA0 001FFBA0 1A000646 */  mula.s     $f0, $f6
    /* FFBA4 001FFBA4 02481446 */  mul.s      $f0, $f9, $f20
    /* FFBA8 001FFBA8 82101446 */  mul.s      $f2, $f2, $f20
    /* FFBAC 001FFBAC 42401446 */  mul.s      $f1, $f8, $f20
    /* FFBB0 001FFBB0 00280046 */  add.s      $f0, $f5, $f0
    /* FFBB4 001FFBB4 9200033C */  lui        $3, %hi(D_00922CA0)
    /* FFBB8 001FFBB8 A02C60E4 */  swc1       $f0, %lo(D_00922CA0)($3)
    /* FFBBC 001FFBBC 00200246 */  add.s      $f0, $f4, $f2
    /* FFBC0 001FFBC0 9200033C */  lui        $3, %hi(D_00922CA4)
    /* FFBC4 001FFBC4 A42C60E4 */  swc1       $f0, %lo(D_00922CA4)($3)
    /* FFBC8 001FFBC8 00180146 */  add.s      $f0, $f3, $f1
    /* FFBCC 001FFBCC 9200033C */  lui        $3, %hi(D_00922CA8)
    /* FFBD0 001FFBD0 A82C60E4 */  swc1       $f0, %lo(D_00922CA8)($3)
    /* FFBD4 001FFBD4 1C381446 */  madd.s     $f0, $f7, $f20
    /* FFBD8 001FFBD8 9200033C */  lui        $3, %hi(D_00922CAC)
    /* FFBDC 001FFBDC AC2C60E4 */  swc1       $f0, %lo(D_00922CAC)($3)
    /* FFBE0 001FFBE0 0C00638E */  lw         $3, 0xC($19)
    /* FFBE4 001FFBE4 EC00A3AF */  sw         $3, 0xEC($29)
    /* FFBE8 001FFBE8 140080C6 */  lwc1       $f0, 0x14($20)
    /* FFBEC 001FFBEC 82000646 */  mul.s      $f2, $f0, $f6
    /* FFBF0 001FFBF0 180080C6 */  lwc1       $f0, 0x18($20)
    /* FFBF4 001FFBF4 42000646 */  mul.s      $f1, $f0, $f6
    /* FFBF8 001FFBF8 1C0080C6 */  lwc1       $f0, 0x1C($20)
    /* FFBFC 001FFBFC 02000646 */  mul.s      $f0, $f0, $f6
    /* FFC00 001FFC00 200083C6 */  lwc1       $f3, 0x20($20)
    /* FFC04 001FFC04 021A0646 */  mul.s      $f8, $f3, $f6
    /* FFC08 001FFC08 EC00A393 */  lbu        $3, 0xEC($29)
    /* FFC0C 001FFC0C 06006004 */  bltz       $3, .L001FFC28
    /* FFC10 001FFC10 00000000 */   nop
    /* FFC14 001FFC14 00188344 */  mtc1       $3, $f3
    /* FFC18 001FFC18 00000000 */  nop
    /* FFC1C 001FFC1C 20198046 */  cvt.s.w    $f4, $f3
    /* FFC20 001FFC20 08000010 */  b          .L001FFC44
    /* FFC24 001FFC24 00000000 */   nop
  .L001FFC28:
    /* FFC28 001FFC28 42200300 */  srl        $4, $3, 1
    /* FFC2C 001FFC2C 01006330 */  andi       $3, $3, 0x1
    /* FFC30 001FFC30 25208300 */  or         $4, $4, $3
    /* FFC34 001FFC34 00188444 */  mtc1       $4, $f3
    /* FFC38 001FFC38 00000000 */  nop
    /* FFC3C 001FFC3C 20198046 */  cvt.s.w    $f4, $f3
    /* FFC40 001FFC40 00210446 */  add.s      $f4, $f4, $f4
  .L001FFC44:
    /* FFC44 001FFC44 AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FFC48 001FFC48 C2180446 */  mul.s      $f3, $f3, $f4
    /* FFC4C 001FFC4C C2191446 */  mul.s      $f7, $f3, $f20
    /* FFC50 001FFC50 ED00A393 */  lbu        $3, 0xED($29)
    /* FFC54 001FFC54 06006004 */  bltz       $3, .L001FFC70
    /* FFC58 001FFC58 00000000 */   nop
    /* FFC5C 001FFC5C 00188344 */  mtc1       $3, $f3
    /* FFC60 001FFC60 00000000 */  nop
    /* FFC64 001FFC64 20198046 */  cvt.s.w    $f4, $f3
    /* FFC68 001FFC68 08000010 */  b          .L001FFC8C
    /* FFC6C 001FFC6C 00000000 */   nop
  .L001FFC70:
    /* FFC70 001FFC70 42200300 */  srl        $4, $3, 1
    /* FFC74 001FFC74 01006330 */  andi       $3, $3, 0x1
    /* FFC78 001FFC78 25208300 */  or         $4, $4, $3
    /* FFC7C 001FFC7C 00188444 */  mtc1       $4, $f3
    /* FFC80 001FFC80 00000000 */  nop
    /* FFC84 001FFC84 20198046 */  cvt.s.w    $f4, $f3
    /* FFC88 001FFC88 00210446 */  add.s      $f4, $f4, $f4
  .L001FFC8C:
    /* FFC8C 001FFC8C AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FFC90 001FFC90 C2180446 */  mul.s      $f3, $f3, $f4
    /* FFC94 001FFC94 82191446 */  mul.s      $f6, $f3, $f20
    /* FFC98 001FFC98 EE00A393 */  lbu        $3, 0xEE($29)
    /* FFC9C 001FFC9C 06006004 */  bltz       $3, .L001FFCB8
    /* FFCA0 001FFCA0 00000000 */   nop
    /* FFCA4 001FFCA4 00188344 */  mtc1       $3, $f3
    /* FFCA8 001FFCA8 00000000 */  nop
    /* FFCAC 001FFCAC 20198046 */  cvt.s.w    $f4, $f3
    /* FFCB0 001FFCB0 08000010 */  b          .L001FFCD4
    /* FFCB4 001FFCB4 00000000 */   nop
  .L001FFCB8:
    /* FFCB8 001FFCB8 42200300 */  srl        $4, $3, 1
    /* FFCBC 001FFCBC 01006330 */  andi       $3, $3, 0x1
    /* FFCC0 001FFCC0 25208300 */  or         $4, $4, $3
    /* FFCC4 001FFCC4 00188444 */  mtc1       $4, $f3
    /* FFCC8 001FFCC8 00000000 */  nop
    /* FFCCC 001FFCCC 20198046 */  cvt.s.w    $f4, $f3
    /* FFCD0 001FFCD0 00210446 */  add.s      $f4, $f4, $f4
  .L001FFCD4:
    /* FFCD4 001FFCD4 AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FFCD8 001FFCD8 C2180446 */  mul.s      $f3, $f3, $f4
    /* FFCDC 001FFCDC 42191446 */  mul.s      $f5, $f3, $f20
    /* FFCE0 001FFCE0 EF00A393 */  lbu        $3, 0xEF($29)
    /* FFCE4 001FFCE4 06006004 */  bltz       $3, .L001FFD00
    /* FFCE8 001FFCE8 00000000 */   nop
    /* FFCEC 001FFCEC 00188344 */  mtc1       $3, $f3
    /* FFCF0 001FFCF0 00000000 */  nop
    /* FFCF4 001FFCF4 20198046 */  cvt.s.w    $f4, $f3
    /* FFCF8 001FFCF8 08000010 */  b          .L001FFD1C
    /* FFCFC 001FFCFC 00000000 */   nop
  .L001FFD00:
    /* FFD00 001FFD00 42200300 */  srl        $4, $3, 1
    /* FFD04 001FFD04 01006330 */  andi       $3, $3, 0x1
    /* FFD08 001FFD08 25208300 */  or         $4, $4, $3
    /* FFD0C 001FFD0C 00188444 */  mtc1       $4, $f3
    /* FFD10 001FFD10 00000000 */  nop
    /* FFD14 001FFD14 20198046 */  cvt.s.w    $f4, $f3
    /* FFD18 001FFD18 00210446 */  add.s      $f4, $f4, $f4
  .L001FFD1C:
    /* FFD1C 001FFD1C AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FFD20 001FFD20 C2180446 */  mul.s      $f3, $f3, $f4
    /* FFD24 001FFD24 C2181446 */  mul.s      $f3, $f3, $f20
    /* FFD28 001FFD28 80100746 */  add.s      $f2, $f2, $f7
    /* FFD2C 001FFD2C 9200033C */  lui        $3, %hi(D_00922CB0)
    /* FFD30 001FFD30 B02C62E4 */  swc1       $f2, %lo(D_00922CB0)($3)
    /* FFD34 001FFD34 40080646 */  add.s      $f1, $f1, $f6
    /* FFD38 001FFD38 9200033C */  lui        $3, %hi(D_00922CB4)
    /* FFD3C 001FFD3C B42C61E4 */  swc1       $f1, %lo(D_00922CB4)($3)
    /* FFD40 001FFD40 00000546 */  add.s      $f0, $f0, $f5
    /* FFD44 001FFD44 9200033C */  lui        $3, %hi(D_00922CB8)
    /* FFD48 001FFD48 B82C60E4 */  swc1       $f0, %lo(D_00922CB8)($3)
    /* FFD4C 001FFD4C 00400346 */  add.s      $f0, $f8, $f3
    /* FFD50 001FFD50 9200033C */  lui        $3, %hi(D_00922CBC)
    /* FFD54 001FFD54 BC2C60E4 */  swc1       $f0, %lo(D_00922CBC)($3)
    /* FFD58 001FFD58 01000424 */  addiu      $4, $0, 0x1
    /* FFD5C 001FFD5C 9200033C */  lui        $3, %hi(D_00922CC0)
    /* FFD60 001FFD60 C02C64AC */  sw         $4, %lo(D_00922CC0)($3)
    /* FFD64 001FFD64 5A000010 */  b          .L001FFED0
    /* FFD68 001FFD68 00000000 */   nop
  .L001FFD6C:
    /* FFD6C 001FFD6C 06006396 */  lhu        $3, 0x6($19)
    /* FFD70 001FFD70 23182302 */  subu       $3, $17, $3
    /* FFD74 001FFD74 19004316 */  bne        $18, $3, .L001FFDDC
    /* FFD78 001FFD78 00000000 */   nop
    /* FFD7C 001FFD7C 9200033C */  lui        $3, %hi(D_00922CA0)
    /* FFD80 001FFD80 A02C63C4 */  lwc1       $f3, %lo(D_00922CA0)($3)
    /* FFD84 001FFD84 9200033C */  lui        $3, %hi(D_00922CA4)
    /* FFD88 001FFD88 A42C62C4 */  lwc1       $f2, %lo(D_00922CA4)($3)
    /* FFD8C 001FFD8C 9200033C */  lui        $3, %hi(D_00922CA8)
    /* FFD90 001FFD90 A82C61C4 */  lwc1       $f1, %lo(D_00922CA8)($3)
    /* FFD94 001FFD94 9200033C */  lui        $3, %hi(D_00922CAC)
    /* FFD98 001FFD98 AC2C60C4 */  lwc1       $f0, %lo(D_00922CAC)($3)
    /* FFD9C 001FFD9C 040083E6 */  swc1       $f3, 0x4($20)
    /* FFDA0 001FFDA0 080082E6 */  swc1       $f2, 0x8($20)
    /* FFDA4 001FFDA4 0C0081E6 */  swc1       $f1, 0xC($20)
    /* FFDA8 001FFDA8 100080E6 */  swc1       $f0, 0x10($20)
    /* FFDAC 001FFDAC 9200033C */  lui        $3, %hi(D_00922CB0)
    /* FFDB0 001FFDB0 B02C63C4 */  lwc1       $f3, %lo(D_00922CB0)($3)
    /* FFDB4 001FFDB4 9200033C */  lui        $3, %hi(D_00922CB4)
    /* FFDB8 001FFDB8 B42C62C4 */  lwc1       $f2, %lo(D_00922CB4)($3)
    /* FFDBC 001FFDBC 9200033C */  lui        $3, %hi(D_00922CB8)
    /* FFDC0 001FFDC0 B82C61C4 */  lwc1       $f1, %lo(D_00922CB8)($3)
    /* FFDC4 001FFDC4 9200033C */  lui        $3, %hi(D_00922CBC)
    /* FFDC8 001FFDC8 BC2C60C4 */  lwc1       $f0, %lo(D_00922CBC)($3)
    /* FFDCC 001FFDCC 140083E6 */  swc1       $f3, 0x14($20)
    /* FFDD0 001FFDD0 180082E6 */  swc1       $f2, 0x18($20)
    /* FFDD4 001FFDD4 1C0081E6 */  swc1       $f1, 0x1C($20)
    /* FFDD8 001FFDD8 200080E6 */  swc1       $f0, 0x20($20)
  .L001FFDDC:
    /* FFDDC 001FFDDC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FFDE0 001FFDE0 00008344 */  mtc1       $3, $f0
    /* FFDE4 001FFDE4 00000000 */  nop
    /* FFDE8 001FFDE8 01021446 */  sub.s      $f8, $f0, $f20
    /* FFDEC 001FFDEC 000000C6 */  lwc1       $f0, 0x0($16)
    /* FFDF0 001FFDF0 C2010846 */  mul.s      $f7, $f0, $f8
    /* FFDF4 001FFDF4 040000C6 */  lwc1       $f0, 0x4($16)
    /* FFDF8 001FFDF8 82010846 */  mul.s      $f6, $f0, $f8
    /* FFDFC 001FFDFC 080000C6 */  lwc1       $f0, 0x8($16)
    /* FFE00 001FFE00 42010846 */  mul.s      $f5, $f0, $f8
    /* FFE04 001FFE04 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* FFE08 001FFE08 1A000846 */  mula.s     $f0, $f8
    /* FFE0C 001FFE0C 040080C6 */  lwc1       $f0, 0x4($20)
    /* FFE10 001FFE10 02011446 */  mul.s      $f4, $f0, $f20
    /* FFE14 001FFE14 080080C6 */  lwc1       $f0, 0x8($20)
    /* FFE18 001FFE18 C2001446 */  mul.s      $f3, $f0, $f20
    /* FFE1C 001FFE1C 0C0080C6 */  lwc1       $f0, 0xC($20)
    /* FFE20 001FFE20 82001446 */  mul.s      $f2, $f0, $f20
    /* FFE24 001FFE24 100081C6 */  lwc1       $f1, 0x10($20)
    /* FFE28 001FFE28 00380446 */  add.s      $f0, $f7, $f4
    /* FFE2C 001FFE2C 9200033C */  lui        $3, %hi(D_00922CA0)
    /* FFE30 001FFE30 A02C60E4 */  swc1       $f0, %lo(D_00922CA0)($3)
    /* FFE34 001FFE34 00300346 */  add.s      $f0, $f6, $f3
    /* FFE38 001FFE38 9200033C */  lui        $3, %hi(D_00922CA4)
    /* FFE3C 001FFE3C A42C60E4 */  swc1       $f0, %lo(D_00922CA4)($3)
    /* FFE40 001FFE40 00280246 */  add.s      $f0, $f5, $f2
    /* FFE44 001FFE44 9200033C */  lui        $3, %hi(D_00922CA8)
    /* FFE48 001FFE48 A82C60E4 */  swc1       $f0, %lo(D_00922CA8)($3)
    /* FFE4C 001FFE4C 1C081446 */  madd.s     $f0, $f1, $f20
    /* FFE50 001FFE50 9200033C */  lui        $3, %hi(D_00922CAC)
    /* FFE54 001FFE54 AC2C60E4 */  swc1       $f0, %lo(D_00922CAC)($3)
    /* FFE58 001FFE58 100000C6 */  lwc1       $f0, 0x10($16)
    /* FFE5C 001FFE5C C2010846 */  mul.s      $f7, $f0, $f8
    /* FFE60 001FFE60 140000C6 */  lwc1       $f0, 0x14($16)
    /* FFE64 001FFE64 82010846 */  mul.s      $f6, $f0, $f8
    /* FFE68 001FFE68 180000C6 */  lwc1       $f0, 0x18($16)
    /* FFE6C 001FFE6C 42010846 */  mul.s      $f5, $f0, $f8
    /* FFE70 001FFE70 1C0000C6 */  lwc1       $f0, 0x1C($16)
    /* FFE74 001FFE74 1A000846 */  mula.s     $f0, $f8
    /* FFE78 001FFE78 140080C6 */  lwc1       $f0, 0x14($20)
    /* FFE7C 001FFE7C 02011446 */  mul.s      $f4, $f0, $f20
    /* FFE80 001FFE80 180080C6 */  lwc1       $f0, 0x18($20)
    /* FFE84 001FFE84 C2001446 */  mul.s      $f3, $f0, $f20
    /* FFE88 001FFE88 1C0080C6 */  lwc1       $f0, 0x1C($20)
    /* FFE8C 001FFE8C 82001446 */  mul.s      $f2, $f0, $f20
    /* FFE90 001FFE90 200081C6 */  lwc1       $f1, 0x20($20)
    /* FFE94 001FFE94 00380446 */  add.s      $f0, $f7, $f4
    /* FFE98 001FFE98 9200033C */  lui        $3, %hi(D_00922CB0)
    /* FFE9C 001FFE9C B02C60E4 */  swc1       $f0, %lo(D_00922CB0)($3)
    /* FFEA0 001FFEA0 00300346 */  add.s      $f0, $f6, $f3
    /* FFEA4 001FFEA4 9200033C */  lui        $3, %hi(D_00922CB4)
    /* FFEA8 001FFEA8 B42C60E4 */  swc1       $f0, %lo(D_00922CB4)($3)
    /* FFEAC 001FFEAC 00280246 */  add.s      $f0, $f5, $f2
    /* FFEB0 001FFEB0 9200033C */  lui        $3, %hi(D_00922CB8)
    /* FFEB4 001FFEB4 B82C60E4 */  swc1       $f0, %lo(D_00922CB8)($3)
    /* FFEB8 001FFEB8 1C081446 */  madd.s     $f0, $f1, $f20
    /* FFEBC 001FFEBC 9200033C */  lui        $3, %hi(D_00922CBC)
    /* FFEC0 001FFEC0 BC2C60E4 */  swc1       $f0, %lo(D_00922CBC)($3)
    /* FFEC4 001FFEC4 01000424 */  addiu      $4, $0, 0x1
    /* FFEC8 001FFEC8 9200033C */  lui        $3, %hi(D_00922CC0)
    /* FFECC 001FFECC C02C64AC */  sw         $4, %lo(D_00922CC0)($3)
  .L001FFED0:
    /* FFED0 001FFED0 0C00E012 */  beqz       $23, .L001FFF04
    /* FFED4 001FFED4 00000000 */   nop
    /* FFED8 001FFED8 A000A627 */  addiu      $6, $29, 0xA0
    /* FFEDC 001FFEDC 9200053C */  lui        $5, %hi(D_00922C60)
    /* FFEE0 001FFEE0 602CA524 */  addiu      $5, $5, %lo(D_00922C60)
    /* FFEE4 001FFEE4 04000424 */  addiu      $4, $0, 0x4
  .L001FFEE8:
    /* FFEE8 001FFEE8 0000C378 */  lq         $3, 0x0($6)
    /* FFEEC 001FFEEC 1000C624 */  addiu      $6, $6, 0x10
    /* FFEF0 001FFEF0 FFFF8424 */  addiu      $4, $4, -0x1
    /* FFEF4 001FFEF4 0000A37C */  sq         $3, 0x0($5)
    /* FFEF8 001FFEF8 1000A524 */  addiu      $5, $5, 0x10
    /* FFEFC 001FFEFC FAFF801C */  bgtz       $4, .L001FFEE8
    /* FFF00 001FFF00 00000000 */   nop
  .L001FFF04:
    /* FFF04 001FFF04 9000BFDF */  ld         $31, 0x90($29)
    /* FFF08 001FFF08 8000B77B */  lq         $23, 0x80($29)
    /* FFF0C 001FFF0C 7000B67B */  lq         $22, 0x70($29)
    /* FFF10 001FFF10 6000B57B */  lq         $21, 0x60($29)
    /* FFF14 001FFF14 5000B47B */  lq         $20, 0x50($29)
    /* FFF18 001FFF18 4000B37B */  lq         $19, 0x40($29)
    /* FFF1C 001FFF1C 3000B27B */  lq         $18, 0x30($29)
    /* FFF20 001FFF20 2000B17B */  lq         $17, 0x20($29)
    /* FFF24 001FFF24 1000B07B */  lq         $16, 0x10($29)
    /* FFF28 001FFF28 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* FFF2C 001FFF2C F000BD27 */  addiu      $29, $29, 0xF0
    /* FFF30 001FFF30 0800E003 */  jr         $31
    /* FFF34 001FFF34 00000000 */   nop
    /* FFF38 001FFF38 00000000 */  nop
    /* FFF3C 001FFF3C 00000000 */  nop
.size func_001ff490, 0xab0
