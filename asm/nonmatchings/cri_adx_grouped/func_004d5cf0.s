.section .text
.set noat
.set noreorder
glabel func_004d5cf0
    /* 3D5CF0 004D5CF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5CF4 004D5CF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5CF8 004D5CF8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D5CFC 004D5CFC 3615130C */  jal        func_004c54d8
    /* 3D5D00 004D5D00 2D808000 */   daddu     $16, $4, $0
    /* 3D5D04 004D5D04 4857130C */  jal        func_004d5d20
    /* 3D5D08 004D5D08 2D200002 */   daddu     $4, $16, $0
    /* 3D5D0C 004D5D0C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5D10 004D5D10 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5D14 004D5D14 38151308 */  j          func_004c54e0
    /* 3D5D18 004D5D18 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D5D1C 004D5D1C 00000000 */  nop
.size func_004d5cf0, 0x30
