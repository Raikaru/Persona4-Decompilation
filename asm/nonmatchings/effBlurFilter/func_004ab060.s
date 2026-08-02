.section .text
.set noat
.set noreorder
glabel func_004ab060
    /* 3AB060 004AB060 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AB064 004AB064 2000BFFF */  sd         $31, 0x20($29)
    /* 3AB068 004AB068 1000B17F */  sq         $17, 0x10($29)
    /* 3AB06C 004AB06C 0000B07F */  sq         $16, 0x0($29)
    /* 3AB070 004AB070 2D888000 */  daddu      $17, $4, $0
    /* 3AB074 004AB074 2411120C */  jal        func_00484490
    /* 3AB078 004AB078 00000000 */   nop
    /* 3AB07C 004AB07C 2D804000 */  daddu      $16, $2, $0
    /* 3AB080 004AB080 06000016 */  bnez       $16, .L004AB09C
    /* 3AB084 004AB084 00000000 */   nop
    /* 3AB088 004AB088 7100043C */  lui        $4, %hi(D_00714380)
    /* 3AB08C 004AB08C 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3AB090 004AB090 60060524 */  addiu      $5, $0, 0x660
    /* 3AB094 004AB094 CCB5110C */  jal        func_0046d730
    /* 3AB098 004AB098 00000000 */   nop
  .L004AB09C:
    /* 3AB09C 004AB09C 0C002496 */  lhu        $4, 0xC($17)
    /* 3AB0A0 004AB0A0 2D280002 */  daddu      $5, $16, $0
    /* 3AB0A4 004AB0A4 B8AB120C */  jal        func_004aaee0
    /* 3AB0A8 004AB0A8 00000000 */   nop
    /* 3AB0AC 004AB0AC 2D804000 */  daddu      $16, $2, $0
    /* 3AB0B0 004AB0B0 06000016 */  bnez       $16, .L004AB0CC
    /* 3AB0B4 004AB0B4 00000000 */   nop
    /* 3AB0B8 004AB0B8 7100043C */  lui        $4, %hi(D_00714380)
    /* 3AB0BC 004AB0BC 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3AB0C0 004AB0C0 62060524 */  addiu      $5, $0, 0x662
    /* 3AB0C4 004AB0C4 CCB5110C */  jal        func_0046d730
    /* 3AB0C8 004AB0C8 00000000 */   nop
  .L004AB0CC:
    /* 3AB0CC 004AB0CC 2D202002 */  daddu      $4, $17, $0
    /* 3AB0D0 004AB0D0 3411120C */  jal        func_004844d0
    /* 3AB0D4 004AB0D4 00000000 */   nop
    /* 3AB0D8 004AB0D8 10004010 */  beqz       $2, .L004AB11C
    /* 3AB0DC 004AB0DC 00000000 */   nop
    /* 3AB0E0 004AB0E0 1800048E */  lw         $4, 0x18($16)
    /* 3AB0E4 004AB0E4 40180400 */  sll        $3, $4, 1
    /* 3AB0E8 004AB0E8 21186400 */  addu       $3, $3, $4
    /* 3AB0EC 004AB0EC C0200300 */  sll        $4, $3, 3
    /* 3AB0F0 004AB0F0 7100033C */  lui        $3, %hi(D_007143A0)
    /* 3AB0F4 004AB0F4 A0436324 */  addiu      $3, $3, %lo(D_007143A0)
    /* 3AB0F8 004AB0F8 21186400 */  addu       $3, $3, $4
    /* 3AB0FC 004AB0FC 00006380 */  lb         $3, 0x0($3)
    /* 3AB100 004AB100 06006010 */  beqz       $3, .L004AB11C
    /* 3AB104 004AB104 00000000 */   nop
    /* 3AB108 004AB108 2D204000 */  daddu      $4, $2, $0
    /* 3AB10C 004AB10C 1C002596 */  lhu        $5, 0x1C($17)
    /* 3AB110 004AB110 58AE120C */  jal        func_004ab960
    /* 3AB114 004AB114 00000000 */   nop
    /* 3AB118 004AB118 280002AE */  sw         $2, 0x28($16)
  .L004AB11C:
    /* 3AB11C 004AB11C 2D100002 */  daddu      $2, $16, $0
    /* 3AB120 004AB120 2000BFDF */  ld         $31, 0x20($29)
    /* 3AB124 004AB124 1000B17B */  lq         $17, 0x10($29)
    /* 3AB128 004AB128 0000B07B */  lq         $16, 0x0($29)
    /* 3AB12C 004AB12C 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AB130 004AB130 0800E003 */  jr         $31
    /* 3AB134 004AB134 00000000 */   nop
    /* 3AB138 004AB138 00000000 */  nop
    /* 3AB13C 004AB13C 00000000 */  nop
.size func_004ab060, 0xe0
