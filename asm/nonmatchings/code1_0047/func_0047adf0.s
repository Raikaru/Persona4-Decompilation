.section .text
.set noat
.set noreorder
glabel func_0047adf0
    /* 37ADF0 0047ADF0 FFFFA530 */  andi       $5, $5, 0xFFFF
    /* 37ADF4 0047ADF4 40180500 */  sll        $3, $5, 1
    /* 37ADF8 0047ADF8 21186500 */  addu       $3, $3, $5
    /* 37ADFC 0047ADFC 80180300 */  sll        $3, $3, 2
    /* 37AE00 0047AE00 21186400 */  addu       $3, $3, $4
    /* 37AE04 0047AE04 940266AC */  sw         $6, 0x294($3)
    /* 37AE08 0047AE08 0800E003 */  jr         $31
    /* 37AE0C 0047AE0C 00000000 */   nop
.size func_0047adf0, 0x20
