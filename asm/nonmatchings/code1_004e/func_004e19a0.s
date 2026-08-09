.section .text
.set noat
.set noreorder
glabel func_004e19a0
    /* 3E19A0 004E19A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E19A4 004E19A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E19A8 004E19A8 0800BFFF */  sd         $31, 0x8($29)
    /* 3E19AC 004E19AC 520A110C */  jal        func_00442948
    /* 3E19B0 004E19B0 2D808000 */   daddu     $16, $4, $0
    /* 3E19B4 004E19B4 01004224 */  addiu      $2, $2, 0x1
    /* 3E19B8 004E19B8 0D004010 */  beqz       $2, .L004E19F0
    /* 3E19BC 004E19BC 2D300000 */   daddu     $6, $0, $0
    /* 3E19C0 004E19C0 2D384000 */  daddu      $7, $2, $0
    /* 3E19C4 004E19C4 21200602 */  addu       $4, $16, $6
  .L004E19C8:
    /* 3E19C8 004E19C8 0100C624 */  addiu      $6, $6, 0x1
    /* 3E19CC 004E19CC 00008290 */  lbu        $2, 0x0($4)
    /* 3E19D0 004E19D0 E0FF4324 */  addiu      $3, $2, -0x20
    /* 3E19D4 004E19D4 9FFF4224 */  addiu      $2, $2, -0x61
    /* 3E19D8 004E19D8 1A00422C */  sltiu      $2, $2, 0x1A
    /* 3E19DC 004E19DC 02004010 */  beqz       $2, .L004E19E8
    /* 3E19E0 004E19E0 2B28C700 */   sltu      $5, $6, $7
    /* 3E19E4 004E19E4 000083A0 */  sb         $3, 0x0($4)
  .L004E19E8:
    /* 3E19E8 004E19E8 F7FFA014 */  bnez       $5, .L004E19C8
    /* 3E19EC 004E19EC 21200602 */   addu      $4, $16, $6
  .L004E19F0:
    /* 3E19F0 004E19F0 0000B0DF */  ld         $16, 0x0($29)
    /* 3E19F4 004E19F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3E19F8 004E19F8 0800E003 */  jr         $31
    /* 3E19FC 004E19FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e19a0, 0x60
