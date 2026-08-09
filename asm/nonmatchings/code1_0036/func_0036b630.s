.section .text
.set noat
.set noreorder
glabel func_0036b630
    /* 26B630 0036B630 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 26B634 0036B634 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 26B638 0036B638 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 26B63C 0036B63C 940982E4 */  swc1       $f2, 0x994($4)
    /* 26B640 0036B640 980981E4 */  swc1       $f1, 0x998($4)
    /* 26B644 0036B644 9C0980E4 */  swc1       $f0, 0x99C($4)
    /* 26B648 0036B648 0800E003 */  jr         $31
    /* 26B64C 0036B64C 00000000 */   nop
.size func_0036b630, 0x20
