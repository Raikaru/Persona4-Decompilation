.section .text
.set noat
.set noreorder
glabel func_004aa890
    /* 3AA890 004AA890 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3AA894 004AA894 4000BFFF */  sd         $31, 0x40($29)
    /* 3AA898 004AA898 3000B37F */  sq         $19, 0x30($29)
    /* 3AA89C 004AA89C 2000B27F */  sq         $18, 0x20($29)
    /* 3AA8A0 004AA8A0 1000B17F */  sq         $17, 0x10($29)
    /* 3AA8A4 004AA8A4 0000B07F */  sq         $16, 0x0($29)
    /* 3AA8A8 004AA8A8 2000918C */  lw         $17, 0x20($4)
    /* 3AA8AC 004AA8AC 2400838C */  lw         $3, 0x24($4)
    /* 3AA8B0 004AA8B0 C0006624 */  addiu      $6, $3, 0xC0
    /* 3AA8B4 004AA8B4 CC00658C */  lw         $5, 0xCC($3)
    /* 3AA8B8 004AA8B8 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* 3AA8BC 004AA8BC 2418A300 */  and        $3, $5, $3
    /* 3AA8C0 004AA8C0 1E006010 */  beqz       $3, .L004AA93C
    /* 3AA8C4 004AA8C4 00000000 */   nop
    /* 3AA8C8 004AA8C8 2800838C */  lw         $3, 0x28($4)
    /* 3AA8CC 004AA8CC 0800708C */  lw         $16, 0x8($3)
    /* 3AA8D0 004AA8D0 0000D28C */  lw         $18, 0x0($6)
    /* 3AA8D4 004AA8D4 6500412A */  slti       $1, $18, 0x65
    /* 3AA8D8 004AA8D8 06002014 */  bnez       $1, .L004AA8F4
    /* 3AA8DC 004AA8DC 00000000 */   nop
    /* 3AA8E0 004AA8E0 7100043C */  lui        $4, %hi(D_00714380)
    /* 3AA8E4 004AA8E4 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3AA8E8 004AA8E8 69020524 */  addiu      $5, $0, 0x269
    /* 3AA8EC 004AA8EC CCB5110C */  jal        func_0046d730
    /* 3AA8F0 004AA8F0 00000000 */   nop
  .L004AA8F4:
    /* 3AA8F4 004AA8F4 2D980000 */  daddu      $19, $0, $0
    /* 3AA8F8 004AA8F8 0D000010 */  b          .L004AA930
    /* 3AA8FC 004AA8FC 00000000 */   nop
  .L004AA900:
    /* 3AA900 004AA900 0000238E */  lw         $3, 0x0($17)
    /* 3AA904 004AA904 08006014 */  bnez       $3, .L004AA928
    /* 3AA908 004AA908 00000000 */   nop
    /* 3AA90C 004AA90C 0F002392 */  lbu        $3, 0xF($17)
    /* 3AA910 004AA910 05006018 */  blez       $3, .L004AA928
    /* 3AA914 004AA914 00000000 */   nop
    /* 3AA918 004AA918 08002426 */  addiu      $4, $17, 0x8
    /* 3AA91C 004AA91C 2D280002 */  daddu      $5, $16, $0
    /* 3AA920 004AA920 24A2120C */  jal        func_004a8890
    /* 3AA924 004AA924 00000000 */   nop
  .L004AA928:
    /* 3AA928 004AA928 34003126 */  addiu      $17, $17, 0x34
    /* 3AA92C 004AA92C 01007326 */  addiu      $19, $19, 0x1
  .L004AA930:
    /* 3AA930 004AA930 2A187202 */  slt        $3, $19, $18
    /* 3AA934 004AA934 F2FF6014 */  bnez       $3, .L004AA900
    /* 3AA938 004AA938 00000000 */   nop
  .L004AA93C:
    /* 3AA93C 004AA93C 4000BFDF */  ld         $31, 0x40($29)
    /* 3AA940 004AA940 3000B37B */  lq         $19, 0x30($29)
    /* 3AA944 004AA944 2000B27B */  lq         $18, 0x20($29)
    /* 3AA948 004AA948 1000B17B */  lq         $17, 0x10($29)
    /* 3AA94C 004AA94C 0000B07B */  lq         $16, 0x0($29)
    /* 3AA950 004AA950 5000BD27 */  addiu      $29, $29, 0x50
    /* 3AA954 004AA954 0800E003 */  jr         $31
    /* 3AA958 004AA958 00000000 */   nop
    /* 3AA95C 004AA95C 00000000 */  nop
.size func_004aa890, 0xd0
