.section .text
.set noat
.set noreorder
glabel func_004fba98
    /* 3FBA98 004FBA98 48018424 */  addiu      $4, $4, 0x148
    /* 3FBA9C 004FBA9C 040086AC */  sw         $6, 0x4($4)
    /* 3FBAA0 004FBAA0 0800E003 */  jr         $31
    /* 3FBAA4 004FBAA4 000085AC */   sw        $5, 0x0($4)
.size func_004fba98, 0x10
