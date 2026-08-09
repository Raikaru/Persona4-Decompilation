.section .text
.set noat
.set noreorder
glabel func_0042c300
    /* 32C300 0042C300 2D288000 */  daddu      $5, $4, $0
    /* 32C304 0042C304 00B0043C */  lui        $4, (0xB0001000 >> 16)
    /* 32C308 0042C308 A4B01008 */  j          func_0042c290
    /* 32C30C 0042C30C 00108434 */   ori       $4, $4, (0xB0001000 & 0xFFFF)
.size func_0042c300, 0x10
