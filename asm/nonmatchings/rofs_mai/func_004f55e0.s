.section .text
.set noat
.set noreorder
glabel func_004f55e0
    /* 3F55E0 004F55E0 7400023C */  lui        $2, %hi(D_00743A50)
    /* 3F55E4 004F55E4 503A438C */  lw         $3, %lo(D_00743A50)($2)
    /* 3F55E8 004F55E8 0800E003 */  jr         $31
    /* 3F55EC 004F55EC 1400628C */   lw        $2, 0x14($3)
.size func_004f55e0, 0x10
