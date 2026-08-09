.section .text
.set noat
.set noreorder
glabel func_004ea728
    /* 3EA728 004EA728 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA72C 004EA72C 0000BFFF */  sd         $31, 0x0($29)
    /* 3EA730 004EA730 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA734 004EA734 88C11308 */  j          func_004f0620
    /* 3EA738 004EA738 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA73C 004EA73C 00000000 */  nop
.size func_004ea728, 0x18
