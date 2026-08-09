.section .text
.set noat
.set noreorder
glabel func_001f8ea0
    /* F8EA0 001F8EA0 3000868C */  lw         $6, 0x30($4)
    /* F8EA4 001F8EA4 A200C290 */  lbu        $2, 0xA2($6)
    /* F8EA8 001F8EA8 04004010 */  beqz       $2, .L001F8EBC
    /* F8EAC 001F8EAC 00000000 */   nop
    /* F8EB0 001F8EB0 FFFF0224 */  addiu      $2, $0, -0x1
    /* F8EB4 001F8EB4 20000010 */  b          .L001F8F38
    /* F8EB8 001F8EB8 00000000 */   nop
  .L001F8EBC:
    /* F8EBC 001F8EBC ACB3828F */  lw         $2, -0x4C54($28)
    /* F8EC0 001F8EC0 7001428C */  lw         $2, 0x170($2)
    /* F8EC4 001F8EC4 04004414 */  bne        $2, $4, .L001F8ED8
    /* F8EC8 001F8EC8 00000000 */   nop
    /* F8ECC 001F8ECC FFFF0224 */  addiu      $2, $0, -0x1
    /* F8ED0 001F8ED0 19000010 */  b          .L001F8F38
    /* F8ED4 001F8ED4 00000000 */   nop
  .L001F8ED8:
    /* F8ED8 001F8ED8 10000724 */  addiu      $7, $0, 0x10
    /* F8EDC 001F8EDC 01000424 */  addiu      $4, $0, 0x1
    /* F8EE0 001F8EE0 05000324 */  addiu      $3, $0, 0x5
    /* F8EE4 001F8EE4 0A000010 */  b          .L001F8F10
    /* F8EE8 001F8EE8 00000000 */   nop
  .L001F8EEC:
    /* F8EEC 001F8EEC 0B008510 */  beq        $4, $5, .L001F8F1C
    /* F8EF0 001F8EF0 00000000 */   nop
    /* F8EF4 001F8EF4 05008310 */  beq        $4, $3, .L001F8F0C
    /* F8EF8 001F8EF8 00000000 */   nop
    /* F8EFC 001F8EFC A400C294 */  lhu        $2, 0xA4($6)
    /* F8F00 001F8F00 02008210 */  beq        $4, $2, .L001F8F0C
    /* F8F04 001F8F04 00000000 */   nop
    /* F8F08 001F8F08 0100E724 */  addiu      $7, $7, 0x1
  .L001F8F0C:
    /* F8F0C 001F8F0C 01008424 */  addiu      $4, $4, 0x1
  .L001F8F10:
    /* F8F10 001F8F10 09008128 */  slti       $1, $4, 0x9
    /* F8F14 001F8F14 F5FF2014 */  bnez       $1, .L001F8EEC
    /* F8F18 001F8F18 00000000 */   nop
  .L001F8F1C:
    /* F8F1C 001F8F1C A400C294 */  lhu        $2, 0xA4($6)
    /* F8F20 001F8F20 40180200 */  sll        $3, $2, 1
    /* F8F24 001F8F24 6200023C */  lui        $2, %hi(D_00624FC0)
    /* F8F28 001F8F28 C04F4224 */  addiu      $2, $2, %lo(D_00624FC0)
    /* F8F2C 001F8F2C 21104300 */  addu       $2, $2, $3
    /* F8F30 001F8F30 00004294 */  lhu        $2, 0x0($2)
    /* F8F34 001F8F34 2110E200 */  addu       $2, $7, $2
  .L001F8F38:
    /* F8F38 001F8F38 0800E003 */  jr         $31
    /* F8F3C 001F8F3C 00000000 */   nop
.size func_001f8ea0, 0xa0
