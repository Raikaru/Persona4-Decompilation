.section .text
.set noat
.set noreorder
glabel func_00513a58
    /* 413A58 00513A58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413A5C 00513A5C 0000BFFF */  sd         $31, 0x0($29)
    /* 413A60 00513A60 E44E140C */  jal        func_00513b90
    /* 413A64 00513A64 2D280000 */   daddu     $5, $0, $0
    /* 413A68 00513A68 0000BFDF */  ld         $31, 0x0($29)
    /* 413A6C 00513A6C 2D100000 */  daddu      $2, $0, $0
    /* 413A70 00513A70 0800E003 */  jr         $31
    /* 413A74 00513A74 1000BD27 */   addiu     $29, $29, 0x10
.size func_00513a58, 0x20
