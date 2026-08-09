.section .text
.set noat
.set noreorder
glabel func_004e49e8
    /* 3E49E8 004E49E8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E49EC 004E49EC 0000B0FF */  sd         $16, 0x0($29)
    /* 3E49F0 004E49F0 2D808000 */  daddu      $16, $4, $0
    /* 3E49F4 004E49F4 0800B1FF */  sd         $17, 0x8($29)
    /* 3E49F8 004E49F8 2D88A000 */  daddu      $17, $5, $0
    /* 3E49FC 004E49FC 1000B2FF */  sd         $18, 0x10($29)
    /* 3E4A00 004E4A00 1800BFFF */  sd         $31, 0x18($29)
    /* 3E4A04 004E4A04 C091130C */  jal        func_004e4700
    /* 3E4A08 004E4A08 2D90C000 */   daddu     $18, $6, $0
    /* 3E4A0C 004E4A0C 2D200002 */  daddu      $4, $16, $0
    /* 3E4A10 004E4A10 2D282002 */  daddu      $5, $17, $0
    /* 3E4A14 004E4A14 CE9C100C */  jal        sceRead
    /* 3E4A18 004E4A18 2D304002 */   daddu     $6, $18, $0
    /* 3E4A1C 004E4A1C 7600043C */  lui        $4, %hi(D_0075ADA0)
    /* 3E4A20 004E4A20 2D804000 */  daddu      $16, $2, $0
    /* 3E4A24 004E4A24 A0AD8424 */  addiu      $4, $4, %lo(D_0075ADA0)
    /* 3E4A28 004E4A28 03000106 */  bgez       $16, .L004E4A38
    /* 3E4A2C 004E4A2C 2D280002 */   daddu     $5, $16, $0
    /* 3E4A30 004E4A30 3291100C */  jal        func_004244c8
    /* 3E4A34 004E4A34 00000000 */   nop
  .L004E4A38:
    /* 3E4A38 004E4A38 CE91130C */  jal        func_004e4738
    /* 3E4A3C 004E4A3C 00000000 */   nop
    /* 3E4A40 004E4A40 2D100002 */  daddu      $2, $16, $0
    /* 3E4A44 004E4A44 0800B1DF */  ld         $17, 0x8($29)
    /* 3E4A48 004E4A48 0000B0DF */  ld         $16, 0x0($29)
    /* 3E4A4C 004E4A4C 1000B2DF */  ld         $18, 0x10($29)
    /* 3E4A50 004E4A50 1800BFDF */  ld         $31, 0x18($29)
    /* 3E4A54 004E4A54 0800E003 */  jr         $31
    /* 3E4A58 004E4A58 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E4A5C 004E4A5C 00000000 */  nop
.size func_004e49e8, 0x78
