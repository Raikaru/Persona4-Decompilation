.section .text
.set noat
.set noreorder
glabel func_002e2a00
    /* 1E2A00 002E2A00 3800828C */  lw         $2, 0x38($4)
    /* 1E2A04 002E2A04 00004280 */  lb         $2, 0x0($2)
    /* 1E2A08 002E2A08 0800E003 */  jr         $31
    /* 1E2A0C 002E2A0C 00000000 */   nop
.size func_002e2a00, 0x10
