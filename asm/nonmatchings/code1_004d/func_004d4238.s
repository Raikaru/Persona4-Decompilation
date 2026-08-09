.section .text
.set noat
.set noreorder
glabel func_004d4238
    /* 3D4238 004D4238 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D423C 004D423C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4240 004D4240 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4244 004D4244 3615130C */  jal        func_004c54d8
    /* 3D4248 004D4248 2D808000 */   daddu     $16, $4, $0
    /* 3D424C 004D424C 9A50130C */  jal        func_004d4268
    /* 3D4250 004D4250 2D200002 */   daddu     $4, $16, $0
    /* 3D4254 004D4254 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4258 004D4258 0800BFDF */  ld         $31, 0x8($29)
    /* 3D425C 004D425C 38151308 */  j          func_004c54e0
    /* 3D4260 004D4260 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4264 004D4264 00000000 */  nop
.size func_004d4238, 0x30
