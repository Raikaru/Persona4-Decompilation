.section .text
.set noat
.set noreorder
glabel func_001f42a0
    /* F42A0 001F42A0 ACB3828F */  lw         $2, -0x4C54($28)
    /* F42A4 001F42A4 7001428C */  lw         $2, 0x170($2)
    /* F42A8 001F42A8 04004410 */  beq        $2, $4, .L001F42BC
    /* F42AC 001F42AC 00000000 */   nop
    /* F42B0 001F42B0 FFFF0224 */  addiu      $2, $0, -0x1
    /* F42B4 001F42B4 02000010 */  b          .L001F42C0
    /* F42B8 001F42B8 00000000 */   nop
  .L001F42BC:
    /* F42BC 001F42BC 73010224 */  addiu      $2, $0, 0x173
  .L001F42C0:
    /* F42C0 001F42C0 0800E003 */  jr         $31
    /* F42C4 001F42C4 00000000 */   nop
    /* F42C8 001F42C8 00000000 */  nop
    /* F42CC 001F42CC 00000000 */  nop
.size func_001f42a0, 0x30
