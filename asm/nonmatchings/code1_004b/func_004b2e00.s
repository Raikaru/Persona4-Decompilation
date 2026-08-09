.section .text
.set noat
.set noreorder
glabel func_004b2e00
    /* 3B2E00 004B2E00 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3B2E04 004B2E04 2000BFFF */  sd         $31, 0x20($29)
    /* 3B2E08 004B2E08 1000B17F */  sq         $17, 0x10($29)
    /* 3B2E0C 004B2E0C 0000B07F */  sq         $16, 0x0($29)
    /* 3B2E10 004B2E10 2D808000 */  daddu      $16, $4, $0
    /* 3B2E14 004B2E14 0C00848C */  lw         $4, 0xC($4)
    /* 3B2E18 004B2E18 1C008010 */  beqz       $4, .L004B2E8C
    /* 3B2E1C 004B2E1C 00000000 */   nop
    /* 3B2E20 004B2E20 0400918C */  lw         $17, 0x4($4)
    /* 3B2E24 004B2E24 07002012 */  beqz       $17, .L004B2E44
    /* 3B2E28 004B2E28 00000000 */   nop
    /* 3B2E2C 004B2E2C 2D280000 */  daddu      $5, $0, $0
    /* 3B2E30 004B2E30 48BF0F0C */  jal        func_003efd20
    /* 3B2E34 004B2E34 00000000 */   nop
    /* 3B2E38 004B2E38 2D202002 */  daddu      $4, $17, $0
    /* 3B2E3C 004B2E3C E4A40F0C */  jal        func_003e9390
    /* 3B2E40 004B2E40 00000000 */   nop
  .L004B2E44:
    /* 3B2E44 004B2E44 0C00038E */  lw         $3, 0xC($16)
    /* 3B2E48 004B2E48 64006224 */  addiu      $2, $3, 0x64
    /* 3B2E4C 004B2E4C 6400648C */  lw         $4, 0x64($3)
    /* 3B2E50 004B2E50 04008010 */  beqz       $4, .L004B2E64
    /* 3B2E54 004B2E54 00000000 */   nop
    /* 3B2E58 004B2E58 000040AC */  sw         $0, 0x0($2)
    /* 3B2E5C 004B2E5C CCB00F0C */  jal        func_003ec330
    /* 3B2E60 004B2E60 00000000 */   nop
  .L004B2E64:
    /* 3B2E64 004B2E64 0C00028E */  lw         $2, 0xC($16)
    /* 3B2E68 004B2E68 60004324 */  addiu      $3, $2, 0x60
    /* 3B2E6C 004B2E6C 6000428C */  lw         $2, 0x60($2)
    /* 3B2E70 004B2E70 02004010 */  beqz       $2, .L004B2E7C
    /* 3B2E74 004B2E74 00000000 */   nop
    /* 3B2E78 004B2E78 000060AC */  sw         $0, 0x0($3)
  .L004B2E7C:
    /* 3B2E7C 004B2E7C 0C00048E */  lw         $4, 0xC($16)
    /* 3B2E80 004B2E80 10A10F0C */  jal        func_003e8440
    /* 3B2E84 004B2E84 00000000 */   nop
    /* 3B2E88 004B2E88 0C0000AE */  sw         $0, 0xC($16)
  .L004B2E8C:
    /* 3B2E8C 004B2E8C 0800048E */  lw         $4, 0x8($16)
    /* 3B2E90 004B2E90 08008010 */  beqz       $4, .L004B2EB4
    /* 3B2E94 004B2E94 00000000 */   nop
    /* 3B2E98 004B2E98 2D280000 */  daddu      $5, $0, $0
    /* 3B2E9C 004B2E9C 343F100C */  jal        func_0040fcd0
    /* 3B2EA0 004B2EA0 00000000 */   nop
    /* 3B2EA4 004B2EA4 0800048E */  lw         $4, 0x8($16)
    /* 3B2EA8 004B2EA8 CCB00F0C */  jal        func_003ec330
    /* 3B2EAC 004B2EAC 00000000 */   nop
    /* 3B2EB0 004B2EB0 080000AE */  sw         $0, 0x8($16)
  .L004B2EB4:
    /* 3B2EB4 004B2EB4 2000BFDF */  ld         $31, 0x20($29)
    /* 3B2EB8 004B2EB8 1000B17B */  lq         $17, 0x10($29)
    /* 3B2EBC 004B2EBC 0000B07B */  lq         $16, 0x0($29)
    /* 3B2EC0 004B2EC0 3000BD27 */  addiu      $29, $29, 0x30
    /* 3B2EC4 004B2EC4 0800E003 */  jr         $31
    /* 3B2EC8 004B2EC8 00000000 */   nop
    /* 3B2ECC 004B2ECC 00000000 */  nop
.size func_004b2e00, 0xd0
