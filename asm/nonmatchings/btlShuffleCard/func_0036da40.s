.section .text
.set noat
.set noreorder
glabel func_0036da40
    /* 26DA40 0036DA40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 26DA44 0036DA44 2000BFFF */  sd         $31, 0x20($29)
    /* 26DA48 0036DA48 1000B17F */  sq         $17, 0x10($29)
    /* 26DA4C 0036DA4C 0000B07F */  sq         $16, 0x0($29)
    /* 26DA50 0036DA50 2D888000 */  daddu      $17, $4, $0
    /* 26DA54 0036DA54 2D80A000 */  daddu      $16, $5, $0
    /* 26DA58 0036DA58 EC9F0D0C */  jal        func_00367fb0
    /* 26DA5C 0036DA5C 00000000 */   nop
    /* 26DA60 0036DA60 2D202002 */  daddu      $4, $17, $0
    /* 26DA64 0036DA64 2D280002 */  daddu      $5, $16, $0
    /* 26DA68 0036DA68 08AA0D0C */  jal        func_0036a820
    /* 26DA6C 0036DA6C 00000000 */   nop
    /* 26DA70 0036DA70 2D200002 */  daddu      $4, $16, $0
    /* 26DA74 0036DA74 F8B10D0C */  jal        func_0036c7e0
    /* 26DA78 0036DA78 00000000 */   nop
    /* 26DA7C 0036DA7C 2D202002 */  daddu      $4, $17, $0
    /* 26DA80 0036DA80 E8B60D0C */  jal        func_0036dba0
    /* 26DA84 0036DA84 00000000 */   nop
    /* 26DA88 0036DA88 2000BFDF */  ld         $31, 0x20($29)
    /* 26DA8C 0036DA8C 1000B17B */  lq         $17, 0x10($29)
    /* 26DA90 0036DA90 0000B07B */  lq         $16, 0x0($29)
    /* 26DA94 0036DA94 3000BD27 */  addiu      $29, $29, 0x30
    /* 26DA98 0036DA98 0800E003 */  jr         $31
    /* 26DA9C 0036DA9C 00000000 */   nop
.size func_0036da40, 0x60
