.section .text
.set noat
.set noreorder
glabel func_00106320
    /* 6320 00106320 7900033C */  lui        $3, %hi(D_00797B80)
    /* 6324 00106324 807B64AC */  sw         $4, %lo(D_00797B80)($3)
    /* 6328 00106328 0800E003 */  jr         $31
    /* 632C 0010632C 00000000 */   nop
.size func_00106320, 0x10
