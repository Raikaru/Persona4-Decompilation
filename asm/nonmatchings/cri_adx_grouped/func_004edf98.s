.section .text
.set noat
.set noreorder
glabel func_004edf98
    /* 3EDF98 004EDF98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDF9C 004EDF9C 0000BFFF */  sd         $31, 0x0($29)
    /* 3EDFA0 004EDFA0 14B5130C */  jal        func_004ed450
    /* 3EDFA4 004EDFA4 00000000 */   nop
    /* 3EDFA8 004EDFA8 F2B7130C */  jal        func_004edfc8
    /* 3EDFAC 004EDFAC 00000000 */   nop
    /* 3EDFB0 004EDFB0 1AB5130C */  jal        func_004ed468
    /* 3EDFB4 004EDFB4 00000000 */   nop
    /* 3EDFB8 004EDFB8 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDFBC 004EDFBC 08B51308 */  j          func_004ed420
    /* 3EDFC0 004EDFC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDFC4 004EDFC4 00000000 */  nop
.size func_004edf98, 0x30
