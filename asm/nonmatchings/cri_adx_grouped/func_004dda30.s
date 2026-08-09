.section .text
.set noat
.set noreorder
glabel func_004dda30
    /* 3DDA30 004DDA30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DDA34 004DDA34 7300023C */  lui        $2, %hi(D_00729A38)
    /* 3DDA38 004DDA38 0000B0FF */  sd         $16, 0x0($29)
    /* 3DDA3C 004DDA3C 389A5024 */  addiu      $16, $2, %lo(D_00729A38)
    /* 3DDA40 004DDA40 0000028E */  lw         $2, 0x0($16)
    /* 3DDA44 004DDA44 01000324 */  addiu      $3, $0, 0x1
    /* 3DDA48 004DDA48 09004314 */  bne        $2, $3, .L004DDA70
    /* 3DDA4C 004DDA4C 0800BFFF */   sd        $31, 0x8($29)
    /* 3DDA50 004DDA50 7300043C */  lui        $4, %hi(D_00729A40)
    /* 3DDA54 004DDA54 2D280000 */  daddu      $5, $0, $0
    /* 3DDA58 004DDA58 409A8424 */  addiu      $4, $4, %lo(D_00729A40)
    /* 3DDA5C 004DDA5C 72FE100C */  jal        func_0043f9c8
    /* 3DDA60 004DDA60 40000624 */   addiu     $6, $0, 0x40
    /* 3DDA64 004DDA64 7067130C */  jal        func_004d9dc0
    /* 3DDA68 004DDA68 00000000 */   nop
    /* 3DDA6C 004DDA6C 0000028E */  lw         $2, 0x0($16)
  .L004DDA70:
    /* 3DDA70 004DDA70 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DDA74 004DDA74 0800BFDF */  ld         $31, 0x8($29)
    /* 3DDA78 004DDA78 000002AE */  sw         $2, 0x0($16)
    /* 3DDA7C 004DDA7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DDA80 004DDA80 0800E003 */  jr         $31
    /* 3DDA84 004DDA84 1000BD27 */   addiu     $29, $29, 0x10
.size func_004dda30, 0x58
