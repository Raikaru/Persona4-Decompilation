.section .text
.set noat
.set noreorder
glabel func_0013ac30
    /* 3AC30 0013AC30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AC34 0013AC34 0000BFFF */  sd         $31, 0x0($29)
    /* 3AC38 0013AC38 2D288000 */  daddu      $5, $4, $0
    /* 3AC3C 0013AC3C FFFFA230 */  andi       $2, $5, 0xFFFF
    /* 3AC40 0013AC40 B8014228 */  slti       $2, $2, 0x1B8
    /* 3AC44 0013AC44 04004014 */  bnez       $2, .L0013AC58
    /* 3AC48 0013AC48 00000000 */   nop
    /* 3AC4C 0013AC4C 35000224 */  addiu      $2, $0, 0x35
    /* 3AC50 0013AC50 35000010 */  b          .L0013AD28
    /* 3AC54 0013AC54 00000000 */   nop
  .L0013AC58:
    /* 3AC58 0013AC58 2D200000 */  daddu      $4, $0, $0
    /* 3AC5C 0013AC5C 38F6080C */  jal        func_0023d8e0
    /* 3AC60 0013AC60 00000000 */   nop
    /* 3AC64 0013AC64 3C140200 */  dsll32     $2, $2, 16
    /* 3AC68 0013AC68 3F140200 */  dsra32     $2, $2, 16
    /* 3AC6C 0013AC6C 01004224 */  addiu      $2, $2, 0x1
    /* 3AC70 0013AC70 1400412C */  sltiu      $1, $2, 0x14
    /* 3AC74 0013AC74 26002010 */  beqz       $1, .L0013AD10
    /* 3AC78 0013AC78 00000000 */   nop
    /* 3AC7C 0013AC7C 7400033C */  lui        $3, %hi(jtbl_007469C0)
    /* 3AC80 0013AC80 C0696324 */  addiu      $3, $3, %lo(jtbl_007469C0)
    /* 3AC84 0013AC84 80100200 */  sll        $2, $2, 2
    /* 3AC88 0013AC88 21104300 */  addu       $2, $2, $3
    /* 3AC8C 0013AC8C 0000428C */  lw         $2, 0x0($2)
    /* 3AC90 0013AC90 08004000 */  jr         $2
    /* 3AC94 0013AC94 00000000 */   nop
    /* 3AC98 0013AC98 2B000224 */  addiu      $2, $0, 0x2B
    /* 3AC9C 0013AC9C 22000010 */  b          .L0013AD28
    /* 3ACA0 0013ACA0 00000000 */   nop
    /* 3ACA4 0013ACA4 2C000224 */  addiu      $2, $0, 0x2C
    /* 3ACA8 0013ACA8 1F000010 */  b          .L0013AD28
    /* 3ACAC 0013ACAC 00000000 */   nop
    /* 3ACB0 0013ACB0 2D000224 */  addiu      $2, $0, 0x2D
    /* 3ACB4 0013ACB4 1C000010 */  b          .L0013AD28
    /* 3ACB8 0013ACB8 00000000 */   nop
    /* 3ACBC 0013ACBC 2E000224 */  addiu      $2, $0, 0x2E
    /* 3ACC0 0013ACC0 19000010 */  b          .L0013AD28
    /* 3ACC4 0013ACC4 00000000 */   nop
    /* 3ACC8 0013ACC8 2F000224 */  addiu      $2, $0, 0x2F
    /* 3ACCC 0013ACCC 16000010 */  b          .L0013AD28
    /* 3ACD0 0013ACD0 00000000 */   nop
    /* 3ACD4 0013ACD4 30000224 */  addiu      $2, $0, 0x30
    /* 3ACD8 0013ACD8 13000010 */  b          .L0013AD28
    /* 3ACDC 0013ACDC 00000000 */   nop
    /* 3ACE0 0013ACE0 31000224 */  addiu      $2, $0, 0x31
    /* 3ACE4 0013ACE4 10000010 */  b          .L0013AD28
    /* 3ACE8 0013ACE8 00000000 */   nop
    /* 3ACEC 0013ACEC 32000224 */  addiu      $2, $0, 0x32
    /* 3ACF0 0013ACF0 0D000010 */  b          .L0013AD28
    /* 3ACF4 0013ACF4 00000000 */   nop
    /* 3ACF8 0013ACF8 33000224 */  addiu      $2, $0, 0x33
    /* 3ACFC 0013ACFC 0A000010 */  b          .L0013AD28
    /* 3AD00 0013AD00 00000000 */   nop
    /* 3AD04 0013AD04 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3AD08 0013AD08 07000010 */  b          .L0013AD28
    /* 3AD0C 0013AD0C 00000000 */   nop
  .L0013AD10:
    /* 3AD10 0013AD10 5F00043C */  lui        $4, %hi(D_005ED9C0)
    /* 3AD14 0013AD14 C0D98424 */  addiu      $4, $4, %lo(D_005ED9C0)
    /* 3AD18 0013AD18 B2060524 */  addiu      $5, $0, 0x6B2
    /* 3AD1C 0013AD1C CCB5110C */  jal        func_0046d730
    /* 3AD20 0013AD20 00000000 */   nop
    /* 3AD24 0013AD24 FFFF0224 */  addiu      $2, $0, -0x1
  .L0013AD28:
    /* 3AD28 0013AD28 0000BFDF */  ld         $31, 0x0($29)
    /* 3AD2C 0013AD2C 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AD30 0013AD30 0800E003 */  jr         $31
    /* 3AD34 0013AD34 00000000 */   nop
    /* 3AD38 0013AD38 00000000 */  nop
    /* 3AD3C 0013AD3C 00000000 */  nop
.size func_0013ac30, 0x110
