.section .text
.set noat
.set noreorder
glabel func_0027b690
    /* 17B690 0027B690 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17B694 0027B694 1000BFFF */  sd         $31, 0x10($29)
    /* 17B698 0027B698 0000B07F */  sq         $16, 0x0($29)
    /* 17B69C 0027B69C 8800033C */  lui        $3, %hi(D_008817EC)
    /* 17B6A0 0027B6A0 EC17638C */  lw         $3, %lo(D_008817EC)($3)
    /* 17B6A4 0027B6A4 06000010 */  b          .L0027B6C0
    /* 17B6A8 0027B6A8 00000000 */   nop
  .L0027B6AC:
    /* 17B6AC 0027B6AC 0400708C */  lw         $16, 0x4($3)
    /* 17B6B0 0027B6B0 0800648C */  lw         $4, 0x8($3)
    /* 17B6B4 0027B6B4 9CE2090C */  jal        func_00278a70
    /* 17B6B8 0027B6B8 00000000 */   nop
    /* 17B6BC 0027B6BC 2D180002 */  daddu      $3, $16, $0
  .L0027B6C0:
    /* 17B6C0 0027B6C0 00000000 */  nop
    /* 17B6C4 0027B6C4 F9FF6014 */  bnez       $3, .L0027B6AC
    /* 17B6C8 0027B6C8 00000000 */   nop
    /* 17B6CC 0027B6CC 1000BFDF */  ld         $31, 0x10($29)
    /* 17B6D0 0027B6D0 0000B07B */  lq         $16, 0x0($29)
    /* 17B6D4 0027B6D4 2000BD27 */  addiu      $29, $29, 0x20
    /* 17B6D8 0027B6D8 0800E003 */  jr         $31
    /* 17B6DC 0027B6DC 00000000 */   nop
.size func_0027b690, 0x50
