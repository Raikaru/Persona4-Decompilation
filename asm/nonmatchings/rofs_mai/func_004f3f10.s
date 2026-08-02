.section .text
.set noat
.set noreorder
glabel func_004f3f10
    /* 3F3F10 004F3F10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F3F14 004F3F14 0000B0FF */  sd         $16, 0x0($29)
    /* 3F3F18 004F3F18 2D808000 */  daddu      $16, $4, $0
    /* 3F3F1C 004F3F1C 0C000016 */  bnez       $16, .L004F3F50
    /* 3F3F20 004F3F20 0800BFFF */   sd        $31, 0x8($29)
    /* 3F3F24 004F3F24 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3F28 004F3F28 7600063C */  lui        $6, %hi(D_0075D7A8)
    /* 3F3F2C 004F3F2C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F3F30 004F3F30 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3F34 004F3F34 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3F38 004F3F38 A8D7C624 */  addiu      $6, $6, %lo(D_0075D7A8)
    /* 3F3F3C 004F3F3C B3040524 */  addiu      $5, $0, 0x4B3
    /* 3F3F40 004F3F40 2D380000 */  daddu      $7, $0, $0
    /* 3F3F44 004F3F44 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F3F48 004F3F48 F0D41308 */  j          func_004f53c0
    /* 3F3F4C 004F3F4C 1000BD27 */   addiu     $29, $29, 0x10
  .L004F3F50:
    /* 3F3F50 004F3F50 7600053C */  lui        $5, %hi(D_0075D6C0)
    /* 3F3F54 004F3F54 BA09110C */  jal        func_004426e8
    /* 3F3F58 004F3F58 C0D6A524 */   addiu     $5, $5, %lo(D_0075D6C0)
    /* 3F3F5C 004F3F5C 7600063C */  lui        $6, %hi(D_0075D7A8)
    /* 3F3F60 004F3F60 2D200002 */  daddu      $4, $16, $0
    /* 3F3F64 004F3F64 A8D7C624 */  addiu      $6, $6, %lo(D_0075D7A8)
    /* 3F3F68 004F3F68 2D280000 */  daddu      $5, $0, $0
    /* 3F3F6C 004F3F6C 2D380000 */  daddu      $7, $0, $0
    /* 3F3F70 004F3F70 09004014 */  bnez       $2, .L004F3F98
    /* 3F3F74 004F3F74 99FF0824 */   addiu     $8, $0, -0x67
    /* 3F3F78 004F3F78 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3F7C 004F3F7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F3F80 004F3F80 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3F84 004F3F84 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3F88 004F3F88 B8040524 */  addiu      $5, $0, 0x4B8
    /* 3F3F8C 004F3F8C F0D41308 */  j          func_004f53c0
    /* 3F3F90 004F3F90 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F3F94 004F3F94 00000000 */  nop
  .L004F3F98:
    /* 3F3F98 004F3F98 A0CB130C */  jal        func_004f2e80
    /* 3F3F9C 004F3F9C 00000000 */   nop
    /* 3F3FA0 004F3FA0 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3FA4 004F3FA4 2D484000 */  daddu      $9, $2, $0
    /* 3F3FA8 004F3FA8 2D100000 */  daddu      $2, $0, $0
    /* 3F3FAC 004F3FAC 7600063C */  lui        $6, %hi(D_0075D798)
    /* 3F3FB0 004F3FB0 2D380000 */  daddu      $7, $0, $0
    /* 3F3FB4 004F3FB4 98D7C624 */  addiu      $6, $6, %lo(D_0075D798)
    /* 3F3FB8 004F3FB8 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3FBC 004F3FBC 99FF0824 */  addiu      $8, $0, -0x67
    /* 3F3FC0 004F3FC0 05002015 */  bnez       $9, .L004F3FD8
    /* 3F3FC4 004F3FC4 BE040524 */   addiu     $5, $0, 0x4BE
    /* 3F3FC8 004F3FC8 0000B0DF */  ld         $16, 0x0($29)
    /* 3F3FCC 004F3FCC 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3FD0 004F3FD0 F0D41308 */  j          func_004f53c0
    /* 3F3FD4 004F3FD4 1000BD27 */   addiu     $29, $29, 0x10
  .L004F3FD8:
    /* 3F3FD8 004F3FD8 7400033C */  lui        $3, %hi(D_00743A50)
    /* 3F3FDC 004F3FDC 0000B0DF */  ld         $16, 0x0($29)
    /* 3F3FE0 004F3FE0 503A648C */  lw         $4, %lo(D_00743A50)($3)
    /* 3F3FE4 004F3FE4 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3FE8 004F3FE8 2C0089AC */  sw         $9, 0x2C($4)
    /* 3F3FEC 004F3FEC 0800E003 */  jr         $31
    /* 3F3FF0 004F3FF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F3FF4 004F3FF4 00000000 */  nop
.size func_004f3f10, 0xe8
