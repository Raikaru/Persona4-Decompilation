.section .text
.set noat
.set noreorder
glabel func_004d3148
    /* 3D3148 004D3148 7200023C */  lui        $2, %hi(D_00723F20)
    /* 3D314C 004D314C 0800E003 */  jr         $31
    /* 3D3150 004D3150 203F44AC */   sw        $4, %lo(D_00723F20)($2)
    /* 3D3154 004D3154 00000000 */  nop
.size func_004d3148, 0x10
