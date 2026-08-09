.section .text
.set noat
.set noreorder
glabel func_00511f28
    /* 411F28 00511F28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411F2C 00511F2C 0000BFFF */  sd         $31, 0x0($29)
    /* 411F30 00511F30 DC34140C */  jal        func_0050d370
    /* 411F34 00511F34 00000000 */   nop
    /* 411F38 00511F38 0000BFDF */  ld         $31, 0x0($29)
    /* 411F3C 00511F3C 2D204000 */  daddu      $4, $2, $0
    /* 411F40 00511F40 94481408 */  j          func_00512250
    /* 411F44 00511F44 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511f28, 0x20
