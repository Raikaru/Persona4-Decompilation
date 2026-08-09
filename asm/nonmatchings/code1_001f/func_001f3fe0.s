.section .text
.set noat
.set noreorder
glabel func_001f3fe0
    /* F3FE0 001F3FE0 3000828C */  lw         $2, 0x30($4)
    /* F3FE4 001F3FE4 A2004290 */  lbu        $2, 0xA2($2)
    /* F3FE8 001F3FE8 04004010 */  beqz       $2, .L001F3FFC
    /* F3FEC 001F3FEC 00000000 */   nop
    /* F3FF0 001F3FF0 FFFF0224 */  addiu      $2, $0, -0x1
    /* F3FF4 001F3FF4 02000010 */  b          .L001F4000
    /* F3FF8 001F3FF8 00000000 */   nop
  .L001F3FFC:
    /* F3FFC 001F3FFC CC000224 */  addiu      $2, $0, 0xCC
  .L001F4000:
    /* F4000 001F4000 0800E003 */  jr         $31
    /* F4004 001F4004 00000000 */   nop
    /* F4008 001F4008 00000000 */  nop
    /* F400C 001F400C 00000000 */  nop
.size func_001f3fe0, 0x30
