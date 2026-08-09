.section .text
.set noat
.set noreorder
glabel func_004d1fa0
    /* 3D1FA0 004D1FA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1FA4 004D1FA4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1FA8 004D1FA8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D1FAC 004D1FAC B248130C */  jal        func_004d22c8
    /* 3D1FB0 004D1FB0 2D808000 */   daddu     $16, $4, $0
    /* 3D1FB4 004D1FB4 C047130C */  jal        func_004d1f00
    /* 3D1FB8 004D1FB8 2D200002 */   daddu     $4, $16, $0
    /* 3D1FBC 004D1FBC 49000282 */  lb         $2, 0x49($16)
    /* 3D1FC0 004D1FC0 07004050 */  beql       $2, $0, .L004D1FE0
    /* 3D1FC4 004D1FC4 0000B0DF */   ld        $16, 0x0($29)
  .L004D1FC8:
    /* 3D1FC8 004D1FC8 5227130C */  jal        func_004c9d48
    /* 3D1FCC 004D1FCC 00000000 */   nop
    /* 3D1FD0 004D1FD0 49000282 */  lb         $2, 0x49($16)
    /* 3D1FD4 004D1FD4 FCFF4014 */  bnez       $2, .L004D1FC8
    /* 3D1FD8 004D1FD8 00000000 */   nop
    /* 3D1FDC 004D1FDC 0000B0DF */  ld         $16, 0x0($29)
  .L004D1FE0:
    /* 3D1FE0 004D1FE0 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1FE4 004D1FE4 0800E003 */  jr         $31
    /* 3D1FE8 004D1FE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D1FEC 004D1FEC 00000000 */  nop
.size func_004d1fa0, 0x50
