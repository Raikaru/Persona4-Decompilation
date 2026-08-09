.section .text
.set noat
.set noreorder
glabel func_0039ac60
    /* 29AC60 0039AC60 ECB5838F */  lw         $3, -0x4A14($28)
    /* 29AC64 0039AC64 2D108000 */  daddu      $2, $4, $0
    /* 29AC68 0039AC68 21188300 */  addu       $3, $4, $3
    /* 29AC6C 0039AC6C 000060AC */  sw         $0, 0x0($3)
    /* 29AC70 0039AC70 040060AC */  sw         $0, 0x4($3)
    /* 29AC74 0039AC74 0800E003 */  jr         $31
    /* 29AC78 0039AC78 080060AC */   sw        $0, 0x8($3)
    /* 29AC7C 0039AC7C 00000000 */  nop
.size func_0039ac60, 0x20
