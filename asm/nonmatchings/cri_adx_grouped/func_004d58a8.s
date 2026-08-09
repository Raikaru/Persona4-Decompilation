.section .text
.set noat
.set noreorder
glabel func_004d58a8
    /* 3D58A8 004D58A8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D58AC 004D58AC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D58B0 004D58B0 2D808000 */  daddu      $16, $4, $0
    /* 3D58B4 004D58B4 0800BFFF */  sd         $31, 0x8($29)
    /* 3D58B8 004D58B8 3615130C */  jal        func_004c54d8
    /* 3D58BC 004D58BC 1000B4E7 */   swc1      $f20, 0x10($29)
    /* 3D58C0 004D58C0 3A56130C */  jal        func_004d58e8
    /* 3D58C4 004D58C4 2D200002 */   daddu     $4, $16, $0
    /* 3D58C8 004D58C8 3815130C */  jal        func_004c54e0
    /* 3D58CC 004D58CC 06050046 */   mov.s     $f20, $f0
    /* 3D58D0 004D58D0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D58D4 004D58D4 06A00046 */  mov.s      $f0, $f20
    /* 3D58D8 004D58D8 0800BFDF */  ld         $31, 0x8($29)
    /* 3D58DC 004D58DC 1000B4C7 */  lwc1       $f20, 0x10($29)
    /* 3D58E0 004D58E0 0800E003 */  jr         $31
    /* 3D58E4 004D58E4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d58a8, 0x40
