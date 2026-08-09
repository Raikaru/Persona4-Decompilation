.section .text
.set noat
.set noreorder
glabel func_004de9f8
    /* 3DE9F8 004DE9F8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DE9FC 004DE9FC 7600023C */  lui        $2, %hi(D_00758688)
    /* 3DEA00 004DEA00 0000B0FF */  sd         $16, 0x0($29)
    /* 3DEA04 004DEA04 2D808000 */  daddu      $16, $4, $0
    /* 3DEA08 004DEA08 0800B1FF */  sd         $17, 0x8($29)
    /* 3DEA0C 004DEA0C 2D88E000 */  daddu      $17, $7, $0
    /* 3DEA10 004DEA10 1000B2FF */  sd         $18, 0x10($29)
    /* 3DEA14 004DEA14 2D90A000 */  daddu      $18, $5, $0
    /* 3DEA18 004DEA18 1800B3FF */  sd         $19, 0x18($29)
    /* 3DEA1C 004DEA1C 2D980001 */  daddu      $19, $8, $0
    /* 3DEA20 004DEA20 2000B4FF */  sd         $20, 0x20($29)
    /* 3DEA24 004DEA24 2DA0C000 */  daddu      $20, $6, $0
    /* 3DEA28 004DEA28 2800BFFF */  sd         $31, 0x28($29)
    /* 3DEA2C 004DEA2C 88864224 */  addiu      $2, $2, %lo(D_00758688)
    /* 3DEA30 004DEA30 0000438C */  lw         $3, 0x0($2)
    /* 3DEA34 004DEA34 04000052 */  beql       $16, $0, .L004DEA48
    /* 3DEA38 004DEA38 7600043C */   lui       $4, %hi(D_00759678)
    /* 3DEA3C 004DEA3C 0C004016 */  bnez       $18, .L004DEA70
    /* 3DEA40 004DEA40 00000000 */   nop
    /* 3DEA44 004DEA44 7600043C */  lui        $4, %hi(D_00759678)
  .L004DEA48:
    /* 3DEA48 004DEA48 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEA4C 004DEA4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3DEA50 004DEA50 78968424 */  addiu      $4, $4, %lo(D_00759678)
    /* 3DEA54 004DEA54 1000B2DF */  ld         $18, 0x10($29)
    /* 3DEA58 004DEA58 1800B3DF */  ld         $19, 0x18($29)
    /* 3DEA5C 004DEA5C 2000B4DF */  ld         $20, 0x20($29)
    /* 3DEA60 004DEA60 2800BFDF */  ld         $31, 0x28($29)
    /* 3DEA64 004DEA64 B0781308 */  j          func_004de2c0
    /* 3DEA68 004DEA68 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DEA6C 004DEA6C 00000000 */  nop
  .L004DEA70:
    /* 3DEA70 004DEA70 0B002106 */  bgez       $17, .L004DEAA0
    /* 3DEA74 004DEA74 2800BFDF */   ld        $31, 0x28($29)
    /* 3DEA78 004DEA78 7600043C */  lui        $4, %hi(D_007596A8)
    /* 3DEA7C 004DEA7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEA80 004DEA80 0800B1DF */  ld         $17, 0x8($29)
    /* 3DEA84 004DEA84 A8968424 */  addiu      $4, $4, %lo(D_007596A8)
    /* 3DEA88 004DEA88 1000B2DF */  ld         $18, 0x10($29)
    /* 3DEA8C 004DEA8C 1800B3DF */  ld         $19, 0x18($29)
    /* 3DEA90 004DEA90 2000B4DF */  ld         $20, 0x20($29)
    /* 3DEA94 004DEA94 B0781308 */  j          func_004de2c0
    /* 3DEA98 004DEA98 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DEA9C 004DEA9C 00000000 */  nop
  .L004DEAA0:
    /* 3DEAA0 004DEAA0 0B00601E */  bgtz       $19, .L004DEAD0
    /* 3DEAA4 004DEAA4 00000000 */   nop
    /* 3DEAA8 004DEAA8 7600043C */  lui        $4, %hi(D_007596D8)
    /* 3DEAAC 004DEAAC 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEAB0 004DEAB0 0800B1DF */  ld         $17, 0x8($29)
    /* 3DEAB4 004DEAB4 D8968424 */  addiu      $4, $4, %lo(D_007596D8)
    /* 3DEAB8 004DEAB8 1000B2DF */  ld         $18, 0x10($29)
    /* 3DEABC 004DEABC 1800B3DF */  ld         $19, 0x18($29)
    /* 3DEAC0 004DEAC0 2000B4DF */  ld         $20, 0x20($29)
    /* 3DEAC4 004DEAC4 B0781308 */  j          func_004de2c0
    /* 3DEAC8 004DEAC8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DEACC 004DEACC 00000000 */  nop
  .L004DEAD0:
    /* 3DEAD0 004DEAD0 587B130C */  jal        func_004ded60
    /* 3DEAD4 004DEAD4 00000000 */   nop
    /* 3DEAD8 004DEAD8 E080130C */  jal        func_004e0380
    /* 3DEADC 004DEADC 00000000 */   nop
    /* 3DEAE0 004DEAE0 8C00028E */  lw         $2, 0x8C($16)
    /* 3DEAE4 004DEAE4 CC0112AE */  sw         $18, 0x1CC($16)
    /* 3DEAE8 004DEAE8 D40111AE */  sw         $17, 0x1D4($16)
    /* 3DEAEC 004DEAEC 2D284000 */  daddu      $5, $2, $0
    /* 3DEAF0 004DEAF0 D00114AE */  sw         $20, 0x1D0($16)
    /* 3DEAF4 004DEAF4 D80113AE */  sw         $19, 0x1D8($16)
    /* 3DEAF8 004DEAF8 900002AE */  sw         $2, 0x90($16)
    /* 3DEAFC 004DEAFC 7681130C */  jal        func_004e05d8
    /* 3DEB00 004DEB00 0400048E */   lw        $4, 0x4($16)
    /* 3DEB04 004DEB04 DC0100AE */  sw         $0, 0x1DC($16)
    /* 3DEB08 004DEB08 01000224 */  addiu      $2, $0, 0x1
    /* 3DEB0C 004DEB0C 0800B1DF */  ld         $17, 0x8($29)
    /* 3DEB10 004DEB10 010002A2 */  sb         $2, 0x1($16)
    /* 3DEB14 004DEB14 B20102A2 */  sb         $2, 0x1B2($16)
    /* 3DEB18 004DEB18 1000B2DF */  ld         $18, 0x10($29)
    /* 3DEB1C 004DEB1C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEB20 004DEB20 1800B3DF */  ld         $19, 0x18($29)
    /* 3DEB24 004DEB24 2000B4DF */  ld         $20, 0x20($29)
    /* 3DEB28 004DEB28 2800BFDF */  ld         $31, 0x28($29)
    /* 3DEB2C 004DEB2C E6801308 */  j          func_004e0398
    /* 3DEB30 004DEB30 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DEB34 004DEB34 00000000 */  nop
.size func_004de9f8, 0x140
