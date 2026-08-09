.section .text
.set noat
.set noreorder
glabel func_004f1308
    /* 3F1308 004F1308 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F130C 004F130C 2D200000 */  daddu      $4, $0, $0
    /* 3F1310 004F1310 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1314 004F1314 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1318 004F1318 B8C41308 */  j          func_004f12e0
    /* 3F131C 004F131C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1308, 0x18
