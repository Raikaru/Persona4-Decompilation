.section .text
.set noat
.set noreorder
glabel func_0042e5b8
    /* 32E5B8 0042E5B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32E5BC 0042E5BC 0000BFFF */  sd         $31, 0x0($29)
    /* 32E5C0 0042E5C0 AEB8100C */  jal        func_0042e2b8
    /* 32E5C4 0042E5C4 2D300000 */   daddu     $6, $0, $0
    /* 32E5C8 0042E5C8 0000BFDF */  ld         $31, 0x0($29)
    /* 32E5CC 0042E5CC 0800E003 */  jr         $31
    /* 32E5D0 0042E5D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 32E5D4 0042E5D4 00000000 */  nop
.size func_0042e5b8, 0x20
