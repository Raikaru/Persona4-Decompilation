.section .text
.set noat
.set noreorder
glabel func_004f63c0
    /* 3F63C0 004F63C0 7400023C */  lui        $2, %hi(D_00743B58)
    /* 3F63C4 004F63C4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F63C8 004F63C8 583B428C */  lw         $2, %lo(D_00743B58)($2)
    /* 3F63CC 004F63CC 0A004010 */  beqz       $2, .L004F63F8
    /* 3F63D0 004F63D0 0000BFFF */   sd        $31, 0x0($29)
    /* 3F63D4 004F63D4 3000428C */  lw         $2, 0x30($2)
    /* 3F63D8 004F63D8 08004050 */  beql       $2, $0, .L004F63FC
    /* 3F63DC 004F63DC 7600043C */   lui       $4, %hi(D_0075DA28)
    /* 3F63E0 004F63E0 09F84000 */  jalr       $2
    /* 3F63E4 004F63E4 00000000 */   nop
    /* 3F63E8 004F63E8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F63EC 004F63EC 0800E003 */  jr         $31
    /* 3F63F0 004F63F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F63F4 004F63F4 00000000 */  nop
  .L004F63F8:
    /* 3F63F8 004F63F8 7600043C */  lui        $4, %hi(D_0075DA28)
  .L004F63FC:
    /* 3F63FC 004F63FC 7600063C */  lui        $6, %hi(D_0075DA70)
    /* 3F6400 004F6400 0000BFDF */  ld         $31, 0x0($29)
    /* 3F6404 004F6404 28DA8424 */  addiu      $4, $4, %lo(D_0075DA28)
    /* 3F6408 004F6408 70DAC624 */  addiu      $6, $6, %lo(D_0075DA70)
    /* 3F640C 004F640C EF000524 */  addiu      $5, $0, 0xEF
    /* 3F6410 004F6410 2D380000 */  daddu      $7, $0, $0
    /* 3F6414 004F6414 35FF0824 */  addiu      $8, $0, -0xCB
    /* 3F6418 004F6418 F0D41308 */  j          func_004f53c0
    /* 3F641C 004F641C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f63c0, 0x60
