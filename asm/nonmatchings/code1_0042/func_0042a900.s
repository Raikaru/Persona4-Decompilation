.section .text
.set noat
.set noreorder
glabel func_0042a900
    /* 32A900 0042A900 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 32A904 0042A904 1000BFFF */  sd         $31, 0x10($29)
    /* 32A908 0042A908 CCA8100C */  jal        func_0042a330
    /* 32A90C 0042A90C 2D38A003 */   daddu     $7, $29, $0
    /* 32A910 0042A910 1000BFDF */  ld         $31, 0x10($29)
    /* 32A914 0042A914 0800E003 */  jr         $31
    /* 32A918 0042A918 2000BD27 */   addiu     $29, $29, 0x20
    /* 32A91C 0042A91C 00000000 */  nop
.size func_0042a900, 0x20
