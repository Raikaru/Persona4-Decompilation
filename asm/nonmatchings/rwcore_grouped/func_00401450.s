.section .text
.set noat
.set noreorder
glabel func_00401450
    /* 301450 00401450 7100023C */  lui        $2, %hi(D_0070C220)
    /* 301454 00401454 0800E003 */  jr         $31
    /* 301458 00401458 20C24224 */   addiu     $2, $2, %lo(D_0070C220)
    /* 30145C 0040145C 00000000 */  nop
.size func_00401450, 0x10
