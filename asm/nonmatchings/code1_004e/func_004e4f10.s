.section .text
.set noat
.set noreorder
glabel func_004e4f10
    /* 3E4F10 004E4F10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E4F14 004E4F14 0800B1FF */  sd         $17, 0x8($29)
    /* 3E4F18 004E4F18 1000B2FF */  sd         $18, 0x10($29)
    /* 3E4F1C 004E4F1C 2D908000 */  daddu      $18, $4, $0
    /* 3E4F20 004E4F20 1800B3FF */  sd         $19, 0x18($29)
    /* 3E4F24 004E4F24 0000B0FF */  sd         $16, 0x0($29)
    /* 3E4F28 004E4F28 2000BFFF */  sd         $31, 0x20($29)
    /* 3E4F2C 004E4F2C 14B5130C */  jal        func_004ed450
    /* 3E4F30 004E4F30 2D98A000 */   daddu     $19, $5, $0
    /* 3E4F34 004E4F34 7300023C */  lui        $2, %hi(D_00731C88)
    /* 3E4F38 004E4F38 881C5124 */  addiu      $17, $2, %lo(D_00731C88)
    /* 3E4F3C 004E4F3C 00002382 */  lb         $3, 0x0($17)
    /* 3E4F40 004E4F40 0C006010 */  beqz       $3, .L004E4F74
    /* 3E4F44 004E4F44 2D280000 */   daddu     $5, $0, $0
    /* 3E4F48 004E4F48 2D302002 */  daddu      $6, $17, $0
    /* 3E4F4C 004E4F4C 2D202002 */  daddu      $4, $17, $0
  .L004E4F50:
    /* 3E4F50 004E4F50 0100A524 */  addiu      $5, $5, 0x1
    /* 3E4F54 004E4F54 40008424 */  addiu      $4, $4, 0x40
    /* 3E4F58 004E4F58 2000A228 */  slti       $2, $5, 0x20
    /* 3E4F5C 004E4F5C 05004010 */  beqz       $2, .L004E4F74
    /* 3E4F60 004E4F60 80190500 */   sll       $3, $5, 6
    /* 3E4F64 004E4F64 00008280 */  lb         $2, 0x0($4)
    /* 3E4F68 004E4F68 00000000 */  nop
    /* 3E4F6C 004E4F6C F8FF4014 */  bnez       $2, .L004E4F50
    /* 3E4F70 004E4F70 21886600 */   addu      $17, $3, $6
  .L004E4F74:
    /* 3E4F74 004E4F74 20000224 */  addiu      $2, $0, 0x20
    /* 3E4F78 004E4F78 0900A214 */  bne        $5, $2, .L004E4FA0
    /* 3E4F7C 004E4F7C 2D202002 */   daddu     $4, $17, $0
    /* 3E4F80 004E4F80 7600043C */  lui        $4, %hi(D_0075AEE0)
    /* 3E4F84 004E4F84 20000524 */  addiu      $5, $0, 0x20
    /* 3E4F88 004E4F88 E0AE8424 */  addiu      $4, $4, %lo(D_0075AEE0)
    /* 3E4F8C 004E4F8C FC34130C */  jal        func_004cd3f0
    /* 3E4F90 004E4F90 20000624 */   addiu     $6, $0, 0x20
    /* 3E4F94 004E4F94 0F000010 */  b          .L004E4FD4
    /* 3E4F98 004E4F98 2D880000 */   daddu     $17, $0, $0
    /* 3E4F9C 004E4F9C 00000000 */  nop
  .L004E4FA0:
    /* 3E4FA0 004E4FA0 2D280000 */  daddu      $5, $0, $0
    /* 3E4FA4 004E4FA4 40000624 */  addiu      $6, $0, 0x40
    /* 3E4FA8 004E4FA8 72FE100C */  jal        func_0043f9c8
    /* 3E4FAC 004E4FAC 40001024 */   addiu     $16, $0, 0x40
    /* 3E4FB0 004E4FB0 010020A2 */  sb         $0, 0x1($17)
    /* 3E4FB4 004E4FB4 01000224 */  addiu      $2, $0, 0x1
    /* 3E4FB8 004E4FB8 380030AE */  sw         $16, 0x38($17)
    /* 3E4FBC 004E4FBC 040032AE */  sw         $18, 0x4($17)
    /* 3E4FC0 004E4FC0 080033AE */  sw         $19, 0x8($17)
    /* 3E4FC4 004E4FC4 000022A2 */  sb         $2, 0x0($17)
    /* 3E4FC8 004E4FC8 020020A2 */  sb         $0, 0x2($17)
    /* 3E4FCC 004E4FCC 300022AE */  sw         $2, 0x30($17)
    /* 3E4FD0 004E4FD0 340020AE */  sw         $0, 0x34($17)
  .L004E4FD4:
    /* 3E4FD4 004E4FD4 1AB5130C */  jal        func_004ed468
    /* 3E4FD8 004E4FD8 00000000 */   nop
    /* 3E4FDC 004E4FDC 2D102002 */  daddu      $2, $17, $0
    /* 3E4FE0 004E4FE0 0000B0DF */  ld         $16, 0x0($29)
    /* 3E4FE4 004E4FE4 0800B1DF */  ld         $17, 0x8($29)
    /* 3E4FE8 004E4FE8 1000B2DF */  ld         $18, 0x10($29)
    /* 3E4FEC 004E4FEC 1800B3DF */  ld         $19, 0x18($29)
    /* 3E4FF0 004E4FF0 2000BFDF */  ld         $31, 0x20($29)
    /* 3E4FF4 004E4FF4 0800E003 */  jr         $31
    /* 3E4FF8 004E4FF8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3E4FFC 004E4FFC 00000000 */  nop
.size func_004e4f10, 0xf0
