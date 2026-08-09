.section .text
.set noat
.set noreorder
glabel func_003db480
    /* 2DB480 003DB480 0000828C */  lw         $2, 0x0($4)
    /* 2DB484 003DB484 26104500 */  xor        $2, $2, $5
    /* 2DB488 003DB488 0800E003 */  jr         $31
    /* 2DB48C 003DB48C 0100422C */   sltiu     $2, $2, 0x1
.size func_003db480, 0x10
