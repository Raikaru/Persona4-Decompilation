.section .text
.set noat
.set noreorder
glabel func_004bc4d0
    /* 3BC4D0 004BC4D0 280080AC */  sw         $0, 0x28($4)
    /* 3BC4D4 004BC4D4 2C0080C4 */  lwc1       $f0, 0x2C($4)
    /* 3BC4D8 004BC4D8 300080E4 */  swc1       $f0, 0x30($4)
    /* 3BC4DC 004BC4DC 34008CE4 */  swc1       $f12, 0x34($4)
    /* 3BC4E0 004BC4E0 0400838C */  lw         $3, 0x4($4)
    /* 3BC4E4 004BC4E4 01006334 */  ori        $3, $3, 0x1
    /* 3BC4E8 004BC4E8 040083AC */  sw         $3, 0x4($4)
    /* 3BC4EC 004BC4EC 0800E003 */  jr         $31
    /* 3BC4F0 004BC4F0 00000000 */   nop
    /* 3BC4F4 004BC4F4 00000000 */  nop
    /* 3BC4F8 004BC4F8 00000000 */  nop
    /* 3BC4FC 004BC4FC 00000000 */  nop
.size func_004bc4d0, 0x30
