.section .text
.set noat
.set noreorder
glabel func_004f2a28
    /* 3F2A28 004F2A28 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F2A2C 004F2A2C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F2A30 004F2A30 2D808000 */  daddu      $16, $4, $0
    /* 3F2A34 004F2A34 0800B1FF */  sd         $17, 0x8($29)
    /* 3F2A38 004F2A38 1000BFFF */  sd         $31, 0x10($29)
    /* 3F2A3C 004F2A3C 28D5130C */  jal        func_004f54a0
    /* 3F2A40 004F2A40 2D88A000 */   daddu     $17, $5, $0
    /* 3F2A44 004F2A44 7400023C */  lui        $2, %hi(D_00743A48)
    /* 3F2A48 004F2A48 7600063C */  lui        $6, %hi(D_0075D5D0)
    /* 3F2A4C 004F2A4C 483A428C */  lw         $2, %lo(D_00743A48)($2)
    /* 3F2A50 004F2A50 2D200002 */  daddu      $4, $16, $0
    /* 3F2A54 004F2A54 2D282002 */  daddu      $5, $17, $0
    /* 3F2A58 004F2A58 D0D5C624 */  addiu      $6, $6, %lo(D_0075D5D0)
    /* 3F2A5C 004F2A5C 2D380000 */  daddu      $7, $0, $0
    /* 3F2A60 004F2A60 09004010 */  beqz       $2, .L004F2A88
    /* 3F2A64 004F2A64 35FF0824 */   addiu     $8, $0, -0xCB
    /* 3F2A68 004F2A68 5400428C */  lw         $2, 0x54($2)
    /* 3F2A6C 004F2A6C 09F84000 */  jalr       $2
    /* 3F2A70 004F2A70 00000000 */   nop
    /* 3F2A74 004F2A74 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2A78 004F2A78 0800B1DF */  ld         $17, 0x8($29)
    /* 3F2A7C 004F2A7C 1000BFDF */  ld         $31, 0x10($29)
    /* 3F2A80 004F2A80 0800E003 */  jr         $31
    /* 3F2A84 004F2A84 2000BD27 */   addiu     $29, $29, 0x20
  .L004F2A88:
    /* 3F2A88 004F2A88 7600043C */  lui        $4, %hi(D_0075D488)
    /* 3F2A8C 004F2A8C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2A90 004F2A90 0800B1DF */  ld         $17, 0x8($29)
    /* 3F2A94 004F2A94 88D48424 */  addiu      $4, $4, %lo(D_0075D488)
    /* 3F2A98 004F2A98 1000BFDF */  ld         $31, 0x10($29)
    /* 3F2A9C 004F2A9C F6010524 */  addiu      $5, $0, 0x1F6
    /* 3F2AA0 004F2AA0 F0D41308 */  j          func_004f53c0
    /* 3F2AA4 004F2AA4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004f2a28, 0x80
