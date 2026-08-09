.section .text
.set noat
.set noreorder
glabel func_004d6f78
    /* 3D6F78 004D6F78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D6F7C 004D6F7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6F80 004D6F80 2D808000 */  daddu      $16, $4, $0
    /* 3D6F84 004D6F84 0800B1FF */  sd         $17, 0x8($29)
    /* 3D6F88 004D6F88 1000BFFF */  sd         $31, 0x10($29)
    /* 3D6F8C 004D6F8C 3615130C */  jal        func_004c54d8
    /* 3D6F90 004D6F90 2D88A000 */   daddu     $17, $5, $0
    /* 3D6F94 004D6F94 2D200002 */  daddu      $4, $16, $0
    /* 3D6F98 004D6F98 EE5B130C */  jal        func_004d6fb8
    /* 3D6F9C 004D6F9C 2D282002 */   daddu     $5, $17, $0
    /* 3D6FA0 004D6FA0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6FA4 004D6FA4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D6FA8 004D6FA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D6FAC 004D6FAC 38151308 */  j          func_004c54e0
    /* 3D6FB0 004D6FB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D6FB4 004D6FB4 00000000 */  nop
.size func_004d6f78, 0x40
