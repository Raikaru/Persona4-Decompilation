.section .text
.set noat
.set noreorder
glabel func_0047a7c0
    /* 37A7C0 0047A7C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37A7C4 0047A7C4 0000BFFF */  sd         $31, 0x0($29)
    /* 37A7C8 0047A7C8 C802828C */  lw         $2, 0x2C8($4)
    /* 37A7CC 0047A7CC 04004010 */  beqz       $2, .L0047A7E0
    /* 37A7D0 0047A7D0 00000000 */   nop
    /* 37A7D4 0047A7D4 00004294 */  lhu        $2, 0x0($2)
    /* 37A7D8 0047A7D8 06000010 */  b          .L0047A7F4
    /* 37A7DC 0047A7DC 00000000 */   nop
  .L0047A7E0:
    /* 37A7E0 0047A7E0 DC00848C */  lw         $4, 0xDC($4)
    /* 37A7E4 0047A7E4 7100053C */  lui        $5, %hi(D_007131D8)
    /* 37A7E8 0047A7E8 D831A524 */  addiu      $5, $5, %lo(D_007131D8)
    /* 37A7EC 0047A7EC 6860110C */  jal        func_004581a0
    /* 37A7F0 0047A7F0 00000000 */   nop
  .L0047A7F4:
    /* 37A7F4 0047A7F4 0000BFDF */  ld         $31, 0x0($29)
    /* 37A7F8 0047A7F8 1000BD27 */  addiu      $29, $29, 0x10
    /* 37A7FC 0047A7FC 0800E003 */  jr         $31
    /* 37A800 0047A800 00000000 */   nop
    /* 37A804 0047A804 00000000 */  nop
    /* 37A808 0047A808 00000000 */  nop
    /* 37A80C 0047A80C 00000000 */  nop
.size func_0047a7c0, 0x50
