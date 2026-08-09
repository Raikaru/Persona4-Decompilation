.section .text
.set noat
.set noreorder
glabel func_004d59d0
    /* 3D59D0 004D59D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D59D4 004D59D4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D59D8 004D59D8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D59DC 004D59DC 3615130C */  jal        func_004c54d8
    /* 3D59E0 004D59E0 2D808000 */   daddu     $16, $4, $0
    /* 3D59E4 004D59E4 8256130C */  jal        func_004d5a08
    /* 3D59E8 004D59E8 2D200002 */   daddu     $4, $16, $0
    /* 3D59EC 004D59EC 3815130C */  jal        func_004c54e0
    /* 3D59F0 004D59F0 2D804000 */   daddu     $16, $2, $0
    /* 3D59F4 004D59F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D59F8 004D59F8 2D100002 */  daddu      $2, $16, $0
    /* 3D59FC 004D59FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5A00 004D5A00 0800E003 */  jr         $31
    /* 3D5A04 004D5A04 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d59d0, 0x38
