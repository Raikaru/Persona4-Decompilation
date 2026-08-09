.section .text
.set noat
.set noreorder
glabel func_001bd5e0
    /* BD5E0 001BD5E0 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* BD5E4 001BD5E4 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* BD5E8 001BD5E8 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* BD5EC 001BD5EC 000082E4 */  swc1       $f2, 0x0($4)
    /* BD5F0 001BD5F0 040081E4 */  swc1       $f1, 0x4($4)
    /* BD5F4 001BD5F4 080080E4 */  swc1       $f0, 0x8($4)
    /* BD5F8 001BD5F8 0C00A3C4 */  lwc1       $f3, 0xC($5)
    /* BD5FC 001BD5FC 1000A2C4 */  lwc1       $f2, 0x10($5)
    /* BD600 001BD600 1400A1C4 */  lwc1       $f1, 0x14($5)
    /* BD604 001BD604 1800A0C4 */  lwc1       $f0, 0x18($5)
    /* BD608 001BD608 0C0083E4 */  swc1       $f3, 0xC($4)
    /* BD60C 001BD60C 100082E4 */  swc1       $f2, 0x10($4)
    /* BD610 001BD610 140081E4 */  swc1       $f1, 0x14($4)
    /* BD614 001BD614 180080E4 */  swc1       $f0, 0x18($4)
    /* BD618 001BD618 0800E003 */  jr         $31
    /* BD61C 001BD61C 00000000 */   nop
.size func_001bd5e0, 0x40
