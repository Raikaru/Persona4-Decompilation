.section .text
.set noat
.set noreorder
glabel func_003bc880
    /* 2BC880 003BC880 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2BC884 003BC884 4000BFFF */  sd         $31, 0x40($29)
    /* 2BC888 003BC888 3000B37F */  sq         $19, 0x30($29)
    /* 2BC88C 003BC88C 2000B27F */  sq         $18, 0x20($29)
    /* 2BC890 003BC890 2D988000 */  daddu      $19, $4, $0
    /* 2BC894 003BC894 1000B17F */  sq         $17, 0x10($29)
    /* 2BC898 003BC898 2D90A000 */  daddu      $18, $5, $0
    /* 2BC89C 003BC89C 3E006012 */  beqz       $19, .L003BC998
    /* 2BC8A0 003BC8A0 0000B07F */   sq        $16, 0x0($29)
    /* 2BC8A4 003BC8A4 0000658E */  lw         $5, 0x0($19)
    /* 2BC8A8 003BC8A8 3B00A018 */  blez       $5, .L003BC998
    /* 2BC8AC 003BC8AC 00000000 */   nop
    /* 2BC8B0 003BC8B0 2A080500 */  slt        $1, $0, $5
    /* 2BC8B4 003BC8B4 5C00A0AF */  sw         $0, 0x5C($29)
    /* 2BC8B8 003BC8B8 2D100000 */  daddu      $2, $0, $0
    /* 2BC8BC 003BC8BC 0C002010 */  beqz       $1, .L003BC8F0
    /* 2BC8C0 003BC8C0 2D380000 */   daddu     $7, $0, $0
    /* 2BC8C4 003BC8C4 0400648E */  lw         $4, 0x4($19)
    /* 2BC8C8 003BC8C8 2D300000 */  daddu      $6, $0, $0
  .L003BC8CC:
    /* 2BC8CC 003BC8CC 21188600 */  addu       $3, $4, $6
    /* 2BC8D0 003BC8D0 0400638C */  lw         $3, 0x4($3)
    /* 2BC8D4 003BC8D4 0C006014 */  bnez       $3, .L003BC908
    /* 2BC8D8 003BC8D8 00000000 */   nop
    /* 2BC8DC 003BC8DC 00000000 */  nop
  .L003BC8E0:
    /* 2BC8E0 003BC8E0 0100E724 */  addiu      $7, $7, 0x1
    /* 2BC8E4 003BC8E4 2A18E500 */  slt        $3, $7, $5
    /* 2BC8E8 003BC8E8 F8FF6014 */  bnez       $3, .L003BC8CC
    /* 2BC8EC 003BC8EC 1000C624 */   addiu     $6, $6, 0x10
  .L003BC8F0:
    /* 2BC8F0 003BC8F0 3C100200 */  dsll32     $2, $2, 0
    /* 2BC8F4 003BC8F4 3F100200 */  dsra32     $2, $2, 0
    /* 2BC8F8 003BC8F8 09004014 */  bnez       $2, .L003BC920
    /* 2BC8FC 003BC8FC 00000000 */   nop
  .L003BC900:
    /* 2BC900 003BC900 26000010 */  b          .L003BC99C
    /* 2BC904 003BC904 2D104002 */   daddu     $2, $18, $0
  .L003BC908:
    /* 2BC908 003BC908 3C100200 */  dsll32     $2, $2, 0
    /* 2BC90C 003BC90C 3F100200 */  dsra32     $2, $2, 0
    /* 2BC910 003BC910 01004224 */  addiu      $2, $2, 0x1
    /* 2BC914 003BC914 F2FF0010 */  b          .L003BC8E0
    /* 2BC918 003BC918 5C00A2AF */   sw        $2, 0x5C($29)
    /* 2BC91C 003BC91C 00000000 */  nop
  .L003BC920:
    /* 2BC920 003BC920 2D204002 */  daddu      $4, $18, $0
    /* 2BC924 003BC924 5C00A527 */  addiu      $5, $29, 0x5C
    /* 2BC928 003BC928 907C0F0C */  jal        func_003df240
    /* 2BC92C 003BC92C 04000624 */   addiu     $6, $0, 0x4
    /* 2BC930 003BC930 12004010 */  beqz       $2, .L003BC97C
    /* 2BC934 003BC934 00000000 */   nop
    /* 2BC938 003BC938 0000628E */  lw         $2, 0x0($19)
    /* 2BC93C 003BC93C 2A080200 */  slt        $1, $0, $2
    /* 2BC940 003BC940 EFFF2010 */  beqz       $1, .L003BC900
    /* 2BC944 003BC944 2D800000 */   daddu     $16, $0, $0
    /* 2BC948 003BC948 2D880000 */  daddu      $17, $0, $0
  .L003BC94C:
    /* 2BC94C 003BC94C 0400628E */  lw         $2, 0x4($19)
    /* 2BC950 003BC950 21205100 */  addu       $4, $2, $17
    /* 2BC954 003BC954 0400828C */  lw         $2, 0x4($4)
    /* 2BC958 003BC958 0A004014 */  bnez       $2, .L003BC984
    /* 2BC95C 003BC95C 00000000 */   nop
  .L003BC960:
    /* 2BC960 003BC960 0000628E */  lw         $2, 0x0($19)
    /* 2BC964 003BC964 01001026 */  addiu      $16, $16, 0x1
    /* 2BC968 003BC968 2A100202 */  slt        $2, $16, $2
    /* 2BC96C 003BC96C F7FF4014 */  bnez       $2, .L003BC94C
    /* 2BC970 003BC970 10003126 */   addiu     $17, $17, 0x10
    /* 2BC974 003BC974 E2FF0010 */  b          .L003BC900
    /* 2BC978 003BC978 00000000 */   nop
  .L003BC97C:
    /* 2BC97C 003BC97C 07000010 */  b          .L003BC99C
    /* 2BC980 003BC980 2D100000 */   daddu     $2, $0, $0
  .L003BC984:
    /* 2BC984 003BC984 00F10E0C */  jal        func_003bc400
    /* 2BC988 003BC988 2D284002 */   daddu     $5, $18, $0
    /* 2BC98C 003BC98C F4FF0010 */  b          .L003BC960
    /* 2BC990 003BC990 2D904000 */   daddu     $18, $2, $0
    /* 2BC994 003BC994 00000000 */  nop
  .L003BC998:
    /* 2BC998 003BC998 2D100000 */  daddu      $2, $0, $0
  .L003BC99C:
    /* 2BC99C 003BC99C 4000BFDF */  ld         $31, 0x40($29)
    /* 2BC9A0 003BC9A0 3000B37B */  lq         $19, 0x30($29)
    /* 2BC9A4 003BC9A4 2000B27B */  lq         $18, 0x20($29)
    /* 2BC9A8 003BC9A8 1000B17B */  lq         $17, 0x10($29)
    /* 2BC9AC 003BC9AC 0000B07B */  lq         $16, 0x0($29)
    /* 2BC9B0 003BC9B0 0800E003 */  jr         $31
    /* 2BC9B4 003BC9B4 6000BD27 */   addiu     $29, $29, 0x60
    /* 2BC9B8 003BC9B8 00000000 */  nop
    /* 2BC9BC 003BC9BC 00000000 */  nop
.size func_003bc880, 0x140
