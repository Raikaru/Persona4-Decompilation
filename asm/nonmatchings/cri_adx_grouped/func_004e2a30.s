.section .text
.set noat
.set noreorder
glabel func_004e2a30
    /* 3E2A30 004E2A30 70FDBD27 */  addiu      $29, $29, -0x290
    /* 3E2A34 004E2A34 6002B0FF */  sd         $16, 0x260($29)
    /* 3E2A38 004E2A38 2D808000 */  daddu      $16, $4, $0
    /* 3E2A3C 004E2A3C 6802B1FF */  sd         $17, 0x268($29)
    /* 3E2A40 004E2A40 3001B127 */  addiu      $17, $29, 0x130
    /* 3E2A44 004E2A44 7002B2FF */  sd         $18, 0x270($29)
    /* 3E2A48 004E2A48 2D90A000 */  daddu      $18, $5, $0
    /* 3E2A4C 004E2A4C 7802B3FF */  sd         $19, 0x278($29)
    /* 3E2A50 004E2A50 2D98C000 */  daddu      $19, $6, $0
    /* 3E2A54 004E2A54 2D20A003 */  daddu      $4, $29, $0
    /* 3E2A58 004E2A58 2D282002 */  daddu      $5, $17, $0
    /* 3E2A5C 004E2A5C 8002B4FF */  sd         $20, 0x280($29)
    /* 3E2A60 004E2A60 8802BFFF */  sd         $31, 0x288($29)
    /* 3E2A64 004E2A64 9E87130C */  jal        func_004e1e78
    /* 3E2A68 004E2A68 2D300002 */   daddu     $6, $16, $0
    /* 3E2A6C 004E2A6C 0000A283 */  lb         $2, 0x0($29)
    /* 3E2A70 004E2A70 2DA00000 */  daddu      $20, $0, $0
    /* 3E2A74 004E2A74 0C004014 */  bnez       $2, .L004E2AA8
    /* 3E2A78 004E2A78 2D20A003 */   daddu     $4, $29, $0
    /* 3E2A7C 004E2A7C F087130C */  jal        func_004e1fc0
    /* 3E2A80 004E2A80 00000000 */   nop
    /* 3E2A84 004E2A84 7600043C */  lui        $4, %hi(D_0075A420)
    /* 3E2A88 004E2A88 0000A283 */  lb         $2, 0x0($29)
    /* 3E2A8C 004E2A8C 06004014 */  bnez       $2, .L004E2AA8
    /* 3E2A90 004E2A90 20A48424 */   addiu     $4, $4, %lo(D_0075A420)
    /* 3E2A94 004E2A94 6A85130C */  jal        func_004e15a8
    /* 3E2A98 004E2A98 00000000 */   nop
    /* 3E2A9C 004E2A9C 11000010 */  b          .L004E2AE4
    /* 3E2AA0 004E2AA0 2D100000 */   daddu     $2, $0, $0
    /* 3E2AA4 004E2AA4 00000000 */  nop
  .L004E2AA8:
    /* 3E2AA8 004E2AA8 2D20A003 */  daddu      $4, $29, $0
    /* 3E2AAC 004E2AAC E48C130C */  jal        func_004e3390
    /* 3E2AB0 004E2AB0 2D282002 */   daddu     $5, $17, $0
    /* 3E2AB4 004E2AB4 4286130C */  jal        func_004e1908
    /* 3E2AB8 004E2AB8 2D20A003 */   daddu     $4, $29, $0
    /* 3E2ABC 004E2ABC 09004050 */  beql       $2, $0, .L004E2AE4
    /* 3E2AC0 004E2AC0 2D108002 */   daddu     $2, $20, $0
    /* 3E2AC4 004E2AC4 4800428C */  lw         $2, 0x48($2)
    /* 3E2AC8 004E2AC8 05004010 */  beqz       $2, .L004E2AE0
    /* 3E2ACC 004E2ACC 2D200002 */   daddu     $4, $16, $0
    /* 3E2AD0 004E2AD0 2D284002 */  daddu      $5, $18, $0
    /* 3E2AD4 004E2AD4 09F84000 */  jalr       $2
    /* 3E2AD8 004E2AD8 2D306002 */   daddu     $6, $19, $0
    /* 3E2ADC 004E2ADC 2DA04000 */  daddu      $20, $2, $0
  .L004E2AE0:
    /* 3E2AE0 004E2AE0 2D108002 */  daddu      $2, $20, $0
  .L004E2AE4:
    /* 3E2AE4 004E2AE4 6002B0DF */  ld         $16, 0x260($29)
    /* 3E2AE8 004E2AE8 6802B1DF */  ld         $17, 0x268($29)
    /* 3E2AEC 004E2AEC 7002B2DF */  ld         $18, 0x270($29)
    /* 3E2AF0 004E2AF0 7802B3DF */  ld         $19, 0x278($29)
    /* 3E2AF4 004E2AF4 8002B4DF */  ld         $20, 0x280($29)
    /* 3E2AF8 004E2AF8 8802BFDF */  ld         $31, 0x288($29)
    /* 3E2AFC 004E2AFC 0800E003 */  jr         $31
    /* 3E2B00 004E2B00 9002BD27 */   addiu     $29, $29, 0x290
    /* 3E2B04 004E2B04 00000000 */  nop
.size func_004e2a30, 0xd8
