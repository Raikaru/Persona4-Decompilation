.section .text
.set noat
.set noreorder
glabel func_001f41b0
    /* F41B0 001F41B0 3000828C */  lw         $2, 0x30($4)
    /* F41B4 001F41B4 A2004290 */  lbu        $2, 0xA2($2)
    /* F41B8 001F41B8 04004010 */  beqz       $2, .L001F41CC
    /* F41BC 001F41BC 00000000 */   nop
    /* F41C0 001F41C0 FFFF0224 */  addiu      $2, $0, -0x1
    /* F41C4 001F41C4 02000010 */  b          .L001F41D0
    /* F41C8 001F41C8 00000000 */   nop
  .L001F41CC:
    /* F41CC 001F41CC CB000224 */  addiu      $2, $0, 0xCB
  .L001F41D0:
    /* F41D0 001F41D0 0800E003 */  jr         $31
    /* F41D4 001F41D4 00000000 */   nop
    /* F41D8 001F41D8 00000000 */  nop
    /* F41DC 001F41DC 00000000 */  nop
.size func_001f41b0, 0x30
