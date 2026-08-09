.section .text
.set noat
.set noreorder
glabel func_004f0620
    /* 3F0620 004F0620 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0624 004F0624 01000424 */  addiu      $4, $0, 0x1
    /* 3F0628 004F0628 0000BFFF */  sd         $31, 0x0($29)
    /* 3F062C 004F062C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0630 004F0630 5EC11308 */  j          func_004f0578
    /* 3F0634 004F0634 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0620, 0x18
