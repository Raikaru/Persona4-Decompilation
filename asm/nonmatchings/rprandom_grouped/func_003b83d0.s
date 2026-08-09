.section .text
.set noat
.set noreorder
glabel func_003b83d0
    /* 2B83D0 003B83D0 8800023C */  lui        $2, %hi(D_00886494)
    /* 2B83D4 003B83D4 9464438C */  lw         $3, %lo(D_00886494)($2)
    /* 2B83D8 003B83D8 21188300 */  addu       $3, $4, $3
    /* 2B83DC 003B83DC 2D108000 */  daddu      $2, $4, $0
    /* 2B83E0 003B83E0 0800E003 */  jr         $31
    /* 2B83E4 003B83E4 000065AC */   sw        $5, 0x0($3)
    /* 2B83E8 003B83E8 00000000 */  nop
    /* 2B83EC 003B83EC 00000000 */  nop
.size func_003b83d0, 0x20
