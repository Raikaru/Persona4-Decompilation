.section .text
.set noat
.set noreorder
glabel func_004bad70
    /* 3BAD70 004BAD70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BAD74 004BAD74 1000BFFF */  sd         $31, 0x10($29)
    /* 3BAD78 004BAD78 0000B07F */  sq         $16, 0x0($29)
    /* 3BAD7C 004BAD7C 2D808000 */  daddu      $16, $4, $0
    /* 3BAD80 004BAD80 0C00878C */  lw         $7, 0xC($4)
    /* 3BAD84 004BAD84 40180700 */  sll        $3, $7, 1
    /* 3BAD88 004BAD88 21186700 */  addu       $3, $3, $7
    /* 3BAD8C 004BAD8C 80380300 */  sll        $7, $3, 2
    /* 3BAD90 004BAD90 1000838C */  lw         $3, 0x10($4)
    /* 3BAD94 004BAD94 21186700 */  addu       $3, $3, $7
    /* 3BAD98 004BAD98 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 3BAD9C 004BAD9C 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 3BADA0 004BADA0 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 3BADA4 004BADA4 000062E4 */  swc1       $f2, 0x0($3)
    /* 3BADA8 004BADA8 040061E4 */  swc1       $f1, 0x4($3)
    /* 3BADAC 004BADAC 080060E4 */  swc1       $f0, 0x8($3)
    /* 3BADB0 004BADB0 1400838C */  lw         $3, 0x14($4)
    /* 3BADB4 004BADB4 21186700 */  addu       $3, $3, $7
    /* 3BADB8 004BADB8 0000C2C4 */  lwc1       $f2, 0x0($6)
    /* 3BADBC 004BADBC 0400C1C4 */  lwc1       $f1, 0x4($6)
    /* 3BADC0 004BADC0 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 3BADC4 004BADC4 000062E4 */  swc1       $f2, 0x0($3)
    /* 3BADC8 004BADC8 040061E4 */  swc1       $f1, 0x4($3)
    /* 3BADCC 004BADCC 080060E4 */  swc1       $f0, 0x8($3)
    /* 3BADD0 004BADD0 0800858C */  lw         $5, 0x8($4)
    /* 3BADD4 004BADD4 0000838C */  lw         $3, 0x0($4)
    /* 3BADD8 004BADD8 0800638C */  lw         $3, 0x8($3)
    /* 3BADDC 004BADDC 2A08A300 */  slt        $1, $5, $3
    /* 3BADE0 004BADE0 03002010 */  beqz       $1, .L004BADF0
    /* 3BADE4 004BADE4 00000000 */   nop
    /* 3BADE8 004BADE8 0100A324 */  addiu      $3, $5, 0x1
    /* 3BADEC 004BADEC 080003AE */  sw         $3, 0x8($16)
  .L004BADF0:
    /* 3BADF0 004BADF0 0C00038E */  lw         $3, 0xC($16)
    /* 3BADF4 004BADF4 01006424 */  addiu      $4, $3, 0x1
    /* 3BADF8 004BADF8 0C0004AE */  sw         $4, 0xC($16)
    /* 3BADFC 004BADFC 0000038E */  lw         $3, 0x0($16)
    /* 3BAE00 004BAE00 0800638C */  lw         $3, 0x8($3)
    /* 3BAE04 004BAE04 1A008300 */  div        $0, $4, $3
    /* 3BAE08 004BAE08 10180000 */  mfhi       $3
    /* 3BAE0C 004BAE0C 0C0003AE */  sw         $3, 0xC($16)
    /* 3BAE10 004BAE10 0800048E */  lw         $4, 0x8($16)
    /* 3BAE14 004BAE14 02000324 */  addiu      $3, $0, 0x2
    /* 3BAE18 004BAE18 0F008310 */  beq        $4, $3, .L004BAE58
    /* 3BAE1C 004BAE1C 00000000 */   nop
    /* 3BAE20 004BAE20 01000524 */  addiu      $5, $0, 0x1
    /* 3BAE24 004BAE24 19008510 */  beq        $4, $5, .L004BAE8C
    /* 3BAE28 004BAE28 00000000 */   nop
    /* 3BAE2C 004BAE2C 03008010 */  beqz       $4, .L004BAE3C
    /* 3BAE30 004BAE30 00000000 */   nop
    /* 3BAE34 004BAE34 0E000010 */  b          .L004BAE70
    /* 3BAE38 004BAE38 00000000 */   nop
  .L004BAE3C:
    /* 3BAE3C 004BAE3C 7100043C */  lui        $4, %hi(D_007146E0)
    /* 3BAE40 004BAE40 E0468424 */  addiu      $4, $4, %lo(D_007146E0)
    /* 3BAE44 004BAE44 BB050524 */  addiu      $5, $0, 0x5BB
    /* 3BAE48 004BAE48 CCB5110C */  jal        func_0046d730
    /* 3BAE4C 004BAE4C 00000000 */   nop
    /* 3BAE50 004BAE50 0E000010 */  b          .L004BAE8C
    /* 3BAE54 004BAE54 00000000 */   nop
  .L004BAE58:
    /* 3BAE58 004BAE58 2D200002 */  daddu      $4, $16, $0
    /* 3BAE5C 004BAE5C 2D280000 */  daddu      $5, $0, $0
    /* 3BAE60 004BAE60 74EC120C */  jal        func_004bb1d0
    /* 3BAE64 004BAE64 00000000 */   nop
    /* 3BAE68 004BAE68 08000010 */  b          .L004BAE8C
    /* 3BAE6C 004BAE6C 00000000 */   nop
  .L004BAE70:
    /* 3BAE70 004BAE70 2D200002 */  daddu      $4, $16, $0
    /* 3BAE74 004BAE74 74EC120C */  jal        func_004bb1d0
    /* 3BAE78 004BAE78 00000000 */   nop
    /* 3BAE7C 004BAE7C 2D200002 */  daddu      $4, $16, $0
    /* 3BAE80 004BAE80 2D280000 */  daddu      $5, $0, $0
    /* 3BAE84 004BAE84 74EC120C */  jal        func_004bb1d0
    /* 3BAE88 004BAE88 00000000 */   nop
  .L004BAE8C:
    /* 3BAE8C 004BAE8C 1000BFDF */  ld         $31, 0x10($29)
    /* 3BAE90 004BAE90 0000B07B */  lq         $16, 0x0($29)
    /* 3BAE94 004BAE94 2000BD27 */  addiu      $29, $29, 0x20
    /* 3BAE98 004BAE98 0800E003 */  jr         $31
    /* 3BAE9C 004BAE9C 00000000 */   nop
.size func_004bad70, 0x130
