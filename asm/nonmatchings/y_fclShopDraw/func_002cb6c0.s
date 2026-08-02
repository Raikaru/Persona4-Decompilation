.section .text
.set noat
.set noreorder
glabel func_002cb6c0
    /* 1CB6C0 002CB6C0 D0FDBD27 */  addiu      $29, $29, -0x230
    /* 1CB6C4 002CB6C4 B000BFFF */  sd         $31, 0xB0($29)
    /* 1CB6C8 002CB6C8 A000BE7F */  sq         $30, 0xA0($29)
    /* 1CB6CC 002CB6CC 9000B77F */  sq         $23, 0x90($29)
    /* 1CB6D0 002CB6D0 8000B67F */  sq         $22, 0x80($29)
    /* 1CB6D4 002CB6D4 7000B57F */  sq         $21, 0x70($29)
    /* 1CB6D8 002CB6D8 6000B47F */  sq         $20, 0x60($29)
    /* 1CB6DC 002CB6DC 5000B37F */  sq         $19, 0x50($29)
    /* 1CB6E0 002CB6E0 4000B27F */  sq         $18, 0x40($29)
    /* 1CB6E4 002CB6E4 3000B17F */  sq         $17, 0x30($29)
    /* 1CB6E8 002CB6E8 2000B07F */  sq         $16, 0x20($29)
    /* 1CB6EC 002CB6EC 1000B4E7 */  swc1       $f20, 0x10($29)
    /* 1CB6F0 002CB6F0 2DA88000 */  daddu      $21, $4, $0
    /* 1CB6F4 002CB6F4 D700A5A3 */  sb         $5, 0xD7($29)
    /* 1CB6F8 002CB6F8 3800908C */  lw         $16, 0x38($4)
    /* 1CB6FC 002CB6FC 9C890B0C */  jal        func_002e2670
    /* 1CB700 002CB700 00000000 */   nop
    /* 1CB704 002CB704 06004128 */  slti       $1, $2, 0x6
    /* 1CB708 002CB708 46002014 */  bnez       $1, .L002CB824
    /* 1CB70C 002CB70C 00000000 */   nop
    /* 1CB710 002CB710 9C890B0C */  jal        func_002e2670
    /* 1CB714 002CB714 00000000 */   nop
    /* 1CB718 002CB718 06004128 */  slti       $1, $2, 0x6
    /* 1CB71C 002CB71C 0C002014 */  bnez       $1, .L002CB750
    /* 1CB720 002CB720 00000000 */   nop
    /* 1CB724 002CB724 9C890B0C */  jal        func_002e2670
    /* 1CB728 002CB728 00000000 */   nop
    /* 1CB72C 002CB72C FBFF4224 */  addiu      $2, $2, -0x5
    /* 1CB730 002CB730 00008244 */  mtc1       $2, $f0
    /* 1CB734 002CB734 00000000 */  nop
    /* 1CB738 002CB738 60008046 */  cvt.s.w    $f1, $f0
    /* 1CB73C 002CB73C D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1CB740 002CB740 00008244 */  mtc1       $2, $f0
    /* 1CB744 002CB744 00000000 */  nop
    /* 1CB748 002CB748 03000146 */  div.s      $f0, $f0, $f1
    /* 1CB74C 002CB74C 0C0000E6 */  swc1       $f0, 0xC($16)
  .L002CB750:
    /* 1CB750 002CB750 02000386 */  lh         $3, 0x2($16)
    /* 1CB754 002CB754 04000286 */  lh         $2, 0x4($16)
    /* 1CB758 002CB758 23106200 */  subu       $2, $3, $2
    /* 1CB75C 002CB75C 00008244 */  mtc1       $2, $f0
    /* 1CB760 002CB760 00000000 */  nop
    /* 1CB764 002CB764 E0008046 */  cvt.s.w    $f3, $f0
    /* 1CB768 002CB768 0C0002C6 */  lwc1       $f2, 0xC($16)
    /* 1CB76C 002CB76C 0E43023C */  lui        $2, (0x430E0000 >> 16)
    /* 1CB770 002CB770 00088244 */  mtc1       $2, $f1
    /* 1CB774 002CB774 00008044 */  mtc1       $0, $f0
    /* 1CB778 002CB778 00000000 */  nop
    /* 1CB77C 002CB77C 18000146 */  adda.s     $f0, $f1
    /* 1CB780 002CB780 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1CB784 002CB784 21020224 */  addiu      $2, $0, 0x221
    /* 1CB788 002CB788 00008244 */  mtc1       $2, $f0
    /* 1CB78C 002CB78C 00000000 */  nop
    /* 1CB790 002CB790 20038046 */  cvt.s.w    $f12, $f0
    /* 1CB794 002CB794 E801A427 */  addiu      $4, $29, 0x1E8
    /* 1CB798 002CB798 5CCA0A0C */  jal        func_002b2970
    /* 1CB79C 002CB79C 00000000 */   nop
    /* 1CB7A0 002CB7A0 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CB7A4 002CB7A4 FE000524 */  addiu      $5, $0, 0xFE
    /* 1CB7A8 002CB7A8 C6000624 */  addiu      $6, $0, 0xC6
    /* 1CB7AC 002CB7AC 31000724 */  addiu      $7, $0, 0x31
    /* 1CB7B0 002CB7B0 8CCA0A0C */  jal        func_002b2a30
    /* 1CB7B4 002CB7B4 00000000 */   nop
    /* 1CB7B8 002CB7B8 2D884000 */  daddu      $17, $2, $0
    /* 1CB7BC 002CB7BC 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CB7C0 002CB7C0 38810B0C */  jal        func_002e04e0
    /* 1CB7C4 002CB7C4 00000000 */   nop
    /* 1CB7C8 002CB7C8 0A43033C */  lui        $3, (0x430A0000 >> 16)
    /* 1CB7CC 002CB7CC 00608344 */  mtc1       $3, $f12
    /* 1CB7D0 002CB7D0 36000424 */  addiu      $4, $0, 0x36
    /* 1CB7D4 002CB7D4 E801A5DF */  ld         $5, 0x1E8($29)
    /* 1CB7D8 002CB7D8 2D302002 */  daddu      $6, $17, $0
    /* 1CB7DC 002CB7DC 62004790 */  lbu        $7, 0x62($2)
    /* 1CB7E0 002CB7E0 2D400000 */  daddu      $8, $0, $0
    /* 1CB7E4 002CB7E4 7900093C */  lui        $9, %hi(D_00794EA0)
    /* 1CB7E8 002CB7E8 A04E2925 */  addiu      $9, $9, %lo(D_00794EA0)
    /* 1CB7EC 002CB7EC C8820B0C */  jal        func_002e0b20
    /* 1CB7F0 002CB7F0 00000000 */   nop
    /* 1CB7F4 002CB7F4 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CB7F8 002CB7F8 2D280000 */  daddu      $5, $0, $0
    /* 1CB7FC 002CB7FC 2D300000 */  daddu      $6, $0, $0
    /* 1CB800 002CB800 3C810B0C */  jal        func_002e04f0
    /* 1CB804 002CB804 00000000 */   nop
    /* 1CB808 002CB808 900C048E */  lw         $4, 0xC90($16)
    /* 1CB80C 002CB80C 2D280000 */  daddu      $5, $0, $0
    /* 1CB810 002CB810 2D300000 */  daddu      $6, $0, $0
    /* 1CB814 002CB814 3C810B0C */  jal        func_002e04f0
    /* 1CB818 002CB818 00000000 */   nop
    /* 1CB81C 002CB81C 0B000010 */  b          .L002CB84C
    /* 1CB820 002CB820 00000000 */   nop
  .L002CB824:
    /* 1CB824 002CB824 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CB828 002CB828 2D280000 */  daddu      $5, $0, $0
    /* 1CB82C 002CB82C 01000624 */  addiu      $6, $0, 0x1
    /* 1CB830 002CB830 3C810B0C */  jal        func_002e04f0
    /* 1CB834 002CB834 00000000 */   nop
    /* 1CB838 002CB838 900C048E */  lw         $4, 0xC90($16)
    /* 1CB83C 002CB83C 2D280000 */  daddu      $5, $0, $0
    /* 1CB840 002CB840 01000624 */  addiu      $6, $0, 0x1
    /* 1CB844 002CB844 3C810B0C */  jal        func_002e04f0
    /* 1CB848 002CB848 00000000 */   nop
  .L002CB84C:
    /* 1CB84C 002CB84C 4C42023C */  lui        $2, (0x424C0000 >> 16)
    /* 1CB850 002CB850 00608244 */  mtc1       $2, $f12
    /* 1CB854 002CB854 4042023C */  lui        $2, (0x42400000 >> 16)
    /* 1CB858 002CB858 00688244 */  mtc1       $2, $f13
    /* 1CB85C 002CB85C E001A427 */  addiu      $4, $29, 0x1E0
    /* 1CB860 002CB860 5CCA0A0C */  jal        func_002b2970
    /* 1CB864 002CB864 00000000 */   nop
    /* 1CB868 002CB868 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CB86C 002CB86C 2D288000 */  daddu      $5, $4, $0
    /* 1CB870 002CB870 2D308000 */  daddu      $6, $4, $0
    /* 1CB874 002CB874 2D388000 */  daddu      $7, $4, $0
    /* 1CB878 002CB878 8CCA0A0C */  jal        func_002b2a30
    /* 1CB87C 002CB87C 00000000 */   nop
    /* 1CB880 002CB880 08000382 */  lb         $3, 0x8($16)
    /* 1CB884 002CB884 21187000 */  addu       $3, $3, $16
    /* 1CB888 002CB888 2D20A002 */  daddu      $4, $21, $0
    /* 1CB88C 002CB88C 730F6580 */  lb         $5, 0xF73($3)
    /* 1CB890 002CB890 E001A6DF */  ld         $6, 0x1E0($29)
    /* 1CB894 002CB894 2D384000 */  daddu      $7, $2, $0
    /* 1CB898 002CB898 20800B0C */  jal        func_002e0080
    /* 1CB89C 002CB89C 00000000 */   nop
    /* 1CB8A0 002CB8A0 C80D048E */  lw         $4, 0xDC8($16)
    /* 1CB8A4 002CB8A4 01000524 */  addiu      $5, $0, 0x1
    /* 1CB8A8 002CB8A8 5C810B0C */  jal        func_002e0570
    /* 1CB8AC 002CB8AC 00000000 */   nop
    /* 1CB8B0 002CB8B0 3C160200 */  dsll32     $2, $2, 24
    /* 1CB8B4 002CB8B4 3F160200 */  dsra32     $2, $2, 24
    /* 1CB8B8 002CB8B8 1C004014 */  bnez       $2, .L002CB92C
    /* 1CB8BC 002CB8BC 00000000 */   nop
    /* 1CB8C0 002CB8C0 6400113C */  lui        $17, %hi(D_0063F880)
    /* 1CB8C4 002CB8C4 80F83126 */  addiu      $17, $17, %lo(D_0063F880)
    /* 1CB8C8 002CB8C8 F842023C */  lui        $2, (0x42F80000 >> 16)
    /* 1CB8CC 002CB8CC 00608244 */  mtc1       $2, $f12
    /* 1CB8D0 002CB8D0 C80D048E */  lw         $4, 0xDC8($16)
    /* 1CB8D4 002CB8D4 41000524 */  addiu      $5, $0, 0x41
    /* 1CB8D8 002CB8D8 78820B0C */  jal        func_002e09e0
    /* 1CB8DC 002CB8DC 00000000 */   nop
    /* 1CB8E0 002CB8E0 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CB8E4 002CB8E4 38810B0C */  jal        func_002e04e0
    /* 1CB8E8 002CB8E8 00000000 */   nop
    /* 1CB8EC 002CB8EC 62005290 */  lbu        $18, 0x62($2)
    /* 1CB8F0 002CB8F0 C80D048E */  lw         $4, 0xDC8($16)
    /* 1CB8F4 002CB8F4 38810B0C */  jal        func_002e04e0
    /* 1CB8F8 002CB8F8 00000000 */   nop
    /* 1CB8FC 002CB8FC 620052A0 */  sb         $18, 0x62($2)
    /* 1CB900 002CB900 04000286 */  lh         $2, 0x4($16)
    /* 1CB904 002CB904 40110200 */  sll        $2, $2, 5
    /* 1CB908 002CB908 00008244 */  mtc1       $2, $f0
    /* 1CB90C 002CB90C 00000000 */  nop
    /* 1CB910 002CB910 60008046 */  cvt.s.w    $f1, $f0
    /* 1CB914 002CB914 040020C6 */  lwc1       $f0, 0x4($17)
    /* 1CB918 002CB918 00050146 */  add.s      $f20, $f0, $f1
    /* 1CB91C 002CB91C C80D048E */  lw         $4, 0xDC8($16)
    /* 1CB920 002CB920 38810B0C */  jal        func_002e04e0
    /* 1CB924 002CB924 00000000 */   nop
    /* 1CB928 002CB928 300054E4 */  swc1       $f20, 0x30($2)
  .L002CB92C:
    /* 1CB92C 002CB92C D00D048E */  lw         $4, 0xDD0($16)
    /* 1CB930 002CB930 01000524 */  addiu      $5, $0, 0x1
    /* 1CB934 002CB934 5C810B0C */  jal        func_002e0570
    /* 1CB938 002CB938 00000000 */   nop
    /* 1CB93C 002CB93C 3C160200 */  dsll32     $2, $2, 24
    /* 1CB940 002CB940 3F160200 */  dsra32     $2, $2, 24
    /* 1CB944 002CB944 1C004014 */  bnez       $2, .L002CB9B8
    /* 1CB948 002CB948 00000000 */   nop
    /* 1CB94C 002CB94C 6400113C */  lui        $17, %hi(D_0063F890)
    /* 1CB950 002CB950 90F83126 */  addiu      $17, $17, %lo(D_0063F890)
    /* 1CB954 002CB954 FA42023C */  lui        $2, (0x42FA0000 >> 16)
    /* 1CB958 002CB958 00608244 */  mtc1       $2, $f12
    /* 1CB95C 002CB95C D00D048E */  lw         $4, 0xDD0($16)
    /* 1CB960 002CB960 41000524 */  addiu      $5, $0, 0x41
    /* 1CB964 002CB964 78820B0C */  jal        func_002e09e0
    /* 1CB968 002CB968 00000000 */   nop
    /* 1CB96C 002CB96C 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CB970 002CB970 38810B0C */  jal        func_002e04e0
    /* 1CB974 002CB974 00000000 */   nop
    /* 1CB978 002CB978 62005290 */  lbu        $18, 0x62($2)
    /* 1CB97C 002CB97C D00D048E */  lw         $4, 0xDD0($16)
    /* 1CB980 002CB980 38810B0C */  jal        func_002e04e0
    /* 1CB984 002CB984 00000000 */   nop
    /* 1CB988 002CB988 620052A0 */  sb         $18, 0x62($2)
    /* 1CB98C 002CB98C 04000286 */  lh         $2, 0x4($16)
    /* 1CB990 002CB990 40110200 */  sll        $2, $2, 5
    /* 1CB994 002CB994 00008244 */  mtc1       $2, $f0
    /* 1CB998 002CB998 00000000 */  nop
    /* 1CB99C 002CB99C 60008046 */  cvt.s.w    $f1, $f0
    /* 1CB9A0 002CB9A0 040020C6 */  lwc1       $f0, 0x4($17)
    /* 1CB9A4 002CB9A4 00050146 */  add.s      $f20, $f0, $f1
    /* 1CB9A8 002CB9A8 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CB9AC 002CB9AC 38810B0C */  jal        func_002e04e0
    /* 1CB9B0 002CB9B0 00000000 */   nop
    /* 1CB9B4 002CB9B4 300054E4 */  swc1       $f20, 0x30($2)
  .L002CB9B8:
    /* 1CB9B8 002CB9B8 07000382 */  lb         $3, 0x7($16)
    /* 1CB9BC 002CB9BC 02000224 */  addiu      $2, $0, 0x2
    /* 1CB9C0 002CB9C0 0E006210 */  beq        $3, $2, .L002CB9FC
    /* 1CB9C4 002CB9C4 00000000 */   nop
    /* 1CB9C8 002CB9C8 01000224 */  addiu      $2, $0, 0x1
    /* 1CB9CC 002CB9CC 0B006210 */  beq        $3, $2, .L002CB9FC
    /* 1CB9D0 002CB9D0 00000000 */   nop
    /* 1CB9D4 002CB9D4 03006010 */  beqz       $3, .L002CB9E4
    /* 1CB9D8 002CB9D8 00000000 */   nop
    /* 1CB9DC 002CB9DC 09000010 */  b          .L002CBA04
    /* 1CB9E0 002CB9E0 00000000 */   nop
  .L002CB9E4:
    /* 1CB9E4 002CB9E4 08000282 */  lb         $2, 0x8($16)
    /* 1CB9E8 002CB9E8 21105000 */  addu       $2, $2, $16
    /* 1CB9EC 002CB9EC 7C0F4280 */  lb         $2, 0xF7C($2)
    /* 1CB9F0 002CB9F0 FFFF5730 */  andi       $23, $2, 0xFFFF
    /* 1CB9F4 002CB9F4 03000010 */  b          .L002CBA04
    /* 1CB9F8 002CB9F8 00000000 */   nop
  .L002CB9FC:
    /* 1CB9FC 002CB9FC 1A006224 */  addiu      $2, $3, 0x1A
    /* 1CBA00 002CBA00 FFFF5730 */  andi       $23, $2, 0xFFFF
  .L002CBA04:
    /* 1CBA04 002CBA04 748A0B0C */  jal        func_002e29d0
    /* 1CBA08 002CBA08 00000000 */   nop
    /* 1CBA0C 002CBA0C 3C1E0200 */  dsll32     $3, $2, 24
    /* 1CBA10 002CBA10 3F1E0300 */  dsra32     $3, $3, 24
    /* 1CBA14 002CBA14 49096014 */  bnez       $3, .L002CDF3C
    /* 1CBA18 002CBA18 00000000 */   nop
    /* 1CBA1C 002CBA1C 02000486 */  lh         $4, 0x2($16)
    /* 1CBA20 002CBA20 04000386 */  lh         $3, 0x4($16)
    /* 1CBA24 002CBA24 23188300 */  subu       $3, $4, $3
    /* 1CBA28 002CBA28 3CA40300 */  dsll32     $20, $3, 16
    /* 1CBA2C 002CBA2C 3FA41400 */  dsra32     $20, $20, 16
    /* 1CBA30 002CBA30 2DB00000 */  daddu      $22, $0, $0
    /* 1CBA34 002CBA34 05008326 */  addiu      $3, $20, 0x5
    /* 1CBA38 002CBA38 C000A37F */  sq         $3, 0xC0($29)
    /* 1CBA3C 002CBA3C 77010010 */  b          .L002CC01C
    /* 1CBA40 002CBA40 00000000 */   nop
  .L002CBA44:
    /* 1CBA44 002CBA44 9C890B0C */  jal        func_002e2670
    /* 1CBA48 002CBA48 00000000 */   nop
    /* 1CBA4C 002CBA4C 2A082202 */  slt        $1, $17, $2
    /* 1CBA50 002CBA50 6C012010 */  beqz       $1, .L002CC004
    /* 1CBA54 002CBA54 00000000 */   nop
    /* 1CBA58 002CBA58 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBA5C 002CBA5C 38810B0C */  jal        func_002e04e0
    /* 1CBA60 002CBA60 00000000 */   nop
    /* 1CBA64 002CBA64 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CBA68 002CBA68 AE000524 */  addiu      $5, $0, 0xAE
    /* 1CBA6C 002CBA6C 2D300000 */  daddu      $6, $0, $0
    /* 1CBA70 002CBA70 62004790 */  lbu        $7, 0x62($2)
    /* 1CBA74 002CBA74 8CCA0A0C */  jal        func_002b2a30
    /* 1CBA78 002CBA78 00000000 */   nop
    /* 1CBA7C 002CBA7C 2D984000 */  daddu      $19, $2, $0
    /* 1CBA80 002CBA80 2D200000 */  daddu      $4, $0, $0
    /* 1CBA84 002CBA84 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CBA88 002CBA88 AE000624 */  addiu      $6, $0, 0xAE
    /* 1CBA8C 002CBA8C 2D380000 */  daddu      $7, $0, $0
    /* 1CBA90 002CBA90 8CCA0A0C */  jal        func_002b2a30
    /* 1CBA94 002CBA94 00000000 */   nop
    /* 1CBA98 002CBA98 2D904000 */  daddu      $18, $2, $0
    /* 1CBA9C 002CBA9C 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBAA0 002CBAA0 38810B0C */  jal        func_002e04e0
    /* 1CBAA4 002CBAA4 00000000 */   nop
    /* 1CBAA8 002CBAA8 2C02A427 */  addiu      $4, $29, 0x22C
    /* 1CBAAC 002CBAAC FF000524 */  addiu      $5, $0, 0xFF
    /* 1CBAB0 002CBAB0 AE000624 */  addiu      $6, $0, 0xAE
    /* 1CBAB4 002CBAB4 2D380000 */  daddu      $7, $0, $0
    /* 1CBAB8 002CBAB8 62004890 */  lbu        $8, 0x62($2)
    /* 1CBABC 002CBABC 98CA0A0C */  jal        func_002b2a60
    /* 1CBAC0 002CBAC0 00000000 */   nop
    /* 1CBAC4 002CBAC4 2D202002 */  daddu      $4, $17, $0
    /* 1CBAC8 002CBAC8 D0890B0C */  jal        func_002e2740
    /* 1CBACC 002CBACC 00000000 */   nop
    /* 1CBAD0 002CBAD0 3C240200 */  dsll32     $4, $2, 16
    /* 1CBAD4 002CBAD4 3F240400 */  dsra32     $4, $4, 16
    /* 1CBAD8 002CBAD8 A41A040C */  jal        func_00106a90
    /* 1CBADC 002CBADC 00000000 */   nop
    /* 1CBAE0 002CBAE0 2DF04000 */  daddu      $30, $2, $0
    /* 1CBAE4 002CBAE4 989E0B0C */  jal        func_002e7a60
    /* 1CBAE8 002CBAE8 00000000 */   nop
    /* 1CBAEC 002CBAEC 2B085E00 */  sltu       $1, $2, $30
    /* 1CBAF0 002CBAF0 0C002014 */  bnez       $1, .L002CBB24
    /* 1CBAF4 002CBAF4 00000000 */   nop
    /* 1CBAF8 002CBAF8 2D202002 */  daddu      $4, $17, $0
    /* 1CBAFC 002CBAFC D0890B0C */  jal        func_002e2740
    /* 1CBB00 002CBB00 00000000 */   nop
    /* 1CBB04 002CBB04 3C240200 */  dsll32     $4, $2, 16
    /* 1CBB08 002CBB08 3F240400 */  dsra32     $4, $4, 16
    /* 1CBB0C 002CBB0C 8019040C */  jal        func_00106600
    /* 1CBB10 002CBB10 00000000 */   nop
    /* 1CBB14 002CBB14 FF004330 */  andi       $3, $2, 0xFF
    /* 1CBB18 002CBB18 63000224 */  addiu      $2, $0, 0x63
    /* 1CBB1C 002CBB1C 61006214 */  bne        $3, $2, .L002CBCA4
    /* 1CBB20 002CBB20 00000000 */   nop
  .L002CBB24:
    /* 1CBB24 002CBB24 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBB28 002CBB28 38810B0C */  jal        func_002e04e0
    /* 1CBB2C 002CBB2C 00000000 */   nop
    /* 1CBB30 002CBB30 A6000424 */  addiu      $4, $0, 0xA6
    /* 1CBB34 002CBB34 7F000524 */  addiu      $5, $0, 0x7F
    /* 1CBB38 002CBB38 2B000624 */  addiu      $6, $0, 0x2B
    /* 1CBB3C 002CBB3C 62004790 */  lbu        $7, 0x62($2)
    /* 1CBB40 002CBB40 8CCA0A0C */  jal        func_002b2a30
    /* 1CBB44 002CBB44 00000000 */   nop
    /* 1CBB48 002CBB48 2D984000 */  daddu      $19, $2, $0
    /* 1CBB4C 002CBB4C 2D200000 */  daddu      $4, $0, $0
    /* 1CBB50 002CBB50 A6000524 */  addiu      $5, $0, 0xA6
    /* 1CBB54 002CBB54 7F000624 */  addiu      $6, $0, 0x7F
    /* 1CBB58 002CBB58 2B000724 */  addiu      $7, $0, 0x2B
    /* 1CBB5C 002CBB5C 8CCA0A0C */  jal        func_002b2a30
    /* 1CBB60 002CBB60 00000000 */   nop
    /* 1CBB64 002CBB64 2D904000 */  daddu      $18, $2, $0
    /* 1CBB68 002CBB68 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBB6C 002CBB6C 38810B0C */  jal        func_002e04e0
    /* 1CBB70 002CBB70 00000000 */   nop
    /* 1CBB74 002CBB74 2C02A427 */  addiu      $4, $29, 0x22C
    /* 1CBB78 002CBB78 A6000524 */  addiu      $5, $0, 0xA6
    /* 1CBB7C 002CBB7C 7F000624 */  addiu      $6, $0, 0x7F
    /* 1CBB80 002CBB80 2B000724 */  addiu      $7, $0, 0x2B
    /* 1CBB84 002CBB84 62004890 */  lbu        $8, 0x62($2)
    /* 1CBB88 002CBB88 98CA0A0C */  jal        func_002b2a60
    /* 1CBB8C 002CBB8C 00000000 */   nop
    /* 1CBB90 002CBB90 2D202002 */  daddu      $4, $17, $0
    /* 1CBB94 002CBB94 D0890B0C */  jal        func_002e2740
    /* 1CBB98 002CBB98 00000000 */   nop
    /* 1CBB9C 002CBB9C 2D204000 */  daddu      $4, $2, $0
    /* 1CBBA0 002CBBA0 0C42040C */  jal        func_00110830
    /* 1CBBA4 002CBBA4 00000000 */   nop
    /* 1CBBA8 002CBBA8 FF004230 */  andi       $2, $2, 0xFF
    /* 1CBBAC 002CBBAC 01004230 */  andi       $2, $2, 0x1
    /* 1CBBB0 002CBBB0 1C004010 */  beqz       $2, .L002CBC24
    /* 1CBBB4 002CBBB4 00000000 */   nop
    /* 1CBBB8 002CBBB8 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBBBC 002CBBBC 38810B0C */  jal        func_002e04e0
    /* 1CBBC0 002CBBC0 00000000 */   nop
    /* 1CBBC4 002CBBC4 A8000424 */  addiu      $4, $0, 0xA8
    /* 1CBBC8 002CBBC8 9C000524 */  addiu      $5, $0, 0x9C
    /* 1CBBCC 002CBBCC 4C000624 */  addiu      $6, $0, 0x4C
    /* 1CBBD0 002CBBD0 62004790 */  lbu        $7, 0x62($2)
    /* 1CBBD4 002CBBD4 8CCA0A0C */  jal        func_002b2a30
    /* 1CBBD8 002CBBD8 00000000 */   nop
    /* 1CBBDC 002CBBDC 2D984000 */  daddu      $19, $2, $0
    /* 1CBBE0 002CBBE0 2D200000 */  daddu      $4, $0, $0
    /* 1CBBE4 002CBBE4 A8000524 */  addiu      $5, $0, 0xA8
    /* 1CBBE8 002CBBE8 9C000624 */  addiu      $6, $0, 0x9C
    /* 1CBBEC 002CBBEC 4C000724 */  addiu      $7, $0, 0x4C
    /* 1CBBF0 002CBBF0 8CCA0A0C */  jal        func_002b2a30
    /* 1CBBF4 002CBBF4 00000000 */   nop
    /* 1CBBF8 002CBBF8 2D904000 */  daddu      $18, $2, $0
    /* 1CBBFC 002CBBFC 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBC00 002CBC00 38810B0C */  jal        func_002e04e0
    /* 1CBC04 002CBC04 00000000 */   nop
    /* 1CBC08 002CBC08 2C02A427 */  addiu      $4, $29, 0x22C
    /* 1CBC0C 002CBC0C A8000524 */  addiu      $5, $0, 0xA8
    /* 1CBC10 002CBC10 9C000624 */  addiu      $6, $0, 0x9C
    /* 1CBC14 002CBC14 4C000724 */  addiu      $7, $0, 0x4C
    /* 1CBC18 002CBC18 62004890 */  lbu        $8, 0x62($2)
    /* 1CBC1C 002CBC1C 98CA0A0C */  jal        func_002b2a60
    /* 1CBC20 002CBC20 00000000 */   nop
  .L002CBC24:
    /* 1CBC24 002CBC24 02000286 */  lh         $2, 0x2($16)
    /* 1CBC28 002CBC28 63002216 */  bne        $17, $2, .L002CBDB8
    /* 1CBC2C 002CBC2C 00000000 */   nop
    /* 1CBC30 002CBC30 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBC34 002CBC34 38810B0C */  jal        func_002e04e0
    /* 1CBC38 002CBC38 00000000 */   nop
    /* 1CBC3C 002CBC3C 9E000424 */  addiu      $4, $0, 0x9E
    /* 1CBC40 002CBC40 73000524 */  addiu      $5, $0, 0x73
    /* 1CBC44 002CBC44 1D000624 */  addiu      $6, $0, 0x1D
    /* 1CBC48 002CBC48 62004790 */  lbu        $7, 0x62($2)
    /* 1CBC4C 002CBC4C 8CCA0A0C */  jal        func_002b2a30
    /* 1CBC50 002CBC50 00000000 */   nop
    /* 1CBC54 002CBC54 2D984000 */  daddu      $19, $2, $0
    /* 1CBC58 002CBC58 2D200000 */  daddu      $4, $0, $0
    /* 1CBC5C 002CBC5C 9E000524 */  addiu      $5, $0, 0x9E
    /* 1CBC60 002CBC60 73000624 */  addiu      $6, $0, 0x73
    /* 1CBC64 002CBC64 1D000724 */  addiu      $7, $0, 0x1D
    /* 1CBC68 002CBC68 8CCA0A0C */  jal        func_002b2a30
    /* 1CBC6C 002CBC6C 00000000 */   nop
    /* 1CBC70 002CBC70 2D904000 */  daddu      $18, $2, $0
    /* 1CBC74 002CBC74 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBC78 002CBC78 38810B0C */  jal        func_002e04e0
    /* 1CBC7C 002CBC7C 00000000 */   nop
    /* 1CBC80 002CBC80 2C02A427 */  addiu      $4, $29, 0x22C
    /* 1CBC84 002CBC84 9E000524 */  addiu      $5, $0, 0x9E
    /* 1CBC88 002CBC88 73000624 */  addiu      $6, $0, 0x73
    /* 1CBC8C 002CBC8C 1D000724 */  addiu      $7, $0, 0x1D
    /* 1CBC90 002CBC90 62004890 */  lbu        $8, 0x62($2)
    /* 1CBC94 002CBC94 98CA0A0C */  jal        func_002b2a60
    /* 1CBC98 002CBC98 00000000 */   nop
    /* 1CBC9C 002CBC9C 46000010 */  b          .L002CBDB8
    /* 1CBCA0 002CBCA0 00000000 */   nop
  .L002CBCA4:
    /* 1CBCA4 002CBCA4 02000286 */  lh         $2, 0x2($16)
    /* 1CBCA8 002CBCA8 1E002216 */  bne        $17, $2, .L002CBD24
    /* 1CBCAC 002CBCAC 00000000 */   nop
    /* 1CBCB0 002CBCB0 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBCB4 002CBCB4 38810B0C */  jal        func_002e04e0
    /* 1CBCB8 002CBCB8 00000000 */   nop
    /* 1CBCBC 002CBCBC 2D000424 */  addiu      $4, $0, 0x2D
    /* 1CBCC0 002CBCC0 2D288000 */  daddu      $5, $4, $0
    /* 1CBCC4 002CBCC4 2D308000 */  daddu      $6, $4, $0
    /* 1CBCC8 002CBCC8 62004790 */  lbu        $7, 0x62($2)
    /* 1CBCCC 002CBCCC 8CCA0A0C */  jal        func_002b2a30
    /* 1CBCD0 002CBCD0 00000000 */   nop
    /* 1CBCD4 002CBCD4 2D984000 */  daddu      $19, $2, $0
    /* 1CBCD8 002CBCD8 2D200000 */  daddu      $4, $0, $0
    /* 1CBCDC 002CBCDC 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CBCE0 002CBCE0 2D30A000 */  daddu      $6, $5, $0
    /* 1CBCE4 002CBCE4 2D38A000 */  daddu      $7, $5, $0
    /* 1CBCE8 002CBCE8 8CCA0A0C */  jal        func_002b2a30
    /* 1CBCEC 002CBCEC 00000000 */   nop
    /* 1CBCF0 002CBCF0 2D904000 */  daddu      $18, $2, $0
    /* 1CBCF4 002CBCF4 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBCF8 002CBCF8 38810B0C */  jal        func_002e04e0
    /* 1CBCFC 002CBCFC 00000000 */   nop
    /* 1CBD00 002CBD00 2C02A427 */  addiu      $4, $29, 0x22C
    /* 1CBD04 002CBD04 2D000524 */  addiu      $5, $0, 0x2D
    /* 1CBD08 002CBD08 2D30A000 */  daddu      $6, $5, $0
    /* 1CBD0C 002CBD0C 2D38A000 */  daddu      $7, $5, $0
    /* 1CBD10 002CBD10 62004890 */  lbu        $8, 0x62($2)
    /* 1CBD14 002CBD14 98CA0A0C */  jal        func_002b2a60
    /* 1CBD18 002CBD18 00000000 */   nop
    /* 1CBD1C 002CBD1C 26000010 */  b          .L002CBDB8
    /* 1CBD20 002CBD20 00000000 */   nop
  .L002CBD24:
    /* 1CBD24 002CBD24 2D202002 */  daddu      $4, $17, $0
    /* 1CBD28 002CBD28 D0890B0C */  jal        func_002e2740
    /* 1CBD2C 002CBD2C 00000000 */   nop
    /* 1CBD30 002CBD30 2D204000 */  daddu      $4, $2, $0
    /* 1CBD34 002CBD34 0C42040C */  jal        func_00110830
    /* 1CBD38 002CBD38 00000000 */   nop
    /* 1CBD3C 002CBD3C FF004230 */  andi       $2, $2, 0xFF
    /* 1CBD40 002CBD40 01004230 */  andi       $2, $2, 0x1
    /* 1CBD44 002CBD44 1C004010 */  beqz       $2, .L002CBDB8
    /* 1CBD48 002CBD48 00000000 */   nop
    /* 1CBD4C 002CBD4C 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBD50 002CBD50 38810B0C */  jal        func_002e04e0
    /* 1CBD54 002CBD54 00000000 */   nop
    /* 1CBD58 002CBD58 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CBD5C 002CBD5C EF000524 */  addiu      $5, $0, 0xEF
    /* 1CBD60 002CBD60 81000624 */  addiu      $6, $0, 0x81
    /* 1CBD64 002CBD64 62004790 */  lbu        $7, 0x62($2)
    /* 1CBD68 002CBD68 8CCA0A0C */  jal        func_002b2a30
    /* 1CBD6C 002CBD6C 00000000 */   nop
    /* 1CBD70 002CBD70 2D984000 */  daddu      $19, $2, $0
    /* 1CBD74 002CBD74 2D200000 */  daddu      $4, $0, $0
    /* 1CBD78 002CBD78 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CBD7C 002CBD7C EF000624 */  addiu      $6, $0, 0xEF
    /* 1CBD80 002CBD80 81000724 */  addiu      $7, $0, 0x81
    /* 1CBD84 002CBD84 8CCA0A0C */  jal        func_002b2a30
    /* 1CBD88 002CBD88 00000000 */   nop
    /* 1CBD8C 002CBD8C 2D904000 */  daddu      $18, $2, $0
    /* 1CBD90 002CBD90 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBD94 002CBD94 38810B0C */  jal        func_002e04e0
    /* 1CBD98 002CBD98 00000000 */   nop
    /* 1CBD9C 002CBD9C 2C02A427 */  addiu      $4, $29, 0x22C
    /* 1CBDA0 002CBDA0 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CBDA4 002CBDA4 EF000624 */  addiu      $6, $0, 0xEF
    /* 1CBDA8 002CBDA8 81000724 */  addiu      $7, $0, 0x81
    /* 1CBDAC 002CBDAC 62004890 */  lbu        $8, 0x62($2)
    /* 1CBDB0 002CBDB0 98CA0A0C */  jal        func_002b2a60
    /* 1CBDB4 002CBDB4 00000000 */   nop
  .L002CBDB8:
    /* 1CBDB8 002CBDB8 2D202002 */  daddu      $4, $17, $0
    /* 1CBDBC 002CBDBC D0890B0C */  jal        func_002e2740
    /* 1CBDC0 002CBDC0 00000000 */   nop
    /* 1CBDC4 002CBDC4 2D204000 */  daddu      $4, $2, $0
    /* 1CBDC8 002CBDC8 0C42040C */  jal        func_00110830
    /* 1CBDCC 002CBDCC 00000000 */   nop
    /* 1CBDD0 002CBDD0 FF004230 */  andi       $2, $2, 0xFF
    /* 1CBDD4 002CBDD4 01004230 */  andi       $2, $2, 0x1
    /* 1CBDD8 002CBDD8 22004010 */  beqz       $2, .L002CBE64
    /* 1CBDDC 002CBDDC 00000000 */   nop
    /* 1CBDE0 002CBDE0 3C141600 */  dsll32     $2, $22, 16
    /* 1CBDE4 002CBDE4 3F140200 */  dsra32     $2, $2, 16
    /* 1CBDE8 002CBDE8 40110200 */  sll        $2, $2, 5
    /* 1CBDEC 002CBDEC 7A004224 */  addiu      $2, $2, 0x7A
    /* 1CBDF0 002CBDF0 00008244 */  mtc1       $2, $f0
    /* 1CBDF4 002CBDF4 00000000 */  nop
    /* 1CBDF8 002CBDF8 60038046 */  cvt.s.w    $f13, $f0
    /* 1CBDFC 002CBDFC B642023C */  lui        $2, (0x42B60000 >> 16)
    /* 1CBE00 002CBE00 00608244 */  mtc1       $2, $f12
    /* 1CBE04 002CBE04 D801A427 */  addiu      $4, $29, 0x1D8
    /* 1CBE08 002CBE08 5CCA0A0C */  jal        func_002b2970
    /* 1CBE0C 002CBE0C 00000000 */   nop
    /* 1CBE10 002CBE10 2D200000 */  daddu      $4, $0, $0
    /* 1CBE14 002CBE14 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CBE18 002CBE18 66000624 */  addiu      $6, $0, 0x66
    /* 1CBE1C 002CBE1C 2D380000 */  daddu      $7, $0, $0
    /* 1CBE20 002CBE20 8CCA0A0C */  jal        func_002b2a30
    /* 1CBE24 002CBE24 00000000 */   nop
    /* 1CBE28 002CBE28 2D884000 */  daddu      $17, $2, $0
    /* 1CBE2C 002CBE2C 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBE30 002CBE30 38810B0C */  jal        func_002e04e0
    /* 1CBE34 002CBE34 00000000 */   nop
    /* 1CBE38 002CBE38 8242033C */  lui        $3, (0x42820000 >> 16)
    /* 1CBE3C 002CBE3C 00608344 */  mtc1       $3, $f12
    /* 1CBE40 002CBE40 49000424 */  addiu      $4, $0, 0x49
    /* 1CBE44 002CBE44 D801A5DF */  ld         $5, 0x1D8($29)
    /* 1CBE48 002CBE48 2D302002 */  daddu      $6, $17, $0
    /* 1CBE4C 002CBE4C 62004790 */  lbu        $7, 0x62($2)
    /* 1CBE50 002CBE50 2D400000 */  daddu      $8, $0, $0
    /* 1CBE54 002CBE54 7900093C */  lui        $9, %hi(D_00794EA0)
    /* 1CBE58 002CBE58 A04E2925 */  addiu      $9, $9, %lo(D_00794EA0)
    /* 1CBE5C 002CBE5C F8820B0C */  jal        func_002e0be0
    /* 1CBE60 002CBE60 00000000 */   nop
  .L002CBE64:
    /* 1CBE64 002CBE64 3C141600 */  dsll32     $2, $22, 16
    /* 1CBE68 002CBE68 3F140200 */  dsra32     $2, $2, 16
    /* 1CBE6C 002CBE6C 40890200 */  sll        $17, $2, 5
    /* 1CBE70 002CBE70 85002226 */  addiu      $2, $17, 0x85
    /* 1CBE74 002CBE74 00008244 */  mtc1       $2, $f0
    /* 1CBE78 002CBE78 00000000 */  nop
    /* 1CBE7C 002CBE7C 60038046 */  cvt.s.w    $f13, $f0
    /* 1CBE80 002CBE80 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1CBE84 002CBE84 00608244 */  mtc1       $2, $f12
    /* 1CBE88 002CBE88 D001A427 */  addiu      $4, $29, 0x1D0
    /* 1CBE8C 002CBE8C 5CCA0A0C */  jal        func_002b2970
    /* 1CBE90 002CBE90 00000000 */   nop
    /* 1CBE94 002CBE94 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CBE98 002CBE98 38810B0C */  jal        func_002e04e0
    /* 1CBE9C 002CBE9C 00000000 */   nop
    /* 1CBEA0 002CBEA0 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1CBEA4 002CBEA4 00608344 */  mtc1       $3, $f12
    /* 1CBEA8 002CBEA8 2D20E002 */  daddu      $4, $23, $0
    /* 1CBEAC 002CBEAC D001A5DF */  ld         $5, 0x1D0($29)
    /* 1CBEB0 002CBEB0 2D304002 */  daddu      $6, $18, $0
    /* 1CBEB4 002CBEB4 62004790 */  lbu        $7, 0x62($2)
    /* 1CBEB8 002CBEB8 2D400000 */  daddu      $8, $0, $0
    /* 1CBEBC 002CBEBC 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1CBEC0 002CBEC0 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1CBEC4 002CBEC4 C8820B0C */  jal        func_002e0b20
    /* 1CBEC8 002CBEC8 00000000 */   nop
    /* 1CBECC 002CBECC 0443023C */  lui        $2, (0x43040000 >> 16)
    /* 1CBED0 002CBED0 00088244 */  mtc1       $2, $f1
    /* 1CBED4 002CBED4 00009144 */  mtc1       $17, $f0
    /* 1CBED8 002CBED8 00000000 */  nop
    /* 1CBEDC 002CBEDC 20008046 */  cvt.s.w    $f0, $f0
    /* 1CBEE0 002CBEE0 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CBEE4 002CBEE4 3D43023C */  lui        $2, (0x433D0000 >> 16)
    /* 1CBEE8 002CBEE8 00608244 */  mtc1       $2, $f12
    /* 1CBEEC 002CBEEC C801A427 */  addiu      $4, $29, 0x1C8
    /* 1CBEF0 002CBEF0 5CCA0A0C */  jal        func_002b2970
    /* 1CBEF4 002CBEF4 00000000 */   nop
    /* 1CBEF8 002CBEF8 C801A1C7 */  lwc1       $f1, 0x1C8($29)
    /* 1CBEFC 002CBEFC CC01A0C7 */  lwc1       $f0, 0x1CC($29)
    /* 1CBF00 002CBF00 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* 1CBF04 002CBF04 DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* 1CBF08 002CBF08 3C941400 */  dsll32     $18, $20, 16
    /* 1CBF0C 002CBF0C 3F941200 */  dsra32     $18, $18, 16
    /* 1CBF10 002CBF10 2D204002 */  daddu      $4, $18, $0
    /* 1CBF14 002CBF14 D0890B0C */  jal        func_002e2740
    /* 1CBF18 002CBF18 00000000 */   nop
    /* 1CBF1C 002CBF1C 3C240200 */  dsll32     $4, $2, 16
    /* 1CBF20 002CBF20 3F240400 */  dsra32     $4, $4, 16
    /* 1CBF24 002CBF24 FC19040C */  jal        func_001067f0
    /* 1CBF28 002CBF28 00000000 */   nop
    /* 1CBF2C 002CBF2C 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1CBF30 002CBF30 00708344 */  mtc1       $3, $f14
    /* 1CBF34 002CBF34 D800ACC7 */  lwc1       $f12, 0xD8($29)
    /* 1CBF38 002CBF38 DC00ADC7 */  lwc1       $f13, 0xDC($29)
    /* 1CBF3C 002CBF3C 2D206002 */  daddu      $4, $19, $0
    /* 1CBF40 002CBF40 2D280000 */  daddu      $5, $0, $0
    /* 1CBF44 002CBF44 01000624 */  addiu      $6, $0, 0x1
    /* 1CBF48 002CBF48 2D384000 */  daddu      $7, $2, $0
    /* 1CBF4C 002CBF4C 2D400000 */  daddu      $8, $0, $0
    /* 1CBF50 002CBF50 2D480000 */  daddu      $9, $0, $0
    /* 1CBF54 002CBF54 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1CBF58 002CBF58 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1CBF5C 002CBF5C FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1CBF60 002CBF60 A0D5090C */  jal        func_00275680
    /* 1CBF64 002CBF64 00000000 */   nop
    /* 1CBF68 002CBF68 0E43023C */  lui        $2, (0x430E0000 >> 16)
    /* 1CBF6C 002CBF6C 00088244 */  mtc1       $2, $f1
    /* 1CBF70 002CBF70 00009144 */  mtc1       $17, $f0
    /* 1CBF74 002CBF74 00000000 */  nop
    /* 1CBF78 002CBF78 20008046 */  cvt.s.w    $f0, $f0
    /* 1CBF7C 002CBF7C 400B0046 */  add.s      $f13, $f1, $f0
    /* 1CBF80 002CBF80 F943023C */  lui        $2, (0x43F90000 >> 16)
    /* 1CBF84 002CBF84 00608244 */  mtc1       $2, $f12
    /* 1CBF88 002CBF88 C001A427 */  addiu      $4, $29, 0x1C0
    /* 1CBF8C 002CBF8C 5CCA0A0C */  jal        func_002b2970
    /* 1CBF90 002CBF90 00000000 */   nop
    /* 1CBF94 002CBF94 2D204002 */  daddu      $4, $18, $0
    /* 1CBF98 002CBF98 D0890B0C */  jal        func_002e2740
    /* 1CBF9C 002CBF9C 00000000 */   nop
    /* 1CBFA0 002CBFA0 3C240200 */  dsll32     $4, $2, 16
    /* 1CBFA4 002CBFA4 3F240400 */  dsra32     $4, $4, 16
    /* 1CBFA8 002CBFA8 A41A040C */  jal        func_00106a90
    /* 1CBFAC 002CBFAC 00000000 */   nop
    /* 1CBFB0 002CBFB0 2D884000 */  daddu      $17, $2, $0
    /* 1CBFB4 002CBFB4 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1CBFB8 002CBFB8 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1CBFBC 002CBFBC DCA9110C */  jal        func_0046a770
    /* 1CBFC0 002CBFC0 00000000 */   nop
    /* 1CBFC4 002CBFC4 280F038E */  lw         $3, 0xF28($16)
    /* 1CBFC8 002CBFC8 0000A3FF */  sd         $3, 0x0($29)
    /* 1CBFCC 002CBFCC A9000324 */  addiu      $3, $0, 0xA9
    /* 1CBFD0 002CBFD0 0800A3FF */  sd         $3, 0x8($29)
    /* 1CBFD4 002CBFD4 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1CBFD8 002CBFD8 00608344 */  mtc1       $3, $f12
    /* 1CBFDC 002CBFDC C001A4DF */  ld         $4, 0x1C0($29)
    /* 1CBFE0 002CBFE0 2C02A58F */  lw         $5, 0x22C($29)
    /* 1CBFE4 002CBFE4 10000624 */  addiu      $6, $0, 0x10
    /* 1CBFE8 002CBFE8 05000724 */  addiu      $7, $0, 0x5
    /* 1CBFEC 002CBFEC 2D402002 */  daddu      $8, $17, $0
    /* 1CBFF0 002CBFF0 09000924 */  addiu      $9, $0, 0x9
    /* 1CBFF4 002CBFF4 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1CBFF8 002CBFF8 2D584000 */  daddu      $11, $2, $0
    /* 1CBFFC 002CBFFC 342B0B0C */  jal        func_002cacd0
    /* 1CC000 002CC000 00000000 */   nop
  .L002CC004:
    /* 1CC004 002CC004 01008326 */  addiu      $3, $20, 0x1
    /* 1CC008 002CC008 3CA40300 */  dsll32     $20, $3, 16
    /* 1CC00C 002CC00C 3FA41400 */  dsra32     $20, $20, 16
    /* 1CC010 002CC010 0100C326 */  addiu      $3, $22, 0x1
    /* 1CC014 002CC014 3CB40300 */  dsll32     $22, $3, 16
    /* 1CC018 002CC018 3FB41600 */  dsra32     $22, $22, 16
  .L002CC01C:
    /* 1CC01C 002CC01C 3C8C1400 */  dsll32     $17, $20, 16
    /* 1CC020 002CC020 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CC024 002CC024 C000A37B */  lq         $3, 0xC0($29)
    /* 1CC028 002CC028 2A182302 */  slt        $3, $17, $3
    /* 1CC02C 002CC02C 85FE6014 */  bnez       $3, .L002CBA44
    /* 1CC030 002CC030 00000000 */   nop
    /* 1CC034 002CC034 D700A383 */  lb         $3, 0xD7($29)
    /* 1CC038 002CC038 2D206000 */  daddu      $4, $3, $0
    /* 1CC03C 002CC03C 01000324 */  addiu      $3, $0, 0x1
    /* 1CC040 002CC040 BE078310 */  beq        $4, $3, .L002CDF3C
    /* 1CC044 002CC044 00000000 */   nop
    /* 1CC048 002CC048 8C00033C */  lui        $3, %hi(D_008C0276)
    /* 1CC04C 002CC04C 76026594 */  lhu        $5, %lo(D_008C0276)($3)
    /* 1CC050 002CC050 0010A330 */  andi       $3, $5, 0x1000
    /* 1CC054 002CC054 34006010 */  beqz       $3, .L002CC128
    /* 1CC058 002CC058 00000000 */   nop
    /* 1CC05C 002CC05C 14000382 */  lb         $3, 0x14($16)
    /* 1CC060 002CC060 31006014 */  bnez       $3, .L002CC128
    /* 1CC064 002CC064 00000000 */   nop
    /* 1CC068 002CC068 2D200000 */  daddu      $4, $0, $0
    /* 1CC06C 002CC06C 2D280000 */  daddu      $5, $0, $0
    /* 1CC070 002CC070 2D300000 */  daddu      $6, $0, $0
    /* 1CC074 002CC074 2D380000 */  daddu      $7, $0, $0
    /* 1CC078 002CC078 D86B110C */  jal        func_0045af60
    /* 1CC07C 002CC07C 00000000 */   nop
    /* 1CC080 002CC080 02000286 */  lh         $2, 0x2($16)
    /* 1CC084 002CC084 0F004014 */  bnez       $2, .L002CC0C4
    /* 1CC088 002CC088 00000000 */   nop
    /* 1CC08C 002CC08C A8890B0C */  jal        func_002e26a0
    /* 1CC090 002CC090 00000000 */   nop
    /* 1CC094 002CC094 020002A6 */  sh         $2, 0x2($16)
    /* 1CC098 002CC098 3C2C0200 */  dsll32     $5, $2, 16
    /* 1CC09C 002CC09C 3F2C0500 */  dsra32     $5, $5, 16
    /* 1CC0A0 002CC0A0 2D200000 */  daddu      $4, $0, $0
    /* 1CC0A4 002CC0A4 04000624 */  addiu      $6, $0, 0x4
    /* 1CC0A8 002CC0A8 2D380000 */  daddu      $7, $0, $0
    /* 1CC0AC 002CC0AC 01000824 */  addiu      $8, $0, 0x1
    /* 1CC0B0 002CC0B0 2CCB0A0C */  jal        func_002b2cb0
    /* 1CC0B4 002CC0B4 00000000 */   nop
    /* 1CC0B8 002CC0B8 040002A6 */  sh         $2, 0x4($16)
    /* 1CC0BC 002CC0BC 16000010 */  b          .L002CC118
    /* 1CC0C0 002CC0C0 00000000 */   nop
  .L002CC0C4:
    /* 1CC0C4 002CC0C4 9C890B0C */  jal        func_002e2670
    /* 1CC0C8 002CC0C8 00000000 */   nop
    /* 1CC0CC 002CC0CC 02000486 */  lh         $4, 0x2($16)
    /* 1CC0D0 002CC0D0 01000524 */  addiu      $5, $0, 0x1
    /* 1CC0D4 002CC0D4 2D300000 */  daddu      $6, $0, $0
    /* 1CC0D8 002CC0D8 2D384000 */  daddu      $7, $2, $0
    /* 1CC0DC 002CC0DC 02000824 */  addiu      $8, $0, 0x2
    /* 1CC0E0 002CC0E0 40CB0A0C */  jal        func_002b2d00
    /* 1CC0E4 002CC0E4 00000000 */   nop
    /* 1CC0E8 002CC0E8 020002A6 */  sh         $2, 0x2($16)
    /* 1CC0EC 002CC0EC 9C890B0C */  jal        func_002e2670
    /* 1CC0F0 002CC0F0 00000000 */   nop
    /* 1CC0F4 002CC0F4 3C340200 */  dsll32     $6, $2, 16
    /* 1CC0F8 002CC0F8 3F340600 */  dsra32     $6, $6, 16
    /* 1CC0FC 002CC0FC 02000486 */  lh         $4, 0x2($16)
    /* 1CC100 002CC100 04000586 */  lh         $5, 0x4($16)
    /* 1CC104 002CC104 05000724 */  addiu      $7, $0, 0x5
    /* 1CC108 002CC108 FFFF0824 */  addiu      $8, $0, -0x1
    /* 1CC10C 002CC10C 54CB0A0C */  jal        func_002b2d50
    /* 1CC110 002CC110 00000000 */   nop
    /* 1CC114 002CC114 040002A6 */  sh         $2, 0x4($16)
  .L002CC118:
    /* 1CC118 002CC118 01000324 */  addiu      $3, $0, 0x1
    /* 1CC11C 002CC11C 140003A2 */  sb         $3, 0x14($16)
    /* 1CC120 002CC120 86070010 */  b          .L002CDF3C
    /* 1CC124 002CC124 00000000 */   nop
  .L002CC128:
    /* 1CC128 002CC128 8C00033C */  lui        $3, %hi(D_008C027A)
    /* 1CC12C 002CC12C 7A026494 */  lhu        $4, %lo(D_008C027A)($3)
    /* 1CC130 002CC130 00108330 */  andi       $3, $4, 0x1000
    /* 1CC134 002CC134 25006010 */  beqz       $3, .L002CC1CC
    /* 1CC138 002CC138 00000000 */   nop
    /* 1CC13C 002CC13C 9C890B0C */  jal        func_002e2670
    /* 1CC140 002CC140 00000000 */   nop
    /* 1CC144 002CC144 7C074018 */  blez       $2, .L002CDF38
    /* 1CC148 002CC148 00000000 */   nop
    /* 1CC14C 002CC14C 02000286 */  lh         $2, 0x2($16)
    /* 1CC150 002CC150 07004010 */  beqz       $2, .L002CC170
    /* 1CC154 002CC154 00000000 */   nop
    /* 1CC158 002CC158 2D200000 */  daddu      $4, $0, $0
    /* 1CC15C 002CC15C 2D280000 */  daddu      $5, $0, $0
    /* 1CC160 002CC160 2D300000 */  daddu      $6, $0, $0
    /* 1CC164 002CC164 2D380000 */  daddu      $7, $0, $0
    /* 1CC168 002CC168 D86B110C */  jal        func_0045af60
    /* 1CC16C 002CC16C 00000000 */   nop
  .L002CC170:
    /* 1CC170 002CC170 02000486 */  lh         $4, 0x2($16)
    /* 1CC174 002CC174 01000524 */  addiu      $5, $0, 0x1
    /* 1CC178 002CC178 2D300000 */  daddu      $6, $0, $0
    /* 1CC17C 002CC17C 2D380000 */  daddu      $7, $0, $0
    /* 1CC180 002CC180 2D40A000 */  daddu      $8, $5, $0
    /* 1CC184 002CC184 40CB0A0C */  jal        func_002b2d00
    /* 1CC188 002CC188 00000000 */   nop
    /* 1CC18C 002CC18C 020002A6 */  sh         $2, 0x2($16)
    /* 1CC190 002CC190 9C890B0C */  jal        func_002e2670
    /* 1CC194 002CC194 00000000 */   nop
    /* 1CC198 002CC198 3C340200 */  dsll32     $6, $2, 16
    /* 1CC19C 002CC19C 3F340600 */  dsra32     $6, $6, 16
    /* 1CC1A0 002CC1A0 02000486 */  lh         $4, 0x2($16)
    /* 1CC1A4 002CC1A4 04000586 */  lh         $5, 0x4($16)
    /* 1CC1A8 002CC1A8 05000724 */  addiu      $7, $0, 0x5
    /* 1CC1AC 002CC1AC FFFF0824 */  addiu      $8, $0, -0x1
    /* 1CC1B0 002CC1B0 54CB0A0C */  jal        func_002b2d50
    /* 1CC1B4 002CC1B4 00000000 */   nop
    /* 1CC1B8 002CC1B8 040002A6 */  sh         $2, 0x4($16)
    /* 1CC1BC 002CC1BC 01000324 */  addiu      $3, $0, 0x1
    /* 1CC1C0 002CC1C0 140003A2 */  sb         $3, 0x14($16)
    /* 1CC1C4 002CC1C4 5D070010 */  b          .L002CDF3C
    /* 1CC1C8 002CC1C8 00000000 */   nop
  .L002CC1CC:
    /* 1CC1CC 002CC1CC 0040A330 */  andi       $3, $5, 0x4000
    /* 1CC1D0 002CC1D0 40006010 */  beqz       $3, .L002CC2D4
    /* 1CC1D4 002CC1D4 00000000 */   nop
    /* 1CC1D8 002CC1D8 14000382 */  lb         $3, 0x14($16)
    /* 1CC1DC 002CC1DC 3D006014 */  bnez       $3, .L002CC2D4
    /* 1CC1E0 002CC1E0 00000000 */   nop
    /* 1CC1E4 002CC1E4 2D200000 */  daddu      $4, $0, $0
    /* 1CC1E8 002CC1E8 2D280000 */  daddu      $5, $0, $0
    /* 1CC1EC 002CC1EC 2D300000 */  daddu      $6, $0, $0
    /* 1CC1F0 002CC1F0 2D380000 */  daddu      $7, $0, $0
    /* 1CC1F4 002CC1F4 D86B110C */  jal        func_0045af60
    /* 1CC1F8 002CC1F8 00000000 */   nop
    /* 1CC1FC 002CC1FC A8890B0C */  jal        func_002e26a0
    /* 1CC200 002CC200 00000000 */   nop
    /* 1CC204 002CC204 02000486 */  lh         $4, 0x2($16)
    /* 1CC208 002CC208 01000524 */  addiu      $5, $0, 0x1
    /* 1CC20C 002CC20C 2D304000 */  daddu      $6, $2, $0
    /* 1CC210 002CC210 2D380000 */  daddu      $7, $0, $0
    /* 1CC214 002CC214 02000824 */  addiu      $8, $0, 0x2
    /* 1CC218 002CC218 2CCB0A0C */  jal        func_002b2cb0
    /* 1CC21C 002CC21C 00000000 */   nop
    /* 1CC220 002CC220 020002A6 */  sh         $2, 0x2($16)
    /* 1CC224 002CC224 3C1C0200 */  dsll32     $3, $2, 16
    /* 1CC228 002CC228 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CC22C 002CC22C 04006014 */  bnez       $3, .L002CC240
    /* 1CC230 002CC230 00000000 */   nop
    /* 1CC234 002CC234 040000A6 */  sh         $0, 0x4($16)
    /* 1CC238 002CC238 22000010 */  b          .L002CC2C4
    /* 1CC23C 002CC23C 00000000 */   nop
  .L002CC240:
    /* 1CC240 002CC240 A8890B0C */  jal        func_002e26a0
    /* 1CC244 002CC244 00000000 */   nop
    /* 1CC248 002CC248 05004228 */  slti       $2, $2, 0x5
    /* 1CC24C 002CC24C 0E004014 */  bnez       $2, .L002CC288
    /* 1CC250 002CC250 00000000 */   nop
    /* 1CC254 002CC254 A8890B0C */  jal        func_002e26a0
    /* 1CC258 002CC258 00000000 */   nop
    /* 1CC25C 002CC25C 3C340200 */  dsll32     $6, $2, 16
    /* 1CC260 002CC260 3F340600 */  dsra32     $6, $6, 16
    /* 1CC264 002CC264 02000486 */  lh         $4, 0x2($16)
    /* 1CC268 002CC268 04000586 */  lh         $5, 0x4($16)
    /* 1CC26C 002CC26C 05000724 */  addiu      $7, $0, 0x5
    /* 1CC270 002CC270 01000824 */  addiu      $8, $0, 0x1
    /* 1CC274 002CC274 54CB0A0C */  jal        func_002b2d50
    /* 1CC278 002CC278 00000000 */   nop
    /* 1CC27C 002CC27C 040002A6 */  sh         $2, 0x4($16)
    /* 1CC280 002CC280 10000010 */  b          .L002CC2C4
    /* 1CC284 002CC284 00000000 */   nop
  .L002CC288:
    /* 1CC288 002CC288 A8890B0C */  jal        func_002e26a0
    /* 1CC28C 002CC28C 00000000 */   nop
    /* 1CC290 002CC290 3C8C0200 */  dsll32     $17, $2, 16
    /* 1CC294 002CC294 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CC298 002CC298 9C890B0C */  jal        func_002e2670
    /* 1CC29C 002CC29C 00000000 */   nop
    /* 1CC2A0 002CC2A0 3C3C0200 */  dsll32     $7, $2, 16
    /* 1CC2A4 002CC2A4 3F3C0700 */  dsra32     $7, $7, 16
    /* 1CC2A8 002CC2A8 02000486 */  lh         $4, 0x2($16)
    /* 1CC2AC 002CC2AC 04000586 */  lh         $5, 0x4($16)
    /* 1CC2B0 002CC2B0 2D302002 */  daddu      $6, $17, $0
    /* 1CC2B4 002CC2B4 01000824 */  addiu      $8, $0, 0x1
    /* 1CC2B8 002CC2B8 54CB0A0C */  jal        func_002b2d50
    /* 1CC2BC 002CC2BC 00000000 */   nop
    /* 1CC2C0 002CC2C0 040002A6 */  sh         $2, 0x4($16)
  .L002CC2C4:
    /* 1CC2C4 002CC2C4 01000324 */  addiu      $3, $0, 0x1
    /* 1CC2C8 002CC2C8 140003A2 */  sb         $3, 0x14($16)
    /* 1CC2CC 002CC2CC 1B070010 */  b          .L002CDF3C
    /* 1CC2D0 002CC2D0 00000000 */   nop
  .L002CC2D4:
    /* 1CC2D4 002CC2D4 00408330 */  andi       $3, $4, 0x4000
    /* 1CC2D8 002CC2D8 3F006010 */  beqz       $3, .L002CC3D8
    /* 1CC2DC 002CC2DC 00000000 */   nop
    /* 1CC2E0 002CC2E0 9C890B0C */  jal        func_002e2670
    /* 1CC2E4 002CC2E4 00000000 */   nop
    /* 1CC2E8 002CC2E8 13074018 */  blez       $2, .L002CDF38
    /* 1CC2EC 002CC2EC 00000000 */   nop
    /* 1CC2F0 002CC2F0 02001186 */  lh         $17, 0x2($16)
    /* 1CC2F4 002CC2F4 A8890B0C */  jal        func_002e26a0
    /* 1CC2F8 002CC2F8 00000000 */   nop
    /* 1CC2FC 002CC2FC 07002212 */  beq        $17, $2, .L002CC31C
    /* 1CC300 002CC300 00000000 */   nop
    /* 1CC304 002CC304 2D200000 */  daddu      $4, $0, $0
    /* 1CC308 002CC308 2D280000 */  daddu      $5, $0, $0
    /* 1CC30C 002CC30C 2D300000 */  daddu      $6, $0, $0
    /* 1CC310 002CC310 2D380000 */  daddu      $7, $0, $0
    /* 1CC314 002CC314 D86B110C */  jal        func_0045af60
    /* 1CC318 002CC318 00000000 */   nop
  .L002CC31C:
    /* 1CC31C 002CC31C A8890B0C */  jal        func_002e26a0
    /* 1CC320 002CC320 00000000 */   nop
    /* 1CC324 002CC324 02000486 */  lh         $4, 0x2($16)
    /* 1CC328 002CC328 01000524 */  addiu      $5, $0, 0x1
    /* 1CC32C 002CC32C 2D304000 */  daddu      $6, $2, $0
    /* 1CC330 002CC330 2D380000 */  daddu      $7, $0, $0
    /* 1CC334 002CC334 2D40A000 */  daddu      $8, $5, $0
    /* 1CC338 002CC338 2CCB0A0C */  jal        func_002b2cb0
    /* 1CC33C 002CC33C 00000000 */   nop
    /* 1CC340 002CC340 020002A6 */  sh         $2, 0x2($16)
    /* 1CC344 002CC344 A8890B0C */  jal        func_002e26a0
    /* 1CC348 002CC348 00000000 */   nop
    /* 1CC34C 002CC34C 05004228 */  slti       $2, $2, 0x5
    /* 1CC350 002CC350 0E004014 */  bnez       $2, .L002CC38C
    /* 1CC354 002CC354 00000000 */   nop
    /* 1CC358 002CC358 A8890B0C */  jal        func_002e26a0
    /* 1CC35C 002CC35C 00000000 */   nop
    /* 1CC360 002CC360 3C340200 */  dsll32     $6, $2, 16
    /* 1CC364 002CC364 3F340600 */  dsra32     $6, $6, 16
    /* 1CC368 002CC368 02000486 */  lh         $4, 0x2($16)
    /* 1CC36C 002CC36C 04000586 */  lh         $5, 0x4($16)
    /* 1CC370 002CC370 05000724 */  addiu      $7, $0, 0x5
    /* 1CC374 002CC374 01000824 */  addiu      $8, $0, 0x1
    /* 1CC378 002CC378 54CB0A0C */  jal        func_002b2d50
    /* 1CC37C 002CC37C 00000000 */   nop
    /* 1CC380 002CC380 040002A6 */  sh         $2, 0x4($16)
    /* 1CC384 002CC384 10000010 */  b          .L002CC3C8
    /* 1CC388 002CC388 00000000 */   nop
  .L002CC38C:
    /* 1CC38C 002CC38C A8890B0C */  jal        func_002e26a0
    /* 1CC390 002CC390 00000000 */   nop
    /* 1CC394 002CC394 3C8C0200 */  dsll32     $17, $2, 16
    /* 1CC398 002CC398 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CC39C 002CC39C 9C890B0C */  jal        func_002e2670
    /* 1CC3A0 002CC3A0 00000000 */   nop
    /* 1CC3A4 002CC3A4 3C3C0200 */  dsll32     $7, $2, 16
    /* 1CC3A8 002CC3A8 3F3C0700 */  dsra32     $7, $7, 16
    /* 1CC3AC 002CC3AC 02000486 */  lh         $4, 0x2($16)
    /* 1CC3B0 002CC3B0 04000586 */  lh         $5, 0x4($16)
    /* 1CC3B4 002CC3B4 2D302002 */  daddu      $6, $17, $0
    /* 1CC3B8 002CC3B8 01000824 */  addiu      $8, $0, 0x1
    /* 1CC3BC 002CC3BC 54CB0A0C */  jal        func_002b2d50
    /* 1CC3C0 002CC3C0 00000000 */   nop
    /* 1CC3C4 002CC3C4 040002A6 */  sh         $2, 0x4($16)
  .L002CC3C8:
    /* 1CC3C8 002CC3C8 01000324 */  addiu      $3, $0, 0x1
    /* 1CC3CC 002CC3CC 140003A2 */  sb         $3, 0x14($16)
    /* 1CC3D0 002CC3D0 DA060010 */  b          .L002CDF3C
    /* 1CC3D4 002CC3D4 00000000 */   nop
  .L002CC3D8:
    /* 1CC3D8 002CC3D8 02008330 */  andi       $3, $4, 0x2
    /* 1CC3DC 002CC3DC 04006014 */  bnez       $3, .L002CC3F0
    /* 1CC3E0 002CC3E0 00000000 */   nop
    /* 1CC3E4 002CC3E4 00208330 */  andi       $3, $4, 0x2000
    /* 1CC3E8 002CC3E8 18006010 */  beqz       $3, .L002CC44C
    /* 1CC3EC 002CC3EC 00000000 */   nop
  .L002CC3F0:
    /* 1CC3F0 002CC3F0 02001186 */  lh         $17, 0x2($16)
    /* 1CC3F4 002CC3F4 A8890B0C */  jal        func_002e26a0
    /* 1CC3F8 002CC3F8 00000000 */   nop
    /* 1CC3FC 002CC3FC 07002212 */  beq        $17, $2, .L002CC41C
    /* 1CC400 002CC400 00000000 */   nop
    /* 1CC404 002CC404 2D200000 */  daddu      $4, $0, $0
    /* 1CC408 002CC408 2D280000 */  daddu      $5, $0, $0
    /* 1CC40C 002CC40C 2D300000 */  daddu      $6, $0, $0
    /* 1CC410 002CC410 2D380000 */  daddu      $7, $0, $0
    /* 1CC414 002CC414 D86B110C */  jal        func_0045af60
    /* 1CC418 002CC418 00000000 */   nop
  .L002CC41C:
    /* 1CC41C 002CC41C 9C890B0C */  jal        func_002e2670
    /* 1CC420 002CC420 00000000 */   nop
    /* 1CC424 002CC424 02000486 */  lh         $4, 0x2($16)
    /* 1CC428 002CC428 04000586 */  lh         $5, 0x4($16)
    /* 1CC42C 002CC42C 2D304000 */  daddu      $6, $2, $0
    /* 1CC430 002CC430 05000724 */  addiu      $7, $0, 0x5
    /* 1CC434 002CC434 02000826 */  addiu      $8, $16, 0x2
    /* 1CC438 002CC438 04000926 */  addiu      $9, $16, 0x4
    /* 1CC43C 002CC43C 9CCB0A0C */  jal        func_002b2e70
    /* 1CC440 002CC440 00000000 */   nop
    /* 1CC444 002CC444 BC060010 */  b          .L002CDF38
    /* 1CC448 002CC448 00000000 */   nop
  .L002CC44C:
    /* 1CC44C 002CC44C 01008330 */  andi       $3, $4, 0x1
    /* 1CC450 002CC450 04006014 */  bnez       $3, .L002CC464
    /* 1CC454 002CC454 00000000 */   nop
    /* 1CC458 002CC458 00808330 */  andi       $3, $4, 0x8000
    /* 1CC45C 002CC45C 16006010 */  beqz       $3, .L002CC4B8
    /* 1CC460 002CC460 00000000 */   nop
  .L002CC464:
    /* 1CC464 002CC464 02000286 */  lh         $2, 0x2($16)
    /* 1CC468 002CC468 07004010 */  beqz       $2, .L002CC488
    /* 1CC46C 002CC46C 00000000 */   nop
    /* 1CC470 002CC470 2D200000 */  daddu      $4, $0, $0
    /* 1CC474 002CC474 2D280000 */  daddu      $5, $0, $0
    /* 1CC478 002CC478 2D300000 */  daddu      $6, $0, $0
    /* 1CC47C 002CC47C 2D380000 */  daddu      $7, $0, $0
    /* 1CC480 002CC480 D86B110C */  jal        func_0045af60
    /* 1CC484 002CC484 00000000 */   nop
  .L002CC488:
    /* 1CC488 002CC488 9C890B0C */  jal        func_002e2670
    /* 1CC48C 002CC48C 00000000 */   nop
    /* 1CC490 002CC490 02000486 */  lh         $4, 0x2($16)
    /* 1CC494 002CC494 04000586 */  lh         $5, 0x4($16)
    /* 1CC498 002CC498 2D304000 */  daddu      $6, $2, $0
    /* 1CC49C 002CC49C 05000724 */  addiu      $7, $0, 0x5
    /* 1CC4A0 002CC4A0 02000826 */  addiu      $8, $16, 0x2
    /* 1CC4A4 002CC4A4 04000926 */  addiu      $9, $16, 0x4
    /* 1CC4A8 002CC4A8 E4CB0A0C */  jal        func_002b2f90
    /* 1CC4AC 002CC4AC 00000000 */   nop
    /* 1CC4B0 002CC4B0 A1060010 */  b          .L002CDF38
    /* 1CC4B4 002CC4B4 00000000 */   nop
  .L002CC4B8:
    /* 1CC4B8 002CC4B8 08008330 */  andi       $3, $4, 0x8
    /* 1CC4BC 002CC4BC 47006010 */  beqz       $3, .L002CC5DC
    /* 1CC4C0 002CC4C0 00000000 */   nop
    /* 1CC4C4 002CC4C4 2D200000 */  daddu      $4, $0, $0
    /* 1CC4C8 002CC4C8 2D280000 */  daddu      $5, $0, $0
    /* 1CC4CC 002CC4CC 2D300000 */  daddu      $6, $0, $0
    /* 1CC4D0 002CC4D0 05000724 */  addiu      $7, $0, 0x5
    /* 1CC4D4 002CC4D4 D86B110C */  jal        func_0045af60
    /* 1CC4D8 002CC4D8 00000000 */   nop
    /* 1CC4DC 002CC4DC 020000A6 */  sh         $0, 0x2($16)
    /* 1CC4E0 002CC4E0 040000A6 */  sh         $0, 0x4($16)
    /* 1CC4E4 002CC4E4 08000482 */  lb         $4, 0x8($16)
    /* 1CC4E8 002CC4E8 09000282 */  lb         $2, 0x9($16)
    /* 1CC4EC 002CC4EC FFFF4624 */  addiu      $6, $2, -0x1
    /* 1CC4F0 002CC4F0 01000524 */  addiu      $5, $0, 0x1
    /* 1CC4F4 002CC4F4 2D380000 */  daddu      $7, $0, $0
    /* 1CC4F8 002CC4F8 02000824 */  addiu      $8, $0, 0x2
    /* 1CC4FC 002CC4FC 2CCB0A0C */  jal        func_002b2cb0
    /* 1CC500 002CC500 00000000 */   nop
    /* 1CC504 002CC504 080002A2 */  sb         $2, 0x8($16)
    /* 1CC508 002CC508 07000282 */  lb         $2, 0x7($16)
    /* 1CC50C 002CC50C 02000624 */  addiu      $6, $0, 0x2
    /* 1CC510 002CC510 22004610 */  beq        $2, $6, .L002CC59C
    /* 1CC514 002CC514 00000000 */   nop
    /* 1CC518 002CC518 01000524 */  addiu      $5, $0, 0x1
    /* 1CC51C 002CC51C 14004510 */  beq        $2, $5, .L002CC570
    /* 1CC520 002CC520 00000000 */   nop
    /* 1CC524 002CC524 03004010 */  beqz       $2, .L002CC534
    /* 1CC528 002CC528 00000000 */   nop
    /* 1CC52C 002CC52C 25000010 */  b          .L002CC5C4
    /* 1CC530 002CC530 00000000 */   nop
  .L002CC534:
    /* 1CC534 002CC534 08000282 */  lb         $2, 0x8($16)
    /* 1CC538 002CC538 21185000 */  addu       $3, $2, $16
    /* 1CC53C 002CC53C 7C0F6280 */  lb         $2, 0xF7C($3)
    /* 1CC540 002CC540 ECFF4224 */  addiu      $2, $2, -0x14
    /* 1CC544 002CC544 3C140200 */  dsll32     $2, $2, 16
    /* 1CC548 002CC548 3F140200 */  dsra32     $2, $2, 16
    /* 1CC54C 002CC54C 04204500 */  sllv       $4, $5, $2
    /* 1CC550 002CC550 730F6280 */  lb         $2, 0xF73($3)
    /* 1CC554 002CC554 04004224 */  addiu      $2, $2, 0x4
    /* 1CC558 002CC558 04284500 */  sllv       $5, $5, $2
    /* 1CC55C 002CC55C 2D38C000 */  daddu      $7, $6, $0
    /* 1CC560 002CC560 848A0B0C */  jal        func_002e2a10
    /* 1CC564 002CC564 00000000 */   nop
    /* 1CC568 002CC568 16000010 */  b          .L002CC5C4
    /* 1CC56C 002CC56C 00000000 */   nop
  .L002CC570:
    /* 1CC570 002CC570 08000282 */  lb         $2, 0x8($16)
    /* 1CC574 002CC574 21105000 */  addu       $2, $2, $16
    /* 1CC578 002CC578 730F4280 */  lb         $2, 0xF73($2)
    /* 1CC57C 002CC57C 04004224 */  addiu      $2, $2, 0x4
    /* 1CC580 002CC580 04284500 */  sllv       $5, $5, $2
    /* 1CC584 002CC584 00400424 */  addiu      $4, $0, 0x4000
    /* 1CC588 002CC588 2D38C000 */  daddu      $7, $6, $0
    /* 1CC58C 002CC58C 848A0B0C */  jal        func_002e2a10
    /* 1CC590 002CC590 00000000 */   nop
    /* 1CC594 002CC594 0B000010 */  b          .L002CC5C4
    /* 1CC598 002CC598 00000000 */   nop
  .L002CC59C:
    /* 1CC59C 002CC59C 08000282 */  lb         $2, 0x8($16)
    /* 1CC5A0 002CC5A0 21105000 */  addu       $2, $2, $16
    /* 1CC5A4 002CC5A4 730F4280 */  lb         $2, 0xF73($2)
    /* 1CC5A8 002CC5A8 04004324 */  addiu      $3, $2, 0x4
    /* 1CC5AC 002CC5AC 01000224 */  addiu      $2, $0, 0x1
    /* 1CC5B0 002CC5B0 04286200 */  sllv       $5, $2, $3
    /* 1CC5B4 002CC5B4 00800434 */  ori        $4, $0, 0x8000
    /* 1CC5B8 002CC5B8 2D38C000 */  daddu      $7, $6, $0
    /* 1CC5BC 002CC5BC 848A0B0C */  jal        func_002e2a10
    /* 1CC5C0 002CC5C0 00000000 */   nop
  .L002CC5C4:
    /* 1CC5C4 002CC5C4 2D20A002 */  daddu      $4, $21, $0
    /* 1CC5C8 002CC5C8 2D280000 */  daddu      $5, $0, $0
    /* 1CC5CC 002CC5CC 80600B0C */  jal        func_002d8200
    /* 1CC5D0 002CC5D0 00000000 */   nop
    /* 1CC5D4 002CC5D4 58060010 */  b          .L002CDF38
    /* 1CC5D8 002CC5D8 00000000 */   nop
  .L002CC5DC:
    /* 1CC5DC 002CC5DC 04008330 */  andi       $3, $4, 0x4
    /* 1CC5E0 002CC5E0 47006010 */  beqz       $3, .L002CC700
    /* 1CC5E4 002CC5E4 00000000 */   nop
    /* 1CC5E8 002CC5E8 2D200000 */  daddu      $4, $0, $0
    /* 1CC5EC 002CC5EC 2D280000 */  daddu      $5, $0, $0
    /* 1CC5F0 002CC5F0 2D300000 */  daddu      $6, $0, $0
    /* 1CC5F4 002CC5F4 05000724 */  addiu      $7, $0, 0x5
    /* 1CC5F8 002CC5F8 D86B110C */  jal        func_0045af60
    /* 1CC5FC 002CC5FC 00000000 */   nop
    /* 1CC600 002CC600 020000A6 */  sh         $0, 0x2($16)
    /* 1CC604 002CC604 040000A6 */  sh         $0, 0x4($16)
    /* 1CC608 002CC608 08000482 */  lb         $4, 0x8($16)
    /* 1CC60C 002CC60C 09000282 */  lb         $2, 0x9($16)
    /* 1CC610 002CC610 FFFF4724 */  addiu      $7, $2, -0x1
    /* 1CC614 002CC614 01000524 */  addiu      $5, $0, 0x1
    /* 1CC618 002CC618 2D300000 */  daddu      $6, $0, $0
    /* 1CC61C 002CC61C 02000824 */  addiu      $8, $0, 0x2
    /* 1CC620 002CC620 40CB0A0C */  jal        func_002b2d00
    /* 1CC624 002CC624 00000000 */   nop
    /* 1CC628 002CC628 080002A2 */  sb         $2, 0x8($16)
    /* 1CC62C 002CC62C 07000282 */  lb         $2, 0x7($16)
    /* 1CC630 002CC630 02000624 */  addiu      $6, $0, 0x2
    /* 1CC634 002CC634 22004610 */  beq        $2, $6, .L002CC6C0
    /* 1CC638 002CC638 00000000 */   nop
    /* 1CC63C 002CC63C 01000524 */  addiu      $5, $0, 0x1
    /* 1CC640 002CC640 14004510 */  beq        $2, $5, .L002CC694
    /* 1CC644 002CC644 00000000 */   nop
    /* 1CC648 002CC648 03004010 */  beqz       $2, .L002CC658
    /* 1CC64C 002CC64C 00000000 */   nop
    /* 1CC650 002CC650 25000010 */  b          .L002CC6E8
    /* 1CC654 002CC654 00000000 */   nop
  .L002CC658:
    /* 1CC658 002CC658 08000282 */  lb         $2, 0x8($16)
    /* 1CC65C 002CC65C 21185000 */  addu       $3, $2, $16
    /* 1CC660 002CC660 7C0F6280 */  lb         $2, 0xF7C($3)
    /* 1CC664 002CC664 ECFF4224 */  addiu      $2, $2, -0x14
    /* 1CC668 002CC668 3C140200 */  dsll32     $2, $2, 16
    /* 1CC66C 002CC66C 3F140200 */  dsra32     $2, $2, 16
    /* 1CC670 002CC670 04204500 */  sllv       $4, $5, $2
    /* 1CC674 002CC674 730F6280 */  lb         $2, 0xF73($3)
    /* 1CC678 002CC678 04004224 */  addiu      $2, $2, 0x4
    /* 1CC67C 002CC67C 04284500 */  sllv       $5, $5, $2
    /* 1CC680 002CC680 2D38C000 */  daddu      $7, $6, $0
    /* 1CC684 002CC684 848A0B0C */  jal        func_002e2a10
    /* 1CC688 002CC688 00000000 */   nop
    /* 1CC68C 002CC68C 16000010 */  b          .L002CC6E8
    /* 1CC690 002CC690 00000000 */   nop
  .L002CC694:
    /* 1CC694 002CC694 08000282 */  lb         $2, 0x8($16)
    /* 1CC698 002CC698 21105000 */  addu       $2, $2, $16
    /* 1CC69C 002CC69C 730F4280 */  lb         $2, 0xF73($2)
    /* 1CC6A0 002CC6A0 04004224 */  addiu      $2, $2, 0x4
    /* 1CC6A4 002CC6A4 04284500 */  sllv       $5, $5, $2
    /* 1CC6A8 002CC6A8 00400424 */  addiu      $4, $0, 0x4000
    /* 1CC6AC 002CC6AC 2D38C000 */  daddu      $7, $6, $0
    /* 1CC6B0 002CC6B0 848A0B0C */  jal        func_002e2a10
    /* 1CC6B4 002CC6B4 00000000 */   nop
    /* 1CC6B8 002CC6B8 0B000010 */  b          .L002CC6E8
    /* 1CC6BC 002CC6BC 00000000 */   nop
  .L002CC6C0:
    /* 1CC6C0 002CC6C0 08000282 */  lb         $2, 0x8($16)
    /* 1CC6C4 002CC6C4 21105000 */  addu       $2, $2, $16
    /* 1CC6C8 002CC6C8 730F4280 */  lb         $2, 0xF73($2)
    /* 1CC6CC 002CC6CC 04004324 */  addiu      $3, $2, 0x4
    /* 1CC6D0 002CC6D0 01000224 */  addiu      $2, $0, 0x1
    /* 1CC6D4 002CC6D4 04286200 */  sllv       $5, $2, $3
    /* 1CC6D8 002CC6D8 00800434 */  ori        $4, $0, 0x8000
    /* 1CC6DC 002CC6DC 2D38C000 */  daddu      $7, $6, $0
    /* 1CC6E0 002CC6E0 848A0B0C */  jal        func_002e2a10
    /* 1CC6E4 002CC6E4 00000000 */   nop
  .L002CC6E8:
    /* 1CC6E8 002CC6E8 2D20A002 */  daddu      $4, $21, $0
    /* 1CC6EC 002CC6EC 01000524 */  addiu      $5, $0, 0x1
    /* 1CC6F0 002CC6F0 80600B0C */  jal        func_002d8200
    /* 1CC6F4 002CC6F4 00000000 */   nop
    /* 1CC6F8 002CC6F8 0F060010 */  b          .L002CDF38
    /* 1CC6FC 002CC6FC 00000000 */   nop
  .L002CC700:
    /* 1CC700 002CC700 8C00033C */  lui        $3, %hi(D_008C024E)
    /* 1CC704 002CC704 4E026494 */  lhu        $4, %lo(D_008C024E)($3)
    /* 1CC708 002CC708 40008330 */  andi       $3, $4, 0x40
    /* 1CC70C 002CC70C 4E006010 */  beqz       $3, .L002CC848
    /* 1CC710 002CC710 00000000 */   nop
    /* 1CC714 002CC714 9C890B0C */  jal        func_002e2670
    /* 1CC718 002CC718 00000000 */   nop
    /* 1CC71C 002CC71C 42004018 */  blez       $2, .L002CC828
    /* 1CC720 002CC720 00000000 */   nop
    /* 1CC724 002CC724 02000486 */  lh         $4, 0x2($16)
    /* 1CC728 002CC728 D0890B0C */  jal        func_002e2740
    /* 1CC72C 002CC72C 00000000 */   nop
    /* 1CC730 002CC730 3C240200 */  dsll32     $4, $2, 16
    /* 1CC734 002CC734 3F240400 */  dsra32     $4, $4, 16
    /* 1CC738 002CC738 A41A040C */  jal        func_00106a90
    /* 1CC73C 002CC73C 00000000 */   nop
    /* 1CC740 002CC740 2D884000 */  daddu      $17, $2, $0
    /* 1CC744 002CC744 989E0B0C */  jal        func_002e7a60
    /* 1CC748 002CC748 00000000 */   nop
    /* 1CC74C 002CC74C 2B085100 */  sltu       $1, $2, $17
    /* 1CC750 002CC750 2D002014 */  bnez       $1, .L002CC808
    /* 1CC754 002CC754 00000000 */   nop
    /* 1CC758 002CC758 02000486 */  lh         $4, 0x2($16)
    /* 1CC75C 002CC75C D0890B0C */  jal        func_002e2740
    /* 1CC760 002CC760 00000000 */   nop
    /* 1CC764 002CC764 3C240200 */  dsll32     $4, $2, 16
    /* 1CC768 002CC768 3F240400 */  dsra32     $4, $4, 16
    /* 1CC76C 002CC76C 8019040C */  jal        func_00106600
    /* 1CC770 002CC770 00000000 */   nop
    /* 1CC774 002CC774 FF004230 */  andi       $2, $2, 0xFF
    /* 1CC778 002CC778 63004128 */  slti       $1, $2, 0x63
    /* 1CC77C 002CC77C 22002010 */  beqz       $1, .L002CC808
    /* 1CC780 002CC780 00000000 */   nop
    /* 1CC784 002CC784 2D200000 */  daddu      $4, $0, $0
    /* 1CC788 002CC788 2D280000 */  daddu      $5, $0, $0
    /* 1CC78C 002CC78C 2D300000 */  daddu      $6, $0, $0
    /* 1CC790 002CC790 01000724 */  addiu      $7, $0, 0x1
    /* 1CC794 002CC794 D86B110C */  jal        func_0045af60
    /* 1CC798 002CC798 00000000 */   nop
    /* 1CC79C 002CC79C C80D048E */  lw         $4, 0xDC8($16)
    /* 1CC7A0 002CC7A0 38810B0C */  jal        func_002e04e0
    /* 1CC7A4 002CC7A4 00000000 */   nop
    /* 1CC7A8 002CC7A8 79004590 */  lbu        $5, 0x79($2)
    /* 1CC7AC 002CC7AC 7A004490 */  lbu        $4, 0x7A($2)
    /* 1CC7B0 002CC7B0 7B004390 */  lbu        $3, 0x7B($2)
    /* 1CC7B4 002CC7B4 7C004290 */  lbu        $2, 0x7C($2)
    /* 1CC7B8 002CC7B8 3E0F05A2 */  sb         $5, 0xF3E($16)
    /* 1CC7BC 002CC7BC 3F0F04A2 */  sb         $4, 0xF3F($16)
    /* 1CC7C0 002CC7C0 400F03A2 */  sb         $3, 0xF40($16)
    /* 1CC7C4 002CC7C4 410F02A2 */  sb         $2, 0xF41($16)
    /* 1CC7C8 002CC7C8 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CC7CC 002CC7CC 38810B0C */  jal        func_002e04e0
    /* 1CC7D0 002CC7D0 00000000 */   nop
    /* 1CC7D4 002CC7D4 79004690 */  lbu        $6, 0x79($2)
    /* 1CC7D8 002CC7D8 7A004590 */  lbu        $5, 0x7A($2)
    /* 1CC7DC 002CC7DC 7B004490 */  lbu        $4, 0x7B($2)
    /* 1CC7E0 002CC7E0 7C004390 */  lbu        $3, 0x7C($2)
    /* 1CC7E4 002CC7E4 420F06A2 */  sb         $6, 0xF42($16)
    /* 1CC7E8 002CC7E8 430F05A2 */  sb         $5, 0xF43($16)
    /* 1CC7EC 002CC7EC 440F04A2 */  sb         $4, 0xF44($16)
    /* 1CC7F0 002CC7F0 450F03A2 */  sb         $3, 0xF45($16)
    /* 1CC7F4 002CC7F4 3C0F00A6 */  sh         $0, 0xF3C($16)
    /* 1CC7F8 002CC7F8 1C000324 */  addiu      $3, $0, 0x1C
    /* 1CC7FC 002CC7FC 000003A2 */  sb         $3, 0x0($16)
    /* 1CC800 002CC800 CD050010 */  b          .L002CDF38
    /* 1CC804 002CC804 00000000 */   nop
  .L002CC808:
    /* 1CC808 002CC808 2D200000 */  daddu      $4, $0, $0
    /* 1CC80C 002CC80C 2D280000 */  daddu      $5, $0, $0
    /* 1CC810 002CC810 2D300000 */  daddu      $6, $0, $0
    /* 1CC814 002CC814 08000724 */  addiu      $7, $0, 0x8
    /* 1CC818 002CC818 D86B110C */  jal        func_0045af60
    /* 1CC81C 002CC81C 00000000 */   nop
    /* 1CC820 002CC820 C5050010 */  b          .L002CDF38
    /* 1CC824 002CC824 00000000 */   nop
  .L002CC828:
    /* 1CC828 002CC828 2D200000 */  daddu      $4, $0, $0
    /* 1CC82C 002CC82C 2D280000 */  daddu      $5, $0, $0
    /* 1CC830 002CC830 2D300000 */  daddu      $6, $0, $0
    /* 1CC834 002CC834 08000724 */  addiu      $7, $0, 0x8
    /* 1CC838 002CC838 D86B110C */  jal        func_0045af60
    /* 1CC83C 002CC83C 00000000 */   nop
    /* 1CC840 002CC840 BD050010 */  b          .L002CDF38
    /* 1CC844 002CC844 00000000 */   nop
  .L002CC848:
    /* 1CC848 002CC848 80008330 */  andi       $3, $4, 0x80
    /* 1CC84C 002CC84C 96006010 */  beqz       $3, .L002CCAA8
    /* 1CC850 002CC850 00000000 */   nop
    /* 1CC854 002CC854 9C890B0C */  jal        func_002e2670
    /* 1CC858 002CC858 00000000 */   nop
    /* 1CC85C 002CC85C B6054018 */  blez       $2, .L002CDF38
    /* 1CC860 002CC860 00000000 */   nop
    /* 1CC864 002CC864 2D200000 */  daddu      $4, $0, $0
    /* 1CC868 002CC868 01000524 */  addiu      $5, $0, 0x1
    /* 1CC86C 002CC86C 2D300000 */  daddu      $6, $0, $0
    /* 1CC870 002CC870 03000724 */  addiu      $7, $0, 0x3
    /* 1CC874 002CC874 D86B110C */  jal        func_0045af60
    /* 1CC878 002CC878 00000000 */   nop
    /* 1CC87C 002CC87C 2802A427 */  addiu      $4, $29, 0x228
    /* 1CC880 002CC880 FE000524 */  addiu      $5, $0, 0xFE
    /* 1CC884 002CC884 C6000624 */  addiu      $6, $0, 0xC6
    /* 1CC888 002CC888 31000724 */  addiu      $7, $0, 0x31
    /* 1CC88C 002CC88C FF000824 */  addiu      $8, $0, 0xFF
    /* 1CC890 002CC890 98CA0A0C */  jal        func_002b2a60
    /* 1CC894 002CC894 00000000 */   nop
    /* 1CC898 002CC898 2402A427 */  addiu      $4, $29, 0x224
    /* 1CC89C 002CC89C FF000524 */  addiu      $5, $0, 0xFF
    /* 1CC8A0 002CC8A0 E2000624 */  addiu      $6, $0, 0xE2
    /* 1CC8A4 002CC8A4 91000724 */  addiu      $7, $0, 0x91
    /* 1CC8A8 002CC8A8 2D40A000 */  daddu      $8, $5, $0
    /* 1CC8AC 002CC8AC 98CA0A0C */  jal        func_002b2a60
    /* 1CC8B0 002CC8B0 00000000 */   nop
    /* 1CC8B4 002CC8B4 C80D048E */  lw         $4, 0xDC8($16)
    /* 1CC8B8 002CC8B8 2802A58F */  lw         $5, 0x228($29)
    /* 1CC8BC 002CC8BC 2402A68F */  lw         $6, 0x224($29)
    /* 1CC8C0 002CC8C0 01000724 */  addiu      $7, $0, 0x1
    /* 1CC8C4 002CC8C4 04000824 */  addiu      $8, $0, 0x4
    /* 1CC8C8 002CC8C8 2D480000 */  daddu      $9, $0, $0
    /* 1CC8CC 002CC8CC 5C820B0C */  jal        func_002e0970
    /* 1CC8D0 002CC8D0 00000000 */   nop
    /* 1CC8D4 002CC8D4 01001124 */  addiu      $17, $0, 0x1
    /* 1CC8D8 002CC8D8 C80D048E */  lw         $4, 0xDC8($16)
    /* 1CC8DC 002CC8DC 38810B0C */  jal        func_002e04e0
    /* 1CC8E0 002CC8E0 00000000 */   nop
    /* 1CC8E4 002CC8E4 850051A0 */  sb         $17, 0x85($2)
    /* 1CC8E8 002CC8E8 2002A427 */  addiu      $4, $29, 0x220
    /* 1CC8EC 002CC8EC FE000524 */  addiu      $5, $0, 0xFE
    /* 1CC8F0 002CC8F0 C6000624 */  addiu      $6, $0, 0xC6
    /* 1CC8F4 002CC8F4 31000724 */  addiu      $7, $0, 0x31
    /* 1CC8F8 002CC8F8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CC8FC 002CC8FC 98CA0A0C */  jal        func_002b2a60
    /* 1CC900 002CC900 00000000 */   nop
    /* 1CC904 002CC904 1C02A427 */  addiu      $4, $29, 0x21C
    /* 1CC908 002CC908 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CC90C 002CC90C E2000624 */  addiu      $6, $0, 0xE2
    /* 1CC910 002CC910 91000724 */  addiu      $7, $0, 0x91
    /* 1CC914 002CC914 2D40A000 */  daddu      $8, $5, $0
    /* 1CC918 002CC918 98CA0A0C */  jal        func_002b2a60
    /* 1CC91C 002CC91C 00000000 */   nop
    /* 1CC920 002CC920 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CC924 002CC924 2002A58F */  lw         $5, 0x220($29)
    /* 1CC928 002CC928 1C02A68F */  lw         $6, 0x21C($29)
    /* 1CC92C 002CC92C 2D382002 */  daddu      $7, $17, $0
    /* 1CC930 002CC930 04000824 */  addiu      $8, $0, 0x4
    /* 1CC934 002CC934 2D480000 */  daddu      $9, $0, $0
    /* 1CC938 002CC938 5C820B0C */  jal        func_002e0970
    /* 1CC93C 002CC93C 00000000 */   nop
    /* 1CC940 002CC940 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CC944 002CC944 38810B0C */  jal        func_002e04e0
    /* 1CC948 002CC948 00000000 */   nop
    /* 1CC94C 002CC94C 850051A0 */  sb         $17, 0x85($2)
    /* 1CC950 002CC950 280F048E */  lw         $4, 0xF28($16)
    /* 1CC954 002CC954 7D000524 */  addiu      $5, $0, 0x7D
    /* 1CC958 002CC958 80B4110C */  jal        func_0046d200
    /* 1CC95C 002CC95C 00000000 */   nop
    /* 1CC960 002CC960 2D884000 */  daddu      $17, $2, $0
    /* 1CC964 002CC964 2D202002 */  daddu      $4, $17, $0
    /* 1CC968 002CC968 98AC110C */  jal        func_0046b260
    /* 1CC96C 002CC96C 00000000 */   nop
    /* 1CC970 002CC970 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CC974 002CC974 00000244 */  mfc1       $2, $f0
    /* 1CC978 002CC978 00000000 */  nop
    /* 1CC97C 002CC97C 3C940200 */  dsll32     $18, $2, 16
    /* 1CC980 002CC980 3F941200 */  dsra32     $18, $18, 16
    /* 1CC984 002CC984 2C0E048E */  lw         $4, 0xE2C($16)
    /* 1CC988 002CC988 38810B0C */  jal        func_002e04e0
    /* 1CC98C 002CC98C 00000000 */   nop
    /* 1CC990 002CC990 000152A4 */  sh         $18, 0x100($2)
    /* 1CC994 002CC994 2D202002 */  daddu      $4, $17, $0
    /* 1CC998 002CC998 BCAC110C */  jal        func_0046b2f0
    /* 1CC99C 002CC99C 00000000 */   nop
    /* 1CC9A0 002CC9A0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CC9A4 002CC9A4 00088244 */  mtc1       $2, $f1
    /* 1CC9A8 002CC9A8 00000000 */  nop
    /* 1CC9AC 002CC9AC 03000146 */  div.s      $f0, $f0, $f1
    /* 1CC9B0 002CC9B0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CC9B4 002CC9B4 00000244 */  mfc1       $2, $f0
    /* 1CC9B8 002CC9B8 00000000 */  nop
    /* 1CC9BC 002CC9BC 3C940200 */  dsll32     $18, $2, 16
    /* 1CC9C0 002CC9C0 3F941200 */  dsra32     $18, $18, 16
    /* 1CC9C4 002CC9C4 2C0E048E */  lw         $4, 0xE2C($16)
    /* 1CC9C8 002CC9C8 38810B0C */  jal        func_002e04e0
    /* 1CC9CC 002CC9CC 00000000 */   nop
    /* 1CC9D0 002CC9D0 020152A4 */  sh         $18, 0x102($2)
    /* 1CC9D4 002CC9D4 300E048E */  lw         $4, 0xE30($16)
    /* 1CC9D8 002CC9D8 38810B0C */  jal        func_002e04e0
    /* 1CC9DC 002CC9DC 00000000 */   nop
    /* 1CC9E0 002CC9E0 000140A4 */  sh         $0, 0x100($2)
    /* 1CC9E4 002CC9E4 2D202002 */  daddu      $4, $17, $0
    /* 1CC9E8 002CC9E8 BCAC110C */  jal        func_0046b2f0
    /* 1CC9EC 002CC9EC 00000000 */   nop
    /* 1CC9F0 002CC9F0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CC9F4 002CC9F4 00088244 */  mtc1       $2, $f1
    /* 1CC9F8 002CC9F8 00000000 */  nop
    /* 1CC9FC 002CC9FC 03000146 */  div.s      $f0, $f0, $f1
    /* 1CCA00 002CCA00 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CCA04 002CCA04 00000244 */  mfc1       $2, $f0
    /* 1CCA08 002CCA08 00000000 */  nop
    /* 1CCA0C 002CCA0C 3C940200 */  dsll32     $18, $2, 16
    /* 1CCA10 002CCA10 3F941200 */  dsra32     $18, $18, 16
    /* 1CCA14 002CCA14 300E048E */  lw         $4, 0xE30($16)
    /* 1CCA18 002CCA18 38810B0C */  jal        func_002e04e0
    /* 1CCA1C 002CCA1C 00000000 */   nop
    /* 1CCA20 002CCA20 020152A4 */  sh         $18, 0x102($2)
    /* 1CCA24 002CCA24 00608044 */  mtc1       $0, $f12
    /* 1CCA28 002CCA28 80C0023C */  lui        $2, (0xC0800000 >> 16)
    /* 1CCA2C 002CCA2C 00688244 */  mtc1       $2, $f13
    /* 1CCA30 002CCA30 2C0E048E */  lw         $4, 0xE2C($16)
    /* 1CCA34 002CCA34 2D280000 */  daddu      $5, $0, $0
    /* 1CCA38 002CCA38 02000624 */  addiu      $6, $0, 0x2
    /* 1CCA3C 002CCA3C 2D380000 */  daddu      $7, $0, $0
    /* 1CCA40 002CCA40 50820B0C */  jal        func_002e0940
    /* 1CCA44 002CCA44 00000000 */   nop
    /* 1CCA48 002CCA48 00608044 */  mtc1       $0, $f12
    /* 1CCA4C 002CCA4C 80C0023C */  lui        $2, (0xC0800000 >> 16)
    /* 1CCA50 002CCA50 00688244 */  mtc1       $2, $f13
    /* 1CCA54 002CCA54 300E048E */  lw         $4, 0xE30($16)
    /* 1CCA58 002CCA58 2D280000 */  daddu      $5, $0, $0
    /* 1CCA5C 002CCA5C 02000624 */  addiu      $6, $0, 0x2
    /* 1CCA60 002CCA60 2D380000 */  daddu      $7, $0, $0
    /* 1CCA64 002CCA64 50820B0C */  jal        func_002e0940
    /* 1CCA68 002CCA68 00000000 */   nop
    /* 1CCA6C 002CCA6C 2C0E048E */  lw         $4, 0xE2C($16)
    /* 1CCA70 002CCA70 38810B0C */  jal        func_002e04e0
    /* 1CCA74 002CCA74 00000000 */   nop
    /* 1CCA78 002CCA78 CF0040A0 */  sb         $0, 0xCF($2)
    /* 1CCA7C 002CCA7C 300E048E */  lw         $4, 0xE30($16)
    /* 1CCA80 002CCA80 38810B0C */  jal        func_002e04e0
    /* 1CCA84 002CCA84 00000000 */   nop
    /* 1CCA88 002CCA88 CF0040A0 */  sb         $0, 0xCF($2)
    /* 1CCA8C 002CCA8C 2D202002 */  daddu      $4, $17, $0
    /* 1CCA90 002CCA90 A0B4110C */  jal        func_0046d280
    /* 1CCA94 002CCA94 00000000 */   nop
    /* 1CCA98 002CCA98 20000324 */  addiu      $3, $0, 0x20
    /* 1CCA9C 002CCA9C 000003A2 */  sb         $3, 0x0($16)
    /* 1CCAA0 002CCAA0 25050010 */  b          .L002CDF38
    /* 1CCAA4 002CCAA4 00000000 */   nop
  .L002CCAA8:
    /* 1CCAA8 002CCAA8 20008330 */  andi       $3, $4, 0x20
    /* 1CCAAC 002CCAAC 22056010 */  beqz       $3, .L002CDF38
    /* 1CCAB0 002CCAB0 00000000 */   nop
    /* 1CCAB4 002CCAB4 2D200000 */  daddu      $4, $0, $0
    /* 1CCAB8 002CCAB8 2D280000 */  daddu      $5, $0, $0
    /* 1CCABC 002CCABC 2D300000 */  daddu      $6, $0, $0
    /* 1CCAC0 002CCAC0 02000724 */  addiu      $7, $0, 0x2
    /* 1CCAC4 002CCAC4 D86B110C */  jal        func_0045af60
    /* 1CCAC8 002CCAC8 00000000 */   nop
    /* 1CCACC 002CCACC 60C1023C */  lui        $2, (0xC1600000 >> 16)
    /* 1CCAD0 002CCAD0 00608244 */  mtc1       $2, $f12
    /* 1CCAD4 002CCAD4 DC42023C */  lui        $2, (0x42DC0000 >> 16)
    /* 1CCAD8 002CCAD8 00688244 */  mtc1       $2, $f13
    /* 1CCADC 002CCADC 6C0D048E */  lw         $4, 0xD6C($16)
    /* 1CCAE0 002CCAE0 2D280000 */  daddu      $5, $0, $0
    /* 1CCAE4 002CCAE4 0A000624 */  addiu      $6, $0, 0xA
    /* 1CCAE8 002CCAE8 2D380000 */  daddu      $7, $0, $0
    /* 1CCAEC 002CCAEC 50820B0C */  jal        func_002e0940
    /* 1CCAF0 002CCAF0 00000000 */   nop
    /* 1CCAF4 002CCAF4 2C0E048E */  lw         $4, 0xE2C($16)
    /* 1CCAF8 002CCAF8 38810B0C */  jal        func_002e04e0
    /* 1CCAFC 002CCAFC 00000000 */   nop
    /* 1CCB00 002CCB00 2C0E048E */  lw         $4, 0xE2C($16)
    /* 1CCB04 002CCB04 62004590 */  lbu        $5, 0x62($2)
    /* 1CCB08 002CCB08 2D300000 */  daddu      $6, $0, $0
    /* 1CCB0C 002CCB0C 2D380000 */  daddu      $7, $0, $0
    /* 1CCB10 002CCB10 05000824 */  addiu      $8, $0, 0x5
    /* 1CCB14 002CCB14 2D480000 */  daddu      $9, $0, $0
    /* 1CCB18 002CCB18 98810B0C */  jal        func_002e0660
    /* 1CCB1C 002CCB1C 00000000 */   nop
    /* 1CCB20 002CCB20 300E048E */  lw         $4, 0xE30($16)
    /* 1CCB24 002CCB24 38810B0C */  jal        func_002e04e0
    /* 1CCB28 002CCB28 00000000 */   nop
    /* 1CCB2C 002CCB2C 300E048E */  lw         $4, 0xE30($16)
    /* 1CCB30 002CCB30 62004590 */  lbu        $5, 0x62($2)
    /* 1CCB34 002CCB34 2D300000 */  daddu      $6, $0, $0
    /* 1CCB38 002CCB38 2D380000 */  daddu      $7, $0, $0
    /* 1CCB3C 002CCB3C 05000824 */  addiu      $8, $0, 0x5
    /* 1CCB40 002CCB40 2D480000 */  daddu      $9, $0, $0
    /* 1CCB44 002CCB44 98810B0C */  jal        func_002e0660
    /* 1CCB48 002CCB48 00000000 */   nop
    /* 1CCB4C 002CCB4C 700D048E */  lw         $4, 0xD70($16)
    /* 1CCB50 002CCB50 38810B0C */  jal        func_002e04e0
    /* 1CCB54 002CCB54 00000000 */   nop
    /* 1CCB58 002CCB58 700D048E */  lw         $4, 0xD70($16)
    /* 1CCB5C 002CCB5C 62004590 */  lbu        $5, 0x62($2)
    /* 1CCB60 002CCB60 2D300000 */  daddu      $6, $0, $0
    /* 1CCB64 002CCB64 2D380000 */  daddu      $7, $0, $0
    /* 1CCB68 002CCB68 05000824 */  addiu      $8, $0, 0x5
    /* 1CCB6C 002CCB6C 2D480000 */  daddu      $9, $0, $0
    /* 1CCB70 002CCB70 98810B0C */  jal        func_002e0660
    /* 1CCB74 002CCB74 00000000 */   nop
    /* 1CCB78 002CCB78 7C0D048E */  lw         $4, 0xD7C($16)
    /* 1CCB7C 002CCB7C 38810B0C */  jal        func_002e04e0
    /* 1CCB80 002CCB80 00000000 */   nop
    /* 1CCB84 002CCB84 7C0D048E */  lw         $4, 0xD7C($16)
    /* 1CCB88 002CCB88 62004590 */  lbu        $5, 0x62($2)
    /* 1CCB8C 002CCB8C 2D300000 */  daddu      $6, $0, $0
    /* 1CCB90 002CCB90 2D380000 */  daddu      $7, $0, $0
    /* 1CCB94 002CCB94 05000824 */  addiu      $8, $0, 0x5
    /* 1CCB98 002CCB98 2D480000 */  daddu      $9, $0, $0
    /* 1CCB9C 002CCB9C 98810B0C */  jal        func_002e0660
    /* 1CCBA0 002CCBA0 00000000 */   nop
    /* 1CCBA4 002CCBA4 D80D048E */  lw         $4, 0xDD8($16)
    /* 1CCBA8 002CCBA8 2D280000 */  daddu      $5, $0, $0
    /* 1CCBAC 002CCBAC 01000624 */  addiu      $6, $0, 0x1
    /* 1CCBB0 002CCBB0 3C810B0C */  jal        func_002e04f0
    /* 1CCBB4 002CCBB4 00000000 */   nop
    /* 1CCBB8 002CCBB8 E80D048E */  lw         $4, 0xDE8($16)
    /* 1CCBBC 002CCBBC 2D280000 */  daddu      $5, $0, $0
    /* 1CCBC0 002CCBC0 01000624 */  addiu      $6, $0, 0x1
    /* 1CCBC4 002CCBC4 3C810B0C */  jal        func_002e04f0
    /* 1CCBC8 002CCBC8 00000000 */   nop
    /* 1CCBCC 002CCBCC F00D048E */  lw         $4, 0xDF0($16)
    /* 1CCBD0 002CCBD0 2D280000 */  daddu      $5, $0, $0
    /* 1CCBD4 002CCBD4 01000624 */  addiu      $6, $0, 0x1
    /* 1CCBD8 002CCBD8 3C810B0C */  jal        func_002e04f0
    /* 1CCBDC 002CCBDC 00000000 */   nop
    /* 1CCBE0 002CCBE0 E40D048E */  lw         $4, 0xDE4($16)
    /* 1CCBE4 002CCBE4 2D280000 */  daddu      $5, $0, $0
    /* 1CCBE8 002CCBE8 01000624 */  addiu      $6, $0, 0x1
    /* 1CCBEC 002CCBEC 3C810B0C */  jal        func_002e04f0
    /* 1CCBF0 002CCBF0 00000000 */   nop
    /* 1CCBF4 002CCBF4 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CCBF8 002CCBF8 38810B0C */  jal        func_002e04e0
    /* 1CCBFC 002CCBFC 00000000 */   nop
    /* 1CCC00 002CCC00 8C0C048E */  lw         $4, 0xC8C($16)
    /* 1CCC04 002CCC04 62004590 */  lbu        $5, 0x62($2)
    /* 1CCC08 002CCC08 2D300000 */  daddu      $6, $0, $0
    /* 1CCC0C 002CCC0C 2D380000 */  daddu      $7, $0, $0
    /* 1CCC10 002CCC10 05000824 */  addiu      $8, $0, 0x5
    /* 1CCC14 002CCC14 2D480000 */  daddu      $9, $0, $0
    /* 1CCC18 002CCC18 98810B0C */  jal        func_002e0660
    /* 1CCC1C 002CCC1C 00000000 */   nop
    /* 1CCC20 002CCC20 900C048E */  lw         $4, 0xC90($16)
    /* 1CCC24 002CCC24 38810B0C */  jal        func_002e04e0
    /* 1CCC28 002CCC28 00000000 */   nop
    /* 1CCC2C 002CCC2C 900C048E */  lw         $4, 0xC90($16)
    /* 1CCC30 002CCC30 62004590 */  lbu        $5, 0x62($2)
    /* 1CCC34 002CCC34 2D300000 */  daddu      $6, $0, $0
    /* 1CCC38 002CCC38 2D380000 */  daddu      $7, $0, $0
    /* 1CCC3C 002CCC3C 05000824 */  addiu      $8, $0, 0x5
    /* 1CCC40 002CCC40 2D480000 */  daddu      $9, $0, $0
    /* 1CCC44 002CCC44 98810B0C */  jal        func_002e0660
    /* 1CCC48 002CCC48 00000000 */   nop
    /* 1CCC4C 002CCC4C C80D048E */  lw         $4, 0xDC8($16)
    /* 1CCC50 002CCC50 38810B0C */  jal        func_002e04e0
    /* 1CCC54 002CCC54 00000000 */   nop
    /* 1CCC58 002CCC58 C80D048E */  lw         $4, 0xDC8($16)
    /* 1CCC5C 002CCC5C 62004590 */  lbu        $5, 0x62($2)
    /* 1CCC60 002CCC60 2D300000 */  daddu      $6, $0, $0
    /* 1CCC64 002CCC64 2D380000 */  daddu      $7, $0, $0
    /* 1CCC68 002CCC68 05000824 */  addiu      $8, $0, 0x5
    /* 1CCC6C 002CCC6C 2D480000 */  daddu      $9, $0, $0
    /* 1CCC70 002CCC70 98810B0C */  jal        func_002e0660
    /* 1CCC74 002CCC74 00000000 */   nop
    /* 1CCC78 002CCC78 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CCC7C 002CCC7C 38810B0C */  jal        func_002e04e0
    /* 1CCC80 002CCC80 00000000 */   nop
    /* 1CCC84 002CCC84 D00D048E */  lw         $4, 0xDD0($16)
    /* 1CCC88 002CCC88 62004590 */  lbu        $5, 0x62($2)
    /* 1CCC8C 002CCC8C 2D300000 */  daddu      $6, $0, $0
    /* 1CCC90 002CCC90 2D380000 */  daddu      $7, $0, $0
    /* 1CCC94 002CCC94 05000824 */  addiu      $8, $0, 0x5
    /* 1CCC98 002CCC98 2D480000 */  daddu      $9, $0, $0
    /* 1CCC9C 002CCC9C 98810B0C */  jal        func_002e0660
    /* 1CCCA0 002CCCA0 00000000 */   nop
    /* 1CCCA4 002CCCA4 6400113C */  lui        $17, %hi(D_0063F5B8)
    /* 1CCCA8 002CCCA8 B8F53126 */  addiu      $17, $17, %lo(D_0063F5B8)
    /* 1CCCAC 002CCCAC B801A427 */  addiu      $4, $29, 0x1B8
    /* 1CCCB0 002CCCB0 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CCCB4 002CCCB4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CCCB8 002CCCB8 5CCA0A0C */  jal        func_002b2970
    /* 1CCCBC 002CCCBC 00000000 */   nop
    /* 1CCCC0 002CCCC0 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1CCCC4 002CCCC4 9643023C */  lui        $2, (0x43960000 >> 16)
    /* 1CCCC8 002CCCC8 00008244 */  mtc1       $2, $f0
    /* 1CCCCC 002CCCCC 00000000 */  nop
    /* 1CCCD0 002CCCD0 40030146 */  add.s      $f13, $f0, $f1
    /* 1CCCD4 002CCCD4 B001A427 */  addiu      $4, $29, 0x1B0
    /* 1CCCD8 002CCCD8 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CCCDC 002CCCDC 5CCA0A0C */  jal        func_002b2970
    /* 1CCCE0 002CCCE0 00000000 */   nop
    /* 1CCCE4 002CCCE4 640C048E */  lw         $4, 0xC64($16)
    /* 1CCCE8 002CCCE8 B801A5DF */  ld         $5, 0x1B8($29)
    /* 1CCCEC 002CCCEC B001A6DF */  ld         $6, 0x1B0($29)
    /* 1CCCF0 002CCCF0 2D380000 */  daddu      $7, $0, $0
    /* 1CCCF4 002CCCF4 0A000824 */  addiu      $8, $0, 0xA
    /* 1CCCF8 002CCCF8 2D480000 */  daddu      $9, $0, $0
    /* 1CCCFC 002CCCFC 88810B0C */  jal        func_002e0620
    /* 1CCD00 002CCD00 00000000 */   nop
    /* 1CCD04 002CCD04 640C048E */  lw         $4, 0xC64($16)
    /* 1CCD08 002CCD08 38810B0C */  jal        func_002e04e0
    /* 1CCD0C 002CCD0C 00000000 */   nop
    /* 1CCD10 002CCD10 640C048E */  lw         $4, 0xC64($16)
    /* 1CCD14 002CCD14 62004590 */  lbu        $5, 0x62($2)
    /* 1CCD18 002CCD18 2D300000 */  daddu      $6, $0, $0
    /* 1CCD1C 002CCD1C 2D380000 */  daddu      $7, $0, $0
    /* 1CCD20 002CCD20 0A000824 */  addiu      $8, $0, 0xA
    /* 1CCD24 002CCD24 2D480000 */  daddu      $9, $0, $0
    /* 1CCD28 002CCD28 98810B0C */  jal        func_002e0660
    /* 1CCD2C 002CCD2C 00000000 */   nop
    /* 1CCD30 002CCD30 6400113C */  lui        $17, %hi(D_0063F5A0)
    /* 1CCD34 002CCD34 A0F53126 */  addiu      $17, $17, %lo(D_0063F5A0)
    /* 1CCD38 002CCD38 2243023C */  lui        $2, (0x43220000 >> 16)
    /* 1CCD3C 002CCD3C 00608244 */  mtc1       $2, $f12
    /* 1CCD40 002CCD40 580C048E */  lw         $4, 0xC58($16)
    /* 1CCD44 002CCD44 40000524 */  addiu      $5, $0, 0x40
    /* 1CCD48 002CCD48 78820B0C */  jal        func_002e09e0
    /* 1CCD4C 002CCD4C 00000000 */   nop
    /* 1CCD50 002CCD50 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1CCD54 002CCD54 E143023C */  lui        $2, (0x43E10000 >> 16)
    /* 1CCD58 002CCD58 00008244 */  mtc1       $2, $f0
    /* 1CCD5C 002CCD5C 00000000 */  nop
    /* 1CCD60 002CCD60 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1CCD64 002CCD64 A801A427 */  addiu      $4, $29, 0x1A8
    /* 1CCD68 002CCD68 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CCD6C 002CCD6C 5CCA0A0C */  jal        func_002b2970
    /* 1CCD70 002CCD70 00000000 */   nop
    /* 1CCD74 002CCD74 A001A427 */  addiu      $4, $29, 0x1A0
    /* 1CCD78 002CCD78 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CCD7C 002CCD7C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CCD80 002CCD80 5CCA0A0C */  jal        func_002b2970
    /* 1CCD84 002CCD84 00000000 */   nop
    /* 1CCD88 002CCD88 580C048E */  lw         $4, 0xC58($16)
    /* 1CCD8C 002CCD8C A801A5DF */  ld         $5, 0x1A8($29)
    /* 1CCD90 002CCD90 A001A6DF */  ld         $6, 0x1A0($29)
    /* 1CCD94 002CCD94 2D380000 */  daddu      $7, $0, $0
    /* 1CCD98 002CCD98 04000824 */  addiu      $8, $0, 0x4
    /* 1CCD9C 002CCD9C 2D480000 */  daddu      $9, $0, $0
    /* 1CCDA0 002CCDA0 88810B0C */  jal        func_002e0620
    /* 1CCDA4 002CCDA4 00000000 */   nop
    /* 1CCDA8 002CCDA8 580C048E */  lw         $4, 0xC58($16)
    /* 1CCDAC 002CCDAC 2D280000 */  daddu      $5, $0, $0
    /* 1CCDB0 002CCDB0 CC000624 */  addiu      $6, $0, 0xCC
    /* 1CCDB4 002CCDB4 2D380000 */  daddu      $7, $0, $0
    /* 1CCDB8 002CCDB8 02000824 */  addiu      $8, $0, 0x2
    /* 1CCDBC 002CCDBC 2D480000 */  daddu      $9, $0, $0
    /* 1CCDC0 002CCDC0 98810B0C */  jal        func_002e0660
    /* 1CCDC4 002CCDC4 00000000 */   nop
    /* 1CCDC8 002CCDC8 1802A427 */  addiu      $4, $29, 0x218
    /* 1CCDCC 002CCDCC 2D280000 */  daddu      $5, $0, $0
    /* 1CCDD0 002CCDD0 2D300000 */  daddu      $6, $0, $0
    /* 1CCDD4 002CCDD4 2D380000 */  daddu      $7, $0, $0
    /* 1CCDD8 002CCDD8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CCDDC 002CCDDC 98CA0A0C */  jal        func_002b2a60
    /* 1CCDE0 002CCDE0 00000000 */   nop
    /* 1CCDE4 002CCDE4 580C048E */  lw         $4, 0xC58($16)
    /* 1CCDE8 002CCDE8 38810B0C */  jal        func_002e04e0
    /* 1CCDEC 002CCDEC 00000000 */   nop
    /* 1CCDF0 002CCDF0 1802A693 */  lbu        $6, 0x218($29)
    /* 1CCDF4 002CCDF4 1902A593 */  lbu        $5, 0x219($29)
    /* 1CCDF8 002CCDF8 1A02A493 */  lbu        $4, 0x21A($29)
    /* 1CCDFC 002CCDFC 1B02A393 */  lbu        $3, 0x21B($29)
    /* 1CCE00 002CCE00 790046A0 */  sb         $6, 0x79($2)
    /* 1CCE04 002CCE04 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CCE08 002CCE08 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CCE0C 002CCE0C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CCE10 002CCE10 6400113C */  lui        $17, %hi(D_0063F5A8)
    /* 1CCE14 002CCE14 A8F53126 */  addiu      $17, $17, %lo(D_0063F5A8)
    /* 1CCE18 002CCE18 2343023C */  lui        $2, (0x43230000 >> 16)
    /* 1CCE1C 002CCE1C 00608244 */  mtc1       $2, $f12
    /* 1CCE20 002CCE20 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1CCE24 002CCE24 40000524 */  addiu      $5, $0, 0x40
    /* 1CCE28 002CCE28 78820B0C */  jal        func_002e09e0
    /* 1CCE2C 002CCE2C 00000000 */   nop
    /* 1CCE30 002CCE30 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1CCE34 002CCE34 E143023C */  lui        $2, (0x43E10000 >> 16)
    /* 1CCE38 002CCE38 00008244 */  mtc1       $2, $f0
    /* 1CCE3C 002CCE3C 00000000 */  nop
    /* 1CCE40 002CCE40 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1CCE44 002CCE44 9801A427 */  addiu      $4, $29, 0x198
    /* 1CCE48 002CCE48 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CCE4C 002CCE4C 5CCA0A0C */  jal        func_002b2970
    /* 1CCE50 002CCE50 00000000 */   nop
    /* 1CCE54 002CCE54 9001A427 */  addiu      $4, $29, 0x190
    /* 1CCE58 002CCE58 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CCE5C 002CCE5C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CCE60 002CCE60 5CCA0A0C */  jal        func_002b2970
    /* 1CCE64 002CCE64 00000000 */   nop
    /* 1CCE68 002CCE68 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1CCE6C 002CCE6C 9801A5DF */  ld         $5, 0x198($29)
    /* 1CCE70 002CCE70 9001A6DF */  ld         $6, 0x190($29)
    /* 1CCE74 002CCE74 2D380000 */  daddu      $7, $0, $0
    /* 1CCE78 002CCE78 04000824 */  addiu      $8, $0, 0x4
    /* 1CCE7C 002CCE7C 2D480000 */  daddu      $9, $0, $0
    /* 1CCE80 002CCE80 88810B0C */  jal        func_002e0620
    /* 1CCE84 002CCE84 00000000 */   nop
    /* 1CCE88 002CCE88 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1CCE8C 002CCE8C 2D280000 */  daddu      $5, $0, $0
    /* 1CCE90 002CCE90 CC000624 */  addiu      $6, $0, 0xCC
    /* 1CCE94 002CCE94 2D380000 */  daddu      $7, $0, $0
    /* 1CCE98 002CCE98 02000824 */  addiu      $8, $0, 0x2
    /* 1CCE9C 002CCE9C 2D480000 */  daddu      $9, $0, $0
    /* 1CCEA0 002CCEA0 98810B0C */  jal        func_002e0660
    /* 1CCEA4 002CCEA4 00000000 */   nop
    /* 1CCEA8 002CCEA8 1402A427 */  addiu      $4, $29, 0x214
    /* 1CCEAC 002CCEAC 2D280000 */  daddu      $5, $0, $0
    /* 1CCEB0 002CCEB0 2D300000 */  daddu      $6, $0, $0
    /* 1CCEB4 002CCEB4 2D380000 */  daddu      $7, $0, $0
    /* 1CCEB8 002CCEB8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1CCEBC 002CCEBC 98CA0A0C */  jal        func_002b2a60
    /* 1CCEC0 002CCEC0 00000000 */   nop
    /* 1CCEC4 002CCEC4 5C0C048E */  lw         $4, 0xC5C($16)
    /* 1CCEC8 002CCEC8 38810B0C */  jal        func_002e04e0
    /* 1CCECC 002CCECC 00000000 */   nop
    /* 1CCED0 002CCED0 1402A693 */  lbu        $6, 0x214($29)
    /* 1CCED4 002CCED4 1502A593 */  lbu        $5, 0x215($29)
    /* 1CCED8 002CCED8 1602A493 */  lbu        $4, 0x216($29)
    /* 1CCEDC 002CCEDC 1702A393 */  lbu        $3, 0x217($29)
    /* 1CCEE0 002CCEE0 790046A0 */  sb         $6, 0x79($2)
    /* 1CCEE4 002CCEE4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CCEE8 002CCEE8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CCEEC 002CCEEC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CCEF0 002CCEF0 2D300000 */  daddu      $6, $0, $0
    /* 1CCEF4 002CCEF4 06000524 */  addiu      $5, $0, 0x6
    /* 1CCEF8 002CCEF8 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CCEFC 002CCEFC 0C000010 */  b          .L002CCF30
    /* 1CCF00 002CCF00 00000000 */   nop
  .L002CCF04:
    /* 1CCF04 002CCF04 3C1C0600 */  dsll32     $3, $6, 16
    /* 1CCF08 002CCF08 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CCF0C 002CCF0C 40100300 */  sll        $2, $3, 1
    /* 1CCF10 002CCF10 21100202 */  addu       $2, $16, $2
    /* 1CCF14 002CCF14 460F40A4 */  sh         $0, 0xF46($2)
    /* 1CCF18 002CCF18 580F45A4 */  sh         $5, 0xF58($2)
    /* 1CCF1C 002CCF1C 21100302 */  addu       $2, $16, $3
    /* 1CCF20 002CCF20 6A0F44A0 */  sb         $4, 0xF6A($2)
    /* 1CCF24 002CCF24 0100C224 */  addiu      $2, $6, 0x1
    /* 1CCF28 002CCF28 3C340200 */  dsll32     $6, $2, 16
    /* 1CCF2C 002CCF2C 3F340600 */  dsra32     $6, $6, 16
  .L002CCF30:
    /* 1CCF30 002CCF30 3C1C0600 */  dsll32     $3, $6, 16
    /* 1CCF34 002CCF34 3F1C0300 */  dsra32     $3, $3, 16
    /* 1CCF38 002CCF38 09000282 */  lb         $2, 0x9($16)
    /* 1CCF3C 002CCF3C 2A106200 */  slt        $2, $3, $2
    /* 1CCF40 002CCF40 F0FF4014 */  bnez       $2, .L002CCF04
    /* 1CCF44 002CCF44 00000000 */   nop
    /* 1CCF48 002CCF48 D40E048E */  lw         $4, 0xED4($16)
    /* 1CCF4C 002CCF4C 2D280000 */  daddu      $5, $0, $0
    /* 1CCF50 002CCF50 2D300000 */  daddu      $6, $0, $0
    /* 1CCF54 002CCF54 3C810B0C */  jal        func_002e04f0
    /* 1CCF58 002CCF58 00000000 */   nop
    /* 1CCF5C 002CCF5C D40E048E */  lw         $4, 0xED4($16)
    /* 1CCF60 002CCF60 2D280000 */  daddu      $5, $0, $0
    /* 1CCF64 002CCF64 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CCF68 002CCF68 2D380000 */  daddu      $7, $0, $0
    /* 1CCF6C 002CCF6C 04000824 */  addiu      $8, $0, 0x4
    /* 1CCF70 002CCF70 2D480000 */  daddu      $9, $0, $0
    /* 1CCF74 002CCF74 98810B0C */  jal        func_002e0660
    /* 1CCF78 002CCF78 00000000 */   nop
    /* 1CCF7C 002CCF7C 08000282 */  lb         $2, 0x8($16)
    /* 1CCF80 002CCF80 00008244 */  mtc1       $2, $f0
    /* 1CCF84 002CCF84 00000000 */  nop
    /* 1CCF88 002CCF88 E0008046 */  cvt.s.w    $f3, $f0
    /* 1CCF8C 002CCF8C 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1CCF90 002CCF90 00108244 */  mtc1       $2, $f2
    /* 1CCF94 002CCF94 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1CCF98 002CCF98 00088244 */  mtc1       $2, $f1
    /* 1CCF9C 002CCF9C 00008044 */  mtc1       $0, $f0
    /* 1CCFA0 002CCFA0 00000000 */  nop
    /* 1CCFA4 002CCFA4 18000146 */  adda.s     $f0, $f1
    /* 1CCFA8 002CCFA8 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1CCFAC 002CCFAC 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1CCFB0 002CCFB0 00608244 */  mtc1       $2, $f12
    /* 1CCFB4 002CCFB4 8801A427 */  addiu      $4, $29, 0x188
    /* 1CCFB8 002CCFB8 5CCA0A0C */  jal        func_002b2970
    /* 1CCFBC 002CCFBC 00000000 */   nop
    /* 1CCFC0 002CCFC0 D40E048E */  lw         $4, 0xED4($16)
    /* 1CCFC4 002CCFC4 38810B0C */  jal        func_002e04e0
    /* 1CCFC8 002CCFC8 00000000 */   nop
    /* 1CCFCC 002CCFCC 8801A1C7 */  lwc1       $f1, 0x188($29)
    /* 1CCFD0 002CCFD0 8C01A0C7 */  lwc1       $f0, 0x18C($29)
    /* 1CCFD4 002CCFD4 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1CCFD8 002CCFD8 300040E4 */  swc1       $f0, 0x30($2)
    /* 1CCFDC 002CCFDC D80E048E */  lw         $4, 0xED8($16)
    /* 1CCFE0 002CCFE0 2D280000 */  daddu      $5, $0, $0
    /* 1CCFE4 002CCFE4 2D300000 */  daddu      $6, $0, $0
    /* 1CCFE8 002CCFE8 3C810B0C */  jal        func_002e04f0
    /* 1CCFEC 002CCFEC 00000000 */   nop
    /* 1CCFF0 002CCFF0 D80E048E */  lw         $4, 0xED8($16)
    /* 1CCFF4 002CCFF4 2D280000 */  daddu      $5, $0, $0
    /* 1CCFF8 002CCFF8 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CCFFC 002CCFFC 2D380000 */  daddu      $7, $0, $0
    /* 1CD000 002CD000 04000824 */  addiu      $8, $0, 0x4
    /* 1CD004 002CD004 2D480000 */  daddu      $9, $0, $0
    /* 1CD008 002CD008 98810B0C */  jal        func_002e0660
    /* 1CD00C 002CD00C 00000000 */   nop
    /* 1CD010 002CD010 08000282 */  lb         $2, 0x8($16)
    /* 1CD014 002CD014 00008244 */  mtc1       $2, $f0
    /* 1CD018 002CD018 00000000 */  nop
    /* 1CD01C 002CD01C E0008046 */  cvt.s.w    $f3, $f0
    /* 1CD020 002CD020 0C42023C */  lui        $2, (0x420C0000 >> 16)
    /* 1CD024 002CD024 00108244 */  mtc1       $2, $f2
    /* 1CD028 002CD028 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1CD02C 002CD02C 00088244 */  mtc1       $2, $f1
    /* 1CD030 002CD030 00008044 */  mtc1       $0, $f0
    /* 1CD034 002CD034 00000000 */  nop
    /* 1CD038 002CD038 18000146 */  adda.s     $f0, $f1
    /* 1CD03C 002CD03C 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1CD040 002CD040 FC42023C */  lui        $2, (0x42FC0000 >> 16)
    /* 1CD044 002CD044 00608244 */  mtc1       $2, $f12
    /* 1CD048 002CD048 8001A427 */  addiu      $4, $29, 0x180
    /* 1CD04C 002CD04C 5CCA0A0C */  jal        func_002b2970
    /* 1CD050 002CD050 00000000 */   nop
    /* 1CD054 002CD054 D80E048E */  lw         $4, 0xED8($16)
    /* 1CD058 002CD058 38810B0C */  jal        func_002e04e0
    /* 1CD05C 002CD05C 00000000 */   nop
    /* 1CD060 002CD060 8001A1C7 */  lwc1       $f1, 0x180($29)
    /* 1CD064 002CD064 8401A0C7 */  lwc1       $f0, 0x184($29)
    /* 1CD068 002CD068 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1CD06C 002CD06C 300040E4 */  swc1       $f0, 0x30($2)
    /* 1CD070 002CD070 2D20A002 */  daddu      $4, $21, $0
    /* 1CD074 002CD074 F0600B0C */  jal        func_002d83c0
    /* 1CD078 002CD078 00000000 */   nop
    /* 1CD07C 002CD07C 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1CD080 002CD080 00608244 */  mtc1       $2, $f12
    /* 1CD084 002CD084 3C0D048E */  lw         $4, 0xD3C($16)
    /* 1CD088 002CD088 41000524 */  addiu      $5, $0, 0x41
    /* 1CD08C 002CD08C 78820B0C */  jal        func_002e09e0
    /* 1CD090 002CD090 00000000 */   nop
    /* 1CD094 002CD094 3C0D048E */  lw         $4, 0xD3C($16)
    /* 1CD098 002CD098 2D280000 */  daddu      $5, $0, $0
    /* 1CD09C 002CD09C FF000624 */  addiu      $6, $0, 0xFF
    /* 1CD0A0 002CD0A0 2D380000 */  daddu      $7, $0, $0
    /* 1CD0A4 002CD0A4 0A000824 */  addiu      $8, $0, 0xA
    /* 1CD0A8 002CD0A8 2D480000 */  daddu      $9, $0, $0
    /* 1CD0AC 002CD0AC 98810B0C */  jal        func_002e0660
    /* 1CD0B0 002CD0B0 00000000 */   nop
    /* 1CD0B4 002CD0B4 6400113C */  lui        $17, %hi(D_0063F7B0)
    /* 1CD0B8 002CD0B8 B0F73126 */  addiu      $17, $17, %lo(D_0063F7B0)
    /* 1CD0BC 002CD0BC 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1CD0C0 002CD0C0 00608244 */  mtc1       $2, $f12
    /* 1CD0C4 002CD0C4 600D048E */  lw         $4, 0xD60($16)
    /* 1CD0C8 002CD0C8 41000524 */  addiu      $5, $0, 0x41
    /* 1CD0CC 002CD0CC 78820B0C */  jal        func_002e09e0
    /* 1CD0D0 002CD0D0 00000000 */   nop
    /* 1CD0D4 002CD0D4 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1CD0D8 002CD0D8 26020224 */  addiu      $2, $0, 0x226
    /* 1CD0DC 002CD0DC 00008244 */  mtc1       $2, $f0
    /* 1CD0E0 002CD0E0 00000000 */  nop
    /* 1CD0E4 002CD0E4 20008046 */  cvt.s.w    $f0, $f0
    /* 1CD0E8 002CD0E8 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1CD0EC 002CD0EC 7801A427 */  addiu      $4, $29, 0x178
    /* 1CD0F0 002CD0F0 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CD0F4 002CD0F4 5CCA0A0C */  jal        func_002b2970
    /* 1CD0F8 002CD0F8 00000000 */   nop
    /* 1CD0FC 002CD0FC 7001A427 */  addiu      $4, $29, 0x170
    /* 1CD100 002CD100 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CD104 002CD104 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CD108 002CD108 5CCA0A0C */  jal        func_002b2970
    /* 1CD10C 002CD10C 00000000 */   nop
    /* 1CD110 002CD110 600D048E */  lw         $4, 0xD60($16)
    /* 1CD114 002CD114 7801A5DF */  ld         $5, 0x178($29)
    /* 1CD118 002CD118 7001A6DF */  ld         $6, 0x170($29)
    /* 1CD11C 002CD11C 02000724 */  addiu      $7, $0, 0x2
    /* 1CD120 002CD120 04000824 */  addiu      $8, $0, 0x4
    /* 1CD124 002CD124 2D480000 */  daddu      $9, $0, $0
    /* 1CD128 002CD128 88810B0C */  jal        func_002e0620
    /* 1CD12C 002CD12C 00000000 */   nop
    /* 1CD130 002CD130 600D048E */  lw         $4, 0xD60($16)
    /* 1CD134 002CD134 38810B0C */  jal        func_002e04e0
    /* 1CD138 002CD138 00000000 */   nop
    /* 1CD13C 002CD13C 020140A4 */  sh         $0, 0x102($2)
    /* 1CD140 002CD140 3C8C0000 */  dsll32     $17, $0, 16
    /* 1CD144 002CD144 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CD148 002CD148 600D048E */  lw         $4, 0xD60($16)
    /* 1CD14C 002CD14C 38810B0C */  jal        func_002e04e0
    /* 1CD150 002CD150 00000000 */   nop
    /* 1CD154 002CD154 000151A4 */  sh         $17, 0x100($2)
    /* 1CD158 002CD158 A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* 1CD15C 002CD15C 00608244 */  mtc1       $2, $f12
    /* 1CD160 002CD160 600D048E */  lw         $4, 0xD60($16)
    /* 1CD164 002CD164 2C858DC7 */  lwc1       $f13, -0x7AD4($28)
    /* 1CD168 002CD168 02000524 */  addiu      $5, $0, 0x2
    /* 1CD16C 002CD16C 2D30A000 */  daddu      $6, $5, $0
    /* 1CD170 002CD170 2D38A000 */  daddu      $7, $5, $0
    /* 1CD174 002CD174 50820B0C */  jal        func_002e0940
    /* 1CD178 002CD178 00000000 */   nop
    /* 1CD17C 002CD17C 1002A427 */  addiu      $4, $29, 0x210
    /* 1CD180 002CD180 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CD184 002CD184 96000624 */  addiu      $6, $0, 0x96
    /* 1CD188 002CD188 2D380000 */  daddu      $7, $0, $0
    /* 1CD18C 002CD18C 2D40A000 */  daddu      $8, $5, $0
    /* 1CD190 002CD190 98CA0A0C */  jal        func_002b2a60
    /* 1CD194 002CD194 00000000 */   nop
    /* 1CD198 002CD198 600D048E */  lw         $4, 0xD60($16)
    /* 1CD19C 002CD19C 38810B0C */  jal        func_002e04e0
    /* 1CD1A0 002CD1A0 00000000 */   nop
    /* 1CD1A4 002CD1A4 1002A693 */  lbu        $6, 0x210($29)
    /* 1CD1A8 002CD1A8 1102A593 */  lbu        $5, 0x211($29)
    /* 1CD1AC 002CD1AC 1202A493 */  lbu        $4, 0x212($29)
    /* 1CD1B0 002CD1B0 1302A393 */  lbu        $3, 0x213($29)
    /* 1CD1B4 002CD1B4 790046A0 */  sb         $6, 0x79($2)
    /* 1CD1B8 002CD1B8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CD1BC 002CD1BC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CD1C0 002CD1C0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CD1C4 002CD1C4 6400113C */  lui        $17, %hi(D_0063F7B8)
    /* 1CD1C8 002CD1C8 B8F73126 */  addiu      $17, $17, %lo(D_0063F7B8)
    /* 1CD1CC 002CD1CC 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1CD1D0 002CD1D0 00608244 */  mtc1       $2, $f12
    /* 1CD1D4 002CD1D4 640D048E */  lw         $4, 0xD64($16)
    /* 1CD1D8 002CD1D8 41000524 */  addiu      $5, $0, 0x41
    /* 1CD1DC 002CD1DC 78820B0C */  jal        func_002e09e0
    /* 1CD1E0 002CD1E0 00000000 */   nop
    /* 1CD1E4 002CD1E4 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1CD1E8 002CD1E8 26020224 */  addiu      $2, $0, 0x226
    /* 1CD1EC 002CD1EC 00008244 */  mtc1       $2, $f0
    /* 1CD1F0 002CD1F0 00000000 */  nop
    /* 1CD1F4 002CD1F4 20008046 */  cvt.s.w    $f0, $f0
    /* 1CD1F8 002CD1F8 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1CD1FC 002CD1FC 6801A427 */  addiu      $4, $29, 0x168
    /* 1CD200 002CD200 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CD204 002CD204 5CCA0A0C */  jal        func_002b2970
    /* 1CD208 002CD208 00000000 */   nop
    /* 1CD20C 002CD20C 6001A427 */  addiu      $4, $29, 0x160
    /* 1CD210 002CD210 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CD214 002CD214 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CD218 002CD218 5CCA0A0C */  jal        func_002b2970
    /* 1CD21C 002CD21C 00000000 */   nop
    /* 1CD220 002CD220 640D048E */  lw         $4, 0xD64($16)
    /* 1CD224 002CD224 6801A5DF */  ld         $5, 0x168($29)
    /* 1CD228 002CD228 6001A6DF */  ld         $6, 0x160($29)
    /* 1CD22C 002CD22C 02000724 */  addiu      $7, $0, 0x2
    /* 1CD230 002CD230 04000824 */  addiu      $8, $0, 0x4
    /* 1CD234 002CD234 2D480000 */  daddu      $9, $0, $0
    /* 1CD238 002CD238 88810B0C */  jal        func_002e0620
    /* 1CD23C 002CD23C 00000000 */   nop
    /* 1CD240 002CD240 CEFF1124 */  addiu      $17, $0, -0x32
    /* 1CD244 002CD244 640D048E */  lw         $4, 0xD64($16)
    /* 1CD248 002CD248 38810B0C */  jal        func_002e04e0
    /* 1CD24C 002CD24C 00000000 */   nop
    /* 1CD250 002CD250 000151A4 */  sh         $17, 0x100($2)
    /* 1CD254 002CD254 25FF1124 */  addiu      $17, $0, -0xDB
    /* 1CD258 002CD258 640D048E */  lw         $4, 0xD64($16)
    /* 1CD25C 002CD25C 38810B0C */  jal        func_002e04e0
    /* 1CD260 002CD260 00000000 */   nop
    /* 1CD264 002CD264 020151A4 */  sh         $17, 0x102($2)
    /* 1CD268 002CD268 A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* 1CD26C 002CD26C 00608244 */  mtc1       $2, $f12
    /* 1CD270 002CD270 640D048E */  lw         $4, 0xD64($16)
    /* 1CD274 002CD274 2C858DC7 */  lwc1       $f13, -0x7AD4($28)
    /* 1CD278 002CD278 02000524 */  addiu      $5, $0, 0x2
    /* 1CD27C 002CD27C 2D30A000 */  daddu      $6, $5, $0
    /* 1CD280 002CD280 2D38A000 */  daddu      $7, $5, $0
    /* 1CD284 002CD284 50820B0C */  jal        func_002e0940
    /* 1CD288 002CD288 00000000 */   nop
    /* 1CD28C 002CD28C 6400113C */  lui        $17, %hi(D_0063F8C0)
    /* 1CD290 002CD290 C0F83126 */  addiu      $17, $17, %lo(D_0063F8C0)
    /* 1CD294 002CD294 3842023C */  lui        $2, (0x42380000 >> 16)
    /* 1CD298 002CD298 00608244 */  mtc1       $2, $f12
    /* 1CD29C 002CD29C E80D048E */  lw         $4, 0xDE8($16)
    /* 1CD2A0 002CD2A0 41000524 */  addiu      $5, $0, 0x41
    /* 1CD2A4 002CD2A4 78820B0C */  jal        func_002e09e0
    /* 1CD2A8 002CD2A8 00000000 */   nop
    /* 1CD2AC 002CD2AC E80D048E */  lw         $4, 0xDE8($16)
    /* 1CD2B0 002CD2B0 2D280000 */  daddu      $5, $0, $0
    /* 1CD2B4 002CD2B4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CD2B8 002CD2B8 2D380000 */  daddu      $7, $0, $0
    /* 1CD2BC 002CD2BC 06000824 */  addiu      $8, $0, 0x6
    /* 1CD2C0 002CD2C0 2D480000 */  daddu      $9, $0, $0
    /* 1CD2C4 002CD2C4 98810B0C */  jal        func_002e0660
    /* 1CD2C8 002CD2C8 00000000 */   nop
    /* 1CD2CC 002CD2CC 000034C6 */  lwc1       $f20, 0x0($17)
    /* 1CD2D0 002CD2D0 E80D048E */  lw         $4, 0xDE8($16)
    /* 1CD2D4 002CD2D4 38810B0C */  jal        func_002e04e0
    /* 1CD2D8 002CD2D8 00000000 */   nop
    /* 1CD2DC 002CD2DC 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1CD2E0 002CD2E0 040034C6 */  lwc1       $f20, 0x4($17)
    /* 1CD2E4 002CD2E4 E80D048E */  lw         $4, 0xDE8($16)
    /* 1CD2E8 002CD2E8 38810B0C */  jal        func_002e04e0
    /* 1CD2EC 002CD2EC 00000000 */   nop
    /* 1CD2F0 002CD2F0 300054E4 */  swc1       $f20, 0x30($2)
    /* 1CD2F4 002CD2F4 3C42023C */  lui        $2, (0x423C0000 >> 16)
    /* 1CD2F8 002CD2F8 00608244 */  mtc1       $2, $f12
    /* 1CD2FC 002CD2FC F00D048E */  lw         $4, 0xDF0($16)
    /* 1CD300 002CD300 41000524 */  addiu      $5, $0, 0x41
    /* 1CD304 002CD304 78820B0C */  jal        func_002e09e0
    /* 1CD308 002CD308 00000000 */   nop
    /* 1CD30C 002CD30C F00D048E */  lw         $4, 0xDF0($16)
    /* 1CD310 002CD310 2D280000 */  daddu      $5, $0, $0
    /* 1CD314 002CD314 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CD318 002CD318 2D380000 */  daddu      $7, $0, $0
    /* 1CD31C 002CD31C 06000824 */  addiu      $8, $0, 0x6
    /* 1CD320 002CD320 2D480000 */  daddu      $9, $0, $0
    /* 1CD324 002CD324 98810B0C */  jal        func_002e0660
    /* 1CD328 002CD328 00000000 */   nop
    /* 1CD32C 002CD32C 1343023C */  lui        $2, (0x43130000 >> 16)
    /* 1CD330 002CD330 00A08244 */  mtc1       $2, $f20
    /* 1CD334 002CD334 F00D048E */  lw         $4, 0xDF0($16)
    /* 1CD338 002CD338 38810B0C */  jal        func_002e04e0
    /* 1CD33C 002CD33C 00000000 */   nop
    /* 1CD340 002CD340 2C0054E4 */  swc1       $f20, 0x2C($2)
    /* 1CD344 002CD344 BC43023C */  lui        $2, (0x43BC0000 >> 16)
    /* 1CD348 002CD348 00A08244 */  mtc1       $2, $f20
    /* 1CD34C 002CD34C F00D048E */  lw         $4, 0xDF0($16)
    /* 1CD350 002CD350 38810B0C */  jal        func_002e04e0
    /* 1CD354 002CD354 00000000 */   nop
    /* 1CD358 002CD358 300054E4 */  swc1       $f20, 0x30($2)
    /* 1CD35C 002CD35C 280F048E */  lw         $4, 0xF28($16)
    /* 1CD360 002CD360 44000524 */  addiu      $5, $0, 0x44
    /* 1CD364 002CD364 80B4110C */  jal        func_0046d200
    /* 1CD368 002CD368 00000000 */   nop
    /* 1CD36C 002CD36C 2D884000 */  daddu      $17, $2, $0
    /* 1CD370 002CD370 6400123C */  lui        $18, %hi(D_0063F780)
    /* 1CD374 002CD374 80F75226 */  addiu      $18, $18, %lo(D_0063F780)
    /* 1CD378 002CD378 5442023C */  lui        $2, (0x42540000 >> 16)
    /* 1CD37C 002CD37C 00608244 */  mtc1       $2, $f12
    /* 1CD380 002CD380 480D048E */  lw         $4, 0xD48($16)
    /* 1CD384 002CD384 56000524 */  addiu      $5, $0, 0x56
    /* 1CD388 002CD388 78820B0C */  jal        func_002e09e0
    /* 1CD38C 002CD38C 00000000 */   nop
    /* 1CD390 002CD390 02C3023C */  lui        $2, (0xC3020000 >> 16)
    /* 1CD394 002CD394 00688244 */  mtc1       $2, $f13
    /* 1CD398 002CD398 5801A427 */  addiu      $4, $29, 0x158
    /* 1CD39C 002CD39C 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD3A0 002CD3A0 5CCA0A0C */  jal        func_002b2970
    /* 1CD3A4 002CD3A4 00000000 */   nop
    /* 1CD3A8 002CD3A8 5001A427 */  addiu      $4, $29, 0x150
    /* 1CD3AC 002CD3AC 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD3B0 002CD3B0 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CD3B4 002CD3B4 5CCA0A0C */  jal        func_002b2970
    /* 1CD3B8 002CD3B8 00000000 */   nop
    /* 1CD3BC 002CD3BC 480D048E */  lw         $4, 0xD48($16)
    /* 1CD3C0 002CD3C0 5801A5DF */  ld         $5, 0x158($29)
    /* 1CD3C4 002CD3C4 5001A6DF */  ld         $6, 0x150($29)
    /* 1CD3C8 002CD3C8 02000724 */  addiu      $7, $0, 0x2
    /* 1CD3CC 002CD3CC 05000824 */  addiu      $8, $0, 0x5
    /* 1CD3D0 002CD3D0 2D480000 */  daddu      $9, $0, $0
    /* 1CD3D4 002CD3D4 88810B0C */  jal        func_002e0620
    /* 1CD3D8 002CD3D8 00000000 */   nop
    /* 1CD3DC 002CD3DC 0C02A427 */  addiu      $4, $29, 0x20C
    /* 1CD3E0 002CD3E0 E4000524 */  addiu      $5, $0, 0xE4
    /* 1CD3E4 002CD3E4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CD3E8 002CD3E8 2D380000 */  daddu      $7, $0, $0
    /* 1CD3EC 002CD3EC 2D40C000 */  daddu      $8, $6, $0
    /* 1CD3F0 002CD3F0 98CA0A0C */  jal        func_002b2a60
    /* 1CD3F4 002CD3F4 00000000 */   nop
    /* 1CD3F8 002CD3F8 480D048E */  lw         $4, 0xD48($16)
    /* 1CD3FC 002CD3FC 38810B0C */  jal        func_002e04e0
    /* 1CD400 002CD400 00000000 */   nop
    /* 1CD404 002CD404 0C02A693 */  lbu        $6, 0x20C($29)
    /* 1CD408 002CD408 0D02A593 */  lbu        $5, 0x20D($29)
    /* 1CD40C 002CD40C 0E02A493 */  lbu        $4, 0x20E($29)
    /* 1CD410 002CD410 0F02A393 */  lbu        $3, 0x20F($29)
    /* 1CD414 002CD414 790046A0 */  sb         $6, 0x79($2)
    /* 1CD418 002CD418 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CD41C 002CD41C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CD420 002CD420 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CD424 002CD424 2D202002 */  daddu      $4, $17, $0
    /* 1CD428 002CD428 98AC110C */  jal        func_0046b260
    /* 1CD42C 002CD42C 00000000 */   nop
    /* 1CD430 002CD430 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD434 002CD434 00088244 */  mtc1       $2, $f1
    /* 1CD438 002CD438 00000000 */  nop
    /* 1CD43C 002CD43C 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD440 002CD440 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD444 002CD444 00000244 */  mfc1       $2, $f0
    /* 1CD448 002CD448 00000000 */  nop
    /* 1CD44C 002CD44C 3C940200 */  dsll32     $18, $2, 16
    /* 1CD450 002CD450 3F941200 */  dsra32     $18, $18, 16
    /* 1CD454 002CD454 480D048E */  lw         $4, 0xD48($16)
    /* 1CD458 002CD458 38810B0C */  jal        func_002e04e0
    /* 1CD45C 002CD45C 00000000 */   nop
    /* 1CD460 002CD460 000152A4 */  sh         $18, 0x100($2)
    /* 1CD464 002CD464 2D202002 */  daddu      $4, $17, $0
    /* 1CD468 002CD468 BCAC110C */  jal        func_0046b2f0
    /* 1CD46C 002CD46C 00000000 */   nop
    /* 1CD470 002CD470 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD474 002CD474 00088244 */  mtc1       $2, $f1
    /* 1CD478 002CD478 00000000 */  nop
    /* 1CD47C 002CD47C 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD480 002CD480 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD484 002CD484 00000244 */  mfc1       $2, $f0
    /* 1CD488 002CD488 00000000 */  nop
    /* 1CD48C 002CD48C 3C940200 */  dsll32     $18, $2, 16
    /* 1CD490 002CD490 3F941200 */  dsra32     $18, $18, 16
    /* 1CD494 002CD494 480D048E */  lw         $4, 0xD48($16)
    /* 1CD498 002CD498 38810B0C */  jal        func_002e04e0
    /* 1CD49C 002CD49C 00000000 */   nop
    /* 1CD4A0 002CD4A0 020152A4 */  sh         $18, 0x102($2)
    /* 1CD4A4 002CD4A4 6400023C */  lui        $2, %hi(D_0063FA44)
    /* 1CD4A8 002CD4A8 44FA4284 */  lh         $2, %lo(D_0063FA44)($2)
    /* 1CD4AC 002CD4AC 00008244 */  mtc1       $2, $f0
    /* 1CD4B0 002CD4B0 00000000 */  nop
    /* 1CD4B4 002CD4B4 20038046 */  cvt.s.w    $f12, $f0
    /* 1CD4B8 002CD4B8 480D048E */  lw         $4, 0xD48($16)
    /* 1CD4BC 002CD4BC 6400023C */  lui        $2, %hi(D_0063FA46)
    /* 1CD4C0 002CD4C0 46FA4584 */  lh         $5, %lo(D_0063FA46)($2)
    /* 1CD4C4 002CD4C4 6C820B0C */  jal        func_002e09b0
    /* 1CD4C8 002CD4C8 00000000 */   nop
    /* 1CD4CC 002CD4CC 00688044 */  mtc1       $0, $f13
    /* 1CD4D0 002CD4D0 6400023C */  lui        $2, %hi(D_0063FA46)
    /* 1CD4D4 002CD4D4 46FA4284 */  lh         $2, %lo(D_0063FA46)($2)
    /* 1CD4D8 002CD4D8 05004624 */  addiu      $6, $2, 0x5
    /* 1CD4DC 002CD4DC 480D048E */  lw         $4, 0xD48($16)
    /* 1CD4E0 002CD4E0 6400023C */  lui        $2, %hi(D_0063FA40)
    /* 1CD4E4 002CD4E4 40FA4CC4 */  lwc1       $f12, %lo(D_0063FA40)($2)
    /* 1CD4E8 002CD4E8 02000524 */  addiu      $5, $0, 0x2
    /* 1CD4EC 002CD4EC 2D380000 */  daddu      $7, $0, $0
    /* 1CD4F0 002CD4F0 50820B0C */  jal        func_002e0940
    /* 1CD4F4 002CD4F4 00000000 */   nop
    /* 1CD4F8 002CD4F8 2D202002 */  daddu      $4, $17, $0
    /* 1CD4FC 002CD4FC A0B4110C */  jal        func_0046d280
    /* 1CD500 002CD500 00000000 */   nop
    /* 1CD504 002CD504 280F048E */  lw         $4, 0xF28($16)
    /* 1CD508 002CD508 43000524 */  addiu      $5, $0, 0x43
    /* 1CD50C 002CD50C 80B4110C */  jal        func_0046d200
    /* 1CD510 002CD510 00000000 */   nop
    /* 1CD514 002CD514 2D984000 */  daddu      $19, $2, $0
    /* 1CD518 002CD518 6400123C */  lui        $18, %hi(D_0063F778)
    /* 1CD51C 002CD51C 78F75226 */  addiu      $18, $18, %lo(D_0063F778)
    /* 1CD520 002CD520 6400113C */  lui        $17, %hi(D_0063FA48)
    /* 1CD524 002CD524 48FA3126 */  addiu      $17, $17, %lo(D_0063FA48)
    /* 1CD528 002CD528 5842023C */  lui        $2, (0x42580000 >> 16)
    /* 1CD52C 002CD52C 00608244 */  mtc1       $2, $f12
    /* 1CD530 002CD530 440D048E */  lw         $4, 0xD44($16)
    /* 1CD534 002CD534 56000524 */  addiu      $5, $0, 0x56
    /* 1CD538 002CD538 78820B0C */  jal        func_002e09e0
    /* 1CD53C 002CD53C 00000000 */   nop
    /* 1CD540 002CD540 3DC3023C */  lui        $2, (0xC33D0000 >> 16)
    /* 1CD544 002CD544 00688244 */  mtc1       $2, $f13
    /* 1CD548 002CD548 4801A427 */  addiu      $4, $29, 0x148
    /* 1CD54C 002CD54C 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD550 002CD550 5CCA0A0C */  jal        func_002b2970
    /* 1CD554 002CD554 00000000 */   nop
    /* 1CD558 002CD558 4001A427 */  addiu      $4, $29, 0x140
    /* 1CD55C 002CD55C 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD560 002CD560 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CD564 002CD564 5CCA0A0C */  jal        func_002b2970
    /* 1CD568 002CD568 00000000 */   nop
    /* 1CD56C 002CD56C 440D048E */  lw         $4, 0xD44($16)
    /* 1CD570 002CD570 4801A5DF */  ld         $5, 0x148($29)
    /* 1CD574 002CD574 4001A6DF */  ld         $6, 0x140($29)
    /* 1CD578 002CD578 02000724 */  addiu      $7, $0, 0x2
    /* 1CD57C 002CD57C 05000824 */  addiu      $8, $0, 0x5
    /* 1CD580 002CD580 03000924 */  addiu      $9, $0, 0x3
    /* 1CD584 002CD584 88810B0C */  jal        func_002e0620
    /* 1CD588 002CD588 00000000 */   nop
    /* 1CD58C 002CD58C 0802A427 */  addiu      $4, $29, 0x208
    /* 1CD590 002CD590 E4000524 */  addiu      $5, $0, 0xE4
    /* 1CD594 002CD594 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CD598 002CD598 2D380000 */  daddu      $7, $0, $0
    /* 1CD59C 002CD59C 2D40C000 */  daddu      $8, $6, $0
    /* 1CD5A0 002CD5A0 98CA0A0C */  jal        func_002b2a60
    /* 1CD5A4 002CD5A4 00000000 */   nop
    /* 1CD5A8 002CD5A8 440D048E */  lw         $4, 0xD44($16)
    /* 1CD5AC 002CD5AC 38810B0C */  jal        func_002e04e0
    /* 1CD5B0 002CD5B0 00000000 */   nop
    /* 1CD5B4 002CD5B4 0802A693 */  lbu        $6, 0x208($29)
    /* 1CD5B8 002CD5B8 0902A593 */  lbu        $5, 0x209($29)
    /* 1CD5BC 002CD5BC 0A02A493 */  lbu        $4, 0x20A($29)
    /* 1CD5C0 002CD5C0 0B02A393 */  lbu        $3, 0x20B($29)
    /* 1CD5C4 002CD5C4 790046A0 */  sb         $6, 0x79($2)
    /* 1CD5C8 002CD5C8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CD5CC 002CD5CC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CD5D0 002CD5D0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CD5D4 002CD5D4 2D206002 */  daddu      $4, $19, $0
    /* 1CD5D8 002CD5D8 98AC110C */  jal        func_0046b260
    /* 1CD5DC 002CD5DC 00000000 */   nop
    /* 1CD5E0 002CD5E0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD5E4 002CD5E4 00088244 */  mtc1       $2, $f1
    /* 1CD5E8 002CD5E8 00000000 */  nop
    /* 1CD5EC 002CD5EC 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD5F0 002CD5F0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD5F4 002CD5F4 00000244 */  mfc1       $2, $f0
    /* 1CD5F8 002CD5F8 00000000 */  nop
    /* 1CD5FC 002CD5FC 3C940200 */  dsll32     $18, $2, 16
    /* 1CD600 002CD600 3F941200 */  dsra32     $18, $18, 16
    /* 1CD604 002CD604 440D048E */  lw         $4, 0xD44($16)
    /* 1CD608 002CD608 38810B0C */  jal        func_002e04e0
    /* 1CD60C 002CD60C 00000000 */   nop
    /* 1CD610 002CD610 000152A4 */  sh         $18, 0x100($2)
    /* 1CD614 002CD614 2D206002 */  daddu      $4, $19, $0
    /* 1CD618 002CD618 BCAC110C */  jal        func_0046b2f0
    /* 1CD61C 002CD61C 00000000 */   nop
    /* 1CD620 002CD620 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD624 002CD624 00088244 */  mtc1       $2, $f1
    /* 1CD628 002CD628 00000000 */  nop
    /* 1CD62C 002CD62C 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD630 002CD630 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD634 002CD634 00000244 */  mfc1       $2, $f0
    /* 1CD638 002CD638 00000000 */  nop
    /* 1CD63C 002CD63C 3C940200 */  dsll32     $18, $2, 16
    /* 1CD640 002CD640 3F941200 */  dsra32     $18, $18, 16
    /* 1CD644 002CD644 440D048E */  lw         $4, 0xD44($16)
    /* 1CD648 002CD648 38810B0C */  jal        func_002e04e0
    /* 1CD64C 002CD64C 00000000 */   nop
    /* 1CD650 002CD650 020152A4 */  sh         $18, 0x102($2)
    /* 1CD654 002CD654 04002286 */  lh         $2, 0x4($17)
    /* 1CD658 002CD658 00008244 */  mtc1       $2, $f0
    /* 1CD65C 002CD65C 00000000 */  nop
    /* 1CD660 002CD660 20038046 */  cvt.s.w    $f12, $f0
    /* 1CD664 002CD664 440D048E */  lw         $4, 0xD44($16)
    /* 1CD668 002CD668 06002586 */  lh         $5, 0x6($17)
    /* 1CD66C 002CD66C 6C820B0C */  jal        func_002e09b0
    /* 1CD670 002CD670 00000000 */   nop
    /* 1CD674 002CD674 00688044 */  mtc1       $0, $f13
    /* 1CD678 002CD678 06002286 */  lh         $2, 0x6($17)
    /* 1CD67C 002CD67C 05004624 */  addiu      $6, $2, 0x5
    /* 1CD680 002CD680 440D048E */  lw         $4, 0xD44($16)
    /* 1CD684 002CD684 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CD688 002CD688 02000524 */  addiu      $5, $0, 0x2
    /* 1CD68C 002CD68C 03000724 */  addiu      $7, $0, 0x3
    /* 1CD690 002CD690 50820B0C */  jal        func_002e0940
    /* 1CD694 002CD694 00000000 */   nop
    /* 1CD698 002CD698 2D206002 */  daddu      $4, $19, $0
    /* 1CD69C 002CD69C A0B4110C */  jal        func_0046d280
    /* 1CD6A0 002CD6A0 00000000 */   nop
    /* 1CD6A4 002CD6A4 280F048E */  lw         $4, 0xF28($16)
    /* 1CD6A8 002CD6A8 45000524 */  addiu      $5, $0, 0x45
    /* 1CD6AC 002CD6AC 80B4110C */  jal        func_0046d200
    /* 1CD6B0 002CD6B0 00000000 */   nop
    /* 1CD6B4 002CD6B4 2D984000 */  daddu      $19, $2, $0
    /* 1CD6B8 002CD6B8 6400123C */  lui        $18, %hi(D_0063F788)
    /* 1CD6BC 002CD6BC 88F75226 */  addiu      $18, $18, %lo(D_0063F788)
    /* 1CD6C0 002CD6C0 6400113C */  lui        $17, %hi(D_0063FA50)
    /* 1CD6C4 002CD6C4 50FA3126 */  addiu      $17, $17, %lo(D_0063FA50)
    /* 1CD6C8 002CD6C8 5C42023C */  lui        $2, (0x425C0000 >> 16)
    /* 1CD6CC 002CD6CC 00608244 */  mtc1       $2, $f12
    /* 1CD6D0 002CD6D0 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CD6D4 002CD6D4 56000524 */  addiu      $5, $0, 0x56
    /* 1CD6D8 002CD6D8 78820B0C */  jal        func_002e09e0
    /* 1CD6DC 002CD6DC 00000000 */   nop
    /* 1CD6E0 002CD6E0 96C2023C */  lui        $2, (0xC2960000 >> 16)
    /* 1CD6E4 002CD6E4 00688244 */  mtc1       $2, $f13
    /* 1CD6E8 002CD6E8 3801A427 */  addiu      $4, $29, 0x138
    /* 1CD6EC 002CD6EC 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD6F0 002CD6F0 5CCA0A0C */  jal        func_002b2970
    /* 1CD6F4 002CD6F4 00000000 */   nop
    /* 1CD6F8 002CD6F8 3001A427 */  addiu      $4, $29, 0x130
    /* 1CD6FC 002CD6FC 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD700 002CD700 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CD704 002CD704 5CCA0A0C */  jal        func_002b2970
    /* 1CD708 002CD708 00000000 */   nop
    /* 1CD70C 002CD70C 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CD710 002CD710 3801A5DF */  ld         $5, 0x138($29)
    /* 1CD714 002CD714 3001A6DF */  ld         $6, 0x130($29)
    /* 1CD718 002CD718 02000724 */  addiu      $7, $0, 0x2
    /* 1CD71C 002CD71C 05000824 */  addiu      $8, $0, 0x5
    /* 1CD720 002CD720 01000924 */  addiu      $9, $0, 0x1
    /* 1CD724 002CD724 88810B0C */  jal        func_002e0620
    /* 1CD728 002CD728 00000000 */   nop
    /* 1CD72C 002CD72C 0402A427 */  addiu      $4, $29, 0x204
    /* 1CD730 002CD730 E4000524 */  addiu      $5, $0, 0xE4
    /* 1CD734 002CD734 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CD738 002CD738 2D380000 */  daddu      $7, $0, $0
    /* 1CD73C 002CD73C 2D40C000 */  daddu      $8, $6, $0
    /* 1CD740 002CD740 98CA0A0C */  jal        func_002b2a60
    /* 1CD744 002CD744 00000000 */   nop
    /* 1CD748 002CD748 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CD74C 002CD74C 38810B0C */  jal        func_002e04e0
    /* 1CD750 002CD750 00000000 */   nop
    /* 1CD754 002CD754 0402A693 */  lbu        $6, 0x204($29)
    /* 1CD758 002CD758 0502A593 */  lbu        $5, 0x205($29)
    /* 1CD75C 002CD75C 0602A493 */  lbu        $4, 0x206($29)
    /* 1CD760 002CD760 0702A393 */  lbu        $3, 0x207($29)
    /* 1CD764 002CD764 790046A0 */  sb         $6, 0x79($2)
    /* 1CD768 002CD768 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CD76C 002CD76C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CD770 002CD770 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CD774 002CD774 2D206002 */  daddu      $4, $19, $0
    /* 1CD778 002CD778 98AC110C */  jal        func_0046b260
    /* 1CD77C 002CD77C 00000000 */   nop
    /* 1CD780 002CD780 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD784 002CD784 00088244 */  mtc1       $2, $f1
    /* 1CD788 002CD788 00000000 */  nop
    /* 1CD78C 002CD78C 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD790 002CD790 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD794 002CD794 00000244 */  mfc1       $2, $f0
    /* 1CD798 002CD798 00000000 */  nop
    /* 1CD79C 002CD79C 3C940200 */  dsll32     $18, $2, 16
    /* 1CD7A0 002CD7A0 3F941200 */  dsra32     $18, $18, 16
    /* 1CD7A4 002CD7A4 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CD7A8 002CD7A8 38810B0C */  jal        func_002e04e0
    /* 1CD7AC 002CD7AC 00000000 */   nop
    /* 1CD7B0 002CD7B0 000152A4 */  sh         $18, 0x100($2)
    /* 1CD7B4 002CD7B4 2D206002 */  daddu      $4, $19, $0
    /* 1CD7B8 002CD7B8 BCAC110C */  jal        func_0046b2f0
    /* 1CD7BC 002CD7BC 00000000 */   nop
    /* 1CD7C0 002CD7C0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD7C4 002CD7C4 00088244 */  mtc1       $2, $f1
    /* 1CD7C8 002CD7C8 00000000 */  nop
    /* 1CD7CC 002CD7CC 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD7D0 002CD7D0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD7D4 002CD7D4 00000244 */  mfc1       $2, $f0
    /* 1CD7D8 002CD7D8 00000000 */  nop
    /* 1CD7DC 002CD7DC 3C940200 */  dsll32     $18, $2, 16
    /* 1CD7E0 002CD7E0 3F941200 */  dsra32     $18, $18, 16
    /* 1CD7E4 002CD7E4 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CD7E8 002CD7E8 38810B0C */  jal        func_002e04e0
    /* 1CD7EC 002CD7EC 00000000 */   nop
    /* 1CD7F0 002CD7F0 020152A4 */  sh         $18, 0x102($2)
    /* 1CD7F4 002CD7F4 04002286 */  lh         $2, 0x4($17)
    /* 1CD7F8 002CD7F8 00008244 */  mtc1       $2, $f0
    /* 1CD7FC 002CD7FC 00000000 */  nop
    /* 1CD800 002CD800 20038046 */  cvt.s.w    $f12, $f0
    /* 1CD804 002CD804 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CD808 002CD808 06002586 */  lh         $5, 0x6($17)
    /* 1CD80C 002CD80C 6C820B0C */  jal        func_002e09b0
    /* 1CD810 002CD810 00000000 */   nop
    /* 1CD814 002CD814 00688044 */  mtc1       $0, $f13
    /* 1CD818 002CD818 06002286 */  lh         $2, 0x6($17)
    /* 1CD81C 002CD81C 05004624 */  addiu      $6, $2, 0x5
    /* 1CD820 002CD820 4C0D048E */  lw         $4, 0xD4C($16)
    /* 1CD824 002CD824 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CD828 002CD828 02000524 */  addiu      $5, $0, 0x2
    /* 1CD82C 002CD82C 01000724 */  addiu      $7, $0, 0x1
    /* 1CD830 002CD830 50820B0C */  jal        func_002e0940
    /* 1CD834 002CD834 00000000 */   nop
    /* 1CD838 002CD838 2D206002 */  daddu      $4, $19, $0
    /* 1CD83C 002CD83C A0B4110C */  jal        func_0046d280
    /* 1CD840 002CD840 00000000 */   nop
    /* 1CD844 002CD844 280F048E */  lw         $4, 0xF28($16)
    /* 1CD848 002CD848 46000524 */  addiu      $5, $0, 0x46
    /* 1CD84C 002CD84C 80B4110C */  jal        func_0046d200
    /* 1CD850 002CD850 00000000 */   nop
    /* 1CD854 002CD854 2D984000 */  daddu      $19, $2, $0
    /* 1CD858 002CD858 6400123C */  lui        $18, %hi(D_0063F790)
    /* 1CD85C 002CD85C 90F75226 */  addiu      $18, $18, %lo(D_0063F790)
    /* 1CD860 002CD860 6400113C */  lui        $17, %hi(D_0063FA58)
    /* 1CD864 002CD864 58FA3126 */  addiu      $17, $17, %lo(D_0063FA58)
    /* 1CD868 002CD868 6042023C */  lui        $2, (0x42600000 >> 16)
    /* 1CD86C 002CD86C 00608244 */  mtc1       $2, $f12
    /* 1CD870 002CD870 500D048E */  lw         $4, 0xD50($16)
    /* 1CD874 002CD874 56000524 */  addiu      $5, $0, 0x56
    /* 1CD878 002CD878 78820B0C */  jal        func_002e09e0
    /* 1CD87C 002CD87C 00000000 */   nop
    /* 1CD880 002CD880 25C3023C */  lui        $2, (0xC3250000 >> 16)
    /* 1CD884 002CD884 00688244 */  mtc1       $2, $f13
    /* 1CD888 002CD888 2801A427 */  addiu      $4, $29, 0x128
    /* 1CD88C 002CD88C 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD890 002CD890 5CCA0A0C */  jal        func_002b2970
    /* 1CD894 002CD894 00000000 */   nop
    /* 1CD898 002CD898 2001A427 */  addiu      $4, $29, 0x120
    /* 1CD89C 002CD89C 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CD8A0 002CD8A0 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CD8A4 002CD8A4 5CCA0A0C */  jal        func_002b2970
    /* 1CD8A8 002CD8A8 00000000 */   nop
    /* 1CD8AC 002CD8AC 500D048E */  lw         $4, 0xD50($16)
    /* 1CD8B0 002CD8B0 2801A5DF */  ld         $5, 0x128($29)
    /* 1CD8B4 002CD8B4 2001A6DF */  ld         $6, 0x120($29)
    /* 1CD8B8 002CD8B8 02000724 */  addiu      $7, $0, 0x2
    /* 1CD8BC 002CD8BC 05000824 */  addiu      $8, $0, 0x5
    /* 1CD8C0 002CD8C0 04000924 */  addiu      $9, $0, 0x4
    /* 1CD8C4 002CD8C4 88810B0C */  jal        func_002e0620
    /* 1CD8C8 002CD8C8 00000000 */   nop
    /* 1CD8CC 002CD8CC 0002A427 */  addiu      $4, $29, 0x200
    /* 1CD8D0 002CD8D0 E4000524 */  addiu      $5, $0, 0xE4
    /* 1CD8D4 002CD8D4 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CD8D8 002CD8D8 2D380000 */  daddu      $7, $0, $0
    /* 1CD8DC 002CD8DC 2D40C000 */  daddu      $8, $6, $0
    /* 1CD8E0 002CD8E0 98CA0A0C */  jal        func_002b2a60
    /* 1CD8E4 002CD8E4 00000000 */   nop
    /* 1CD8E8 002CD8E8 500D048E */  lw         $4, 0xD50($16)
    /* 1CD8EC 002CD8EC 38810B0C */  jal        func_002e04e0
    /* 1CD8F0 002CD8F0 00000000 */   nop
    /* 1CD8F4 002CD8F4 0002A693 */  lbu        $6, 0x200($29)
    /* 1CD8F8 002CD8F8 0102A593 */  lbu        $5, 0x201($29)
    /* 1CD8FC 002CD8FC 0202A493 */  lbu        $4, 0x202($29)
    /* 1CD900 002CD900 0302A393 */  lbu        $3, 0x203($29)
    /* 1CD904 002CD904 790046A0 */  sb         $6, 0x79($2)
    /* 1CD908 002CD908 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CD90C 002CD90C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CD910 002CD910 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CD914 002CD914 2D206002 */  daddu      $4, $19, $0
    /* 1CD918 002CD918 98AC110C */  jal        func_0046b260
    /* 1CD91C 002CD91C 00000000 */   nop
    /* 1CD920 002CD920 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD924 002CD924 00088244 */  mtc1       $2, $f1
    /* 1CD928 002CD928 00000000 */  nop
    /* 1CD92C 002CD92C 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD930 002CD930 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD934 002CD934 00000244 */  mfc1       $2, $f0
    /* 1CD938 002CD938 00000000 */  nop
    /* 1CD93C 002CD93C 3C940200 */  dsll32     $18, $2, 16
    /* 1CD940 002CD940 3F941200 */  dsra32     $18, $18, 16
    /* 1CD944 002CD944 500D048E */  lw         $4, 0xD50($16)
    /* 1CD948 002CD948 38810B0C */  jal        func_002e04e0
    /* 1CD94C 002CD94C 00000000 */   nop
    /* 1CD950 002CD950 000152A4 */  sh         $18, 0x100($2)
    /* 1CD954 002CD954 2D206002 */  daddu      $4, $19, $0
    /* 1CD958 002CD958 BCAC110C */  jal        func_0046b2f0
    /* 1CD95C 002CD95C 00000000 */   nop
    /* 1CD960 002CD960 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CD964 002CD964 00088244 */  mtc1       $2, $f1
    /* 1CD968 002CD968 00000000 */  nop
    /* 1CD96C 002CD96C 03000146 */  div.s      $f0, $f0, $f1
    /* 1CD970 002CD970 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CD974 002CD974 00000244 */  mfc1       $2, $f0
    /* 1CD978 002CD978 00000000 */  nop
    /* 1CD97C 002CD97C 3C940200 */  dsll32     $18, $2, 16
    /* 1CD980 002CD980 3F941200 */  dsra32     $18, $18, 16
    /* 1CD984 002CD984 500D048E */  lw         $4, 0xD50($16)
    /* 1CD988 002CD988 38810B0C */  jal        func_002e04e0
    /* 1CD98C 002CD98C 00000000 */   nop
    /* 1CD990 002CD990 020152A4 */  sh         $18, 0x102($2)
    /* 1CD994 002CD994 00A08044 */  mtc1       $0, $f20
    /* 1CD998 002CD998 500D048E */  lw         $4, 0xD50($16)
    /* 1CD99C 002CD99C 38810B0C */  jal        func_002e04e0
    /* 1CD9A0 002CD9A0 00000000 */   nop
    /* 1CD9A4 002CD9A4 C40054E4 */  swc1       $f20, 0xC4($2)
    /* 1CD9A8 002CD9A8 04002286 */  lh         $2, 0x4($17)
    /* 1CD9AC 002CD9AC 00008244 */  mtc1       $2, $f0
    /* 1CD9B0 002CD9B0 00000000 */  nop
    /* 1CD9B4 002CD9B4 20038046 */  cvt.s.w    $f12, $f0
    /* 1CD9B8 002CD9B8 500D048E */  lw         $4, 0xD50($16)
    /* 1CD9BC 002CD9BC 06002586 */  lh         $5, 0x6($17)
    /* 1CD9C0 002CD9C0 6C820B0C */  jal        func_002e09b0
    /* 1CD9C4 002CD9C4 00000000 */   nop
    /* 1CD9C8 002CD9C8 46A30046 */  mov.s      $f13, $f20
    /* 1CD9CC 002CD9CC 06002286 */  lh         $2, 0x6($17)
    /* 1CD9D0 002CD9D0 05004624 */  addiu      $6, $2, 0x5
    /* 1CD9D4 002CD9D4 500D048E */  lw         $4, 0xD50($16)
    /* 1CD9D8 002CD9D8 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CD9DC 002CD9DC 02000524 */  addiu      $5, $0, 0x2
    /* 1CD9E0 002CD9E0 04000724 */  addiu      $7, $0, 0x4
    /* 1CD9E4 002CD9E4 50820B0C */  jal        func_002e0940
    /* 1CD9E8 002CD9E8 00000000 */   nop
    /* 1CD9EC 002CD9EC 2D206002 */  daddu      $4, $19, $0
    /* 1CD9F0 002CD9F0 A0B4110C */  jal        func_0046d280
    /* 1CD9F4 002CD9F4 00000000 */   nop
    /* 1CD9F8 002CD9F8 280F048E */  lw         $4, 0xF28($16)
    /* 1CD9FC 002CD9FC 47000524 */  addiu      $5, $0, 0x47
    /* 1CDA00 002CDA00 80B4110C */  jal        func_0046d200
    /* 1CDA04 002CDA04 00000000 */   nop
    /* 1CDA08 002CDA08 2D984000 */  daddu      $19, $2, $0
    /* 1CDA0C 002CDA0C 6400123C */  lui        $18, %hi(D_0063F798)
    /* 1CDA10 002CDA10 98F75226 */  addiu      $18, $18, %lo(D_0063F798)
    /* 1CDA14 002CDA14 6400113C */  lui        $17, %hi(D_0063FA60)
    /* 1CDA18 002CDA18 60FA3126 */  addiu      $17, $17, %lo(D_0063FA60)
    /* 1CDA1C 002CDA1C 6442023C */  lui        $2, (0x42640000 >> 16)
    /* 1CDA20 002CDA20 00608244 */  mtc1       $2, $f12
    /* 1CDA24 002CDA24 540D048E */  lw         $4, 0xD54($16)
    /* 1CDA28 002CDA28 56000524 */  addiu      $5, $0, 0x56
    /* 1CDA2C 002CDA2C 78820B0C */  jal        func_002e09e0
    /* 1CDA30 002CDA30 00000000 */   nop
    /* 1CDA34 002CDA34 FCC2023C */  lui        $2, (0xC2FC0000 >> 16)
    /* 1CDA38 002CDA38 00688244 */  mtc1       $2, $f13
    /* 1CDA3C 002CDA3C 1801A427 */  addiu      $4, $29, 0x118
    /* 1CDA40 002CDA40 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CDA44 002CDA44 5CCA0A0C */  jal        func_002b2970
    /* 1CDA48 002CDA48 00000000 */   nop
    /* 1CDA4C 002CDA4C 1001A427 */  addiu      $4, $29, 0x110
    /* 1CDA50 002CDA50 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CDA54 002CDA54 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CDA58 002CDA58 5CCA0A0C */  jal        func_002b2970
    /* 1CDA5C 002CDA5C 00000000 */   nop
    /* 1CDA60 002CDA60 540D048E */  lw         $4, 0xD54($16)
    /* 1CDA64 002CDA64 1801A5DF */  ld         $5, 0x118($29)
    /* 1CDA68 002CDA68 1001A6DF */  ld         $6, 0x110($29)
    /* 1CDA6C 002CDA6C 02000724 */  addiu      $7, $0, 0x2
    /* 1CDA70 002CDA70 05000824 */  addiu      $8, $0, 0x5
    /* 1CDA74 002CDA74 2D48E000 */  daddu      $9, $7, $0
    /* 1CDA78 002CDA78 88810B0C */  jal        func_002e0620
    /* 1CDA7C 002CDA7C 00000000 */   nop
    /* 1CDA80 002CDA80 FC01A427 */  addiu      $4, $29, 0x1FC
    /* 1CDA84 002CDA84 E4000524 */  addiu      $5, $0, 0xE4
    /* 1CDA88 002CDA88 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CDA8C 002CDA8C 2D380000 */  daddu      $7, $0, $0
    /* 1CDA90 002CDA90 2D40C000 */  daddu      $8, $6, $0
    /* 1CDA94 002CDA94 98CA0A0C */  jal        func_002b2a60
    /* 1CDA98 002CDA98 00000000 */   nop
    /* 1CDA9C 002CDA9C 540D048E */  lw         $4, 0xD54($16)
    /* 1CDAA0 002CDAA0 38810B0C */  jal        func_002e04e0
    /* 1CDAA4 002CDAA4 00000000 */   nop
    /* 1CDAA8 002CDAA8 FC01A693 */  lbu        $6, 0x1FC($29)
    /* 1CDAAC 002CDAAC FD01A593 */  lbu        $5, 0x1FD($29)
    /* 1CDAB0 002CDAB0 FE01A493 */  lbu        $4, 0x1FE($29)
    /* 1CDAB4 002CDAB4 FF01A393 */  lbu        $3, 0x1FF($29)
    /* 1CDAB8 002CDAB8 790046A0 */  sb         $6, 0x79($2)
    /* 1CDABC 002CDABC 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CDAC0 002CDAC0 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CDAC4 002CDAC4 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CDAC8 002CDAC8 2D206002 */  daddu      $4, $19, $0
    /* 1CDACC 002CDACC 98AC110C */  jal        func_0046b260
    /* 1CDAD0 002CDAD0 00000000 */   nop
    /* 1CDAD4 002CDAD4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CDAD8 002CDAD8 00088244 */  mtc1       $2, $f1
    /* 1CDADC 002CDADC 00000000 */  nop
    /* 1CDAE0 002CDAE0 03000146 */  div.s      $f0, $f0, $f1
    /* 1CDAE4 002CDAE4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CDAE8 002CDAE8 00000244 */  mfc1       $2, $f0
    /* 1CDAEC 002CDAEC 00000000 */  nop
    /* 1CDAF0 002CDAF0 3C940200 */  dsll32     $18, $2, 16
    /* 1CDAF4 002CDAF4 3F941200 */  dsra32     $18, $18, 16
    /* 1CDAF8 002CDAF8 540D048E */  lw         $4, 0xD54($16)
    /* 1CDAFC 002CDAFC 38810B0C */  jal        func_002e04e0
    /* 1CDB00 002CDB00 00000000 */   nop
    /* 1CDB04 002CDB04 000152A4 */  sh         $18, 0x100($2)
    /* 1CDB08 002CDB08 2D206002 */  daddu      $4, $19, $0
    /* 1CDB0C 002CDB0C BCAC110C */  jal        func_0046b2f0
    /* 1CDB10 002CDB10 00000000 */   nop
    /* 1CDB14 002CDB14 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CDB18 002CDB18 00088244 */  mtc1       $2, $f1
    /* 1CDB1C 002CDB1C 00000000 */  nop
    /* 1CDB20 002CDB20 03000146 */  div.s      $f0, $f0, $f1
    /* 1CDB24 002CDB24 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CDB28 002CDB28 00000244 */  mfc1       $2, $f0
    /* 1CDB2C 002CDB2C 00000000 */  nop
    /* 1CDB30 002CDB30 3C940200 */  dsll32     $18, $2, 16
    /* 1CDB34 002CDB34 3F941200 */  dsra32     $18, $18, 16
    /* 1CDB38 002CDB38 540D048E */  lw         $4, 0xD54($16)
    /* 1CDB3C 002CDB3C 38810B0C */  jal        func_002e04e0
    /* 1CDB40 002CDB40 00000000 */   nop
    /* 1CDB44 002CDB44 020152A4 */  sh         $18, 0x102($2)
    /* 1CDB48 002CDB48 540D048E */  lw         $4, 0xD54($16)
    /* 1CDB4C 002CDB4C 38810B0C */  jal        func_002e04e0
    /* 1CDB50 002CDB50 00000000 */   nop
    /* 1CDB54 002CDB54 C40054E4 */  swc1       $f20, 0xC4($2)
    /* 1CDB58 002CDB58 04002286 */  lh         $2, 0x4($17)
    /* 1CDB5C 002CDB5C 00008244 */  mtc1       $2, $f0
    /* 1CDB60 002CDB60 00000000 */  nop
    /* 1CDB64 002CDB64 20038046 */  cvt.s.w    $f12, $f0
    /* 1CDB68 002CDB68 540D048E */  lw         $4, 0xD54($16)
    /* 1CDB6C 002CDB6C 06002586 */  lh         $5, 0x6($17)
    /* 1CDB70 002CDB70 6C820B0C */  jal        func_002e09b0
    /* 1CDB74 002CDB74 00000000 */   nop
    /* 1CDB78 002CDB78 46A30046 */  mov.s      $f13, $f20
    /* 1CDB7C 002CDB7C 06002286 */  lh         $2, 0x6($17)
    /* 1CDB80 002CDB80 05004624 */  addiu      $6, $2, 0x5
    /* 1CDB84 002CDB84 540D048E */  lw         $4, 0xD54($16)
    /* 1CDB88 002CDB88 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CDB8C 002CDB8C 01000524 */  addiu      $5, $0, 0x1
    /* 1CDB90 002CDB90 02000724 */  addiu      $7, $0, 0x2
    /* 1CDB94 002CDB94 50820B0C */  jal        func_002e0940
    /* 1CDB98 002CDB98 00000000 */   nop
    /* 1CDB9C 002CDB9C 2D206002 */  daddu      $4, $19, $0
    /* 1CDBA0 002CDBA0 A0B4110C */  jal        func_0046d280
    /* 1CDBA4 002CDBA4 00000000 */   nop
    /* 1CDBA8 002CDBA8 280F048E */  lw         $4, 0xF28($16)
    /* 1CDBAC 002CDBAC 48000524 */  addiu      $5, $0, 0x48
    /* 1CDBB0 002CDBB0 80B4110C */  jal        func_0046d200
    /* 1CDBB4 002CDBB4 00000000 */   nop
    /* 1CDBB8 002CDBB8 2D984000 */  daddu      $19, $2, $0
    /* 1CDBBC 002CDBBC 6400123C */  lui        $18, %hi(D_0063F7A0)
    /* 1CDBC0 002CDBC0 A0F75226 */  addiu      $18, $18, %lo(D_0063F7A0)
    /* 1CDBC4 002CDBC4 6400113C */  lui        $17, %hi(D_0063FA68)
    /* 1CDBC8 002CDBC8 68FA3126 */  addiu      $17, $17, %lo(D_0063FA68)
    /* 1CDBCC 002CDBCC 6842023C */  lui        $2, (0x42680000 >> 16)
    /* 1CDBD0 002CDBD0 00608244 */  mtc1       $2, $f12
    /* 1CDBD4 002CDBD4 580D048E */  lw         $4, 0xD58($16)
    /* 1CDBD8 002CDBD8 56000524 */  addiu      $5, $0, 0x56
    /* 1CDBDC 002CDBDC 78820B0C */  jal        func_002e09e0
    /* 1CDBE0 002CDBE0 00000000 */   nop
    /* 1CDBE4 002CDBE4 45C3023C */  lui        $2, (0xC3450000 >> 16)
    /* 1CDBE8 002CDBE8 00688244 */  mtc1       $2, $f13
    /* 1CDBEC 002CDBEC 0801A427 */  addiu      $4, $29, 0x108
    /* 1CDBF0 002CDBF0 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CDBF4 002CDBF4 5CCA0A0C */  jal        func_002b2970
    /* 1CDBF8 002CDBF8 00000000 */   nop
    /* 1CDBFC 002CDBFC 0001A427 */  addiu      $4, $29, 0x100
    /* 1CDC00 002CDC00 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1CDC04 002CDC04 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1CDC08 002CDC08 5CCA0A0C */  jal        func_002b2970
    /* 1CDC0C 002CDC0C 00000000 */   nop
    /* 1CDC10 002CDC10 580D048E */  lw         $4, 0xD58($16)
    /* 1CDC14 002CDC14 0801A5DF */  ld         $5, 0x108($29)
    /* 1CDC18 002CDC18 0001A6DF */  ld         $6, 0x100($29)
    /* 1CDC1C 002CDC1C 02000724 */  addiu      $7, $0, 0x2
    /* 1CDC20 002CDC20 05000824 */  addiu      $8, $0, 0x5
    /* 1CDC24 002CDC24 2D480001 */  daddu      $9, $8, $0
    /* 1CDC28 002CDC28 88810B0C */  jal        func_002e0620
    /* 1CDC2C 002CDC2C 00000000 */   nop
    /* 1CDC30 002CDC30 F801A427 */  addiu      $4, $29, 0x1F8
    /* 1CDC34 002CDC34 E4000524 */  addiu      $5, $0, 0xE4
    /* 1CDC38 002CDC38 FF000624 */  addiu      $6, $0, 0xFF
    /* 1CDC3C 002CDC3C 2D380000 */  daddu      $7, $0, $0
    /* 1CDC40 002CDC40 2D40C000 */  daddu      $8, $6, $0
    /* 1CDC44 002CDC44 98CA0A0C */  jal        func_002b2a60
    /* 1CDC48 002CDC48 00000000 */   nop
    /* 1CDC4C 002CDC4C 580D048E */  lw         $4, 0xD58($16)
    /* 1CDC50 002CDC50 38810B0C */  jal        func_002e04e0
    /* 1CDC54 002CDC54 00000000 */   nop
    /* 1CDC58 002CDC58 F801A693 */  lbu        $6, 0x1F8($29)
    /* 1CDC5C 002CDC5C F901A593 */  lbu        $5, 0x1F9($29)
    /* 1CDC60 002CDC60 FA01A493 */  lbu        $4, 0x1FA($29)
    /* 1CDC64 002CDC64 FB01A393 */  lbu        $3, 0x1FB($29)
    /* 1CDC68 002CDC68 790046A0 */  sb         $6, 0x79($2)
    /* 1CDC6C 002CDC6C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CDC70 002CDC70 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CDC74 002CDC74 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CDC78 002CDC78 2D206002 */  daddu      $4, $19, $0
    /* 1CDC7C 002CDC7C 98AC110C */  jal        func_0046b260
    /* 1CDC80 002CDC80 00000000 */   nop
    /* 1CDC84 002CDC84 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CDC88 002CDC88 00088244 */  mtc1       $2, $f1
    /* 1CDC8C 002CDC8C 00000000 */  nop
    /* 1CDC90 002CDC90 03000146 */  div.s      $f0, $f0, $f1
    /* 1CDC94 002CDC94 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CDC98 002CDC98 00000244 */  mfc1       $2, $f0
    /* 1CDC9C 002CDC9C 00000000 */  nop
    /* 1CDCA0 002CDCA0 3C940200 */  dsll32     $18, $2, 16
    /* 1CDCA4 002CDCA4 3F941200 */  dsra32     $18, $18, 16
    /* 1CDCA8 002CDCA8 580D048E */  lw         $4, 0xD58($16)
    /* 1CDCAC 002CDCAC 38810B0C */  jal        func_002e04e0
    /* 1CDCB0 002CDCB0 00000000 */   nop
    /* 1CDCB4 002CDCB4 000152A4 */  sh         $18, 0x100($2)
    /* 1CDCB8 002CDCB8 2D206002 */  daddu      $4, $19, $0
    /* 1CDCBC 002CDCBC BCAC110C */  jal        func_0046b2f0
    /* 1CDCC0 002CDCC0 00000000 */   nop
    /* 1CDCC4 002CDCC4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1CDCC8 002CDCC8 00088244 */  mtc1       $2, $f1
    /* 1CDCCC 002CDCCC 00000000 */  nop
    /* 1CDCD0 002CDCD0 03000146 */  div.s      $f0, $f0, $f1
    /* 1CDCD4 002CDCD4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CDCD8 002CDCD8 00000244 */  mfc1       $2, $f0
    /* 1CDCDC 002CDCDC 00000000 */  nop
    /* 1CDCE0 002CDCE0 3C940200 */  dsll32     $18, $2, 16
    /* 1CDCE4 002CDCE4 3F941200 */  dsra32     $18, $18, 16
    /* 1CDCE8 002CDCE8 580D048E */  lw         $4, 0xD58($16)
    /* 1CDCEC 002CDCEC 38810B0C */  jal        func_002e04e0
    /* 1CDCF0 002CDCF0 00000000 */   nop
    /* 1CDCF4 002CDCF4 020152A4 */  sh         $18, 0x102($2)
    /* 1CDCF8 002CDCF8 580D048E */  lw         $4, 0xD58($16)
    /* 1CDCFC 002CDCFC 38810B0C */  jal        func_002e04e0
    /* 1CDD00 002CDD00 00000000 */   nop
    /* 1CDD04 002CDD04 C40054E4 */  swc1       $f20, 0xC4($2)
    /* 1CDD08 002CDD08 04002286 */  lh         $2, 0x4($17)
    /* 1CDD0C 002CDD0C 00008244 */  mtc1       $2, $f0
    /* 1CDD10 002CDD10 00000000 */  nop
    /* 1CDD14 002CDD14 20038046 */  cvt.s.w    $f12, $f0
    /* 1CDD18 002CDD18 580D048E */  lw         $4, 0xD58($16)
    /* 1CDD1C 002CDD1C 06002586 */  lh         $5, 0x6($17)
    /* 1CDD20 002CDD20 6C820B0C */  jal        func_002e09b0
    /* 1CDD24 002CDD24 00000000 */   nop
    /* 1CDD28 002CDD28 46A30046 */  mov.s      $f13, $f20
    /* 1CDD2C 002CDD2C 06002286 */  lh         $2, 0x6($17)
    /* 1CDD30 002CDD30 05004624 */  addiu      $6, $2, 0x5
    /* 1CDD34 002CDD34 580D048E */  lw         $4, 0xD58($16)
    /* 1CDD38 002CDD38 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CDD3C 002CDD3C 02000524 */  addiu      $5, $0, 0x2
    /* 1CDD40 002CDD40 05000724 */  addiu      $7, $0, 0x5
    /* 1CDD44 002CDD44 50820B0C */  jal        func_002e0940
    /* 1CDD48 002CDD48 00000000 */   nop
    /* 1CDD4C 002CDD4C 2D206002 */  daddu      $4, $19, $0
    /* 1CDD50 002CDD50 A0B4110C */  jal        func_0046d280
    /* 1CDD54 002CDD54 00000000 */   nop
    /* 1CDD58 002CDD58 6400113C */  lui        $17, %hi(D_0063F7B0)
    /* 1CDD5C 002CDD5C B0F73126 */  addiu      $17, $17, %lo(D_0063F7B0)
    /* 1CDD60 002CDD60 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1CDD64 002CDD64 00608244 */  mtc1       $2, $f12
    /* 1CDD68 002CDD68 600D048E */  lw         $4, 0xD60($16)
    /* 1CDD6C 002CDD6C 41000524 */  addiu      $5, $0, 0x41
    /* 1CDD70 002CDD70 78820B0C */  jal        func_002e09e0
    /* 1CDD74 002CDD74 00000000 */   nop
    /* 1CDD78 002CDD78 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1CDD7C 002CDD7C 26020224 */  addiu      $2, $0, 0x226
    /* 1CDD80 002CDD80 00008244 */  mtc1       $2, $f0
    /* 1CDD84 002CDD84 00000000 */  nop
    /* 1CDD88 002CDD88 20008046 */  cvt.s.w    $f0, $f0
    /* 1CDD8C 002CDD8C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1CDD90 002CDD90 F800A427 */  addiu      $4, $29, 0xF8
    /* 1CDD94 002CDD94 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CDD98 002CDD98 5CCA0A0C */  jal        func_002b2970
    /* 1CDD9C 002CDD9C 00000000 */   nop
    /* 1CDDA0 002CDDA0 F000A427 */  addiu      $4, $29, 0xF0
    /* 1CDDA4 002CDDA4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CDDA8 002CDDA8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CDDAC 002CDDAC 5CCA0A0C */  jal        func_002b2970
    /* 1CDDB0 002CDDB0 00000000 */   nop
    /* 1CDDB4 002CDDB4 600D048E */  lw         $4, 0xD60($16)
    /* 1CDDB8 002CDDB8 F800A5DF */  ld         $5, 0xF8($29)
    /* 1CDDBC 002CDDBC F000A6DF */  ld         $6, 0xF0($29)
    /* 1CDDC0 002CDDC0 02000724 */  addiu      $7, $0, 0x2
    /* 1CDDC4 002CDDC4 04000824 */  addiu      $8, $0, 0x4
    /* 1CDDC8 002CDDC8 2D480000 */  daddu      $9, $0, $0
    /* 1CDDCC 002CDDCC 88810B0C */  jal        func_002e0620
    /* 1CDDD0 002CDDD0 00000000 */   nop
    /* 1CDDD4 002CDDD4 600D048E */  lw         $4, 0xD60($16)
    /* 1CDDD8 002CDDD8 38810B0C */  jal        func_002e04e0
    /* 1CDDDC 002CDDDC 00000000 */   nop
    /* 1CDDE0 002CDDE0 020140A4 */  sh         $0, 0x102($2)
    /* 1CDDE4 002CDDE4 3C8C0000 */  dsll32     $17, $0, 16
    /* 1CDDE8 002CDDE8 3F8C1100 */  dsra32     $17, $17, 16
    /* 1CDDEC 002CDDEC 600D048E */  lw         $4, 0xD60($16)
    /* 1CDDF0 002CDDF0 38810B0C */  jal        func_002e04e0
    /* 1CDDF4 002CDDF4 00000000 */   nop
    /* 1CDDF8 002CDDF8 000151A4 */  sh         $17, 0x100($2)
    /* 1CDDFC 002CDDFC A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* 1CDE00 002CDE00 00608244 */  mtc1       $2, $f12
    /* 1CDE04 002CDE04 600D048E */  lw         $4, 0xD60($16)
    /* 1CDE08 002CDE08 2C858DC7 */  lwc1       $f13, -0x7AD4($28)
    /* 1CDE0C 002CDE0C 02000524 */  addiu      $5, $0, 0x2
    /* 1CDE10 002CDE10 2D30A000 */  daddu      $6, $5, $0
    /* 1CDE14 002CDE14 2D38A000 */  daddu      $7, $5, $0
    /* 1CDE18 002CDE18 50820B0C */  jal        func_002e0940
    /* 1CDE1C 002CDE1C 00000000 */   nop
    /* 1CDE20 002CDE20 F401A427 */  addiu      $4, $29, 0x1F4
    /* 1CDE24 002CDE24 FF000524 */  addiu      $5, $0, 0xFF
    /* 1CDE28 002CDE28 96000624 */  addiu      $6, $0, 0x96
    /* 1CDE2C 002CDE2C 2D380000 */  daddu      $7, $0, $0
    /* 1CDE30 002CDE30 2D40A000 */  daddu      $8, $5, $0
    /* 1CDE34 002CDE34 98CA0A0C */  jal        func_002b2a60
    /* 1CDE38 002CDE38 00000000 */   nop
    /* 1CDE3C 002CDE3C 600D048E */  lw         $4, 0xD60($16)
    /* 1CDE40 002CDE40 38810B0C */  jal        func_002e04e0
    /* 1CDE44 002CDE44 00000000 */   nop
    /* 1CDE48 002CDE48 F401A693 */  lbu        $6, 0x1F4($29)
    /* 1CDE4C 002CDE4C F501A593 */  lbu        $5, 0x1F5($29)
    /* 1CDE50 002CDE50 F601A493 */  lbu        $4, 0x1F6($29)
    /* 1CDE54 002CDE54 F701A393 */  lbu        $3, 0x1F7($29)
    /* 1CDE58 002CDE58 790046A0 */  sb         $6, 0x79($2)
    /* 1CDE5C 002CDE5C 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1CDE60 002CDE60 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1CDE64 002CDE64 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1CDE68 002CDE68 6400113C */  lui        $17, %hi(D_0063F7B8)
    /* 1CDE6C 002CDE6C B8F73126 */  addiu      $17, $17, %lo(D_0063F7B8)
    /* 1CDE70 002CDE70 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 1CDE74 002CDE74 00608244 */  mtc1       $2, $f12
    /* 1CDE78 002CDE78 640D048E */  lw         $4, 0xD64($16)
    /* 1CDE7C 002CDE7C 41000524 */  addiu      $5, $0, 0x41
    /* 1CDE80 002CDE80 78820B0C */  jal        func_002e09e0
    /* 1CDE84 002CDE84 00000000 */   nop
    /* 1CDE88 002CDE88 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1CDE8C 002CDE8C 26020224 */  addiu      $2, $0, 0x226
    /* 1CDE90 002CDE90 00008244 */  mtc1       $2, $f0
    /* 1CDE94 002CDE94 00000000 */  nop
    /* 1CDE98 002CDE98 20008046 */  cvt.s.w    $f0, $f0
    /* 1CDE9C 002CDE9C 410B0046 */  sub.s      $f13, $f1, $f0
    /* 1CDEA0 002CDEA0 E800A427 */  addiu      $4, $29, 0xE8
    /* 1CDEA4 002CDEA4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CDEA8 002CDEA8 5CCA0A0C */  jal        func_002b2970
    /* 1CDEAC 002CDEAC 00000000 */   nop
    /* 1CDEB0 002CDEB0 E000A427 */  addiu      $4, $29, 0xE0
    /* 1CDEB4 002CDEB4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1CDEB8 002CDEB8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1CDEBC 002CDEBC 5CCA0A0C */  jal        func_002b2970
    /* 1CDEC0 002CDEC0 00000000 */   nop
    /* 1CDEC4 002CDEC4 640D048E */  lw         $4, 0xD64($16)
    /* 1CDEC8 002CDEC8 E800A5DF */  ld         $5, 0xE8($29)
    /* 1CDECC 002CDECC E000A6DF */  ld         $6, 0xE0($29)
    /* 1CDED0 002CDED0 02000724 */  addiu      $7, $0, 0x2
    /* 1CDED4 002CDED4 04000824 */  addiu      $8, $0, 0x4
    /* 1CDED8 002CDED8 2D480000 */  daddu      $9, $0, $0
    /* 1CDEDC 002CDEDC 88810B0C */  jal        func_002e0620
    /* 1CDEE0 002CDEE0 00000000 */   nop
    /* 1CDEE4 002CDEE4 CEFF1124 */  addiu      $17, $0, -0x32
    /* 1CDEE8 002CDEE8 640D048E */  lw         $4, 0xD64($16)
    /* 1CDEEC 002CDEEC 38810B0C */  jal        func_002e04e0
    /* 1CDEF0 002CDEF0 00000000 */   nop
    /* 1CDEF4 002CDEF4 000151A4 */  sh         $17, 0x100($2)
    /* 1CDEF8 002CDEF8 25FF1124 */  addiu      $17, $0, -0xDB
    /* 1CDEFC 002CDEFC 640D048E */  lw         $4, 0xD64($16)
    /* 1CDF00 002CDF00 38810B0C */  jal        func_002e04e0
    /* 1CDF04 002CDF04 00000000 */   nop
    /* 1CDF08 002CDF08 020151A4 */  sh         $17, 0x102($2)
    /* 1CDF0C 002CDF0C A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* 1CDF10 002CDF10 00608244 */  mtc1       $2, $f12
    /* 1CDF14 002CDF14 640D048E */  lw         $4, 0xD64($16)
    /* 1CDF18 002CDF18 2C858DC7 */  lwc1       $f13, -0x7AD4($28)
    /* 1CDF1C 002CDF1C 02000524 */  addiu      $5, $0, 0x2
    /* 1CDF20 002CDF20 2D30A000 */  daddu      $6, $5, $0
    /* 1CDF24 002CDF24 2D38A000 */  daddu      $7, $5, $0
    /* 1CDF28 002CDF28 50820B0C */  jal        func_002e0940
    /* 1CDF2C 002CDF2C 00000000 */   nop
    /* 1CDF30 002CDF30 15000324 */  addiu      $3, $0, 0x15
    /* 1CDF34 002CDF34 000003A2 */  sb         $3, 0x0($16)
  .L002CDF38:
    /* 1CDF38 002CDF38 140000A2 */  sb         $0, 0x14($16)
  .L002CDF3C:
    /* 1CDF3C 002CDF3C B000BFDF */  ld         $31, 0xB0($29)
    /* 1CDF40 002CDF40 A000BE7B */  lq         $30, 0xA0($29)
    /* 1CDF44 002CDF44 9000B77B */  lq         $23, 0x90($29)
    /* 1CDF48 002CDF48 8000B67B */  lq         $22, 0x80($29)
    /* 1CDF4C 002CDF4C 7000B57B */  lq         $21, 0x70($29)
    /* 1CDF50 002CDF50 6000B47B */  lq         $20, 0x60($29)
    /* 1CDF54 002CDF54 5000B37B */  lq         $19, 0x50($29)
    /* 1CDF58 002CDF58 4000B27B */  lq         $18, 0x40($29)
    /* 1CDF5C 002CDF5C 3000B17B */  lq         $17, 0x30($29)
    /* 1CDF60 002CDF60 2000B07B */  lq         $16, 0x20($29)
    /* 1CDF64 002CDF64 1000B4C7 */  lwc1       $f20, 0x10($29)
    /* 1CDF68 002CDF68 3002BD27 */  addiu      $29, $29, 0x230
    /* 1CDF6C 002CDF6C 0800E003 */  jr         $31
    /* 1CDF70 002CDF70 00000000 */   nop
    /* 1CDF74 002CDF74 00000000 */  nop
    /* 1CDF78 002CDF78 00000000 */  nop
    /* 1CDF7C 002CDF7C 00000000 */  nop
.size func_002cb6c0, 0x28c0
