.section .text
.set noat
.set noreorder
glabel func_004d5f78
    /* 3D5F78 004D5F78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D5F7C 004D5F7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5F80 004D5F80 2D808000 */  daddu      $16, $4, $0
    /* 3D5F84 004D5F84 0800B1FF */  sd         $17, 0x8($29)
    /* 3D5F88 004D5F88 1000BFFF */  sd         $31, 0x10($29)
    /* 3D5F8C 004D5F8C 3615130C */  jal        func_004c54d8
    /* 3D5F90 004D5F90 2D88A000 */   daddu     $17, $5, $0
    /* 3D5F94 004D5F94 2D200002 */  daddu      $4, $16, $0
    /* 3D5F98 004D5F98 EE57130C */  jal        func_004d5fb8
    /* 3D5F9C 004D5F9C 2D282002 */   daddu     $5, $17, $0
    /* 3D5FA0 004D5FA0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5FA4 004D5FA4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5FA8 004D5FA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D5FAC 004D5FAC 38151308 */  j          func_004c54e0
    /* 3D5FB0 004D5FB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D5FB4 004D5FB4 00000000 */  nop
.size func_004d5f78, 0x40
