.section .text
.set noat
.set noreorder
glabel func_004ae650
    /* 3AE650 004AE650 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AE654 004AE654 1000BFFF */  sd         $31, 0x10($29)
    /* 3AE658 004AE658 0000B07F */  sq         $16, 0x0($29)
    /* 3AE65C 004AE65C 2D808000 */  daddu      $16, $4, $0
    /* 3AE660 004AE660 5800848C */  lw         $4, 0x58($4)
    /* 3AE664 004AE664 03008010 */  beqz       $4, .L004AE674
    /* 3AE668 004AE668 00000000 */   nop
    /* 3AE66C 004AE66C 344B120C */  jal        func_00492cd0
    /* 3AE670 004AE670 00000000 */   nop
  .L004AE674:
    /* 3AE674 004AE674 6000048E */  lw         $4, 0x60($16)
    /* 3AE678 004AE678 05008010 */  beqz       $4, .L004AE690
    /* 3AE67C 004AE67C 00000000 */   nop
    /* 3AE680 004AE680 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AE684 004AE684 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AE688 004AE688 09F84000 */  jalr       $2
    /* 3AE68C 004AE68C 00000000 */   nop
  .L004AE690:
    /* 3AE690 004AE690 5400048E */  lw         $4, 0x54($16)
    /* 3AE694 004AE694 03008010 */  beqz       $4, .L004AE6A4
    /* 3AE698 004AE698 00000000 */   nop
    /* 3AE69C 004AE69C C0010F0C */  jal        func_003c0700
    /* 3AE6A0 004AE6A0 00000000 */   nop
  .L004AE6A4:
    /* 3AE6A4 004AE6A4 2D200002 */  daddu      $4, $16, $0
    /* 3AE6A8 004AE6A8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AE6AC 004AE6AC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AE6B0 004AE6B0 09F84000 */  jalr       $2
    /* 3AE6B4 004AE6B4 00000000 */   nop
    /* 3AE6B8 004AE6B8 1000BFDF */  ld         $31, 0x10($29)
    /* 3AE6BC 004AE6BC 0000B07B */  lq         $16, 0x0($29)
    /* 3AE6C0 004AE6C0 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AE6C4 004AE6C4 0800E003 */  jr         $31
    /* 3AE6C8 004AE6C8 00000000 */   nop
    /* 3AE6CC 004AE6CC 00000000 */  nop
.size func_004ae650, 0x80
