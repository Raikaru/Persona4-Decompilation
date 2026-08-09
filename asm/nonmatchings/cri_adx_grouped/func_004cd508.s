.section .text
.set noat
.set noreorder
glabel func_004cd508
    /* 3CD508 004CD508 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD50C 004CD50C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD510 004CD510 0C00828C */  lw         $2, 0xC($4)
    /* 3CD514 004CD514 80200500 */  sll        $4, $5, 2
    /* 3CD518 004CD518 01000524 */  addiu      $5, $0, 0x1
    /* 3CD51C 004CD51C 21104400 */  addu       $2, $2, $4
    /* 3CD520 004CD520 0800438C */  lw         $3, 0x8($2)
    /* 3CD524 004CD524 AABF130C */  jal        func_004efea8
    /* 3CD528 004CD528 0400648C */   lw        $4, 0x4($3)
    /* 3CD52C 004CD52C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD530 004CD530 42100200 */  srl        $2, $2, 1
    /* 3CD534 004CD534 0800E003 */  jr         $31
    /* 3CD538 004CD538 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD53C 004CD53C 00000000 */  nop
.size func_004cd508, 0x38
