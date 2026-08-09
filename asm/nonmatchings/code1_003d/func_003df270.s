.section .text
.set noat
.set noreorder
glabel func_003df270
    /* 2DF270 003DF270 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DF274 003DF274 1000BFFF */  sd         $31, 0x10($29)
    /* 2DF278 003DF278 0000B07F */  sq         $16, 0x0($29)
    /* 2DF27C 003DF27C AC8A0F0C */  jal        func_003e2ab0
    /* 2DF280 003DF280 2D808000 */   daddu     $16, $4, $0
    /* 2DF284 003DF284 2D100002 */  daddu      $2, $16, $0
    /* 2DF288 003DF288 1000BFDF */  ld         $31, 0x10($29)
    /* 2DF28C 003DF28C 0000B07B */  lq         $16, 0x0($29)
    /* 2DF290 003DF290 0800E003 */  jr         $31
    /* 2DF294 003DF294 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DF298 003DF298 00000000 */  nop
    /* 2DF29C 003DF29C 00000000 */  nop
.size func_003df270, 0x30
