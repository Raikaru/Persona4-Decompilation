.section .text
.set noat
.set noreorder
glabel func_004c95f8
    /* 3C95F8 004C95F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C95FC 004C95FC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9600 004C9600 0800BFFF */  sd         $31, 0x8($29)
    /* 3C9604 004C9604 4627130C */  jal        func_004c9d18
    /* 3C9608 004C9608 2D808000 */   daddu     $16, $4, $0
    /* 3C960C 004C960C 8C25130C */  jal        func_004c9630
    /* 3C9610 004C9610 2D200002 */   daddu     $4, $16, $0
    /* 3C9614 004C9614 4C27130C */  jal        func_004c9d30
    /* 3C9618 004C9618 2D804000 */   daddu     $16, $2, $0
    /* 3C961C 004C961C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C9620 004C9620 2D100002 */  daddu      $2, $16, $0
    /* 3C9624 004C9624 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9628 004C9628 0800E003 */  jr         $31
    /* 3C962C 004C962C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c95f8, 0x38
