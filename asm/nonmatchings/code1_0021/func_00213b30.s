.section .text
.set noat
.set noreorder
glabel func_00213b30
    /* 113B30 00213B30 100A838C */  lw         $3, 0xA10($4)
    /* 113B34 00213B34 02006334 */  ori        $3, $3, 0x2
    /* 113B38 00213B38 100A83AC */  sw         $3, 0xA10($4)
    /* 113B3C 00213B3C 1A0A80A4 */  sh         $0, 0xA1A($4)
    /* 113B40 00213B40 0800E003 */  jr         $31
    /* 113B44 00213B44 00000000 */   nop
    /* 113B48 00213B48 00000000 */  nop
    /* 113B4C 00213B4C 00000000 */  nop
.size func_00213b30, 0x20
