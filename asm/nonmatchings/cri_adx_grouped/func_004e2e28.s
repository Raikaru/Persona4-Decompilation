.section .text
.set noat
.set noreorder
glabel func_004e2e28
    /* 3E2E28 004E2E28 05008014 */  bnez       $4, .L004E2E40
    /* 3E2E2C 004E2E2C 7300023C */   lui       $2, %hi(D_00731BF4)
    /* 3E2E30 004E2E30 7300033C */  lui        $3, %hi(D_00731BF8)
    /* 3E2E34 004E2E34 F41B40AC */  sw         $0, %lo(D_00731BF4)($2)
    /* 3E2E38 004E2E38 0800E003 */  jr         $31
    /* 3E2E3C 004E2E3C F81B60AC */   sw        $0, %lo(D_00731BF8)($3)
  .L004E2E40:
    /* 3E2E40 004E2E40 7300033C */  lui        $3, %hi(D_00731BF8)
    /* 3E2E44 004E2E44 F41B44AC */  sw         $4, %lo(D_00731BF4)($2)
    /* 3E2E48 004E2E48 0800E003 */  jr         $31
    /* 3E2E4C 004E2E4C F81B65AC */   sw        $5, %lo(D_00731BF8)($3)
.size func_004e2e28, 0x28
