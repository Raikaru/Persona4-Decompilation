.section .text
.set noat
.set noreorder
glabel func_003c08c0
    /* 2C08C0 003C08C0 B0B6838F */  lw         $3, -0x4950($28)
    /* 2C08C4 003C08C4 2D108000 */  daddu      $2, $4, $0
    /* 2C08C8 003C08C8 2128A300 */  addu       $5, $5, $3
    /* 2C08CC 003C08CC 0400A48C */  lw         $4, 0x4($5)
    /* 2C08D0 003C08D0 0800A38C */  lw         $3, 0x8($5)
    /* 2C08D4 003C08D4 000064AC */  sw         $4, 0x0($3)
    /* 2C08D8 003C08D8 0800A48C */  lw         $4, 0x8($5)
    /* 2C08DC 003C08DC 0400A38C */  lw         $3, 0x4($5)
    /* 2C08E0 003C08E0 040064AC */  sw         $4, 0x4($3)
    /* 2C08E4 003C08E4 0800A0AC */  sw         $0, 0x8($5)
    /* 2C08E8 003C08E8 0400A0AC */  sw         $0, 0x4($5)
    /* 2C08EC 003C08EC 0800E003 */  jr         $31
    /* 2C08F0 003C08F0 0000A0AC */   sw        $0, 0x0($5)
    /* 2C08F4 003C08F4 00000000 */  nop
    /* 2C08F8 003C08F8 00000000 */  nop
    /* 2C08FC 003C08FC 00000000 */  nop
.size func_003c08c0, 0x40
