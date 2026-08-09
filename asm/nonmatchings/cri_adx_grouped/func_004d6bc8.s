.section .text
.set noat
.set noreorder
glabel func_004d6bc8
    /* 3D6BC8 004D6BC8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D6BCC 004D6BCC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6BD0 004D6BD0 2D808000 */  daddu      $16, $4, $0
    /* 3D6BD4 004D6BD4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6BD8 004D6BD8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D6BDC 004D6BDC 3615130C */  jal        func_004c54d8
    /* 3D6BE0 004D6BE0 2D88A000 */   daddu     $17, $5, $0
    /* 3D6BE4 004D6BE4 2D200002 */  daddu      $4, $16, $0
    /* 3D6BE8 004D6BE8 025B130C */  jal        func_004d6c08
    /* 3D6BEC 004D6BEC 2D282002 */   daddu     $5, $17, $0
    /* 3D6BF0 004D6BF0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6BF4 004D6BF4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6BF8 004D6BF8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D6BFC 004D6BFC 38151308 */  j          func_004c54e0
    /* 3D6C00 004D6C00 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D6C04 004D6C04 00000000 */  nop
.size func_004d6bc8, 0x40
