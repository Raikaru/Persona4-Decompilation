.section .text
.set noat
.set noreorder
glabel func_004cd958
    /* 3CD958 004CD958 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD95C 004CD95C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD960 004CD960 B4B4130C */  jal        func_004ed2d0
    /* 3CD964 004CD964 00000000 */   nop
    /* 3CD968 004CD968 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD96C 004CD96C 2D100000 */  daddu      $2, $0, $0
    /* 3CD970 004CD970 0800E003 */  jr         $31
    /* 3CD974 004CD974 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd958, 0x20
