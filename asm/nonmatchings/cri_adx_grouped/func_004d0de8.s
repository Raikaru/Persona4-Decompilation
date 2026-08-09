.section .text
.set noat
.set noreorder
glabel func_004d0de8
    /* 3D0DE8 004D0DE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D0DEC 004D0DEC 7200023C */  lui        $2, %hi(D_00721D78)
    /* 3D0DF0 004D0DF0 0000B0FF */  sd         $16, 0x0($29)
    /* 3D0DF4 004D0DF4 781D5024 */  addiu      $16, $2, %lo(D_00721D78)
    /* 3D0DF8 004D0DF8 0000038E */  lw         $3, 0x0($16)
    /* 3D0DFC 004D0DFC 08006014 */  bnez       $3, .L004D0E20
    /* 3D0E00 004D0E00 0800BFFF */   sd        $31, 0x8($29)
    /* 3D0E04 004D0E04 303C130C */  jal        func_004cf0c0
    /* 3D0E08 004D0E08 00000000 */   nop
    /* 3D0E0C 004D0E0C 7200043C */  lui        $4, %hi(D_00721D88)
    /* 3D0E10 004D0E10 881D8424 */  addiu      $4, $4, %lo(D_00721D88)
    /* 3D0E14 004D0E14 2D280000 */  daddu      $5, $0, $0
    /* 3D0E18 004D0E18 72FE100C */  jal        func_0043f9c8
    /* 3D0E1C 004D0E1C C0170624 */   addiu     $6, $0, 0x17C0
  .L004D0E20:
    /* 3D0E20 004D0E20 0000028E */  lw         $2, 0x0($16)
    /* 3D0E24 004D0E24 0800BFDF */  ld         $31, 0x8($29)
    /* 3D0E28 004D0E28 01004224 */  addiu      $2, $2, 0x1
    /* 3D0E2C 004D0E2C 000002AE */  sw         $2, 0x0($16)
    /* 3D0E30 004D0E30 0000B0DF */  ld         $16, 0x0($29)
    /* 3D0E34 004D0E34 0800E003 */  jr         $31
    /* 3D0E38 004D0E38 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D0E3C 004D0E3C 00000000 */  nop
.size func_004d0de8, 0x58
