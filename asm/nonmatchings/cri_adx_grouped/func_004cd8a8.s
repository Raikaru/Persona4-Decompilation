.section .text
.set noat
.set noreorder
glabel func_004cd8a8
    /* 3CD8A8 004CD8A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD8AC 004CD8AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD8B0 004CD8B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD8B4 004CD8B4 46B41308 */  j          func_004ed118
    /* 3CD8B8 004CD8B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD8BC 004CD8BC 00000000 */  nop
.size func_004cd8a8, 0x18
