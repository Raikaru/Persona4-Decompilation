.section .text
.set noat
.set noreorder
glabel func_004cd1d0
    /* 3CD1D0 004CD1D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CD1D4 004CD1D4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CD1D8 004CD1D8 2D808000 */  daddu      $16, $4, $0
    /* 3CD1DC 004CD1DC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CD1E0 004CD1E0 01001124 */  addiu      $17, $0, 0x1
    /* 3CD1E4 004CD1E4 1000B2FF */  sd         $18, 0x10($29)
    /* 3CD1E8 004CD1E8 1800BFFF */  sd         $31, 0x18($29)
    /* 3CD1EC 004CD1EC A834130C */  jal        func_004cd2a0
    /* 3CD1F0 004CD1F0 2D90A000 */   daddu     $18, $5, $0
    /* 3CD1F4 004CD1F4 B02C130C */  jal        func_004cb2c0
    /* 3CD1F8 004CD1F8 2D204000 */   daddu     $4, $2, $0
    /* 3CD1FC 004CD1FC 7200023C */  lui        $2, %hi(D_007212CC)
    /* 3CD200 004CD200 0B001112 */  beq        $16, $17, .L004CD230
    /* 3CD204 004CD204 CC1250AC */   sw        $16, %lo(D_007212CC)($2)
    /* 3CD208 004CD208 04000012 */  beqz       $16, .L004CD21C
    /* 3CD20C 004CD20C 00000000 */   nop
    /* 3CD210 004CD210 02000224 */  addiu      $2, $0, 0x2
    /* 3CD214 004CD214 06000256 */  bnel       $16, $2, .L004CD230
    /* 3CD218 004CD218 2D880000 */   daddu     $17, $0, $0
  .L004CD21C:
    /* 3CD21C 004CD21C 8630130C */  jal        func_004cc218
    /* 3CD220 004CD220 2D204002 */   daddu     $4, $18, $0
    /* 3CD224 004CD224 03000010 */  b          .L004CD234
    /* 3CD228 004CD228 2D102002 */   daddu     $2, $17, $0
    /* 3CD22C 004CD22C 00000000 */  nop
  .L004CD230:
    /* 3CD230 004CD230 2D102002 */  daddu      $2, $17, $0
  .L004CD234:
    /* 3CD234 004CD234 0000B0DF */  ld         $16, 0x0($29)
    /* 3CD238 004CD238 0800B1DF */  ld         $17, 0x8($29)
    /* 3CD23C 004CD23C 1000B2DF */  ld         $18, 0x10($29)
    /* 3CD240 004CD240 1800BFDF */  ld         $31, 0x18($29)
    /* 3CD244 004CD244 0800E003 */  jr         $31
    /* 3CD248 004CD248 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CD24C 004CD24C 00000000 */  nop
.size func_004cd1d0, 0x80
