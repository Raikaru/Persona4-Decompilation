.section .text
.set noat
.set noreorder
glabel func_004d3f08
    /* 3D3F08 004D3F08 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D3F0C 004D3F0C 7200023C */  lui        $2, %hi(D_007188C0)
    /* 3D3F10 004D3F10 1800BFFF */  sd         $31, 0x18($29)
    /* 3D3F14 004D3F14 0000B0FF */  sd         $16, 0x0($29)
    /* 3D3F18 004D3F18 C0885024 */  addiu      $16, $2, %lo(D_007188C0)
    /* 3D3F1C 004D3F1C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D3F20 004D3F20 0F001124 */  addiu      $17, $0, 0xF
    /* 3D3F24 004D3F24 1000B2FF */  sd         $18, 0x10($29)
    /* 3D3F28 004D3F28 01001224 */  addiu      $18, $0, 0x1
    /* 3D3F2C 004D3F2C 00000000 */  nop
  .L004D3F30:
    /* 3D3F30 004D3F30 00000282 */  lb         $2, 0x0($16)
    /* 3D3F34 004D3F34 04005254 */  bnel       $2, $18, .L004D3F48
    /* 3D3F38 004D3F38 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3D3F3C 004D3F3C 424F130C */  jal        func_004d3d08
    /* 3D3F40 004D3F40 2D200002 */   daddu     $4, $16, $0
    /* 3D3F44 004D3F44 FFFF3126 */  addiu      $17, $17, -0x1
  .L004D3F48:
    /* 3D3F48 004D3F48 F9FF2106 */  bgez       $17, .L004D3F30
    /* 3D3F4C 004D3F4C C8001026 */   addiu     $16, $16, 0xC8
    /* 3D3F50 004D3F50 0000B0DF */  ld         $16, 0x0($29)
    /* 3D3F54 004D3F54 0800B1DF */  ld         $17, 0x8($29)
    /* 3D3F58 004D3F58 1000B2DF */  ld         $18, 0x10($29)
    /* 3D3F5C 004D3F5C 1800BFDF */  ld         $31, 0x18($29)
    /* 3D3F60 004D3F60 0800E003 */  jr         $31
    /* 3D3F64 004D3F64 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d3f08, 0x60
