.section .text
.set noat
.set noreorder
glabel func_004dfc38
    /* 3DFC38 004DFC38 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DFC3C 004DFC3C 7300023C */  lui        $2, %hi(D_0072ACC8)
    /* 3DFC40 004DFC40 1800BFFF */  sd         $31, 0x18($29)
    /* 3DFC44 004DFC44 0000B0FF */  sd         $16, 0x0($29)
    /* 3DFC48 004DFC48 C8AC5024 */  addiu      $16, $2, %lo(D_0072ACC8)
    /* 3DFC4C 004DFC4C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DFC50 004DFC50 03001124 */  addiu      $17, $0, 0x3
    /* 3DFC54 004DFC54 1000B2FF */  sd         $18, 0x10($29)
    /* 3DFC58 004DFC58 01001224 */  addiu      $18, $0, 0x1
    /* 3DFC5C 004DFC5C 00000000 */  nop
  .L004DFC60:
    /* 3DFC60 004DFC60 00000282 */  lb         $2, 0x0($16)
    /* 3DFC64 004DFC64 04005254 */  bnel       $2, $18, .L004DFC78
    /* 3DFC68 004DFC68 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3DFC6C 004DFC6C 007E130C */  jal        func_004df800
    /* 3DFC70 004DFC70 2D200002 */   daddu     $4, $16, $0
    /* 3DFC74 004DFC74 FFFF3126 */  addiu      $17, $17, -0x1
  .L004DFC78:
    /* 3DFC78 004DFC78 F9FF2106 */  bgez       $17, .L004DFC60
    /* 3DFC7C 004DFC7C 6C021026 */   addiu     $16, $16, 0x26C
    /* 3DFC80 004DFC80 0000B0DF */  ld         $16, 0x0($29)
    /* 3DFC84 004DFC84 0800B1DF */  ld         $17, 0x8($29)
    /* 3DFC88 004DFC88 1000B2DF */  ld         $18, 0x10($29)
    /* 3DFC8C 004DFC8C 1800BFDF */  ld         $31, 0x18($29)
    /* 3DFC90 004DFC90 0800E003 */  jr         $31
    /* 3DFC94 004DFC94 2000BD27 */   addiu     $29, $29, 0x20
.size func_004dfc38, 0x60
