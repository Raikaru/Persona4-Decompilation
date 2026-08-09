.section .text
.set noat
.set noreorder
glabel func_004e7a00
    /* 3E7A00 004E7A00 7300023C */  lui        $2, %hi(D_00733FD0)
    /* 3E7A04 004E7A04 2D280000 */  daddu      $5, $0, $0
    /* 3E7A08 004E7A08 D03F4324 */  addiu      $3, $2, %lo(D_00733FD0)
    /* 3E7A0C 004E7A0C 0C000424 */  addiu      $4, $0, 0xC
  .L004E7A10:
    /* 3E7A10 004E7A10 00006280 */  lb         $2, 0x0($3)
    /* 3E7A14 004E7A14 FFFF8424 */  addiu      $4, $4, -0x1
    /* 3E7A18 004E7A18 00004238 */  xori       $2, $2, 0x0
    /* 3E7A1C 004E7A1C 0A286200 */  movz       $5, $3, $2
    /* 3E7A20 004E7A20 00000000 */  nop
    /* 3E7A24 004E7A24 FAFF8104 */  bgez       $4, .L004E7A10
    /* 3E7A28 004E7A28 30006324 */   addiu     $3, $3, 0x30
    /* 3E7A2C 004E7A2C 0800E003 */  jr         $31
    /* 3E7A30 004E7A30 2D10A000 */   daddu     $2, $5, $0
    /* 3E7A34 004E7A34 00000000 */  nop
.size func_004e7a00, 0x38
