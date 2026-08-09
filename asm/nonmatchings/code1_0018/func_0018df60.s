.section .text
.set noat
.set noreorder
glabel func_0018df60
    /* 8DF60 0018DF60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 8DF64 0018DF64 2000BFFF */  sd         $31, 0x20($29)
    /* 8DF68 0018DF68 1000B17F */  sq         $17, 0x10($29)
    /* 8DF6C 0018DF6C 0000B07F */  sq         $16, 0x0($29)
    /* 8DF70 0018DF70 2D888000 */  daddu      $17, $4, $0
    /* 8DF74 0018DF74 5869050C */  jal        func_0015a560
    /* 8DF78 0018DF78 00000000 */   nop
    /* 8DF7C 0018DF7C 04004014 */  bnez       $2, .L0018DF90
    /* 8DF80 0018DF80 00000000 */   nop
    /* 8DF84 0018DF84 2D100000 */  daddu      $2, $0, $0
    /* 8DF88 0018DF88 22000010 */  b          .L0018E014
    /* 8DF8C 0018DF8C 00000000 */   nop
  .L0018DF90:
    /* 8DF90 0018DF90 5F00043C */  lui        $4, %hi(D_005F54D8)
    /* 8DF94 0018DF94 D8548424 */  addiu      $4, $4, %lo(D_005F54D8)
    /* 8DF98 0018DF98 91000524 */  addiu      $5, $0, 0x91
    /* 8DF9C 0018DF9C A43A110C */  jal        func_0044ea90
    /* 8DFA0 0018DFA0 00000000 */   nop
    /* 8DFA4 0018DFA4 01000424 */  addiu      $4, $0, 0x1
    /* 8DFA8 0018DFA8 14000524 */  addiu      $5, $0, 0x14
    /* 8DFAC 0018DFAC 0400063C */  lui        $6, (0x40000 >> 16)
    /* 8DFB0 0018DFB0 8800023C */  lui        $2, %hi(D_008873F4)
    /* 8DFB4 0018DFB4 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 8DFB8 0018DFB8 09F84000 */  jalr       $2
    /* 8DFBC 0018DFBC 00000000 */   nop
    /* 8DFC0 0018DFC0 2D804000 */  daddu      $16, $2, $0
    /* 8DFC4 0018DFC4 04000016 */  bnez       $16, .L0018DFD8
    /* 8DFC8 0018DFC8 00000000 */   nop
    /* 8DFCC 0018DFCC 2D100000 */  daddu      $2, $0, $0
    /* 8DFD0 0018DFD0 10000010 */  b          .L0018E014
    /* 8DFD4 0018DFD4 00000000 */   nop
  .L0018DFD8:
    /* 8DFD8 0018DFD8 2D202002 */  daddu      $4, $17, $0
    /* 8DFDC 0018DFDC 5F00053C */  lui        $5, %hi(D_005F54E8)
    /* 8DFE0 0018DFE0 E854A524 */  addiu      $5, $5, %lo(D_005F54E8)
    /* 8DFE4 0018DFE4 0F000624 */  addiu      $6, $0, 0xF
    /* 8DFE8 0018DFE8 2D380000 */  daddu      $7, $0, $0
    /* 8DFEC 0018DFEC 2D400000 */  daddu      $8, $0, $0
    /* 8DFF0 0018DFF0 1900093C */  lui        $9, %hi(func_0018dde0)
    /* 8DFF4 0018DFF4 E0DD2925 */  addiu      $9, $9, %lo(func_0018dde0)
    /* 8DFF8 0018DFF8 19000A3C */  lui        $10, %hi(func_0018df30)
    /* 8DFFC 0018DFFC 30DF4A25 */  addiu      $10, $10, %lo(func_0018df30)
    /* 8E000 0018E000 2D580002 */  daddu      $11, $16, $0
    /* 8E004 0018E004 F047110C */  jal        func_00451fc0
    /* 8E008 0018E008 00000000 */   nop
    /* 8E00C 0018E00C 1E000324 */  addiu      $3, $0, 0x1E
    /* 8E010 0018E010 080003AE */  sw         $3, 0x8($16)
  .L0018E014:
    /* 8E014 0018E014 2000BFDF */  ld         $31, 0x20($29)
    /* 8E018 0018E018 1000B17B */  lq         $17, 0x10($29)
    /* 8E01C 0018E01C 0000B07B */  lq         $16, 0x0($29)
    /* 8E020 0018E020 3000BD27 */  addiu      $29, $29, 0x30
    /* 8E024 0018E024 0800E003 */  jr         $31
    /* 8E028 0018E028 00000000 */   nop
    /* 8E02C 0018E02C 00000000 */  nop
.size func_0018df60, 0xd0
