.section .text
.set noat
.set noreorder
glabel func_002b6130
    /* 1B6130 002B6130 3800838C */  lw         $3, 0x38($4)
    /* 1B6134 002B6134 880165AC */  sw         $5, 0x188($3)
    /* 1B6138 002B6138 0800E003 */  jr         $31
    /* 1B613C 002B613C 00000000 */   nop
.size func_002b6130, 0x10
