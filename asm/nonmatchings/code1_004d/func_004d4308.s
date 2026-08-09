.section .text
.set noat
.set noreorder
glabel func_004d4308
    /* 3D4308 004D4308 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D430C 004D430C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4310 004D4310 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4314 004D4314 3615130C */  jal        func_004c54d8
    /* 3D4318 004D4318 2D808000 */   daddu     $16, $4, $0
    /* 3D431C 004D431C CE50130C */  jal        func_004d4338
    /* 3D4320 004D4320 2D200002 */   daddu     $4, $16, $0
    /* 3D4324 004D4324 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4328 004D4328 0800BFDF */  ld         $31, 0x8($29)
    /* 3D432C 004D432C 38151308 */  j          func_004c54e0
    /* 3D4330 004D4330 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4334 004D4334 00000000 */  nop
.size func_004d4308, 0x30
