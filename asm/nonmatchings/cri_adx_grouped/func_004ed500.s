.section .text
.set noat
.set noreorder
glabel func_004ed500
    /* 3ED500 004ED500 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED504 004ED504 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED508 004ED508 FAB4130C */  jal        func_004ed3e8
    /* 3ED50C 004ED50C 00000000 */   nop
    /* 3ED510 004ED510 14B5130C */  jal        func_004ed450
    /* 3ED514 004ED514 00000000 */   nop
    /* 3ED518 004ED518 4CB5130C */  jal        func_004ed530
    /* 3ED51C 004ED51C 00000000 */   nop
    /* 3ED520 004ED520 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED524 004ED524 1AB51308 */  j          func_004ed468
    /* 3ED528 004ED528 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED52C 004ED52C 00000000 */  nop
.size func_004ed500, 0x30
