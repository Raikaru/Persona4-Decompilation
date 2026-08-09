.section .text
.set noat
.set noreorder
glabel func_002b2a30
    /* 1B2A30 002B2A30 FF00E330 */  andi       $3, $7, 0xFF
    /* 1B2A34 002B2A34 FF00C230 */  andi       $2, $6, 0xFF
    /* 1B2A38 002B2A38 00120200 */  sll        $2, $2, 8
    /* 1B2A3C 002B2A3C 25186200 */  or         $3, $3, $2
    /* 1B2A40 002B2A40 FF00A230 */  andi       $2, $5, 0xFF
    /* 1B2A44 002B2A44 00140200 */  sll        $2, $2, 16
    /* 1B2A48 002B2A48 25184300 */  or         $3, $2, $3
    /* 1B2A4C 002B2A4C FF008230 */  andi       $2, $4, 0xFF
    /* 1B2A50 002B2A50 00160200 */  sll        $2, $2, 24
    /* 1B2A54 002B2A54 25104300 */  or         $2, $2, $3
    /* 1B2A58 002B2A58 0800E003 */  jr         $31
    /* 1B2A5C 002B2A5C 00000000 */   nop
.size func_002b2a30, 0x30
