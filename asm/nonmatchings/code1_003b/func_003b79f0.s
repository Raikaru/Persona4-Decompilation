.section .text
.set noat
.set noreorder
glabel func_003b79f0
    /* 2B79F0 003B79F0 8800023C */  lui        $2, %hi(D_00886498)
    /* 2B79F4 003B79F4 9864438C */  lw         $3, %lo(D_00886498)($2)
    /* 2B79F8 003B79F8 21188300 */  addu       $3, $4, $3
    /* 2B79FC 003B79FC 2D108000 */  daddu      $2, $4, $0
    /* 2B7A00 003B7A00 0800E003 */  jr         $31
    /* 2B7A04 003B7A04 000060AC */   sw        $0, 0x0($3)
    /* 2B7A08 003B7A08 00000000 */  nop
    /* 2B7A0C 003B7A0C 00000000 */  nop
.size func_003b79f0, 0x20
