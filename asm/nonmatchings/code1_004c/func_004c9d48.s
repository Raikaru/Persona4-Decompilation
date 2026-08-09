.section .text
.set noat
.set noreorder
glabel func_004c9d48
    /* 3C9D48 004C9D48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9D4C 004C9D4C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C9D50 004C9D50 3615130C */  jal        func_004c54d8
    /* 3C9D54 004C9D54 00000000 */   nop
    /* 3C9D58 004C9D58 5C27130C */  jal        func_004c9d70
    /* 3C9D5C 004C9D5C 00000000 */   nop
    /* 3C9D60 004C9D60 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9D64 004C9D64 38151308 */  j          func_004c54e0
    /* 3C9D68 004C9D68 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9D6C 004C9D6C 00000000 */  nop
.size func_004c9d48, 0x28
