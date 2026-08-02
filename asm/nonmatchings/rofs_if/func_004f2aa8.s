.section .text
.set noat
.set noreorder
glabel func_004f2aa8
    /* 3F2AA8 004F2AA8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F2AAC 004F2AAC 0000B0FF */  sd         $16, 0x0($29)
    /* 3F2AB0 004F2AB0 2D808000 */  daddu      $16, $4, $0
    /* 3F2AB4 004F2AB4 0800B1FF */  sd         $17, 0x8($29)
    /* 3F2AB8 004F2AB8 1000BFFF */  sd         $31, 0x10($29)
    /* 3F2ABC 004F2ABC 28D5130C */  jal        func_004f54a0
    /* 3F2AC0 004F2AC0 2D88A000 */   daddu     $17, $5, $0
    /* 3F2AC4 004F2AC4 7400023C */  lui        $2, %hi(D_00743A48)
    /* 3F2AC8 004F2AC8 7600063C */  lui        $6, %hi(D_0075D5E8)
    /* 3F2ACC 004F2ACC 483A428C */  lw         $2, %lo(D_00743A48)($2)
    /* 3F2AD0 004F2AD0 2D200002 */  daddu      $4, $16, $0
    /* 3F2AD4 004F2AD4 2D282002 */  daddu      $5, $17, $0
    /* 3F2AD8 004F2AD8 E8D5C624 */  addiu      $6, $6, %lo(D_0075D5E8)
    /* 3F2ADC 004F2ADC 2D380000 */  daddu      $7, $0, $0
    /* 3F2AE0 004F2AE0 09004010 */  beqz       $2, .L004F2B08
    /* 3F2AE4 004F2AE4 35FF0824 */   addiu     $8, $0, -0xCB
    /* 3F2AE8 004F2AE8 5C00428C */  lw         $2, 0x5C($2)
    /* 3F2AEC 004F2AEC 09F84000 */  jalr       $2
    /* 3F2AF0 004F2AF0 00000000 */   nop
    /* 3F2AF4 004F2AF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2AF8 004F2AF8 0800B1DF */  ld         $17, 0x8($29)
    /* 3F2AFC 004F2AFC 1000BFDF */  ld         $31, 0x10($29)
    /* 3F2B00 004F2B00 0800E003 */  jr         $31
    /* 3F2B04 004F2B04 2000BD27 */   addiu     $29, $29, 0x20
  .L004F2B08:
    /* 3F2B08 004F2B08 7600043C */  lui        $4, %hi(D_0075D488)
    /* 3F2B0C 004F2B0C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2B10 004F2B10 0800B1DF */  ld         $17, 0x8($29)
    /* 3F2B14 004F2B14 88D48424 */  addiu      $4, $4, %lo(D_0075D488)
    /* 3F2B18 004F2B18 1000BFDF */  ld         $31, 0x10($29)
    /* 3F2B1C 004F2B1C 05020524 */  addiu      $5, $0, 0x205
    /* 3F2B20 004F2B20 F0D41308 */  j          func_004f53c0
    /* 3F2B24 004F2B24 2000BD27 */   addiu     $29, $29, 0x20
.size func_004f2aa8, 0x80
