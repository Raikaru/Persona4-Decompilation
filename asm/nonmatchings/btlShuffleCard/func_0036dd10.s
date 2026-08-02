.section .text
.set noat
.set noreorder
glabel func_0036dd10
    /* 26DD10 0036DD10 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 26DD14 0036DD14 3000BFFF */  sd         $31, 0x30($29)
    /* 26DD18 0036DD18 2000B17F */  sq         $17, 0x20($29)
    /* 26DD1C 0036DD1C 1000B07F */  sq         $16, 0x10($29)
    /* 26DD20 0036DD20 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 26DD24 0036DD24 2D888000 */  daddu      $17, $4, $0
    /* 26DD28 0036DD28 2D80A000 */  daddu      $16, $5, $0
    /* 26DD2C 0036DD2C 06650046 */  mov.s      $f20, $f12
    /* 26DD30 0036DD30 06000016 */  bnez       $16, .L0036DD4C
    /* 26DD34 0036DD34 00000000 */   nop
    /* 26DD38 0036DD38 6500043C */  lui        $4, %hi(D_0064E5B0)
    /* 26DD3C 0036DD3C B0E58424 */  addiu      $4, $4, %lo(D_0064E5B0)
    /* 26DD40 0036DD40 D4000524 */  addiu      $5, $0, 0xD4
    /* 26DD44 0036DD44 CCB5110C */  jal        func_0046d730
    /* 26DD48 0036DD48 00000000 */   nop
  .L0036DD4C:
    /* 26DD4C 0036DD4C 2D202002 */  daddu      $4, $17, $0
    /* 26DD50 0036DD50 06A30046 */  mov.s      $f12, $f20
    /* 26DD54 0036DD54 E4A90D0C */  jal        func_0036a790
    /* 26DD58 0036DD58 00000000 */   nop
    /* 26DD5C 0036DD5C 2D202002 */  daddu      $4, $17, $0
    /* 26DD60 0036DD60 2D280002 */  daddu      $5, $16, $0
    /* 26DD64 0036DD64 06030046 */  mov.s      $f12, $f0
    /* 26DD68 0036DD68 4000A627 */  addiu      $6, $29, 0x40
    /* 26DD6C 0036DD6C ACA90D0C */  jal        func_0036a6b0
    /* 26DD70 0036DD70 00000000 */   nop
    /* 26DD74 0036DD74 2D202002 */  daddu      $4, $17, $0
    /* 26DD78 0036DD78 4000A527 */  addiu      $5, $29, 0x40
    /* 26DD7C 0036DD7C 68B70D0C */  jal        func_0036dda0
    /* 26DD80 0036DD80 00000000 */   nop
    /* 26DD84 0036DD84 3000BFDF */  ld         $31, 0x30($29)
    /* 26DD88 0036DD88 2000B17B */  lq         $17, 0x20($29)
    /* 26DD8C 0036DD8C 1000B07B */  lq         $16, 0x10($29)
    /* 26DD90 0036DD90 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 26DD94 0036DD94 5000BD27 */  addiu      $29, $29, 0x50
    /* 26DD98 0036DD98 0800E003 */  jr         $31
    /* 26DD9C 0036DD9C 00000000 */   nop
.size func_0036dd10, 0x90
