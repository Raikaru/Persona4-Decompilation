.section .text
.set noat
.set noreorder
glabel func_004da468
    /* 3DA468 004DA468 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DA46C 004DA46C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DA470 004DA470 0000BFDF */  ld         $31, 0x0($29)
    /* 3DA474 004DA474 26691308 */  j          func_004da498
    /* 3DA478 004DA478 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DA47C 004DA47C 00000000 */  nop
.size func_004da468, 0x18
