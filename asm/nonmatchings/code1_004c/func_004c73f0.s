.section .text
.set noat
.set noreorder
glabel func_004c73f0
    /* 3C73F0 004C73F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C73F4 004C73F4 2D38C000 */  daddu      $7, $6, $0
    /* 3C73F8 004C73F8 0000BFFF */  sd         $31, 0x0($29)
    /* 3C73FC 004C73FC 2D300000 */  daddu      $6, $0, $0
    /* 3C7400 004C7400 0000BFDF */  ld         $31, 0x0($29)
    /* 3C7404 004C7404 1E1D1308 */  j          func_004c7478
    /* 3C7408 004C7408 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C740C 004C740C 00000000 */  nop
.size func_004c73f0, 0x20
