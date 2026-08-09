.section .text
.set noat
.set noreorder
glabel func_004d6310
    /* 3D6310 004D6310 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6314 004D6314 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6318 004D6318 0800BFFF */  sd         $31, 0x8($29)
    /* 3D631C 004D631C 3615130C */  jal        func_004c54d8
    /* 3D6320 004D6320 2D808000 */   daddu     $16, $4, $0
    /* 3D6324 004D6324 D058130C */  jal        func_004d6340
    /* 3D6328 004D6328 2D200002 */   daddu     $4, $16, $0
    /* 3D632C 004D632C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6330 004D6330 0800BFDF */  ld         $31, 0x8($29)
    /* 3D6334 004D6334 38151308 */  j          func_004c54e0
    /* 3D6338 004D6338 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D633C 004D633C 00000000 */  nop
.size func_004d6310, 0x30
