.section .text
.set noat
.set noreorder
glabel func_002b9f90
    /* 1B9F90 002B9F90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1B9F94 002B9F94 4000BFFF */  sd         $31, 0x40($29)
    /* 1B9F98 002B9F98 3000B37F */  sq         $19, 0x30($29)
    /* 1B9F9C 002B9F9C 2000B27F */  sq         $18, 0x20($29)
    /* 1B9FA0 002B9FA0 1000B17F */  sq         $17, 0x10($29)
    /* 1B9FA4 002B9FA4 0000B07F */  sq         $16, 0x0($29)
    /* 1B9FA8 002B9FA8 2D988000 */  daddu      $19, $4, $0
    /* 1B9FAC 002B9FAC 2D90A000 */  daddu      $18, $5, $0
    /* 1B9FB0 002B9FB0 2D88C000 */  daddu      $17, $6, $0
    /* 1B9FB4 002B9FB4 6400043C */  lui        $4, %hi(D_0063F178)
    /* 1B9FB8 002B9FB8 78F18424 */  addiu      $4, $4, %lo(D_0063F178)
    /* 1B9FBC 002B9FBC 93060524 */  addiu      $5, $0, 0x693
    /* 1B9FC0 002B9FC0 A43A110C */  jal        func_0044ea90
    /* 1B9FC4 002B9FC4 00000000 */   nop
    /* 1B9FC8 002B9FC8 01000424 */  addiu      $4, $0, 0x1
    /* 1B9FCC 002B9FCC 10660524 */  addiu      $5, $0, 0x6610
    /* 1B9FD0 002B9FD0 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1B9FD4 002B9FD4 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1B9FD8 002B9FD8 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1B9FDC 002B9FDC 09F84000 */  jalr       $2
    /* 1B9FE0 002B9FE0 00000000 */   nop
    /* 1B9FE4 002B9FE4 2D804000 */  daddu      $16, $2, $0
    /* 1B9FE8 002B9FE8 2D206002 */  daddu      $4, $19, $0
    /* 1B9FEC 002B9FEC 6400053C */  lui        $5, %hi(D_0063F1E0)
    /* 1B9FF0 002B9FF0 E0F1A524 */  addiu      $5, $5, %lo(D_0063F1E0)
    /* 1B9FF4 002B9FF4 0F000624 */  addiu      $6, $0, 0xF
    /* 1B9FF8 002B9FF8 2D380000 */  daddu      $7, $0, $0
    /* 1B9FFC 002B9FFC 2D400000 */  daddu      $8, $0, $0
    /* 1BA000 002BA000 2C00093C */  lui        $9, %hi(func_002b9e10)
    /* 1BA004 002BA004 109E2925 */  addiu      $9, $9, %lo(func_002b9e10)
    /* 1BA008 002BA008 2C000A3C */  lui        $10, %hi(func_002b9f60)
    /* 1BA00C 002BA00C 609F4A25 */  addiu      $10, $10, %lo(func_002b9f60)
    /* 1BA010 002BA010 2D580002 */  daddu      $11, $16, $0
    /* 1BA014 002BA014 F047110C */  jal        func_00451fc0
    /* 1BA018 002BA018 00000000 */   nop
    /* 1BA01C 002BA01C 2D200000 */  daddu      $4, $0, $0
    /* 1BA020 002BA020 08000010 */  b          .L002BA044
    /* 1BA024 002BA024 00000000 */   nop
  .L002BA028:
    /* 1BA028 002BA028 00190400 */  sll        $3, $4, 4
    /* 1BA02C 002BA02C 21186400 */  addu       $3, $3, $4
    /* 1BA030 002BA030 40190300 */  sll        $3, $3, 5
    /* 1BA034 002BA034 21180302 */  addu       $3, $16, $3
    /* 1BA038 002BA038 040160A4 */  sh         $0, 0x104($3)
    /* 1BA03C 002BA03C 140271AC */  sw         $17, 0x214($3)
    /* 1BA040 002BA040 01008424 */  addiu      $4, $4, 0x1
  .L002BA044:
    /* 1BA044 002BA044 30008328 */  slti       $3, $4, 0x30
    /* 1BA048 002BA048 F7FF6014 */  bnez       $3, .L002BA028
    /* 1BA04C 002BA04C 00000000 */   nop
    /* 1BA050 002BA050 006612A6 */  sh         $18, 0x6600($16)
    /* 1BA054 002BA054 4000BFDF */  ld         $31, 0x40($29)
    /* 1BA058 002BA058 3000B37B */  lq         $19, 0x30($29)
    /* 1BA05C 002BA05C 2000B27B */  lq         $18, 0x20($29)
    /* 1BA060 002BA060 1000B17B */  lq         $17, 0x10($29)
    /* 1BA064 002BA064 0000B07B */  lq         $16, 0x0($29)
    /* 1BA068 002BA068 5000BD27 */  addiu      $29, $29, 0x50
    /* 1BA06C 002BA06C 0800E003 */  jr         $31
    /* 1BA070 002BA070 00000000 */   nop
    /* 1BA074 002BA074 00000000 */  nop
    /* 1BA078 002BA078 00000000 */  nop
    /* 1BA07C 002BA07C 00000000 */  nop
.size func_002b9f90, 0xf0
