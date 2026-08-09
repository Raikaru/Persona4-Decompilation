.section .text
.set noat
.set noreorder
glabel func_001f8f40
    /* F8F40 001F8F40 3000868C */  lw         $6, 0x30($4)
    /* F8F44 001F8F44 A200C290 */  lbu        $2, 0xA2($6)
    /* F8F48 001F8F48 04004010 */  beqz       $2, .L001F8F5C
    /* F8F4C 001F8F4C 00000000 */   nop
    /* F8F50 001F8F50 FFFF0224 */  addiu      $2, $0, -0x1
    /* F8F54 001F8F54 20000010 */  b          .L001F8FD8
    /* F8F58 001F8F58 00000000 */   nop
  .L001F8F5C:
    /* F8F5C 001F8F5C ACB3828F */  lw         $2, -0x4C54($28)
    /* F8F60 001F8F60 7001428C */  lw         $2, 0x170($2)
    /* F8F64 001F8F64 04004414 */  bne        $2, $4, .L001F8F78
    /* F8F68 001F8F68 00000000 */   nop
    /* F8F6C 001F8F6C FFFF0224 */  addiu      $2, $0, -0x1
    /* F8F70 001F8F70 19000010 */  b          .L001F8FD8
    /* F8F74 001F8F74 00000000 */   nop
  .L001F8F78:
    /* F8F78 001F8F78 16000724 */  addiu      $7, $0, 0x16
    /* F8F7C 001F8F7C 01000424 */  addiu      $4, $0, 0x1
    /* F8F80 001F8F80 05000324 */  addiu      $3, $0, 0x5
    /* F8F84 001F8F84 0A000010 */  b          .L001F8FB0
    /* F8F88 001F8F88 00000000 */   nop
  .L001F8F8C:
    /* F8F8C 001F8F8C 0B008510 */  beq        $4, $5, .L001F8FBC
    /* F8F90 001F8F90 00000000 */   nop
    /* F8F94 001F8F94 05008310 */  beq        $4, $3, .L001F8FAC
    /* F8F98 001F8F98 00000000 */   nop
    /* F8F9C 001F8F9C A400C294 */  lhu        $2, 0xA4($6)
    /* F8FA0 001F8FA0 02008210 */  beq        $4, $2, .L001F8FAC
    /* F8FA4 001F8FA4 00000000 */   nop
    /* F8FA8 001F8FA8 0100E724 */  addiu      $7, $7, 0x1
  .L001F8FAC:
    /* F8FAC 001F8FAC 01008424 */  addiu      $4, $4, 0x1
  .L001F8FB0:
    /* F8FB0 001F8FB0 09008128 */  slti       $1, $4, 0x9
    /* F8FB4 001F8FB4 F5FF2014 */  bnez       $1, .L001F8F8C
    /* F8FB8 001F8FB8 00000000 */   nop
  .L001F8FBC:
    /* F8FBC 001F8FBC A400C294 */  lhu        $2, 0xA4($6)
    /* F8FC0 001F8FC0 40180200 */  sll        $3, $2, 1
    /* F8FC4 001F8FC4 6200023C */  lui        $2, %hi(D_00624FC0)
    /* F8FC8 001F8FC8 C04F4224 */  addiu      $2, $2, %lo(D_00624FC0)
    /* F8FCC 001F8FCC 21104300 */  addu       $2, $2, $3
    /* F8FD0 001F8FD0 00004294 */  lhu        $2, 0x0($2)
    /* F8FD4 001F8FD4 2110E200 */  addu       $2, $7, $2
  .L001F8FD8:
    /* F8FD8 001F8FD8 0800E003 */  jr         $31
    /* F8FDC 001F8FDC 00000000 */   nop
.size func_001f8f40, 0xa0
