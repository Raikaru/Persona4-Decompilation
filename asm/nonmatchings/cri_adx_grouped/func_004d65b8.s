.section .text
.set noat
.set noreorder
glabel func_004d65b8
    /* 3D65B8 004D65B8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D65BC 004D65BC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D65C0 004D65C0 2D808000 */  daddu      $16, $4, $0
    /* 3D65C4 004D65C4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D65C8 004D65C8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D65CC 004D65CC 3615130C */  jal        func_004c54d8
    /* 3D65D0 004D65D0 2D88A000 */   daddu     $17, $5, $0
    /* 3D65D4 004D65D4 2D200002 */  daddu      $4, $16, $0
    /* 3D65D8 004D65D8 7E59130C */  jal        func_004d65f8
    /* 3D65DC 004D65DC 2D282002 */   daddu     $5, $17, $0
    /* 3D65E0 004D65E0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D65E4 004D65E4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D65E8 004D65E8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D65EC 004D65EC 38151308 */  j          func_004c54e0
    /* 3D65F0 004D65F0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D65F4 004D65F4 00000000 */  nop
.size func_004d65b8, 0x40
