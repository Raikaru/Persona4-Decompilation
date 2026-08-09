.section .text
.set noat
.set noreorder
glabel func_004e3a10
    /* 3E3A10 004E3A10 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3E3A14 004E3A14 01000224 */  addiu      $2, $0, 0x1
    /* 3E3A18 004E3A18 1000B0FF */  sd         $16, 0x10($29)
    /* 3E3A1C 004E3A1C 4800BFFF */  sd         $31, 0x48($29)
    /* 3E3A20 004E3A20 0000A2AF */  sw         $2, 0x0($29)
    /* 3E3A24 004E3A24 1800B1FF */  sd         $17, 0x18($29)
    /* 3E3A28 004E3A28 2D888000 */  daddu      $17, $4, $0
    /* 3E3A2C 004E3A2C 2000B2FF */  sd         $18, 0x20($29)
    /* 3E3A30 004E3A30 2D900000 */  daddu      $18, $0, $0
    /* 3E3A34 004E3A34 2800B3FF */  sd         $19, 0x28($29)
    /* 3E3A38 004E3A38 00901334 */  ori        $19, $0, 0x9000
    /* 3E3A3C 004E3A3C 3000B4FF */  sd         $20, 0x30($29)
    /* 3E3A40 004E3A40 01001424 */  addiu      $20, $0, 0x1
    /* 3E3A44 004E3A44 3800B5FF */  sd         $21, 0x38($29)
    /* 3E3A48 004E3A48 7600153C */  lui        $21, %hi(D_0075AAC0)
    /* 3E3A4C 004E3A4C 4000B6FF */  sd         $22, 0x40($29)
    /* 3E3A50 004E3A50 09001624 */  addiu      $22, $0, 0x9
    /* 3E3A54 004E3A54 0000A28F */  lw         $2, 0x0($29)
  .L004E3A58:
    /* 3E3A58 004E3A58 17005414 */  bne        $2, $20, .L004E3AB8
    /* 3E3A5C 004E3A5C 1000B0DF */   ld        $16, 0x10($29)
    /* 3E3A60 004E3A60 8691130C */  jal        func_004e4618
    /* 3E3A64 004E3A64 00110424 */   addiu     $4, $0, 0x1100
    /* 3E3A68 004E3A68 3000248E */  lw         $4, 0x30($17)
    /* 3E3A6C 004E3A6C 01000524 */  addiu      $5, $0, 0x1
    /* 3E3A70 004E3A70 2C92130C */  jal        func_004e48b0
    /* 3E3A74 004E3A74 2D30A003 */   daddu     $6, $29, $0
    /* 3E3A78 004E3A78 01110424 */  addiu      $4, $0, 0x1101
    /* 3E3A7C 004E3A7C 8691130C */  jal        func_004e4618
    /* 3E3A80 004E3A80 2D804000 */   daddu     $16, $2, $0
    /* 3E3A84 004E3A84 04000106 */  bgez       $16, .L004E3A98
    /* 3E3A88 004E3A88 00000000 */   nop
    /* 3E3A8C 004E3A8C 340030AE */  sw         $16, 0x34($17)
    /* 3E3A90 004E3A90 08000010 */  b          .L004E3AB4
    /* 3E3A94 004E3A94 020036A2 */   sb        $22, 0x2($17)
  .L004E3A98:
    /* 3E3A98 004E3A98 6E8E130C */  jal        func_004e39b8
    /* 3E3A9C 004E3A9C 01005226 */   addiu     $18, $18, 0x1
    /* 3E3AA0 004E3AA0 2A107202 */  slt        $2, $19, $18
    /* 3E3AA4 004E3AA4 ECFF4050 */  beql       $2, $0, .L004E3A58
    /* 3E3AA8 004E3AA8 0000A28F */   lw        $2, 0x0($29)
    /* 3E3AAC 004E3AAC 3291100C */  jal        func_004244c8
    /* 3E3AB0 004E3AB0 C0AAA426 */   addiu     $4, $21, %lo(D_0075AAC0)
  .L004E3AB4:
    /* 3E3AB4 004E3AB4 1000B0DF */  ld         $16, 0x10($29)
  .L004E3AB8:
    /* 3E3AB8 004E3AB8 1800B1DF */  ld         $17, 0x18($29)
    /* 3E3ABC 004E3ABC 2000B2DF */  ld         $18, 0x20($29)
    /* 3E3AC0 004E3AC0 2800B3DF */  ld         $19, 0x28($29)
    /* 3E3AC4 004E3AC4 3000B4DF */  ld         $20, 0x30($29)
    /* 3E3AC8 004E3AC8 3800B5DF */  ld         $21, 0x38($29)
    /* 3E3ACC 004E3ACC 4000B6DF */  ld         $22, 0x40($29)
    /* 3E3AD0 004E3AD0 4800BFDF */  ld         $31, 0x48($29)
    /* 3E3AD4 004E3AD4 0800E003 */  jr         $31
    /* 3E3AD8 004E3AD8 5000BD27 */   addiu     $29, $29, 0x50
    /* 3E3ADC 004E3ADC 00000000 */  nop
.size func_004e3a10, 0xd0
