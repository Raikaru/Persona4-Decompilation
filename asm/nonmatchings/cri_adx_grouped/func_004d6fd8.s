.section .text
.set noat
.set noreorder
glabel func_004d6fd8
    /* 3D6FD8 004D6FD8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D6FDC 004D6FDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6FE0 004D6FE0 2D808000 */  daddu      $16, $4, $0
    /* 3D6FE4 004D6FE4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6FE8 004D6FE8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D6FEC 004D6FEC 3615130C */  jal        func_004c54d8
    /* 3D6FF0 004D6FF0 2D88A000 */   daddu     $17, $5, $0
    /* 3D6FF4 004D6FF4 2D200002 */  daddu      $4, $16, $0
    /* 3D6FF8 004D6FF8 065C130C */  jal        func_004d7018
    /* 3D6FFC 004D6FFC 2D282002 */   daddu     $5, $17, $0
    /* 3D7000 004D7000 0000B0DF */  ld         $16, 0x0($29)
    /* 3D7004 004D7004 0800B1DF */  ld         $17, 0x8($29)
    /* 3D7008 004D7008 1000BFDF */  ld         $31, 0x10($29)
    /* 3D700C 004D700C 38151308 */  j          func_004c54e0
    /* 3D7010 004D7010 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D7014 004D7014 00000000 */  nop
.size func_004d6fd8, 0x40
