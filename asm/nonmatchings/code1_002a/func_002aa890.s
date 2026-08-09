.section .text
.set noat
.set noreorder
glabel func_002aa890
    /* 1AA890 002AA890 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1AA894 002AA894 1000BFFF */  sd         $31, 0x10($29)
    /* 1AA898 002AA898 0000B07F */  sq         $16, 0x0($29)
    /* 1AA89C 002AA89C 2D808000 */  daddu      $16, $4, $0
    /* 1AA8A0 002AA8A0 8800023C */  lui        $2, %hi(D_00882F20)
    /* 1AA8A4 002AA8A4 202F4224 */  addiu      $2, $2, %lo(D_00882F20)
    /* 1AA8A8 002AA8A8 8800033C */  lui        $3, %hi(D_00882F24)
    /* 1AA8AC 002AA8AC 242F658C */  lw         $5, %lo(D_00882F24)($3)
    /* 1AA8B0 002AA8B0 04000424 */  addiu      $4, $0, 0x4
    /* 1AA8B4 002AA8B4 1900A410 */  beq        $5, $4, .L002AA91C
    /* 1AA8B8 002AA8B8 00000000 */   nop
    /* 1AA8BC 002AA8BC 03000324 */  addiu      $3, $0, 0x3
    /* 1AA8C0 002AA8C0 1100A310 */  beq        $5, $3, .L002AA908
    /* 1AA8C4 002AA8C4 00000000 */   nop
    /* 1AA8C8 002AA8C8 01000324 */  addiu      $3, $0, 0x1
    /* 1AA8CC 002AA8CC 0600A310 */  beq        $5, $3, .L002AA8E8
    /* 1AA8D0 002AA8D0 00000000 */   nop
    /* 1AA8D4 002AA8D4 0300A010 */  beqz       $5, .L002AA8E4
    /* 1AA8D8 002AA8D8 00000000 */   nop
    /* 1AA8DC 002AA8DC 40000010 */  b          .L002AA9E0
    /* 1AA8E0 002AA8E0 00000000 */   nop
  .L002AA8E4:
    /* 1AA8E4 002AA8E4 040043AC */  sw         $3, 0x4($2)
  .L002AA8E8:
    /* 1AA8E8 002AA8E8 0000438C */  lw         $3, 0x0($2)
    /* 1AA8EC 002AA8EC 01006330 */  andi       $3, $3, 0x1
    /* 1AA8F0 002AA8F0 3B006010 */  beqz       $3, .L002AA9E0
    /* 1AA8F4 002AA8F4 00000000 */   nop
    /* 1AA8F8 002AA8F8 03000324 */  addiu      $3, $0, 0x3
    /* 1AA8FC 002AA8FC 040043AC */  sw         $3, 0x4($2)
    /* 1AA900 002AA900 37000010 */  b          .L002AA9E0
    /* 1AA904 002AA904 00000000 */   nop
  .L002AA908:
    /* 1AA908 002AA908 040044AC */  sw         $4, 0x4($2)
    /* 1AA90C 002AA90C 080040AC */  sw         $0, 0x8($2)
    /* 1AA910 002AA910 0000438C */  lw         $3, 0x0($2)
    /* 1AA914 002AA914 02006334 */  ori        $3, $3, 0x2
    /* 1AA918 002AA918 000043AC */  sw         $3, 0x0($2)
  .L002AA91C:
    /* 1AA91C 002AA91C 0000448C */  lw         $4, 0x0($2)
    /* 1AA920 002AA920 01008330 */  andi       $3, $4, 0x1
    /* 1AA924 002AA924 03006014 */  bnez       $3, .L002AA934
    /* 1AA928 002AA928 00000000 */   nop
    /* 1AA92C 002AA92C 04008334 */  ori        $3, $4, 0x4
    /* 1AA930 002AA930 000043AC */  sw         $3, 0x0($2)
  .L002AA934:
    /* 1AA934 002AA934 0000448C */  lw         $4, 0x0($2)
    /* 1AA938 002AA938 02008330 */  andi       $3, $4, 0x2
    /* 1AA93C 002AA93C 0E006010 */  beqz       $3, .L002AA978
    /* 1AA940 002AA940 00000000 */   nop
    /* 1AA944 002AA944 0C00438C */  lw         $3, 0xC($2)
    /* 1AA948 002AA948 05006128 */  slti       $1, $3, 0x5
    /* 1AA94C 002AA94C 05002010 */  beqz       $1, .L002AA964
    /* 1AA950 002AA950 00000000 */   nop
    /* 1AA954 002AA954 01006324 */  addiu      $3, $3, 0x1
    /* 1AA958 002AA958 0C0043AC */  sw         $3, 0xC($2)
    /* 1AA95C 002AA95C 15000010 */  b          .L002AA9B4
    /* 1AA960 002AA960 00000000 */   nop
  .L002AA964:
    /* 1AA964 002AA964 FDFF0324 */  addiu      $3, $0, -0x3
    /* 1AA968 002AA968 24188300 */  and        $3, $4, $3
    /* 1AA96C 002AA96C 000043AC */  sw         $3, 0x0($2)
    /* 1AA970 002AA970 10000010 */  b          .L002AA9B4
    /* 1AA974 002AA974 00000000 */   nop
  .L002AA978:
    /* 1AA978 002AA978 04008330 */  andi       $3, $4, 0x4
    /* 1AA97C 002AA97C 0D006010 */  beqz       $3, .L002AA9B4
    /* 1AA980 002AA980 00000000 */   nop
    /* 1AA984 002AA984 0C00438C */  lw         $3, 0xC($2)
    /* 1AA988 002AA988 05006018 */  blez       $3, .L002AA9A0
    /* 1AA98C 002AA98C 00000000 */   nop
    /* 1AA990 002AA990 FFFF6324 */  addiu      $3, $3, -0x1
    /* 1AA994 002AA994 0C0043AC */  sw         $3, 0xC($2)
    /* 1AA998 002AA998 06000010 */  b          .L002AA9B4
    /* 1AA99C 002AA99C 00000000 */   nop
  .L002AA9A0:
    /* 1AA9A0 002AA9A0 FBFF0324 */  addiu      $3, $0, -0x5
    /* 1AA9A4 002AA9A4 24188300 */  and        $3, $4, $3
    /* 1AA9A8 002AA9A8 000043AC */  sw         $3, 0x0($2)
    /* 1AA9AC 002AA9AC 01000324 */  addiu      $3, $0, 0x1
    /* 1AA9B0 002AA9B0 040043AC */  sw         $3, 0x4($2)
  .L002AA9B4:
    /* 1AA9B4 002AA9B4 6482110C */  jal        func_00460990
    /* 1AA9B8 002AA9B8 00000000 */   nop
    /* 1AA9BC 002AA9BC 2D284000 */  daddu      $5, $2, $0
    /* 1AA9C0 002AA9C0 2B00033C */  lui        $3, %hi(func_002aa450)
    /* 1AA9C4 002AA9C4 50A46324 */  addiu      $3, $3, %lo(func_002aa450)
    /* 1AA9C8 002AA9C8 080043AC */  sw         $3, 0x8($2)
    /* 1AA9CC 002AA9CC 100050AC */  sw         $16, 0x10($2)
    /* 1AA9D0 002AA9D0 7900043C */  lui        $4, %hi(D_007966A0)
    /* 1AA9D4 002AA9D4 A0668424 */  addiu      $4, $4, %lo(D_007966A0)
    /* 1AA9D8 002AA9D8 B082110C */  jal        func_00460ac0
    /* 1AA9DC 002AA9DC 00000000 */   nop
  .L002AA9E0:
    /* 1AA9E0 002AA9E0 2D100000 */  daddu      $2, $0, $0
    /* 1AA9E4 002AA9E4 1000BFDF */  ld         $31, 0x10($29)
    /* 1AA9E8 002AA9E8 0000B07B */  lq         $16, 0x0($29)
    /* 1AA9EC 002AA9EC 2000BD27 */  addiu      $29, $29, 0x20
    /* 1AA9F0 002AA9F0 0800E003 */  jr         $31
    /* 1AA9F4 002AA9F4 00000000 */   nop
    /* 1AA9F8 002AA9F8 00000000 */  nop
    /* 1AA9FC 002AA9FC 00000000 */  nop
.size func_002aa890, 0x170
