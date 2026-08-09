.section .text
.set noat
.set noreorder
glabel func_004d9cd8
    /* 3D9CD8 004D9CD8 7300023C */  lui        $2, %hi(D_007286F0)
    /* 3D9CDC 004D9CDC E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D9CE0 004D9CE0 F086438C */  lw         $3, %lo(D_007286F0)($2)
    /* 3D9CE4 004D9CE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D9CE8 004D9CE8 2D808000 */  daddu      $16, $4, $0
    /* 3D9CEC 004D9CEC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D9CF0 004D9CF0 2D88A000 */  daddu      $17, $5, $0
    /* 3D9CF4 004D9CF4 1000B2FF */  sd         $18, 0x10($29)
    /* 3D9CF8 004D9CF8 2D90C000 */  daddu      $18, $6, $0
    /* 3D9CFC 004D9CFC 03006014 */  bnez       $3, .L004D9D0C
    /* 3D9D00 004D9D00 1800BFFF */   sd        $31, 0x18($29)
    /* 3D9D04 004D9D04 B866130C */  jal        func_004d9ae0
    /* 3D9D08 004D9D08 00000000 */   nop
  .L004D9D0C:
    /* 3D9D0C 004D9D0C 7600043C */  lui        $4, %hi(D_00759558)
    /* 3D9D10 004D9D10 2D300002 */  daddu      $6, $16, $0
    /* 3D9D14 004D9D14 2D382002 */  daddu      $7, $17, $0
    /* 3D9D18 004D9D18 2D404002 */  daddu      $8, $18, $0
    /* 3D9D1C 004D9D1C 58958424 */  addiu      $4, $4, %lo(D_00759558)
    /* 3D9D20 004D9D20 C866130C */  jal        func_004d9b20
    /* 3D9D24 004D9D24 06000524 */   addiu     $5, $0, 0x6
    /* 3D9D28 004D9D28 2D100000 */  daddu      $2, $0, $0
    /* 3D9D2C 004D9D2C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D9D30 004D9D30 0800B1DF */  ld         $17, 0x8($29)
    /* 3D9D34 004D9D34 1000B2DF */  ld         $18, 0x10($29)
    /* 3D9D38 004D9D38 1800BFDF */  ld         $31, 0x18($29)
    /* 3D9D3C 004D9D3C 0800E003 */  jr         $31
    /* 3D9D40 004D9D40 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D9D44 004D9D44 00000000 */  nop
.size func_004d9cd8, 0x70
