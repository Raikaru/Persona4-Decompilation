.section .text
.set noat
.set noreorder
glabel func_003cc2c0
    /* 2CC2C0 003CC2C0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2CC2C4 003CC2C4 1000BFFF */  sd         $31, 0x10($29)
    /* 2CC2C8 003CC2C8 7445100C */  jal        func_004115d0
    /* 2CC2CC 003CC2CC 0000B07F */   sq        $16, 0x0($29)
    /* 2CC2D0 003CC2D0 2D804000 */  daddu      $16, $2, $0
    /* 2CC2D4 003CC2D4 17000012 */  beqz       $16, .L003CC334
    /* 2CC2D8 003CC2D8 00000000 */   nop
    /* 2CC2DC 003CC2DC 01000224 */  addiu      $2, $0, 0x1
    /* 2CC2E0 003CC2E0 2D200002 */  daddu      $4, $16, $0
    /* 2CC2E4 003CC2E4 284B100C */  jal        func_00412ca0
    /* 2CC2E8 003CC2E8 2C0002AE */   sw        $2, 0x2C($16)
    /* 2CC2EC 003CC2EC 0F004010 */  beqz       $2, .L003CC32C
    /* 2CC2F0 003CC2F0 00000000 */   nop
    /* 2CC2F4 003CC2F4 7100063C */  lui        $6, %hi(D_0070B0A0)
    /* 2CC2F8 003CC2F8 2D204000 */  daddu      $4, $2, $0
    /* 2CC2FC 003CC2FC 2D280000 */  daddu      $5, $0, $0
    /* 2CC300 003CC300 A0B0C624 */  addiu      $6, $6, %lo(D_0070B0A0)
    /* 2CC304 003CC304 EC4B100C */  jal        func_00412fb0
    /* 2CC308 003CC308 2D380000 */   daddu     $7, $0, $0
    /* 2CC30C 003CC30C 07004010 */  beqz       $2, .L003CC32C
    /* 2CC310 003CC310 00000000 */   nop
    /* 2CC314 003CC314 7849100C */  jal        func_004125e0
    /* 2CC318 003CC318 2D204000 */   daddu     $4, $2, $0
    /* 2CC31C 003CC31C 03004010 */  beqz       $2, .L003CC32C
    /* 2CC320 003CC320 00000000 */   nop
    /* 2CC324 003CC324 0E000010 */  b          .L003CC360
    /* 2CC328 003CC328 2D100002 */   daddu     $2, $16, $0
  .L003CC32C:
    /* 2CC32C 003CC32C 9C45100C */  jal        func_00411670
    /* 2CC330 003CC330 2D200002 */   daddu     $4, $16, $0
  .L003CC334:
    /* 2CC334 003CC334 02000324 */  addiu      $3, $0, 0x2
    /* 2CC338 003CC338 0080023C */  lui        $2, (0x80000006 >> 16)
    /* 2CC33C 003CC33C 7100053C */  lui        $5, %hi(D_0070B0E0)
    /* 2CC340 003CC340 2800A3AF */  sw         $3, 0x28($29)
    /* 2CC344 003CC344 06004434 */  ori        $4, $2, (0x80000006 & 0xFFFF)
    /* 2CC348 003CC348 647D0F0C */  jal        func_003df590
    /* 2CC34C 003CC34C E0B0A524 */   addiu     $5, $5, %lo(D_0070B0E0)
    /* 2CC350 003CC350 2C00A2AF */  sw         $2, 0x2C($29)
    /* 2CC354 003CC354 347D0F0C */  jal        func_003df4d0
    /* 2CC358 003CC358 2800A427 */   addiu     $4, $29, 0x28
    /* 2CC35C 003CC35C 2D100000 */  daddu      $2, $0, $0
  .L003CC360:
    /* 2CC360 003CC360 1000BFDF */  ld         $31, 0x10($29)
    /* 2CC364 003CC364 0000B07B */  lq         $16, 0x0($29)
    /* 2CC368 003CC368 0800E003 */  jr         $31
    /* 2CC36C 003CC36C 3000BD27 */   addiu     $29, $29, 0x30
.size func_003cc2c0, 0xb0
