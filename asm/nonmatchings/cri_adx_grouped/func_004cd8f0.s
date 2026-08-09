.section .text
.set noat
.set noreorder
glabel func_004cd8f0
    /* 3CD8F0 004CD8F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD8F4 004CD8F4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD8F8 004CD8F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD8FC 004CD8FC 90B41308 */  j          func_004ed240
    /* 3CD900 004CD900 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD904 004CD904 00000000 */  nop
.size func_004cd8f0, 0x18
