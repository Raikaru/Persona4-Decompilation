.section .text
.set noat
.set noreorder
glabel func_004f0508
    /* 3F0508 004F0508 02008294 */  lhu        $2, 0x2($4)
    /* 3F050C 004F050C 01004224 */  addiu      $2, $2, 0x1
    /* 3F0510 004F0510 0800E003 */  jr         $31
    /* 3F0514 004F0514 020082A4 */   sh        $2, 0x2($4)
.size func_004f0508, 0x10
