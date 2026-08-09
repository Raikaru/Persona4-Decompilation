.section .text
.set noat
.set noreorder
glabel func_0050ed60
    /* 40ED60 0050ED60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40ED64 0050ED64 2D380000 */  daddu      $7, $0, $0
    /* 40ED68 0050ED68 0000BFFF */  sd         $31, 0x0($29)
    /* 40ED6C 0050ED6C 0000BFDF */  ld         $31, 0x0($29)
    /* 40ED70 0050ED70 8A3B1408 */  j          func_0050ee28
    /* 40ED74 0050ED74 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050ed60, 0x18
