.section .text
.set noat
.set noreorder
glabel func_003bd0d0
    /* 2BD0D0 003BD0D0 0C00838C */  lw         $3, 0xC($4)
    /* 2BD0D4 003BD0D4 80280500 */  sll        $5, $5, 2
    /* 2BD0D8 003BD0D8 21186500 */  addu       $3, $3, $5
    /* 2BD0DC 003BD0DC 0800E003 */  jr         $31
    /* 2BD0E0 003BD0E0 000066AC */   sw        $6, 0x0($3)
    /* 2BD0E4 003BD0E4 00000000 */  nop
    /* 2BD0E8 003BD0E8 00000000 */  nop
    /* 2BD0EC 003BD0EC 00000000 */  nop
.size func_003bd0d0, 0x20
