.section .text
.set noat
.set noreorder
glabel func_003bd0f0
    /* 2BD0F0 003BD0F0 0C00838C */  lw         $3, 0xC($4)
    /* 2BD0F4 003BD0F4 80280500 */  sll        $5, $5, 2
    /* 2BD0F8 003BD0F8 21186500 */  addu       $3, $3, $5
    /* 2BD0FC 003BD0FC 0800E003 */  jr         $31
    /* 2BD100 003BD100 00006CE4 */   swc1      $f12, 0x0($3)
    /* 2BD104 003BD104 00000000 */  nop
    /* 2BD108 003BD108 00000000 */  nop
    /* 2BD10C 003BD10C 00000000 */  nop
.size func_003bd0f0, 0x20
