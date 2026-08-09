.section .text
.set noat
.set noreorder
glabel func_004d8c18
    /* 3D8C18 004D8C18 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D8C1C 004D8C1C 7200023C */  lui        $2, %hi(D_00724ED0)
    /* 3D8C20 004D8C20 1800BFFF */  sd         $31, 0x18($29)
    /* 3D8C24 004D8C24 0000B0FF */  sd         $16, 0x0($29)
    /* 3D8C28 004D8C28 D04E5024 */  addiu      $16, $2, %lo(D_00724ED0)
    /* 3D8C2C 004D8C2C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D8C30 004D8C30 0F001124 */  addiu      $17, $0, 0xF
    /* 3D8C34 004D8C34 1000B2FF */  sd         $18, 0x10($29)
    /* 3D8C38 004D8C38 01001224 */  addiu      $18, $0, 0x1
    /* 3D8C3C 004D8C3C 00000000 */  nop
  .L004D8C40:
    /* 3D8C40 004D8C40 0000028E */  lw         $2, 0x0($16)
    /* 3D8C44 004D8C44 04005254 */  bnel       $2, $18, .L004D8C58
    /* 3D8C48 004D8C48 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3D8C4C 004D8C4C C862130C */  jal        func_004d8b20
    /* 3D8C50 004D8C50 2D200002 */   daddu     $4, $16, $0
    /* 3D8C54 004D8C54 FFFF3126 */  addiu      $17, $17, -0x1
  .L004D8C58:
    /* 3D8C58 004D8C58 F9FF2106 */  bgez       $17, .L004D8C40
    /* 3D8C5C 004D8C5C 3C001026 */   addiu     $16, $16, 0x3C
    /* 3D8C60 004D8C60 0000B0DF */  ld         $16, 0x0($29)
    /* 3D8C64 004D8C64 0800B1DF */  ld         $17, 0x8($29)
    /* 3D8C68 004D8C68 1000B2DF */  ld         $18, 0x10($29)
    /* 3D8C6C 004D8C6C 1800BFDF */  ld         $31, 0x18($29)
    /* 3D8C70 004D8C70 0800E003 */  jr         $31
    /* 3D8C74 004D8C74 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d8c18, 0x60
