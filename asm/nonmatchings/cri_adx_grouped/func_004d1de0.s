.section .text
.set noat
.set noreorder
glabel func_004d1de0
    /* 3D1DE0 004D1DE0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D1DE4 004D1DE4 1000B2FF */  sd         $18, 0x10($29)
    /* 3D1DE8 004D1DE8 2D900001 */  daddu      $18, $8, $0
    /* 3D1DEC 004D1DEC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1DF0 004D1DF0 2D808000 */  daddu      $16, $4, $0
    /* 3D1DF4 004D1DF4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D1DF8 004D1DF8 2D88E000 */  daddu      $17, $7, $0
    /* 3D1DFC 004D1DFC 1800B3FF */  sd         $19, 0x18($29)
    /* 3D1E00 004D1E00 2D98A000 */  daddu      $19, $5, $0
    /* 3D1E04 004D1E04 2000B4FF */  sd         $20, 0x20($29)
    /* 3D1E08 004D1E08 2800BFFF */  sd         $31, 0x28($29)
    /* 3D1E0C 004D1E0C 2046130C */  jal        func_004d1880
    /* 3D1E10 004D1E10 2DA0C000 */   daddu     $20, $6, $0
    /* 3D1E14 004D1E14 C01A1200 */  sll        $3, $18, 11
    /* 3D1E18 004D1E18 01000224 */  addiu      $2, $0, 0x1
    /* 3D1E1C 004D1E1C 0C0011AE */  sw         $17, 0xC($16)
    /* 3D1E20 004D1E20 140012AE */  sw         $18, 0x14($16)
    /* 3D1E24 004D1E24 500013AE */  sw         $19, 0x50($16)
    /* 3D1E28 004D1E28 540014AE */  sw         $20, 0x54($16)
    /* 3D1E2C 004D1E2C 450002A2 */  sb         $2, 0x45($16)
    /* 3D1E30 004D1E30 100003AE */  sw         $3, 0x10($16)
    /* 3D1E34 004D1E34 0800B1DF */  ld         $17, 0x8($29)
    /* 3D1E38 004D1E38 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1E3C 004D1E3C 1000B2DF */  ld         $18, 0x10($29)
    /* 3D1E40 004D1E40 1800B3DF */  ld         $19, 0x18($29)
    /* 3D1E44 004D1E44 2000B4DF */  ld         $20, 0x20($29)
    /* 3D1E48 004D1E48 2800BFDF */  ld         $31, 0x28($29)
    /* 3D1E4C 004D1E4C 26461308 */  j          func_004d1898
    /* 3D1E50 004D1E50 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D1E54 004D1E54 00000000 */  nop
.size func_004d1de0, 0x78
