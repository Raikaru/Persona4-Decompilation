.section .text
.set noat
.set noreorder
glabel func_004bc540
    /* 3BC540 004BC540 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BC544 004BC544 0800A727 */  addiu      $7, $29, 0x8
    /* 3BC548 004BC548 08000324 */  addiu      $3, $0, 0x8
    /* 3BC54C 004BC54C 0800E010 */  beqz       $7, .L004BC570
    /* 3BC550 004BC550 00000000 */   nop
  .L004BC554:
    /* 3BC554 004BC554 0000E0A0 */  sb         $0, 0x0($7)
    /* 3BC558 004BC558 0100E724 */  addiu      $7, $7, 0x1
    /* 3BC55C 004BC55C FFFF6324 */  addiu      $3, $3, -0x1
    /* 3BC560 004BC560 00000000 */  nop
    /* 3BC564 004BC564 00000000 */  nop
    /* 3BC568 004BC568 FAFF6014 */  bnez       $3, .L004BC554
    /* 3BC56C 004BC56C 00000000 */   nop
  .L004BC570:
    /* 3BC570 004BC570 C0280500 */  sll        $5, $5, 3
    /* 3BC574 004BC574 0000838C */  lw         $3, 0x0($4)
    /* 3BC578 004BC578 0400638C */  lw         $3, 0x4($3)
    /* 3BC57C 004BC57C 21286500 */  addu       $5, $3, $5
    /* 3BC580 004BC580 0800A324 */  addiu      $3, $5, 0x8
    /* 3BC584 004BC584 0800A3AF */  sw         $3, 0x8($29)
    /* 3BC588 004BC588 0C00A524 */  addiu      $5, $5, 0xC
    /* 3BC58C 004BC58C 0C00A5AF */  sw         $5, 0xC($29)
    /* 3BC590 004BC590 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 3BC594 004BC594 00288344 */  mtc1       $3, $f5
    /* 3BC598 004BC598 00000000 */  nop
    /* 3BC59C 004BC59C 41280C46 */  sub.s      $f1, $f5, $f12
    /* 3BC5A0 004BC5A0 0400838C */  lw         $3, 0x4($4)
    /* 3BC5A4 004BC5A4 01006330 */  andi       $3, $3, 0x1
    /* 3BC5A8 004BC5A8 F9006010 */  beqz       $3, .L004BC990
    /* 3BC5AC 004BC5AC 00000000 */   nop
    /* 3BC5B0 004BC5B0 340084C4 */  lwc1       $f4, 0x34($4)
    /* 3BC5B4 004BC5B4 00188044 */  mtc1       $0, $f3
    /* 3BC5B8 004BC5B8 00000000 */  nop
    /* 3BC5BC 004BC5BC 36200346 */  c.le.s     $f4, $f3
    /* 3BC5C0 004BC5C0 0D000145 */  bc1t       .L004BC5F8
    /* 3BC5C4 004BC5C4 00000000 */   nop
    /* 3BC5C8 004BC5C8 2C0082C4 */  lwc1       $f2, 0x2C($4)
    /* 3BC5CC 004BC5CC 300080C4 */  lwc1       $f0, 0x30($4)
    /* 3BC5D0 004BC5D0 01100046 */  sub.s      $f0, $f2, $f0
    /* 3BC5D4 004BC5D4 03000446 */  div.s      $f0, $f0, $f4
    /* 3BC5D8 004BC5D8 00000000 */  nop
    /* 3BC5DC 004BC5DC 01280046 */  sub.s      $f0, $f5, $f0
    /* 3BC5E0 004BC5E0 34000346 */  c.lt.s     $f0, $f3
    /* 3BC5E4 004BC5E4 10000045 */  bc1f       .L004BC628
    /* 3BC5E8 004BC5E8 00000000 */   nop
    /* 3BC5EC 004BC5EC 06180046 */  mov.s      $f0, $f3
    /* 3BC5F0 004BC5F0 0D000010 */  b          .L004BC628
    /* 3BC5F4 004BC5F4 00000000 */   nop
  .L004BC5F8:
    /* 3BC5F8 004BC5F8 32180446 */  c.eq.s     $f3, $f4
    /* 3BC5FC 004BC5FC 0A000045 */  bc1f       .L004BC628
    /* 3BC600 004BC600 00000000 */   nop
    /* 3BC604 004BC604 2C0082C4 */  lwc1       $f2, 0x2C($4)
    /* 3BC608 004BC608 300080C4 */  lwc1       $f0, 0x30($4)
    /* 3BC60C 004BC60C 34100046 */  c.lt.s     $f2, $f0
    /* 3BC610 004BC610 04000145 */  bc1t       .L004BC624
    /* 3BC614 004BC614 00000000 */   nop
    /* 3BC618 004BC618 06180046 */  mov.s      $f0, $f3
    /* 3BC61C 004BC61C 02000010 */  b          .L004BC628
    /* 3BC620 004BC620 00000000 */   nop
  .L004BC624:
    /* 3BC624 004BC624 06280046 */  mov.s      $f0, $f5
  .L004BC628:
    /* 3BC628 004BC628 0C00A38F */  lw         $3, 0xC($29)
    /* 3BC62C 004BC62C 00006390 */  lbu        $3, 0x0($3)
    /* 3BC630 004BC630 06006004 */  bltz       $3, .L004BC64C
    /* 3BC634 004BC634 00000000 */   nop
    /* 3BC638 004BC638 00108344 */  mtc1       $3, $f2
    /* 3BC63C 004BC63C 00000000 */  nop
    /* 3BC640 004BC640 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC644 004BC644 08000010 */  b          .L004BC668
    /* 3BC648 004BC648 00000000 */   nop
  .L004BC64C:
    /* 3BC64C 004BC64C 42200300 */  srl        $4, $3, 1
    /* 3BC650 004BC650 01006330 */  andi       $3, $3, 0x1
    /* 3BC654 004BC654 25208300 */  or         $4, $4, $3
    /* 3BC658 004BC658 00108444 */  mtc1       $4, $f2
    /* 3BC65C 004BC65C 00000000 */  nop
    /* 3BC660 004BC660 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC664 004BC664 C0180346 */  add.s      $f3, $f3, $f3
  .L004BC668:
    /* 3BC668 004BC668 0800A38F */  lw         $3, 0x8($29)
    /* 3BC66C 004BC66C 00006390 */  lbu        $3, 0x0($3)
    /* 3BC670 004BC670 06006004 */  bltz       $3, .L004BC68C
    /* 3BC674 004BC674 00000000 */   nop
    /* 3BC678 004BC678 00108344 */  mtc1       $3, $f2
    /* 3BC67C 004BC67C 00000000 */  nop
    /* 3BC680 004BC680 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC684 004BC684 08000010 */  b          .L004BC6A8
    /* 3BC688 004BC688 00000000 */   nop
  .L004BC68C:
    /* 3BC68C 004BC68C 42200300 */  srl        $4, $3, 1
    /* 3BC690 004BC690 01006330 */  andi       $3, $3, 0x1
    /* 3BC694 004BC694 25208300 */  or         $4, $4, $3
    /* 3BC698 004BC698 00108444 */  mtc1       $4, $f2
    /* 3BC69C 004BC69C 00000000 */  nop
    /* 3BC6A0 004BC6A0 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC6A4 004BC6A4 80100246 */  add.s      $f2, $f2, $f2
  .L004BC6A8:
    /* 3BC6A8 004BC6A8 1A080246 */  mula.s     $f1, $f2
    /* 3BC6AC 004BC6AC 9C600346 */  madd.s     $f2, $f12, $f3
    /* 3BC6B0 004BC6B0 C2000246 */  mul.s      $f3, $f0, $f2
    /* 3BC6B4 004BC6B4 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BC6B8 004BC6B8 00108344 */  mtc1       $3, $f2
    /* 3BC6BC 004BC6BC 00000000 */  nop
    /* 3BC6C0 004BC6C0 36100346 */  c.le.s     $f2, $f3
    /* 3BC6C4 004BC6C4 07000145 */  bc1t       .L004BC6E4
    /* 3BC6C8 004BC6C8 00000000 */   nop
    /* 3BC6CC 004BC6CC A4180046 */  .word      0x460018A4                    # cvt.w.s    $f2, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC6D0 004BC6D0 00100444 */  mfc1       $4, $f2
    /* 3BC6D4 004BC6D4 00000000 */  nop
    /* 3BC6D8 004BC6D8 FF008430 */  andi       $4, $4, 0xFF
    /* 3BC6DC 004BC6DC 07000010 */  b          .L004BC6FC
    /* 3BC6E0 004BC6E0 00000000 */   nop
  .L004BC6E4:
    /* 3BC6E4 004BC6E4 81180246 */  sub.s      $f2, $f3, $f2
    /* 3BC6E8 004BC6E8 A4100046 */  .word      0x460010A4                    # cvt.w.s    $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC6EC 004BC6EC 00100444 */  mfc1       $4, $f2
    /* 3BC6F0 004BC6F0 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BC6F4 004BC6F4 25208300 */  or         $4, $4, $3
    /* 3BC6F8 004BC6F8 FF008430 */  andi       $4, $4, 0xFF
  .L004BC6FC:
    /* 3BC6FC 004BC6FC 0000C4A0 */  sb         $4, 0x0($6)
    /* 3BC700 004BC700 0C00A38F */  lw         $3, 0xC($29)
    /* 3BC704 004BC704 01006390 */  lbu        $3, 0x1($3)
    /* 3BC708 004BC708 06006004 */  bltz       $3, .L004BC724
    /* 3BC70C 004BC70C 00000000 */   nop
    /* 3BC710 004BC710 00108344 */  mtc1       $3, $f2
    /* 3BC714 004BC714 00000000 */  nop
    /* 3BC718 004BC718 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC71C 004BC71C 08000010 */  b          .L004BC740
    /* 3BC720 004BC720 00000000 */   nop
  .L004BC724:
    /* 3BC724 004BC724 42200300 */  srl        $4, $3, 1
    /* 3BC728 004BC728 01006330 */  andi       $3, $3, 0x1
    /* 3BC72C 004BC72C 25208300 */  or         $4, $4, $3
    /* 3BC730 004BC730 00108444 */  mtc1       $4, $f2
    /* 3BC734 004BC734 00000000 */  nop
    /* 3BC738 004BC738 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC73C 004BC73C C0180346 */  add.s      $f3, $f3, $f3
  .L004BC740:
    /* 3BC740 004BC740 0800A38F */  lw         $3, 0x8($29)
    /* 3BC744 004BC744 01006390 */  lbu        $3, 0x1($3)
    /* 3BC748 004BC748 06006004 */  bltz       $3, .L004BC764
    /* 3BC74C 004BC74C 00000000 */   nop
    /* 3BC750 004BC750 00108344 */  mtc1       $3, $f2
    /* 3BC754 004BC754 00000000 */  nop
    /* 3BC758 004BC758 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC75C 004BC75C 08000010 */  b          .L004BC780
    /* 3BC760 004BC760 00000000 */   nop
  .L004BC764:
    /* 3BC764 004BC764 42200300 */  srl        $4, $3, 1
    /* 3BC768 004BC768 01006330 */  andi       $3, $3, 0x1
    /* 3BC76C 004BC76C 25208300 */  or         $4, $4, $3
    /* 3BC770 004BC770 00108444 */  mtc1       $4, $f2
    /* 3BC774 004BC774 00000000 */  nop
    /* 3BC778 004BC778 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC77C 004BC77C 80100246 */  add.s      $f2, $f2, $f2
  .L004BC780:
    /* 3BC780 004BC780 1A080246 */  mula.s     $f1, $f2
    /* 3BC784 004BC784 9C600346 */  madd.s     $f2, $f12, $f3
    /* 3BC788 004BC788 C2000246 */  mul.s      $f3, $f0, $f2
    /* 3BC78C 004BC78C 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BC790 004BC790 00108344 */  mtc1       $3, $f2
    /* 3BC794 004BC794 00000000 */  nop
    /* 3BC798 004BC798 36100346 */  c.le.s     $f2, $f3
    /* 3BC79C 004BC79C 07000145 */  bc1t       .L004BC7BC
    /* 3BC7A0 004BC7A0 00000000 */   nop
    /* 3BC7A4 004BC7A4 A4180046 */  .word      0x460018A4                    # cvt.w.s    $f2, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC7A8 004BC7A8 00100444 */  mfc1       $4, $f2
    /* 3BC7AC 004BC7AC 00000000 */  nop
    /* 3BC7B0 004BC7B0 FF008430 */  andi       $4, $4, 0xFF
    /* 3BC7B4 004BC7B4 07000010 */  b          .L004BC7D4
    /* 3BC7B8 004BC7B8 00000000 */   nop
  .L004BC7BC:
    /* 3BC7BC 004BC7BC 81180246 */  sub.s      $f2, $f3, $f2
    /* 3BC7C0 004BC7C0 A4100046 */  .word      0x460010A4                    # cvt.w.s    $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC7C4 004BC7C4 00100444 */  mfc1       $4, $f2
    /* 3BC7C8 004BC7C8 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BC7CC 004BC7CC 25208300 */  or         $4, $4, $3
    /* 3BC7D0 004BC7D0 FF008430 */  andi       $4, $4, 0xFF
  .L004BC7D4:
    /* 3BC7D4 004BC7D4 0100C4A0 */  sb         $4, 0x1($6)
    /* 3BC7D8 004BC7D8 0C00A38F */  lw         $3, 0xC($29)
    /* 3BC7DC 004BC7DC 02006390 */  lbu        $3, 0x2($3)
    /* 3BC7E0 004BC7E0 06006004 */  bltz       $3, .L004BC7FC
    /* 3BC7E4 004BC7E4 00000000 */   nop
    /* 3BC7E8 004BC7E8 00108344 */  mtc1       $3, $f2
    /* 3BC7EC 004BC7EC 00000000 */  nop
    /* 3BC7F0 004BC7F0 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC7F4 004BC7F4 08000010 */  b          .L004BC818
    /* 3BC7F8 004BC7F8 00000000 */   nop
  .L004BC7FC:
    /* 3BC7FC 004BC7FC 42200300 */  srl        $4, $3, 1
    /* 3BC800 004BC800 01006330 */  andi       $3, $3, 0x1
    /* 3BC804 004BC804 25208300 */  or         $4, $4, $3
    /* 3BC808 004BC808 00108444 */  mtc1       $4, $f2
    /* 3BC80C 004BC80C 00000000 */  nop
    /* 3BC810 004BC810 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC814 004BC814 C0180346 */  add.s      $f3, $f3, $f3
  .L004BC818:
    /* 3BC818 004BC818 0800A38F */  lw         $3, 0x8($29)
    /* 3BC81C 004BC81C 02006390 */  lbu        $3, 0x2($3)
    /* 3BC820 004BC820 06006004 */  bltz       $3, .L004BC83C
    /* 3BC824 004BC824 00000000 */   nop
    /* 3BC828 004BC828 00108344 */  mtc1       $3, $f2
    /* 3BC82C 004BC82C 00000000 */  nop
    /* 3BC830 004BC830 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC834 004BC834 08000010 */  b          .L004BC858
    /* 3BC838 004BC838 00000000 */   nop
  .L004BC83C:
    /* 3BC83C 004BC83C 42200300 */  srl        $4, $3, 1
    /* 3BC840 004BC840 01006330 */  andi       $3, $3, 0x1
    /* 3BC844 004BC844 25208300 */  or         $4, $4, $3
    /* 3BC848 004BC848 00108444 */  mtc1       $4, $f2
    /* 3BC84C 004BC84C 00000000 */  nop
    /* 3BC850 004BC850 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC854 004BC854 80100246 */  add.s      $f2, $f2, $f2
  .L004BC858:
    /* 3BC858 004BC858 1A080246 */  mula.s     $f1, $f2
    /* 3BC85C 004BC85C 9C600346 */  madd.s     $f2, $f12, $f3
    /* 3BC860 004BC860 C2000246 */  mul.s      $f3, $f0, $f2
    /* 3BC864 004BC864 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BC868 004BC868 00108344 */  mtc1       $3, $f2
    /* 3BC86C 004BC86C 00000000 */  nop
    /* 3BC870 004BC870 36100346 */  c.le.s     $f2, $f3
    /* 3BC874 004BC874 07000145 */  bc1t       .L004BC894
    /* 3BC878 004BC878 00000000 */   nop
    /* 3BC87C 004BC87C A4180046 */  .word      0x460018A4                    # cvt.w.s    $f2, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC880 004BC880 00100444 */  mfc1       $4, $f2
    /* 3BC884 004BC884 00000000 */  nop
    /* 3BC888 004BC888 FF008430 */  andi       $4, $4, 0xFF
    /* 3BC88C 004BC88C 07000010 */  b          .L004BC8AC
    /* 3BC890 004BC890 00000000 */   nop
  .L004BC894:
    /* 3BC894 004BC894 81180246 */  sub.s      $f2, $f3, $f2
    /* 3BC898 004BC898 A4100046 */  .word      0x460010A4                    # cvt.w.s    $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC89C 004BC89C 00100444 */  mfc1       $4, $f2
    /* 3BC8A0 004BC8A0 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BC8A4 004BC8A4 25208300 */  or         $4, $4, $3
    /* 3BC8A8 004BC8A8 FF008430 */  andi       $4, $4, 0xFF
  .L004BC8AC:
    /* 3BC8AC 004BC8AC 0200C4A0 */  sb         $4, 0x2($6)
    /* 3BC8B0 004BC8B0 0C00A38F */  lw         $3, 0xC($29)
    /* 3BC8B4 004BC8B4 03006390 */  lbu        $3, 0x3($3)
    /* 3BC8B8 004BC8B8 06006004 */  bltz       $3, .L004BC8D4
    /* 3BC8BC 004BC8BC 00000000 */   nop
    /* 3BC8C0 004BC8C0 00108344 */  mtc1       $3, $f2
    /* 3BC8C4 004BC8C4 00000000 */  nop
    /* 3BC8C8 004BC8C8 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC8CC 004BC8CC 08000010 */  b          .L004BC8F0
    /* 3BC8D0 004BC8D0 00000000 */   nop
  .L004BC8D4:
    /* 3BC8D4 004BC8D4 42200300 */  srl        $4, $3, 1
    /* 3BC8D8 004BC8D8 01006330 */  andi       $3, $3, 0x1
    /* 3BC8DC 004BC8DC 25208300 */  or         $4, $4, $3
    /* 3BC8E0 004BC8E0 00108444 */  mtc1       $4, $f2
    /* 3BC8E4 004BC8E4 00000000 */  nop
    /* 3BC8E8 004BC8E8 E0108046 */  cvt.s.w    $f3, $f2
    /* 3BC8EC 004BC8EC C0180346 */  add.s      $f3, $f3, $f3
  .L004BC8F0:
    /* 3BC8F0 004BC8F0 0800A38F */  lw         $3, 0x8($29)
    /* 3BC8F4 004BC8F4 03006390 */  lbu        $3, 0x3($3)
    /* 3BC8F8 004BC8F8 06006004 */  bltz       $3, .L004BC914
    /* 3BC8FC 004BC8FC 00000000 */   nop
    /* 3BC900 004BC900 00108344 */  mtc1       $3, $f2
    /* 3BC904 004BC904 00000000 */  nop
    /* 3BC908 004BC908 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC90C 004BC90C 08000010 */  b          .L004BC930
    /* 3BC910 004BC910 00000000 */   nop
  .L004BC914:
    /* 3BC914 004BC914 42200300 */  srl        $4, $3, 1
    /* 3BC918 004BC918 01006330 */  andi       $3, $3, 0x1
    /* 3BC91C 004BC91C 25208300 */  or         $4, $4, $3
    /* 3BC920 004BC920 00108444 */  mtc1       $4, $f2
    /* 3BC924 004BC924 00000000 */  nop
    /* 3BC928 004BC928 A0108046 */  cvt.s.w    $f2, $f2
    /* 3BC92C 004BC92C 80100246 */  add.s      $f2, $f2, $f2
  .L004BC930:
    /* 3BC930 004BC930 1A080246 */  mula.s     $f1, $f2
    /* 3BC934 004BC934 5C600346 */  madd.s     $f1, $f12, $f3
    /* 3BC938 004BC938 42000146 */  mul.s      $f1, $f0, $f1
    /* 3BC93C 004BC93C 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BC940 004BC940 00008344 */  mtc1       $3, $f0
    /* 3BC944 004BC944 00000000 */  nop
    /* 3BC948 004BC948 36000146 */  c.le.s     $f0, $f1
    /* 3BC94C 004BC94C 07000145 */  bc1t       .L004BC96C
    /* 3BC950 004BC950 00000000 */   nop
    /* 3BC954 004BC954 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC958 004BC958 00000444 */  mfc1       $4, $f0
    /* 3BC95C 004BC95C 00000000 */  nop
    /* 3BC960 004BC960 FF008430 */  andi       $4, $4, 0xFF
    /* 3BC964 004BC964 07000010 */  b          .L004BC984
    /* 3BC968 004BC968 00000000 */   nop
  .L004BC96C:
    /* 3BC96C 004BC96C 01080046 */  sub.s      $f0, $f1, $f0
    /* 3BC970 004BC970 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BC974 004BC974 00000444 */  mfc1       $4, $f0
    /* 3BC978 004BC978 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BC97C 004BC97C 25208300 */  or         $4, $4, $3
    /* 3BC980 004BC980 FF008430 */  andi       $4, $4, 0xFF
  .L004BC984:
    /* 3BC984 004BC984 0300C4A0 */  sb         $4, 0x3($6)
    /* 3BC988 004BC988 D4000010 */  b          .L004BCCDC
    /* 3BC98C 004BC98C 00000000 */   nop
  .L004BC990:
    /* 3BC990 004BC990 0000A390 */  lbu        $3, 0x0($5)
    /* 3BC994 004BC994 06006004 */  bltz       $3, .L004BC9B0
    /* 3BC998 004BC998 00000000 */   nop
    /* 3BC99C 004BC99C 00008344 */  mtc1       $3, $f0
    /* 3BC9A0 004BC9A0 00000000 */  nop
    /* 3BC9A4 004BC9A4 A0008046 */  cvt.s.w    $f2, $f0
    /* 3BC9A8 004BC9A8 08000010 */  b          .L004BC9CC
    /* 3BC9AC 004BC9AC 00000000 */   nop
  .L004BC9B0:
    /* 3BC9B0 004BC9B0 42200300 */  srl        $4, $3, 1
    /* 3BC9B4 004BC9B4 01006330 */  andi       $3, $3, 0x1
    /* 3BC9B8 004BC9B8 25208300 */  or         $4, $4, $3
    /* 3BC9BC 004BC9BC 00008444 */  mtc1       $4, $f0
    /* 3BC9C0 004BC9C0 00000000 */  nop
    /* 3BC9C4 004BC9C4 A0008046 */  cvt.s.w    $f2, $f0
    /* 3BC9C8 004BC9C8 80100246 */  add.s      $f2, $f2, $f2
  .L004BC9CC:
    /* 3BC9CC 004BC9CC 0800A38F */  lw         $3, 0x8($29)
    /* 3BC9D0 004BC9D0 00006390 */  lbu        $3, 0x0($3)
    /* 3BC9D4 004BC9D4 06006004 */  bltz       $3, .L004BC9F0
    /* 3BC9D8 004BC9D8 00000000 */   nop
    /* 3BC9DC 004BC9DC 00008344 */  mtc1       $3, $f0
    /* 3BC9E0 004BC9E0 00000000 */  nop
    /* 3BC9E4 004BC9E4 20008046 */  cvt.s.w    $f0, $f0
    /* 3BC9E8 004BC9E8 08000010 */  b          .L004BCA0C
    /* 3BC9EC 004BC9EC 00000000 */   nop
  .L004BC9F0:
    /* 3BC9F0 004BC9F0 42200300 */  srl        $4, $3, 1
    /* 3BC9F4 004BC9F4 01006330 */  andi       $3, $3, 0x1
    /* 3BC9F8 004BC9F8 25208300 */  or         $4, $4, $3
    /* 3BC9FC 004BC9FC 00008444 */  mtc1       $4, $f0
    /* 3BCA00 004BCA00 00000000 */  nop
    /* 3BCA04 004BCA04 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCA08 004BCA08 00000046 */  add.s      $f0, $f0, $f0
  .L004BCA0C:
    /* 3BCA0C 004BCA0C 1A080046 */  mula.s     $f1, $f0
    /* 3BCA10 004BCA10 9C600246 */  madd.s     $f2, $f12, $f2
    /* 3BCA14 004BCA14 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BCA18 004BCA18 00008344 */  mtc1       $3, $f0
    /* 3BCA1C 004BCA1C 00000000 */  nop
    /* 3BCA20 004BCA20 36000246 */  c.le.s     $f0, $f2
    /* 3BCA24 004BCA24 07000145 */  bc1t       .L004BCA44
    /* 3BCA28 004BCA28 00000000 */   nop
    /* 3BCA2C 004BCA2C 24100046 */  .word      0x46001024                    # cvt.w.s    $f0, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCA30 004BCA30 00000444 */  mfc1       $4, $f0
    /* 3BCA34 004BCA34 00000000 */  nop
    /* 3BCA38 004BCA38 FF008430 */  andi       $4, $4, 0xFF
    /* 3BCA3C 004BCA3C 07000010 */  b          .L004BCA5C
    /* 3BCA40 004BCA40 00000000 */   nop
  .L004BCA44:
    /* 3BCA44 004BCA44 01100046 */  sub.s      $f0, $f2, $f0
    /* 3BCA48 004BCA48 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCA4C 004BCA4C 00000444 */  mfc1       $4, $f0
    /* 3BCA50 004BCA50 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BCA54 004BCA54 25208300 */  or         $4, $4, $3
    /* 3BCA58 004BCA58 FF008430 */  andi       $4, $4, 0xFF
  .L004BCA5C:
    /* 3BCA5C 004BCA5C 0000C4A0 */  sb         $4, 0x0($6)
    /* 3BCA60 004BCA60 0C00A38F */  lw         $3, 0xC($29)
    /* 3BCA64 004BCA64 01006390 */  lbu        $3, 0x1($3)
    /* 3BCA68 004BCA68 06006004 */  bltz       $3, .L004BCA84
    /* 3BCA6C 004BCA6C 00000000 */   nop
    /* 3BCA70 004BCA70 00008344 */  mtc1       $3, $f0
    /* 3BCA74 004BCA74 00000000 */  nop
    /* 3BCA78 004BCA78 A0008046 */  cvt.s.w    $f2, $f0
    /* 3BCA7C 004BCA7C 08000010 */  b          .L004BCAA0
    /* 3BCA80 004BCA80 00000000 */   nop
  .L004BCA84:
    /* 3BCA84 004BCA84 42200300 */  srl        $4, $3, 1
    /* 3BCA88 004BCA88 01006330 */  andi       $3, $3, 0x1
    /* 3BCA8C 004BCA8C 25208300 */  or         $4, $4, $3
    /* 3BCA90 004BCA90 00008444 */  mtc1       $4, $f0
    /* 3BCA94 004BCA94 00000000 */  nop
    /* 3BCA98 004BCA98 A0008046 */  cvt.s.w    $f2, $f0
    /* 3BCA9C 004BCA9C 80100246 */  add.s      $f2, $f2, $f2
  .L004BCAA0:
    /* 3BCAA0 004BCAA0 0800A38F */  lw         $3, 0x8($29)
    /* 3BCAA4 004BCAA4 01006390 */  lbu        $3, 0x1($3)
    /* 3BCAA8 004BCAA8 06006004 */  bltz       $3, .L004BCAC4
    /* 3BCAAC 004BCAAC 00000000 */   nop
    /* 3BCAB0 004BCAB0 00008344 */  mtc1       $3, $f0
    /* 3BCAB4 004BCAB4 00000000 */  nop
    /* 3BCAB8 004BCAB8 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCABC 004BCABC 08000010 */  b          .L004BCAE0
    /* 3BCAC0 004BCAC0 00000000 */   nop
  .L004BCAC4:
    /* 3BCAC4 004BCAC4 42200300 */  srl        $4, $3, 1
    /* 3BCAC8 004BCAC8 01006330 */  andi       $3, $3, 0x1
    /* 3BCACC 004BCACC 25208300 */  or         $4, $4, $3
    /* 3BCAD0 004BCAD0 00008444 */  mtc1       $4, $f0
    /* 3BCAD4 004BCAD4 00000000 */  nop
    /* 3BCAD8 004BCAD8 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCADC 004BCADC 00000046 */  add.s      $f0, $f0, $f0
  .L004BCAE0:
    /* 3BCAE0 004BCAE0 1A080046 */  mula.s     $f1, $f0
    /* 3BCAE4 004BCAE4 9C600246 */  madd.s     $f2, $f12, $f2
    /* 3BCAE8 004BCAE8 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BCAEC 004BCAEC 00008344 */  mtc1       $3, $f0
    /* 3BCAF0 004BCAF0 00000000 */  nop
    /* 3BCAF4 004BCAF4 36000246 */  c.le.s     $f0, $f2
    /* 3BCAF8 004BCAF8 07000145 */  bc1t       .L004BCB18
    /* 3BCAFC 004BCAFC 00000000 */   nop
    /* 3BCB00 004BCB00 24100046 */  .word      0x46001024                    # cvt.w.s    $f0, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCB04 004BCB04 00000444 */  mfc1       $4, $f0
    /* 3BCB08 004BCB08 00000000 */  nop
    /* 3BCB0C 004BCB0C FF008430 */  andi       $4, $4, 0xFF
    /* 3BCB10 004BCB10 07000010 */  b          .L004BCB30
    /* 3BCB14 004BCB14 00000000 */   nop
  .L004BCB18:
    /* 3BCB18 004BCB18 01100046 */  sub.s      $f0, $f2, $f0
    /* 3BCB1C 004BCB1C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCB20 004BCB20 00000444 */  mfc1       $4, $f0
    /* 3BCB24 004BCB24 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BCB28 004BCB28 25208300 */  or         $4, $4, $3
    /* 3BCB2C 004BCB2C FF008430 */  andi       $4, $4, 0xFF
  .L004BCB30:
    /* 3BCB30 004BCB30 0100C4A0 */  sb         $4, 0x1($6)
    /* 3BCB34 004BCB34 0C00A38F */  lw         $3, 0xC($29)
    /* 3BCB38 004BCB38 02006390 */  lbu        $3, 0x2($3)
    /* 3BCB3C 004BCB3C 06006004 */  bltz       $3, .L004BCB58
    /* 3BCB40 004BCB40 00000000 */   nop
    /* 3BCB44 004BCB44 00008344 */  mtc1       $3, $f0
    /* 3BCB48 004BCB48 00000000 */  nop
    /* 3BCB4C 004BCB4C A0008046 */  cvt.s.w    $f2, $f0
    /* 3BCB50 004BCB50 08000010 */  b          .L004BCB74
    /* 3BCB54 004BCB54 00000000 */   nop
  .L004BCB58:
    /* 3BCB58 004BCB58 42200300 */  srl        $4, $3, 1
    /* 3BCB5C 004BCB5C 01006330 */  andi       $3, $3, 0x1
    /* 3BCB60 004BCB60 25208300 */  or         $4, $4, $3
    /* 3BCB64 004BCB64 00008444 */  mtc1       $4, $f0
    /* 3BCB68 004BCB68 00000000 */  nop
    /* 3BCB6C 004BCB6C A0008046 */  cvt.s.w    $f2, $f0
    /* 3BCB70 004BCB70 80100246 */  add.s      $f2, $f2, $f2
  .L004BCB74:
    /* 3BCB74 004BCB74 0800A38F */  lw         $3, 0x8($29)
    /* 3BCB78 004BCB78 02006390 */  lbu        $3, 0x2($3)
    /* 3BCB7C 004BCB7C 06006004 */  bltz       $3, .L004BCB98
    /* 3BCB80 004BCB80 00000000 */   nop
    /* 3BCB84 004BCB84 00008344 */  mtc1       $3, $f0
    /* 3BCB88 004BCB88 00000000 */  nop
    /* 3BCB8C 004BCB8C 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCB90 004BCB90 08000010 */  b          .L004BCBB4
    /* 3BCB94 004BCB94 00000000 */   nop
  .L004BCB98:
    /* 3BCB98 004BCB98 42200300 */  srl        $4, $3, 1
    /* 3BCB9C 004BCB9C 01006330 */  andi       $3, $3, 0x1
    /* 3BCBA0 004BCBA0 25208300 */  or         $4, $4, $3
    /* 3BCBA4 004BCBA4 00008444 */  mtc1       $4, $f0
    /* 3BCBA8 004BCBA8 00000000 */  nop
    /* 3BCBAC 004BCBAC 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCBB0 004BCBB0 00000046 */  add.s      $f0, $f0, $f0
  .L004BCBB4:
    /* 3BCBB4 004BCBB4 1A080046 */  mula.s     $f1, $f0
    /* 3BCBB8 004BCBB8 9C600246 */  madd.s     $f2, $f12, $f2
    /* 3BCBBC 004BCBBC 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BCBC0 004BCBC0 00008344 */  mtc1       $3, $f0
    /* 3BCBC4 004BCBC4 00000000 */  nop
    /* 3BCBC8 004BCBC8 36000246 */  c.le.s     $f0, $f2
    /* 3BCBCC 004BCBCC 07000145 */  bc1t       .L004BCBEC
    /* 3BCBD0 004BCBD0 00000000 */   nop
    /* 3BCBD4 004BCBD4 24100046 */  .word      0x46001024                    # cvt.w.s    $f0, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCBD8 004BCBD8 00000444 */  mfc1       $4, $f0
    /* 3BCBDC 004BCBDC 00000000 */  nop
    /* 3BCBE0 004BCBE0 FF008430 */  andi       $4, $4, 0xFF
    /* 3BCBE4 004BCBE4 07000010 */  b          .L004BCC04
    /* 3BCBE8 004BCBE8 00000000 */   nop
  .L004BCBEC:
    /* 3BCBEC 004BCBEC 01100046 */  sub.s      $f0, $f2, $f0
    /* 3BCBF0 004BCBF0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCBF4 004BCBF4 00000444 */  mfc1       $4, $f0
    /* 3BCBF8 004BCBF8 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BCBFC 004BCBFC 25208300 */  or         $4, $4, $3
    /* 3BCC00 004BCC00 FF008430 */  andi       $4, $4, 0xFF
  .L004BCC04:
    /* 3BCC04 004BCC04 0200C4A0 */  sb         $4, 0x2($6)
    /* 3BCC08 004BCC08 0C00A38F */  lw         $3, 0xC($29)
    /* 3BCC0C 004BCC0C 03006390 */  lbu        $3, 0x3($3)
    /* 3BCC10 004BCC10 06006004 */  bltz       $3, .L004BCC2C
    /* 3BCC14 004BCC14 00000000 */   nop
    /* 3BCC18 004BCC18 00008344 */  mtc1       $3, $f0
    /* 3BCC1C 004BCC1C 00000000 */  nop
    /* 3BCC20 004BCC20 A0008046 */  cvt.s.w    $f2, $f0
    /* 3BCC24 004BCC24 08000010 */  b          .L004BCC48
    /* 3BCC28 004BCC28 00000000 */   nop
  .L004BCC2C:
    /* 3BCC2C 004BCC2C 42200300 */  srl        $4, $3, 1
    /* 3BCC30 004BCC30 01006330 */  andi       $3, $3, 0x1
    /* 3BCC34 004BCC34 25208300 */  or         $4, $4, $3
    /* 3BCC38 004BCC38 00008444 */  mtc1       $4, $f0
    /* 3BCC3C 004BCC3C 00000000 */  nop
    /* 3BCC40 004BCC40 A0008046 */  cvt.s.w    $f2, $f0
    /* 3BCC44 004BCC44 80100246 */  add.s      $f2, $f2, $f2
  .L004BCC48:
    /* 3BCC48 004BCC48 0800A38F */  lw         $3, 0x8($29)
    /* 3BCC4C 004BCC4C 03006390 */  lbu        $3, 0x3($3)
    /* 3BCC50 004BCC50 06006004 */  bltz       $3, .L004BCC6C
    /* 3BCC54 004BCC54 00000000 */   nop
    /* 3BCC58 004BCC58 00008344 */  mtc1       $3, $f0
    /* 3BCC5C 004BCC5C 00000000 */  nop
    /* 3BCC60 004BCC60 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCC64 004BCC64 08000010 */  b          .L004BCC88
    /* 3BCC68 004BCC68 00000000 */   nop
  .L004BCC6C:
    /* 3BCC6C 004BCC6C 42200300 */  srl        $4, $3, 1
    /* 3BCC70 004BCC70 01006330 */  andi       $3, $3, 0x1
    /* 3BCC74 004BCC74 25208300 */  or         $4, $4, $3
    /* 3BCC78 004BCC78 00008444 */  mtc1       $4, $f0
    /* 3BCC7C 004BCC7C 00000000 */  nop
    /* 3BCC80 004BCC80 20008046 */  cvt.s.w    $f0, $f0
    /* 3BCC84 004BCC84 00000046 */  add.s      $f0, $f0, $f0
  .L004BCC88:
    /* 3BCC88 004BCC88 1A080046 */  mula.s     $f1, $f0
    /* 3BCC8C 004BCC8C 5C600246 */  madd.s     $f1, $f12, $f2
    /* 3BCC90 004BCC90 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3BCC94 004BCC94 00008344 */  mtc1       $3, $f0
    /* 3BCC98 004BCC98 00000000 */  nop
    /* 3BCC9C 004BCC9C 36000146 */  c.le.s     $f0, $f1
    /* 3BCCA0 004BCCA0 07000145 */  bc1t       .L004BCCC0
    /* 3BCCA4 004BCCA4 00000000 */   nop
    /* 3BCCA8 004BCCA8 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCCAC 004BCCAC 00000444 */  mfc1       $4, $f0
    /* 3BCCB0 004BCCB0 00000000 */  nop
    /* 3BCCB4 004BCCB4 FF008430 */  andi       $4, $4, 0xFF
    /* 3BCCB8 004BCCB8 07000010 */  b          .L004BCCD8
    /* 3BCCBC 004BCCBC 00000000 */   nop
  .L004BCCC0:
    /* 3BCCC0 004BCCC0 01080046 */  sub.s      $f0, $f1, $f0
    /* 3BCCC4 004BCCC4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BCCC8 004BCCC8 00000444 */  mfc1       $4, $f0
    /* 3BCCCC 004BCCCC 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3BCCD0 004BCCD0 25208300 */  or         $4, $4, $3
    /* 3BCCD4 004BCCD4 FF008430 */  andi       $4, $4, 0xFF
  .L004BCCD8:
    /* 3BCCD8 004BCCD8 0300C4A0 */  sb         $4, 0x3($6)
  .L004BCCDC:
    /* 3BCCDC 004BCCDC 1000BD27 */  addiu      $29, $29, 0x10
    /* 3BCCE0 004BCCE0 0800E003 */  jr         $31
    /* 3BCCE4 004BCCE4 00000000 */   nop
    /* 3BCCE8 004BCCE8 00000000 */  nop
    /* 3BCCEC 004BCCEC 00000000 */  nop
.size func_004bc540, 0x7b0
