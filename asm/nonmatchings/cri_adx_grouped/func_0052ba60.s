.section .text
.set noat
.set noreorder
glabel func_0052ba60
    /* 42BA60 0052BA60 0800828C */  lw         $2, 0x8($4)
    /* 42BA64 0052BA64 0000A2AC */  sw         $2, 0x0($5)
    /* 42BA68 0052BA68 0C00838C */  lw         $3, 0xC($4)
    /* 42BA6C 0052BA6C 0800E003 */  jr         $31
    /* 42BA70 0052BA70 0000C3AC */   sw        $3, 0x0($6)
    /* 42BA74 0052BA74 00000000 */  nop
.size func_0052ba60, 0x18
