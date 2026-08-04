.section .text
.set noat
.set noreorder
glabel func_001f0f70
    /* F0F70 001F0F70 2D300000 */  daddu      $6, $0, $0
    /* F0F74 001F0F74 6A008594 */  lhu        $5, 0x6A($4)
    /* F0F78 001F0F78 14000010 */  b          .L001F0FCC
    /* F0F7C 001F0F7C 00000000 */   nop
  .L001F0F80:
    /* F0F80 001F0F80 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* F0F84 001F0F84 80100200 */  sll        $2, $2, 2
    /* F0F88 001F0F88 21108200 */  addu       $2, $4, $2
    /* F0F8C 001F0F8C 3800438C */  lw         $3, 0x38($2)
    /* F0F90 001F0F90 E400628C */  lw         $2, 0xE4($3)
    /* F0F94 001F0F94 04004010 */  beqz       $2, .L001F0FA8
    /* F0F98 001F0F98 00000000 */   nop
    /* F0F9C 001F0F9C 01000224 */  addiu      $2, $0, 0x1
    /* F0FA0 001F0FA0 0F000010 */  b          .L001F0FE0
    /* F0FA4 001F0FA4 00000000 */   nop
  .L001F0FA8:
    /* F0FA8 001F0FA8 DC006294 */  lhu        $2, 0xDC($3)
    /* F0FAC 001F0FAC 00054230 */  andi       $2, $2, 0x500
    /* F0FB0 001F0FB0 04004010 */  beqz       $2, .L001F0FC4
    /* F0FB4 001F0FB4 00000000 */   nop
    /* F0FB8 001F0FB8 01000224 */  addiu      $2, $0, 0x1
    /* F0FBC 001F0FBC 08000010 */  b          .L001F0FE0
    /* F0FC0 001F0FC0 00000000 */   nop
  .L001F0FC4:
    /* F0FC4 001F0FC4 0100C224 */  addiu      $2, $6, 0x1
    /* F0FC8 001F0FC8 FFFF4630 */  andi       $6, $2, 0xFFFF
  .L001F0FCC:
    /* F0FCC 001F0FCC FFFFC230 */  andi       $2, $6, 0xFFFF
    /* F0FD0 001F0FD0 2A104500 */  slt        $2, $2, $5
    /* F0FD4 001F0FD4 EAFF4014 */  bnez       $2, .L001F0F80
    /* F0FD8 001F0FD8 00000000 */   nop
    /* F0FDC 001F0FDC 2D100000 */  daddu      $2, $0, $0
  .L001F0FE0:
    /* F0FE0 001F0FE0 0800E003 */  jr         $31
    /* F0FE4 001F0FE4 00000000 */   nop
    /* F0FE8 001F0FE8 00000000 */  nop
    /* F0FEC 001F0FEC 00000000 */  nop
.size func_001f0f70, 0x80
