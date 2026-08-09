.section .text
.set noat
.set noreorder
glabel func_004ecba8
    /* 3ECBA8 004ECBA8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECBAC 004ECBAC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ECBB0 004ECBB0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECBB4 004ECBB4 01000524 */  addiu      $5, $0, 0x1
    /* 3ECBB8 004ECBB8 0000BFFF */  sd         $31, 0x0($29)
    /* 3ECBBC 004ECBBC 05006514 */  bne        $3, $5, .L004ECBD4
    /* 3ECBC0 004ECBC0 2D308000 */   daddu     $6, $4, $0
    /* 3ECBC4 004ECBC4 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ECBC8 004ECBC8 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ECBCC 004ECBCC 0A006018 */  blez       $3, .L004ECBF8
    /* 3ECBD0 004ECBD0 2D100000 */   daddu     $2, $0, $0
  .L004ECBD4:
    /* 3ECBD4 004ECBD4 0800C28C */  lw         $2, 0x8($6)
    /* 3ECBD8 004ECBD8 0800448C */  lw         $4, 0x8($2)
    /* 3ECBDC 004ECBDC 0000838C */  lw         $3, 0x0($4)
    /* 3ECBE0 004ECBE0 2400628C */  lw         $2, 0x24($3)
    /* 3ECBE4 004ECBE4 09F84000 */  jalr       $2
    /* 3ECBE8 004ECBE8 2D280000 */   daddu     $5, $0, $0
    /* 3ECBEC 004ECBEC C21F0200 */  srl        $3, $2, 31
    /* 3ECBF0 004ECBF0 21186200 */  addu       $3, $3, $2
    /* 3ECBF4 004ECBF4 43100300 */  sra        $2, $3, 1
  .L004ECBF8:
    /* 3ECBF8 004ECBF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3ECBFC 004ECBFC 0800E003 */  jr         $31
    /* 3ECC00 004ECC00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ECC04 004ECC04 00000000 */  nop
.size func_004ecba8, 0x60
