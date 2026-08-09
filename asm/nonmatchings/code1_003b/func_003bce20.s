.section .text
.set noat
.set noreorder
glabel func_003bce20
    /* 2BCE20 003BCE20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BCE24 003BCE24 1000BFFF */  sd         $31, 0x10($29)
    /* 2BCE28 003BCE28 0000B07F */  sq         $16, 0x0($29)
    /* 2BCE2C 003BCE2C 2D808000 */  daddu      $16, $4, $0
    /* 2BCE30 003BCE30 2120C700 */  addu       $4, $6, $7
    /* 2BCE34 003BCE34 20F20E0C */  jal        func_003bc880
    /* 2BCE38 003BCE38 2D280002 */   daddu     $5, $16, $0
    /* 2BCE3C 003BCE3C 2D100002 */  daddu      $2, $16, $0
    /* 2BCE40 003BCE40 1000BFDF */  ld         $31, 0x10($29)
    /* 2BCE44 003BCE44 0000B07B */  lq         $16, 0x0($29)
    /* 2BCE48 003BCE48 0800E003 */  jr         $31
    /* 2BCE4C 003BCE4C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003bce20, 0x30
