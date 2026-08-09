.section .text
.set noat
.set noreorder
glabel func_004c0f08
    /* 3C0F08 004C0F08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C0F0C 004C0F0C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C0F10 004C0F10 2D808000 */  daddu      $16, $4, $0
    /* 3C0F14 004C0F14 0800BFFF */  sd         $31, 0x8($29)
    /* 3C0F18 004C0F18 0400028E */  lw         $2, 0x4($16)
    /* 3C0F1C 004C0F1C 04004010 */  beqz       $2, .L004C0F30
    /* 3C0F20 004C0F20 08000426 */   addiu     $4, $16, 0x8
    /* 3C0F24 004C0F24 7500043C */  lui        $4, %hi(D_00757508)
    /* 3C0F28 004C0F28 08000010 */  b          .L004C0F4C
    /* 3C0F2C 004C0F2C 08758424 */   addiu     $4, $4, %lo(D_00757508)
  .L004C0F30:
    /* 3C0F30 004C0F30 AEF5120C */  jal        func_004bd6b8
    /* 3C0F34 004C0F34 44000524 */   addiu     $5, $0, 0x44
    /* 3C0F38 004C0F38 2D280000 */  daddu      $5, $0, $0
    /* 3C0F3C 004C0F3C 7500043C */  lui        $4, %hi(D_00757538)
    /* 3C0F40 004C0F40 040002AE */  sw         $2, 0x4($16)
    /* 3C0F44 004C0F44 06004014 */  bnez       $2, .L004C0F60
    /* 3C0F48 004C0F48 38758424 */   addiu     $4, $4, %lo(D_00757538)
  .L004C0F4C:
    /* 3C0F4C 004C0F4C A8F5120C */  jal        func_004bd6a0
    /* 3C0F50 004C0F50 00000000 */   nop
    /* 3C0F54 004C0F54 08000010 */  b          .L004C0F78
    /* 3C0F58 004C0F58 2D100000 */   daddu     $2, $0, $0
    /* 3C0F5C 004C0F5C 00000000 */  nop
  .L004C0F60:
    /* 3C0F60 004C0F60 2D204000 */  daddu      $4, $2, $0
    /* 3C0F64 004C0F64 2D300000 */  daddu      $6, $0, $0
    /* 3C0F68 004C0F68 2D380000 */  daddu      $7, $0, $0
    /* 3C0F6C 004C0F6C E4F5120C */  jal        func_004bd790
    /* 3C0F70 004C0F70 2D400000 */   daddu     $8, $0, $0
    /* 3C0F74 004C0F74 01000224 */  addiu      $2, $0, 0x1
  .L004C0F78:
    /* 3C0F78 004C0F78 0000B0DF */  ld         $16, 0x0($29)
    /* 3C0F7C 004C0F7C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C0F80 004C0F80 0800E003 */  jr         $31
    /* 3C0F84 004C0F84 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c0f08, 0x80
