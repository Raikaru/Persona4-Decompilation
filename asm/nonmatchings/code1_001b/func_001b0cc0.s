.section .text
.set noat
.set noreorder
glabel func_001b0cc0
    /* B0CC0 001B0CC0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B0CC4 001B0CC4 7401428C */  lw         $2, 0x174($2)
    /* B0CC8 001B0CC8 07000010 */  b          .L001B0CE8
    /* B0CCC 001B0CCC 00000000 */   nop
  .L001B0CD0:
    /* B0CD0 001B0CD0 0800438C */  lw         $3, 0x8($2)
    /* B0CD4 001B0CD4 03006414 */  bne        $3, $4, .L001B0CE4
    /* B0CD8 001B0CD8 00000000 */   nop
    /* B0CDC 001B0CDC 05000010 */  b          .L001B0CF4
    /* B0CE0 001B0CE0 00000000 */   nop
  .L001B0CE4:
    /* B0CE4 001B0CE4 5004428C */  lw         $2, 0x450($2)
  .L001B0CE8:
    /* B0CE8 001B0CE8 F9FF4014 */  bnez       $2, .L001B0CD0
    /* B0CEC 001B0CEC 00000000 */   nop
    /* B0CF0 001B0CF0 2D100000 */  daddu      $2, $0, $0
  .L001B0CF4:
    /* B0CF4 001B0CF4 0800E003 */  jr         $31
    /* B0CF8 001B0CF8 00000000 */   nop
    /* B0CFC 001B0CFC 00000000 */  nop
.size func_001b0cc0, 0x40
