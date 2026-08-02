.section .text
.set noat
.set noreorder
glabel func_002a6af0
    /* 1A6AF0 002A6AF0 AC03828C */  lw         $2, 0x3AC($4)
    /* 1A6AF4 002A6AF4 80100200 */  sll        $2, $2, 2
    /* 1A6AF8 002A6AF8 21104400 */  addu       $2, $2, $4
    /* 1A6AFC 002A6AFC 1400428C */  lw         $2, 0x14($2)
    /* 1A6B00 002A6B00 0800E003 */  jr         $31
    /* 1A6B04 002A6B04 00000000 */   nop
    /* 1A6B08 002A6B08 00000000 */  nop
    /* 1A6B0C 002A6B0C 00000000 */  nop
.size func_002a6af0, 0x20
