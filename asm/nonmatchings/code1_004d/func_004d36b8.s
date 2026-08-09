.section .text
.set noat
.set noreorder
glabel func_004d36b8
    /* 3D36B8 004D36B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D36BC 004D36BC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D36C0 004D36C0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D36C4 004D36C4 3615130C */  jal        func_004c54d8
    /* 3D36C8 004D36C8 2D808000 */   daddu     $16, $4, $0
    /* 3D36CC 004D36CC BA4D130C */  jal        func_004d36e8
    /* 3D36D0 004D36D0 2D200002 */   daddu     $4, $16, $0
    /* 3D36D4 004D36D4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D36D8 004D36D8 0800BFDF */  ld         $31, 0x8($29)
    /* 3D36DC 004D36DC 38151308 */  j          func_004c54e0
    /* 3D36E0 004D36E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D36E4 004D36E4 00000000 */  nop
.size func_004d36b8, 0x30
