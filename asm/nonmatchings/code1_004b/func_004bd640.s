.section .text
.set noat
.set noreorder
glabel func_004bd640
    /* 3BD640 004BD640 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD644 004BD644 0000BFFF */  sd         $31, 0x0($29)
    /* 3BD648 004BD648 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD64C 004BD64C ACC11308 */  j          func_004f06b0
    /* 3BD650 004BD650 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD654 004BD654 00000000 */  nop
.size func_004bd640, 0x18
