.section .text
.set noat
.set noreorder
glabel func_004d2a48
    /* 3D2A48 004D2A48 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D2A4C 004D2A4C 1800B3FF */  sd         $19, 0x18($29)
    /* 3D2A50 004D2A50 7200133C */  lui        $19, %hi(D_00723F1C)
    /* 3D2A54 004D2A54 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2A58 004D2A58 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2A5C 004D2A5C 1000B2FF */  sd         $18, 0x10($29)
    /* 3D2A60 004D2A60 2000BFFF */  sd         $31, 0x20($29)
    /* 3D2A64 004D2A64 2C46130C */  jal        func_004d18b0
    /* 3D2A68 004D2A68 1C3F6426 */   addiu     $4, $19, %lo(D_00723F1C)
    /* 3D2A6C 004D2A6C 0E004010 */  beqz       $2, .L004D2AA8
    /* 3D2A70 004D2A70 7200023C */   lui       $2, %hi(D_00723F28)
    /* 3D2A74 004D2A74 01001224 */  addiu      $18, $0, 0x1
    /* 3D2A78 004D2A78 283F5024 */  addiu      $16, $2, %lo(D_00723F28)
    /* 3D2A7C 004D2A7C 27001124 */  addiu      $17, $0, 0x27
  .L004D2A80:
    /* 3D2A80 004D2A80 00000282 */  lb         $2, 0x0($16)
    /* 3D2A84 004D2A84 04005254 */  bnel       $2, $18, .L004D2A98
    /* 3D2A88 004D2A88 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3D2A8C 004D2A8C 104A130C */  jal        func_004d2840
    /* 3D2A90 004D2A90 2D200002 */   daddu     $4, $16, $0
    /* 3D2A94 004D2A94 FFFF3126 */  addiu      $17, $17, -0x1
  .L004D2A98:
    /* 3D2A98 004D2A98 F9FF2106 */  bgez       $17, .L004D2A80
    /* 3D2A9C 004D2A9C 60001026 */   addiu     $16, $16, 0x60
    /* 3D2AA0 004D2AA0 1C3F6226 */  addiu      $2, $19, %lo(D_00723F1C)
    /* 3D2AA4 004D2AA4 000040AC */  sw         $0, 0x0($2)
  .L004D2AA8:
    /* 3D2AA8 004D2AA8 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2AAC 004D2AAC 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2AB0 004D2AB0 1000B2DF */  ld         $18, 0x10($29)
    /* 3D2AB4 004D2AB4 1800B3DF */  ld         $19, 0x18($29)
    /* 3D2AB8 004D2AB8 2000BFDF */  ld         $31, 0x20($29)
    /* 3D2ABC 004D2ABC 0800E003 */  jr         $31
    /* 3D2AC0 004D2AC0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D2AC4 004D2AC4 00000000 */  nop
.size func_004d2a48, 0x80
