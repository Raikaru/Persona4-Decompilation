.section .text
.set noat
.set noreorder
glabel func_0029cf70
    /* 19CF70 0029CF70 01000424 */  addiu      $4, $0, 0x1
    /* 19CF74 0029CF74 10B5838F */  lw         $3, -0x4AF0($28)
    /* 19CF78 0029CF78 4F0064A0 */  sb         $4, 0x4F($3)
    /* 19CF7C 0029CF7C 10B5838F */  lw         $3, -0x4AF0($28)
    /* 19CF80 0029CF80 0C016CE4 */  swc1       $f12, 0x10C($3)
    /* 19CF84 0029CF84 0800E003 */  jr         $31
    /* 19CF88 0029CF88 00000000 */   nop
    /* 19CF8C 0029CF8C 00000000 */  nop
.size func_0029cf70, 0x20
