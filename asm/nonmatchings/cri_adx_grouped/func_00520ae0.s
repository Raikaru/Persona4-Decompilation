.section .text
.set noat
.set noreorder
glabel func_00520ae0
    /* 420AE0 00520AE0 C01F838C */  lw         $3, 0x1FC0($4)
    /* 420AE4 00520AE4 0800E003 */  jr         $31
    /* 420AE8 00520AE8 FC11628C */   lw        $2, 0x11FC($3)
    /* 420AEC 00520AEC 00000000 */  nop
.size func_00520ae0, 0x10
