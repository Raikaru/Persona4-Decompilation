.section .text
.set noat
.set noreorder
glabel func_00422298
    /* 322298 00422298 FFFF023C */  lui        $2, (0xFFFFFFC0 >> 16)
    /* 32229C 0042229C C0FF4234 */  ori        $2, $2, (0xFFFFFFC0 & 0xFFFF)
    /* 3222A0 004222A0 2428A200 */  and        $5, $5, $2
    /* 3222A4 004222A4 5C881008 */  j          func_00422170
    /* 3222A8 004222A8 24208200 */   and       $4, $4, $2
    /* 3222AC 004222AC 00000000 */  nop
.size func_00422298, 0x18
