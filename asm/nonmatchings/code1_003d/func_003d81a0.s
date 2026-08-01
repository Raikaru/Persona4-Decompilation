.section .text
.set noat
.set noreorder
glabel func_003d81a0
    /* 2D81A0 003D81A0 0900812C */  sltiu      $1, $4, 0x9
    /* 2D81A4 003D81A4 05002010 */  beqz       $1, .L003D81BC
    /* 2D81A8 003D81A8 00000000 */   nop
    /* 2D81AC 003D81AC 01000224 */  addiu      $2, $0, 0x1
    /* 2D81B0 003D81B0 04108200 */  sllv       $2, $2, $4
    /* 2D81B4 003D81B4 02000010 */  b          .L003D81C0
    /* 2D81B8 003D81B8 80100200 */   sll       $2, $2, 2
  .L003D81BC:
    /* 2D81BC 003D81BC 2D100000 */  daddu      $2, $0, $0
  .L003D81C0:
    /* 2D81C0 003D81C0 0800E003 */  jr         $31
    /* 2D81C4 003D81C4 00000000 */   nop
    /* 2D81C8 003D81C8 00000000 */  nop
    /* 2D81CC 003D81CC 00000000 */  nop
.size func_003d81a0, 0x30
