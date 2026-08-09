.section .text
.set noat
.set noreorder
glabel func_004ed498
    /* 3ED498 004ED498 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED49C 004ED49C 7600043C */  lui        $4, %hi(D_0075CC20)
    /* 3ED4A0 004ED4A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED4A4 004ED4A4 20CC8424 */  addiu      $4, $4, %lo(D_0075CC20)
    /* 3ED4A8 004ED4A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED4AC 004ED4AC 20B51308 */  j          func_004ed480
    /* 3ED4B0 004ED4B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED4B4 004ED4B4 00000000 */  nop
.size func_004ed498, 0x20
