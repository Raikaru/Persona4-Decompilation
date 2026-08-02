.section .text
.set noat
.set noreorder
glabel func_004ab5a0
    /* 3AB5A0 004AB5A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AB5A4 004AB5A4 2000BFFF */  sd         $31, 0x20($29)
    /* 3AB5A8 004AB5A8 1000B17F */  sq         $17, 0x10($29)
    /* 3AB5AC 004AB5AC 0000B07F */  sq         $16, 0x0($29)
    /* 3AB5B0 004AB5B0 2D888000 */  daddu      $17, $4, $0
    /* 3AB5B4 004AB5B4 2411120C */  jal        func_00484490
    /* 3AB5B8 004AB5B8 00000000 */   nop
    /* 3AB5BC 004AB5BC 2D804000 */  daddu      $16, $2, $0
    /* 3AB5C0 004AB5C0 06000016 */  bnez       $16, .L004AB5DC
    /* 3AB5C4 004AB5C4 00000000 */   nop
    /* 3AB5C8 004AB5C8 7100043C */  lui        $4, %hi(D_00714380)
    /* 3AB5CC 004AB5CC 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3AB5D0 004AB5D0 2B070524 */  addiu      $5, $0, 0x72B
    /* 3AB5D4 004AB5D4 CCB5110C */  jal        func_0046d730
    /* 3AB5D8 004AB5D8 00000000 */   nop
  .L004AB5DC:
    /* 3AB5DC 004AB5DC 0C002496 */  lhu        $4, 0xC($17)
    /* 3AB5E0 004AB5E0 2D280002 */  daddu      $5, $16, $0
    /* 3AB5E4 004AB5E4 08AD120C */  jal        func_004ab420
    /* 3AB5E8 004AB5E8 00000000 */   nop
    /* 3AB5EC 004AB5EC 2D804000 */  daddu      $16, $2, $0
    /* 3AB5F0 004AB5F0 06000016 */  bnez       $16, .L004AB60C
    /* 3AB5F4 004AB5F4 00000000 */   nop
    /* 3AB5F8 004AB5F8 7100043C */  lui        $4, %hi(D_00714380)
    /* 3AB5FC 004AB5FC 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3AB600 004AB600 2D070524 */  addiu      $5, $0, 0x72D
    /* 3AB604 004AB604 CCB5110C */  jal        func_0046d730
    /* 3AB608 004AB608 00000000 */   nop
  .L004AB60C:
    /* 3AB60C 004AB60C 2D202002 */  daddu      $4, $17, $0
    /* 3AB610 004AB610 3411120C */  jal        func_004844d0
    /* 3AB614 004AB614 00000000 */   nop
    /* 3AB618 004AB618 10004010 */  beqz       $2, .L004AB65C
    /* 3AB61C 004AB61C 00000000 */   nop
    /* 3AB620 004AB620 1800048E */  lw         $4, 0x18($16)
    /* 3AB624 004AB624 40180400 */  sll        $3, $4, 1
    /* 3AB628 004AB628 21186400 */  addu       $3, $3, $4
    /* 3AB62C 004AB62C C0200300 */  sll        $4, $3, 3
    /* 3AB630 004AB630 7100033C */  lui        $3, %hi(D_00714470)
    /* 3AB634 004AB634 70446324 */  addiu      $3, $3, %lo(D_00714470)
    /* 3AB638 004AB638 21186400 */  addu       $3, $3, $4
    /* 3AB63C 004AB63C 00006380 */  lb         $3, 0x0($3)
    /* 3AB640 004AB640 06006010 */  beqz       $3, .L004AB65C
    /* 3AB644 004AB644 00000000 */   nop
    /* 3AB648 004AB648 2D204000 */  daddu      $4, $2, $0
    /* 3AB64C 004AB64C 1C002596 */  lhu        $5, 0x1C($17)
    /* 3AB650 004AB650 58AE120C */  jal        func_004ab960
    /* 3AB654 004AB654 00000000 */   nop
    /* 3AB658 004AB658 280002AE */  sw         $2, 0x28($16)
  .L004AB65C:
    /* 3AB65C 004AB65C 2D100002 */  daddu      $2, $16, $0
    /* 3AB660 004AB660 2000BFDF */  ld         $31, 0x20($29)
    /* 3AB664 004AB664 1000B17B */  lq         $17, 0x10($29)
    /* 3AB668 004AB668 0000B07B */  lq         $16, 0x0($29)
    /* 3AB66C 004AB66C 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AB670 004AB670 0800E003 */  jr         $31
    /* 3AB674 004AB674 00000000 */   nop
    /* 3AB678 004AB678 00000000 */  nop
    /* 3AB67C 004AB67C 00000000 */  nop
.size func_004ab5a0, 0xe0
