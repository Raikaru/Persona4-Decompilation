.section .text
.set noat
.set noreorder
glabel func_001fa320
    /* FA320 001FA320 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FA324 001FA324 0000BFFF */  sd         $31, 0x0($29)
    /* FA328 001FA328 010C0424 */  addiu      $4, $0, 0xC01
    /* FA32C 001FA32C 04000524 */  addiu      $5, $0, 0x4
    /* FA330 001FA330 1C51060C */  jal        func_00194470
    /* FA334 001FA334 00000000 */   nop
    /* FA338 001FA338 47004390 */  lbu        $3, 0x47($2)
    /* FA33C 001FA33C EE006330 */  andi       $3, $3, 0xEE
    /* FA340 001FA340 470043A0 */  sb         $3, 0x47($2)
    /* FA344 001FA344 2000033C */  lui        $3, %hi(func_001fa190)
    /* FA348 001FA348 90A16324 */  addiu      $3, $3, %lo(func_001fa190)
    /* FA34C 001FA34C 6C0043AC */  sw         $3, 0x6C($2)
    /* FA350 001FA350 7800438C */  lw         $3, 0x78($2)
    /* FA354 001FA354 000060AC */  sw         $0, 0x0($3)
    /* FA358 001FA358 0000BFDF */  ld         $31, 0x0($29)
    /* FA35C 001FA35C 1000BD27 */  addiu      $29, $29, 0x10
    /* FA360 001FA360 0800E003 */  jr         $31
    /* FA364 001FA364 00000000 */   nop
    /* FA368 001FA368 00000000 */  nop
    /* FA36C 001FA36C 00000000 */  nop
.size func_001fa320, 0x50
