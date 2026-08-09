.section .text
.set noat
.set noreorder
glabel func_001fa720
    /* FA720 001FA720 D0FFBD27 */  addiu      $29, $29, -0x30
    /* FA724 001FA724 2000BFFF */  sd         $31, 0x20($29)
    /* FA728 001FA728 1000B17F */  sq         $17, 0x10($29)
    /* FA72C 001FA72C 0000B07F */  sq         $16, 0x0($29)
    /* FA730 001FA730 2D888000 */  daddu      $17, $4, $0
    /* FA734 001FA734 040C0424 */  addiu      $4, $0, 0xC04
    /* FA738 001FA738 0A000524 */  addiu      $5, $0, 0xA
    /* FA73C 001FA73C 1C51060C */  jal        func_00194470
    /* FA740 001FA740 00000000 */   nop
    /* FA744 001FA744 2D804000 */  daddu      $16, $2, $0
    /* FA748 001FA748 47004390 */  lbu        $3, 0x47($2)
    /* FA74C 001FA74C EE006330 */  andi       $3, $3, 0xEE
    /* FA750 001FA750 470043A0 */  sb         $3, 0x47($2)
    /* FA754 001FA754 2000033C */  lui        $3, %hi(func_001fa490)
    /* FA758 001FA758 90A46324 */  addiu      $3, $3, %lo(func_001fa490)
    /* FA75C 001FA75C 680043AC */  sw         $3, 0x68($2)
    /* FA760 001FA760 2000033C */  lui        $3, %hi(func_001fa660)
    /* FA764 001FA764 60A66324 */  addiu      $3, $3, %lo(func_001fa660)
    /* FA768 001FA768 6C0043AC */  sw         $3, 0x6C($2)
    /* FA76C 001FA76C 7800448C */  lw         $4, 0x78($2)
    /* FA770 001FA770 2D282002 */  daddu      $5, $17, $0
    /* FA774 001FA774 0A000624 */  addiu      $6, $0, 0xA
    /* FA778 001FA778 04FE100C */  jal        func_0043f810
    /* FA77C 001FA77C 00000000 */   nop
    /* FA780 001FA780 2D100002 */  daddu      $2, $16, $0
    /* FA784 001FA784 2000BFDF */  ld         $31, 0x20($29)
    /* FA788 001FA788 1000B17B */  lq         $17, 0x10($29)
    /* FA78C 001FA78C 0000B07B */  lq         $16, 0x0($29)
    /* FA790 001FA790 3000BD27 */  addiu      $29, $29, 0x30
    /* FA794 001FA794 0800E003 */  jr         $31
    /* FA798 001FA798 00000000 */   nop
    /* FA79C 001FA79C 00000000 */  nop
.size func_001fa720, 0x80
