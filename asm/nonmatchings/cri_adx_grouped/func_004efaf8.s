.section .text
.set noat
.set noreorder
glabel func_004efaf8
    /* 3EFAF8 004EFAF8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3EFAFC 004EFAFC 1800B3FF */  sd         $19, 0x18($29)
    /* 3EFB00 004EFB00 2D98E000 */  daddu      $19, $7, $0
    /* 3EFB04 004EFB04 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFB08 004EFB08 1000B2FF */  sd         $18, 0x10($29)
    /* 3EFB0C 004EFB0C 2D90C000 */  daddu      $18, $6, $0
    /* 3EFB10 004EFB10 2000B4FF */  sd         $20, 0x20($29)
    /* 3EFB14 004EFB14 2800B5FF */  sd         $21, 0x28($29)
    /* 3EFB18 004EFB18 2DA8A000 */  daddu      $21, $5, $0
    /* 3EFB1C 004EFB1C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EFB20 004EFB20 3000BFFF */  sd         $31, 0x30($29)
    /* 3EFB24 004EFB24 000060AE */  sw         $0, 0x0($19)
    /* 3EFB28 004EFB28 040060AE */  sw         $0, 0x4($19)
    /* 3EFB2C 004EFB2C 0000828C */  lw         $2, 0x0($4)
    /* 3EFB30 004EFB30 0400838C */  lw         $3, 0x4($4)
    /* 3EFB34 004EFB34 2D804000 */  daddu      $16, $2, $0
    /* 3EFB38 004EFB38 0B000010 */  b          .L004EFB68
    /* 3EFB3C 004EFB3C 21A04300 */   addu      $20, $2, $3
  .L004EFB40:
    /* 3EFB40 004EFB40 05004012 */  beqz       $18, .L004EFB58
    /* 3EFB44 004EFB44 00000000 */   nop
    /* 3EFB48 004EFB48 0C0B110C */  jal        func_00442c30
    /* 3EFB4C 004EFB4C 00000000 */   nop
    /* 3EFB50 004EFB50 15004050 */  beql       $2, $0, .L004EFBA8
    /* 3EFB54 004EFB54 0000B0DF */   ld        $16, 0x0($29)
  .L004EFB58:
    /* 3EFB58 004EFB58 6CBE130C */  jal        func_004ef9b0
    /* 3EFB5C 004EFB5C 08000426 */   addiu     $4, $16, 0x8
    /* 3EFB60 004EFB60 21100202 */  addu       $2, $16, $2
    /* 3EFB64 004EFB64 10005024 */  addiu      $16, $2, 0x10
  .L004EFB68:
    /* 3EFB68 004EFB68 2B881402 */  sltu       $17, $16, $20
    /* 3EFB6C 004EFB6C 0C002012 */  beqz       $17, .L004EFBA0
    /* 3EFB70 004EFB70 2D100000 */   daddu     $2, $0, $0
    /* 3EFB74 004EFB74 2D200002 */  daddu      $4, $16, $0
    /* 3EFB78 004EFB78 2D28A002 */  daddu      $5, $21, $0
    /* 3EFB7C 004EFB7C 0C0B110C */  jal        func_00442c30
    /* 3EFB80 004EFB80 07000624 */   addiu     $6, $0, 0x7
    /* 3EFB84 004EFB84 2D200002 */  daddu      $4, $16, $0
    /* 3EFB88 004EFB88 2D284002 */  daddu      $5, $18, $0
    /* 3EFB8C 004EFB8C ECFF4014 */  bnez       $2, .L004EFB40
    /* 3EFB90 004EFB90 07000624 */   addiu     $6, $0, 0x7
    /* 3EFB94 004EFB94 B0BE130C */  jal        func_004efac0
    /* 3EFB98 004EFB98 2D286002 */   daddu     $5, $19, $0
    /* 3EFB9C 004EFB9C 2D100000 */  daddu      $2, $0, $0
  .L004EFBA0:
    /* 3EFBA0 004EFBA0 0B101102 */  movn       $2, $16, $17
    /* 3EFBA4 004EFBA4 0000B0DF */  ld         $16, 0x0($29)
  .L004EFBA8:
    /* 3EFBA8 004EFBA8 0800B1DF */  ld         $17, 0x8($29)
    /* 3EFBAC 004EFBAC 1000B2DF */  ld         $18, 0x10($29)
    /* 3EFBB0 004EFBB0 1800B3DF */  ld         $19, 0x18($29)
    /* 3EFBB4 004EFBB4 2000B4DF */  ld         $20, 0x20($29)
    /* 3EFBB8 004EFBB8 2800B5DF */  ld         $21, 0x28($29)
    /* 3EFBBC 004EFBBC 3000BFDF */  ld         $31, 0x30($29)
    /* 3EFBC0 004EFBC0 0800E003 */  jr         $31
    /* 3EFBC4 004EFBC4 4000BD27 */   addiu     $29, $29, 0x40
.size func_004efaf8, 0xd0
