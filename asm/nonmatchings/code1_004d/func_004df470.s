.section .text
.set noat
.set noreorder
glabel func_004df470
    /* 3DF470 004DF470 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF474 004DF474 06008014 */  bnez       $4, .L004DF490
    /* 3DF478 004DF478 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF47C 004DF47C 7600043C */  lui        $4, %hi(D_00759B08)
    /* 3DF480 004DF480 B078130C */  jal        func_004de2c0
    /* 3DF484 004DF484 089B8424 */   addiu     $4, $4, %lo(D_00759B08)
    /* 3DF488 004DF488 0B000010 */  b          .L004DF4B8
    /* 3DF48C 004DF48C FFFF0224 */   addiu     $2, $0, -0x1
  .L004DF490:
    /* 3DF490 004DF490 01008290 */  lbu        $2, 0x1($4)
    /* 3DF494 004DF494 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DF498 004DF498 0300422C */  sltiu      $2, $2, 0x3
    /* 3DF49C 004DF49C 06004050 */  beql       $2, $0, .L004DF4B8
    /* 3DF4A0 004DF4A0 2D100000 */   daddu     $2, $0, $0
    /* 3DF4A4 004DF4A4 0400848C */  lw         $4, 0x4($4)
    /* 3DF4A8 004DF4A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF4AC 004DF4AC A2811308 */  j          func_004e0688
    /* 3DF4B0 004DF4B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF4B4 004DF4B4 00000000 */  nop
  .L004DF4B8:
    /* 3DF4B8 004DF4B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF4BC 004DF4BC 0800E003 */  jr         $31
    /* 3DF4C0 004DF4C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF4C4 004DF4C4 00000000 */  nop
.size func_004df470, 0x58
