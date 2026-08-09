.section .text
.set noat
.set noreorder
glabel func_004eddd0
    /* 3EDDD0 004EDDD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EDDD4 004EDDD4 0800B1FF */  sd         $17, 0x8($29)
    /* 3EDDD8 004EDDD8 2D88C000 */  daddu      $17, $6, $0
    /* 3EDDDC 004EDDDC 1000B2FF */  sd         $18, 0x10($29)
    /* 3EDDE0 004EDDE0 2D90E000 */  daddu      $18, $7, $0
    /* 3EDDE4 004EDDE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3EDDE8 004EDDE8 07008014 */  bnez       $4, .L004EDE08
    /* 3EDDEC 004EDDEC 1800BFFF */   sd        $31, 0x18($29)
    /* 3EDDF0 004EDDF0 7600043C */  lui        $4, %hi(D_0075CD50)
    /* 3EDDF4 004EDDF4 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3EDDF8 004EDDF8 50CD8424 */  addiu      $4, $4, %lo(D_0075CD50)
    /* 3EDDFC 004EDDFC 09000010 */  b          .L004EDE24
    /* 3EDE00 004EDE00 40CCA524 */   addiu     $5, $5, %lo(D_0075CC40)
    /* 3EDE04 004EDE04 00000000 */  nop
  .L004EDE08:
    /* 3EDE08 004EDE08 0400828C */  lw         $2, 0x4($4)
    /* 3EDE0C 004EDE0C 0A004014 */  bnez       $2, .L004EDE38
    /* 3EDE10 004EDE10 00000000 */   nop
    /* 3EDE14 004EDE14 7600043C */  lui        $4, %hi(D_0075CD60)
    /* 3EDE18 004EDE18 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3EDE1C 004EDE1C 60CD8424 */  addiu      $4, $4, %lo(D_0075CD60)
    /* 3EDE20 004EDE20 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
  .L004EDE24:
    /* 3EDE24 004EDE24 2EB5130C */  jal        func_004ed4b8
    /* 3EDE28 004EDE28 00000000 */   nop
    /* 3EDE2C 004EDE2C 16000010 */  b          .L004EDE88
    /* 3EDE30 004EDE30 2D100000 */   daddu     $2, $0, $0
    /* 3EDE34 004EDE34 00000000 */  nop
  .L004EDE38:
    /* 3EDE38 004EDE38 1000A010 */  beqz       $5, .L004EDE7C
    /* 3EDE3C 004EDE3C 2D800000 */   daddu     $16, $0, $0
    /* 3EDE40 004EDE40 01000224 */  addiu      $2, $0, 0x1
    /* 3EDE44 004EDE44 0800A254 */  bnel       $5, $2, .L004EDE68
    /* 3EDE48 004EDE48 1C00828C */   lw        $2, 0x1C($4)
    /* 3EDE4C 004EDE4C 0C00848C */  lw         $4, 0xC($4)
    /* 3EDE50 004EDE50 2A109100 */  slt        $2, $4, $17
    /* 3EDE54 004EDE54 09004010 */  beqz       $2, .L004EDE7C
    /* 3EDE58 004EDE58 2D802002 */   daddu     $16, $17, $0
    /* 3EDE5C 004EDE5C 07000010 */  b          .L004EDE7C
    /* 3EDE60 004EDE60 2D808000 */   daddu     $16, $4, $0
    /* 3EDE64 004EDE64 00000000 */  nop
  .L004EDE68:
    /* 3EDE68 004EDE68 04004010 */  beqz       $2, .L004EDE7C
    /* 3EDE6C 004EDE6C 2D800000 */   daddu     $16, $0, $0
    /* 3EDE70 004EDE70 2000848C */  lw         $4, 0x20($4)
    /* 3EDE74 004EDE74 09F84000 */  jalr       $2
    /* 3EDE78 004EDE78 FDFF0524 */   addiu     $5, $0, -0x3
  .L004EDE7C:
    /* 3EDE7C 004EDE7C 26101102 */  xor        $2, $16, $17
    /* 3EDE80 004EDE80 000050AE */  sw         $16, 0x0($18)
    /* 3EDE84 004EDE84 0100422C */  sltiu      $2, $2, 0x1
  .L004EDE88:
    /* 3EDE88 004EDE88 0000B0DF */  ld         $16, 0x0($29)
    /* 3EDE8C 004EDE8C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EDE90 004EDE90 1000B2DF */  ld         $18, 0x10($29)
    /* 3EDE94 004EDE94 1800BFDF */  ld         $31, 0x18($29)
    /* 3EDE98 004EDE98 0800E003 */  jr         $31
    /* 3EDE9C 004EDE9C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004eddd0, 0xd0
