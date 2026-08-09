.section .text
.set noat
.set noreorder
glabel func_00514388
    /* 414388 00514388 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41438C 0051438C 00FF053C */  lui        $5, (0xFF000A01 >> 16)
    /* 414390 00514390 0000BFFF */  sd         $31, 0x0($29)
    /* 414394 00514394 010AA534 */  ori        $5, $5, (0xFF000A01 & 0xFFFF)
    /* 414398 00514398 0000BFDF */  ld         $31, 0x0($29)
    /* 41439C 0051439C B45E1408 */  j          func_00517ad0
    /* 4143A0 005143A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4143A4 005143A4 00000000 */  nop
.size func_00514388, 0x20
