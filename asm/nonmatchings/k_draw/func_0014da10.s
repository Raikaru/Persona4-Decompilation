.section .text
.set noat
.set noreorder
glabel func_0014da10
    /* 4DA10 0014DA10 3800838C */  lw         $3, 0x38($4)
    /* 4DA14 0014DA14 10006CE4 */  swc1       $f12, 0x10($3)
    /* 4DA18 0014DA18 0800E003 */  jr         $31
    /* 4DA1C 0014DA1C 00000000 */   nop
.size func_0014da10, 0x10
