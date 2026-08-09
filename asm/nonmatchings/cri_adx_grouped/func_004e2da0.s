.section .text
.set noat
.set noreorder
glabel func_004e2da0
    /* 3E2DA0 004E2DA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E2DA4 004E2DA4 06008014 */  bnez       $4, .L004E2DC0
    /* 3E2DA8 004E2DA8 0000BFFF */   sd        $31, 0x0($29)
    /* 3E2DAC 004E2DAC 7600043C */  lui        $4, %hi(D_0075A6A0)
    /* 3E2DB0 004E2DB0 6A85130C */  jal        func_004e15a8
    /* 3E2DB4 004E2DB4 A0A68424 */   addiu     $4, $4, %lo(D_0075A6A0)
    /* 3E2DB8 004E2DB8 17000010 */  b          .L004E2E18
    /* 3E2DBC 004E2DBC 2D100000 */   daddu     $2, $0, $0
  .L004E2DC0:
    /* 3E2DC0 004E2DC0 9200023C */  lui        $2, %hi(D_00923440)
    /* 3E2DC4 004E2DC4 0000848C */  lw         $4, 0x0($4)
    /* 3E2DC8 004E2DC8 40344324 */  addiu      $3, $2, %lo(D_00923440)
    /* 3E2DCC 004E2DCC 2D300000 */  daddu      $6, $0, $0
    /* 3E2DD0 004E2DD0 0000628C */  lw         $2, 0x0($3)
    /* 3E2DD4 004E2DD4 0D004410 */  beq        $2, $4, .L004E2E0C
    /* 3E2DD8 004E2DD8 2D280000 */   daddu     $5, $0, $0
    /* 3E2DDC 004E2DDC 2D386000 */  daddu      $7, $3, $0
    /* 3E2DE0 004E2DE0 0100C624 */  addiu      $6, $6, 0x1
    /* 3E2DE4 004E2DE4 00000000 */  nop
  .L004E2DE8:
    /* 3E2DE8 004E2DE8 00290600 */  sll        $5, $6, 4
    /* 3E2DEC 004E2DEC 2000C228 */  slti       $2, $6, 0x20
    /* 3E2DF0 004E2DF0 06004010 */  beqz       $2, .L004E2E0C
    /* 3E2DF4 004E2DF4 2118A700 */   addu      $3, $5, $7
    /* 3E2DF8 004E2DF8 0000628C */  lw         $2, 0x0($3)
    /* 3E2DFC 004E2DFC 00000000 */  nop
    /* 3E2E00 004E2E00 00000000 */  nop
    /* 3E2E04 004E2E04 F8FF4454 */  bnel       $2, $4, .L004E2DE8
    /* 3E2E08 004E2E08 0100C624 */   addiu     $6, $6, 0x1
  .L004E2E0C:
    /* 3E2E0C 004E2E0C 9200023C */  lui        $2, %hi(D_00923444)
    /* 3E2E10 004E2E10 44344224 */  addiu      $2, $2, %lo(D_00923444)
    /* 3E2E14 004E2E14 21104500 */  addu       $2, $2, $5
  .L004E2E18:
    /* 3E2E18 004E2E18 0000BFDF */  ld         $31, 0x0($29)
    /* 3E2E1C 004E2E1C 0800E003 */  jr         $31
    /* 3E2E20 004E2E20 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E2E24 004E2E24 00000000 */  nop
.size func_004e2da0, 0x88
