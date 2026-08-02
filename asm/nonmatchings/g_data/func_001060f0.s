.section .text
.set noat
.set noreorder
glabel func_001060f0
    /* 60F0 001060F0 7900023C */  lui        $2, %hi(D_00797B80)
    /* 60F4 001060F4 807B428C */  lw         $2, %lo(D_00797B80)($2)
    /* 60F8 001060F8 0800E003 */  jr         $31
    /* 60FC 001060FC 00000000 */   nop
.size func_001060f0, 0x10
