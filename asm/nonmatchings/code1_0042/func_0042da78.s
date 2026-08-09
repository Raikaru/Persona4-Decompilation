.section .text
.set noat
.set noreorder
glabel func_0042da78
    /* 32DA78 0042DA78 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 32DA7C 0042DA7C 1000B1FF */  sd         $17, 0x10($29)
    /* 32DA80 0042DA80 0000B0FF */  sd         $16, 0x0($29)
    /* 32DA84 0042DA84 2D88A000 */  daddu      $17, $5, $0
    /* 32DA88 0042DA88 3000B3FF */  sd         $19, 0x30($29)
    /* 32DA8C 0042DA8C 2000B2FF */  sd         $18, 0x20($29)
    /* 32DA90 0042DA90 4000BFFF */  sd         $31, 0x40($29)
    /* 32DA94 0042DA94 88AE100C */  jal        func_0042ba20
    /* 32DA98 0042DA98 2D808000 */   daddu     $16, $4, $0
    /* 32DA9C 0042DA9C 7100033C */  lui        $3, %hi(D_0070DCB0)
    /* 32DAA0 0042DAA0 7100053C */  lui        $5, %hi(D_0070DCB4)
    /* 32DAA4 0042DAA4 B0DC738C */  lw         $19, %lo(D_0070DCB0)($3)
    /* 32DAA8 0042DAA8 2D904000 */  daddu      $18, $2, $0
    /* 32DAAC 0042DAAC B4DCB1AC */  sw         $17, %lo(D_0070DCB4)($5)
    /* 32DAB0 0042DAB0 2D200002 */  daddu      $4, $16, $0
    /* 32DAB4 0042DAB4 B0DC70AC */  sw         $16, %lo(D_0070DCB0)($3)
    /* 32DAB8 0042DAB8 00311100 */  sll        $6, $17, 4
    /* 32DABC 0042DABC 72FE100C */  jal        func_0043f9c8
    /* 32DAC0 0042DAC0 2D280000 */   daddu     $5, $0, $0
    /* 32DAC4 0042DAC4 04004012 */  beqz       $18, .L0042DAD8
    /* 32DAC8 0042DAC8 2D106002 */   daddu     $2, $19, $0
    /* 32DACC 0042DACC 9CAE100C */  jal        func_0042ba70
    /* 32DAD0 0042DAD0 00000000 */   nop
    /* 32DAD4 0042DAD4 2D106002 */  daddu      $2, $19, $0
  .L0042DAD8:
    /* 32DAD8 0042DAD8 4000BFDF */  ld         $31, 0x40($29)
    /* 32DADC 0042DADC 3000B3DF */  ld         $19, 0x30($29)
    /* 32DAE0 0042DAE0 2000B2DF */  ld         $18, 0x20($29)
    /* 32DAE4 0042DAE4 1000B1DF */  ld         $17, 0x10($29)
    /* 32DAE8 0042DAE8 0000B0DF */  ld         $16, 0x0($29)
    /* 32DAEC 0042DAEC 0800E003 */  jr         $31
    /* 32DAF0 0042DAF0 5000BD27 */   addiu     $29, $29, 0x50
    /* 32DAF4 0042DAF4 00000000 */  nop
.size func_0042da78, 0x80
