.section .text
.set noat
.set noreorder
glabel func_00513790
    /* 413790 00513790 7400033C */  lui        $3, %hi(D_00745AC0)
    /* 413794 00513794 0800E003 */  jr         $31
    /* 413798 00513798 C05A628C */   lw        $2, %lo(D_00745AC0)($3)
    /* 41379C 0051379C 00000000 */  nop
.size func_00513790, 0x10
