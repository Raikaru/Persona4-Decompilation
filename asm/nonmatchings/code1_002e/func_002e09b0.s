.section .text
.set noat
.set noreorder
glabel func_002e09b0
    /* 1E09B0 002E09B0 3800848C */  lw         $4, 0x38($4)
    /* 1E09B4 002E09B4 04008384 */  lh         $3, 0x4($4)
    /* 1E09B8 002E09B8 80006334 */  ori        $3, $3, 0x80
    /* 1E09BC 002E09BC 040083A4 */  sh         $3, 0x4($4)
    /* 1E09C0 002E09C0 F00080A4 */  sh         $0, 0xF0($4)
    /* 1E09C4 002E09C4 EC008CE4 */  swc1       $f12, 0xEC($4)
    /* 1E09C8 002E09C8 F20085A4 */  sh         $5, 0xF2($4)
    /* 1E09CC 002E09CC 0800E003 */  jr         $31
    /* 1E09D0 002E09D0 00000000 */   nop
    /* 1E09D4 002E09D4 00000000 */  nop
    /* 1E09D8 002E09D8 00000000 */  nop
    /* 1E09DC 002E09DC 00000000 */  nop
.size func_002e09b0, 0x30
