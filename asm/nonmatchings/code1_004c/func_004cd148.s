.section .text
.set noat
.set noreorder
glabel func_004cd148
    /* 3CD148 004CD148 9200023C */  lui        $2, %hi(D_00922E20)
    /* 3CD14C 004CD14C 9200033C */  lui        $3, %hi(D_00922E28)
    /* 3CD150 004CD150 202E4224 */  addiu      $2, $2, %lo(D_00922E20)
    /* 3CD154 004CD154 282E6324 */  addiu      $3, $3, %lo(D_00922E28)
    /* 3CD158 004CD158 040045AC */  sw         $5, 0x4($2)
    /* 3CD15C 004CD15C 000044AC */  sw         $4, 0x0($2)
    /* 3CD160 004CD160 040067AC */  sw         $7, 0x4($3)
    /* 3CD164 004CD164 0800E003 */  jr         $31
    /* 3CD168 004CD168 000066AC */   sw        $6, 0x0($3)
    /* 3CD16C 004CD16C 00000000 */  nop
.size func_004cd148, 0x28
