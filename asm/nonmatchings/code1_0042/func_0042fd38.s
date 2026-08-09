.section .text
.set noat
.set noreorder
glabel func_0042fd38
    /* 32FD38 0042FD38 2D388000 */  daddu      $7, $4, $0
    /* 32FD3C 0042FD3C 70000324 */  addiu      $3, $0, 0x70
    /* 32FD40 0042FD40 1C000424 */  addiu      $4, $0, 0x1C
    /* 32FD44 0042FD44 1818E370 */  mult1      $3, $7, $3
    /* 32FD48 0042FD48 1820A400 */  mult       $4, $5, $4
    /* 32FD4C 0042FD4C 8900023C */  lui        $2, %hi(D_00894F90)
    /* 32FD50 0042FD50 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 32FD54 0042FD54 904F4224 */  addiu      $2, $2, %lo(D_00894F90)
    /* 32FD58 0042FD58 2000B1FF */  sd         $17, 0x20($29)
    /* 32FD5C 0042FD5C 10004224 */  addiu      $2, $2, 0x10
    /* 32FD60 0042FD60 3000BFFF */  sd         $31, 0x30($29)
    /* 32FD64 0042FD64 21208300 */  addu       $4, $4, $3
    /* 32FD68 0042FD68 1000B0FF */  sd         $16, 0x10($29)
    /* 32FD6C 0042FD6C 21888200 */  addu       $17, $4, $2
    /* 32FD70 0042FD70 0000238E */  lw         $3, 0x0($17)
    /* 32FD74 0042FD74 19006010 */  beqz       $3, .L0042FDDC
    /* 32FD78 0042FD78 2D100000 */   daddu     $2, $0, $0
    /* 32FD7C 0042FD7C 8900023C */  lui        $2, %hi(D_00895180)
    /* 32FD80 0042FD80 0E000324 */  addiu      $3, $0, 0xE
    /* 32FD84 0042FD84 80515024 */  addiu      $16, $2, %lo(D_00895180)
    /* 32FD88 0042FD88 805143AC */  sw         $3, %lo(D_00895180)($2)
    /* 32FD8C 0042FD8C 01000624 */  addiu      $6, $0, 0x1
    /* 32FD90 0042FD90 040007AE */  sw         $7, 0x4($16)
    /* 32FD94 0042FD94 080005AE */  sw         $5, 0x8($16)
    /* 32FD98 0042FD98 8900043C */  lui        $4, %hi(D_00894F40)
    /* 32FD9C 0042FD9C 100006AE */  sw         $6, 0x10($16)
    /* 32FDA0 0042FDA0 404F8424 */  addiu      $4, $4, %lo(D_00894F40)
    /* 32FDA4 0042FDA4 01000524 */  addiu      $5, $0, 0x1
    /* 32FDA8 0042FDA8 2D300000 */  daddu      $6, $0, $0
    /* 32FDAC 0042FDAC 0000A0AF */  sw         $0, 0x0($29)
    /* 32FDB0 0042FDB0 2D380002 */  daddu      $7, $16, $0
    /* 32FDB4 0042FDB4 80000824 */  addiu      $8, $0, 0x80
    /* 32FDB8 0042FDB8 2D480002 */  daddu      $9, $16, $0
    /* 32FDBC 0042FDBC 80000A24 */  addiu      $10, $0, 0x80
    /* 32FDC0 0042FDC0 2C96100C */  jal        func_004258b0
    /* 32FDC4 0042FDC4 2D580000 */   daddu     $11, $0, $0
    /* 32FDC8 0042FDC8 03004304 */  bgezl      $2, .L0042FDD8
    /* 32FDCC 0042FDCC 000020AE */   sw        $0, 0x0($17)
    /* 32FDD0 0042FDD0 02000010 */  b          .L0042FDDC
    /* 32FDD4 0042FDD4 2D100000 */   daddu     $2, $0, $0
  .L0042FDD8:
    /* 32FDD8 0042FDD8 0C00028E */  lw         $2, 0xC($16)
  .L0042FDDC:
    /* 32FDDC 0042FDDC 3000BFDF */  ld         $31, 0x30($29)
    /* 32FDE0 0042FDE0 2000B1DF */  ld         $17, 0x20($29)
    /* 32FDE4 0042FDE4 1000B0DF */  ld         $16, 0x10($29)
    /* 32FDE8 0042FDE8 0800E003 */  jr         $31
    /* 32FDEC 0042FDEC 4000BD27 */   addiu     $29, $29, 0x40
.size func_0042fd38, 0xb8
