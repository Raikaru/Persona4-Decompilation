.section .text
.set noat
.set noreorder
glabel func_001bd560
    /* BD560 001BD560 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* BD564 001BD564 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* BD568 001BD568 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* BD56C 001BD56C 000082E4 */  swc1       $f2, 0x0($4)
    /* BD570 001BD570 040081E4 */  swc1       $f1, 0x4($4)
    /* BD574 001BD574 080080E4 */  swc1       $f0, 0x8($4)
    /* BD578 001BD578 0C00A3C4 */  lwc1       $f3, 0xC($5)
    /* BD57C 001BD57C 1000A2C4 */  lwc1       $f2, 0x10($5)
    /* BD580 001BD580 1400A1C4 */  lwc1       $f1, 0x14($5)
    /* BD584 001BD584 1800A0C4 */  lwc1       $f0, 0x18($5)
    /* BD588 001BD588 0C0083E4 */  swc1       $f3, 0xC($4)
    /* BD58C 001BD58C 100082E4 */  swc1       $f2, 0x10($4)
    /* BD590 001BD590 140081E4 */  swc1       $f1, 0x14($4)
    /* BD594 001BD594 180080E4 */  swc1       $f0, 0x18($4)
    /* BD598 001BD598 0800E003 */  jr         $31
    /* BD59C 001BD59C 00000000 */   nop
.size func_001bd560, 0x40
