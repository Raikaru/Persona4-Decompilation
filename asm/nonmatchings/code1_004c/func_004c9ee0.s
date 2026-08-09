.section .text
.set noat
.set noreorder
glabel func_004c9ee0
    /* 3C9EE0 004C9EE0 02160500 */  srl        $2, $5, 24
    /* 3C9EE4 004C9EE4 021C0500 */  srl        $3, $5, 16
    /* 3C9EE8 004C9EE8 02320500 */  srl        $6, $5, 8
    /* 3C9EEC 004C9EEC 030085A0 */  sb         $5, 0x3($4)
    /* 3C9EF0 004C9EF0 000082A0 */  sb         $2, 0x0($4)
    /* 3C9EF4 004C9EF4 010083A0 */  sb         $3, 0x1($4)
    /* 3C9EF8 004C9EF8 0800E003 */  jr         $31
    /* 3C9EFC 004C9EFC 020086A0 */   sb        $6, 0x2($4)
.size func_004c9ee0, 0x20
