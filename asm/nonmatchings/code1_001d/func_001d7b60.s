.section .text
.set noat
.set noreorder
glabel func_001d7b60
    /* D7B60 001D7B60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D7B64 001D7B64 1000BFFF */  sd         $31, 0x10($29)
    /* D7B68 001D7B68 0000B07F */  sq         $16, 0x0($29)
    /* D7B6C 001D7B6C 2D808000 */  daddu      $16, $4, $0
    /* D7B70 001D7B70 0B030424 */  addiu      $4, $0, 0x30B
    /* D7B74 001D7B74 02000524 */  addiu      $5, $0, 0x2
    /* D7B78 001D7B78 1C51060C */  jal        func_00194470
    /* D7B7C 001D7B7C 00000000 */   nop
    /* D7B80 001D7B80 1D00033C */  lui        $3, %hi(func_001d7b30)
    /* D7B84 001D7B84 307B6324 */  addiu      $3, $3, %lo(func_001d7b30)
    /* D7B88 001D7B88 6C0043AC */  sw         $3, 0x6C($2)
    /* D7B8C 001D7B8C 7800438C */  lw         $3, 0x78($2)
    /* D7B90 001D7B90 000070A4 */  sh         $16, 0x0($3)
    /* D7B94 001D7B94 1000BFDF */  ld         $31, 0x10($29)
    /* D7B98 001D7B98 0000B07B */  lq         $16, 0x0($29)
    /* D7B9C 001D7B9C 2000BD27 */  addiu      $29, $29, 0x20
    /* D7BA0 001D7BA0 0800E003 */  jr         $31
    /* D7BA4 001D7BA4 00000000 */   nop
    /* D7BA8 001D7BA8 00000000 */  nop
    /* D7BAC 001D7BAC 00000000 */  nop
.size func_001d7b60, 0x50
