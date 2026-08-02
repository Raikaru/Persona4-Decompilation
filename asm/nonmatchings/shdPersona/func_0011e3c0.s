.section .text
.set noat
.set noreorder
glabel func_0011e3c0
    /* 1E3C0 0011E3C0 3800868C */  lw         $6, 0x38($4)
    /* 1E3C4 0011E3C4 0800C490 */  lbu        $4, 0x8($6)
    /* 1E3C8 0011E3C8 00FF0324 */  addiu      $3, $0, -0x100
    /* 1E3CC 0011E3CC 2418A300 */  and        $3, $5, $3
    /* 1E3D0 0011E3D0 25186400 */  or         $3, $3, $4
    /* 1E3D4 0011E3D4 0C00C3AC */  sw         $3, 0xC($6)
    /* 1E3D8 0011E3D8 0800E003 */  jr         $31
    /* 1E3DC 0011E3DC 00000000 */   nop
.size func_0011e3c0, 0x20
