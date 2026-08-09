.section .text
.set noat
.set noreorder
glabel func_004f1068
    /* 3F1068 004F1068 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F106C 004F106C 01000424 */  addiu      $4, $0, 0x1
    /* 3F1070 004F1070 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1074 004F1074 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1078 004F1078 BCC31308 */  j          func_004f0ef0
    /* 3F107C 004F107C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1068, 0x18
