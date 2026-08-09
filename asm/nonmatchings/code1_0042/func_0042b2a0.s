.section .text
.set noat
.set noreorder
glabel func_0042b2a0
    /* 32B2A0 0042B2A0 82300600 */  srl        $6, $6, 2
    /* 32B2A4 0042B2A4 0A00C010 */  beqz       $6, .L0042B2D0
    /* 32B2A8 0042B2A8 2D380000 */   daddu     $7, $0, $0
    /* 32B2AC 0042B2AC 00000000 */  nop
  .L0042B2B0:
    /* 32B2B0 0042B2B0 0000A38C */  lw         $3, 0x0($5)
    /* 32B2B4 0042B2B4 0100E724 */  addiu      $7, $7, 0x1
    /* 32B2B8 0042B2B8 0400A524 */  addiu      $5, $5, 0x4
    /* 32B2BC 0042B2BC 2B10E600 */  sltu       $2, $7, $6
    /* 32B2C0 0042B2C0 000083AC */  sw         $3, 0x0($4)
    /* 32B2C4 0042B2C4 04008424 */  addiu      $4, $4, 0x4
    /* 32B2C8 0042B2C8 F9FF4014 */  bnez       $2, .L0042B2B0
    /* 32B2CC 0042B2CC 00000000 */   nop
  .L0042B2D0:
    /* 32B2D0 0042B2D0 0800E003 */  jr         $31
    /* 32B2D4 0042B2D4 2D100000 */   daddu     $2, $0, $0
.size func_0042b2a0, 0x38
