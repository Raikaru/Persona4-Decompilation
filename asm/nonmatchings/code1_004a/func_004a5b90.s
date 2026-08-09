.section .text
.set noat
.set noreorder
glabel func_004a5b90
    /* 3A5B90 004A5B90 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 3A5B94 004A5B94 200080E4 */  swc1       $f0, 0x20($4)
    /* 3A5B98 004A5B98 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 3A5B9C 004A5B9C 240080E4 */  swc1       $f0, 0x24($4)
    /* 3A5BA0 004A5BA0 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 3A5BA4 004A5BA4 280080E4 */  swc1       $f0, 0x28($4)
    /* 3A5BA8 004A5BA8 0800E003 */  jr         $31
    /* 3A5BAC 004A5BAC 00000000 */   nop
.size func_004a5b90, 0x20
