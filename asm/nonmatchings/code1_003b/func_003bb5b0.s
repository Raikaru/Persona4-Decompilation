.section .text
.set noat
.set noreorder
glabel func_003bb5b0
    /* 2BB5B0 003BB5B0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2BB5B4 003BB5B4 38008324 */  addiu      $3, $4, 0x38
    /* 2BB5B8 003BB5B8 2000BFFF */  sd         $31, 0x20($29)
    /* 2BB5BC 003BB5BC 00008044 */  mtc1       $0, $f0
    /* 2BB5C0 003BB5C0 1000B17F */  sq         $17, 0x10($29)
    /* 2BB5C4 003BB5C4 0000B07F */  sq         $16, 0x0($29)
    /* 2BB5C8 003BB5C8 34600046 */  c.lt.s     $f12, $f0
    /* 2BB5CC 003BB5CC 2D80E000 */  daddu      $16, $7, $0
    /* 2BB5D0 003BB5D0 0800878C */  lw         $7, 0x8($4)
    /* 2BB5D4 003BB5D4 03000145 */  bc1t       .L003BB5E4
    /* 2BB5D8 003BB5D8 2D88C000 */   daddu     $17, $6, $0
    /* 2BB5DC 003BB5DC 03000010 */  b          .L003BB5EC
    /* 2BB5E0 003BB5E0 0C00848C */   lw        $4, 0xC($4)
  .L003BB5E4:
    /* 2BB5E4 003BB5E4 07630046 */  neg.s      $f12, $f12
    /* 2BB5E8 003BB5E8 0C00848C */  lw         $4, 0xC($4)
  .L003BB5EC:
    /* 2BB5EC 003BB5EC 02000224 */  addiu      $2, $0, 0x2
    /* 2BB5F0 003BB5F0 24008214 */  bne        $4, $2, .L003BB684
    /* 2BB5F4 003BB5F4 00000000 */   nop
    /* 2BB5F8 003BB5F8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2BB5FC 003BB5FC 00008244 */  mtc1       $2, $f0
    /* 2BB600 003BB600 00000000 */  nop
    /* 2BB604 003BB604 36600046 */  c.le.s     $f12, $f0
    /* 2BB608 003BB608 1E000145 */  bc1t       .L003BB684
    /* 2BB60C 003BB60C 00000000 */   nop
    /* 2BB610 003BB610 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 2BB614 003BB614 00008244 */  mtc1       $2, $f0
    /* 2BB618 003BB618 00000000 */  nop
    /* 2BB61C 003BB61C 36000C46 */  c.le.s     $f0, $f12
    /* 2BB620 003BB620 05000145 */  bc1t       .L003BB638
    /* 2BB624 003BB624 00000000 */   nop
    /* 2BB628 003BB628 24600046 */  .word      0x46006024                    # cvt.w.s    $f0, $f12 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2BB62C 003BB62C 00000644 */  mfc1       $6, $f0
    /* 2BB630 003BB630 07000010 */  b          .L003BB650
    /* 2BB634 003BB634 00000000 */   nop
  .L003BB638:
    /* 2BB638 003BB638 01600046 */  sub.s      $f0, $f12, $f0
    /* 2BB63C 003BB63C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 2BB640 003BB640 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2BB644 003BB644 00000644 */  mfc1       $6, $f0
    /* 2BB648 003BB648 00000000 */  nop
    /* 2BB64C 003BB64C 2530C200 */  or         $6, $6, $2
  .L003BB650:
    /* 2BB650 003BB650 0400C004 */  bltz       $6, .L003BB664
    /* 2BB654 003BB654 00000000 */   nop
    /* 2BB658 003BB658 00008644 */  mtc1       $6, $f0
    /* 2BB65C 003BB65C 08000010 */  b          .L003BB680
    /* 2BB660 003BB660 20008046 */   cvt.s.w   $f0, $f0
  .L003BB664:
    /* 2BB664 003BB664 42200600 */  srl        $4, $6, 1
    /* 2BB668 003BB668 0100C230 */  andi       $2, $6, 0x1
    /* 2BB66C 003BB66C 25208200 */  or         $4, $4, $2
    /* 2BB670 003BB670 00008444 */  mtc1       $4, $f0
    /* 2BB674 003BB674 00000000 */  nop
    /* 2BB678 003BB678 20008046 */  cvt.s.w    $f0, $f0
    /* 2BB67C 003BB67C 00000046 */  add.s      $f0, $f0, $f0
  .L003BB680:
    /* 2BB680 003BB680 01630046 */  sub.s      $f12, $f12, $f0
  .L003BB684:
    /* 2BB684 003BB684 0B000224 */  addiu      $2, $0, 0xB
    /* 2BB688 003BB688 0600A210 */  beq        $5, $2, .L003BB6A4
    /* 2BB68C 003BB68C 00000000 */   nop
    /* 2BB690 003BB690 0A000224 */  addiu      $2, $0, 0xA
    /* 2BB694 003BB694 1800A210 */  beq        $5, $2, .L003BB6F8
    /* 2BB698 003BB698 00000000 */   nop
    /* 2BB69C 003BB69C 2D000010 */  b          .L003BB754
    /* 2BB6A0 003BB6A0 02010224 */   addiu     $2, $0, 0x102
  .L003BB6A4:
    /* 2BB6A4 003BB6A4 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2BB6A8 003BB6A8 00008244 */  mtc1       $2, $f0
    /* 2BB6AC 003BB6AC 00000000 */  nop
    /* 2BB6B0 003BB6B0 36600046 */  c.le.s     $f12, $f0
    /* 2BB6B4 003BB6B4 04000045 */  bc1f       .L003BB6C8
    /* 2BB6B8 003BB6B8 00000000 */   nop
    /* 2BB6BC 003BB6BC 00600C46 */  add.s      $f0, $f12, $f12
    /* 2BB6C0 003BB6C0 0D000010 */  b          .L003BB6F8
    /* 2BB6C4 003BB6C4 02630046 */   mul.s     $f12, $f12, $f0
  .L003BB6C8:
    /* 2BB6C8 003BB6C8 00C0043C */  lui        $4, (0xC0000000 >> 16)
    /* 2BB6CC 003BB6CC 8040023C */  lui        $2, (0x40800000 >> 16)
    /* 2BB6D0 003BB6D0 00008444 */  mtc1       $4, $f0
    /* 2BB6D4 003BB6D4 00188244 */  mtc1       $2, $f3
    /* 2BB6D8 003BB6D8 82000C46 */  mul.s      $f2, $f0, $f12
    /* 2BB6DC 003BB6DC 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* 2BB6E0 003BB6E0 00088244 */  mtc1       $2, $f1
    /* 2BB6E4 003BB6E4 00008044 */  mtc1       $0, $f0
    /* 2BB6E8 003BB6E8 00000000 */  nop
    /* 2BB6EC 003BB6EC 18000146 */  adda.s     $f0, $f1
    /* 2BB6F0 003BB6F0 1E100C46 */  madda.s    $f2, $f12
    /* 2BB6F4 003BB6F4 1C1B0C46 */  madd.s     $f12, $f3, $f12
  .L003BB6F8:
    /* 2BB6F8 003BB6F8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2BB6FC 003BB6FC 00108244 */  mtc1       $2, $f2
    /* 2BB700 003BB700 00000000 */  nop
    /* 2BB704 003BB704 32100C46 */  c.eq.s     $f2, $f12
    /* 2BB708 003BB708 D6000145 */  bc1t       .L003BBA64
    /* 2BB70C 003BB70C 00000000 */   nop
    /* 2BB710 003BB710 FDFFE424 */  addiu      $4, $7, -0x3
    /* 2BB714 003BB714 8043023C */  lui        $2, (0x43800000 >> 16)
    /* 2BB718 003BB718 00088444 */  mtc1       $4, $f1
    /* 2BB71C 003BB71C 00008244 */  mtc1       $2, $f0
    /* 2BB720 003BB720 00000000 */  nop
    /* 2BB724 003BB724 60088046 */  cvt.s.w    $f1, $f1
    /* 2BB728 003BB728 82080C46 */  mul.s      $f2, $f1, $f12
    /* 2BB72C 003BB72C 64100046 */  .word      0x46001064                    # cvt.w.s    $f1, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2BB730 003BB730 00080544 */  mfc1       $5, $f1
    /* 2BB734 003BB734 60088046 */  cvt.s.w    $f1, $f1
    /* 2BB738 003BB738 41100146 */  sub.s      $f1, $f2, $f1
    /* 2BB73C 003BB73C 42000146 */  mul.s      $f1, $f0, $f1
    /* 2BB740 003BB740 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 2BB744 003BB744 00000244 */  mfc1       $2, $f0
    /* 2BB748 003BB748 20008046 */  cvt.s.w    $f0, $f0
    /* 2BB74C 003BB74C 09000010 */  b          .L003BB774
    /* 2BB750 003BB750 81080046 */   sub.s     $f2, $f1, $f0
  .L003BB754:
    /* 2BB754 003BB754 01000424 */  addiu      $4, $0, 0x1
    /* 2BB758 003BB758 647D0F0C */  jal        func_003df590
    /* 2BB75C 003BB75C 3800A2AF */   sw        $2, 0x38($29)
    /* 2BB760 003BB760 3C00A2AF */  sw         $2, 0x3C($29)
    /* 2BB764 003BB764 347D0F0C */  jal        func_003df4d0
    /* 2BB768 003BB768 3800A427 */   addiu     $4, $29, 0x38
    /* 2BB76C 003BB76C C0000010 */  b          .L003BBA70
    /* 2BB770 003BB770 2D100000 */   daddu     $2, $0, $0
  .L003BB774:
    /* 2BB774 003BB774 28B68A8F */  lw         $10, -0x49D8($28)
    /* 2BB778 003BB778 40200500 */  sll        $4, $5, 1
    /* 2BB77C 003BB77C 21208500 */  addu       $4, $4, $5
    /* 2BB780 003BB780 80100200 */  sll        $2, $2, 2
    /* 2BB784 003BB784 24B6898F */  lw         $9, -0x49DC($28)
    /* 2BB788 003BB788 80200400 */  sll        $4, $4, 2
    /* 2BB78C 003BB78C 21406400 */  addu       $8, $3, $4
    /* 2BB790 003BB790 20B6858F */  lw         $5, -0x49E0($28)
    /* 2BB794 003BB794 1CB6848F */  lw         $4, -0x49E4($28)
    /* 2BB798 003BB798 00088044 */  mtc1       $0, $f1
    /* 2BB79C 003BB79C 0C000725 */  addiu      $7, $8, 0xC
    /* 2BB7A0 003BB7A0 18000625 */  addiu      $6, $8, 0x18
    /* 2BB7A4 003BB7A4 21504201 */  addu       $10, $10, $2
    /* 2BB7A8 003BB7A8 24000325 */  addiu      $3, $8, 0x24
    /* 2BB7AC 003BB7AC 000047C5 */  lwc1       $f7, 0x0($10)
    /* 2BB7B0 003BB7B0 21482201 */  addu       $9, $9, $2
    /* 2BB7B4 003BB7B4 040046C5 */  lwc1       $f6, 0x4($10)
    /* 2BB7B8 003BB7B8 2128A200 */  addu       $5, $5, $2
    /* 2BB7BC 003BB7BC 000025C5 */  lwc1       $f5, 0x0($9)
    /* 2BB7C0 003BB7C0 21208200 */  addu       $4, $4, $2
    /* 2BB7C4 003BB7C4 040024C5 */  lwc1       $f4, 0x4($9)
    /* 2BB7C8 003BB7C8 0000A3C4 */  lwc1       $f3, 0x0($5)
    /* 2BB7CC 003BB7CC 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 2BB7D0 003BB7D0 18080746 */  adda.s     $f1, $f7
    /* 2BB7D4 003BB7D4 81310746 */  sub.s      $f6, $f6, $f7
    /* 2BB7D8 003BB7D8 DC110646 */  madd.s     $f7, $f2, $f6
    /* 2BB7DC 003BB7DC 01210546 */  sub.s      $f4, $f4, $f5
    /* 2BB7E0 003BB7E0 18080546 */  adda.s     $f1, $f5
    /* 2BB7E4 003BB7E4 9C110446 */  madd.s     $f6, $f2, $f4
    /* 2BB7E8 003BB7E8 01000346 */  sub.s      $f0, $f0, $f3
    /* 2BB7EC 003BB7EC 18080346 */  adda.s     $f1, $f3
    /* 2BB7F0 003BB7F0 000003C5 */  lwc1       $f3, 0x0($8)
    /* 2BB7F4 003BB7F4 5C110046 */  madd.s     $f5, $f2, $f0
    /* 2BB7F8 003BB7F8 000084C4 */  lwc1       $f4, 0x0($4)
    /* 2BB7FC 003BB7FC 040080C4 */  lwc1       $f0, 0x4($4)
    /* 2BB800 003BB800 C2180746 */  mul.s      $f3, $f3, $f7
    /* 2BB804 003BB804 000023E6 */  swc1       $f3, 0x0($17)
    /* 2BB808 003BB808 040003C5 */  lwc1       $f3, 0x4($8)
    /* 2BB80C 003BB80C 01000446 */  sub.s      $f0, $f0, $f4
    /* 2BB810 003BB810 18080446 */  adda.s     $f1, $f4
    /* 2BB814 003BB814 C2180746 */  mul.s      $f3, $f3, $f7
    /* 2BB818 003BB818 040023E6 */  swc1       $f3, 0x4($17)
    /* 2BB81C 003BB81C 080003C5 */  lwc1       $f3, 0x8($8)
    /* 2BB820 003BB820 1C100046 */  madd.s     $f0, $f2, $f0
    /* 2BB824 003BB824 C2180746 */  mul.s      $f3, $f3, $f7
    /* 2BB828 003BB828 080023E6 */  swc1       $f3, 0x8($17)
    /* 2BB82C 003BB82C 000023C6 */  lwc1       $f3, 0x0($17)
    /* 2BB830 003BB830 0C0004C5 */  lwc1       $f4, 0xC($8)
    /* 2BB834 003BB834 18080346 */  adda.s     $f1, $f3
    /* 2BB838 003BB838 DC200646 */  madd.s     $f3, $f4, $f6
    /* 2BB83C 003BB83C 000023E6 */  swc1       $f3, 0x0($17)
    /* 2BB840 003BB840 040023C6 */  lwc1       $f3, 0x4($17)
    /* 2BB844 003BB844 100004C5 */  lwc1       $f4, 0x10($8)
    /* 2BB848 003BB848 18080346 */  adda.s     $f1, $f3
    /* 2BB84C 003BB84C DC200646 */  madd.s     $f3, $f4, $f6
    /* 2BB850 003BB850 040023E6 */  swc1       $f3, 0x4($17)
    /* 2BB854 003BB854 080023C6 */  lwc1       $f3, 0x8($17)
    /* 2BB858 003BB858 140004C5 */  lwc1       $f4, 0x14($8)
    /* 2BB85C 003BB85C 18080346 */  adda.s     $f1, $f3
    /* 2BB860 003BB860 DC200646 */  madd.s     $f3, $f4, $f6
    /* 2BB864 003BB864 080023E6 */  swc1       $f3, 0x8($17)
    /* 2BB868 003BB868 000023C6 */  lwc1       $f3, 0x0($17)
    /* 2BB86C 003BB86C 180004C5 */  lwc1       $f4, 0x18($8)
    /* 2BB870 003BB870 18080346 */  adda.s     $f1, $f3
    /* 2BB874 003BB874 DC200546 */  madd.s     $f3, $f4, $f5
    /* 2BB878 003BB878 000023E6 */  swc1       $f3, 0x0($17)
    /* 2BB87C 003BB87C 040023C6 */  lwc1       $f3, 0x4($17)
    /* 2BB880 003BB880 1C0004C5 */  lwc1       $f4, 0x1C($8)
    /* 2BB884 003BB884 18080346 */  adda.s     $f1, $f3
    /* 2BB888 003BB888 DC200546 */  madd.s     $f3, $f4, $f5
    /* 2BB88C 003BB88C 040023E6 */  swc1       $f3, 0x4($17)
    /* 2BB890 003BB890 080023C6 */  lwc1       $f3, 0x8($17)
    /* 2BB894 003BB894 200004C5 */  lwc1       $f4, 0x20($8)
    /* 2BB898 003BB898 18080346 */  adda.s     $f1, $f3
    /* 2BB89C 003BB89C DC200546 */  madd.s     $f3, $f4, $f5
    /* 2BB8A0 003BB8A0 080023E6 */  swc1       $f3, 0x8($17)
    /* 2BB8A4 003BB8A4 000023C6 */  lwc1       $f3, 0x0($17)
    /* 2BB8A8 003BB8A8 240004C5 */  lwc1       $f4, 0x24($8)
    /* 2BB8AC 003BB8AC 18080346 */  adda.s     $f1, $f3
    /* 2BB8B0 003BB8B0 DC200046 */  madd.s     $f3, $f4, $f0
    /* 2BB8B4 003BB8B4 000023E6 */  swc1       $f3, 0x0($17)
    /* 2BB8B8 003BB8B8 040023C6 */  lwc1       $f3, 0x4($17)
    /* 2BB8BC 003BB8BC 280004C5 */  lwc1       $f4, 0x28($8)
    /* 2BB8C0 003BB8C0 18080346 */  adda.s     $f1, $f3
    /* 2BB8C4 003BB8C4 DC200046 */  madd.s     $f3, $f4, $f0
    /* 2BB8C8 003BB8C8 040023E6 */  swc1       $f3, 0x4($17)
    /* 2BB8CC 003BB8CC 080023C6 */  lwc1       $f3, 0x8($17)
    /* 2BB8D0 003BB8D0 2C0004C5 */  lwc1       $f4, 0x2C($8)
    /* 2BB8D4 003BB8D4 18080346 */  adda.s     $f1, $f3
    /* 2BB8D8 003BB8D8 1C200046 */  madd.s     $f0, $f4, $f0
    /* 2BB8DC 003BB8DC 5F000012 */  beqz       $16, .L003BBA5C
    /* 2BB8E0 003BB8E0 080020E6 */   swc1      $f0, 0x8($17)
    /* 2BB8E4 003BB8E4 38B68C8F */  lw         $12, -0x49C8($28)
    /* 2BB8E8 003BB8E8 000000C5 */  lwc1       $f0, 0x0($8)
    /* 2BB8EC 003BB8EC 34B68B8F */  lw         $11, -0x49CC($28)
    /* 2BB8F0 003BB8F0 2D200002 */  daddu      $4, $16, $0
    /* 2BB8F4 003BB8F4 30B68A8F */  lw         $10, -0x49D0($28)
    /* 2BB8F8 003BB8F8 2D280002 */  daddu      $5, $16, $0
    /* 2BB8FC 003BB8FC 2CB6898F */  lw         $9, -0x49D4($28)
    /* 2BB900 003BB900 21608201 */  addu       $12, $12, $2
    /* 2BB904 003BB904 000088C5 */  lwc1       $f8, 0x0($12)
    /* 2BB908 003BB908 21586201 */  addu       $11, $11, $2
    /* 2BB90C 003BB90C 040087C5 */  lwc1       $f7, 0x4($12)
    /* 2BB910 003BB910 21504201 */  addu       $10, $10, $2
    /* 2BB914 003BB914 000066C5 */  lwc1       $f6, 0x0($11)
    /* 2BB918 003BB918 21102201 */  addu       $2, $9, $2
    /* 2BB91C 003BB91C 040065C5 */  lwc1       $f5, 0x4($11)
    /* 2BB920 003BB920 000044C5 */  lwc1       $f4, 0x0($10)
    /* 2BB924 003BB924 040043C5 */  lwc1       $f3, 0x4($10)
    /* 2BB928 003BB928 18080846 */  adda.s     $f1, $f8
    /* 2BB92C 003BB92C C1390846 */  sub.s      $f7, $f7, $f8
    /* 2BB930 003BB930 DC110746 */  madd.s     $f7, $f2, $f7
    /* 2BB934 003BB934 41290646 */  sub.s      $f5, $f5, $f6
    /* 2BB938 003BB938 18080646 */  adda.s     $f1, $f6
    /* 2BB93C 003BB93C 9C110546 */  madd.s     $f6, $f2, $f5
    /* 2BB940 003BB940 C1180446 */  sub.s      $f3, $f3, $f4
    /* 2BB944 003BB944 18080446 */  adda.s     $f1, $f4
    /* 2BB948 003BB948 5C110346 */  madd.s     $f5, $f2, $f3
    /* 2BB94C 003BB94C C2000746 */  mul.s      $f3, $f0, $f7
    /* 2BB950 003BB950 000044C4 */  lwc1       $f4, 0x0($2)
    /* 2BB954 003BB954 040040C4 */  lwc1       $f0, 0x4($2)
    /* 2BB958 003BB958 18080446 */  adda.s     $f1, $f4
    /* 2BB95C 003BB95C 01000446 */  sub.s      $f0, $f0, $f4
    /* 2BB960 003BB960 1C100046 */  madd.s     $f0, $f2, $f0
    /* 2BB964 003BB964 000003E6 */  swc1       $f3, 0x0($16)
    /* 2BB968 003BB968 040002C5 */  lwc1       $f2, 0x4($8)
    /* 2BB96C 003BB96C 82100746 */  mul.s      $f2, $f2, $f7
    /* 2BB970 003BB970 040002E6 */  swc1       $f2, 0x4($16)
    /* 2BB974 003BB974 080002C5 */  lwc1       $f2, 0x8($8)
    /* 2BB978 003BB978 82100746 */  mul.s      $f2, $f2, $f7
    /* 2BB97C 003BB97C 080002E6 */  swc1       $f2, 0x8($16)
    /* 2BB980 003BB980 000002C6 */  lwc1       $f2, 0x0($16)
    /* 2BB984 003BB984 0000E3C4 */  lwc1       $f3, 0x0($7)
    /* 2BB988 003BB988 18080246 */  adda.s     $f1, $f2
    /* 2BB98C 003BB98C 9C180646 */  madd.s     $f2, $f3, $f6
    /* 2BB990 003BB990 000002E6 */  swc1       $f2, 0x0($16)
    /* 2BB994 003BB994 040002C6 */  lwc1       $f2, 0x4($16)
    /* 2BB998 003BB998 0400E3C4 */  lwc1       $f3, 0x4($7)
    /* 2BB99C 003BB99C 18080246 */  adda.s     $f1, $f2
    /* 2BB9A0 003BB9A0 9C180646 */  madd.s     $f2, $f3, $f6
    /* 2BB9A4 003BB9A4 040002E6 */  swc1       $f2, 0x4($16)
    /* 2BB9A8 003BB9A8 080002C6 */  lwc1       $f2, 0x8($16)
    /* 2BB9AC 003BB9AC 0800E3C4 */  lwc1       $f3, 0x8($7)
    /* 2BB9B0 003BB9B0 18080246 */  adda.s     $f1, $f2
    /* 2BB9B4 003BB9B4 9C180646 */  madd.s     $f2, $f3, $f6
    /* 2BB9B8 003BB9B8 080002E6 */  swc1       $f2, 0x8($16)
    /* 2BB9BC 003BB9BC 000002C6 */  lwc1       $f2, 0x0($16)
    /* 2BB9C0 003BB9C0 0000C3C4 */  lwc1       $f3, 0x0($6)
    /* 2BB9C4 003BB9C4 18080246 */  adda.s     $f1, $f2
    /* 2BB9C8 003BB9C8 9C180546 */  madd.s     $f2, $f3, $f5
    /* 2BB9CC 003BB9CC 000002E6 */  swc1       $f2, 0x0($16)
    /* 2BB9D0 003BB9D0 040002C6 */  lwc1       $f2, 0x4($16)
    /* 2BB9D4 003BB9D4 0400C3C4 */  lwc1       $f3, 0x4($6)
    /* 2BB9D8 003BB9D8 18080246 */  adda.s     $f1, $f2
    /* 2BB9DC 003BB9DC 9C180546 */  madd.s     $f2, $f3, $f5
    /* 2BB9E0 003BB9E0 040002E6 */  swc1       $f2, 0x4($16)
    /* 2BB9E4 003BB9E4 080002C6 */  lwc1       $f2, 0x8($16)
    /* 2BB9E8 003BB9E8 0800C3C4 */  lwc1       $f3, 0x8($6)
    /* 2BB9EC 003BB9EC 18080246 */  adda.s     $f1, $f2
    /* 2BB9F0 003BB9F0 9C180546 */  madd.s     $f2, $f3, $f5
    /* 2BB9F4 003BB9F4 080002E6 */  swc1       $f2, 0x8($16)
    /* 2BB9F8 003BB9F8 000002C6 */  lwc1       $f2, 0x0($16)
    /* 2BB9FC 003BB9FC 000063C4 */  lwc1       $f3, 0x0($3)
    /* 2BBA00 003BBA00 18080246 */  adda.s     $f1, $f2
    /* 2BBA04 003BBA04 9C180046 */  madd.s     $f2, $f3, $f0
    /* 2BBA08 003BBA08 000002E6 */  swc1       $f2, 0x0($16)
    /* 2BBA0C 003BBA0C 040002C6 */  lwc1       $f2, 0x4($16)
    /* 2BBA10 003BBA10 040063C4 */  lwc1       $f3, 0x4($3)
    /* 2BBA14 003BBA14 18080246 */  adda.s     $f1, $f2
    /* 2BBA18 003BBA18 9C180046 */  madd.s     $f2, $f3, $f0
    /* 2BBA1C 003BBA1C 040002E6 */  swc1       $f2, 0x4($16)
    /* 2BBA20 003BBA20 080002C6 */  lwc1       $f2, 0x8($16)
    /* 2BBA24 003BBA24 080063C4 */  lwc1       $f3, 0x8($3)
    /* 2BBA28 003BBA28 18080246 */  adda.s     $f1, $f2
    /* 2BBA2C 003BBA2C 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2BBA30 003BBA30 0C900F0C */  jal        func_003e4030
    /* 2BBA34 003BBA34 080000E6 */   swc1      $f0, 0x8($16)
    /* 2BBA38 003BBA38 00088044 */  mtc1       $0, $f1
    /* 2BBA3C 003BBA3C 00000000 */  nop
    /* 2BBA40 003BBA40 32080046 */  c.eq.s     $f1, $f0
    /* 2BBA44 003BBA44 05000045 */  bc1f       .L003BBA5C
    /* 2BBA48 003BBA48 00000000 */   nop
    /* 2BBA4C 003BBA4C 000001E6 */  swc1       $f1, 0x0($16)
    /* 2BBA50 003BBA50 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2BBA54 003BBA54 040002AE */  sw         $2, 0x4($16)
    /* 2BBA58 003BBA58 080001E6 */  swc1       $f1, 0x8($16)
  .L003BBA5C:
    /* 2BBA5C 003BBA5C 04000010 */  b          .L003BBA70
    /* 2BBA60 003BBA60 2D102002 */   daddu     $2, $17, $0
  .L003BBA64:
    /* 2BBA64 003BBA64 FCFFE524 */  addiu      $5, $7, -0x4
    /* 2BBA68 003BBA68 42FF0010 */  b          .L003BB774
    /* 2BBA6C 003BBA6C FF000224 */   addiu     $2, $0, 0xFF
  .L003BBA70:
    /* 2BBA70 003BBA70 2000BFDF */  ld         $31, 0x20($29)
    /* 2BBA74 003BBA74 1000B17B */  lq         $17, 0x10($29)
    /* 2BBA78 003BBA78 0000B07B */  lq         $16, 0x0($29)
    /* 2BBA7C 003BBA7C 0800E003 */  jr         $31
    /* 2BBA80 003BBA80 4000BD27 */   addiu     $29, $29, 0x40
    /* 2BBA84 003BBA84 00000000 */  nop
    /* 2BBA88 003BBA88 00000000 */  nop
    /* 2BBA8C 003BBA8C 00000000 */  nop
.size func_003bb5b0, 0x4e0
