.section .text
.set noat
.set noreorder
glabel func_004e4618
    /* 3E4618 004E4618 7300033C */  lui        $3, %hi(D_00731C6C)
    /* 3E461C 004E461C 7300023C */  lui        $2, %hi(D_00731C68)
    /* 3E4620 004E4620 6C1C6324 */  addiu      $3, $3, %lo(D_00731C6C)
    /* 3E4624 004E4624 681C4224 */  addiu      $2, $2, %lo(D_00731C68)
    /* 3E4628 004E4628 0000658C */  lw         $5, 0x0($3)
    /* 3E462C 004E462C 000045AC */  sw         $5, 0x0($2)
    /* 3E4630 004E4630 0800E003 */  jr         $31
    /* 3E4634 004E4634 000064AC */   sw        $4, 0x0($3)
.size func_004e4618, 0x20
