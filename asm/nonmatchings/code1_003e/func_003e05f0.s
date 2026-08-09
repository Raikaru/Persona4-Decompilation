.section .text
.set noat
.set noreorder
glabel func_003e05f0
    /* 2E05F0 003E05F0 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 2E05F4 003E05F4 1000A2D8 */  lqc2       $vf2, 0x10($5)
    /* 2E05F8 003E05F8 2000A3D8 */  lqc2       $vf3, 0x20($5)
    /* 2E05FC 003E05FC 3000A4D8 */  lqc2       $vf4, 0x30($5)
    /* 2E0600 003E0600 0C00A39C */  lwu        $3, 0xC($5)
    /* 2E0604 003E0604 0000C5D8 */  lqc2       $vf5, 0x0($6)
    /* 2E0608 003E0608 1000C6D8 */  lqc2       $vf6, 0x10($6)
    /* 2E060C 003E060C 2000C7D8 */  lqc2       $vf7, 0x20($6)
    /* 2E0610 003E0610 3000C8D8 */  lqc2       $vf8, 0x30($6)
    /* 2E0614 003E0614 0C00C29C */  lwu        $2, 0xC($6)
    /* 2E0618 003E0618 BC29C14B */  vmulax.xyz $ACC, $vf5, $vf1x
    /* 2E061C 003E061C BD30C14B */  vmadday.xyz $ACC, $vf6, $vf1y
    /* 2E0620 003E0620 4A3AC14B */  vmaddz.xyz $vf9, $vf7, $vf1z
    /* 2E0624 003E0624 BC29C24B */  vmulax.xyz $ACC, $vf5, $vf2x
    /* 2E0628 003E0628 BD30C24B */  vmadday.xyz $ACC, $vf6, $vf2y
    /* 2E062C 003E062C 8A3AC24B */  vmaddz.xyz $vf10, $vf7, $vf2z
    /* 2E0630 003E0630 BC29C34B */  vmulax.xyz $ACC, $vf5, $vf3x
    /* 2E0634 003E0634 BD30C34B */  vmadday.xyz $ACC, $vf6, $vf3y
    /* 2E0638 003E0638 CA3AC34B */  vmaddz.xyz $vf11, $vf7, $vf3z
    /* 2E063C 003E063C BC29C44B */  vmulax.xyz $ACC, $vf5, $vf4x
    /* 2E0640 003E0640 BD30C44B */  vmadday.xyz $ACC, $vf6, $vf4y
    /* 2E0644 003E0644 BE38C44B */  vmaddaz.xyz $ACC, $vf7, $vf4z
    /* 2E0648 003E0648 0B43C04B */  vmaddw.xyz $vf12, $vf8, $vf0w
    /* 2E064C 003E064C 24104300 */  and        $2, $2, $3
    /* 2E0650 003E0650 000089F8 */  sqc2       $vf9, 0x0($4)
    /* 2E0654 003E0654 10008AF8 */  sqc2       $vf10, 0x10($4)
    /* 2E0658 003E0658 20008BF8 */  sqc2       $vf11, 0x20($4)
    /* 2E065C 003E065C 30008CF8 */  sqc2       $vf12, 0x30($4)
    /* 2E0660 003E0660 0C0082AC */  sw         $2, 0xC($4)
    /* 2E0664 003E0664 0800E003 */  jr         $31
    /* 2E0668 003E0668 2D108000 */   daddu     $2, $4, $0
    /* 2E066C 003E066C 00000000 */  nop
.size func_003e05f0, 0x80
