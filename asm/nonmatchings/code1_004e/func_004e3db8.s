.section .text
.set noat
.set noreorder
glabel func_004e3db8
    /* 3E3DB8 004E3DB8 7300033C */  lui        $3, %hi(D_00731C78)
    /* 3E3DBC 004E3DBC 0800E003 */  jr         $31
    /* 3E3DC0 004E3DC0 781C628C */   lw        $2, %lo(D_00731C78)($3)
    /* 3E3DC4 004E3DC4 00000000 */  nop
.size func_004e3db8, 0x10
