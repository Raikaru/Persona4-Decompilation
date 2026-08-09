.section .text
.set noat
.set noreorder
glabel func_004d4ac0
    /* 3D4AC0 004D4AC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4AC4 004D4AC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4AC8 004D4AC8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4ACC 004D4ACC 3615130C */  jal        func_004c54d8
    /* 3D4AD0 004D4AD0 2D808000 */   daddu     $16, $4, $0
    /* 3D4AD4 004D4AD4 BE52130C */  jal        func_004d4af8
    /* 3D4AD8 004D4AD8 2D200002 */   daddu     $4, $16, $0
    /* 3D4ADC 004D4ADC 3815130C */  jal        func_004c54e0
    /* 3D4AE0 004D4AE0 2D804000 */   daddu     $16, $2, $0
    /* 3D4AE4 004D4AE4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D4AE8 004D4AE8 2D100002 */  daddu      $2, $16, $0
    /* 3D4AEC 004D4AEC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4AF0 004D4AF0 0800E003 */  jr         $31
    /* 3D4AF4 004D4AF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d4ac0, 0x38
