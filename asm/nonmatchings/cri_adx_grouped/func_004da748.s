.section .text
.set noat
.set noreorder
glabel func_004da748
    /* 3DA748 004DA748 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DA74C 004DA74C 2D28C000 */  daddu      $5, $6, $0
    /* 3DA750 004DA750 0000BFFF */  sd         $31, 0x0($29)
    /* 3DA754 004DA754 2D200000 */  daddu      $4, $0, $0
    /* 3DA758 004DA758 0000BFDF */  ld         $31, 0x0($29)
    /* 3DA75C 004DA75C 96661308 */  j          func_004d9a58
    /* 3DA760 004DA760 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DA764 004DA764 00000000 */  nop
.size func_004da748, 0x20
