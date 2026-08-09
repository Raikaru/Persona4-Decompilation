.section .text
.set noat
.set noreorder
glabel func_0052bd40
    /* 42BD40 0052BD40 0400838C */  lw         $3, 0x4($4)
    /* 42BD44 0052BD44 0000868C */  lw         $6, 0x0($4)
    /* 42BD48 0052BD48 1818A300 */  mult       $3, $5, $3
    /* 42BD4C 0052BD4C 0800828C */  lw         $2, 0x8($4)
    /* 42BD50 0052BD50 23104500 */  subu       $2, $2, $5
    /* 42BD54 0052BD54 080082AC */  sw         $2, 0x8($4)
    /* 42BD58 0052BD58 2130C300 */  addu       $6, $6, $3
    /* 42BD5C 0052BD5C 0800E003 */  jr         $31
    /* 42BD60 0052BD60 000086AC */   sw        $6, 0x0($4)
    /* 42BD64 0052BD64 00000000 */  nop
.size func_0052bd40, 0x28
