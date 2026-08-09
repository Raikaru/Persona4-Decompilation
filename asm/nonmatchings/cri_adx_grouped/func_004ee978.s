.section .text
.set noat
.set noreorder
glabel func_004ee978
    /* 3EE978 004EE978 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EE97C 004EE97C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EE980 004EE980 2D88C000 */  daddu      $17, $6, $0
    /* 3EE984 004EE984 1000B2FF */  sd         $18, 0x10($29)
    /* 3EE988 004EE988 2D90E000 */  daddu      $18, $7, $0
    /* 3EE98C 004EE98C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE990 004EE990 07008014 */  bnez       $4, .L004EE9B0
    /* 3EE994 004EE994 1800BFFF */   sd        $31, 0x18($29)
    /* 3EE998 004EE998 7600043C */  lui        $4, %hi(D_0075CEA8)
    /* 3EE99C 004EE99C 7600053C */  lui        $5, %hi(D_0075CDA0)
    /* 3EE9A0 004EE9A0 A8CE8424 */  addiu      $4, $4, %lo(D_0075CEA8)
    /* 3EE9A4 004EE9A4 09000010 */  b          .L004EE9CC
    /* 3EE9A8 004EE9A8 A0CDA524 */   addiu     $5, $5, %lo(D_0075CDA0)
    /* 3EE9AC 004EE9AC 00000000 */  nop
  .L004EE9B0:
    /* 3EE9B0 004EE9B0 0400828C */  lw         $2, 0x4($4)
    /* 3EE9B4 004EE9B4 0A004014 */  bnez       $2, .L004EE9E0
    /* 3EE9B8 004EE9B8 00000000 */   nop
    /* 3EE9BC 004EE9BC 7600043C */  lui        $4, %hi(D_0075CEB8)
    /* 3EE9C0 004EE9C0 7600053C */  lui        $5, %hi(D_0075CDD0)
    /* 3EE9C4 004EE9C4 B8CE8424 */  addiu      $4, $4, %lo(D_0075CEB8)
    /* 3EE9C8 004EE9C8 D0CDA524 */  addiu      $5, $5, %lo(D_0075CDD0)
  .L004EE9CC:
    /* 3EE9CC 004EE9CC B4B7130C */  jal        func_004eded0
    /* 3EE9D0 004EE9D0 00000000 */   nop
    /* 3EE9D4 004EE9D4 20000010 */  b          .L004EEA58
    /* 3EE9D8 004EE9D8 2D100000 */   daddu     $2, $0, $0
    /* 3EE9DC 004EE9DC 00000000 */  nop
  .L004EE9E0:
    /* 3EE9E0 004EE9E0 0700A014 */  bnez       $5, .L004EEA00
    /* 3EE9E4 004EE9E4 01000224 */   addiu     $2, $0, 0x1
    /* 3EE9E8 004EE9E8 1400828C */  lw         $2, 0x14($4)
    /* 3EE9EC 004EE9EC 2000838C */  lw         $3, 0x20($4)
    /* 3EE9F0 004EE9F0 2400858C */  lw         $5, 0x24($4)
    /* 3EE9F4 004EE9F4 23186200 */  subu       $3, $3, $2
    /* 3EE9F8 004EE9F8 08000010 */  b          .L004EEA1C
    /* 3EE9FC 004EE9FC 1000848C */   lw        $4, 0x10($4)
  .L004EEA00:
    /* 3EEA00 004EEA00 0D00A254 */  bnel       $5, $2, .L004EEA38
    /* 3EEA04 004EEA04 3800828C */   lw        $2, 0x38($4)
    /* 3EEA08 004EEA08 1800828C */  lw         $2, 0x18($4)
    /* 3EEA0C 004EEA0C 2000838C */  lw         $3, 0x20($4)
    /* 3EEA10 004EEA10 2400858C */  lw         $5, 0x24($4)
    /* 3EEA14 004EEA14 23186200 */  subu       $3, $3, $2
    /* 3EEA18 004EEA18 0C00848C */  lw         $4, 0xC($4)
  .L004EEA1C:
    /* 3EEA1C 004EEA1C 21806500 */  addu       $16, $3, $5
    /* 3EEA20 004EEA20 2A109000 */  slt        $2, $4, $16
    /* 3EEA24 004EEA24 0B808200 */  movn       $16, $4, $2
    /* 3EEA28 004EEA28 2A181102 */  slt        $3, $16, $17
    /* 3EEA2C 004EEA2C 07000010 */  b          .L004EEA4C
    /* 3EEA30 004EEA30 0A802302 */   movz      $16, $17, $3
    /* 3EEA34 004EEA34 00000000 */  nop
  .L004EEA38:
    /* 3EEA38 004EEA38 04004010 */  beqz       $2, .L004EEA4C
    /* 3EEA3C 004EEA3C 2D800000 */   daddu     $16, $0, $0
    /* 3EEA40 004EEA40 3C00848C */  lw         $4, 0x3C($4)
    /* 3EEA44 004EEA44 09F84000 */  jalr       $2
    /* 3EEA48 004EEA48 FDFF0524 */   addiu     $5, $0, -0x3
  .L004EEA4C:
    /* 3EEA4C 004EEA4C 26101102 */  xor        $2, $16, $17
    /* 3EEA50 004EEA50 000050AE */  sw         $16, 0x0($18)
    /* 3EEA54 004EEA54 0100422C */  sltiu      $2, $2, 0x1
  .L004EEA58:
    /* 3EEA58 004EEA58 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEA5C 004EEA5C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EEA60 004EEA60 1000B2DF */  ld         $18, 0x10($29)
    /* 3EEA64 004EEA64 1800BFDF */  ld         $31, 0x18($29)
    /* 3EEA68 004EEA68 0800E003 */  jr         $31
    /* 3EEA6C 004EEA6C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ee978, 0xf8
