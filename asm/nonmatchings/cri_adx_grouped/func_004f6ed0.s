.section .text
.set noat
.set noreorder
glabel func_004f6ed0
    /* 3F6ED0 004F6ED0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F6ED4 004F6ED4 70070624 */  addiu      $6, $0, 0x770
    /* 3F6ED8 004F6ED8 0800B1FF */  sd         $17, 0x8($29)
    /* 3F6EDC 004F6EDC 2D88A000 */  daddu      $17, $5, $0
    /* 3F6EE0 004F6EE0 0000B0FF */  sd         $16, 0x0($29)
    /* 3F6EE4 004F6EE4 2D808000 */  daddu      $16, $4, $0
    /* 3F6EE8 004F6EE8 2D280000 */  daddu      $5, $0, $0
    /* 3F6EEC 004F6EEC 1000BFFF */  sd         $31, 0x10($29)
    /* 3F6EF0 004F6EF0 72FE100C */  jal        func_0043f9c8
    /* 3F6EF4 004F6EF4 2D202002 */   daddu     $4, $17, $0
    /* 3F6EF8 004F6EF8 0000058E */  lw         $5, 0x0($16)
    /* 3F6EFC 004F6EFC 4943073C */  lui        $7, (0x43494D46 >> 16)
    /* 3F6F00 004F6F00 00000692 */  lbu        $6, 0x0($16)
    /* 3F6F04 004F6F04 5643083C */  lui        $8, (0x43564D48 >> 16)
    /* 3F6F08 004F6F08 02120500 */  srl        $2, $5, 8
    /* 3F6F0C 004F6F0C 022E0500 */  srl        $5, $5, 24
    /* 3F6F10 004F6F10 2D184000 */  daddu      $3, $2, $0
    /* 3F6F14 004F6F14 FF004230 */  andi       $2, $2, 0xFF
    /* 3F6F18 004F6F18 00360600 */  sll        $6, $6, 24
    /* 3F6F1C 004F6F1C 00FF6330 */  andi       $3, $3, 0xFF00
    /* 3F6F20 004F6F20 00140200 */  sll        $2, $2, 16
    /* 3F6F24 004F6F24 2530C500 */  or         $6, $6, $5
    /* 3F6F28 004F6F28 25186200 */  or         $3, $3, $2
    /* 3F6F2C 004F6F2C 464DE734 */  ori        $7, $7, (0x43494D46 & 0xFFFF)
    /* 3F6F30 004F6F30 2530C300 */  or         $6, $6, $3
    /* 3F6F34 004F6F34 2D200002 */  daddu      $4, $16, $0
    /* 3F6F38 004F6F38 2D282002 */  daddu      $5, $17, $0
    /* 3F6F3C 004F6F3C 0600C714 */  bne        $6, $7, .L004F6F58
    /* 3F6F40 004F6F40 484D0835 */   ori       $8, $8, (0x43564D48 & 0xFFFF)
    /* 3F6F44 004F6F44 C8DC130C */  jal        func_004f7320
    /* 3F6F48 004F6F48 00000000 */   nop
    /* 3F6F4C 004F6F4C 0B000010 */  b          .L004F6F7C
    /* 3F6F50 004F6F50 0000B0DF */   ld        $16, 0x0($29)
    /* 3F6F54 004F6F54 00000000 */  nop
  .L004F6F58:
    /* 3F6F58 004F6F58 0700C854 */  bnel       $6, $8, .L004F6F78
    /* 3F6F5C 004F6F5C FEFF0224 */   addiu     $2, $0, -0x2
    /* 3F6F60 004F6F60 2D200002 */  daddu      $4, $16, $0
    /* 3F6F64 004F6F64 2EDB130C */  jal        func_004f6cb8
    /* 3F6F68 004F6F68 2D282002 */   daddu     $5, $17, $0
    /* 3F6F6C 004F6F6C 03000010 */  b          .L004F6F7C
    /* 3F6F70 004F6F70 0000B0DF */   ld        $16, 0x0($29)
    /* 3F6F74 004F6F74 00000000 */  nop
  .L004F6F78:
    /* 3F6F78 004F6F78 0000B0DF */  ld         $16, 0x0($29)
  .L004F6F7C:
    /* 3F6F7C 004F6F7C 0800B1DF */  ld         $17, 0x8($29)
    /* 3F6F80 004F6F80 1000BFDF */  ld         $31, 0x10($29)
    /* 3F6F84 004F6F84 0800E003 */  jr         $31
    /* 3F6F88 004F6F88 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F6F8C 004F6F8C 00000000 */  nop
.size func_004f6ed0, 0xc0
