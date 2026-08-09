.section .text
.set noat
.set noreorder
glabel func_004f06c8
    /* 3F06C8 004F06C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F06CC 004F06CC 03000424 */  addiu      $4, $0, 0x3
    /* 3F06D0 004F06D0 0000BFFF */  sd         $31, 0x0($29)
    /* 3F06D4 004F06D4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F06D8 004F06D8 5EC11308 */  j          func_004f0578
    /* 3F06DC 004F06DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f06c8, 0x18
