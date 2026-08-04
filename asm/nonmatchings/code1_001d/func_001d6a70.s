.section .text
.set noat
.set noreorder
glabel func_001d6a70
    /* D6A70 001D6A70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D6A74 001D6A74 1000BFFF */  sd         $31, 0x10($29)
    /* D6A78 001D6A78 0000B07F */  sq         $16, 0x0($29)
    /* D6A7C 001D6A7C ACB3828F */  lw         $2, -0x4C54($28)
    /* D6A80 001D6A80 B801448C */  lw         $4, 0x1B8($2)
    /* D6A84 001D6A84 05000010 */  b          .L001D6A9C
    /* D6A88 001D6A88 00000000 */   nop
  .L001D6A8C:
    /* D6A8C 001D6A8C 2000908C */  lw         $16, 0x20($4)
    /* D6A90 001D6A90 445A070C */  jal        func_001d6910
    /* D6A94 001D6A94 00000000 */   nop
    /* D6A98 001D6A98 2D200002 */  daddu      $4, $16, $0
  .L001D6A9C:
    /* D6A9C 001D6A9C 00000000 */  nop
    /* D6AA0 001D6AA0 00000000 */  nop
    /* D6AA4 001D6AA4 F9FF8014 */  bnez       $4, .L001D6A8C
    /* D6AA8 001D6AA8 00000000 */   nop
    /* D6AAC 001D6AAC 745D070C */  jal        func_001d75d0
    /* D6AB0 001D6AB0 00000000 */   nop
    /* D6AB4 001D6AB4 1000BFDF */  ld         $31, 0x10($29)
    /* D6AB8 001D6AB8 0000B07B */  lq         $16, 0x0($29)
    /* D6ABC 001D6ABC 2000BD27 */  addiu      $29, $29, 0x20
    /* D6AC0 001D6AC0 0800E003 */  jr         $31
    /* D6AC4 001D6AC4 00000000 */   nop
    /* D6AC8 001D6AC8 00000000 */  nop
    /* D6ACC 001D6ACC 00000000 */  nop
.size func_001d6a70, 0x60
