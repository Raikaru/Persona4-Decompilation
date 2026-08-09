.section .text
.set noat
.set noreorder
glabel func_004d6d18
    /* 3D6D18 004D6D18 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D6D1C 004D6D1C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6D20 004D6D20 2D808000 */  daddu      $16, $4, $0
    /* 3D6D24 004D6D24 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6D28 004D6D28 2D88A000 */  daddu      $17, $5, $0
    /* 3D6D2C 004D6D2C 1000B2FF */  sd         $18, 0x10($29)
    /* 3D6D30 004D6D30 1800BFFF */  sd         $31, 0x18($29)
    /* 3D6D34 004D6D34 3615130C */  jal        func_004c54d8
    /* 3D6D38 004D6D38 2D90C000 */   daddu     $18, $6, $0
    /* 3D6D3C 004D6D3C 2D200002 */  daddu      $4, $16, $0
    /* 3D6D40 004D6D40 2D282002 */  daddu      $5, $17, $0
    /* 3D6D44 004D6D44 5A5B130C */  jal        func_004d6d68
    /* 3D6D48 004D6D48 2D304002 */   daddu     $6, $18, $0
    /* 3D6D4C 004D6D4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6D50 004D6D50 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6D54 004D6D54 1000B2DF */  ld         $18, 0x10($29)
    /* 3D6D58 004D6D58 1800BFDF */  ld         $31, 0x18($29)
    /* 3D6D5C 004D6D5C 38151308 */  j          func_004c54e0
    /* 3D6D60 004D6D60 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D6D64 004D6D64 00000000 */  nop
.size func_004d6d18, 0x50
