.section .text
.set noat
.set noreorder
glabel func_00189fa0
    /* 89FA0 00189FA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 89FA4 00189FA4 0000BFFF */  sd         $31, 0x0($29)
    /* 89FA8 00189FA8 A054050C */  jal        func_00155280
    /* 89FAC 00189FAC 00000000 */   nop
    /* 89FB0 00189FB0 3000428C */  lw         $2, 0x30($2)
    /* 89FB4 00189FB4 04004014 */  bnez       $2, .L00189FC8
    /* 89FB8 00189FB8 00000000 */   nop
    /* 89FBC 00189FBC 2D100000 */  daddu      $2, $0, $0
    /* 89FC0 00189FC0 0A000010 */  b          .L00189FEC
    /* 89FC4 00189FC4 00000000 */   nop
  .L00189FC8:
    /* 89FC8 00189FC8 A054050C */  jal        func_00155280
    /* 89FCC 00189FCC 00000000 */   nop
    /* 89FD0 00189FD0 3000448C */  lw         $4, 0x30($2)
    /* 89FD4 00189FD4 2048110C */  jal        func_00452080
    /* 89FD8 00189FD8 00000000 */   nop
    /* 89FDC 00189FDC A054050C */  jal        func_00155280
    /* 89FE0 00189FE0 00000000 */   nop
    /* 89FE4 00189FE4 300040AC */  sw         $0, 0x30($2)
    /* 89FE8 00189FE8 01000224 */  addiu      $2, $0, 0x1
  .L00189FEC:
    /* 89FEC 00189FEC 0000BFDF */  ld         $31, 0x0($29)
    /* 89FF0 00189FF0 1000BD27 */  addiu      $29, $29, 0x10
    /* 89FF4 00189FF4 0800E003 */  jr         $31
    /* 89FF8 00189FF8 00000000 */   nop
    /* 89FFC 00189FFC 00000000 */  nop
.size func_00189fa0, 0x60
