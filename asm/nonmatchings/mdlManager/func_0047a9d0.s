.section .text
.set noat
.set noreorder
glabel func_0047a9d0
    /* 37A9D0 0047A9D0 40018294 */  lhu        $2, 0x140($4)
    /* 37A9D4 0047A9D4 E0814230 */  andi       $2, $2, 0x81E0
    /* 37A9D8 0047A9D8 2B100200 */  sltu       $2, $0, $2
    /* 37A9DC 0047A9DC 0800E003 */  jr         $31
    /* 37A9E0 0047A9E0 00000000 */   nop
    /* 37A9E4 0047A9E4 00000000 */  nop
    /* 37A9E8 0047A9E8 00000000 */  nop
    /* 37A9EC 0047A9EC 00000000 */  nop
.size func_0047a9d0, 0x20
