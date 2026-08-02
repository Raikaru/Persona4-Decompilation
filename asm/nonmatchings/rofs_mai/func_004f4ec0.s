.section .text
.set noat
.set noreorder
glabel func_004f4ec0
    /* 3F4EC0 004F4EC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F4EC4 004F4EC4 0800B1FF */  sd         $17, 0x8($29)
    /* 3F4EC8 004F4EC8 2D88A000 */  daddu      $17, $5, $0
    /* 3F4ECC 004F4ECC 0000B0FF */  sd         $16, 0x0($29)
    /* 3F4ED0 004F4ED0 2D80C000 */  daddu      $16, $6, $0
    /* 3F4ED4 004F4ED4 1000BFFF */  sd         $31, 0x10($29)
    /* 3F4ED8 004F4ED8 0D002016 */  bnez       $17, .L004F4F10
    /* 3F4EDC 004F4EDC 68070524 */   addiu     $5, $0, 0x768
    /* 3F4EE0 004F4EE0 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4EE4 004F4EE4 7600063C */  lui        $6, %hi(D_0075D7E0)
    /* 3F4EE8 004F4EE8 0000B0DF */  ld         $16, 0x0($29)
    /* 3F4EEC 004F4EEC C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4EF0 004F4EF0 0800B1DF */  ld         $17, 0x8($29)
    /* 3F4EF4 004F4EF4 E0D7C624 */  addiu      $6, $6, %lo(D_0075D7E0)
    /* 3F4EF8 004F4EF8 1000BFDF */  ld         $31, 0x10($29)
    /* 3F4EFC 004F4EFC 2D380000 */  daddu      $7, $0, $0
    /* 3F4F00 004F4F00 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F4F04 004F4F04 F0D41308 */  j          func_004f53c0
    /* 3F4F08 004F4F08 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F4F0C 004F4F0C 00000000 */  nop
  .L004F4F10:
    /* 3F4F10 004F4F10 A0CB130C */  jal        func_004f2e80
    /* 3F4F14 004F4F14 01000524 */   addiu     $5, $0, 0x1
    /* 3F4F18 004F4F18 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4F1C 004F4F1C 7600063C */  lui        $6, %hi(D_0075D798)
    /* 3F4F20 004F4F20 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4F24 004F4F24 98D7C624 */  addiu      $6, $6, %lo(D_0075D798)
    /* 3F4F28 004F4F28 2D280002 */  daddu      $5, $16, $0
    /* 3F4F2C 004F4F2C 2D380000 */  daddu      $7, $0, $0
    /* 3F4F30 004F4F30 07004014 */  bnez       $2, .L004F4F50
    /* 3F4F34 004F4F34 97FF0824 */   addiu     $8, $0, -0x69
    /* 3F4F38 004F4F38 0000B0DF */  ld         $16, 0x0($29)
    /* 3F4F3C 004F4F3C 6E070524 */  addiu      $5, $0, 0x76E
    /* 3F4F40 004F4F40 0800B1DF */  ld         $17, 0x8($29)
    /* 3F4F44 004F4F44 1000BFDF */  ld         $31, 0x10($29)
    /* 3F4F48 004F4F48 F0D41308 */  j          func_004f53c0
    /* 3F4F4C 004F4F4C 2000BD27 */   addiu     $29, $29, 0x20
  .L004F4F50:
    /* 3F4F50 004F4F50 2D202002 */  daddu      $4, $17, $0
    /* 3F4F54 004F4F54 0800B1DF */  ld         $17, 0x8($29)
    /* 3F4F58 004F4F58 1000468C */  lw         $6, 0x10($2)
    /* 3F4F5C 004F4F5C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F4F60 004F4F60 1000BFDF */  ld         $31, 0x10($29)
    /* 3F4F64 004F4F64 86DF1308 */  j          func_004f7e18
    /* 3F4F68 004F4F68 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F4F6C 004F4F6C 00000000 */  nop
.size func_004f4ec0, 0xb0
