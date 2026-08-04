.section .text
.set noat
.set noreorder
glabel func_003e7ee0
    /* 2E7EE0 003E7EE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E7EE4 003E7EE4 01000224 */  addiu      $2, $0, 0x1
    /* 2E7EE8 003E7EE8 1000BFFF */  sd         $31, 0x10($29)
    /* 2E7EEC 003E7EEC 0000B07F */  sq         $16, 0x0($29)
    /* 2E7EF0 003E7EF0 1400838C */  lw         $3, 0x14($4)
    /* 2E7EF4 003E7EF4 07006214 */  bne        $3, $2, .L003E7F14
    /* 2E7EF8 003E7EF8 2D808000 */   daddu     $16, $4, $0
    /* 2E7EFC 003E7EFC A09D0F0C */  jal        func_003e7680
    /* 2E7F00 003E7F00 00000000 */   nop
    /* 2E7F04 003E7F04 9C9B0F0C */  jal        func_003e6e70
    /* 2E7F08 003E7F08 2D200002 */   daddu     $4, $16, $0
    /* 2E7F0C 003E7F0C 06000010 */  b          .L003E7F28
    /* 2E7F10 003E7F10 0C010426 */   addiu     $4, $16, 0x10C
  .L003E7F14:
    /* 2E7F14 003E7F14 549F0F0C */  jal        func_003e7d50
    /* 2E7F18 003E7F18 00000000 */   nop
    /* 2E7F1C 003E7F1C 049E0F0C */  jal        func_003e7810
    /* 2E7F20 003E7F20 2D200002 */   daddu     $4, $16, $0
    /* 2E7F24 003E7F24 0C010426 */  addiu      $4, $16, 0x10C
  .L003E7F28:
    /* 2E7F28 003E7F28 24010526 */  addiu      $5, $16, 0x124
    /* 2E7F2C 003E7F2C 44940F0C */  jal        func_003e5110
    /* 2E7F30 003E7F30 08000624 */   addiu     $6, $0, 0x8
    /* 2E7F34 003E7F34 2D100002 */  daddu      $2, $16, $0
    /* 2E7F38 003E7F38 1000BFDF */  ld         $31, 0x10($29)
    /* 2E7F3C 003E7F3C 0000B07B */  lq         $16, 0x0($29)
    /* 2E7F40 003E7F40 0800E003 */  jr         $31
    /* 2E7F44 003E7F44 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E7F48 003E7F48 00000000 */  nop
    /* 2E7F4C 003E7F4C 00000000 */  nop
.size func_003e7ee0, 0x70
