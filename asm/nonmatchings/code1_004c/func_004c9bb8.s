.section .text
.set noat
.set noreorder
glabel func_004c9bb8
    /* 3C9BB8 004C9BB8 80200400 */  sll        $4, $4, 2
    /* 3C9BBC 004C9BBC 7100023C */  lui        $2, %hi(D_007161F0)
    /* 3C9BC0 004C9BC0 21104400 */  addu       $2, $2, $4
    /* 3C9BC4 004C9BC4 F061428C */  lw         $2, %lo(D_007161F0)($2)
    /* 3C9BC8 004C9BC8 0800E003 */  jr         $31
    /* 3C9BCC 004C9BCC 10004224 */   addiu     $2, $2, 0x10
.size func_004c9bb8, 0x18
