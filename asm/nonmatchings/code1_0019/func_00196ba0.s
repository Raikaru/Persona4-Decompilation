.section .text
.set noat
.set noreorder
glabel func_00196ba0
    /* 96BA0 00196BA0 C400858C */  lw         $5, 0xC4($4)
    /* 96BA4 00196BA4 FDFF0324 */  addiu      $3, $0, -0x3
    /* 96BA8 00196BA8 2418A300 */  and        $3, $5, $3
    /* 96BAC 00196BAC C40083AC */  sw         $3, 0xC4($4)
    /* 96BB0 00196BB0 C8008394 */  lhu        $3, 0xC8($4)
    /* 96BB4 00196BB4 FDFF6330 */  andi       $3, $3, 0xFFFD
    /* 96BB8 00196BB8 C80083A4 */  sh         $3, 0xC8($4)
    /* 96BBC 00196BBC 0800E003 */  jr         $31
    /* 96BC0 00196BC0 00000000 */   nop
    /* 96BC4 00196BC4 00000000 */  nop
    /* 96BC8 00196BC8 00000000 */  nop
    /* 96BCC 00196BCC 00000000 */  nop
.size func_00196ba0, 0x30
