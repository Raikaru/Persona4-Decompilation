.section .text
.set noat
.set noreorder
glabel func_0017abd0
    /* 7ABD0 0017ABD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 7ABD4 0017ABD4 2000BFFF */  sd         $31, 0x20($29)
    /* 7ABD8 0017ABD8 1000B17F */  sq         $17, 0x10($29)
    /* 7ABDC 0017ABDC 0000B07F */  sq         $16, 0x0($29)
    /* 7ABE0 0017ABE0 2D88A000 */  daddu      $17, $5, $0
    /* 7ABE4 0017ABE4 8800103C */  lui        $16, %hi(D_00887300)
    /* 7ABE8 0017ABE8 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* 7ABEC 0017ABEC 07000424 */  addiu      $4, $0, 0x7
    /* 7ABF0 0017ABF0 02000524 */  addiu      $5, $0, 0x2
    /* 7ABF4 0017ABF4 0000028E */  lw         $2, 0x0($16)
    /* 7ABF8 0017ABF8 09F84000 */  jalr       $2
    /* 7ABFC 0017ABFC 00000000 */   nop
    /* 7AC00 0017AC00 06000424 */  addiu      $4, $0, 0x6
    /* 7AC04 0017AC04 01000524 */  addiu      $5, $0, 0x1
    /* 7AC08 0017AC08 0000028E */  lw         $2, 0x0($16)
    /* 7AC0C 0017AC0C 09F84000 */  jalr       $2
    /* 7AC10 0017AC10 00000000 */   nop
    /* 7AC14 0017AC14 08000424 */  addiu      $4, $0, 0x8
    /* 7AC18 0017AC18 2D280000 */  daddu      $5, $0, $0
    /* 7AC1C 0017AC1C 0000028E */  lw         $2, 0x0($16)
    /* 7AC20 0017AC20 09F84000 */  jalr       $2
    /* 7AC24 0017AC24 00000000 */   nop
    /* 7AC28 0017AC28 48BA828F */  lw         $2, -0x45B8($28)
    /* 7AC2C 0017AC2C 01000524 */  addiu      $5, $0, 0x1
    /* 7AC30 0017AC30 05004514 */  bne        $2, $5, .L0017AC48
    /* 7AC34 0017AC34 00000000 */   nop
    /* 7AC38 0017AC38 0E000424 */  addiu      $4, $0, 0xE
    /* 7AC3C 0017AC3C 0000028E */  lw         $2, 0x0($16)
    /* 7AC40 0017AC40 09F84000 */  jalr       $2
    /* 7AC44 0017AC44 00000000 */   nop
  .L0017AC48:
    /* 7AC48 0017AC48 02000424 */  addiu      $4, $0, 0x2
    /* 7AC4C 0017AC4C 44000524 */  addiu      $5, $0, 0x44
    /* 7AC50 0017AC50 10D90F0C */  jal        func_003f6440
    /* 7AC54 0017AC54 00000000 */   nop
    /* 7AC58 0017AC58 03000424 */  addiu      $4, $0, 0x3
    /* 7AC5C 0017AC5C 0700023C */  lui        $2, (0x717FB >> 16)
    /* 7AC60 0017AC60 FB174534 */  ori        $5, $2, (0x717FB & 0xFFFF)
    /* 7AC64 0017AC64 10D90F0C */  jal        func_003f6440
    /* 7AC68 0017AC68 00000000 */   nop
    /* 7AC6C 0017AC6C 5000228E */  lw         $2, 0x50($17)
    /* 7AC70 0017AC70 0400448C */  lw         $4, 0x4($2)
    /* 7AC74 0017AC74 4800828C */  lw         $2, 0x48($4)
    /* 7AC78 0017AC78 09F84000 */  jalr       $2
    /* 7AC7C 0017AC7C 00000000 */   nop
    /* 7AC80 0017AC80 48BA838F */  lw         $3, -0x45B8($28)
    /* 7AC84 0017AC84 01000524 */  addiu      $5, $0, 0x1
    /* 7AC88 0017AC88 05006514 */  bne        $3, $5, .L0017ACA0
    /* 7AC8C 0017AC8C 00000000 */   nop
    /* 7AC90 0017AC90 0E000424 */  addiu      $4, $0, 0xE
    /* 7AC94 0017AC94 0000028E */  lw         $2, 0x0($16)
    /* 7AC98 0017AC98 09F84000 */  jalr       $2
    /* 7AC9C 0017AC9C 00000000 */   nop
  .L0017ACA0:
    /* 7ACA0 0017ACA0 2000BFDF */  ld         $31, 0x20($29)
    /* 7ACA4 0017ACA4 1000B17B */  lq         $17, 0x10($29)
    /* 7ACA8 0017ACA8 0000B07B */  lq         $16, 0x0($29)
    /* 7ACAC 0017ACAC 3000BD27 */  addiu      $29, $29, 0x30
    /* 7ACB0 0017ACB0 0800E003 */  jr         $31
    /* 7ACB4 0017ACB4 00000000 */   nop
    /* 7ACB8 0017ACB8 00000000 */  nop
    /* 7ACBC 0017ACBC 00000000 */  nop
.size func_0017abd0, 0xf0
