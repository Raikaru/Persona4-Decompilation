.section .text
.set noat
.set noreorder
glabel func_00521ae0
    /* 421AE0 00521AE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 421AE4 00521AE4 02000524 */  addiu      $5, $0, 0x2
    /* 421AE8 00521AE8 0000BFFF */  sd         $31, 0x0($29)
    /* 421AEC 00521AEC 0000BFDF */  ld         $31, 0x0($29)
    /* 421AF0 00521AF0 069E1408 */  j          func_00527818
    /* 421AF4 00521AF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00521ae0, 0x18
