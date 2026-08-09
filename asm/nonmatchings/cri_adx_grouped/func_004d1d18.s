.section .text
.set noat
.set noreorder
glabel func_004d1d18
    /* 3D1D18 004D1D18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1D1C 004D1D1C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1D20 004D1D20 2D808000 */  daddu      $16, $4, $0
    /* 3D1D24 004D1D24 0E000012 */  beqz       $16, .L004D1D60
    /* 3D1D28 004D1D28 0800BFFF */   sd        $31, 0x8($29)
    /* 3D1D2C 004D1D2C B248130C */  jal        func_004d22c8
    /* 3D1D30 004D1D30 00000000 */   nop
    /* 3D1D34 004D1D34 DC47130C */  jal        func_004d1f70
    /* 3D1D38 004D1D38 2D200002 */   daddu     $4, $16, $0
    /* 3D1D3C 004D1D3C 000000A2 */  sb         $0, 0x0($16)
    /* 3D1D40 004D1D40 2D200002 */  daddu      $4, $16, $0
    /* 3D1D44 004D1D44 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1D48 004D1D48 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1D4C 004D1D4C 2D280000 */  daddu      $5, $0, $0
    /* 3D1D50 004D1D50 60000624 */  addiu      $6, $0, 0x60
    /* 3D1D54 004D1D54 72FE1008 */  j          func_0043f9c8
    /* 3D1D58 004D1D58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D1D5C 004D1D5C 00000000 */  nop
  .L004D1D60:
    /* 3D1D60 004D1D60 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1D64 004D1D64 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1D68 004D1D68 0800E003 */  jr         $31
    /* 3D1D6C 004D1D6C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d1d18, 0x58
