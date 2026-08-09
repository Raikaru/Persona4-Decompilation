.section .text
.set noat
.set noreorder
glabel func_004e8ed0
    /* 3E8ED0 004E8ED0 7300063C */  lui        $6, %hi(D_007345F0)
    /* 3E8ED4 004E8ED4 2D380000 */  daddu      $7, $0, $0
    /* 3E8ED8 004E8ED8 F045C324 */  addiu      $3, $6, %lo(D_007345F0)
    /* 3E8EDC 004E8EDC 00006280 */  lb         $2, 0x0($3)
    /* 3E8EE0 004E8EE0 03004014 */  bnez       $2, .L004E8EF0
    /* 3E8EE4 004E8EE4 2D280000 */   daddu     $5, $0, $0
    /* 3E8EE8 004E8EE8 0F000010 */  b          .L004E8F28
    /* 3E8EEC 004E8EEC 2D386000 */   daddu     $7, $3, $0
  .L004E8EF0:
    /* 3E8EF0 004E8EF0 0100A524 */  addiu      $5, $5, 0x1
  .L004E8EF4:
    /* 3E8EF4 004E8EF4 C0100500 */  sll        $2, $5, 3
    /* 3E8EF8 004E8EF8 2000A328 */  slti       $3, $5, 0x20
    /* 3E8EFC 004E8EFC 0A006010 */  beqz       $3, .L004E8F28
    /* 3E8F00 004E8F00 21104500 */   addu      $2, $2, $5
    /* 3E8F04 004E8F04 C0100200 */  sll        $2, $2, 3
    /* 3E8F08 004E8F08 F045C424 */  addiu      $4, $6, %lo(D_007345F0)
    /* 3E8F0C 004E8F0C 23104500 */  subu       $2, $2, $5
    /* 3E8F10 004E8F10 C0100200 */  sll        $2, $2, 3
    /* 3E8F14 004E8F14 21104400 */  addu       $2, $2, $4
    /* 3E8F18 004E8F18 00004380 */  lb         $3, 0x0($2)
    /* 3E8F1C 004E8F1C F5FF6054 */  bnel       $3, $0, .L004E8EF4
    /* 3E8F20 004E8F20 0100A524 */   addiu     $5, $5, 0x1
    /* 3E8F24 004E8F24 2D384000 */  daddu      $7, $2, $0
  .L004E8F28:
    /* 3E8F28 004E8F28 0800E003 */  jr         $31
    /* 3E8F2C 004E8F2C 2D10E000 */   daddu     $2, $7, $0
.size func_004e8ed0, 0x60
