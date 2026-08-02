.section .text
.set noat
.set noreorder
glabel func_004f6728
    /* 3F6728 004F6728 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F672C 004F672C 2110C400 */  addu       $2, $6, $4
    /* 3F6730 004F6730 0000BFFF */  sd         $31, 0x0($29)
    /* 3F6734 004F6734 2D20A000 */  daddu      $4, $5, $0
    /* 3F6738 004F6738 2D30E000 */  daddu      $6, $7, $0
    /* 3F673C 004F673C 2D380001 */  daddu      $7, $8, $0
    /* 3F6740 004F6740 0000BFDF */  ld         $31, 0x0($29)
    /* 3F6744 004F6744 2D284000 */  daddu      $5, $2, $0
    /* 3F6748 004F6748 3CD91308 */  j          func_004f64f0
    /* 3F674C 004F674C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f6728, 0x28
