.section .text
.set noat
.set noreorder
glabel func_00511d60
    /* 411D60 00511D60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411D64 00511D64 2D200000 */  daddu      $4, $0, $0
    /* 411D68 00511D68 0000BFFF */  sd         $31, 0x0($29)
    /* 411D6C 00511D6C 0000BFDF */  ld         $31, 0x0($29)
    /* 411D70 00511D70 C0461408 */  j          func_00511b00
    /* 411D74 00511D74 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511d60, 0x18
