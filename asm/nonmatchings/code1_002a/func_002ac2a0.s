.section .text
.set noat
.set noreorder
glabel func_002ac2a0
    /* 1AC2A0 002AC2A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1AC2A4 002AC2A4 1000BFFF */  sd         $31, 0x10($29)
    /* 1AC2A8 002AC2A8 0000B07F */  sq         $16, 0x0($29)
    /* 1AC2AC 002AC2AC 6400043C */  lui        $4, %hi(D_0063EEC0)
    /* 1AC2B0 002AC2B0 C0EE8424 */  addiu      $4, $4, %lo(D_0063EEC0)
    /* 1AC2B4 002AC2B4 B9040524 */  addiu      $5, $0, 0x4B9
    /* 1AC2B8 002AC2B8 A43A110C */  jal        func_0044ea90
    /* 1AC2BC 002AC2BC 00000000 */   nop
    /* 1AC2C0 002AC2C0 01000424 */  addiu      $4, $0, 0x1
    /* 1AC2C4 002AC2C4 784D0524 */  addiu      $5, $0, 0x4D78
    /* 1AC2C8 002AC2C8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1AC2CC 002AC2CC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1AC2D0 002AC2D0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1AC2D4 002AC2D4 09F84000 */  jalr       $2
    /* 1AC2D8 002AC2D8 00000000 */   nop
    /* 1AC2DC 002AC2DC 2D804000 */  daddu      $16, $2, $0
    /* 1AC2E0 002AC2E0 6400043C */  lui        $4, %hi(D_0063EED0)
    /* 1AC2E4 002AC2E4 D0EE8424 */  addiu      $4, $4, %lo(D_0063EED0)
    /* 1AC2E8 002AC2E8 0F000524 */  addiu      $5, $0, 0xF
    /* 1AC2EC 002AC2EC 2D300000 */  daddu      $6, $0, $0
    /* 1AC2F0 002AC2F0 2D380000 */  daddu      $7, $0, $0
    /* 1AC2F4 002AC2F4 2B00083C */  lui        $8, %hi(func_002abf70)
    /* 1AC2F8 002AC2F8 70BF0825 */  addiu      $8, $8, %lo(func_002abf70)
    /* 1AC2FC 002AC2FC 2B00093C */  lui        $9, %hi(func_002ac270)
    /* 1AC300 002AC300 70C22925 */  addiu      $9, $9, %lo(func_002ac270)
    /* 1AC304 002AC304 2D500002 */  daddu      $10, $16, $0
    /* 1AC308 002AC308 7847110C */  jal        func_00451de0
    /* 1AC30C 002AC30C 00000000 */   nop
    /* 1AC310 002AC310 000000A2 */  sb         $0, 0x0($16)
    /* 1AC314 002AC314 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 1AC318 002AC318 B40603AE */  sw         $3, 0x6B4($16)
    /* 1AC31C 002AC31C 1F000324 */  addiu      $3, $0, 0x1F
    /* 1AC320 002AC320 B80603A6 */  sh         $3, 0x6B8($16)
    /* 1AC324 002AC324 BA0600A6 */  sh         $0, 0x6BA($16)
    /* 1AC328 002AC328 01000324 */  addiu      $3, $0, 0x1
    /* 1AC32C 002AC32C BC0603A2 */  sb         $3, 0x6BC($16)
    /* 1AC330 002AC330 BD0603A2 */  sb         $3, 0x6BD($16)
    /* 1AC334 002AC334 C00600AE */  sw         $0, 0x6C0($16)
    /* 1AC338 002AC338 1000BFDF */  ld         $31, 0x10($29)
    /* 1AC33C 002AC33C 0000B07B */  lq         $16, 0x0($29)
    /* 1AC340 002AC340 2000BD27 */  addiu      $29, $29, 0x20
    /* 1AC344 002AC344 0800E003 */  jr         $31
    /* 1AC348 002AC348 00000000 */   nop
    /* 1AC34C 002AC34C 00000000 */  nop
.size func_002ac2a0, 0xb0
