.section .text
.set noat
.set noreorder
glabel func_0042c310
    /* 32C310 0042C310 2D288000 */  daddu      $5, $4, $0
    /* 32C314 0042C314 00B0043C */  lui        $4, (0xB0001010 >> 16)
    /* 32C318 0042C318 A4B01008 */  j          func_0042c290
    /* 32C31C 0042C31C 10108434 */   ori       $4, $4, (0xB0001010 & 0xFFFF)
.size func_0042c310, 0x10
