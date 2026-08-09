.section .text
.set noat
.set noreorder
glabel func_004f8ed8
    /* 3F8ED8 004F8ED8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3F8EDC 004F8EDC 1000B0FF */  sd         $16, 0x10($29)
    /* 3F8EE0 004F8EE0 3800BFFF */  sd         $31, 0x38($29)
    /* 3F8EE4 004F8EE4 1800B1FF */  sd         $17, 0x18($29)
    /* 3F8EE8 004F8EE8 2D880000 */  daddu      $17, $0, $0
    /* 3F8EEC 004F8EEC 2000B2FF */  sd         $18, 0x20($29)
    /* 3F8EF0 004F8EF0 2D908000 */  daddu      $18, $4, $0
    /* 3F8EF4 004F8EF4 2800B3FF */  sd         $19, 0x28($29)
    /* 3F8EF8 004F8EF8 0400B327 */  addiu      $19, $29, 0x4
    /* 3F8EFC 004F8EFC 3000B4FF */  sd         $20, 0x30($29)
    /* 3F8F00 004F8F00 0200B427 */  addiu      $20, $29, 0x2
    /* 3F8F04 004F8F04 21805102 */  addu       $16, $18, $17
  .L004F8F08:
    /* 3F8F08 004F8F08 02003126 */  addiu      $17, $17, 0x2
    /* 3F8F0C 004F8F0C 2D200002 */  daddu      $4, $16, $0
    /* 3F8F10 004F8F10 02000524 */  addiu      $5, $0, 0x2
    /* 3F8F14 004F8F14 2D30A003 */  daddu      $6, $29, $0
    /* 3F8F18 004F8F18 2D388002 */  daddu      $7, $20, $0
    /* 3F8F1C 004F8F1C C6E2130C */  jal        func_004f8b18
    /* 3F8F20 004F8F20 2D406002 */   daddu     $8, $19, $0
    /* 3F8F24 004F8F24 2D280002 */  daddu      $5, $16, $0
    /* 3F8F28 004F8F28 58E3130C */  jal        func_004f8d60
    /* 3F8F2C 004F8F2C 0000A497 */   lhu       $4, 0x0($29)
    /* 3F8F30 004F8F30 0800222A */  slti       $2, $17, 0x8
    /* 3F8F34 004F8F34 F4FF4014 */  bnez       $2, .L004F8F08
    /* 3F8F38 004F8F38 21805102 */   addu      $16, $18, $17
    /* 3F8F3C 004F8F3C 1000B0DF */  ld         $16, 0x10($29)
    /* 3F8F40 004F8F40 1800B1DF */  ld         $17, 0x18($29)
    /* 3F8F44 004F8F44 2000B2DF */  ld         $18, 0x20($29)
    /* 3F8F48 004F8F48 2800B3DF */  ld         $19, 0x28($29)
    /* 3F8F4C 004F8F4C 3000B4DF */  ld         $20, 0x30($29)
    /* 3F8F50 004F8F50 3800BFDF */  ld         $31, 0x38($29)
    /* 3F8F54 004F8F54 0800E003 */  jr         $31
    /* 3F8F58 004F8F58 4000BD27 */   addiu     $29, $29, 0x40
    /* 3F8F5C 004F8F5C 00000000 */  nop
.size func_004f8ed8, 0x88
