.section .text
.set noat
.set noreorder
glabel func_003cae70
    /* 2CAE70 003CAE70 10B7858F */  lw         $5, -0x48F0($28)
    /* 2CAE74 003CAE74 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CAE78 003CAE78 2D108000 */  daddu      $2, $4, $0
    /* 2CAE7C 003CAE7C E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CAE80 003CAE80 21288500 */  addu       $5, $4, $5
    /* 2CAE84 003CAE84 0000A0AC */  sw         $0, 0x0($5)
    /* 2CAE88 003CAE88 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CAE8C 003CAE8C 21186400 */  addu       $3, $3, $4
    /* 2CAE90 003CAE90 0800638C */  lw         $3, 0x8($3)
    /* 2CAE94 003CAE94 0800E003 */  jr         $31
    /* 2CAE98 003CAE98 0400A3AC */   sw        $3, 0x4($5)
    /* 2CAE9C 003CAE9C 00000000 */  nop
.size func_003cae70, 0x30
