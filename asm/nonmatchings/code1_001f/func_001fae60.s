.section .text
.set noat
.set noreorder
glabel func_001fae60
    /* FAE60 001FAE60 ACB3838F */  lw         $3, -0x4C54($28)
    /* FAE64 001FAE64 400B64AC */  sw         $4, 0xB40($3)
    /* FAE68 001FAE68 ACB3838F */  lw         $3, -0x4C54($28)
    /* FAE6C 001FAE6C 440B65AC */  sw         $5, 0xB44($3)
    /* FAE70 001FAE70 ACB3838F */  lw         $3, -0x4C54($28)
    /* FAE74 001FAE74 480B66AC */  sw         $6, 0xB48($3)
    /* FAE78 001FAE78 0800E003 */  jr         $31
    /* FAE7C 001FAE7C 00000000 */   nop
.size func_001fae60, 0x20
