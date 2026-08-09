.section .text
.set noat
.set noreorder
glabel func_003ec480
    /* 2EC480 003EC480 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2EC484 003EC484 8800023C */  lui        $2, %hi(D_00887378)
    /* 2EC488 003EC488 4000BFFF */  sd         $31, 0x40($29)
    /* 2EC48C 003EC48C 3000B37F */  sq         $19, 0x30($29)
    /* 2EC490 003EC490 2000B27F */  sq         $18, 0x20($29)
    /* 2EC494 003EC494 2D988000 */  daddu      $19, $4, $0
    /* 2EC498 003EC498 1000B17F */  sq         $17, 0x10($29)
    /* 2EC49C 003EC49C 2D90A000 */  daddu      $18, $5, $0
    /* 2EC4A0 003EC4A0 0000B07F */  sq         $16, 0x0($29)
    /* 2EC4A4 003EC4A4 7873508C */  lw         $16, %lo(D_00887378)($2)
    /* 2EC4A8 003EC4A8 D4870F0C */  jal        func_003e1f50
    /* 2EC4AC 003EC4AC 2D88C000 */   daddu     $17, $6, $0
    /* 2EC4B0 003EC4B0 2D284002 */  daddu      $5, $18, $0
    /* 2EC4B4 003EC4B4 2D302002 */  daddu      $6, $17, $0
    /* 2EC4B8 003EC4B8 09F80002 */  jalr       $16
    /* 2EC4BC 003EC4BC 2D206002 */   daddu     $4, $19, $0
    /* 2EC4C0 003EC4C0 0A980200 */  movz       $19, $0, $2
    /* 2EC4C4 003EC4C4 2D106002 */  daddu      $2, $19, $0
    /* 2EC4C8 003EC4C8 4000BFDF */  ld         $31, 0x40($29)
    /* 2EC4CC 003EC4CC 3000B37B */  lq         $19, 0x30($29)
    /* 2EC4D0 003EC4D0 2000B27B */  lq         $18, 0x20($29)
    /* 2EC4D4 003EC4D4 1000B17B */  lq         $17, 0x10($29)
    /* 2EC4D8 003EC4D8 0000B07B */  lq         $16, 0x0($29)
    /* 2EC4DC 003EC4DC 0800E003 */  jr         $31
    /* 2EC4E0 003EC4E0 5000BD27 */   addiu     $29, $29, 0x50
    /* 2EC4E4 003EC4E4 00000000 */  nop
    /* 2EC4E8 003EC4E8 00000000 */  nop
    /* 2EC4EC 003EC4EC 00000000 */  nop
.size func_003ec480, 0x70
