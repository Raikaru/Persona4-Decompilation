.section .text
.set noat
.set noreorder
glabel func_00422158
    /* 322158 00422158 FFFF023C */  lui        $2, (0xFFFFFFC0 >> 16)
    /* 32215C 0042215C C0FF4234 */  ori        $2, $2, (0xFFFFFFC0 & 0xFFFF)
    /* 322160 00422160 2428A200 */  and        $5, $5, $2
    /* 322164 00422164 0C881008 */  j          func_00422030
    /* 322168 00422168 24208200 */   and       $4, $4, $2
    /* 32216C 0042216C 00000000 */  nop
.size func_00422158, 0x18
