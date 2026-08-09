.section .text
.set noat
.set noreorder
glabel func_004ceb90
    /* 3CEB90 004CEB90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CEB94 004CEB94 7200023C */  lui        $2, %hi(D_007212E8)
    /* 3CEB98 004CEB98 1800BFFF */  sd         $31, 0x18($29)
    /* 3CEB9C 004CEB9C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CEBA0 004CEBA0 E8125024 */  addiu      $16, $2, %lo(D_007212E8)
    /* 3CEBA4 004CEBA4 0800B1FF */  sd         $17, 0x8($29)
    /* 3CEBA8 004CEBA8 0F001124 */  addiu      $17, $0, 0xF
    /* 3CEBAC 004CEBAC 1000B2FF */  sd         $18, 0x10($29)
    /* 3CEBB0 004CEBB0 01001224 */  addiu      $18, $0, 0x1
    /* 3CEBB4 004CEBB4 00000000 */  nop
  .L004CEBB8:
    /* 3CEBB8 004CEBB8 00000282 */  lb         $2, 0x0($16)
    /* 3CEBBC 004CEBBC 04005254 */  bnel       $2, $18, .L004CEBD0
    /* 3CEBC0 004CEBC0 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3CEBC4 004CEBC4 163A130C */  jal        func_004ce858
    /* 3CEBC8 004CEBC8 2D200002 */   daddu     $4, $16, $0
    /* 3CEBCC 004CEBCC FFFF3126 */  addiu      $17, $17, -0x1
  .L004CEBD0:
    /* 3CEBD0 004CEBD0 F9FF2106 */  bgez       $17, .L004CEBB8
    /* 3CEBD4 004CEBD4 A8001026 */   addiu     $16, $16, 0xA8
    /* 3CEBD8 004CEBD8 0000B0DF */  ld         $16, 0x0($29)
    /* 3CEBDC 004CEBDC 0800B1DF */  ld         $17, 0x8($29)
    /* 3CEBE0 004CEBE0 1000B2DF */  ld         $18, 0x10($29)
    /* 3CEBE4 004CEBE4 1800BFDF */  ld         $31, 0x18($29)
    /* 3CEBE8 004CEBE8 0800E003 */  jr         $31
    /* 3CEBEC 004CEBEC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ceb90, 0x60
