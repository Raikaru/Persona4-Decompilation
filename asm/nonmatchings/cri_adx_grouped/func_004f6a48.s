.section .text
.set noat
.set noreorder
glabel func_004f6a48
    /* 3F6A48 004F6A48 00008290 */  lbu        $2, 0x0($4)
    /* 3F6A4C 004F6A4C 0000A2A0 */  sb         $2, 0x0($5)
    /* 3F6A50 004F6A50 01008390 */  lbu        $3, 0x1($4)
    /* 3F6A54 004F6A54 0100A3A0 */  sb         $3, 0x1($5)
    /* 3F6A58 004F6A58 02008290 */  lbu        $2, 0x2($4)
    /* 3F6A5C 004F6A5C 0200A2A0 */  sb         $2, 0x2($5)
    /* 3F6A60 004F6A60 03008390 */  lbu        $3, 0x3($4)
    /* 3F6A64 004F6A64 0800E003 */  jr         $31
    /* 3F6A68 004F6A68 0300A3A0 */   sb        $3, 0x3($5)
    /* 3F6A6C 004F6A6C 00000000 */  nop
.size func_004f6a48, 0x28
