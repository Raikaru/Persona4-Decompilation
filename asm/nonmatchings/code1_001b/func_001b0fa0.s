.section .text
.set noat
.set noreorder
glabel func_001b0fa0
    /* B0FA0 001B0FA0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B0FA4 001B0FA4 9C024524 */  addiu      $5, $2, 0x29C
    /* B0FA8 001B0FA8 2D180000 */  daddu      $3, $0, $0
    /* B0FAC 001B0FAC 06000010 */  b          .L001B0FC8
    /* B0FB0 001B0FB0 00000000 */   nop
  .L001B0FB4:
    /* B0FB4 001B0FB4 0000A28C */  lw         $2, 0x0($5)
    /* B0FB8 001B0FB8 06004410 */  beq        $2, $4, .L001B0FD4
    /* B0FBC 001B0FBC 00000000 */   nop
    /* B0FC0 001B0FC0 0400A524 */  addiu      $5, $5, 0x4
    /* B0FC4 001B0FC4 01006324 */  addiu      $3, $3, 0x1
  .L001B0FC8:
    /* B0FC8 001B0FC8 0C00622C */  sltiu      $2, $3, 0xC
    /* B0FCC 001B0FCC F9FF4014 */  bnez       $2, .L001B0FB4
    /* B0FD0 001B0FD0 00000000 */   nop
  .L001B0FD4:
    /* B0FD4 001B0FD4 0C000224 */  addiu      $2, $0, 0xC
    /* B0FD8 001B0FD8 0A006214 */  bne        $3, $2, .L001B1004
    /* B0FDC 001B0FDC 00000000 */   nop
    /* B0FE0 001B0FE0 2D100000 */  daddu      $2, $0, $0
    /* B0FE4 001B0FE4 0C000010 */  b          .L001B1018
    /* B0FE8 001B0FE8 00000000 */   nop
  .L001B0FEC:
    /* B0FEC 001B0FEC 0400A28C */  lw         $2, 0x4($5)
    /* B0FF0 001B0FF0 07004010 */  beqz       $2, .L001B1010
    /* B0FF4 001B0FF4 00000000 */   nop
    /* B0FF8 001B0FF8 0000A2AC */  sw         $2, 0x0($5)
    /* B0FFC 001B0FFC 0400A524 */  addiu      $5, $5, 0x4
    /* B1000 001B1000 01006324 */  addiu      $3, $3, 0x1
  .L001B1004:
    /* B1004 001B1004 0B00622C */  sltiu      $2, $3, 0xB
    /* B1008 001B1008 F8FF4014 */  bnez       $2, .L001B0FEC
    /* B100C 001B100C 00000000 */   nop
  .L001B1010:
    /* B1010 001B1010 0000A4AC */  sw         $4, 0x0($5)
    /* B1014 001B1014 01000224 */  addiu      $2, $0, 0x1
  .L001B1018:
    /* B1018 001B1018 0800E003 */  jr         $31
    /* B101C 001B101C 00000000 */   nop
.size func_001b0fa0, 0x80
