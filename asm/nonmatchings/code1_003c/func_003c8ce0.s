.section .text
.set noat
.set noreorder
glabel func_003c8ce0
    /* 2C8CE0 003C8CE0 8800023C */  lui        $2, %hi(D_008872E4)
    /* 2C8CE4 003C8CE4 E472428C */  lw         $2, %lo(D_008872E4)($2)
    /* 2C8CE8 003C8CE8 6800428C */  lw         $2, 0x68($2)
    /* 2C8CEC 003C8CEC 08004000 */  jr         $2
    /* 2C8CF0 003C8CF0 00000000 */   nop
    /* 2C8CF4 003C8CF4 00000000 */  nop
    /* 2C8CF8 003C8CF8 00000000 */  nop
    /* 2C8CFC 003C8CFC 00000000 */  nop
.size func_003c8ce0, 0x20
