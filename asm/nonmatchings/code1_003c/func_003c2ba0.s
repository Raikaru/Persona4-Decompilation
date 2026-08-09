.section .text
.set noat
.set noreorder
glabel func_003c2ba0
    /* 2C2BA0 003C2BA0 2D18A000 */  daddu      $3, $5, $0
    /* 2C2BA4 003C2BA4 2D10C000 */  daddu      $2, $6, $0
    /* 2C2BA8 003C2BA8 2D288000 */  daddu      $5, $4, $0
    /* 2C2BAC 003C2BAC 2D40E000 */  daddu      $8, $7, $0
    /* 2C2BB0 003C2BB0 7100043C */  lui        $4, %hi(D_0070AFB0)
    /* 2C2BB4 003C2BB4 2D306000 */  daddu      $6, $3, $0
    /* 2C2BB8 003C2BB8 B0AF8424 */  addiu      $4, $4, %lo(D_0070AFB0)
    /* 2C2BBC 003C2BBC 088C0F08 */  j          func_003e3020
    /* 2C2BC0 003C2BC0 2D384000 */   daddu     $7, $2, $0
    /* 2C2BC4 003C2BC4 00000000 */  nop
    /* 2C2BC8 003C2BC8 00000000 */  nop
    /* 2C2BCC 003C2BCC 00000000 */  nop
.size func_003c2ba0, 0x30
