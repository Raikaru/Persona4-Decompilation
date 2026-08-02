.section .text
.set noat
.set noreorder
glabel func_0047a9b0
    /* 37A9B0 0047A9B0 40018394 */  lhu        $3, 0x140($4)
    /* 37A9B4 0047A9B4 00026334 */  ori        $3, $3, 0x200
    /* 37A9B8 0047A9B8 400183A4 */  sh         $3, 0x140($4)
    /* 37A9BC 0047A9BC 0800E003 */  jr         $31
    /* 37A9C0 0047A9C0 00000000 */   nop
    /* 37A9C4 0047A9C4 00000000 */  nop
    /* 37A9C8 0047A9C8 00000000 */  nop
    /* 37A9CC 0047A9CC 00000000 */  nop
.size func_0047a9b0, 0x20
