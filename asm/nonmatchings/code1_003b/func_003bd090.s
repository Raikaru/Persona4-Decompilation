.section .text
.set noat
.set noreorder
glabel func_003bd090
    /* 2BD090 003BD090 0C00828C */  lw         $2, 0xC($4)
    /* 2BD094 003BD094 80180500 */  sll        $3, $5, 2
    /* 2BD098 003BD098 21104300 */  addu       $2, $2, $3
    /* 2BD09C 003BD09C 0800E003 */  jr         $31
    /* 2BD0A0 003BD0A0 000040C4 */   lwc1      $f0, 0x0($2)
    /* 2BD0A4 003BD0A4 00000000 */  nop
    /* 2BD0A8 003BD0A8 00000000 */  nop
    /* 2BD0AC 003BD0AC 00000000 */  nop
.size func_003bd090, 0x20
