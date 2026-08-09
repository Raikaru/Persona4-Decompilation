.section .text
.set noat
.set noreorder
glabel func_0042da50
    /* 32DA50 0042DA50 7100023C */  lui        $2, %hi(D_0070DCB0)
    /* 32DA54 0042DA54 7100033C */  lui        $3, %hi(D_0070DCB4)
    /* 32DA58 0042DA58 8900043C */  lui        $4, %hi(D_00894A48)
    /* 32DA5C 0042DA5C B0DC40AC */  sw         $0, %lo(D_0070DCB0)($2)
    /* 32DA60 0042DA60 B4DC60AC */  sw         $0, %lo(D_0070DCB4)($3)
    /* 32DA64 0042DA64 484A8424 */  addiu      $4, $4, %lo(D_00894A48)
    /* 32DA68 0042DA68 2D280000 */  daddu      $5, $0, $0
    /* 32DA6C 0042DA6C 72FE1008 */  j          func_0043f9c8
    /* 32DA70 0042DA70 00020624 */   addiu     $6, $0, 0x200
    /* 32DA74 0042DA74 00000000 */  nop
.size func_0042da50, 0x28
