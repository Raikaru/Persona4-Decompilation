.section .text
.set noat
.set noreorder
glabel func_004d44c8
    /* 3D44C8 004D44C8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D44CC 004D44CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D44D0 004D44D0 2D808000 */  daddu      $16, $4, $0
    /* 3D44D4 004D44D4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D44D8 004D44D8 2D88A000 */  daddu      $17, $5, $0
    /* 3D44DC 004D44DC 1000B2FF */  sd         $18, 0x10($29)
    /* 3D44E0 004D44E0 1800BFFF */  sd         $31, 0x18($29)
    /* 3D44E4 004D44E4 3615130C */  jal        func_004c54d8
    /* 3D44E8 004D44E8 2D90C000 */   daddu     $18, $6, $0
    /* 3D44EC 004D44EC 2D200002 */  daddu      $4, $16, $0
    /* 3D44F0 004D44F0 2D282002 */  daddu      $5, $17, $0
    /* 3D44F4 004D44F4 4651130C */  jal        func_004d4518
    /* 3D44F8 004D44F8 2D304002 */   daddu     $6, $18, $0
    /* 3D44FC 004D44FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4500 004D4500 0800B1DF */  ld         $17, 0x8($29)
    /* 3D4504 004D4504 1000B2DF */  ld         $18, 0x10($29)
    /* 3D4508 004D4508 1800BFDF */  ld         $31, 0x18($29)
    /* 3D450C 004D450C 38151308 */  j          func_004c54e0
    /* 3D4510 004D4510 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D4514 004D4514 00000000 */  nop
.size func_004d44c8, 0x50
