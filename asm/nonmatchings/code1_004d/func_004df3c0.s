.section .text
.set noat
.set noreorder
glabel func_004df3c0
    /* 3DF3C0 004DF3C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF3C4 004DF3C4 06008014 */  bnez       $4, .L004DF3E0
    /* 3DF3C8 004DF3C8 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF3CC 004DF3CC 7600043C */  lui        $4, %hi(D_00759A88)
    /* 3DF3D0 004DF3D0 B078130C */  jal        func_004de2c0
    /* 3DF3D4 004DF3D4 889A8424 */   addiu     $4, $4, %lo(D_00759A88)
    /* 3DF3D8 004DF3D8 0B000010 */  b          .L004DF408
    /* 3DF3DC 004DF3DC FFFF0224 */   addiu     $2, $0, -0x1
  .L004DF3E0:
    /* 3DF3E0 004DF3E0 01008290 */  lbu        $2, 0x1($4)
    /* 3DF3E4 004DF3E4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DF3E8 004DF3E8 0300422C */  sltiu      $2, $2, 0x3
    /* 3DF3EC 004DF3EC 06004050 */  beql       $2, $0, .L004DF408
    /* 3DF3F0 004DF3F0 2D100000 */   daddu     $2, $0, $0
    /* 3DF3F4 004DF3F4 0400848C */  lw         $4, 0x4($4)
    /* 3DF3F8 004DF3F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF3FC 004DF3FC 7E811308 */  j          func_004e05f8
    /* 3DF400 004DF400 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF404 004DF404 00000000 */  nop
  .L004DF408:
    /* 3DF408 004DF408 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF40C 004DF40C 0800E003 */  jr         $31
    /* 3DF410 004DF410 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF414 004DF414 00000000 */  nop
.size func_004df3c0, 0x58
