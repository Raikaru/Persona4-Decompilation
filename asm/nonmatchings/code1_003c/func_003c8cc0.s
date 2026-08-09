.section .text
.set noat
.set noreorder
glabel func_003c8cc0
    /* 2C8CC0 003C8CC0 FCB6838F */  lw         $3, -0x4904($28)
    /* 2C8CC4 003C8CC4 2D108000 */  daddu      $2, $4, $0
    /* 2C8CC8 003C8CC8 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2C8CCC 003C8CCC 0800E003 */  jr         $31
    /* 2C8CD0 003C8CD0 FCB683AF */   sw        $3, -0x4904($28)
    /* 2C8CD4 003C8CD4 00000000 */  nop
    /* 2C8CD8 003C8CD8 00000000 */  nop
    /* 2C8CDC 003C8CDC 00000000 */  nop
.size func_003c8cc0, 0x20
