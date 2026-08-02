.section .text
.set noat
.set noreorder
glabel func_004aa660
    /* 3AA660 004AA660 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AA664 004AA664 0000BFFF */  sd         $31, 0x0($29)
    /* 3AA668 004AA668 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AA66C 004AA66C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AA670 004AA670 09F84000 */  jalr       $2
    /* 3AA674 004AA674 00000000 */   nop
    /* 3AA678 004AA678 0000BFDF */  ld         $31, 0x0($29)
    /* 3AA67C 004AA67C 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AA680 004AA680 0800E003 */  jr         $31
    /* 3AA684 004AA684 00000000 */   nop
    /* 3AA688 004AA688 00000000 */  nop
    /* 3AA68C 004AA68C 00000000 */  nop
.size func_004aa660, 0x30
