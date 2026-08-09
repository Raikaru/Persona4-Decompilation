.section .text
.set noat
.set noreorder
glabel func_0014dce0
    /* 4DCE0 0014DCE0 3800888C */  lw         $8, 0x38($4)
    /* 4DCE4 0014DCE4 0000A790 */  lbu        $7, 0x0($5)
    /* 4DCE8 0014DCE8 0100A690 */  lbu        $6, 0x1($5)
    /* 4DCEC 0014DCEC 0200A490 */  lbu        $4, 0x2($5)
    /* 4DCF0 0014DCF0 0300A390 */  lbu        $3, 0x3($5)
    /* 4DCF4 0014DCF4 480007A1 */  sb         $7, 0x48($8)
    /* 4DCF8 0014DCF8 490006A1 */  sb         $6, 0x49($8)
    /* 4DCFC 0014DCFC 4A0004A1 */  sb         $4, 0x4A($8)
    /* 4DD00 0014DD00 4B0003A1 */  sb         $3, 0x4B($8)
    /* 4DD04 0014DD04 0800E003 */  jr         $31
    /* 4DD08 0014DD08 00000000 */   nop
    /* 4DD0C 0014DD0C 00000000 */  nop
.size func_0014dce0, 0x30
