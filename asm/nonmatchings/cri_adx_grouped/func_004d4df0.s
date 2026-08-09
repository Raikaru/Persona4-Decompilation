.section .text
.set noat
.set noreorder
glabel func_004d4df0
    /* 3D4DF0 004D4DF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D4DF4 004D4DF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4DF8 004D4DF8 2D808000 */  daddu      $16, $4, $0
    /* 3D4DFC 004D4DFC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D4E00 004D4E00 2D88A000 */  daddu      $17, $5, $0
    /* 3D4E04 004D4E04 1000B2FF */  sd         $18, 0x10($29)
    /* 3D4E08 004D4E08 1800BFFF */  sd         $31, 0x18($29)
    /* 3D4E0C 004D4E0C 3615130C */  jal        func_004c54d8
    /* 3D4E10 004D4E10 2D90C000 */   daddu     $18, $6, $0
    /* 3D4E14 004D4E14 2D200002 */  daddu      $4, $16, $0
    /* 3D4E18 004D4E18 2D282002 */  daddu      $5, $17, $0
    /* 3D4E1C 004D4E1C 9053130C */  jal        func_004d4e40
    /* 3D4E20 004D4E20 2D304002 */   daddu     $6, $18, $0
    /* 3D4E24 004D4E24 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4E28 004D4E28 0800B1DF */  ld         $17, 0x8($29)
    /* 3D4E2C 004D4E2C 1000B2DF */  ld         $18, 0x10($29)
    /* 3D4E30 004D4E30 1800BFDF */  ld         $31, 0x18($29)
    /* 3D4E34 004D4E34 38151308 */  j          func_004c54e0
    /* 3D4E38 004D4E38 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D4E3C 004D4E3C 00000000 */  nop
.size func_004d4df0, 0x50
