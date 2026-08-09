.section .text
.set noat
.set noreorder
glabel func_003c4a60
    /* 2C4A60 003C4A60 0000828C */  lw         $2, 0x0($4)
    /* 2C4A64 003C4A64 80180500 */  sll        $3, $5, 2
    /* 2C4A68 003C4A68 21104300 */  addu       $2, $2, $3
    /* 2C4A6C 003C4A6C 0800E003 */  jr         $31
    /* 2C4A70 003C4A70 0000428C */   lw        $2, 0x0($2)
    /* 2C4A74 003C4A74 00000000 */  nop
    /* 2C4A78 003C4A78 00000000 */  nop
    /* 2C4A7C 003C4A7C 00000000 */  nop
.size func_003c4a60, 0x20
