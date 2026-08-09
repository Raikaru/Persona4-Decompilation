.section .text
.set noat
.set noreorder
glabel func_0042c320
    /* 32C320 0042C320 2D288000 */  daddu      $5, $4, $0
    /* 32C324 0042C324 00B0043C */  lui        $4, (0xB0001020 >> 16)
    /* 32C328 0042C328 A4B01008 */  j          func_0042c290
    /* 32C32C 0042C32C 20108434 */   ori       $4, $4, (0xB0001020 & 0xFFFF)
.size func_0042c320, 0x10
