.section .text
.set noat
.set noreorder
glabel func_003bcbc0
    /* 2BCBC0 003BCBC0 21188500 */  addu       $3, $4, $5
    /* 2BCBC4 003BCBC4 2D108000 */  daddu      $2, $4, $0
    /* 2BCBC8 003BCBC8 000060AC */  sw         $0, 0x0($3)
    /* 2BCBCC 003BCBCC 0800E003 */  jr         $31
    /* 2BCBD0 003BCBD0 040060AC */   sw        $0, 0x4($3)
    /* 2BCBD4 003BCBD4 00000000 */  nop
    /* 2BCBD8 003BCBD8 00000000 */  nop
    /* 2BCBDC 003BCBDC 00000000 */  nop
.size func_003bcbc0, 0x20
