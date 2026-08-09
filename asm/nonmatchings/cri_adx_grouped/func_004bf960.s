.section .text
.set noat
.set noreorder
glabel func_004bf960
    /* 3BF960 004BF960 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BF964 004BF964 0800B1FF */  sd         $17, 0x8($29)
    /* 3BF968 004BF968 2D888000 */  daddu      $17, $4, $0
    /* 3BF96C 004BF96C 0000B0FF */  sd         $16, 0x0($29)
    /* 3BF970 004BF970 1000B2FF */  sd         $18, 0x10($29)
    /* 3BF974 004BF974 1800B3FF */  sd         $19, 0x18($29)
    /* 3BF978 004BF978 2000BFFF */  sd         $31, 0x20($29)
    /* 3BF97C 004BF97C 5000228E */  lw         $2, 0x50($17)
    /* 3BF980 004BF980 09004014 */  bnez       $2, .L004BF9A8
    /* 3BF984 004BF984 7500043C */   lui       $4, %hi(D_00757288)
    /* 3BF988 004BF988 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF98C 004BF98C 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF990 004BF990 88728424 */  addiu      $4, $4, %lo(D_00757288)
    /* 3BF994 004BF994 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF998 004BF998 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF99C 004BF99C 2000BFDF */  ld         $31, 0x20($29)
    /* 3BF9A0 004BF9A0 A8F51208 */  j          func_004bd6a0
    /* 3BF9A4 004BF9A4 3000BD27 */   addiu     $29, $29, 0x30
  .L004BF9A8:
    /* 3BF9A8 004BF9A8 96F5120C */  jal        func_004bd658
    /* 3BF9AC 004BF9AC 01001024 */   addiu     $16, $0, 0x1
    /* 3BF9B0 004BF9B0 6000228E */  lw         $2, 0x60($17)
    /* 3BF9B4 004BF9B4 08005054 */  bnel       $2, $16, .L004BF9D8
    /* 3BF9B8 004BF9B8 A4002282 */   lb        $2, 0xA4($17)
    /* 3BF9BC 004BF9BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF9C0 004BF9C0 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF9C4 004BF9C4 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF9C8 004BF9C8 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF9CC 004BF9CC 2000BFDF */  ld         $31, 0x20($29)
    /* 3BF9D0 004BF9D0 9CF51208 */  j          func_004bd670
    /* 3BF9D4 004BF9D4 3000BD27 */   addiu     $29, $29, 0x30
  .L004BF9D8:
    /* 3BF9D8 004BF9D8 3B005054 */  bnel       $2, $16, .L004BFAC8
    /* 3BF9DC 004BF9DC C800228E */   lw        $2, 0xC8($17)
    /* 3BF9E0 004BF9E0 6400228E */  lw         $2, 0x64($17)
    /* 3BF9E4 004BF9E4 21005054 */  bnel       $2, $16, .L004BFA6C
    /* 3BF9E8 004BF9E8 A000238E */   lw        $3, 0xA0($17)
    /* 3BF9EC 004BF9EC 1000238E */  lw         $3, 0x10($17)
    /* 3BF9F0 004BF9F0 40100300 */  sll        $2, $3, 1
    /* 3BF9F4 004BF9F4 21104300 */  addu       $2, $2, $3
    /* 3BF9F8 004BF9F8 80100200 */  sll        $2, $2, 2
    /* 3BF9FC 004BF9FC 21105100 */  addu       $2, $2, $17
    /* 3BFA00 004BFA00 D2F5120C */  jal        func_004bd748
    /* 3BFA04 004BFA04 2000448C */   lw        $4, 0x20($2)
    /* 3BFA08 004BFA08 18005050 */  beql       $2, $16, .L004BFA6C
    /* 3BFA0C 004BFA0C A000238E */   lw        $3, 0xA0($17)
    /* 3BFA10 004BFA10 0800248E */  lw         $4, 0x8($17)
    /* 3BFA14 004BFA14 0000838C */  lw         $3, 0x0($4)
    /* 3BFA18 004BFA18 2400628C */  lw         $2, 0x24($3)
    /* 3BFA1C 004BFA1C 09F84000 */  jalr       $2
    /* 3BFA20 004BFA20 00000000 */   nop
    /* 3BFA24 004BFA24 02000324 */  addiu      $3, $0, 0x2
    /* 3BFA28 004BFA28 09004354 */  bnel       $2, $3, .L004BFA50
    /* 3BFA2C 004BFA2C 0000B0DF */   ld        $16, 0x0($29)
    /* 3BFA30 004BFA30 0800248E */  lw         $4, 0x8($17)
    /* 3BFA34 004BFA34 0000838C */  lw         $3, 0x0($4)
    /* 3BFA38 004BFA38 1C00628C */  lw         $2, 0x1C($3)
    /* 3BFA3C 004BFA3C 09F84000 */  jalr       $2
    /* 3BFA40 004BFA40 2D280000 */   daddu     $5, $0, $0
    /* 3BFA44 004BFA44 08000010 */  b          .L004BFA68
    /* 3BFA48 004BFA48 640020AE */   sw        $0, 0x64($17)
    /* 3BFA4C 004BFA4C 00000000 */  nop
  .L004BFA50:
    /* 3BFA50 004BFA50 0800B1DF */  ld         $17, 0x8($29)
    /* 3BFA54 004BFA54 1000B2DF */  ld         $18, 0x10($29)
    /* 3BFA58 004BFA58 1800B3DF */  ld         $19, 0x18($29)
    /* 3BFA5C 004BFA5C 2000BFDF */  ld         $31, 0x20($29)
    /* 3BFA60 004BFA60 9CF51208 */  j          func_004bd670
    /* 3BFA64 004BFA64 3000BD27 */   addiu     $29, $29, 0x30
  .L004BFA68:
    /* 3BFA68 004BFA68 A000238E */  lw         $3, 0xA0($17)
  .L004BFA6C:
    /* 3BFA6C 004BFA6C 12006018 */  blez       $3, .L004BFAB8
    /* 3BFA70 004BFA70 2D980000 */   daddu     $19, $0, $0
    /* 3BFA74 004BFA74 18003226 */  addiu      $18, $17, 0x18
    /* 3BFA78 004BFA78 20003026 */  addiu      $16, $17, 0x20
    /* 3BFA7C 004BFA7C 00000000 */  nop
  .L004BFA80:
    /* 3BFA80 004BFA80 FCFF0282 */  lb         $2, -0x4($16)
    /* 3BFA84 004BFA84 08004050 */  beql       $2, $0, .L004BFAA8
    /* 3BFA88 004BFA88 01007326 */   addiu     $19, $19, 0x1
    /* 3BFA8C 004BFA8C 24F6120C */  jal        func_004bd890
    /* 3BFA90 004BFA90 0000048E */   lw        $4, 0x0($16)
    /* 3BFA94 004BFA94 2D202002 */  daddu      $4, $17, $0
    /* 3BFA98 004BFA98 4601130C */  jal        func_004c0518
    /* 3BFA9C 004BFA9C 2D284002 */   daddu     $5, $18, $0
    /* 3BFAA0 004BFAA0 A000238E */  lw         $3, 0xA0($17)
    /* 3BFAA4 004BFAA4 01007326 */  addiu      $19, $19, 0x1
  .L004BFAA8:
    /* 3BFAA8 004BFAA8 0C005226 */  addiu      $18, $18, 0xC
    /* 3BFAAC 004BFAAC 2A106302 */  slt        $2, $19, $3
    /* 3BFAB0 004BFAB0 F3FF4014 */  bnez       $2, .L004BFA80
    /* 3BFAB4 004BFAB4 0C001026 */   addiu     $16, $16, 0xC
  .L004BFAB8:
    /* 3BFAB8 004BFAB8 1401130C */  jal        func_004c0450
    /* 3BFABC 004BFABC 2D202002 */   daddu     $4, $17, $0
    /* 3BFAC0 004BFAC0 12000010 */  b          .L004BFB0C
    /* 3BFAC4 004BFAC4 0000B0DF */   ld        $16, 0x0($29)
  .L004BFAC8:
    /* 3BFAC8 004BFAC8 10005014 */  bne        $2, $16, .L004BFB0C
    /* 3BFACC 004BFACC 0000B0DF */   ld        $16, 0x0($29)
    /* 3BFAD0 004BFAD0 A000228E */  lw         $2, 0xA0($17)
    /* 3BFAD4 004BFAD4 0D004018 */  blez       $2, .L004BFB0C
    /* 3BFAD8 004BFAD8 2D980000 */   daddu     $19, $0, $0
    /* 3BFADC 004BFADC 18003026 */  addiu      $16, $17, 0x18
    /* 3BFAE0 004BFAE0 2D280002 */  daddu      $5, $16, $0
    /* 3BFAE4 004BFAE4 00000000 */  nop
  .L004BFAE8:
    /* 3BFAE8 004BFAE8 0C001026 */  addiu      $16, $16, 0xC
    /* 3BFAEC 004BFAEC 2D202002 */  daddu      $4, $17, $0
    /* 3BFAF0 004BFAF0 4601130C */  jal        func_004c0518
    /* 3BFAF4 004BFAF4 01007326 */   addiu     $19, $19, 0x1
    /* 3BFAF8 004BFAF8 A000228E */  lw         $2, 0xA0($17)
    /* 3BFAFC 004BFAFC 2A106202 */  slt        $2, $19, $2
    /* 3BFB00 004BFB00 F9FF4014 */  bnez       $2, .L004BFAE8
    /* 3BFB04 004BFB04 2D280002 */   daddu     $5, $16, $0
    /* 3BFB08 004BFB08 0000B0DF */  ld         $16, 0x0($29)
  .L004BFB0C:
    /* 3BFB0C 004BFB0C 0800B1DF */  ld         $17, 0x8($29)
    /* 3BFB10 004BFB10 1000B2DF */  ld         $18, 0x10($29)
    /* 3BFB14 004BFB14 1800B3DF */  ld         $19, 0x18($29)
    /* 3BFB18 004BFB18 2000BFDF */  ld         $31, 0x20($29)
    /* 3BFB1C 004BFB1C 9CF51208 */  j          func_004bd670
    /* 3BFB20 004BFB20 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BFB24 004BFB24 00000000 */  nop
.size func_004bf960, 0x1c8
