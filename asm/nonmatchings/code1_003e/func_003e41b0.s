.section .text
.set noat
.set noreorder
glabel func_003e41b0
    /* 2E41B0 003E41B0 040081C4 */  lwc1       $f1, 0x4($4)
    /* 2E41B4 003E41B4 000080C4 */  lwc1       $f0, 0x0($4)
    /* 2E41B8 003E41B8 1A080146 */  mula.s     $f1, $f1
    /* 2E41BC 003E41BC 1C000046 */  madd.s     $f0, $f0, $f0
    /* 2E41C0 003E41C0 04000046 */  c1         0x4
    /* 2E41C4 003E41C4 00000000 */  nop
    /* 2E41C8 003E41C8 00000000 */  nop
    /* 2E41CC 003E41CC 0800E003 */  jr         $31
    /* 2E41D0 003E41D0 00000000 */   nop
    /* 2E41D4 003E41D4 00000000 */  nop
    /* 2E41D8 003E41D8 00000000 */  nop
    /* 2E41DC 003E41DC 00000000 */  nop
.size func_003e41b0, 0x30
