.section .text
.set noat
.set noreorder
glabel func_004f1ce0
    /* 3F1CE0 004F1CE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1CE4 004F1CE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3F1CE8 004F1CE8 0800BFFF */  sd         $31, 0x8($29)
    /* 3F1CEC 004F1CEC 28D5130C */  jal        func_004f54a0
    /* 3F1CF0 004F1CF0 2D808000 */   daddu     $16, $4, $0
    /* 3F1CF4 004F1CF4 7600043C */  lui        $4, %hi(D_0075D408)
    /* 3F1CF8 004F1CF8 7600063C */  lui        $6, %hi(D_0075D458)
    /* 3F1CFC 004F1CFC 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1D00 004F1D00 58D4C624 */  addiu      $6, $6, %lo(D_0075D458)
    /* 3F1D04 004F1D04 E5010524 */  addiu      $5, $0, 0x1E5
    /* 3F1D08 004F1D08 2D380000 */  daddu      $7, $0, $0
    /* 3F1D0C 004F1D0C 06000016 */  bnez       $16, .L004F1D28
    /* 3F1D10 004F1D10 9BFF0824 */   addiu     $8, $0, -0x65
    /* 3F1D14 004F1D14 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1D18 004F1D18 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1D1C 004F1D1C F0D41308 */  j          func_004f53c0
    /* 3F1D20 004F1D20 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1D24 004F1D24 00000000 */  nop
  .L004F1D28:
    /* 3F1D28 004F1D28 34000286 */  lh         $2, 0x34($16)
    /* 3F1D2C 004F1D2C 0C004054 */  bnel       $2, $0, .L004F1D60
    /* 3F1D30 004F1D30 2400028E */   lw        $2, 0x24($16)
    /* 3F1D34 004F1D34 7600043C */  lui        $4, %hi(D_0075D408)
    /* 3F1D38 004F1D38 7600063C */  lui        $6, %hi(D_0075D458)
    /* 3F1D3C 004F1D3C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1D40 004F1D40 08D48424 */  addiu      $4, $4, %lo(D_0075D408)
    /* 3F1D44 004F1D44 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1D48 004F1D48 58D4C624 */  addiu      $6, $6, %lo(D_0075D458)
    /* 3F1D4C 004F1D4C E8010524 */  addiu      $5, $0, 0x1E8
    /* 3F1D50 004F1D50 2D380000 */  daddu      $7, $0, $0
    /* 3F1D54 004F1D54 9BFF0824 */  addiu      $8, $0, -0x65
    /* 3F1D58 004F1D58 F0D41308 */  j          func_004f53c0
    /* 3F1D5C 004F1D5C 1000BD27 */   addiu     $29, $29, 0x10
  .L004F1D60:
    /* 3F1D60 004F1D60 2800038E */  lw         $3, 0x28($16)
    /* 3F1D64 004F1D64 C0120200 */  sll        $2, $2, 11
    /* 3F1D68 004F1D68 0800BFDF */  ld         $31, 0x8($29)
    /* 3F1D6C 004F1D6C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F1D70 004F1D70 21104300 */  addu       $2, $2, $3
    /* 3F1D74 004F1D74 0800E003 */  jr         $31
    /* 3F1D78 004F1D78 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1D7C 004F1D7C 00000000 */  nop
.size func_004f1ce0, 0xa0
