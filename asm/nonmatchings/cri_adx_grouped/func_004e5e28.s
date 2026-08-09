.section .text
.set noat
.set noreorder
glabel func_004e5e28
    /* 3E5E28 004E5E28 7300023C */  lui        $2, %hi(D_00733140)
    /* 3E5E2C 004E5E2C 2D280000 */  daddu      $5, $0, $0
    /* 3E5E30 004E5E30 40314324 */  addiu      $3, $2, %lo(D_00733140)
    /* 3E5E34 004E5E34 27000424 */  addiu      $4, $0, 0x27
  .L004E5E38:
    /* 3E5E38 004E5E38 00006280 */  lb         $2, 0x0($3)
    /* 3E5E3C 004E5E3C FFFF8424 */  addiu      $4, $4, -0x1
    /* 3E5E40 004E5E40 00004238 */  xori       $2, $2, 0x0
    /* 3E5E44 004E5E44 0A286200 */  movz       $5, $3, $2
    /* 3E5E48 004E5E48 00000000 */  nop
    /* 3E5E4C 004E5E4C FAFF8104 */  bgez       $4, .L004E5E38
    /* 3E5E50 004E5E50 48006324 */   addiu     $3, $3, 0x48
    /* 3E5E54 004E5E54 0800E003 */  jr         $31
    /* 3E5E58 004E5E58 2D10A000 */   daddu     $2, $5, $0
    /* 3E5E5C 004E5E5C 00000000 */  nop
.size func_004e5e28, 0x38
