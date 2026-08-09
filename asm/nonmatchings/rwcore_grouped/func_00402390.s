.section .text
.set noat
.set noreorder
glabel func_00402390
    /* 302390 00402390 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 302394 00402394 1000A2D8 */  lqc2       $vf2, 0x10($5)
    /* 302398 00402398 2000A3D8 */  lqc2       $vf3, 0x20($5)
    /* 30239C 0040239C 3000A4D8 */  lqc2       $vf4, 0x30($5)
    /* 3023A0 004023A0 0000C5D8 */  lqc2       $vf5, 0x0($6)
    /* 3023A4 004023A4 1000C6D8 */  lqc2       $vf6, 0x10($6)
    /* 3023A8 004023A8 2000C7D8 */  lqc2       $vf7, 0x20($6)
    /* 3023AC 004023AC 3000C8D8 */  lqc2       $vf8, 0x30($6)
    /* 3023B0 004023B0 00008DD8 */  lqc2       $vf13, 0x0($4)
    /* 3023B4 004023B4 BC29C14B */  vmulax.xyz $ACC, $vf5, $vf1x
    /* 3023B8 004023B8 BD30C14B */  vmadday.xyz $ACC, $vf6, $vf1y
    /* 3023BC 004023BC 4A3AC14B */  vmaddz.xyz $vf9, $vf7, $vf1z
    /* 3023C0 004023C0 BC29C24B */  vmulax.xyz $ACC, $vf5, $vf2x
    /* 3023C4 004023C4 BD30C24B */  vmadday.xyz $ACC, $vf6, $vf2y
    /* 3023C8 004023C8 8A3AC24B */  vmaddz.xyz $vf10, $vf7, $vf2z
    /* 3023CC 004023CC 3C6B294A */  vmove.w    $vf9, $vf13
    /* 3023D0 004023D0 BC29C34B */  vmulax.xyz $ACC, $vf5, $vf3x
    /* 3023D4 004023D4 BD30C34B */  vmadday.xyz $ACC, $vf6, $vf3y
    /* 3023D8 004023D8 CA3AC34B */  vmaddz.xyz $vf11, $vf7, $vf3z
    /* 3023DC 004023DC BC29C44B */  vmulax.xyz $ACC, $vf5, $vf4x
    /* 3023E0 004023E0 BD30C44B */  vmadday.xyz $ACC, $vf6, $vf4y
    /* 3023E4 004023E4 BE38C44B */  vmaddaz.xyz $ACC, $vf7, $vf4z
    /* 3023E8 004023E8 0B43C04B */  vmaddw.xyz $vf12, $vf8, $vf0w
    /* 3023EC 004023EC 000089F8 */  sqc2       $vf9, 0x0($4)
    /* 3023F0 004023F0 10008AF8 */  sqc2       $vf10, 0x10($4)
    /* 3023F4 004023F4 20008BF8 */  sqc2       $vf11, 0x20($4)
    /* 3023F8 004023F8 30008CF8 */  sqc2       $vf12, 0x30($4)
    /* 3023FC 004023FC 0800E003 */  jr         $31
    /* 302400 00402400 00000000 */   nop
    /* 302404 00402404 00000000 */  nop
    /* 302408 00402408 00000000 */  nop
    /* 30240C 0040240C 00000000 */  nop
.size func_00402390, 0x80
