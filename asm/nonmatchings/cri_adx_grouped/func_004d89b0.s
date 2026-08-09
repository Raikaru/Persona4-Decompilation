.section .text
.set noat
.set noreorder
glabel func_004d89b0
    /* 3D89B0 004D89B0 34008294 */  lhu        $2, 0x34($4)
    /* 3D89B4 004D89B4 0000A2A4 */  sh         $2, 0x0($5)
    /* 3D89B8 004D89B8 36008394 */  lhu        $3, 0x36($4)
    /* 3D89BC 004D89BC 0000C3A4 */  sh         $3, 0x0($6)
    /* 3D89C0 004D89C0 38008294 */  lhu        $2, 0x38($4)
    /* 3D89C4 004D89C4 0800E003 */  jr         $31
    /* 3D89C8 004D89C8 0000E2A4 */   sh        $2, 0x0($7)
    /* 3D89CC 004D89CC 00000000 */  nop
.size func_004d89b0, 0x20
