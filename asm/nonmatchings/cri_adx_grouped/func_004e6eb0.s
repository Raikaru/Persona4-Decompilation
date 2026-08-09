.section .text
.set noat
.set noreorder
glabel func_004e6eb0
    /* 3E6EB0 004E6EB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E6EB4 004E6EB4 1800B1FF */  sd         $17, 0x18($29)
    /* 3E6EB8 004E6EB8 2D888000 */  daddu      $17, $4, $0
    /* 3E6EBC 004E6EBC 7600043C */  lui        $4, %hi(D_0075B320)
    /* 3E6EC0 004E6EC0 1000B0FF */  sd         $16, 0x10($29)
    /* 3E6EC4 004E6EC4 20B38424 */  addiu      $4, $4, %lo(D_0075B320)
    /* 3E6EC8 004E6EC8 2D80A000 */  daddu      $16, $5, $0
    /* 3E6ECC 004E6ECC 2000BFFF */  sd         $31, 0x20($29)
    /* 3E6ED0 004E6ED0 BA09110C */  jal        func_004426e8
    /* 3E6ED4 004E6ED4 2D282002 */   daddu     $5, $17, $0
    /* 3E6ED8 004E6ED8 2D202002 */  daddu      $4, $17, $0
    /* 3E6EDC 004E6EDC 0A004014 */  bnez       $2, .L004E6F08
    /* 3E6EE0 004E6EE0 2E000524 */   addiu     $5, $0, 0x2E
    /* 3E6EE4 004E6EE4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3E6EE8 004E6EE8 7600043C */  lui        $4, %hi(D_0075B328)
    /* 3E6EEC 004E6EEC 040002AE */  sw         $2, 0x4($16)
    /* 3E6EF0 004E6EF0 28B38424 */  addiu      $4, $4, %lo(D_0075B328)
    /* 3E6EF4 004E6EF4 FC34130C */  jal        func_004cd3f0
    /* 3E6EF8 004E6EF8 000000AE */   sw        $0, 0x0($16)
    /* 3E6EFC 004E6EFC 1E000010 */  b          .L004E6F78
    /* 3E6F00 004E6F00 01000224 */   addiu     $2, $0, 0x1
    /* 3E6F04 004E6F04 00000000 */  nop
  .L004E6F08:
    /* 3E6F08 004E6F08 6C9B130C */  jal        func_004e6db0
    /* 3E6F0C 004E6F0C 00000000 */   nop
    /* 3E6F10 004E6F10 7300033C */  lui        $3, %hi(D_00733DB0)
    /* 3E6F14 004E6F14 01000724 */  addiu      $7, $0, 0x1
    /* 3E6F18 004E6F18 B03D6324 */  addiu      $3, $3, %lo(D_00733DB0)
    /* 3E6F1C 004E6F1C 2D202002 */  daddu      $4, $17, $0
    /* 3E6F20 004E6F20 2D28A003 */  daddu      $5, $29, $0
    /* 3E6F24 004E6F24 0A004714 */  bne        $2, $7, .L004E6F50
    /* 3E6F28 004E6F28 0400A627 */   addiu     $6, $29, 0x4
    /* 3E6F2C 004E6F2C 7C9B130C */  jal        func_004e6df0
    /* 3E6F30 004E6F30 00000000 */   nop
    /* 3E6F34 004E6F34 2D100000 */  daddu      $2, $0, $0
    /* 3E6F38 004E6F38 0400A38F */  lw         $3, 0x4($29)
    /* 3E6F3C 004E6F3C 0000A48F */  lw         $4, 0x0($29)
    /* 3E6F40 004E6F40 C01A0300 */  sll        $3, $3, 11
    /* 3E6F44 004E6F44 040003AE */  sw         $3, 0x4($16)
    /* 3E6F48 004E6F48 0B000010 */  b          .L004E6F78
    /* 3E6F4C 004E6F4C 000004AE */   sw        $4, 0x0($16)
  .L004E6F50:
    /* 3E6F50 004E6F50 000000AE */  sw         $0, 0x0($16)
    /* 3E6F54 004E6F54 040000AE */  sw         $0, 0x4($16)
    /* 3E6F58 004E6F58 0000628C */  lw         $2, 0x0($3)
    /* 3E6F5C 004E6F5C 05004010 */  beqz       $2, .L004E6F74
    /* 3E6F60 004E6F60 2D304000 */   daddu     $6, $2, $0
    /* 3E6F64 004E6F64 0400678C */  lw         $7, 0x4($3)
    /* 3E6F68 004E6F68 2D200002 */  daddu      $4, $16, $0
    /* 3E6F6C 004E6F6C 309B130C */  jal        func_004e6cc0
    /* 3E6F70 004E6F70 2D282002 */   daddu     $5, $17, $0
  .L004E6F74:
    /* 3E6F74 004E6F74 2D100000 */  daddu      $2, $0, $0
  .L004E6F78:
    /* 3E6F78 004E6F78 1000B0DF */  ld         $16, 0x10($29)
    /* 3E6F7C 004E6F7C 1800B1DF */  ld         $17, 0x18($29)
    /* 3E6F80 004E6F80 2000BFDF */  ld         $31, 0x20($29)
    /* 3E6F84 004E6F84 0800E003 */  jr         $31
    /* 3E6F88 004E6F88 3000BD27 */   addiu     $29, $29, 0x30
    /* 3E6F8C 004E6F8C 00000000 */  nop
.size func_004e6eb0, 0xe0
