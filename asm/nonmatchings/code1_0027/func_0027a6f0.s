.section .text
.set noat
.set noreorder
glabel func_0027a6f0
    /* 17A6F0 0027A6F0 0000858C */  lw         $5, 0x0($4)
    /* 17A6F4 0027A6F4 FFF00324 */  addiu      $3, $0, -0xF01
    /* 17A6F8 0027A6F8 2418A300 */  and        $3, $5, $3
    /* 17A6FC 0027A6FC 000083AC */  sw         $3, 0x0($4)
    /* 17A700 0027A700 0800E003 */  jr         $31
    /* 17A704 0027A704 00000000 */   nop
    /* 17A708 0027A708 00000000 */  nop
    /* 17A70C 0027A70C 00000000 */  nop
.size func_0027a6f0, 0x20
