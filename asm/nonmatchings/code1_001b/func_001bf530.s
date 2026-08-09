.section .text
.set noat
.set noreorder
glabel func_001bf530
    /* BF530 001BF530 C0FFBD27 */  addiu      $29, $29, -0x40
    /* BF534 001BF534 2000BFFF */  sd         $31, 0x20($29)
    /* BF538 001BF538 1000B17F */  sq         $17, 0x10($29)
    /* BF53C 001BF53C 0000B07F */  sq         $16, 0x0($29)
    /* BF540 001BF540 2D808000 */  daddu      $16, $4, $0
    /* BF544 001BF544 4401838C */  lw         $3, 0x144($4)
    /* BF548 001BF548 05006010 */  beqz       $3, .L001BF560
    /* BF54C 001BF54C 00000000 */   nop
    /* BF550 001BF550 ACF7060C */  jal        func_001bdeb0
    /* BF554 001BF554 00000000 */   nop
    /* BF558 001BF558 1A000010 */  b          .L001BF5C4
    /* BF55C 001BF55C 00000000 */   nop
  .L001BF560:
    /* BF560 001BF560 E000048E */  lw         $4, 0xE0($16)
    /* BF564 001BF564 17008010 */  beqz       $4, .L001BF5C4
    /* BF568 001BF568 00000000 */   nop
    /* BF56C 001BF56C 1A008394 */  lhu        $3, 0x1A($4)
    /* BF570 001BF570 01006330 */  andi       $3, $3, 0x1
    /* BF574 001BF574 13006010 */  beqz       $3, .L001BF5C4
    /* BF578 001BF578 00000000 */   nop
    /* BF57C 001BF57C 3000918C */  lw         $17, 0x30($4)
    /* BF580 001BF580 2D202002 */  daddu      $4, $17, $0
    /* BF584 001BF584 3000A527 */  addiu      $5, $29, 0x30
    /* BF588 001BF588 1456060C */  jal        func_00195850
    /* BF58C 001BF58C 00000000 */   nop
    /* BF590 001BF590 900021C6 */  lwc1       $f1, 0x90($17)
    /* BF594 001BF594 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* BF598 001BF598 42080046 */  mul.s      $f1, $f1, $f0
    /* BF59C 001BF59C 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* BF5A0 001BF5A0 00008244 */  mtc1       $2, $f0
    /* BF5A4 001BF5A4 00000000 */  nop
    /* BF5A8 001BF5A8 02030146 */  mul.s      $f12, $f0, $f1
    /* BF5AC 001BF5AC E000048E */  lw         $4, 0xE0($16)
    /* BF5B0 001BF5B0 9C000526 */  addiu      $5, $16, 0x9C
    /* BF5B4 001BF5B4 3000A627 */  addiu      $6, $29, 0x30
    /* BF5B8 001BF5B8 C1000724 */  addiu      $7, $0, 0xC1
    /* BF5BC 001BF5BC 50F3060C */  jal        func_001bcd40
    /* BF5C0 001BF5C0 00000000 */   nop
  .L001BF5C4:
    /* BF5C4 001BF5C4 2000BFDF */  ld         $31, 0x20($29)
    /* BF5C8 001BF5C8 1000B17B */  lq         $17, 0x10($29)
    /* BF5CC 001BF5CC 0000B07B */  lq         $16, 0x0($29)
    /* BF5D0 001BF5D0 4000BD27 */  addiu      $29, $29, 0x40
    /* BF5D4 001BF5D4 0800E003 */  jr         $31
    /* BF5D8 001BF5D8 00000000 */   nop
    /* BF5DC 001BF5DC 00000000 */  nop
.size func_001bf530, 0xb0
