.section .text
.set noat
.set noreorder
glabel func_0052a6a8
    /* 42A6A8 0052A6A8 14008424 */  addiu      $4, $4, 0x14
    /* 42A6AC 0052A6AC 020087A0 */  sb         $7, 0x2($4)
    /* 42A6B0 0052A6B0 000085A0 */  sb         $5, 0x0($4)
    /* 42A6B4 0052A6B4 0800E003 */  jr         $31
    /* 42A6B8 0052A6B8 010086A0 */   sb        $6, 0x1($4)
    /* 42A6BC 0052A6BC 00000000 */  nop
.size func_0052a6a8, 0x18
