.section .text
.set noat
.set noreorder
glabel func_003ec180
    /* 2EC180 003EC180 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2EC184 003EC184 8800023C */  lui        $2, %hi(D_00887344)
    /* 2EC188 003EC188 2000BFFF */  sd         $31, 0x20($29)
    /* 2EC18C 003EC18C 2D300000 */  daddu      $6, $0, $0
    /* 2EC190 003EC190 1000B17F */  sq         $17, 0x10($29)
    /* 2EC194 003EC194 0000B07F */  sq         $16, 0x0($29)
    /* 2EC198 003EC198 2D88A000 */  daddu      $17, $5, $0
    /* 2EC19C 003EC19C 4473428C */  lw         $2, %lo(D_00887344)($2)
    /* 2EC1A0 003EC1A0 09F84000 */  jalr       $2
    /* 2EC1A4 003EC1A4 2D808000 */   daddu     $16, $4, $0
    /* 2EC1A8 003EC1A8 0B004010 */  beqz       $2, .L003EC1D8
    /* 2EC1AC 003EC1AC 00000000 */   nop
    /* 2EC1B0 003EC1B0 0000228E */  lw         $2, 0x0($17)
    /* 2EC1B4 003EC1B4 02004230 */  andi       $2, $2, 0x2
    /* 2EC1B8 003EC1B8 03004014 */  bnez       $2, .L003EC1C8
    /* 2EC1BC 003EC1BC 00000000 */   nop
  .L003EC1C0:
    /* 2EC1C0 003EC1C0 06000010 */  b          .L003EC1DC
    /* 2EC1C4 003EC1C4 2D100002 */   daddu     $2, $16, $0
  .L003EC1C8:
    /* 2EC1C8 003EC1C8 22000292 */  lbu        $2, 0x22($16)
    /* 2EC1CC 003EC1CC 01004234 */  ori        $2, $2, 0x1
    /* 2EC1D0 003EC1D0 FBFF0010 */  b          .L003EC1C0
    /* 2EC1D4 003EC1D4 220002A2 */   sb        $2, 0x22($16)
  .L003EC1D8:
    /* 2EC1D8 003EC1D8 2D100000 */  daddu      $2, $0, $0
  .L003EC1DC:
    /* 2EC1DC 003EC1DC 2000BFDF */  ld         $31, 0x20($29)
    /* 2EC1E0 003EC1E0 1000B17B */  lq         $17, 0x10($29)
    /* 2EC1E4 003EC1E4 0000B07B */  lq         $16, 0x0($29)
    /* 2EC1E8 003EC1E8 0800E003 */  jr         $31
    /* 2EC1EC 003EC1EC 3000BD27 */   addiu     $29, $29, 0x30
.size func_003ec180, 0x70
