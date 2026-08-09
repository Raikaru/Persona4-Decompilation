.section .text
.set noat
.set noreorder
glabel func_004ecb40
    /* 3ECB40 004ECB40 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECB44 004ECB44 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ECB48 004ECB48 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECB4C 004ECB4C 01000524 */  addiu      $5, $0, 0x1
    /* 3ECB50 004ECB50 0000BFFF */  sd         $31, 0x0($29)
    /* 3ECB54 004ECB54 05006514 */  bne        $3, $5, .L004ECB6C
    /* 3ECB58 004ECB58 2D308000 */   daddu     $6, $4, $0
    /* 3ECB5C 004ECB5C 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ECB60 004ECB60 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ECB64 004ECB64 0C006018 */  blez       $3, .L004ECB98
    /* 3ECB68 004ECB68 2D100000 */   daddu     $2, $0, $0
  .L004ECB6C:
    /* 3ECB6C 004ECB6C 0800C28C */  lw         $2, 0x8($6)
    /* 3ECB70 004ECB70 0800448C */  lw         $4, 0x8($2)
    /* 3ECB74 004ECB74 0000838C */  lw         $3, 0x0($4)
    /* 3ECB78 004ECB78 2400628C */  lw         $2, 0x24($3)
    /* 3ECB7C 004ECB7C 09F84000 */  jalr       $2
    /* 3ECB80 004ECB80 2D280000 */   daddu     $5, $0, $0
    /* 3ECB84 004ECB84 00400324 */  addiu      $3, $0, 0x4000
    /* 3ECB88 004ECB88 23186200 */  subu       $3, $3, $2
    /* 3ECB8C 004ECB8C C2170300 */  srl        $2, $3, 31
    /* 3ECB90 004ECB90 21186200 */  addu       $3, $3, $2
    /* 3ECB94 004ECB94 43100300 */  sra        $2, $3, 1
  .L004ECB98:
    /* 3ECB98 004ECB98 0000BFDF */  ld         $31, 0x0($29)
    /* 3ECB9C 004ECB9C 0800E003 */  jr         $31
    /* 3ECBA0 004ECBA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ECBA4 004ECBA4 00000000 */  nop
.size func_004ecb40, 0x68
