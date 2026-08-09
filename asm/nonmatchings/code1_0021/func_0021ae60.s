.section .text
.set noat
.set noreorder
glabel func_0021ae60
    /* 11AE60 0021AE60 80BF033C */  lui        $3, (0xBF800000 >> 16)
    /* 11AE64 0021AE64 0000A3AC */  sw         $3, 0x0($5)
    /* 11AE68 0021AE68 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 11AE6C 0021AE6C 0400A3AC */  sw         $3, 0x4($5)
    /* 11AE70 0021AE70 FFFF0324 */  addiu      $3, $0, -0x1
    /* 11AE74 0021AE74 1000A3A4 */  sh         $3, 0x10($5)
    /* 11AE78 0021AE78 0800E003 */  jr         $31
    /* 11AE7C 0021AE7C 00000000 */   nop
.size func_0021ae60, 0x20
