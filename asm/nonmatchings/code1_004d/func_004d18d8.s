.section .text
.set noat
.set noreorder
glabel func_004d18d8
    /* 3D18D8 004D18D8 7200023C */  lui        $2, %hi(D_00723F10)
    /* 3D18DC 004D18DC 0800E003 */  jr         $31
    /* 3D18E0 004D18E0 103F44AC */   sw        $4, %lo(D_00723F10)($2)
    /* 3D18E4 004D18E4 00000000 */  nop
.size func_004d18d8, 0x10
