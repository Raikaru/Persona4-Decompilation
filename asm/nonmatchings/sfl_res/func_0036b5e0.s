.section .text
.set noat
.set noreorder
glabel func_0036b5e0
    /* 26B5E0 0036B5E0 2C0082C4 */  lwc1       $f2, 0x2C($4)
    /* 26B5E4 0036B5E4 300081C4 */  lwc1       $f1, 0x30($4)
    /* 26B5E8 0036B5E8 340080C4 */  lwc1       $f0, 0x34($4)
    /* 26B5EC 0036B5EC 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 26B5F0 0036B5F0 0400A1E4 */  swc1       $f1, 0x4($5)
    /* 26B5F4 0036B5F4 0800A0E4 */  swc1       $f0, 0x8($5)
    /* 26B5F8 0036B5F8 0800E003 */  jr         $31
    /* 26B5FC 0036B5FC 00000000 */   nop
.size func_0036b5e0, 0x20
