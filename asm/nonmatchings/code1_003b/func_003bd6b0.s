.section .text
.set noat
.set noreorder
glabel func_003bd6b0
    /* 2BD6B0 003BD6B0 E0FEBD27 */  addiu      $29, $29, -0x120
    /* 2BD6B4 003BD6B4 9000BFFF */  sd         $31, 0x90($29)
    /* 2BD6B8 003BD6B8 8000BE7F */  sq         $30, 0x80($29)
    /* 2BD6BC 003BD6BC 7000B77F */  sq         $23, 0x70($29)
    /* 2BD6C0 003BD6C0 6000B67F */  sq         $22, 0x60($29)
    /* 2BD6C4 003BD6C4 2DB8C000 */  daddu      $23, $6, $0
    /* 2BD6C8 003BD6C8 5000B57F */  sq         $21, 0x50($29)
    /* 2BD6CC 003BD6CC 2DB08000 */  daddu      $22, $4, $0
    /* 2BD6D0 003BD6D0 4000B47F */  sq         $20, 0x40($29)
    /* 2BD6D4 003BD6D4 2D300000 */  daddu      $6, $0, $0
    /* 2BD6D8 003BD6D8 3000B37F */  sq         $19, 0x30($29)
    /* 2BD6DC 003BD6DC 2DA0A000 */  daddu      $20, $5, $0
    /* 2BD6E0 003BD6E0 2000B27F */  sq         $18, 0x20($29)
    /* 2BD6E4 003BD6E4 1000B17F */  sq         $17, 0x10($29)
    /* 2BD6E8 003BD6E8 2D90E000 */  daddu      $18, $7, $0
    /* 2BD6EC 003BD6EC 01001124 */  addiu      $17, $0, 0x1
    /* 2BD6F0 003BD6F0 1C01A727 */  addiu      $7, $29, 0x11C
    /* 2BD6F4 003BD6F4 2D282002 */  daddu      $5, $17, $0
    /* 2BD6F8 003BD6F8 147C0F0C */  jal        func_003df050
    /* 2BD6FC 003BD6FC 0000B07F */   sq        $16, 0x0($29)
    /* 2BD700 003BD700 16004010 */  beqz       $2, .L003BD75C
    /* 2BD704 003BD704 00000000 */   nop
    /* 2BD708 003BD708 1C01A38F */  lw         $3, 0x11C($29)
    /* 2BD70C 003BD70C 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BD710 003BD710 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BD714 003BD714 2B106200 */  sltu       $2, $3, $2
    /* 2BD718 003BD718 06004014 */  bnez       $2, .L003BD734
    /* 2BD71C 003BD71C 00000000 */   nop
    /* 2BD720 003BD720 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BD724 003BD724 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BD728 003BD728 2B086100 */  sltu       $1, $3, $1
    /* 2BD72C 003BD72C 0D002014 */  bnez       $1, .L003BD764
    /* 2BD730 003BD730 00000000 */   nop
  .L003BD734:
    /* 2BD734 003BD734 02000324 */  addiu      $3, $0, 0x2
    /* 2BD738 003BD738 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BD73C 003BD73C 1001A3AF */  sw         $3, 0x110($29)
    /* 2BD740 003BD740 647D0F0C */  jal        func_003df590
    /* 2BD744 003BD744 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BD748 003BD748 1401A2AF */  sw         $2, 0x114($29)
    /* 2BD74C 003BD74C 347D0F0C */  jal        func_003df4d0
    /* 2BD750 003BD750 1001A427 */   addiu     $4, $29, 0x110
    /* 2BD754 003BD754 5E010010 */  b          .L003BDCD0
    /* 2BD758 003BD758 2D100000 */   daddu     $2, $0, $0
  .L003BD75C:
    /* 2BD75C 003BD75C 5C010010 */  b          .L003BDCD0
    /* 2BD760 003BD760 2D100000 */   daddu     $2, $0, $0
  .L003BD764:
    /* 2BD764 003BD764 2D20C002 */  daddu      $4, $22, $0
    /* 2BD768 003BD768 A000A527 */  addiu      $5, $29, 0xA0
    /* 2BD76C 003BD76C 448A0F0C */  jal        func_003e2910
    /* 2BD770 003BD770 2C000624 */   addiu     $6, $0, 0x2C
    /* 2BD774 003BD774 2C000324 */  addiu      $3, $0, 0x2C
    /* 2BD778 003BD778 84004314 */  bne        $2, $3, .L003BD98C
    /* 2BD77C 003BD77C 00000000 */   nop
    /* 2BD780 003BD780 7100023C */  lui        $2, %hi(D_0070B040)
    /* 2BD784 003BD784 0000938E */  lw         $19, 0x0($20)
    /* 2BD788 003BD788 40B0428C */  lw         $2, %lo(D_0070B040)($2)
    /* 2BD78C 003BD78C 21106202 */  addu       $2, $19, $2
    /* 2BD790 003BD790 80006012 */  beqz       $19, .L003BD994
    /* 2BD794 003BD794 000082AE */   sw        $2, 0x0($20)
    /* 2BD798 003BD798 FFFF0224 */  addiu      $2, $0, -0x1
    /* 2BD79C 003BD79C A400BE27 */  addiu      $30, $29, 0xA4
    /* 2BD7A0 003BD7A0 000062AE */  sw         $2, 0x0($19)
    /* 2BD7A4 003BD7A4 A800B527 */  addiu      $21, $29, 0xA8
    /* 2BD7A8 003BD7A8 AC00A2C7 */  lwc1       $f2, 0xAC($29)
    /* 2BD7AC 003BD7AC 10006426 */  addiu      $4, $19, 0x10
    /* 2BD7B0 003BD7B0 B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* 2BD7B4 003BD7B4 2D280000 */  daddu      $5, $0, $0
    /* 2BD7B8 003BD7B8 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* 2BD7BC 003BD7BC 20000624 */  addiu      $6, $0, 0x20
    /* 2BD7C0 003BD7C0 6C0062E6 */  swc1       $f2, 0x6C($19)
    /* 2BD7C4 003BD7C4 700061E6 */  swc1       $f1, 0x70($19)
    /* 2BD7C8 003BD7C8 740060E6 */  swc1       $f0, 0x74($19)
    /* 2BD7CC 003BD7CC B800A2C7 */  lwc1       $f2, 0xB8($29)
    /* 2BD7D0 003BD7D0 BC00A1C7 */  lwc1       $f1, 0xBC($29)
    /* 2BD7D4 003BD7D4 C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* 2BD7D8 003BD7D8 600062E6 */  swc1       $f2, 0x60($19)
    /* 2BD7DC 003BD7DC 640061E6 */  swc1       $f1, 0x64($19)
    /* 2BD7E0 003BD7E0 680060E6 */  swc1       $f0, 0x68($19)
    /* 2BD7E4 003BD7E4 A000A28F */  lw         $2, 0xA0($29)
    /* 2BD7E8 003BD7E8 800062A6 */  sh         $2, 0x80($19)
    /* 2BD7EC 003BD7EC 0000C28F */  lw         $2, 0x0($30)
    /* 2BD7F0 003BD7F0 840062A6 */  sh         $2, 0x84($19)
    /* 2BD7F4 003BD7F4 0000A28E */  lw         $2, 0x0($21)
    /* 2BD7F8 003BD7F8 820062A6 */  sh         $2, 0x82($19)
    /* 2BD7FC 003BD7FC 040060AE */  sw         $0, 0x4($19)
    /* 2BD800 003BD800 080060AE */  sw         $0, 0x8($19)
    /* 2BD804 003BD804 300060AE */  sw         $0, 0x30($19)
    /* 2BD808 003BD808 72FE100C */  jal        func_0043f9c8
    /* 2BD80C 003BD80C 0C0060AE */   sw        $0, 0xC($19)
    /* 2BD810 003BD810 7C0060AE */  sw         $0, 0x7C($19)
    /* 2BD814 003BD814 38006426 */  addiu      $4, $19, 0x38
    /* 2BD818 003BD818 340060AE */  sw         $0, 0x34($19)
    /* 2BD81C 003BD81C 40006326 */  addiu      $3, $19, 0x40
    /* 2BD820 003BD820 780060AE */  sw         $0, 0x78($19)
    /* 2BD824 003BD824 0001023C */  lui        $2, (0x1000000 >> 16)
    /* 2BD828 003BD828 380064AE */  sw         $4, 0x38($19)
    /* 2BD82C 003BD82C 3C0064AE */  sw         $4, 0x3C($19)
    /* 2BD830 003BD830 400063AE */  sw         $3, 0x40($19)
    /* 2BD834 003BD834 440063AE */  sw         $3, 0x44($19)
    /* 2BD838 003BD838 0800E38E */  lw         $3, 0x8($23)
    /* 2BD83C 003BD83C 24106200 */  and        $2, $3, $2
    /* 2BD840 003BD840 41004014 */  bnez       $2, .L003BD948
    /* 2BD844 003BD844 00000000 */   nop
    /* 2BD848 003BD848 0000A48E */  lw         $4, 0x0($21)
    /* 2BD84C 003BD84C 5D008014 */  bnez       $4, .L003BD9C4
    /* 2BD850 003BD850 00000000 */   nop
  .L003BD854:
    /* 2BD854 003BD854 3C002012 */  beqz       $17, .L003BD948
    /* 2BD858 003BD858 00000000 */   nop
    /* 2BD85C 003BD85C 0000C28F */  lw         $2, 0x0($30)
    /* 2BD860 003BD860 39004010 */  beqz       $2, .L003BD948
    /* 2BD864 003BD864 00000000 */   nop
    /* 2BD868 003BD868 0000838E */  lw         $3, 0x0($20)
    /* 2BD86C 003BD86C C0800200 */  sll        $16, $2, 3
    /* 2BD870 003BD870 21107000 */  addu       $2, $3, $16
    /* 2BD874 003BD874 000082AE */  sw         $2, 0x0($20)
    /* 2BD878 003BD878 040063AE */  sw         $3, 0x4($19)
    /* 2BD87C 003BD87C 0400628E */  lw         $2, 0x4($19)
    /* 2BD880 003BD880 E3004010 */  beqz       $2, .L003BDC10
    /* 2BD884 003BD884 00000000 */   nop
  .L003BD888:
    /* 2BD888 003BD888 EC002016 */  bnez       $17, .L003BDC3C
    /* 2BD88C 003BD88C 00000000 */   nop
  .L003BD890:
    /* 2BD890 003BD890 2D002012 */  beqz       $17, .L003BD948
    /* 2BD894 003BD894 00000000 */   nop
    /* 2BD898 003BD898 1C01A28F */  lw         $2, 0x11C($29)
    /* 2BD89C 003BD89C 0300013C */  lui        $1, (0x36002 >> 16)
    /* 2BD8A0 003BD8A0 02602134 */  ori        $1, $1, (0x36002 & 0xFFFF)
    /* 2BD8A4 003BD8A4 2B084100 */  sltu       $1, $2, $1
    /* 2BD8A8 003BD8A8 27002010 */  beqz       $1, .L003BD948
    /* 2BD8AC 003BD8AC 00000000 */   nop
    /* 2BD8B0 003BD8B0 0000C28F */  lw         $2, 0x0($30)
    /* 2BD8B4 003BD8B4 2A080200 */  slt        $1, $0, $2
    /* 2BD8B8 003BD8B8 23002010 */  beqz       $1, .L003BD948
    /* 2BD8BC 003BD8BC 2D280000 */   daddu     $5, $0, $0
    /* 2BD8C0 003BD8C0 2D300000 */  daddu      $6, $0, $0
    /* 2BD8C4 003BD8C4 DA00A427 */  addiu      $4, $29, 0xDA
    /* 2BD8C8 003BD8C8 DC00A327 */  addiu      $3, $29, 0xDC
    /* 2BD8CC 003BD8CC DE00A227 */  addiu      $2, $29, 0xDE
  .L003BD8D0:
    /* 2BD8D0 003BD8D0 0400678E */  lw         $7, 0x4($19)
    /* 2BD8D4 003BD8D4 0100A524 */  addiu      $5, $5, 0x1
    /* 2BD8D8 003BD8D8 2158E600 */  addu       $11, $7, $6
    /* 2BD8DC 003BD8DC 02006985 */  lh         $9, 0x2($11)
    /* 2BD8E0 003BD8E0 06006785 */  lh         $7, 0x6($11)
    /* 2BD8E4 003BD8E4 00006A85 */  lh         $10, 0x0($11)
    /* 2BD8E8 003BD8E8 04006885 */  lh         $8, 0x4($11)
    /* 2BD8EC 003BD8EC DA00A9A7 */  sh         $9, 0xDA($29)
    /* 2BD8F0 003BD8F0 DE00A7A7 */  sh         $7, 0xDE($29)
    /* 2BD8F4 003BD8F4 00008794 */  lhu        $7, 0x0($4)
    /* 2BD8F8 003BD8F8 D800AAA7 */  sh         $10, 0xD8($29)
    /* 2BD8FC 003BD8FC DC00A8A7 */  sh         $8, 0xDC($29)
    /* 2BD900 003BD900 00006A94 */  lhu        $10, 0x0($3)
    /* 2BD904 003BD904 00004994 */  lhu        $9, 0x0($2)
    /* 2BD908 003BD908 D800A897 */  lhu        $8, 0xD8($29)
    /* 2BD90C 003BD90C 000067A5 */  sh         $7, 0x0($11)
    /* 2BD910 003BD910 0400678E */  lw         $7, 0x4($19)
    /* 2BD914 003BD914 2138E600 */  addu       $7, $7, $6
    /* 2BD918 003BD918 0200EAA4 */  sh         $10, 0x2($7)
    /* 2BD91C 003BD91C 0400678E */  lw         $7, 0x4($19)
    /* 2BD920 003BD920 2138E600 */  addu       $7, $7, $6
    /* 2BD924 003BD924 0400E9A4 */  sh         $9, 0x4($7)
    /* 2BD928 003BD928 0400678E */  lw         $7, 0x4($19)
    /* 2BD92C 003BD92C 2138E600 */  addu       $7, $7, $6
    /* 2BD930 003BD930 0600E8A4 */  sh         $8, 0x6($7)
    /* 2BD934 003BD934 0000C78F */  lw         $7, 0x0($30)
    /* 2BD938 003BD938 2A38A700 */  slt        $7, $5, $7
    /* 2BD93C 003BD93C E4FFE014 */  bnez       $7, .L003BD8D0
    /* 2BD940 003BD940 0800C624 */   addiu     $6, $6, 0x8
    /* 2BD944 003BD944 00000000 */  nop
  .L003BD948:
    /* 2BD948 003BD948 C4002016 */  bnez       $17, .L003BDC5C
    /* 2BD94C 003BD94C 00000000 */   nop
  .L003BD950:
    /* 2BD950 003BD950 DE002016 */  bnez       $17, .L003BDCCC
    /* 2BD954 003BD954 00000000 */   nop
    /* 2BD958 003BD958 0300E292 */  lbu        $2, 0x3($23)
    /* 2BD95C 003BD95C 01004230 */  andi       $2, $2, 0x1
    /* 2BD960 003BD960 05004010 */  beqz       $2, .L003BD978
    /* 2BD964 003BD964 00000000 */   nop
    /* 2BD968 003BD968 74240F0C */  jal        func_003c91d0
    /* 2BD96C 003BD96C 2D206002 */   daddu     $4, $19, $0
    /* 2BD970 003BD970 04000010 */  b          .L003BD984
    /* 2BD974 003BD974 2D100000 */   daddu     $2, $0, $0
  .L003BD978:
    /* 2BD978 003BD978 C0240F0C */  jal        func_003c9300
    /* 2BD97C 003BD97C 2D206002 */   daddu     $4, $19, $0
    /* 2BD980 003BD980 2D100000 */  daddu      $2, $0, $0
  .L003BD984:
    /* 2BD984 003BD984 D3000010 */  b          .L003BDCD4
    /* 2BD988 003BD988 9000BFDF */   ld        $31, 0x90($29)
  .L003BD98C:
    /* 2BD98C 003BD98C D0000010 */  b          .L003BDCD0
    /* 2BD990 003BD990 2D100000 */   daddu     $2, $0, $0
  .L003BD994:
    /* 2BD994 003BD994 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BD998 003BD998 02000324 */  addiu      $3, $0, 0x2
    /* 2BD99C 003BD99C 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2BD9A0 003BD9A0 7100023C */  lui        $2, %hi(D_0070B040)
    /* 2BD9A4 003BD9A4 40B0458C */  lw         $5, %lo(D_0070B040)($2)
    /* 2BD9A8 003BD9A8 647D0F0C */  jal        func_003df590
    /* 2BD9AC 003BD9AC 0801A3AF */   sw        $3, 0x108($29)
    /* 2BD9B0 003BD9B0 0C01A2AF */  sw         $2, 0x10C($29)
    /* 2BD9B4 003BD9B4 347D0F0C */  jal        func_003df4d0
    /* 2BD9B8 003BD9B8 0801A427 */   addiu     $4, $29, 0x108
    /* 2BD9BC 003BD9BC C4000010 */  b          .L003BDCD0
    /* 2BD9C0 003BD9C0 2D100000 */   daddu     $2, $0, $0
  .L003BD9C4:
    /* 2BD9C4 003BD9C4 0000838E */  lw         $3, 0x0($20)
    /* 2BD9C8 003BD9C8 40100400 */  sll        $2, $4, 1
    /* 2BD9CC 003BD9CC 21104400 */  addu       $2, $2, $4
    /* 2BD9D0 003BD9D0 80800200 */  sll        $16, $2, 2
    /* 2BD9D4 003BD9D4 21107000 */  addu       $2, $3, $16
    /* 2BD9D8 003BD9D8 000082AE */  sw         $2, 0x0($20)
    /* 2BD9DC 003BD9DC 080063AE */  sw         $3, 0x8($19)
    /* 2BD9E0 003BD9E0 0800628E */  lw         $2, 0x8($19)
    /* 2BD9E4 003BD9E4 4B004010 */  beqz       $2, .L003BDB14
    /* 2BD9E8 003BD9E8 00000000 */   nop
  .L003BD9EC:
    /* 2BD9EC 003BD9EC 54002016 */  bnez       $17, .L003BDB40
    /* 2BD9F0 003BD9F0 00000000 */   nop
  .L003BD9F4:
    /* 2BD9F4 003BD9F4 16002012 */  beqz       $17, .L003BDA50
    /* 2BD9F8 003BD9F8 00000000 */   nop
    /* 2BD9FC 003BD9FC 10004232 */  andi       $2, $18, 0x10
    /* 2BDA00 003BDA00 13004010 */  beqz       $2, .L003BDA50
    /* 2BDA04 003BDA04 00000000 */   nop
    /* 2BDA08 003BDA08 0000A28E */  lw         $2, 0x0($21)
    /* 2BDA0C 003BDA0C 0000838E */  lw         $3, 0x0($20)
    /* 2BDA10 003BDA10 80800200 */  sll        $16, $2, 2
    /* 2BDA14 003BDA14 21107000 */  addu       $2, $3, $16
    /* 2BDA18 003BDA18 000082AE */  sw         $2, 0x0($20)
    /* 2BDA1C 003BDA1C 0C0063AE */  sw         $3, 0xC($19)
    /* 2BDA20 003BDA20 0C00628E */  lw         $2, 0xC($19)
    /* 2BDA24 003BDA24 4E004010 */  beqz       $2, .L003BDB60
    /* 2BDA28 003BDA28 00000000 */   nop
  .L003BDA2C:
    /* 2BDA2C 003BDA2C 08002012 */  beqz       $17, .L003BDA50
    /* 2BDA30 003BDA30 00000000 */   nop
    /* 2BDA34 003BDA34 0C00658E */  lw         $5, 0xC($19)
    /* 2BDA38 003BDA38 2D20C002 */  daddu      $4, $22, $0
    /* 2BDA3C 003BDA3C 448A0F0C */  jal        func_003e2910
    /* 2BDA40 003BDA40 2D300002 */   daddu     $6, $16, $0
    /* 2BDA44 003BDA44 02000212 */  beq        $16, $2, .L003BDA50
    /* 2BDA48 003BDA48 00000000 */   nop
    /* 2BDA4C 003BDA4C 2D880000 */  daddu      $17, $0, $0
  .L003BDA50:
    /* 2BDA50 003BDA50 16002012 */  beqz       $17, .L003BDAAC
    /* 2BDA54 003BDA54 00000000 */   nop
    /* 2BDA58 003BDA58 08004232 */  andi       $2, $18, 0x8
    /* 2BDA5C 003BDA5C 13004010 */  beqz       $2, .L003BDAAC
    /* 2BDA60 003BDA60 00000000 */   nop
    /* 2BDA64 003BDA64 0000A28E */  lw         $2, 0x0($21)
    /* 2BDA68 003BDA68 0000838E */  lw         $3, 0x0($20)
    /* 2BDA6C 003BDA6C 80800200 */  sll        $16, $2, 2
    /* 2BDA70 003BDA70 21107000 */  addu       $2, $3, $16
    /* 2BDA74 003BDA74 000082AE */  sw         $2, 0x0($20)
    /* 2BDA78 003BDA78 300063AE */  sw         $3, 0x30($19)
    /* 2BDA7C 003BDA7C 3000628E */  lw         $2, 0x30($19)
    /* 2BDA80 003BDA80 42004010 */  beqz       $2, .L003BDB8C
    /* 2BDA84 003BDA84 00000000 */   nop
  .L003BDA88:
    /* 2BDA88 003BDA88 08002012 */  beqz       $17, .L003BDAAC
    /* 2BDA8C 003BDA8C 00000000 */   nop
    /* 2BDA90 003BDA90 3000658E */  lw         $5, 0x30($19)
    /* 2BDA94 003BDA94 2D300002 */  daddu      $6, $16, $0
    /* 2BDA98 003BDA98 448A0F0C */  jal        func_003e2910
    /* 2BDA9C 003BDA9C 2D20C002 */   daddu     $4, $22, $0
    /* 2BDAA0 003BDAA0 02004014 */  bnez       $2, .L003BDAAC
    /* 2BDAA4 003BDAA4 00000000 */   nop
    /* 2BDAA8 003BDAA8 2D880000 */  daddu      $17, $0, $0
  .L003BDAAC:
    /* 2BDAAC 003BDAAC 69FF2012 */  beqz       $17, .L003BD854
    /* 2BDAB0 003BDAB0 00000000 */   nop
    /* 2BDAB4 003BDAB4 2000E38E */  lw         $3, 0x20($23)
    /* 2BDAB8 003BDAB8 66FF6018 */  blez       $3, .L003BD854
    /* 2BDABC 003BDABC 00000000 */   nop
    /* 2BDAC0 003BDAC0 82006296 */  lhu        $2, 0x82($19)
    /* 2BDAC4 003BDAC4 2A080300 */  slt        $1, $0, $3
    /* 2BDAC8 003BDAC8 2D900000 */  daddu      $18, $0, $0
    /* 2BDACC 003BDACC 61FF2010 */  beqz       $1, .L003BD854
    /* 2BDAD0 003BDAD0 C0A80200 */   sll       $21, $2, 3
    /* 2BDAD4 003BDAD4 2D806002 */  daddu      $16, $19, $0
  .L003BDAD8:
    /* 2BDAD8 003BDAD8 0000838E */  lw         $3, 0x0($20)
    /* 2BDADC 003BDADC 21107500 */  addu       $2, $3, $21
    /* 2BDAE0 003BDAE0 000082AE */  sw         $2, 0x0($20)
    /* 2BDAE4 003BDAE4 34002016 */  bnez       $17, .L003BDBB8
    /* 2BDAE8 003BDAE8 100003AE */   sw        $3, 0x10($16)
    /* 2BDAEC 003BDAEC 00000000 */  nop
  .L003BDAF0:
    /* 2BDAF0 003BDAF0 3F002016 */  bnez       $17, .L003BDBF0
    /* 2BDAF4 003BDAF4 00000000 */   nop
  .L003BDAF8:
    /* 2BDAF8 003BDAF8 2000E28E */  lw         $2, 0x20($23)
    /* 2BDAFC 003BDAFC 01005226 */  addiu      $18, $18, 0x1
    /* 2BDB00 003BDB00 2A104202 */  slt        $2, $18, $2
    /* 2BDB04 003BDB04 F4FF4014 */  bnez       $2, .L003BDAD8
    /* 2BDB08 003BDB08 04001026 */   addiu     $16, $16, 0x4
    /* 2BDB0C 003BDB0C 51FF0010 */  b          .L003BD854
    /* 2BDB10 003BDB10 00000000 */   nop
  .L003BDB14:
    /* 2BDB14 003BDB14 02000324 */  addiu      $3, $0, 0x2
    /* 2BDB18 003BDB18 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BDB1C 003BDB1C 0001A3AF */  sw         $3, 0x100($29)
    /* 2BDB20 003BDB20 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2BDB24 003BDB24 647D0F0C */  jal        func_003df590
    /* 2BDB28 003BDB28 2D280002 */   daddu     $5, $16, $0
    /* 2BDB2C 003BDB2C 0401A2AF */  sw         $2, 0x104($29)
    /* 2BDB30 003BDB30 347D0F0C */  jal        func_003df4d0
    /* 2BDB34 003BDB34 0001A427 */   addiu     $4, $29, 0x100
    /* 2BDB38 003BDB38 ACFF0010 */  b          .L003BD9EC
    /* 2BDB3C 003BDB3C 2D880000 */   daddu     $17, $0, $0
  .L003BDB40:
    /* 2BDB40 003BDB40 0800658E */  lw         $5, 0x8($19)
    /* 2BDB44 003BDB44 2D300002 */  daddu      $6, $16, $0
    /* 2BDB48 003BDB48 C07C0F0C */  jal        func_003df300
    /* 2BDB4C 003BDB4C 2D20C002 */   daddu     $4, $22, $0
    /* 2BDB50 003BDB50 A8FF4014 */  bnez       $2, .L003BD9F4
    /* 2BDB54 003BDB54 00000000 */   nop
    /* 2BDB58 003BDB58 A6FF0010 */  b          .L003BD9F4
    /* 2BDB5C 003BDB5C 2D880000 */   daddu     $17, $0, $0
  .L003BDB60:
    /* 2BDB60 003BDB60 02000324 */  addiu      $3, $0, 0x2
    /* 2BDB64 003BDB64 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BDB68 003BDB68 F800A3AF */  sw         $3, 0xF8($29)
    /* 2BDB6C 003BDB6C 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2BDB70 003BDB70 647D0F0C */  jal        func_003df590
    /* 2BDB74 003BDB74 2D280002 */   daddu     $5, $16, $0
    /* 2BDB78 003BDB78 FC00A2AF */  sw         $2, 0xFC($29)
    /* 2BDB7C 003BDB7C 347D0F0C */  jal        func_003df4d0
    /* 2BDB80 003BDB80 F800A427 */   addiu     $4, $29, 0xF8
    /* 2BDB84 003BDB84 A9FF0010 */  b          .L003BDA2C
    /* 2BDB88 003BDB88 2D880000 */   daddu     $17, $0, $0
  .L003BDB8C:
    /* 2BDB8C 003BDB8C 02000324 */  addiu      $3, $0, 0x2
    /* 2BDB90 003BDB90 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BDB94 003BDB94 F000A3AF */  sw         $3, 0xF0($29)
    /* 2BDB98 003BDB98 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2BDB9C 003BDB9C 647D0F0C */  jal        func_003df590
    /* 2BDBA0 003BDBA0 2D280002 */   daddu     $5, $16, $0
    /* 2BDBA4 003BDBA4 F400A2AF */  sw         $2, 0xF4($29)
    /* 2BDBA8 003BDBA8 347D0F0C */  jal        func_003df4d0
    /* 2BDBAC 003BDBAC F000A427 */   addiu     $4, $29, 0xF0
    /* 2BDBB0 003BDBB0 B5FF0010 */  b          .L003BDA88
    /* 2BDBB4 003BDBB4 2D880000 */   daddu     $17, $0, $0
  .L003BDBB8:
    /* 2BDBB8 003BDBB8 1000028E */  lw         $2, 0x10($16)
    /* 2BDBBC 003BDBBC CCFF4014 */  bnez       $2, .L003BDAF0
    /* 2BDBC0 003BDBC0 00000000 */   nop
    /* 2BDBC4 003BDBC4 02000224 */  addiu      $2, $0, 0x2
    /* 2BDBC8 003BDBC8 2D28A002 */  daddu      $5, $21, $0
    /* 2BDBCC 003BDBCC E800A2AF */  sw         $2, 0xE8($29)
    /* 2BDBD0 003BDBD0 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BDBD4 003BDBD4 647D0F0C */  jal        func_003df590
    /* 2BDBD8 003BDBD8 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2BDBDC 003BDBDC EC00A2AF */  sw         $2, 0xEC($29)
    /* 2BDBE0 003BDBE0 347D0F0C */  jal        func_003df4d0
    /* 2BDBE4 003BDBE4 E800A427 */   addiu     $4, $29, 0xE8
    /* 2BDBE8 003BDBE8 1AFF0010 */  b          .L003BD854
    /* 2BDBEC 003BDBEC 2D880000 */   daddu     $17, $0, $0
  .L003BDBF0:
    /* 2BDBF0 003BDBF0 1000058E */  lw         $5, 0x10($16)
    /* 2BDBF4 003BDBF4 2D20C002 */  daddu      $4, $22, $0
    /* 2BDBF8 003BDBF8 C07C0F0C */  jal        func_003df300
    /* 2BDBFC 003BDBFC 2D30A002 */   daddu     $6, $21, $0
    /* 2BDC00 003BDC00 BDFF4014 */  bnez       $2, .L003BDAF8
    /* 2BDC04 003BDC04 00000000 */   nop
    /* 2BDC08 003BDC08 12FF0010 */  b          .L003BD854
    /* 2BDC0C 003BDC0C 2D880000 */   daddu     $17, $0, $0
  .L003BDC10:
    /* 2BDC10 003BDC10 02000324 */  addiu      $3, $0, 0x2
    /* 2BDC14 003BDC14 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BDC18 003BDC18 E000A3AF */  sw         $3, 0xE0($29)
    /* 2BDC1C 003BDC1C 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2BDC20 003BDC20 647D0F0C */  jal        func_003df590
    /* 2BDC24 003BDC24 2D280002 */   daddu     $5, $16, $0
    /* 2BDC28 003BDC28 E400A2AF */  sw         $2, 0xE4($29)
    /* 2BDC2C 003BDC2C 347D0F0C */  jal        func_003df4d0
    /* 2BDC30 003BDC30 E000A427 */   addiu     $4, $29, 0xE0
    /* 2BDC34 003BDC34 14FF0010 */  b          .L003BD888
    /* 2BDC38 003BDC38 2D880000 */   daddu     $17, $0, $0
  .L003BDC3C:
    /* 2BDC3C 003BDC3C 0400658E */  lw         $5, 0x4($19)
    /* 2BDC40 003BDC40 2D300002 */  daddu      $6, $16, $0
    /* 2BDC44 003BDC44 A87C0F0C */  jal        func_003df2a0
    /* 2BDC48 003BDC48 2D20C002 */   daddu     $4, $22, $0
    /* 2BDC4C 003BDC4C 10FF4014 */  bnez       $2, .L003BD890
    /* 2BDC50 003BDC50 00000000 */   nop
    /* 2BDC54 003BDC54 0EFF0010 */  b          .L003BD890
    /* 2BDC58 003BDC58 2D880000 */   daddu     $17, $0, $0
  .L003BDC5C:
    /* 2BDC5C 003BDC5C 7100043C */  lui        $4, %hi(D_0070B040)
    /* 2BDC60 003BDC60 2D286002 */  daddu      $5, $19, $0
    /* 2BDC64 003BDC64 DC8E0F0C */  jal        func_003e3b70
    /* 2BDC68 003BDC68 40B08424 */   addiu     $4, $4, %lo(D_0070B040)
    /* 2BDC6C 003BDC6C 9CB680AF */  sw         $0, -0x4964($28)
    /* 2BDC70 003BDC70 0D002016 */  bnez       $17, .L003BDCA8
    /* 2BDC74 003BDC74 98B680AF */   sw        $0, -0x4968($28)
  .L003BDC78:
    /* 2BDC78 003BDC78 35FF2012 */  beqz       $17, .L003BD950
    /* 2BDC7C 003BDC7C 00000000 */   nop
    /* 2BDC80 003BDC80 9CB6858F */  lw         $5, -0x4964($28)
    /* 2BDC84 003BDC84 32FFA010 */  beqz       $5, .L003BD950
    /* 2BDC88 003BDC88 00000000 */   nop
    /* 2BDC8C 003BDC8C 98B6878F */  lw         $7, -0x4968($28)
    /* 2BDC90 003BDC90 7100043C */  lui        $4, %hi(D_0070B040)
    /* 2BDC94 003BDC94 40B08424 */  addiu      $4, $4, %lo(D_0070B040)
    /* 2BDC98 003BDC98 BC8C0F0C */  jal        func_003e32f0
    /* 2BDC9C 003BDC9C 2D306002 */   daddu     $6, $19, $0
    /* 2BDCA0 003BDCA0 2BFF0010 */  b          .L003BD950
    /* 2BDCA4 003BDCA4 00000000 */   nop
  .L003BDCA8:
    /* 2BDCA8 003BDCA8 7100043C */  lui        $4, %hi(D_0070B040)
    /* 2BDCAC 003BDCAC 2D28C002 */  daddu      $5, $22, $0
    /* 2BDCB0 003BDCB0 40B08424 */  addiu      $4, $4, %lo(D_0070B040)
    /* 2BDCB4 003BDCB4 448C0F0C */  jal        func_003e3110
    /* 2BDCB8 003BDCB8 2D306002 */   daddu     $6, $19, $0
    /* 2BDCBC 003BDCBC EEFF4014 */  bnez       $2, .L003BDC78
    /* 2BDCC0 003BDCC0 00000000 */   nop
    /* 2BDCC4 003BDCC4 ECFF0010 */  b          .L003BDC78
    /* 2BDCC8 003BDCC8 2D880000 */   daddu     $17, $0, $0
  .L003BDCCC:
    /* 2BDCCC 003BDCCC 2D106002 */  daddu      $2, $19, $0
  .L003BDCD0:
    /* 2BDCD0 003BDCD0 9000BFDF */  ld         $31, 0x90($29)
  .L003BDCD4:
    /* 2BDCD4 003BDCD4 8000BE7B */  lq         $30, 0x80($29)
    /* 2BDCD8 003BDCD8 7000B77B */  lq         $23, 0x70($29)
    /* 2BDCDC 003BDCDC 6000B67B */  lq         $22, 0x60($29)
    /* 2BDCE0 003BDCE0 5000B57B */  lq         $21, 0x50($29)
    /* 2BDCE4 003BDCE4 4000B47B */  lq         $20, 0x40($29)
    /* 2BDCE8 003BDCE8 3000B37B */  lq         $19, 0x30($29)
    /* 2BDCEC 003BDCEC 2000B27B */  lq         $18, 0x20($29)
    /* 2BDCF0 003BDCF0 1000B17B */  lq         $17, 0x10($29)
    /* 2BDCF4 003BDCF4 0000B07B */  lq         $16, 0x0($29)
    /* 2BDCF8 003BDCF8 0800E003 */  jr         $31
    /* 2BDCFC 003BDCFC 2001BD27 */   addiu     $29, $29, 0x120
.size func_003bd6b0, 0x650
