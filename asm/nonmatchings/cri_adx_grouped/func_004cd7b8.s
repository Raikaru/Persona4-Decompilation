.section .text
.set noat
.set noreorder
glabel func_004cd7b8
    /* 3CD7B8 004CD7B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD7BC 004CD7BC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD7C0 004CD7C0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD7C4 004CD7C4 72B31308 */  j          func_004ecdc8
    /* 3CD7C8 004CD7C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD7CC 004CD7CC 00000000 */  nop
.size func_004cd7b8, 0x18
