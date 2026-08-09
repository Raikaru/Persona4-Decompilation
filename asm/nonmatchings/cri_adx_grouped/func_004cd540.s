.section .text
.set noat
.set noreorder
glabel func_004cd540
    /* 3CD540 004CD540 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD544 004CD544 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD548 004CD548 0C00828C */  lw         $2, 0xC($4)
    /* 3CD54C 004CD54C 80200500 */  sll        $4, $5, 2
    /* 3CD550 004CD550 2D280000 */  daddu      $5, $0, $0
    /* 3CD554 004CD554 21104400 */  addu       $2, $2, $4
    /* 3CD558 004CD558 0800438C */  lw         $3, 0x8($2)
    /* 3CD55C 004CD55C AABF130C */  jal        func_004efea8
    /* 3CD560 004CD560 0400648C */   lw        $4, 0x4($3)
    /* 3CD564 004CD564 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD568 004CD568 42100200 */  srl        $2, $2, 1
    /* 3CD56C 004CD56C 0800E003 */  jr         $31
    /* 3CD570 004CD570 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD574 004CD574 00000000 */  nop
.size func_004cd540, 0x38
