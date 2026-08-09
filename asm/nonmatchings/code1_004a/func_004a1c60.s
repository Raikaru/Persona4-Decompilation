.section .text
.set noat
.set noreorder
glabel func_004a1c60
    /* 3A1C60 004A1C60 20008CE4 */  swc1       $f12, 0x20($4)
    /* 3A1C64 004A1C64 24008CE4 */  swc1       $f12, 0x24($4)
    /* 3A1C68 004A1C68 28008CE4 */  swc1       $f12, 0x28($4)
    /* 3A1C6C 004A1C6C 0800E003 */  jr         $31
    /* 3A1C70 004A1C70 00000000 */   nop
    /* 3A1C74 004A1C74 00000000 */  nop
    /* 3A1C78 004A1C78 00000000 */  nop
    /* 3A1C7C 004A1C7C 00000000 */  nop
.size func_004a1c60, 0x20
