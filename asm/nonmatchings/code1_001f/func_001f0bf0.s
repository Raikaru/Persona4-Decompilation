.section .text
.set noat
.set noreorder
glabel func_001f0bf0
    /* F0BF0 001F0BF0 2D280000 */  daddu      $5, $0, $0
    /* F0BF4 001F0BF4 6A008394 */  lhu        $3, 0x6A($4)
    /* F0BF8 001F0BF8 0E000010 */  b          .L001F0C34
    /* F0BFC 001F0BFC 00000000 */   nop
  .L001F0C00:
    /* F0C00 001F0C00 FFFFA230 */  andi       $2, $5, 0xFFFF
    /* F0C04 001F0C04 80100200 */  sll        $2, $2, 2
    /* F0C08 001F0C08 21108200 */  addu       $2, $4, $2
    /* F0C0C 001F0C0C 3800428C */  lw         $2, 0x38($2)
    /* F0C10 001F0C10 DE004294 */  lhu        $2, 0xDE($2)
    /* F0C14 001F0C14 06004230 */  andi       $2, $2, 0x6
    /* F0C18 001F0C18 04004010 */  beqz       $2, .L001F0C2C
    /* F0C1C 001F0C1C 00000000 */   nop
    /* F0C20 001F0C20 01000224 */  addiu      $2, $0, 0x1
    /* F0C24 001F0C24 08000010 */  b          .L001F0C48
    /* F0C28 001F0C28 00000000 */   nop
  .L001F0C2C:
    /* F0C2C 001F0C2C 0100A224 */  addiu      $2, $5, 0x1
    /* F0C30 001F0C30 FFFF4530 */  andi       $5, $2, 0xFFFF
  .L001F0C34:
    /* F0C34 001F0C34 FFFFA230 */  andi       $2, $5, 0xFFFF
    /* F0C38 001F0C38 2A104300 */  slt        $2, $2, $3
    /* F0C3C 001F0C3C F0FF4014 */  bnez       $2, .L001F0C00
    /* F0C40 001F0C40 00000000 */   nop
    /* F0C44 001F0C44 2D100000 */  daddu      $2, $0, $0
  .L001F0C48:
    /* F0C48 001F0C48 0800E003 */  jr         $31
    /* F0C4C 001F0C4C 00000000 */   nop
.size func_001f0bf0, 0x60
