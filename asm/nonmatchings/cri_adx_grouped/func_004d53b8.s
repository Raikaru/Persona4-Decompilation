.section .text
.set noat
.set noreorder
glabel func_004d53b8
    /* 3D53B8 004D53B8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D53BC 004D53BC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D53C0 004D53C0 2D808000 */  daddu      $16, $4, $0
    /* 3D53C4 004D53C4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D53C8 004D53C8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D53CC 004D53CC 3615130C */  jal        func_004c54d8
    /* 3D53D0 004D53D0 2D88A000 */   daddu     $17, $5, $0
    /* 3D53D4 004D53D4 2D200002 */  daddu      $4, $16, $0
    /* 3D53D8 004D53D8 0C55130C */  jal        func_004d5430
    /* 3D53DC 004D53DC 2D282002 */   daddu     $5, $17, $0
    /* 3D53E0 004D53E0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D53E4 004D53E4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D53E8 004D53E8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D53EC 004D53EC 38151308 */  j          func_004c54e0
    /* 3D53F0 004D53F0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D53F4 004D53F4 00000000 */  nop
.size func_004d53b8, 0x40
