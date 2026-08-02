.section .text
.set noat
.set noreorder
glabel func_0036db60
    /* 26DB60 0036DB60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26DB64 0036DB64 1000BFFF */  sd         $31, 0x10($29)
    /* 26DB68 0036DB68 0000B07F */  sq         $16, 0x0($29)
    /* 26DB6C 0036DB6C 2D808000 */  daddu      $16, $4, $0
    /* 26DB70 0036DB70 4CA30D0C */  jal        func_00368d30
    /* 26DB74 0036DB74 00000000 */   nop
    /* 26DB78 0036DB78 40B20D0C */  jal        func_0036c900
    /* 26DB7C 0036DB7C 00000000 */   nop
    /* 26DB80 0036DB80 2D200002 */  daddu      $4, $16, $0
    /* 26DB84 0036DB84 E8B60D0C */  jal        func_0036dba0
    /* 26DB88 0036DB88 00000000 */   nop
    /* 26DB8C 0036DB8C 1000BFDF */  ld         $31, 0x10($29)
    /* 26DB90 0036DB90 0000B07B */  lq         $16, 0x0($29)
    /* 26DB94 0036DB94 2000BD27 */  addiu      $29, $29, 0x20
    /* 26DB98 0036DB98 0800E003 */  jr         $31
    /* 26DB9C 0036DB9C 00000000 */   nop
.size func_0036db60, 0x40
