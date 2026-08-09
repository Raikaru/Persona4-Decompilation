.section .text
.set noat
.set noreorder
glabel func_00121af0
    /* 21AF0 00121AF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 21AF4 00121AF4 0000BFFF */  sd         $31, 0x0($29)
    /* 21AF8 00121AF8 C00E040C */  jal        func_00103b00
    /* 21AFC 00121AFC 00000000 */   nop
    /* 21B00 00121B00 2D100000 */  daddu      $2, $0, $0
    /* 21B04 00121B04 0000BFDF */  ld         $31, 0x0($29)
    /* 21B08 00121B08 1000BD27 */  addiu      $29, $29, 0x10
    /* 21B0C 00121B0C 0800E003 */  jr         $31
    /* 21B10 00121B10 00000000 */   nop
    /* 21B14 00121B14 00000000 */  nop
    /* 21B18 00121B18 00000000 */  nop
    /* 21B1C 00121B1C 00000000 */  nop
.size func_00121af0, 0x30
