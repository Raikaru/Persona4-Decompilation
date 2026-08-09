.section .text
.set noat
.set noreorder
glabel func_004d6e60
    /* 3D6E60 004D6E60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D6E64 004D6E64 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6E68 004D6E68 2D808000 */  daddu      $16, $4, $0
    /* 3D6E6C 004D6E6C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6E70 004D6E70 2D88A000 */  daddu      $17, $5, $0
    /* 3D6E74 004D6E74 1000B2FF */  sd         $18, 0x10($29)
    /* 3D6E78 004D6E78 2D90C000 */  daddu      $18, $6, $0
    /* 3D6E7C 004D6E7C 1800B3FF */  sd         $19, 0x18($29)
    /* 3D6E80 004D6E80 2000BFFF */  sd         $31, 0x20($29)
    /* 3D6E84 004D6E84 3615130C */  jal        func_004c54d8
    /* 3D6E88 004D6E88 2D98E000 */   daddu     $19, $7, $0
    /* 3D6E8C 004D6E8C 2D200002 */  daddu      $4, $16, $0
    /* 3D6E90 004D6E90 2D282002 */  daddu      $5, $17, $0
    /* 3D6E94 004D6E94 2D304002 */  daddu      $6, $18, $0
    /* 3D6E98 004D6E98 B05B130C */  jal        func_004d6ec0
    /* 3D6E9C 004D6E9C 2D386002 */   daddu     $7, $19, $0
    /* 3D6EA0 004D6EA0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6EA4 004D6EA4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6EA8 004D6EA8 1000B2DF */  ld         $18, 0x10($29)
    /* 3D6EAC 004D6EAC 1800B3DF */  ld         $19, 0x18($29)
    /* 3D6EB0 004D6EB0 2000BFDF */  ld         $31, 0x20($29)
    /* 3D6EB4 004D6EB4 38151308 */  j          func_004c54e0
    /* 3D6EB8 004D6EB8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D6EBC 004D6EBC 00000000 */  nop
.size func_004d6e60, 0x60
