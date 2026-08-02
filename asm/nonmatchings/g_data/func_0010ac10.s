.section .text
.set noat
.set noreorder
glabel func_0010ac10
    /* AC10 0010AC10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AC14 0010AC14 1000BFFF */  sd         $31, 0x10($29)
    /* AC18 0010AC18 0000B07F */  sq         $16, 0x0($29)
    /* AC1C 0010AC1C 2D808000 */  daddu      $16, $4, $0
    /* AC20 0010AC20 6C2D040C */  jal        func_0010b5b0
    /* AC24 0010AC24 00000000 */   nop
    /* AC28 0010AC28 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* AC2C 0010AC2C 2D380000 */  daddu      $7, $0, $0
    /* AC30 0010AC30 3C2C1000 */  dsll32     $5, $16, 16
    /* AC34 0010AC34 3F2C0500 */  dsra32     $5, $5, 16
    /* AC38 0010AC38 7900043C */  lui        $4, %hi(D_007973A0)
    /* AC3C 0010AC3C A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* AC40 0010AC40 13000010 */  b          .L0010AC90
    /* AC44 0010AC44 00000000 */   nop
  .L0010AC48:
    /* AC48 0010AC48 FFFFE330 */  andi       $3, $7, 0xFFFF
    /* AC4C 0010AC4C 40100300 */  sll        $2, $3, 1
    /* AC50 0010AC50 21104300 */  addu       $2, $2, $3
    /* AC54 0010AC54 00110200 */  sll        $2, $2, 4
    /* AC58 0010AC58 21188200 */  addu       $3, $4, $2
    /* AC5C 0010AC5C EC0B6294 */  lhu        $2, 0xBEC($3)
    /* AC60 0010AC60 01004230 */  andi       $2, $2, 0x1
    /* AC64 0010AC64 08004010 */  beqz       $2, .L0010AC88
    /* AC68 0010AC68 00000000 */   nop
    /* AC6C 0010AC6C EE0B6294 */  lhu        $2, 0xBEE($3)
    /* AC70 0010AC70 05004514 */  bne        $2, $5, .L0010AC88
    /* AC74 0010AC74 00000000 */   nop
    /* AC78 0010AC78 3C240700 */  dsll32     $4, $7, 16
    /* AC7C 0010AC7C 3F240400 */  dsra32     $4, $4, 16
    /* AC80 0010AC80 08000010 */  b          .L0010ACA4
    /* AC84 0010AC84 00000000 */   nop
  .L0010AC88:
    /* AC88 0010AC88 0100E224 */  addiu      $2, $7, 0x1
    /* AC8C 0010AC8C FFFF4730 */  andi       $7, $2, 0xFFFF
  .L0010AC90:
    /* AC90 0010AC90 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AC94 0010AC94 2A104600 */  slt        $2, $2, $6
    /* AC98 0010AC98 EBFF4014 */  bnez       $2, .L0010AC48
    /* AC9C 0010AC9C 00000000 */   nop
    /* ACA0 0010ACA0 FFFF0424 */  addiu      $4, $0, -0x1
  .L0010ACA4:
    /* ACA4 0010ACA4 3C1C0400 */  dsll32     $3, $4, 16
    /* ACA8 0010ACA8 3F1C0300 */  dsra32     $3, $3, 16
    /* ACAC 0010ACAC FFFF0224 */  addiu      $2, $0, -0x1
    /* ACB0 0010ACB0 04006214 */  bne        $3, $2, .L0010ACC4
    /* ACB4 0010ACB4 00000000 */   nop
    /* ACB8 0010ACB8 2D100000 */  daddu      $2, $0, $0
    /* ACBC 0010ACBC 03000010 */  b          .L0010ACCC
    /* ACC0 0010ACC0 00000000 */   nop
  .L0010ACC4:
    /* ACC4 0010ACC4 382B040C */  jal        func_0010ace0
    /* ACC8 0010ACC8 00000000 */   nop
  .L0010ACCC:
    /* ACCC 0010ACCC 1000BFDF */  ld         $31, 0x10($29)
    /* ACD0 0010ACD0 0000B07B */  lq         $16, 0x0($29)
    /* ACD4 0010ACD4 2000BD27 */  addiu      $29, $29, 0x20
    /* ACD8 0010ACD8 0800E003 */  jr         $31
    /* ACDC 0010ACDC 00000000 */   nop
.size func_0010ac10, 0xd0
