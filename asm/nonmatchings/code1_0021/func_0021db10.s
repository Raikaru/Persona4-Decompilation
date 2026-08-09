.section .text
.set noat
.set noreorder
glabel func_0021db10
    /* 11DB10 0021DB10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 11DB14 0021DB14 0000BFFF */  sd         $31, 0x0($29)
    /* 11DB18 0021DB18 5849110C */  jal        func_00452560
    /* 11DB1C 0021DB1C 00000000 */   nop
    /* 11DB20 0021DB20 0000428C */  lw         $2, 0x0($2)
    /* 11DB24 0021DB24 02004230 */  andi       $2, $2, 0x2
    /* 11DB28 0021DB28 2B100200 */  sltu       $2, $0, $2
    /* 11DB2C 0021DB2C 0000BFDF */  ld         $31, 0x0($29)
    /* 11DB30 0021DB30 1000BD27 */  addiu      $29, $29, 0x10
    /* 11DB34 0021DB34 0800E003 */  jr         $31
    /* 11DB38 0021DB38 00000000 */   nop
    /* 11DB3C 0021DB3C 00000000 */  nop
.size func_0021db10, 0x30
