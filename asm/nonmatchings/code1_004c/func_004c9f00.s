.section .text
.set noat
.set noreorder
glabel func_004c9f00
    /* 3C9F00 004C9F00 02160500 */  srl        $2, $5, 24
    /* 3C9F04 004C9F04 021A0500 */  srl        $3, $5, 8
    /* 3C9F08 004C9F08 02340500 */  srl        $6, $5, 16
    /* 3C9F0C 004C9F0C 030082A0 */  sb         $2, 0x3($4)
    /* 3C9F10 004C9F10 010083A0 */  sb         $3, 0x1($4)
    /* 3C9F14 004C9F14 020086A0 */  sb         $6, 0x2($4)
    /* 3C9F18 004C9F18 0800E003 */  jr         $31
    /* 3C9F1C 004C9F1C 000085A0 */   sb        $5, 0x0($4)
.size func_004c9f00, 0x20
