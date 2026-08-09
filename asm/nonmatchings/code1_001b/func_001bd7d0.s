.section .text
.set noat
.set noreorder
glabel func_001bd7d0
    /* BD7D0 001BD7D0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* BD7D4 001BD7D4 1000BFFF */  sd         $31, 0x10($29)
    /* BD7D8 001BD7D8 0000B07F */  sq         $16, 0x0($29)
    /* BD7DC 001BD7DC ACB3848F */  lw         $4, -0x4C54($28)
    /* BD7E0 001BD7E0 F800838C */  lw         $3, 0xF8($4)
    /* BD7E4 001BD7E4 01006330 */  andi       $3, $3, 0x1
    /* BD7E8 001BD7E8 71006014 */  bnez       $3, .L001BD9B0
    /* BD7EC 001BD7EC 00000000 */   nop
    /* BD7F0 001BD7F0 00018324 */  addiu      $3, $4, 0x100
    /* BD7F4 001BD7F4 0001828C */  lw         $2, 0x100($4)
    /* BD7F8 001BD7F8 1F00401C */  bgtz       $2, .L001BD878
    /* BD7FC 001BD7FC 00000000 */   nop
    /* BD800 001BD800 F4009094 */  lhu        $16, 0xF4($4)
    /* BD804 001BD804 2D200002 */  daddu      $4, $16, $0
    /* BD808 001BD808 6CB3080C */  jal        func_0022cdb0
    /* BD80C 001BD80C 00000000 */   nop
    /* BD810 001BD810 08004014 */  bnez       $2, .L001BD834
    /* BD814 001BD814 00000000 */   nop
    /* BD818 001BD818 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* BD81C 001BD81C 80100300 */  sll        $2, $3, 2
    /* BD820 001BD820 21104300 */  addu       $2, $2, $3
    /* BD824 001BD824 80180200 */  sll        $3, $2, 2
    /* BD828 001BD828 5F00023C */  lui        $2, %hi(D_005F74C0)
    /* BD82C 001BD82C C0744224 */  addiu      $2, $2, %lo(D_005F74C0)
    /* BD830 001BD830 21104300 */  addu       $2, $2, $3
  .L001BD834:
    /* BD834 001BD834 0400438C */  lw         $3, 0x4($2)
    /* BD838 001BD838 05006010 */  beqz       $3, .L001BD850
    /* BD83C 001BD83C 00000000 */   nop
    /* BD840 001BD840 ACB3828F */  lw         $2, -0x4C54($28)
    /* BD844 001BD844 24004424 */  addiu      $4, $2, 0x24
    /* BD848 001BD848 09F86000 */  jalr       $3
    /* BD84C 001BD84C 00000000 */   nop
  .L001BD850:
    /* BD850 001BD850 ACB3828F */  lw         $2, -0x4C54($28)
    /* BD854 001BD854 24004424 */  addiu      $4, $2, 0x24
    /* BD858 001BD858 E4EF060C */  jal        func_001bbf90
    /* BD85C 001BD85C 00000000 */   nop
    /* BD860 001BD860 ACB3838F */  lw         $3, -0x4C54($28)
    /* BD864 001BD864 FC00628C */  lw         $2, 0xFC($3)
    /* BD868 001BD868 01004224 */  addiu      $2, $2, 0x1
    /* BD86C 001BD86C FC0062AC */  sw         $2, 0xFC($3)
    /* BD870 001BD870 03000010 */  b          .L001BD880
    /* BD874 001BD874 00000000 */   nop
  .L001BD878:
    /* BD878 001BD878 FFFF4224 */  addiu      $2, $2, -0x1
    /* BD87C 001BD87C 000062AC */  sw         $2, 0x0($3)
  .L001BD880:
    /* BD880 001BD880 ACB3838F */  lw         $3, -0x4C54($28)
    /* BD884 001BD884 D00064C4 */  lwc1       $f4, 0xD0($3)
    /* BD888 001BD888 CC006CC4 */  lwc1       $f12, 0xCC($3)
    /* BD88C 001BD88C D4006BC4 */  lwc1       $f11, 0xD4($3)
    /* BD890 001BD890 D80063C4 */  lwc1       $f3, 0xD8($3)
    /* BD894 001BD894 1A200446 */  mula.s     $f4, $f4
    /* BD898 001BD898 1E600C46 */  madda.s    $f12, $f12
    /* BD89C 001BD89C 1E580B46 */  madda.s    $f11, $f11
    /* BD8A0 001BD8A0 5C180346 */  madd.s     $f1, $f3, $f3
    /* BD8A4 001BD8A4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* BD8A8 001BD8A8 00008244 */  mtc1       $2, $f0
    /* BD8AC 001BD8AC 00000000 */  nop
    /* BD8B0 001BD8B0 03000146 */  div.s      $f0, $f0, $f1
    /* BD8B4 001BD8B4 82600046 */  mul.s      $f2, $f12, $f0
    /* BD8B8 001BD8B8 42200046 */  mul.s      $f1, $f4, $f0
    /* BD8BC 001BD8BC 02580046 */  mul.s      $f0, $f11, $f0
    /* BD8C0 001BD8C0 82120346 */  mul.s      $f10, $f2, $f3
    /* BD8C4 001BD8C4 420A0346 */  mul.s      $f9, $f1, $f3
    /* BD8C8 001BD8C8 02020346 */  mul.s      $f8, $f0, $f3
    /* BD8CC 001BD8CC C2610246 */  mul.s      $f7, $f12, $f2
    /* BD8D0 001BD8D0 82210146 */  mul.s      $f6, $f4, $f1
    /* BD8D4 001BD8D4 42590046 */  mul.s      $f5, $f11, $f0
    /* BD8D8 001BD8D8 02210046 */  mul.s      $f4, $f4, $f0
    /* BD8DC 001BD8DC C2580246 */  mul.s      $f3, $f11, $f2
    /* BD8E0 001BD8E0 82600146 */  mul.s      $f2, $f12, $f1
    /* BD8E4 001BD8E4 00300546 */  add.s      $f0, $f6, $f5
    /* BD8E8 001BD8E8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BD8EC 001BD8EC 00088244 */  mtc1       $2, $f1
    /* BD8F0 001BD8F0 00000000 */  nop
    /* BD8F4 001BD8F4 01080046 */  sub.s      $f0, $f1, $f0
    /* BD8F8 001BD8F8 2000A0E7 */  swc1       $f0, 0x20($29)
    /* BD8FC 001BD8FC 00100846 */  add.s      $f0, $f2, $f8
    /* BD900 001BD900 2400A0E7 */  swc1       $f0, 0x24($29)
    /* BD904 001BD904 01180946 */  sub.s      $f0, $f3, $f9
    /* BD908 001BD908 2800A0E7 */  swc1       $f0, 0x28($29)
    /* BD90C 001BD90C 01100846 */  sub.s      $f0, $f2, $f8
    /* BD910 001BD910 3000A0E7 */  swc1       $f0, 0x30($29)
    /* BD914 001BD914 00280746 */  add.s      $f0, $f5, $f7
    /* BD918 001BD918 01080046 */  sub.s      $f0, $f1, $f0
    /* BD91C 001BD91C 3400A0E7 */  swc1       $f0, 0x34($29)
    /* BD920 001BD920 00200A46 */  add.s      $f0, $f4, $f10
    /* BD924 001BD924 3800A0E7 */  swc1       $f0, 0x38($29)
    /* BD928 001BD928 00180946 */  add.s      $f0, $f3, $f9
    /* BD92C 001BD92C 4000A0E7 */  swc1       $f0, 0x40($29)
    /* BD930 001BD930 01200A46 */  sub.s      $f0, $f4, $f10
    /* BD934 001BD934 4400A0E7 */  swc1       $f0, 0x44($29)
    /* BD938 001BD938 00380646 */  add.s      $f0, $f7, $f6
    /* BD93C 001BD93C 01080046 */  sub.s      $f0, $f1, $f0
    /* BD940 001BD940 4800A0E7 */  swc1       $f0, 0x48($29)
    /* BD944 001BD944 5000A0AF */  sw         $0, 0x50($29)
    /* BD948 001BD948 5400A0AF */  sw         $0, 0x54($29)
    /* BD94C 001BD94C 5800A0AF */  sw         $0, 0x58($29)
    /* BD950 001BD950 03000224 */  addiu      $2, $0, 0x3
    /* BD954 001BD954 2C00A2AF */  sw         $2, 0x2C($29)
    /* BD958 001BD958 C00062C4 */  lwc1       $f2, 0xC0($3)
    /* BD95C 001BD95C C40061C4 */  lwc1       $f1, 0xC4($3)
    /* BD960 001BD960 C80060C4 */  lwc1       $f0, 0xC8($3)
    /* BD964 001BD964 5000A2E7 */  swc1       $f2, 0x50($29)
    /* BD968 001BD968 5400A1E7 */  swc1       $f1, 0x54($29)
    /* BD96C 001BD96C 5800A0E7 */  swc1       $f0, 0x58($29)
    /* BD970 001BD970 485C110C */  jal        func_00457120
    /* BD974 001BD974 00000000 */   nop
    /* BD978 001BD978 0400448C */  lw         $4, 0x4($2)
    /* BD97C 001BD97C 2000A527 */  addiu      $5, $29, 0x20
    /* BD980 001BD980 2D300000 */  daddu      $6, $0, $0
    /* BD984 001BD984 2CA70F0C */  jal        func_003e9cb0
    /* BD988 001BD988 00000000 */   nop
    /* BD98C 001BD98C 485C110C */  jal        func_00457120
    /* BD990 001BD990 00000000 */   nop
    /* BD994 001BD994 ACB3838F */  lw         $3, -0x4C54($28)
    /* BD998 001BD998 488081C7 */  lwc1       $f1, -0x7FB8($28)
    /* BD99C 001BD99C DC0060C4 */  lwc1       $f0, 0xDC($3)
    /* BD9A0 001BD9A0 020B0046 */  mul.s      $f12, $f1, $f0
    /* BD9A4 001BD9A4 2D204000 */  daddu      $4, $2, $0
    /* BD9A8 001BD9A8 F45D110C */  jal        func_004577d0
    /* BD9AC 001BD9AC 00000000 */   nop
  .L001BD9B0:
    /* BD9B0 001BD9B0 ACB3838F */  lw         $3, -0x4C54($28)
    /* BD9B4 001BD9B4 F800638C */  lw         $3, 0xF8($3)
    /* BD9B8 001BD9B8 02006330 */  andi       $3, $3, 0x2
    /* BD9BC 001BD9BC 03006010 */  beqz       $3, .L001BD9CC
    /* BD9C0 001BD9C0 00000000 */   nop
    /* BD9C4 001BD9C4 E4F4060C */  jal        func_001bd390
    /* BD9C8 001BD9C8 00000000 */   nop
  .L001BD9CC:
    /* BD9CC 001BD9CC 1000BFDF */  ld         $31, 0x10($29)
    /* BD9D0 001BD9D0 0000B07B */  lq         $16, 0x0($29)
    /* BD9D4 001BD9D4 6000BD27 */  addiu      $29, $29, 0x60
    /* BD9D8 001BD9D8 0800E003 */  jr         $31
    /* BD9DC 001BD9DC 00000000 */   nop
.size func_001bd7d0, 0x210
