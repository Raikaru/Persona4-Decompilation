.section .text
.set noat
.set noreorder
glabel func_004a1c80
    /* 3A1C80 004A1C80 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 3A1C84 004A1C84 200080E4 */  swc1       $f0, 0x20($4)
    /* 3A1C88 004A1C88 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 3A1C8C 004A1C8C 240080E4 */  swc1       $f0, 0x24($4)
    /* 3A1C90 004A1C90 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 3A1C94 004A1C94 280080E4 */  swc1       $f0, 0x28($4)
    /* 3A1C98 004A1C98 0800E003 */  jr         $31
    /* 3A1C9C 004A1C9C 00000000 */   nop
.size func_004a1c80, 0x20
