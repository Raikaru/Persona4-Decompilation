.section .text
.set noat
.set noreorder
glabel func_0047afd0
    /* 37AFD0 0047AFD0 0C03848C */  lw         $4, 0x30C($4)
    /* 37AFD4 0047AFD4 0000A38C */  lw         $3, 0x0($5)
    /* 37AFD8 0047AFD8 2C0083AC */  sw         $3, 0x2C($4)
    /* 37AFDC 0047AFDC 0400A38C */  lw         $3, 0x4($5)
    /* 37AFE0 0047AFE0 300083AC */  sw         $3, 0x30($4)
    /* 37AFE4 0047AFE4 0800E003 */  jr         $31
    /* 37AFE8 0047AFE8 00000000 */   nop
    /* 37AFEC 0047AFEC 00000000 */  nop
.size func_0047afd0, 0x20
