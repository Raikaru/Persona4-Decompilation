.section .text
.set noat
.set noreorder
glabel func_001bd5a0
    /* BD5A0 001BD5A0 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* BD5A4 001BD5A4 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* BD5A8 001BD5A8 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* BD5AC 001BD5AC 000082E4 */  swc1       $f2, 0x0($4)
    /* BD5B0 001BD5B0 040081E4 */  swc1       $f1, 0x4($4)
    /* BD5B4 001BD5B4 080080E4 */  swc1       $f0, 0x8($4)
    /* BD5B8 001BD5B8 0C00A3C4 */  lwc1       $f3, 0xC($5)
    /* BD5BC 001BD5BC 1000A2C4 */  lwc1       $f2, 0x10($5)
    /* BD5C0 001BD5C0 1400A1C4 */  lwc1       $f1, 0x14($5)
    /* BD5C4 001BD5C4 1800A0C4 */  lwc1       $f0, 0x18($5)
    /* BD5C8 001BD5C8 0C0083E4 */  swc1       $f3, 0xC($4)
    /* BD5CC 001BD5CC 100082E4 */  swc1       $f2, 0x10($4)
    /* BD5D0 001BD5D0 140081E4 */  swc1       $f1, 0x14($4)
    /* BD5D4 001BD5D4 180080E4 */  swc1       $f0, 0x18($4)
    /* BD5D8 001BD5D8 0800E003 */  jr         $31
    /* BD5DC 001BD5DC 00000000 */   nop
.size func_001bd5a0, 0x40
