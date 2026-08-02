.section .text
.set noat
.set noreorder
glabel func_001fd790
    /* FD790 001FD790 E0FFBD27 */  addiu      $29, $29, -0x20
    /* FD794 001FD794 0000BFFF */  sd         $31, 0x0($29)
    /* FD798 001FD798 38008E8C */  lw         $14, 0x38($4)
    /* FD79C 001FD79C 28008D8C */  lw         $13, 0x28($4)
    /* FD7A0 001FD7A0 0000CC8D */  lw         $12, 0x0($14)
    /* FD7A4 001FD7A4 2B088D01 */  sltu       $1, $12, $13
    /* FD7A8 001FD7A8 03002010 */  beqz       $1, .L001FD7B8
    /* FD7AC 001FD7AC 00000000 */   nop
    /* FD7B0 001FD7B0 12028015 */  bnez       $12, .L001FDFFC
    /* FD7B4 001FD7B4 00000000 */   nop
  .L001FD7B8:
    /* FD7B8 001FD7B8 2D200000 */  daddu      $4, $0, $0
    /* FD7BC 001FD7BC 5E008011 */  beqz       $12, .L001FD938
    /* FD7C0 001FD7C0 00000000 */   nop
    /* FD7C4 001FD7C4 0400C595 */  lhu        $5, 0x4($14)
    /* FD7C8 001FD7C8 2B08AD00 */  sltu       $1, $5, $13
    /* FD7CC 001FD7CC 2C002014 */  bnez       $1, .L001FD880
    /* FD7D0 001FD7D0 00000000 */   nop
    /* FD7D4 001FD7D4 2500A018 */  blez       $5, .L001FD86C
    /* FD7D8 001FD7D8 00000000 */   nop
    /* FD7DC 001FD7DC 0600A005 */  bltz       $13, .L001FD7F8
    /* FD7E0 001FD7E0 00000000 */   nop
    /* FD7E4 001FD7E4 00008D44 */  mtc1       $13, $f0
    /* FD7E8 001FD7E8 00000000 */  nop
    /* FD7EC 001FD7EC 60008046 */  cvt.s.w    $f1, $f0
    /* FD7F0 001FD7F0 08000010 */  b          .L001FD814
    /* FD7F4 001FD7F4 00000000 */   nop
  .L001FD7F8:
    /* FD7F8 001FD7F8 42200D00 */  srl        $4, $13, 1
    /* FD7FC 001FD7FC 0100A331 */  andi       $3, $13, 0x1
    /* FD800 001FD800 25208300 */  or         $4, $4, $3
    /* FD804 001FD804 00008444 */  mtc1       $4, $f0
    /* FD808 001FD808 00000000 */  nop
    /* FD80C 001FD80C 60008046 */  cvt.s.w    $f1, $f0
    /* FD810 001FD810 40080146 */  add.s      $f1, $f1, $f1
  .L001FD814:
    /* FD814 001FD814 0600A004 */  bltz       $5, .L001FD830
    /* FD818 001FD818 00000000 */   nop
    /* FD81C 001FD81C 00008544 */  mtc1       $5, $f0
    /* FD820 001FD820 00000000 */  nop
    /* FD824 001FD824 20008046 */  cvt.s.w    $f0, $f0
    /* FD828 001FD828 08000010 */  b          .L001FD84C
    /* FD82C 001FD82C 00000000 */   nop
  .L001FD830:
    /* FD830 001FD830 42200500 */  srl        $4, $5, 1
    /* FD834 001FD834 0100A330 */  andi       $3, $5, 0x1
    /* FD838 001FD838 25208300 */  or         $4, $4, $3
    /* FD83C 001FD83C 00008444 */  mtc1       $4, $f0
    /* FD840 001FD840 00000000 */  nop
    /* FD844 001FD844 20008046 */  cvt.s.w    $f0, $f0
    /* FD848 001FD848 00000046 */  add.s      $f0, $f0, $f0
  .L001FD84C:
    /* FD84C 001FD84C 00000000 */  nop
    /* FD850 001FD850 00000000 */  nop
    /* FD854 001FD854 43090046 */  div.s      $f5, $f1, $f0
    /* FD858 001FD858 00000000 */  nop
    /* FD85C 001FD85C 00000000 */  nop
    /* FD860 001FD860 00000000 */  nop
    /* FD864 001FD864 03000010 */  b          .L001FD874
    /* FD868 001FD868 00000000 */   nop
  .L001FD86C:
    /* FD86C 001FD86C 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FD870 001FD870 00288344 */  mtc1       $3, $f5
  .L001FD874:
    /* FD874 001FD874 01000464 */  daddiu     $4, $0, 0x1
    /* FD878 001FD878 2F000010 */  b          .L001FD938
    /* FD87C 001FD87C 00000000 */   nop
  .L001FD880:
    /* FD880 001FD880 0600C595 */  lhu        $5, 0x6($14)
    /* FD884 001FD884 23188501 */  subu       $3, $12, $5
    /* FD888 001FD888 2B18A301 */  sltu       $3, $13, $3
    /* FD88C 001FD88C 2A006014 */  bnez       $3, .L001FD938
    /* FD890 001FD890 00000000 */   nop
    /* FD894 001FD894 2600A018 */  blez       $5, .L001FD930
    /* FD898 001FD898 00000000 */   nop
    /* FD89C 001FD89C 23188D01 */  subu       $3, $12, $13
    /* FD8A0 001FD8A0 06006004 */  bltz       $3, .L001FD8BC
    /* FD8A4 001FD8A4 00000000 */   nop
    /* FD8A8 001FD8A8 00008344 */  mtc1       $3, $f0
    /* FD8AC 001FD8AC 00000000 */  nop
    /* FD8B0 001FD8B0 60008046 */  cvt.s.w    $f1, $f0
    /* FD8B4 001FD8B4 08000010 */  b          .L001FD8D8
    /* FD8B8 001FD8B8 00000000 */   nop
  .L001FD8BC:
    /* FD8BC 001FD8BC 42200300 */  srl        $4, $3, 1
    /* FD8C0 001FD8C0 01006330 */  andi       $3, $3, 0x1
    /* FD8C4 001FD8C4 25208300 */  or         $4, $4, $3
    /* FD8C8 001FD8C8 00008444 */  mtc1       $4, $f0
    /* FD8CC 001FD8CC 00000000 */  nop
    /* FD8D0 001FD8D0 60008046 */  cvt.s.w    $f1, $f0
    /* FD8D4 001FD8D4 40080146 */  add.s      $f1, $f1, $f1
  .L001FD8D8:
    /* FD8D8 001FD8D8 0600A004 */  bltz       $5, .L001FD8F4
    /* FD8DC 001FD8DC 00000000 */   nop
    /* FD8E0 001FD8E0 00008544 */  mtc1       $5, $f0
    /* FD8E4 001FD8E4 00000000 */  nop
    /* FD8E8 001FD8E8 20008046 */  cvt.s.w    $f0, $f0
    /* FD8EC 001FD8EC 08000010 */  b          .L001FD910
    /* FD8F0 001FD8F0 00000000 */   nop
  .L001FD8F4:
    /* FD8F4 001FD8F4 42200500 */  srl        $4, $5, 1
    /* FD8F8 001FD8F8 0100A330 */  andi       $3, $5, 0x1
    /* FD8FC 001FD8FC 25208300 */  or         $4, $4, $3
    /* FD900 001FD900 00008444 */  mtc1       $4, $f0
    /* FD904 001FD904 00000000 */  nop
    /* FD908 001FD908 20008046 */  cvt.s.w    $f0, $f0
    /* FD90C 001FD90C 00000046 */  add.s      $f0, $f0, $f0
  .L001FD910:
    /* FD910 001FD910 00000000 */  nop
    /* FD914 001FD914 00000000 */  nop
    /* FD918 001FD918 43090046 */  div.s      $f5, $f1, $f0
    /* FD91C 001FD91C 00000000 */  nop
    /* FD920 001FD920 00000000 */  nop
    /* FD924 001FD924 00000000 */  nop
    /* FD928 001FD928 02000010 */  b          .L001FD934
    /* FD92C 001FD92C 00000000 */   nop
  .L001FD930:
    /* FD930 001FD930 00288044 */  mtc1       $0, $f5
  .L001FD934:
    /* FD934 001FD934 02000464 */  daddiu     $4, $0, 0x2
  .L001FD938:
    /* FD938 001FD938 2D780000 */  daddu      $15, $0, $0
    /* FD93C 001FD93C FF008B30 */  andi       $11, $4, 0xFF
    /* FD940 001FD940 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FD944 001FD944 00008344 */  mtc1       $3, $f0
    /* FD948 001FD948 00000000 */  nop
    /* FD94C 001FD94C 81000546 */  sub.s      $f2, $f0, $f5
    /* FD950 001FD950 A7010010 */  b          .L001FDFF0
    /* FD954 001FD954 00000000 */   nop
  .L001FD958:
    /* FD958 001FD958 C0200F00 */  sll        $4, $15, 3
    /* FD95C 001FD95C ACB3838F */  lw         $3, -0x4C54($28)
    /* FD960 001FD960 21186400 */  addu       $3, $3, $4
    /* FD964 001FD964 7801648C */  lw         $4, 0x178($3)
    /* FD968 001FD968 9E010010 */  b          .L001FDFE4
    /* FD96C 001FD96C 00000000 */   nop
  .L001FD970:
    /* FD970 001FD970 0C00C525 */  addiu      $5, $14, 0xC
    /* FD974 001FD974 C0F0070C */  jal        func_001fc300
    /* FD978 001FD978 00000000 */   nop
    /* FD97C 001FD97C 98014010 */  beqz       $2, .L001FDFE0
    /* FD980 001FD980 00000000 */   nop
    /* FD984 001FD984 9800838C */  lw         $3, 0x98($4)
    /* FD988 001FD988 04006334 */  ori        $3, $3, 0x4
    /* FD98C 001FD98C 980083AC */  sw         $3, 0x98($4)
    /* FD990 001FD990 02000324 */  addiu      $3, $0, 0x2
    /* FD994 001FD994 D5006311 */  beq        $11, $3, .L001FDCEC
    /* FD998 001FD998 00000000 */   nop
    /* FD99C 001FD99C 01000324 */  addiu      $3, $0, 0x1
    /* FD9A0 001FD9A0 13006311 */  beq        $11, $3, .L001FD9F0
    /* FD9A4 001FD9A4 00000000 */   nop
    /* FD9A8 001FD9A8 03006011 */  beqz       $11, .L001FD9B8
    /* FD9AC 001FD9AC 00000000 */   nop
    /* FD9B0 001FD9B0 8B010010 */  b          .L001FDFE0
    /* FD9B4 001FD9B4 00000000 */   nop
  .L001FD9B8:
    /* FD9B8 001FD9B8 8901A015 */  bnez       $13, .L001FDFE0
    /* FD9BC 001FD9BC 00000000 */   nop
    /* FD9C0 001FD9C0 0800C38D */  lw         $3, 0x8($14)
    /* FD9C4 001FD9C4 1C00A3AF */  sw         $3, 0x1C($29)
    /* FD9C8 001FD9C8 1C00A793 */  lbu        $7, 0x1C($29)
    /* FD9CC 001FD9CC 1D00A693 */  lbu        $6, 0x1D($29)
    /* FD9D0 001FD9D0 1E00A593 */  lbu        $5, 0x1E($29)
    /* FD9D4 001FD9D4 1F00A393 */  lbu        $3, 0x1F($29)
    /* FD9D8 001FD9D8 3C0087A0 */  sb         $7, 0x3C($4)
    /* FD9DC 001FD9DC 3D0086A0 */  sb         $6, 0x3D($4)
    /* FD9E0 001FD9E0 3E0085A0 */  sb         $5, 0x3E($4)
    /* FD9E4 001FD9E4 3F0083A0 */  sb         $3, 0x3F($4)
    /* FD9E8 001FD9E8 7D010010 */  b          .L001FDFE0
    /* FD9EC 001FD9EC 00000000 */   nop
  .L001FD9F0:
    /* FD9F0 001FD9F0 0900A015 */  bnez       $13, .L001FDA18
    /* FD9F4 001FD9F4 00000000 */   nop
    /* FD9F8 001FD9F8 3C008790 */  lbu        $7, 0x3C($4)
    /* FD9FC 001FD9FC 3D008690 */  lbu        $6, 0x3D($4)
    /* FDA00 001FDA00 3E008590 */  lbu        $5, 0x3E($4)
    /* FDA04 001FDA04 3F008390 */  lbu        $3, 0x3F($4)
    /* FDA08 001FDA08 380087A0 */  sb         $7, 0x38($4)
    /* FDA0C 001FDA0C 390086A0 */  sb         $6, 0x39($4)
    /* FDA10 001FDA10 3A0085A0 */  sb         $5, 0x3A($4)
    /* FDA14 001FDA14 3B0083A0 */  sb         $3, 0x3B($4)
  .L001FDA18:
    /* FDA18 001FDA18 0800C38D */  lw         $3, 0x8($14)
    /* FDA1C 001FDA1C 1C00A3AF */  sw         $3, 0x1C($29)
    /* FDA20 001FDA20 1C00A393 */  lbu        $3, 0x1C($29)
    /* FDA24 001FDA24 06006004 */  bltz       $3, .L001FDA40
    /* FDA28 001FDA28 00000000 */   nop
    /* FDA2C 001FDA2C 00008344 */  mtc1       $3, $f0
    /* FDA30 001FDA30 00000000 */  nop
    /* FDA34 001FDA34 60008046 */  cvt.s.w    $f1, $f0
    /* FDA38 001FDA38 08000010 */  b          .L001FDA5C
    /* FDA3C 001FDA3C 00000000 */   nop
  .L001FDA40:
    /* FDA40 001FDA40 42280300 */  srl        $5, $3, 1
    /* FDA44 001FDA44 01006330 */  andi       $3, $3, 0x1
    /* FDA48 001FDA48 2528A300 */  or         $5, $5, $3
    /* FDA4C 001FDA4C 00008544 */  mtc1       $5, $f0
    /* FDA50 001FDA50 00000000 */  nop
    /* FDA54 001FDA54 60008046 */  cvt.s.w    $f1, $f0
    /* FDA58 001FDA58 40080146 */  add.s      $f1, $f1, $f1
  .L001FDA5C:
    /* FDA5C 001FDA5C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FDA60 001FDA60 02010146 */  mul.s      $f4, $f0, $f1
    /* FDA64 001FDA64 1D00A393 */  lbu        $3, 0x1D($29)
    /* FDA68 001FDA68 06006004 */  bltz       $3, .L001FDA84
    /* FDA6C 001FDA6C 00000000 */   nop
    /* FDA70 001FDA70 00008344 */  mtc1       $3, $f0
    /* FDA74 001FDA74 00000000 */  nop
    /* FDA78 001FDA78 60008046 */  cvt.s.w    $f1, $f0
    /* FDA7C 001FDA7C 08000010 */  b          .L001FDAA0
    /* FDA80 001FDA80 00000000 */   nop
  .L001FDA84:
    /* FDA84 001FDA84 42280300 */  srl        $5, $3, 1
    /* FDA88 001FDA88 01006330 */  andi       $3, $3, 0x1
    /* FDA8C 001FDA8C 2528A300 */  or         $5, $5, $3
    /* FDA90 001FDA90 00008544 */  mtc1       $5, $f0
    /* FDA94 001FDA94 00000000 */  nop
    /* FDA98 001FDA98 60008046 */  cvt.s.w    $f1, $f0
    /* FDA9C 001FDA9C 40080146 */  add.s      $f1, $f1, $f1
  .L001FDAA0:
    /* FDAA0 001FDAA0 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FDAA4 001FDAA4 C2000146 */  mul.s      $f3, $f0, $f1
    /* FDAA8 001FDAA8 1E00A393 */  lbu        $3, 0x1E($29)
    /* FDAAC 001FDAAC 06006004 */  bltz       $3, .L001FDAC8
    /* FDAB0 001FDAB0 00000000 */   nop
    /* FDAB4 001FDAB4 00008344 */  mtc1       $3, $f0
    /* FDAB8 001FDAB8 00000000 */  nop
    /* FDABC 001FDABC 60008046 */  cvt.s.w    $f1, $f0
    /* FDAC0 001FDAC0 08000010 */  b          .L001FDAE4
    /* FDAC4 001FDAC4 00000000 */   nop
  .L001FDAC8:
    /* FDAC8 001FDAC8 42280300 */  srl        $5, $3, 1
    /* FDACC 001FDACC 01006330 */  andi       $3, $3, 0x1
    /* FDAD0 001FDAD0 2528A300 */  or         $5, $5, $3
    /* FDAD4 001FDAD4 00008544 */  mtc1       $5, $f0
    /* FDAD8 001FDAD8 00000000 */  nop
    /* FDADC 001FDADC 60008046 */  cvt.s.w    $f1, $f0
    /* FDAE0 001FDAE0 40080146 */  add.s      $f1, $f1, $f1
  .L001FDAE4:
    /* FDAE4 001FDAE4 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FDAE8 001FDAE8 42000146 */  mul.s      $f1, $f0, $f1
    /* FDAEC 001FDAEC 1F00A393 */  lbu        $3, 0x1F($29)
    /* FDAF0 001FDAF0 06006004 */  bltz       $3, .L001FDB0C
    /* FDAF4 001FDAF4 00000000 */   nop
    /* FDAF8 001FDAF8 00008344 */  mtc1       $3, $f0
    /* FDAFC 001FDAFC 00000000 */  nop
    /* FDB00 001FDB00 A0018046 */  cvt.s.w    $f6, $f0
    /* FDB04 001FDB04 08000010 */  b          .L001FDB28
    /* FDB08 001FDB08 00000000 */   nop
  .L001FDB0C:
    /* FDB0C 001FDB0C 42280300 */  srl        $5, $3, 1
    /* FDB10 001FDB10 01006330 */  andi       $3, $3, 0x1
    /* FDB14 001FDB14 2528A300 */  or         $5, $5, $3
    /* FDB18 001FDB18 00008544 */  mtc1       $5, $f0
    /* FDB1C 001FDB1C 00000000 */  nop
    /* FDB20 001FDB20 A0018046 */  cvt.s.w    $f6, $f0
    /* FDB24 001FDB24 80310646 */  add.s      $f6, $f6, $f6
  .L001FDB28:
    /* FDB28 001FDB28 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FDB2C 001FDB2C 02000646 */  mul.s      $f0, $f0, $f6
    /* FDB30 001FDB30 38008390 */  lbu        $3, 0x38($4)
    /* FDB34 001FDB34 06006004 */  bltz       $3, .L001FDB50
    /* FDB38 001FDB38 00000000 */   nop
    /* FDB3C 001FDB3C 00308344 */  mtc1       $3, $f6
    /* FDB40 001FDB40 00000000 */  nop
    /* FDB44 001FDB44 E0318046 */  cvt.s.w    $f7, $f6
    /* FDB48 001FDB48 08000010 */  b          .L001FDB6C
    /* FDB4C 001FDB4C 00000000 */   nop
  .L001FDB50:
    /* FDB50 001FDB50 42280300 */  srl        $5, $3, 1
    /* FDB54 001FDB54 01006330 */  andi       $3, $3, 0x1
    /* FDB58 001FDB58 2528A300 */  or         $5, $5, $3
    /* FDB5C 001FDB5C 00308544 */  mtc1       $5, $f6
    /* FDB60 001FDB60 00000000 */  nop
    /* FDB64 001FDB64 E0318046 */  cvt.s.w    $f7, $f6
    /* FDB68 001FDB68 C0390746 */  add.s      $f7, $f7, $f7
  .L001FDB6C:
    /* FDB6C 001FDB6C AC8186C7 */  lwc1       $f6, -0x7E54($28)
    /* FDB70 001FDB70 02320746 */  mul.s      $f8, $f6, $f7
    /* FDB74 001FDB74 39008390 */  lbu        $3, 0x39($4)
    /* FDB78 001FDB78 06006004 */  bltz       $3, .L001FDB94
    /* FDB7C 001FDB7C 00000000 */   nop
    /* FDB80 001FDB80 00308344 */  mtc1       $3, $f6
    /* FDB84 001FDB84 00000000 */  nop
    /* FDB88 001FDB88 E0318046 */  cvt.s.w    $f7, $f6
    /* FDB8C 001FDB8C 08000010 */  b          .L001FDBB0
    /* FDB90 001FDB90 00000000 */   nop
  .L001FDB94:
    /* FDB94 001FDB94 42280300 */  srl        $5, $3, 1
    /* FDB98 001FDB98 01006330 */  andi       $3, $3, 0x1
    /* FDB9C 001FDB9C 2528A300 */  or         $5, $5, $3
    /* FDBA0 001FDBA0 00308544 */  mtc1       $5, $f6
    /* FDBA4 001FDBA4 00000000 */  nop
    /* FDBA8 001FDBA8 E0318046 */  cvt.s.w    $f7, $f6
    /* FDBAC 001FDBAC C0390746 */  add.s      $f7, $f7, $f7
  .L001FDBB0:
    /* FDBB0 001FDBB0 AC8186C7 */  lwc1       $f6, -0x7E54($28)
    /* FDBB4 001FDBB4 C2320746 */  mul.s      $f11, $f6, $f7
    /* FDBB8 001FDBB8 3A008390 */  lbu        $3, 0x3A($4)
    /* FDBBC 001FDBBC 06006004 */  bltz       $3, .L001FDBD8
    /* FDBC0 001FDBC0 00000000 */   nop
    /* FDBC4 001FDBC4 00308344 */  mtc1       $3, $f6
    /* FDBC8 001FDBC8 00000000 */  nop
    /* FDBCC 001FDBCC E0318046 */  cvt.s.w    $f7, $f6
    /* FDBD0 001FDBD0 08000010 */  b          .L001FDBF4
    /* FDBD4 001FDBD4 00000000 */   nop
  .L001FDBD8:
    /* FDBD8 001FDBD8 42280300 */  srl        $5, $3, 1
    /* FDBDC 001FDBDC 01006330 */  andi       $3, $3, 0x1
    /* FDBE0 001FDBE0 2528A300 */  or         $5, $5, $3
    /* FDBE4 001FDBE4 00308544 */  mtc1       $5, $f6
    /* FDBE8 001FDBE8 00000000 */  nop
    /* FDBEC 001FDBEC E0318046 */  cvt.s.w    $f7, $f6
    /* FDBF0 001FDBF0 C0390746 */  add.s      $f7, $f7, $f7
  .L001FDBF4:
    /* FDBF4 001FDBF4 AC8186C7 */  lwc1       $f6, -0x7E54($28)
    /* FDBF8 001FDBF8 82320746 */  mul.s      $f10, $f6, $f7
    /* FDBFC 001FDBFC 3B008390 */  lbu        $3, 0x3B($4)
    /* FDC00 001FDC00 06006004 */  bltz       $3, .L001FDC1C
    /* FDC04 001FDC04 00000000 */   nop
    /* FDC08 001FDC08 00308344 */  mtc1       $3, $f6
    /* FDC0C 001FDC0C 00000000 */  nop
    /* FDC10 001FDC10 E0318046 */  cvt.s.w    $f7, $f6
    /* FDC14 001FDC14 08000010 */  b          .L001FDC38
    /* FDC18 001FDC18 00000000 */   nop
  .L001FDC1C:
    /* FDC1C 001FDC1C 42280300 */  srl        $5, $3, 1
    /* FDC20 001FDC20 01006330 */  andi       $3, $3, 0x1
    /* FDC24 001FDC24 2528A300 */  or         $5, $5, $3
    /* FDC28 001FDC28 00308544 */  mtc1       $5, $f6
    /* FDC2C 001FDC2C 00000000 */  nop
    /* FDC30 001FDC30 E0318046 */  cvt.s.w    $f7, $f6
    /* FDC34 001FDC34 C0390746 */  add.s      $f7, $f7, $f7
  .L001FDC38:
    /* FDC38 001FDC38 AC8186C7 */  lwc1       $f6, -0x7E54($28)
    /* FDC3C 001FDC3C 42320746 */  mul.s      $f9, $f6, $f7
    /* FDC40 001FDC40 02420246 */  mul.s      $f8, $f8, $f2
    /* FDC44 001FDC44 C2590246 */  mul.s      $f7, $f11, $f2
    /* FDC48 001FDC48 82510246 */  mul.s      $f6, $f10, $f2
    /* FDC4C 001FDC4C 1A480246 */  mula.s     $f9, $f2
    /* FDC50 001FDC50 02210546 */  mul.s      $f4, $f4, $f5
    /* FDC54 001FDC54 C2180546 */  mul.s      $f3, $f3, $f5
    /* FDC58 001FDC58 42080546 */  mul.s      $f1, $f1, $f5
    /* FDC5C 001FDC5C 40420446 */  add.s      $f9, $f8, $f4
    /* FDC60 001FDC60 003A0346 */  add.s      $f8, $f7, $f3
    /* FDC64 001FDC64 C0310146 */  add.s      $f7, $f6, $f1
    /* FDC68 001FDC68 9C010546 */  madd.s     $f6, $f0, $f5
    /* FDC6C 001FDC6C 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* FDC70 001FDC70 00208344 */  mtc1       $3, $f4
    /* FDC74 001FDC74 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* FDC78 001FDC78 00188344 */  mtc1       $3, $f3
    /* FDC7C 001FDC7C 00088044 */  mtc1       $0, $f1
    /* FDC80 001FDC80 00000000 */  nop
    /* FDC84 001FDC84 18080346 */  adda.s     $f1, $f3
    /* FDC88 001FDC88 1C200946 */  madd.s     $f0, $f4, $f9
    /* FDC8C 001FDC8C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDC90 001FDC90 00000344 */  mfc1       $3, $f0
    /* FDC94 001FDC94 00000000 */  nop
    /* FDC98 001FDC98 3C0083A0 */  sb         $3, 0x3C($4)
    /* FDC9C 001FDC9C 18080346 */  adda.s     $f1, $f3
    /* FDCA0 001FDCA0 1C200846 */  madd.s     $f0, $f4, $f8
    /* FDCA4 001FDCA4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDCA8 001FDCA8 00000344 */  mfc1       $3, $f0
    /* FDCAC 001FDCAC 00000000 */  nop
    /* FDCB0 001FDCB0 3D0083A0 */  sb         $3, 0x3D($4)
    /* FDCB4 001FDCB4 18080346 */  adda.s     $f1, $f3
    /* FDCB8 001FDCB8 1C200746 */  madd.s     $f0, $f4, $f7
    /* FDCBC 001FDCBC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDCC0 001FDCC0 00000344 */  mfc1       $3, $f0
    /* FDCC4 001FDCC4 00000000 */  nop
    /* FDCC8 001FDCC8 3E0083A0 */  sb         $3, 0x3E($4)
    /* FDCCC 001FDCCC 18080346 */  adda.s     $f1, $f3
    /* FDCD0 001FDCD0 1C200646 */  madd.s     $f0, $f4, $f6
    /* FDCD4 001FDCD4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDCD8 001FDCD8 00000344 */  mfc1       $3, $f0
    /* FDCDC 001FDCDC 00000000 */  nop
    /* FDCE0 001FDCE0 3F0083A0 */  sb         $3, 0x3F($4)
    /* FDCE4 001FDCE4 BE000010 */  b          .L001FDFE0
    /* FDCE8 001FDCE8 00000000 */   nop
  .L001FDCEC:
    /* FDCEC 001FDCEC 0600C395 */  lhu        $3, 0x6($14)
    /* FDCF0 001FDCF0 23188301 */  subu       $3, $12, $3
    /* FDCF4 001FDCF4 0900A315 */  bne        $13, $3, .L001FDD1C
    /* FDCF8 001FDCF8 00000000 */   nop
    /* FDCFC 001FDCFC 3C008790 */  lbu        $7, 0x3C($4)
    /* FDD00 001FDD00 3D008690 */  lbu        $6, 0x3D($4)
    /* FDD04 001FDD04 3E008590 */  lbu        $5, 0x3E($4)
    /* FDD08 001FDD08 3F008390 */  lbu        $3, 0x3F($4)
    /* FDD0C 001FDD0C 380087A0 */  sb         $7, 0x38($4)
    /* FDD10 001FDD10 390086A0 */  sb         $6, 0x39($4)
    /* FDD14 001FDD14 3A0085A0 */  sb         $5, 0x3A($4)
    /* FDD18 001FDD18 3B0083A0 */  sb         $3, 0x3B($4)
  .L001FDD1C:
    /* FDD1C 001FDD1C 08B18393 */  lbu        $3, -0x4EF8($28)
    /* FDD20 001FDD20 06006004 */  bltz       $3, .L001FDD3C
    /* FDD24 001FDD24 00000000 */   nop
    /* FDD28 001FDD28 00008344 */  mtc1       $3, $f0
    /* FDD2C 001FDD2C 00000000 */  nop
    /* FDD30 001FDD30 60008046 */  cvt.s.w    $f1, $f0
    /* FDD34 001FDD34 08000010 */  b          .L001FDD58
    /* FDD38 001FDD38 00000000 */   nop
  .L001FDD3C:
    /* FDD3C 001FDD3C 42280300 */  srl        $5, $3, 1
    /* FDD40 001FDD40 01006330 */  andi       $3, $3, 0x1
    /* FDD44 001FDD44 2528A300 */  or         $5, $5, $3
    /* FDD48 001FDD48 00008544 */  mtc1       $5, $f0
    /* FDD4C 001FDD4C 00000000 */  nop
    /* FDD50 001FDD50 60008046 */  cvt.s.w    $f1, $f0
    /* FDD54 001FDD54 40080146 */  add.s      $f1, $f1, $f1
  .L001FDD58:
    /* FDD58 001FDD58 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FDD5C 001FDD5C 42000146 */  mul.s      $f1, $f0, $f1
    /* FDD60 001FDD60 09B18393 */  lbu        $3, -0x4EF7($28)
    /* FDD64 001FDD64 06006004 */  bltz       $3, .L001FDD80
    /* FDD68 001FDD68 00000000 */   nop
    /* FDD6C 001FDD6C 00008344 */  mtc1       $3, $f0
    /* FDD70 001FDD70 00000000 */  nop
    /* FDD74 001FDD74 E0008046 */  cvt.s.w    $f3, $f0
    /* FDD78 001FDD78 08000010 */  b          .L001FDD9C
    /* FDD7C 001FDD7C 00000000 */   nop
  .L001FDD80:
    /* FDD80 001FDD80 42280300 */  srl        $5, $3, 1
    /* FDD84 001FDD84 01006330 */  andi       $3, $3, 0x1
    /* FDD88 001FDD88 2528A300 */  or         $5, $5, $3
    /* FDD8C 001FDD8C 00008544 */  mtc1       $5, $f0
    /* FDD90 001FDD90 00000000 */  nop
    /* FDD94 001FDD94 E0008046 */  cvt.s.w    $f3, $f0
    /* FDD98 001FDD98 C0180346 */  add.s      $f3, $f3, $f3
  .L001FDD9C:
    /* FDD9C 001FDD9C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FDDA0 001FDDA0 02000346 */  mul.s      $f0, $f0, $f3
    /* FDDA4 001FDDA4 0AB18393 */  lbu        $3, -0x4EF6($28)
    /* FDDA8 001FDDA8 06006004 */  bltz       $3, .L001FDDC4
    /* FDDAC 001FDDAC 00000000 */   nop
    /* FDDB0 001FDDB0 00188344 */  mtc1       $3, $f3
    /* FDDB4 001FDDB4 00000000 */  nop
    /* FDDB8 001FDDB8 20198046 */  cvt.s.w    $f4, $f3
    /* FDDBC 001FDDBC 08000010 */  b          .L001FDDE0
    /* FDDC0 001FDDC0 00000000 */   nop
  .L001FDDC4:
    /* FDDC4 001FDDC4 42280300 */  srl        $5, $3, 1
    /* FDDC8 001FDDC8 01006330 */  andi       $3, $3, 0x1
    /* FDDCC 001FDDCC 2528A300 */  or         $5, $5, $3
    /* FDDD0 001FDDD0 00188544 */  mtc1       $5, $f3
    /* FDDD4 001FDDD4 00000000 */  nop
    /* FDDD8 001FDDD8 20198046 */  cvt.s.w    $f4, $f3
    /* FDDDC 001FDDDC 00210446 */  add.s      $f4, $f4, $f4
  .L001FDDE0:
    /* FDDE0 001FDDE0 AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FDDE4 001FDDE4 421B0446 */  mul.s      $f13, $f3, $f4
    /* FDDE8 001FDDE8 0BB18393 */  lbu        $3, -0x4EF5($28)
    /* FDDEC 001FDDEC 06006004 */  bltz       $3, .L001FDE08
    /* FDDF0 001FDDF0 00000000 */   nop
    /* FDDF4 001FDDF4 00188344 */  mtc1       $3, $f3
    /* FDDF8 001FDDF8 00000000 */  nop
    /* FDDFC 001FDDFC 20198046 */  cvt.s.w    $f4, $f3
    /* FDE00 001FDE00 08000010 */  b          .L001FDE24
    /* FDE04 001FDE04 00000000 */   nop
  .L001FDE08:
    /* FDE08 001FDE08 42280300 */  srl        $5, $3, 1
    /* FDE0C 001FDE0C 01006330 */  andi       $3, $3, 0x1
    /* FDE10 001FDE10 2528A300 */  or         $5, $5, $3
    /* FDE14 001FDE14 00188544 */  mtc1       $5, $f3
    /* FDE18 001FDE18 00000000 */  nop
    /* FDE1C 001FDE1C 20198046 */  cvt.s.w    $f4, $f3
    /* FDE20 001FDE20 00210446 */  add.s      $f4, $f4, $f4
  .L001FDE24:
    /* FDE24 001FDE24 AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FDE28 001FDE28 021B0446 */  mul.s      $f12, $f3, $f4
    /* FDE2C 001FDE2C 38008390 */  lbu        $3, 0x38($4)
    /* FDE30 001FDE30 06006004 */  bltz       $3, .L001FDE4C
    /* FDE34 001FDE34 00000000 */   nop
    /* FDE38 001FDE38 00188344 */  mtc1       $3, $f3
    /* FDE3C 001FDE3C 00000000 */  nop
    /* FDE40 001FDE40 20198046 */  cvt.s.w    $f4, $f3
    /* FDE44 001FDE44 08000010 */  b          .L001FDE68
    /* FDE48 001FDE48 00000000 */   nop
  .L001FDE4C:
    /* FDE4C 001FDE4C 42280300 */  srl        $5, $3, 1
    /* FDE50 001FDE50 01006330 */  andi       $3, $3, 0x1
    /* FDE54 001FDE54 2528A300 */  or         $5, $5, $3
    /* FDE58 001FDE58 00188544 */  mtc1       $5, $f3
    /* FDE5C 001FDE5C 00000000 */  nop
    /* FDE60 001FDE60 20198046 */  cvt.s.w    $f4, $f3
    /* FDE64 001FDE64 00210446 */  add.s      $f4, $f4, $f4
  .L001FDE68:
    /* FDE68 001FDE68 AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FDE6C 001FDE6C C21A0446 */  mul.s      $f11, $f3, $f4
    /* FDE70 001FDE70 39008390 */  lbu        $3, 0x39($4)
    /* FDE74 001FDE74 06006004 */  bltz       $3, .L001FDE90
    /* FDE78 001FDE78 00000000 */   nop
    /* FDE7C 001FDE7C 00188344 */  mtc1       $3, $f3
    /* FDE80 001FDE80 00000000 */  nop
    /* FDE84 001FDE84 20198046 */  cvt.s.w    $f4, $f3
    /* FDE88 001FDE88 08000010 */  b          .L001FDEAC
    /* FDE8C 001FDE8C 00000000 */   nop
  .L001FDE90:
    /* FDE90 001FDE90 42280300 */  srl        $5, $3, 1
    /* FDE94 001FDE94 01006330 */  andi       $3, $3, 0x1
    /* FDE98 001FDE98 2528A300 */  or         $5, $5, $3
    /* FDE9C 001FDE9C 00188544 */  mtc1       $5, $f3
    /* FDEA0 001FDEA0 00000000 */  nop
    /* FDEA4 001FDEA4 20198046 */  cvt.s.w    $f4, $f3
    /* FDEA8 001FDEA8 00210446 */  add.s      $f4, $f4, $f4
  .L001FDEAC:
    /* FDEAC 001FDEAC AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FDEB0 001FDEB0 821A0446 */  mul.s      $f10, $f3, $f4
    /* FDEB4 001FDEB4 3A008390 */  lbu        $3, 0x3A($4)
    /* FDEB8 001FDEB8 06006004 */  bltz       $3, .L001FDED4
    /* FDEBC 001FDEBC 00000000 */   nop
    /* FDEC0 001FDEC0 00188344 */  mtc1       $3, $f3
    /* FDEC4 001FDEC4 00000000 */  nop
    /* FDEC8 001FDEC8 20198046 */  cvt.s.w    $f4, $f3
    /* FDECC 001FDECC 08000010 */  b          .L001FDEF0
    /* FDED0 001FDED0 00000000 */   nop
  .L001FDED4:
    /* FDED4 001FDED4 42280300 */  srl        $5, $3, 1
    /* FDED8 001FDED8 01006330 */  andi       $3, $3, 0x1
    /* FDEDC 001FDEDC 2528A300 */  or         $5, $5, $3
    /* FDEE0 001FDEE0 00188544 */  mtc1       $5, $f3
    /* FDEE4 001FDEE4 00000000 */  nop
    /* FDEE8 001FDEE8 20198046 */  cvt.s.w    $f4, $f3
    /* FDEEC 001FDEEC 00210446 */  add.s      $f4, $f4, $f4
  .L001FDEF0:
    /* FDEF0 001FDEF0 AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FDEF4 001FDEF4 021A0446 */  mul.s      $f8, $f3, $f4
    /* FDEF8 001FDEF8 3B008390 */  lbu        $3, 0x3B($4)
    /* FDEFC 001FDEFC 06006004 */  bltz       $3, .L001FDF18
    /* FDF00 001FDF00 00000000 */   nop
    /* FDF04 001FDF04 00188344 */  mtc1       $3, $f3
    /* FDF08 001FDF08 00000000 */  nop
    /* FDF0C 001FDF0C 20198046 */  cvt.s.w    $f4, $f3
    /* FDF10 001FDF10 08000010 */  b          .L001FDF34
    /* FDF14 001FDF14 00000000 */   nop
  .L001FDF18:
    /* FDF18 001FDF18 42280300 */  srl        $5, $3, 1
    /* FDF1C 001FDF1C 01006330 */  andi       $3, $3, 0x1
    /* FDF20 001FDF20 2528A300 */  or         $5, $5, $3
    /* FDF24 001FDF24 00188544 */  mtc1       $5, $f3
    /* FDF28 001FDF28 00000000 */  nop
    /* FDF2C 001FDF2C 20198046 */  cvt.s.w    $f4, $f3
    /* FDF30 001FDF30 00210446 */  add.s      $f4, $f4, $f4
  .L001FDF34:
    /* FDF34 001FDF34 AC8183C7 */  lwc1       $f3, -0x7E54($28)
    /* FDF38 001FDF38 421A0446 */  mul.s      $f9, $f3, $f4
    /* FDF3C 001FDF3C C2090246 */  mul.s      $f7, $f1, $f2
    /* FDF40 001FDF40 82010246 */  mul.s      $f6, $f0, $f2
    /* FDF44 001FDF44 02690246 */  mul.s      $f4, $f13, $f2
    /* FDF48 001FDF48 1A600246 */  mula.s     $f12, $f2
    /* FDF4C 001FDF4C 02580546 */  mul.s      $f0, $f11, $f5
    /* FDF50 001FDF50 C2500546 */  mul.s      $f3, $f10, $f5
    /* FDF54 001FDF54 42400546 */  mul.s      $f1, $f8, $f5
    /* FDF58 001FDF58 00380046 */  add.s      $f0, $f7, $f0
    /* FDF5C 001FDF5C 00320346 */  add.s      $f8, $f6, $f3
    /* FDF60 001FDF60 C0210146 */  add.s      $f7, $f4, $f1
    /* FDF64 001FDF64 9C490546 */  madd.s     $f6, $f9, $f5
    /* FDF68 001FDF68 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* FDF6C 001FDF6C 00208344 */  mtc1       $3, $f4
    /* FDF70 001FDF70 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* FDF74 001FDF74 00188344 */  mtc1       $3, $f3
    /* FDF78 001FDF78 00088044 */  mtc1       $0, $f1
    /* FDF7C 001FDF7C 00000000 */  nop
    /* FDF80 001FDF80 18080346 */  adda.s     $f1, $f3
    /* FDF84 001FDF84 1C200046 */  madd.s     $f0, $f4, $f0
    /* FDF88 001FDF88 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDF8C 001FDF8C 00000344 */  mfc1       $3, $f0
    /* FDF90 001FDF90 00000000 */  nop
    /* FDF94 001FDF94 3C0083A0 */  sb         $3, 0x3C($4)
    /* FDF98 001FDF98 18080346 */  adda.s     $f1, $f3
    /* FDF9C 001FDF9C 1C200846 */  madd.s     $f0, $f4, $f8
    /* FDFA0 001FDFA0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDFA4 001FDFA4 00000344 */  mfc1       $3, $f0
    /* FDFA8 001FDFA8 00000000 */  nop
    /* FDFAC 001FDFAC 3D0083A0 */  sb         $3, 0x3D($4)
    /* FDFB0 001FDFB0 18080346 */  adda.s     $f1, $f3
    /* FDFB4 001FDFB4 1C200746 */  madd.s     $f0, $f4, $f7
    /* FDFB8 001FDFB8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDFBC 001FDFBC 00000344 */  mfc1       $3, $f0
    /* FDFC0 001FDFC0 00000000 */  nop
    /* FDFC4 001FDFC4 3E0083A0 */  sb         $3, 0x3E($4)
    /* FDFC8 001FDFC8 18080346 */  adda.s     $f1, $f3
    /* FDFCC 001FDFCC 1C200646 */  madd.s     $f0, $f4, $f6
    /* FDFD0 001FDFD0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FDFD4 001FDFD4 00000344 */  mfc1       $3, $f0
    /* FDFD8 001FDFD8 00000000 */  nop
    /* FDFDC 001FDFDC 3F0083A0 */  sb         $3, 0x3F($4)
  .L001FDFE0:
    /* FDFE0 001FDFE0 6C0A848C */  lw         $4, 0xA6C($4)
  .L001FDFE4:
    /* FDFE4 001FDFE4 62FE8014 */  bnez       $4, .L001FD970
    /* FDFE8 001FDFE8 00000000 */   nop
    /* FDFEC 001FDFEC 0100EF25 */  addiu      $15, $15, 0x1
  .L001FDFF0:
    /* FDFF0 001FDFF0 0400E32D */  sltiu      $3, $15, 0x4
    /* FDFF4 001FDFF4 58FE6014 */  bnez       $3, .L001FD958
    /* FDFF8 001FDFF8 00000000 */   nop
  .L001FDFFC:
    /* FDFFC 001FDFFC 0000BFDF */  ld         $31, 0x0($29)
    /* FE000 001FE000 2000BD27 */  addiu      $29, $29, 0x20
    /* FE004 001FE004 0800E003 */  jr         $31
    /* FE008 001FE008 00000000 */   nop
    /* FE00C 001FE00C 00000000 */  nop
.size func_001fd790, 0x880
