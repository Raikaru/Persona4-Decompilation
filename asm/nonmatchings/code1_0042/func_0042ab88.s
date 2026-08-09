.section .text
.set noat
.set noreorder
glabel func_0042ab88
    /* 32AB88 0042AB88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32AB8C 0042AB8C 0000BFFF */  sd         $31, 0x0($29)
    /* 32AB90 0042AB90 50AA100C */  jal        func_0042a940
    /* 32AB94 0042AB94 2D400000 */   daddu     $8, $0, $0
    /* 32AB98 0042AB98 0000BFDF */  ld         $31, 0x0($29)
    /* 32AB9C 0042AB9C 0800E003 */  jr         $31
    /* 32ABA0 0042ABA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 32ABA4 0042ABA4 00000000 */  nop
.size func_0042ab88, 0x20
