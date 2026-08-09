.section .text
.set noat
.set noreorder
glabel func_0041f580
    /* 31F580 0041F580 4000838C */  lw         $3, 0x40($4)
    /* 31F584 0041F584 01000224 */  addiu      $2, $0, 0x1
    /* 31F588 0041F588 0800E003 */  jr         $31
    /* 31F58C 0041F58C EC0065AC */   sw        $5, 0xEC($3)
.size func_0041f580, 0x10
