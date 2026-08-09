.section .text
.set noat
.set noreorder
glabel func_004df418
    /* 3DF418 004DF418 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF41C 004DF41C 06008014 */  bnez       $4, .L004DF438
    /* 3DF420 004DF420 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF424 004DF424 7600043C */  lui        $4, %hi(D_00759AC8)
    /* 3DF428 004DF428 B078130C */  jal        func_004de2c0
    /* 3DF42C 004DF42C C89A8424 */   addiu     $4, $4, %lo(D_00759AC8)
    /* 3DF430 004DF430 0B000010 */  b          .L004DF460
    /* 3DF434 004DF434 FFFF0224 */   addiu     $2, $0, -0x1
  .L004DF438:
    /* 3DF438 004DF438 01008290 */  lbu        $2, 0x1($4)
    /* 3DF43C 004DF43C FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DF440 004DF440 0300422C */  sltiu      $2, $2, 0x3
    /* 3DF444 004DF444 06004050 */  beql       $2, $0, .L004DF460
    /* 3DF448 004DF448 2D100000 */   daddu     $2, $0, $0
    /* 3DF44C 004DF44C 0400848C */  lw         $4, 0x4($4)
    /* 3DF450 004DF450 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF454 004DF454 88811308 */  j          func_004e0620
    /* 3DF458 004DF458 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF45C 004DF45C 00000000 */  nop
  .L004DF460:
    /* 3DF460 004DF460 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF464 004DF464 0800E003 */  jr         $31
    /* 3DF468 004DF468 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF46C 004DF46C 00000000 */  nop
.size func_004df418, 0x58
