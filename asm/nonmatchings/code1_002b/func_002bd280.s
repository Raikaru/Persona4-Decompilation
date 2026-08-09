.section .text
.set noat
.set noreorder
glabel func_002bd280
    /* 1BD280 002BD280 90FFBD27 */  addiu      $29, $29, -0x70
    /* 1BD284 002BD284 6000BFFF */  sd         $31, 0x60($29)
    /* 1BD288 002BD288 5000B57F */  sq         $21, 0x50($29)
    /* 1BD28C 002BD28C 4000B47F */  sq         $20, 0x40($29)
    /* 1BD290 002BD290 3000B37F */  sq         $19, 0x30($29)
    /* 1BD294 002BD294 2000B27F */  sq         $18, 0x20($29)
    /* 1BD298 002BD298 1000B17F */  sq         $17, 0x10($29)
    /* 1BD29C 002BD29C 0000B07F */  sq         $16, 0x0($29)
    /* 1BD2A0 002BD2A0 2D988000 */  daddu      $19, $4, $0
    /* 1BD2A4 002BD2A4 2D90A000 */  daddu      $18, $5, $0
    /* 1BD2A8 002BD2A8 2D88C000 */  daddu      $17, $6, $0
    /* 1BD2AC 002BD2AC 2D80E000 */  daddu      $16, $7, $0
    /* 1BD2B0 002BD2B0 7CB5958F */  lw         $21, -0x4A84($28)
    /* 1BD2B4 002BD2B4 0C00A28E */  lw         $2, 0xC($21)
    /* 1BD2B8 002BD2B8 06004014 */  bnez       $2, .L002BD2D4
    /* 1BD2BC 002BD2BC 00000000 */   nop
    /* 1BD2C0 002BD2C0 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BD2C4 002BD2C4 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BD2C8 002BD2C8 68060524 */  addiu      $5, $0, 0x668
    /* 1BD2CC 002BD2CC CCB5110C */  jal        func_0046d730
    /* 1BD2D0 002BD2D0 00000000 */   nop
  .L002BD2D4:
    /* 1BD2D4 002BD2D4 0C00B48E */  lw         $20, 0xC($21)
    /* 1BD2D8 002BD2D8 0000A48E */  lw         $4, 0x0($21)
    /* 1BD2DC 002BD2DC 10008294 */  lhu        $2, 0x10($4)
    /* 1BD2E0 002BD2E0 01004524 */  addiu      $5, $2, 0x1
    /* 1BD2E4 002BD2E4 30000624 */  addiu      $6, $0, 0x30
    /* 1BD2E8 002BD2E8 5C880B0C */  jal        func_002e2170
    /* 1BD2EC 002BD2EC 00000000 */   nop
    /* 1BD2F0 002BD2F0 1400438C */  lw         $3, 0x14($2)
    /* 1BD2F4 002BD2F4 000062AC */  sw         $2, 0x0($3)
    /* 1BD2F8 002BD2F8 2C0073AC */  sw         $19, 0x2C($3)
    /* 1BD2FC 002BD2FC 200072AC */  sw         $18, 0x20($3)
    /* 1BD300 002BD300 240071AC */  sw         $17, 0x24($3)
    /* 1BD304 002BD304 280074AC */  sw         $20, 0x28($3)
    /* 1BD308 002BD308 0E0070A4 */  sh         $16, 0xE($3)
    /* 1BD30C 002BD30C 2D100000 */  daddu      $2, $0, $0
    /* 1BD310 002BD310 6000BFDF */  ld         $31, 0x60($29)
    /* 1BD314 002BD314 5000B57B */  lq         $21, 0x50($29)
    /* 1BD318 002BD318 4000B47B */  lq         $20, 0x40($29)
    /* 1BD31C 002BD31C 3000B37B */  lq         $19, 0x30($29)
    /* 1BD320 002BD320 2000B27B */  lq         $18, 0x20($29)
    /* 1BD324 002BD324 1000B17B */  lq         $17, 0x10($29)
    /* 1BD328 002BD328 0000B07B */  lq         $16, 0x0($29)
    /* 1BD32C 002BD32C 7000BD27 */  addiu      $29, $29, 0x70
    /* 1BD330 002BD330 0800E003 */  jr         $31
    /* 1BD334 002BD334 00000000 */   nop
    /* 1BD338 002BD338 00000000 */  nop
    /* 1BD33C 002BD33C 00000000 */  nop
.size func_002bd280, 0xc0
