.section .text
.set noat
.set noreorder
glabel func_004fb410
    /* 3FB410 004FB410 7400033C */  lui        $3, %hi(D_00743CB8)
    /* 3FB414 004FB414 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB418 004FB418 B83C638C */  lw         $3, %lo(D_00743CB8)($3)
    /* 3FB41C 004FB41C 2D100000 */  daddu      $2, $0, $0
    /* 3FB420 004FB420 03006010 */  beqz       $3, .L004FB430
    /* 3FB424 004FB424 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB428 004FB428 09F86000 */  jalr       $3
    /* 3FB42C 004FB42C 00000000 */   nop
  .L004FB430:
    /* 3FB430 004FB430 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB434 004FB434 0800E003 */  jr         $31
    /* 3FB438 004FB438 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FB43C 004FB43C 00000000 */  nop
.size func_004fb410, 0x30
