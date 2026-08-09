.section .text
.set noat
.set noreorder
glabel func_004f0c60
    /* 3F0C60 004F0C60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0C64 004F0C64 2D400000 */  daddu      $8, $0, $0
    /* 3F0C68 004F0C68 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0C6C 004F0C6C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0C70 004F0C70 1EC31308 */  j          func_004f0c78
    /* 3F0C74 004F0C74 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0c60, 0x18
