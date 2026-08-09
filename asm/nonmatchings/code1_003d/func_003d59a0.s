.section .text
.set noat
.set noreorder
glabel func_003d59a0
    /* 2D59A0 003D59A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D59A4 003D59A4 0000BFFF */  sd         $31, 0x0($29)
    /* 2D59A8 003D59A8 2400838C */  lw         $3, 0x24($4)
    /* 2D59AC 003D59AC 2C00828C */  lw         $2, 0x2C($4)
    /* 2D59B0 003D59B0 18306200 */  mult       $6, $3, $2
    /* 2D59B4 003D59B4 4C008424 */  addiu      $4, $4, 0x4C
    /* 2D59B8 003D59B8 04FE100C */  jal        func_0043f810
    /* 2D59BC 003D59BC 4C00A524 */   addiu     $5, $5, 0x4C
    /* 2D59C0 003D59C0 0000BFDF */  ld         $31, 0x0($29)
    /* 2D59C4 003D59C4 01000224 */  addiu      $2, $0, 0x1
    /* 2D59C8 003D59C8 0800E003 */  jr         $31
    /* 2D59CC 003D59CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_003d59a0, 0x30
