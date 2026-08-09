.section .text
.set noat
.set noreorder
glabel func_004cdd60
    /* 3CDD60 004CDD60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CDD64 004CDD64 0000B0FF */  sd         $16, 0x0($29)
    /* 3CDD68 004CDD68 0800BFFF */  sd         $31, 0x8($29)
    /* 3CDD6C 004CDD6C 9E36130C */  jal        func_004cda78
    /* 3CDD70 004CDD70 2D808000 */   daddu     $16, $4, $0
    /* 3CDD74 004CDD74 01000224 */  addiu      $2, $0, 0x1
    /* 3CDD78 004CDD78 0800BFDF */  ld         $31, 0x8($29)
    /* 3CDD7C 004CDD7C 010002A2 */  sb         $2, 0x1($16)
    /* 3CDD80 004CDD80 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDD84 004CDD84 0800E003 */  jr         $31
    /* 3CDD88 004CDD88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CDD8C 004CDD8C 00000000 */  nop
.size func_004cdd60, 0x30
