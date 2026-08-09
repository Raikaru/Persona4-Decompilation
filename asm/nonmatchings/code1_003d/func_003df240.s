.section .text
.set noat
.set noreorder
glabel func_003df240
    /* 2DF240 003DF240 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DF244 003DF244 1000BFFF */  sd         $31, 0x10($29)
    /* 2DF248 003DF248 0000B07F */  sq         $16, 0x0($29)
    /* 2DF24C 003DF24C AC8A0F0C */  jal        func_003e2ab0
    /* 2DF250 003DF250 2D808000 */   daddu     $16, $4, $0
    /* 2DF254 003DF254 2D100002 */  daddu      $2, $16, $0
    /* 2DF258 003DF258 1000BFDF */  ld         $31, 0x10($29)
    /* 2DF25C 003DF25C 0000B07B */  lq         $16, 0x0($29)
    /* 2DF260 003DF260 0800E003 */  jr         $31
    /* 2DF264 003DF264 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DF268 003DF268 00000000 */  nop
    /* 2DF26C 003DF26C 00000000 */  nop
.size func_003df240, 0x30
