.section .text
.set noat
.set noreorder
glabel func_004cad10
    /* 3CAD10 004CAD10 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CAD14 004CAD14 2D108000 */  daddu      $2, $4, $0
    /* 3CAD18 004CAD18 2000B0FF */  sd         $16, 0x20($29)
    /* 3CAD1C 004CAD1C 2D80A000 */  daddu      $16, $5, $0
    /* 3CAD20 004CAD20 2800B1FF */  sd         $17, 0x28($29)
    /* 3CAD24 004CAD24 2D88C000 */  daddu      $17, $6, $0
    /* 3CAD28 004CAD28 3000B2FF */  sd         $18, 0x30($29)
    /* 3CAD2C 004CAD2C 2D200002 */  daddu      $4, $16, $0
    /* 3CAD30 004CAD30 3800BFFF */  sd         $31, 0x38($29)
    /* 3CAD34 004CAD34 2D282002 */  daddu      $5, $17, $0
    /* 3CAD38 004CAD38 07004014 */  bnez       $2, .L004CAD58
    /* 3CAD3C 004CAD3C 9400528C */   lw        $18, 0x94($2)
    /* 3CAD40 004CAD40 7600043C */  lui        $4, %hi(D_00758760)
    /* 3CAD44 004CAD44 A61A130C */  jal        func_004c6a98
    /* 3CAD48 004CAD48 60878424 */   addiu     $4, $4, %lo(D_00758760)
    /* 3CAD4C 004CAD4C 1D000010 */  b          .L004CADC4
    /* 3CAD50 004CAD50 2000B0DF */   ld        $16, 0x20($29)
    /* 3CAD54 004CAD54 00000000 */  nop
  .L004CAD58:
    /* 3CAD58 004CAD58 B000468C */  lw         $6, 0xB0($2)
    /* 3CAD5C 004CAD5C 1000A727 */  addiu      $7, $29, 0x10
    /* 3CAD60 004CAD60 1400A827 */  addiu      $8, $29, 0x14
    /* 3CAD64 004CAD64 6826130C */  jal        func_004c99a0
    /* 3CAD68 004CAD68 1800A927 */   addiu     $9, $29, 0x18
    /* 3CAD6C 004CAD6C 2D200002 */  daddu      $4, $16, $0
    /* 3CAD70 004CAD70 2D282002 */  daddu      $5, $17, $0
    /* 3CAD74 004CAD74 2D30A003 */  daddu      $6, $29, $0
    /* 3CAD78 004CAD78 0B004014 */  bnez       $2, .L004CADA8
    /* 3CAD7C 004CAD7C 10000724 */   addiu     $7, $0, 0x10
    /* 3CAD80 004CAD80 E026130C */  jal        func_004c9b80
    /* 3CAD84 004CAD84 00000000 */   nop
    /* 3CAD88 004CAD88 2D204002 */  daddu      $4, $18, $0
    /* 3CAD8C 004CAD8C 1000A68F */  lw         $6, 0x10($29)
    /* 3CAD90 004CAD90 2D284000 */  daddu      $5, $2, $0
    /* 3CAD94 004CAD94 1400A78F */  lw         $7, 0x14($29)
    /* 3CAD98 004CAD98 2EA4130C */  jal        func_004e90b8
    /* 3CAD9C 004CAD9C 1800A88F */   lw        $8, 0x18($29)
    /* 3CADA0 004CADA0 08000010 */  b          .L004CADC4
    /* 3CADA4 004CADA4 2000B0DF */   ld        $16, 0x20($29)
  .L004CADA8:
    /* 3CADA8 004CADA8 1A1B130C */  jal        func_004c6c68
    /* 3CADAC 004CADAC 00000000 */   nop
    /* 3CADB0 004CADB0 7600043C */  lui        $4, %hi(D_00758790)
    /* 3CADB4 004CADB4 90878424 */  addiu      $4, $4, %lo(D_00758790)
    /* 3CADB8 004CADB8 BC1A130C */  jal        func_004c6af0
    /* 3CADBC 004CADBC 2D28A003 */   daddu     $5, $29, $0
    /* 3CADC0 004CADC0 2000B0DF */  ld         $16, 0x20($29)
  .L004CADC4:
    /* 3CADC4 004CADC4 2800B1DF */  ld         $17, 0x28($29)
    /* 3CADC8 004CADC8 3000B2DF */  ld         $18, 0x30($29)
    /* 3CADCC 004CADCC 3800BFDF */  ld         $31, 0x38($29)
    /* 3CADD0 004CADD0 0800E003 */  jr         $31
    /* 3CADD4 004CADD4 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cad10, 0xc8
