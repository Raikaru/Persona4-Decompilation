.section .text
.set noat
.set noreorder
glabel func_00522fd0
    /* 422FD0 00522FD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 422FD4 00522FD4 07000524 */  addiu      $5, $0, 0x7
    /* 422FD8 00522FD8 06000624 */  addiu      $6, $0, 0x6
    /* 422FDC 00522FDC 2D380000 */  daddu      $7, $0, $0
    /* 422FE0 00522FE0 0000BFFF */  sd         $31, 0x0($29)
    /* 422FE4 00522FE4 2C9E140C */  jal        func_005278b0
    /* 422FE8 00522FE8 2D400000 */   daddu     $8, $0, $0
    /* 422FEC 00522FEC 0000BFDF */  ld         $31, 0x0($29)
    /* 422FF0 00522FF0 0800E003 */  jr         $31
    /* 422FF4 00522FF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00522fd0, 0x28
