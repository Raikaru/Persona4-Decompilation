.section .text
.set noat
.set noreorder
glabel func_004d5af8
    /* 3D5AF8 004D5AF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5AFC 004D5AFC 06008014 */  bnez       $4, .L004D5B18
    /* 3D5B00 004D5B00 0000BFFF */   sd        $31, 0x0($29)
    /* 3D5B04 004D5B04 7600043C */  lui        $4, %hi(D_00759070)
    /* 3D5B08 004D5B08 A61A130C */  jal        func_004c6a98
    /* 3D5B0C 004D5B0C 70908424 */   addiu     $4, $4, %lo(D_00759070)
    /* 3D5B10 004D5B10 04000010 */  b          .L004D5B24
    /* 3D5B14 004D5B14 FFFF0224 */   addiu     $2, $0, -0x1
  .L004D5B18:
    /* 3D5B18 004D5B18 01008280 */  lb         $2, 0x1($4)
    /* 3D5B1C 004D5B1C 05004238 */  xori       $2, $2, 0x5
    /* 3D5B20 004D5B20 0100422C */  sltiu      $2, $2, 0x1
  .L004D5B24:
    /* 3D5B24 004D5B24 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5B28 004D5B28 0800E003 */  jr         $31
    /* 3D5B2C 004D5B2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5af8, 0x38
