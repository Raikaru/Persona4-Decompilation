.section .text
.set noat
.set noreorder
glabel func_003c1d00
    /* 2C1D00 003C1D00 CCB6838F */  lw         $3, -0x4934($28)
    /* 2C1D04 003C1D04 2D108000 */  daddu      $2, $4, $0
    /* 2C1D08 003C1D08 C8B685AF */  sw         $5, -0x4938($28)
    /* 2C1D0C 003C1D0C 01006324 */  addiu      $3, $3, 0x1
    /* 2C1D10 003C1D10 0800E003 */  jr         $31
    /* 2C1D14 003C1D14 CCB683AF */   sw        $3, -0x4934($28)
    /* 2C1D18 003C1D18 00000000 */  nop
    /* 2C1D1C 003C1D1C 00000000 */  nop
.size func_003c1d00, 0x20
