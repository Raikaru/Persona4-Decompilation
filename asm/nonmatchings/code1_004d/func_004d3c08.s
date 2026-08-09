.section .text
.set noat
.set noreorder
glabel func_004d3c08
    /* 3D3C08 004D3C08 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D3C0C 004D3C0C 00FCA624 */  addiu      $6, $5, -0x400
    /* 3D3C10 004D3C10 0000B0FF */  sd         $16, 0x0($29)
    /* 3D3C14 004D3C14 2D808000 */  daddu      $16, $4, $0
    /* 3D3C18 004D3C18 00040526 */  addiu      $5, $16, 0x400
    /* 3D3C1C 004D3C1C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D3C20 004D3C20 1000BFFF */  sd         $31, 0x10($29)
    /* 3D3C24 004D3C24 2A4E130C */  jal        func_004d38a8
    /* 3D3C28 004D3C28 02000424 */   addiu     $4, $0, 0x2
    /* 3D3C2C 004D3C2C 2D884000 */  daddu      $17, $2, $0
    /* 3D3C30 004D3C30 05002012 */  beqz       $17, .L004D3C48
    /* 3D3C34 004D3C34 2D280002 */   daddu     $5, $16, $0
    /* 3D3C38 004D3C38 2D202002 */  daddu      $4, $17, $0
    /* 3D3C3C 004D3C3C 08AC130C */  jal        func_004eb020
    /* 3D3C40 004D3C40 00040624 */   addiu     $6, $0, 0x400
    /* 3D3C44 004D3C44 2D102002 */  daddu      $2, $17, $0
  .L004D3C48:
    /* 3D3C48 004D3C48 0000B0DF */  ld         $16, 0x0($29)
    /* 3D3C4C 004D3C4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3D3C50 004D3C50 1000BFDF */  ld         $31, 0x10($29)
    /* 3D3C54 004D3C54 0800E003 */  jr         $31
    /* 3D3C58 004D3C58 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D3C5C 004D3C5C 00000000 */  nop
.size func_004d3c08, 0x58
