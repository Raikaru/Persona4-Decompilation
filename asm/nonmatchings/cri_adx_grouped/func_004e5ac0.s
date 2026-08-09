.section .text
.set noat
.set noreorder
glabel func_004e5ac0
    /* 3E5AC0 004E5AC0 7300023C */  lui        $2, %hi(D_00733140)
    /* 3E5AC4 004E5AC4 2D280000 */  daddu      $5, $0, $0
    /* 3E5AC8 004E5AC8 40314424 */  addiu      $4, $2, %lo(D_00733140)
    /* 3E5ACC 004E5ACC 01000724 */  addiu      $7, $0, 0x1
    /* 3E5AD0 004E5AD0 02000624 */  addiu      $6, $0, 0x2
    /* 3E5AD4 004E5AD4 00000000 */  nop
  .L004E5AD8:
    /* 3E5AD8 004E5AD8 00008280 */  lb         $2, 0x0($4)
    /* 3E5ADC 004E5ADC 05004754 */  bnel       $2, $7, .L004E5AF4
    /* 3E5AE0 004E5AE0 0100A524 */   addiu     $5, $5, 0x1
    /* 3E5AE4 004E5AE4 02008380 */  lb         $3, 0x2($4)
    /* 3E5AE8 004E5AE8 07006610 */  beq        $3, $6, .L004E5B08
    /* 3E5AEC 004E5AEC 01000224 */   addiu     $2, $0, 0x1
    /* 3E5AF0 004E5AF0 0100A524 */  addiu      $5, $5, 0x1
  .L004E5AF4:
    /* 3E5AF4 004E5AF4 2800A228 */  slti       $2, $5, 0x28
    /* 3E5AF8 004E5AF8 00000000 */  nop
    /* 3E5AFC 004E5AFC F6FF4014 */  bnez       $2, .L004E5AD8
    /* 3E5B00 004E5B00 48008424 */   addiu     $4, $4, 0x48
    /* 3E5B04 004E5B04 2D100000 */  daddu      $2, $0, $0
  .L004E5B08:
    /* 3E5B08 004E5B08 0800E003 */  jr         $31
    /* 3E5B0C 004E5B0C 00000000 */   nop
.size func_004e5ac0, 0x50
