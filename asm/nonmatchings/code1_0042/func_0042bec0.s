.section .text
.set noat
.set noreorder
glabel func_0042bec0
    /* 32BEC0 0042BEC0 0900C010 */  beqz       $6, .L0042BEE8
    /* 32BEC4 0042BEC4 2D380000 */   daddu     $7, $0, $0
  .L0042BEC8:
    /* 32BEC8 0042BEC8 0000A390 */  lbu        $3, 0x0($5)
    /* 32BECC 0042BECC 0100E724 */  addiu      $7, $7, 0x1
    /* 32BED0 0042BED0 0100A524 */  addiu      $5, $5, 0x1
    /* 32BED4 0042BED4 2B10E600 */  sltu       $2, $7, $6
    /* 32BED8 0042BED8 000083A0 */  sb         $3, 0x0($4)
    /* 32BEDC 0042BEDC 01008424 */  addiu      $4, $4, 0x1
    /* 32BEE0 0042BEE0 F9FF4014 */  bnez       $2, .L0042BEC8
    /* 32BEE4 0042BEE4 00000000 */   nop
  .L0042BEE8:
    /* 32BEE8 0042BEE8 0800E003 */  jr         $31
    /* 32BEEC 0042BEEC 2D100000 */   daddu     $2, $0, $0
.size func_0042bec0, 0x30
