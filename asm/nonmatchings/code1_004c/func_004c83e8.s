.section .text
.set noat
.set noreorder
glabel func_004c83e8
    /* 3C83E8 004C83E8 80200400 */  sll        $4, $4, 2
    /* 3C83EC 004C83EC 7100033C */  lui        $3, %hi(D_007161F0)
    /* 3C83F0 004C83F0 21186400 */  addu       $3, $3, $4
    /* 3C83F4 004C83F4 F061638C */  lw         $3, %lo(D_007161F0)($3)
    /* 3C83F8 004C83F8 0800E003 */  jr         $31
    /* 3C83FC 004C83FC 0400628C */   lw        $2, 0x4($3)
.size func_004c83e8, 0x18
