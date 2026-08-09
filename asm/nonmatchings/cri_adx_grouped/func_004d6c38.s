.section .text
.set noat
.set noreorder
glabel func_004d6c38
    /* 3D6C38 004D6C38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6C3C 004D6C3C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6C40 004D6C40 0800BFFF */  sd         $31, 0x8($29)
    /* 3D6C44 004D6C44 3615130C */  jal        func_004c54d8
    /* 3D6C48 004D6C48 2D808000 */   daddu     $16, $4, $0
    /* 3D6C4C 004D6C4C 1A5B130C */  jal        func_004d6c68
    /* 3D6C50 004D6C50 2D200002 */   daddu     $4, $16, $0
    /* 3D6C54 004D6C54 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6C58 004D6C58 0800BFDF */  ld         $31, 0x8($29)
    /* 3D6C5C 004D6C5C 38151308 */  j          func_004c54e0
    /* 3D6C60 004D6C60 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D6C64 004D6C64 00000000 */  nop
.size func_004d6c38, 0x30
