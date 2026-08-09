.section .text
.set noat
.set noreorder
glabel func_003a15e0
    /* 2A15E0 003A15E0 10B6838F */  lw         $3, -0x49F0($28)
    /* 2A15E4 003A15E4 2D108000 */  daddu      $2, $4, $0
    /* 2A15E8 003A15E8 21188300 */  addu       $3, $4, $3
    /* 2A15EC 003A15EC 0800E003 */  jr         $31
    /* 2A15F0 003A15F0 000060AC */   sw        $0, 0x0($3)
    /* 2A15F4 003A15F4 00000000 */  nop
    /* 2A15F8 003A15F8 00000000 */  nop
    /* 2A15FC 003A15FC 00000000 */  nop
.size func_003a15e0, 0x20
