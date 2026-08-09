.section .text
.set noat
.set noreorder
glabel func_0041f5d0
    /* 31F5D0 0041F5D0 4000838C */  lw         $3, 0x40($4)
    /* 31F5D4 0041F5D4 FC00628C */  lw         $2, 0xFC($3)
    /* 31F5D8 0041F5D8 0800E003 */  jr         $31
    /* 31F5DC 0041F5DC FC0065AC */   sw        $5, 0xFC($3)
.size func_0041f5d0, 0x10
