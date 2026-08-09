.section .text
.set noat
.set noreorder
glabel func_00521400
    /* 421400 00521400 C01F828C */  lw         $2, 0x1FC0($4)
    /* 421404 00521404 0800E003 */  jr         $31
    /* 421408 00521408 50114224 */   addiu     $2, $2, 0x1150
    /* 42140C 0052140C 00000000 */  nop
.size func_00521400, 0x10
