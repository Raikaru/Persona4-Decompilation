.section .text
.set noat
.set noreorder
glabel func_0041f2a8
    /* 31F2A8 0041F2A8 4000838C */  lw         $3, 0x40($4)
    /* 31F2AC 0041F2AC 0400628C */  lw         $2, 0x4($3)
    /* 31F2B0 0041F2B0 0800E003 */  jr         $31
    /* 31F2B4 0041F2B4 0100422C */   sltiu     $2, $2, 0x1
.size func_0041f2a8, 0x10
