.section .text
.set noat
.set noreorder
glabel func_004cacc0
    /* 3CACC0 004CACC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CACC4 004CACC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CACC8 004CACC8 2D808000 */  daddu      $16, $4, $0
    /* 3CACCC 004CACCC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CACD0 004CACD0 2D88A000 */  daddu      $17, $5, $0
    /* 3CACD4 004CACD4 1000B2FF */  sd         $18, 0x10($29)
    /* 3CACD8 004CACD8 1800BFFF */  sd         $31, 0x18($29)
    /* 3CACDC 004CACDC 3615130C */  jal        func_004c54d8
    /* 3CACE0 004CACE0 2D90C000 */   daddu     $18, $6, $0
    /* 3CACE4 004CACE4 2D200002 */  daddu      $4, $16, $0
    /* 3CACE8 004CACE8 2D282002 */  daddu      $5, $17, $0
    /* 3CACEC 004CACEC 442B130C */  jal        func_004cad10
    /* 3CACF0 004CACF0 2D304002 */   daddu     $6, $18, $0
    /* 3CACF4 004CACF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3CACF8 004CACF8 0800B1DF */  ld         $17, 0x8($29)
    /* 3CACFC 004CACFC 1000B2DF */  ld         $18, 0x10($29)
    /* 3CAD00 004CAD00 1800BFDF */  ld         $31, 0x18($29)
    /* 3CAD04 004CAD04 38151308 */  j          func_004c54e0
    /* 3CAD08 004CAD08 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CAD0C 004CAD0C 00000000 */  nop
.size func_004cacc0, 0x50
