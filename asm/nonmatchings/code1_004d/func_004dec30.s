.section .text
.set noat
.set noreorder
glabel func_004dec30
    /* 3DEC30 004DEC30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DEC34 004DEC34 0800B1FF */  sd         $17, 0x8($29)
    /* 3DEC38 004DEC38 2D888000 */  daddu      $17, $4, $0
    /* 3DEC3C 004DEC3C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DEC40 004DEC40 2D80A000 */  daddu      $16, $5, $0
    /* 3DEC44 004DEC44 03002012 */  beqz       $17, .L004DEC54
    /* 3DEC48 004DEC48 1000BFFF */   sd        $31, 0x10($29)
    /* 3DEC4C 004DEC4C 08000016 */  bnez       $16, .L004DEC70
    /* 3DEC50 004DEC50 00000000 */   nop
  .L004DEC54:
    /* 3DEC54 004DEC54 7600043C */  lui        $4, %hi(D_00759738)
    /* 3DEC58 004DEC58 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEC5C 004DEC5C 0800B1DF */  ld         $17, 0x8($29)
    /* 3DEC60 004DEC60 38978424 */  addiu      $4, $4, %lo(D_00759738)
    /* 3DEC64 004DEC64 1000BFDF */  ld         $31, 0x10($29)
    /* 3DEC68 004DEC68 B0781308 */  j          func_004de2c0
    /* 3DEC6C 004DEC6C 2000BD27 */   addiu     $29, $29, 0x20
  .L004DEC70:
    /* 3DEC70 004DEC70 587B130C */  jal        func_004ded60
    /* 3DEC74 004DEC74 00000000 */   nop
    /* 3DEC78 004DEC78 E080130C */  jal        func_004e0380
    /* 3DEC7C 004DEC7C 00000000 */   nop
    /* 3DEC80 004DEC80 900030AE */  sw         $16, 0x90($17)
    /* 3DEC84 004DEC84 2D280002 */  daddu      $5, $16, $0
    /* 3DEC88 004DEC88 7681130C */  jal        func_004e05d8
    /* 3DEC8C 004DEC8C 0400248E */   lw        $4, 0x4($17)
    /* 3DEC90 004DEC90 03000224 */  addiu      $2, $0, 0x3
    /* 3DEC94 004DEC94 01000324 */  addiu      $3, $0, 0x1
    /* 3DEC98 004DEC98 DC0122AE */  sw         $2, 0x1DC($17)
    /* 3DEC9C 004DEC9C 010023A2 */  sb         $3, 0x1($17)
    /* 3DECA0 004DECA0 0000B0DF */  ld         $16, 0x0($29)
    /* 3DECA4 004DECA4 0800B1DF */  ld         $17, 0x8($29)
    /* 3DECA8 004DECA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3DECAC 004DECAC E6801308 */  j          func_004e0398
    /* 3DECB0 004DECB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DECB4 004DECB4 00000000 */  nop
.size func_004dec30, 0x88
