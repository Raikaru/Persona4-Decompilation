.section .text
.set noat
.set noreorder
glabel func_003b7b00
    /* 2B7B00 003B7B00 8800023C */  lui        $2, %hi(D_00886494)
    /* 2B7B04 003B7B04 9464438C */  lw         $3, %lo(D_00886494)($2)
    /* 2B7B08 003B7B08 2128A300 */  addu       $5, $5, $3
    /* 2B7B0C 003B7B0C 2D108000 */  daddu      $2, $4, $0
    /* 2B7B10 003B7B10 21188300 */  addu       $3, $4, $3
    /* 2B7B14 003B7B14 0000A48C */  lw         $4, 0x0($5)
    /* 2B7B18 003B7B18 0800E003 */  jr         $31
    /* 2B7B1C 003B7B1C 000064AC */   sw        $4, 0x0($3)
.size func_003b7b00, 0x20
