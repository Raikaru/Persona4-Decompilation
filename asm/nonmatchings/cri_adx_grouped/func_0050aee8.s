.section .text
.set noat
.set noreorder
glabel func_0050aee8
    /* 40AEE8 0050AEE8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40AEEC 0050AEEC E0000524 */  addiu      $5, $0, 0xE0
    /* 40AEF0 0050AEF0 1000BFFF */  sd         $31, 0x10($29)
    /* 40AEF4 0050AEF4 9CA8140C */  jal        func_0052a270
    /* 40AEF8 0050AEF8 2D30A003 */   daddu     $6, $29, $0
    /* 40AEFC 0050AEFC 01000324 */  addiu      $3, $0, 0x1
    /* 40AF00 0050AF00 12004314 */  bne        $2, $3, .L0050AF4C
    /* 40AF04 0050AF04 11000224 */   addiu     $2, $0, 0x11
    /* 40AF08 0050AF08 0000A38F */  lw         $3, 0x0($29)
    /* 40AF0C 0050AF0C 0900622C */  sltiu      $2, $3, 0x9
    /* 40AF10 0050AF10 0E004010 */  beqz       $2, .L0050AF4C
    /* 40AF14 0050AF14 11000224 */   addiu     $2, $0, 0x11
    /* 40AF18 0050AF18 80100300 */  sll        $2, $3, 2
    /* 40AF1C 0050AF1C 7600033C */  lui        $3, %hi(jtbl_0075E850)
    /* 40AF20 0050AF20 21186200 */  addu       $3, $3, $2
    /* 40AF24 0050AF24 50E8638C */  lw         $3, %lo(jtbl_0075E850)($3)
    /* 40AF28 0050AF28 08006000 */  jr         $3
    /* 40AF2C 0050AF2C 00000000 */   nop
    /* 40AF30 0050AF30 06000010 */  b          .L0050AF4C
    /* 40AF34 0050AF34 21000224 */   addiu     $2, $0, 0x21
    /* 40AF38 0050AF38 04000010 */  b          .L0050AF4C
    /* 40AF3C 0050AF3C 51000224 */   addiu     $2, $0, 0x51
    /* 40AF40 0050AF40 02000010 */  b          .L0050AF4C
    /* 40AF44 0050AF44 61000224 */   addiu     $2, $0, 0x61
    /* 40AF48 0050AF48 11000224 */  addiu      $2, $0, 0x11
  .L0050AF4C:
    /* 40AF4C 0050AF4C 1000BFDF */  ld         $31, 0x10($29)
    /* 40AF50 0050AF50 0800E003 */  jr         $31
    /* 40AF54 0050AF54 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050aee8, 0x70
