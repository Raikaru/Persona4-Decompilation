.section .text
.set noat
.set noreorder
glabel func_001f0b90
    /* F0B90 001F0B90 2D280000 */  daddu      $5, $0, $0
    /* F0B94 001F0B94 6A008394 */  lhu        $3, 0x6A($4)
    /* F0B98 001F0B98 0D000010 */  b          .L001F0BD0
    /* F0B9C 001F0B9C 00000000 */   nop
  .L001F0BA0:
    /* F0BA0 001F0BA0 FFFFA230 */  andi       $2, $5, 0xFFFF
    /* F0BA4 001F0BA4 80100200 */  sll        $2, $2, 2
    /* F0BA8 001F0BA8 21108200 */  addu       $2, $4, $2
    /* F0BAC 001F0BAC 3800428C */  lw         $2, 0x38($2)
    /* F0BB0 001F0BB0 E400428C */  lw         $2, 0xE4($2)
    /* F0BB4 001F0BB4 04004010 */  beqz       $2, .L001F0BC8
    /* F0BB8 001F0BB8 00000000 */   nop
    /* F0BBC 001F0BBC 01000224 */  addiu      $2, $0, 0x1
    /* F0BC0 001F0BC0 08000010 */  b          .L001F0BE4
    /* F0BC4 001F0BC4 00000000 */   nop
  .L001F0BC8:
    /* F0BC8 001F0BC8 0100A224 */  addiu      $2, $5, 0x1
    /* F0BCC 001F0BCC FFFF4530 */  andi       $5, $2, 0xFFFF
  .L001F0BD0:
    /* F0BD0 001F0BD0 FFFFA230 */  andi       $2, $5, 0xFFFF
    /* F0BD4 001F0BD4 2A104300 */  slt        $2, $2, $3
    /* F0BD8 001F0BD8 F1FF4014 */  bnez       $2, .L001F0BA0
    /* F0BDC 001F0BDC 00000000 */   nop
    /* F0BE0 001F0BE0 2D100000 */  daddu      $2, $0, $0
  .L001F0BE4:
    /* F0BE4 001F0BE4 0800E003 */  jr         $31
    /* F0BE8 001F0BE8 00000000 */   nop
    /* F0BEC 001F0BEC 00000000 */  nop
.size func_001f0b90, 0x60
