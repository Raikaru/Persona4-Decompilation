.section .text
.set noat
.set noreorder
glabel func_003b5fb0
    /* 2B5FB0 003B5FB0 00008C8C */  lw         $12, 0x0($4)
    /* 2B5FB4 003B5FB4 2A080500 */  slt        $1, $0, $5
    /* 2B5FB8 003B5FB8 04008A8C */  lw         $10, 0x4($4)
    /* 2B5FBC 003B5FBC 2C00CB8C */  lw         $11, 0x2C($6)
    /* 2B5FC0 003B5FC0 3000C98C */  lw         $9, 0x30($6)
    /* 2B5FC4 003B5FC4 12002010 */  beqz       $1, .L003B6010
    /* 2B5FC8 003B5FC8 2D700000 */   daddu     $14, $0, $0
  .L003B5FCC:
    /* 2B5FCC 003B5FCC 2D686001 */  daddu      $13, $11, $0
    /* 2B5FD0 003B5FD0 21408A01 */  addu       $8, $12, $10
    /* 2B5FD4 003B5FD4 0000A48D */  lw         $4, 0x0($13)
    /* 2B5FD8 003B5FD8 21380A01 */  addu       $7, $8, $10
    /* 2B5FDC 003B5FDC 0100CE25 */  addiu      $14, $14, 0x1
    /* 2B5FE0 003B5FE0 2130EA00 */  addu       $6, $7, $10
    /* 2B5FE4 003B5FE4 2A18C501 */  slt        $3, $14, $5
    /* 2B5FE8 003B5FE8 21586901 */  addu       $11, $11, $9
    /* 2B5FEC 003B5FEC 000084AD */  sw         $4, 0x0($12)
    /* 2B5FF0 003B5FF0 0400A48D */  lw         $4, 0x4($13)
    /* 2B5FF4 003B5FF4 2160CA00 */  addu       $12, $6, $10
    /* 2B5FF8 003B5FF8 000004AD */  sw         $4, 0x0($8)
    /* 2B5FFC 003B5FFC 0800A48D */  lw         $4, 0x8($13)
    /* 2B6000 003B6000 0000E4AC */  sw         $4, 0x0($7)
    /* 2B6004 003B6004 0C00A48D */  lw         $4, 0xC($13)
    /* 2B6008 003B6008 F0FF6014 */  bnez       $3, .L003B5FCC
    /* 2B600C 003B600C 0000C4AC */   sw        $4, 0x0($6)
  .L003B6010:
    /* 2B6010 003B6010 0800E003 */  jr         $31
    /* 2B6014 003B6014 00000000 */   nop
    /* 2B6018 003B6018 00000000 */  nop
    /* 2B601C 003B601C 00000000 */  nop
.size func_003b5fb0, 0x70
