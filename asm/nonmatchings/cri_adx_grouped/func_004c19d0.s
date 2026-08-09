.section .text
.set noat
.set noreorder
glabel func_004c19d0
    /* 3C19D0 004C19D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C19D4 004C19D4 7100023C */  lui        $2, %hi(D_007146F8)
    /* 3C19D8 004C19D8 1800BFFF */  sd         $31, 0x18($29)
    /* 3C19DC 004C19DC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C19E0 004C19E0 F8465024 */  addiu      $16, $2, %lo(D_007146F8)
    /* 3C19E4 004C19E4 0800B1FF */  sd         $17, 0x8($29)
    /* 3C19E8 004C19E8 0F001124 */  addiu      $17, $0, 0xF
    /* 3C19EC 004C19EC 1000B2FF */  sd         $18, 0x10($29)
    /* 3C19F0 004C19F0 01001224 */  addiu      $18, $0, 0x1
    /* 3C19F4 004C19F4 00000000 */  nop
  .L004C19F8:
    /* 3C19F8 004C19F8 00000282 */  lb         $2, 0x0($16)
    /* 3C19FC 004C19FC 04005254 */  bnel       $2, $18, .L004C1A10
    /* 3C1A00 004C1A00 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3C1A04 004C1A04 6A06130C */  jal        func_004c19a8
    /* 3C1A08 004C1A08 2D200002 */   daddu     $4, $16, $0
    /* 3C1A0C 004C1A0C FFFF3126 */  addiu      $17, $17, -0x1
  .L004C1A10:
    /* 3C1A10 004C1A10 F9FF2106 */  bgez       $17, .L004C19F8
    /* 3C1A14 004C1A14 30001026 */   addiu     $16, $16, 0x30
    /* 3C1A18 004C1A18 0000B0DF */  ld         $16, 0x0($29)
    /* 3C1A1C 004C1A1C 0800B1DF */  ld         $17, 0x8($29)
    /* 3C1A20 004C1A20 1000B2DF */  ld         $18, 0x10($29)
    /* 3C1A24 004C1A24 1800BFDF */  ld         $31, 0x18($29)
    /* 3C1A28 004C1A28 0800E003 */  jr         $31
    /* 3C1A2C 004C1A2C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c19d0, 0x60
