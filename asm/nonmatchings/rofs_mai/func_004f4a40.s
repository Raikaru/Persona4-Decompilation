.section .text
.set noat
.set noreorder
glabel func_004f4a40
    /* 3F4A40 004F4A40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F4A44 004F4A44 0000B0FF */  sd         $16, 0x0($29)
    /* 3F4A48 004F4A48 2D80A000 */  daddu      $16, $5, $0
    /* 3F4A4C 004F4A4C 0800BFFF */  sd         $31, 0x8($29)
    /* 3F4A50 004F4A50 0B000016 */  bnez       $16, .L004F4A80
    /* 3F4A54 004F4A54 B1060524 */   addiu     $5, $0, 0x6B1
    /* 3F4A58 004F4A58 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4A5C 004F4A5C 7600063C */  lui        $6, %hi(D_0075D870)
    /* 3F4A60 004F4A60 0000B0DF */  ld         $16, 0x0($29)
    /* 3F4A64 004F4A64 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4A68 004F4A68 0800BFDF */  ld         $31, 0x8($29)
    /* 3F4A6C 004F4A6C 70D8C624 */  addiu      $6, $6, %lo(D_0075D870)
    /* 3F4A70 004F4A70 2D380000 */  daddu      $7, $0, $0
    /* 3F4A74 004F4A74 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F4A78 004F4A78 F0D41308 */  j          func_004f53c0
    /* 3F4A7C 004F4A7C 1000BD27 */   addiu     $29, $29, 0x10
  .L004F4A80:
    /* 3F4A80 004F4A80 A0CB130C */  jal        func_004f2e80
    /* 3F4A84 004F4A84 01000524 */   addiu     $5, $0, 0x1
    /* 3F4A88 004F4A88 2D184000 */  daddu      $3, $2, $0
    /* 3F4A8C 004F4A8C 2D100000 */  daddu      $2, $0, $0
    /* 3F4A90 004F4A90 05006014 */  bnez       $3, .L004F4AA8
    /* 3F4A94 004F4A94 16006424 */   addiu     $4, $3, 0x16
    /* 3F4A98 004F4A98 040000AE */  sw         $0, 0x4($16)
    /* 3F4A9C 004F4A9C 97FF0224 */  addiu      $2, $0, -0x69
    /* 3F4AA0 004F4AA0 04000010 */  b          .L004F4AB4
    /* 3F4AA4 004F4AA4 000000AE */   sw        $0, 0x0($16)
  .L004F4AA8:
    /* 3F4AA8 004F4AA8 0000638C */  lw         $3, 0x0($3)
    /* 3F4AAC 004F4AAC 000004AE */  sw         $4, 0x0($16)
    /* 3F4AB0 004F4AB0 040003AE */  sw         $3, 0x4($16)
  .L004F4AB4:
    /* 3F4AB4 004F4AB4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F4AB8 004F4AB8 0800BFDF */  ld         $31, 0x8($29)
    /* 3F4ABC 004F4ABC 0800E003 */  jr         $31
    /* 3F4AC0 004F4AC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F4AC4 004F4AC4 00000000 */  nop
.size func_004f4a40, 0x88
