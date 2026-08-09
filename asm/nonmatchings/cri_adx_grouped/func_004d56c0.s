.section .text
.set noat
.set noreorder
glabel func_004d56c0
    /* 3D56C0 004D56C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D56C4 004D56C4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D56C8 004D56C8 2D808000 */  daddu      $16, $4, $0
    /* 3D56CC 004D56CC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D56D0 004D56D0 1000BFFF */  sd         $31, 0x10($29)
    /* 3D56D4 004D56D4 3615130C */  jal        func_004c54d8
    /* 3D56D8 004D56D8 2D88A000 */   daddu     $17, $5, $0
    /* 3D56DC 004D56DC 2D200002 */  daddu      $4, $16, $0
    /* 3D56E0 004D56E0 C055130C */  jal        func_004d5700
    /* 3D56E4 004D56E4 2D282002 */   daddu     $5, $17, $0
    /* 3D56E8 004D56E8 0000B0DF */  ld         $16, 0x0($29)
    /* 3D56EC 004D56EC 0800B1DF */  ld         $17, 0x8($29)
    /* 3D56F0 004D56F0 1000BFDF */  ld         $31, 0x10($29)
    /* 3D56F4 004D56F4 38151308 */  j          func_004c54e0
    /* 3D56F8 004D56F8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D56FC 004D56FC 00000000 */  nop
.size func_004d56c0, 0x40
