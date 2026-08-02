.section .text
.set noat
.set noreorder
glabel func_0011d0a0
    /* 1D0A0 0011D0A0 3800868C */  lw         $6, 0x38($4)
    /* 1D0A4 0011D0A4 2720A000 */  not        $4, $5
    /* 1D0A8 0011D0A8 3405C38C */  lw         $3, 0x534($6)
    /* 1D0AC 0011D0AC 24186400 */  and        $3, $3, $4
    /* 1D0B0 0011D0B0 3405C3AC */  sw         $3, 0x534($6)
    /* 1D0B4 0011D0B4 0800E003 */  jr         $31
    /* 1D0B8 0011D0B8 00000000 */   nop
    /* 1D0BC 0011D0BC 00000000 */  nop
.size func_0011d0a0, 0x20
