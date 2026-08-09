.section .text
.set noat
.set noreorder
glabel func_003e0180
    /* 2E0180 003E0180 240089C4 */  lwc1       $f9, 0x24($4)
    /* 2E0184 003E0184 140088C4 */  lwc1       $f8, 0x14($4)
    /* 2E0188 003E0188 200087C4 */  lwc1       $f7, 0x20($4)
    /* 2E018C 003E018C 100086C4 */  lwc1       $f6, 0x10($4)
    /* 2E0190 003E0190 280081C4 */  lwc1       $f1, 0x28($4)
    /* 2E0194 003E0194 180085C4 */  lwc1       $f5, 0x18($4)
    /* 2E0198 003E0198 040083C4 */  lwc1       $f3, 0x4($4)
    /* 2E019C 003E019C 1A400946 */  mula.s     $f8, $f9
    /* 2E01A0 003E01A0 000082C4 */  lwc1       $f2, 0x0($4)
    /* 2E01A4 003E01A4 1E300746 */  madda.s    $f6, $f7
    /* 2E01A8 003E01A8 080080C4 */  lwc1       $f0, 0x8($4)
    /* 2E01AC 003E01AC 1C290146 */  madd.s     $f4, $f5, $f1
    /* 2E01B0 003E01B0 1A480346 */  mula.s     $f9, $f3
    /* 2E01B4 003E01B4 1E380246 */  madda.s    $f7, $f2
    /* 2E01B8 003E01B8 5C080046 */  madd.s     $f1, $f1, $f0
    /* 2E01BC 003E01BC 1A180846 */  mula.s     $f3, $f8
    /* 2E01C0 003E01C0 1E100646 */  madda.s    $f2, $f6
    /* 2E01C4 003E01C4 1C000546 */  madd.s     $f0, $f0, $f5
    /* 2E01C8 003E01C8 1A080146 */  mula.s     $f1, $f1
    /* 2E01CC 003E01CC 1E200446 */  madda.s    $f4, $f4
    /* 2E01D0 003E01D0 0800E003 */  jr         $31
    /* 2E01D4 003E01D4 1C000046 */   madd.s    $f0, $f0, $f0
    /* 2E01D8 003E01D8 00000000 */  nop
    /* 2E01DC 003E01DC 00000000 */  nop
.size func_003e0180, 0x60
