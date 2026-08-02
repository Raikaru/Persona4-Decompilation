.section .text
.set noat
.set noreorder
glabel func_00478eb0
    /* 378EB0 00478EB0 180385AC */  sw         $5, 0x318($4)
    /* 378EB4 00478EB4 1C0386AC */  sw         $6, 0x31C($4)
    /* 378EB8 00478EB8 0800E003 */  jr         $31
    /* 378EBC 00478EBC 00000000 */   nop
.size func_00478eb0, 0x10
