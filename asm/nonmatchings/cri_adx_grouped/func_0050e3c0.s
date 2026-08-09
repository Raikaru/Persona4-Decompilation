.section .text
.set noat
.set noreorder
glabel func_0050e3c0
    /* 40E3C0 0050E3C0 2D308000 */  daddu      $6, $4, $0
    /* 40E3C4 0050E3C4 2D200000 */  daddu      $4, $0, $0
    /* 40E3C8 0050E3C8 0100C224 */  addiu      $2, $6, 0x1
    /* 40E3CC 0050E3CC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E3D0 0050E3D0 0300422C */  sltiu      $2, $2, 0x3
    /* 40E3D4 0050E3D4 06004014 */  bnez       $2, .L0050E3F0
    /* 40E3D8 0050E3D8 0000BFFF */   sd        $31, 0x0($29)
    /* 40E3DC 0050E3DC 7600043C */  lui        $4, %hi(D_0075F678)
    /* 40E3E0 0050E3E0 0000BFDF */  ld         $31, 0x0($29)
    /* 40E3E4 0050E3E4 78F68424 */  addiu      $4, $4, %lo(D_0075F678)
    /* 40E3E8 0050E3E8 88441408 */  j          func_00511220
    /* 40E3EC 0050E3EC 1000BD27 */   addiu     $29, $29, 0x10
  .L0050E3F0:
    /* 40E3F0 0050E3F0 0000BFDF */  ld         $31, 0x0($29)
    /* 40E3F4 0050E3F4 3D000524 */  addiu      $5, $0, 0x3D
    /* 40E3F8 0050E3F8 64931408 */  j          func_00524d90
    /* 40E3FC 0050E3FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e3c0, 0x40
