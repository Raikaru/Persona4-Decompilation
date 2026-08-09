.section .text
.set noat
.set noreorder
glabel func_004f2bc0
    /* 3F2BC0 004F2BC0 7600023C */  lui        $2, %hi(D_0075D6B8)
    /* 3F2BC4 004F2BC4 01008524 */  addiu      $5, $4, 0x1
    /* 3F2BC8 004F2BC8 B8D64724 */  addiu      $7, $2, %lo(D_0075D6B8)
    /* 3F2BCC 004F2BCC 2D300000 */  daddu      $6, $0, $0
    /* 3F2BD0 004F2BD0 0000A490 */  lbu        $4, 0x0($5)
    /* 3F2BD4 004F2BD4 00000000 */  nop
  .L004F2BD8:
    /* 3F2BD8 004F2BD8 0100A524 */  addiu      $5, $5, 0x1
    /* 3F2BDC 004F2BDC 0000E390 */  lbu        $3, 0x0($7)
    /* 3F2BE0 004F2BE0 0100E724 */  addiu      $7, $7, 0x1
    /* 3F2BE4 004F2BE4 06006414 */  bne        $3, $4, .L004F2C00
    /* 3F2BE8 004F2BE8 2D100000 */   daddu     $2, $0, $0
    /* 3F2BEC 004F2BEC 0100C624 */  addiu      $6, $6, 0x1
    /* 3F2BF0 004F2BF0 0500C228 */  slti       $2, $6, 0x5
    /* 3F2BF4 004F2BF4 F8FF4054 */  bnel       $2, $0, .L004F2BD8
    /* 3F2BF8 004F2BF8 0000A490 */   lbu       $4, 0x0($5)
    /* 3F2BFC 004F2BFC 01000224 */  addiu      $2, $0, 0x1
  .L004F2C00:
    /* 3F2C00 004F2C00 0800E003 */  jr         $31
    /* 3F2C04 004F2C04 00000000 */   nop
.size func_004f2bc0, 0x48
