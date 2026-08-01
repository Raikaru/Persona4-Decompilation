.section .text
.set noat
.set noreorder
glabel func_005179e8
    /* 4179E8 005179E8 FC018424 */  addiu      $4, $4, 0x1FC
    /* 4179EC 005179EC 040080AC */  sw         $0, 0x4($4)
    /* 4179F0 005179F0 0800E003 */  jr         $31
    /* 4179F4 005179F4 000080AC */   sw        $0, 0x0($4)
.size func_005179e8, 0x10
