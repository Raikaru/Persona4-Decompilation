.section .text
.set noat
.set noreorder
glabel func_001f4b80
    /* F4B80 001F4B80 3000838C */  lw         $3, 0x30($4)
    /* F4B84 001F4B84 A2006290 */  lbu        $2, 0xA2($3)
    /* F4B88 001F4B88 04004010 */  beqz       $2, .L001F4B9C
    /* F4B8C 001F4B8C 00000000 */   nop
    /* F4B90 001F4B90 FFFF0224 */  addiu      $2, $0, -0x1
    /* F4B94 001F4B94 22000010 */  b          .L001F4C20
    /* F4B98 001F4B98 00000000 */   nop
  .L001F4B9C:
    /* F4B9C 001F4B9C A4006294 */  lhu        $2, 0xA4($3)
    /* F4BA0 001F4BA0 0900412C */  sltiu      $1, $2, 0x9
    /* F4BA4 001F4BA4 1D002010 */  beqz       $1, .L001F4C1C
    /* F4BA8 001F4BA8 00000000 */   nop
    /* F4BAC 001F4BAC 7400033C */  lui        $3, %hi(jtbl_00747440)
    /* F4BB0 001F4BB0 40746324 */  addiu      $3, $3, %lo(jtbl_00747440)
    /* F4BB4 001F4BB4 80100200 */  sll        $2, $2, 2
    /* F4BB8 001F4BB8 21104300 */  addu       $2, $2, $3
    /* F4BBC 001F4BBC 0000428C */  lw         $2, 0x0($2)
    /* F4BC0 001F4BC0 08004000 */  jr         $2
    /* F4BC4 001F4BC4 00000000 */   nop
    /* F4BC8 001F4BC8 4D000224 */  addiu      $2, $0, 0x4D
    /* F4BCC 001F4BCC 14000010 */  b          .L001F4C20
    /* F4BD0 001F4BD0 00000000 */   nop
    /* F4BD4 001F4BD4 4E000224 */  addiu      $2, $0, 0x4E
    /* F4BD8 001F4BD8 11000010 */  b          .L001F4C20
    /* F4BDC 001F4BDC 00000000 */   nop
    /* F4BE0 001F4BE0 4F000224 */  addiu      $2, $0, 0x4F
    /* F4BE4 001F4BE4 0E000010 */  b          .L001F4C20
    /* F4BE8 001F4BE8 00000000 */   nop
    /* F4BEC 001F4BEC 50000224 */  addiu      $2, $0, 0x50
    /* F4BF0 001F4BF0 0B000010 */  b          .L001F4C20
    /* F4BF4 001F4BF4 00000000 */   nop
    /* F4BF8 001F4BF8 51000224 */  addiu      $2, $0, 0x51
    /* F4BFC 001F4BFC 08000010 */  b          .L001F4C20
    /* F4C00 001F4C00 00000000 */   nop
    /* F4C04 001F4C04 52000224 */  addiu      $2, $0, 0x52
    /* F4C08 001F4C08 05000010 */  b          .L001F4C20
    /* F4C0C 001F4C0C 00000000 */   nop
    /* F4C10 001F4C10 53000224 */  addiu      $2, $0, 0x53
    /* F4C14 001F4C14 02000010 */  b          .L001F4C20
    /* F4C18 001F4C18 00000000 */   nop
  .L001F4C1C:
    /* F4C1C 001F4C1C FFFF0224 */  addiu      $2, $0, -0x1
  .L001F4C20:
    /* F4C20 001F4C20 0800E003 */  jr         $31
    /* F4C24 001F4C24 00000000 */   nop
    /* F4C28 001F4C28 00000000 */  nop
    /* F4C2C 001F4C2C 00000000 */  nop
.size func_001f4b80, 0xb0
