.section .text
.set noat
.set noreorder
glabel func_004ecc08
    /* 3ECC08 004ECC08 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3ECC0C 004ECC0C 01000324 */  addiu      $3, $0, 0x1
    /* 3ECC10 004ECC10 1800B1FF */  sd         $17, 0x18($29)
    /* 3ECC14 004ECC14 2D888000 */  daddu      $17, $4, $0
    /* 3ECC18 004ECC18 1000B0FF */  sd         $16, 0x10($29)
    /* 3ECC1C 004ECC1C 2000B2FF */  sd         $18, 0x20($29)
    /* 3ECC20 004ECC20 2800B3FF */  sd         $19, 0x28($29)
    /* 3ECC24 004ECC24 3000B4FF */  sd         $20, 0x30($29)
    /* 3ECC28 004ECC28 3800BFFF */  sd         $31, 0x38($29)
    /* 3ECC2C 004ECC2C 58002282 */  lb         $2, 0x58($17)
    /* 3ECC30 004ECC30 5D004314 */  bne        $2, $3, .L004ECDA8
    /* 3ECC34 004ECC34 1000B0DF */   ld        $16, 0x10($29)
    /* 3ECC38 004ECC38 52002282 */  lb         $2, 0x52($17)
    /* 3ECC3C 004ECC3C 2D900000 */  daddu      $18, $0, $0
    /* 3ECC40 004ECC40 52002392 */  lbu        $3, 0x52($17)
    /* 3ECC44 004ECC44 18004018 */  blez       $2, .L004ECCA8
    /* 3ECC48 004ECC48 2D980000 */   daddu     $19, $0, $0
    /* 3ECC4C 004ECC4C 01001424 */  addiu      $20, $0, 0x1
    /* 3ECC50 004ECC50 08003026 */  addiu      $16, $17, 0x8
    /* 3ECC54 004ECC54 00000000 */  nop
  .L004ECC58:
    /* 3ECC58 004ECC58 7293130C */  jal        func_004e4dc8
    /* 3ECC5C 004ECC5C 0800048E */   lw        $4, 0x8($16)
    /* 3ECC60 004ECC60 0B005410 */  beq        $2, $20, .L004ECC90
    /* 3ECC64 004ECC64 2D280000 */   daddu     $5, $0, $0
    /* 3ECC68 004ECC68 0000028E */  lw         $2, 0x0($16)
    /* 3ECC6C 004ECC6C 0800448C */  lw         $4, 0x8($2)
    /* 3ECC70 004ECC70 0000838C */  lw         $3, 0x0($4)
    /* 3ECC74 004ECC74 2400628C */  lw         $2, 0x24($3)
    /* 3ECC78 004ECC78 09F84000 */  jalr       $2
    /* 3ECC7C 004ECC7C 00000000 */   nop
    /* 3ECC80 004ECC80 2C00238E */  lw         $3, 0x2C($17)
    /* 3ECC84 004ECC84 01004426 */  addiu      $4, $18, 0x1
    /* 3ECC88 004ECC88 26104300 */  xor        $2, $2, $3
    /* 3ECC8C 004ECC8C 0A908200 */  movz       $18, $4, $2
  .L004ECC90:
    /* 3ECC90 004ECC90 52002282 */  lb         $2, 0x52($17)
    /* 3ECC94 004ECC94 01007326 */  addiu      $19, $19, 0x1
    /* 3ECC98 004ECC98 04001026 */  addiu      $16, $16, 0x4
    /* 3ECC9C 004ECC9C 2A106202 */  slt        $2, $19, $2
    /* 3ECCA0 004ECCA0 EDFF4014 */  bnez       $2, .L004ECC58
    /* 3ECCA4 004ECCA4 52002392 */   lbu       $3, 0x52($17)
  .L004ECCA8:
    /* 3ECCA8 004ECCA8 00160300 */  sll        $2, $3, 24
    /* 3ECCAC 004ECCAC 03160200 */  sra        $2, $2, 24
    /* 3ECCB0 004ECCB0 3D004216 */  bne        $18, $2, .L004ECDA8
    /* 3ECCB4 004ECCB4 1000B0DF */   ld        $16, 0x10($29)
    /* 3ECCB8 004ECCB8 3B00401A */  blez       $18, .L004ECDA8
    /* 3ECCBC 004ECCBC 2D980000 */   daddu     $19, $0, $0
    /* 3ECCC0 004ECCC0 10003226 */  addiu      $18, $17, 0x10
    /* 3ECCC4 004ECCC4 08003026 */  addiu      $16, $17, 0x8
    /* 3ECCC8 004ECCC8 0000028E */  lw         $2, 0x0($16)
    /* 3ECCCC 004ECCCC 00000000 */  nop
  .L004ECCD0:
    /* 3ECCD0 004ECCD0 FF7F063C */  lui        $6, (0x7FFFFFFF >> 16)
    /* 3ECCD4 004ECCD4 2D38A003 */  daddu      $7, $29, $0
    /* 3ECCD8 004ECCD8 2D280000 */  daddu      $5, $0, $0
    /* 3ECCDC 004ECCDC 0800448C */  lw         $4, 0x8($2)
    /* 3ECCE0 004ECCE0 0000838C */  lw         $3, 0x0($4)
    /* 3ECCE4 004ECCE4 1800628C */  lw         $2, 0x18($3)
    /* 3ECCE8 004ECCE8 09F84000 */  jalr       $2
    /* 3ECCEC 004ECCEC FFFFC634 */   ori       $6, $6, (0x7FFFFFFF & 0xFFFF)
    /* 3ECCF0 004ECCF0 0000078E */  lw         $7, 0x0($16)
    /* 3ECCF4 004ECCF4 2D30A003 */  daddu      $6, $29, $0
    /* 3ECCF8 004ECCF8 0800E48C */  lw         $4, 0x8($7)
    /* 3ECCFC 004ECCFC 0000838C */  lw         $3, 0x0($4)
    /* 3ECD00 004ECD00 2000628C */  lw         $2, 0x20($3)
    /* 3ECD04 004ECD04 09F84000 */  jalr       $2
    /* 3ECD08 004ECD08 2D280000 */   daddu     $5, $0, $0
    /* 3ECD0C 004ECD0C 0000038E */  lw         $3, 0x0($16)
    /* 3ECD10 004ECD10 FF7F063C */  lui        $6, (0x7FFFFFFF >> 16)
    /* 3ECD14 004ECD14 2D280000 */  daddu      $5, $0, $0
    /* 3ECD18 004ECD18 0800648C */  lw         $4, 0x8($3)
    /* 3ECD1C 004ECD1C FFFFC634 */  ori        $6, $6, (0x7FFFFFFF & 0xFFFF)
    /* 3ECD20 004ECD20 0000838C */  lw         $3, 0x0($4)
    /* 3ECD24 004ECD24 1800628C */  lw         $2, 0x18($3)
    /* 3ECD28 004ECD28 09F84000 */  jalr       $2
    /* 3ECD2C 004ECD2C 2D38A003 */   daddu     $7, $29, $0
    /* 3ECD30 004ECD30 2D280000 */  daddu      $5, $0, $0
    /* 3ECD34 004ECD34 0400A38F */  lw         $3, 0x4($29)
    /* 3ECD38 004ECD38 2C00228E */  lw         $2, 0x2C($17)
    /* 3ECD3C 004ECD3C 0A006210 */  beq        $3, $2, .L004ECD68
    /* 3ECD40 004ECD40 2D30A003 */   daddu     $6, $29, $0
    /* 3ECD44 004ECD44 00000000 */  nop
  .L004ECD48:
    /* 3ECD48 004ECD48 00000000 */  nop
    /* 3ECD4C 004ECD4C 00000000 */  nop
    /* 3ECD50 004ECD50 00000000 */  nop
    /* 3ECD54 004ECD54 00000000 */  nop
    /* 3ECD58 004ECD58 00000000 */  nop
    /* 3ECD5C 004ECD5C FAFF0010 */  b          .L004ECD48
    /* 3ECD60 004ECD60 00000000 */   nop
    /* 3ECD64 004ECD64 00000000 */  nop
  .L004ECD68:
    /* 3ECD68 004ECD68 0000028E */  lw         $2, 0x0($16)
    /* 3ECD6C 004ECD6C 04001026 */  addiu      $16, $16, 0x4
    /* 3ECD70 004ECD70 0800448C */  lw         $4, 0x8($2)
    /* 3ECD74 004ECD74 0000838C */  lw         $3, 0x0($4)
    /* 3ECD78 004ECD78 2000628C */  lw         $2, 0x20($3)
    /* 3ECD7C 004ECD7C 09F84000 */  jalr       $2
    /* 3ECD80 004ECD80 01007326 */   addiu     $19, $19, 0x1
    /* 3ECD84 004ECD84 5B0020A2 */  sb         $0, 0x5B($17)
    /* 3ECD88 004ECD88 0000448E */  lw         $4, 0x0($18)
    /* 3ECD8C 004ECD8C 0A94130C */  jal        func_004e5028
    /* 3ECD90 004ECD90 04005226 */   addiu     $18, $18, 0x4
    /* 3ECD94 004ECD94 52002282 */  lb         $2, 0x52($17)
    /* 3ECD98 004ECD98 2A106202 */  slt        $2, $19, $2
    /* 3ECD9C 004ECD9C CCFF4054 */  bnel       $2, $0, .L004ECCD0
    /* 3ECDA0 004ECDA0 0000028E */   lw        $2, 0x0($16)
    /* 3ECDA4 004ECDA4 1000B0DF */  ld         $16, 0x10($29)
  .L004ECDA8:
    /* 3ECDA8 004ECDA8 1800B1DF */  ld         $17, 0x18($29)
    /* 3ECDAC 004ECDAC 2000B2DF */  ld         $18, 0x20($29)
    /* 3ECDB0 004ECDB0 2800B3DF */  ld         $19, 0x28($29)
    /* 3ECDB4 004ECDB4 3000B4DF */  ld         $20, 0x30($29)
    /* 3ECDB8 004ECDB8 3800BFDF */  ld         $31, 0x38($29)
    /* 3ECDBC 004ECDBC 0800E003 */  jr         $31
    /* 3ECDC0 004ECDC0 4000BD27 */   addiu     $29, $29, 0x40
    /* 3ECDC4 004ECDC4 00000000 */  nop
.size func_004ecc08, 0x1c0
