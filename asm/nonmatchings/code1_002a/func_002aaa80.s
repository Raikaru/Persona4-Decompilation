.section .text
.set noat
.set noreorder
glabel func_002aaa80
    /* 1AAA80 002AAA80 8800033C */  lui        $3, %hi(D_00882F20)
    /* 1AAA84 002AAA84 202F638C */  lw         $3, %lo(D_00882F20)($3)
    /* 1AAA88 002AAA88 01006434 */  ori        $4, $3, 0x1
    /* 1AAA8C 002AAA8C 8800033C */  lui        $3, %hi(D_00882F20)
    /* 1AAA90 002AAA90 202F64AC */  sw         $4, %lo(D_00882F20)($3)
    /* 1AAA94 002AAA94 0800E003 */  jr         $31
    /* 1AAA98 002AAA98 00000000 */   nop
    /* 1AAA9C 002AAA9C 00000000 */  nop
.size func_002aaa80, 0x20
