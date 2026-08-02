.section .text
.set noat
.set noreorder
glabel func_0011ded0
    /* 1DED0 0011DED0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1DED4 0011DED4 2000BFFF */  sd         $31, 0x20($29)
    /* 1DED8 0011DED8 1000B17F */  sq         $17, 0x10($29)
    /* 1DEDC 0011DEDC 0000B07F */  sq         $16, 0x0($29)
    /* 1DEE0 0011DEE0 3800908C */  lw         $16, 0x38($4)
    /* 1DEE4 0011DEE4 0000048E */  lw         $4, 0x0($16)
    /* 1DEE8 0011DEE8 3C00A527 */  addiu      $5, $29, 0x3C
    /* 1DEEC 0011DEEC 2D300000 */  daddu      $6, $0, $0
    /* 1DEF0 0011DEF0 749A110C */  jal        func_004669d0
    /* 1DEF4 0011DEF4 00000000 */   nop
    /* 1DEF8 0011DEF8 2D884000 */  daddu      $17, $2, $0
    /* 1DEFC 0011DEFC 3C00A28F */  lw         $2, 0x3C($29)
    /* 1DF00 0011DF00 1C004010 */  beqz       $2, .L0011DF74
    /* 1DF04 0011DF04 00000000 */   nop
    /* 1DF08 0011DF08 0400028E */  lw         $2, 0x4($16)
    /* 1DF0C 0011DF0C 08004010 */  beqz       $2, .L0011DF30
    /* 1DF10 0011DF10 00000000 */   nop
    /* 1DF14 0011DF14 5E00043C */  lui        $4, %hi(D_005E4ED0)
    /* 1DF18 0011DF18 D04E8424 */  addiu      $4, $4, %lo(D_005E4ED0)
    /* 1DF1C 0011DF1C 10004524 */  addiu      $5, $2, 0x10
    /* 1DF20 0011DF20 DA02110C */  jal        func_00440b68
    /* 1DF24 0011DF24 00000000 */   nop
    /* 1DF28 0011DF28 05000010 */  b          .L0011DF40
    /* 1DF2C 0011DF2C 00000000 */   nop
  .L0011DF30:
    /* 1DF30 0011DF30 5E00043C */  lui        $4, %hi(D_005E4EF0)
    /* 1DF34 0011DF34 F04E8424 */  addiu      $4, $4, %lo(D_005E4EF0)
    /* 1DF38 0011DF38 DA02110C */  jal        func_00440b68
    /* 1DF3C 0011DF3C 00000000 */   nop
  .L0011DF40:
    /* 1DF40 0011DF40 04002012 */  beqz       $17, .L0011DF54
    /* 1DF44 0011DF44 00000000 */   nop
    /* 1DF48 0011DF48 2D202002 */  daddu      $4, $17, $0
    /* 1DF4C 0011DF4C E8BC0F0C */  jal        func_003ef3a0
    /* 1DF50 0011DF50 00000000 */   nop
  .L0011DF54:
    /* 1DF54 0011DF54 0400048E */  lw         $4, 0x4($16)
    /* 1DF58 0011DF58 03008010 */  beqz       $4, .L0011DF68
    /* 1DF5C 0011DF5C 00000000 */   nop
    /* 1DF60 0011DF60 F452110C */  jal        func_00454bd0
    /* 1DF64 0011DF64 00000000 */   nop
  .L0011DF68:
    /* 1DF68 0011DF68 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1DF6C 0011DF6C 02000010 */  b          .L0011DF78
    /* 1DF70 0011DF70 00000000 */   nop
  .L0011DF74:
    /* 1DF74 0011DF74 2D100000 */  daddu      $2, $0, $0
  .L0011DF78:
    /* 1DF78 0011DF78 2000BFDF */  ld         $31, 0x20($29)
    /* 1DF7C 0011DF7C 1000B17B */  lq         $17, 0x10($29)
    /* 1DF80 0011DF80 0000B07B */  lq         $16, 0x0($29)
    /* 1DF84 0011DF84 4000BD27 */  addiu      $29, $29, 0x40
    /* 1DF88 0011DF88 0800E003 */  jr         $31
    /* 1DF8C 0011DF8C 00000000 */   nop
.size func_0011ded0, 0xc0
