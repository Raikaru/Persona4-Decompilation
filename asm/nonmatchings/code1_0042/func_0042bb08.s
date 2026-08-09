.section .text
.set noat
.set noreorder
glabel func_0042bb08
    /* 32BB08 0042BB08 82300600 */  srl        $6, $6, 2
    /* 32BB0C 0042BB0C 0A00C010 */  beqz       $6, .L0042BB38
    /* 32BB10 0042BB10 2D380000 */   daddu     $7, $0, $0
    /* 32BB14 0042BB14 00000000 */  nop
  .L0042BB18:
    /* 32BB18 0042BB18 0000A38C */  lw         $3, 0x0($5)
    /* 32BB1C 0042BB1C 0100E724 */  addiu      $7, $7, 0x1
    /* 32BB20 0042BB20 0400A524 */  addiu      $5, $5, 0x4
    /* 32BB24 0042BB24 2B10E600 */  sltu       $2, $7, $6
    /* 32BB28 0042BB28 000083AC */  sw         $3, 0x0($4)
    /* 32BB2C 0042BB2C 04008424 */  addiu      $4, $4, 0x4
    /* 32BB30 0042BB30 F9FF4014 */  bnez       $2, .L0042BB18
    /* 32BB34 0042BB34 00000000 */   nop
  .L0042BB38:
    /* 32BB38 0042BB38 0800E003 */  jr         $31
    /* 32BB3C 0042BB3C 2D100000 */   daddu     $2, $0, $0
.size func_0042bb08, 0x38
