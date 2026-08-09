.section .text
.set noat
.set noreorder
glabel func_004ed4b8
    /* 3ED4B8 004ED4B8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3ED4BC 004ED4BC 2D108000 */  daddu      $2, $4, $0
    /* 3ED4C0 004ED4C0 4000B0FF */  sd         $16, 0x40($29)
    /* 3ED4C4 004ED4C4 2D80A000 */  daddu      $16, $5, $0
    /* 3ED4C8 004ED4C8 2D20A003 */  daddu      $4, $29, $0
    /* 3ED4CC 004ED4CC 4800BFFF */  sd         $31, 0x48($29)
    /* 3ED4D0 004ED4D0 0C0A110C */  jal        func_00442830
    /* 3ED4D4 004ED4D4 2D284000 */   daddu     $5, $2, $0
    /* 3ED4D8 004ED4D8 2D20A003 */  daddu      $4, $29, $0
    /* 3ED4DC 004ED4DC 0A09110C */  jal        func_00442428
    /* 3ED4E0 004ED4E0 2D280002 */   daddu     $5, $16, $0
    /* 3ED4E4 004ED4E4 20B5130C */  jal        func_004ed480
    /* 3ED4E8 004ED4E8 2D20A003 */   daddu     $4, $29, $0
    /* 3ED4EC 004ED4EC 4000B0DF */  ld         $16, 0x40($29)
    /* 3ED4F0 004ED4F0 4800BFDF */  ld         $31, 0x48($29)
    /* 3ED4F4 004ED4F4 0800E003 */  jr         $31
    /* 3ED4F8 004ED4F8 5000BD27 */   addiu     $29, $29, 0x50
    /* 3ED4FC 004ED4FC 00000000 */  nop
.size func_004ed4b8, 0x48
