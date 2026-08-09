.section .text
.set noat
.set noreorder
glabel func_003ddc10
    /* 2DDC10 003DDC10 8800023C */  lui        $2, %hi(D_00887180)
    /* 2DDC14 003DDC14 0800E003 */  jr         $31
    /* 2DDC18 003DDC18 80714224 */   addiu     $2, $2, %lo(D_00887180)
    /* 2DDC1C 003DDC1C 00000000 */  nop
.size func_003ddc10, 0x10
