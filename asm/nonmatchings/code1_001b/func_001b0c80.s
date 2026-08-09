.section .text
.set noat
.set noreorder
glabel func_001b0c80
    /* B0C80 001B0C80 ACB3828F */  lw         $2, -0x4C54($28)
    /* B0C84 001B0C84 7401428C */  lw         $2, 0x174($2)
    /* B0C88 001B0C88 07000010 */  b          .L001B0CA8
    /* B0C8C 001B0C8C 00000000 */   nop
  .L001B0C90:
    /* B0C90 001B0C90 3000438C */  lw         $3, 0x30($2)
    /* B0C94 001B0C94 03006414 */  bne        $3, $4, .L001B0CA4
    /* B0C98 001B0C98 00000000 */   nop
    /* B0C9C 001B0C9C 05000010 */  b          .L001B0CB4
    /* B0CA0 001B0CA0 00000000 */   nop
  .L001B0CA4:
    /* B0CA4 001B0CA4 5004428C */  lw         $2, 0x450($2)
  .L001B0CA8:
    /* B0CA8 001B0CA8 F9FF4014 */  bnez       $2, .L001B0C90
    /* B0CAC 001B0CAC 00000000 */   nop
    /* B0CB0 001B0CB0 2D100000 */  daddu      $2, $0, $0
  .L001B0CB4:
    /* B0CB4 001B0CB4 0800E003 */  jr         $31
    /* B0CB8 001B0CB8 00000000 */   nop
    /* B0CBC 001B0CBC 00000000 */  nop
.size func_001b0c80, 0x40
