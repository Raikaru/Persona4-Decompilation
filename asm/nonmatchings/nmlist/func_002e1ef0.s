.section .text
.set noat
.set noreorder
glabel func_002e1ef0
    /* 1E1EF0 002E1EF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1E1EF4 002E1EF4 1000BFFF */  sd         $31, 0x10($29)
    /* 1E1EF8 002E1EF8 0000B07F */  sq         $16, 0x0($29)
    /* 1E1EFC 002E1EFC 2D808000 */  daddu      $16, $4, $0
    /* 1E1F00 002E1F00 04000526 */  addiu      $5, $16, 0x4
    /* 1E1F04 002E1F04 BC880B0C */  jal        func_002e22f0
    /* 1E1F08 002E1F08 00000000 */   nop
    /* 1E1F0C 002E1F0C 06000016 */  bnez       $16, .L002E1F28
    /* 1E1F10 002E1F10 00000000 */   nop
    /* 1E1F14 002E1F14 6400043C */  lui        $4, %hi(D_0063FC38)
    /* 1E1F18 002E1F18 38FC8424 */  addiu      $4, $4, %lo(D_0063FC38)
    /* 1E1F1C 002E1F1C 49000524 */  addiu      $5, $0, 0x49
    /* 1E1F20 002E1F20 CCB5110C */  jal        func_0046d730
    /* 1E1F24 002E1F24 00000000 */   nop
  .L002E1F28:
    /* 1E1F28 002E1F28 2D200002 */  daddu      $4, $16, $0
    /* 1E1F2C 002E1F2C 2D280000 */  daddu      $5, $0, $0
    /* 1E1F30 002E1F30 2000068E */  lw         $6, 0x20($16)
    /* 1E1F34 002E1F34 72FE100C */  jal        func_0043f9c8
    /* 1E1F38 002E1F38 00000000 */   nop
    /* 1E1F3C 002E1F3C 2D200002 */  daddu      $4, $16, $0
    /* 1E1F40 002E1F40 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1E1F44 002E1F44 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1E1F48 002E1F48 09F84000 */  jalr       $2
    /* 1E1F4C 002E1F4C 00000000 */   nop
    /* 1E1F50 002E1F50 1000BFDF */  ld         $31, 0x10($29)
    /* 1E1F54 002E1F54 0000B07B */  lq         $16, 0x0($29)
    /* 1E1F58 002E1F58 2000BD27 */  addiu      $29, $29, 0x20
    /* 1E1F5C 002E1F5C 0800E003 */  jr         $31
    /* 1E1F60 002E1F60 00000000 */   nop
    /* 1E1F64 002E1F64 00000000 */  nop
    /* 1E1F68 002E1F68 00000000 */  nop
    /* 1E1F6C 002E1F6C 00000000 */  nop
.size func_002e1ef0, 0x80
