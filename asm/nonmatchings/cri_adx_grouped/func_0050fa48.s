.section .text
.set noat
.set noreorder
glabel func_0050fa48
    /* 40FA48 0050FA48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FA4C 0050FA4C 0000B0FF */  sd         $16, 0x0($29)
    /* 40FA50 0050FA50 0800BFFF */  sd         $31, 0x8($29)
    /* 40FA54 0050FA54 2E39140C */  jal        func_0050e4b8
    /* 40FA58 0050FA58 2D80A000 */   daddu     $16, $5, $0
    /* 40FA5C 0050FA5C 0800BFDF */  ld         $31, 0x8($29)
    /* 40FA60 0050FA60 2D280002 */  daddu      $5, $16, $0
    /* 40FA64 0050FA64 0000B0DF */  ld         $16, 0x0($29)
    /* 40FA68 0050FA68 2D204000 */  daddu      $4, $2, $0
    /* 40FA6C 0050FA6C 88AE1408 */  j          func_0052ba20
    /* 40FA70 0050FA70 1000BD27 */   addiu     $29, $29, 0x10
    /* 40FA74 0050FA74 00000000 */  nop
.size func_0050fa48, 0x30
