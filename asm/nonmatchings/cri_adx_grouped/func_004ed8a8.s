.section .text
.set noat
.set noreorder
glabel func_004ed8a8
    /* 3ED8A8 004ED8A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED8AC 004ED8AC 08008014 */  bnez       $4, .L004ED8D0
    /* 3ED8B0 004ED8B0 0000BFFF */   sd        $31, 0x0($29)
    /* 3ED8B4 004ED8B4 7600043C */  lui        $4, %hi(D_0075CCB0)
    /* 3ED8B8 004ED8B8 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3ED8BC 004ED8BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED8C0 004ED8C0 B0CC8424 */  addiu      $4, $4, %lo(D_0075CCB0)
    /* 3ED8C4 004ED8C4 40CCA524 */  addiu      $5, $5, %lo(D_0075CC40)
    /* 3ED8C8 004ED8C8 2EB51308 */  j          func_004ed4b8
    /* 3ED8CC 004ED8CC 1000BD27 */   addiu     $29, $29, 0x10
  .L004ED8D0:
    /* 3ED8D0 004ED8D0 0400828C */  lw         $2, 0x4($4)
    /* 3ED8D4 004ED8D4 08004014 */  bnez       $2, .L004ED8F8
    /* 3ED8D8 004ED8D8 0000BFDF */   ld        $31, 0x0($29)
    /* 3ED8DC 004ED8DC 7600043C */  lui        $4, %hi(D_0075CCC0)
    /* 3ED8E0 004ED8E0 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3ED8E4 004ED8E4 C0CC8424 */  addiu      $4, $4, %lo(D_0075CCC0)
    /* 3ED8E8 004ED8E8 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
    /* 3ED8EC 004ED8EC 2EB51308 */  j          func_004ed4b8
    /* 3ED8F0 004ED8F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED8F4 004ED8F4 00000000 */  nop
  .L004ED8F8:
    /* 3ED8F8 004ED8F8 200086AC */  sw         $6, 0x20($4)
    /* 3ED8FC 004ED8FC 1C0085AC */  sw         $5, 0x1C($4)
    /* 3ED900 004ED900 0800E003 */  jr         $31
    /* 3ED904 004ED904 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ed8a8, 0x60
