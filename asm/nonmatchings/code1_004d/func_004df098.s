.section .text
.set noat
.set noreorder
glabel func_004df098
    /* 3DF098 004DF098 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF09C 004DF09C 06008014 */  bnez       $4, .L004DF0B8
    /* 3DF0A0 004DF0A0 0000BFFF */   sd        $31, 0x0($29)
    /* 3DF0A4 004DF0A4 7600043C */  lui        $4, %hi(D_007598C0)
    /* 3DF0A8 004DF0A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF0AC 004DF0AC C0988424 */  addiu      $4, $4, %lo(D_007598C0)
    /* 3DF0B0 004DF0B0 B0781308 */  j          func_004de2c0
    /* 3DF0B4 004DF0B4 1000BD27 */   addiu     $29, $29, 0x10
  .L004DF0B8:
    /* 3DF0B8 004DF0B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3DF0BC 004DF0BC B10185A0 */  sb         $5, 0x1B1($4)
    /* 3DF0C0 004DF0C0 0800E003 */  jr         $31
    /* 3DF0C4 004DF0C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df098, 0x30
