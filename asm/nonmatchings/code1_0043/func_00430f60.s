.section .text
.set noat
.set noreorder
glabel func_00430f60
    /* 330F60 00430F60 7100033C */  lui        $3, %hi(D_0070F8C8)
    /* 330F64 00430F64 C8F8628C */  lw         $2, %lo(D_0070F8C8)($3)
    /* 330F68 00430F68 C8F864AC */  sw         $4, %lo(D_0070F8C8)($3)
    /* 330F6C 00430F6C 2D208003 */  daddu      $4, $28, $0
    /* 330F70 00430F70 7100033C */  lui        $3, %hi(D_0070F8CC)
    /* 330F74 00430F74 0800E003 */  jr         $31
    /* 330F78 00430F78 CCF864AC */   sw        $4, %lo(D_0070F8CC)($3)
    /* 330F7C 00430F7C 00000000 */  nop
.size func_00430f60, 0x20
