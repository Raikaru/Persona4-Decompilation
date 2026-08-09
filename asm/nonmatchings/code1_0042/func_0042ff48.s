.section .text
.set noat
.set noreorder
glabel func_0042ff48
    /* 32FF48 0042FF48 2D308000 */  daddu      $6, $4, $0
    /* 32FF4C 0042FF4C 70000324 */  addiu      $3, $0, 0x70
    /* 32FF50 0042FF50 1C000424 */  addiu      $4, $0, 0x1C
    /* 32FF54 0042FF54 1818C370 */  mult1      $3, $6, $3
    /* 32FF58 0042FF58 1820A400 */  mult       $4, $5, $4
    /* 32FF5C 0042FF5C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32FF60 0042FF60 8900023C */  lui        $2, %hi(D_00894F90)
    /* 32FF64 0042FF64 0000BFFF */  sd         $31, 0x0($29)
    /* 32FF68 0042FF68 904F4224 */  addiu      $2, $2, %lo(D_00894F90)
    /* 32FF6C 0042FF6C 21208300 */  addu       $4, $4, $3
    /* 32FF70 0042FF70 21104400 */  addu       $2, $2, $4
    /* 32FF74 0042FF74 1000438C */  lw         $3, 0x10($2)
    /* 32FF78 0042FF78 03006014 */  bnez       $3, .L0042FF88
    /* 32FF7C 0042FF7C 2D20C000 */   daddu     $4, $6, $0
    /* 32FF80 0042FF80 04000010 */  b          .L0042FF94
    /* 32FF84 0042FF84 2D100000 */   daddu     $2, $0, $0
  .L0042FF88:
    /* 32FF88 0042FF88 7CBF100C */  jal        func_0042fdf0
    /* 32FF8C 0042FF8C 2D300000 */   daddu     $6, $0, $0
    /* 32FF90 0042FF90 5800428C */  lw         $2, 0x58($2)
  .L0042FF94:
    /* 32FF94 0042FF94 0000BFDF */  ld         $31, 0x0($29)
    /* 32FF98 0042FF98 0800E003 */  jr         $31
    /* 32FF9C 0042FF9C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0042ff48, 0x58
