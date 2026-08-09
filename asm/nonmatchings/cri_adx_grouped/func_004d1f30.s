.section .text
.set noat
.set noreorder
glabel func_004d1f30
    /* 3D1F30 004D1F30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1F34 004D1F34 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1F38 004D1F38 0800BFFF */  sd         $31, 0x8($29)
    /* 3D1F3C 004D1F3C 8C48130C */  jal        func_004d2230
    /* 3D1F40 004D1F40 2D808000 */   daddu     $16, $4, $0
    /* 3D1F44 004D1F44 2046130C */  jal        func_004d1880
    /* 3D1F48 004D1F48 00000000 */   nop
    /* 3D1F4C 004D1F4C 49000382 */  lb         $3, 0x49($16)
    /* 3D1F50 004D1F50 01000224 */  addiu      $2, $0, 0x1
    /* 3D1F54 004D1F54 01006250 */  beql       $3, $2, .L004D1F5C
    /* 3D1F58 004D1F58 460003A2 */   sb        $3, 0x46($16)
  .L004D1F5C:
    /* 3D1F5C 004D1F5C 450000A2 */  sb         $0, 0x45($16)
    /* 3D1F60 004D1F60 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1F64 004D1F64 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1F68 004D1F68 26461308 */  j          func_004d1898
    /* 3D1F6C 004D1F6C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d1f30, 0x40
