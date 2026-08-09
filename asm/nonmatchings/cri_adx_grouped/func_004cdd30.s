.section .text
.set noat
.set noreorder
glabel func_004cdd30
    /* 3CDD30 004CDD30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CDD34 004CDD34 0000B0FF */  sd         $16, 0x0($29)
    /* 3CDD38 004CDD38 2D808000 */  daddu      $16, $4, $0
    /* 3CDD3C 004CDD3C 0800BFFF */  sd         $31, 0x8($29)
    /* 3CDD40 004CDD40 4407130C */  jal        func_004c1d10
    /* 3CDD44 004CDD44 0400048E */   lw        $4, 0x4($16)
    /* 3CDD48 004CDD48 0400048E */  lw         $4, 0x4($16)
    /* 3CDD4C 004CDD4C 0800BFDF */  ld         $31, 0x8($29)
    /* 3CDD50 004CDD50 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDD54 004CDD54 AE061308 */  j          func_004c1ab8
    /* 3CDD58 004CDD58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CDD5C 004CDD5C 00000000 */  nop
.size func_004cdd30, 0x30
