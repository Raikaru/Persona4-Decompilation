.section .text
.set noat
.set noreorder
glabel func_0047a810
    /* 37A810 0047A810 D800838C */  lw         $3, 0xD8($4)
    /* 37A814 0047A814 01006334 */  ori        $3, $3, 0x1
    /* 37A818 0047A818 D80083AC */  sw         $3, 0xD8($4)
    /* 37A81C 0047A81C 0800E003 */  jr         $31
    /* 37A820 0047A820 00000000 */   nop
    /* 37A824 0047A824 00000000 */  nop
    /* 37A828 0047A828 00000000 */  nop
    /* 37A82C 0047A82C 00000000 */  nop
.size func_0047a810, 0x20
