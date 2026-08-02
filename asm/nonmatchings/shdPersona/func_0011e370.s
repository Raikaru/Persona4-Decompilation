.section .text
.set noat
.set noreorder
glabel func_0011e370
    /* 1E370 0011E370 3800838C */  lw         $3, 0x38($4)
    /* 1E374 0011E374 280060C4 */  lwc1       $f0, 0x28($3)
    /* 1E378 0011E378 400060E4 */  swc1       $f0, 0x40($3)
    /* 1E37C 0011E37C 2C0060C4 */  lwc1       $f0, 0x2C($3)
    /* 1E380 0011E380 440060E4 */  swc1       $f0, 0x44($3)
    /* 1E384 0011E384 0800E003 */  jr         $31
    /* 1E388 0011E388 00000000 */   nop
    /* 1E38C 0011E38C 00000000 */  nop
.size func_0011e370, 0x20
