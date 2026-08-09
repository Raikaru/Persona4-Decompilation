.section .text
.set noat
.set noreorder
glabel func_001b0590
    /* B0590 001B0590 1A008394 */  lhu        $3, 0x1A($4)
    /* B0594 001B0594 01006330 */  andi       $3, $3, 0x1
    /* B0598 001B0598 0A006010 */  beqz       $3, .L001B05C4
    /* B059C 001B059C 00000000 */   nop
    /* B05A0 001B05A0 3000838C */  lw         $3, 0x30($4)
    /* B05A4 001B05A4 9C006524 */  addiu      $5, $3, 0x9C
    /* B05A8 001B05A8 9C00648C */  lw         $4, 0x9C($3)
    /* B05AC 001B05AC 08008330 */  andi       $3, $4, 0x8
    /* B05B0 001B05B0 04006010 */  beqz       $3, .L001B05C4
    /* B05B4 001B05B4 00000000 */   nop
    /* B05B8 001B05B8 F7FF0324 */  addiu      $3, $0, -0x9
    /* B05BC 001B05BC 24188300 */  and        $3, $4, $3
    /* B05C0 001B05C0 0000A3AC */  sw         $3, 0x0($5)
  .L001B05C4:
    /* B05C4 001B05C4 0800E003 */  jr         $31
    /* B05C8 001B05C8 00000000 */   nop
    /* B05CC 001B05CC 00000000 */  nop
.size func_001b0590, 0x40
