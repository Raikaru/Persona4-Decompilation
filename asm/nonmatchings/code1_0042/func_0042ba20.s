.section .text
.set noat
.set noreorder
glabel func_0042ba20
    /* 32BA20 0042BA20 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 32BA24 0042BA24 0100023C */  lui        $2, (0x10000 >> 16)
    /* 32BA28 0042BA28 24186200 */  and        $3, $3, $2
    /* 32BA2C 0042BA2C 0D006010 */  beqz       $3, .L0042BA64
    /* 32BA30 0042BA30 2B200300 */   sltu      $4, $0, $3
    /* 32BA34 0042BA34 00000000 */  nop
  .L0042BA38:
    /* 32BA38 0042BA38 39000042 */  di /* handwritten instruction */
    /* 32BA3C 0042BA3C 0F040000 */  sync.p
    /* 32BA40 0042BA40 00600240 */  mfc0       $2, $12 /* handwritten instruction */
    /* 32BA44 0042BA44 0100033C */  lui        $3, (0x10000 >> 16)
    /* 32BA48 0042BA48 24104300 */  and        $2, $2, $3
    /* 32BA4C 0042BA4C 00000000 */  nop
    /* 32BA50 0042BA50 00000000 */  nop
    /* 32BA54 0042BA54 F8FF4014 */  bnez       $2, .L0042BA38
    /* 32BA58 0042BA58 00000000 */   nop
    /* 32BA5C 0042BA5C 0800E003 */  jr         $31
    /* 32BA60 0042BA60 2D108000 */   daddu     $2, $4, $0
  .L0042BA64:
    /* 32BA64 0042BA64 2D200000 */  daddu      $4, $0, $0
    /* 32BA68 0042BA68 0800E003 */  jr         $31
    /* 32BA6C 0042BA6C 2D108000 */   daddu     $2, $4, $0
.size func_0042ba20, 0x50
