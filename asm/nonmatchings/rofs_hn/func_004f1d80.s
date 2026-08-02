.section .text
.set noat
.set noreorder
glabel func_004f1d80
    /* 3F1D80 004F1D80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1D84 004F1D84 0000B0FF */  sd         $16, 0x0($29)
    /* 3F1D88 004F1D88 0800BFFF */  sd         $31, 0x8($29)
    /* 3F1D8C 004F1D8C 28D5130C */  jal        func_004f54a0
    /* 3F1D90 004F1D90 2D808000 */   daddu     $16, $4, $0
    /* 3F1D94 004F1D94 7600043C */  lui        $4, %hi(D_0075D408)
    /* 3F1D98 004F1D98 7600063C */  lui        $6, %hi(D_0075D468)
    /* 3F1D9C 004F1D9C 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1DA0 004F1DA0 68D4C624 */  addiu      $6, $6, %lo(D_0075D468)
    /* 3F1DA4 004F1DA4 F7010524 */  addiu      $5, $0, 0x1F7
    /* 3F1DA8 004F1DA8 2D380000 */  daddu      $7, $0, $0
    /* 3F1DAC 004F1DAC 0B000012 */  beqz       $16, .L004F1DDC
    /* 3F1DB0 004F1DB0 9BFF0824 */   addiu     $8, $0, -0x65
    /* 3F1DB4 004F1DB4 34000286 */  lh         $2, 0x34($16)
    /* 3F1DB8 004F1DB8 0D004054 */  bnel       $2, $0, .L004F1DF0
    /* 3F1DBC 004F1DBC 2400028E */   lw        $2, 0x24($16)
    /* 3F1DC0 004F1DC0 7600043C */  lui        $4, %hi(D_0075D408)
    /* 3F1DC4 004F1DC4 7600063C */  lui        $6, %hi(D_0075D468)
    /* 3F1DC8 004F1DC8 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1DCC 004F1DCC 68D4C624 */  addiu      $6, $6, %lo(D_0075D468)
    /* 3F1DD0 004F1DD0 FA010524 */  addiu      $5, $0, 0x1FA
    /* 3F1DD4 004F1DD4 2D380000 */  daddu      $7, $0, $0
    /* 3F1DD8 004F1DD8 9BFF0824 */  addiu      $8, $0, -0x65
  .L004F1DDC:
    /* 3F1DDC 004F1DDC F0D4130C */  jal        func_004f53c0
    /* 3F1DE0 004F1DE0 00000000 */   nop
    /* 3F1DE4 004F1DE4 05000010 */  b          .L004F1DFC
    /* 3F1DE8 004F1DE8 2D104000 */   daddu     $2, $2, $0
    /* 3F1DEC 004F1DEC 00000000 */  nop
  .L004F1DF0:
    /* 3F1DF0 004F1DF0 2800038E */  lw         $3, 0x28($16)
    /* 3F1DF4 004F1DF4 C0120200 */  sll        $2, $2, 11
    /* 3F1DF8 004F1DF8 21104300 */  addu       $2, $2, $3
  .L004F1DFC:
    /* 3F1DFC 004F1DFC 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1E00 004F1E00 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1E04 004F1E04 0800E003 */  jr         $31
    /* 3F1E08 004F1E08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1E0C 004F1E0C 00000000 */  nop
.size func_004f1d80, 0x90
