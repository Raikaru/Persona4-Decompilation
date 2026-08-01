.section .text
.set noat
.set noreorder
glabel func_0041f550
    /* 31F550 0041F550 4000838C */  lw         $3, 0x40($4)
    /* 31F554 0041F554 01000224 */  addiu      $2, $0, 0x1
    /* 31F558 0041F558 01000424 */  addiu      $4, $0, 0x1
    /* 31F55C 0041F55C 900065FC */  sd         $5, 0x90($3)
    /* 31F560 0041F560 0800E003 */  jr         $31
    /* 31F564 0041F564 8C0064AC */   sw        $4, 0x8C($3)
.size func_0041f550, 0x18
