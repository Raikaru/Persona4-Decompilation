.section .text
.set noat
.set noreorder
glabel func_00176bc0
    /* 76BC0 00176BC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 76BC4 00176BC4 1000BFFF */  sd         $31, 0x10($29)
    /* 76BC8 00176BC8 0000B07F */  sq         $16, 0x0($29)
    /* 76BCC 00176BCC 2D800000 */  daddu      $16, $0, $0
    /* 76BD0 00176BD0 A054050C */  jal        func_00155280
    /* 76BD4 00176BD4 00000000 */   nop
    /* 76BD8 00176BD8 0000428C */  lw         $2, 0x0($2)
    /* 76BDC 00176BDC 07004010 */  beqz       $2, .L00176BFC
    /* 76BE0 00176BE0 00000000 */   nop
    /* 76BE4 00176BE4 A054050C */  jal        func_00155280
    /* 76BE8 00176BE8 00000000 */   nop
    /* 76BEC 00176BEC 0000448C */  lw         $4, 0x0($2)
    /* 76BF0 00176BF0 6058050C */  jal        func_00156180
    /* 76BF4 00176BF4 00000000 */   nop
    /* 76BF8 00176BF8 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L00176BFC:
    /* 76BFC 00176BFC 2D200002 */  daddu      $4, $16, $0
    /* 76C00 00176C00 D4730A0C */  jal        func_0029cf50
    /* 76C04 00176C04 00000000 */   nop
    /* 76C08 00176C08 01000224 */  addiu      $2, $0, 0x1
    /* 76C0C 00176C0C 1000BFDF */  ld         $31, 0x10($29)
    /* 76C10 00176C10 0000B07B */  lq         $16, 0x0($29)
    /* 76C14 00176C14 2000BD27 */  addiu      $29, $29, 0x20
    /* 76C18 00176C18 0800E003 */  jr         $31
    /* 76C1C 00176C1C 00000000 */   nop
.size func_00176bc0, 0x60
