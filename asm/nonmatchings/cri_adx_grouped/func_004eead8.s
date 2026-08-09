.section .text
.set noat
.set noreorder
glabel func_004eead8
    /* 3EEAD8 004EEAD8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3EEADC 004EEADC 2D108000 */  daddu      $2, $4, $0
    /* 3EEAE0 004EEAE0 4000B0FF */  sd         $16, 0x40($29)
    /* 3EEAE4 004EEAE4 2D80A000 */  daddu      $16, $5, $0
    /* 3EEAE8 004EEAE8 2D20A003 */  daddu      $4, $29, $0
    /* 3EEAEC 004EEAEC 4800BFFF */  sd         $31, 0x48($29)
    /* 3EEAF0 004EEAF0 0C0A110C */  jal        func_00442830
    /* 3EEAF4 004EEAF4 2D284000 */   daddu     $5, $2, $0
    /* 3EEAF8 004EEAF8 2D20A003 */  daddu      $4, $29, $0
    /* 3EEAFC 004EEAFC 0A09110C */  jal        func_00442428
    /* 3EEB00 004EEB00 2D280002 */   daddu     $5, $16, $0
    /* 3EEB04 004EEB04 20B5130C */  jal        func_004ed480
    /* 3EEB08 004EEB08 2D20A003 */   daddu     $4, $29, $0
    /* 3EEB0C 004EEB0C 4000B0DF */  ld         $16, 0x40($29)
    /* 3EEB10 004EEB10 4800BFDF */  ld         $31, 0x48($29)
    /* 3EEB14 004EEB14 0800E003 */  jr         $31
    /* 3EEB18 004EEB18 5000BD27 */   addiu     $29, $29, 0x50
    /* 3EEB1C 004EEB1C 00000000 */  nop
.size func_004eead8, 0x48
