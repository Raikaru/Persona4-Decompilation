.section .text
.set noat
.set noreorder
glabel func_00243e70
    /* 143E70 00243E70 00008394 */  lhu        $3, 0x0($4)
    /* 143E74 00243E74 FFFD6330 */  andi       $3, $3, 0xFDFF
    /* 143E78 00243E78 000083A4 */  sh         $3, 0x0($4)
    /* 143E7C 00243E7C 0800E003 */  jr         $31
    /* 143E80 00243E80 00000000 */   nop
    /* 143E84 00243E84 00000000 */  nop
    /* 143E88 00243E88 00000000 */  nop
    /* 143E8C 00243E8C 00000000 */  nop
.size func_00243e70, 0x20
