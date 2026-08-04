.section .text
.set noat
.set noreorder
glabel func_001f3b20
    /* F3B20 001F3B20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F3B24 001F3B24 1000BFFF */  sd         $31, 0x10($29)
    /* F3B28 001F3B28 0000B07F */  sq         $16, 0x0($29)
    /* F3B2C 001F3B2C 2D808000 */  daddu      $16, $4, $0
    /* F3B30 001F3B30 02070424 */  addiu      $4, $0, 0x702
    /* F3B34 001F3B34 04000524 */  addiu      $5, $0, 0x4
    /* F3B38 001F3B38 1C51060C */  jal        func_00194470
    /* F3B3C 001F3B3C 00000000 */   nop
    /* F3B40 001F3B40 1F00033C */  lui        $3, %hi(func_001f39b0)
    /* F3B44 001F3B44 B0396324 */  addiu      $3, $3, %lo(func_001f39b0)
    /* F3B48 001F3B48 680043AC */  sw         $3, 0x68($2)
    /* F3B4C 001F3B4C 1F00033C */  lui        $3, %hi(func_001f39d0)
    /* F3B50 001F3B50 D0396324 */  addiu      $3, $3, %lo(func_001f39d0)
    /* F3B54 001F3B54 6C0043AC */  sw         $3, 0x6C($2)
    /* F3B58 001F3B58 1F00033C */  lui        $3, %hi(func_001f3b00)
    /* F3B5C 001F3B5C 003B6324 */  addiu      $3, $3, %lo(func_001f3b00)
    /* F3B60 001F3B60 700043AC */  sw         $3, 0x70($2)
    /* F3B64 001F3B64 7800438C */  lw         $3, 0x78($2)
    /* F3B68 001F3B68 000070AC */  sw         $16, 0x0($3)
    /* F3B6C 001F3B6C 1000BFDF */  ld         $31, 0x10($29)
    /* F3B70 001F3B70 0000B07B */  lq         $16, 0x0($29)
    /* F3B74 001F3B74 2000BD27 */  addiu      $29, $29, 0x20
    /* F3B78 001F3B78 0800E003 */  jr         $31
    /* F3B7C 001F3B7C 00000000 */   nop
.size func_001f3b20, 0x60
