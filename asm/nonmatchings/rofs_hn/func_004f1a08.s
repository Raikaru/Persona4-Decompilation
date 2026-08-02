.section .text
.set noat
.set noreorder
glabel func_004f1a08
    /* 3F1A08 004F1A08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1A0C 004F1A0C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F1A10 004F1A10 0800BFFF */  sd         $31, 0x8($29)
    /* 3F1A14 004F1A14 28D5130C */  jal        func_004f54a0
    /* 3F1A18 004F1A18 2D808000 */   daddu     $16, $4, $0
    /* 3F1A1C 004F1A1C 7600043C */  lui        $4, %hi(D_0075D408)
    /* 3F1A20 004F1A20 7600063C */  lui        $6, %hi(D_0075D428)
    /* 3F1A24 004F1A24 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1A28 004F1A28 28D4C624 */  addiu      $6, $6, %lo(D_0075D428)
    /* 3F1A2C 004F1A2C 5C010524 */  addiu      $5, $0, 0x15C
    /* 3F1A30 004F1A30 2D380000 */  daddu      $7, $0, $0
    /* 3F1A34 004F1A34 9BFF0824 */  addiu      $8, $0, -0x65
    /* 3F1A38 004F1A38 05000016 */  bnez       $16, .L004F1A50
    /* 3F1A3C 004F1A3C 01000324 */   addiu     $3, $0, 0x1
    /* 3F1A40 004F1A40 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1A44 004F1A44 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1A48 004F1A48 F0D41308 */  j          func_004f53c0
    /* 3F1A4C 004F1A4C 1000BD27 */   addiu     $29, $29, 0x10
  .L004F1A50:
    /* 3F1A50 004F1A50 34000286 */  lh         $2, 0x34($16)
    /* 3F1A54 004F1A54 0C004310 */  beq        $2, $3, .L004F1A88
    /* 3F1A58 004F1A58 7600043C */   lui       $4, %hi(D_0075D408)
    /* 3F1A5C 004F1A5C 7600063C */  lui        $6, %hi(D_0075D428)
    /* 3F1A60 004F1A60 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1A64 004F1A64 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1A68 004F1A68 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1A6C 004F1A6C 28D4C624 */  addiu      $6, $6, %lo(D_0075D428)
    /* 3F1A70 004F1A70 5F010524 */  addiu      $5, $0, 0x15F
    /* 3F1A74 004F1A74 2D380000 */  daddu      $7, $0, $0
    /* 3F1A78 004F1A78 9BFF0824 */  addiu      $8, $0, -0x65
    /* 3F1A7C 004F1A7C F0D41308 */  j          func_004f53c0
    /* 3F1A80 004F1A80 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1A84 004F1A84 00000000 */  nop
  .L004F1A88:
    /* 3F1A88 004F1A88 1400028E */  lw         $2, 0x14($16)
    /* 3F1A8C 004F1A8C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1A90 004F1A90 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1A94 004F1A94 0800E003 */  jr         $31
    /* 3F1A98 004F1A98 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1A9C 004F1A9C 00000000 */  nop
.size func_004f1a08, 0x98
