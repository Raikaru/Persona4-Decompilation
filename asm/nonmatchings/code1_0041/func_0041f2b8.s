.section .text
.set noat
.set noreorder
glabel func_0041f2b8
    /* 31F2B8 0041F2B8 4000828C */  lw         $2, 0x40($4)
    /* 31F2BC 0041F2BC B00047AC */  sw         $7, 0xB0($2)
    /* 31F2C0 0041F2C0 A80045AC */  sw         $5, 0xA8($2)
    /* 31F2C4 0041F2C4 0800E003 */  jr         $31
    /* 31F2C8 0041F2C8 AC0046AC */   sw        $6, 0xAC($2)
    /* 31F2CC 0041F2CC 00000000 */  nop
.size func_0041f2b8, 0x18
