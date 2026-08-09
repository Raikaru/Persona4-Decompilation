.section .text
.set noat
.set noreorder
glabel func_003bf330
    /* 2BF330 003BF330 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BF334 003BF334 1000BFFF */  sd         $31, 0x10($29)
    /* 2BF338 003BF338 0000B07F */  sq         $16, 0x0($29)
    /* 2BF33C 003BF33C B8000F0C */  jal        func_003c02e0
    /* 2BF340 003BF340 2D808000 */   daddu     $16, $4, $0
    /* 2BF344 003BF344 2D100002 */  daddu      $2, $16, $0
    /* 2BF348 003BF348 1000BFDF */  ld         $31, 0x10($29)
    /* 2BF34C 003BF34C 0000B07B */  lq         $16, 0x0($29)
    /* 2BF350 003BF350 0800E003 */  jr         $31
    /* 2BF354 003BF354 2000BD27 */   addiu     $29, $29, 0x20
    /* 2BF358 003BF358 00000000 */  nop
    /* 2BF35C 003BF35C 00000000 */  nop
.size func_003bf330, 0x30
