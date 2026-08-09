.section .text
.set noat
.set noreorder
glabel func_003bd0b0
    /* 2BD0B0 003BD0B0 0C00828C */  lw         $2, 0xC($4)
    /* 2BD0B4 003BD0B4 80180500 */  sll        $3, $5, 2
    /* 2BD0B8 003BD0B8 21104300 */  addu       $2, $2, $3
    /* 2BD0BC 003BD0BC 0800E003 */  jr         $31
    /* 2BD0C0 003BD0C0 0000428C */   lw        $2, 0x0($2)
    /* 2BD0C4 003BD0C4 00000000 */  nop
    /* 2BD0C8 003BD0C8 00000000 */  nop
    /* 2BD0CC 003BD0CC 00000000 */  nop
.size func_003bd0b0, 0x20
