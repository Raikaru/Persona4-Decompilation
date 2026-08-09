.section .text
.set noat
.set noreorder
glabel func_004d67b8
    /* 3D67B8 004D67B8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D67BC 004D67BC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D67C0 004D67C0 2D808000 */  daddu      $16, $4, $0
    /* 3D67C4 004D67C4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D67C8 004D67C8 2D88A000 */  daddu      $17, $5, $0
    /* 3D67CC 004D67CC 1000B2FF */  sd         $18, 0x10($29)
    /* 3D67D0 004D67D0 1800BFFF */  sd         $31, 0x18($29)
    /* 3D67D4 004D67D4 3615130C */  jal        func_004c54d8
    /* 3D67D8 004D67D8 2D90C000 */   daddu     $18, $6, $0
    /* 3D67DC 004D67DC 2D200002 */  daddu      $4, $16, $0
    /* 3D67E0 004D67E0 2D282002 */  daddu      $5, $17, $0
    /* 3D67E4 004D67E4 025A130C */  jal        func_004d6808
    /* 3D67E8 004D67E8 2D304002 */   daddu     $6, $18, $0
    /* 3D67EC 004D67EC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D67F0 004D67F0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D67F4 004D67F4 1000B2DF */  ld         $18, 0x10($29)
    /* 3D67F8 004D67F8 1800BFDF */  ld         $31, 0x18($29)
    /* 3D67FC 004D67FC 38151308 */  j          func_004c54e0
    /* 3D6800 004D6800 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D6804 004D6804 00000000 */  nop
.size func_004d67b8, 0x50
