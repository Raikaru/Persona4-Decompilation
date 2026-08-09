.section .text
.set noat
.set noreorder
glabel func_0042d2d8
    /* 32D2D8 0042D2D8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32D2DC 0042D2DC 0000B0FF */  sd         $16, 0x0($29)
    /* 32D2E0 0042D2E0 1000B1FF */  sd         $17, 0x10($29)
    /* 32D2E4 0042D2E4 2000BFFF */  sd         $31, 0x20($29)
    /* 32D2E8 0042D2E8 88AE100C */  jal        func_0042ba20
    /* 32D2EC 0042D2EC 2D808000 */   daddu     $16, $4, $0
    /* 32D2F0 0042D2F0 2D200002 */  daddu      $4, $16, $0
    /* 32D2F4 0042D2F4 9AB4100C */  jal        func_0042d268
    /* 32D2F8 0042D2F8 2D884000 */   daddu     $17, $2, $0
    /* 32D2FC 0042D2FC 03002012 */  beqz       $17, .L0042D30C
    /* 32D300 0042D300 2D804000 */   daddu     $16, $2, $0
    /* 32D304 0042D304 9CAE100C */  jal        func_0042ba70
    /* 32D308 0042D308 00000000 */   nop
  .L0042D30C:
    /* 32D30C 0042D30C 2D100002 */  daddu      $2, $16, $0
    /* 32D310 0042D310 2000BFDF */  ld         $31, 0x20($29)
    /* 32D314 0042D314 1000B1DF */  ld         $17, 0x10($29)
    /* 32D318 0042D318 0000B0DF */  ld         $16, 0x0($29)
    /* 32D31C 0042D31C 0800E003 */  jr         $31
    /* 32D320 0042D320 3000BD27 */   addiu     $29, $29, 0x30
    /* 32D324 0042D324 00000000 */  nop
.size func_0042d2d8, 0x50
