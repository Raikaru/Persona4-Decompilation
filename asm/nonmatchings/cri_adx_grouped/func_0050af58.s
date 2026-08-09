.section .text
.set noat
.set noreorder
glabel func_0050af58
    /* 40AF58 0050AF58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40AF5C 0050AF5C 1000BFFF */  sd         $31, 0x10($29)
    /* 40AF60 0050AF60 D4A5140C */  jal        func_00529750
    /* 40AF64 0050AF64 2D28A003 */   daddu     $5, $29, $0
    /* 40AF68 0050AF68 01000324 */  addiu      $3, $0, 0x1
    /* 40AF6C 0050AF6C 0000A58F */  lw         $5, 0x0($29)
    /* 40AF70 0050AF70 26204300 */  xor        $4, $2, $3
    /* 40AF74 0050AF74 1000BFDF */  ld         $31, 0x10($29)
    /* 40AF78 0050AF78 FFFF0224 */  addiu      $2, $0, -0x1
    /* 40AF7C 0050AF7C 0A10A400 */  movz       $2, $5, $4
    /* 40AF80 0050AF80 0800E003 */  jr         $31
    /* 40AF84 0050AF84 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050af58, 0x30
