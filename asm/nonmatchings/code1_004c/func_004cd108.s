.section .text
.set noat
.set noreorder
glabel func_004cd108
    /* 3CD108 004CD108 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD10C 004CD10C 2D308000 */  daddu      $6, $4, $0
    /* 3CD110 004CD110 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD114 004CD114 2D38A000 */  daddu      $7, $5, $0
    /* 3CD118 004CD118 07000424 */  addiu      $4, $0, 0x7
    /* 3CD11C 004CD11C 2D280000 */  daddu      $5, $0, $0
    /* 3CD120 004CD120 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD124 004CD124 18C31308 */  j          func_004f0c60
    /* 3CD128 004CD128 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD12C 004CD12C 00000000 */  nop
.size func_004cd108, 0x28
