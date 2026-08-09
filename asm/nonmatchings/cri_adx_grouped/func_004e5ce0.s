.section .text
.set noat
.set noreorder
glabel func_004e5ce0
    /* 3E5CE0 004E5CE0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3E5CE4 004E5CE4 2D100000 */  daddu      $2, $0, $0
    /* 3E5CE8 004E5CE8 3000B0FF */  sd         $16, 0x30($29)
    /* 3E5CEC 004E5CEC 2D808000 */  daddu      $16, $4, $0
    /* 3E5CF0 004E5CF0 3800B1FF */  sd         $17, 0x38($29)
    /* 3E5CF4 004E5CF4 17000012 */  beqz       $16, .L004E5D54
    /* 3E5CF8 004E5CF8 4000BFFF */   sd        $31, 0x40($29)
    /* 3E5CFC 004E5CFC AC9B130C */  jal        func_004e6eb0
    /* 3E5D00 004E5D00 2D28A003 */   daddu     $5, $29, $0
    /* 3E5D04 004E5D04 7300033C */  lui        $3, %hi(D_00733C80)
    /* 3E5D08 004E5D08 0400A28F */  lw         $2, 0x4($29)
    /* 3E5D0C 004E5D0C 803C7124 */  addiu      $17, $3, %lo(D_00733C80)
    /* 3E5D10 004E5D10 2D200002 */  daddu      $4, $16, $0
    /* 3E5D14 004E5D14 0E004014 */  bnez       $2, .L004E5D50
    /* 3E5D18 004E5D18 2D282002 */   daddu     $5, $17, $0
    /* 3E5D1C 004E5D1C 9099130C */  jal        func_004e6640
    /* 3E5D20 004E5D20 00000000 */   nop
    /* 3E5D24 004E5D24 8691130C */  jal        func_004e4618
    /* 3E5D28 004E5D28 00810434 */   ori       $4, $0, 0x8100
    /* 3E5D2C 004E5D2C F2B9100C */  jal        func_0042e7c8
    /* 3E5D30 004E5D30 2D200000 */   daddu     $4, $0, $0
    /* 3E5D34 004E5D34 8691130C */  jal        func_004e4618
    /* 3E5D38 004E5D38 01810434 */   ori       $4, $0, 0x8101
    /* 3E5D3C 004E5D3C 2D282002 */  daddu      $5, $17, $0
    /* 3E5D40 004E5D40 9A96130C */  jal        func_004e5a68
    /* 3E5D44 004E5D44 2D20A003 */   daddu     $4, $29, $0
    /* 3E5D48 004E5D48 03004010 */  beqz       $2, .L004E5D58
    /* 3E5D4C 004E5D4C 3000B0DF */   ld        $16, 0x30($29)
  .L004E5D50:
    /* 3E5D50 004E5D50 01000224 */  addiu      $2, $0, 0x1
  .L004E5D54:
    /* 3E5D54 004E5D54 3000B0DF */  ld         $16, 0x30($29)
  .L004E5D58:
    /* 3E5D58 004E5D58 3800B1DF */  ld         $17, 0x38($29)
    /* 3E5D5C 004E5D5C 4000BFDF */  ld         $31, 0x40($29)
    /* 3E5D60 004E5D60 0800E003 */  jr         $31
    /* 3E5D64 004E5D64 5000BD27 */   addiu     $29, $29, 0x50
.size func_004e5ce0, 0x88
