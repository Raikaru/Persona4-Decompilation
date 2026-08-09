.section .text
.set noat
.set noreorder
glabel func_004c8b48
    /* 3C8B48 004C8B48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C8B4C 004C8B4C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C8B50 004C8B50 4627130C */  jal        func_004c9d18
    /* 3C8B54 004C8B54 00000000 */   nop
    /* 3C8B58 004C8B58 DC22130C */  jal        func_004c8b70
    /* 3C8B5C 004C8B5C 00000000 */   nop
    /* 3C8B60 004C8B60 0000BFDF */  ld         $31, 0x0($29)
    /* 3C8B64 004C8B64 4C271308 */  j          func_004c9d30
    /* 3C8B68 004C8B68 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C8B6C 004C8B6C 00000000 */  nop
.size func_004c8b48, 0x28
