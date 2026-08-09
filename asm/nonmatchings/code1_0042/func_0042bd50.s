.section .text
.set noat
.set noreorder
glabel func_0042bd50
    /* 32BD50 0042BD50 82300600 */  srl        $6, $6, 2
    /* 32BD54 0042BD54 0A00C010 */  beqz       $6, .L0042BD80
    /* 32BD58 0042BD58 2D380000 */   daddu     $7, $0, $0
    /* 32BD5C 0042BD5C 00000000 */  nop
  .L0042BD60:
    /* 32BD60 0042BD60 0000A38C */  lw         $3, 0x0($5)
    /* 32BD64 0042BD64 0100E724 */  addiu      $7, $7, 0x1
    /* 32BD68 0042BD68 0400A524 */  addiu      $5, $5, 0x4
    /* 32BD6C 0042BD6C 2B10E600 */  sltu       $2, $7, $6
    /* 32BD70 0042BD70 000083AC */  sw         $3, 0x0($4)
    /* 32BD74 0042BD74 04008424 */  addiu      $4, $4, 0x4
    /* 32BD78 0042BD78 F9FF4014 */  bnez       $2, .L0042BD60
    /* 32BD7C 0042BD7C 00000000 */   nop
  .L0042BD80:
    /* 32BD80 0042BD80 0800E003 */  jr         $31
    /* 32BD84 0042BD84 2D100000 */   daddu     $2, $0, $0
.size func_0042bd50, 0x38
