.section .text
.set noat
.set noreorder
glabel func_001f83b0
    /* F83B0 001F83B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F83B4 001F83B4 1000BFFF */  sd         $31, 0x10($29)
    /* F83B8 001F83B8 0000B07F */  sq         $16, 0x0($29)
    /* F83BC 001F83BC 2D808000 */  daddu      $16, $4, $0
    /* F83C0 001F83C0 0B090424 */  addiu      $4, $0, 0x90B
    /* F83C4 001F83C4 04000524 */  addiu      $5, $0, 0x4
    /* F83C8 001F83C8 1C51060C */  jal        func_00194470
    /* F83CC 001F83CC 00000000 */   nop
    /* F83D0 001F83D0 2000033C */  lui        $3, %hi(func_001f8380)
    /* F83D4 001F83D4 80836324 */  addiu      $3, $3, %lo(func_001f8380)
    /* F83D8 001F83D8 6C0043AC */  sw         $3, 0x6C($2)
    /* F83DC 001F83DC 7800438C */  lw         $3, 0x78($2)
    /* F83E0 001F83E0 000070AC */  sw         $16, 0x0($3)
    /* F83E4 001F83E4 1000BFDF */  ld         $31, 0x10($29)
    /* F83E8 001F83E8 0000B07B */  lq         $16, 0x0($29)
    /* F83EC 001F83EC 2000BD27 */  addiu      $29, $29, 0x20
    /* F83F0 001F83F0 0800E003 */  jr         $31
    /* F83F4 001F83F4 00000000 */   nop
    /* F83F8 001F83F8 00000000 */  nop
    /* F83FC 001F83FC 00000000 */  nop
.size func_001f83b0, 0x50
