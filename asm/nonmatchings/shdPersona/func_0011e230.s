.section .text
.set noat
.set noreorder
glabel func_0011e230
    /* 1E230 0011E230 3800838C */  lw         $3, 0x38($4)
    /* 1E234 0011E234 080065AC */  sw         $5, 0x8($3)
    /* 1E238 0011E238 0800E003 */  jr         $31
    /* 1E23C 0011E23C 00000000 */   nop
.size func_0011e230, 0x10
