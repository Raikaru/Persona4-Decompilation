.section .text
.set noat
.set noreorder
glabel func_0047a990
    /* 37A990 0047A990 40018394 */  lhu        $3, 0x140($4)
    /* 37A994 0047A994 00016334 */  ori        $3, $3, 0x100
    /* 37A998 0047A998 400183A4 */  sh         $3, 0x140($4)
    /* 37A99C 0047A99C 0800E003 */  jr         $31
    /* 37A9A0 0047A9A0 00000000 */   nop
    /* 37A9A4 0047A9A4 00000000 */  nop
    /* 37A9A8 0047A9A8 00000000 */  nop
    /* 37A9AC 0047A9AC 00000000 */  nop
.size func_0047a990, 0x20
