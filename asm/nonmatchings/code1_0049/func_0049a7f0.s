.section .text
.set noat
.set noreorder
glabel func_0049a7f0
    /* 39A7F0 0049A7F0 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 39A7F4 0049A7F4 200080E4 */  swc1       $f0, 0x20($4)
    /* 39A7F8 0049A7F8 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 39A7FC 0049A7FC 240080E4 */  swc1       $f0, 0x24($4)
    /* 39A800 0049A800 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 39A804 0049A804 280080E4 */  swc1       $f0, 0x28($4)
    /* 39A808 0049A808 0800E003 */  jr         $31
    /* 39A80C 0049A80C 00000000 */   nop
.size func_0049a7f0, 0x20
