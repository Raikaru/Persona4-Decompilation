.section .text
.set noat
.set noreorder
glabel func_001eb8d0
    /* EB8D0 001EB8D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EB8D4 001EB8D4 0000BFFF */  sd         $31, 0x0($29)
    /* EB8D8 001EB8D8 ACB3848F */  lw         $4, -0x4C54($28)
    /* EB8DC 001EB8DC 0C00838C */  lw         $3, 0xC($4)
    /* EB8E0 001EB8E0 80006330 */  andi       $3, $3, 0x80
    /* EB8E4 001EB8E4 04006010 */  beqz       $3, .L001EB8F8
    /* EB8E8 001EB8E8 00000000 */   nop
    /* EB8EC 001EB8EC 2D180000 */  daddu      $3, $0, $0
    /* EB8F0 001EB8F0 0D000010 */  b          .L001EB928
    /* EB8F4 001EB8F4 00000000 */   nop
  .L001EB8F8:
    /* EB8F8 001EB8F8 680C838C */  lw         $3, 0xC68($4)
    /* EB8FC 001EB8FC 09006010 */  beqz       $3, .L001EB924
    /* EB900 001EB900 00000000 */   nop
    /* EB904 001EB904 68BE070C */  jal        func_001ef9a0
    /* EB908 001EB908 00000000 */   nop
    /* EB90C 001EB90C 15020324 */  addiu      $3, $0, 0x215
    /* EB910 001EB910 04004314 */  bne        $2, $3, .L001EB924
    /* EB914 001EB914 00000000 */   nop
    /* EB918 001EB918 2D180000 */  daddu      $3, $0, $0
    /* EB91C 001EB91C 02000010 */  b          .L001EB928
    /* EB920 001EB920 00000000 */   nop
  .L001EB924:
    /* EB924 001EB924 01000324 */  addiu      $3, $0, 0x1
  .L001EB928:
    /* EB928 001EB928 37006010 */  beqz       $3, .L001EBA08
    /* EB92C 001EB92C 00000000 */   nop
    /* EB930 001EB930 ACB3838F */  lw         $3, -0x4C54($28)
    /* EB934 001EB934 0C006624 */  addiu      $6, $3, 0xC
    /* EB938 001EB938 0C00648C */  lw         $4, 0xC($3)
    /* EB93C 001EB93C 00208330 */  andi       $3, $4, 0x2000
    /* EB940 001EB940 31006010 */  beqz       $3, .L001EBA08
    /* EB944 001EB944 00000000 */   nop
    /* EB948 001EB948 00108530 */  andi       $5, $4, 0x1000
    /* EB94C 001EB94C 1B00A010 */  beqz       $5, .L001EB9BC
    /* EB950 001EB950 00000000 */   nop
    /* EB954 001EB954 8C00033C */  lui        $3, %hi(D_008C024E)
    /* EB958 001EB958 4E026494 */  lhu        $4, %lo(D_008C024E)($3)
    /* EB95C 001EB95C 10008330 */  andi       $3, $4, 0x10
    /* EB960 001EB960 04006014 */  bnez       $3, .L001EB974
    /* EB964 001EB964 00000000 */   nop
    /* EB968 001EB968 20008330 */  andi       $3, $4, 0x20
    /* EB96C 001EB96C 26006010 */  beqz       $3, .L001EBA08
    /* EB970 001EB970 00000000 */   nop
  .L001EB974:
    /* EB974 001EB974 2400A010 */  beqz       $5, .L001EBA08
    /* EB978 001EB978 00000000 */   nop
    /* EB97C 001EB97C 0000C38C */  lw         $3, 0x0($6)
    /* EB980 001EB980 FFEF0224 */  addiu      $2, $0, -0x1001
    /* EB984 001EB984 24106200 */  and        $2, $3, $2
    /* EB988 001EB988 0000C2AC */  sw         $2, 0x0($6)
    /* EB98C 001EB98C ACB3828F */  lw         $2, -0x4C54($28)
    /* EB990 001EB990 D40D448C */  lw         $4, 0xDD4($2)
    /* EB994 001EB994 8448080C */  jal        func_00212210
    /* EB998 001EB998 00000000 */   nop
    /* EB99C 001EB99C 01000424 */  addiu      $4, $0, 0x1
    /* EB9A0 001EB9A0 0F000524 */  addiu      $5, $0, 0xF
    /* EB9A4 001EB9A4 02000624 */  addiu      $6, $0, 0x2
    /* EB9A8 001EB9A8 13000724 */  addiu      $7, $0, 0x13
    /* EB9AC 001EB9AC D86B110C */  jal        func_0045af60
    /* EB9B0 001EB9B0 00000000 */   nop
    /* EB9B4 001EB9B4 14000010 */  b          .L001EBA08
    /* EB9B8 001EB9B8 00000000 */   nop
  .L001EB9BC:
    /* EB9BC 001EB9BC 8C00033C */  lui        $3, %hi(D_008C024E)
    /* EB9C0 001EB9C0 4E026394 */  lhu        $3, %lo(D_008C024E)($3)
    /* EB9C4 001EB9C4 10006330 */  andi       $3, $3, 0x10
    /* EB9C8 001EB9C8 0F006010 */  beqz       $3, .L001EBA08
    /* EB9CC 001EB9CC 00000000 */   nop
    /* EB9D0 001EB9D0 0D00A014 */  bnez       $5, .L001EBA08
    /* EB9D4 001EB9D4 00000000 */   nop
    /* EB9D8 001EB9D8 00108234 */  ori        $2, $4, 0x1000
    /* EB9DC 001EB9DC 0000C2AC */  sw         $2, 0x0($6)
    /* EB9E0 001EB9E0 ACB3828F */  lw         $2, -0x4C54($28)
    /* EB9E4 001EB9E4 D40D448C */  lw         $4, 0xDD4($2)
    /* EB9E8 001EB9E8 6C48080C */  jal        func_002121b0
    /* EB9EC 001EB9EC 00000000 */   nop
    /* EB9F0 001EB9F0 01000424 */  addiu      $4, $0, 0x1
    /* EB9F4 001EB9F4 0F000524 */  addiu      $5, $0, 0xF
    /* EB9F8 001EB9F8 02000624 */  addiu      $6, $0, 0x2
    /* EB9FC 001EB9FC 12000724 */  addiu      $7, $0, 0x12
    /* EBA00 001EBA00 D86B110C */  jal        func_0045af60
    /* EBA04 001EBA04 00000000 */   nop
  .L001EBA08:
    /* EBA08 001EBA08 0000BFDF */  ld         $31, 0x0($29)
    /* EBA0C 001EBA0C 1000BD27 */  addiu      $29, $29, 0x10
    /* EBA10 001EBA10 0800E003 */  jr         $31
    /* EBA14 001EBA14 00000000 */   nop
    /* EBA18 001EBA18 00000000 */  nop
    /* EBA1C 001EBA1C 00000000 */  nop
.size func_001eb8d0, 0x150
