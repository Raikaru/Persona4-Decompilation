.section .text
.set noat
.set noreorder
glabel func_004de998
    /* 3DE998 004DE998 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DE99C 004DE99C 7300023C */  lui        $2, %hi(D_0072ACC8)
    /* 3DE9A0 004DE9A0 1800BFFF */  sd         $31, 0x18($29)
    /* 3DE9A4 004DE9A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3DE9A8 004DE9A8 C8AC5024 */  addiu      $16, $2, %lo(D_0072ACC8)
    /* 3DE9AC 004DE9AC 0800B1FF */  sd         $17, 0x8($29)
    /* 3DE9B0 004DE9B0 03001124 */  addiu      $17, $0, 0x3
    /* 3DE9B4 004DE9B4 1000B2FF */  sd         $18, 0x10($29)
    /* 3DE9B8 004DE9B8 01001224 */  addiu      $18, $0, 0x1
    /* 3DE9BC 004DE9BC 00000000 */  nop
  .L004DE9C0:
    /* 3DE9C0 004DE9C0 00000282 */  lb         $2, 0x0($16)
    /* 3DE9C4 004DE9C4 04005254 */  bnel       $2, $18, .L004DE9D8
    /* 3DE9C8 004DE9C8 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3DE9CC 004DE9CC 187A130C */  jal        func_004de860
    /* 3DE9D0 004DE9D0 2D200002 */   daddu     $4, $16, $0
    /* 3DE9D4 004DE9D4 FFFF3126 */  addiu      $17, $17, -0x1
  .L004DE9D8:
    /* 3DE9D8 004DE9D8 F9FF2106 */  bgez       $17, .L004DE9C0
    /* 3DE9DC 004DE9DC 6C021026 */   addiu     $16, $16, 0x26C
    /* 3DE9E0 004DE9E0 0000B0DF */  ld         $16, 0x0($29)
    /* 3DE9E4 004DE9E4 0800B1DF */  ld         $17, 0x8($29)
    /* 3DE9E8 004DE9E8 1000B2DF */  ld         $18, 0x10($29)
    /* 3DE9EC 004DE9EC 1800BFDF */  ld         $31, 0x18($29)
    /* 3DE9F0 004DE9F0 0800E003 */  jr         $31
    /* 3DE9F4 004DE9F4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004de998, 0x60
