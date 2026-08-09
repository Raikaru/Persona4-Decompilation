.section .text
.set noat
.set noreorder
glabel func_00353fb0
    /* 253FB0 00353FB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 253FB4 00353FB4 0000BFFF */  sd         $31, 0x0($29)
    /* 253FB8 00353FB8 2D200000 */  daddu      $4, $0, $0
    /* 253FBC 00353FBC A025050C */  jal        func_00149680
    /* 253FC0 00353FC0 00000000 */   nop
    /* 253FC4 00353FC4 0000BFDF */  ld         $31, 0x0($29)
    /* 253FC8 00353FC8 1000BD27 */  addiu      $29, $29, 0x10
    /* 253FCC 00353FCC 0800E003 */  jr         $31
    /* 253FD0 00353FD0 00000000 */   nop
    /* 253FD4 00353FD4 00000000 */  nop
    /* 253FD8 00353FD8 00000000 */  nop
    /* 253FDC 00353FDC 00000000 */  nop
.size func_00353fb0, 0x30
