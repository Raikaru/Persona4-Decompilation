.section .text
.set noat
.set noreorder
glabel func_004efc20
    /* 3EFC20 004EFC20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFC24 004EFC24 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFC28 004EFC28 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFC2C 004EFC2C 9200103C */  lui        $16, %hi(D_00925AC0)
    /* 3EFC30 004EFC30 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFC34 004EFC34 0800BFFF */  sd         $31, 0x8($29)
    /* 3EFC38 004EFC38 C05A1026 */  addiu      $16, $16, %lo(D_00925AC0)
    /* 3EFC3C 004EFC3C 000044AC */  sw         $4, 0x0($2)
    /* 3EFC40 004EFC40 040045AC */  sw         $5, 0x4($2)
    /* 3EFC44 004EFC44 2D284000 */  daddu      $5, $2, $0
    /* 3EFC48 004EFC48 2D380002 */  daddu      $7, $16, $0
    /* 3EFC4C 004EFC4C 21000424 */  addiu      $4, $0, 0x21
    /* 3EFC50 004EFC50 02000624 */  addiu      $6, $0, 0x2
    /* 3EFC54 004EFC54 2896130C */  jal        func_004e58a0
    /* 3EFC58 004EFC58 01000824 */   addiu     $8, $0, 0x1
    /* 3EFC5C 004EFC5C 0000028E */  lw         $2, 0x0($16)
    /* 3EFC60 004EFC60 0800BFDF */  ld         $31, 0x8($29)
    /* 3EFC64 004EFC64 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFC68 004EFC68 0800E003 */  jr         $31
    /* 3EFC6C 004EFC6C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004efc20, 0x50
