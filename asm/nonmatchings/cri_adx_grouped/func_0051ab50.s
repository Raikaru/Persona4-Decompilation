.section .text
.set noat
.set noreorder
glabel func_0051ab50
    /* 41AB50 0051AB50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 41AB54 0051AB54 0000B0FF */  sd         $16, 0x0($29)
    /* 41AB58 0051AB58 2D808000 */  daddu      $16, $4, $0
    /* 41AB5C 0051AB5C 0800B1FF */  sd         $17, 0x8($29)
    /* 41AB60 0051AB60 1000BFFF */  sd         $31, 0x10($29)
    /* 41AB64 0051AB64 827D140C */  jal        func_0051f608
    /* 41AB68 0051AB68 50091126 */   addiu     $17, $16, 0x950
    /* 41AB6C 0051AB6C FFFF0324 */  addiu      $3, $0, -0x1
    /* 41AB70 0051AB70 2D284000 */  daddu      $5, $2, $0
    /* 41AB74 0051AB74 05004310 */  beq        $2, $3, .L0051AB8C
    /* 41AB78 0051AB78 2D200002 */   daddu     $4, $16, $0
    /* 41AB7C 0051AB7C F66A140C */  jal        func_0051abd8
    /* 41AB80 0051AB80 00000000 */   nop
    /* 41AB84 0051AB84 0F004050 */  beql       $2, $0, .L0051ABC4
    /* 41AB88 0051AB88 0000B0DF */   ld        $16, 0x0($29)
  .L0051AB8C:
    /* 41AB8C 0051AB8C 2D200002 */  daddu      $4, $16, $0
    /* 41AB90 0051AB90 126B140C */  jal        func_0051ac48
    /* 41AB94 0051AB94 01000524 */   addiu     $5, $0, 0x1
    /* 41AB98 0051AB98 2D200002 */  daddu      $4, $16, $0
    /* 41AB9C 0051AB9C 0000228E */  lw         $2, 0x0($17)
    /* 41ABA0 0051ABA0 05000524 */  addiu      $5, $0, 0x5
    /* 41ABA4 0051ABA4 06004014 */  bnez       $2, .L0051ABC0
    /* 41ABA8 0051ABA8 2D300000 */   daddu     $6, $0, $0
    /* 41ABAC 0051ABAC 0000B0DF */  ld         $16, 0x0($29)
    /* 41ABB0 0051ABB0 0800B1DF */  ld         $17, 0x8($29)
    /* 41ABB4 0051ABB4 1000BFDF */  ld         $31, 0x10($29)
    /* 41ABB8 0051ABB8 B4931408 */  j          func_00524ed0
    /* 41ABBC 0051ABBC 2000BD27 */   addiu     $29, $29, 0x20
  .L0051ABC0:
    /* 41ABC0 0051ABC0 0000B0DF */  ld         $16, 0x0($29)
  .L0051ABC4:
    /* 41ABC4 0051ABC4 0800B1DF */  ld         $17, 0x8($29)
    /* 41ABC8 0051ABC8 1000BFDF */  ld         $31, 0x10($29)
    /* 41ABCC 0051ABCC 0800E003 */  jr         $31
    /* 41ABD0 0051ABD0 2000BD27 */   addiu     $29, $29, 0x20
    /* 41ABD4 0051ABD4 00000000 */  nop
.size func_0051ab50, 0x88
