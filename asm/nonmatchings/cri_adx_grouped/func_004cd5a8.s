.section .text
.set noat
.set noreorder
glabel func_004cd5a8
    /* 3CD5A8 004CD5A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD5AC 004CD5AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD5B0 004CD5B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD5B4 004CD5B4 36B01308 */  j          func_004ec0d8
    /* 3CD5B8 004CD5B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD5BC 004CD5BC 00000000 */  nop
.size func_004cd5a8, 0x18
