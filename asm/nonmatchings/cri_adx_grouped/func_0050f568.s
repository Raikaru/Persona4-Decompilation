.section .text
.set noat
.set noreorder
glabel func_0050f568
    /* 40F568 0050F568 94018424 */  addiu      $4, $4, 0x194
    /* 40F56C 0050F56C 0800828C */  lw         $2, 0x8($4)
    /* 40F570 0050F570 0400838C */  lw         $3, 0x4($4)
    /* 40F574 0050F574 0000C2AC */  sw         $2, 0x0($6)
    /* 40F578 0050F578 0800E003 */  jr         $31
    /* 40F57C 0050F57C 0000A3AC */   sw        $3, 0x0($5)
.size func_0050f568, 0x18
