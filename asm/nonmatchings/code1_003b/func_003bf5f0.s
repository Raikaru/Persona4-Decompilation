.section .text
.set noat
.set noreorder
glabel func_003bf5f0
    /* 2BF5F0 003BF5F0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 2BF5F4 003BF5F4 4000BFFF */  sd         $31, 0x40($29)
    /* 2BF5F8 003BF5F8 9800A727 */  addiu      $7, $29, 0x98
    /* 2BF5FC 003BF5FC 3000B37F */  sq         $19, 0x30($29)
    /* 2BF600 003BF600 2000B27F */  sq         $18, 0x20($29)
    /* 2BF604 003BF604 2D988000 */  daddu      $19, $4, $0
    /* 2BF608 003BF608 1000B17F */  sq         $17, 0x10($29)
    /* 2BF60C 003BF60C 2D90A000 */  daddu      $18, $5, $0
    /* 2BF610 003BF610 2D88C000 */  daddu      $17, $6, $0
    /* 2BF614 003BF614 01000524 */  addiu      $5, $0, 0x1
    /* 2BF618 003BF618 9C00A627 */  addiu      $6, $29, 0x9C
    /* 2BF61C 003BF61C 147C0F0C */  jal        func_003df050
    /* 2BF620 003BF620 0000B07F */   sq        $16, 0x0($29)
    /* 2BF624 003BF624 3D004010 */  beqz       $2, .L003BF71C
    /* 2BF628 003BF628 00000000 */   nop
    /* 2BF62C 003BF62C 9800A38F */  lw         $3, 0x98($29)
    /* 2BF630 003BF630 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BF634 003BF634 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BF638 003BF638 2B106200 */  sltu       $2, $3, $2
    /* 2BF63C 003BF63C AB004014 */  bnez       $2, .L003BF8EC
    /* 2BF640 003BF640 00000000 */   nop
    /* 2BF644 003BF644 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BF648 003BF648 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BF64C 003BF64C 2B086100 */  sltu       $1, $3, $1
    /* 2BF650 003BF650 A6002010 */  beqz       $1, .L003BF8EC
    /* 2BF654 003BF654 00000000 */   nop
    /* 2BF658 003BF658 5000A427 */  addiu      $4, $29, 0x50
    /* 2BF65C 003BF65C 2D280000 */  daddu      $5, $0, $0
    /* 2BF660 003BF660 72FE100C */  jal        func_0043f9c8
    /* 2BF664 003BF664 10000624 */   addiu     $6, $0, 0x10
    /* 2BF668 003BF668 9C00A68F */  lw         $6, 0x9C($29)
    /* 2BF66C 003BF66C 2D206002 */  daddu      $4, $19, $0
    /* 2BF670 003BF670 448A0F0C */  jal        func_003e2910
    /* 2BF674 003BF674 5000A527 */   addiu     $5, $29, 0x50
    /* 2BF678 003BF678 9C00A38F */  lw         $3, 0x9C($29)
    /* 2BF67C 003BF67C 26106200 */  xor        $2, $3, $2
    /* 2BF680 003BF680 0100422C */  sltiu      $2, $2, 0x1
    /* 2BF684 003BF684 2F004010 */  beqz       $2, .L003BF744
    /* 2BF688 003BF688 00000000 */   nop
    /* 2BF68C 003BF68C 38000F0C */  jal        func_003c00e0
    /* 2BF690 003BF690 00000000 */   nop
    /* 2BF694 003BF694 2D804000 */  daddu      $16, $2, $0
    /* 2BF698 003BF698 34000012 */  beqz       $16, .L003BF76C
    /* 2BF69C 003BF69C 00000000 */   nop
    /* 2BF6A0 003BF6A0 5800A28F */  lw         $2, 0x58($29)
    /* 2BF6A4 003BF6A4 020002A2 */  sb         $2, 0x2($16)
    /* 2BF6A8 003BF6A8 0400428E */  lw         $2, 0x4($18)
    /* 2BF6AC 003BF6AC 31004014 */  bnez       $2, .L003BF774
    /* 2BF6B0 003BF6B0 00000000 */   nop
    /* 2BF6B4 003BF6B4 0400228E */  lw         $2, 0x4($17)
  .L003BF6B8:
    /* 2BF6B8 003BF6B8 37004010 */  beqz       $2, .L003BF798
    /* 2BF6BC 003BF6BC 00000000 */   nop
    /* 2BF6C0 003BF6C0 5400A38F */  lw         $3, 0x54($29)
    /* 2BF6C4 003BF6C4 2D200002 */  daddu      $4, $16, $0
    /* 2BF6C8 003BF6C8 0000228E */  lw         $2, 0x0($17)
    /* 2BF6CC 003BF6CC 80180300 */  sll        $3, $3, 2
    /* 2BF6D0 003BF6D0 21104300 */  addu       $2, $2, $3
    /* 2BF6D4 003BF6D4 0000458C */  lw         $5, 0x0($2)
    /* 2BF6D8 003BF6D8 84000F0C */  jal        func_003c0210
    /* 2BF6DC 003BF6DC 2D300000 */   daddu     $6, $0, $0
  .L003BF6E0:
    /* 2BF6E0 003BF6E0 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2BF6E4 003BF6E4 2D286002 */  daddu      $5, $19, $0
    /* 2BF6E8 003BF6E8 70AF8424 */  addiu      $4, $4, %lo(D_0070AF70)
    /* 2BF6EC 003BF6EC 2D300002 */  daddu      $6, $16, $0
    /* 2BF6F0 003BF6F0 BCB680AF */  sw         $0, -0x4944($28)
    /* 2BF6F4 003BF6F4 448C0F0C */  jal        func_003e3110
    /* 2BF6F8 003BF6F8 B8B680AF */   sw        $0, -0x4948($28)
    /* 2BF6FC 003BF6FC 2B100200 */  sltu       $2, $0, $2
    /* 2BF700 003BF700 69004010 */  beqz       $2, .L003BF8A8
    /* 2BF704 003BF704 00000000 */   nop
    /* 2BF708 003BF708 BCB6858F */  lw         $5, -0x4944($28)
    /* 2BF70C 003BF70C 7000A014 */  bnez       $5, .L003BF8D0
    /* 2BF710 003BF710 00000000 */   nop
  .L003BF714:
    /* 2BF714 003BF714 7E000010 */  b          .L003BF910
    /* 2BF718 003BF718 2D100002 */   daddu     $2, $16, $0
  .L003BF71C:
    /* 2BF71C 003BF71C 02000324 */  addiu      $3, $0, 0x2
    /* 2BF720 003BF720 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2BF724 003BF724 9000A3AF */  sw         $3, 0x90($29)
    /* 2BF728 003BF728 647D0F0C */  jal        func_003df590
    /* 2BF72C 003BF72C 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2BF730 003BF730 9400A2AF */  sw         $2, 0x94($29)
    /* 2BF734 003BF734 347D0F0C */  jal        func_003df4d0
    /* 2BF738 003BF738 9000A427 */   addiu     $4, $29, 0x90
    /* 2BF73C 003BF73C 74000010 */  b          .L003BF910
    /* 2BF740 003BF740 2D100000 */   daddu     $2, $0, $0
  .L003BF744:
    /* 2BF744 003BF744 02000324 */  addiu      $3, $0, 0x2
    /* 2BF748 003BF748 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2BF74C 003BF74C 8800A3AF */  sw         $3, 0x88($29)
    /* 2BF750 003BF750 647D0F0C */  jal        func_003df590
    /* 2BF754 003BF754 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2BF758 003BF758 8C00A2AF */  sw         $2, 0x8C($29)
    /* 2BF75C 003BF75C 347D0F0C */  jal        func_003df4d0
    /* 2BF760 003BF760 8800A427 */   addiu     $4, $29, 0x88
    /* 2BF764 003BF764 6A000010 */  b          .L003BF910
    /* 2BF768 003BF768 2D100000 */   daddu     $2, $0, $0
  .L003BF76C:
    /* 2BF76C 003BF76C 68000010 */  b          .L003BF910
    /* 2BF770 003BF770 2D100000 */   daddu     $2, $0, $0
  .L003BF774:
    /* 2BF774 003BF774 5000A38F */  lw         $3, 0x50($29)
    /* 2BF778 003BF778 0000428E */  lw         $2, 0x0($18)
    /* 2BF77C 003BF77C 80180300 */  sll        $3, $3, 2
    /* 2BF780 003BF780 21104300 */  addu       $2, $2, $3
    /* 2BF784 003BF784 0000458C */  lw         $5, 0x0($2)
    /* 2BF788 003BF788 E4060F0C */  jal        func_003c1b90
    /* 2BF78C 003BF78C 2D200002 */   daddu     $4, $16, $0
    /* 2BF790 003BF790 C9FF0010 */  b          .L003BF6B8
    /* 2BF794 003BF794 0400228E */   lw        $2, 0x4($17)
  .L003BF798:
    /* 2BF798 003BF798 2D206002 */  daddu      $4, $19, $0
    /* 2BF79C 003BF79C 0F000524 */  addiu      $5, $0, 0xF
    /* 2BF7A0 003BF7A0 2D300000 */  daddu      $6, $0, $0
    /* 2BF7A4 003BF7A4 147C0F0C */  jal        func_003df050
    /* 2BF7A8 003BF7A8 9800A727 */   addiu     $7, $29, 0x98
    /* 2BF7AC 003BF7AC 1A004010 */  beqz       $2, .L003BF818
    /* 2BF7B0 003BF7B0 00000000 */   nop
    /* 2BF7B4 003BF7B4 9800A38F */  lw         $3, 0x98($29)
    /* 2BF7B8 003BF7B8 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BF7BC 003BF7BC 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BF7C0 003BF7C0 2B106200 */  sltu       $2, $3, $2
    /* 2BF7C4 003BF7C4 2C004014 */  bnez       $2, .L003BF878
    /* 2BF7C8 003BF7C8 00000000 */   nop
    /* 2BF7CC 003BF7CC 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BF7D0 003BF7D0 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BF7D4 003BF7D4 2B086100 */  sltu       $1, $3, $1
    /* 2BF7D8 003BF7D8 27002010 */  beqz       $1, .L003BF878
    /* 2BF7DC 003BF7DC 00000000 */   nop
    /* 2BF7E0 003BF7E0 2C0C0F0C */  jal        func_003c30b0
    /* 2BF7E4 003BF7E4 2D206002 */   daddu     $4, $19, $0
    /* 2BF7E8 003BF7E8 2D884000 */  daddu      $17, $2, $0
    /* 2BF7EC 003BF7EC 2B101100 */  sltu       $2, $0, $17
    /* 2BF7F0 003BF7F0 15004010 */  beqz       $2, .L003BF848
    /* 2BF7F4 003BF7F4 00000000 */   nop
    /* 2BF7F8 003BF7F8 2D200002 */  daddu      $4, $16, $0
    /* 2BF7FC 003BF7FC 2D282002 */  daddu      $5, $17, $0
    /* 2BF800 003BF800 84000F0C */  jal        func_003c0210
    /* 2BF804 003BF804 2D300000 */   daddu     $6, $0, $0
    /* 2BF808 003BF808 A00A0F0C */  jal        func_003c2a80
    /* 2BF80C 003BF80C 2D202002 */   daddu     $4, $17, $0
    /* 2BF810 003BF810 B3FF0010 */  b          .L003BF6E0
    /* 2BF814 003BF814 00000000 */   nop
  .L003BF818:
    /* 2BF818 003BF818 B8000F0C */  jal        func_003c02e0
    /* 2BF81C 003BF81C 2D200002 */   daddu     $4, $16, $0
    /* 2BF820 003BF820 02000324 */  addiu      $3, $0, 0x2
    /* 2BF824 003BF824 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2BF828 003BF828 8000A3AF */  sw         $3, 0x80($29)
    /* 2BF82C 003BF82C 647D0F0C */  jal        func_003df590
    /* 2BF830 003BF830 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2BF834 003BF834 8400A2AF */  sw         $2, 0x84($29)
    /* 2BF838 003BF838 347D0F0C */  jal        func_003df4d0
    /* 2BF83C 003BF83C 8000A427 */   addiu     $4, $29, 0x80
    /* 2BF840 003BF840 33000010 */  b          .L003BF910
    /* 2BF844 003BF844 2D100000 */   daddu     $2, $0, $0
  .L003BF848:
    /* 2BF848 003BF848 B8000F0C */  jal        func_003c02e0
    /* 2BF84C 003BF84C 2D200002 */   daddu     $4, $16, $0
    /* 2BF850 003BF850 02000324 */  addiu      $3, $0, 0x2
    /* 2BF854 003BF854 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2BF858 003BF858 7800A3AF */  sw         $3, 0x78($29)
    /* 2BF85C 003BF85C 647D0F0C */  jal        func_003df590
    /* 2BF860 003BF860 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2BF864 003BF864 7C00A2AF */  sw         $2, 0x7C($29)
    /* 2BF868 003BF868 347D0F0C */  jal        func_003df4d0
    /* 2BF86C 003BF86C 7800A427 */   addiu     $4, $29, 0x78
    /* 2BF870 003BF870 27000010 */  b          .L003BF910
    /* 2BF874 003BF874 2D100000 */   daddu     $2, $0, $0
  .L003BF878:
    /* 2BF878 003BF878 B8000F0C */  jal        func_003c02e0
    /* 2BF87C 003BF87C 2D200002 */   daddu     $4, $16, $0
    /* 2BF880 003BF880 02000324 */  addiu      $3, $0, 0x2
    /* 2BF884 003BF884 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BF888 003BF888 7000A3AF */  sw         $3, 0x70($29)
    /* 2BF88C 003BF88C 647D0F0C */  jal        func_003df590
    /* 2BF890 003BF890 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BF894 003BF894 7400A2AF */  sw         $2, 0x74($29)
    /* 2BF898 003BF898 347D0F0C */  jal        func_003df4d0
    /* 2BF89C 003BF89C 7000A427 */   addiu     $4, $29, 0x70
    /* 2BF8A0 003BF8A0 1B000010 */  b          .L003BF910
    /* 2BF8A4 003BF8A4 2D100000 */   daddu     $2, $0, $0
  .L003BF8A8:
    /* 2BF8A8 003BF8A8 02000324 */  addiu      $3, $0, 0x2
    /* 2BF8AC 003BF8AC 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2BF8B0 003BF8B0 6800A3AF */  sw         $3, 0x68($29)
    /* 2BF8B4 003BF8B4 647D0F0C */  jal        func_003df590
    /* 2BF8B8 003BF8B8 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2BF8BC 003BF8BC 6C00A2AF */  sw         $2, 0x6C($29)
    /* 2BF8C0 003BF8C0 347D0F0C */  jal        func_003df4d0
    /* 2BF8C4 003BF8C4 6800A427 */   addiu     $4, $29, 0x68
    /* 2BF8C8 003BF8C8 11000010 */  b          .L003BF910
    /* 2BF8CC 003BF8CC 2D100000 */   daddu     $2, $0, $0
  .L003BF8D0:
    /* 2BF8D0 003BF8D0 B8B6878F */  lw         $7, -0x4948($28)
    /* 2BF8D4 003BF8D4 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2BF8D8 003BF8D8 70AF8424 */  addiu      $4, $4, %lo(D_0070AF70)
    /* 2BF8DC 003BF8DC BC8C0F0C */  jal        func_003e32f0
    /* 2BF8E0 003BF8E0 2D300002 */   daddu     $6, $16, $0
    /* 2BF8E4 003BF8E4 8BFF0010 */  b          .L003BF714
    /* 2BF8E8 003BF8E8 00000000 */   nop
  .L003BF8EC:
    /* 2BF8EC 003BF8EC 02000324 */  addiu      $3, $0, 0x2
    /* 2BF8F0 003BF8F0 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BF8F4 003BF8F4 6000A3AF */  sw         $3, 0x60($29)
    /* 2BF8F8 003BF8F8 647D0F0C */  jal        func_003df590
    /* 2BF8FC 003BF8FC 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BF900 003BF900 6400A2AF */  sw         $2, 0x64($29)
    /* 2BF904 003BF904 347D0F0C */  jal        func_003df4d0
    /* 2BF908 003BF908 6000A427 */   addiu     $4, $29, 0x60
    /* 2BF90C 003BF90C 2D100000 */  daddu      $2, $0, $0
  .L003BF910:
    /* 2BF910 003BF910 4000BFDF */  ld         $31, 0x40($29)
    /* 2BF914 003BF914 3000B37B */  lq         $19, 0x30($29)
    /* 2BF918 003BF918 2000B27B */  lq         $18, 0x20($29)
    /* 2BF91C 003BF91C 1000B17B */  lq         $17, 0x10($29)
    /* 2BF920 003BF920 0000B07B */  lq         $16, 0x0($29)
    /* 2BF924 003BF924 0800E003 */  jr         $31
    /* 2BF928 003BF928 A000BD27 */   addiu     $29, $29, 0xA0
    /* 2BF92C 003BF92C 00000000 */  nop
.size func_003bf5f0, 0x340
