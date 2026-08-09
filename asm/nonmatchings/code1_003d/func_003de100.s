.section .text
.set noat
.set noreorder
glabel func_003de100
    /* 2DE100 003DE100 5000828C */  lw         $2, 0x50($4)
    /* 2DE104 003DE104 4400428C */  lw         $2, 0x44($2)
    /* 2DE108 003DE108 08004000 */  jr         $2
    /* 2DE10C 003DE10C 00000000 */   nop
.size func_003de100, 0x10
