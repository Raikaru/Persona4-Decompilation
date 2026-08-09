.section .text
.set noat
.set noreorder
glabel func_004cd488
    /* 3CD488 004CD488 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD48C 004CD48C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD490 004CD490 0C00828C */  lw         $2, 0xC($4)
    /* 3CD494 004CD494 80200500 */  sll        $4, $5, 2
    /* 3CD498 004CD498 21104400 */  addu       $2, $2, $4
    /* 3CD49C 004CD49C 0800438C */  lw         $3, 0x8($2)
    /* 3CD4A0 004CD4A0 0800648C */  lw         $4, 0x8($3)
    /* 3CD4A4 004CD4A4 0000868C */  lw         $6, 0x0($4)
    /* 3CD4A8 004CD4A8 2400C28C */  lw         $2, 0x24($6)
    /* 3CD4AC 004CD4AC 09F84000 */  jalr       $2
    /* 3CD4B0 004CD4B0 01000524 */   addiu     $5, $0, 0x1
    /* 3CD4B4 004CD4B4 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD4B8 004CD4B8 42100200 */  srl        $2, $2, 1
    /* 3CD4BC 004CD4BC 0800E003 */  jr         $31
    /* 3CD4C0 004CD4C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD4C4 004CD4C4 00000000 */  nop
.size func_004cd488, 0x40
