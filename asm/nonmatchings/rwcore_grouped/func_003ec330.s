.section .text
.set noat
.set noreorder
glabel func_003ec330
    /* 2EC330 003EC330 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC334 003EC334 1000BFFF */  sd         $31, 0x10($29)
    /* 2EC338 003EC338 0000B07F */  sq         $16, 0x0($29)
    /* 2EC33C 003EC33C 2D808000 */  daddu      $16, $4, $0
    /* 2EC340 003EC340 7100043C */  lui        $4, %hi(D_0070B7E0)
    /* 2EC344 003EC344 2D280002 */  daddu      $5, $16, $0
    /* 2EC348 003EC348 088F0F0C */  jal        func_003e3c20
    /* 2EC34C 003EC34C E0B78424 */   addiu     $4, $4, %lo(D_0070B7E0)
    /* 2EC350 003EC350 8800023C */  lui        $2, %hi(D_0088733C)
    /* 2EC354 003EC354 2D200000 */  daddu      $4, $0, $0
    /* 2EC358 003EC358 3C73428C */  lw         $2, %lo(D_0088733C)($2)
    /* 2EC35C 003EC35C 2D280002 */  daddu      $5, $16, $0
    /* 2EC360 003EC360 09F84000 */  jalr       $2
    /* 2EC364 003EC364 2D300000 */   daddu     $6, $0, $0
    /* 2EC368 003EC368 D0B7848F */  lw         $4, -0x4830($28)
    /* 2EC36C 003EC36C 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EC370 003EC370 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EC374 003EC374 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EC378 003EC378 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EC37C 003EC37C 21186400 */  addu       $3, $3, $4
    /* 2EC380 003EC380 6000648C */  lw         $4, 0x60($3)
    /* 2EC384 003EC384 09F84000 */  jalr       $2
    /* 2EC388 003EC388 2D280002 */   daddu     $5, $16, $0
    /* 2EC38C 003EC38C 1000BFDF */  ld         $31, 0x10($29)
    /* 2EC390 003EC390 01000224 */  addiu      $2, $0, 0x1
    /* 2EC394 003EC394 0000B07B */  lq         $16, 0x0($29)
    /* 2EC398 003EC398 0800E003 */  jr         $31
    /* 2EC39C 003EC39C 2000BD27 */   addiu     $29, $29, 0x20
.size func_003ec330, 0x70
