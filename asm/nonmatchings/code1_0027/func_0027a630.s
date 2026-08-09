.section .text
.set noat
.set noreorder
glabel func_0027a630
    /* 17A630 0027A630 000080AC */  sw         $0, 0x0($4)
    /* 17A634 0027A634 FFFF0334 */  ori        $3, $0, 0xFFFF
    /* 17A638 0027A638 040083A4 */  sh         $3, 0x4($4)
    /* 17A63C 0027A63C 0800E003 */  jr         $31
    /* 17A640 0027A640 00000000 */   nop
    /* 17A644 0027A644 00000000 */  nop
    /* 17A648 0027A648 00000000 */  nop
    /* 17A64C 0027A64C 00000000 */  nop
.size func_0027a630, 0x20
