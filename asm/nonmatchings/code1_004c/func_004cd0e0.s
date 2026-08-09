.section .text
.set noat
.set noreorder
glabel func_004cd0e0
    /* 3CD0E0 004CD0E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD0E4 004CD0E4 2D308000 */  daddu      $6, $4, $0
    /* 3CD0E8 004CD0E8 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD0EC 004CD0EC 2D38A000 */  daddu      $7, $5, $0
    /* 3CD0F0 004CD0F0 01000424 */  addiu      $4, $0, 0x1
    /* 3CD0F4 004CD0F4 2D280000 */  daddu      $5, $0, $0
    /* 3CD0F8 004CD0F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD0FC 004CD0FC 18C31308 */  j          func_004f0c60
    /* 3CD100 004CD100 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD104 004CD104 00000000 */  nop
.size func_004cd0e0, 0x28
