.section .text
.set noat
.set noreorder
glabel func_0050cd80
    /* 40CD80 0050CD80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CD84 0050CD84 0000BFFF */  sd         $31, 0x0($29)
    /* 40CD88 0050CD88 0000BFDF */  ld         $31, 0x0($29)
    /* 40CD8C 0050CD8C 26331308 */  j          func_004ccc98
    /* 40CD90 0050CD90 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CD94 0050CD94 00000000 */  nop
.size func_0050cd80, 0x18
