.section .text
.set noat
.set noreorder
glabel func_0044b950
    /* 34B950 0044B950 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B954 0044B954 0000BFFF */  sd         $31, 0x0($29)
    /* 34B958 0044B958 0000BFDF */  ld         $31, 0x0($29)
    /* 34B95C 0044B95C 2E251108 */  j          func_004494b8
    /* 34B960 0044B960 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B964 0044B964 00000000 */  nop
.size func_0044b950, 0x18
