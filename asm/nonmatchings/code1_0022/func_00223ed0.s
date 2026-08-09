.section .text
.set noat
.set noreorder
glabel func_00223ed0
    /* 123ED0 00223ED0 0000A394 */  lhu        $3, 0x0($5)
    /* 123ED4 00223ED4 02006330 */  andi       $3, $3, 0x2
    /* 123ED8 00223ED8 0800E003 */  jr         $31
    /* 123EDC 00223EDC 00000000 */   nop
.size func_00223ed0, 0x10
