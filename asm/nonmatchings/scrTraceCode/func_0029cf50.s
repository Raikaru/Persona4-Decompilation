.section .text
.set noat
.set noreorder
glabel func_0029cf50
    /* 19CF50 0029CF50 10B5838F */  lw         $3, -0x4AF0($28)
    /* 19CF54 0029CF54 4F0060A0 */  sb         $0, 0x4F($3)
    /* 19CF58 0029CF58 10B5838F */  lw         $3, -0x4AF0($28)
    /* 19CF5C 0029CF5C 0C0164AC */  sw         $4, 0x10C($3)
    /* 19CF60 0029CF60 0800E003 */  jr         $31
    /* 19CF64 0029CF64 00000000 */   nop
    /* 19CF68 0029CF68 00000000 */  nop
    /* 19CF6C 0029CF6C 00000000 */  nop
.size func_0029cf50, 0x20
