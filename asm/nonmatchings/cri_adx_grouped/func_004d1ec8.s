.section .text
.set noat
.set noreorder
glabel func_004d1ec8
    /* 3D1EC8 004D1EC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1ECC 004D1ECC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1ED0 004D1ED0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D1ED4 004D1ED4 5C47130C */  jal        func_004d1d70
    /* 3D1ED8 004D1ED8 2D808000 */   daddu     $16, $4, $0
    /* 3D1EDC 004D1EDC 00000000 */  nop
  .L004D1EE0:
    /* 3D1EE0 004D1EE0 5227130C */  jal        func_004c9d48
    /* 3D1EE4 004D1EE4 00000000 */   nop
    /* 3D1EE8 004D1EE8 45000282 */  lb         $2, 0x45($16)
    /* 3D1EEC 004D1EEC FCFF4014 */  bnez       $2, .L004D1EE0
    /* 3D1EF0 004D1EF0 0800BFDF */   ld        $31, 0x8($29)
    /* 3D1EF4 004D1EF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1EF8 004D1EF8 0800E003 */  jr         $31
    /* 3D1EFC 004D1EFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d1ec8, 0x38
