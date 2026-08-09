.section .text
.set noat
.set noreorder
glabel func_0052a6c0
    /* 42A6C0 0052A6C0 14008424 */  addiu      $4, $4, 0x14
    /* 42A6C4 0052A6C4 00008290 */  lbu        $2, 0x0($4)
    /* 42A6C8 0052A6C8 0000A2A0 */  sb         $2, 0x0($5)
    /* 42A6CC 0052A6CC 01008390 */  lbu        $3, 0x1($4)
    /* 42A6D0 0052A6D0 0000C3A0 */  sb         $3, 0x0($6)
    /* 42A6D4 0052A6D4 02008290 */  lbu        $2, 0x2($4)
    /* 42A6D8 0052A6D8 0800E003 */  jr         $31
    /* 42A6DC 0052A6DC 0000E2A0 */   sb        $2, 0x0($7)
.size func_0052a6c0, 0x20
