.section .text
.set noat
.set noreorder
glabel func_0042d0b0
    /* 32D0B0 0042D0B0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32D0B4 0042D0B4 0000B0FF */  sd         $16, 0x0($29)
    /* 32D0B8 0042D0B8 1000B1FF */  sd         $17, 0x10($29)
    /* 32D0BC 0042D0BC 2000BFFF */  sd         $31, 0x20($29)
    /* 32D0C0 0042D0C0 88AE100C */  jal        func_0042ba20
    /* 32D0C4 0042D0C4 2D808000 */   daddu     $16, $4, $0
    /* 32D0C8 0042D0C8 2D200002 */  daddu      $4, $16, $0
    /* 32D0CC 0042D0CC F4B3100C */  jal        func_0042cfd0
    /* 32D0D0 0042D0D0 2D884000 */   daddu     $17, $2, $0
    /* 32D0D4 0042D0D4 03002012 */  beqz       $17, .L0042D0E4
    /* 32D0D8 0042D0D8 2D804000 */   daddu     $16, $2, $0
    /* 32D0DC 0042D0DC 9CAE100C */  jal        func_0042ba70
    /* 32D0E0 0042D0E0 00000000 */   nop
  .L0042D0E4:
    /* 32D0E4 0042D0E4 2D100002 */  daddu      $2, $16, $0
    /* 32D0E8 0042D0E8 2000BFDF */  ld         $31, 0x20($29)
    /* 32D0EC 0042D0EC 1000B1DF */  ld         $17, 0x10($29)
    /* 32D0F0 0042D0F0 0000B0DF */  ld         $16, 0x0($29)
    /* 32D0F4 0042D0F4 0800E003 */  jr         $31
    /* 32D0F8 0042D0F8 3000BD27 */   addiu     $29, $29, 0x30
    /* 32D0FC 0042D0FC 00000000 */  nop
.size func_0042d0b0, 0x50
