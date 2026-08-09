.section .text
.set noat
.set noreorder
glabel func_004cac50
    /* 3CAC50 004CAC50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CAC54 004CAC54 2D10C000 */  daddu      $2, $6, $0
    /* 3CAC58 004CAC58 0000B0FF */  sd         $16, 0x0($29)
    /* 3CAC5C 004CAC5C 2D80A000 */  daddu      $16, $5, $0
    /* 3CAC60 004CAC60 0800BFFF */  sd         $31, 0x8($29)
    /* 3CAC64 004CAC64 2D40E000 */  daddu      $8, $7, $0
    /* 3CAC68 004CAC68 2D300000 */  daddu      $6, $0, $0
    /* 3CAC6C 004CAC6C 2D384000 */  daddu      $7, $2, $0
    /* 3CAC70 004CAC70 07008014 */  bnez       $4, .L004CAC90
    /* 3CAC74 004CAC74 9400828C */   lw        $2, 0x94($4)
    /* 3CAC78 004CAC78 7600043C */  lui        $4, %hi(D_00758710)
    /* 3CAC7C 004CAC7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CAC80 004CAC80 0800BFDF */  ld         $31, 0x8($29)
    /* 3CAC84 004CAC84 10878424 */  addiu      $4, $4, %lo(D_00758710)
    /* 3CAC88 004CAC88 A61A1308 */  j          func_004c6a98
    /* 3CAC8C 004CAC8C 1000BD27 */   addiu     $29, $29, 0x10
  .L004CAC90:
    /* 3CAC90 004CAC90 2EA4130C */  jal        func_004e90b8
    /* 3CAC94 004CAC94 2D204000 */   daddu     $4, $2, $0
    /* 3CAC98 004CAC98 7600043C */  lui        $4, %hi(D_00758740)
    /* 3CAC9C 004CAC9C 40878424 */  addiu      $4, $4, %lo(D_00758740)
    /* 3CACA0 004CACA0 03004104 */  bgez       $2, .L004CACB0
    /* 3CACA4 004CACA4 2D280002 */   daddu     $5, $16, $0
    /* 3CACA8 004CACA8 BC1A130C */  jal        func_004c6af0
    /* 3CACAC 004CACAC 00000000 */   nop
  .L004CACB0:
    /* 3CACB0 004CACB0 0000B0DF */  ld         $16, 0x0($29)
    /* 3CACB4 004CACB4 0800BFDF */  ld         $31, 0x8($29)
    /* 3CACB8 004CACB8 0800E003 */  jr         $31
    /* 3CACBC 004CACBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cac50, 0x70
