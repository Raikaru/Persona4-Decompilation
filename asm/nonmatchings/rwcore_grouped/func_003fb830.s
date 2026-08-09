.section .text
.set noat
.set noreorder
glabel func_003fb830
    /* 2FB830 003FB830 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2FB834 003FB834 3000BFFF */  sd         $31, 0x30($29)
    /* 2FB838 003FB838 2000B27F */  sq         $18, 0x20($29)
    /* 2FB83C 003FB83C 1000B17F */  sq         $17, 0x10($29)
    /* 2FB840 003FB840 0000B07F */  sq         $16, 0x0($29)
    /* 2FB844 003FB844 2D88A000 */  daddu      $17, $5, $0
    /* 2FB848 003FB848 38B9828F */  lw         $2, -0x46C8($28)
    /* 2FB84C 003FB84C 21102202 */  addu       $2, $17, $2
    /* 2FB850 003FB850 17004290 */  lbu        $2, 0x17($2)
    /* 2FB854 003FB854 04004010 */  beqz       $2, .L003FB868
    /* 2FB858 003FB858 00000000 */   nop
    /* 2FB85C 003FB85C 2D202002 */  daddu      $4, $17, $0
    /* 2FB860 003FB860 343F100C */  jal        func_0040fcd0
    /* 2FB864 003FB864 2D280000 */   daddu     $5, $0, $0
  .L003FB868:
    /* 2FB868 003FB868 A43E100C */  jal        func_0040fa90
    /* 2FB86C 003FB86C 2D202002 */   daddu     $4, $17, $0
    /* 2FB870 003FB870 21002292 */  lbu        $2, 0x21($17)
    /* 2FB874 003FB874 80004230 */  andi       $2, $2, 0x80
    /* 2FB878 003FB878 3B004014 */  bnez       $2, .L003FB968
    /* 2FB87C 003FB87C 00000000 */   nop
    /* 2FB880 003FB880 38B9828F */  lw         $2, -0x46C8($28)
    /* 2FB884 003FB884 21802202 */  addu       $16, $17, $2
    /* 2FB888 003FB888 0000028E */  lw         $2, 0x0($16)
    /* 2FB88C 003FB88C 3800401C */  bgtz       $2, .L003FB970
    /* 2FB890 003FB890 00000000 */   nop
    /* 2FB894 003FB894 000000AE */  sw         $0, 0x0($16)
  .L003FB898:
    /* 2FB898 003FB898 0000028E */  lw         $2, 0x0($16)
    /* 2FB89C 003FB89C 08004014 */  bnez       $2, .L003FB8C0
    /* 2FB8A0 003FB8A0 00000000 */   nop
    /* 2FB8A4 003FB8A4 2400248E */  lw         $4, 0x24($17)
    /* 2FB8A8 003FB8A8 05008010 */  beqz       $4, .L003FB8C0
    /* 2FB8AC 003FB8AC 00000000 */   nop
    /* 2FB8B0 003FB8B0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2FB8B4 003FB8B4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2FB8B8 003FB8B8 09F84000 */  jalr       $2
    /* 2FB8BC 003FB8BC 00000000 */   nop
  .L003FB8C0:
    /* 2FB8C0 003FB8C0 0000028E */  lw         $2, 0x0($16)
    /* 2FB8C4 003FB8C4 1A004014 */  bnez       $2, .L003FB930
    /* 2FB8C8 003FB8C8 00000000 */   nop
    /* 2FB8CC 003FB8CC 3800048E */  lw         $4, 0x38($16)
    /* 2FB8D0 003FB8D0 06008010 */  beqz       $4, .L003FB8EC
    /* 2FB8D4 003FB8D4 00000000 */   nop
    /* 2FB8D8 003FB8D8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2FB8DC 003FB8DC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2FB8E0 003FB8E0 09F84000 */  jalr       $2
    /* 2FB8E4 003FB8E4 00000000 */   nop
    /* 2FB8E8 003FB8E8 380000AE */  sw         $0, 0x38($16)
  .L003FB8EC:
    /* 2FB8EC 003FB8EC 8800113C */  lui        $17, %hi(jtbl_008873EC)
    /* 2FB8F0 003FB8F0 2D900000 */  daddu      $18, $0, $0
    /* 2FB8F4 003FB8F4 EC733126 */  addiu      $17, $17, %lo(jtbl_008873EC)
  .L003FB8F8:
    /* 2FB8F8 003FB8F8 3C00048E */  lw         $4, 0x3C($16)
    /* 2FB8FC 003FB8FC 06008010 */  beqz       $4, .L003FB918
    /* 2FB900 003FB900 00000000 */   nop
    /* 2FB904 003FB904 0000228E */  lw         $2, 0x0($17)
    /* 2FB908 003FB908 09F84000 */  jalr       $2
    /* 2FB90C 003FB90C 00000000 */   nop
    /* 2FB910 003FB910 3C0000AE */  sw         $0, 0x3C($16)
    /* 2FB914 003FB914 00000000 */  nop
  .L003FB918:
    /* 2FB918 003FB918 01005226 */  addiu      $18, $18, 0x1
    /* 2FB91C 003FB91C 0700422A */  slti       $2, $18, 0x7
    /* 2FB920 003FB920 F5FF4014 */  bnez       $2, .L003FB8F8
    /* 2FB924 003FB924 04001026 */   addiu     $16, $16, 0x4
    /* 2FB928 003FB928 0F000010 */  b          .L003FB968
    /* 2FB92C 003FB92C 00000000 */   nop
  .L003FB930:
    /* 2FB930 003FB930 3800028E */  lw         $2, 0x38($16)
    /* 2FB934 003FB934 19004014 */  bnez       $2, .L003FB99C
    /* 2FB938 003FB938 00000000 */   nop
  .L003FB93C:
    /* 2FB93C 003FB93C 2D180000 */  daddu      $3, $0, $0
  .L003FB940:
    /* 2FB940 003FB940 3C00028E */  lw         $2, 0x3C($16)
    /* 2FB944 003FB944 17004014 */  bnez       $2, .L003FB9A4
    /* 2FB948 003FB948 00000000 */   nop
    /* 2FB94C 003FB94C 00000000 */  nop
  .L003FB950:
    /* 2FB950 003FB950 01006324 */  addiu      $3, $3, 0x1
    /* 2FB954 003FB954 07006228 */  slti       $2, $3, 0x7
    /* 2FB958 003FB958 04001026 */  addiu      $16, $16, 0x4
    /* 2FB95C 003FB95C F8FF4014 */  bnez       $2, .L003FB940
    /* 2FB960 003FB960 00000000 */   nop
    /* 2FB964 003FB964 00000000 */  nop
  .L003FB968:
    /* 2FB968 003FB968 11000010 */  b          .L003FB9B0
    /* 2FB96C 003FB96C 01000224 */   addiu     $2, $0, 0x1
  .L003FB970:
    /* 2FB970 003FB970 B4CC0F0C */  jal        func_003f32d0
    /* 2FB974 003FB974 00000000 */   nop
    /* 2FB978 003FB978 B4CC0F0C */  jal        func_003f32d0
    /* 2FB97C 003FB97C 00000000 */   nop
    /* 2FB980 003FB980 0000028E */  lw         $2, 0x0($16)
    /* 2FB984 003FB984 00000000 */  nop
    /* 2FB988 003FB988 00000000 */  nop
    /* 2FB98C 003FB98C F8FF401C */  bgtz       $2, .L003FB970
    /* 2FB990 003FB990 00000000 */   nop
    /* 2FB994 003FB994 C0FF0010 */  b          .L003FB898
    /* 2FB998 003FB998 000000AE */   sw        $0, 0x0($16)
  .L003FB99C:
    /* 2FB99C 003FB99C E7FF0010 */  b          .L003FB93C
    /* 2FB9A0 003FB9A0 380000AE */   sw        $0, 0x38($16)
  .L003FB9A4:
    /* 2FB9A4 003FB9A4 EAFF0010 */  b          .L003FB950
    /* 2FB9A8 003FB9A8 3C0000AE */   sw        $0, 0x3C($16)
    /* 2FB9AC 003FB9AC 00000000 */  nop
  .L003FB9B0:
    /* 2FB9B0 003FB9B0 3000BFDF */  ld         $31, 0x30($29)
    /* 2FB9B4 003FB9B4 2000B27B */  lq         $18, 0x20($29)
    /* 2FB9B8 003FB9B8 1000B17B */  lq         $17, 0x10($29)
    /* 2FB9BC 003FB9BC 0000B07B */  lq         $16, 0x0($29)
    /* 2FB9C0 003FB9C0 0800E003 */  jr         $31
    /* 2FB9C4 003FB9C4 4000BD27 */   addiu     $29, $29, 0x40
    /* 2FB9C8 003FB9C8 00000000 */  nop
    /* 2FB9CC 003FB9CC 00000000 */  nop
.size func_003fb830, 0x1a0
