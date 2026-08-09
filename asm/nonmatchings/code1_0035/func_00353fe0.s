.section .text
.set noat
.set noreorder
glabel func_00353fe0
    /* 253FE0 00353FE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 253FE4 00353FE4 0000BFFF */  sd         $31, 0x0($29)
    /* 253FE8 00353FE8 01000424 */  addiu      $4, $0, 0x1
    /* 253FEC 00353FEC A025050C */  jal        func_00149680
    /* 253FF0 00353FF0 00000000 */   nop
    /* 253FF4 00353FF4 0000BFDF */  ld         $31, 0x0($29)
    /* 253FF8 00353FF8 1000BD27 */  addiu      $29, $29, 0x10
    /* 253FFC 00353FFC 0800E003 */  jr         $31
    /* 254000 00354000 00000000 */   nop
    /* 254004 00354004 00000000 */  nop
    /* 254008 00354008 00000000 */  nop
    /* 25400C 0035400C 00000000 */  nop
.size func_00353fe0, 0x30
