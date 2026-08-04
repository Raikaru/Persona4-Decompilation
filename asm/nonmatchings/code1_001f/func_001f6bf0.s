.section .text
.set noat
.set noreorder
glabel func_001f6bf0
    /* F6BF0 001F6BF0 2D280000 */  daddu      $5, $0, $0
    /* F6BF4 001F6BF4 01000324 */  addiu      $3, $0, 0x1
    /* F6BF8 001F6BF8 0B000010 */  b          .L001F6C28
    /* F6BFC 001F6BFC 00000000 */   nop
  .L001F6C00:
    /* F6C00 001F6C00 0410A300 */  sllv       $2, $3, $5
    /* F6C04 001F6C04 07004314 */  bne        $2, $3, .L001F6C24
    /* F6C08 001F6C08 00000000 */   nop
    /* F6C0C 001F6C0C 2110A400 */  addu       $2, $5, $4
    /* F6C10 001F6C10 F6034290 */  lbu        $2, 0x3F6($2)
    /* F6C14 001F6C14 02004228 */  slti       $2, $2, 0x2
    /* F6C18 001F6C18 01004238 */  xori       $2, $2, 0x1
    /* F6C1C 001F6C1C 06000010 */  b          .L001F6C38
    /* F6C20 001F6C20 00000000 */   nop
  .L001F6C24:
    /* F6C24 001F6C24 0100A524 */  addiu      $5, $5, 0x1
  .L001F6C28:
    /* F6C28 001F6C28 1800A22C */  sltiu      $2, $5, 0x18
    /* F6C2C 001F6C2C F4FF4014 */  bnez       $2, .L001F6C00
    /* F6C30 001F6C30 00000000 */   nop
    /* F6C34 001F6C34 01000224 */  addiu      $2, $0, 0x1
  .L001F6C38:
    /* F6C38 001F6C38 0800E003 */  jr         $31
    /* F6C3C 001F6C3C 00000000 */   nop
.size func_001f6bf0, 0x50
