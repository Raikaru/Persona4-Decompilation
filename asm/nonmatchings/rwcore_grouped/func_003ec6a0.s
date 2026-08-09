.section .text
.set noat
.set noreorder
glabel func_003ec6a0
    /* 2EC6A0 003EC6A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC6A4 003EC6A4 FF00A230 */  andi       $2, $5, 0xFF
    /* 2EC6A8 003EC6A8 00120200 */  sll        $2, $2, 8
    /* 2EC6AC 003EC6AC 2D188000 */  daddu      $3, $4, $0
    /* 2EC6B0 003EC6B0 2130C200 */  addu       $6, $6, $2
    /* 2EC6B4 003EC6B4 0000BFFF */  sd         $31, 0x0($29)
    /* 2EC6B8 003EC6B8 8800023C */  lui        $2, %hi(D_00887364)
    /* 2EC6BC 003EC6BC 1C00A427 */  addiu      $4, $29, 0x1C
    /* 2EC6C0 003EC6C0 6473428C */  lw         $2, %lo(D_00887364)($2)
    /* 2EC6C4 003EC6C4 09F84000 */  jalr       $2
    /* 2EC6C8 003EC6C8 2D286000 */   daddu     $5, $3, $0
    /* 2EC6CC 003EC6CC 03004010 */  beqz       $2, .L003EC6DC
    /* 2EC6D0 003EC6D0 00000000 */   nop
    /* 2EC6D4 003EC6D4 02000010 */  b          .L003EC6E0
    /* 2EC6D8 003EC6D8 1C00A28F */   lw        $2, 0x1C($29)
  .L003EC6DC:
    /* 2EC6DC 003EC6DC 2D100000 */  daddu      $2, $0, $0
  .L003EC6E0:
    /* 2EC6E0 003EC6E0 0000BFDF */  ld         $31, 0x0($29)
    /* 2EC6E4 003EC6E4 0800E003 */  jr         $31
    /* 2EC6E8 003EC6E8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EC6EC 003EC6EC 00000000 */  nop
.size func_003ec6a0, 0x50
