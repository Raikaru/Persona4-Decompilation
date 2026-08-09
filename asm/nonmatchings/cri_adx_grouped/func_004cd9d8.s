.section .text
.set noat
.set noreorder
glabel func_004cd9d8
    /* 3CD9D8 004CD9D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD9DC 004CD9DC 7200023C */  lui        $2, %hi(D_007212E0)
    /* 3CD9E0 004CD9E0 0000B0FF */  sd         $16, 0x0($29)
    /* 3CD9E4 004CD9E4 E0125024 */  addiu      $16, $2, %lo(D_007212E0)
    /* 3CD9E8 004CD9E8 0000038E */  lw         $3, 0x0($16)
    /* 3CD9EC 004CD9EC 08006014 */  bnez       $3, .L004CDA10
    /* 3CD9F0 004CD9F0 0800BFFF */   sd        $31, 0x8($29)
    /* 3CD9F4 004CD9F4 080D130C */  jal        func_004c3420
    /* 3CD9F8 004CD9F8 00000000 */   nop
    /* 3CD9FC 004CD9FC 7200043C */  lui        $4, %hi(D_007212E8)
    /* 3CDA00 004CDA00 E8128424 */  addiu      $4, $4, %lo(D_007212E8)
    /* 3CDA04 004CDA04 2D280000 */  daddu      $5, $0, $0
    /* 3CDA08 004CDA08 72FE100C */  jal        func_0043f9c8
    /* 3CDA0C 004CDA0C 800A0624 */   addiu     $6, $0, 0xA80
  .L004CDA10:
    /* 3CDA10 004CDA10 0000028E */  lw         $2, 0x0($16)
    /* 3CDA14 004CDA14 0800BFDF */  ld         $31, 0x8($29)
    /* 3CDA18 004CDA18 01004224 */  addiu      $2, $2, 0x1
    /* 3CDA1C 004CDA1C 000002AE */  sw         $2, 0x0($16)
    /* 3CDA20 004CDA20 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDA24 004CDA24 0800E003 */  jr         $31
    /* 3CDA28 004CDA28 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CDA2C 004CDA2C 00000000 */  nop
.size func_004cd9d8, 0x58
