.section .text
.set noat
.set noreorder
glabel func_004e59a8
    /* 3E59A8 004E59A8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E59AC 004E59AC 0000B0FF */  sd         $16, 0x0($29)
    /* 3E59B0 004E59B0 0800B1FF */  sd         $17, 0x8($29)
    /* 3E59B4 004E59B4 0F001124 */  addiu      $17, $0, 0xF
    /* 3E59B8 004E59B8 1000B2FF */  sd         $18, 0x10($29)
    /* 3E59BC 004E59BC 1800BFFF */  sd         $31, 0x18($29)
    /* 3E59C0 004E59C0 14B5130C */  jal        func_004ed450
    /* 3E59C4 004E59C4 01001224 */   addiu     $18, $0, 0x1
    /* 3E59C8 004E59C8 7300023C */  lui        $2, %hi(D_007324B0)
    /* 3E59CC 004E59CC B0245024 */  addiu      $16, $2, %lo(D_007324B0)
  .L004E59D0:
    /* 3E59D0 004E59D0 00000282 */  lb         $2, 0x0($16)
    /* 3E59D4 004E59D4 04005254 */  bnel       $2, $18, .L004E59E8
    /* 3E59D8 004E59D8 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3E59DC 004E59DC 7295130C */  jal        func_004e55c8
    /* 3E59E0 004E59E0 2D200002 */   daddu     $4, $16, $0
    /* 3E59E4 004E59E4 FFFF3126 */  addiu      $17, $17, -0x1
  .L004E59E8:
    /* 3E59E8 004E59E8 F9FF2106 */  bgez       $17, .L004E59D0
    /* 3E59EC 004E59EC 44001026 */   addiu     $16, $16, 0x44
    /* 3E59F0 004E59F0 0000B0DF */  ld         $16, 0x0($29)
    /* 3E59F4 004E59F4 0800B1DF */  ld         $17, 0x8($29)
    /* 3E59F8 004E59F8 1000B2DF */  ld         $18, 0x10($29)
    /* 3E59FC 004E59FC 1800BFDF */  ld         $31, 0x18($29)
    /* 3E5A00 004E5A00 1AB51308 */  j          func_004ed468
    /* 3E5A04 004E5A04 2000BD27 */   addiu     $29, $29, 0x20
.size func_004e59a8, 0x60
