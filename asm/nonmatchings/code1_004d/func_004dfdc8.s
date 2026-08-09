.section .text
.set noat
.set noreorder
glabel func_004dfdc8
    /* 3DFDC8 004DFDC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DFDCC 004DFDCC 2D188000 */  daddu      $3, $4, $0
    /* 3DFDD0 004DFDD0 2D38C000 */  daddu      $7, $6, $0
    /* 3DFDD4 004DFDD4 2D30A000 */  daddu      $6, $5, $0
    /* 3DFDD8 004DFDD8 07006014 */  bnez       $3, .L004DFDF8
    /* 3DFDDC 004DFDDC 0000BFFF */   sd        $31, 0x0($29)
    /* 3DFDE0 004DFDE0 7600043C */  lui        $4, %hi(D_00759BE0)
    /* 3DFDE4 004DFDE4 0000BFDF */  ld         $31, 0x0($29)
    /* 3DFDE8 004DFDE8 E09B8424 */  addiu      $4, $4, %lo(D_00759BE0)
    /* 3DFDEC 004DFDEC B0781308 */  j          func_004de2c0
    /* 3DFDF0 004DFDF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DFDF4 004DFDF4 00000000 */  nop
  .L004DFDF8:
    /* 3DFDF8 004DFDF8 2100C228 */  slti       $2, $6, 0x21
    /* 3DFDFC 004DFDFC 06004054 */  bnel       $2, $0, .L004DFE18
    /* 3DFE00 004DFE00 80100600 */   sll       $2, $6, 2
    /* 3DFE04 004DFE04 7600043C */  lui        $4, %hi(D_00759C10)
    /* 3DFE08 004DFE08 0000BFDF */  ld         $31, 0x0($29)
    /* 3DFE0C 004DFE0C 109C8424 */  addiu      $4, $4, %lo(D_00759C10)
    /* 3DFE10 004DFE10 B0781308 */  j          func_004de2c0
    /* 3DFE14 004DFE14 1000BD27 */   addiu     $29, $29, 0x10
  .L004DFE18:
    /* 3DFE18 004DFE18 0000BFDF */  ld         $31, 0x0($29)
    /* 3DFE1C 004DFE1C 21104300 */  addu       $2, $2, $3
    /* 3DFE20 004DFE20 E80147AC */  sw         $7, 0x1E8($2)
    /* 3DFE24 004DFE24 E401668C */  lw         $6, 0x1E4($3)
    /* 3DFE28 004DFE28 2130C700 */  addu       $6, $6, $7
    /* 3DFE2C 004DFE2C 8E7F1308 */  j          func_004dfe38
    /* 3DFE30 004DFE30 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DFE34 004DFE34 00000000 */  nop
.size func_004dfdc8, 0x70
