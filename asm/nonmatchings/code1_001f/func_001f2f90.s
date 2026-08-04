.section .text
.set noat
.set noreorder
glabel func_001f2f90
    /* F2F90 001F2F90 6E008384 */  lh         $3, 0x6E($4)
    /* F2F94 001F2F94 80100300 */  sll        $2, $3, 2
    /* F2F98 001F2F98 21104300 */  addu       $2, $2, $3
    /* F2F9C 001F2F9C C0180200 */  sll        $3, $2, 3
    /* F2FA0 001F2FA0 B8B3828F */  lw         $2, -0x4C48($28)
    /* F2FA4 001F2FA4 21184300 */  addu       $3, $2, $3
    /* F2FA8 001F2FA8 00006290 */  lbu        $2, 0x0($3)
    /* F2FAC 001F2FAC 02004230 */  andi       $2, $2, 0x2
    /* F2FB0 001F2FB0 04004010 */  beqz       $2, .L001F2FC4
    /* F2FB4 001F2FB4 00000000 */   nop
    /* F2FB8 001F2FB8 2D100000 */  daddu      $2, $0, $0
    /* F2FBC 001F2FBC 04000010 */  b          .L001F2FD0
    /* F2FC0 001F2FC0 00000000 */   nop
  .L001F2FC4:
    /* F2FC4 001F2FC4 24006290 */  lbu        $2, 0x24($3)
    /* F2FC8 001F2FC8 06004238 */  xori       $2, $2, 0x6
    /* F2FCC 001F2FCC 2B100200 */  sltu       $2, $0, $2
  .L001F2FD0:
    /* F2FD0 001F2FD0 0800E003 */  jr         $31
    /* F2FD4 001F2FD4 00000000 */   nop
    /* F2FD8 001F2FD8 00000000 */  nop
    /* F2FDC 001F2FDC 00000000 */  nop
.size func_001f2f90, 0x50
