.section .text
.set noat
.set noreorder
glabel func_004cd8d8
    /* 3CD8D8 004CD8D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD8DC 004CD8DC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD8E0 004CD8E0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD8E4 004CD8E4 60B41308 */  j          func_004ed180
    /* 3CD8E8 004CD8E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD8EC 004CD8EC 00000000 */  nop
.size func_004cd8d8, 0x18
