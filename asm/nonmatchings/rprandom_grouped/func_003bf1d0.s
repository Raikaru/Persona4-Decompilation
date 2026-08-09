.section .text
.set noat
.set noreorder
glabel func_003bf1d0
    /* 2BF1D0 003BF1D0 B4B6838F */  lw         $3, -0x494C($28)
    /* 2BF1D4 003BF1D4 2D108000 */  daddu      $2, $4, $0
    /* 2BF1D8 003BF1D8 21188300 */  addu       $3, $4, $3
    /* 2BF1DC 003BF1DC 080060AC */  sw         $0, 0x8($3)
    /* 2BF1E0 003BF1E0 040060AC */  sw         $0, 0x4($3)
    /* 2BF1E4 003BF1E4 0800E003 */  jr         $31
    /* 2BF1E8 003BF1E8 000060AC */   sw        $0, 0x0($3)
    /* 2BF1EC 003BF1EC 00000000 */  nop
.size func_003bf1d0, 0x20
