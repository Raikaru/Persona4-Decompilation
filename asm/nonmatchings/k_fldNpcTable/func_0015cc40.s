.section .text
.set noat
.set noreorder
glabel func_0015cc40
    /* 5CC40 0015CC40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 5CC44 0015CC44 0000BFFF */  sd         $31, 0x0($29)
    /* 5CC48 0015CC48 A054050C */  jal        func_00155280
    /* 5CC4C 0015CC4C 00000000 */   nop
    /* 5CC50 0015CC50 E818438C */  lw         $3, 0x18E8($2)
    /* 5CC54 0015CC54 14006010 */  beqz       $3, .L0015CCA8
    /* 5CC58 0015CC58 00000000 */   nop
    /* 5CC5C 0015CC5C A054050C */  jal        func_00155280
    /* 5CC60 0015CC60 00000000 */   nop
    /* 5CC64 0015CC64 E818448C */  lw         $4, 0x18E8($2)
    /* 5CC68 0015CC68 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 5CC6C 0015CC6C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 5CC70 0015CC70 09F84000 */  jalr       $2
    /* 5CC74 0015CC74 00000000 */   nop
    /* 5CC78 0015CC78 A054050C */  jal        func_00155280
    /* 5CC7C 0015CC7C 00000000 */   nop
    /* 5CC80 0015CC80 E81840AC */  sw         $0, 0x18E8($2)
    /* 5CC84 0015CC84 A054050C */  jal        func_00155280
    /* 5CC88 0015CC88 00000000 */   nop
    /* 5CC8C 0015CC8C EC1840AC */  sw         $0, 0x18EC($2)
    /* 5CC90 0015CC90 A054050C */  jal        func_00155280
    /* 5CC94 0015CC94 00000000 */   nop
    /* 5CC98 0015CC98 F01840AC */  sw         $0, 0x18F0($2)
    /* 5CC9C 0015CC9C A054050C */  jal        func_00155280
    /* 5CCA0 0015CCA0 00000000 */   nop
    /* 5CCA4 0015CCA4 F41840AC */  sw         $0, 0x18F4($2)
  .L0015CCA8:
    /* 5CCA8 0015CCA8 0000BFDF */  ld         $31, 0x0($29)
    /* 5CCAC 0015CCAC 1000BD27 */  addiu      $29, $29, 0x10
    /* 5CCB0 0015CCB0 0800E003 */  jr         $31
    /* 5CCB4 0015CCB4 00000000 */   nop
    /* 5CCB8 0015CCB8 00000000 */  nop
    /* 5CCBC 0015CCBC 00000000 */  nop
.size func_0015cc40, 0x80
