.section .text
.set noat
.set noreorder
glabel func_003bf1a0
    /* 2BF1A0 003BF1A0 B0B6838F */  lw         $3, -0x4950($28)
    /* 2BF1A4 003BF1A4 2D108000 */  daddu      $2, $4, $0
    /* 2BF1A8 003BF1A8 21188300 */  addu       $3, $4, $3
    /* 2BF1AC 003BF1AC 080060AC */  sw         $0, 0x8($3)
    /* 2BF1B0 003BF1B0 040060AC */  sw         $0, 0x4($3)
    /* 2BF1B4 003BF1B4 0800E003 */  jr         $31
    /* 2BF1B8 003BF1B8 000060AC */   sw        $0, 0x0($3)
    /* 2BF1BC 003BF1BC 00000000 */  nop
.size func_003bf1a0, 0x20
