.section .text
.set noat
.set noreorder
glabel func_004cd8c0
    /* 3CD8C0 004CD8C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD8C4 004CD8C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD8C8 004CD8C8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD8CC 004CD8CC 54B41308 */  j          func_004ed150
    /* 3CD8D0 004CD8D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD8D4 004CD8D4 00000000 */  nop
.size func_004cd8c0, 0x18
