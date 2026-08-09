.section .text
.set noat
.set noreorder
glabel func_004caf88
    /* 3CAF88 004CAF88 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3CAF8C 004CAF8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CAF90 004CAF90 2D808000 */  daddu      $16, $4, $0
    /* 3CAF94 004CAF94 0800B1FF */  sd         $17, 0x8($29)
    /* 3CAF98 004CAF98 2D88A000 */  daddu      $17, $5, $0
    /* 3CAF9C 004CAF9C 1000B2FF */  sd         $18, 0x10($29)
    /* 3CAFA0 004CAFA0 2D90C000 */  daddu      $18, $6, $0
    /* 3CAFA4 004CAFA4 1800B3FF */  sd         $19, 0x18($29)
    /* 3CAFA8 004CAFA8 2000BFFF */  sd         $31, 0x20($29)
    /* 3CAFAC 004CAFAC 3615130C */  jal        func_004c54d8
    /* 3CAFB0 004CAFB0 2D98E000 */   daddu     $19, $7, $0
    /* 3CAFB4 004CAFB4 2D200002 */  daddu      $4, $16, $0
    /* 3CAFB8 004CAFB8 2D282002 */  daddu      $5, $17, $0
    /* 3CAFBC 004CAFBC 2D304002 */  daddu      $6, $18, $0
    /* 3CAFC0 004CAFC0 FA2B130C */  jal        func_004cafe8
    /* 3CAFC4 004CAFC4 2D386002 */   daddu     $7, $19, $0
    /* 3CAFC8 004CAFC8 0000B0DF */  ld         $16, 0x0($29)
    /* 3CAFCC 004CAFCC 0800B1DF */  ld         $17, 0x8($29)
    /* 3CAFD0 004CAFD0 1000B2DF */  ld         $18, 0x10($29)
    /* 3CAFD4 004CAFD4 1800B3DF */  ld         $19, 0x18($29)
    /* 3CAFD8 004CAFD8 2000BFDF */  ld         $31, 0x20($29)
    /* 3CAFDC 004CAFDC 38151308 */  j          func_004c54e0
    /* 3CAFE0 004CAFE0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3CAFE4 004CAFE4 00000000 */  nop
.size func_004caf88, 0x60
