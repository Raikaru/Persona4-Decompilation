.section .text
.set noat
.set noreorder
glabel func_004dfcd8
    /* 3DFCD8 004DFCD8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DFCDC 004DFCDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3DFCE0 004DFCE0 2D808000 */  daddu      $16, $4, $0
    /* 3DFCE4 004DFCE4 0800B1FF */  sd         $17, 0x8($29)
    /* 3DFCE8 004DFCE8 1000B2FF */  sd         $18, 0x10($29)
    /* 3DFCEC 004DFCEC 0A000016 */  bnez       $16, .L004DFD18
    /* 3DFCF0 004DFCF0 1800BFFF */   sd        $31, 0x18($29)
    /* 3DFCF4 004DFCF4 7600043C */  lui        $4, %hi(D_00759BB0)
    /* 3DFCF8 004DFCF8 0000B0DF */  ld         $16, 0x0($29)
    /* 3DFCFC 004DFCFC 0800B1DF */  ld         $17, 0x8($29)
    /* 3DFD00 004DFD00 B09B8424 */  addiu      $4, $4, %lo(D_00759BB0)
    /* 3DFD04 004DFD04 1000B2DF */  ld         $18, 0x10($29)
    /* 3DFD08 004DFD08 1800BFDF */  ld         $31, 0x18($29)
    /* 3DFD0C 004DFD0C B0781308 */  j          func_004de2c0
    /* 3DFD10 004DFD10 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DFD14 004DFD14 00000000 */  nop
  .L004DFD18:
    /* 3DFD18 004DFD18 03000282 */  lb         $2, 0x3($16)
    /* 3DFD1C 004DFD1C 2D900000 */  daddu      $18, $0, $0
    /* 3DFD20 004DFD20 0E004018 */  blez       $2, .L004DFD5C
    /* 3DFD24 004DFD24 E40105AE */   sw        $5, 0x1E4($16)
    /* 3DFD28 004DFD28 E8011126 */  addiu      $17, $16, 0x1E8
    /* 3DFD2C 004DFD2C 0000228E */  lw         $2, 0x0($17)
  .L004DFD30:
    /* 3DFD30 004DFD30 04003126 */  addiu      $17, $17, 0x4
    /* 3DFD34 004DFD34 E401068E */  lw         $6, 0x1E4($16)
    /* 3DFD38 004DFD38 2D284002 */  daddu      $5, $18, $0
    /* 3DFD3C 004DFD3C 2D200002 */  daddu      $4, $16, $0
    /* 3DFD40 004DFD40 01005226 */  addiu      $18, $18, 0x1
    /* 3DFD44 004DFD44 8E7F130C */  jal        func_004dfe38
    /* 3DFD48 004DFD48 2130C200 */   addu      $6, $6, $2
    /* 3DFD4C 004DFD4C 03000282 */  lb         $2, 0x3($16)
    /* 3DFD50 004DFD50 2A104202 */  slt        $2, $18, $2
    /* 3DFD54 004DFD54 F6FF4054 */  bnel       $2, $0, .L004DFD30
    /* 3DFD58 004DFD58 0000228E */   lw        $2, 0x0($17)
  .L004DFD5C:
    /* 3DFD5C 004DFD5C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DFD60 004DFD60 0800B1DF */  ld         $17, 0x8($29)
    /* 3DFD64 004DFD64 1000B2DF */  ld         $18, 0x10($29)
    /* 3DFD68 004DFD68 1800BFDF */  ld         $31, 0x18($29)
    /* 3DFD6C 004DFD6C 0800E003 */  jr         $31
    /* 3DFD70 004DFD70 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DFD74 004DFD74 00000000 */  nop
.size func_004dfcd8, 0xa0
