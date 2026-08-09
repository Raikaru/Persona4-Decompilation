.section .text
.set noat
.set noreorder
glabel func_004cf2b8
    /* 3CF2B8 004CF2B8 7200023C */  lui        $2, %hi(D_00721D68)
    /* 3CF2BC 004CF2BC E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CF2C0 004CF2C0 681D438C */  lw         $3, %lo(D_00721D68)($2)
    /* 3CF2C4 004CF2C4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CF2C8 004CF2C8 2D808000 */  daddu      $16, $4, $0
    /* 3CF2CC 004CF2CC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CF2D0 004CF2D0 2D88A000 */  daddu      $17, $5, $0
    /* 3CF2D4 004CF2D4 1000B2FF */  sd         $18, 0x10($29)
    /* 3CF2D8 004CF2D8 2D90C000 */  daddu      $18, $6, $0
    /* 3CF2DC 004CF2DC 03006014 */  bnez       $3, .L004CF2EC
    /* 3CF2E0 004CF2E0 1800BFFF */   sd        $31, 0x18($29)
    /* 3CF2E4 004CF2E4 303C130C */  jal        func_004cf0c0
    /* 3CF2E8 004CF2E8 00000000 */   nop
  .L004CF2EC:
    /* 3CF2EC 004CF2EC 7600043C */  lui        $4, %hi(D_00758A68)
    /* 3CF2F0 004CF2F0 2D300002 */  daddu      $6, $16, $0
    /* 3CF2F4 004CF2F4 2D382002 */  daddu      $7, $17, $0
    /* 3CF2F8 004CF2F8 2D404002 */  daddu      $8, $18, $0
    /* 3CF2FC 004CF2FC 688A8424 */  addiu      $4, $4, %lo(D_00758A68)
    /* 3CF300 004CF300 403C130C */  jal        func_004cf100
    /* 3CF304 004CF304 06000524 */   addiu     $5, $0, 0x6
    /* 3CF308 004CF308 2D100000 */  daddu      $2, $0, $0
    /* 3CF30C 004CF30C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CF310 004CF310 0800B1DF */  ld         $17, 0x8($29)
    /* 3CF314 004CF314 1000B2DF */  ld         $18, 0x10($29)
    /* 3CF318 004CF318 1800BFDF */  ld         $31, 0x18($29)
    /* 3CF31C 004CF31C 0800E003 */  jr         $31
    /* 3CF320 004CF320 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CF324 004CF324 00000000 */  nop
.size func_004cf2b8, 0x70
