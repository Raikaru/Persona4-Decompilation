.section .text
.set noat
.set noreorder
glabel func_0042acb0
    /* 32ACB0 0042ACB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32ACB4 0042ACB4 0000BFFF */  sd         $31, 0x0($29)
    /* 32ACB8 0042ACB8 EAAA100C */  jal        func_0042aba8
    /* 32ACBC 0042ACBC 01000724 */   addiu     $7, $0, 0x1
    /* 32ACC0 0042ACC0 0000BFDF */  ld         $31, 0x0($29)
    /* 32ACC4 0042ACC4 0800E003 */  jr         $31
    /* 32ACC8 0042ACC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 32ACCC 0042ACCC 00000000 */  nop
.size func_0042acb0, 0x20
