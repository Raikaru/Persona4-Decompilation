.section .text
.set noat
.set noreorder
glabel func_004eeba0
    /* 3EEBA0 004EEBA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEBA4 004EEBA4 0000BFFF */  sd         $31, 0x0($29)
    /* 3EEBA8 004EEBA8 14B5130C */  jal        func_004ed450
    /* 3EEBAC 004EEBAC 00000000 */   nop
    /* 3EEBB0 004EEBB0 F4BA130C */  jal        func_004eebd0
    /* 3EEBB4 004EEBB4 00000000 */   nop
    /* 3EEBB8 004EEBB8 1AB5130C */  jal        func_004ed468
    /* 3EEBBC 004EEBBC 00000000 */   nop
    /* 3EEBC0 004EEBC0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEBC4 004EEBC4 08B51308 */  j          func_004ed420
    /* 3EEBC8 004EEBC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEBCC 004EEBCC 00000000 */  nop
.size func_004eeba0, 0x30
