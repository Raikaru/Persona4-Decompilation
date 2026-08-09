.section .text
.set noat
.set noreorder
glabel func_003e6a60
    /* 2E6A60 003E6A60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E6A64 003E6A64 1000BFFF */  sd         $31, 0x10($29)
    /* 2E6A68 003E6A68 0000B07F */  sq         $16, 0x0($29)
    /* 2E6A6C 003E6A6C E8BC0F0C */  jal        func_003ef3a0
    /* 2E6A70 003E6A70 2D808000 */   daddu     $16, $4, $0
    /* 2E6A74 003E6A74 2D100002 */  daddu      $2, $16, $0
    /* 2E6A78 003E6A78 1000BFDF */  ld         $31, 0x10($29)
    /* 2E6A7C 003E6A7C 0000B07B */  lq         $16, 0x0($29)
    /* 2E6A80 003E6A80 0800E003 */  jr         $31
    /* 2E6A84 003E6A84 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E6A88 003E6A88 00000000 */  nop
    /* 2E6A8C 003E6A8C 00000000 */  nop
.size func_003e6a60, 0x30
