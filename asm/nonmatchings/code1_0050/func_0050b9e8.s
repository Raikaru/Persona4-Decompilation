.section .text
.set noat
.set noreorder
glabel func_0050b9e8
    /* 40B9E8 0050B9E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B9EC 0050B9EC 0000BFFF */  sd         $31, 0x0($29)
    /* 40B9F0 0050B9F0 7E5E140C */  jal        func_005179f8
    /* 40B9F4 0050B9F4 00000000 */   nop
    /* 40B9F8 0050B9F8 0000BFDF */  ld         $31, 0x0($29)
    /* 40B9FC 0050B9FC 2D100000 */  daddu      $2, $0, $0
    /* 40BA00 0050BA00 0800E003 */  jr         $31
    /* 40BA04 0050BA04 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b9e8, 0x20
