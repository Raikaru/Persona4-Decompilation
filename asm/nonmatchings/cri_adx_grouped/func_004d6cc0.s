.section .text
.set noat
.set noreorder
glabel func_004d6cc0
    /* 3D6CC0 004D6CC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D6CC4 004D6CC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6CC8 004D6CC8 2D808000 */  daddu      $16, $4, $0
    /* 3D6CCC 004D6CCC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6CD0 004D6CD0 1000BFFF */  sd         $31, 0x10($29)
    /* 3D6CD4 004D6CD4 3615130C */  jal        func_004c54d8
    /* 3D6CD8 004D6CD8 2D88A000 */   daddu     $17, $5, $0
    /* 3D6CDC 004D6CDC 2D200002 */  daddu      $4, $16, $0
    /* 3D6CE0 004D6CE0 405B130C */  jal        func_004d6d00
    /* 3D6CE4 004D6CE4 2D282002 */   daddu     $5, $17, $0
    /* 3D6CE8 004D6CE8 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6CEC 004D6CEC 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6CF0 004D6CF0 1000BFDF */  ld         $31, 0x10($29)
    /* 3D6CF4 004D6CF4 38151308 */  j          func_004c54e0
    /* 3D6CF8 004D6CF8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D6CFC 004D6CFC 00000000 */  nop
.size func_004d6cc0, 0x40
