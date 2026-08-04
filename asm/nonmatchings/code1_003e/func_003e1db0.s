.section .text
.set noat
.set noreorder
glabel func_003e1db0
    /* 2E1DB0 003E1DB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E1DB4 003E1DB4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E1DB8 003E1DB8 1000BFFF */  sd         $31, 0x10($29)
    /* 2E1DBC 003E1DBC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E1DC0 003E1DC0 0000B07F */  sq         $16, 0x0($29)
    /* 2E1DC4 003E1DC4 2D808000 */  daddu      $16, $4, $0
    /* 2E1DC8 003E1DC8 80B785AF */  sw         $5, -0x4880($28)
    /* 2E1DCC 003E1DCC 21204500 */  addu       $4, $2, $5
    /* 2E1DD0 003E1DD0 8800023C */  lui        $2, %hi(D_00887408)
    /* 2E1DD4 003E1DD4 2C870F0C */  jal        func_003e1cb0
    /* 2E1DD8 003E1DD8 0874458C */   lw        $5, %lo(D_00887408)($2)
    /* 2E1DDC 003E1DDC 03004014 */  bnez       $2, .L003E1DEC
    /* 2E1DE0 003E1DE0 00000000 */   nop
    /* 2E1DE4 003E1DE4 05000010 */  b          .L003E1DFC
    /* 2E1DE8 003E1DE8 2D100000 */   daddu     $2, $0, $0
  .L003E1DEC:
    /* 2E1DEC 003E1DEC 84B7838F */  lw         $3, -0x487C($28)
    /* 2E1DF0 003E1DF0 2D100002 */  daddu      $2, $16, $0
    /* 2E1DF4 003E1DF4 01006324 */  addiu      $3, $3, 0x1
    /* 2E1DF8 003E1DF8 84B783AF */  sw         $3, -0x487C($28)
  .L003E1DFC:
    /* 2E1DFC 003E1DFC 1000BFDF */  ld         $31, 0x10($29)
    /* 2E1E00 003E1E00 0000B07B */  lq         $16, 0x0($29)
    /* 2E1E04 003E1E04 0800E003 */  jr         $31
    /* 2E1E08 003E1E08 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E1E0C 003E1E0C 00000000 */  nop
.size func_003e1db0, 0x60
