.section .text
.set noat
.set noreorder
glabel func_004d1e58
    /* 3D1E58 004D1E58 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D1E5C 004D1E5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1E60 004D1E60 2D808000 */  daddu      $16, $4, $0
    /* 3D1E64 004D1E64 0800B1FF */  sd         $17, 0x8($29)
    /* 3D1E68 004D1E68 2D88A000 */  daddu      $17, $5, $0
    /* 3D1E6C 004D1E6C 1000B2FF */  sd         $18, 0x10($29)
    /* 3D1E70 004D1E70 2D90C000 */  daddu      $18, $6, $0
    /* 3D1E74 004D1E74 1800B3FF */  sd         $19, 0x18($29)
    /* 3D1E78 004D1E78 2D98E000 */  daddu      $19, $7, $0
    /* 3D1E7C 004D1E7C 2000B4FF */  sd         $20, 0x20($29)
    /* 3D1E80 004D1E80 2800BFFF */  sd         $31, 0x28($29)
    /* 3D1E84 004D1E84 3246130C */  jal        func_004d18c8
    /* 3D1E88 004D1E88 2DA00001 */   daddu     $20, $8, $0
    /* 3D1E8C 004D1E8C 2D200002 */  daddu      $4, $16, $0
    /* 3D1E90 004D1E90 2D282002 */  daddu      $5, $17, $0
    /* 3D1E94 004D1E94 2D304002 */  daddu      $6, $18, $0
    /* 3D1E98 004D1E98 2D386002 */  daddu      $7, $19, $0
    /* 3D1E9C 004D1E9C B247130C */  jal        func_004d1ec8
    /* 3D1EA0 004D1EA0 2D408002 */   daddu     $8, $20, $0
    /* 3D1EA4 004D1EA4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1EA8 004D1EA8 0800B1DF */  ld         $17, 0x8($29)
    /* 3D1EAC 004D1EAC 1000B2DF */  ld         $18, 0x10($29)
    /* 3D1EB0 004D1EB0 1800B3DF */  ld         $19, 0x18($29)
    /* 3D1EB4 004D1EB4 2000B4DF */  ld         $20, 0x20($29)
    /* 3D1EB8 004D1EB8 2800BFDF */  ld         $31, 0x28($29)
    /* 3D1EBC 004D1EBC 34461308 */  j          func_004d18d0
    /* 3D1EC0 004D1EC0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D1EC4 004D1EC4 00000000 */  nop
.size func_004d1e58, 0x70
