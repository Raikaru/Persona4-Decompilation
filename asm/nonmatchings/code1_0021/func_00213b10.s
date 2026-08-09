.section .text
.set noat
.set noreorder
glabel func_00213b10
    /* 113B10 00213B10 100A838C */  lw         $3, 0xA10($4)
    /* 113B14 00213B14 01006334 */  ori        $3, $3, 0x1
    /* 113B18 00213B18 100A83AC */  sw         $3, 0xA10($4)
    /* 113B1C 00213B1C 180A80A4 */  sh         $0, 0xA18($4)
    /* 113B20 00213B20 0800E003 */  jr         $31
    /* 113B24 00213B24 00000000 */   nop
    /* 113B28 00213B28 00000000 */  nop
    /* 113B2C 00213B2C 00000000 */  nop
.size func_00213b10, 0x20
