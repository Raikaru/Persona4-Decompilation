.section .text
.set noat
.set noreorder
glabel func_00513a78
    /* 413A78 00513A78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413A7C 00513A7C 0000BFFF */  sd         $31, 0x0($29)
    /* 413A80 00513A80 0420828C */  lw         $2, 0x2004($4)
    /* 413A84 00513A84 C250130C */  jal        func_004d4308
    /* 413A88 00513A88 0000448C */   lw        $4, 0x0($2)
    /* 413A8C 00513A8C 2D100000 */  daddu      $2, $0, $0
    /* 413A90 00513A90 0000BFDF */  ld         $31, 0x0($29)
    /* 413A94 00513A94 0800E003 */  jr         $31
    /* 413A98 00513A98 1000BD27 */   addiu     $29, $29, 0x10
    /* 413A9C 00513A9C 00000000 */  nop
.size func_00513a78, 0x28
