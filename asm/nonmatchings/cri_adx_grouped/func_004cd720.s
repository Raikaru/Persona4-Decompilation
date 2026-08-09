.section .text
.set noat
.set noreorder
glabel func_004cd720
    /* 3CD720 004CD720 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD724 004CD724 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD728 004CD728 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD72C 004CD72C 6CB21308 */  j          func_004ec9b0
    /* 3CD730 004CD730 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD734 004CD734 00000000 */  nop
.size func_004cd720, 0x18
