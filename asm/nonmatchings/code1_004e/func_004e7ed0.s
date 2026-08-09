.section .text
.set noat
.set noreorder
glabel func_004e7ed0
    /* 3E7ED0 004E7ED0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E7ED4 004E7ED4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E7ED8 004E7ED8 2D808000 */  daddu      $16, $4, $0
    /* 3E7EDC 004E7EDC 1000B2FF */  sd         $18, 0x10($29)
    /* 3E7EE0 004E7EE0 2D900000 */  daddu      $18, $0, $0
    /* 3E7EE4 004E7EE4 0800B1FF */  sd         $17, 0x8($29)
    /* 3E7EE8 004E7EE8 1800B3FF */  sd         $19, 0x18($29)
    /* 3E7EEC 004E7EEC 2000B4FF */  sd         $20, 0x20($29)
    /* 3E7EF0 004E7EF0 0B000016 */  bnez       $16, .L004E7F20
    /* 3E7EF4 004E7EF4 2800BFFF */   sd        $31, 0x28($29)
    /* 3E7EF8 004E7EF8 7600053C */  lui        $5, %hi(D_0075B730)
    /* 3E7EFC 004E7EFC 0000B0DF */  ld         $16, 0x0($29)
    /* 3E7F00 004E7F00 0800B1DF */  ld         $17, 0x8($29)
    /* 3E7F04 004E7F04 30B7A524 */  addiu      $5, $5, %lo(D_0075B730)
    /* 3E7F08 004E7F08 1000B2DF */  ld         $18, 0x10($29)
    /* 3E7F0C 004E7F0C 1800B3DF */  ld         $19, 0x18($29)
    /* 3E7F10 004E7F10 2000B4DF */  ld         $20, 0x20($29)
    /* 3E7F14 004E7F14 2800BFDF */  ld         $31, 0x28($29)
    /* 3E7F18 004E7F18 169D1308 */  j          func_004e7458
    /* 3E7F1C 004E7F1C 3000BD27 */   addiu     $29, $29, 0x30
  .L004E7F20:
    /* 3E7F20 004E7F20 02000292 */  lbu        $2, 0x2($16)
    /* 3E7F24 004E7F24 0200422C */  sltiu      $2, $2, 0x2
    /* 3E7F28 004E7F28 1F004054 */  bnel       $2, $0, .L004E7FA8
    /* 3E7F2C 004E7F2C 0000B0DF */   ld        $16, 0x0($29)
    /* 3E7F30 004E7F30 2C00048E */  lw         $4, 0x2C($16)
    /* 3E7F34 004E7F34 03008010 */  beqz       $4, .L004E7F44
    /* 3E7F38 004E7F38 6300113C */   lui       $17, (0x63FFF6 >> 16)
    /* 3E7F3C 004E7F3C 048F130C */  jal        func_004e3c10
    /* 3E7F40 004E7F40 00000000 */   nop
  .L004E7F44:
    /* 3E7F44 004E7F44 02001324 */  addiu      $19, $0, 0x2
    /* 3E7F48 004E7F48 F6FF3136 */  ori        $17, $17, (0x63FFF6 & 0xFFFF)
    /* 3E7F4C 004E7F4C 04000010 */  b          .L004E7F60
    /* 3E7F50 004E7F50 7600143C */   lui       $20, %hi(D_0075B748)
    /* 3E7F54 004E7F54 00000000 */  nop
  .L004E7F58:
    /* 3E7F58 004E7F58 0A9D130C */  jal        func_004e7428
    /* 3E7F5C 004E7F5C 00000000 */   nop
  .L004E7F60:
    /* 3E7F60 004E7F60 6490130C */  jal        func_004e4190
    /* 3E7F64 004E7F64 00000000 */   nop
    /* 3E7F68 004E7F68 9A9D130C */  jal        func_004e7668
    /* 3E7F6C 004E7F6C 00000000 */   nop
    /* 3E7F70 004E7F70 F29F130C */  jal        func_004e7fc8
    /* 3E7F74 004E7F74 2D200002 */   daddu     $4, $16, $0
    /* 3E7F78 004E7F78 02000382 */  lb         $3, 0x2($16)
    /* 3E7F7C 004E7F7C 08007354 */  bnel       $3, $19, .L004E7FA0
    /* 3E7F80 004E7F80 280000AE */   sw        $0, 0x28($16)
    /* 3E7F84 004E7F84 01005226 */  addiu      $18, $18, 0x1
    /* 3E7F88 004E7F88 2A103202 */  slt        $2, $17, $18
    /* 3E7F8C 004E7F8C F2FF4010 */  beqz       $2, .L004E7F58
    /* 3E7F90 004E7F90 00000000 */   nop
    /* 3E7F94 004E7F94 FC34130C */  jal        func_004cd3f0
    /* 3E7F98 004E7F98 48B78426 */   addiu     $4, $20, %lo(D_0075B748)
    /* 3E7F9C 004E7F9C 280000AE */  sw         $0, 0x28($16)
  .L004E7FA0:
    /* 3E7FA0 004E7FA0 020000A2 */  sb         $0, 0x2($16)
    /* 3E7FA4 004E7FA4 0000B0DF */  ld         $16, 0x0($29)
  .L004E7FA8:
    /* 3E7FA8 004E7FA8 0800B1DF */  ld         $17, 0x8($29)
    /* 3E7FAC 004E7FAC 1000B2DF */  ld         $18, 0x10($29)
    /* 3E7FB0 004E7FB0 1800B3DF */  ld         $19, 0x18($29)
    /* 3E7FB4 004E7FB4 2000B4DF */  ld         $20, 0x20($29)
    /* 3E7FB8 004E7FB8 2800BFDF */  ld         $31, 0x28($29)
    /* 3E7FBC 004E7FBC 0800E003 */  jr         $31
    /* 3E7FC0 004E7FC0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3E7FC4 004E7FC4 00000000 */  nop
.size func_004e7ed0, 0xf8
