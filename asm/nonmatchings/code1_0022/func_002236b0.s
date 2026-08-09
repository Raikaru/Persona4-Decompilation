.section .text
.set noat
.set noreorder
glabel func_002236b0
    /* 1236B0 002236B0 0000A394 */  lhu        $3, 0x0($5)
    /* 1236B4 002236B4 02006330 */  andi       $3, $3, 0x2
    /* 1236B8 002236B8 0800E003 */  jr         $31
    /* 1236BC 002236BC 00000000 */   nop
.size func_002236b0, 0x10
