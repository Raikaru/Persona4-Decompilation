.section .text
.set noat
.set noreorder
glabel func_003ea2c0
    /* 2EA2C0 003EA2C0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2EA2C4 003EA2C4 0300033C */  lui        $3, (0x30018 >> 16)
    /* 2EA2C8 003EA2C8 4000BFFF */  sd         $31, 0x40($29)
    /* 2EA2CC 003EA2CC 8800023C */  lui        $2, %hi(D_008873F8)
    /* 2EA2D0 003EA2D0 3000B37F */  sq         $19, 0x30($29)
    /* 2EA2D4 003EA2D4 2000B27F */  sq         $18, 0x20($29)
    /* 2EA2D8 003EA2D8 1000B17F */  sq         $17, 0x10($29)
    /* 2EA2DC 003EA2DC 2D908000 */  daddu      $18, $4, $0
    /* 2EA2E0 003EA2E0 0000B07F */  sq         $16, 0x0($29)
    /* 2EA2E4 003EA2E4 2D88A000 */  daddu      $17, $5, $0
    /* 2EA2E8 003EA2E8 2D80C000 */  daddu      $16, $6, $0
    /* 2EA2EC 003EA2EC 8800043C */  lui        $4, %hi(D_008872E0)
    /* 2EA2F0 003EA2F0 C8B7868F */  lw         $6, -0x4838($28)
    /* 2EA2F4 003EA2F4 E0728424 */  addiu      $4, $4, %lo(D_008872E0)
    /* 2EA2F8 003EA2F8 18006534 */  ori        $5, $3, (0x30018 & 0xFFFF)
    /* 2EA2FC 003EA2FC F873428C */  lw         $2, %lo(D_008873F8)($2)
    /* 2EA300 003EA300 21188600 */  addu       $3, $4, $6
    /* 2EA304 003EA304 09F84000 */  jalr       $2
    /* 2EA308 003EA308 0000648C */   lw        $4, 0x0($3)
    /* 2EA30C 003EA30C 2D984000 */  daddu      $19, $2, $0
    /* 2EA310 003EA310 0D006012 */  beqz       $19, .L003EA348
    /* 2EA314 003EA314 00000000 */   nop
    /* 2EA318 003EA318 040072AE */  sw         $18, 0x4($19)
    /* 2EA31C 003EA31C 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EA320 003EA320 080071AE */  sw         $17, 0x8($19)
    /* 2EA324 003EA324 C0B78424 */  addiu      $4, $4, %lo(D_0070B7C0)
    /* 2EA328 003EA328 0C0070AE */  sw         $16, 0xC($19)
    /* 2EA32C 003EA32C 2D286002 */  daddu      $5, $19, $0
    /* 2EA330 003EA330 140060AE */  sw         $0, 0x14($19)
    /* 2EA334 003EA334 180060AE */  sw         $0, 0x18($19)
    /* 2EA338 003EA338 DC8E0F0C */  jal        func_003e3b70
    /* 2EA33C 003EA33C 000060AE */   sw        $0, 0x0($19)
    /* 2EA340 003EA340 02000010 */  b          .L003EA34C
    /* 2EA344 003EA344 2D106002 */   daddu     $2, $19, $0
  .L003EA348:
    /* 2EA348 003EA348 2D100000 */  daddu      $2, $0, $0
  .L003EA34C:
    /* 2EA34C 003EA34C 4000BFDF */  ld         $31, 0x40($29)
    /* 2EA350 003EA350 3000B37B */  lq         $19, 0x30($29)
    /* 2EA354 003EA354 2000B27B */  lq         $18, 0x20($29)
    /* 2EA358 003EA358 1000B17B */  lq         $17, 0x10($29)
    /* 2EA35C 003EA35C 0000B07B */  lq         $16, 0x0($29)
    /* 2EA360 003EA360 0800E003 */  jr         $31
    /* 2EA364 003EA364 5000BD27 */   addiu     $29, $29, 0x50
    /* 2EA368 003EA368 00000000 */  nop
    /* 2EA36C 003EA36C 00000000 */  nop
.size func_003ea2c0, 0xb0
