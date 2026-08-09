.section .text
.set noat
.set noreorder
glabel func_004c3e20
    /* 3C3E20 004C3E20 A0008294 */  lhu        $2, 0xA0($4)
    /* 3C3E24 004C3E24 0000A2A4 */  sh         $2, 0x0($5)
    /* 3C3E28 004C3E28 A2008394 */  lhu        $3, 0xA2($4)
    /* 3C3E2C 004C3E2C 0000C3A4 */  sh         $3, 0x0($6)
    /* 3C3E30 004C3E30 A4008294 */  lhu        $2, 0xA4($4)
    /* 3C3E34 004C3E34 0800E003 */  jr         $31
    /* 3C3E38 004C3E38 0000E2A4 */   sh        $2, 0x0($7)
    /* 3C3E3C 004C3E3C 00000000 */  nop
.size func_004c3e20, 0x20
