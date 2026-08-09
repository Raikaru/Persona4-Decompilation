.section .text
.set noat
.set noreorder
glabel func_005248a8
    /* 4248A8 005248A8 E8030224 */  addiu      $2, $0, 0x3E8
    /* 4248AC 005248AC 0000C0AC */  sw         $0, 0x0($6)
    /* 4248B0 005248B0 0800E003 */  jr         $31
    /* 4248B4 005248B4 0000E2AC */   sw        $2, 0x0($7)
.size func_005248a8, 0x10
