.section .text
.set noat
.set noreorder
glabel func_003bf240
    /* 2BF240 003BF240 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BF244 003BF244 1000BFFF */  sd         $31, 0x10($29)
    /* 2BF248 003BF248 0000B07F */  sq         $16, 0x0($29)
    /* 2BF24C 003BF24C B0B6828F */  lw         $2, -0x4950($28)
    /* 2BF250 003BF250 2D808000 */  daddu      $16, $4, $0
    /* 2BF254 003BF254 21100202 */  addu       $2, $16, $2
    /* 2BF258 003BF258 0000448C */  lw         $4, 0x0($2)
    /* 2BF25C 003BF25C 30020F0C */  jal        func_003c08c0
    /* 2BF260 003BF260 2D280002 */   daddu     $5, $16, $0
    /* 2BF264 003BF264 10A10F0C */  jal        func_003e8440
    /* 2BF268 003BF268 2D200002 */   daddu     $4, $16, $0
    /* 2BF26C 003BF26C 2D100002 */  daddu      $2, $16, $0
    /* 2BF270 003BF270 1000BFDF */  ld         $31, 0x10($29)
    /* 2BF274 003BF274 0000B07B */  lq         $16, 0x0($29)
    /* 2BF278 003BF278 0800E003 */  jr         $31
    /* 2BF27C 003BF27C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003bf240, 0x40
