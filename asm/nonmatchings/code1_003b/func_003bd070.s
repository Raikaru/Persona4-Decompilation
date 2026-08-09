.section .text
.set noat
.set noreorder
glabel func_003bd070
    /* 2BD070 003BD070 0C00828C */  lw         $2, 0xC($4)
    /* 2BD074 003BD074 80180500 */  sll        $3, $5, 2
    /* 2BD078 003BD078 21104300 */  addu       $2, $2, $3
    /* 2BD07C 003BD07C 0800E003 */  jr         $31
    /* 2BD080 003BD080 0000428C */   lw        $2, 0x0($2)
    /* 2BD084 003BD084 00000000 */  nop
    /* 2BD088 003BD088 00000000 */  nop
    /* 2BD08C 003BD08C 00000000 */  nop
.size func_003bd070, 0x20
