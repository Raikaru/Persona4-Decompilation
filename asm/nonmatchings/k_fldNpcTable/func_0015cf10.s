.section .text
.set noat
.set noreorder
glabel func_0015cf10
    /* 5CF10 0015CF10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 5CF14 0015CF14 0000BFFF */  sd         $31, 0x0($29)
    /* 5CF18 0015CF18 A054050C */  jal        func_00155280
    /* 5CF1C 0015CF1C 00000000 */   nop
    /* 5CF20 0015CF20 E018438C */  lw         $3, 0x18E0($2)
    /* 5CF24 0015CF24 0B006010 */  beqz       $3, .L0015CF54
    /* 5CF28 0015CF28 00000000 */   nop
    /* 5CF2C 0015CF2C A054050C */  jal        func_00155280
    /* 5CF30 0015CF30 00000000 */   nop
    /* 5CF34 0015CF34 E018448C */  lw         $4, 0x18E0($2)
    /* 5CF38 0015CF38 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 5CF3C 0015CF3C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 5CF40 0015CF40 09F84000 */  jalr       $2
    /* 5CF44 0015CF44 00000000 */   nop
    /* 5CF48 0015CF48 A054050C */  jal        func_00155280
    /* 5CF4C 0015CF4C 00000000 */   nop
    /* 5CF50 0015CF50 E01840AC */  sw         $0, 0x18E0($2)
  .L0015CF54:
    /* 5CF54 0015CF54 0000BFDF */  ld         $31, 0x0($29)
    /* 5CF58 0015CF58 1000BD27 */  addiu      $29, $29, 0x10
    /* 5CF5C 0015CF5C 0800E003 */  jr         $31
    /* 5CF60 0015CF60 00000000 */   nop
    /* 5CF64 0015CF64 00000000 */  nop
    /* 5CF68 0015CF68 00000000 */  nop
    /* 5CF6C 0015CF6C 00000000 */  nop
.size func_0015cf10, 0x60
