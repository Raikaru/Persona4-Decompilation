.section .text
.set noat
.set noreorder
glabel func_004eded0
    /* 3EDED0 004EDED0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3EDED4 004EDED4 2D108000 */  daddu      $2, $4, $0
    /* 3EDED8 004EDED8 4000B0FF */  sd         $16, 0x40($29)
    /* 3EDEDC 004EDEDC 2D80A000 */  daddu      $16, $5, $0
    /* 3EDEE0 004EDEE0 2D20A003 */  daddu      $4, $29, $0
    /* 3EDEE4 004EDEE4 4800BFFF */  sd         $31, 0x48($29)
    /* 3EDEE8 004EDEE8 0C0A110C */  jal        func_00442830
    /* 3EDEEC 004EDEEC 2D284000 */   daddu     $5, $2, $0
    /* 3EDEF0 004EDEF0 2D20A003 */  daddu      $4, $29, $0
    /* 3EDEF4 004EDEF4 0A09110C */  jal        func_00442428
    /* 3EDEF8 004EDEF8 2D280002 */   daddu     $5, $16, $0
    /* 3EDEFC 004EDEFC 20B5130C */  jal        func_004ed480
    /* 3EDF00 004EDF00 2D20A003 */   daddu     $4, $29, $0
    /* 3EDF04 004EDF04 4000B0DF */  ld         $16, 0x40($29)
    /* 3EDF08 004EDF08 4800BFDF */  ld         $31, 0x48($29)
    /* 3EDF0C 004EDF0C 0800E003 */  jr         $31
    /* 3EDF10 004EDF10 5000BD27 */   addiu     $29, $29, 0x50
    /* 3EDF14 004EDF14 00000000 */  nop
.size func_004eded0, 0x48
