.section .text
.set noat
.set noreorder
glabel func_001fa8f0
    /* FA8F0 001FA8F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FA8F4 001FA8F4 0000BFFF */  sd         $31, 0x0($29)
    /* FA8F8 001FA8F8 050C0424 */  addiu      $4, $0, 0xC05
    /* FA8FC 001FA8FC 04000524 */  addiu      $5, $0, 0x4
    /* FA900 001FA900 1C51060C */  jal        func_00194470
    /* FA904 001FA904 00000000 */   nop
    /* FA908 001FA908 47004390 */  lbu        $3, 0x47($2)
    /* FA90C 001FA90C EE006330 */  andi       $3, $3, 0xEE
    /* FA910 001FA910 470043A0 */  sb         $3, 0x47($2)
    /* FA914 001FA914 2000033C */  lui        $3, %hi(func_001fa7a0)
    /* FA918 001FA918 A0A76324 */  addiu      $3, $3, %lo(func_001fa7a0)
    /* FA91C 001FA91C 6C0043AC */  sw         $3, 0x6C($2)
    /* FA920 001FA920 7800438C */  lw         $3, 0x78($2)
    /* FA924 001FA924 000060AC */  sw         $0, 0x0($3)
    /* FA928 001FA928 0000BFDF */  ld         $31, 0x0($29)
    /* FA92C 001FA92C 1000BD27 */  addiu      $29, $29, 0x10
    /* FA930 001FA930 0800E003 */  jr         $31
    /* FA934 001FA934 00000000 */   nop
    /* FA938 001FA938 00000000 */  nop
    /* FA93C 001FA93C 00000000 */  nop
.size func_001fa8f0, 0x50
