.section .text
.set noat
.set noreorder
glabel func_004ecdc8
    /* 3ECDC8 004ECDC8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECDCC 004ECDCC E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ECDD0 004ECDD0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECDD4 004ECDD4 01000424 */  addiu      $4, $0, 0x1
    /* 3ECDD8 004ECDD8 0000B0FF */  sd         $16, 0x0($29)
    /* 3ECDDC 004ECDDC 0800B1FF */  sd         $17, 0x8($29)
    /* 3ECDE0 004ECDE0 1000B2FF */  sd         $18, 0x10($29)
    /* 3ECDE4 004ECDE4 05006414 */  bne        $3, $4, .L004ECDFC
    /* 3ECDE8 004ECDE8 1800BFFF */   sd        $31, 0x18($29)
    /* 3ECDEC 004ECDEC 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECDF0 004ECDF0 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECDF4 004ECDF4 18006018 */  blez       $3, .L004ECE58
    /* 3ECDF8 004ECDF8 0000B0DF */   ld        $16, 0x0($29)
  .L004ECDFC:
    /* 3ECDFC 004ECDFC EEB4130C */  jal        func_004ed3b8
    /* 3ECE00 004ECE00 01001224 */   addiu     $18, $0, 0x1
    /* 3ECE04 004ECE04 7400023C */  lui        $2, %hi(D_0073CBA0)
    /* 3ECE08 004ECE08 A0CB5024 */  addiu      $16, $2, %lo(D_0073CBA0)
    /* 3ECE0C 004ECE0C 0F001124 */  addiu      $17, $0, 0xF
  .L004ECE10:
    /* 3ECE10 004ECE10 00000282 */  lb         $2, 0x0($16)
    /* 3ECE14 004ECE14 04005254 */  bnel       $2, $18, .L004ECE28
    /* 3ECE18 004ECE18 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3ECE1C 004ECE1C 02B3130C */  jal        func_004ecc08
    /* 3ECE20 004ECE20 2D200002 */   daddu     $4, $16, $0
    /* 3ECE24 004ECE24 FFFF3126 */  addiu      $17, $17, -0x1
  .L004ECE28:
    /* 3ECE28 004ECE28 F9FF2106 */  bgez       $17, .L004ECE10
    /* 3ECE2C 004ECE2C 64001026 */   addiu     $16, $16, 0x64
    /* 3ECE30 004ECE30 F4B4130C */  jal        func_004ed3d0
    /* 3ECE34 004ECE34 00000000 */   nop
    /* 3ECE38 004ECE38 7493130C */  jal        func_004e4dd0
    /* 3ECE3C 004ECE3C 00000000 */   nop
    /* 3ECE40 004ECE40 0000B0DF */  ld         $16, 0x0($29)
    /* 3ECE44 004ECE44 0800B1DF */  ld         $17, 0x8($29)
    /* 3ECE48 004ECE48 1000B2DF */  ld         $18, 0x10($29)
    /* 3ECE4C 004ECE4C 1800BFDF */  ld         $31, 0x18($29)
    /* 3ECE50 004ECE50 68C01308 */  j          func_004f01a0
    /* 3ECE54 004ECE54 2000BD27 */   addiu     $29, $29, 0x20
  .L004ECE58:
    /* 3ECE58 004ECE58 0800B1DF */  ld         $17, 0x8($29)
    /* 3ECE5C 004ECE5C 1000B2DF */  ld         $18, 0x10($29)
    /* 3ECE60 004ECE60 1800BFDF */  ld         $31, 0x18($29)
    /* 3ECE64 004ECE64 0800E003 */  jr         $31
    /* 3ECE68 004ECE68 2000BD27 */   addiu     $29, $29, 0x20
    /* 3ECE6C 004ECE6C 00000000 */  nop
.size func_004ecdc8, 0xa8
