.section .text
.set noat
.set noreorder
glabel func_004e7258
    /* 3E7258 004E7258 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3E725C 004E725C 3000BFFF */  sd         $31, 0x30($29)
    /* 3E7260 004E7260 AC9B130C */  jal        func_004e6eb0
    /* 3E7264 004E7264 2D28A003 */   daddu     $5, $29, $0
    /* 3E7268 004E7268 0000A28F */  lw         $2, 0x0($29)
    /* 3E726C 004E726C 3000BFDF */  ld         $31, 0x30($29)
    /* 3E7270 004E7270 2B100200 */  sltu       $2, $0, $2
    /* 3E7274 004E7274 0800E003 */  jr         $31
    /* 3E7278 004E7278 4000BD27 */   addiu     $29, $29, 0x40
    /* 3E727C 004E727C 00000000 */  nop
.size func_004e7258, 0x28
