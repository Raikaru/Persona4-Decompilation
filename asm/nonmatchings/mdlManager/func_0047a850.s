.section .text
.set noat
.set noreorder
glabel func_0047a850
    /* 37A850 0047A850 D800838C */  lw         $3, 0xD8($4)
    /* 37A854 0047A854 20006334 */  ori        $3, $3, 0x20
    /* 37A858 0047A858 D80083AC */  sw         $3, 0xD8($4)
    /* 37A85C 0047A85C 0800E003 */  jr         $31
    /* 37A860 0047A860 00000000 */   nop
    /* 37A864 0047A864 00000000 */  nop
    /* 37A868 0047A868 00000000 */  nop
    /* 37A86C 0047A86C 00000000 */  nop
.size func_0047a850, 0x20
