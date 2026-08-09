.section .text
.set noat
.set noreorder
glabel func_004d5a78
    /* 3D5A78 004D5A78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D5A7C 004D5A7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5A80 004D5A80 2D808000 */  daddu      $16, $4, $0
    /* 3D5A84 004D5A84 0800B1FF */  sd         $17, 0x8($29)
    /* 3D5A88 004D5A88 1000BFFF */  sd         $31, 0x10($29)
    /* 3D5A8C 004D5A8C 3615130C */  jal        func_004c54d8
    /* 3D5A90 004D5A90 2D88A000 */   daddu     $17, $5, $0
    /* 3D5A94 004D5A94 2D200002 */  daddu      $4, $16, $0
    /* 3D5A98 004D5A98 AE56130C */  jal        func_004d5ab8
    /* 3D5A9C 004D5A9C 2D282002 */   daddu     $5, $17, $0
    /* 3D5AA0 004D5AA0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5AA4 004D5AA4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5AA8 004D5AA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D5AAC 004D5AAC 38151308 */  j          func_004c54e0
    /* 3D5AB0 004D5AB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D5AB4 004D5AB4 00000000 */  nop
.size func_004d5a78, 0x40
