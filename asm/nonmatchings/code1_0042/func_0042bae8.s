.section .text
.set noat
.set noreorder
glabel func_0042bae8
    /* 32BAE8 0042BAE8 7100033C */  lui        $3, %hi(D_0070CD14)
    /* 32BAEC 0042BAEC 0800E003 */  jr         $31
    /* 32BAF0 0042BAF0 14CD628C */   lw        $2, %lo(D_0070CD14)($3)
    /* 32BAF4 0042BAF4 00000000 */  nop
.size func_0042bae8, 0x10
